/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#undef GCAD_OBJID_INLINE_INTERNAL
#include "dbhatch.h"
#if defined(WIN32) || defined(WIN64)
#include <tchar.h>
#endif

class GcDbCircle;
class GcDb2dPolyline;
class GcDbPolyline;
class GcDbMPolygonCrossingArray;
class GcDbMPolygonNode;

const double GcDbMPolygonCrossingFuzz = 1E-6;

class GCDB_PORT GcDbMPolygon : public GcDbEntity {
public:
  enum loopDir {
    kExterior = 0,
    kInterior,
    kAnnotation
  };

  GcDbMPolygon();
  ~GcDbMPolygon();
  GCDB_DECLARE_MEMBERS(GcDbMPolygon);

  virtual GcDbHatch * hatch();
  virtual double elevation() const;
  virtual Gcad::ErrorStatus setElevation(double elevation);

  virtual GcGeVector3d normal() const;
  virtual Gcad::ErrorStatus setNormal(const GcGeVector3d& normal);

  virtual Gcad::ErrorStatus  evaluateHatch(bool bUnderestimateNumLines = false);
  virtual GcDbHatch::HatchPatternType patternType() const;
  virtual const TCHAR* patternName() const;
  virtual Gcad::ErrorStatus  setPattern(GcDbHatch::HatchPatternType patType, const TCHAR* patName);

  virtual double patternAngle() const;
  virtual Gcad::ErrorStatus setPatternAngle(double angle);

  virtual double patternSpace() const;
  virtual Gcad::ErrorStatus setPatternSpace(double space);

  virtual double patternScale() const;
  virtual Gcad::ErrorStatus setPatternScale(double scale);

  virtual bool patternDouble() const;
  virtual Gcad::ErrorStatus setPatternDouble(bool isDouble);

  virtual int numPatternDefinitions() const;
  virtual Gcad::ErrorStatus  getPatternDefinitionAt(int index,
    double& angle,
    double& baseX,
    double& baseY,
    double& offsetX,
    double& offsetY,
    GcGeDoubleArray& dashes)
    const;

  Gcad::ErrorStatus setGradientAngle(double angle);
  Gcad::ErrorStatus setGradientShift(float shiftValue);
  Gcad::ErrorStatus setGradientOneColorMode(Gsoft::Boolean oneColorMode);
  Gcad::ErrorStatus setGradientColors(unsigned int count,
    GcCmColor* colors,
    float* values);
  Gcad::ErrorStatus setGradient(GcDbHatch::GradientPatternType gradType, const TCHAR* gradName);

  virtual GcCmColor patternColor() const;
  virtual Gcad::ErrorStatus setPatternColor(const GcCmColor& pc);

  virtual double getArea() const;
  virtual double getPerimeter() const;
  virtual bool isBalanced() const;
  virtual GcGeVector2d getOffsetVector() const;

  virtual Gcad::ErrorStatus getMPolygonTree(GcDbMPolygonNode*& loopNode) const;
  virtual void deleteMPolygonTree(GcDbMPolygonNode* loopNode) const;

  virtual Gcad::ErrorStatus appendLoopFromBoundary(const GcDbCircle* pCircle,
    bool excludeCrossing = true, double tol = GcDbMPolygonCrossingFuzz);
  virtual Gcad::ErrorStatus appendLoopFromBoundary(const GcDbPolyline* pPoly,
    bool excludeCrossing = true, double tol = GcDbMPolygonCrossingFuzz);
  virtual Gcad::ErrorStatus appendLoopFromBoundary(const GcDb2dPolyline* pPoly,
    bool excludeCrossing = true, double tol = GcDbMPolygonCrossingFuzz);

  virtual int numMPolygonLoops() const;
  virtual Gcad::ErrorStatus getMPolygonLoopAt(int loopIndex, GcGePoint2dArray& vertices,
    GcGeDoubleArray& bulges) const;
  virtual Gcad::ErrorStatus insertMPolygonLoopAt(int loopIndex,
    const GcGePoint2dArray& vertices, const GcGeDoubleArray& bulges,
    bool excludeCrossing = true, double tol = GcDbMPolygonCrossingFuzz);
  virtual Gcad::ErrorStatus appendMPolygonLoop(const GcGePoint2dArray& vertices,
    const GcGeDoubleArray& bulges, bool excludeCrossing = true,
    double tol = GcDbMPolygonCrossingFuzz);
  virtual Gcad::ErrorStatus removeMPolygonLoopAt(int loopIndex);
  virtual Gcad::ErrorStatus balanceTree();
  virtual Gcad::ErrorStatus balanceDisplay();

  virtual Gcad::ErrorStatus getLoopDirection(int lindex, GcDbMPolygon::loopDir& dir) const;
  virtual Gcad::ErrorStatus setLoopDirection(int lindex, GcDbMPolygon::loopDir dir);

  virtual Gcad::ErrorStatus getLoopAtGsMarker(int gsMark, int &loop) const;
  virtual void getChildLoops(int curLoop, GcGeIntArray& selectedLoopIndexes) const;
  virtual int  getParentLoop(int curLoop) const;
  virtual int  getClosestLoopTo(const GcGePoint3d& worldPt) const;
  virtual int  isPointInsideMPolygon(const GcGePoint3d& worldPt, GcGeIntArray& loopsArray,
    double tol = GcDbMPolygonCrossingFuzz) const;
  virtual bool isPointOnLoopBoundary(const GcGePoint3d& worldPt, int loop,
    double tol = GcDbMPolygonCrossingFuzz) const;

  virtual Gcad::ErrorStatus loopCrossesItself(bool& crosses, bool findAll,
    GcDbMPolygonCrossingArray& crossingsArray,
    const GcGePoint2dArray& vertexPts,
    const GcGeDoubleArray& vertexBulges,
    double tol = GcDbMPolygonCrossingFuzz) const;
  virtual bool loopCrossesItself(const GcGePoint2dArray& vertexPts,
    const GcGeDoubleArray& vertexBulges,
    double tol = GcDbMPolygonCrossingFuzz) const;
  virtual Gcad::ErrorStatus loopCrossesMPolygon(bool& crosses, bool findAll,
    GcDbMPolygonCrossingArray& crossingsArray,
    const GcGePoint2dArray& testVertexPts,
    const GcGeDoubleArray& testVertexBulges,
    double tol = GcDbMPolygonCrossingFuzz) const;
  virtual bool selfCrosses(const GcGePoint2dArray& vertexPts,
    const GcGeDoubleArray& vertexBulges,
    double tol = GcDbMPolygonCrossingFuzz) const;
  virtual bool includesTouchingLoops(double tol = GcDbMPolygonCrossingFuzz) const;
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
  Gsoft::Boolean    subWorldDraw(GcGiWorldDraw*  mode) override;
  void              saveAs(GcGiWorldDraw* mode, GcDb::SaveType st) override;
  Gcad::ErrorStatus subGetSubentPathsAtGsMarker(
    GcDb::SubentType      type,
    Gsoft::GsMarker       gsMark,
    const GcGePoint3d&    pickPoint,
    const GcGeMatrix3d&   viewXform,
    int&                  numPaths,
    GcDbFullSubentPath*&  subentPaths,
    int                   numInserts = 0,
    GcDbObjectId*         entAndInsertStack
    = NULL) const override;
  Gcad::ErrorStatus subGetGsMarkersAtSubentPath(
    const GcDbFullSubentPath& subPath,
    GcArray<Gsoft::GsMarker>&         gsMarkers) const override;
  GcDbEntity* subSubentPtr(const GcDbFullSubentPath& id) const override;
  Gcad::ErrorStatus   subIntersectWith(
    const GcDbEntity*   ent,
    GcDb::Intersect     intType,
    GcGePoint3dArray&   points,
    Gsoft::GsMarker     thisGsMarker = 0,
    Gsoft::GsMarker     otherGsMarker = 0)
    const override;
  Gcad::ErrorStatus   subIntersectWith(
    const GcDbEntity*   ent,
    GcDb::Intersect     intType,
    const GcGePlane&    projPlane,
    GcGePoint3dArray&   points,
    Gsoft::GsMarker     thisGsMarker = 0,
    Gsoft::GsMarker     otherGsMarker = 0)
    const override;
  Gcad::ErrorStatus   subGetOsnapPoints(
    GcDb::OsnapMode       osnapMode,
    Gsoft::GsMarker       gsSelectionMark,
    const GcGePoint3d&    pickPoint,
    const GcGePoint3d&    lastPoint,
    const GcGeMatrix3d&   viewXform,
    GcGePoint3dArray&        snapPoints,
    GcDbIntArray&     geomIds) const override;
  Gcad::ErrorStatus subGetGripPoints(GcGePoint3dArray&     gripPoints,
    GcDbIntArray&  osnapModes,
    GcDbIntArray&  geomIds) const override;
  Gcad::ErrorStatus subMoveGripPointsAt(const GcDbIntArray& indices,
    const GcGeVector3d& offset) override;
  Gcad::ErrorStatus subGetStretchPoints(GcGePoint3dArray& stretchPoints) const override;
  Gcad::ErrorStatus subMoveStretchPointsAt(const GcDbIntArray& indices,
    const GcGeVector3d& offset) override;

  Gcad::ErrorStatus   subTransformBy(const GcGeMatrix3d& xform) override;
  Gcad::ErrorStatus   subGetGeomExtents(GcDbExtents& extents) const override;
  void                subList() const override;
  Gcad::ErrorStatus   subExplode(GcDbVoidPtrArray& entitySet) const override;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;
  Gcad::ErrorStatus audit(GcDbAuditInfo*) override;
  Gcad::ErrorStatus decomposeForSave(GcDb::GcDbDwgVersion ver,
    GcDbObject*& replaceObj, GcDbObjectId& replaceId,
    Gsoft::Boolean& exchangeXData) override;

  virtual Gcad::ErrorStatus createLoopsFromBoundaries(const GcDbObjectIdArray &ids,
    GcDbIntArray &rejectedObjs,
    bool excludeCrossing = true, double tol = GcDbMPolygonCrossingFuzz);
  virtual Gcad::ErrorStatus createLoops(const GcArray<GcGePoint2dArray, GcArrayObjectCopyReallocator<GcGePoint2dArray> > &vertices,
    const GcArray<GcGeDoubleArray, GcArrayObjectCopyReallocator<GcGeDoubleArray> > &bulges, GcDbIntArray &rejectedObjs,
    bool excludeCrossing = true, double tol = GcDbMPolygonCrossingFuzz);

private:
  friend class GcDbImpMPolygon;
  void* pImp;
};

class GcDbMpolygonLoops {
public:
  GcDbMpolygonLoops(int lindex, int gindex = 0, int gcnt = 0);

  int mLoopIndex;
  bool mIsText;
  int mGripIndex;
  int mGripCount;
  GcGePoint2dArray mVertexPoints;
  GcGeDoubleArray mVertexBulges;
};

inline
GcDbMpolygonLoops::GcDbMpolygonLoops(int lindex, int gindex, int gcnt)
{
  mLoopIndex = lindex;
  mGripIndex = gindex;
  mGripCount = gcnt;
}

class GCDB_PORT GcDbMPolygonCrossing {
public:
  GcDbMPolygonCrossing();
  ~GcDbMPolygonCrossing();

  int getLoopIndex() const;
  void setLoopIndex(int index);

  int getEdgeIndex() const;
  void setEdgeIndex(int index);

  GcGePoint2d getCrossingPoint() const;
  void setCrossingPoint(const GcGePoint2d& pt);

private:
  void* pImp;
};

class GcDbMPolygonCrossingArray {
public:
  ~GcDbMPolygonCrossingArray();
  GcArray<GcDbMPolygonCrossing *> mCrossingArray;
};

inline
GcDbMPolygonCrossingArray::~GcDbMPolygonCrossingArray()
{
  GcDbMPolygonCrossing* pCrossing;
  int numCross = mCrossingArray.length();
  for (int i = numCross - 1; i >= 0; i--) {
    pCrossing = mCrossingArray[i];
    mCrossingArray.removeAt(i);
    if (pCrossing != NULL)
      delete pCrossing;
  }
}

class GcDbMPolygonNode {
public:
  GcDbMPolygonNode();

public:
  GcDbMPolygonNode * mParent;
  GcArray<GcDbMPolygonNode*> mChildren;
  int mLoopIndex;
};

inline
GcDbMPolygonNode::GcDbMPolygonNode()
  : mLoopIndex(-1), mParent(NULL)
{
}