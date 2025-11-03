/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiEdit_h
#define _gduiEdit_h
#pragma pack (push, 8)

#pragma once

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiEdit : public CEdit {
  DECLARE_DYNAMIC(CGdUiEdit)

public:
  CGdUiEdit();
  ~CGdUiEdit();

protected:
  CPoint  m_lastMousePoint;
  CRect   m_tipRect;

public:
  virtual void    GetContentExtent(LPCTSTR text, int& width, int& height);
  void    GetTextExtent(LPCTSTR text, int& width, int& height);

public:
  DWORD   m_styleMask;

  virtual void    SetStyleMask(DWORD);
  DWORD   GetStyleMask();
  BOOL    IsStyleMaskSet(DWORD);

protected:
  CWnd    *m_gduiParent;

  virtual GDUI_REPLY DoGdUiMessage(
    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
  );
  virtual void    OnDrawTip(CDC& dc);
  virtual BOOL    OnDrawTipText(CGdUiDrawTipText& dtt);
  virtual GDUI_REPLY OnGetTipSupport(CPoint& p);
  virtual BOOL    OnGetTipRect(CRect& r);
  virtual BOOL    OnGetTipText(CString& text);
  virtual BOOL    OnHitTipRect(CPoint& p);
public:
  CWnd    *GetGdUiParent();
  void    SetGdUiParent(CWnd *w);

protected:
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);

  DECLARE_MESSAGE_MAP()
};

class    CGdUiSearchBoxEditor;
class    CGdUiSearchBoxSearchButton;
class    CGdUiSearchBoxClearButton;

class GCAD_PORT CGdUiSearchBox : public CGdUiEdit {
  DECLARE_DYNAMIC(CGdUiSearchBox)

public:
  CGdUiSearchBox();
  ~CGdUiSearchBox();
  virtual BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
  void    PreSubclassWindow() override;
  void    SetDefaultText(LPCTSTR pszText);
  void    SetNotification(LPCTSTR pszText);
  void    ClearEditor();
  bool    IsEditEmpty();

  void    SetButtonBackgroundColorForThemeChange(COLORREF color, bool bThemeIsDark);

public:
  virtual void    EditChanged();
  virtual void    ClearButtonClicked();
  virtual void    SearchButtonClicked();

protected:
  LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;
  BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) override;
  afx_msg void OnClearButton();
  afx_msg void OnSearchButton();
  afx_msg void SetEditFocus();
  afx_msg void KillEditFocus();
  afx_msg void OnEditChange();
  afx_msg void OnSize(UINT nType, int cx, int cy);
  DECLARE_MESSAGE_MAP()
private:
  BOOL    CreateControls();
  BOOL    DestroyControls();
  void    UpdateSearchBox();
  void    UpdateButton();
  void    GetControlRect(CRect &editRect, CRect &buttonRect);

private:
  bool                    m_bIsControlsCreated;
  CGdUiSearchBoxEditor*    m_pEditor;
  CGdUiSearchBoxSearchButton*      m_pBtnSearch;
  CGdUiSearchBoxClearButton*   m_pBtnClear;

  CString                 m_strNotification;
  CString                 m_strDefaultText;
};
#pragma warning(pop)

#endif 

#pragma pack (pop)
#endif
