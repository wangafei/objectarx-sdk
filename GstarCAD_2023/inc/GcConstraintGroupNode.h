/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcGraphNode.h"
#pragma pack (push, 8)

class GcImpConstraintGroupNode;
class GcDbImpAssoc2dConstraintGroup;
class GcDbAssoc2dConstraintGroupUtil;

class GcConstraintGroupNode : public GcGraphNode
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcConstraintGroupNode, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT virtual ~GcConstraintGroupNode();

  DBCONSTRAINTS_PORT GcDbObjectId owningConstraintGroupId()const;

protected:
  DBCONSTRAINTS_PORT GcConstraintGroupNode();

  friend class GcDbImpAssoc2dConstraintGroup;
  friend class GcDbAssoc2dConstraintGroupEvalHelper;
  friend class GcDbAssoc2dConstaintGroupCloningHelper;
};

#pragma pack (pop)