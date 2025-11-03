#pragma once
#include "stdafx.h"
#include "accmd.h"
#include "dbgrip.h"
#include "dbpl.h"

class CMyAppData;

class Pipe : public AcDbCurve
{
public:
	ACRX_DECLARE_MEMBERS(Pipe);

	enum
	{
		eSubentTypeCenterLine = 1,
		eSubentTypeBorderLine,
		eSubentTypeCloseLine,
		eSubentTypeDiaLabel,
	};

	enum
	{
		kDxfStuffId = AcDb::kDxfInt16 + 1,
	};

	Pipe();
	virtual ~Pipe();

	AcGePoint3d StartPoint() const;

	void SetStartPoint(const AcGePoint3d& pnt);

	AcGePoint3d EndPoint() const;

	void SetEndPoint(const AcGePoint3d& pnt);

	double Diameter() const;

	void SetDiameter(double diameter);

	Adesk::Int16 StuffId() const;

	void SetStuffId(Adesk::Int16 nStuffId);

	virtual Acad::ErrorStatus ConvertFrom(AcDbEntity* pEnt);

	virtual Acad::ErrorStatus applyPartialUndo(AcDbDwgFiler* pFiler, AcRxClass* classObj);
	virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler* pFiler) const;
	virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler* pFiler);
	virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler* pFiler) const;
	virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler* pFiler);

	virtual Adesk::Boolean isClosed() const;
	virtual Adesk::Boolean isPlanar() const;
	virtual Acad::ErrorStatus getPlane(AcGePlane& plane, AcDb::Planarity& type) const;
	virtual Acad::ErrorStatus getStartParam(double& param) const;
	virtual Acad::ErrorStatus getEndParam(double& param) const;
	virtual Acad::ErrorStatus getStartPoint(AcGePoint3d& point) const;
	virtual Acad::ErrorStatus getEndPoint(AcGePoint3d& point) const;
	virtual Acad::ErrorStatus getPointAtParam(double param, AcGePoint3d& point) const;
	virtual Acad::ErrorStatus getParamAtPoint(const AcGePoint3d& point, double& param) const;
	virtual Acad::ErrorStatus getDistAtPoint(const AcGePoint3d& point, double& dist)const;
	virtual Acad::ErrorStatus getPointAtDist(double dist, AcGePoint3d& point) const;
	virtual Acad::ErrorStatus getFirstDeriv(double param, AcGeVector3d& firstDeriv) const;
	virtual Acad::ErrorStatus getFirstDeriv(const AcGePoint3d& point, AcGeVector3d& firstDeriv) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt, AcGePoint3d& pointOnCurve, Adesk::Boolean extend = Adesk::kFalse) const;
	virtual Acad::ErrorStatus getClosestPointTo(const AcGePoint3d& givenPnt, const AcGeVector3d& direction, AcGePoint3d& pointOnCurve, Adesk::Boolean extend = Adesk::kFalse) const;
	virtual Acad::ErrorStatus getOffsetCurvesGivenPlaneNormal(const AcGeVector3d& normal, double offsetDist, AcDbVoidPtrArray& offsetCurves) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGeDoubleArray& params, AcDbVoidPtrArray& curveSegments) const;
	virtual Acad::ErrorStatus getSplitCurves(const AcGePoint3dArray& points, AcDbVoidPtrArray& curveSegments) const;
	virtual Acad::ErrorStatus extend(double newParam);
	virtual Acad::ErrorStatus extend(Adesk::Boolean extendStart, const AcGePoint3d& toPoint);

	static AcDbObjectId m_currentPipe;
	static double m_currentDiameter;

protected:
	static Adesk::UInt32 kCurrentVersionNumber;

	virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw* mode);

	virtual void subViewportDraw(AcGiViewportDraw* mode);

	virtual Acad::ErrorStatus subGetGeomExtents(AcDbExtents& extents) const;

	virtual Acad::ErrorStatus subExplode(AcDbVoidPtrArray& entitySet) const;

	virtual void subList() const;

	virtual Acad::ErrorStatus subGetClassID(CLSID* pClsid) const;

	// ------------------------------------------------------------------------------------------------------------------------

	virtual Acad::ErrorStatus subGetSubentPathsAtGsMarker(AcDb::SubentType type, int gsMark, const AcGePoint3d& pickPoint, const AcGeMatrix3d& viewXform, int& numPaths, AcDbFullSubentPath*& subentPaths, int numInserts, AcDbObjectId* entAndInsertStack) const;

	virtual Acad::ErrorStatus subGetGsMarkersAtSubentPath(const AcDbFullSubentPath& subPath, AcDbIntArray& gsMarkers) const;

	virtual AcDbEntity* subSubentPtr(const AcDbFullSubentPath& id) const;

	virtual Acad::ErrorStatus subGetGripPointsAtSubentPath(const AcDbFullSubentPath& path, AcDbGripDataPtrArray& grips, const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir, const int bitflags) const;

	virtual Acad::ErrorStatus subMoveGripPointsAtSubentPaths(const AcDbFullSubentPathArray& paths, const AcDbVoidPtrArray& gripAppData, const AcGeVector3d& offset, const int bitflags);

	virtual Acad::ErrorStatus subTransformSubentPathsBy(const AcDbFullSubentPathArray& paths, const AcGeMatrix3d& xform);

	// ------------------------------------------------------------------------------------------------------------------------

	virtual Acad::ErrorStatus subGetOsnapPoints(AcDb::OsnapMode osnapMode, int gsSelectionMark, const AcGePoint3d& pickPoint, const AcGePoint3d& lastPoint, const AcGeMatrix3d& viewXform, AcGePoint3dArray& snapPoints, AcDbIntArray& geomIds) const;

	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType, AcGePoint3dArray& points, int thisGsMarker = 0, int otherGsMarker = 0) const;
	virtual Acad::ErrorStatus subIntersectWith(const AcDbEntity* pEnt, AcDb::Intersect intType, const AcGePlane& projPlane, AcGePoint3dArray& points, int thisGsMarker = 0, int otherGsMarker = 0) const;

	virtual Acad::ErrorStatus subGetGripPoints(AcGePoint3dArray& gripPoints, AcDbIntArray& osnapModes, AcDbIntArray& geomIds) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbIntArray& indices, const AcGeVector3d& offset);

	virtual Acad::ErrorStatus subGetGripPoints(AcDbGripDataPtrArray& grips, const double curViewUnitSize, const int gripSize, const AcGeVector3d& curViewDir, const int bitflags) const;
	virtual Acad::ErrorStatus subMoveGripPointsAt(const AcDbVoidPtrArray& gripAppData, const AcGeVector3d& offset, const int bitflags);
	virtual void subGripStatus(const AcDb::GripStat status);

	virtual Acad::ErrorStatus subTransformBy(const AcGeMatrix3d& xform);

	virtual bool SupportsBaseCurveCommands() const { return true; };

	virtual const AcDbCurve* GetBaseCurve() const { return m_pBaseCurve; };

	virtual AcGePoint3d BlockOrigin() const { assertReadEnabled(); return (m_startPnt + m_endPnt.asVector()) / 2; };

	virtual bool IsViewportDraw() const { return true; };
private:
	enum PartialUndoOpCode
	{
		kNoOperation = 0,
		kSetDiameter = 1,
		kSetStuffId = 2,
	};

	static void GripViewportDraw(AcDbGripData* pThis, AcGiViewportDraw* pWd, const AcDbObjectId& entId, AcDbGripOperations::DrawType type, AcGePoint3d* imageGripPoint, int gripSize);

	static void HoverDimension(AcDbGripData* pGrip, const AcDbObjectId& objId, double dimScale, AcDbDimDataPtrArray& dimDataArr);

	static void HotGripDimension(AcDbGripData* pGrip, const AcDbObjectId& objId, double dimScale, AcDbDimDataPtrArray& dimDataArr);

	static void GripDimension(AcDbGripData* pGrip, const AcDbObjectId& objId, double dimScale, AcDbDimDataPtrArray& dimDataArr, bool isHover);

	static AcGeVector3d SetDimValueFunc(AcDbDimData* pThis, AcDbEntity* pEnt, double value, const AcGeVector3d& offset);

	AcGePoint3d m_startPnt;
	AcGePoint3d m_endPnt;
	double m_diameter;				// pipe diameter
	Adesk::Int16 m_nStuffId;		// pipe stuff

	AcGeVector3d m_diaDimOffset;

	AcDbPolyline* m_pBaseCurve;

	mutable AcArray<CMyAppData*> m_appDataArr;

};