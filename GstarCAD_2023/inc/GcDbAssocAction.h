/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocGlobal.h"
#include "dbeval.h"
#include "GcValue.h"
#pragma pack (push, 8)

class  GcDbAssocAction : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocAction, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocAction(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT GcDbObjectId        actionBody() const;
  DBCONSTRAINTS_PORT static GcDbObjectId actionBody(const GcDbObjectId& actionId);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus   setActionBody(const GcDbObjectId& actionBodyId);
  DBCONSTRAINTS_PORT bool                isActionBodyAProxy() const;

  DBCONSTRAINTS_PORT GcDbAssocStatus   status() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setStatus(GcDbAssocStatus newStatus,
                                                 bool notifyOwningNetwork = true,
                                                 bool setInOwnedActions = false);

  DBCONSTRAINTS_PORT GcDbObjectId      owningNetwork() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setOwningNetwork(const GcDbObjectId& networkId, bool alsoSetAsDatabaseOwner);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getDependencies(bool readDependenciesWanted,
                                                       bool writeDependenciesWanted,
                                                       GcDbObjectIdArray& dependencyIds) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addDependency(const GcDbObjectId& dependencyId,
                                                     bool setThisActionAsOwningAction = true);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addDependency(GcRxClass*    pDependencyClass,
                                                     GcRxClass*    pDependencyBodyClass,
                                                     bool          isReadDep,
                                                     bool          isWriteDep,
                                                     int           order,
                                                     GcDbObjectId& dependencyId);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus removeDependency(const GcDbObjectId& dependencyId,
                                                        bool alsoEraseIt);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus removeAllDependencies(bool alsoEraseThem);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getDependentObjects(bool readDependenciesWanted,
                                                           bool writeDependenciesWanted,
                                                           GcDbObjectIdArray& objectIds) const;

  DBCONSTRAINTS_PORT bool isOwnedDependency(const GcDbAssocDependency* pDependency) const;
  DBCONSTRAINTS_PORT bool isExternalDependency(const GcDbAssocDependency* pDependency) const;
  DBCONSTRAINTS_PORT bool isRelevantDependencyChange(const GcDbAssocDependency* pDependency) const;
  DBCONSTRAINTS_PORT bool hasDependencyCachedValue(const GcDbAssocDependency* pDependency) const;
  DBCONSTRAINTS_PORT bool areDependenciesOnTheSameThing(const GcDbAssocDependency* pDependency1,
                                                        const GcDbAssocDependency* pDependency2) const;

  DBCONSTRAINTS_PORT bool areDependenciesEqual(const GcDbAssocDependency* pDependency1,
                                               const GcDbAssocDependency* pDependency2) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus notification(GcDbAssocNotificationData* pNotifData);

  DBCONSTRAINTS_PORT void dependentObjectCloned(const GcDbAssocDependency* pDependency,
                                                const GcDbObject*          pDbObj,
                                                const GcDbObject*          pNewObj);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus addMoreObjectsToDeepClone(GcDbIdMapping& idMap,
                                                                 GcDbObjectIdArray& additionalObjectsToClone) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus postProcessAfterDeepClone(GcDbIdMapping& idMap);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus postProcessAfterDeepCloneCancel(GcDbIdMapping& idMap);
  DBCONSTRAINTS_PORT bool isActionEvaluationInProgress() const;
  DBCONSTRAINTS_PORT GcDbAssocEvaluationCallback* currentEvaluationCallback() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus evaluateDependencies();
  DBCONSTRAINTS_PORT void evaluateDependency(GcDbAssocDependency* pDependency);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus ownedDependencyStatusChanged(GcDbAssocDependency* pOwnedDependency,
                                                                    GcDbAssocStatus      previousStatus);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus transformActionBy(const GcGeMatrix3d& transform);
  DBCONSTRAINTS_PORT bool isEqualTo(const GcDbAssocAction* pOtherAction) const;
  DBCONSTRAINTS_PORT GcDbAssocEvaluationPriority evaluationPriority() const;
  DBCONSTRAINTS_PORT void getDependentActionsToEvaluate(GcDbActionsToEvaluateCallback* pActionsToEvaluateCallback) const;
  DBCONSTRAINTS_PORT void evaluate(GcDbAssocEvaluationCallback* pEvaluationCallback);
  DBCONSTRAINTS_PORT GcDbObjectId objectThatOwnsNetworkInstance() const;
  DBCONSTRAINTS_PORT void dragStatus(const GcDb::DragStat status);

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus getActionsDependentOnObject(const GcDbObject* pObject,
                                                                          bool readDependenciesWanted,
                                                                          bool writeDependenciesWanted,
                                                                          GcDbObjectIdArray& actionIds);

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus removeActionsControllingObject(
                                                                              const GcDbObjectId& objectToRemoveActionsFrom,
                                                                              int                 readOnlyDependencyHandling = 0,
                                                                              const GcDbObjectId& objectToRedirectReadOnlyDependenciesTo = GcDbObjectId::kNull);

  DBCONSTRAINTS_PORT static Gcad::ErrorStatus markDependentActionsToEvaluate(const GcDbObjectId& actionId);

  DBCONSTRAINTS_PORT static bool              doesObjectHaveActiveActions(const GcDbObject* pObject);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus        removeAllParams(bool alsoEraseThem);
  DBCONSTRAINTS_PORT int                      paramCount() const;
  DBCONSTRAINTS_PORT const GcDbObjectIdArray& ownedParams() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus addParam(const GcDbObjectId& paramId, int& paramIndex);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus addParam(const GcString& paramName, GcRxClass* pParamClass, GcDbObjectId& paramId, int& paramIndex);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus removeParam(const GcDbObjectId& paramId, bool alsoEraseIt);

  DBCONSTRAINTS_PORT const GcDbObjectIdArray& paramsAtName(const GcString& paramName) const;
  DBCONSTRAINTS_PORT GcDbObjectId             paramAtName(const GcString& paramName, int index = 0) const;
  DBCONSTRAINTS_PORT GcDbObjectId             paramAtIndex(int paramIndex) const;

  DBCONSTRAINTS_PORT void              ownedValueParamNames(GcArray<GcString>& paramNames) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getValueParamArray(const GcString&           paramName,
                                                          GcArray<GcDbEvalVariant>& values,
                                                          GcArray<GcString>&        expressions,
                                                          GcArray<GcString>&        evaluatorIds) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getValueParam(const GcString&  paramName,
                                                     GcDbEvalVariant& value,
                                                     GcString&        expression,
                                                     GcString&        evaluatorId,
                                                     int              valueIndex = 0) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setValueParamArray(const GcString&                 paramName,
                                                          const GcArray<GcDbEvalVariant>& values,
                                                          const GcArray<GcString>&        expressions,
                                                          const GcArray<GcString>&        evaluatorIds,
                                                          GcArray<GcString>&              errorMessages,
                                                          bool                            silentMode);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setValueParam(const GcString&        paramName,
                                                     const GcDbEvalVariant& value,
                                                     const GcString&        expression,
                                                     const GcString&        evaluatorId,
                                                     GcString&              errorMessage,
                                                     bool                   silentMode,
                                                     int                    valueIndex = 0);

  DBCONSTRAINTS_PORT GcValue::UnitType valueParamUnitType(const GcString& paramName) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setValueParamUnitType(const GcString& paramName, GcValue::UnitType unitType);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus removeValueParam(const GcString& paramName);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus valueParamInputVariables(const GcString& paramName, GcDbObjectIdArray& variableIds) const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setValueParamControlledObjectDep(const GcString& paramName, const GcDbObjectId& controlledObjectDepId);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateValueParamControlledObject(const GcString& paramName) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateValueParamFromControlledObject(const GcString& paramName);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateAllObjectsControlledByValueParams() const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus transformAllConstantGeometryParams(const GcGeMatrix3d& transform);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus scaleAllDistanceValueParams(double scaleFactor);

  friend class GcDbImpAssocAction;
};

#pragma pack (pop)