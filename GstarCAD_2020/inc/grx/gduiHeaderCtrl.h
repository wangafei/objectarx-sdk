#ifndef _GduiHeaderCtrl_h
#define _GduiHeaderCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGdUiHeaderCtrl window
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiHeaderCtrl : public CHeaderCtrl {
    DECLARE_DYNAMIC(CGdUiHeaderCtrl)

public:
                CGdUiHeaderCtrl ();
virtual         ~CGdUiHeaderCtrl ();

// Misc.
protected:
        // store the last mouse point recorded
        CPoint  m_lastMousePoint;
        int     m_tipItem;
        CRect   m_tipRect;

public:
virtual void    GetContentExtent (
                    int item, LPCTSTR text, int& width, int& height
                 );
        int     GetItemAtPoint (CPoint& p);
        BOOL    GetItemRect (int idx, CRect& rItem);
        BOOL    GetText (int idx, CString& text);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    IsOwnerDraw (int idx);

// GdUi message handlers
protected:
        CWnd    *m_iduiParent;

virtual GDUI_REPLY DoGdUiMessage (
                    GDUI_NOTIFY notifyCode, UINT controlId, LPARAM lParam
                );
virtual void    OnDrawTip (CDC& dc);
virtual BOOL    OnDrawTipText (CGdUiDrawTipText& dtt);
virtual GDUI_REPLY OnGetTipSupport (CPoint& p);
virtual BOOL    OnGetTipRect (CRect& r);
virtual BOOL    OnGetTipText (CString& text);
virtual BOOL    OnHitTipRect (CPoint& p);
public:
        CWnd    *GetGdUiParent ();
        void    SetGdUiParent (CWnd *w);

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CGdUiHeaderCtrl)
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGdUiHeaderCtrl)
    afx_msg LRESULT OnGdUiMessage (WPARAM wParam, LPARAM lParam);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};
#pragma warning(pop)
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
