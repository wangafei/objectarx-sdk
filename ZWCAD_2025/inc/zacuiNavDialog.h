
#pragma once

#include "zANav.h"
#include "zacui_port.h"

class CZcUiNavPreviewButton;

typedef enum
{

    zcUiOpenNoTemplateNone      =   0x0000,
    zcUiOpenNoTemplateImperail  =   0x0001,
    zcUiOpenNoTemplateMetric    =   0x0002
} ZcUiOpenNoTemplateFlag;

class ZCUI_PORT CZcUiNavDialog : public CNavDialog {
    DECLARE_DYNAMIC(CZcUiNavDialog)

    public:

        CZcUiNavDialog (
            CNavDataArray& dataArray,
            CNavFilterArray& filterArray,
            UINT idd=0,
            CWnd *pParent=NULL,
            HINSTANCE hDialogResource=NULL
        );
        virtual ~CZcUiNavDialog ();

        virtual BOOL OnInitDialog () override;

        virtual BOOL GetRecentDirectory(CString& strRecent) override;

        virtual BOOL FindInSearchPath(LPCTSTR sBase, CString* pFullPath) override;

        virtual void GetDefaultBrowserStartURL(CString& strStartPage) override;

        virtual BOOL LaunchBrowserDialog(CString& strSelectedURL, LPCTSTR strDialogCaption,
            LPCTSTR strOk, LPCTSTR strStartPage) override;

        virtual void DisplaySearchError(LPCTSTR sBase) override;

        virtual void OnDoLocate() override;

        virtual BOOL GetProductName(CString& strProduct) override;

        virtual BOOL BeginDownloadFiles(CStringArray& strURLs, CDWordArray& dwActionCodes) override;

        virtual DWORD GetDownloadActionCodes(CString& strURL) override;

        virtual void OnPaintPreview(LPCTSTR strFullPath, CWnd* previewWnd);

        virtual void OnDialogHelp() override;
        virtual void OnDialogHelp(LPCTSTR pTag) override;

        BOOL GetPreviewPresent();
        void SetPreviewPresent(BOOL preview);
        BOOL GetPreviewVisible();
        void SetPreviewVisible(BOOL visible);
        BOOL GetInitialViewButtonChecked();
        void ConvertFlagsToState(int nFlags);

        ZcUiOpenNoTemplateFlag GetOpenNoTemplateSelection();

        short GetUpdateThumbnailOverride();

        void SetUseRememberFolders(bool bUseRememberFolders);
        bool GetUseRememberFolders() const;

public:

        virtual void EnableFloatingWindows (BOOL allow) override;
        virtual int IsMultiDocumentActivationEnabled() override;
        virtual int EnableMultiDocumentActivation(BOOL bEnable) override;

    protected:
        virtual void OnFolderItemChange() override;     
        virtual void OnFilterChange() override;         
        virtual BOOL OnFileNameOK () override;          
        virtual void OnFileNameChange () override;      
        virtual void PrepareOkMenu(CMenu* pMenu) override;
        virtual void PrepareViewsMenu(CMenu* pMenu) override;
        virtual void PrepareToolsMenu(CMenu* pMenu) override;
        virtual void OnURLDownloadSuccess(CString& strURL) override;
        virtual BOOL GetOptionsState();
        virtual void OnCancel() override;
        virtual void OnOK() override;

        void Do3DDwfOptionsDialog();
        void InitPreviewState();

    protected:

        afx_msg void OnOpenNoTemplateImperial();
        afx_msg void OnOpenNoTemplateMetric();
        afx_msg void OnOpenMenuPartialOpen();
        afx_msg void OnOpenMenuPartialOpenReadOnly();
        afx_msg void OnViewsMenuPreview();
        afx_msg void OnToolsMenuOptions();
        afx_msg void OnToolsMenuSecurity();
        afx_msg void OnDestroy();
        afx_msg void OnUpdateThumbnailCheck();
        afx_msg void OnOnlineOptions();
        afx_msg void OnShowReferenceFiles();

        DECLARE_MESSAGE_MAP()

    private:

        short m_CmdInProgress;
        short m_nUpdateThumbnailOverride;
        BOOL m_bIsOpen;
        BOOL m_bIsSaveAs;
        BOOL m_bIsRecover;
        BOOL m_bPartialOpenAlwaysDisabled;
        BOOL m_bInitialViewButtonPresent;
        BOOL m_bInitialViewButtonChecked;
        BOOL m_bPartialOpenPresent;
        BOOL m_bOptionsPresent;
        BOOL m_bPreviewPresent;
        BOOL m_bPreviewVisible;
        BOOL m_bOpenNoTemplate;
        ZcUiOpenNoTemplateFlag m_nOpenNoTemplateSelection;
        CZcUiNavPreviewButton* m_previewButton;
        BOOL m_bIsExport;
        BOOL CanPartiallyOpen(LPCTSTR szfullPath);
        bool ApplyRememberFoldersInitialization(int rememberFolders);
        bool ApplyRememberFoldersOnOk();
        bool m_bUseRememberFolders;
        void HideControls();
        void UpdateInitialFolder();
        int  CheckSharedFilePrivileges(const CString & filename);

        static BOOL m_bOriginalMultiSelAllowed;
        BOOL m_bOpenSample;

};

