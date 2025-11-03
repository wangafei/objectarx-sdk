#pragma once

#include "dbmain.h"
#include "dbentityoverrule.h"

class COsnapOverrule : public AcDbOsnapOverrule
{
public:

	virtual Acad::ErrorStatus getOsnapPoints(
		const AcDbEntity*   pSubject,
		AcDb::OsnapMode     osnapMode,
		Adesk::GsMarker     gsSelectionMark,
		const AcGePoint3d&  pickPoint,
		const AcGePoint3d&  lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray&   snapPoints,
		AcDbIntArray &   geomIds);

	virtual Acad::ErrorStatus getOsnapPoints(
		const AcDbEntity*   pSubject,
		AcDb::OsnapMode     osnapMode,
		Adesk::GsMarker     gsSelectionMark,
		const AcGePoint3d&  pickPoint,
		const AcGePoint3d&  lastPoint,
		const AcGeMatrix3d& viewXform,
		AcGePoint3dArray&   snapPoints,
		AcDbIntArray &   geomIds,
		const AcGeMatrix3d& insertionMat);

	virtual bool isContentSnappable(const AcDbEntity*   pSubject);
	virtual bool isApplicable(const AcRxObject* pOverruledSubject) const;
protected:
private:
};