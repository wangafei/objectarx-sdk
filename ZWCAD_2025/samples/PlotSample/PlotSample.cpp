#include "pch.h"
#include "PlotSample.h"

SampleDlg::SampleDlg(CWnd* pParent /*=NULL*/)
	: CAcUiDialog(SampleDlg::IDD, pParent)
{
	m_Scale = 0;
	m_Landscape = false;
	m_CurrentDevice = _T("");
	pPSV = NULL;
	pPlotSettings = NULL;
	m_bFit = false;
	m_Background = false;
	m_bPlotToFile = false;
	m_csFilename = _T("");
}

SampleDlg::~SampleDlg()
{
	if (pPlotSettings)
	{
		delete pPlotSettings;
		pPlotSettings = NULL;
	}
}

void SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CAcUiDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEVICES, m_Devices);
	DDX_Control(pDX, IDC_MEDIA, m_Media);
	DDX_Control(pDX, IDC_PLOTSTYLE, m_PlotStyle);
	DDX_Text(pDX, IDC_SCALE, m_Scale);
	DDX_Check(pDX, IDC_LANDSCAPE, m_Landscape);
	DDX_Check(pDX, IDC_FIT, m_bFit);
	DDX_Check(pDX, IDC_BACKGROUND, m_Background);
	DDX_Check(pDX, IDC_PLOTTOFILE, m_bPlotToFile);
	DDX_Text(pDX, IDC_FILENAME, m_csFilename);
}


BEGIN_MESSAGE_MAP(SampleDlg, CAcUiDialog)
	ON_CBN_SELCHANGE(IDC_DEVICES, OnCbnSelchangeDevices)
	ON_CBN_SELCHANGE(IDC_MEDIA, OnCbnSelchangeMedia)
	ON_BN_CLICKED(IDC_PLOT11, OnBnClickedPlot)
	ON_BN_CLICKED(IDC_PREVIEW11, OnBnClickedPreview)
	ON_BN_CLICKED(IDC_LANDSCAPE, OnBnClickedLandscape)
	ON_BN_CLICKED(IDC_FIT, OnBnClickedFit)
	ON_BN_CLICKED(IDC_BACKGROUND, OnBnClickedBackground)
	ON_EN_CHANGE(IDC_SCALE, OnEnChangeScale)
	ON_BN_CLICKED(IDC_PLOTTOFILE, OnBnClickedPlottofile)
	ON_EN_CHANGE(IDC_FILENAME, OnFilePathChange)
END_MESSAGE_MAP()


// SampleDlg
BOOL SampleDlg::OnInitDialog()
{
	CAcUiDialog::OnInitDialog();

	// Get the printer validator object
	pPSV = (AcDbPlotSettingsValidator*)acdbHostApplicationServices()->plotSettingsValidator();

	LockDocManager lock;

	// Get the current active layout and plot settings
	AcDbLayoutManager *pLayoutManager = acdbHostApplicationServices()->layoutManager();
	AcDbObjectId btrId = pLayoutManager->getActiveLayoutBTRId();
	AcDbBlockTableRecord *pBTR = NULL;
	Acad::ErrorStatus es = acdbOpenObject(pBTR, btrId, AcDb::kForRead);
	layoutId = pBTR->getLayoutId();
	AcDbLayout *pLayout = NULL;
	acdbOpenObject(pLayout, layoutId, AcDb::kForRead);
	pPlotSettings = new AcDbPlotSettings(pLayout->modelType());
	pPlotSettings->copyFrom(pLayout);
	pLayout->close();
	pBTR->close();

	// Partial control initialization
	m_bFit = TRUE;
	CEdit *pEdit = (CEdit*)GetDlgItem(IDC_SCALE);
	pEdit->EnableWindow(FALSE);

	TCHAR szDocPath[MAX_PATH] = { 0 };
	SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_CURRENT, szDocPath);
	m_csFilename.Format(_T("%s\\PlotTest.pdf"), szDocPath);

	pEdit = (CEdit*)GetDlgItem(IDC_FILENAME);
	pEdit->EnableWindow(FALSE);
	m_bPlotToFile = FALSE;

	m_Landscape = FALSE;
	pPSV->setPlotRotation(pPlotSettings, AcDbPlotSettings::k0degrees);

	// Setting of BACKGROUNDPLOT
	struct resbuf res;
	acedGetVar(_T("BACKGROUNDPLOT"), &res);
	if (res.resval.rint == 1 || res.resval.rint == 3)
		m_Background = TRUE;
	else
		m_Background = FALSE;

	// Refresh the device list
	RefreshDevices();
	// Refresh the plot style list
	RefreshPlotStyle();
	// Calculate the page scale
	CalcExtents();

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
}

void SampleDlg::OnCbnSelchangeDevices()
{
	LockDocManager lock;

	m_Devices.GetLBText(m_Devices.GetCurSel(), m_CurrentDevice);

	Acad::ErrorStatus es = pPSV->setPlotCfgName(pPlotSettings, m_CurrentDevice);
	pPSV->refreshLists(pPlotSettings);
	// Refresh the media list
	RefreshMediaNames();
	if (m_bFit)
		CalcExtents();

	AcPlPlotConfig *pPlotConfig = NULL;;
	if (Acad::eOk == acplPlotConfigManagerPtr()->setCurrentConfig(pPlotConfig, m_CurrentDevice))
	{
		// Does the device support plotting to files?
		if (pPlotConfig->plotToFileCapability() != AcPlPlotConfig::kPlotToFileAllowed)
		{
			if (pPlotConfig->plotToFileCapability() == AcPlPlotConfig::kNoPlotToFile)
			{
				m_bPlotToFile = FALSE;
				CEdit *pEdit = (CEdit*)GetDlgItem(IDC_FILENAME);
				pEdit->EnableWindow(FALSE);
			}
			else
			{	
				// kMustPlotToFile
				m_bPlotToFile = TRUE;
				CEdit *pEdit = (CEdit*)GetDlgItem(IDC_FILENAME);
				pEdit->EnableWindow(TRUE);
			}
			// Disable the check box
			CButton *pButton = (CButton*)GetDlgItem(IDC_PLOTTOFILE);
			pButton->EnableWindow(FALSE);
		}
		else
		{
			CEdit *pEdit = (CEdit*)GetDlgItem(IDC_FILENAME);
			pEdit->EnableWindow(TRUE);
			CButton *pButton = (CButton*)GetDlgItem(IDC_PLOTTOFILE);
			pButton->EnableWindow(TRUE);
		}
	}
	UpdateData(FALSE);
}

void SampleDlg::OnCbnSelchangeMedia()
{
	LockDocManager lock;

	m_Media.UpdateData();
	m_Media.GetLBText(m_Media.GetCurSel(), m_CurrentMedia);

	Acad::ErrorStatus es = pPSV->setCanonicalMediaName(pPlotSettings, m_CurrentMedia);
	if (m_bFit)
		CalcExtents();
}

void SampleDlg::OnBnClickedPlot()
{
	Acad::ErrorStatus es;
	LockDocManager lock;

	if (m_bPlotToFile)
	{
		CString szTempPath = m_csFilename.Left(m_csFilename.ReverseFind('\\'));
		if (!PathFileExists(szTempPath))
		{
			AfxMessageBox(_T("File directory does not exist!"));
			return;
		}
	}

	es = pPSV->setPlotType(pPlotSettings, AcDbPlotSettings::kExtents);
	// Set the plot scale
	if (m_bFit)
	{
		es = pPSV->setUseStandardScale(pPlotSettings, Adesk::kTrue);
		es = pPSV->setStdScaleType(pPlotSettings, AcDbPlotSettings::kScaleToFit);
	}
	else // The custom scale
	{
		CString scale;
		GetDlgItemText(IDC_SCALE, scale);
		m_Scale = _wtof(scale);
		es = pPSV->setUseStandardScale(pPlotSettings, Adesk::kFalse);
		es = pPSV->setCustomPrintScale(pPlotSettings, 1, m_Scale);
	}
	es = pPSV->setPlotCentered(pPlotSettings, true);

	CString strCurrentPlStyle;
	m_PlotStyle.GetLBText(m_PlotStyle.GetCurSel(), strCurrentPlStyle);
	ACHAR * m_plotstyle = (ACHAR*)strCurrentPlStyle.GetBuffer();
	es = pPSV->setCurrentStyleSheet(pPlotSettings, m_plotstyle);

	// Create the plot engine to start plotting
	AcPlPlotEngine* pEngine = NULL;
	if (Acad::eOk == AcPlPlotFactory::createPublishEngine(pEngine))
	{
		es = pEngine->beginPlot(NULL);

		AcPlPlotPageInfo pageInfo;
		AcPlPlotInfo plotInfo;

		plotInfo.setLayout(layoutId);

		plotInfo.setOverrideSettings(pPlotSettings);

		AcPlPlotInfoValidator validator;
		validator.setMediaMatchingPolicy(AcPlPlotInfoValidator::kMatchEnabled);
		es = validator.validate(plotInfo);

		const TCHAR *szDocName = acDocManager->curDocument()->fileName();
		if (m_bPlotToFile)
			es = pEngine->beginDocument(plotInfo, szDocName, NULL, 1, true, m_csFilename);
		else
			es = pEngine->beginDocument(plotInfo, szDocName);

		es = pEngine->beginPage(pageInfo, plotInfo, true);

		es = pEngine->beginGenerateGraphics();
		es = pEngine->endGenerateGraphics();

		es = pEngine->endPage();

		es = pEngine->endDocument();
		es = pEngine->endPlot();

		pEngine->destroy();
		pEngine = NULL;
	}
	else
	{
		AfxMessageBox(_T("Plot Engine is Busy..."));
	}
}

void SampleDlg::OnBnClickedPreview()
{
	Acad::ErrorStatus es;

	LockDocManager lock;

	es = pPSV->setPlotType(pPlotSettings, AcDbPlotSettings::kExtents);
	if (m_bFit)
	{
		es = pPSV->setUseStandardScale(pPlotSettings, Adesk::kTrue);
		es = pPSV->setStdScaleType(pPlotSettings, AcDbPlotSettings::kScaleToFit);
	}
	else
	{
		CString scale;
		GetDlgItemText(IDC_SCALE, scale);
		m_Scale = _wtof(scale);
		es = pPSV->setUseStandardScale(pPlotSettings, Adesk::kFalse);
		es = pPSV->setCustomPrintScale(pPlotSettings, 1, m_Scale);
	}
	es = pPSV->setPlotCentered(pPlotSettings, true);
	CString strCurrentPlStyle;
	m_PlotStyle.GetLBText(m_PlotStyle.GetCurSel(), strCurrentPlStyle);
	ACHAR * m_plotstyle = (ACHAR*)strCurrentPlStyle.GetBuffer();
	es = pPSV->setCurrentStyleSheet(pPlotSettings, m_plotstyle);

	AcPlPlotEngine* pEngine = NULL;
	if (Acad::eOk == AcPlPlotFactory::createPreviewEngine(pEngine))
	{
		pEngine->beginPlot(NULL);

		AcPlPlotPageInfo pageInfo;
		AcPlPlotInfo plotInfo;

		plotInfo.setLayout(layoutId);

		plotInfo.setOverrideSettings(pPlotSettings);

		AcPlPlotInfoValidator validator;
		validator.setMediaMatchingPolicy(AcPlPlotInfoValidator::kMatchEnabled);
		es = validator.validate(plotInfo);

		const TCHAR *szDocName = acDocManager->curDocument()->fileName();

		es = pEngine->beginDocument(plotInfo, szDocName);
		es = pEngine->beginPage(pageInfo, plotInfo, true);
		es = pEngine->beginGenerateGraphics();
		es = pEngine->endGenerateGraphics();
		es = pEngine->endPage();
		es = pEngine->endDocument();
		es = pEngine->endPlot();

		pEngine->destroy();
		pEngine = NULL;
	}
	else
		AfxMessageBox(_T("Plot Engine is Busy..."));

	SetFocus();
}

void SampleDlg::OnBnClickedLandscape()
{
	UpdateData(TRUE);
	LockDocManager lock;
	if (m_Landscape)
		Acad::ErrorStatus es = pPSV->setPlotRotation(pPlotSettings, AcDbPlotSettings::k90degrees);
	else
		Acad::ErrorStatus es = pPSV->setPlotRotation(pPlotSettings, AcDbPlotSettings::k0degrees);

	CalcExtents();
}

void SampleDlg::OnBnClickedFit()
{
	UpdateData(TRUE);
	CEdit *pEdit = (CEdit*)GetDlgItem(IDC_SCALE);
	if (m_bFit)
	{
		pEdit->EnableWindow(FALSE);
		CalcExtents();
	}
	else
		pEdit->EnableWindow(TRUE);
}

void SampleDlg::OnBnClickedBackground()
{
	UpdateData(TRUE);

	struct resbuf res;
	res.resval.rint = (int)m_Background;
	res.restype = RTSHORT;

	acedSetVar(_T("BACKGROUNDPLOT"), &res);
}

void SampleDlg::OnEnChangeScale()
{
	UpdateData(TRUE);
}

void SampleDlg::OnBnClickedPlottofile()
{
	UpdateData(TRUE);
	CEdit *pEdit = (CEdit*)GetDlgItem(IDC_FILENAME);
	if (m_bPlotToFile)
		pEdit->EnableWindow(TRUE);
	else
		pEdit->EnableWindow(FALSE);
}

void SampleDlg::OnFilePathChange()
{
	UpdateData(TRUE);
}

void SampleDlg::RefreshDevices(void)
{
	AcArray<const TCHAR*> deviceList;

	m_Devices.ResetContent();

	pPSV->plotDeviceList(deviceList);
	for (int c = 0; c < deviceList.length(); c++)
		m_Devices.AddString(deviceList[c]);

	const TCHAR* plotCfgchar;
	pPlotSettings->getPlotCfgName(plotCfgchar);
	m_Devices.SetCurSel(m_Devices.SelectString(0, plotCfgchar));
}

void SampleDlg::RefreshMediaNames()
{
	AcArray<const TCHAR*> MediaList;

	m_Media.ResetContent();

	pPSV->canonicalMediaNameList(pPlotSettings, MediaList);

	for (int c = 0; c < MediaList.length(); c++)
		m_Media.AddString(MediaList[c]);

	const TCHAR *pCurName;
	pPlotSettings->getCanonicalMediaName(pCurName);
	m_Media.SetCurSel(m_Media.SelectString(0, (CString)pCurName));
}

void SampleDlg::RefreshPlotStyle()
{
	AcArray<const TCHAR*> StyleList;
	m_PlotStyle.ResetContent();
	pPSV->plotStyleSheetList(StyleList);
	for (int c = 0; c < StyleList.length(); c++)
		m_PlotStyle.AddString(StyleList[c]);

	const TCHAR* plotStyle;
	Acad::ErrorStatus es = pPlotSettings->getCurrentStyleSheet(plotStyle);
}

void SampleDlg::CalcExtents()
{
	CEdit *pEdit = (CEdit*)GetDlgItem(IDC_SCALE);
	if (m_bFit)
	{
		pEdit->EnableWindow(FALSE);
		Acad::ErrorStatus es = pPSV->setUseStandardScale(pPlotSettings, Adesk::kTrue);
		es = pPSV->setStdScaleType(pPlotSettings, AcDbPlotSettings::kScaleToFit);
		es = pPSV->setPlotType(pPlotSettings, AcDbPlotSettings::kExtents);
		es = pPSV->setPlotCentered(pPlotSettings, true);
		double numerator, denominator;
		es = pPlotSettings->getCustomPrintScale(numerator, denominator);
		m_Scale = numerator / denominator;
		UpdateData(FALSE);
	}
	else
	{
		pEdit->EnableWindow(TRUE);
	}
		
	UpdateData(FALSE);
}