/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocActionBody.h"
#pragma pack (push, 8)

class DBCONSTRAINTS_PORT GcDbAssocParamBasedActionBody : public GcDbAssocActionBody
{
public:
  GCRX_DECLARE_MEMBERS(GcDbAssocParamBasedActionBody);

  explicit GcDbAssocParamBasedActionBody(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);
};

#pragma pack (pop)