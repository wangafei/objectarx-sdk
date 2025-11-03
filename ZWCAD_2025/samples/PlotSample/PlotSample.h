#pragma once
#include "pch.h"
#include "resource.h"
#include <dbsymtb.h>
#include <dbapserv.h>
#include <adslib.h>
#include <adui.h>
#include <acui.h>

class SampleDlg : public CAcUiDialog
{

public:
	SampleDlg(CWnd* pParent = NULL);
	virtual ~SampleDlg();


	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	afx_msg void OnCbnSelchangeDevices();
	afx_msg void OnCbnSelchangeMedia();
	afx_msg void OnBnClickedPlot();
	afx_msg void OnBnClickedPreview();
	afx_msg void OnBnClickedLandscape();
	afx_msg void OnBnClickedFit();
	afx_msg void OnBnClickedBackground();
	afx_msg void OnEnChangeScale();
	afx_msg void OnBnClickedPlottofile();
	afx_msg void OnFilePathChange();

	void RefreshDevices(void);
	void RefreshMediaNames();
	void RefreshPlotStyle();
	void CalcExtents(void);

	CComboBox m_Devices;              // Devices
	CComboBox m_Media;                // Media
	CComboBox m_PlotStyle;            // Plot style
	double m_Scale;                   // Plot scale
	AcDbObjectId layoutId;            // Current layout id
	BOOL m_Landscape;                 // Landscape printing
	CString m_CurrentDevice;          // Current device
	CString m_CurrentMedia;           // Current media
	AcDbPlotSettingsValidator* pPSV;  // Printer validator object
	AcDbPlotSettings *pPlotSettings;  // Plot settings
	BOOL m_bFit;                      // Is fit?
	BOOL m_Background;                // Plot background
	BOOL m_bPlotToFile;               // Whether plot to file
	CString m_csFilename;             // Filename
};