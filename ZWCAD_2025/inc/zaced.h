

#ifndef   _ZCED_H
#define   _ZCED_H

#include "zadesk.h"
#include "zacadapidef.h"
#include "zrxevent.h"
#include "zads.h"
#include "zacutmem.h"

#pragma pack (push, 8)

struct IDispatch;
class CZdUiPathname;
class ZcEdSelectionSetService;

#define ZCED_SERVICES  ZCRX_T("ZcEdServices")
#define ZCED_EDITOR_OBJ ZCRX_T("ZcEditor")

enum ZcadContextMenuMode {
    kDefault = 0,           
    kEdit,                  
    kCommand,               
    kHotGrip,               
    kOsnap,
#ifdef _ZSOFT_MAC_
	kCMPaperSpace
#endif 
};

#include "zaced-xref.h"

enum undoSubcommandActivities
{
    kNone = 0,
    kOne = 1,
    kAll = 2
};

#pragma pack (pop)
#include "zaccmd.h"
#pragma pack (push, 8)


struct ZcEdCommandStruc;
class ZcString;
class ZcRxVariable;
class ZcGiImageBGRA32;
class ZcEdImpSysVarIterator;


ZCAD_PORT bool zcedCmdLookup2(const ZTCHAR* cmdStr, bool globalLookup,
                   ZcEdCommandStruc* retStruc,
                   int sf = ZCRX_CMD_DEFUN);

inline bool zcedCmdLookup(const ZTCHAR* cmdStr, bool globalLookup,
    ZcEdCommandStruc* retStruc, bool skipUndef = false)
{
    return ::zcedCmdLookup2(cmdStr, globalLookup, retStruc,
        skipUndef ? (ZCRX_CMD_DEFUN | ZCRX_CMD_UNDEFINED)
        : ZCRX_CMD_DEFUN);
}

ZCAD_PORT int zcedCmdUndefine(const ZTCHAR* cmdStr, int undefIt);

ZCAD_PORT int zcedPopCommandDirectory(const ZTCHAR* cmdDirName);

class ZcApDocument;
ZCAD_PORT Zcad::ErrorStatus zcedGetCommandForDocument(const ZcApDocument* pDoc,
	ZcString & sCmdName,
	bool bLocalized = false);

inline Zcad::ErrorStatus zcedGetCommandForDocument(const ZcApDocument* pDoc,
    ZTCHAR*& pGlobalCmdName)
{
    pGlobalCmdName = nullptr;
    ZcString sOutput;
    const Zcad::ErrorStatus es = zcedGetCommandForDocument(pDoc, sOutput, false);
    if (es == Zcad::eOk)
        ::zcutNewString(sOutput.kwszPtr(), pGlobalCmdName);
    return es;
}

ZCAD_PORT bool zcedSetOLELock(int handle, int flags=0);

ZCAD_PORT bool zcedClearOLELock(int handle);

ZCAD_PORT void zcedPostCommandPrompt();
 
Zcad::ErrorStatus zcedSyncFileOpen(const ZTCHAR *pszFileToOpen,
                                   const wchar_t* wszPassword = NULL);

ZSoft::Boolean zcedSetColorDialog(int& nColor, ZSoft::Boolean bAllowMetaColor,
    int nCurLayerColor);

ZSoft::Boolean zcedSetColorDialogTrueColor( ZcCmColor& color, ZSoft::Boolean bAllowMetaColor,
                                           const ZcCmColor& curLayerColor, ZcCm::DialogTabs tabs = (ZcCm::DialogTabs)(ZcCm::kACITab | ZcCm::kTrueColorTab  | ZcCm::kColorBookTab) );
#if defined (_ZSOFT_WINDOWS_)
typedef void (ZSOFT_STDCALL* ZcEdColorDialogCallbackFunction)(void *pCallbackData, const ZcCmColor& newColor);
ZCAD_PORT ZSoft::Boolean zcedSetColorDialogTrueColorWithCallback( ZcCmColor& color,
                                                        ZSoft::Boolean bAllowMetaColor,
                                                        const ZcCmColor& curLayerColor,
                                                        ZcCm::DialogTabs tabs = (ZcCm::DialogTabs)(ZcCm::kACITab | ZcCm::kTrueColorTab  | ZcCm::kColorBookTab),
                                                        ZcEdColorDialogCallbackFunction callback = NULL,
														void * pCallbackData = NULL);
#endif

ZCAD_PORT bool zcedSetColorPrompt( const ZTCHAR* promptString,
                                   ZcCmColor& color,
                                   bool bAllowMetaColor);

ZSoft::Boolean zcedIsMenuGroupLoaded(const ZTCHAR *pszGroupName);
bool zcedLoadPartialMenu(const wchar_t* pszMenuFile); 

bool zcedUnloadPartialMenu(const wchar_t* pszMenuFile);
void zcedReloadMenus(bool bIncrementalReloading);
void zcedSendModelessOperationStart(const ZTCHAR* strContext);
void zcedSendModelessOperationEnded(const ZTCHAR* strContext);

void zcedUpdateDisplay();

void zcedUpdateDisplayPause (bool bEnable);

bool zcedIsUpdateDisplayPaused (void);

ZSoft::Boolean zcedInitDialog(ZSoft::Boolean useDialog = ZSoft::kTrue);

ZSoft::UInt8 zcedInitCommandVersion(ZSoft::UInt8 nVersion = 0);
ZSoft::UInt8 zcedGetCommandVersion();
void
zcedDisableDefaultZRXExceptionHandler(ZSoft::Boolean disable = ZSoft::kTrue);

Zcad::ErrorStatus zcedVportTableRecords2Vports();

Zcad::ErrorStatus zcedVports2VportTableRecords();

Zcad::ErrorStatus
zcedVPLayer(const ZcDbObjectId& vpId, const ZcDbObjectIdArray& layerIds,
    ZcDb::VpFreezeOps operation);

#define zcedServices  \
ZcEdServices::cast(zcrxServiceDictionary->at(ZCED_SERVICES))

class ZcEdCommand;
class ZCAD_PORT ZcEdServices: public ZcRxService 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEdServices);
    virtual ZcEdCommand* newZcEdCommand(ZcRxFunctionPtr cmdFcnAddr,
        ZSoft::Int32 cmdFlags) const = 0;
};

class ZcDbDatabase;

class ZCDBCORE2D_PORT ZcEditorReactor: public ZcRxEventReactor 
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEditorReactor);
    ZcEditorReactor() {}
    virtual ~ZcEditorReactor();

    virtual void unknownCommand  (const ZTCHAR* cmdStr, ZcDbVoidPtrArray *al);
    virtual void commandWillStart(const ZTCHAR* cmdStr);
    virtual void commandEnded    (const ZTCHAR* cmdStr);
    virtual void commandCancelled(const ZTCHAR* cmdStr);
    virtual void commandFailed   (const ZTCHAR* cmdStr);

    virtual void lispWillStart   (const ZTCHAR* firstLine);
    virtual void lispEnded       ();
    virtual void lispCancelled   ();

    virtual void beginDxfIn      (ZcDbDatabase*) override;
    virtual void abortDxfIn      (ZcDbDatabase*) override;
    virtual void dxfInComplete   (ZcDbDatabase*) override;
    
    virtual void beginDxfOut     (ZcDbDatabase*) override;
    virtual void abortDxfOut     (ZcDbDatabase*) override;
    virtual void dxfOutComplete  (ZcDbDatabase*) override;

    virtual void beginDwgOpen    (const ZTCHAR* filename){};
    virtual void endDwgOpen      (const ZTCHAR* filename, ZcDbDatabase* pDb);
    virtual void initialDwgFileOpenComplete(ZcDbDatabase* pDwg) override;

	virtual void curDocOpenUpgraded(ZcDbDatabase*,
		const CZdUiPathname& )
	{}

    virtual void curDocOpenDowngraded(ZcDbDatabase* ,
            const CZdUiPathname& )
	{}
	virtual void databaseConstructed(ZcDbDatabase*) override;
    virtual void databaseToBeDestroyed(ZcDbDatabase*) override;
    virtual void beginSave    (ZcDbDatabase*, const ZTCHAR* pIntendedName) override;
    virtual void saveComplete (ZcDbDatabase*, const ZTCHAR* pActualName) override;
    virtual void abortSave    (ZcDbDatabase*) override;

    virtual void beginInsert(ZcDbDatabase* pTo, const ZTCHAR* pBlockName,
		ZcDbDatabase* pFrom) override;
    virtual void beginInsert(ZcDbDatabase* pTo, const ZcGeMatrix3d& xform,
                             ZcDbDatabase* pFrom) override;
    virtual void otherInsert(ZcDbDatabase* pTo, ZcDbIdMapping& idMap,
                             ZcDbDatabase* pFrom) override;
    virtual void abortInsert(ZcDbDatabase* pTo) override;
    virtual void endInsert  (ZcDbDatabase* pTo) override;

    virtual void wblockNotice(ZcDbDatabase* pDb) override;
    virtual void beginWblock(ZcDbDatabase* pTo, ZcDbDatabase* pFrom,
                             const ZcGePoint3d*& insertionPoint) override;
    virtual void beginWblock(ZcDbDatabase* pTo, ZcDbDatabase* pFrom,
                             ZcDbObjectId blockId) override;
    virtual void beginWblock(ZcDbDatabase* pTo, ZcDbDatabase* pFrom) override;
    virtual void otherWblock(ZcDbDatabase* pTo, ZcDbIdMapping&,
                             ZcDbDatabase* pFrom) override;
    virtual void abortWblock(ZcDbDatabase* pTo) override;
    virtual void endWblock  (ZcDbDatabase* pTo) override;

    virtual void beginDeepClone       (ZcDbDatabase* pTo, ZcDbIdMapping&) override;
    virtual void beginDeepCloneXlation(ZcDbIdMapping&, Zcad::ErrorStatus*) override;
    virtual void abortDeepClone       (ZcDbIdMapping&) override;
    virtual void endDeepClone         (ZcDbIdMapping&) override;

    virtual void sysVarChanged        (const ZTCHAR* varName, bool success);

    virtual void sysVarChanged        (const ZTCHAR*, int) final { };
    virtual void sysVarWillChange     (const ZTCHAR* varName) ;

    virtual void beginAttach (ZcDbDatabase* pTo, const ZTCHAR*,
                              ZcDbDatabase* pFrom) override;
    virtual void otherAttach (ZcDbDatabase* pTo, ZcDbDatabase* pFrom) override;
    virtual void abortAttach (ZcDbDatabase* pFrom) override;
    virtual void endAttach   (ZcDbDatabase* pTo) override;
    virtual void redirected  (ZcDbObjectId  newId, ZcDbObjectId oldId) override;
    virtual void comandeered (ZcDbDatabase* pTo, ZcDbObjectId id,
                              ZcDbDatabase* pFrom) override;
    virtual void beginRestore(ZcDbDatabase* pTo, const ZTCHAR*,
                              ZcDbDatabase* pFrom) override;
    virtual void abortRestore(ZcDbDatabase* pTo) override;
    virtual void endRestore  (ZcDbDatabase* pTo) override;

    virtual void xrefSubcommandBindItem   (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId) override;
    virtual void xrefSubcommandAttachItem (ZcDbDatabase* pHost, int activity, const ZTCHAR* pPath) override;
    virtual void xrefSubcommandOverlayItem(ZcDbDatabase* pHost, int activity, const ZTCHAR* pPath) override;
    virtual void xrefSubcommandDetachItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId) override;
    virtual void xrefSubcommandPathItem   (int activity, ZcDbObjectId blockId,
                                           const ZTCHAR* pNewPath) override;
    virtual void xrefSubcommandReloadItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId) override;
    virtual void xrefSubcommandUnloadItem (ZcDbDatabase* pHost, int activity, ZcDbObjectId blockId) override;

    virtual void undoSubcommandAuto       (int activity, bool state);
    virtual void undoSubcommandAuto       (int, int) final { }; 
    virtual void undoSubcommandControl    (int activity, int option);
    virtual void undoSubcommandBegin      (int activity);
    virtual void undoSubcommandEnd        (int activity);
    virtual void undoSubcommandMark       (int activity);
    virtual void undoSubcommandBack       (int activity);
    virtual void undoSubcommandNumber     (int activity, int num);

    virtual void redoSubcommandNumber(int, int) {}
    virtual void undoWriteBoundary(int) {}
    virtual void subcommandsWillBeUndone(int) {}

    virtual void pickfirstModified();
    virtual void layoutSwitched(const ZTCHAR* newLayoutName);

    virtual void layoutToBeSwitched (const ZTCHAR *, const ZTCHAR * ) {}
    virtual void dwgViewResized (ZSoft::LongPtr ) {}
    virtual void fullRegenEnded(ZcDbDatabase* ,
            const ZcDbIntArray & ) {}
    virtual void docFrameMovedOrResized(ZSoft::LongPtr hwndDocFrame, bool bMoved);
    virtual void mainFrameMovedOrResized(ZSoft::LongPtr hwndMainFrame, bool bMoved);

    virtual void beginDoubleClick(const ZcGePoint3d& clickPoint);
    virtual void beginRightClick(const ZcGePoint3d& clickPoint);

    virtual void toolbarBitmapSizeWillChange(bool bLarge);
    virtual void toolbarBitmapSizeChanged(bool bLarge);
    virtual void toolbarBitmapSizeWillChange(int ) final { };
    virtual void toolbarBitmapSizeChanged(int ) final { };

    virtual void beginWblockObjects (ZcDbDatabase* pFrom, ZcDbIdMapping& ) override;

    virtual void partialOpenNotice(ZcDbDatabase* pDb) override;
    virtual void objectsLazyLoaded(const ZcDbObjectIdArray& idArray);

    virtual void beginDocClose(ZcDbDatabase* ) {}
    virtual void docCloseAborted(ZcDbDatabase* ) {}
    virtual void docCloseWillStart(ZcDbDatabase* ) {}
    ZSOFT_DEPRECATED virtual void beginClose(ZcDbDatabase* ) final;
    virtual void beginCloseAll() {}

    virtual void beginQuit();
    virtual void quitAborted();
    virtual void quitWillStart();

    virtual void modelessOperationWillStart(const ZTCHAR* contextStr);
    virtual void modelessOperationEnded(const ZTCHAR* contextStr);

    virtual void cmdIUnkModified(const ZTCHAR* strCommand);
    virtual Zcad::ErrorStatus xrefSubCommandStart(
            ZcXrefSubCommand subcmd,
            const ZcDbObjectIdArray& btrIds,
            const ZTCHAR* const * btrNames,
            const ZTCHAR* const * paths);
    virtual void preXrefLockFile(ZcDbObjectId btrId);

    virtual void viewChanged();

    virtual void fullRegenWillStart(ZcDbDatabase* ) {}
protected:
    Zcad::ErrorStatus veto();

private:
    ZSoft::UInt8 mVeto = 0;

friend class ZcEditorImp;
};

#define ZcEditorReactor2 ZcEditorReactor
#define ZcEditorReactor3 ZcEditorReactor

#define zcedEditor ZcEditor::cast(zcrxSysRegistry()->at(ZCED_EDITOR_OBJ))

class ZCAD_PORT ZcEditor: public ZcRxEvent
{ 
public:
    ZCRX_DECLARE_MEMBERS(ZcEditor);
    virtual void addReactor   (ZcRxEventReactor * newObj) override = 0;
    virtual void removeReactor(ZcRxEventReactor * delObj) override = 0;
};

class ZCAD_PORT ZcEdUIContext : public ZcRxObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcEdUIContext);
    virtual void* getMenuContext(const ZcRxClass *, 
                                 const ZcDbObjectIdArray&)=0;
    virtual void* getMenuContext(const ZcRxClass*,
                                 const ZcDbObjectIdArray&,
                                 const ZcArray<ZcDbFullSubentPathArray,
                                               ZcArrayObjectCopyReallocator<ZcDbFullSubentPathArray> >& subentIds);

    virtual void  onCommand(ZSoft::UInt32 ) =0;
    virtual void  OnUpdateMenu();
};

ZSoft::Boolean zcedAddObjectContextMenu(ZcRxClass *pClass, 
                                        ZcEdUIContext *pContext,
                                        const void *appId);
ZSoft::Boolean zcedRemoveObjectContextMenu(ZcRxClass *pClass, 
                                           ZcEdUIContext *pContext);

ZSoft::Boolean zcedAddDefaultContextMenu(ZcEdUIContext *pContext, 
                                         const void *appId, 
                                         const ZTCHAR* appName=NULL);
ZSoft::Boolean zcedRemoveDefaultContextMenu(ZcEdUIContext *pContext);

bool    zcedSetCMBaseAlias(const wchar_t* strAlias, ZcadContextMenuMode mode);
const wchar_t* zcedGetCMBaseAlias(ZcadContextMenuMode mode);

Zcad::ErrorStatus zcedMspace();  
Zcad::ErrorStatus zcedPspace();  
Zcad::ErrorStatus zcedSetCurrentVPort(int vpnumber);
Zcad::ErrorStatus zcedSetCurrentVPort(const ZcDbViewport* pVp);

int zcedIsDragging(void);

Zcad::ErrorStatus
zcedSetCurrentView(ZcDbViewTableRecord *pVwRec, ZcDbViewport *pVP);

Zcad::ErrorStatus zcedRestoreCurrentView(const ZcDbObjectId& namedViewId);

short zcedGetCurVportCircleSides();
Zcad::ErrorStatus zcedSetCurVportCircleSides(short value);
void zcedGetCurVportPixelToDisplay(double& xFactor, double& yFactor);
void zcedGetCurVportScreenToDisplay(double& xFactor, double& yFactor);

Zcad::ErrorStatus zcedSetCurrentUCS(const ZcGeMatrix3d & mat);
Zcad::ErrorStatus zcedGetCurrentUCS(ZcGeMatrix3d& mat);
Zcad::ErrorStatus zcedRestorePreviousUCS();

class ZcDbFcf;
class ZcDbMText;

void zcedEditToleranceInteractive(ZcDbFcf* pTol);

int zcedEditMTextInteractive(ZcDbMText* pMText, bool useNewUI = false, bool allowTabs = false);

enum DimstyleTabSuppressed {
    kSymbolsArrowsTabSuppressed   = 0x01,
    kTextTabSuppressed            = 0x02,
    kFitTabSuppressed             = 0x04,
    kPrimaryTabSuppressed         = 0x08,
    kAlternateTabSuppressed       = 0x10,
    kToleranceTabSuppressed       = 0x20
};
int zcedEditDimstyleInteractiveEx(ZcDbDatabase * pDb,
                              ZcDbDimStyleTableRecord * pRec,
                              int familyType,
                              const ZTCHAR* title = NULL,
                              int tabCtrlFlags = 0);

ZSoft::ColorRef    zcedGetRGB(int color);

Zcad::ErrorStatus zcedGetCurrentSelectionSet(ZcDbObjectIdArray& sset);

Zcad::ErrorStatus zcedGetFullSubentPathsForCurrentSelection(
        const ZcDbObjectId&      selectedObject,
        ZcDbFullSubentPathArray& selectedSubentities);

class ZcDbHatch;
class ZcDbEntity;

#define zcedGetIDispatch ZcadGetIDispatch
extern "C" IDispatch *zcedGetIDispatch (bool bAddRef);

ZcDbObjectId zcedActiveViewportId();

ZcDbObjectId zcedViewportIdFromNumber(int nVpNum);

int zcedNumberOfViewports();

ZcDbObjectId zcedGetCurViewportObjectId();

Zcad::ErrorStatus 
zcedConvertEntityToHatch(ZcDbHatch* pHatch, ZcDbEntity*& pEnt, bool transferId);

#include "zaced-hatch.h"

Zcad::ErrorStatus
zcedManageHatchEditorReactor(ZcDbObjectId hatchId,
                         ZcHatchEdReact action,
                         ZcDbObjectId boundaryId = ZcDbObjectId::kNull,
                         ZcHatchNotifier notifyType = kNobody,
                         bool transformed = false);
enum ZcEdDrawOrderCmdType {
    kDrawOrderNone = 0,
    kDrawOrderBottom,
    kDrawOrderTop,
    kDrawOrderBelow,
    kDrawOrderAbove
};

Zcad::ErrorStatus  zcedDrawOrderInherit(ZcDbObjectId parent,
                                        ZcDbObjectIdArray &childArray,
                                        ZcEdDrawOrderCmdType cmd);

Zcad::ErrorStatus
zcedCreateViewportByView(ZcDbDatabase *pDb,
                         const ZcDbObjectId& view, 
                         const ZcGePoint2d& location, 
                         double scale,
                         ZcDbObjectId& viewportId);

ZCAD_PORT Zcad::ErrorStatus
zcedCreateEnhancedViewportOnDrop(const ZTCHAR *filename,
                                 const ZTCHAR *viewName,
                                 const ZcGePoint2d& location,
                                 double scale,
                                 ZcDbObjectId labelBlockId,
                                 ZcDbObjectId& sheetViewId,
                                 ZcDbObjectId& viewportId);

ZCAD_PORT Zcad::ErrorStatus
zcedCreateEnhancedViewportOnDropDWG(const ZTCHAR *filename,
                                    ZcDbExtents *extents,
                                    const ZcGePoint2d& location,
                                    double scale,
                                    ZcDbObjectId labelBlockId,
                                    ZcDbObjectId& sheetViewId,
                                    ZcDbObjectId& viewportId);

ZCAD_PORT Zcad::ErrorStatus zcedGetUnitsValueString (ZcDb::UnitsValue units, ZcString &sUnits);
inline const ZcString* zcedGetUnitsValueString(ZcDb::UnitsValue units)
{
    static ZcString sRetVal;
    ::zcedGetUnitsValueString(units, sRetVal);
    return &sRetVal;
}

bool zcedGetUnitsConversion(ZcDb::UnitsValue blkInsunits, double& conversionFactor);
bool zcdbCanonicalToSystemRange(int eUnits, const ZcString& strIn, ZcString& strOut);

bool zcdbSystemRangeToCanonical(int eUnits, const ZcString& strIn, ZcString& strOut);

void zcedEnableUsrbrk();
void zcedDisableUsrbrk();
bool zcedIsUsrbrkDisabled();
bool zcedIsInBackgroundMode();

enum BlockEditModeFlags {
    kBlkEditModeNone   = 0x0,
    kBlkEditModeActive = 0x01,
    kBlkEditModeOpen   = 0x02,
    kBlkEditModeDirty  = 0x04,
    kBlkEditModeBSaved = 0x08
};

unsigned int zcedGetBlockEditMode();

void zcedOpenDocWindowsMinimized( bool bMinimized );

bool zcedCompareToCurrentViewport(const ZcDbViewTableRecord *pVwRec);

ZSoft::UInt32 zcedGetAnimationFrameId(void);

ZCAD_PORT bool zcedShowConstraintBar(ZcDbFullSubentPathArray &subentPaths);

ZCAD_PORT bool zcedHideConstraintBar(ZcDbFullSubentPathArray &subentPaths);

ZCAD_PORT bool zcedShowConstraintBarForAll(bool bToShow);

ZCAD_PORT bool zcedDisplayBorder(bool bShow);

Zcad::ErrorStatus zcedTraceBoundary(const ZcGePoint3d& seedPoint,
                                    bool detectIslands,
                                    ZcDbVoidPtrArray& resultingBoundarySet);

void zcedSetDrawComplexShape (int val);
int zcedGetDrawComplexShape ();

void zcedSetRecursingLinetypeVectorGeneration (int val);
int zcedGetRecursingLinetypeVectorGeneration ();

struct flagmat * zcedGetComplexLineTypeTransformPtr();

ZCAD_PORT Zcad::ErrorStatus zcedAudit(ZcDbDatabase* pDb, bool bFixErrors, bool bCmdLnEcho = false);

ZCCORE_PORT bool zcedAddSupplementalCursorImage(const ZcGiImageBGRA32* pSuppCursorImage, int priorityOrder = 0);

ZCCORE_PORT bool zcedRemoveSupplementalCursorImage(const ZcGiImageBGRA32* pSuppCursorImage);

ZCAD_PORT bool zcedHasSupplementalCursorImage();

ZCCORE_PORT void zcedSetSupplementalCursorOffset(int x, int y);

ZCAD_PORT void zcedGetSupplementalCursorOffset(int& x, int& y);

ZCCORE_PORT float zcedGetDpiScalingValue();

ZCAD_PORT bool zcedScaleImageWithGDIPlus(const ZcGiImageBGRA32 *pSrcImg, const ZcGiImageBGRA32 *pDstImg);

ZCCORE_PORT void zcedSetFieldUpdateEnabled(ZcApDocument* pDoc, bool enabled);

ZCCORE_PORT bool zcedIsFieldUpdateEnabled(const ZcApDocument* pDoc);

ZCCORE_PORT bool zcedGetFullSubentPathArray(ZcEdSelectionSetService* service, bool bIsSubSelectionIndex, int index, ZcDbFullSubentPathArray& fullPaths);

ZCCORE_PORT void zcedSetIgnoredEntAndDuplicatedBlkCount(ZcEdSelectionSetService* service, int ignoredEntCount, int duplicatedBlkCount);

class ZCAD_PORT ZcEdSysVarIterator
{
public:
    ZcEdSysVarIterator();
    ~ZcEdSysVarIterator();

	void step();
	const ZcRxVariable* getSysVar();
	void reset();
	bool done() const;
private:
    ZcEdImpSysVarIterator* m_pImp = nullptr;
};

class ZcEdUpdateDisplayPauseScope
{
public:

    ZcEdUpdateDisplayPauseScope() {}

    ZcEdUpdateDisplayPauseScope(bool bEnable)
    {
        SaveAndSet(bEnable);
    }

    ~ZcEdUpdateDisplayPauseScope()
    {
        Restore();
    }

    void SaveAndSet(bool bDisable)
    {
        if (!m_bDidSet)
        {
            m_bDidSet = true;
            m_bOldValue = zcedIsUpdateDisplayPaused();
            zcedUpdateDisplayPause(bDisable);
        }
    }

    void Restore()
    {
        if (m_bDidSet)
        {
            m_bDidSet = false;
            zcedUpdateDisplayPause(m_bOldValue);
        }
    }

protected:
    bool  m_bOldValue = false;
    bool  m_bDidSet = false;
};


#pragma pack (pop)

#endif
