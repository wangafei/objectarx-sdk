
#pragma once

#include "zadui_port.h"

class CZdUiTab;
class CZdUiTabChildDialog;
class CZdUiTabMainDialog;

#pragma pack (push, 8)

class ZDUI_PORT CZdUiTabExtensionManager {
public:
                CZdUiTabExtensionManager ();
virtual         ~CZdUiTabExtensionManager ();

private:
        CString m_dlgName;
        CZdUiTabMainDialog *m_pDlg;
        CZdUiTab *m_pTabCtrl;

        BOOL    AddApplicationTabs (LPCTSTR pszAppName);
public:

        int     AddExtendedTabs ();

virtual BOOL    AddTab (
                    HINSTANCE hInstRes,
                    UINT uTemplateID,
                    LPCTSTR pszTabName,
                    CZdUiTabChildDialog *pDialog
                );

virtual LPCTSTR GetDialogName ();

        void    Initialize (CZdUiTab *pTabCtrl, CZdUiTabMainDialog *pDlg);

        CZdUiTab* GetTabControl() const {return m_pTabCtrl;}
};

#pragma pack (pop)

