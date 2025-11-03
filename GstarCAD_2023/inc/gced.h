/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCED_H
#define   _GCED_H

#include "gsoft.h"
#include "gcadapidef.h" 
#include "rxevent.h"    
#include "gds.h"

#pragma pack (push, 8)

struct IDispatch;
class CGdUiPathname;
class GcEdSelectionSetService;

#define GCED_SERVICES  GCRX_T("GcEdServices")
#define GCED_EDITOR_OBJ GCRX_T("GcEditor")

enum GcadContextMenuMode {
  kDefault = 0,
  kEdit,
  kCommand,
  kHotGrip,
  kOsnap,
#ifdef _GSOFT_MAC_
  kCMPaperSpace
#endif
};

#include "gced-xref.h"

enum undoSubcommandActivities
{
  kNone = 0,
  kOne = 1,
  kAll = 2
};

#pragma pack (pop)
#include "gccmd.h"      
#pragma pack (push, 8)

struct GcEdCommandStruc;
class GcString;
class GcRxVariable;
class GcGiImageBGRA32;
class GcEdImpSysVarIterator;


GCCORE_PORT bool gcedCmdLookup2(const GCHAR* cmdStr, bool globalLookup,
  GcEdCommandStruc* retStruc, int sf = GCRX_CMD_DEFUN);
inline bool gcedCmdLookup(const GCHAR* cmdStr, bool globalLookup,
  GcEdCommandStruc* retStruc, bool skipUndef = false)
{
  return ::gcedCmdLookup2(cmdStr, globalLookup, retStruc,
    skipUndef ? (GCRX_CMD_DEFUN | GCRX_CMD_UNDEFINED)
    : GCRX_CMD_DEFUN);
}

GCCORE_PORT int gcedCmdUndefine(const GCHAR* cmdStr, int undefIt);

GCCORE_PORT int gcedPopCommandDirectory(const GCHAR* cmdDirName);

class GcApDocument;
GCCORE_PORT Gcad::ErrorStatus gcedGetCommandForDocument(const GcApDocument* pDoc,
  GcString & sCmdName,
  bool bLocalized = false);
GCCORE_PORT Gcad::ErrorStatus gcedGetCommandForDocument(const GcApDocument* pDoc,
  GCHAR *& pGlobalCmdName);

GCCORE_PORT bool gcedSetOLELock(int handle, int flags = 0);
GCCORE_PORT bool gcedClearOLELock(int handle);

GCCORE_PORT void gcedPostCommandPrompt();

GCCORE_PORT Gcad::ErrorStatus gcedSyncFileOpen(const GCHAR *pszFileToOpen,
  const wchar_t* wszPassword = NULL);

GCAD_PORT Gsoft::Boolean gcedSetColorDialog(int& nColor, Gsoft::Boolean bAllowMetaColor,
  int nCurLayerColor);

GCAD_PORT Gsoft::Boolean gcedSetColorDialogTrueColor(GcCmColor& color, Gsoft::Boolean bAllowMetaColor,
  const GcCmColor& curLayerColor, GcCm::DialogTabs tabs = (GcCm::DialogTabs)(GcCm::kACITab | GcCm::kTrueColorTab | GcCm::kColorBookTab));

#if defined(_GSOFT_WINDOWS_)
typedef void (GSOFT_STDCALL* GcEdColorDialogCallbackFunction)(void *pCallbackData, const GcCmColor& newColor);

GCAD_PORT Gsoft::Boolean gcedSetColorDialogTrueColorWithCallback(GcCmColor& color,
  Gsoft::Boolean bAllowMetaColor,
  const GcCmColor& curLayerColor,
  GcCm::DialogTabs tabs = (GcCm::DialogTabs)(GcCm::kACITab | GcCm::kTrueColorTab | GcCm::kColorBookTab),
  GcEdColorDialogCallbackFunction callback = NULL,
  void * pCallbackData = NULL);

#endif

GCAD_PORT bool gcedSetColorPrompt(const GCHAR* promptString,
  GcCmColor& color,
  bool bAllowMetaColor);

GCAD_PORT Gsoft::Boolean gcedIsMenuGroupLoaded(const GCHAR *pszGroupName);

GCAD_PORT bool gcedLoadPartialMenu(const wchar_t* pszMenuFile);
GCAD_PORT bool gcedUnloadPartialMenu(const wchar_t* pszMenuFile);

GCAD_PORT void gcedReloadMenus(bool bIncrementalReloading);

GCCORE_PORT void gcedSendModelessOperationStart(const GCHAR* strContext);
GCCORE_PORT void gcedSendModelessOperationEnded(const GCHAR* strContext);

GCCORE_PORT void gcedUpdateDisplay();
GCCORE_PORT void gcedUpdateDisplayPause(bool bEnable);
GCCORE_PORT bool gcedIsUpdateDisplayPaused(void);

GCCORE_PORT Gsoft::Boolean gcedInitDialog(Gsoft::Boolean useDialog = Gsoft::kTrue);

GCCORE_PORT Gsoft::UInt8 gcedInitCommandVersion(Gsoft::UInt8 nVersion = 0);
GCCORE_PORT Gsoft::UInt8 gcedGetCommandVersion();

GCCORE_PORT void
gcedDisableDefaultGRXExceptionHandler(Gsoft::Boolean disable = Gsoft::kTrue);

GCCORE_PORT Gcad::ErrorStatus gcedVportTableRecords2Vports();
GCCORE_PORT Gcad::ErrorStatus gcedVports2VportTableRecords();

GCCORE_PORT Gcad::ErrorStatus
gcedVPLayer(const GcDbObjectId& vpId, const GcDbObjectIdArray& layerIds,
  GcDb::VpFreezeOps operation);

#define gcedServices  \
GcEdServices::cast(gcrxServiceDictionary->at(GCED_SERVICES))

class GcEdCommand;
class GCCORE_PORT GcEdServices : public GcRxService
{
public:
  GCRX_DECLARE_MEMBERS(GcEdServices);
  virtual GcEdCommand* newAcEdCommand(GcRxFunctionPtr cmdFcnAddr,
    Gsoft::Int32 cmdFlags) const = 0;
};

class GcDbDatabase;

class GCDB_PORT GcEditorReactor : public GcRxEventReactor
{
public:
  GCRX_DECLARE_MEMBERS(GcEditorReactor);
  GcEditorReactor() {}

  virtual void unknownCommand(const GCHAR* cmdStr, GcDbVoidPtrArray *al);
  virtual void commandWillStart(const GCHAR* cmdStr);
  virtual void commandEnded(const GCHAR* cmdStr);
  virtual void commandCancelled(const GCHAR* cmdStr);
  virtual void commandFailed(const GCHAR* cmdStr);

  virtual void lispWillStart(const GCHAR* firstLine);
  virtual void lispEnded();
  virtual void lispCancelled();

  void beginDxfIn(GcDbDatabase*) override;
  void abortDxfIn(GcDbDatabase*) override;
  void dxfInComplete(GcDbDatabase*) override;
  void beginDxfOut(GcDbDatabase*) override;
  void abortDxfOut(GcDbDatabase*) override;
  void dxfOutComplete(GcDbDatabase*) override;

  GSOFT_DEPRECATED virtual void beginDwgOpen(GCHAR*) final {};
  virtual void beginDwgOpen(const GCHAR*) {};
  virtual void endDwgOpen(const GCHAR* filename, GcDbDatabase* pDb);
  void initialDwgFileOpenComplete(GcDbDatabase* pDwg) override;

  virtual void curDocOpenUpgraded(GcDbDatabase*,
    const CGdUiPathname&)
  {}
  virtual void curDocOpenDowngraded(GcDbDatabase*,
    const CGdUiPathname&)
  {}

  void databaseConstructed(GcDbDatabase*) override;
  void databaseToBeDestroyed(GcDbDatabase*) override;
  void beginSave(GcDbDatabase*, const GCHAR* pIntendedName) override;
  void saveComplete(GcDbDatabase*, const GCHAR* pActualName) override;
  void abortSave(GcDbDatabase*) override;

  void beginInsert(GcDbDatabase* pTo, const GCHAR* pBlockName,
    GcDbDatabase* pFrom) override;
  void beginInsert(GcDbDatabase* pTo, const GcGeMatrix3d& xform,
    GcDbDatabase* pFrom) override;
  void otherInsert(GcDbDatabase* pTo, GcDbIdMapping& idMap,
    GcDbDatabase* pFrom) override;
  void abortInsert(GcDbDatabase* pTo) override;
  void endInsert(GcDbDatabase* pTo) override;

  void wblockNotice(GcDbDatabase* pDb) override;
  void beginWblock(
    GcDbDatabase* pTo,
    GcDbDatabase* pFrom,
    const GcGePoint3d*& insertionPoint) override;
  void beginWblock(
    GcDbDatabase* pTo,
    GcDbDatabase* pFrom,
    GcDbObjectId blockId) override;
  void beginWblock(
    GcDbDatabase* pTo,
    GcDbDatabase* pFrom) override;
  void otherWblock(
    GcDbDatabase* pTo,
    GcDbIdMapping&,
    GcDbDatabase* pFrom) override;
  void abortWblock(GcDbDatabase* pTo) override;
  void endWblock(GcDbDatabase* pTo) override;

  void beginDeepClone(GcDbDatabase* pTo, GcDbIdMapping&) override;
  void beginDeepCloneXlation(GcDbIdMapping&, Gcad::ErrorStatus*) override;
  void abortDeepClone(GcDbIdMapping&) override;
  void endDeepClone(GcDbIdMapping&) override;

  virtual void sysVarChanged(const GCHAR* varName, Gsoft::Boolean success);
  virtual void sysVarChanged(const GCHAR*, int) final { };
  virtual void sysVarWillChange(const GCHAR* varName);

  void beginAttach(
    GcDbDatabase* pTo,
    const GCHAR*,
    GcDbDatabase* pFrom) override;
  void otherAttach(GcDbDatabase* pTo, GcDbDatabase* pFrom) override;
  void abortAttach(GcDbDatabase* pFrom) override;
  void endAttach(GcDbDatabase* pTo) override;
  void redirected(GcDbObjectId  newId, GcDbObjectId oldId) override;
  void comandeered(
    GcDbDatabase* pTo,
    GcDbObjectId id,
    GcDbDatabase* pFrom) override;
  void beginRestore(
    GcDbDatabase* pTo,
    const GCHAR*,
    GcDbDatabase* pFrom) override;
  void abortRestore(GcDbDatabase* pTo) override;
  void endRestore(GcDbDatabase* pTo) override;

  void xrefSubcommandBindItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId) override;
  void xrefSubcommandAttachItem(GcDbDatabase* pHost, int activity, const GCHAR* pPath) override;
  void xrefSubcommandOverlayItem(GcDbDatabase* pHost, int activity, const GCHAR* pPath) override;
  void xrefSubcommandDetachItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId) override;
  void xrefSubcommandPathItem(
    int activity,
    GcDbObjectId blockId,
    const GCHAR* pNewPath) override;
  void xrefSubcommandReloadItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId) override;
  void xrefSubcommandUnloadItem(GcDbDatabase* pHost, int activity, GcDbObjectId blockId) override;

  virtual void undoSubcommandAuto(int activity, Gsoft::Boolean state);
  virtual void undoSubcommandAuto(int, int) final { };
  virtual void undoSubcommandControl(int activity, int option);
  virtual void undoSubcommandBegin(int activity);
  virtual void undoSubcommandEnd(int activity);
  virtual void undoSubcommandMark(int activity);
  virtual void undoSubcommandBack(int activity);
  virtual void undoSubcommandNumber(int activity, int num);

  virtual void pickfirstModified();
  virtual void layoutSwitched(const GCHAR* newLayoutName);
  virtual void layoutToBeSwitched(const GCHAR *, const GCHAR *) {}
  virtual void dwgViewResized(Gsoft::LongPtr) {}

  virtual void fullRegenEnded(GcDbDatabase*,
    const GcDbIntArray &) {}

  virtual void docFrameMovedOrResized(Gsoft::LongPtr hwndDocFrame, bool bMoved);
  virtual void mainFrameMovedOrResized(Gsoft::LongPtr hwndMainFrame, bool bMoved);

  virtual void beginDoubleClick(const GcGePoint3d& clickPoint);
  virtual void beginRightClick(const GcGePoint3d& clickPoint);

  virtual void toolbarBitmapSizeWillChange(Gsoft::Boolean bLarge);
  virtual void toolbarBitmapSizeChanged(Gsoft::Boolean bLarge);
  virtual void toolbarBitmapSizeWillChange(int) final { };
  virtual void toolbarBitmapSizeChanged(int) final { };

  void beginWblockObjects(GcDbDatabase* pFrom, GcDbIdMapping&) override;
  void partialOpenNotice(GcDbDatabase* pDb) override;
  virtual void objectsLazyLoaded(const GcDbObjectIdArray& idArray);
  virtual void beginDocClose(GcDbDatabase*) {}
  virtual void docCloseAborted(GcDbDatabase*) {}
  virtual void docCloseWillStart(GcDbDatabase*) {}

  GSOFT_DEPRECATED virtual void beginClose(GcDbDatabase*) final;

  virtual void beginCloseAll() {}
  virtual void beginQuit();
  virtual void quitAborted();
  virtual void quitWillStart();

  virtual void modelessOperationWillStart(const GCHAR* contextStr);
  virtual void modelessOperationEnded(const GCHAR* contextStr);

  virtual void cmdIUnkModified(const GCHAR* strCommand);


  virtual Gcad::ErrorStatus xrefSubCommandStart(
    GcXrefSubCommand subcmd,
    const GcDbObjectIdArray& btrIds,
    const GCHAR* const * btrNames,
    const GCHAR* const * paths);

  virtual void preXrefLockFile(GcDbObjectId btrId);

  virtual void viewChanged();

  virtual void fullRegenWillStart(GcDbDatabase*) {}

protected:
  Gcad::ErrorStatus veto();

private:
  Gsoft::UInt8 mVeto = 0;
  friend class GcEditorImp;
};

#define GcEditorReactor2 GcEditorReactor
#define GcEditorReactor3 GcEditorReactor

#define gcedEditor GcEditor::cast(gcrxSysRegistry()->at(GCED_EDITOR_OBJ))

class GCDB_PORT GcEditor : public GcRxEvent
{
public:
  GCRX_DECLARE_MEMBERS(GcEditor);
  void addReactor(GcRxEventReactor * newObj) override = 0;
  void removeReactor(GcRxEventReactor * delObj) override = 0;
};

class GCBASE_PORT GcEdUIContext : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcEdUIContext);
  virtual void* getMenuContext(const GcRxClass *,
    const GcDbObjectIdArray&) = 0;
  virtual void* getMenuContext(const GcRxClass*,
    const GcDbObjectIdArray&,
    const GcArray<GcDbFullSubentPathArray,
    GcArrayObjectCopyReallocator<GcDbFullSubentPathArray> >& subentIds);

  virtual void  onCommand(Gsoft::UInt32) = 0;
  virtual void  OnUpdateMenu();
};

GCAD_PORT Gsoft::Boolean gcedAddObjectContextMenu(GcRxClass *pClass,
  GcEdUIContext *pContext,
  const void *appId);
GCAD_PORT Gsoft::Boolean gcedRemoveObjectContextMenu(GcRxClass *pClass,
  GcEdUIContext *pContext);
GCAD_PORT Gsoft::Boolean gcedAddDefaultContextMenu(GcEdUIContext *pContext,
  const void *appId,
  const GCHAR* appName = NULL);
GCAD_PORT Gsoft::Boolean gcedRemoveDefaultContextMenu(GcEdUIContext *pContext);

GCCORE_PORT bool    gcedSetCMBaseAlias(const wchar_t* strAlias, GcadContextMenuMode mode);
GCCORE_PORT const wchar_t* gcedGetCMBaseAlias(GcadContextMenuMode mode);

GCCORE_PORT Gcad::ErrorStatus gcedMspace();
GCCORE_PORT Gcad::ErrorStatus gcedPspace();
GCCORE_PORT Gcad::ErrorStatus gcedSetCurrentVPort(int vpnumber);
GCCORE_PORT Gcad::ErrorStatus gcedSetCurrentVPort(const GcDbViewport* pVp);

GCCORE_PORT int gcedIsDragging(void);

GCCORE_PORT Gcad::ErrorStatus
gcedSetCurrentView(GcDbViewTableRecord *pVwRec, GcDbViewport *pVP);

GCCORE_PORT Gcad::ErrorStatus gcedRestoreCurrentView(const GcDbObjectId& namedViewId);

GCCORE_PORT short gcedGetCurVportCircleSides();
GCCORE_PORT Gcad::ErrorStatus gcedSetCurVportCircleSides(short value);

GCCORE_PORT void gcedGetCurVportPixelToDisplay(double& xFactor, double& yFactor);
GCCORE_PORT void gcedGetCurVportScreenToDisplay(double& xFactor, double& yFactor);

GCCORE_PORT Gcad::ErrorStatus gcedSetCurrentUCS(const GcGeMatrix3d & mat);
GCCORE_PORT Gcad::ErrorStatus gcedGetCurrentUCS(GcGeMatrix3d& mat);
GCCORE_PORT Gcad::ErrorStatus gcedRestorePreviousUCS();

class GcDbFcf;
class GcDbMText;

GCAD_PORT void gcedEditToleranceInteractive(GcDbFcf* pTol);

GCCORE_PORT int gcedEditMTextInteractive(GcDbMText* pMText, bool useNewUI = false, bool allowTabs = false);

enum DimstyleTabSuppressed {
  kSymbolsArrowsTabSuppressed = 0x01,
  kTextTabSuppressed = 0x02,
  kFitTabSuppressed = 0x04,
  kPrimaryTabSuppressed = 0x08,
  kAlternateTabSuppressed = 0x10,
  kToleranceTabSuppressed = 0x20
};

GCCORE_PORT int gcedEditDimstyleInteractiveEx(GcDbDatabase * pDb,
  GcDbDimStyleTableRecord * pRec,
  int familyType,
  const GCHAR* title = NULL,
  int tabCtrlFlags = 0);

GCAD_PORT Gsoft::UInt32     gcedGetRGB(int color);

GCCORE_PORT Gcad::ErrorStatus gcedGetCurrentSelectionSet(GcDbObjectIdArray& sset);

GCCORE_PORT Gcad::ErrorStatus gcedGetFullSubentPathsForCurrentSelection(
  const GcDbObjectId&      selectedObject,
  GcDbFullSubentPathArray& selectedSubentities);

class GcDbHatch;
class GcDbEntity;

#define gcedGetIDispatch GcadGetIDispatch
extern "C" GCAD_PORT IDispatch *gcedGetIDispatch(bool bAddRef);

GCCORE_PORT GcDbObjectId gcedActiveViewportId();
GCCORE_PORT GcDbObjectId gcedViewportIdFromNumber(int nVpNum);
GCCORE_PORT int gcedNumberOfViewports();
GCCORE_PORT GcDbObjectId gcedGetCurViewportObjectId();

GCCORE_PORT Gcad::ErrorStatus
gcedConvertEntityToHatch(GcDbHatch* pHatch, GcDbEntity*& pEnt, bool transferId);

#include "gced-hatch.h"

GCCORE_PORT Gcad::ErrorStatus
gcedManageHatchEditorReactor(GcDbObjectId hatchId,
  GcHatchEdReact action,
  GcDbObjectId boundaryId = GcDbObjectId::kNull,
  GcHatchNotifier notifyType = kNobody,
  bool transformed = false);

enum GcEdDrawOrderCmdType {
  kDrawOrderNone = 0,
  kDrawOrderBottom,
  kDrawOrderTop,
  kDrawOrderBelow,
  kDrawOrderAbove
};

GCCORE_PORT Gcad::ErrorStatus  gcedDrawOrderInherit(GcDbObjectId parent,
  GcDbObjectIdArray &childArray,
  GcEdDrawOrderCmdType cmd);

GCCORE_PORT Gcad::ErrorStatus
gcedCreateViewportByView(GcDbDatabase *pDb,
  const GcDbObjectId& view,
  const GcGePoint2d& location,
  double scale,
  GcDbObjectId& viewportId);

GCCORE_PORT Gcad::ErrorStatus
gcedCreateEnhancedViewportOnDrop(const GCHAR *filename,
  const GCHAR *viewName,
  const GcGePoint2d & location,
  double scale,
  GcDbObjectId labelBlockId,
  GcDbObjectId& sheetViewId,
  GcDbObjectId& viewportId);

GCCORE_PORT Gcad::ErrorStatus
gcedCreateEnhancedViewportOnDropDWG(const GCHAR *filename,
  GcDbExtents *extents,
  const GcGePoint2d & location,
  double scale,
  GcDbObjectId labelBlockId,
  GcDbObjectId& sheetViewId,
  GcDbObjectId& viewportId);

GCCORE_PORT Gcad::ErrorStatus gcedGetUnitsValueString(GcDb::UnitsValue units, GcString &sUnits);

inline const GcString* gcedGetUnitsValueString(GcDb::UnitsValue units)
{
  static GcString sRetVal;
  ::gcedGetUnitsValueString(units, sRetVal);
  return &sRetVal;
}

GCCORE_PORT bool gcedGetUnitsConversion(GcDb::UnitsValue blkInsunits, double& conversionFactor);

GCCORE_PORT bool gcdbCanonicalToSystemRange(int eUnits, const GcString& strIn, GcString& strOut);

GCCORE_PORT bool gcdbSystemRangeToCanonical(int eUnits, const GcString& strIn, GcString& strOut);

GCCORE_PORT void gcedEnableUsrbrk();
GCCORE_PORT void gcedDisableUsrbrk();
GCCORE_PORT bool gcedIsUsrbrkDisabled();

GCCORE_PORT bool gcedIsInBackgroundMode();

enum BlockEditModeFlags {
  kBlkEditModeNone = 0x0,
  kBlkEditModeActive = 0x01,
  kBlkEditModeOpen = 0x02,
  kBlkEditModeDirty = 0x04,
  kBlkEditModeBSaved = 0x08
};

GCCORE_PORT unsigned int gcedGetBlockEditMode();

GCCORE_PORT void gcedOpenDocWindowsMinimized(bool bMinimized);

GCCORE_PORT bool gcedCompareToCurrentViewport(const GcDbViewTableRecord *pVwRec);

GCCORE_PORT Gsoft::UInt32 gcedGetAnimationFrameId(void);

GCCORE_PORT bool gcedShowConstraintBar(GcDbFullSubentPathArray &subentPaths);
GCCORE_PORT bool gcedHideConstraintBar(GcDbFullSubentPathArray &subentPaths);
GCCORE_PORT bool gcedShowConstraintBarForAll(bool bToShow);

GCCORE_PORT Gcad::ErrorStatus gcedTraceBoundary(const GcGePoint3d& seedPoint,
  bool detectIslands,
  GcDbVoidPtrArray& resultingBoundarySet);

void gcedSetDrawComplexShape(int val);
int gcedGetDrawComplexShape();

void gcedSetRecursingLinetypeVectorGeneration(int val);
int gcedGetRecursingLinetypeVectorGeneration();

struct flagmat * gcedGetComplexLineTypeTransformPtr();

GCCORE_PORT Gcad::ErrorStatus gcedAudit(GcDbDatabase* pDb, bool bFixErrors, bool bCmdLnEcho = false);
GCCORE_PORT bool gcedAddSupplementalCursorImage(const GcGiImageBGRA32* pSuppCursorImage, int priorityOrder = 0);
GCCORE_PORT bool gcedRemoveSupplementalCursorImage(const GcGiImageBGRA32* pSuppCursorImage);
GCCORE_PORT bool gcedHasSupplementalCursorImage();

GCCORE_PORT void gcedSetSupplementalCursorOffset(int x, int y);
GCCORE_PORT void gcedGetSupplementalCursorOffset(int& x, int& y);

GCCORE_PORT float gcedGetDpiScalingValue();

GCCORE_PORT bool gcedScaleImageWithGDIPlus(const GcGiImageBGRA32 *pSrcImg, const GcGiImageBGRA32 *pDstImg);

GCCORE_PORT void gcedSetFieldUpdateEnabled(GcApDocument* pDoc, bool enabled);
GCCORE_PORT bool gcedIsFieldUpdateEnabled(const GcApDocument* pDoc);

GCCORE_PORT bool gcedGetFullSubentPathArray(GcEdSelectionSetService* service, bool bIsSubSelectionIndex, int index, GcDbFullSubentPathArray& fullPaths);

GCCORE_PORT void gcedSetIgnoredEntAndDuplicatedBlkCount(GcEdSelectionSetService* service, int ignoredEntCount, int duplicatedBlkCount);

class GcEdSysVarIterator
{
public:
  GCCORE_PORT GcEdSysVarIterator();
  GCCORE_PORT ~GcEdSysVarIterator();

  GCCORE_PORT void step();
  GCCORE_PORT const GcRxVariable* getSysVar();
  GCCORE_PORT void reset();
  GCCORE_PORT bool done() const;
private:
  GcEdImpSysVarIterator* m_pImp = nullptr;
};

#pragma pack (pop)

#endif