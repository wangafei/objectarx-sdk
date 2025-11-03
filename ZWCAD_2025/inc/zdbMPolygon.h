

#pragma once

#undef ZCAD_OBJID_INLINE_INTERNAL	
#include "zdbhatch.h"
#include <tchar.h>

class ZcDbCircle;
class ZcDb2dPolyline;
class ZcDbPolyline;
class ZcDbMPolygonCrossingArray;
class ZcDbMPolygonNode;

const double ZcDbMPolygonCrossingFuzz = 1E-6;

#ifndef _ZSOFT_MAC_
#ifndef ZCMPOLYGON_PORT
#ifdef ZCMPOLYGON_API
#define ZCMPOLYGON_PORT _declspec(dllexport)
#else
#define ZCMPOLYGON_PORT _declspec(dllimport)
#endif
#endif
#else

#define ZCBASE_PORT
#endif 

class ZcDbMPolygon : public ZcDbEntity {
public:

    enum loopDir {
        kExterior     = 0,            
        kInterior,                    
        kAnnotation                   
    };

    ZCMPOLYGON_PORT ZcDbMPolygon();
    ZCMPOLYGON_PORT virtual ~ZcDbMPolygon();

    ZCRX_DECLARE_MEMBERS_EXPIMP(ZcDbMPolygon, ZCMPOLYGON_PORT); 

    ZCMPOLYGON_PORT virtual ZcDbHatch * hatch();

    ZCMPOLYGON_PORT virtual double elevation() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setElevation(double elevation);

    ZCMPOLYGON_PORT virtual ZcGeVector3d normal() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setNormal(const ZcGeVector3d& normal);

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus  evaluateHatch(bool bUnderestimateNumLines = false);

    ZCMPOLYGON_PORT virtual ZcDbHatch::HatchPatternType patternType() const;

    ZCMPOLYGON_PORT virtual const TCHAR* patternName() const;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus  setPattern(ZcDbHatch::HatchPatternType patType,
                                  const TCHAR* patName);

    ZCMPOLYGON_PORT virtual double patternAngle() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setPatternAngle(double angle);

    ZCMPOLYGON_PORT virtual double patternSpace() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setPatternSpace(double space);

    ZCMPOLYGON_PORT virtual double patternScale() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setPatternScale(double scale);

    ZCMPOLYGON_PORT virtual bool patternDouble() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setPatternDouble(bool isDouble);

    ZCMPOLYGON_PORT virtual int numPatternDefinitions() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus  getPatternDefinitionAt(int index, 
                                              double& angle,
                                              double& baseX,
                                              double& baseY,
                                              double& offsetX,
                                              double& offsetY,
                                              ZcGeDoubleArray& dashes)
                                              const;

    ZCMPOLYGON_PORT Zcad::ErrorStatus setGradientAngle(double angle);
    ZCMPOLYGON_PORT Zcad::ErrorStatus setGradientShift( float shiftValue );
	ZCMPOLYGON_PORT Zcad::ErrorStatus setGradientOneColorMode( ZSoft::Boolean oneColorMode );			   
    ZCMPOLYGON_PORT Zcad::ErrorStatus setGradientColors( unsigned int count, 
                                            ZcCmColor* colors,
                                            float* values );
    ZCMPOLYGON_PORT Zcad::ErrorStatus setGradient(ZcDbHatch::GradientPatternType gradType,
                                   const TCHAR* gradName);

    ZCMPOLYGON_PORT virtual ZcCmColor patternColor() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setPatternColor(const ZcCmColor& pc);

    ZCMPOLYGON_PORT virtual double getArea() const;
    ZCMPOLYGON_PORT virtual double getPerimeter() const;

    ZCMPOLYGON_PORT virtual bool isBalanced() const;

    ZCMPOLYGON_PORT virtual ZcGeVector2d getOffsetVector() const;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus getMPolygonTree(ZcDbMPolygonNode*& loopNode) const;
    ZCMPOLYGON_PORT virtual void deleteMPolygonTree(ZcDbMPolygonNode* loopNode) const;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus appendLoopFromBoundary(const ZcDbCircle* pCircle,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus appendLoopFromBoundary(const ZcDbPolyline* pPoly,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus appendLoopFromBoundary(const ZcDb2dPolyline* pPoly,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);

    ZCMPOLYGON_PORT virtual int numMPolygonLoops() const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus getMPolygonLoopAt(int loopIndex, ZcGePoint2dArray& vertices,
                                        ZcGeDoubleArray& bulges) const;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus insertMPolygonLoopAt(int loopIndex, 
        const ZcGePoint2dArray& vertices, const ZcGeDoubleArray& bulges, 
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus appendMPolygonLoop(const ZcGePoint2dArray& vertices, 
        const ZcGeDoubleArray& bulges, bool excludeCrossing = true,
        double tol = ZcDbMPolygonCrossingFuzz);
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus removeMPolygonLoopAt(int loopIndex);

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus balanceTree();
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus balanceDisplay();

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus getLoopDirection(int lindex, ZcDbMPolygon::loopDir& dir) const;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus setLoopDirection(int lindex, ZcDbMPolygon::loopDir dir);

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus getLoopAtGsMarker(int gsMark, int &loop) const;
    ZCMPOLYGON_PORT virtual void getChildLoops(int curLoop, ZcGeIntArray& selectedLoopIndexes) const;
    ZCMPOLYGON_PORT virtual int getParentLoop(int curLoop) const;
    ZCMPOLYGON_PORT virtual int getClosestLoopTo(const ZcGePoint3d& worldPt) const;

    ZCMPOLYGON_PORT virtual int isPointInsideMPolygon(const ZcGePoint3d& worldPt, ZcGeIntArray& loopsArray,
                                      double tol = ZcDbMPolygonCrossingFuzz) const;
    ZCMPOLYGON_PORT virtual bool isPointOnLoopBoundary(const ZcGePoint3d& worldPt, int loop, 
                                       double tol = ZcDbMPolygonCrossingFuzz) const;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus loopCrossesItself(bool& crosses, bool findAll,
                                        ZcDbMPolygonCrossingArray& crossingsArray,
                                        const ZcGePoint2dArray& vertexPts, 
                                        const ZcGeDoubleArray& vertexBulges, 
                                        double tol = ZcDbMPolygonCrossingFuzz) const;

    ZCMPOLYGON_PORT virtual bool loopCrossesItself(const ZcGePoint2dArray& vertexPts, 
                           const ZcGeDoubleArray& vertexBulges, 
                           double tol = ZcDbMPolygonCrossingFuzz) const;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus loopCrossesMPolygon(bool& crosses, bool findAll,
                                          ZcDbMPolygonCrossingArray& crossingsArray,
                                          const ZcGePoint2dArray& testVertexPts, 
                                          const ZcGeDoubleArray& testVertexBulges, 
                                          double tol = ZcDbMPolygonCrossingFuzz) const;

    ZCMPOLYGON_PORT virtual bool selfCrosses(const ZcGePoint2dArray& vertexPts, 
                     const ZcGeDoubleArray& vertexBulges,
                     double tol = ZcDbMPolygonCrossingFuzz) const;

    ZCMPOLYGON_PORT virtual bool includesTouchingLoops(double tol = ZcDbMPolygonCrossingFuzz) const;

   ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subGetClassID( CLSID* pClsid) const override; 

    ZCMPOLYGON_PORT virtual ZSoft::Boolean    subWorldDraw(ZcGiWorldDraw*  mode) override;
    ZCMPOLYGON_PORT virtual void              saveAs(ZcGiWorldDraw* mode, ZcDb::SaveType st) override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subGetSubentPathsAtGsMarker(		
        ZcDb::SubentType      type,
        ZSoft::GsMarker       gsMark,
        const ZcGePoint3d&    pickPoint,
        const ZcGeMatrix3d&   viewXform,
        int&                  numPaths,
        ZcDbFullSubentPath*&  subentPaths,
        int                   numInserts = 0,
        ZcDbObjectId*         entAndInsertStack 
        = NULL) const override;
    
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subGetGsMarkersAtSubentPath(	
        const ZcDbFullSubentPath& subPath, 
        ZcArray<ZSoft::GsMarker>&          gsMarkers) const override;

    ZCMPOLYGON_PORT virtual ZcDbEntity*       subSubentPtr(const ZcDbFullSubentPath& id) const override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus   subIntersectWith(	
        const ZcDbEntity*   ent,
        ZcDb::Intersect     intType,
        ZcGePoint3dArray&      points,
        ZSoft::GsMarker/*int*/                 thisGsMarker  = 0,
        ZSoft::GsMarker/*int*/                 otherGsMarker = 0)
        const override;
    
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus   subIntersectWith(	
        const ZcDbEntity*   ent,
        ZcDb::Intersect     intType,
        const ZcGePlane&    projPlane,
        ZcGePoint3dArray&      points,
        ZSoft::GsMarker/*int*/                 thisGsMarker  = 0,
        ZSoft::GsMarker/*int*/                 otherGsMarker = 0)
        const override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus   subGetOsnapPoints(	
        ZcDb::OsnapMode       osnapMode,
        ZSoft::GsMarker       gsSelectionMark,
        const ZcGePoint3d&    pickPoint,
        const ZcGePoint3d&    lastPoint,
        const ZcGeMatrix3d&   viewXform,
        ZcGePoint3dArray&        snapPoints,
        ZcDbIntArray&     geomIds) const override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subGetGripPoints(ZcGePoint3dArray&     gripPoints,	
        ZcDbIntArray&  osnapModes,
        ZcDbIntArray&  geomIds) const override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subMoveGripPointsAt(const ZcDbIntArray& indices,	 
        const ZcGeVector3d& offset) override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subGetStretchPoints(ZcGePoint3dArray& stretchPoints) const override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus subMoveStretchPointsAt( const ZcDbIntArray& indices,		
        const ZcGeVector3d& offset) override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus   subTransformBy(const ZcGeMatrix3d& xform) override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus	subGetGeomExtents(ZcDbExtents& extents) const override;

    ZCMPOLYGON_PORT virtual void              subList() const override;
    
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus   subExplode( ZcDbVoidPtrArray& entitySet) const override;

    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* filer) override;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* filer) const override;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* filer) override;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* filer) const override;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus audit(ZcDbAuditInfo* ) override;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus decomposeForSave(ZcDb::ZcDbDwgVersion ver,
        ZcDbObject*& replaceObj, ZcDbObjectId& replaceId, 
        ZSoft::Boolean& exchangeXData) override;
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus createLoopsFromBoundaries (const ZcDbObjectIdArray &ids,
        ZcDbIntArray &rejectedObjs,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);
    ZCMPOLYGON_PORT virtual Zcad::ErrorStatus createLoops (const ZcArray<ZcGePoint2dArray,ZcArrayObjectCopyReallocator<ZcGePoint2dArray> > &vertices,
        const ZcArray<ZcGeDoubleArray,ZcArrayObjectCopyReallocator<ZcGeDoubleArray> > &bulges, ZcDbIntArray &rejectedObjs,
        bool excludeCrossing = true, double tol = ZcDbMPolygonCrossingFuzz);

private:
    friend class ZcDbImpMPolygon;
    void* pImp;
};

class ZcDbMpolygonLoops {
public:
    ZcDbMpolygonLoops(int lindex, int gindex = 0, int gcnt = 0);

    int mLoopIndex;                   
    bool mIsText;                     
    int mGripIndex;                   
    int mGripCount;                   
    ZcGePoint2dArray mVertexPoints;    
    ZcGeDoubleArray mVertexBulges;
};

inline
ZcDbMpolygonLoops::ZcDbMpolygonLoops(int lindex, int gindex, int gcnt)
{
    mLoopIndex = lindex;
    mGripIndex = gindex;
    mGripCount = gcnt;
}

class ZCMPOLYGON_PORT ZcDbMPolygonCrossing {
public:
     ZcDbMPolygonCrossing();
    ~ZcDbMPolygonCrossing();

    int getLoopIndex() const;         
    void setLoopIndex(int index);
    
    int getEdgeIndex() const;         
    void setEdgeIndex(int index);

    ZcGePoint2d getCrossingPoint() const; 
    void setCrossingPoint(const ZcGePoint2d& pt);

private:
    void* pImp;
};

class ZcDbMPolygonCrossingArray {
public:
    ~ZcDbMPolygonCrossingArray();

    ZcArray<ZcDbMPolygonCrossing *> mCrossingArray;
};

inline
ZcDbMPolygonCrossingArray::~ZcDbMPolygonCrossingArray()
{
    ZcDbMPolygonCrossing* pCrossing;
    int numCross = mCrossingArray.length();
    for (int i = numCross - 1; i >= 0; i--) {
        pCrossing = mCrossingArray[i];
        mCrossingArray.removeAt(i);
        if (pCrossing != NULL)
            delete pCrossing;
    }
}

class ZcDbMPolygonNode {
public:
    
    ZcDbMPolygonNode();

public:
    ZcDbMPolygonNode * mParent;
    ZcArray<ZcDbMPolygonNode*> mChildren;
    int mLoopIndex;                   
};

inline
ZcDbMPolygonNode::ZcDbMPolygonNode()
    : mLoopIndex(-1), mParent(NULL)
{
}



