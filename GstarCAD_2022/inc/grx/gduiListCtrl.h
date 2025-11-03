#ifndef _GduiListCtrl_h
#define _GduiListCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGdUiListCtrl window
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiListCtrl : public CListCtrl {
    DECLARE_DYNAMIC(CGdUiListCtrl);

public:
                CGdUiListCtrl ();
 virtual         ~CGdUiListCtrl ();

// Misc.
protected:
        CPoint  m_lastMousePoint;
        int     m_tipIndex;
        int     m_tipItem;
        CRect   m_tipRect;

public:
        CGdUiHeaderCtrl m_headerCtrl;

        int     ColumnCount ();
virtual void    GetContentExtent (
                    int item, int index, LPCTSTR text, int& width, int& height
                 );
        BOOL    GetItemAtPoint (CPoint& p, int& item, int& index);
        BOOL    GetSubItemRect (int item, int index, CRect& rect);
        void    GetTextExtent (LPCTSTR text, int& width, int& height);
        BOOL    IsOwnerDraw ();

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
    //{{AFX_VIRTUAL(CGdUiListCtrl)
    protected:
    virtual void PreSubclassWindow();
    //}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGdUiListCtrl)
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
