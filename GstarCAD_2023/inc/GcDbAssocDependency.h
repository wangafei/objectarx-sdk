/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocGlobal.h"
#include "GcDbCompoundObjectId.h"
#pragma pack (push, 8)

class  GcDbAssocDependency : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocDependency, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocDependency(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT GcDbObjectId dependencyBody() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setDependencyBody(const GcDbObjectId& dependencyBodyId);
  DBCONSTRAINTS_PORT GcDbAssocStatus status() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setStatus(GcDbAssocStatus newStatus,
    bool            notifyOwningAction = true);
  DBCONSTRAINTS_PORT bool isReadDependency() const;
  DBCONSTRAINTS_PORT bool isWriteDependency() const;
  DBCONSTRAINTS_PORT void setIsReadDependency(bool yesNo);
  DBCONSTRAINTS_PORT void setIsWriteDependency(bool yesNo);
  DBCONSTRAINTS_PORT bool isObjectStateDependent() const;
  DBCONSTRAINTS_PORT void setIsObjectStateDependent(bool yesNo);
  DBCONSTRAINTS_PORT int order() const;
  DBCONSTRAINTS_PORT void setOrder(int newOrder);
  DBCONSTRAINTS_PORT GcDbObjectId owningAction() const { return ownerId(); }
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setOwningAction(const GcDbObjectId& actionId);
  DBCONSTRAINTS_PORT GcDbObjectId dependentOnObject() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getDependentOnCompoundObject(GcDbCompoundObjectId& compoundId) const;
  DBCONSTRAINTS_PORT bool isDependentOnCompoundObject() const;
  DBCONSTRAINTS_PORT GcDbObjectId prevDependencyOnObject() const;
  DBCONSTRAINTS_PORT GcDbObjectId nextDependencyOnObject() const;
  DBCONSTRAINTS_PORT bool isAttachedToObject() const { return !dependentOnObject().isNull(); }
  DBCONSTRAINTS_PORT Gcad::ErrorStatus attachToObject(const GcDbCompoundObjectId& compoundId);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus transferToObject(const GcDbCompoundObjectId& compoundId);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus dependentOnObjectStatus() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus detachFromObject();
  DBCONSTRAINTS_PORT Gcad::ErrorStatus updateDependentOnObject();
  DBCONSTRAINTS_PORT void setDependentOnObject(const GcDbCompoundObjectId& compoundId);
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus getFirstDependencyOnObject(const GcDbObject* pObject,
    GcDbObjectId& firstDependencyId);
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus getDependenciesOnObject(const GcDbObject* pObject,
    bool readDependenciesWanted,
    bool writeDependenciesWanted,
    GcDbObjectIdArray& dependencyIds);
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus notifyDependenciesOnObject(const GcDbObject* pObject,
    GcDbAssocStatus   newStatus);
  DBCONSTRAINTS_PORT bool isDelegatingToOwningAction() const;
  DBCONSTRAINTS_PORT void setIsDelegatingToOwningAction(bool yesNo);
  DBCONSTRAINTS_PORT bool hasCachedValue() const;
  DBCONSTRAINTS_PORT bool isRelevantChange() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus notification(GcDbAssocNotificationData* pNotifData);
  DBCONSTRAINTS_PORT bool isDependentOnTheSameThingAs(const GcDbAssocDependency* pOtherDependency) const;
  DBCONSTRAINTS_PORT bool isDependentOnObjectReadOnly() const;
  DBCONSTRAINTS_PORT bool isEqualTo(const GcDbAssocDependency* pOtherDependency) const;
  DBCONSTRAINTS_PORT bool isActionEvaluationInProgress() const;
  DBCONSTRAINTS_PORT GcDbAssocEvaluationCallback* currentEvaluationCallback() const;
  DBCONSTRAINTS_PORT void evaluate();
  DBCONSTRAINTS_PORT void erased(const GcDbObject* dbObj, Gsoft::Boolean isErasing = true) override;
  DBCONSTRAINTS_PORT void modified(const GcDbObject* dbObj) override;
  DBCONSTRAINTS_PORT void copied(const GcDbObject* pDbObj, const GcDbObject* pNewObj) override;

private:
  DBCONSTRAINTS_PORT void setPrevDependencyOnObject(const GcDbObjectId& depId);
  DBCONSTRAINTS_PORT void setNextDependencyOnObject(const GcDbObjectId& depId);
  friend class GcDbImpAssocDependency;
  friend class GcDbAssocDeepCloneRxEventReactor;
  friend class GcDbAssocDeepCloneData;
};

class GCDB_PORT GcDbAssocDependencyNotificationDisabler
{
public:
  explicit GcDbAssocDependencyNotificationDisabler(bool disableIt = true);
  ~GcDbAssocDependencyNotificationDisabler();
  static bool isDisabled();
private:
  const bool mPrev;
};

#pragma pack ( pop )