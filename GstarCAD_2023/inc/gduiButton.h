/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiButton_h
#define _gduiButton_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#include "gduiTheme.h"

#ifndef _GSOFT_MAC_

class CGdUiOwnerDrawButton;
class CGdUiTrackButtonDraw;

class CGdUiODButtonThemeModReactor : public CGdUiThemeModifiedReactor
{
public:
  CGdUiODButtonThemeModReactor(CGdUiOwnerDrawButton* pBtn);
  void ThemeModified(const CGdUiTheme * pTheme, GdUiThemeElement element) override;

private:
  CGdUiOwnerDrawButton * m_pBtn;
};

#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiOwnerDrawButton : public CButton {
  friend class CGdUiODButtonThemeModReactor;

  DECLARE_DYNAMIC(CGdUiOwnerDrawButton)

public:
  CGdUiOwnerDrawButton();
  ~CGdUiOwnerDrawButton();

protected:
  CPoint  m_lastMousePoint;
  CRect   m_tipRect;
  CGdUiTheme * m_pTheme;

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

  virtual void    SetTracking(BOOL b) { m_bIsTrackButton = !!b; };
  virtual CGdUiTheme * SetTheme(CGdUiTheme *pTheme);

protected:
  static const UINT_PTR m_timerEvent;
  bool    m_bEnableDragDrop : 1;
  bool    m_bEnableFastDraw : 1;
  bool    m_bEnablePointedAt : 1;
  bool    m_bIsPointedAt : 1;
  bool    m_bIsStatic : 1;
  bool    m_bIsToolButton : 1;
  bool    m_bIsTrackButton : 1;
  UINT_PTR  m_timerId;

  int     m_nPartId;
  int     m_nStateId;
  UINT    m_uEdge;
  BOOL    m_bMouseHover;

  virtual void    DrawBorder(CDC *pDC, CRect &r, COLORREF cr);
  virtual void    DrawHotBorder();
  virtual void    DrawButton(
    CDC& dc, int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused
  );
  virtual void    DrawPushButtonBorder(
    CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected
  );
  virtual void    DrawToolButtonBorder(
    CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused
  );
  void    DrawTransparentBitmap(
    CDC& dc,
    CBitmap& bmp,
    int x, int y, int w, int h,
    BOOL isDisabled
  );
  void    DrawContentText(
    CDC& dc,
    CString sText,
    CRect& rcText,
    BOOL isDisabled
  );
  BOOL    GetIsPointedAt();
  void    SetIsPointedAt(BOOL isPointedAt);
  virtual BOOL    OnAutoLoad();
  virtual void    OnDragDrop(HDROP hDropInfo);
  virtual void    OnPointedAt(BOOL isPointedAt);
  virtual BOOL    OnReload(LPCTSTR strResId);
  void    StartTimer(DWORD ms = 50);
  void    StopTimer();
  virtual void ThemeModified(GdUiThemeElement element);

public:
  BOOL    AutoLoad();
  BOOL    GetEnableDragDrop();
  void    SetEnableDragDrop(BOOL allow);
  BOOL    GetEnableFastDraw();
  void    SetEnableFastDraw(BOOL allow);
  BOOL    GetEnablePointedAt();
  void    SetEnablePointedAt(BOOL allow);
  BOOL    GetIsStatic();
  void    SetIsStatic(BOOL isStatic);
  BOOL    GetIsToolButton();
  void    SetIsToolButton(BOOL isToolButton);
  BOOL    Reload(LPCTSTR strResId);

public:
public:
  void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
  void PreSubclassWindow() override;

protected:
  afx_msg LRESULT OnGdUiMessage(WPARAM wParam, LPARAM lParam);
  afx_msg void OnDropFiles(HDROP hDropInfo);
  afx_msg UINT OnGetDlgCode();
  afx_msg void OnKillFocus(CWnd* pNewWnd);
  afx_msg void OnMouseMove(UINT nFlags, CPoint point);
  afx_msg LRESULT OnMouseLeave(WPARAM, LPARAM);
  afx_msg void OnNcDestroy();
  afx_msg void OnSetFocus(CWnd* pOldWnd);
  afx_msg void OnTimer(UINT_PTR nIDEvent);
  afx_msg void OnDestroy();
  afx_msg LRESULT OnThemeChanged(WPARAM wParam, LPARAM lParam);

  DECLARE_MESSAGE_MAP()
protected:
  HANDLE GetVisualStylesTheme() { return m_hVS; }
private:
  CGdUiODButtonThemeModReactor* m_pThemeModReactor;
  HANDLE    m_hVS;
};
#pragma warning(pop)

class GCAD_PORT CGdUiBitmapButton : public CGdUiOwnerDrawButton
{
  DECLARE_DYNAMIC(CGdUiBitmapButton)

  friend class CGdUiImpBitmapButton;
public:
  CGdUiBitmapButton();
  ~CGdUiBitmapButton();

  enum Constants
  {
    ThemedSize = 24,
  };

  BOOL GetAutoSizeToBitmap();
  void SetAutoSizeToBitmap(BOOL autoSizeToBitmap);
  void SizeToBitmap();
  bool SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);

  virtual BOOL IsThemed() const;
  virtual void SetIsThemed(BOOL isThemed);

  virtual void EnableThemedState(BOOL bEnableHover, BOOL bEnableClick);
  CGdUiTheme * SetTheme(CGdUiTheme *pTheme) override;
  virtual void SetThemeBackground(GdUiThemeElement nElement);

  enum ImageDrawStyle
  {
    kImageDrawStyle_Default = 0x0,
    kImageDrawStyle_Static = 0x1,
    kImageDrawStyle_Center = 0x2,
    kImageDrawStyle_Stretch_BtnSize = 0x3,
  };

  ImageDrawStyle GetImageDrawStyle() const;
  void SetImageDrawStyle(ImageDrawStyle style);

  BOOL LoadBitmap(LPCTSTR strResId);

protected:
  void  DrawButton(
    CDC& dc,
    int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused) override;

  virtual void DrawButtonImage(CDC* pDC, const CRect& rect, BOOL isSelected, BOOL isDisabled);
  virtual void DrawFocusMark(CDC* pDC, CRect& rect, BOOL isDefault, BOOL isSelected, BOOL isFocused);
  BOOL OnAutoLoad() override;
  BOOL OnReload(LPCTSTR strResId) override;

  virtual void DrawThemedButton(CDC& dc, int x, int y, int width, int height, int statusId);
  void ThemeModified(GdUiThemeElement element) override;

  enum ImageType
  {
    kImageType_Undefined,
    kImageType_Bitmap,
    kImageType_Icon,
    kImageType_RCDATA
  };

  BOOL LoadIconResource(LPCTSTR strResId, HINSTANCE hInst = NULL);
  BOOL LoadRCDATAResource(LPCTSTR strResId, HINSTANCE hInst = NULL);
  BOOL LoadBitmapResource(LPCTSTR strResId, CBitmap& bmp, HINSTANCE hInst = NULL);
  virtual BOOL OnLoadBitmap(LPCTSTR strResId);
  void ClearImages(bool bClearResId = false);
  void CalcBitmapSize();
  void SaveAndCalcSize(LPCTSTR strResId, ImageType type);

  BOOL    m_bAutoSizeToBitmap;
  CBitmap m_bmp;
  void *  m_image;
  CString m_bmpResId;
  int     m_bmpHeight;
  int     m_bmpWidth;
  int     m_bmpX;
  int     m_bmpY;
  int     m_focusRectOffset;
  BOOL    m_isThemed;
  BOOL    m_enableThemedHoverState;
  BOOL    m_enableThemedClickState;
  GdUiThemeElement m_backgroundElement;
  ImageType m_imageType;
  ImageDrawStyle m_imageDrawStyle;

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGdUiBitmapStatic : public CGdUiBitmapButton {
  DECLARE_DYNAMIC(CGdUiBitmapStatic)

public:
  CGdUiBitmapStatic();
  ~CGdUiBitmapStatic();

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGdUiDropSite : public CGdUiBitmapStatic {
  DECLARE_DYNAMIC(CGdUiDropSite)
public:
  CGdUiDropSite();
  ~CGdUiDropSite();

protected:
  DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGdUiToolButton : public CGdUiBitmapButton {
  DECLARE_DYNAMIC(CGdUiToolButton)
public:
  CGdUiToolButton();
  ~CGdUiToolButton();

protected:
  DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGdUiTrackButton : public CGdUiOwnerDrawButton {
  DECLARE_DYNAMIC(CGdUiTrackButton)
public:
  CGdUiTrackButton();
  CGdUiTrackButton(const CGdUiTrackButtonDraw & pDraw);
  ~CGdUiTrackButton();

public:
  void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
  virtual CGdUiTheme * GetTheme() const;
  CGdUiTheme * SetTheme(CGdUiTheme *pTheme) override;
  static  CGdUiTrackButtonDraw * SetDefaultDraw(CGdUiTrackButtonDraw * pDraw);
  CGdUiTrackButtonDraw * SetDraw(CGdUiTrackButtonDraw * pDraw);
  void    SetTracking(BOOL b) override;

protected:
  void    DrawButton(
    CDC& dc,
    int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused) override;

  void    DrawBorder(CDC *pDC, CRect &r, COLORREF cr) override;
  void    DrawHotBorder() override;
  void    DrawPushButtonBorder(CDC& dc, CRect& rButton, BOOL isDefault, BOOL isSelected) override;
  void    DrawToolButtonBorder(CDC& dc, CRect& rButton, BOOL isSelected, BOOL isFocused) override;

  GDUI_REPLY OnGetTipSupport(CPoint& p) override;

  afx_msg void OnNcPaint();
  afx_msg void OnPaint();

  DECLARE_MESSAGE_MAP()

  virtual void releaseDraw();

private:
  static CGdUiTrackButtonDraw * s_pDefaultDraw;
  CGdUiTrackButtonDraw * m_pDraw;

};

class GCAD_PORT CGdUiBitmapTextButton : public CGdUiBitmapButton
{
  friend class CGdUiImpBitmapButton;
  DECLARE_DYNAMIC(CGdUiBitmapTextButton)
public:
  enum ButtonType
  {
    kBitmap = 0x1,
    kText = 0x2,
  };

  enum BitmapLocation
  {
    kLeft = 0x1,
    kTop = 0x2,
    kRight = 0x4,
    kBottom = 0x8,
  };

  enum ButtonStyle
  {
    kButtonStyleNone = 0,
    kButtonStyleFlat = 0x1,
    kButtonStyleCheck = 0x2,

    kButtonHCenter = 0x00000300,
    kButtonVCenter = 0x00000C00,
  };

public:
  CGdUiBitmapTextButton();
  ~CGdUiBitmapTextButton();

protected:
  void DrawButton(
    CDC& dc,
    int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused) override;
  BOOL OnAutoLoad() override;
  BOOL OnReload(LPCTSTR strResId) override;
  BOOL OnLoadBitmap(LPCTSTR strResId) override;

public:
  BOOL                GetAutoSizeToContent();
  void                SetAutoSizeToContent(BOOL autoSizeToContent);
  void                SizeToContent();
  void                SetContentOffsets(int nBorderOffset,
    int nFocusRectOffset);
  UINT                GetButtonType();
  UINT                GetBitmapLocation();
  UINT                SetButtonType(UINT btnType);
  UINT                SetBitmapLocation(UINT imgPos);

  ButtonStyle			GetBitmapTextButtonStyle() const;
  void				SetBitmapTextButtonStyle(ButtonStyle nBtnStyle);

  DECLARE_MESSAGE_MAP()
public:
  BOOL				GetAutoSizeToBitmap();
  void				SetAutoSizeToBitmap(BOOL autoSizeToBitmap);
  void				SizeToBitmap();
  void				SetBitmapOffsets(int nBorderOffset, int nFocusRectOffset);

  void				SetBkColor(COLORREF);
  void				SetBorderColor(COLORREF);

  void				SetCheck(int nCheck);
  int					GetCheck();

  HICON				SetIcon(HICON hIcon, BOOL bRedraw = TRUE);
  HICON				GetIcon() const;
  HBITMAP				SetBitmap(HBITMAP hBitmap, BOOL bRedraw = TRUE);
  HBITMAP				GetBitmap() const;
private:
  void*               mpImpObj;
};

class GCAD_PORT CGdUiThemedDropDownBitmapButton : public CGdUiBitmapButton
{
  DECLARE_DYNAMIC(CGdUiThemedDropDownBitmapButton)
public:
  enum
  {
    BitmapButtonSize = 24,
    MenuButtonWidth = 15,
  };
  CGdUiThemedDropDownBitmapButton();
  ~CGdUiThemedDropDownBitmapButton();

  BOOL            GetMainButtonSelected();
  void            SetMainButtonSelected(BOOL selected);
  BOOL            GetMenuButtonSelected();
  void            SetMenuButtonSelected(BOOL selected);
  void            ClearClick();

  virtual int     GetMenuButtonWidth();
  virtual bool    SetMenuButtonWidth(int width);

protected:
  BOOL    m_bMainButtonSelected;
  BOOL    m_bMenuButtonSelected;
  int     m_menuButtonWidth;

protected:
  void DrawButton(
    CDC& dc,
    int w, int h,
    BOOL isDefault,
    BOOL isDisabled,
    BOOL isSelected,
    BOOL isFocused) override;

  afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
  afx_msg void OnKillFocus(CWnd *pNewWnd);
  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
  afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

  DECLARE_MESSAGE_MAP()
};

#endif 


#pragma pack (pop)
#endif
