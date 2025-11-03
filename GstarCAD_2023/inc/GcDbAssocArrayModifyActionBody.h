/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocArrayActionBody.h"

class GcDbVertexRef;

class DBCONSTRAINTS_PORT GcDbAssocArrayModifyActionBody : public GcDbAssocArrayActionBody
{
public:
  GCDB_DECLARE_MEMBERS(GcDbAssocArrayModifyActionBody);

  explicit GcDbAssocArrayModifyActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);
  ~GcDbAssocArrayModifyActionBody(void);

  Gcad::ErrorStatus getOverridenItems(GcArray<GcDbItemLocator>& indices) const;
  Gcad::ErrorStatus setOverridenItems(const GcArray<GcDbItemLocator>& indices);

  bool controlsItem(const GcDbAssocArrayItem& item) const override;
  static Gcad::ErrorStatus createInstance(GcDbObjectId arrayId,
                                          const GcArray<GcDbItemLocator>& indices,
                                          const GcDbObjectIdArray& substEntities,
                                          GcDbVertexRef& basePoint,
                                          GcDbObjectId& actionBodyId);
};