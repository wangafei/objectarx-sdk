#ifndef _GmModeler_Interface_INCLUDED_
#define _GmModeler_Interface_INCLUDED_

#include "GmCommon.h"
#include "ModelerGeometry.h"

//#include "Wr/wrTriangulationParams.h"
//#include "Br/BrBrep.h"

#if defined(_MSC_VER)
#pragma warning ( disable : 4100 ) //   unreferenced formal parameter
#endif

class OdBrepRenderer;
class OdDbRevolveOptions;
class OdDbSweepOptions;
class OdDbLoftOptions;


// 支持读写，但不支持render
class GmModelerGeometryBase : public OdModelerGeometry
{
//	ACIS::File     *m_pAcisData;

protected:
	GmModelerGeometryBase();
	virtual ~GmModelerGeometryBase();

	static bool facetRes2NormalTol(double dFacetRes, double &dNormalTol);

	virtual void clearCache()
	{
		if (isCachingEnabled())
		{
			disableCaching(true);
			enableCaching();
		}
	}

public:
	ODRX_DECLARE_MEMBERS(GmModelerGeometryBase);

//	virtual bool isEmpty() const { return m_pAcisData == 0; }

	virtual bool setFACETRES(double /*dFacetRes*/) { return false; }

	virtual OdResult in(OdStreamBuf* pStreamIn, AfTypeVer *typeVer, bool bStandardSaveFlag);

	virtual OdResult out(OdStreamBuf* pStreamOut, AfTypeVer typeVer, bool bStandardSaveFlag) const;

	virtual bool brep(OdBrBrep& brep) const;

	///
	virtual void enableCaching() {}

	virtual void disableCaching(bool) {}

	virtual bool isCachingEnabled() const { return false; }
	///

	virtual bool worldDraw(OdGiCommonDraw* /*pWd*/, OdUInt32 /*geomType*/, const OdModelerGeometry::NumIsolines *, OdCmColor* pEntColor = NULL) { return true; }

	virtual bool drawSilhouettes(OdGiViewportDraw* /*pVd*/) { return false; }

	virtual bool explode(OdDbEntityPtrArray& entitySet) const;

	virtual bool getTransformation(OdGeMatrix3d& m);

	virtual void transformBy(const OdGeMatrix3d& xform);

	virtual void createBox(double xLen, double yLen, double zLen);

	virtual void createFrustum(double height, double xRadius, double yRadius, double topXRadius);

	virtual void createSphere(double radius);

	virtual void createTorus(double majorRadius, double minorRadius);

	virtual void createWedge(double xLen, double yLen, double zLen);

	virtual OdResult revolve(const OdDbRegion* region, const OdGePoint3d& axisPoint, const OdGeVector3d& axisDir, double angleOfRevolution, bool isSolid = true);

	virtual OdResult extrude(const OdDbRegion* region, double height, double taper, bool isSolid = true);

//	static void ApplyAdeskColor(ACIS::File *pAcisData, const OdCmColor &color, bool Apply);

//	static void ApplyMaterial(ACIS::File *pAcisData, OdDbObjectId matId, bool Apply);

//	static void ApplyMaterialMapper(ACIS::File *pAcisData, OdGeMatrix3d &mx, OdUInt8 &projection, OdUInt8 &tiling,
//		OdUInt8 &autoTransform, bool Apply);

//	static void SetStAttribColor(ACIS::File *pCurFile, OdDbEntityPtr pEntity);

	virtual void ClearColorAttributes();

	virtual void ClearMaterialAttributes();

	virtual void ClearMaterialMapperAttributes();

	virtual bool hasTrueColorAttributes() const;

  virtual bool hasColorAttributes() const;

	virtual OdResult getPlane(OdGePlane& regionPlane) const;

	virtual bool setMMPerUnit(double dVal);

	virtual bool getMMPerUnit(double &dVal) const;

	virtual geomType bodyType() const;

	virtual solidGeomType solidType() const;

	virtual OdResult booleanOper(OdDb::BoolOperType operation, OdSmartPtr<OdModelerGeometry> otherRegion, const OdCmColor & thisEntColor, const OdCmColor& otherEntColor, bool bHistoryEnabled)
	{
		return eNotImplemented;
	}
  
	virtual OdResult booleanOper(OdDb::BoolOperType operation, const OdSmartPtr<OdModelerGeometry> pModelerPar, OdDbEntityPtrArray& intersectionEntities, const OdCmColor & thisEntColor, const OdCmColor& otherEntColor, bool bHistoryEnabled)
	{
		return eNotImplemented;
	}

	virtual OdResult getArea(double& regionArea) const;

	virtual OdResult getPerimeter(double&) const;

	virtual OdResult getAreaProp(const OdGePoint3d& origin, const OdGeVector3d& xAxis,
		const OdGeVector3d& yAxis, double& perimeter,
		double& area, OdGePoint2d& centroid,
		double momInertia[2], double& prodInertia,
		double prinMoments[2], OdGeVector2d prinAxes[2],
		double radiiGyration[2], OdGePoint2d& extentsLow,
		OdGePoint2d& extentsHigh) const;

	virtual OdResult clear();

	virtual OdResult extrudeAlongPath(const OdDbRegion* region, const OdDbCurve* path, double taperAngle = 0.0, bool isSolid = true);
	virtual OdResult imprintEntity(const OdDbEntity *pEntity);

	virtual OdResult checkInterference(const OdDb3dSolid* otherSolid,
		OdBool createNewSolid,
		OdBool& solidsInterfere,
		OdDb3dSolidPtr &commonVolumeSolid)
		const 
	{
		return eNotImplemented;
	}

	virtual OdResult getMassProp(double& volume,
		OdGePoint3d& centroid,
		double momInertia[3],
		double prodInertia[3],
		double prinMoments[3],
		OdGeVector3d prinAxes[3],
		double radiiGyration[3],
		OdGeExtents3d& extents) const 
	{
		return eNotImplemented;
	}

	virtual OdResult getSection(const OdGePlane& plane, OdDbRegionPtr &sectionRegion, OdDbEntityPtrArray* pSectionCurves = NULL) const
	{
		return eNotImplemented;
	}
	virtual OdResult getSectionByProject(const OdGePlane& plane, OdDbEntityPtrArray& sectionPrjCurves) const
	{
		return eNotImplemented;
	}

	virtual OdResult getSlice(const OdGePlane& plane, bool bGetNegHalfToo, OdDb3dSolid* &pNegHalfSolid)
	{
		return eNotImplemented;
	}
	virtual OdResult getSlice(OdDbSurface* pSurface, bool bGetNegHalfToo, OdDb3dSolid* &pNegHalfSolid)
	{
		return eNotImplemented;
	}

	///
	virtual OdResult sliceByPlane(const OdGePlane& slicePlane, OdDbSurfacePtr& pNegHalfSurface, OdDbSurfacePtr& pNewSurface, bool bNotModifyItself)
	{
		return eNotImplemented;
	}
	virtual OdResult sliceBySurface(const OdDbSurfacePtr pSlicingSurface, OdDbSurfacePtr& pNegHalfSurface, OdDbSurfacePtr& pNewSurface, bool bNotModifyItself)
	{
		return eNotImplemented;
	}
	virtual OdResult getPlaneSliceFaceId(int &faceId, OdGeIntArray &edgeIt)
	{
		return eNotImplemented;
	}
	///

	virtual OdResult cleanBody() { return eNotImplemented; }
	virtual OdResult offsetBody(double offsetDistance) { return eNotImplemented; }

	virtual OdResult separateBody(OdArray<OdDb3dSolid *> &newSolids);

	virtual OdResult createExtrudedObject(OdDbEntity* pSweepEnt,
		const OdGeVector3d& directionVec,
		OdDbSweepOptions& sweepOptions,
		bool isSolid = true,
		bool bHistoryEnabled = false)
	{
		return eNotImplemented;
	}

	virtual OdResult createLoftedObject(
		OdDbEntityPtrArray& crossSectionCurves,
		OdDbEntityPtrArray& guideCurves,
		OdDbEntity* pPathCurve,
		OdDbLoftOptions& /*loftOptions*/,
		bool isSolid = true) 
	{
		return eNotImplemented;
	}

	virtual OdResult createBlendObject(
		OdDbEntityPtrArray& blendedEdges,
		OdDbBlendOptions& loftOptions,
		bool isSolid = true)
	{
		return eNotImplemented;
	}

	virtual OdResult createPyramid(double height, int sides,
		double radius, double topRadius = 0.0) 
	{
		return eNotImplemented;
	}

	virtual OdResult createRevolvedObject(OdDbEntity* pRevEnt,
		OdGePoint3d& axisPnt,
		const OdGeVector3d& axisDir,
		double revAngle, double startAngle,
		OdDbRevolveOptions& revolveOptions,
		bool isSolid = true,
		bool bHistoryEnabled = false)
	{
		return eNotImplemented;
	}

	virtual OdResult createSweptObject(OdDbEntity* pSweepEnt,
		OdDbEntity* pPathEnt,
		OdDbSweepOptions& sweepOptions,
		bool isSolid = true,
		bool bHistoryEnabled = false)
	{
		return eNotImplemented;
	}

	// Loft options utility functions
	virtual OdResult checkCrossSectionCurves(
    OdArray<OdDbEntity*>& crossSectionCurves,
		bool& allOpen, bool& allClosed, bool& allPlanar,
		bool displayErrorMessages = false) 
	{
		return eNotImplemented;
	}

	virtual OdResult checkGuideCurves(OdArray<OdDbEntity*>& guideCurves, bool displayErrorMessages = false)
	{
		return eNotImplemented;
	}

	virtual OdResult checkPathCurve(OdDbEntity *pPathCurve, bool displayErrorMessages = false)
	{
		return eNotImplemented;
	}

	// Sweep options utility functions
	virtual OdResult checkSweepCurve(OdDbEntity *pSweepEnt,
		OdDb::Planarity& planarity, OdGePoint3d& pnt, OdGeVector3d& vec,
		bool& closed, double& approxArcLen, bool displayErrorMessages = false)
	{
		return eNotImplemented;
	}

	virtual OdResult checkSweepPathCurve(OdDbEntity *pPathEnt, bool displayErrorMessages = false)
	{
		return eNotImplemented;
	}

	// Revolve options utility functions
	virtual OdResult checkRevolveCurve(
		OdDbEntity* pRevEnt,
		const OdGePoint3d& axisPnt,
		const OdGeVector3d& axisDir,
		bool& closed,
		bool& endPointsOnAxis,
		bool& planar,
		bool displayErrorMessages = false) 
	{
		return eNotImplemented;
	}

	virtual OdResult createFrom(const OdDbEntity* pFromEntity) { return eNotImplemented; }
	virtual OdResult convertToRegion(OdDbEntityPtrArray& regions) { return eNotImplemented; }
	virtual OdResult thicken(double thickness, bool bBothSides, OdDb3dSolid*& pSolid) const { return eNotImplemented; }

	virtual OdResult intersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
		OdGePoint3dArray& points, OdGsMarker thisGsMarker, OdGsMarker otherGsMarker) const
	{
		return eNotImplemented;
	}

	virtual OdResult intersectWith(const OdDbEntity* ent, OdDb::Intersect intType,
		const OdGePlane& projPlane, OdGePoint3dArray& points,
		OdGsMarker thisGsMarker, OdGsMarker otherGsMarker) const 
	{
		return eNotImplemented;
	}

	virtual OdResult copySubEntity(const OdDbSubentId &subentId, OdDbEntityPtr &newEntity) const;
	virtual OdResult taperFaces(const OdArray<OdDbSubentId *> &faceSubentIds, const OdGePoint3d &basePoint,
		const OdGeVector3d &draftVector, double draftAngle) 
	{
		return eNotImplemented;
	}
	virtual OdResult removeFaces(const OdArray<OdDbSubentId *> &faceSubentIds) { return eNotImplemented; }
	virtual OdResult offsetFaces(const OdArray<OdDbSubentId *> &faceSubentIds, double offsetDistance) { return eNotImplemented; }
	virtual OdResult shellBody(const OdArray<OdDbSubentId *> &faceSubentIds, double offsetDistance) { return eNotImplemented; }
	virtual OdResult transformFaces(const OdArray<OdDbSubentId *> &faceSubentIds, const OdGeMatrix3d &matrix) { return eNotImplemented; }

	virtual OdResult getSubentPathsAtGsMarker(OdDb::SubentType type,
		OdGsMarker gsMark,
		const OdGePoint3d& pickPoint,
		const OdGeMatrix3d& viewXform,
		OdDbFullSubentPathArray& subentPaths,
		OdDbObjectIdArray* pEntAndInsertStack = 0) const;

	virtual OdResult getGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath,
		OdGsMarkerArray& gsMarkers) const;

	virtual OdDbSubentId internalSubentId(void* ent) const;
	virtual void* internalSubentPtr(const OdDbSubentId& id) const;

	virtual bool getNurbCurvesCache(OdGeCurve3dPtrArray &) const;

	virtual OdResult setSubentColor(const OdDbSubentId &subentId, const OdCmColor &color);
	virtual OdResult getSubentColor(const OdDbSubentId &subentId, OdCmColor &color) const;
	virtual OdResult setSubentMaterial(const OdDbSubentId &subentId, OdDbObjectId matId);
	virtual OdResult getSubentMaterial(const OdDbSubentId &subentId, OdUInt64& matId) const;
	virtual OdResult setSubentMaterialMapper(const OdDbSubentId &subentId,
		OdGeMatrix3d &mx,
		OdUInt8 &projection,
		OdUInt8 &tiling,
		OdUInt8 &autoTransform);
	virtual OdResult getSubentMaterialMapper(const OdDbSubentId &subentId,
		OdGeMatrix3d &mx,
		OdUInt8 &projection,
		OdUInt8 &tiling,
		OdUInt8 &autoTransform) const;

	virtual OdResult chamferEdges(const OdArray<OdDbSubentId *> &edgeSubentIds,
		const OdDbSubentId& baseFaceSubentId,
		double baseDist,
		double otherDist);

	virtual OdResult filletEdges(const OdArray<OdDbSubentId *> &edgeSubentIds,
		const OdGeDoubleArray& radius,
		const OdGeDoubleArray& startSetback,
		const OdGeDoubleArray& endSetback);

	virtual OdResult createSectionObjects(const OdGePlane& sectionPlane, OdDbEntityPtrArray& sectionObjects) const
	{
		return eNotImplemented;
	}

	virtual OdResult createInterferenceObjects(OdDbEntityPtrArray& interferenceObjects,
		OdDbEntityPtr pEntity,
		unsigned int flags) const
	{
		return eNotImplemented;
	}

	virtual OdResult extrudeFaces(const OdArray<OdDbSubentId *> &faceSubentIds, double height, double taper)
	{
		return eNotImplemented;
	}

	virtual OdResult extrudeFacesAlongPath(const OdArray<OdDbSubentId *> &faceSubentIds, const OdDbCurve* path)
	{
		return eNotImplemented;
	}

	virtual OdResult ChangeFacesDoubleSidedParam(bool isDoubleSided);

	virtual OdResult convertToNurbSurface(OdDbNurbSurfaceArray& nurbSurfaceArray) 
	{
		return eNotImplemented;
	}

	virtual OdResult get(int& iUDegree, int& iVDegree, bool& bRational, int& iUNumControlPoints, int& iVNumControlPoints,
		OdGePoint3dArray& ctrlPtsArr, OdGeDoubleArray& weights,
		OdGeKnotVector& uKnots, OdGeKnotVector& vKnots) const;

	virtual OdResult set(int iUDegree, int iVDegree, bool bRational, int iUNumControlPoints, int iVNumControlPoints,
		const OdGePoint3dArray& ctrlPtsArr, const OdGeDoubleArray& weights,
		const OdGeKnotVector& uKnots, const OdGeKnotVector& vKnots) 
	{
		return eNotImplemented;
	}

	virtual OdResult getNumberOfControlPointsInU(int& iCount) const;
	virtual OdResult getNumberOfControlPointsInV(int& iCount) const;

	virtual OdResult getNumberOfKnotsInU(int& iCount) const;
	virtual OdResult getNumberOfKnotsInV(int& iCount) const;

	virtual OdResult getUKnots(OdGeKnotVector& knots) const;
	virtual OdResult getVKnots(OdGeKnotVector& knots) const;

	virtual OdResult getDegreeInU(int& iDegree) const;
	virtual OdResult getDegreeInV(int& iDegree) const;

	virtual OdResult isClosedInU(bool& bIsClosed) const;
	virtual OdResult isClosedInV(bool& bIsClosed) const;

	virtual OdResult isPeriodicInU(bool& bIsPeriodic) const;
	virtual OdResult isPeriodicInV(bool& bIsPeriodic) const;

	virtual OdResult getPeriodInU(double& dPeriod) const;
	virtual OdResult getPeriodInV(double& dPeriod) const;

	virtual OdResult evaluate(double dU, double dV, OdGePoint3d& pos) const
	{
		return eNotImplemented;
	}
	virtual OdResult evaluate(double dU, double dV, OdGePoint3d& pos, 
		OdGeVector3d& uDeriv, OdGeVector3d& vDeriv) const 
	{
		return eNotImplemented; 
	}
	virtual OdResult evaluate(double dU, double dV, OdGePoint3d& pos,
		OdGeVector3d& uDeriv, OdGeVector3d& vDeriv,
		OdGeVector3d& uuDeriv, OdGeVector3d& uvDeriv, OdGeVector3d& vvDeriv) const 
	{
		return eNotImplemented;
	}
	virtual OdResult evaluate(double dU, double dV, int iDerivDegree, OdGePoint3d& point, OdGeVector3dArray& derivatives) const 
	{
		return eNotImplemented;
	}

	virtual OdResult isRational(bool& bIsRational) const;

	virtual OdResult isPlanar(bool& bIsPlanar, OdGePoint3d& ptOnSurface, OdGeVector3d& normal) const
	{
		return eNotImplemented; 
	}

	virtual OdResult isPointOnSurface(const OdGePoint3d& point, bool& bOnSurface) const
	{
		return eNotImplemented; 
	}

	virtual OdResult getNormal(double dU, double dV, OdGeVector3d& normal) const
	{
		return eNotImplemented; 
	}

	virtual OdResult getNumberOfSpansInU(int& iSpan) const
	{
		return eNotImplemented;
	}
	virtual OdResult getNumberOfSpansInV(int& iSpan) const
	{
		return eNotImplemented;
	}

	virtual OdResult getIsolineAtU(double dNumberSegments, OdDbCurvePtrArray& lineSegments) const
	{
		return eNotImplemented;
	}
	virtual OdResult getIsolineAtV(double dNumberSegments, OdDbCurvePtrArray& lineSegments) const
	{
		return eNotImplemented;
	}

	virtual OdResult InsertKnot(double dVal, int iUorV) 
	{
		return eNotImplemented; 
	}

	virtual OdResult InsertControlPointsAtU(double dVal, const OdGePoint3dArray& vCtrlPts, const OdGeDoubleArray& vWeights)
	{
		return eNotImplemented;
	}
	virtual OdResult InsertControlPointsAtV(double dVal, const OdGePoint3dArray& vCtrlPts, const OdGeDoubleArray& vWeights)
	{
		return eNotImplemented; 
	}

	virtual OdResult RemoveControlPointsAtU(int iIndex)
	{
		return eNotImplemented;
	}
	virtual OdResult RemoveControlPointsAtV(int iIndex)
	{
		return eNotImplemented;
	}

	virtual OdResult rebuild(int iUDegree, int iVDegree, int iNumUCtrlPts, int iNumVCtrlPts, bool bRestore)
	{
		return eNotImplemented; 
	}

	virtual OdResult modifyPositionAndTangent(double dU, double dV, const OdGePoint3d& point, const OdGeVector3d* uDeriv, const OdGeVector3d* vDeriv)
	{
		return eNotImplemented;
	}

	virtual OdResult getParameterOfPoint(const OdGePoint3d& point, double& dU, double& dV) const
	{
		return eNotImplemented;
	}

	virtual OdResult getControlPoints(int& iUCount, int& iVCount, OdGePoint3dArray& points) const;

	virtual OdResult setControlPoints(int iUCount, int iVCount, const OdGePoint3dArray& points)
	{
		return eNotImplemented;
	}

	virtual OdResult getControlPointAndWeight(int iUIndex, int iVIndex, OdGePoint3d& point, double& weight, bool& bIsRational) const;

	virtual OdResult setControlPointAndWeight(int iUIndex, int iVIndex, const OdGePoint3d& point, double weight)
	{
		return eNotImplemented;
	}

	virtual OdResult generateSectionGeometry(
		const OdDbSection*      pSection,
		OdDbEntityPtrArray&     sourceEntArr,
		OdArray<OdDbEntityPtr>& intBoundaryEnts,
		OdArray<OdDbEntityPtr>& intFillEnts,
		OdArray<OdDbEntityPtr>& backgroundEnts,
		OdArray<OdDbEntityPtr>& foregroundEnts,
		OdArray<OdDbEntityPtr>& curveTangencyEnts,
		bool                    bIsSetProperties) 
	{
		return eNotImplemented;
	}

	virtual OdResult setSubentPath(OdBrEntity& pInpEnt, OdDbFullSubentPath& subpath);

	virtual OdResult setColorToSubents(OdCmColor const& color);

	virtual OdResult setMaterialToSubents(OdDbObjectId materialId);

	virtual OdResult setMaterialMapperToSubents(OdGeMatrix3d &mx, OdUInt8 &projection,
		OdUInt8 &tiling, OdUInt8 &autoTransform);

	virtual OdResult trimSurface(const OdDbObjectIdArray& toolIds,
		const OdDbObjectIdArray& toolCurveIds,
		const OdGeVector3dArray& projVectors,
		const OdGePoint3d&       pickPoint,
		const OdGeVector3d&      viewVector,
		bool                     bAutoExtend,
		bool                     bAssociativeEnabled) 
	{
		return eNotImplemented;
	}

	virtual OdResult projectOnToEntity(const OdDbEntity*   pEntityToProject,
		const OdGeVector3d& projectionDirection,
    OdArray<OdDbEntity*>& projectedEntities) const
	{
		return eNotImplemented;
	}

	virtual OdResult createSculptedSolid(const OdArray<OdDbEntity*>& limitingBodies, const OdGeIntArray& limitingFlags)
	{
		return eNotImplemented;
	}

	virtual OdResult selectFaces(int selType, const OdGePoint3dArray &selPnts, const OdGeVector3d &viewDir,
		OdArray<OdDbSubentId *>& faceSet, OdUInt32 flags = 0, const OdGeTol &tol = OdGeTol(1.0e-6));

	virtual OdResult rayTest(
		const OdGePoint3d&      rayBasePoint,
		const OdGeVector3d&     rayDir,
		double                  rayRadius,
		OdArray<OdDbSubentId> & subEntIds,
		OdGeDoubleArray&        parameters) const 
	{
		return eNotImplemented;
	}

	virtual OdResult createFilletSurface(OdDbSurfacePtr&      surf1,
		const OdGePoint3d&   pickPt1,
		OdDbSurfacePtr&      surf2,
		const OdGePoint3d&   pickPt2,
		double               dRadius,
		OdDb::FilletTrimMode trimMode,
		const OdGeVector3d&  projDir) 
	{
		return eNotImplemented;
	}

	virtual OdResult extendEdges(OdDbFullSubentPathArray& edgesId,
		double                   dExtDist,
    OdDbSurface::EdgeExtensionType        extOption)
	{
		return eNotImplemented;
	}

	virtual OdResult getObjectMesh(const OdDbFaceterSettings *faceter,
		OdGePoint3dArray& vertexArray,
		OdInt32Array& faceArray,
		OdGiFaceData*& faceData)
	{
		return eNotImplemented;
	}

	virtual OdResult getBoundingBox(OdGeExtents3d &box) 
	{
		return eNotImplemented;
	}

	// for internal use only
  virtual OdResult generateSectionGeometry(SectArgs& sectArgs, OdDbEntity *pEnt, bool* bHasForeground) 
  {
    return eNotImplemented;
  }

  virtual OdResult convertTo(const OdGePoint3dArray &arrVertexes, const OdInt32Array &arrEdges, const OdInt32Array &arrFaces, OdGiFaceData &fd,
    OdInt32Array &arrFacesColors, OdInt32Array &arrFacesMaterials, OdDbEntity* pEntity)
  {
    return eNotImplemented;
  }

  virtual OdResult setMaterialResolver(const OdMaterialResolver *pResolver)
  {
    return eNotImplemented;
  }
};

typedef OdSmartPtr<GmModelerGeometryBase> GmModelerGeometryBasePtr;

#endif
