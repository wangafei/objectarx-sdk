/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once


// CFirstPalette
#include "CDlgPalette.h"

class CFirstPalette : public CAdUiPalette
{
	DECLARE_DYNAMIC(CFirstPalette)

public:
	CFirstPalette();
	virtual ~CFirstPalette();

protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()

protected:
  CDlgPalette m_dlgPalette;
};


