/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcConstraintGroupNode.h"
#pragma pack (push, 8)

class GcConstrainedGeometry;
class GcHelpParameter;
class GcEqualHelpParameterConstraint;
class GcCompositeConstraint;

class GcGeomConstraint : public GcConstraintGroupNode
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcGeomConstraint, DBCONSTRAINTS_PORT);

  enum GeomConstraintType
  {
    kHorizontal = 0,
    kVertical,
    kParallel,
    kPerpendicular,
    kNormal,
    kColinear,
    kCoincident,
    kConcentric,
    kTangent,
    kEqualRadius,
    kEqualLength,
    kSymmetric,
    kG2Smooth,
    kFix
  };

  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getConnectedGeometries(GcArray<GcConstrainedGeometry*>& apConsGeoms) const;
  DBCONSTRAINTS_PORT virtual Gcad::ErrorStatus getConnectedHelpParameters(GcArray<GcHelpParameter*>& apHelpParameters) const;
  DBCONSTRAINTS_PORT virtual GcHelpParameter*  getConnectedHelpParameterFor(const GcConstrainedGeometry* pConsGeom) const;
  DBCONSTRAINTS_PORT GcCompositeConstraint*    getOwningCompositeConstraint() const;

  DBCONSTRAINTS_PORT Gcad::ErrorStatus deactivate();
  DBCONSTRAINTS_PORT Gcad::ErrorStatus reactivate();

  DBCONSTRAINTS_PORT bool isActive() const;
  DBCONSTRAINTS_PORT bool isImplied() const;
  DBCONSTRAINTS_PORT void setIsImplied(bool yesNo);
  DBCONSTRAINTS_PORT bool isInternal() const;
  DBCONSTRAINTS_PORT bool isEnabled() const;

protected:
  DBCONSTRAINTS_PORT GcGeomConstraint();
};

class GcHelpParameter : public GcConstraintGroupNode
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcHelpParameter, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT GcHelpParameter(bool bCreateImp = true);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConnectedGeometry(GcConstrainedGeometry*& pGeometry) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConnectedConstraint(GcGeomConstraint*& pConstraint) const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus getConnectedEqualparamConstraints(GcArray<GcEqualHelpParameterConstraint*>& apEqualParamConstrs) const;
  DBCONSTRAINTS_PORT double getValue() const;
};

class  GcCompositeConstraint : public GcGeomConstraint
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcCompositeConstraint, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT Gcad::ErrorStatus getOwnedConstraints(GcArray<GcGeomConstraint*>& apSubConstraints) const;

protected:
  DBCONSTRAINTS_PORT GcCompositeConstraint() {}
};

#pragma pack (pop)