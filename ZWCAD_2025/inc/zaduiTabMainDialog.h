
#pragma once

#include "zaduiDialog.h"
#include "zaduiTabExtension.h"

#pragma pack (push, 8)
#ifndef _ZSOFT_MAC_

class ZDUI_PORT CZdUiTabMainDialog : public CZdUiDialog {
friend class CZdUiTab;

    DECLARE_DYNAMIC(CZdUiTabMainDialog);

public:
                CZdUiTabMainDialog (
                    UINT idd,
                    CWnd *pParent=NULL,
                    HINSTANCE hDialogResource=NULL
                );

private:

        int m_idDefaultButton;

        CZdUiTab *m_pZcadTab;

        CString m_strTabIndex;

        BOOL    TranslateTabKey ();
protected:
        void    SetZcadTabPointer (CZdUiTab *pZcadTab);

public:

        int     AddExtendedTabs ();

        int     GetDefaultButton ();

        CZdUiTab *GetTabControl ();

        void    SetDefaultButton (int nIdDefaultButton);

        void    UpdateDefaultButton (HWND hFocusBefore, HWND hFocusAfter);

        void    SetInitialTabIndex(LPCTSTR strTabIndex) {m_strTabIndex = strTabIndex;}
        LPCTSTR GetInitialTabIndex() {return m_strTabIndex;}
        int     GetInitialRequestedTabIndex();

protected:
virtual void    OnInitDialogBegin () override;
virtual void    OnInitDialogFinish () override;

protected:
        CZdUiTabExtensionManager m_xtabManager;

public:
virtual BOOL    AddApplicationTabs (LPCTSTR pszAppName);
        CZdUiTabExtensionManager *GetXtabPointer ();

public:
        BOOL    AddTab (
                    int iPos, LPCTSTR tabName,
                    UINT uTemplateID, CZdUiTabChildDialog *pDialog
                );
        BOOL    AddTab (
                    int iPos, UINT uTabStringID,
                    UINT uTemplateID, CZdUiTabChildDialog *pDialog
                );
        int     GetTabIndex (CZdUiTabChildDialog *pDialog);
        BOOL    RemoveTab (int iPos);

public:

    enum { IDD = 0 };

public:
    virtual BOOL PreTranslateMessage(MSG* pMsg) override;        
protected:
	virtual void DoDataExchange(CDataExchange* pDX) override;    
    virtual void OnCancel() override;
    virtual void OnOK() override;
    void RaiseApplyEvent();

protected:

    afx_msg void OnSize(UINT nType, int cx, int cy);

    DECLARE_MESSAGE_MAP()
};

#endif

#pragma pack (pop)

