#include "stdafx.h"
#include "SubentityOverrule.h"

Acad::ErrorStatus CSubentityOverrule::getSubentPathsAtGsMarker(
	const AcDbEntity* pSubject,
	AcDb::SubentType type,
	Adesk::GsMarker gsMark,
	const AcGePoint3d& pickPoint,
	const AcGeMatrix3d& viewXform,
	int& numPaths,
	AcDbFullSubentPath*& subentPaths,
	int numInserts/*= 0*/,
	AcDbObjectId* entAndInsertStack/*= NULL*/)
{
	return AcDbSubentityOverrule::getSubentPathsAtGsMarker(pSubject, type, gsMark, pickPoint, viewXform, numPaths, subentPaths, numInserts, entAndInsertStack);
}

Acad::ErrorStatus CSubentityOverrule::getGsMarkersAtSubentPath(
	const AcDbEntity* pSubject,
	const AcDbFullSubentPath& subPath,
	AcArray<Adesk::GsMarker>& gsMarkers)
{
	return AcDbSubentityOverrule::getGsMarkersAtSubentPath(pSubject, subPath, gsMarkers);
}

AcDbEntity* CSubentityOverrule::subentPtr(const AcDbEntity* pSubject, const AcDbFullSubentPath& id)
{
	acutPrintf(_T("\nSubentityOverrule::subentPtr is called!"));
	if (isApplicable(pSubject))
		return NULL;
	return AcDbSubentityOverrule::subentPtr(pSubject, id);
}

bool CSubentityOverrule::isApplicable(const AcRxObject* pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbPolyline::desc());
}
