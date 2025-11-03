/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////

#ifndef _DBMPOLYGON_H_INCLUDED_
#define _DBMPOLYGON_H_INCLUDED_

#include "DbHatch.h"

class OdDbCircle;
class OdDb2dPolyline;
class OdDbPolyline;
class OdDbMPolygonCrossing;
typedef OdArray<OdDbMPolygonCrossing,OdPlainObjectsAllocator<OdDbMPolygonCrossing> > OdDbMPolygonCrossingArray;
class OdDbMPolygonNode;

const double OdDbMPolygonCrossingFuzz = 1E-6;

/** Description:
    This class processes one or more closed polygons as a single polygon.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/class TOOLKIT_EXPORT OdDbMPolygon : public OdDbEntity 
{
public:
  OdDbMPolygon();
  virtual ~OdDbMPolygon();

  ODDB_DECLARE_MEMBERS(OdDbMPolygon);

  virtual OdDbHatch * hatch();

  virtual double elevation() const;
  virtual OdResult setElevation(double elevation);

  virtual OdGeVector3d normal() const;
  virtual OdResult setNormal(const OdGeVector3d& normal);

  virtual OdResult evaluateHatch(bool bUnderestimateNumLines = false);

  virtual OdDbHatch::HatchPatternType patternType() const;

  virtual const OdChar * patternName() const;

  virtual OdResult setPattern(OdDbHatch::HatchPatternType patType,
    const OdChar* patName);

  virtual double patternAngle() const;
  virtual OdResult setPatternAngle(double angle);

  virtual double patternSpace() const;
  virtual OdResult setPatternSpace(double space);

  virtual double patternScale() const;
  virtual OdResult setPatternScale(double scale);

  virtual bool patternDouble() const;
  virtual OdResult setPatternDouble(bool isDouble);

  virtual int numPatternDefinitions() const;
  virtual OdResult getPatternDefinitionAt(int index, 
    double& angle,
    double& baseX,
    double& baseY,
    double& offsetX,
    double& offsetY,
    OdGeDoubleArray& dashes)
    const;

  //Gcad(Modify):returns:void->OdResult
  OdResult setGradientAngle(double angle);
  OdResult setGradientShift( float shiftValue );
  OdResult setGradientOneColorMode( OdBool oneColorMode );
  OdResult setGradientColors( unsigned int count, 
    OdCmColor* colors,
    float* values );
  OdResult setGradient(OdDbHatch::GradientPatternType gradType,
    const OdChar * gradName);


  virtual OdCmColor patternColor() const;
  //Gcad(Modify):returns:void->OdResult
  virtual OdResult setPatternColor(const OdCmColor& pc);

  /**
    Description:
    Returns the *area* of this entity.

    Arguments:
    area (O) Receives the *area*.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult getArea(double& area) const;

  virtual double getArea() const;

  virtual double getPerimeter() const;

  virtual bool isBalanced() const;
  

  virtual OdGeVector2d getOffsetVector() const;

  virtual OdResult getMPolygonTree(OdDbMPolygonNode*& loopNode) const;
  virtual void deleteMPolygonTree(OdDbMPolygonNode* loopNode) const;

  virtual OdResult appendLoopFromBoundary(const OdDbCircle* pCircle,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  virtual OdResult appendLoopFromBoundary(const OdDbPolyline* pPoly,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  virtual OdResult appendLoopFromBoundary(const OdDb2dPolyline* pPoly,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);

  virtual OdResult getLoopAtGsMarker(int gsMark, int &loop) const;
  virtual void getChildLoops(int curLoop, OdGeIntArray& selectedLoopIndexes) const;
  virtual int getParentLoop(int curLoop) const;
  virtual int getClosestLoopTo(const OdGePoint3d& worldPt) const;

  virtual OdResult loopCrossesItself(bool& crosses, bool findAll,
    OdDbMPolygonCrossingArray& crossingsArray,
    const OdGePoint2dArray& vertexPts,
    const OdGeDoubleArray& vertexBulges,
    double tol = OdDbMPolygonCrossingFuzz) const;
  virtual bool loopCrossesItself(const OdGePoint2dArray& vertexPts,
    const OdGeDoubleArray& vertexBulges,
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual OdResult loopCrossesMPolygon(bool& crosses, bool findAll,
    OdDbMPolygonCrossingArray& crossingsArray,
    const OdGePoint2dArray& testVertexPts,
    const OdGeDoubleArray& testVertexBulges,
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual bool selfCrosses(const OdGePoint2dArray& vertexPts,
    const OdGeDoubleArray& vertexBulges,
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual bool includesTouchingLoops(double tol = OdDbMPolygonCrossingFuzz) const;
  
  virtual OdResult subGetClassID(CLSID* pClsid) const;

  /* Not implemented
  virtual OdResult getMPolygonTree(OdDbMPolygonNode*& loopNode) const;
  virtual void deleteMPolygonTree(OdDbMPolygonNode* loopNode) const;

  virtual OdResult appendLoopFromBoundary(const OdDbCircle* pCircle,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  virtual OdResult appendLoopFromBoundary(const OdDbPolyline* pPoly,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  virtual OdResult appendLoopFromBoundary(const OdDb2dPolyline* pPoly,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  */

  virtual int numMPolygonLoops() const;
  virtual OdResult getMPolygonLoopAt(int loopIndex, OdGePoint2dArray& vertices,
    OdGeDoubleArray& bulges) const;

  virtual OdResult appendMPolygonLoop(const OdGePoint2dArray& vertices, 
    const OdGeDoubleArray& bulges, bool excludeCrossing = true,
    double tol = OdDbMPolygonCrossingFuzz);

 
  virtual OdResult insertMPolygonLoopAt(int loopIndex, 
    const OdGePoint2dArray& vertices, const OdGeDoubleArray& bulges, 
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);

  virtual OdResult removeMPolygonLoopAt(int loopIndex);
  
  virtual OdResult balanceTree();
  virtual OdResult balanceDisplay();
  
  enum loopDir {
  kExterior = 0,
  kInterior,
  kAnnotation
  };
  virtual OdResult getLoopDirection(int lindex, OdDbMPolygon::loopDir& dir) const;
  virtual OdResult setLoopDirection(int lindex, OdDbMPolygon::loopDir dir);
  /*
  //virtual OdResult getLoopAtGsMarker(OdGsMarker gsMark, int &loop) const;
  virtual void getChildLoops(int curLoop, OdGeIntArray& selectedLoopIndexes) const;
  virtual int getParentLoop(int curLoop) const;
  virtual int getClosestLoopTo(const OdGePoint3d& worldPt) const;
  */
  // Mpolyon loop crossing and inside methods.
  //
  virtual int isPointInsideMPolygon(const OdGePoint3d& worldPt, OdGeIntArray& loopsArray,
    double tol = OdDbMPolygonCrossingFuzz) const;

 
  virtual bool isPointOnLoopBoundary(const OdGePoint3d& worldPt, int loop, 
    double tol = OdDbMPolygonCrossingFuzz) const;
 /*/
  virtual OdResult loopCrossesItself(bool& crosses, bool findAll,
    OdDbMPolygonCrossingArray& crossingsArray,
    const OdGePoint2dArray& vertexPts, 
    const OdGeDoubleArray& vertexBulges, 
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual bool loopCrossesItself(const OdGePoint2dArray& vertexPts, 
    const OdGeDoubleArray& vertexBulges, 
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual OdResult loopCrossesMPolygon(bool& crosses, bool findAll,
    OdDbMPolygonCrossingArray& crossingsArray,
    const OdGePoint2dArray& testVertexPts, 
    const OdGeDoubleArray& testVertexBulges, 
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual bool selfCrosses(const OdGePoint2dArray& vertexPts, 
    const OdGeDoubleArray& vertexBulges,
    double tol = OdDbMPolygonCrossingFuzz) const;

  virtual bool includesTouchingLoops(double tol = OdDbMPolygonCrossingFuzz) const;

  //virtual OdResult subGetClassID(CLSID* pClsid) const;

  virtual OdResult   intersectWith(
    const OdDbEntity*   ent,
    OdDb::Intersect     intType,
    OdGePoint3dArray&   points,
    OdGsMarker            thisGsMarker  = 0,
    OdGsMarker            otherGsMarker = 0)
    const;

  virtual OdResult   intersectWith(
    const OdDbEntity*   ent,
    OdDb::Intersect     intType,
    const OdGePlane&    projPlane,
    OdGePoint3dArray&   points,
    OdGsMarker            thisGsMarker  = 0,
    OdGsMarker            otherGsMarker = 0)
    const;

  virtual OdResult   getOsnapPoints(
    OdDb::OsnapMode       osnapMode,
    OdGsMarker              gsSelectionMark,
    const OdGePoint3d&    pickPoint,
    const OdGePoint3d&    lastPoint,
    const OdGeMatrix3d&   viewXform,
    OdGePoint3dArray&        snapPoints,
    OdDbIntArray&     geomIds) const;

  virtual OdResult getGripPoints(OdGePoint3dArray&     gripPoints,
    OdDbIntArray&  osnapModes,
    OdDbIntArray&  geomIds) const;

  virtual OdResult moveGripPointsAt(const OdDbIntArray& indices,
    const OdGeVector3d& offset);

  virtual OdResult getStretchPoints(OdGePoint3dArray& stretchPoints) const;

  virtual OdResult moveStretchPointsAt( const OdDbIntArray& indices,
    const OdGeVector3d& offset);

  virtual OdResult createLoopsFromBoundaries (const OdDbObjectIdArray &ids,
    OdIntArray &rejectedObjs,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  
  virtual OdResult createLoops (const OdGePoint2dArrayArray &vertices,
    const OdArray<OdGeDoubleArray> &bulges, OdIntArray &rejectedObjs,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  */
  ////////////////////////
  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  virtual OdResult subTransformBy( 
    const OdGeMatrix3d& xfn );

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual void subSetDatabaseDefaults(OdDbDatabase* pDb);

  virtual void saveAs(
    OdGiWorldDraw* pWd,
    OdDb::SaveType ver );

  virtual OdResult subGetSubentPathsAtGsMarker(
    OdDb::SubentType      type,
    OdGsMarker       gsMark,
    const OdGePoint3d&    pickPoint,
    const OdGeMatrix3d&   viewXform,
    int&                  numPaths,
    OdDbFullSubentPath*&  subentPaths,
    int                   numInserts = 0,
    OdDbObjectId*         entAndInsertStack
    = NULL) const;

  virtual OdResult subGetGsMarkersAtSubentPath(
    const OdDbFullSubentPath& subPath,
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& id) const;

  virtual OdResult subIntersectWith(
    const OdDbEntity*   ent,
    OdDb::Intersect     intType,
    OdGePoint3dArray&   points,
    OdGsMarker     thisGsMarker = 0,
    OdGsMarker     otherGsMarker = 0)
    const;

  virtual OdResult subIntersectWith(
    const OdDbEntity*   ent,
    OdDb::Intersect     intType,
    const OdGePlane&    projPlane,
    OdGePoint3dArray&   points,
    OdGsMarker     thisGsMarker = 0,
    OdGsMarker     otherGsMarker = 0)
    const;

  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode       osnapMode,
    OdGsMarker       gsSelectionMark,
    const OdGePoint3d&    pickPoint,
    const OdGePoint3d&    lastPoint,
    const OdGeMatrix3d&   viewXform,
    OdGePoint3dArray&     snapPoints,
    OdDbIntArray&         geomIds) const;

  virtual OdResult subGetGripPoints(OdGePoint3dArray&     gripPoints,
    OdDbIntArray&  osnapModes,
    OdDbIntArray&  geomIds) const;

  virtual OdResult subMoveGripPointsAt(const OdDbIntArray& indices,
    const OdGeVector3d& offset);

  virtual OdResult subGetStretchPoints(OdGePoint3dArray& stretchPoints) const;

  virtual OdResult subMoveStretchPointsAt(const OdDbIntArray& indices,
    const OdGeVector3d& offset);

  virtual OdResult	subGetGeomExtents(OdDbExtents& extents) const;

  virtual void subList() const;
  virtual OdResult audit(OdDbAuditInfo*);
  virtual OdResult decomposeForSave(OdDb::DwgVersion ver,
    OdDbObject*& replaceObj, OdDbObjectId& replaceId,
    OdBool& exchangeXData);
  virtual OdResult createLoopsFromBoundaries(const OdDbObjectIdArray &ids,
    OdDbIntArray &rejectedObjs,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);
  virtual OdResult createLoops(const OdArray<OdGePoint2dArray, OdObjectsAllocator<OdGePoint2dArray> > &vertices,
    const OdArray<OdGeDoubleArray, OdObjectsAllocator<OdGeDoubleArray> > &bulges, OdDbIntArray &rejectedObjs,
    bool excludeCrossing = true, double tol = OdDbMPolygonCrossingFuzz);

};

typedef OdSmartPtr<OdDbMPolygon> OdDbMPolygonPtr;

#endif // _DBMPOLYGON_H_INCLUDED_
