
#pragma once
#include "zAcDbAssocAction.h"
#include "zdbEval.h"
#include "zAcValue.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocActionBody : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocActionBody);

    explicit ZcDbAssocActionBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);
    ~ZcDbAssocActionBody();

    ZcDbObjectId parentAction() const { return ownerId(); }

    static ZcDbObjectId parentAction(const ZcDbObjectId& actionBodyId);

    ZcDbAssocStatus status() const;

    Zcad::ErrorStatus setStatus(ZcDbAssocStatus newStatus,
                                bool            notifyOwningNetwork = true,
                                bool            setInOwnedActions   = false) const;

    ZcDbObjectId owningNetwork() const;

    Zcad::ErrorStatus getDependencies(bool readDependenciesWanted,
                                      bool writeDependenciesWanted,
                                      ZcDbObjectIdArray& dependencyIds) const;

    Zcad::ErrorStatus addDependency(const ZcDbObjectId& dependencyId,
                                    bool                setThisActionAsOwningAction = true) const;

    Zcad::ErrorStatus addDependency(ZcRxClass*    pDependencyClass,
                                    ZcRxClass*    pDependencyBodyClass,
                                    bool          isReadDep,
                                    bool          isWriteDep,
                                    int           order,
                                    ZcDbObjectId& dependencyId) const;

    Zcad::ErrorStatus removeDependency(const ZcDbObjectId& dependencyId,
                                       bool                alsoEraseIt) const;

    Zcad::ErrorStatus removeAllDependencies(bool alsoEraseThem) const;

    Zcad::ErrorStatus evaluateDependencies() const;

    bool isActionEvaluationInProgress() const;

    ZcDbAssocEvaluationCallback* currentEvaluationCallback() const;

    Zcad::ErrorStatus removeAllParams(bool alsoEraseThem) const;

    int paramCount() const;

    const ZcDbObjectIdArray& ownedParams() const;

    Zcad::ErrorStatus addParam(const ZcDbObjectId& paramId, int& paramIndex) const;

    Zcad::ErrorStatus addParam(const ZcString& paramName, ZcRxClass* pParamClass, ZcDbObjectId& paramId, int& paramIndex) const;

    Zcad::ErrorStatus removeParam(const ZcDbObjectId& paramId, bool alsoEraseIt) const;

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
                                         bool                            silentMode) const;

    Zcad::ErrorStatus setValueParam(const ZcString&        paramName,
                                    const ZcDbEvalVariant& value,
                                    const ZcString&        expression,
                                    const ZcString&        evaluatorId,
                                    ZcString&              errorMessage,
                                    bool                   silentMode,
                                    int                    valueIndex = 0) const;

    ZcValue::UnitType valueParamUnitType(const ZcString& paramName) const;

    Zcad::ErrorStatus setValueParamUnitType(const ZcString& paramName, ZcValue::UnitType unitType) const;

    Zcad::ErrorStatus removeValueParam(const ZcString& paramName) const;

    Zcad::ErrorStatus valueParamInputVariables(const ZcString& paramName, ZcDbObjectIdArray& variableIds) const;

    Zcad::ErrorStatus setValueParamControlledObjectDep(const ZcString& paramName, const ZcDbObjectId& controlledObjectDepId) const;

    Zcad::ErrorStatus updateValueParamControlledObject(const ZcString& paramName) const;

    Zcad::ErrorStatus updateValueParamFromControlledObject(const ZcString& paramName) const;

    Zcad::ErrorStatus updateAllObjectsControlledByValueParams() const;

    Zcad::ErrorStatus transformAllConstantGeometryParams(const ZcGeMatrix3d& transform) const;

    Zcad::ErrorStatus scaleAllDistanceValueParams(double scaleFactor) const;

    bool hasAnyErasedOrBrokenDependencies() const;

    static Zcad::ErrorStatus createActionAndActionBodyAndPostToDatabase(
        ZcRxClass*          pActionBodyClass,
        const ZcDbObjectId& objectId,
        ZcDbObjectId&       createdActionId,
        ZcDbObjectId&       createdActionBodyId);

    static Zcad::ErrorStatus getActionBodiesOnObject(const ZcDbObject*  pObject,
                                                     bool               ignoreInternalActions,
                                                     bool               ignoreSuppressedActions,
                                                     ZcDbObjectId*      pWriteOnlyActionBodyId,
                                                     ZcDbObjectIdArray* pReadWriteActionBodyIds,
                                                     ZcDbObjectIdArray* pReadOnlyActionBodyIds = NULL);

public:

    virtual void evaluateOverride() = 0;

    virtual Zcad::ErrorStatus getDependenciesOverride(bool readDependenciesWanted,
                                                      bool writeDependenciesWanted,
                                                      ZcDbObjectIdArray& dependencyIds) const
    {
        ZSOFT_UNREFED_PARAM(readDependenciesWanted);
        ZSOFT_UNREFED_PARAM(writeDependenciesWanted);
        ZSOFT_UNREFED_PARAM(dependencyIds);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getDependentObjectsOverride(bool readDependenciesWanted,
                                                          bool writeDependenciesWanted,
                                                          ZcDbObjectIdArray& objectIds) const
    {
        ZSOFT_UNREFED_PARAM(readDependenciesWanted);
        ZSOFT_UNREFED_PARAM(writeDependenciesWanted);
        ZSOFT_UNREFED_PARAM(objectIds);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus removeAllDependenciesOverride(bool alsoEraseThem)
    {
        ZSOFT_UNREFED_PARAM(alsoEraseThem);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isOwnedDependencyOverride(const ZcDbAssocDependency* pDependency,
                                                        bool& isOwnedDependency) const
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        ZSOFT_UNREFED_PARAM(isOwnedDependency);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isExternalDependencyOverride(const ZcDbAssocDependency* pDependency,
                                                           bool& isExternalDependency) const
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        ZSOFT_UNREFED_PARAM(isExternalDependency);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus hasDependencyCachedValueOverride(const ZcDbAssocDependency* pDependency,
                                                               bool& hasDepCachedValue) const
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        ZSOFT_UNREFED_PARAM(hasDepCachedValue);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isRelevantDependencyChangeOverride(const ZcDbAssocDependency* pDependency,
                                                                 bool& isRelevantDepChange) const
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        ZSOFT_UNREFED_PARAM(isRelevantDepChange);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus areDependenciesOnTheSameThingOverride(const ZcDbAssocDependency* pDependency1,
                                                                    const ZcDbAssocDependency* pDependency2,
                                                                    bool& areDependentOnSameThing) const
    {
        ZSOFT_UNREFED_PARAM(pDependency1);
        ZSOFT_UNREFED_PARAM(pDependency2);
        ZSOFT_UNREFED_PARAM(areDependentOnSameThing);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus areDependenciesEqualOverride(const ZcDbAssocDependency* pDependency1,
                                                           const ZcDbAssocDependency* pDependency2,
                                                           bool& areEqual) const
    {
        ZSOFT_UNREFED_PARAM(pDependency1);
        ZSOFT_UNREFED_PARAM(pDependency2);
        ZSOFT_UNREFED_PARAM(areEqual);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus evaluateDependencyOverride(ZcDbAssocDependency* pDependency)
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus dependentObjectClonedOverride(const ZcDbAssocDependency* pDependency,
                                                            const ZcDbObject*          pDbObj,
                                                            const ZcDbObject*          pNewObj)
    {
        ZSOFT_UNREFED_PARAM(pDependency);
        ZSOFT_UNREFED_PARAM(pDbObj);
        ZSOFT_UNREFED_PARAM(pNewObj);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus addMoreObjectsToDeepCloneOverride(ZcDbIdMapping& ,
                                                                ZcDbObjectIdArray& ) const
    {
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus postProcessAfterDeepCloneOverride(ZcDbIdMapping& )
    {
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus postProcessAfterDeepCloneCancelOverride(ZcDbIdMapping& )
    {
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus ownedDependencyStatusChangedOverride(ZcDbAssocDependency* pOwnedDependency,
                                                                   ZcDbAssocStatus      previousStatus)
    {
        ZSOFT_UNREFED_PARAM(pOwnedDependency);
        ZSOFT_UNREFED_PARAM(previousStatus);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isEqualToOverride(const ZcDbAssocAction* pOtherAction, bool& isEqual) const
    {
        ZSOFT_UNREFED_PARAM(pOtherAction);
        ZSOFT_UNREFED_PARAM(isEqual);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus evaluationPriorityOverride(ZcDbAssocEvaluationPriority& priority) const
    {
        ZSOFT_UNREFED_PARAM(priority);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus getDependentActionsToEvaluateOverride(ZcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const
    {
        ZSOFT_UNREFED_PARAM(pActionsToEvaluateCallback);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus transformActionByOverride(const ZcGeMatrix3d&)
    { return Zcad::eNotImplemented; }

    virtual Zcad::ErrorStatus dragStatusOverride(const ZcDb::DragStat status)
    {
        ZSOFT_UNREFED_PARAM(status);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus removeActionsControllingObjectOverride(ZcDbObject* pControlledObject)
    {
        ZSOFT_UNREFED_PARAM(pControlledObject);
        return Zcad::eNotImplemented;
    }

    virtual void auditAssociativeDataOverride(ZcDbAssocStatus& parentActionHandling);

    virtual Zcad::ErrorStatus notificationOverride(class ZcDbAssocNotificationData* pNotificationData);

    virtual Zcad::ErrorStatus collectPersSubentNamingDataOverride(ZcDbPersStepIdArray&   stepIds,
                                                                  ZcDbPersSubentIdArray& persSubentIds) const;

    virtual Zcad::ErrorStatus clonePersSubentNamingDataOverride(class ZcDbAssocPersSubentManagerCloner* pCloner);

};

ZCDBCORE2D_PORT ZcString& dummyString();

#pragma pack (pop)

