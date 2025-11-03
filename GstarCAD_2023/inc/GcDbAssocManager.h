/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcString.h"
#include "GcDbAssocGlobal.h"
#pragma pack (push, 8)
#pragma warning( push )
#pragma warning( disable : 4275 ) 

class DBCONSTRAINTS_PORT GcDbAssocManager : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocManager);

  GcDbAssocManager();
  static bool                         evaluateTopLevelNetwork(GcDbDatabase*                pDatabase,
    GcDbAssocEvaluationCallback* pCallback = NULL,
    int                          callbackOrder = 0);
  static GcDbAssocEvaluationCallback* globalEvaluationMultiCallback();
  static Gcad::ErrorStatus addGlobalEvaluationCallback(GcDbAssocEvaluationCallback* pCallback, int order);
  static Gcad::ErrorStatus removeGlobalEvaluationCallback(GcDbAssocEvaluationCallback* pCallback);
  static void              getGlobalEvaluationCallbacks(GcArray<GcDbAssocEvaluationCallback*>& callbacks,
    GcArray<int>&                          orders);
  static bool              isActionEvaluationInProgress(const GcDbDatabase*);
  static Gcad::ErrorStatus requestToEvaluate(const GcDbObjectId& objectId,
    GcDbAssocStatus     newStatus = kChangedDirectlyAssocStatus,
    bool                ownedActionsAlso = true);
  static GcDbAssocEvaluationCallback* getCurrentEvaluationCallback(const GcDbDatabase*);
  static bool              hasAssocNetwork(const GcDbDatabase* pDatabase);
  static GcDbObjectId      currentlyEvaluatedAction(const GcDbDatabase*);
  static Gcad::ErrorStatus auditAssociativeData(GcDbDatabase* pDatabase, bool traverseWholeDatabase);
  static Gcad::ErrorStatus markSyncUpWithXrefsNeeded(GcDbDatabase* pDatabase);
  static Gcad::ErrorStatus syncUpWithXrefs(GcDbDatabase* pHostDatabase);
  static Gcad::ErrorStatus initialize();
  static void              uninitialize();
  static void              enableProgressMeter(bool enableIt, const GcString& progressLabel = GcString());
};

class GcDbAssocNetworkEvaluationDisabler
{
public:
  DBCONSTRAINTS_PORT explicit GcDbAssocNetworkEvaluationDisabler(GcDbDatabase*, bool disableIt = true);
  DBCONSTRAINTS_PORT ~GcDbAssocNetworkEvaluationDisabler();
  DBCONSTRAINTS_PORT static bool isDisabled(const GcDbDatabase*);

private:
  GcDbDatabase* mpDatabase;
  bool          mPreviouslyDisabled;
};

#pragma warning( pop ) 
#pragma pack (pop)