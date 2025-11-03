#pragma once
#include "gcadstd.h"
#include "../DbEntity.h"
#include "../rxsrvice.h"


enum DimstyleTabSuppressed
{
  kSymbolsArrowsTabSuppressed = 0x01,
  kTextTabSuppressed = 0x02,
  kFitTabSuppressed = 0x04,
  kPrimaryTabSuppressed = 0x08,
  kAlternateTabSuppressed = 0x10,
  kToleranceTabSuppressed = 0x20
};

enum GcHatchEdReact
{
  kStartHatchWatcher = 1,
  kSwapHatchId,
  kUpRootHatchWatcher,
  kDestroyHatchWatcher,
  kDisableNextStart,
  kRecomputeBoundary
};

enum GcHatchNotifier
{
  kNobody = 0x00,
  kImpHatch = 0x01,
  kBoundary = 0x02,
  kHatchAndBoundary = (kImpHatch | kBoundary),
  kAddScale = 0x04
};

GCED_DLL_DECL int gcedEditDimstyleInteractiveEx(GcDbDatabase * pDb, GcDbDimStyleTableRecord * pRec,
  int familyType, const GCHAR* title = NULL, int tabCtrlFlags = 0);

GCED_DLL_DECL Gcad::ErrorStatus gcedConvertEntityToHatch(GcDbHatch* pHatch, GcDbEntity*& pEnt, bool transferId);

GCED_DLL_DECL Gcad::ErrorStatus gcedManageHatchEditorReactor(GcDbObjectId hatchId, GcHatchEdReact action,
  GcDbObjectId boundaryId = GcDbObjectId::kNull,
  GcHatchNotifier notifyType = kNobody,
  bool transformed = false);

GCED_DLL_DECL bool gcdbCanonicalToSystemRange(int eUnits, const GcString& strIn, GcString& strOut);

GCED_DLL_DECL bool gcdbSystemRangeToCanonical(int eUnits, const GcString& strIn, GcString& strOut);

GCED_DLL_DECL bool gcedIsInBackgroundMode();

GCED_DLL_DECL void gcedOpenDocWindowsMinimized(bool bMinimized);

GCED_DLL_DECL bool gcedCompareToCurrentViewport(const GcDbViewTableRecord *pVwRec);

GCED_DLL_DECL unsigned long gcedGetAnimationFrameId(void);

GCED_DLL_DECL bool gcedShowConstraintBar(GcDbFullSubentPathArray &subentPaths);

GCED_DLL_DECL void gcedDisableDefaultARXExceptionHandler(Hccad::Boolean disable = Hccad::kTrue);

class OdEdServices : public OdRxService
{
public:
  ODRX_DECLARE_MEMBERS(OdEdServices);
  virtual OdEdCommand* newAcEdCommand(GcRxFunctionPtr cmdFcnAddr, OdInt32 cmdFlags) const = 0;
};

class CGdUiPathname;

class OdEditorReactor3 : public OdEditorReactor2
{
public:
  ODRX_DECLARE_MEMBERS(OdEditorReactor3);

  virtual void fullRegenEnded(OdDbDatabase*  pDb,
    const OdDbIntArray & regenedViewports) {}

  virtual void curDocOpenUpgraded(OdDbDatabase* pDb,
    const CGdUiPathname& filename)
  {}

  virtual void curDocOpenDowngraded(OdDbDatabase* pDb,
    const CGdUiPathname& filename)
  {}
};


  GCED_DLL_DECL Hccad::Boolean gcedSetOLELock(int handle, int flags = 0);

  GCED_DLL_DECL Hccad::Boolean gcedClearOLELock(int handle);
