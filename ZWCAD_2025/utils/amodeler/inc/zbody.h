
#ifndef AECMODELER_INC_BODY_H
#define AECMODELER_INC_BODY_H


#pragma warning(push)
#pragma warning(disable : 4702) 
#include <vector>
#pragma warning(pop)
#include "zentity.h"
#include "zinterval.h"
#include "ztransf3d.h"
#include "zcolor.h"
#include "zmorphmap.h"
#include "zenums.h"

AECMODELER_NAMESPACE_BEGIN

const ZwFlag IPBF   = ZWFLAG(0); 
const ZwFlag NEGBF  = ZWFLAG(1);
const ZwFlag DASHBF = ZWFLAG(2);
const ZwFlag WFBF   = ZWFLAG(3);
const ZwFlag DAEBF  = ZWFLAG(4);
const ZwFlag DBEBF  = ZWFLAG(5);




class DllImpExp ZwBody : public ZwEntity
{
public:


    ZwBody();
    ZwBody(const ZwBody&);
    ~ZwBody();
    ZwBody& operator =(const ZwBody &);
    ZwBody copy() const;
    void init(bool  deleteContents);
    
    void modified();

    ZwBody boolOper(ZwBody&, BoolOperType eType, bool  hideZeroSlopeEdges = true, ZwTopologyChangeCallback* pCallBack = NULL, bool  keepInputBodiesWhenFails = ZwKeepInputBodiesWhenBooleanOperationsFail());

    //使用ZwPlane分割body,移除ZwPlane法向指定的部分
    void section(const ZwPlane&, bool keepInputBodyWhenFails = ZwKeepInputBodiesWhenBooleanOperationsFail());

    //使用ZwPlane分割body,移除ZwPlane法向指定的部分,(若被移除的部分由多个不相交的lump组成,就只移除离point最近的那个lump)
    void section(const ZwPlane&, const ZwPoint3d& point, bool keepInputBodyWhenFails = ZwKeepInputBodiesWhenBooleanOperationsFail());

    bool slice(const ZwPlane&, std::vector<ZwPoint3d>& outputVertices, std::vector<int>& outputLoops) const;

    ZwBody operator + (const ZwBody& );
    ZwBody  operator - (const ZwBody& );
    ZwBody  operator * (const ZwBody& );
    ZwBody  operator - (const ZwPlane&);
    ZwBody& operator +=(const ZwBody& );
    ZwBody& operator -=(const ZwBody& );
    ZwBody& operator *=(const ZwBody& ); 
    ZwBody& operator -=(const ZwPlane&);

    ZwBodyInterferenceType interfere(const ZwBody& body) const;
    ZwPointInBodyLocation  contains(const ZwPoint3d&) const; 
    ZwPointInBodyLocation  contains(const ZwPoint3d&, ZwEntity*& coincidentEntity) const;

    ZwBodyInterferenceType operator &&(const ZwBody&   ) const;
    ZwPointInBodyLocation  operator &&(const ZwPoint3d&) const;

    ZwPoint3d closestPointOnBody(ZwPoint3d testPoint, ZwEntity*& pClosestEntity) const;

    void classifyLineSegment(const ZwPoint3d&                    startPoint,
                             const ZwPoint3d&                    endPoint,
                             std::vector<ZwPoint3d>&             fragmentPoints,
                             std::vector<ZwPointInBodyLocation>& fragmentClassifications);

    bool planeIntersectsBody(const ZwPlane&) const;

    ZwRayBodyIntersection rayIntersection(const ZwLine3d& ray,double tolerance,ZwEntity*& closestIntersectedEntity,double& closestEntiyDistanceAlongRay) const;

    ZwRayBodyIntersection rayIntersection(const ZwLine3d& ray,double tolerance,ZwEntity*& closestIntersectedEntity) const;


    ZwBody combine(ZwBody&);

    ZwBody& translate(const ZwVector3d&);

    ZwBody& rotate   (const ZwLine3d& axis, double angle);

    ZwBody& scale    (const ZwPoint3d& fixedPt, double factor);

    ZwBody& scale    (const ZwPoint3d& fixedPt, const ZwVector3d& xyzFactors);

    ZwBody& stretch  (const ZwLine3d& axis);

    ZwBody& mirror   (const ZwPlane&);

    ZwBody& align    (const ZwPoint3d& src1, const ZwPoint3d& src2, const ZwPoint3d& src3, const ZwPoint3d& dst1, const ZwPoint3d& dst2, const ZwPoint3d& dst3);

    ZwBody& align    (const ZwPoint3d& src1, const ZwVector3d& src2, const ZwVector3d& src3,const ZwPoint3d&  dst1, const ZwVector3d& dst2, const ZwVector3d& dst3);

    ZwBody& align    (const ZwPoint3d&  src1, const ZwVector3d& src2, const ZwPoint3d&  dst1, const ZwVector3d& dst2);

    ZwBody& transform(const ZwTransf3d&);

    ZwBody& negate     ();
    ZwBody  operator  -();                   

    ZwBody& operator *=(const ZwTransf3d&);          
    ZwBody  operator * (const ZwTransf3d&); 

    void massProperties(double&  area, double&  volume, ZwPoint3d& centroid, ZwPoint3d& moments, ZwPoint3d& products) const;
    double volume() const;

    static ZwBody box (const ZwPoint3d& corner, const ZwVector3d& sizes);
    static ZwBody sphere (const ZwPoint3d& center, double radius, int approx);
    static ZwBody cylinder(const ZwLine3d&axis, double radius, int approx);
    static ZwBody cylinder(const ZwLine3d&axis, const ZwVector3d& baseNormal,double radius, int approx);
    static ZwBody cone(const ZwLine3d& axis, double radius1, double radius2, int approx);
    static ZwBody cone(const ZwLine3d& axis, const ZwVector3d& baseNormal, double radius1, double radius2, int approx);
    enum torus_type { DONUT_TORUS, APPLE_TORUS, LEMON_TORUS, VORTEX_TORUS };

    static ZwBody torus_extension(const ZwLine3d& axis, double majorRadius, double minorRadius, int majorApprox, int minorApprox);
    static ZwBody torus(const ZwLine3d& axis, double majorRadius, double minorRadius, int majorApprox, int minorApprox);
    static ZwBody pipe(const ZwLine3d&axis, double outerRadius, double innerRadius, int approx);
    static ZwBody pipe(const ZwLine3d&axis, const ZwVector3d& baseNormal, double outerRadius, double innerRadius, int approx);
    static ZwBody pipeConic(const ZwLine3d&axis, double outerRadius1, double innerRadius1, double outerRadius2, double innerRadius2, int approx);
    static ZwBody pipeConic(const ZwLine3d&axis, const ZwVector3d& baseNormal, double outerRadius1, double innerRadius1, double outerRadius2, double innerRadius2, int approx);
    static ZwBody tetrahedron (const ZwPoint3d& p1, const ZwPoint3d& p2, const ZwPoint3d& p3, const ZwPoint3d& p4);
    static ZwBody reducingElbow(const ZwPoint3d& elbowCenter, const ZwPoint3d& endCenter1, const ZwPoint3d& endCenter2, double endRadius1, double endRadius2, int majorApprox, int minorApprox);
    static ZwBody rectangleToCircleReducer(const ZwPoint3d& baseCorner, const ZwVector2d& baseSizes,const ZwCircle3d& topCircle,int approx);

    static ZwBody convexHull(const ZwPoint3d pts[], int numPoints);

    ZwBody convexHull() const;



    static ZwBody extrusion (const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[],int numVertices,const ZwVector3d&plgNormal,const ZwVector3d&extrusionVector,const ZwPoint3d& scaleTwistFixedPt,double scaleFactor,double twistAngle = 0.0);
    static ZwBody extrusion (const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[],int numVertices,const ZwVector3d&plgNormal,const ZwVector3d&extrusionVector);
    static ZwBody extrusion (const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[],int numVertices,const ZwVector3d&plgNormal,const ZwVector3d&extrusionVector,const std::vector<void*>*attribs);

    static ZwBody pyramid(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d&plgNormal,const ZwPoint3d& pyramidApex);

    static ZwBody axisRevolution(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d& plgNormal, const ZwLine3d& axis, double revolutionAngle, int approx, const ZwPoint3d& scaleTwistFixedPt, double scaleFactor, double twistAngle = 0.0);
    static ZwBody axisRevolution(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d& plgNormal, const ZwLine3d& axis, double revolutionAngle, int approx);

    static ZwBody endpointRevolution(const ZwPoint3d plg[], ZwPolygonVertexData* vertexData[], int numVertices, const ZwVector3d& plgNormal, double revolutionAngle, int approx);

    static ZwBody extrusionAlongPath(

        const ZwBody& startProfile,
        const ZwBody& endProfile,
        const ZwPoint3d           pathPlg[],
        ZwPolygonVertexData* pathVertexData[],
        int                     pathNumVertices,
        bool                    pathIsClosed,
        bool                    checkBodyValidity = true,
        const ZwPoint3d& scaleTwistFixedPt = ZwPoint3d::kNull,
        double                  scaleFactor = 1.0,
        double                  twistAngle = 0.0,
        const ZwMorphingMap& morphingMap = ZwMorphingMap::kNull,
        bool                    calcluateMorphingMapAutomatically = false,
        std::vector<int>        startProfileSignificantVertices = std::vector<int>(),
        std::vector<int>        endProfileSignificantVertices = std::vector<int>());

    static ZwBody skin (ZwBody* profiles[], int numProfiles, bool isClosed,bool checkPlanarity,ZwMorphingMap** morphingMaps = NULL,bool markInnerProfileEdgesAsApprox = false,bool ckeckInputProfiles= true);


    void hideDisplay(const ZwTransf3d&projectionTransf,ZwOutputPolylineCallback*,bool  = true, ZwHiddenLineDrawingImprove = kNoDrawingImprove, ZwHideIntegerTransform* = NULL); // Output argument, may be NULL

    void hideDisplayDxf(const ZwTransf3d& projectionTransf, const wchar_t* dxfFileName, bool outputProjectedCoords = true, ZwHiddenLineDrawingImprove = kNoDrawingImprove);

    void setHiddenLineParams(ZwHiddenLinesDisplay hiddenLinesDisplay = kHiddenLinesInvisible, bool displayApproxEdges = false, bool displayBridgeEdges = false);

    ZwVertex* pickVertex(const ZwPoint3d& pickPoint, double aperture, const ZwHideIntegerTransform&, ZwBody** bPicked=NULL) const;
    ZwEdge*   pickEdge  (const ZwPoint3d& pickPoint, double aperture, const ZwHideIntegerTransform&, ZwBody** bPicked=NULL) const;
    ZwFace*   pickFace  (const ZwPoint3d& pickPoint, double aperture, const ZwHideIntegerTransform&, ZwBody** bPicked=NULL) const;
    ZwBody*   pickBody  (const ZwPoint3d& pickPoint, double aperture, const ZwHideIntegerTransform&) const;

    void triangulate(ZwOutputTriangleCallback* pCallBack, ZwTriangulationType type = kGenerateTriangles,bool  cacheTriangles= true) const;

    void triangulateDxf(const wchar_t* dxfFileName, ZwTriangulationType type = kGenerateTriangles, bool cacheTriangles    = true) const;

    void triangulateFace(ZwFace*);

    void triangulateAllFaces();


    void save(ZwSaveRestoreCallback*) const;
    void save(FILE*)const;
    void save(const wchar_t* fileName) const;

    static ZwBody restore(ZwSaveRestoreCallback*); 
    static ZwBody restore(FILE*);
    static ZwBody restore(const wchar_t* fileName); 

    void     saveToSat(ZwSaveToSatCallback*,   bool colorsAlso = false) const;
    void     saveToSat(FILE*,                bool colorsAlso = false) const;
    void     saveToSat(const wchar_t* fileName, bool colorsAlso = false) const;

    void        print  (FILE* = NULL) const; 
 
    void stitchFaces(bool splitEdges = false, bool orientFaces = false, bool addMissingFaces = false);


    void mergeCoplanarEntities(bool bridgeEdgesOnly    = true,
                               bool sameColorOnly      = true,
                               ZwTopologyChangeCallback* = NULL);

    void mergeCoplanarFaces(ZwEdge* pEdgeBetweenFaces);

    void mergeEqualSurfaces();

    void makeArcTessellationsInExtrusionsCoincide(const ZwBody&     referenceExtrusion, 
                                                  const ZwVector3d& extrusionVector, // Of this extrusion body
                                                  bool&           changedSomething,
                                                  bool&           everythingSucceeded);

    void copyGeomFrom(const ZwBody&, const ZwTransf3d& = ZwTransf3d::kIdentity);

    void changeVertexCoordinates(ZwVertex* changedVertices[], ZwPoint3d changedVertexCoordinates[], int numChangedVertices, bool checkPlanarity = true);

    ZwBody extractShell(ZwFace* pFaceInTheShell = NULL);

    ZwBody extractFace(ZwFace* pFaceToExtract = NULL);

    void decomposeIntoLumps(std::vector<ZwBody*>& lumpBodies);

    void moveFace(ZwFace* pFaceToMove, const ZwVector3d& vector, bool keepAdjacentFacePlanesFixed, bool keepFaceGeometryFixed, ZwFace*& pFaceToMoveAfterMove);

    void generateUnspecifiedSurfaces(double angleTolerance, int minNumberOfFacesInSurface = 2);

    void generateUnspecifiedSurfacesFromApproxEdges(int minNumberOfFacesInSurface = 2);


    void convertToTerrainBody(double height, bool checkValidity, std::vector<ZwFace*>& bottomFaces);

    void     setColor(ZwColor color);

    ZwBody*  next   () const  { return mpNext; }
    void     setNext(ZwBody* nxt)  { mpNext = nxt;  }


    int      vertexCount  () const;
    int      edgeCount    () const;  
    int      faceCount    () const;
    int      surfaceCount () const;
    int      curveCount   () const;
    int      triangleCount() const;



    bool     isNull   () const     { return mpFaceList == NULL; }
    bool     isNegated() const     { return isFlagOn(NEGBF);    } 


    bool     isValid(int validityCheckingLevel = -1) const;

    bool     containsNonManifoldEdges() const; 

    ZwFace*    faceList         () const     { return mpFaceList;    }
    ZwSurface* surfaceList      () const     { return mpSurfaceList; }
    ZwCurve*   curveList        () const     { return mpCurveList;   }
    ZwVertex*  vertexList       () const     { return mpVertexList;  }
    void     setFaceList      (ZwFace*    f) { mpFaceList    = f;    }
    void     setSurfaceList   (ZwSurface* s) { mpSurfaceList = s;    }
    void     setCurveList     (ZwCurve*   c) { mpCurveList   = c;    }
    void     setVertexList    (ZwVertex*  v) { mpVertexList  = v;    }

    void     addFace          (ZwFace*   );
    void     addSurface       (ZwSurface*);
    void     addCurve         (ZwCurve*  );
    void     addVertex        (ZwVertex* );

    void     getPhysicalEdgesAndVertices(bool wantPhysicalEdges, bool wantPhysicalVertices, std::vector<ZwEdge*>&   physicalEdges, std::vector<ZwVertex*>& physicalVertices);
    const    ZwInterval3d& interval(double enlargeBy = 10*ZwEpsAbs()) const;

    void     evaluateVertexSurfaceData  () const;
    void     deleteVertexSurfaceData    () const;

    void     setAEFAndBEFFlags          (bool markEdgesBetweenCoplanarFacesAsBridge);
    void     setAEFAndBEFFlags          (); 
    void     deleteFaceIntervals        () const;
    void     deleteFaceIntervalsAndPlanes() const;

    void     removeFace(ZwFace*); // Removes the face from the face list
    void     deleteFace(ZwFace*); // ... and also deletes it
             
    void     deleteMarkedFaces(ZwFlag);
    void     deleteMarkedSurfaces(ZwFlag); 
    void     deleteMarkedCurves(ZwFlag);
    void     deleteMarkedVertices(ZwFlag);

    void     deleteEmptyFaces();
    void     deleteUnusedVerticesSurfacesCurves(); // Note: Reuses FLAG(31)

    void     setFaceFlags(ZwOnOff, ZwFlag) const;
    void     setSurfaceFlags(ZwOnOff, ZwFlag) const;
    void     setCurveFlags(ZwOnOff, ZwFlag) const;
    void     setEdgeFlags(ZwOnOff, ZwFlag) const;
    void     setVertexFlags(ZwOnOff, ZwFlag) const;

    bool     mergeCoincidentVertices();

    void cleanUpNonManifoldEdgesAndCoincidentFaces();

    void getAllEdgesReferencingVertex(const ZwVertex* v, std::vector<ZwEdge*>&) const;

    void setInterval(const ZwInterval3d&); // For internal use only
private:
    
    ZwFace*      mpFaceList;
    ZwSurface*   mpSurfaceList;
    ZwCurve*     mpCurveList;
    ZwVertex*    mpVertexList;
    ZwBody*      mpNext;
    ZwInterval3d mInterval;
    ZwTriangleCache* mpTriangleCache; 

}; 



extern ZwBody operator * (const ZwTransf3d&,ZwBody&); 
extern ZwPointInBodyLocation operator &&(const ZwPoint3d&, const ZwBody&);

DllImpExp int setValidityCheckingLevel(int newLevel);

DllImpExp int getValidityCheckingLevel();


#define SetValidityCheckingLevel setValidityCheckingLevel


AECMODELER_NAMESPACE_END
#endif

