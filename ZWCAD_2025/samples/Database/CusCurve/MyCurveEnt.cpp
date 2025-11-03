#include "stdafx.h"
#include "MyCurveEnt.h"
#include "rxboiler.h"
#include "dbproxy.h"
#include "acgi.h"

Adesk::UInt32 kCurrentVersionNumber = 1;

ACRX_DXF_DEFINE_MEMBERS(
	CMyCurve, AcDbCurve,
	AcDb::kDHL_CURRENT, AcDb::kMReleaseCurrent,
	AcDbProxyEntity::kNoOperation, MYCURVE,
	MyCurveEnt
	| Product ZRX Enabler for Curve Entity
	| Company : ZWSOFT
	| WEB Address : www.zwcad.com
)

static double pi()
{
	return atan(1.0) * 4;
}

CMyCurve::CMyCurve() : AcDbCurve()
{
}

CMyCurve::CMyCurve(const AcGePoint3d &ptC, const AcGePoint3d &ptE, int num/* =25 */) : AcDbCurve()
{
	m_ptCenter = ptC;
	m_ptEnd = ptE;
	m_number = num;
}

CMyCurve::~CMyCurve() 
{
}

void CMyCurve::setEndPoint(const AcGePoint3d &pten)
{
	m_ptEnd = pten;
}

Acad::ErrorStatus CMyCurve::dwgInFields(AcDbDwgFiler *pFiler)
{
	assertWriteEnabled();

	Acad::ErrorStatus es = AcDbCurve::dwgInFields(pFiler);
	if (es != Acad::eOk)
		return (es);

	Adesk::UInt32 version = 0;
	if ((es = pFiler->readUInt32(&version)) != Acad::eOk)
		return (es);
	if (version > kCurrentVersionNumber)
		return (Acad::eMakeMeProxy);

	pFiler->readItem(&m_ptCenter);
	pFiler->readItem(&m_ptEnd);
	pFiler->readItem(&m_number);

	return pFiler->filerStatus();
}

Acad::ErrorStatus CMyCurve::dwgOutFields(AcDbDwgFiler *pFiler) const
{
	assertReadEnabled();

	Acad::ErrorStatus es = AcDbCurve::dwgOutFields(pFiler);
	if (es != Acad::eOk)
		return (es);

	if ((es = pFiler->writeUInt32(kCurrentVersionNumber)) != Acad::eOk)
		return (es);

	pFiler->writeItem(m_ptCenter);
	pFiler->writeItem(m_ptEnd);
	pFiler->writeItem(m_number);

	return (pFiler->filerStatus());
}

Acad::ErrorStatus CMyCurve::dxfInFields(AcDbDxfFiler * filer)
{
	assertWriteEnabled();
	Acad::ErrorStatus es = AcDbCurve::dxfInFields(filer);
	if (es != Acad::eOk || !filer->atSubclassData(_T("CMyCurve")))
	{
		return filer->filerStatus();
	}

	// Check version number
	struct resbuf rb;
	if (Acad::eOk != (es = filer->readItem(&rb)))
	{
		return es;
	}

	if (AcDb::kDxfInt32 != rb.restype)
	{
		return Acad::eMakeMeProxy;
	}
	if (rb.resval.rreal > 1)
	{
		return Acad::eMakeMeProxy;
	}

	while (Acad::eOk == es)
	{
		if (Acad::eOk == (es = filer->readItem(&rb)))
		{
			switch (rb.restype)
			{
			case AcDb::kDxfXCoord:
				m_ptCenter.set(rb.resval.rpoint[X],
					rb.resval.rpoint[Y],
					rb.resval.rpoint[Z]);
				break;
			case AcDb::kDxfXCoord + 1:
				m_ptEnd.set(rb.resval.rpoint[X],
					rb.resval.rpoint[Y],
					rb.resval.rpoint[Z]);
				break;
			case AcDb::kDxfInt32 +1:
				m_number = rb.resval.rint;
				break;
			default:
				break;
			}
		}
	}

	return filer->filerStatus();
}

Acad::ErrorStatus CMyCurve::dxfOutFields(AcDbDxfFiler * filer) const
{
	assertReadEnabled();
	Acad::ErrorStatus es = AcDbCurve::dxfOutFields(filer);
	if (es != Acad::eOk)
	{
		return es;
	}
	filer->writeItem(AcDb::kDxfSubclass, _T("CMyCurve"));

	// Write version number
	filer->writeItem(AcDb::kDxfInt32, kCurrentVersionNumber);
	filer->writeItem(AcDb::kDxfXCoord, m_ptCenter);
	filer->writeItem(AcDb::kDxfXCoord + 1, m_ptEnd);
	filer->writeItem(AcDb::kDxfInt32 + 1, m_number);

	return filer->filerStatus();
}

Adesk::Boolean CMyCurve::subWorldDraw(AcGiWorldDraw *mode)
{
	assertReadEnabled();
	double radius = m_ptCenter.distanceTo(m_ptEnd);

	AcGePoint3d* verts = new AcGePoint3d[m_number + 1];
	for (int i = 0; i < m_number; i++)
	{
		verts[i].x = m_ptCenter.x + radius * cos(2 * i * pi() / m_number);
		verts[i].y = m_ptCenter.y + radius * sin(2 * i * pi() / m_number);
		verts[i].z = m_ptCenter.z;
	}
	verts[m_number] = verts[0];
	mode->geometry().polyline(m_number + 1, verts);

	delete[] verts;
	return Adesk::kTrue;
}

void CMyCurve::subViewportDraw(AcGiViewportDraw *mode)
{
	assertReadEnabled();
	AcDbCurve::subViewportDraw(mode);
}

Adesk::UInt32 CMyCurve::subViewportDrawLogicalFlags(AcGiViewportDraw *vd)
{
	assertReadEnabled();
	return AcDbCurve::subViewportDrawLogicalFlags(vd);
}

Adesk::UInt32 CMyCurve::subSetAttributes(AcGiDrawableTraits *traits)
{
	assertReadEnabled();
	return AcDbCurve::subSetAttributes(traits);
}

Adesk::UInt32 CMyCurve::getPlane(ZcGePlane &plane, ZcDb::Planarity &planarity)
{
	assertReadEnabled();
	planarity = AcDb::kLinear;
	plane.set(m_ptCenter, m_ptEnd - m_ptCenter);

	return Acad::eOk;
}

Acad::ErrorStatus CMyCurve::subGetOsnapPoints(
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds) const
{
	assertReadEnabled();
	return AcDbCurve::subGetOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds);
}

Acad::ErrorStatus CMyCurve::subGetOsnapPoints(
	AcDb::OsnapMode osnapMode,
	int gsSelectionMark,
	const AcGePoint3d &pickPoint,
	const AcGePoint3d &lastPoint,
	const AcGeMatrix3d &viewXform,
	AcGePoint3dArray &snapPoints,
	AcDbIntArray &geomIds,
	const AcGeMatrix3d &insertionMat) const
{
	assertReadEnabled();
	return AcDbCurve::subGetOsnapPoints(osnapMode, gsSelectionMark, pickPoint, lastPoint, viewXform, snapPoints, geomIds, insertionMat);
}

Acad::ErrorStatus CMyCurve::subGetGripPoints(AcGePoint3dArray &gripPoints, AcDbIntArray &osnapModes, AcDbIntArray &geomIds) const
{
	assertReadEnabled();

	return AcDbCurve::subGetGripPoints(gripPoints, osnapModes, geomIds);
}

Acad::ErrorStatus CMyCurve::subMoveGripPointsAt(const AcDbIntArray &indices, const AcGeVector3d &offset)
{
	assertWriteEnabled();

	return AcDbCurve::subMoveGripPointsAt(indices, offset);
}

Acad::ErrorStatus CMyCurve::subGetGripPoints(
	AcDbGripDataPtrArray &grips,
	const double curViewUnitSize, 
	const int gripSize,
	const AcGeVector3d &curViewDir, 
	const int bitflags) const 
{
	assertReadEnabled();

	return AcDbCurve::subGetGripPoints(grips, curViewUnitSize, gripSize, curViewDir, bitflags);
}

Acad::ErrorStatus CMyCurve::subMoveGripPointsAt(
	const AcDbVoidPtrArray &gripAppData, 
	const AcGeVector3d &offset,
	const int bitflags) 
{
	assertWriteEnabled();

	return AcDbCurve::subMoveGripPointsAt(gripAppData, offset, bitflags);
}

Adesk::Boolean CMyCurve::isClosed() const 
{
	assertReadEnabled();
	//return AcDbCurve::isClosed();
	return false;
}

Adesk::Boolean CMyCurve::isPeriodic() const 
{
	assertReadEnabled();
	return AcDbCurve::isPeriodic();
}

Acad::ErrorStatus CMyCurve::getStartParam(double &param) const
{
	assertReadEnabled();
	return AcDbCurve::getStartParam(param);
}

Acad::ErrorStatus CMyCurve::getEndParam(double &param) const
{
	assertReadEnabled();
	return AcDbCurve::getEndParam(param);
}

Acad::ErrorStatus CMyCurve::getStartPoint(AcGePoint3d &point) const
{
	assertReadEnabled();
	return AcDbCurve::getStartPoint(point);
}

Acad::ErrorStatus CMyCurve::getEndPoint(AcGePoint3d &point) const
{
	assertReadEnabled();
	return AcDbCurve::getEndPoint(point);
}

Acad::ErrorStatus CMyCurve::getPointAtParam(double param, AcGePoint3d &point) const
{
	assertReadEnabled();
	return AcDbCurve::getPointAtParam(param, point);
}

Acad::ErrorStatus CMyCurve::getParamAtPoint(const AcGePoint3d &point, double &param) const
{
	assertReadEnabled();
	return AcDbCurve::getParamAtPoint(point, param);
}

Acad::ErrorStatus CMyCurve::getDistAtParam(double param, double &dist) const
{
	assertReadEnabled();
	return AcDbCurve::getDistAtParam(param, dist);
}

Acad::ErrorStatus CMyCurve::getParamAtDist(double dist, double &param) const
{
	assertReadEnabled();
	return AcDbCurve::getParamAtDist(dist, param);
}

Acad::ErrorStatus CMyCurve::getDistAtPoint(const AcGePoint3d &point, double &dist) const
{
	assertReadEnabled();
	return AcDbCurve::getDistAtPoint(point, dist);
}

Acad::ErrorStatus CMyCurve::getPointAtDist(double dist, AcGePoint3d &point) const
{
	assertReadEnabled();
	return AcDbCurve::getPointAtDist(dist, point);
}

Acad::ErrorStatus CMyCurve::getFirstDeriv(double param, AcGeVector3d &firstDeriv) const
{
	assertReadEnabled();
	return AcDbCurve::getFirstDeriv(param, firstDeriv);
}

Acad::ErrorStatus CMyCurve::getFirstDeriv(const AcGePoint3d &point, AcGeVector3d &firstDeriv) const
{
	assertReadEnabled();
	return AcDbCurve::getFirstDeriv(point, firstDeriv);
}

Acad::ErrorStatus CMyCurve::getSecondDeriv(double param, AcGeVector3d &secDeriv) const
{
	assertReadEnabled();
	return AcDbCurve::getSecondDeriv(param, secDeriv);
}

Acad::ErrorStatus CMyCurve::getSecondDeriv(const AcGePoint3d &point, AcGeVector3d &secDeriv) const
{
	assertReadEnabled();
	return AcDbCurve::getSecondDeriv(point, secDeriv);
}

Acad::ErrorStatus CMyCurve::getClosestPointTo(const AcGePoint3d &givenPnt, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const
{
	assertReadEnabled();
	return AcDbCurve::getClosestPointTo(givenPnt, pointOnCurve, extend);
}

Acad::ErrorStatus CMyCurve::getClosestPointTo(const AcGePoint3d &givenPnt, const AcGeVector3d &direction, AcGePoint3d &pointOnCurve, Adesk::Boolean extend /*=Adesk::kFalse*/) const
{
	assertReadEnabled();
	return AcDbCurve::getClosestPointTo(givenPnt, direction, pointOnCurve, extend);
}

Acad::ErrorStatus CMyCurve::getOrthoProjectedCurve(const AcGePlane &plane, AcDbCurve *&projCrv) const
{
	assertReadEnabled();
	return AcDbCurve::getOrthoProjectedCurve(plane, projCrv);
}

Acad::ErrorStatus CMyCurve::getProjectedCurve(const AcGePlane &plane, const AcGeVector3d &projDir, AcDbCurve *&projCrv) const
{
	assertReadEnabled();
	return AcDbCurve::getProjectedCurve(plane, projDir, projCrv);
}

Acad::ErrorStatus CMyCurve::getOffsetCurves(double offsetDist, AcDbVoidPtrArray &offsetCurves) const
{
	assertReadEnabled();
	return AcDbCurve::getOffsetCurves(offsetDist, offsetCurves);
}

Acad::ErrorStatus CMyCurve::getOffsetCurvesGivenPlaneNormal(const AcGeVector3d &normal, double offsetDist, AcDbVoidPtrArray &offsetCurves) const
{
	assertReadEnabled();
	return AcDbCurve::getOffsetCurvesGivenPlaneNormal(normal, offsetDist, offsetCurves);
}

Acad::ErrorStatus CMyCurve::getSpline(AcDbSpline *&spline) const
{
	assertReadEnabled();
	return AcDbCurve::getSpline(spline);
}

Acad::ErrorStatus CMyCurve::getSplitCurves(const AcGeDoubleArray &params, AcDbVoidPtrArray &curveSegments) const
{
	assertReadEnabled();
	return AcDbCurve::getSplitCurves(params, curveSegments);
}

Acad::ErrorStatus CMyCurve::getSplitCurves(const AcGePoint3dArray &points, AcDbVoidPtrArray &curveSegments) const
{
	assertReadEnabled();
	return AcDbCurve::getSplitCurves(points, curveSegments);
}

Acad::ErrorStatus CMyCurve::extend(double newParam)
{
	assertReadEnabled();
	return AcDbCurve::extend(newParam);
}

Acad::ErrorStatus CMyCurve::extend(Adesk::Boolean extendStart, const AcGePoint3d &toPoint)
{
	assertReadEnabled();
	return AcDbCurve::extend(extendStart, toPoint);
}

Acad::ErrorStatus CMyCurve::getArea(double &area) const
{
	assertReadEnabled();
	return AcDbCurve::getArea(area);
}