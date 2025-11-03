#pragma once

#include "dbents.h"
#include "dbentityoverrule.h"

class CGeometryOverrule : public AcDbGeometryOverrule
{
public:
	virtual  Acad::ErrorStatus intersectWith(
		const AcDbEntity* pSubject,
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0);
	virtual  Acad::ErrorStatus intersectWith(
		const AcDbEntity* pSubject,
		const AcDbEntity* pEnt,
		AcDb::Intersect intType,
		const AcGePlane& projPlane,
		AcGePoint3dArray& points,
		Adesk::GsMarker thisGsMarker = 0,
		Adesk::GsMarker otherGsMarker = 0);
	virtual  Acad::ErrorStatus getGeomExtents(const AcDbEntity* pSubject, AcDbExtents& extents);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
};