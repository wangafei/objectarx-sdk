// SampleDlg.cpp: Implementation file
//

#include "pch.h"
#include "SampleDlg.h"
#include "rxmfcapi.h"
#include "Resource.h"


// SampleDlg Dialog

IMPLEMENT_DYNAMIC(SampleDlg, CAcUiDialog)

SampleDlg::SampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

SampleDlg::~SampleDlg()
{
}

void SampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listctl);
}


BEGIN_MESSAGE_MAP(SampleDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &SampleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

void SampleDlg::AddToList(CString field, CString value)
{
	int insertNum = m_listctl.GetItemCount();
	m_listctl.InsertItem(insertNum, field);
	m_listctl.SetItemText(insertNum, 1, value);
}

void SampleDlg::AddSeperatorLine(CString field)
{
	m_listctl.InsertItem(m_listctl.GetItemCount(), field);
}

BOOL SampleDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CRect rect;
	m_listctl.GetClientRect(&rect);
	m_listctl.InsertColumn(0, _T("Field"), LVCFMT_CENTER, rect.Width() / 2, 0);
	m_listctl.InsertColumn(1, _T("Value"), LVCFMT_CENTER, rect.Width() / 2, 1);

	return TRUE;
}

CString GetObjClassName(AcDbObject* pObj)
{
	if (pObj != NULL && pObj->isA() != NULL)
	{
		return pObj->isA()->name();
	}
	return _T("NULL");
}

CString GetObjEntName(AcDbObject* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	ads_name ent;
	acdbGetAdsName(ent, pObj->objectId());
	CString entname;
	entname.Format(_T("%lx"), ent[0]);
	return entname;
}

CString GetObjHandle(AcDbObject* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	CString strhandle;
	AcDbHandle handle;
	pObj->getAcDbHandle(handle);
	TCHAR tmpStr[256];
	handle.getIntoAsciiBuffer(tmpStr);
	strhandle = tmpStr;
	return strhandle;
}

CString GetEntLayerName(AcDbEntity* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	AcDbObjectId layId = pObj->layerId();
	if (layId == AcDbObjectId::kNull)
	{
		return _T("NULL");
	}

	const TCHAR* locName = _T("NULL");
	AcDbSymbolTableRecord* pSymbolTableRecord;
	if (acdbOpenObject(pSymbolTableRecord, layId, AcDb::kForRead) == Acad::eOk)
	{
		pSymbolTableRecord->getName(locName);
		pSymbolTableRecord->close();
	}
	return locName;
}

void intToStr(const int intVal, CString& str)
{
	str.Format(_T("%d"), intVal);
}
CString GetEntColorName(AcDbEntity* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	int coloridx = pObj->colorIndex();
	coloridx = abs(coloridx);
	if ((coloridx < 0) || (coloridx > 256))
	{
		return _T("NULL");
	}

	CString str;

	if (coloridx == 0)
		str = _T("ByBlock");
	else if (coloridx == 256)
		str = _T("ByLayer");
	else if (coloridx == 1)
		str = _T("1-Red");
	else if (coloridx == 2)
		str = _T("2-Yellow");
	else if (coloridx == 3)
		str = _T("3-Green");
	else if (coloridx == 4)
		str = _T("4-Cyan");
	else if (coloridx == 5)
		str = _T("5-Blue");
	else if (coloridx == 6)
		str = _T("6-Magenta");
	else if (coloridx == 7)
		str = _T("7-White");
	else
		intToStr(coloridx, str);

	return str;
}

CString GetEntBlockName(AcDbEntity* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	AcDbObjectId blkId = pObj->blockId();
	if (blkId == AcDbObjectId::kNull)
	{
		return _T("NULL");
	}

	AcDbSymbolTableRecord* tblRec;
	const TCHAR* locName = NULL;
	if (acdbOpenObject(tblRec, blkId, AcDb::kForRead) == Acad::eOk)
	{
		tblRec->getName(locName);
		tblRec->close();
	}
	return locName;
}

CString GetCurveIsClosed(AcDbCurve* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	if (pObj->isClosed())
	{
		return _T("TRUE");
	}
	else
	{
		return _T("FALSE");
	}
}

CString GetCurveIsPeriodic(AcDbCurve* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}
	if (pObj->isPeriodic())
	{
		return _T("TRUE");
	}
	else
	{
		return _T("FALSE");
	}
}

CString GetCircleCenter(AcDbCircle* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}

	AcGePoint3d pt = pObj->center();
	TCHAR xstr[100], ystr[100], zstr[100];
	acdbRToS(pt.x, -1, -1, xstr);
	acdbRToS(pt.y, -1, -1, ystr);
	acdbRToS(pt.z, -1, -1, zstr);

	CString str;
	str.Format(_T("(%s, %s, %s)"), xstr, ystr, zstr);
	return str;
}

CString GetCircleRadius(AcDbCircle* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}

	TCHAR tmpStr[100];
	CString str;
	acdbRToS(pObj->radius(), -1, -1, tmpStr);
	str = tmpStr;
	return str;
}

CString GetCircleThickness(AcDbCircle* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}

	TCHAR tmpStr[100];
	CString str;
	acdbRToS(pObj->thickness(), -1, -1, tmpStr);
	str = tmpStr;
	return str;
}

CString GetCircleNormal(AcDbCircle* pObj)
{
	if (pObj == NULL)
	{
		return _T("NULL");
	}

	AcGeVector3d vec = pObj->normal();
	TCHAR xstr[100], ystr[100], zstr[100];
	acdbRToS(vec.x, -1, -1, xstr);
	acdbRToS(vec.y, -1, -1, ystr);
	acdbRToS(vec.z, -1, -1, zstr);

	CString str;
	str.Format(_T("(%s, %s, %s)"), xstr, ystr, zstr);
	return str;
}

void SampleDlg::Display(AcDbObject* pObj)
{
	if (pObj == NULL)
	{
		return;
	}

	AddSeperatorLine(_T("------AcDbObject------"));

	CString classname = GetObjClassName(pObj);
	CString entname = GetObjEntName(pObj);
	CString strhandle = GetObjHandle(pObj);
	AddToList(_T("Class Name"), classname);
	AddToList(_T("Entity Name"), entname);
	AddToList(_T("Handle"), strhandle);

	AcDbEntity* ent = NULL;
	AcDbDictionary* dict = NULL;
	if ((ent = AcDbEntity::cast(pObj)) != NULL)
	{
		Display(ent);
	}
	else if ((dict = AcDbDictionary::cast(pObj)) != NULL)
	{
		//TODO
	}
}

void SampleDlg::Display(AcDbEntity* pObj)
{
	if (pObj == NULL)
	{
		return;
	}

	AddSeperatorLine(_T("------AcDbEntity------"));

	CString layername = GetEntLayerName(pObj);
	CString colorname = GetEntColorName(pObj);
	CString blockname = GetEntBlockName(pObj);

	AddToList(_T("Layer Name"), layername);
	AddToList(_T("Color Name"), colorname);
	AddToList(_T("Block Name"), blockname);

	AcDbCurve* curve = NULL;
	AcDbPoint* point = NULL;
	if ((curve = AcDbCurve::cast(pObj)) != NULL)
	{
		Display(curve);
	}
	else if ((point = AcDbPoint::cast(pObj)) != NULL)
	{
		//TODO
	}
}

void SampleDlg::Display(AcDbCurve* pObj)
{
	if (pObj == NULL)
	{
		return;
	}

	AddSeperatorLine(_T("------AcDbCurve------"));

	CString isclosed = GetCurveIsClosed(pObj);
	CString isperiodic = GetCurveIsPeriodic(pObj);
	AddToList(_T("Is Closed"), isclosed);
	AddToList(_T("Is Periodic"), isperiodic);

	AcDbCircle* circle = NULL;
	AcDbLine* line = NULL;
	if ((circle = AcDbCircle::cast(pObj)) != NULL)
	{
		Display(circle);
	}
	else if ((line = AcDbLine::cast(pObj)) != NULL)
	{
		//TODO
	}
}

void SampleDlg::Display(AcDbCircle* pObj)
{
	if (pObj == NULL)
	{
		return;
	}

	AddSeperatorLine(_T("------AcDbCircle------"));

	CString centerpt = GetCircleCenter(pObj);
	CString rad = GetCircleRadius(pObj);
	CString thick = GetCircleThickness(pObj);
	CString nor = GetCircleNormal(pObj);
	AddToList(_T("Center Pt"), centerpt);
	AddToList(_T("Radius"), rad);
	AddToList(_T("Thickness"), thick);
	AddToList(_T("Normal"), nor);
}

// SampleDlg Message Handler
void SampleDlg::OnBnClickedButton1()
{
	// Hide the current dialog
	ShowWindow(SW_HIDE);

	ads_name en;
	ads_point pt;
	if (acedEntSel(_T("\nSelect the entity: \n"), en, pt) != RTNORM)
	{
		// Display the dialog box
		m_listctl.DeleteAllItems();
		ShowWindow(SW_SHOW);
		return;
	}
	AcDbObjectId entId;
	Acad::ErrorStatus es = acdbGetObjectId(entId, en);
	AcDbObject* pObj = NULL;
	acdbOpenObject(pObj, entId, AcDb::kForRead);


	m_listctl.DeleteAllItems();
	Display(pObj);

	pObj->close();
	// Display the dialog box
	ShowWindow(SW_SHOW);
}