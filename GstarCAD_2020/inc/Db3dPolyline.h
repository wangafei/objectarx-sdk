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




#ifndef _OD_DB_3D_POLYLINE_
#define _OD_DB_3D_POLYLINE_

#include "TD_PackPush.h"
#include "OdDb.h"

#include "DbCurve.h"
#include "DbObjectIterator.h"

class OdDb3dPolylineVertex;
class OdDbSequenceEnd;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDb3dPolylineVertex object pointers.
*/
typedef OdSmartPtr<OdDb3dPolylineVertex> OdDb3dPolylineVertexPtr;
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSequenceEnd object pointers.
*/
typedef OdSmartPtr<OdDbSequenceEnd> OdDbSequenceEndPtr;

/** Description:
    This class represents 3D Polyline entities in an OdDbDatabase instance.

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDb3dPolyline: public OdDbCurve
{
public:

  ODDB_DECLARE_MEMBERS(OdDb3dPolyline);

  OdDb3dPolyline();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDb3dPolyline(OdDb::Poly3dType, OdGePoint3dArray& vertices,
                   OdBool closed = kFalse);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDb3dPolyline();
	
  /** Description:
    Sets this Polyline entity closed (DXF 70, bit 0x01=1).

	Gcad(Modify):returns:void->OdResult
  */
  OdResult makeClosed();

  /** Description:
    Sets this Polyline entity open (DXF 70, bit 0x01=0).

	Gcad(Modify):returns:void->OdResult
  */
   OdResult makeOpen();

  /** Description:
    Returns the type of this Polyline entity. 
    
    Remarks:
    polyType() returns one of the following:
    
    @table
    Name                        Value   Description
    OdDb::k3dSimplePoly         0       Simple polyline.
    OdDb::k3dQuadSplinePoly     1       Quadratic B-spline fit (DXF 80, bit 0x08; DXF 75 == 5).
    OdDb::k3dCubicSplinePoly    2       Cubic B-spline-fit (DXF 80, bit 0x08; DXF 75 == 6).
  */
  OdDb::Poly3dType polyType() const;

  /** Description:
    Sets the type of this Polyline entity. 

    Arguments:
    polyType (I) Polyline type.
   
    Remarks:
    polyType() returns one of the following:
    
    @table
    Name                        Value   Description
    OdDb::k3dSimplePoly         0       Simple polyline.
    OdDb::k3dQuadSplinePoly     1       Quadratic B-spline fit (DXF 80, bit 0x08; DXF 75 == 5).
    OdDb::k3dCubicSplinePoly    2       Cubic B-spline-fit (DXF 80, bit 0x08; DXF 75 == 6).

	Gcad(Modify):returns:void->OdResult
  */
   OdResult setPolyType(
    OdDb::Poly3dType polyType);

  /** Description:
    Removes all spline fitting from this Polyline entity.
  
    Remarks:
    Removes all but the simple vertices.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult straighten();

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

	Gcad(Internal):接口冲突
  */
  OdDbObjectId appendVertex(
	ODSYSDEF,
    OdDb3dPolylineVertex* pVertex);

  /**
  Remarks:
    Returns eOk if successful

  Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult appendVertex(OdDb3dPolylineVertex*);
#endif
  /**
  Arguments:
	objId (O) the Object ID of the appended vertex.

  Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult appendVertex(OdDbObjectId& objId, OdDb3dPolylineVertex*);
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
    OdDb3dPolylineVertex* pVertex);

  /**
    Arguments:
    pIndexVert (I) Pointer to vertex after which to insert the specified vertex.

	Gcad(Internal):接口冲突
  */
  OdDbObjectId insertVertexAt(
	ODSYSDEF,
    const OdDb3dPolylineVertex* pIndexVert, 
    OdDb3dPolylineVertex* pVertex);

  /**
  Remarks:
    Returns eOk if successful

  Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult insertVertexAt(const OdDb3dPolylineVertex* pIndexVert,
        OdDb3dPolylineVertex* pNewVertex); 
#endif
  /**
  Arguments:
  newVertId(O) the Object ID of the newly inserted vertex.

  Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult insertVertexAt(OdDbObjectId& newVertId,
        const OdDbObjectId& indexVertId, OdDb3dPolylineVertex* pNewVertex);
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
  OdDb3dPolylineVertexPtr openVertex(
    OdDbObjectId vertId, 
    OdDb::OpenMode mode, 
    bool openErasedOne = false);

  /**
  Remarks:
    Returns eOk if successful

  Arguments:
  pVertex(O) a Pointer to the opened object

  Gcad(Add):增加兼容接口
  */
  OdResult openVertex(OdDb3dPolylineVertex*& pVertex, OdDbObjectId vertId,
                                 OdDb::OpenMode,
                                 bool openErasedOne = false);

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
  pSeqEnd(O) a Pointer to the newly opened OdDbSequenceEnd.

  Gcad(Add):增加兼容接口
  */
  OdResult openSequenceEnd(OdDbSequenceEnd*& pSeqEnd, OdDb::OpenMode);
  /** Description:
    Returns a SmartPointer to an iterator that can be used to traverse the vertices owned 
    by this Polyline entity.

	Gcad(Internal):接口冲突
  */
  OdDbObjectIteratorPtr vertexIterator(ODSYSDEF) const;

  /**
  Returns a Pointer to an iterator that can be used to traverse the vertices owned 
    by this Polyline entity.

  Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdDbObjectIterator* vertexIterator() const;
#endif

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  // Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdBool isPlanar() const;

  virtual OdResult getPlane(
    OdGePlane& plane, 
      OdDb::Planarity& planarity) const;


  /* OdDbCurveMethods */

  virtual OdBool isClosed() const;

  virtual OdBool isPeriodic() const;

  virtual OdResult getStartParam(
    double& startParam) const;

  virtual OdResult getEndParam(
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

  virtual OdResult getArea(
    double& area) const;

  TD_USING(OdDbCurve::getFirstDeriv);
  TD_USING(OdDbCurve::getSecondDeriv);


 // OdDb3dPolyline(OdDb::Poly3dType, OdGePoint3dArray& vertices, bool closed = false);

  OdResult convertToPolyType(OdDb::Poly3dType newVal); 
  OdResult splineFit();
  OdResult splineFit(OdDb::Poly3dType splineType, OdInt16 splineSegs);
  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  OdResult subGetGsMarkersAtSubentPath( const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);
  
  private:
  bool checkMark(OdGsMarker gsMark, bool bSplFrm, OdDbObjectIteratorPtr pVi) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDb3dPolyline object pointers.
*/
typedef OdSmartPtr<OdDb3dPolyline> OdDb3dPolylinePtr;

#include "TD_PackPop.h"

#endif

