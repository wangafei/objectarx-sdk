/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocDependency.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocValueDependency : public GcDbAssocDependency
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocValueDependency);

  explicit GcDbAssocValueDependency(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  const GcString&   valueName() const;
  Gcad::ErrorStatus setValueName(const GcString& newValueName);
  Gcad::ErrorStatus getDependentOnObjectValue(GcDbEvalVariant& objectValue) const;
  Gcad::ErrorStatus setDependentOnObjectValue(const GcDbEvalVariant& newObjectValue);
};

#pragma pack (pop)