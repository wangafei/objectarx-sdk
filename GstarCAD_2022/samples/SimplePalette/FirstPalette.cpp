// FirstPalette.cpp : implementation file
//

#include "stdafx.h"
#include "FirstPalette.h"


// CFirstPalette

IMPLEMENT_DYNAMIC(CFirstPalette, CAdUiPalette)

CFirstPalette::CFirstPalette()
{

}

CFirstPalette::~CFirstPalette()
{
}


BEGIN_MESSAGE_MAP(CFirstPalette, CAdUiPalette)
  ON_WM_CREATE()
  ON_WM_SIZE()
END_MESSAGE_MAP()



// CFirstPalette message handlers




int CFirstPalette::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
  if (CAdUiPalette::OnCreate(lpCreateStruct) == -1)
    return -1;

  m_dlgPalette.Create(CDlgPalette::IDD, this);
  m_dlgPalette.ShowWindow(SW_SHOW);

  return 0;
}


void CFirstPalette::OnSize(UINT nType, int cx, int cy)
{
  CAdUiPalette::OnSize(nType, cx, cy);

  if (m_dlgPalette.GetSafeHwnd())
  {
    m_dlgPalette.MoveWindow(0, 0, cx, cy);
  }
}
