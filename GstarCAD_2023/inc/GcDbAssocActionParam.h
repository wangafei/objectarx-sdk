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

class DBCONSTRAINTS_PORT GcDbAssocActionParam : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocActionParam);

  GcDbAssocActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  const GcString& name() const;
  virtual Gcad::ErrorStatus setName(const GcString& newName);
  virtual Gcad::ErrorStatus makeParamEmpty(bool alsoEraseOwnedObjects);
  virtual Gcad::ErrorStatus detachDependencies();
  virtual Gcad::ErrorStatus makeParamConstant();
  virtual Gcad::ErrorStatus transformConstantGeometry(const GcGeMatrix3d& transform);
  GcDbObjectId parentAction() const;
  virtual Gcad::ErrorStatus getDependencies(bool readDependenciesWanted,
                                            bool writeDependenciesWanted,
                                            GcDbObjectIdArray& dependencyIds) const;

  Gcad::ErrorStatus getCompoundObjectIds(bool                           readDependenciesWanted,
                                         bool                           writeDependenciesWanted,
                                         GcArray<GcDbCompoundObjectId>& compoundObjectIds) const;

  GcDbAssocStatus status(bool alsoCheckDependencies) const;
  Gcad::ErrorStatus setStatus(GcDbAssocStatus newStatus,
                              bool            notifyParentAction = true,
                              bool            setInOwnedParams = false);

  virtual void auditAssociativeData(GcDbAssocStatus& parentActionHandling);
  virtual void collectPersSubentNamingDataOverride(GcDbPersStepIdArray&   stepIds,
                                                   GcDbPersSubentIdArray& persSubentIds) const;
  virtual void clonePersSubentNamingDataOverride(GcDbAssocPersSubentManagerCloner* pCloner);
};

#pragma pack (pop)