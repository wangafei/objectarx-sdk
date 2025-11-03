
#pragma once

#include "zAdAChar.h"
#include "zaduitheme.h"

#pragma pack (push, 8)
#ifndef _ZSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)

class CZdUiRichEditCtrl;

class ZDUI_PORT CZdUiRichEditThemeModReactor : public CZdUiThemeModifiedReactor  
{
public:
    CZdUiRichEditThemeModReactor(CZdUiRichEditCtrl* pCtrl);

    virtual void ThemeModified(const CZdUiTheme * pTheme, ZdUiThemeElement element) override;  

private:
    CZdUiRichEditCtrl * m_pCtrl;
};

class ZDUI_PORT CZdUiRichEditCtrl: public CRichEditCtrl{
    friend class CZdUiRichEditThemeModReactor;

    DECLARE_DYNAMIC(CZdUiRichEditCtrl)

public:
                CZdUiRichEditCtrl (bool bIsThemed = false);
virtual         ~CZdUiRichEditCtrl ();

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

        void SetTitle(LPCTSTR pszTitle) {m_csTitle = pszTitle;} ;

        virtual BOOL PreTranslateMessage(MSG* pMsg) override;

static  bool m_bInitOnce;

protected:
     CWnd    *m_zduiParent;

public:

protected:

    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnSetFocus(CWnd* pOldWnd);
    afx_msg void OnSize(UINT nType, int cx, int cy);
    afx_msg BOOL OnEnLink(NMHDR *pNMHDR, LRESULT *pResult);

    DECLARE_MESSAGE_MAP()

    virtual void ThemeModified(ZdUiThemeElement element);

private:
    CString m_csTitle;
    CString m_csText;
    int     m_horizontalMargin;
    int     m_verticalMargin;
    bool    m_bIsThemed;
    CZdUiRichEditThemeModReactor    * m_pThemeModReactor;
    CZdUiTheme * m_pTheme;
    COLORREF mBackgroundColor;
    COLORREF mTextColor;
};

#pragma warning(pop)

#endif

#pragma pack (pop)

