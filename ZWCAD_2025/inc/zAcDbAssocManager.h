
#pragma once
#include "zAcString.h"
#include "zAcDbAssocGlobal.h"
#pragma pack (push, 8)
#pragma warning( push )
#pragma warning( disable : 4275 )

class ZCDBCORE2D_PORT ZcDbAssocManager : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocManager);

    ZcDbAssocManager();

    static bool evaluateTopLevelNetwork(ZcDbDatabase*                pDatabase,
                                        ZcDbAssocEvaluationCallback* pCallback     = NULL,
                                        int                          callbackOrder = 0);

    static ZcDbAssocEvaluationCallback* globalEvaluationMultiCallback();

    static Zcad::ErrorStatus addGlobalEvaluationCallback(ZcDbAssocEvaluationCallback* pCallback, int order);

    static Zcad::ErrorStatus removeGlobalEvaluationCallback(ZcDbAssocEvaluationCallback* pCallback);

    static void getGlobalEvaluationCallbacks(ZcArray<ZcDbAssocEvaluationCallback*>& callbacks,
                                             ZcArray<int>&                          orders);

    static bool isActionEvaluationInProgress(const ZcDbDatabase*);

    static Zcad::ErrorStatus requestToEvaluate(const ZcDbObjectId& objectId,
                                               ZcDbAssocStatus     newStatus        = kChangedDirectlyAssocStatus,
                                               bool                ownedActionsAlso = true);

    static ZcDbAssocEvaluationCallback* getCurrentEvaluationCallback(const ZcDbDatabase*);

    static bool hasAssocNetwork(const ZcDbDatabase* pDatabase);

    static ZcDbObjectId currentlyEvaluatedAction(const ZcDbDatabase*);

    static Zcad::ErrorStatus auditAssociativeData(ZcDbDatabase* pDatabase, bool traverseWholeDatabase);

    static Zcad::ErrorStatus markSyncUpWithXrefsNeeded(ZcDbDatabase* pDatabase);

    static Zcad::ErrorStatus syncUpWithXrefs(ZcDbDatabase* pHostDatabase);

    static Zcad::ErrorStatus initialize();

    static void uninitialize();

    static void enableProgressMeter(bool enableIt, const ZcString& progressLabel = ZcString());

};

class ZCDBCORE2D_PORT ZcDbAssocNetworkEvaluationDisabler
{
public:
    explicit ZcDbAssocNetworkEvaluationDisabler(ZcDbDatabase*, bool disableIt = true);
    ~ZcDbAssocNetworkEvaluationDisabler();
    static bool isDisabled(const ZcDbDatabase*);

private:
    ZcDbDatabase* mpDatabase;
    bool          mPreviouslyDisabled;
};

#pragma warning( pop )
#pragma pack (pop)

