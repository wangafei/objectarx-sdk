
#pragma once

#include "zacarray.h"
#include "zadui_port.h"

#pragma pack (push, 8)
class CZdUiTheme;

typedef void (*ZdUiBmpBtnFcnPtr)(CWnd*);

typedef struct ZdUiGroupCtrlData
{
    ZdUiGroupCtrlData() : nWndIndex(0), title(""), pWnd(NULL), dwBtnCookie(DWORD_MAX) {};
    int nWndIndex;
    CString title;
    CWnd* pWnd;
    DWORD dwBtnCookie;
} groupData;
typedef ZcArray<groupData> ZDUIGROUPCTRLDATALIST;

typedef struct ZdUiBmpBtnData
{
    ZdUiBmpBtnData() : pBmp(NULL), fcnPtr(NULL),
                       tooltip(""), dwCookie(0) {};

    CString strResId;
    CBitmap* pBmp;
    ZdUiBmpBtnFcnPtr fcnPtr;
    CString tooltip;
    DWORD dwCookie;
} bmpBtnData;
typedef ZcArray<bmpBtnData> ZDUIHEADERBTNLIST;

#define ZDUI_NCHT_BASE      (HTHELP + 200)
#define ZDUI_NCHT_TITLE     ZDUI_NCHT_BASE
#define ZDUI_NCHT_CHEVRON   (ZDUI_NCHT_BASE + 1)
#define ZDUI_NCHT_BUTTON    (ZDUI_NCHT_BASE + 2)

#define ZDUI_GROUP_BORDER_SIZE              1
#define ZDUI_GROUP_TITLE_HEIGHT             22
#define ZDUI_GROUP_TITLE_BEVELSIZE          5
#define ZDUI_GROUP_TITLE_TEXTLEFT           8
#define ZDUI_GROUP_TITLE_TEXTTOP            1
#define ZDUI_GROUP_TITLE_TEXTBOTTOM         5
#define ZDUI_GROUP_BUTTON_SIZE              14
#define ZDUI_GROUP_BUTTONS_RIGHT            25
#define ZDUI_GROUP_CHEVRON_TOPPADDING       5
#define ZDUI_GROUP_CHEVRON_BOTTOMPADDING    4
#define ZDUI_GROUP_BUTTON_TOPPADDING        2
#define ZDUI_GROUP_BUTTON_BOTTOMPADDING     2
#define ZDUI_GROUP_BUTTON_SPACE             3
#define ZDUI_GROUP_CHEVRON_RIGHT            4
#define ZDUI_GROUP_EXPANDER_RIGHT_OFFSET    7
#define ZDUI_GROUP_CHILD_VERT_SPACE         8

#define ZDUI_GROUP_BUTTON_DISABLE_FLAG  0x80000000
#define ZDUI_GROUP_BUTTON_SELECTED_FLAG 0x40000000
#define ZDUI_GROUP_BUTTON_ID_MASK       0x0000FFFF

#define ZDUI_GROUP_STYLE_CHEVRON        0x00000001
#define ZDUI_GROUP_STYLE_SHOWBTNFORCE   0x00000002
#define ZDUI_GROUP_STYLE_NONACTIVE      0x00000004
#define ZDUI_GROUP_STYLE_NOBORDER       0x00000008
#define ZDUI_GROUP_STYLE_TRANSBTN       0x00000010
#define ZDUI_GROUP_STYLE_BTNBORDER      0x00000020
#define ZDUI_GROUP_STYLE_ACTIVEHEADER   0x00000040
#define ZDUI_GROUP_STYLE_OPAQUEIMAGE    0x00000080
#define ZDUI_GROUP_STYLE_STRETCHIMAGE   0x00000100

const DWORD WM_ZDUI_VISIBILITY_CHANGING = WM_USER + 1936;

#pragma warning(push)
#pragma warning(disable : 4275)

class ZDUI_PORT CZdUiGroupCtrl : public CStatic {
    DECLARE_DYNAMIC(CZdUiGroupCtrl);

public:

    CZdUiGroupCtrl( );

    virtual ~CZdUiGroupCtrl();

    virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, CBitmap* pBMP = NULL);

    virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszToolTip, CBitmap* pBMP);

    virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszResName);

    virtual bool AddWnd(CWnd* pWnd, LPCTSTR pszTitle, LPCTSTR pszToolTip, LPCTSTR pszResName);

    virtual bool ShowWnd(CWnd* pWnd);

    virtual bool AddBmpBtnToHeader(LPCTSTR pszResName,
                                   ZdUiBmpBtnFcnPtr fcnPtr,
                                   DWORD& dwCookie,
                                   LPCTSTR pszToolTip);

    virtual bool AddBmpBtnToHeader(CBitmap* pBmp,
                                   ZdUiBmpBtnFcnPtr fcnPtr,
                                   DWORD& dwCookie,
                                   LPCTSTR pszToolTip);

    virtual bool RemoveBmpBtnFromHeader(DWORD dwCookie);

    virtual void ModGroupStyle(DWORD styleRemove, DWORD styleAdd);

    CZdUiTheme* GetTheme() const;

    virtual void SetTheme(CZdUiTheme* pTheme);

    virtual void SetFont(CFont* pFont);

    virtual void SetFont(CFont* pFont, BOOL bRedraw);

    virtual void SetMinimized(bool bMinimized);

    bool GetMinimized() const;

    void SetTitle(LPCTSTR pszTitle) { m_csTitle = pszTitle; }

    CString GetTitle() { return m_csTitle; }

    void SetHeaderHeight(int nHeight) { m_nHeaderHeight = nHeight; }

    int GetHeaderHeight() { return m_nHeaderHeight; }

    void SetStyle(DWORD nStyle) { m_nStyle = nStyle; }

    DWORD GetStyle() { return m_nStyle; }

    void SetSelIndex(int nSelIndex);

    int GetSelIndex();

    void SetHideGroupHeader(bool bHide) {
        m_bHideGroupHeader = bHide;
    }

    bool GetHideGroupHeader() {
        return m_bHideGroupHeader;
    }

    void SetActive(bool bActive);

    bool GetActive() { return m_bActive; }

    void SetUseDialogTheme(bool bUseDialogTheme);

    bool UseDialogTheme() const;

protected:

    virtual void DrawGroupContent(CDC* pDC);

    virtual void DrawGroupHeader(CDC* pDC);
    virtual void DeselectGroupHeader() {
        CDC* pDC = GetWindowDC();
        DrawGroupHeader(pDC);
        ReleaseDC(pDC);
    }
    void OnChevronClicked();

    void DrawHeaderBorder(CDC   *pDC, CRect &rect);
	virtual BOOL PreTranslateMessage(MSG* pMsg) override;
    static CZdToolTipCtrl* GetToolTipControl();

protected:

    afx_msg void OnNcPaint();
    afx_msg void OnPaint();
    afx_msg void OnNcCalcSize( BOOL bCalcValidRects, NCCALCSIZE_PARAMS * );
    afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
    afx_msg void OnSize( UINT nType, int cx, int cy );
    afx_msg void OnNcLButtonDown( UINT nHitTest, CPoint );
    afx_msg void OnNcLButtonDblClk( UINT nHitTest, CPoint );
#if _MSC_VER<1400
    afx_msg UINT OnNcHitTest(CPoint point);
#else
    afx_msg LRESULT OnNcHitTest(CPoint point);
#endif
    afx_msg void OnSetFocus( CWnd * pOldWnd );
    afx_msg void OnKillFocus( CWnd * pNewWnd );
    afx_msg BOOL OnEraseBkgnd(CDC*) { return TRUE;};
    afx_msg HBRUSH OnCtlColor(CDC*, CWnd*, UINT);

    DECLARE_MESSAGE_MAP()

protected:

    CZdUiTheme* m_pTheme;

protected:
    CString         m_csTitle;
    bool            m_bMinimized;
    bool            m_bUseDialogTheme;
    bool            m_bActive;
    bool            m_bHideGroupHeader;
    int             m_nHeaderHeight;
    int             m_nRestoreHeight;
    int             m_nSelIndex;
    DWORD           m_nStyle;
    DWORD           m_dwBtnId;

    ZDUIHEADERBTNLIST       m_bmpBtnList;
    ZDUIGROUPCTRLDATALIST   m_groupList;

    static LOGFONT& font();
private:

    static LOGFONT          m_lf;

    class CAdUiGroupCtrlImp;
    CAdUiGroupCtrlImp* m_imp;
};

inline bool CZdUiGroupCtrl::GetMinimized() const
{
    return m_bMinimized;
}

inline void CZdUiGroupCtrl::SetMinimized( bool bMinimized )
{
    m_bMinimized = bMinimized;
}

inline bool CZdUiGroupCtrl::UseDialogTheme() const
{
    return m_bUseDialogTheme;
}

inline CZdUiTheme* CZdUiGroupCtrl::GetTheme() const
{
    return m_pTheme;
}

#pragma warning(pop)

#pragma pack (pop)

