#ifndef GCDOCMAN_H
#define GCDOCMAN_H

#include <wtypes.h>
#include "gcadstd.h"
#include "gcdb.h"
#include "rxobject.h"

#pragma pack (push, 8)

class GcTransactionManager;
class GcDbDatabase;
class CDocument;
class GcEdInputPointManager;
class GcApStatusBar;
class GcApPlotReactor;
class GcRxIterator;

#define GC_DOCUMENT_MANAGER_OBJ "GcApDocManager"

struct GcAp 
{
  enum DocLockMode   
  { 
    kNone               = 0x00,
    kAutoWrite          = 0x01,
    kNotLocked          = 0x02,
    kWrite              = 0x04,
    kProtectedAutoWrite = 0x14,
    kRead               = 0x20,
    kXWrite             = 0x40  
  };
};

class GcLispAppInfo
{
public:
  GCHAR appFileName[_MAX_PATH];
  bool bUnloadable;
};

struct IDispatch;
class GCAP_DLL_DECL GcApDocument : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcApDocument);

  virtual const GCHAR* fileName() const = 0;

  virtual CDocument* cDoc() const = 0;

  virtual GcTransactionManager* transactionManager() const = 0;

  virtual GcDbDatabase* database() const = 0;

  enum SaveFormat 
  {
    kUnknown = -1, 
    kR12_dxf = 1,

    kR13_dwg = 4,
    kR13_dxf = 5,

    kR14_dwg = 8,
    kR14_dxf = 9,

    k2000_dwg = 12,
    k2000_dxf = 13,
    k2000_Template = 14,
    k2000_Standard = 15,
    k2000_xml = 16,

    k2004_dwg = 24,
    k2004_dxf = 25,
    k2004_Template = 26,
    k2004_Standard = 27,

    k2007_dwg = 36,
    k2007_dxf = 37,
    k2007_Template = 38,
    k2007_Standard = 39,

    k2010_dwg = 48, 
    k2010_dxf = 49, 
    k2010_Template = 50,
    k2010_Standard = 51,

    k2013_dwg = 60,     
    k2013_dxf = 61,     
    k2013_Template = 62,
    k2013_Standard = 63,

    k2018_dwg = 64,      
    k2018_dxf = 65,      
    k2018_Template = 66, 
    k2018_Standard = 67, 

    kNative = k2018_dwg, 
    kNative_Template = k2018_Template 
  };

  virtual SaveFormat formatForSave() const = 0;

  virtual GcAp::DocLockMode lockMode(bool bIncludeMyLocks = false) const = 0;
  virtual GcAp::DocLockMode myLockMode() const = 0;

  virtual bool isQuiescent() const = 0;

  virtual void * contextPtr() const = 0;

  virtual GcEdInputPointManager* inputPointManager() = 0;

  virtual const GCHAR * docTitle() const = 0;

  virtual bool isReadOnly() const = 0;

  virtual int GetCountOfLispList() const = 0;
  virtual GcLispAppInfo* GetItemOfLispList(int nIndex) const = 0;

  virtual GcApStatusBar* drawingStatusBar() const = 0;

  // Returns a pointer to the IDispatch object associated with the CDocument object
  virtual IDispatch * GetIDispatch(bool bAddRef) = 0;

  void              pushDbmod();
  Gcad::ErrorStatus popDbmod();

  Gcad::ErrorStatus upgradeDocOpen() { return eNotImplementedYet; }

  Gcad::ErrorStatus downgradeDocOpen(bool bPromptForSave) { return eNotImplementedYet; }
};

class GCAP_DLL_DECL GcApDocManagerReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcApDocManagerReactor);

  virtual void documentCreateStarted(GcApDocument* pDocCreating);
  virtual void documentCreated(GcApDocument* pDocCreating);
  virtual void documentToBeDestroyed(GcApDocument* pDocToDestroy);
  virtual void documentDestroyed(const GCHAR* fileName);
  virtual void documentCreateCanceled(GcApDocument* pDocCreateCancelled);

  virtual void documentLockModeWillChange(GcApDocument* ,
    GcAp::DocLockMode myCurrentMode,
    GcAp::DocLockMode myNewMode,
    GcAp::DocLockMode currentMode,
    const GCHAR* pGlobalCmdName);
  virtual void documentLockModeChangeVetoed(GcApDocument* ,
    const GCHAR* pGlobalCmdName);
  virtual void documentLockModeChanged(GcApDocument* ,
    GcAp::DocLockMode myPreviousMode,
    GcAp::DocLockMode myCurrentMode,
    GcAp::DocLockMode currentMode,
    const GCHAR* pGlobalCmdName);

  virtual void documentBecameCurrent(GcApDocument* );
  virtual void documentToBeActivated(GcApDocument* pActivatingDoc );
  virtual void documentToBeDeactivated(GcApDocument* pDeActivatedDoc );
  virtual void documentActivationModified(bool bActivation);
  virtual void documentActivated(GcApDocument* pActivatedDoc);
protected:
  GcApDocManagerReactor() : mVeto(0) {}
  Gcad::ErrorStatus         veto();

private:
  Hccad::Int8 mVeto;

  friend class CApDocManager;
};

class GCAP_DLL_DECL GcApDocumentIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcApDocumentIterator);

  virtual bool done() const = 0;
  virtual void step() = 0;
  virtual GcApDocument* document() = 0;
};

#ifndef  GcRxExecuteProcPtr
typedef void (*GcRxExecuteProcPtr)(void *);
#endif

class GCAP_DLL_DECL GcApDocManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcApDocManager);

  virtual GcApDocument* curDocument() const = 0;
  virtual GcApDocument* mdiActiveDocument() const = 0;

  virtual bool isApplicationContext() const = 0;

  virtual GcApDocument* document(const GcDbDatabase* ) const = 0;

  virtual Gcad::ErrorStatus lockDocument(GcApDocument* pDoc,
    GcAp::DocLockMode = GcAp::kWrite,
    const GCHAR* pGlobalCmdName = NULL,
    const GCHAR* pLocalCmdName = NULL,
    bool prompt = true) = 0;
  virtual Gcad::ErrorStatus unlockDocument(GcApDocument* pDoc) = 0;

  virtual GcApDocumentIterator* newAcApDocumentIterator() = 0;

  virtual void addReactor(GcApDocManagerReactor* ) = 0;
  virtual void removeReactor(GcApDocManagerReactor* ) = 0;

  virtual Gcad::ErrorStatus setDefaultFormatForSave(
    GcApDocument::SaveFormat format) = 0;

  virtual Gcad::ErrorStatus setCurDocument(GcApDocument* pDoc,
    GcAp::DocLockMode = GcAp::kNone,
    bool activate = false) = 0;

  virtual Gcad::ErrorStatus activateDocument(GcApDocument* pAcTargetDocument,
    bool bPassScript = false) = 0;

  virtual Gcad::ErrorStatus sendStringToExecute(GcApDocument* pAcTargetDocument,
    const GCHAR * pszExecute,
    bool bActivate = true,
    bool bWrapUpInactiveDoc = false,
    bool bEchoString = true) = 0;    

  virtual Gcad::ErrorStatus appContextNewDocument(const GCHAR *pszTemplateName) = 0;
  virtual Gcad::ErrorStatus appContextOpenDocument(const GCHAR *pszDrawingName) = 0;

  struct DocOpenParams 
  {
    union 
    { // drawing file name
      const GCHAR * mpszFileName;
      const wchar_t * mpwszFileName;
	};
    union 
    { // layout or view name, or handle string
      const GCHAR * mpszViewName;
      const wchar_t * mpwszViewName;
      const double * mpCoords;    // or world coords to zoom to
    };
    enum 
    {
      kUnknown = 0,             // not used
      kDefaultView = 1,         // open in last saved view
      kLayoutName = 2,          // specify layout by name
      kViewName = 3,            // specify view by name
      kLayoutHandle = 4,        // specify layout by gcdb handle
      kViewHandle = 5,          // specify view by gcdb handle
      kViewWorldCoords = 6
    };
    BYTE mnInitialViewType;
    enum 
    {
      kDisallowReadOnly = 0x01,
      kRequireReadOnly = 0x02,
      kFileNameArgIsUnicode = 0x04,
      kViewNameArgIsUnicode = 0x08,
      kUseUIOnErrors = 0x10,
      kOwnerControlled = 0x20,
    };
    int  mnFlags;       // open it as readonly, etc
    const wchar_t * mpwszPassword;
    void  * mpOwnerData;
    void  * mpUnused;
    int  mnUnused;
    const wchar_t * mpwszTitle;
  };

  virtual Gcad::ErrorStatus appContextCloseDocument(GcApDocument* pAcTargetDocument) = 0;

  virtual Gcad::ErrorStatus newDocument() = 0;
  virtual Gcad::ErrorStatus openDocument() = 0;
  virtual Gcad::ErrorStatus closeDocument(GcApDocument* pAcTargetDocument) = 0;
  
  virtual int inputPending(GcApDocument* pAcTargetDocument) = 0;

  virtual Gcad::ErrorStatus disableDocumentActivation() = 0;
  virtual Gcad::ErrorStatus enableDocumentActivation() = 0;
  virtual bool isDocumentActivationEnabled() = 0;

  virtual void executeInApplicationContext(GcRxExecuteProcPtr procAddr, void *pData ) const = 0;

  virtual int documentCount() const = 0;

  virtual void pushResourceHandle( HINSTANCE hNewResourceHandle) = 0;
  virtual void pushGcadResourceHandle() = 0;
  virtual void popResourceHandle() = 0;

  virtual Gcad::ErrorStatus sendModelessInterrupt(GcApDocument* pAcTargetDocument) = 0;

  virtual void* contextPtr() const = 0;
};

#ifdef _GCRX_MODULE_
#define GCRXAPIDECL __declspec(dllexport)
#else
#define GCRXAPIDECL __declspec(dllimport)
#endif

GCAP_DLL_DECL GcApDocManager* gcDocManagerPtr();
#define gcDocManager gcDocManagerPtr()

inline GcApDocument* curDoc() { return gcDocManager->curDocument(); }
extern "C" GCAP_DLL_DECL GcDbDatabase *curDatabase();
#pragma pack (pop)
#endif // GCDOCMAND_H
