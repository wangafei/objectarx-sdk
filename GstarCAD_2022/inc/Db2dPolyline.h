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




#ifndef _OD_DB_2DPOLYLINE_
#define _OD_DB_2DPOLYLINE_

#include "TD_PackPush.h"

#include "DbCurve.h"
#include "DbObjectIterator.h"
#include "Db2dVertex.h"
#include "OdDb.h"

class OdGePoint3d;
class OdDbSequenceEnd;
template <class T> class OdSmartPtr;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSequenceEnd object pointers.
*/
typedef OdSmartPtr<OdDbSequenceEnd> OdDbSequenceEndPtr;

/** Description: 
  
    {group:TD_Namespaces}
*/

/** Description:
    This class represents 2D Polyline entities in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDb2dPolyline: public OdDbCurve
{
public:

  ODDB_DECLARE_MEMBERS(OdDb2dPolyline);

  OdDb2dPolyline();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDb2dPolyline (
        OdDb::Poly2dType  type,
        OdGePoint3dArray& vertices,
        double            elevation     = 0,
        OdBool            closed = kFalse,
        double            defStartWidth = 0,
        double            defEndWidth   = 0,
        OdGeDoubleArray*  bulges        = NULL);

  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDb2dPolyline();

  OdResult setColor(
    const OdCmColor &color, 
    bool doSubents = false);

  OdResult setColorIndex(
    OdUInt16 colorIndex, 
    bool doSubents = false);

  OdResult setTransparency(
    const OdCmTransparency& transparency, 
    bool doSubents = true);
  
  /** Description:
    Returns the type of this Polyline entity. 
    
    Remarks:
    polyType() returns one of the following:
    
    @table
    Name                        Value   Description
    OdDb::k2dSimplePoly         0       Simple polyline.
    OdDb::k2dFitCurvePoly       1       Curve fit (DXF 70, bit 0x04).
    OdDb::k2dQuadSplinePoly     2       Quadratic B-spline fit (DXF 80, bit 0x08; DXF 75 == 5).
    OdDb::k2dCubicSplinePoly    3       Cubic B-spline-fit (DXF 80, bit 0x08; DXF 75 == 6).
  */
  OdDb::Poly2dType polyType() const;

  /** Description:
    Sets the type of this Polyline entity. 
      
    Arguments:
    polyType (I) Polyline type.
    
    Remarks:
    polyType must be one of the following:
    
    @table
    Name                        Value   Description
    OdDb::k2dSimplePoly         0       Simple polyline.
    OdDb::k2dFitCurvePoly       1       Curve fit (DXF 70, bit 0x04).
    OdDb::k2dQuadSplinePoly     2       Quadratic B-spline fit (DXF 80, bit 0x08; DXF 75 == 5).
    OdDb::k2dCubicSplinePoly    3       Cubic B-spline-fit (DXF 80, bit 0x08; DXF 75 == 6).
	
	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setPolyType(
    OdDb::Poly2dType polyType);

  /** 
  Gcad(Add):增加兼容接口	
  */
  OdResult   convertToPolyType(OdDb::Poly2dType newVal);

  /** Description:
    Sets this Polyline entity closed (DXF 70, bit 0x01=1).

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult makeClosed();

  /** Description:
    Sets this Polyline entity open (DXF 70, bit 0x01=0).

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult makeOpen();

  /** Description:
    Returns the default segment start width for this Polyline entity (DXF 40).
  */
  double defaultStartWidth() const;

  /** Description:
    Sets the default segment start width for this Polyline entity (DXF 40).
    Arguments:
    defaultStartWidth (I) Default start width.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setDefaultStartWidth(
    double defaultStartWidth);

  /** Description:
    Returns the default segment end width for this Polyline entity (DXF 41).
  */
  double defaultEndWidth() const;

  /** Description:
    Sets the default segment end width for this Polyline entity (DXF 41).
    Arguments:
    defaultEndWidth (I) Default end width.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setDefaultEndWidth(
    double defaultEndWidth);

  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;
  
  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setThickness(
    double thickness);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  /** Description:
    Returns the *elevation* of this entity in the OCS (DXF 30).
    
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.
  */
  double elevation() const;

  /** Description:
    Sets the *elevation* of this entity in the OCS (DXF 30).

    Arguments:
    elevation (I) Elevation.    

    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setElevation(
    double elevation);

  /** Description:
    Returns true if and only if *linetype* generation is on for this Polyline entity (DXF 70, bit 0x80).
      
    Remarks:
    Linetype generation on indicates that the *linetype* pattern of this Polyline entity
    is continuously generated around all vertices, rather than being restarted at each vertex.
  */
  OdBool isLinetypeGenerationOn() const;

  /** Description:
    Sets the *linetype* generation on for this Polyline entity (DXF 70, bit 0x80).
      
    Remarks:
    Linetype generation on indicates that the *linetype* pattern of this Polyline entity
    is continuously generated around all vertices, rather than being restarted at each vertex.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setLinetypeGenerationOn();

  /** Description:
    Sets the *linetype* generation off for this Polyline entity (DXF 70, bit 0x80).
      
    Remarks:
    Linetype generation off indicates that the *linetype* pattern of this Polyline entity is
    restarted at each vertex, rather than being continuously generated around all vertices.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setLinetypeGenerationOff();

  /** Description:
    Removes all curve and spline fitting from this Polyline entity.
  
    Remarks:
    Removes all but the simple vertices.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult straighten();

  bool isLocked() const;
  void lock(bool blLock);

  /** Description:
    Appends the specified Vertex entity to this Polyline entity, and makes this Polyline entity its owner.
    
    Remarks:
    Returns the Object ID of the appended vertex.
    
    If this Polyline entity is *database* resident, the Vertex entity will be made *database* resident. 
    
    If this Polyline entity is not *database* resident, the Vertex entity will be made *database* resident
    when this Polyline entity is made *database* resident.
    
    Note:
    If this Polyline is *database* resident, the Vertex entity must explicitly be closed when
    appendVertex() returns.
    
    Arguments:
    pVertex (I) Pointer to the Vertex entity to be appended.

	Gcad(Internal):接口跟arx冲突
  */
  OdDbObjectId appendVertex(
	ODSYSDEF,
    OdDb2dVertex* pVertex);
 
  /**
	Remarks:
    Returns eOk if successful

    Arguments:
	pVertex (I) Pointer to the Vertex entity to be appended.

	Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult appendVertex(OdDb2dVertex*);
#endif

  /**
  Arguments:
	objId (O) Returns the Object ID of the appended vertex.
    
	Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult appendVertex(OdDbObjectId& objId, OdDb2dVertex*);
#endif
  /** Description:
    Inserts the specified Vertex entity into this Polyline entity
    after the specified vertex, and makes this Polyline its owner.
    
    Remarks:
    Returns the Object ID of the newly inserted vertex.
    
    The Vertex will be made *database* resident. 
    
    If this Polyline entity is not *database* resident, the vertex will be made *database* resident
    when the polyline is made *database* resident.
    
    To insert the specified Vertex at the start of this Polyline, use a null indexVertexId.
    
    Note:
    The Vertex entity must explicitly be closed when insertertex() returns.

    Arguments:
    indexVertId (I) Object ID of vertex after which to insert the specified vertex.
    pVertex (I) Pointer to the Vertex entity to be inserted.

  */
  OdDbObjectId insertVertexAt(
    const OdDbObjectId& indexVertId, 
    OdDb2dVertex* pVertex);

  /**
    Arguments:
    pIndexVert (I) Pointer to vertex after which to insert the specified vertex.

	Gcad(Internal):接口跟arx冲突
  */
  OdDbObjectId insertVertexAt(
	ODSYSDEF,
    const OdDb2dVertex* pIndexVert, 
    OdDb2dVertex* pVertex);

  /**
	Remarks:
    Returns eOk if successful

	Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult insertVertexAt(const OdDb2dVertex* pIndexVert,
        OdDb2dVertex* pNewVertex); 
#endif
  /**
	Remarks:
    Returns eOk if successful

	Arguments:
	newVertId (O) Returns the Object ID of the newly inserted vertex.

	Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult insertVertexAt(OdDbObjectId& newVertId,
        const OdDbObjectId& indexVertId, OdDb2dVertex* pNewVertex);
#endif
  /** Description:
    Opens a vertex owned by this Polyline entity.

    Arguments:
    vertId (I) Object ID of vertex to be opened.
    mode (I) Mode in which to open the vertex.
    openErasedOne (I) If and only if true, *erased* objects will be opened.

    Remarks:
    Returns a SmartPointer to the opened object if successful, otherwise a null SmartPointer.
  */
  OdDb2dVertexPtr openVertex(
    OdDbObjectId vertId, 
    OdDb::OpenMode mode, 
    bool openErasedOne = false);

  /**
	Remarks:
    Returns eOk if successful

	Arguments:
	OdDb2dVertex*& (O) Returns a Pointer to the opened object

	Gcad(Add):增加兼容接口
  */
  OdResult openVertex(OdDb2dVertex*&,
					  OdDbObjectId vertId,
					  OdDb::OpenMode,
					  bool openErasedOne = false) const;
 
  /** Description:
    Opens the OdDbSequenceEnd entity for this Polyline entity.

    Arguments:
    mode (I) Mode in which to open the OdDbSequenceEnd entity.

    Remarks:
    Returns a SmartPointer to the newly opened OdDbSequenceEnd, or a null SmartPointer.

    Note:
    This method is provided solely for applications that store XData on
    OdDbSequenceEnd entities; this is not recommended. 
  */
  OdDbSequenceEndPtr openSequenceEnd(
    OdDb::OpenMode mode);

  /**
	Remarks:
    Returns eOk if successful

	Arguments:
	OdDbSequenceEnd*& (O) Returns a Pointer to the newly opened OdDbSequenceEnd,

	Gcad(Add):增加兼容接口
  */
  OdResult openSequenceEnd(OdDbSequenceEnd*&, OdDb::OpenMode);
  /** Description:
    Returns an Iterator that can be used to traverse the vertices owned 
    by this Polyline entity.

	Gcad(Internal):接口冲突
  */
  OdDbObjectIteratorPtr vertexIterator(ODSYSDEF) const;

  /**
	Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdDbObjectIterator*  vertexIterator() const;
#endif
  /** Description:
    Returns the WCS position of the specified Vertex entity.
    
    Arguments:
    vertex (I) Vertex.
  */
  OdGePoint3d vertexPosition(
    const OdDb2dVertex& vertex) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult subClose();

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const ODRX_OVERRIDE;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const ODRX_OVERRIDE;

  virtual OdBool isPlanar() const;

  virtual OdResult getArea(
    double& area) const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual void    getEcs(OdGeMatrix3d& retVal) const;


  // OdDbCurveMethods

  virtual OdBool isClosed() const;

  virtual OdBool isPeriodic() const;

  virtual OdResult getStartParam(
    double& startParam) const;

  virtual OdResult getEndParam (
    double& endParam) const;

  virtual OdResult getStartPoint(
    OdGePoint3d& startPoint) const;

  virtual OdResult getEndPoint(
    OdGePoint3d& endPoint) const;

  virtual OdResult getPointAtParam(
    double param, 
    OdGePoint3d& pointOnCurve) const;

  virtual OdResult getParamAtPoint(
    const OdGePoint3d& pointOnCurve, 
    double& param) const;

  virtual OdResult getDistAtParam( double param, double& dist ) const;

  virtual OdResult getParamAtDist( double dist, double& param ) const;

  virtual OdResult getFirstDeriv (
    double param,
    OdGeVector3d& firstDeriv) const;

  virtual OdResult getSecondDeriv (
    double param,
    OdGeVector3d& secondDeriv) const;

  TD_USING(OdDbCurve::getFirstDeriv);
  TD_USING(OdDbCurve::getSecondDeriv);

  OdResult curveFit();
  OdResult splineFit();
  OdResult splineFit(OdDb::Poly2dType splineType, OdInt16 splineSegs);

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  OdResult subGetGsMarkersAtSubentPath( const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);

  //arx 2013 增加
  OdResult    setClosed(OdBool);
  OdResult    constantWidth(double&) const;
  OdResult    setConstantWidth(double);
  OdResult    length(double &) const;

  private:
  bool checkMarker(OdGsMarker gsMark) const;
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDb2dPolyline object pointers.
*/
typedef OdSmartPtr<OdDb2dPolyline> OdDb2dPolylinePtr;


/*

inline void OdDb2dPolyline::extend(double)
{
  return OdeNotApplicable;
}
*/
#include "TD_PackPop.h"

#endif

