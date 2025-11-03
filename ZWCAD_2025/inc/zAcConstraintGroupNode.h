#pragma once
#include "zAcGraphNode.h"
#pragma pack (push, 8)

class ZcImpConstraintGroupNode;
class ZcDbImpAssoc2dConstraintGroup;
class ZcDbAssoc2dConstraintGroupUtil;

class ZCDB_PORT ZcConstraintGroupNode : public ZcGraphNode
{
public:
  ZCRX_DECLARE_MEMBERS(ZcConstraintGroupNode);
  virtual ~ZcConstraintGroupNode();
  ZcDbObjectId owningConstraintGroupId()const;

protected:
  ZcConstraintGroupNode();

  friend class ZcDbImpAssoc2dConstraintGroup;
  friend class ZcDbAssoc2dConstraintGroupEvalHelper;
  friend class ZcDbAssoc2dConstaintGroupCloningHelper;
};

#pragma pack (pop)
