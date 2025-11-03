
#pragma once
#include "zAcDbAssocGlobal.h"
#include "zAcDbCompoundObjectId.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocActionParam : public ZcDbObject
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocActionParam);

    ZcDbAssocActionParam(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    const ZcString& name() const;

    virtual Zcad::ErrorStatus setName(const ZcString& newName);

    virtual Zcad::ErrorStatus makeParamEmpty(bool alsoEraseOwnedObjects);

    virtual Zcad::ErrorStatus detachDependencies();

    virtual Zcad::ErrorStatus makeParamConstant();

    virtual Zcad::ErrorStatus transformConstantGeometry(const ZcGeMatrix3d& transform);

    ZcDbObjectId parentAction() const;

    virtual Zcad::ErrorStatus getDependencies(bool readDependenciesWanted,
                                              bool writeDependenciesWanted,
                                              ZcDbObjectIdArray& dependencyIds) const;

    Zcad::ErrorStatus getCompoundObjectIds(bool                           readDependenciesWanted,
                                           bool                           writeDependenciesWanted,
                                           ZcArray<ZcDbCompoundObjectId>& compoundObjectIds) const;

    ZcDbAssocStatus status(bool alsoCheckDependencies) const;

    Zcad::ErrorStatus setStatus(ZcDbAssocStatus newStatus,
                                bool            notifyParentAction = true,
                                bool            setInOwnedParams   = false);

    virtual void auditAssociativeData(ZcDbAssocStatus& parentActionHandling);

    virtual void collectPersSubentNamingDataOverride(ZcDbPersStepIdArray&   stepIds,
                                                     ZcDbPersSubentIdArray& persSubentIds) const;

    virtual void clonePersSubentNamingDataOverride(ZcDbAssocPersSubentManagerCloner* pCloner);
};

#pragma pack (pop)

