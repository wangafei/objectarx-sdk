/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcDbAssocArrayCommonParameters.h"

class GcDbImpAssocArrayRectangularParameters;

class GcDbAssocArrayRectangularParameters : public GcDbAssocArrayCommonParameters
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocArrayRectangularParameters, DBCONSTRAINTS_PORT);

  enum GripModes
  {
    kStretchGrip = 1 << 0,
    kRowCountGrip = 1 << 1,
    kRowSpacingGrip = 1 << 2,
    kUniformRowSpacingGrip = 1 << 3,
    kColumnCountGrip = 1 << 4,
    kColumnSpacingGrip = 1 << 5,
    kUniformColSpacingGrip = 1 << 6,
    kRowColumnCountGrip = 1 << 7,
    kRowColumnSpacingGrip = 1 << 8,
    kColumnDirectionGrip = 1 << 9,
    kRowDirectionGrip = 1 << 10,
    kLevelCountGrip = 1 << 11,
    kLevelSpacingGrip = 1 << 12,
    kUniformLevelSpacingGrip = 1 << 13,
    kRowAxisAngleGrip = 1 << 14,
  };

  DBCONSTRAINTS_PORT GcDbAssocArrayRectangularParameters(double columnSpacing = 1, double rowSpacing = 1,
    double levelSpacing = 1, int columnCount = 1, int rowCount = 1,
    int levelCount = 1, double rowElevation = 1, double axesAngle = 90);
  DBCONSTRAINTS_PORT ~GcDbAssocArrayRectangularParameters(void);

  DBCONSTRAINTS_PORT int columnCount(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline int columnCount() const
  {
    GcString expression, evaluatorId;
    return columnCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline int columnCount(GcString& expression) const
  {
    GcString evaluatorId;
    return columnCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double columnSpacing(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double columnSpacing() const
  {
    GcString expression, evaluatorId;
    return columnSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double columnSpacing(GcString& expression) const
  {
    GcString evaluatorId;
    return columnSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double axesAngle(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double axesAngle() const
  {
    GcString expression, evaluatorId;
    return axesAngle(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double axesAngle(GcString& expression) const
  {
    GcString evaluatorId;
    return axesAngle(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT GcGeVector3d      axisDirection(GcGeVector3d* pYAxis = NULL) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setColumnCount(int nColumns, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setColumnSpacing(double offset, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setAxesAngle(double axesAngle, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setAxisDirection(const GcGeVector3d& xAxis);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getItems(GcArray<GcDbAssocArrayItem*>& items) const override;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getItemPosition(const GcDbItemLocator& locator,
    GcGePoint3d& position, GcGeMatrix3d& xform) const override;

protected:
  friend class GcDbImpAssocArrayRectangularParameters;
  DBCONSTRAINTS_PORT explicit GcDbAssocArrayRectangularParameters(GcDbImpAssocArrayRectangularParameters* pSelf);
};