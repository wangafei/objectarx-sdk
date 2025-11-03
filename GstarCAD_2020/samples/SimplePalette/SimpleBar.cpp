// SimpleBar.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleBar.h"


// CSimpleBar

CSimpleBar::CSimpleBar()
{

}

CSimpleBar::~CSimpleBar()
{
}


BEGIN_MESSAGE_MAP(CSimpleBar, CAdUiPaletteSet)
  ON_WM_CREATE()
END_MESSAGE_MAP()



// CSimpleBar message handlers


int CSimpleBar::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CAdUiPaletteSet::OnCreate(lpCreateStruct) == -1)
    return -1;

  m_pFirstPalette = new CFirstPalette;
  m_pFirstPalette->Create(WS_CHILD | WS_VISIBLE,
    L"First",
    this,
    PS_EDIT_NAME);
  AddPalette(m_pFirstPalette);

  m_pSecondPalette = new CSecondPalette;
  m_pSecondPalette->Create(WS_CHILD | WS_VISIBLE,
    L"Second",
    this,
    PS_EDIT_NAME);
  AddPalette(m_pSecondPalette);

  SetActivePalette(m_pFirstPalette);

  return 0;
}
