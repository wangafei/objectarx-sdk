#include "stdafx.h"
#include "OsnapOverrule.h"
#include "dbents.h"

Acad::ErrorStatus COsnapOverrule::getOsnapPoints(
	const AcDbEntity * pSubject, 
	AcDb::OsnapMode osnapMode, 
	Adesk::GsMarker gsSelectionMark,
	const AcGePoint3d & pickPoint, 
	const AcGePoint3d & lastPoint,
	const AcGeMatrix3d & viewXform, 
	AcGePoint3dArray & snapPoints, 
	AcDbIntArray & geomIds)
{
	acutPrintf(_T("\nCOsnapOverrule::getOsnapPoints(8) is called!"));
	AcGePoint3d pt(100, 100, 0);
	snapPoints.append(pickPoint);
	snapPoints.append(pt);
	snapPoints.append(lastPoint);
	return Acad::eOk;
}

Acad::ErrorStatus COsnapOverrule::getOsnapPoints(
	const AcDbEntity * pSubject,
	AcDb::OsnapMode osnapMode, 
	Adesk::GsMarker gsSelectionMark, 
	const AcGePoint3d & pickPoint, 
	const AcGePoint3d & lastPoint, 
	const AcGeMatrix3d & viewXform, 
	AcGePoint3dArray & snapPoints, 
	AcDbIntArray & geomIds, 
	const AcGeMatrix3d & insertionMat)
{
	acutPrintf(_T("\nCOsnapOverrule::getOsnapPoints(9) is called!"));
	AcGePoint3d pt(200, 200, 0);
	snapPoints.append(pickPoint);
	snapPoints.append(pt);
	snapPoints.append(lastPoint);
	return Acad::eOk;
}

bool COsnapOverrule::isContentSnappable(const AcDbEntity * pSubject)
{
	if (isApplicable(pSubject))
	{
		acutPrintf(_T("\nInvoke isContentSnappable"));
		return true;
	}
	return AcDbOsnapOverrule::isContentSnappable(pSubject);
}

bool COsnapOverrule::isApplicable(const AcRxObject * pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc());
}