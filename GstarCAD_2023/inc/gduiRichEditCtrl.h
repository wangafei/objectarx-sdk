/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiRichEditCtrl_h
#define _gduiRichEditCtrl_h
#pragma pack (push, 8)

#pragma once

#include "GdGChar.h"

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)

class CGdUiRichEditCtrl;

class CGdUiRichEditThemeModReactor : public CGdUiThemeModifiedReactor
{
public:
  CGdUiRichEditThemeModReactor(CGdUiRichEditCtrl* pCtrl);
  void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element) override;

private:
  CGdUiRichEditCtrl * m_pCtrl;
};

class GCAD_PORT CGdUiRichEditCtrl : public CRichEditCtrl {
  friend class CGdUiRichEditThemeModReactor;
  DECLARE_DYNAMIC(CGdUiRichEditCtrl)
public:
  CGdUiRichEditCtrl(bool bIsThemed = false);
  ~CGdUiRichEditCtrl();

protected:

public:
  void clear();
  void SetBackgroundAndTextColor(COLORREF bgColor, COLORREF textColor);
  void AppendString(CString& str, bool bBoldFormat);
  void streamIn();
  void SetMargins(int horizontal, int vertical);
  int  GetHorizontalMargin();
  int  GetVerticalMargin();

  bool IsThemed() { return m_bIsThemed; };
  void SetIsThemed(bool isThemed);

  void SetTitle(LPCTSTR pszTitle) { m_csTitle = pszTitle; };
  BOOL PreTranslateMessage(MSG* pMsg) override;

  static  bool m_bInitOnce;

protected:
  CWnd    *m_gduiParent;

protected:
  afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
  afx_msg void OnSetFocus(CWnd* pOldWnd);
  afx_msg void OnSize(UINT nType, int cx, int cy);
  afx_msg BOOL OnEnLink(NMHDR *pNMHDR, LRESULT *pResult);

  DECLARE_MESSAGE_MAP()

  virtual void ThemeModified(GdUiThemeElement element);

private:
  CString m_csTitle;
  CString m_csText;
  int     m_horizontalMargin;
  int     m_verticalMargin;
  bool    m_bIsThemed;
  CGdUiRichEditThemeModReactor    * m_pThemeModReactor;
  CGdUiTheme * m_pTheme;
  COLORREF mBackgroundColor;
  COLORREF mTextColor;
};

#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif 
