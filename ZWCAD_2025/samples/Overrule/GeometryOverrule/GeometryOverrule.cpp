#include "stdafx.h"
#include "GeometryOverrule.h"

Acad::ErrorStatus CGeometryOverrule::intersectWith(
	const AcDbEntity* pSubject,
	const AcDbEntity* pEnt,
	AcDb::Intersect intType,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker/*= 0*/,
	Adesk::GsMarker otherGsMarker/*= 0*/)
{
	acutPrintf(_T("\nGeometryOverrule::intersectWith()<name: %s>..."), pSubject->isA()->name());
	AcGePoint3dArray tmpPoints;
	Acad::ErrorStatus es;
	if (pSubject->isKindOf(AcDbLine::desc()))
	{
		AcGePoint3d pt1(50, 50, 0), pt2(100, 100, 0);
		points.append(pt1);
		points.append(pt2);
		acutPrintf(_T("\n<AcDbLine> Find %d Points"), points.length());
	}
	else if (pSubject->isKindOf(AcDbCircle::desc()))
	{
		AcGePoint3d pt(1, 1, 0);
		points.append(pt);
		acutPrintf(_T("\n<AcDbCircle> Find %d Points"), points.length());
	}
	else 
	{
		AcGePoint3d pt(2, 2, 0);
		points.append(pt);
		acutPrintf(_T("\n<OtherType> Find %d Points"), points.length());
	}

	return AcDbGeometryOverrule::intersectWith(pSubject, pEnt, intType, tmpPoints, thisGsMarker, otherGsMarker);
}

Acad::ErrorStatus CGeometryOverrule::intersectWith(
	const AcDbEntity* pSubject,
	const AcDbEntity* pEnt,
	AcDb::Intersect intType,
	const AcGePlane& projPlane,
	AcGePoint3dArray& points,
	Adesk::GsMarker thisGsMarker/*= 0*/,
	Adesk::GsMarker otherGsMarker/*= 0*/)
{
	acutPrintf(_T("\nGeometryOverrule::intersectWith(AcGePlane)<name: %s>..."), pSubject->isA()->name());
	AcGePoint3dArray tmpPoints;

	if (pSubject->isKindOf(AcDbLine::desc()))
	{
		AcGePoint3d pt1(50, 50, 0), pt2(100, 100, 0);
		points.append(pt1);
		points.append(pt2);
		acutPrintf(_T("\n<AcDbLine> Find %d Points"), points.length());
	}
	else if (pSubject->isKindOf(AcDbCircle::desc()))
	{
		AcGePoint3d pt(1, 1, 0);
		points.append(pt);
		acutPrintf(_T("\n<AcDbCircle> Find %d Points"), points.length());
	}
	else
	{
		AcGePoint3d pt(2, 2, 0);
		points.append(pt);
		acutPrintf(_T("\n<OtherType> Find %d Points"), points.length());
	}

	return AcDbGeometryOverrule::intersectWith(pSubject, pEnt, intType, projPlane, tmpPoints, thisGsMarker, otherGsMarker);
}

Acad::ErrorStatus CGeometryOverrule::getGeomExtents(const AcDbEntity* pSubject, AcDbExtents& extents)
{
	acutPrintf(_T("\nGeometryOverrule::getGeomExtents()<name: %s>..."), pSubject->isA()->name());
	AcDbExtents extTemp;

	if (pSubject->isKindOf(AcDbLine::desc()))
	{
		AcGePoint3d ptMax(100, 100, 0), ptMin(5, 5, 0);
		extents.addPoint(ptMax);
		extents.addPoint(ptMin);
		acutPrintf(_T("\nAcDbLine extents: (%g, %g)-->(%g, %g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	}
	else if (pSubject->isKindOf(AcDbCircle::desc()))
	{
		AcGePoint3d ptMax(50, 50, 0), ptMin(0, 0, 0);
		extents.addPoint(ptMax);
		extents.addPoint(ptMin);
		acutPrintf(_T("\nAcDbCircle extents: (%g, %g)-->(%g, %g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	}
	else
	{
		AcGePoint3d ptMax(20, 20, 0), ptMin(0, 0, 0);
		extents.addPoint(ptMax);
		extents.addPoint(ptMin);
		acutPrintf(_T("\nOtherType extents: (%g, %g)-->(%g, %g)"), ptMin.x, ptMin.y, ptMax.x, ptMax.y);
	}

	return AcDbGeometryOverrule::getGeomExtents(pSubject, extTemp);
}

bool CGeometryOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return true;
}