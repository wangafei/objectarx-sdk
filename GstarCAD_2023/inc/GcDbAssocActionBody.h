/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocAction.h"
#include "dbeval.h"
#include "GcValue.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocActionBody : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocActionBody);

  explicit GcDbAssocActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);
  ~GcDbAssocActionBody();

  GcDbObjectId parentAction() const { return ownerId(); }
  static GcDbObjectId parentAction(const GcDbObjectId& actionBodyId);

  GcDbAssocStatus status() const;
  Gcad::ErrorStatus setStatus(GcDbAssocStatus newStatus,
                              bool            notifyOwningNetwork = true,
                              bool            setInOwnedActions = false) const;

  GcDbObjectId owningNetwork() const;

  Gcad::ErrorStatus getDependencies(bool readDependenciesWanted,
                                    bool writeDependenciesWanted,
                                    GcDbObjectIdArray& dependencyIds) const;

  Gcad::ErrorStatus addDependency(const GcDbObjectId& dependencyId,
                                  bool                setThisActionAsOwningAction = true) const;

  Gcad::ErrorStatus addDependency(GcRxClass*    pDependencyClass,
                                  GcRxClass*    pDependencyBodyClass,
                                  bool          isReadDep,
                                  bool          isWriteDep,
                                  int           order,
                                  GcDbObjectId& dependencyId) const;

  Gcad::ErrorStatus removeDependency(const GcDbObjectId& dependencyId,
                                     bool                alsoEraseIt) const;

  Gcad::ErrorStatus removeAllDependencies(bool alsoEraseThem) const;
  Gcad::ErrorStatus evaluateDependencies() const;
  bool isActionEvaluationInProgress() const;
  GcDbAssocEvaluationCallback* currentEvaluationCallback() const;
  Gcad::ErrorStatus removeAllParams(bool alsoEraseThem) const;
  int paramCount() const;
  const GcDbObjectIdArray& ownedParams() const;
  Gcad::ErrorStatus addParam(const GcDbObjectId& paramId, int& paramIndex) const;
  Gcad::ErrorStatus addParam(const GcString& paramName, GcRxClass* pParamClass, GcDbObjectId& paramId, int& paramIndex) const;
  Gcad::ErrorStatus removeParam(const GcDbObjectId& paramId, bool alsoEraseIt) const;
  const GcDbObjectIdArray& paramsAtName(const GcString& paramName) const;
  GcDbObjectId paramAtName(const GcString& paramName, int index = 0) const;
  GcDbObjectId paramAtIndex(int paramIndex) const;
  void ownedValueParamNames(GcArray<GcString>& paramNames) const;

  Gcad::ErrorStatus getValueParamArray(const GcString&           paramName,
                                       GcArray<GcDbEvalVariant>& values,
                                       GcArray<GcString>&        expressions,
                                       GcArray<GcString>&        evaluatorIds) const;

  Gcad::ErrorStatus getValueParam(const GcString&  paramName,
                                  GcDbEvalVariant& value,
                                  GcString&        expression,
                                  GcString&        evaluatorId,
                                  int              valueIndex = 0) const;

  Gcad::ErrorStatus setValueParamArray(const GcString&                 paramName,
                                       const GcArray<GcDbEvalVariant>& values,
                                       const GcArray<GcString>&        expressions,
                                       const GcArray<GcString>&        evaluatorIds,
                                       GcArray<GcString>&              errorMessages,
                                       bool                            silentMode) const;

  Gcad::ErrorStatus setValueParam(const GcString&        paramName,
                                  const GcDbEvalVariant& value,
                                  const GcString&        expression,
                                  const GcString&        evaluatorId,
                                  GcString&              errorMessage,
                                  bool                   silentMode,
                                  int                    valueIndex = 0) const;

  GcValue::UnitType valueParamUnitType(const GcString& paramName) const;
  Gcad::ErrorStatus setValueParamUnitType(const GcString& paramName, GcValue::UnitType unitType) const;
  Gcad::ErrorStatus removeValueParam(const GcString& paramName) const;
  Gcad::ErrorStatus valueParamInputVariables(const GcString& paramName, GcDbObjectIdArray& variableIds) const;
  Gcad::ErrorStatus setValueParamControlledObjectDep(const GcString& paramName, const GcDbObjectId& controlledObjectDepId) const;
  Gcad::ErrorStatus updateValueParamControlledObject(const GcString& paramName) const;
  Gcad::ErrorStatus updateValueParamFromControlledObject(const GcString& paramName) const;
  Gcad::ErrorStatus updateAllObjectsControlledByValueParams() const;
  Gcad::ErrorStatus transformAllConstantGeometryParams(const GcGeMatrix3d& transform) const;
  Gcad::ErrorStatus scaleAllDistanceValueParams(double scaleFactor) const;
  bool hasAnyErasedOrBrokenDependencies() const;

  static Gcad::ErrorStatus createActionAndActionBodyAndPostToDatabase(
                                                                      GcRxClass*          pActionBodyClass,
                                                                      const GcDbObjectId& objectId,
                                                                      GcDbObjectId&       createdActionId,
                                                                      GcDbObjectId&       createdActionBodyId);

  static Gcad::ErrorStatus getActionBodiesOnObject(const GcDbObject*  pObject,
                                                   bool               ignoreInternalActions,
                                                   bool               ignoreSuppressedActions,
                                                   GcDbObjectId*      pWriteOnlyActionBodyId,
                                                   GcDbObjectIdArray* pReadWriteActionBodyIds,
                                                   GcDbObjectIdArray* pReadOnlyActionBodyIds = NULL);

public:
  virtual void evaluateOverride() = 0;
  virtual Gcad::ErrorStatus getDependenciesOverride(bool readDependenciesWanted,
    bool writeDependenciesWanted,
    GcDbObjectIdArray& dependencyIds) const
  {
    GSOFT_UNREFED_PARAM(readDependenciesWanted);
    GSOFT_UNREFED_PARAM(writeDependenciesWanted);
    GSOFT_UNREFED_PARAM(dependencyIds);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getDependentObjectsOverride(bool readDependenciesWanted,
    bool writeDependenciesWanted,
    GcDbObjectIdArray& objectIds) const
  {
    GSOFT_UNREFED_PARAM(readDependenciesWanted);
    GSOFT_UNREFED_PARAM(writeDependenciesWanted);
    GSOFT_UNREFED_PARAM(objectIds);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus removeAllDependenciesOverride(bool alsoEraseThem)
  {
    GSOFT_UNREFED_PARAM(alsoEraseThem);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus isOwnedDependencyOverride(const GcDbAssocDependency* pDependency,
    bool& isOwnedDependency) const
  {
    GSOFT_UNREFED_PARAM(pDependency);
    GSOFT_UNREFED_PARAM(isOwnedDependency);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus isExternalDependencyOverride(const GcDbAssocDependency* pDependency,
    bool& isExternalDependency) const
  {
    GSOFT_UNREFED_PARAM(pDependency);
    GSOFT_UNREFED_PARAM(isExternalDependency);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus hasDependencyCachedValueOverride(const GcDbAssocDependency* pDependency,
    bool& hasDepCachedValue) const
  {
    GSOFT_UNREFED_PARAM(pDependency);
    GSOFT_UNREFED_PARAM(hasDepCachedValue);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus isRelevantDependencyChangeOverride(const GcDbAssocDependency* pDependency,
    bool& isRelevantDepChange) const
  {
    GSOFT_UNREFED_PARAM(pDependency);
    GSOFT_UNREFED_PARAM(isRelevantDepChange);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus areDependenciesOnTheSameThingOverride(const GcDbAssocDependency* pDependency1,
    const GcDbAssocDependency* pDependency2,
    bool& areDependentOnSameThing) const
  {
    GSOFT_UNREFED_PARAM(pDependency1);
    GSOFT_UNREFED_PARAM(pDependency2);
    GSOFT_UNREFED_PARAM(areDependentOnSameThing);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus areDependenciesEqualOverride(const GcDbAssocDependency* pDependency1,
    const GcDbAssocDependency* pDependency2,
    bool& areEqual) const
  {
    GSOFT_UNREFED_PARAM(pDependency1);
    GSOFT_UNREFED_PARAM(pDependency2);
    GSOFT_UNREFED_PARAM(areEqual);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus evaluateDependencyOverride(GcDbAssocDependency* pDependency)
  {
    GSOFT_UNREFED_PARAM(pDependency);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus dependentObjectClonedOverride(const GcDbAssocDependency* pDependency,
    const GcDbObject*          pDbObj,
    const GcDbObject*          pNewObj)
  {
    GSOFT_UNREFED_PARAM(pDependency);
    GSOFT_UNREFED_PARAM(pDbObj);
    GSOFT_UNREFED_PARAM(pNewObj);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus addMoreObjectsToDeepCloneOverride(GcDbIdMapping&,
    GcDbObjectIdArray&) const
  {
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus postProcessAfterDeepCloneOverride(GcDbIdMapping&)
  {
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus postProcessAfterDeepCloneCancelOverride(GcDbIdMapping&)
  {
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus ownedDependencyStatusChangedOverride(GcDbAssocDependency* pOwnedDependency,
    GcDbAssocStatus      previousStatus)
  {
    GSOFT_UNREFED_PARAM(pOwnedDependency);
    GSOFT_UNREFED_PARAM(previousStatus);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus isEqualToOverride(const GcDbAssocAction* pOtherAction, bool& isEqual) const
  {
    GSOFT_UNREFED_PARAM(pOtherAction);
    GSOFT_UNREFED_PARAM(isEqual);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus evaluationPriorityOverride(GcDbAssocEvaluationPriority& priority) const
  {
    GSOFT_UNREFED_PARAM(priority);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus getDependentActionsToEvaluateOverride(GcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const
  {
    GSOFT_UNREFED_PARAM(pActionsToEvaluateCallback);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus transformActionByOverride(const GcGeMatrix3d&)
  {
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus dragStatusOverride(const GcDb::DragStat status)
  {
    GSOFT_UNREFED_PARAM(status);
    return Gcad::eNotImplemented;
  }

  virtual Gcad::ErrorStatus removeActionsControllingObjectOverride(GcDbObject* pControlledObject)
  {
    GSOFT_UNREFED_PARAM(pControlledObject);
    return Gcad::eNotImplemented;
  }

  virtual void auditAssociativeDataOverride(GcDbAssocStatus& parentActionHandling);
  virtual Gcad::ErrorStatus notificationOverride(class GcDbAssocNotificationData* pNotificationData);
  virtual Gcad::ErrorStatus collectPersSubentNamingDataOverride(GcDbPersStepIdArray&   stepIds,
                                                                GcDbPersSubentIdArray& persSubentIds) const;
  virtual Gcad::ErrorStatus clonePersSubentNamingDataOverride(class GcDbAssocPersSubentManagerCloner* pCloner);
};

DBCONSTRAINTS_PORT GcString& dummyString();

#pragma pack (pop)