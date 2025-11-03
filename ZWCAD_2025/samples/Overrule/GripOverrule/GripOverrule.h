#pragma once

#include "dbmain.h"
#include "dbmain.h"
#include "dbentityoverrule.h"

class CGripOverrule : public AcDbGripOverrule
{
public:
	virtual Acad::ErrorStatus getGripPoints(
		const AcDbEntity* pSubject,
		AcGePoint3dArray& gripPoints,
		AcDbIntArray & osnapModes,
		AcDbIntArray & geomIds);

	virtual Acad::ErrorStatus moveGripPointsAt(
		AcDbEntity* pSubject,
		const AcDbIntArray & indices,
		const AcGeVector3d& offset);

	virtual Acad::ErrorStatus getGripPoints(
		const AcDbEntity* pSubject,
		AcDbGripDataPtrArray& grips,
		const double curViewUnitSize,
		const int gripSize,
		const AcGeVector3d& curViewDir,
		const int bitflags);

	virtual Acad::ErrorStatus moveGripPointsAt(
		AcDbEntity* pSubject,
		const AcDbVoidPtrArray& gripAppData,
		const AcGeVector3d& offset,
		const int bitflags);

	virtual Acad::ErrorStatus getStretchPoints(const AcDbEntity* pSubject, AcGePoint3dArray& stretchPoints);

	virtual Acad::ErrorStatus moveStretchPointsAt(
		AcDbEntity* pSubject,
		const AcDbIntArray & indices,
		const AcGeVector3d& offset);

	virtual void gripStatus(AcDbEntity* pSubject, const AcDb::GripStat status);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
protected:
private:
};
