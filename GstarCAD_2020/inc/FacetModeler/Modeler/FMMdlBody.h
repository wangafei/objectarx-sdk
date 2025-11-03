/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2015, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2002-2015 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef __FMMDL_BODY_H__
#define __FMMDL_BODY_H__

#include "../FacetModeler/Modeler/FMMdlBase.h"
#include "../FacetModeler/FMContour3D.h"
#include "../FacetModeler/FMProfile3D.h"
#include "../FacetModeler/Modeler/FMMdlMorphmap.h"
#include "../FacetModeler/Modeler/FMMdlPoint3d.h"
#include "../FacetModeler/Modeler/FMMdlInterval.h"

class OdGeCircArc3d;

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

  class VertexSurfData;
  class Surface;
  typedef OdArray<const Face*, OdMemoryAllocator<const Face*> > FaceConstPtrArray;

  enum Color {
    kColor1 = 1,
    kColor2 = 2,
    kColor3 = 3,
    kColor4 = 4,    // Feel free to invent more colors
    kColorInvisible = -1
  };


  FMGEOMETRY_API extern Color gDefaultColor;

  inline Color defaultColor() { return gDefaultColor; }
  inline void  setDefaultColor(Color co) { gDefaultColor = co; }

  /** \details
     Facet body.
  */
  class FMGEOMETRY_API Body
  {
  public:
    /** \details
       Constructor.
    */
    Body(class BodyImpl* pImpl);

    /** \details
       Constructor.
    */
    Body();

    /** \details
       Copy constructor.

       \remarks
       Ddoesn't create copy of the body - it only copy references.
    */
    Body(const Body& B);

    /** \details
       Destructor.
    */
    ~Body();

    /** \details
       Assignment operator.

       \remarks
       Doesn't create copy of the body - it only copies impl pointer.
    */
    Body& operator = (const Body& B);

    void init(bool deleteContents);

    void setColor(Color clr);

    /** \details
       Clears body.
    */
    void clear();

    /** \details
       Returns copy of the body.
    */
    Body clone() const;

    Body copy() const;

    Body& translate(const Vector3d&);

    Body& rotate(const Line3d& axis, double angle);

    Body& scale(const Point3d& fixedPt, double factor);

    // Scales in the directions of x, y and z axis by the scale factor 
    // xyzFactors.x, xyzFactors.y and xyzFactors.z, respectively
    //
    Body& scale(const Point3d& fixedPt, const Vector3d& xyzFactors);

    // Scales (stretches) the body in the given direction. The axis.point is 
    // the fixed point, the axis.vector is the direction of the stretch. The 
    // length of the axis.vector defines the scale factor
    //
    Body& stretch(const Line3d& axis);

    /** \details
       Transforms body.
    */
    void transform(const OdGeMatrix3d& mMatrix);

    /** \details
       Inverts body.
    */
    void negate();

    /** \details
       Returns whether the body is empty.
    */
    bool isNull() const;

    /** \details
       Returns whether the body is negated.
    */
    bool isNegated() const;

    /** \details
       Returns whether the body is valid.
    */
    bool isValid(int nCheckingLevel = -1) const;

    /** \details
       Returns whether the body is closed (any face is connected to other one at any adge).
    */
    bool isClosed() const;

    /** \details
       Merges coincident vertices.
    */
    bool mergeCoincidentVertices();

    /** \details
       Merges coplanar faces and collinear edges.
    */
    void mergeCoplanarEntities();

    /** \details
    */
    bool containsNonManifoldEdges() const;

    /** \details
    */
    void decomposeIntoLumps(std::vector<Body>& aLumps);

    /** \details
       Combines this body and operand into single body.
       \remarks
       Clears this body and operand.
    */
    Body combine(Body& rAnother);

    /** \details
       Returns vertex count.
    */
    OdUInt32 vertexCount() const;

    FacetModeler::Vertex* addVertex(const OdGePoint3d& pt);

    /** \details
       Counts and returns number of edges.
    */
    int      edgeCount() const;
    //OdUInt32 countEdges() const;

    /** \details
       Returns cached edge count (that was calculated in most recent countEdges() call ).
    */
    OdUInt32 cachedEdgesCount() const;

    /** \details
       Returns face count.
    */
    OdUInt32 faceCount() const;

    FacetModeler::Face* addFace(Surface* pSurface = 0);

    /** \details
       Returns surface count.
    */
    OdUInt32 surfaceCount() const;

    void addSurface(Surface* pSurface);

    /** \details
       Returns face list.
    */
    FacetModeler::Face* faceList() const;

    /** \details
       Returns vertex list.
    */
    FacetModeler::Vertex* vertexList() const;

    /** \details
       Returns surface list.
    */
    Surface* surfaceList() const;

    void     setFaceList      (Face*    f);
    void     setCurveList     (Curve*   c);

    /** \details
       Clears vertex tags.
    */
    void clearVertexTags(FacetModeler::AecTagType clearValue = 0);

    /** \details
       Clears body tags.
    */
    void clearSurfaceTags(FacetModeler::AecTagType clearValue = 0);

    /** \details
       Clears edge tags.
    */
    void clearEdgeTags(FacetModeler::AecTagType clearValue = 0);

    /** \details
       Clears face tags.
    */
    void clearFaceTags(FacetModeler::AecTagType clearValue = 0);

    /** \details
       Clears body tags.
    */
    void clearBodyTags(FacetModeler::AecTagType clearValue = 0) { setTag(clearValue); }

    /** \details
       Returns tag 1.
    */
    FacetModeler::AecTagType tag() const;

    /** \details
       Sets tag 1.
    */
    void setTag(FacetModeler::AecTagType iTag);

    /** \details
       Deletes unused vertices from body.
    */
    void deleteUnusedVertices();

    /** \details
       Returns extents.
    */
    OdGeExtents3d intervalODA() const;

    const Interval3d& interval(double enlargeBy = 10 * epsAbs()) const;

    /** \details
       Returns volume.
    */
    double volume() const;

    /** \details
       Returns slice profile.
    */
    void slice(const OdGePlane& rCutter,
      Profile3D& rResult, bool bIncludeBoundary = true) const;

    void sliceFaceDbg(const OdGePlane& rCutter, OdUInt32 faceNum);

    /** \details
       Returns slice profile.
    */
    void slice(const OdGePlane& rCutter,
      Profile2D* pResultIncludingBoundary,
      Profile2D* pResultExcludingCoincidingBoundary = 0,
      Profile2D* pResultExcludingOppositeBoundary = 0,
      Profile2D* pResultExcludingBoundary = 0,
      FaceConstPtrArray* pCoincidingFaces = 0,
      FaceConstPtrArray* pOppositeFaces = 0
    ) const;

    /** \details
       Returns slice along specified cut line profile.
    */
    void slice(const Contour2D& cCutLine, const OdGePlane& pProjectOn,
      Profile3D& rResult, bool bIncludeBoundary = true) const;

    bool slice(const Plane&, std::vector<Point3d>& outputVertices, std::vector<int>& outputLoops) const;

    void section(const Plane& plane, bool keepInputBodyWhenFails = keepInputBodiesWhenBooleanOperationsFail());

    void section(const Plane& plane, const Point3d& point, bool keepInputBodyWhenFails = keepInputBodiesWhenBooleanOperationsFail());

    /** \details
       Intersects this Body with the given line.
       Returns true, if there are intersections.
       There can be multiple equal intersections.
    */
    bool intersectLine(const OdGeLinearEnt3d& gLine, std::vector< OdGePoint3d >& vecPoints, bool bSortResults = false) const;

    bool operator == (const Body& aBody) const;
    bool operator != (const Body& aBody) const;


    Body  operator + (const Body&);
    Body  operator - (const Body&);
    Body  operator * (const Body&);
    Body  operator - (const Plane&);

    Body& operator +=(const Body&);
    Body& operator -=(const Body&);
    Body& operator *=(const Body&);
    Body& operator -=(const Plane&);

    FMGEOMETRY_API_STATIC static const Body kEmpty;

    static Body box(const Point3d&  corner,
      const Vector3d& sizes);

    static Body sphere(const Point3d&  center,
      double          radius,
      int             approx);

    static Body cylinder(const Line3d&   axis,
      double          radius,
      int             approx);

    static Body cylinder(const Line3d&   axis,
      const Vector3d& baseNormal,
      double          radius,
      int             approx);

    static Body cone(const Line3d&   axis,
      double          radius1,
      double          radius2,
      int             approx);

    static Body cone(const Line3d&   axis,
      const Vector3d& baseNormal,
      double          radius1,
      double          radius2,
      int             approx);

    enum torus_type { DONUT_TORUS, APPLE_TORUS, LEMON_TORUS, VORTEX_TORUS };

    static Body torus_extension(
      const Line3d&   axis,
      double          majorRadius,
      double          minorRadius,
      int             majorApprox,
      int             minorApprox);

    static Body torus(const Line3d&   axis,
      double          majorRadius,
      double          minorRadius,
      int             majorApprox,
      int             minorApprox);

    static Body pipe(const Line3d&   axis,
      double          outerRadius,
      double          innerRadius,
      int             approx);

    static Body pipe(const Line3d&   axis,
      const Vector3d& baseNormal,
      double          outerRadius,
      double          innerRadius,
      int             approx);

    static Body pipeConic(const Line3d&   axis,
      double          outerRadius1,
      double          innerRadius1,
      double          outerRadius2,
      double          innerRadius2,
      int             approx);

    static Body pipeConic(const Line3d&   axis,
      const Vector3d& baseNormal,
      double          outerRadius1,
      double          innerRadius1,
      double          outerRadius2,
      double          innerRadius2,
      int             approx);

    static Body tetrahedron(const Point3d&  p1,
      const Point3d&  p2,
      const Point3d&  p3,
      const Point3d&  p4);

    static Body reducingElbow(const Point3d& elbowCenter,
      const Point3d&  endCenter1,
      const Point3d&  endCenter2,
      double          endRadius1,
      double          endRadius2,
      int             majorApprox,
      int             minorApprox);

    static Body rectangleToCircleReducer
    (const Point3d&  baseCorner,
      const Vector2d& baseSizes,
      const Circle3d& topCircle,
      int             approx);

    static Body convexHull(const Point3d   pts[],
      int             numPoints);

    static Body extrusion(const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      const Vector3d&    extrusionVector,
      const Point3d&     scaleTwistFixedPt,
      double             scaleFactor,
      double             twistAngle = 0.0);

    static Body extrusion(const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      const Vector3d&    extrusionVector);

    static Body extrusion(const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      const Vector3d&    extrusionVector,
      const std::vector<void*>*    attribs);

    static Body pyramid(const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      const Point3d&     pyramidApex);

    // \details
    // Creates a body by revolving profile around the axis defined by the projection of the line
    // from axis.point to axis.point+axis.vector onto the plane containing profile. Therefore, the 
    // rotation axis will always be coplanar with profile. The profile is revolved revolutionAngle
    // radians around the rotation axis. Positive angles result in a clockwise rotation, when
    // looking in the direction of the projection of axisDir onto the plane containing profile (that
    // is, right-hand rule). Angles of revolution more than 2 pi are treated as 2 pi. The rotation
    // axis must not pass through region.
    // 
    // If the rotation axis is not valid for a rotation of profile (for example, axisDir is 
    // perpendicular to the plane of profile, the rotation axis passes through region, and so on),
    // then this function will fail and a NULL body will be returned. 
    // 
    // \param plg               [in] Profile to revolve.
    // \param vertexData        [in] Vertex data of the given polygon.
    // \param numVertices       [in] Vertex count of the given polygon.
    // \param plgNormal         [in] Normal of the given polygon.
    // \param axis              [in] Rotation axis defined by the the line.
    // \param revolutionAngle   [in] Rotation angle in radians around the rotation axis.
    // \param approx            [in] Number of lines to approximate a circle.
    // \param scaleTwistFixedPt [in] Fixed point for scale/twist.
    // \param scaleFactor       [in] Scale factor of revolution
    // \param twistAngle        [in] Twist angle of revolution
    // 
    // \returns
    // Resulting body.
    //
    static Body axisRevolution(
      const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      const Line3d&      axis,
      double             revolutionAngle,
      int                approx,
      const Point3d&     scaleTwistFixedPt,
      double             scaleFactor,
      double             twistAngle = 0.0);

    static Body axisRevolution(
      const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      const Line3d&      axis,
      double             revolutionAngle,
      int                approx);

    static Body endpointRevolution(
      const Point3d      plg[],
      PolygonVertexData* vertexData[],
      int                numVertices,
      const Vector3d&    plgNormal,
      double             revolutionAngle,
      int                approx);

    static Body extrusionAlongPath(
      const Body&             startProfile,
      const Body&             endProfile,
      const Point3d           pathPlg[],
      PolygonVertexData*      pathVertexData[],
      int                     pathNumVertices,
      bool                    pathIsClosed,
      bool                    checkBodyValidity = true,
      const Point3d&          scaleTwistFixedPt = Point3d::kNull,
      double                  scaleFactor = 1.0,
      double                  twistAngle = 0.0,

      const MorphingMap&      morphingMap = MorphingMap::kNull,
      bool                    calcluateMorphingMapAutomatically = false,
      std::vector<int>        startProfileSignificantVertices = std::vector<int>(),
      std::vector<int>        endProfileSignificantVertices = std::vector<int>());

    static Body skin(Body*              profiles[],
      int                numProfiles,
      bool               isClosed,
      bool               checkPlanarity,
      MorphingMap**      morphingMaps = NULL,
      bool               markInnerProfileEdgesAsApprox = false,
      bool               ckeckInputProfiles = true);

    /** \details
       Creates pyramid.

       \param rBase [in]  Base profile.
       \param ptApex [in]  Pyramid apex.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body pyramid(const Profile2D& rBase,
      const OdGePoint3d& ptApex,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Creates extrusion.

       \param rBase [in]  Base profile (in XY plane).
       \param vDir [in]  Extrusion direction.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body extrusion(const Profile2D& rBase,
      const OdGeVector3d& vDir,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Creates extrusion.

       \param rBase [in]  Base profile (in XY plane).
       \param rPath [in]  Extrusion path.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    // static Body extrusion( const Profile2D& rBase,
    //     const Contour3D& rPath,
    //     const DeviationParams& devDeviation = FMGeGbl::gDefDev );

    /** \details
       Creates extrusion.

       \param rBase [in]  Base profile.
       \param rPath [in]  Extrusion path.
       \param vNormal [in]  Z axis for extrusion.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    // static Body extrusion( const Profile2D& rBase,
    //     const std::vector<OdGePoint3d>& rPath,
    //     const OdGeVector3d& vNormal,
    //     const DeviationParams& devDeviation = FMGeGbl::gDefDev );

    /** \details
       Creates revolution.

       \param rBase [in]  Base profile (X - along height, Y - along radius).
       \param dRadius [in]  Radius.
       \param dHeight [in]  Height.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body revolution(const Profile2D& rBase,
      double dRadius, double dHeight,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Creates revolution.

       \param base [in]  Base profile.
       \param axis [in]  Revolution axis.
       \param revolutionAngle [in]  Revolution angle.
       \param deviation [in]  Deviation.
       \param baseTransform [in]  Additional transform to be applied to base profile while being revolved.

       \returns
       Resulting body.
    */
    static Body revolution(
      const Profile2D&        base,
      const OdGeCircArc3d&    revolutionAxisAndAngles,
      const DeviationParams&  deviation = FMGeGbl::gDefDev,
      const OdGeMatrix2d*     pBaseTransform = 0);

    /** \details
       Creates inside body.

       \param rBase [in]  Base profile (in XZ plane).
       \param dDepth [in]  Depth.
       \param dDepthOrigin [in]  Depth origin.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body insideBody(const Profile2D& rBase,
      double dDepth, double dDepthOrigin,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Creates inside frame.

       \param rBase [in]  Base profile (in XZ plane).
       \param dWidth [in]  Width.
       \param dDepth [in]  Depth.
       \param dDepthOrigin [in]  Depth origin.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body insideFrame(const Profile2D& rBase,
      double dWidth, double dDepth, double dDepthOrigin,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Creates single face body.

       \param rBase [in]  Base profile (in XY plane).
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.

       \remarks
       Body will have one face only if specified profile
       has one outer loop.
    */
    static Body singleFace(const Profile2D& rBase,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    struct FMGEOMETRY_API SurfaceData {
      OdArray<Surface*>        surfaces;
      OdArray<Surface*>        face2Surface;
      OdArray<VertexSurfData*> vertexSurfData;

      void addVertexSurfData(int nVertex, Surface* pSurf);
    };

    /** \details
       Creates custom body.

       \param aVertices [in]  Vertex data.
       \param aFaceData [in]  Face data.
       \param aEdgeFlags [in]  Edge flags.
       \param aFaceFlags [in]  Face flags.
       \param aVertexFlags [in]  Vertex flags.

       \returns
       Resulting body.

       \remarks
       Only suitable for good input topology (without t-junctions).
       For bad topology use customRemoveTJ instead.
    */
    static Body custom(const std::vector<OdGePoint3d>& aVertices,
      const std::vector<OdInt32>& aFaceData,
      const std::vector<OdUInt32>* aEdgeFlags = 0,
      const std::vector<OdUInt32>* aFaceFlags = 0,
      const std::vector<OdUInt32>* aVertexFlags = 0,
      const SurfaceData* pSurfaceData = 0
    );

    /** \details
       Creates custom body.

       \param aVertices [in]  Vertex data.
       \param aFaceData [in]  Face data.
       \param aEdgeFlags [in]  Edge flags.
       \param aFaceFlags [in]  Face flags.
       \param aVertexFlags [in]  Vertex flags.
       \param pFaceColors [in]  Colors of the faces.

       \returns
       Resulting body.

       \remarks
       Only suitable for good input topology (without t-junctions).
       For bad topology use customRemoveTJ instead.
    */
    static Body customC(const std::vector<OdGePoint3d>& aVertices,
      const std::vector<OdInt32>& aFaceData,
      const std::vector<OdUInt32>* aEdgeFlags = 0,
      const std::vector<OdUInt32>* aFaceFlags = 0,
      const std::vector<OdUInt32>* aVertexFlags = 0,
      const SurfaceData* pSurfaceData = 0,
      std::vector<OdUInt32>* pFaceColors = 0,
      std::vector<OdUInt32>* pEdgeColors = 0,
      OdUInt32 iUnknown = 0);


    /** \details
       Creates custom body. Removes t-junctions.

       \param aVertices [in]  Vertex data.
       \param aFaceData [in]  Face data.
       \param aEdgeFlags [in]  Edge flags.
       \param aFaceFlags [in]  Face flags.
       \param aVertexFlags [in]  Vertex flags.

       \returns
       Resulting body.
    */
    // static Body customRemoveTJ(const std::vector<OdGePoint3d>& aVertices,
    //   const std::vector<OdInt32>& aFaceData,
    //   std::vector<OdUInt32>* aEdgeFlags = 0,
    //   std::vector<OdUInt32>* aFaceFlags = 0,
    //   std::vector<OdUInt32>* aVertexFlags = 0);

    /** \details
       Creates a new Body from ACAD entity (OdDb3dSolid is supported)

       \param idEntity [in]  original object (OdDb3dSolid).

       \returns
       Resulting body.
    */
    // static Body convertFromEntity( const OdDbObjectId& idEntity );

    /** \details
    Sets faces and edges colors to zero
    */
    void resetColors();

    /** \details
       Performs boolean operation. Destroys both operand.
       
       This function reuse the entities of the input bodies to produce the resulting body and set
       the input bodies to empty bodies.

       \param rOperand [in] Operand Body.
       \param operType [in] Boolean operation type.
       \param hideZeroSlopeEdges [in] Hide zero slope edges.
       \param callbackFun [in] Topology change callback.
       \param keepInputBodiesWhenFails [in] Whether the input bodies are or are not preserved
              when the Boolean operations fail.

       \returns
       Resulting body.
    */
    Body boolOper(
      Body& rOperand,
      BoolOperType operType,
      bool hideZeroSlopeEdges = true,
      TopologyChangeCallback* callbackFun = NULL,
      bool keepInputBodiesWhenFails = keepInputBodiesWhenBooleanOperationsFail());

    /** \details
       Performs boolean operation. Destroys both operand.

       \param eOperation [in] Boolean operation type.
       \param rOperandA [in]  Operand A.
       \param rOperandB [in]  Operand B.

       \returns
       Resulting body.
    */
    static Body boolOper(BooleanOperation eOperation,
      Body& rOperandA, Body& rOperandB);

    /** \details
       Returns part of the body in negative half-plane. Destroys operand.

       \param rBase [in]  Initial body.
       \param rCutter [in]  Cut plane.

       \returns
       Resulting body.
    */
    // static Body section( Body& rBase,
    //     const OdGePlane& rCutter );

    /** \details
       Cuts with extrusion. Destroys operand.

       \param rBase [in]  Base body.
       \param rCutter [in]  Cutting profile.
       \param bInside [in]  Whether to leave inside part or outside.
       \param dDepth [in]  Extrusion depth.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body cutWithExtrusion(Body& rBase,
      const Profile3D& rCutter, bool bInside, double dDepth,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Cuts with infinite extrusion. Destroys operand.

       \param rBase [in]  Base body.
       \param rCutter [in]  Cutting profile.
       \param bInside [in]  Whether to leave inside part or outside.
       \param devDeviation [in]  Deviation.

       \returns
       Resulting body.
    */
    static Body cutWithInfExtrusion(Body& rBase,
      const Profile3D& rCutter, bool bInside,
      const DeviationParams& devDeviation = FMGeGbl::gDefDev);

    /** \details
       Splits single face by plane preserving topology.

       \param pFace [in]  Face to split.
       \param pPlane [in]  Splitting plane.
       \param pNewOuter [out]  Resulting outer faces.
       \param pNewInner [out]  Resulting inner faces.
    */
    void splitFace(FacetModeler::Face* pFace,
      const OdGePlane& pPlane,
      std::vector<FacetModeler::Face*>* pNewOuter = 0,
      std::vector<FacetModeler::Face*>* pNewInner = 0);

    /** \details
       Adds face. Low level operation!
    */
    void addFace(FacetModeler::Face* pFace);

    /** \details
       Removes face. Low level operation!
    */
    void removeFace(FacetModeler::Face* pFace);

    /** \details
       Removes and deletes face. Low level operation!
    */
    void deleteFace(FacetModeler::Face* pFace);

    //
    void regeneratePairEdges();

    // If pFirstErrorDetected is provided then method returns false and assign error message to passed OdString
    // otherwise OdError with the error message is thrown if error is detected
    bool checkInternalConsistence(OdString* pFirstErrorDetected = 0) const;

    bool hasCoincidentEdges() const;
    bool hasCoincidentVertices() const;

    void clone_impl_if_referenced();

    void        save(SaveRestoreCallback*) const;
    void        save(FILE*)                const;
    void        save(const wchar_t* fileName) const;

    static Body restore(SaveRestoreCallback*);  // Returns a newly created body
    static Body restore(FILE*);                 // Returns a newly created body
    static Body restore(const wchar_t* fileName);  // Returns a newly created body

    void        saveToSat(SaveToSatCallback*, bool colorsAlso = false) const;
    void        saveToSat(FILE*, bool colorsAlso = false) const;
    void        saveToSat(const wchar_t* fileName, bool colorsAlso = false) const;
    static Body restoreFromSat(const wchar_t* fileName, int approx);

    void hideDisplay(const Transf3d&            projectionTransf,
      OutputPolylineCallback*,
      bool = true,
      HiddenLineDrawingImprove = kNoDrawingImprove,
      HideIntegerTransform* = NULL);

    void hideDisplayDxf(const Transf3d&            projectionTransf,
      const wchar_t*             dxfFileName,
      bool                       outputProjectedCoords = true,
      HiddenLineDrawingImprove = kNoDrawingImprove);

    void setHiddenLineParams
    (HiddenLinesDisplay hiddenLinesDisplay = kHiddenLinesInvisible,
      bool               displayApproxEdges = false,
      bool               displayBridgeEdges = false);

    ///////////////////////////////////////////////////////////////////////////
    //                          Triangulation
    // Notes:
    //
    // The OutputTriangleCallback is a pointer to a callback object whose 
    // method is called to output the individual triangles or quadrilaterals. 
    // See file callback.h for the definition of the abstract base class 
    // OutputTriangleCallback and files dxfout.h and dxfout.cpp for a sample 
    // callback class.
    //
    // The TriangulationType specifies what type of output is going to be
    // generated. Currently it may be triangles, quadrilaterals or triangle 
    // strips.
    //
    // The cacheTriangles Boolean argument specifies whether the evaluated 
    // triangles are to be be cached so that the next time they are needed, 
    // they are quickly read from the cache instead of reevaluated from
    // the model. 
    ///////////////////////////////////////////////////////////////////////////

    void triangulate(OutputTriangleCallback*,
      TriangulationType type = kGenerateTriangles,
      bool cacheTriangles = true) const;

    Body*    next() const;
    void     setNext(Body* nxt);

    BodyInterferenceType interfere(const Body& b) const;
    BodyInterferenceType operator &&(const Body& b) const;

    PointInBodyLocation contains(const Point3d& pt) const;
    PointInBodyLocation contains(const Point3d& pt, Entity*& coincidentEntity) const;

    // Returns true iff the given plane intersects or touches the body
    //
    bool planeIntersectsBody(const Plane&) const;

  private:
    void addFace2(Face* pFace);

    Face* addFace2(Surface* pSurface);

    // returns new starting edge of the loop
    Edge* mergeEdgesInLoop(Edge* pFirstEdge, const OdGeTol& gTol);

    // delete edge (without partners) and update face loop start, if the edge was first in a loop
    void deleteEdge(Edge* pEdge, Edge* pNewLoopStart);

    // split edge and all partners preserving topology
    // the vertex->point() must be at the edge
    void splitEdge(Edge* pEdge, Vertex* pNewVertex);

    //
    //void removeTJunctions();

    //
    void collectLoopsLight(Face* pFace);
    Body cloneByFaceList(std::vector<Face*> aFaceList) const;

  public:
    static Body customInternal(const std::vector<OdGePoint3d>& aVertices,
      const std::vector<OdInt32>& aFaceData,
      bool bRemoveTJ,
      const std::vector<OdUInt32>* aEdgeFlags = 0,
      const std::vector<OdUInt32>* aFaceFlags = 0,
      const std::vector<OdUInt32>* aVertexFlags = 0,
      const SurfaceData* pSurfaceData = 0,
      const std::vector<OdUInt32>* aFaceColors = 0,
      const std::vector<OdUInt32>* aEdgeColors = 0,
      OdUInt32 iUnknown = 0);
  private:

    //static Body CallOldBooleanOp( BooleanOperation operation, Body& rOperandA, Body& rOperandB );
    static Body DoUnionOperation(Body& rOperandA, Body& rOperandB);
    static Body DoIntersectionOperation(Body& rOperandA, Body& rOperandB);
    static Body DoDifferenceOperation(Body& rOperandA, Body& rOperandB);
    static Body DoXOROperation(Body& rOperandA, Body& rOperandB);

    static void CheckOperationResult(BooleanOperation operation, Body& rOperandA, Body& rOperandB, Body& rResult);

  public:
    FacetModeler::Vertex* getVertexList();
    void setVertexList(FacetModeler::Vertex* pList);
    FacetModeler::Surface* getSurfaceList();
    void setSurfaceList(FacetModeler::Surface* pList);
    OdUInt32 getSurfaceCount();
    void setSurfaceCount(OdUInt32 count);
    //OdUInt32 getVertexCount();
    void setVertexCount(OdUInt32 count);

  private:

    class BodyImpl* m_pImpl;

    friend class Vertex;
    friend class Face;
    friend class Surface;
    friend class BodyImpl;
    friend class BodyInternalConsistencyRestorer;
  };

  /** \details
  Sets the default level of checking done by Body::isValid() predicate.

  \param [in] the new checking level value:
  0: No checking.
  1: Simpler topology and geometry checking.
  2: Extensive topology and geometry checking.

  \returns the previous validity checking level value.
  */
  FMGEOMETRY_API int setValidityCheckingLevel(int nNewCheckingLevel);

  /** \details
  Returns the default level of checking done by Body::isValid() predicate.
  */
  FMGEOMETRY_API int getValidityCheckingLevel();

  /** \details
  For AModeler compatibility reason.
  */
#define SetValidityCheckingLevel setValidityCheckingLevel

}

#endif //__FMMDL_BODY_H__
