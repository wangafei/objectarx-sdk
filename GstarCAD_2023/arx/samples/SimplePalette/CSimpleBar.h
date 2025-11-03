/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once


// CSimpleBar
#include "CFirstPalette.h"
#include "CSecondPalette.h"

class CSimpleBar : public CAdUiPaletteSet
{
public:
	CSimpleBar();
	virtual ~CSimpleBar();
	
protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

protected:
  CFirstPalette* m_pFirstPalette;
  CSecondPalette* m_pSecondPalette;
};


