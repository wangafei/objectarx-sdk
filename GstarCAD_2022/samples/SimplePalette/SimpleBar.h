#pragma once


// CSimpleBar
#include "FirstPalette.h"
#include "SecondPalette.h"

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


