
#ifndef ZCDOCMAN_H
#define ZCDOCMAN_H
#include <memory>
#include "zadesk.h"
#include "zaccoredefs.h"
#include "zacdb.h"
#include "zacadstrc.h"
#include "zrxobject.h"
#include "zrxboiler.h"

#include "zAcApDocLockMode.h"
#pragma pack (push, 8)

class ZcTransactionManager;
class ZcDbDatabase;
class CDocument;
class ZcEdInputPointManager;
class ZcApStatusBar;
class ZcApPlotReactor;
class ZcRxIterator;
class ZcApCommandLineEditor;

struct IDispatch;

#define ZC_DOCUMENT_MANAGER_OBJ ZCRX_T("ZcApDocManager") 

class ZcLispAppInfo
{
public:
    static const int MaxPath = 260;
    ZTCHAR appFileName[MaxPath];
    bool bUnloadable;
};

class ZcApView;
class IZcApDocumentHost;
class ZSOFT_NO_VTABLE ZcApDocument : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocument);

    virtual const ZTCHAR*       fileName() const = 0;

    virtual CDocument* cDoc() const = 0;

    virtual ZcTransactionManager* transactionManager() const = 0;

    virtual ZcDbDatabase*     database() const = 0;

     enum SaveFormat {
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
		
		kNative_Template = k2018_Template,
     };

    virtual SaveFormat formatForSave() const = 0;

	ZCCORE_PORT static Zcad::ErrorStatus getDwgVersionFromSaveFormat(
		SaveFormat docFormat,
		ZcDb::ZcDbDwgVersion& dwgVer,
		ZcDb::MaintenanceReleaseVersion& dwgMaintVer);

    virtual ZcAp::DocLockMode lockMode(bool bIncludeMyLocks =
                                           false) const = 0;
    virtual ZcAp::DocLockMode myLockMode() const = 0;

    virtual bool    isQuiescent() const = 0;

    virtual void * contextPtr() const = 0;

    virtual ZcEdInputPointManager* inputPointManager() = 0;

    virtual const ZTCHAR * docTitle() const = 0;
    ZCCORE_PORT void setDocTitle(const ZTCHAR* title);

    virtual IDispatch * GetIDispatch(bool bAddRef) = 0;
    virtual bool isReadOnly() const = 0;

    virtual int GetCountOfLispList() const = 0;
    virtual ZcLispAppInfo* GetItemOfLispList(int nIndex) const = 0;

    virtual ZcApStatusBar* drawingStatusBar() const = 0;
	virtual bool isCommandInputInactive() const = 0;

    ZCCORE_PORT void              pushDbmod();
    ZCCORE_PORT Zcad::ErrorStatus popDbmod();

    ZCCORE_PORT Zcad::ErrorStatus upgradeDocOpen();
    ZCCORE_PORT Zcad::ErrorStatus downgradeDocOpen(bool bPromptForSave);
    ZCCORE_PORT ZcApView*       view() const;
    ZCCORE_PORT ZcApCommandLineEditor* commandLineEditor() const;
    ZCCORE_PORT void            setHost(IZcApDocumentHost* pHost);
    ZCCORE_PORT bool isNamedDrawing() const;
};

Zcad::ErrorStatus zcedUpgradeDocOpen();
Zcad::ErrorStatus zcedDowngradeDocOpen(bool bPromptForSave);

class ZSOFT_NO_VTABLE ZcApDocManagerReactor : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocManagerReactor);
    ZCCORE_PORT virtual ~ZcApDocManagerReactor() {}

    virtual void              documentCreateStarted(ZcApDocument* pDocCreating);
    
    virtual void              documentCreated(ZcApDocument* pDocCreating);
    
    virtual void              documentToBeDestroyed(ZcApDocument* pDocToDestroy);
    
    virtual void              documentDestroyed(const ZTCHAR* fileName);

    virtual void              documentCreateCanceled(ZcApDocument* pDocCreateCancelled);

    virtual void              documentLockModeWillChange(ZcApDocument* ,
                                         ZcAp::DocLockMode myCurrentMode,
                                         ZcAp::DocLockMode myNewMode,
                                         ZcAp::DocLockMode currentMode,
                                         const ZTCHAR* pGlobalCmdName);
    virtual void              documentLockModeChangeVetoed(ZcApDocument* ,
                                         const ZTCHAR* pGlobalCmdName);
    virtual void              documentLockModeChanged(ZcApDocument* ,
                                         ZcAp::DocLockMode myPreviousMode,
                                         ZcAp::DocLockMode myCurrentMode,
                                         ZcAp::DocLockMode currentMode,
                                         const ZTCHAR* pGlobalCmdName);

    virtual void              documentBecameCurrent(ZcApDocument* );

    virtual void              documentToBeActivated(ZcApDocument* pActivatingDoc );
    
    virtual void              documentToBeDeactivated(ZcApDocument* pDeActivatedDoc );

    virtual void              documentActivationModified(bool bActivation);

    virtual void              documentActivated(ZcApDocument* pActivatedDoc);

    virtual void              documentTitleUpdated(ZcApDocument*) {}
protected:
    ZcApDocManagerReactor() : mVeto(0) {}
    Zcad::ErrorStatus         veto();

private:
    ZSoft::Int8               mVeto;

friend class ZcApDocImpManager;
};

class ZSOFT_NO_VTABLE ZcApDocumentIterator : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocumentIterator);

    virtual bool    done() const = 0;
    virtual void              step() = 0;
    virtual ZcApDocument*       document() = 0;
};

class IZcApDocManagerHost;
class ZSOFT_NO_VTABLE ZcApDocManager : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcApDocManager);

    virtual ZcApDocument*       curDocument() const = 0;
    virtual ZcApDocument*       mdiActiveDocument() const = 0;

    virtual bool    isApplicationContext() const = 0;

    virtual ZcApDocument*       document(const ZcDbDatabase* ) const = 0;

    virtual Zcad::ErrorStatus lockDocument(ZcApDocument* pDoc,
                                   ZcAp::DocLockMode = ZcAp::kWrite,
                                   const ZTCHAR* pGlobalCmdName = NULL,
                                   const ZTCHAR* pLocalCmdName = NULL,
                                   bool prompt = true) = 0;
    virtual Zcad::ErrorStatus unlockDocument(ZcApDocument* pDoc) = 0;

    ZSOFT_DEPRECATE_FOR_INTERNAL_USE virtual ZcApDocumentIterator* newZcApDocumentIterator() = 0;

    auto getDocumentIterator() {
        ZSOFT_SUPPRESS_DEPRECATED
            return std::unique_ptr<ZcApDocumentIterator>(newZcApDocumentIterator());
    }

    virtual void              addReactor(ZcApDocManagerReactor* ) = 0;
    virtual void              removeReactor(ZcApDocManagerReactor* ) = 0;

    virtual Zcad::ErrorStatus setDefaultFormatForSave(
                                ZcApDocument::SaveFormat format) = 0;

	virtual ZcApDocument::SaveFormat defaultFormatForSave() const = 0;

    virtual Zcad::ErrorStatus setCurDocument(ZcApDocument* pDoc,
                                   ZcAp::DocLockMode = ZcAp::kNone,
                                   bool activate = false) = 0;
    
    virtual Zcad::ErrorStatus activateDocument(ZcApDocument* pAcTargetDocument,
                                               bool bPassScript = false) = 0;

    virtual Zcad::ErrorStatus sendStringToExecute(ZcApDocument* pAcTargetDocument,
                                       const ZTCHAR * pszExecute,
                                       bool bActivate = true,
                                       bool bWrapUpInactiveDoc = false,
                                       bool bEchoString = true) = 0;

    virtual Zcad::ErrorStatus appContextNewDocument(const ZTCHAR *pszTemplateName) = 0;
    virtual Zcad::ErrorStatus appContextOpenDocument(const ZTCHAR *pszDrawingName) = 0;
	virtual Zcad::ErrorStatus appContextRecoverDocument(const ZTCHAR *pszDrawingName) = 0;

    ZCCORE_PORT Zcad::ErrorStatus appContextPromptNewDocument();

    ZCCORE_PORT Zcad::ErrorStatus appContextPromptOpenDocument();

    ZCCORE_PORT Zcad::ErrorStatus appContextCloseDocument(ZcApDocument* pDoc);

    struct DocOpenParams {
        union { 
            const ZTCHAR * mpszFileName;
            const wchar_t * mpwszFileName;
        };

        union { 
            const ZTCHAR * mpszViewName;
            const wchar_t * mpwszViewName;
            const double * mpCoords;
        };
        enum InitialViewType : unsigned char
        { 
              kUnknown = 0,             
              kDefaultView = 1,         
              kLayoutName = 2,          
              kViewName = 3,            
              kLayoutHandle = 4,        
              kViewHandle = 5,          
              kViewWorldCoords = 6
		};

		InitialViewType mnInitialViewType;
        enum {  kDisallowReadOnly       = 0x01,
                kRequireReadOnly        = 0x02,
                kFileNameArgIsUnicode   = 0x04,
                kViewNameArgIsUnicode   = 0x08,
                kUseUIOnErrors          = 0x10,
				kOwnerControlled        = 0x20,
				kUseUI                  = 0x40};

        int  mnFlags;       
        const wchar_t * mpwszPassword;
		void*			mpOwnerData;
        void*			mpUnused;
        int				mnUnused;
		const wchar_t*	mpwszTitle;
    };

	virtual Zcad::ErrorStatus appContextOpenDocument(const DocOpenParams *pParams) = 0;
    virtual Zcad::ErrorStatus newDocument() = 0;
    virtual Zcad::ErrorStatus openDocument() = 0;
    virtual Zcad::ErrorStatus closeDocument(ZcApDocument* pAcTargetDocument) = 0;

    virtual int    inputPending(ZcApDocument* pAcTargetDocument) = 0;

    virtual Zcad::ErrorStatus disableDocumentActivation() = 0;
    virtual Zcad::ErrorStatus enableDocumentActivation() = 0;
    virtual bool isDocumentActivationEnabled() = 0;

    virtual void executeInApplicationContext(void (*procAddr)(void *), void *pData ) const = 0;

    ZCCORE_PORT Zcad::ErrorStatus beginExecuteInCommandContext(void (*procAddr)(void *), void *pData);
    ZCCORE_PORT Zcad::ErrorStatus beginExecuteInApplicationContext(void(*procAddr)(void *), void *pData);
    virtual int documentCount() const = 0;

    virtual void pushResourceHandle( HINSTANCE hNewResourceHandle) = 0;
    virtual void pushZcadResourceHandle() = 0;
    virtual void popResourceHandle() = 0;
    
    virtual Zcad::ErrorStatus sendModelessInterrupt(ZcApDocument* pAcTargetDocument) = 0;
    ZCCORE_PORT void setHost(IZcApDocManagerHost* pHost);
};

ZCCORE_PORT ZcApDocManager* zcDocManagerPtr(); 
#define zcDocManager zcDocManagerPtr()

inline ZcApDocument* curDoc() { return ::zcDocManager->curDocument(); }

#pragma pack (pop)
#endif 

