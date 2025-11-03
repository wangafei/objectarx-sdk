/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbViewSymbol.h"
#include "dbDetailViewStyle.h"

#pragma pack (push, 8)

#ifndef GCSYNERGY_PORT
#define GCSYNERGY_PORT
#endif

class GCSYNERGY_PORT GcDbDetailSymbol : public GcDbViewSymbol
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDetailSymbol);

  GcDbDetailSymbol();

  enum BoundaryType
  {
    kCircularBoundary,
    kRectangularBoundary,
    kCustomBoundary
  };

  enum OverriddenProperty
  {
    kModelEdge = 0x00000001,
    kIdentifierPosition = 0x00000001 << 1,
  };

  BoundaryType					boundaryType() const;
  GcDbDetailViewStyle::ModelEdge	modelEdgeType() const;
  bool							    isOverriddenProperty(GcDbDetailSymbol::OverriddenProperty property) const;
  bool							    displayIdentifier() const;
  GcGePoint3d						origin() const;
  const GcGeVector3d&				direction() const;
  const GcGeVector2d&				boundarySize() const;
  const GcGePoint3d&				modelEdgeOrigin() const;
  double							      owningViewScale() const;
  double							      detailViewScale() const;
  const GcGeVector3d&				modelEdgeDirection() const;
  const GcGePoint3d				  identifierPosition() const;

  Gcad::ErrorStatus				setBoundaryType(BoundaryType bndType);
  Gcad::ErrorStatus				setModelEdgeType(GcDbDetailViewStyle::ModelEdge modelEdgeType);
  Gcad::ErrorStatus				setPickPoints(const GcGePoint3dArray& pickPoints);
  Gcad::ErrorStatus				setModelEdgeOrigin(const GcGePoint3d& pt);
  Gcad::ErrorStatus				setOwningViewScale(double viewScale);
  Gcad::ErrorStatus				setDetailViewScale(double viewScale);
  Gcad::ErrorStatus				setModelEdgeDirection(const GcGeVector3d& dir);
  Gcad::ErrorStatus				setIdentifierPosition(const GcGePoint3d& pt);
  Gcad::ErrorStatus				initializeIdentifierPositionAt(const GcGePoint3d& pt);
  Gcad::ErrorStatus				resetIdentifierPosition();
  Gcad::ErrorStatus				setDisplayIdentifier(const bool displayIdentifier);

  Gcad::ErrorStatus				setOrigin(const GcGePoint3d& pt);
  Gcad::ErrorStatus				setBoundarySize(const GcGeVector2d& size);

  Gcad::ErrorStatus				modelEdgeBorderExtents(GcDbExtents& modelEdgeExtent)const;
};

#pragma pack (pop)