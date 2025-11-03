
#pragma once
#include "zAcDbAssocGlobal.h"
#include "zdbEval.h"
#include "zAcValue.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocAction : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocAction);

    explicit ZcDbAssocAction(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ZcDbObjectId actionBody() const;

    static ZcDbObjectId actionBody(const ZcDbObjectId& actionId);

    Zcad::ErrorStatus setActionBody(const ZcDbObjectId& actionBodyId);

    bool isActionBodyAProxy() const;

    ZcDbAssocStatus status() const;

    Zcad::ErrorStatus setStatus(ZcDbAssocStatus newStatus,
                                bool            notifyOwningNetwork = true,
                                bool            setInOwnedActions   = false);

    ZcDbObjectId owningNetwork() const;

    Zcad::ErrorStatus setOwningNetwork(const ZcDbObjectId& networkId, bool alsoSetAsDatabaseOwner);

    Zcad::ErrorStatus getDependencies(bool readDependenciesWanted,
                                      bool writeDependenciesWanted,
                                      ZcDbObjectIdArray& dependencyIds) const;

    Zcad::ErrorStatus addDependency(const ZcDbObjectId& dependencyId,
                                    bool                setThisActionAsOwningAction = true);

    Zcad::ErrorStatus addDependency(ZcRxClass*    pDependencyClass,
                                    ZcRxClass*    pDependencyBodyClass,
                                    bool          isReadDep,
                                    bool          isWriteDep,
                                    int           order,
                                    ZcDbObjectId& dependencyId);

    Zcad::ErrorStatus removeDependency(const ZcDbObjectId& dependencyId,
                                       bool                alsoEraseIt);

    Zcad::ErrorStatus removeAllDependencies(bool alsoEraseThem);

    Zcad::ErrorStatus getDependentObjects(bool readDependenciesWanted,
                                          bool writeDependenciesWanted,
                                          ZcDbObjectIdArray& objectIds) const;

    bool isOwnedDependency(const ZcDbAssocDependency* pDependency) const;

    bool isExternalDependency(const ZcDbAssocDependency* pDependency) const;

    bool isRelevantDependencyChange(const ZcDbAssocDependency* pDependency) const;

    bool hasDependencyCachedValue(const ZcDbAssocDependency* pDependency) const;

    bool areDependenciesOnTheSameThing(const ZcDbAssocDependency* pDependency1,
                                       const ZcDbAssocDependency* pDependency2) const;

    bool areDependenciesEqual(const ZcDbAssocDependency* pDependency1,
                              const ZcDbAssocDependency* pDependency2) const;

    Zcad::ErrorStatus notification(ZcDbAssocNotificationData* pNotifData);

    void dependentObjectCloned(const ZcDbAssocDependency* pDependency,
                               const ZcDbObject*          pDbObj,
                               const ZcDbObject*          pNewObj);

    Zcad::ErrorStatus addMoreObjectsToDeepClone(ZcDbIdMapping& idMap,
                                                ZcDbObjectIdArray& additionalObjectsToClone) const;

    Zcad::ErrorStatus postProcessAfterDeepClone(ZcDbIdMapping& idMap);

    Zcad::ErrorStatus postProcessAfterDeepCloneCancel(ZcDbIdMapping& idMap);

    bool isActionEvaluationInProgress() const;

    ZcDbAssocEvaluationCallback* currentEvaluationCallback() const;

    Zcad::ErrorStatus evaluateDependencies();

    void evaluateDependency(ZcDbAssocDependency* pDependency);

    Zcad::ErrorStatus ownedDependencyStatusChanged(ZcDbAssocDependency* pOwnedDependency,
                                                   ZcDbAssocStatus      previousStatus);

    Zcad::ErrorStatus transformActionBy(const ZcGeMatrix3d& transform);

    bool isEqualTo(const ZcDbAssocAction* pOtherAction) const;

    ZcDbAssocEvaluationPriority evaluationPriority() const;

    void getDependentActionsToEvaluate(ZcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const;

    void evaluate(ZcDbAssocEvaluationCallback* pEvaluationCallback);

    ZcDbObjectId objectThatOwnsNetworkInstance() const;

    void dragStatus(const ZcDb::DragStat status);

    static Zcad::ErrorStatus getActionsDependentOnObject(const ZcDbObject* pObject,
                                                         bool readDependenciesWanted,
                                                         bool writeDependenciesWanted,
                                                         ZcDbObjectIdArray& actionIds);

    static Zcad::ErrorStatus removeActionsControllingObject(
        const ZcDbObjectId& objectToRemoveActionsFrom,
        int                 readOnlyDependencyHandling = 0,
        const ZcDbObjectId& objectToRedirectReadOnlyDependenciesTo = ZcDbObjectId::kNull);

    static Zcad::ErrorStatus markDependentActionsToEvaluate(const ZcDbObjectId& actionId);

    static bool doesObjectHaveActiveActions(const ZcDbObject* pObject);

    Zcad::ErrorStatus removeAllParams(bool alsoEraseThem);

    int paramCount() const;

    const ZcDbObjectIdArray& ownedParams() const;

    Zcad::ErrorStatus addParam(const ZcDbObjectId& paramId, int& paramIndex);

    Zcad::ErrorStatus addParam(const ZcString& paramName, ZcRxClass* pParamClass, ZcDbObjectId& paramId, int& paramIndex);

    Zcad::ErrorStatus removeParam(const ZcDbObjectId& paramId, bool alsoEraseIt);

    const ZcDbObjectIdArray& paramsAtName(const ZcString& paramName) const;

    ZcDbObjectId paramAtName(const ZcString& paramName, int index = 0) const;

    ZcDbObjectId paramAtIndex(int paramIndex) const;

    void ownedValueParamNames(ZcArray<ZcString>& paramNames) const;

    Zcad::ErrorStatus getValueParamArray(const ZcString&           paramName,
                                         ZcArray<ZcDbEvalVariant>& values,
                                         ZcArray<ZcString>&        expressions,
                                         ZcArray<ZcString>&        evaluatorIds) const;

    Zcad::ErrorStatus getValueParam(const ZcString&  paramName,
                                    ZcDbEvalVariant& value,
                                    ZcString&        expression,
                                    ZcString&        evaluatorId,
                                    int              valueIndex = 0) const;

    Zcad::ErrorStatus setValueParamArray(const ZcString&                 paramName,
                                         const ZcArray<ZcDbEvalVariant>& values,
                                         const ZcArray<ZcString>&        expressions,
                                         const ZcArray<ZcString>&        evaluatorIds,
                                         ZcArray<ZcString>&              errorMessages,
                                         bool                            silentMode);

    Zcad::ErrorStatus setValueParam(const ZcString&        paramName,
                                    const ZcDbEvalVariant& value,
                                    const ZcString&        expression,
                                    const ZcString&        evaluatorId,
                                    ZcString&              errorMessage,
                                    bool                   silentMode,
                                    int                    valueIndex = 0);

    ZcValue::UnitType valueParamUnitType(const ZcString& paramName) const;

    Zcad::ErrorStatus setValueParamUnitType(const ZcString& paramName, ZcValue::UnitType unitType);

    Zcad::ErrorStatus removeValueParam(const ZcString& paramName);

    Zcad::ErrorStatus valueParamInputVariables(const ZcString& paramName, ZcDbObjectIdArray& variableIds) const;

    Zcad::ErrorStatus setValueParamControlledObjectDep(const ZcString& paramName, const ZcDbObjectId& controlledObjectDepId);

    Zcad::ErrorStatus updateValueParamControlledObject(const ZcString& paramName) const;

    Zcad::ErrorStatus updateValueParamFromControlledObject(const ZcString& paramName);

    Zcad::ErrorStatus updateAllObjectsControlledByValueParams() const;

    Zcad::ErrorStatus transformAllConstantGeometryParams(const ZcGeMatrix3d& transform);

    Zcad::ErrorStatus scaleAllDistanceValueParams(double scaleFactor);

    friend class ZcDbImpAssocAction;

};

#pragma pack (pop)

