#ifndef _GduiTabExtension_h
#define _GduiTabExtension_h
#pragma pack (push, 8)

//#include "gdui.h"

/////////////////////////////////////////////////////////////////////////////
// This class manages extended tabs in a tab extensible dialog.
// A tab extensible dialog has one instance of this class in the
// dialog object which is initialized in the dialog's constructor.

class GDUI_PORT CGdUiTabExtensionManager {
public:
                CGdUiTabExtensionManager ();
 virtual         ~CGdUiTabExtensionManager ();    

// Tab Extension Manager
private:
        CString m_dlgName;              // Buffer for GetDialogName().
        CGdUiTabMainDialog *m_pDlg;     // The tab extensible dialog.
        CGdUiTab *m_pTabCtrl;           // The tab control in the dialog.

        // Adds tabs to a dialog that have been registered by a particular application.
        BOOL    AddApplicationTabs (LPCTSTR pszAppName);
public:
        // This function in called in the OnInitDialog() of a tab extensible
        // dialog to add extended tabs to itself.
        int     AddExtendedTabs ();

        // Actually adds an extended tab.
virtual BOOL    AddTab (
                    HINSTANCE hInstRes,
                    UINT uTemplateID,
                    LPCTSTR pszTabName,         // since templates don't have captions...
                    CGdUiTabChildDialog *pDialog
                 );

        // Return the dialog name used as a registry key for extended tabs.
 virtual LPCTSTR GetDialogName ();
    
        // Initialize the manager.
        void    Initialize (CGdUiTab *pTabCtrl, CGdUiTabMainDialog *pDlg);

        CGdUiTab* GetTabControl() const {return m_pTabCtrl;}
};

/////////////////////////////////////////////////////////////////////////////

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
