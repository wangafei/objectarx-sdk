
#pragma once

#include "zadui_port.h"

#pragma pack (push, 8)

#ifndef _ZSOFT_MAC_

class CZdUiDrawTipText;

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiEdit : public CEdit {
    DECLARE_DYNAMIC(CZdUiEdit)

public:
                CZdUiEdit ();
virtual         ~CZdUiEdit ();

protected:
        CPoint  m_lastMousePoint;
        CRect   m_tipRect;

public:
virtual void    GetContentExtent (LPCTSTR text, int& width, int& height);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);

public:
        DWORD   m_styleMask;

virtual void    SetStyleMask (DWORD);
        DWORD   GetStyleMask ();
        BOOL    IsStyleMaskSet (DWORD);

protected:
        CWnd    *m_zduiParent;

virtual ZDUI_REPLY DoZdUiMessage (
                    ZDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual void    OnDrawTip (CDC& dc);
virtual BOOL    OnDrawTipText (CZdUiDrawTipText& dtt);
virtual ZDUI_REPLY OnGetTipSupport (CPoint& p);
virtual BOOL    OnGetTipRect (CRect& r);
virtual BOOL    OnGetTipText (CString& text);
virtual BOOL    OnHitTipRect (CPoint& p);
public:
        CWnd    *GetZdUiParent ();
        void    SetZdUiParent (CWnd *w);

public:

protected:

    afx_msg LRESULT OnZdUiMessage (WPARAM wParam, LPARAM lParam);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);

    DECLARE_MESSAGE_MAP()
};

class    CZdUiSearchBoxEditor;
class    CZdUiSearchBoxSearchButton;
class    CZdUiSearchBoxClearButton;

class ZDUI_PORT CZdUiSearchBox : public CZdUiEdit{
    DECLARE_DYNAMIC(CZdUiSearchBox)

public:
                CZdUiSearchBox ();
	virtual         ~CZdUiSearchBox ();
virtual BOOL    Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	virtual void    PreSubclassWindow() override;
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
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam) override;

	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) override;
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
    CZdUiSearchBoxEditor*    m_pEditor;
    CZdUiSearchBoxSearchButton*      m_pBtnSearch;
    CZdUiSearchBoxClearButton*   m_pBtnClear;

    CString                 m_strNotification;
    CString                 m_strDefaultText;
};
#pragma warning(pop)

#endif

#pragma pack (pop)

