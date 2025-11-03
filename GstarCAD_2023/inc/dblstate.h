/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_LSTATE_H
#define GCDB_LSTATE_H

#include "dbmain.h"
#include "gcarray.h"
#include "GcString.h"

#pragma pack(push, 8)

class GcDbImpLayerStateManager;
class GcDbLayerStateManagerReactor;

class GCDB_PORT GcDbLayerStateManager : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbLayerStateManager);
  GcDbLayerStateManager();
  GcDbLayerStateManager(GcDbDatabase *pHostDb);
  ~GcDbLayerStateManager();

  enum LayerStateMask {
    kNone = 0x0000,
    kOn = 0x0001,
    kFrozen = 0x0002,
    kLocked = 0x0004,
    kPlot = 0x0008,
    kNewViewport = 0x0010,
    kColor = 0x0020,
    kLineType = 0x0040,
    kLineWeight = 0x0080,
    kPlotStyle = 0x0100,
    kCurrentViewport = 0x0200,
    kTransparency = 0x0400,
    kAll = kOn | kFrozen | kLocked | kPlot | kNewViewport |
    kColor | kLineType | kLineWeight | kPlotStyle |
    kCurrentViewport | kTransparency,
    kStateIsHidden = 0x8000,
    kLastRestored = 0x10000,
    kDecomposition = kAll | 0x20000
  };

  enum {
    kUndefDoNothing = 0,
    kUndefTurnOff = 1,
    kUndefFreeze = 2,
    kRestoreAsOverrides = 4
  };

  bool                addReactor(GcDbLayerStateManagerReactor * pReactor);
  bool                removeReactor(GcDbLayerStateManagerReactor * pReactor);
  GcDbObjectId        layerStatesDictionaryId(bool bCreateIfNotPresent = false);
  bool                hasLayerState(const GCHAR *sName);
  Gcad::ErrorStatus   saveLayerState(const GCHAR *sName, LayerStateMask mask);
  Gcad::ErrorStatus   restoreLayerState(const GCHAR *sName);
  Gcad::ErrorStatus   setLayerStateMask(const GCHAR *sName, LayerStateMask mask);
  Gcad::ErrorStatus   getLayerStateMask(const GCHAR *sName, LayerStateMask &returnMask);
  Gcad::ErrorStatus   deleteLayerState(const GCHAR *sName);
  Gcad::ErrorStatus   renameLayerState(const GCHAR *sName, const GCHAR *sNewName);
  Gcad::ErrorStatus   importLayerState(const GCHAR *sFilename);
  Gcad::ErrorStatus   importLayerState(const GCHAR *sFilename, GcString & sName);
  Gcad::ErrorStatus   exportLayerState(const GCHAR *sNameToExport, const GCHAR *sFilename);
  Gcad::ErrorStatus   saveLayerState(const GCHAR *sName, LayerStateMask mask, const GcDbObjectId& idVp);
  Gcad::ErrorStatus   restoreLayerState(const GCHAR *sName, const GcDbObjectId& idVp, int nRestoreFlags = 0, const LayerStateMask* pClientMask = NULL);
  Gcad::ErrorStatus   setLayerStateDescription(const GCHAR* sName, const GCHAR* sDesc);
  Gcad::ErrorStatus   getLayerStateDescription(const GCHAR* sName, GCHAR*& sDesc);
  bool                layerStateHasViewportData(const GCHAR* sName);
  Gcad::ErrorStatus   importLayerStateFromDb(const GCHAR *pStateName, GcDbDatabase* pDb);
  Gcad::ErrorStatus   getLayerStateNames(GcStringArray& lsArray, bool bIncludeHidden = true, bool bIncludeXref = true);
  Gcad::ErrorStatus   getLastRestoredLayerState(GcString & sName, GcDbObjectId &restoredLSId);
  Gcad::ErrorStatus   getLayerStateLayers(GcStringArray& layerArray, const GCHAR* sName, bool bInvert = false);
  bool                compareLayerStateToDb(const GCHAR* sName, const GcDbObjectId& idVp);
  Gcad::ErrorStatus   addLayerStateLayers(const GCHAR *sName, const GcDbObjectIdArray& layerIds);
  Gcad::ErrorStatus   removeLayerStateLayers(const GCHAR *sName, const GcStringArray& layerNames);
  bool                isDependentLayerState(const GCHAR *sName);
  GcDbDatabase *      getDatabase() const;

private:
  friend class GcDbImpDatabase;
  GcDbImpLayerStateManager *mpImpLSM;
};

class GCDB_PORT GcDbLayerStateManagerReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbLayerStateManagerReactor);

  virtual void layerStateCreated(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void layerStateCompareFailed(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void layerStateToBeRestored(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void layerStateRestored(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void abortLayerStateRestore(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void layerStateToBeDeleted(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void layerStateDeleted(const GCHAR * layerStateName);
  virtual void abortLayerStateDelete(const GCHAR * layerStateName,
    const GcDbObjectId& layerStateId);
  virtual void layerStateToBeRenamed(const GCHAR * oldLayerStateName,
    const GCHAR * newLayerStateName);
  virtual void layerStateRenamed(const GCHAR * oldLayerStateName,
    const GCHAR * newLayerStateName);
  virtual void abortLayerStateRename(const GCHAR * oldLayerStateName,
    const GCHAR * newLayerStateName);
};

#pragma pack(pop)

#endif