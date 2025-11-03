/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_BODY_H
#define GMODELER_INC_BODY_H


#pragma warning(push)
#pragma warning(disable : 4702) 
#include <vector>
#pragma warning(pop)
#include "entity.h"
#include "interval.h"
#include "transf3d.h"
#include "color.h"
#include "morphmap.h"
#include "enums.h"

GMODELER_NAMESPACE_BEGIN

const Flag IPBF   = FLAG(0);
const Flag NEGBF  = FLAG(1);
const Flag DASHBF = FLAG(2);
const Flag WFBF   = FLAG(3);
const Flag DAEBF  = FLAG(4);
const Flag DBEBF  = FLAG(5);

class DllImpExp Body : public Entity
{
public:
  Body();
  Body(const Body&);
  ~Body();

  Body& operator =(const Body &);

  Body copy() const;

  void init(bool deleteContents);

  void modified();

  Body boolOper(Body&, BoolOperType, bool hideZeroSlopeEdges = true, TopologyChangeCallback* = NULL, bool keepInputBodiesWhenFails = keepInputBodiesWhenBooleanOperationsFail());

  void section(const Plane&, bool keepInputBodyWhenFails = keepInputBodiesWhenBooleanOperationsFail());
  void section(const Plane&, const Point3d& point, bool keepInputBodyWhenFails = keepInputBodiesWhenBooleanOperationsFail());

  bool slice(const Plane&, std::vector<Point3d>& outputVertices, std::vector<int>& outputLoops) const;

  Body  operator + (const Body&);
  Body  operator - (const Body&);
  Body  operator * (const Body&);
  Body  operator - (const Plane&);

  Body& operator +=(const Body&);
  Body& operator -=(const Body&);
  Body& operator *=(const Body&);
  Body& operator -=(const Plane&);

  BodyInterferenceType interfere(const Body&) const;
  PointInBodyLocation  contains(const Point3d&) const;
  PointInBodyLocation  contains(const Point3d&, Entity*& coincidentEntity) const;

  BodyInterferenceType operator &&(const Body&) const;
  PointInBodyLocation  operator &&(const Point3d&) const;

  Point3d closestPointOnBody(Point3d testPoint, Entity*& pClosestEntity) const;

  void classifyLineSegment(const Point3d&                    startPoint,
                           const Point3d&                    endPoint,
                           std::vector<Point3d>&             fragmentPoints,
                           std::vector<PointInBodyLocation>& fragmentClassifications);

  bool planeIntersectsBody(const Plane&) const;

  RayBodyIntersection rayIntersection(
    const Line3d& ray,
    double        tolerance,
    Entity*&      closestIntersectedEntity,
    double&       closestEntiyDistanceAlongRay) const;
  RayBodyIntersection rayIntersection(
    const Line3d& ray,
    double        tolerance,
    Entity*&      closestIntersectedEntity) const;

  Body combine(Body&);

  Body& translate(const Vector3d&);
  Body& rotate(const Line3d& axis, double angle);
  Body& scale(const Point3d& fixedPt, double factor);
  Body& scale(const Point3d& fixedPt, const Vector3d& xyzFactors);
  Body& stretch(const Line3d& axis);
  Body& mirror(const Plane&);

  Body& align(const Point3d& src1,
              const Point3d& src2,
              const Point3d& src3,
              const Point3d& dst1,
              const Point3d& dst2,
              const Point3d& dst3);
  Body& align(const Point3d&  src1,
              const Vector3d& src2,
              const Vector3d& src3,
              const Point3d&  dst1,
              const Vector3d& dst2,
              const Vector3d& dst3);
  Body& align(const Point3d&  src1,
              const Vector3d& src2,
              const Point3d&  dst1,
              const Vector3d& dst2);

  Body& transform(const Transf3d&);

  Body& negate();
  Body  operator  -();

  Body& operator *=(const Transf3d&);
  Body  operator * (const Transf3d&);

  void massProperties(double&  area,
                      double&  volume,
                      Point3d& centroid,
                      Point3d& moments,
                      Point3d& products) const;

  double volume() const;

  static Body box(const Point3d& corner, const Vector3d& sizes);

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

  enum torus_type
  {
    DONUT_TORUS,
    APPLE_TORUS,
    LEMON_TORUS,
    VORTEX_TORUS
  };

  static Body torus_extension(const Line3d&   axis,
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

  static Body rectangleToCircleReducer(const Point3d&  baseCorner,
                                       const Vector2d& baseSizes,
                                       const Circle3d& topCircle,
                                       int             approx);

  static Body convexHull(const Point3d pts[], int numPoints);
  Body convexHull() const;

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

  static Body axisRevolution(const Point3d      plg[],
                             PolygonVertexData* vertexData[],
                             int                numVertices,
                             const Vector3d&    plgNormal,
                             const Line3d&      axis,
                             double             revolutionAngle,
                             int                approx,
                             const Point3d&     scaleTwistFixedPt,
                             double             scaleFactor,
                             double             twistAngle = 0.0);

  static Body axisRevolution(const Point3d      plg[],
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

  void hideDisplay(const Transf3d&            projectionTransf,
                   OutputPolylineCallback*,
                   bool = true,
                   HiddenLineDrawingImprove = kNoDrawingImprove,
                   HideIntegerTransform* = NULL);
  void hideDisplayDxf(const Transf3d&            projectionTransf,
                      const wchar_t*             dxfFileName,
                      bool                       outputProjectedCoords = true,
                      HiddenLineDrawingImprove = kNoDrawingImprove);

  void setHiddenLineParams(HiddenLinesDisplay hiddenLinesDisplay = kHiddenLinesInvisible,
                           bool               displayApproxEdges = false,
                           bool               displayBridgeEdges = false);

  Vertex* pickVertex(const Point3d& pickPoint, double aperture, const HideIntegerTransform&, Body** bPicked = NULL) const;
  Edge*   pickEdge(const Point3d& pickPoint, double aperture, const HideIntegerTransform&, Body** bPicked = NULL) const;
  Face*   pickFace(const Point3d& pickPoint, double aperture, const HideIntegerTransform&, Body** bPicked = NULL) const;
  Body*   pickBody(const Point3d& pickPoint, double aperture, const HideIntegerTransform&) const;

  void triangulate(OutputTriangleCallback*,
                   TriangulationType type = kGenerateTriangles,
                   bool cacheTriangles = true) const;
  void triangulateDxf(const wchar_t* dxfFileName,
                      TriangulationType type = kGenerateTriangles,
                      bool cacheTriangles = true) const;
  void triangulateFace(Face*);
  void triangulateAllFaces();

  void        save(SaveRestoreCallback*) const;
  void        save(FILE*)                const;
  void        save(const wchar_t* fileName) const;

  static Body restore(SaveRestoreCallback*);
  static Body restore(FILE*);
  static Body restore(const wchar_t* fileName);

  void        saveToSat(SaveToSatCallback*, bool colorsAlso = false) const;
  void        saveToSat(FILE*, bool colorsAlso = false) const;
  void        saveToSat(const wchar_t* fileName, bool colorsAlso = false) const;

  void        print(FILE* = NULL) const;

  void stitchFaces(bool splitEdges = false, bool orientFaces = false, bool addMissingFaces = false);

  void mergeCoplanarEntities(bool bridgeEdgesOnly = true,
                             bool sameColorOnly = true,
                             TopologyChangeCallback* = NULL);
  void mergeCoplanarFaces(Edge* pEdgeBetweenFaces);
  void mergeEqualSurfaces();
  void makeArcTessellationsInExtrusionsCoincide(const Body&     referenceExtrusion,
                                                const Vector3d& extrusionVector,
                                                bool&           changedSomething,
                                                bool&           everythingSucceeded);

  void copyGeomFrom(const Body&, const Transf3d& = Transf3d::kIdentity);

  void changeVertexCoordinates(Vertex* changedVertices[],
                               Point3d changedVertexCoordinates[],
                               int     numChangedVertices,
                               bool    checkPlanarity = true);

  Body extractShell(Face* pFaceInTheShell = NULL);
  Body extractFace(Face* pFaceToExtract = NULL);

  void decomposeIntoLumps(std::vector<Body*>& lumpBodies);

  void moveFace(Face*           pFaceToMove,
                const Vector3d& vector,
                bool            keepAdjacentFacePlanesFixed,
                bool            keepFaceGeometryFixed,
                Face*&          pFaceToMoveAfterMove);

  void generateUnspecifiedSurfaces(double angleTolerance, int minNumberOfFacesInSurface = 2);
  void generateUnspecifiedSurfacesFromApproxEdges(int minNumberOfFacesInSurface = 2);

  void convertToTerrainBody(double              height,
                            bool                checkValidity,
                            std::vector<Face*>& bottomFaces);

  void setColor(Color);

  Body*    next() const { return mpNext; }
  void     setNext(Body* nxt) { mpNext = nxt; }

  int      vertexCount() const;
  int      edgeCount() const;
  int      faceCount() const;
  int      surfaceCount() const;
  int      curveCount() const;
  int      triangleCount() const;

  bool     isNull() const { return mpFaceList == NULL; }
  bool     isNegated() const { return isFlagOn(NEGBF); }
  bool     isValid(int validityCheckingLevel = -1) const;

  bool     containsNonManifoldEdges() const;

  Face*    faceList() const { return mpFaceList; }
  Surface* surfaceList() const { return mpSurfaceList; }
  Curve*   curveList() const { return mpCurveList; }
  Vertex*  vertexList() const { return mpVertexList; }

  void     setFaceList(Face*    f) { mpFaceList = f; }
  void     setSurfaceList(Surface* s) { mpSurfaceList = s; }
  void     setCurveList(Curve*   c) { mpCurveList = c; }
  void     setVertexList(Vertex*  v) { mpVertexList = v; }

  void     addFace(Face*);
  void     addSurface(Surface*);
  void     addCurve(Curve*);
  void     addVertex(Vertex*);

  void getPhysicalEdgesAndVertices(bool                  wantPhysicalEdges,
                                   bool                  wantPhysicalVertices,
                                   std::vector<Edge*>&   physicalEdges,
                                   std::vector<Vertex*>& physicalVertices);

  const Interval3d& interval(double enlargeBy = 10 * epsAbs()) const;

  void evaluateVertexSurfaceData() const;
  void deleteVertexSurfaceData() const;

  void setAEFAndBEFFlags(bool markEdgesBetweenCoplanarFacesAsBridge);
  void setAEFAndBEFFlags();
  void deleteFaceIntervals() const;
  void deleteFaceIntervalsAndPlanes() const;

  void removeFace(Face*);
  void deleteFace(Face*);

  void deleteMarkedFaces(Flag);
  void deleteMarkedSurfaces(Flag);
  void deleteMarkedCurves(Flag);
  void deleteMarkedVertices(Flag);

  void deleteEmptyFaces();
  void deleteUnusedVerticesSurfacesCurves();

  void setFaceFlags(OnOff, Flag) const;
  void setSurfaceFlags(OnOff, Flag) const;
  void setCurveFlags(OnOff, Flag) const;
  void setEdgeFlags(OnOff, Flag) const;
  void setVertexFlags(OnOff, Flag) const;

  bool mergeCoincidentVertices();

  void cleanUpNonManifoldEdgesAndCoincidentFaces();

  void getAllEdgesReferencingVertex(const Vertex* v, std::vector<Edge*>&) const;

  void setInterval(const Interval3d&);

private:
  Face*      mpFaceList;
  Surface*   mpSurfaceList;
  Curve*     mpCurveList;
  Vertex*    mpVertexList;
  Body*      mpNext;
  Interval3d     mInterval;
  TriangleCache* mpTriangleCache;
};

extern Body                operator * (const Transf3d&, Body&);
extern PointInBodyLocation operator &&(const Point3d&, const Body&);

DllImpExp int setValidityCheckingLevel(int newLevel);
DllImpExp int getValidityCheckingLevel();

#define SetValidityCheckingLevel setValidityCheckingLevel

GMODELER_NAMESPACE_END
#endif
