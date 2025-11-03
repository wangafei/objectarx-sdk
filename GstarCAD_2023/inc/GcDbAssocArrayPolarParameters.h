/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcDbAssocArrayCommonParameters.h"

class GcDbImpAssocArrayPolarParameters;

class GcDbAssocArrayPolarParameters : public GcDbAssocArrayCommonParameters
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocArrayPolarParameters, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcDbAssocArrayPolarParameters(double angle = 15, double rowSpacing = 1,
    double levelSpacing = 1, int itemCount = 1, int rowCount = 1,
    int levelCount = 1, double rowElevation = 1);
  DBCONSTRAINTS_PORT ~GcDbAssocArrayPolarParameters(void);

  enum GripModes
  {
    kCenterPointGrip = 1 << 0,
    kStretchRadiusGrip = 1 << 1,
    kRowCountGrip = 1 << 2,
    kRowSpacingGrip = 1 << 3,
    kUniformRowSpacingGrip = 1 << 4,
    kLevelCountGrip = 1 << 5,
    kLevelSpacingGrip = 1 << 6,
    kUniformLevelSpacingGrip = 1 << 7,
    kItemCountGrip = 1 << 8,
    kAngleBetweenItemsGrip = 1 << 9,
    kFillAngleGrip = 1 << 10,
  };

  enum Direction
  {
    kClockwise,
    kCounterClockwise,
  };

  DBCONSTRAINTS_PORT int itemCount(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline int itemCount() const
  {
    GcString expression, evaluatorId;
    return itemCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline int itemCount(GcString& expression) const
  {
    GcString evaluatorId;
    return itemCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double angleBetweenItems(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double angleBetweenItems() const
  {
    GcString expression, evaluatorId;
    return angleBetweenItems(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double angleBetweenItems(GcString& expression) const
  {
    GcString evaluatorId;
    return angleBetweenItems(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double fillAngle(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double fillAngle() const
  {
    GcString expression, evaluatorId;
    return fillAngle(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double fillAngle(GcString& expression) const
  {
    GcString evaluatorId;
    return fillAngle(expression, evaluatorId);
  }

  DBCONSTRAINTS_PORT double startAngle(GcString& expression, GcString& evaluatorId) const;

  DBCONSTRAINTS_PORT Direction direction() const;

  DBCONSTRAINTS_PORT bool rotateItems() const;

  DBCONSTRAINTS_PORT double radius(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double radius() const
  {
    GcString expression, evaluatorId;
    return radius(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double radius(GcString& expression) const
  {
    GcString evaluatorId;
    return radius(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setItemCount(int nItems, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setAngleBetweenItems(double angle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setFillAngle(double fillAngle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setStartAngle(double angle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setDirection(Direction direction);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setRotateItems(bool bRotateItems);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setRadius(double radius, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getItems(GcArray<GcDbAssocArrayItem*>& items) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getItemPosition(const GcDbItemLocator& locator,
    GcGePoint3d& position, GcGeMatrix3d& xform) const override;

protected:
  friend class GcDbImpAssocArrayPolarParameters;
  DBCONSTRAINTS_PORT explicit GcDbAssocArrayPolarParameters(GcDbImpAssocArrayPolarParameters* pSelf);
};