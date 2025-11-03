#include "stdafx.h"
#include "GripOverrule.h"
#include "dbents.h"

Acad::ErrorStatus CGripOverrule::getGripPoints(const AcDbEntity * pSubject, AcGePoint3dArray & gripPoints, AcDbIntArray & osnapModes, AcDbIntArray & geomIds)
{
	if (isApplicable(pSubject))
	{
		const AcDbLine* pLine = AcDbLine::cast(pSubject);
		if (pLine != NULL)
		{
			double len = pLine->startPoint().distanceTo(pLine->endPoint());
			if (len < 1000)
			{
				Acad::ErrorStatus es = AcDbGripOverrule::getGripPoints(pSubject, gripPoints, osnapModes, geomIds);
				gripPoints.removeAll();
				return es;
			}
		}
	}
	return AcDbGripOverrule::getGripPoints(pSubject, gripPoints, osnapModes, geomIds);
}

Acad::ErrorStatus CGripOverrule::moveGripPointsAt(AcDbEntity * pSubject, const AcDbIntArray & indices, const AcGeVector3d & offset)
{
	if (isApplicable(pSubject))
	{
		acutPrintf(_T("\noffset vector (%0.1f, %0.1f, %0.1f)"), offset.x, offset.y, offset.z);
	}
	return AcDbGripOverrule::moveGripPointsAt(pSubject, indices, offset);
}

Acad::ErrorStatus CGripOverrule::getGripPoints(const AcDbEntity * pSubject, AcDbGripDataPtrArray & grips, const double curViewUnitSize, const int gripSize, const AcGeVector3d & curViewDir, const int bitflags)
{
	if (isApplicable(pSubject))
	{
		const AcDbLine* pLine = AcDbLine::cast(pSubject);
		if (pLine != NULL)
		{
			double len = pLine->startPoint().distanceTo(pLine->endPoint());
			if (len < 1000)
			{
				Acad::ErrorStatus es = AcDbGripOverrule::getGripPoints(pSubject, grips, curViewUnitSize, gripSize, curViewDir, bitflags);
				grips.removeAll();
				return es;
			}
		}
	}
	return AcDbGripOverrule::getGripPoints(pSubject, grips, curViewUnitSize, gripSize, curViewDir, bitflags);
}

Acad::ErrorStatus CGripOverrule::moveGripPointsAt(AcDbEntity * pSubject, const AcDbVoidPtrArray & gripAppData, const AcGeVector3d & offset, const int bitflags)
{
	if (isApplicable(pSubject))
	{
		acutPrintf(_T("\noffset vector (%0.1f, %0.1f, %0.1f)"), offset.x, offset.y, offset.z);
	}
	return AcDbGripOverrule::moveGripPointsAt(pSubject, gripAppData, offset, bitflags);
}

Acad::ErrorStatus CGripOverrule::getStretchPoints(const AcDbEntity * pSubject, AcGePoint3dArray & stretchPoints)
{
	if (isApplicable(pSubject))
	{
		const AcDbLine* pLine = AcDbLine::cast(pSubject);
		if (pLine != NULL)
		{
			double len = pLine->startPoint().distanceTo(pLine->endPoint());
			if (len < 1000)
			{
				Acad::ErrorStatus es = AcDbGripOverrule::getStretchPoints(pSubject, stretchPoints);
				stretchPoints.removeAll();
				return es;
			}
		}
	}
	return AcDbGripOverrule::getStretchPoints(pSubject, stretchPoints);
}

Acad::ErrorStatus CGripOverrule::moveStretchPointsAt(AcDbEntity * pSubject, const AcDbIntArray & indices, const AcGeVector3d & offset)
{
	if (isApplicable(pSubject))
	{
		acutPrintf(_T("\noffset vector (%0.1f, %0.1f, %0.1f)"), offset.x, offset.y, offset.z);
	}
	return AcDbGripOverrule::moveStretchPointsAt(pSubject, indices, offset);
}

void CGripOverrule::gripStatus(AcDbEntity * pSubject, const AcDb::GripStat status)
{
	if (isApplicable(pSubject))
	{
		if (status == AcDb::GripStat::kDimDataToBeDeleted)
		{
			acutPrintf(_T("\ndim data to be deleted"));
		}
		else if (status == AcDb::GripStat::kGripsDone)
		{
			acutPrintf(_T("\ngrip done"));
		}
		else if (status == AcDb::GripStat::kGripsToBeDeleted)
		{
			acutPrintf(_T("\ngrip has deleted"));
		}
	}
	AcDbGripOverrule::gripStatus(pSubject, status);
}

bool CGripOverrule::isApplicable(const AcRxObject * pOverruledSubject) const
{
	return pOverruledSubject->isKindOf(AcDbLine::desc());
}