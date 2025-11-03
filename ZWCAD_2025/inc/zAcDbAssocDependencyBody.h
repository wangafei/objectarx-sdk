
#pragma once
#include "zAcDbAssocDependency.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocDependencyBody : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocDependencyBody);

    explicit ZcDbAssocDependencyBody(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);
    ~ZcDbAssocDependencyBody();

    ZcDbObjectId parentDependency() const { return ownerId(); }

    ZcDbAssocStatus status() const;

    Zcad::ErrorStatus setStatus(ZcDbAssocStatus newStatus,
                                bool notifyOwningAction = true);

    ZcDbObjectId owningAction() const;

    ZcDbObjectId dependentOnObject() const;

    bool isAttachedToObject() const { return !dependentOnObject().isNull(); }

    bool isActionEvaluationInProgress() const;

    ZcDbAssocEvaluationCallback* currentEvaluationCallback() const;

public:

    virtual void evaluateOverride() = 0;

    virtual Zcad::ErrorStatus updateDependentOnObjectOverride()
    { return Zcad::eNotImplemented; }

    virtual Zcad::ErrorStatus hasCachedValueOverride(bool& hasCachedVal) const
    {
        ZSOFT_UNREFED_PARAM(hasCachedVal);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isRelevantChangeOverride(bool& isRelevChange) const
    {
        ZSOFT_UNREFED_PARAM(isRelevChange);
        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isDependentOnTheSameThingAsOverride(const ZcDbAssocDependency* pOtherDependency,
                                                                  bool& isDependentOnSameThing) const
    {
        ZSOFT_UNREFED_PARAM(pOtherDependency);
        ZSOFT_UNREFED_PARAM(isDependentOnSameThing);

        return Zcad::eNotImplemented;
    }

    virtual Zcad::ErrorStatus isEqualToOverride(const ZcDbAssocDependency* pOtherDependency, bool& isEqual) const
    {
        ZSOFT_UNREFED_PARAM(pOtherDependency);
        ZSOFT_UNREFED_PARAM(isEqual);
        return Zcad::eNotImplemented;
    }

    virtual void erasedOverride(const ZcDbObject* pDbObj, ZSoft::Boolean isErasing)
    {
        ZSOFT_UNREFED_PARAM(pDbObj);
        ZSOFT_UNREFED_PARAM(isErasing);
    }

    virtual void modifiedOverride(const ZcDbObject* pDbObj)
    {
        ZSOFT_UNREFED_PARAM(pDbObj);
    }

    virtual void clonedOverride(const ZcDbObject* pDbObj, const ZcDbObject* pNewObj)
    {
        ZSOFT_UNREFED_PARAM(pDbObj);
        ZSOFT_UNREFED_PARAM(pNewObj);
    }

    virtual void auditAssociativeDataOverride(ZcDbAssocStatus& parentActionHandling);

};

#pragma pack (pop)

