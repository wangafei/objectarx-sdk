#ifndef GCUINAVDIALOG_H_
#define GCUINAVDIALOG_H_
#include "gnav.h"

// Forward class declarations.
class CGcUiNavPreviewButton;

typedef enum
{
  // Open with no template flags
	gcUiOpenNoTemplateNone      =   0x0000,
	gcUiOpenNoTemplateImperail  =   0x0001,
	gcUiOpenNoTemplateMetric    =   0x0002
} GcUiOpenNoTemplateFlag;

/////////////////////////////////////////////////////////////////////////////
// File Navigation dialog - this is the GCAD file navigation dialog.
class GCUI_PORT CGcUiNavDialog : public CNavDialog {
  DECLARE_DYNAMIC(CGcUiNavDialog)

public:

  // Constructor and destructor.
  CGcUiNavDialog (
    CNavDataArray& dataArray,           // For results of the dialog.
    CNavFilterArray& filterArray,       // Files of type.
    UINT idd=0,                         // Template id, 0 means use the default template for GCAD dialog.
    CWnd *pParent=NULL,                 // Dialog parent. NULL means the desktop.
    HINSTANCE hDialogResource=NULL      // Resource ID where template is found. NULL means use the default.
    );
  virtual ~CGcUiNavDialog ();

  // Dialog initialization.
  virtual BOOL OnInitDialog ();

  // Get the "Recent" directory under the "Application Data"
  // directory of the OS for use with the "History" places item.
  virtual BOOL GetRecentDirectory(CString& strRecent);

  // Locate a file in a search path for use with the "Locate" tools menu item.
  virtual BOOL FindInSearchPath(LPCTSTR sBase, CString* pFullPath);

  // Get the default URL to use in the web browser when the web button is selected.
  virtual void GetDefaultBrowserStartURL(CString& strStartPage);

  // Launch a browser and get a URL. Called when the web button is selected.
  virtual BOOL LaunchBrowserDialog(CString& strSelectedURL, LPCTSTR strDialogCaption,
    LPCTSTR strOk, LPCTSTR strStartPage);

  // Display an error in trying to locate a file in the search path when the "Locate"
  // tools menu item is selected.
  virtual void DisplaySearchError(LPCTSTR sBase);

  // Called when the user choses "Locate" form tools menu.
  virtual void OnDoLocate();

  // Return the product name to be used when registering extensions.
  virtual BOOL GetProductName(CString& strProduct);

  // Called at the start of a remote file download operation.        
  virtual BOOL BeginDownloadFiles(CStringArray& strURLs, CDWordArray& dwActionCodes);

  // Callback to get additional action code bits for a remote download.
  virtual DWORD GetDownloadActionCodes(CString& strURL);

  // Called when the preview needs painting after it has been erased.
  virtual void OnPaintPreview(LPCTSTR strFullPath, CWnd* previewWnd);

  // Called when the help button is selected.
  virtual void OnDialogHelp();
  virtual void OnDialogHelp(LPCTSTR pTag);

  BOOL GetPreviewPresent();              // Does the dialog have an GCAD preview window?
  void SetPreviewPresent(BOOL preview);  // Set the GCAD preview window as present.
  BOOL GetPreviewVisible();              // Is the GCAD preview window visible?
  void SetPreviewVisible(BOOL visible);  // Set the GCAD preview window visible.
  BOOL GetInitialViewButtonChecked();    // Is the initial view checkbox checked?
  void ConvertFlagsToState(int nFlags);  // Sets up dialog internal state. FOR INTERNAL USE ONLY.

  GcUiOpenNoTemplateFlag GetOpenNoTemplateSelection();

  short GetUpdateThumbnailOverride();      // Get the override value for the UPDATETHUMBNAIL sysvar

public:
  //CAdUiBaseDialog overrides

  //turn off warning about non-standard extensions used, 
  //but still use the override keyword on the MS compiler
  //to get early warning if these are no longer overrides
#pragma warning(push)
#pragma warning(disable: 4481)
  virtual void EnableFloatingWindows (BOOL allow);
  virtual int IsMultiDocumentActivationEnabled();
  virtual int EnableMultiDocumentActivation(BOOL bEnable);
#pragma warning(pop)

protected:
  virtual void OnFolderItemChange();     // Called when the selection changes.
  virtual void OnFilterChange();         // Called when the filter changes.
  virtual BOOL OnFileNameOK ();          // Called when the commit button is clicked.
  virtual void OnFileNameChange ();      // Called when thetext changes in the file name editbox.
  virtual void PrepareOkMenu(CMenu* pMenu);// Possibly alter the base ok menu.
  virtual void PrepareViewsMenu(CMenu* pMenu);// Possibly alter the base views menu.
  virtual void PrepareToolsMenu(CMenu* pMenu);// Possibly alter the base tools menu.
  virtual void OnURLDownloadSuccess(CString& strURL);// Called when checking for errors after downloading files.
  virtual BOOL GetOptionsState();        // Check for a tab in the options dialog for the current combination of filetype and get/put file..
  virtual void OnCancel();

  void Do3DDwfOptionsDialog();           // Display the 3D Dwf option dialog.
  void DoFbxOptionsDialog();             // Display the FBX options dialog.
  void InitPreviewState();               // Initialize the preview control.

protected:
  //{{AFX_MSG(CGcUiNavDialog)
  afx_msg void OnOpenNoTemplateImperial();  // Called when "open with no template - Imperial" item is selected.
  afx_msg void OnOpenNoTemplateMetric();  // Called when "open with no template - Metric" item is selected.
  afx_msg void OnOpenMenuPartialOpen();  // Called when the partial open item is selected.
  afx_msg void OnOpenMenuPartialOpenReadOnly();// Called when the partial open read only item is selected.
  afx_msg void OnViewsMenuPreview();     // Called when the preview item is selected from the view menu.
  afx_msg void OnToolsMenuOptions();     // Called when the options item is selected from the view menu.
  afx_msg void OnToolsMenuSecurity();     // Called when the security item is selected from the tools menu.
  afx_msg void OnDestroy();        
  afx_msg void OnUpdateThumbnailCheck();  // Called when the update thumbnail checkbox is selected.
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()

private:

  // These members are used by GCAD's dialogs.
  short m_CmdInProgress;
  short m_nUpdateThumbnailOverride;      // The override value for the UPDATETHUMBNAIL sysvar.
  BOOL m_bIsOpen;                        // This is the GCAD file OPEN dialog.
  BOOL m_bIsSaveAs;                      // This is the GCAD file SAVEAS dialog.
  BOOL m_bIsRecover;                     // We are doing a RECOVER.
  BOOL m_bPartialOpenAlwaysDisabled;     // Set by OEM.
  BOOL m_bInitialViewButtonPresent;      // There is an initial view checkbox.
  BOOL m_bInitialViewButtonChecked;      // Initial view checkbox is checked.
  BOOL m_bPartialOpenPresent;            // There is a partial open button.
  BOOL m_bOptionsPresent;                // There is an OPTIONS menu item.
  BOOL m_bPreviewPresent;                // There is a preview.
  BOOL m_bPreviewVisible;                // Preview is visible.
  BOOL m_bOpenNoTemplate;        // DLFNOTEMPIPR, Open with no Template - Imperial or Metric
  GcUiOpenNoTemplateFlag m_nOpenNoTemplateSelection;
  CGcUiNavPreviewButton* m_previewButton;
  BOOL m_bIsExport;                       // This is the GCAD file Export dialog.
  BOOL CanPartiallyOpen(LPCTSTR szfullPath);// Can the file be partially opened?
  //use static variable instead of to avoid binary compatibility.
  static BOOL m_bOriginalMultiSelAllowed;        // Log original multi-selection setting
};
#endif // GCUINAVDIALOG_H_