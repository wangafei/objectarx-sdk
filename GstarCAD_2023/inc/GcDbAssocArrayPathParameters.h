/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcDbAssocArrayCommonParameters.h"

class GcDbImpAssocArrayPathParameters;
class GcDbEdgeRef;

class GcDbAssocArrayPathParameters : public GcDbAssocArrayCommonParameters
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocArrayPathParameters, DBCONSTRAINTS_PORT);

  enum GripModes
  {
    kStretchGrip = 1 << 0,
    kRowCountGrip = 1 << 1,
    kRowSpacingGrip = 1 << 2,
    kUniformRowSpacingGrip = 1 << 3,
    kLevelCountGrip = 1 << 4,
    kLevelSpacingGrip = 1 << 5,
    kUniformLevelSpacingGrip = 1 << 6,
    kItemCountGrip = 1 << 7,
    kItemSpacingGrip = 1 << 8,
    kUniformItemSpacingGrip = 1 << 9,
  };

  DBCONSTRAINTS_PORT GcDbAssocArrayPathParameters(double itemSpacing = 1, double rowSpacing = 1,
    double levelSpacing = 1, int itemCount = 1, int rowCount = 1,
    int levelCount = 1, double rowElevation = 1);

  DBCONSTRAINTS_PORT ~GcDbAssocArrayPathParameters(void);

  enum Method
  {
    kDivide,
    kMeasure,
  };

  DBCONSTRAINTS_PORT int itemCount(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline int itemCount() const
  {
    GcString expression, evaluatorId;
    return itemCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline int itemCount(GcString & expression) const
  {
    GcString evaluatorId;
    return itemCount(expression, evaluatorId);
  }

  DBCONSTRAINTS_PORT double itemSpacing(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double itemSpacing() const
  {
    GcString expression, evaluatorId;
    return itemSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double itemSpacing(GcString& expression) const
  {
    GcString evaluatorId;
    return itemSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT GcDbEdgeRef path() const;
  DBCONSTRAINTS_PORT Method method() const;
  DBCONSTRAINTS_PORT bool alignItems() const;

  DBCONSTRAINTS_PORT double startOffset(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double startOffset() const
  {
    GcString expression, evaluatorId;
    return startOffset(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double endOffset(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double endOffset() const
  {
    GcString expression, evaluatorId;
    return endOffset(expression, evaluatorId);
  }

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setItemCount(int nItems, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setItemSpacing(double offset, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setPath(const GcDbEdgeRef& edgeRef);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setMethod(Method method);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setAlignItems(bool bAlignItems);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setStartOffset(double startOffset, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setEndOffset(double endOffset, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setPathDirection(bool bAlongParams);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getItems(GcArray<GcDbAssocArrayItem*>& items) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getItemPosition(const GcDbItemLocator& locator,
    GcGePoint3d& position, GcGeMatrix3d& xform) const override;
  DBCONSTRAINTS_PORT inline Gcad::ErrorStatus getItemPosition(const GcDbItemLocator& locator,
    GcGePoint3d& position) const
  {
    GcGeMatrix3d xform;
    return getItemPosition(locator, position, xform);
  }

protected:
  friend class GcDbImpAssocArrayPathParameters;
  DBCONSTRAINTS_PORT explicit GcDbAssocArrayPathParameters(GcDbImpAssocArrayPathParameters* pSelf);
};