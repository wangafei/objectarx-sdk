#pragma once

#include "dbents.h"
#include "dbentityoverrule.h"

class CSubentityOverrule : public AcDbSubentityOverrule
{
public:
	virtual Acad::ErrorStatus getSubentPathsAtGsMarker(
		const AcDbEntity* pSubject,
		AcDb::SubentType type,
		Adesk::GsMarker gsMark,
		const AcGePoint3d& pickPoint,
		const AcGeMatrix3d& viewXform,
		int& numPaths, AcDbFullSubentPath*& subentPaths,
		int numInserts = 0,
		AcDbObjectId* entAndInsertStack = NULL);

	virtual Acad::ErrorStatus getGsMarkersAtSubentPath(
		const AcDbEntity* pSubject,
		const AcDbFullSubentPath& subPath,
		AcArray<Adesk::GsMarker>& gsMarkers);

	virtual AcDbEntity* subentPtr(const AcDbEntity* pSubject, const AcDbFullSubentPath& id);

	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const ADESK_OVERRIDE;
};