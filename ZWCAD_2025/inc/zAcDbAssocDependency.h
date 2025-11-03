
#pragma once
#include "zAcDbAssocGlobal.h"
#include "zAcDbCompoundObjectId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocDependency : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocDependency);

    explicit ZcDbAssocDependency(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    ZcDbObjectId dependencyBody() const;

    Zcad::ErrorStatus setDependencyBody(const ZcDbObjectId& dependencyBodyId);

    ZcDbAssocStatus status() const;

    Zcad::ErrorStatus setStatus(ZcDbAssocStatus newStatus,
                                bool            notifyOwningAction = true);

    bool isReadDependency() const;

    bool isWriteDependency() const;

    void setIsReadDependency(bool yesNo);

    void setIsWriteDependency(bool yesNo);

    bool isObjectStateDependent() const;

    void setIsObjectStateDependent(bool yesNo);

    int order() const;

    void setOrder(int newOrder);

    ZcDbObjectId owningAction() const { return ownerId(); }

    Zcad::ErrorStatus setOwningAction(const ZcDbObjectId& actionId);

    ZcDbObjectId dependentOnObject() const;

    Zcad::ErrorStatus getDependentOnCompoundObject(ZcDbCompoundObjectId& compoundId) const;

    bool isDependentOnCompoundObject() const;

    ZcDbObjectId prevDependencyOnObject() const;

    ZcDbObjectId nextDependencyOnObject() const;

    bool isAttachedToObject() const { return !dependentOnObject().isNull(); }

    Zcad::ErrorStatus attachToObject(const ZcDbCompoundObjectId& compoundId);

    Zcad::ErrorStatus transferToObject(const ZcDbCompoundObjectId& compoundId);

    Zcad::ErrorStatus dependentOnObjectStatus() const;

    Zcad::ErrorStatus detachFromObject();

    Zcad::ErrorStatus updateDependentOnObject();

    void setDependentOnObject(const ZcDbCompoundObjectId& compoundId);

    static Zcad::ErrorStatus getFirstDependencyOnObject(const ZcDbObject* pObject,
                                                        ZcDbObjectId& firstDependencyId);

    static Zcad::ErrorStatus getDependenciesOnObject(const ZcDbObject* pObject,
                                                     bool readDependenciesWanted,
                                                     bool writeDependenciesWanted,
                                                     ZcDbObjectIdArray& dependencyIds);

    static Zcad::ErrorStatus notifyDependenciesOnObject(const ZcDbObject* pObject,
                                                        ZcDbAssocStatus   newStatus);

    bool isDelegatingToOwningAction() const;

    void setIsDelegatingToOwningAction(bool yesNo);

    bool hasCachedValue() const;

    bool isRelevantChange() const;

    Zcad::ErrorStatus notification(ZcDbAssocNotificationData* pNotifData);

    bool isDependentOnTheSameThingAs(const ZcDbAssocDependency* pOtherDependency) const;

    bool isDependentOnObjectReadOnly() const;

    bool isEqualTo(const ZcDbAssocDependency* pOtherDependency) const;

    bool isActionEvaluationInProgress() const;

    ZcDbAssocEvaluationCallback* currentEvaluationCallback() const;

    void evaluate();

    void erased(const ZcDbObject* dbObj, ZSoft::Boolean isErasing = true) override;

    void modified(const ZcDbObject* dbObj) override;

    void copied(const ZcDbObject* pDbObj, const ZcDbObject* pNewObj) override;

    void setPrevDependencyOnObject(const ZcDbObjectId& depId);

    void setNextDependencyOnObject(const ZcDbObjectId& depId);
private:
    friend class ZcDbImpAssocDependency;
    friend class ZcDbAssocDeepCloneRxEventReactor;
    friend class ZcDbAssocDeepCloneData;

};

class ZCDBCORE2D_PORT ZcDbAssocDependencyNotificationDisabler
{
public:
    explicit ZcDbAssocDependencyNotificationDisabler(bool disableIt = true);
    ~ZcDbAssocDependencyNotificationDisabler();
    static bool isDisabled();
private:
    const bool mPrev;
};

#pragma pack ( pop )
