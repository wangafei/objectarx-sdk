#pragma once

#include "gcadstd.h"
#include "../rxnames.h"
#include "../Editor.h"
#include "../DbEntity.h"
#include "../Ed/EdCommandStack.h"
#include "../Ed/EdCommandContext.h"
#include "../Ed/EdUserIO.h"
#include "../DbViewTableRecord.h"
#include "../DbViewport.h"
#include "gcedinpt.h"
#include "gccmd.h"
#include "dbjig.h"
#include "gcssgetfilter.h"

#if defined(__cplusplus)
struct GcEdCommandStruc;
class GcString;
extern "C" {
#endif


GCED_DLL_DECL void gcedSendModelessOperationStart(const GCHAR* strContext);
GCED_DLL_DECL void gcedSendModelessOperationEnded(const GCHAR* strContext);

GCED_DLL_DECL void	gcedUpdateDisplay();
GCED_DLL_DECL void gcedPostCommandPrompt();

GCED_DLL_DECL int gcedCmdLookup(const GCHAR* cmdStr, int globalLookup,GcEdCommandStruc* retStruc,int skipUndef = FALSE);
GCED_DLL_DECL int gcedCmdLookup2(const GCHAR* cmdStr, int globalLookup,GcEdCommandStruc* retStruc,int sf = 0x00000800);//GCRX_CMD_DEFUN 
GCED_DLL_DECL int gcedCmdUndefine(const GCHAR* cmdStr, int undefIt);

GCED_DLL_DECL int gcedPopCommandDirectory(const GCHAR* cmdDirName);

GCED_DLL_DECL Gcad::ErrorStatus gcedGetCommandForDocument(GcApDocument* pDoc, GCHAR*& pGlobalCmdName);

#if defined(__cplusplus)
}

GCED_DLL_DECL void gcedEditToleranceInteractive(GcDbFcf* pTol);

GCED_DLL_DECL int gcedEditMTextInteractive(GcDbMText* pMText, bool useNewUI = false, bool allowTabs = false);

GCED_DLL_DECL bool gcedLinetypeDialog(GcDbObjectId old_linetypeId, bool IncludeByBlockByLayer, GCHAR *&new_linetypeName, GcDbObjectId &new_linetypeId);

GCED_DLL_DECL bool gcedLinetypeDialog2();

GCED_DLL_DECL bool gcedPlotstyleDialog(const GCHAR* sOldStrIn, bool IncludeByBlockByLayer, GCHAR* &sOldStrOut);

GCED_DLL_DECL bool gcedPlotstyleDialog2(GCHAR* &szNewStyleOut);

GCED_DLL_DECL bool gcedLineWeightDialog(GcDb::LineWeight oldLineWeight, bool bIncludeByBlockByLayer, GcDb::LineWeight& newLineWeight);

GCED_DLL_DECL Hccad::Boolean gcedSetColorDialog (int &nColor, Hccad::Boolean bAllowMetaColor, int nCurLayerColor);
GCED_DLL_DECL Hccad::Boolean gcedSetColorDialogTrueColor( GcCmColor& color, Hccad::Boolean bAllowMetaColor,
                                                        const GcCmColor& curLayerColor, GcCm::DialogTabs tabs = (GcCm::DialogTabs)(GcCm::kACITab | GcCm::kTrueColorTab  | GcCm::kColorBookTab));

//#if defined(_GCAD_WINDOWS_)
typedef void (WINAPI* GcEdColorDialogCallbackFunction)(void *pCallbackData, const GcCmColor& newColor);
GCED_DLL_DECL Hccad::Boolean gcedSetColorDialogTrueColorWithCallback( GcCmColor& color,
                                                        Hccad::Boolean bAllowMetaColor,
                                                        const GcCmColor& curLayerColor,
                                                        GcCm::DialogTabs tabs = (GcCm::DialogTabs)(GcCm::kACITab | GcCm::kTrueColorTab  | GcCm::kColorBookTab),
                                                        GcEdColorDialogCallbackFunction callback = NULL,
                                                        void * pCallbackData = NULL);
//#endif

GCED_DLL_DECL Hccad::Boolean gcedSetColorPrompt( GCHAR* promptString,
                                   GcCmColor& color,
                                   Hccad::Boolean bAllowMetaColor);

enum GcEdDrawOrderCmdType {
  kDrawOrderNone = 0,
  kDrawOrderBottom,
  kDrawOrderTop,
  kDrawOrderBelow,
  kDrawOrderAbove
};
GCED_DLL_DECL Gcad::ErrorStatus gcedDrawOrderInherit(GcDbObjectId parent,
  GcDbObjectIdArray &childArray, GcEdDrawOrderCmdType cmd);

GCED_DLL_DECL Gcad::ErrorStatus gcedCreateViewportByView(GcDbDatabase *pDb, const GcDbObjectId& view, 
                                                  const GcGePoint2d& location, double scale, GcDbObjectId& viewportId);

GCED_DLL_DECL Gcad::ErrorStatus gcedRestoreCurrentView(const GcDbObjectId& namedViewId);

GCED_DLL_DECL short gcedGetCurVportCircleSides();
GCED_DLL_DECL Gcad::ErrorStatus acedSetCurVportCircleSides(short value);

GCED_DLL_DECL void gcedGetCurVportPixelToDisplay(double& xFactor, double& yFactor);
GCED_DLL_DECL void gcedGetCurVportScreenToDisplay(double& xFactor, double& yFactor);

GCED_DLL_DECL Gcad::ErrorStatus gcedSetCurrentUCS(const GcGeMatrix3d& mat);
GCED_DLL_DECL Gcad::ErrorStatus gcedGetCurrentUCS(GcGeMatrix3d& mat);
GCED_DLL_DECL Gcad::ErrorStatus gcedRestorePreviousUCS();

GCED_DLL_DECL GcDbObjectId gcedGetCurViewportObjectId();

GCED_DLL_DECL GcDbObjectId gcedViewportIdFromNumber(int nVpNum);

GCED_DLL_DECL Gcad::ErrorStatus gcedSetCurrentVPort(int vpnumber);
GCED_DLL_DECL Gcad::ErrorStatus gcedSetCurrentVPort(const GcDbViewport* pVp);

GCED_DLL_DECL int gcedIsDragging();

GCED_DLL_DECL Gcad::ErrorStatus gcedSetCurrentView(GcDbViewTableRecord* pVwRec, GcDbViewport* pVP);

GCED_DLL_DECL Gcad::ErrorStatus gcedVportTableRecords2Vports();
GCED_DLL_DECL Gcad::ErrorStatus gcedVports2VportTableRecords();

GCED_DLL_DECL Gcad::ErrorStatus gcedVPLayer(const GcDbObjectId& vpId, const GcDbObjectIdArray& layerIds,GcDb::VpFreezeOps operation);

GCED_DLL_DECL Gcad::ErrorStatus gcedSyncFileOpen(const GCHAR* pszFileToOpen, const wchar_t* wszPassword = NULL);

GCED_DLL_DECL Gcad::ErrorStatus gcedGetCurrentSelectionSet(GcDbObjectIdArray& sset);

GCED_DLL_DECL Gcad::ErrorStatus gcedGetFullSubentPathsForCurrentSelection(
  const GcDbObjectId&      selectedObject,
  GcDbFullSubentPathArray& selectedSubentities);

GCAD_DLL_DECL Hccad::Boolean gcedIsMenuGroupLoaded(const GCHAR *pszGroupName);
GCAD_DLL_DECL bool gcedLoadPartialMenu(const GCHAR* pszMenuFile);
GCAD_DLL_DECL bool gcedUnloadPartialMenu(const GCHAR* pszMenuFile);

GCED_DLL_DECL GcDbObjectId gcedActiveViewportId();

GCED_DLL_DECL Gcad::ErrorStatus gcedMspace();
GCED_DLL_DECL Gcad::ErrorStatus gcedPspace();

GCED_DLL_DECL unsigned long gcedGetRGB(int color);

GCED_DLL_DECL Gcad::ErrorStatus 
gcedCreateEnhancedViewportOnDrop(const GCHAR *filename,
                                const GCHAR *viewName,
                                const GcGePoint2d location,
                                double scale,
                                GcDbObjectId labelBlockId,
                                GcDbObjectId& sheetViewId,
                                GcDbObjectId& viewportId);


GCED_DLL_DECL Gcad::ErrorStatus 
gcedCreateEnhancedViewportOnDropDWG(const GCHAR *filename,
                                    GcDbExtents *extents,
                                    const GcGePoint2d location,
                                    double scale,
                                    GcDbObjectId labelBlockId,
                                    GcDbObjectId& sheetViewId,
                                    GcDbObjectId& viewportId);

GCED_DLL_DECL const GcString* gcedGetUnitsValueString (GcDb::UnitsValue units);
GCED_DLL_DECL bool gcedGetUnitsConversion(GcDb::UnitsValue blkInsunits, double& conversionFactor);

GCED_DLL_DECL void gcedEnableUsrbrk();
GCED_DLL_DECL void gcedDisableUsrbrk();
GCED_DLL_DECL bool gcedIsUsrbrkDisabled();

enum BlockEditModeFlags 
{
  kBlkEditModeNone   = 0x0,
  kBlkEditModeActive = 0x01,
  kBlkEditModeOpen   = 0x02,
  kBlkEditModeDirty  = 0x04
};

GCED_DLL_DECL unsigned int gcedGetBlockEditMode();

enum GcadContextMenuMode
{
  kDefault = 0,
  kEdit,
  kCommand,
  kHotGrip,
  kOsnap
};

GCAD_DLL_DECL Hccad::Boolean gcedAddObjectContextMenu(const GcRxClass *pClass, GcEdUIContext *pContext, const void *appId);
GCAD_DLL_DECL Hccad::Boolean gcedRemoveObjectContextMenu(const GcRxClass *pClass, GcEdUIContext *pContext);

GCAD_DLL_DECL Hccad::Boolean gcedAddDefaultContextMenu(GcEdUIContext *pContext, const void *appId, const GCHAR* appName=NULL);
GCAD_DLL_DECL Hccad::Boolean gcedRemoveDefaultContextMenu(GcEdUIContext *pContext);

GCED_DLL_DECL bool    gcedSetCMBaseAlias(LPCTSTR strAlias, GcadContextMenuMode mode);
GCED_DLL_DECL LPCTSTR gcedGetCMBaseAlias(GcadContextMenuMode mode);

GCED_DLL_DECL Hccad::UInt8 gcedInitCommandVersion(Hccad::UInt8 nVersion = 0);
GCED_DLL_DECL Hccad::UInt8 gcedGetCommandVersion();
GCED_DLL_DECL Hccad::Boolean gcedInitDialog(Hccad::Boolean useDialog = Hccad::kTrue);
GCED_DLL_DECL int gcedEatCommandThroat(void);
GCED_DLL_DECL	bool gcedIsUpdateDisplayPaused (void);
GCED_DLL_DECL void gcedUpdateDisplayPause (bool bEnable);
struct IDispatch;
GCED_DLL_DECL IDispatch* gcedGetIDispatch(BOOL bAddRef);
GCED_DLL_DECL void gcdbUpdateArrrayEntLayer(GcDbEntity* pEntity);
#endif // cplusplus