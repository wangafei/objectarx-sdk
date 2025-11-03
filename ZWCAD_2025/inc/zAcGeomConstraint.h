#pragma once
#include "zAcConstraintGroupNode.h"
#pragma pack (push, 8)

class ZcConstrainedGeometry;
class ZcHelpParameter;
class ZcEqualHelpParameterConstraint;
class ZcCompositeConstraint;

class ZCDB_PORT ZcGeomConstraint : public ZcConstraintGroupNode
{
public:
  ZCRX_DECLARE_MEMBERS(ZcGeomConstraint);

  enum GeomConstraintType
  {
    kHorizontal    = 0,
    kVertical         ,
    kParallel         ,
    kPerpendicular    ,
    kNormal           ,
    kColinear         ,
    kCoincident       ,
    kConcentric       ,
    kTangent          ,
    kEqualRadius      ,
    kEqualLength      ,
    kSymmetric		    ,
    kG2Smooth         ,
    kFix			
  };

  virtual Zcad::ErrorStatus getConnectedGeometries(ZcArray<ZcConstrainedGeometry*>& apConsGeoms) const;
  virtual Zcad::ErrorStatus getConnectedHelpParameters(ZcArray<ZcHelpParameter*>& apHelpParameters) const;
  virtual ZcHelpParameter*  getConnectedHelpParameterFor(const ZcConstrainedGeometry* pConsGeom) const;
  ZcCompositeConstraint*    getOwningCompositeConstraint() const;
  Zcad::ErrorStatus deactivate();
  Zcad::ErrorStatus reactivate();
  bool isActive() const;
  bool isImplied() const;
  void setIsImplied(bool yesNo);
  bool isInternal() const;
  bool isEnabled() const;

protected:

  ZcGeomConstraint();
};

class ZCDB_PORT ZcHelpParameter : public ZcConstraintGroupNode
{
public:
  ZCRX_DECLARE_MEMBERS(ZcHelpParameter);

  ZcHelpParameter(bool bCreateImp = true);
  Zcad::ErrorStatus getConnectedGeometry(ZcConstrainedGeometry*& pGeometry) const;
  Zcad::ErrorStatus getConnectedConstraint(ZcGeomConstraint*& pConstraint) const;
  Zcad::ErrorStatus getConnectedEqualparamConstraints(ZcArray<ZcEqualHelpParameterConstraint*>& apEqualParamConstrs) const;
  double getValue() const;
};

class ZCDB_PORT ZcCompositeConstraint : public ZcGeomConstraint
{
public:
  ZCRX_DECLARE_MEMBERS(ZcCompositeConstraint);

  Zcad::ErrorStatus getOwnedConstraints(ZcArray<ZcGeomConstraint*>& apSubConstraints) const;

protected:

  ZcCompositeConstraint(){}
};

#pragma pack (pop)
