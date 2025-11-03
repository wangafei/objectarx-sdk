/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocParamBasedActionBody.h"
#include "GcDbAssocArrayItem.h"

class GcDbVertexRef;
class GcDbAssocArrayParameters;

class DBCONSTRAINTS_PORT GcDbAssocArrayActionBody : public GcDbAssocParamBasedActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocArrayActionBody);

  explicit GcDbAssocArrayActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);
  ~GcDbAssocArrayActionBody(void);

  const GcDbAssocArrayParameters* parameters() const;
  GcDbAssocArrayParameters* parameters();

  Gcad::ErrorStatus deleteItem(const GcDbItemLocator& index, bool bErase = true);
  Gcad::ErrorStatus transformItemBy(const GcDbItemLocator& index,
                                    const GcGeMatrix3d&    xform);

  void getItems(GcArray<GcDbItemLocator>& indices, bool skipErased = true) const;
  const GcDbAssocArrayItem* getItemAt(const GcDbItemLocator& index,
                                      GcDbFullSubentPath& path) const;
  inline const GcDbAssocArrayItem* getItemAt(const GcDbItemLocator& index) const
  {
    GcDbFullSubentPath path = GcDbFullSubentPath();
    return getItemAt(index, path);
  }

  const GcDbAssocArrayItem* getItemAt(const GcDbFullSubentPath& path) const;
  void evaluateOverride() override;
  virtual GcDbObjectId getArrayEntity() const;
  virtual bool controlsItem(const GcDbAssocArrayItem& index) const;
  virtual Gcad::ErrorStatus transformBy(const GcGeMatrix3d& xform);
  virtual GcGeMatrix3d getTransform() const;
  GcDbObjectIdArray getSourceEntities() const;

  Gcad::ErrorStatus addSourceEntity(GcDbObjectId entity,
                                    const GcGePoint3d& basePoint);
  Gcad::ErrorStatus removeSourceEntity(GcDbObjectId entity);

  Gcad::ErrorStatus setSourceBasePoint(const GcDbVertexRef& basePoint);
  Gcad::ErrorStatus getSourceBasePoint(GcDbVertexRef& vertexRef,
                                       GcGePoint3d& position) const;

  static bool              isAssociativeArray(const GcDbEntity* pEntity);
  static GcDbObjectId      getControllingActionBody(const GcDbEntity* pEntity,
                                               const GcDbItemLocator* pItemIndex = NULL);
  static Gcad::ErrorStatus explode(GcDbEntity* pEntity,
                                   GcDbObjectIdArray& newIds);
  static Gcad::ErrorStatus resetArrayItems(GcDbObjectId arrayEntityId,
                                           const GcArray<GcDbItemLocator>& indices, bool resetAll = false);
  static Gcad::ErrorStatus getArrayItemLocators(const GcDbFullSubentPathArray& subents, 
                                                GcArray<GcDbItemLocator>& indices);
  static Gcad::ErrorStatus createInstance(const GcDbObjectIdArray& sourceEntites,
                                          GcDbVertexRef& basePoint, const GcDbAssocArrayParameters* pParameters,
                                          GcDbObjectId& arrayId, GcDbObjectId& actionBodyId);
  GcDbObjectId             getArraySourceBTR() const;
  Gcad::ErrorStatus        addMoreObjectsToDeepCloneOverride(GcDbIdMapping& idMap,
                                                      GcDbObjectIdArray& additionalObjectsToClone) const override;
  Gcad::ErrorStatus        postProcessAfterDeepCloneOverride(GcDbIdMapping& idMap) override;
  Gcad::ErrorStatus        dragStatusOverride(const GcDb::DragStat status) override;
};