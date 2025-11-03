/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocActionParam.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocCompoundActionParam : public GcDbAssocActionParam
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocCompoundActionParam);

  explicit GcDbAssocCompoundActionParam(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  virtual Gcad::ErrorStatus removeAllParams(bool alsoEraseThem);
  int paramCount() const;
  const GcDbObjectIdArray& ownedParams() const;
  Gcad::ErrorStatus addParam(const GcDbObjectId& paramId, int& paramIndex);
  Gcad::ErrorStatus removeParam(const GcDbObjectId& paramId, bool alsoEraseIt);
  const GcDbObjectIdArray& paramsAtName(const GcString& paramName) const;
  GcDbObjectId paramAtName(const GcString& paramName, int index = 0) const;
  GcDbObjectId paramAtIndex(int paramIndex) const;
};

#pragma pack (pop)