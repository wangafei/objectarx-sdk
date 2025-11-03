/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GcDbAssocArrayParameters.h"
#include "GcDbAssocActionBody.h"

class GcDbImpAssocArrayCommonParameters;
class GcDbVertexRef;
class GcDbFaceRef;

class GcDbAssocArrayCommonParameters : public GcDbAssocArrayParameters
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocArrayCommonParameters, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT ~GcDbAssocArrayCommonParameters(void);

  DBCONSTRAINTS_PORT int levelCount(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline int levelCount() const
  {
    GcString expression, evaluatorId;
    return levelCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline int levelCount(GcString& expression) const
  {
    GcString evaluatorId;
    return levelCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double levelSpacing(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double levelSpacing() const
  {
    GcString expression, evaluatorId;
    return levelSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double levelSpacing(GcString& expression) const
  {
    GcString evaluatorId;
    return levelSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT int rowCount(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline int rowCount() const
  {
    GcString expression, evaluatorId;
    return rowCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline int rowCount(GcString& expression) const
  {
    GcString evaluatorId;
    return rowCount(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double rowElevation(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double rowElevation() const
  {
    GcString expression, evaluatorId;
    return rowElevation(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double rowElevation(GcString& expression) const
  {
    GcString evaluatorId;
    return rowElevation(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT double rowSpacing(GcString& expression, GcString& evaluatorId) const;
  DBCONSTRAINTS_PORT inline double rowSpacing() const
  {
    GcString expression, evaluatorId;
    return rowSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT inline double rowSpacing(GcString& expression) const
  {
    GcString evaluatorId;
    return rowSpacing(expression, evaluatorId);
  }
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setLevelCount(int nLevels, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setLevelSpacing(double offset, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());

  DBCONSTRAINTS_PORT Gcad::ErrorStatus setRowCount(int nRows, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setRowElevation(double elevation, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setRowSpacing(double offset, const GcString& expression = GcString(),
    const GcString& evaluatorId = GcString(), GcString& errorMessage = dummyString());

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getBasePlane(GcDbVertexRef& basePoint,
    GcGeVector3d& normal, GcDbFaceRef* pFace = NULL) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus setBasePlane(const GcDbVertexRef& basePoint,
    const GcGeVector3d& normal, const GcDbFaceRef* pFace = NULL);

  DBCONSTRAINTS_PORT GcDbItemLocator getCanonicalForm(const GcDbItemLocator& locator) const override;

protected:
  friend class GcDbImpAssocArrayCommonParameters;
  DBCONSTRAINTS_PORT explicit GcDbAssocArrayCommonParameters(GcDbImpAssocArrayCommonParameters* pSelf);
};