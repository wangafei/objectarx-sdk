
#pragma once

#include "zadui_port.h"

#pragma pack (push, 8)
#ifndef _ZSOFT_MAC_

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdUiTipWindow : public CWnd {
    DECLARE_DYNAMIC(CZdUiTipWindow)

public:
                CZdUiTipWindow ();
virtual         ~CZdUiTipWindow ();

private:
        void    ForwardClickMessage (UINT msg, UINT nFlags, CPoint& point, BOOL focus);
protected:
static  LPCTSTR m_className;
static const UINT_PTR m_timerEvent;

        BOOL    m_bUseText;
        CWnd    *m_control;
        CWnd    *m_owner;
        UINT_PTR m_timerId;

virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior);
virtual void    DrawContent (CDC& dc, CRect& rInterior);
        void    StartTimer (DWORD ms=50);
        void    StopTimer ();
public:
virtual BOOL    Create (CWnd *owner);
        CWnd    *GetControl ();
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    GetUseText ();
virtual void    Hide ();
        CWnd    *Owner ();
        void    SetControl (CWnd *control);
        void    SetUseText (BOOL useText);
virtual void    Show ();

public:

protected:

    afx_msg void OnActivateApp(BOOL bActive, DWORD hTask);
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnNcDestroy();
    afx_msg void OnPaint();
    afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnTimer(UINT_PTR nIDEvent);

    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)

class ZDUI_PORT CZdUiBalloonTip : public CZdUiTipWindow {
    DECLARE_DYNAMIC(CZdUiBalloonTip)

public:
                CZdUiBalloonTip ();
virtual         ~CZdUiBalloonTip ();

protected:
        CPoint  m_initialCursorPos;

virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior) override;
virtual void    DrawContent (CDC& dc, CRect& rInterior) override;

public:
virtual void    Hide () override;
virtual void    Show () override;

public:

protected:

    afx_msg void OnTimer(UINT_PTR nIDEvent);

    DECLARE_MESSAGE_MAP()
};

class ZDUI_PORT CZdUiTextTip : public CZdUiTipWindow {
    DECLARE_DYNAMIC(CZdUiTextTip)

public:
                CZdUiTextTip ();
virtual         ~CZdUiTextTip ();

protected:
virtual void    DrawBorder (CDC& dc, CRect& rExterior, CRect& rInterior) override;
virtual void    DrawContent (CDC& dc, CRect& rInterior) override;
public:
virtual void    Hide () override;
        void    Update (CWnd *control, BOOL useText);
        void    UpdateIfNecessary (CWnd *control, BOOL useText);

public:

    virtual BOOL PreCreateWindow(CREATESTRUCT& cs) override;

protected:

    DECLARE_MESSAGE_MAP()
};

class ZdToolTip;

#pragma warning(push)
#pragma warning(disable : 4275)
class ZDUI_PORT CZdToolTipCtrl : public CToolTipCtrl{

    DECLARE_MESSAGE_MAP()
public:
    CZdToolTipCtrl();
	virtual ~CZdToolTipCtrl ();

	virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult) override;
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnDestroy();
    static void SetToolTipsFlag(BOOL bToolTipsFlag);
    static void SetDeaultDelayTime(int nDelay);

    BOOL AddTool(_In_ CWnd* pWnd, _In_ UINT nIDText,
                 _In_opt_ LPCRECT lpRectTool = nullptr, _In_ UINT_PTR nIDTool = 0) {
        return CToolTipCtrl::AddTool(pWnd, nIDText, lpRectTool, nIDTool);
    }

    BOOL AddTool(_In_ CWnd* pWnd, _In_z_ LPCTSTR lpszText = LPSTR_TEXTCALLBACK,
                 _In_opt_ LPCRECT lpRectTool = nullptr, _In_ UINT_PTR nIDTool = 0);

    void UpdateTipText(_In_ UINT nIDText, _In_ CWnd* pWnd, _In_ UINT_PTR nIDTool = 0) {
        return CToolTipCtrl::UpdateTipText(nIDText, pWnd, nIDTool);
    }

    void UpdateTipText(_In_z_ LPCTSTR lpszText, _In_ CWnd* pWnd, _In_ UINT_PTR nIDTool = 0);

protected:
    virtual ZdToolTip * CreateZdToolTipInstance();
    ZdToolTip* m_pToolTip { nullptr };
    BOOL m_bActivate { true };
    UINT m_nDelayTime { 0 };

private:
    static BOOL m_bToolTipHasCreated;
    static BOOL m_bToolTipsFlag;
    static UINT m_nDefaultDealyTime;
};
#pragma warning(pop)

class ZdWthToolTip;

class ZDUI_PORT CZdWthToolTipCtrl : public CZdToolTipCtrl
{
    DECLARE_MESSAGE_MAP()
public:
    ZdWthToolTip* GetWthToolTip();
protected:
	virtual ZdToolTip * CreateZdToolTipInstance() override;
};

void ZDUI_PORT ZdUiHideBalloonTip (CWnd *control);
BOOL ZDUI_PORT ZdUiShowBalloonTip (
    CWnd *owner, CWnd *control, LPCTSTR text, BOOL beep
);
BOOL ZDUI_PORT ZdUiShowBalloonTip (
    CWnd *owner, CWnd *control, CRect& rect, LPCTSTR text, BOOL beep
);

#endif

#pragma pack (pop)

