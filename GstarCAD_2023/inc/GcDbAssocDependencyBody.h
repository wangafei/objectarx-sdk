/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocDependency.h"
#pragma pack (push, 8)

class GcDbAssocDependencyBody : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocDependencyBody, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocDependencyBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);
  DBCONSTRAINTS_PORT ~GcDbAssocDependencyBody();

  DBCONSTRAINTS_PORT GcDbObjectId parentDependency() const { return ownerId(); }
  DBCONSTRAINTS_PORT GcDbAssocStatus status() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setStatus(GcDbAssocStatus newStatus,
    bool notifyOwningAction = true);
  DBCONSTRAINTS_PORT GcDbObjectId owningAction() const;
  DBCONSTRAINTS_PORT GcDbObjectId dependentOnObject() const;
  DBCONSTRAINTS_PORT bool isAttachedToObject() const { return !dependentOnObject().isNull(); }
  DBCONSTRAINTS_PORT bool isActionEvaluationInProgress() const;
  DBCONSTRAINTS_PORT GcDbAssocEvaluationCallback* currentEvaluationCallback() const;

public:
  DBCONSTRAINTS_PORT virtual void evaluateOverride() = 0;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus updateDependentOnObjectOverride()
  {
    return Gcad::eNotImplemented;
  }

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus hasCachedValueOverride(bool& hasCachedVal) const
  {
    GSOFT_UNREFED_PARAM(hasCachedVal);
    return Gcad::eNotImplemented;
  }

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus isRelevantChangeOverride(bool& isRelevChange) const
  {
    GSOFT_UNREFED_PARAM(isRelevChange);
    return Gcad::eNotImplemented;
  }

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus isDependentOnTheSameThingAsOverride(const GcDbAssocDependency* pOtherDependency,
    bool& isDependentOnSameThing) const
  {
    GSOFT_UNREFED_PARAM(pOtherDependency);
    GSOFT_UNREFED_PARAM(isDependentOnSameThing);

    return Gcad::eNotImplemented;
  }

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus isEqualToOverride(const GcDbAssocDependency* pOtherDependency, bool& isEqual) const
  {
    GSOFT_UNREFED_PARAM(pOtherDependency);
    GSOFT_UNREFED_PARAM(isEqual);
    return Gcad::eNotImplemented;
  }

  DBCONSTRAINTS_PORT virtual void erasedOverride(const GcDbObject* pDbObj, Gsoft::Boolean isErasing)
  {
    GSOFT_UNREFED_PARAM(pDbObj);
    GSOFT_UNREFED_PARAM(isErasing);
  }

  DBCONSTRAINTS_PORT virtual void modifiedOverride(const GcDbObject* pDbObj)
  {
    GSOFT_UNREFED_PARAM(pDbObj);
  }

  DBCONSTRAINTS_PORT virtual void clonedOverride(const GcDbObject* pDbObj, const GcDbObject* pNewObj)
  {
    GSOFT_UNREFED_PARAM(pDbObj);
    GSOFT_UNREFED_PARAM(pNewObj);
  }

  DBCONSTRAINTS_PORT virtual void auditAssociativeDataOverride(GcDbAssocStatus& parentActionHandling);
};

#pragma pack (pop)