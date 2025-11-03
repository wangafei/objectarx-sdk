

#pragma once

#include "zdbViewSymbol.h"	
#include "zdbDetailViewStyle.h"

#pragma pack (push, 8)


#ifndef ZCSYNERGY_PORT
#define ZCSYNERGY_PORT _declspec(dllexport)
#endif


class ZCSYNERGY_PORT ZcDbDetailSymbol : public ZcDbViewSymbol
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbDetailSymbol);

	ZcDbDetailSymbol();

	enum BoundaryType
    {
        kCircularBoundary,
        kRectangularBoundary,
		kCustomBoundary
    };

	enum OverriddenProperty
	{
		kModelEdge            = 0x00000001,
        kIdentifierPosition   = 0x00000001 << 1,
	};

    BoundaryType					boundaryType () const;
	ZcDbDetailViewStyle::ModelEdge	modelEdgeType() const;
	bool							isOverriddenProperty(ZcDbDetailSymbol::OverriddenProperty property) const;
    bool							displayIdentifier() const;
    ZcGePoint3d						origin () const;
    const ZcGeVector3d&				direction () const;
    const ZcGeVector2d&				boundarySize () const;
	const ZcGePoint3d&				modelEdgeOrigin() const;
	double							owningViewScale () const;
    double							detailViewScale () const;
	const ZcGeVector3d&				modelEdgeDirection () const;
	const ZcGePoint3d				identifierPosition () const;

    
    
    Zcad::ErrorStatus				setBoundaryType (BoundaryType bndType);
	Zcad::ErrorStatus				setModelEdgeType(ZcDbDetailViewStyle::ModelEdge modelEdgeType);
    Zcad::ErrorStatus				setPickPoints (const ZcGePoint3dArray& pickPoints);
	Zcad::ErrorStatus				setModelEdgeOrigin(const ZcGePoint3d& pt);
	Zcad::ErrorStatus				setOwningViewScale (double viewScale);
    Zcad::ErrorStatus				setDetailViewScale (double viewScale);
    Zcad::ErrorStatus				setModelEdgeDirection (const ZcGeVector3d& dir);
    Zcad::ErrorStatus				setIdentifierPosition (const ZcGePoint3d& pt);
	Zcad::ErrorStatus				initializeIdentifierPositionAt (const ZcGePoint3d& pt);
    Zcad::ErrorStatus				resetIdentifierPosition ();
    Zcad::ErrorStatus				setDisplayIdentifier (const bool displayIdentifier);

    Zcad::ErrorStatus				setOrigin (const ZcGePoint3d& pt);
    Zcad::ErrorStatus				setBoundarySize (const ZcGeVector2d& size);

    Zcad::ErrorStatus				modelEdgeBorderExtents(ZcDbExtents& modelEdgeExtent)const;
};

#pragma pack (pop)
