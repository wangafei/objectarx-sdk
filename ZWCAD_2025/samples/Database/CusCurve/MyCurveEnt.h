#pragma once

#include "dbmain.h"
#include "dbcurve.h"

class CMyCurve : public AcDbCurve
{
public:
	CMyCurve();
	CMyCurve(const AcGePoint3d &ptC, const AcGePoint3d &ptE , int num = 25 );
	~CMyCurve();

	ACRX_DECLARE_MEMBERS(CMyCurve);

	void setEndPoint(const AcGePoint3d &pten);
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler *pFiler);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler *pFiler) const;
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* filer);
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* filer) const;
	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw *mode);
	virtual void subViewportDraw(AcGiViewportDraw *mode);
	virtual Adesk::UInt32 subViewportDrawLogicalFlags(AcGiViewportDraw *vd);
	virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits *traits);
	virtual Adesk::UInt32 getPlane(ZcGePlane& plane, ZcDb::Planarity& planarity);
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subGetOsnapPoints(
		AcDb::OsnapMode osnapMode,
		int gsSelectionMark,
		const AcGePoint3d &pickPoint,
		const AcGePoint3d &lastPoint,
		const AcGeMatrix3d &viewXform,
		AcGePoint3dArray &snapPoints,
		AcDbIntArray &geomIds,
		const AcGeMatrix3d &insertionMat) const;
	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray &indices, const AcGeVector3d &offset);
	virtual Acad::ErrorStatus subGetGripPoints(
		AcDbGripDataPtrArray &grips, const double curViewUnitSize, const int gripSize,
		const AcGeVector3d &curViewDir, const int bitflags) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(
		const AcDbVoidPtrArray &gripAppData, const AcGeVector3d &offset,
		const int bitflags);
	virtual Adesk::Boolean isClosed() const;//Closed/////////////////
	virtual Adesk::Boolean isPeriodic() const;//Periodic/////////////////////
	virtual Acad::ErrorStatus getStartParam(double &param) const;//Start parameter of the curve
	virtual Acad::ErrorStatus getEndParam(double &param) const;
	virtual Acad::ErrorStatus getStartPoint(AcGePoint3d &point) const;//Start point
	virtual Acad::ErrorStatus getEndPoint(AcGePoint3d &point) const;
	virtual Acad::ErrorStatus getPointAtParam(double param, AcGePoint3d &point) const;
	virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d &point, double &param) const;
	virtual Acad::ErrorStatus getDistAtParam(double param, double &dist) const;
	virtual Acad::ErrorStatus getParamAtDist(double dist, double &param) const;
	virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d &point, double &dist) const;
	virtual Acad::ErrorStatus getPointAtDist(double dist, AcGePoint3d &point) const;
	virtual Acad::ErrorStatus getFirstDeriv(double param, AcGeVector3d &firstDeriv) const;
	virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d &point, AcGeVector3d &firstDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(double param, AcGeVector3d &secDeriv) const;
	virtual Acad::ErrorStatus getSecondDeriv(const AcGePoint3d &point, AcGeVector3d &secDeriv) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const;
	virtual Acad::ErrorStatus getOrthoProjectedCurve(const AcGePlane &plane, AcDbCurve *&projCrv) const;
	virtual Acad::ErrorStatus getProjectedCurve(const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const;
	virtual Acad::ErrorStatus getOffsetCurves(double offsetDist, AcDbVoidPtrArray &offsetCurves) const;
	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const;
	virtual Acad::ErrorStatus getSpline(AcDbSpline *&spline) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const;
	virtual Acad::ErrorStatus extend(double newParam);
	virtual Acad::ErrorStatus extend(Adesk::Boolean extendStart, const AcGePoint3d &toPoint);
	virtual Acad::ErrorStatus getArea(double &area) const;

private:
	AcGePoint3d m_ptCenter;//Center of a circle
	AcGePoint3d m_ptEnd;
	int m_number;
};