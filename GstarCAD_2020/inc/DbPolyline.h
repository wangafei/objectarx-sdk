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




#ifndef OD_DBPL_H
#define OD_DBPL_H

#include "TD_PackPush.h"

#include "DbCurve.h"
#include "Db2dPolyline.h"
#include "Ge/GeLineSeg2d.h"
#include "Ge/GeLineSeg3d.h"
#include "Ge/GeCircArc2d.h"
#include "Ge/GeCircArc3d.h"

class OdDb2dPolyline;
class OdGeLineSeg2d;
class OdGeLineSeg3d;
class OdGeCircArc2d;
class OdGeCircArc3d;

/** Description:
    This class represents Lightweight Polyline entities in an OdDbDatabase instance.

    Library:
    TD_Db

    OdDbPolyline entities differ from OdDb2dPolyline entities as follows:
    
    o  OdDbPolyline entities are stored as single objects, thereby improving
       performance and reducing overhead compared to OdDb2DPolyline objects.
       
    o Curve fitting and Spline fitting of OdDbPolyline entities are not supported.  
    
    Note:
    The number of vertices in an OdDbPolyline must be at least two. 
    Polylines with less than two vertices should not left in or added to
    the *database*.
    
    Since the nth Segment of a Polyline is the segment following the nth Vertex, 
    the segment index and vertex index may be used interchangeably. 
    
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbPolyline : public OdDbCurve
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPolyline);

  OdDbPolyline();
  /** 
  Gcad(Add):增加兼容接口	
  */
  OdDbPolyline(unsigned int num_verts);
  /** 
  Gcad(Add):增加兼容接口	
  */
  virtual          ~OdDbPolyline();

  /** Description:
    Fills this OdDbPolyline entity with data from the specified OdDb2dPolyline entity.  
    
    Arguments:
    pSource (I) Pointer to the source OdDb2dPolyline entity.
    transferId (I) True to do a handOverTo() between the source OdDb2dPolyline 
                   entity and this OdDbPolyline entity.  

    Remarks:
    If and only if transferId is true, 
    
      o  This OdDbPolyline entity will be made *database* resident.
      o  It will assume the objectId, handle, extended entity data, extension
         dictionary, and reactors of the source OdDb2dPolyline entity
      o  The source OdDb2dPolyline entity will be deleted.
    
        
    Note:
    The source OdDb2dPolyline entity
    
      o  Must be non- *database* resident.
      o  Must by of type k2dSimplePoly or k2dFitCurvePoly.
   
    Remarks:
    Returns must be one of the following:
    
    @table
    Name                   Description
    eOk                    Success
    AlreadyInDb            This entity is *database* resident
    eIllegalEntityType     *pSource is not an OdDb2dPolyline
    eNotApplicable         *pSource is not k2dSimplePoly or there is extended
                           entity data attached to a vertex.
  */
  OdResult convertFrom(
    OdDbEntity* pSource, 
    OdBool transferId = kTrue);

  /** Description:
    Fills the specified OdDb2dPolyline with data from this OdDbPolyline entity.

    Arguments:
    pDest (I) Pointer to the destination OdDb2dPolyline entity.
    transferId (I) True to do a handOverTo() between this OdDbPolyline entity 
    and the destination OdDb2dPolyline entity.  

    Remarks:
    If and only if transferId is true,
    
      o  The destination OdDb2dPolyline entity will be made *database* resident.
      o  It will assume the objectId, handle, extended entity data, extension
         dictionary, and reactors of this OdDbPolyline entity. 
      o  This OdDbPolyline entity will made non- *database* resident, and may be deleted with the C++ delete operator.

    Remarks:
    Returns must be one of the following:
    
    @table
    Name                   Description
    eOk                    Success
    eIllegalReplacement    This entity is non- *database* resident.
    eObjectToBeDeleted     This entity is now non- *database* resident, and should be deleted.
  */
  OdResult convertTo(
    OdDb2dPolyline*& pDest, 
    OdBool transferId = kTrue) const;

  /** Description:
    Returns the OCS or WCS *point* of the specified vertex of this Polyline entity (DXF 10).

    Arguments:
    vertexIndex (I) Vertex *index*.
    point2d (O) Receives the OCS *point*.
    point3d (O) Receives the WCS *point*.

	Gcad(Modify):returns:void->OdResult
 */
  OdResult getPointAt(
    unsigned int vertexIndex, 
    OdGePoint2d& point2d) const;
  OdResult getPointAt(
    unsigned int vertexIndex, 
    OdGePoint3d& point3d) const;


  enum SegType
  {
    kLine,        // Straight segment with length > 0.
    kArc,         // Arc segment with length > 0.
    kCoincident,  // Segment with length == 0.
    kPoint,       // Polyline with 1 vertex.
    kEmpty        // Polyline with 0 vertices.
  };

  /** Description:
    Returns the type of the specified segment of this Polyline entity.

    Arguments:
    segmentIndex (I) Segment *index*.
    Remarks:
    segType() returns one of the following:
    
    @table
    Name           Description
    kLine          Straight segment with length > 0.0
    kArc           Arc segment with length > 0.0
    kCoincident    Segment with length == 0.0
    kPoint         Polyline with 1 vertex.
    kEmpty         Polyline with 0 vertices.
  */
  SegType segType(
    unsigned int segmentIndex) const;

  /** Description:
    Returns the specified OCS or WCS line segment of this Polyline entity.
    Arguments:
    segmentIndex (I) Segment *index*.
    line2d (O) Receives the OCS *line* segment.
    line3d (O) Receives the WCS *line* segment.
  */
  OdResult getLineSegAt(
    unsigned int segmentIndex, 
    OdGeLineSeg2d& line2d) const;

  OdResult getLineSegAt(
    unsigned int segmentIndex, 
    OdGeLineSeg3d& line3d) const;

  /** Description:
    Returns the specified OCS or WCS arc segment of this Polyline entity.
    Arguments:
    segmentIndex (I) Segment *index*.
    arc2d (O) Receives the OCS *arc* segment.
    arc3d (O) Receives the WCS *arc* segment.
  */
  OdResult getArcSegAt(
    unsigned int segmentIndex, 
    OdGeCircArc2d& arc2d) const;

  OdResult getArcSegAt(
    unsigned int segmentIndex, 
    OdGeCircArc3d& arc3d) const;

  /** Description:
    Returns true if and only if the specified OCS point is on the specified segment
    of this Polyline entity,
    and returns the parameter of that point on the segment.
    
    Arguments:
    segmentIndex (I) Segment *index*.
    point2d (I) The OCS point to query.
    param (O) The parameter at that point.
    
    Remarks:
    The returned parameter will be in the parametric form of the segment (linear or arc).
  */
  virtual OdBool onSegAt(
    unsigned int segmentIndex, 
    const OdGePoint2d& point2d, 
    double& param) const;

  /** Description:
    Controls the *closed* state for this Polyline entity (DXF 70, bit 0x01=1).
    
    Arguments:
    closed (I) Controls *closed*.
  */
  void setClosed(
    OdBool closed);

  /** Description:
    Controls the *linetype* generation for this Polyline entity (DXF 70, bit 0x80).
      
    Remarks:
    Linetype generation on indicates that the *linetype* pattern of this Polyline entity
    is continuously generated around all vertices.
    
    Linetype generation off indicates that the *linetype* pattern of this Polyline entity is
    restarted at each vertex.
    
    Arguments:
    plinegen (I) Controls *linetype* generation.
  */
  void setPlinegen(
    OdBool plinegen);

  /** Description:
    Sets the *elevation* of this entity in the OCS (DXF 38).

    Arguments:
    elevation (I) Elevation.    

    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.
  */
  void setElevation(
    double elevation);

  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  OdResult setThickness(
    double thickness);

  /** Description:
    Sets this Polyline entity to a constant width (DXF 43).
    Arguments:
    constantWidth (I) Constant width.
  */
  OdResult setConstantWidth(
    double constantWidth);

  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  OdResult setNormal(
    const OdGeVector3d& normal);

  /** Description:
    Returns true if and only if this Polyline entity consists solely of line segments.
  */
  OdBool isOnlyLines() const;

  /** Description:
    Returns true if and only if *linetype* generation is on for this Polyline entity (DXF 70, bit 0x80).
      
    Remarks:
    Linetype generation on indicates that the *linetype* pattern of this Polyline entity
    is continuously generated around all vertices.
    
    Linetype generation off indicates that the *linetype* pattern of this Polyline entity is
    restarted at each vertex.
  */
  OdBool hasPlinegen() const;

  /** Description:
    Returns the *elevation* of this entity in the OCS (DXF 30).
    
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.
  */
  double elevation() const;

  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;

  /** Description:
    Returns the constant width for this Polyline entity (DXF 43).
  */
  double getConstantWidth() const;
  /**
  Gcad(Add)
  */
  OdResult getConstantWidth(double&) const;
  
  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;

  /** Description:
    Inserts a vertex into this Polyline entity at the specified *index*.

    Arguments:
    vertexIndex (I) Vertex *index*.
    point2d (I) OCS *point* of the vertex.
    bulge (I) Bulge value for the segment following the vertex.
    startWidth (I) Start width for the segment following the vertex.
    endWidth (I) End width for the segment following the vertex.
    vertexIdentifier (I) 
    
    Remarks:
    The vertex is inserted before the specified vertex.
    If vertexIndex == numVerts(), the vertex is appended to the Polyline.
    
    Bulge is the *tangent* of 1/4 the included angle of the arc segment, measured counterclockwise.
  */
  OdResult addVertexAt(
    unsigned int vertexIndex,
    const OdGePoint2d& point2d,
    double bulge = 0.,
    double startWidth = -1.,
    double endWidth = -1.,
    OdInt32 vertexIdentifier = 0);

  /** Description:
    Removes the specified vertex from this Polyline entity.
    Arguments:
    vertexIndex (I) Vertex *index*.
  */
  OdResult removeVertexAt(
    unsigned int vertexIndex);

  /** Description:
     Returns the number of vertices in this Polyline entity (DXF 90).
  */
  unsigned int numVerts() const;


  /** Description:
    Returns the bulge of the specified segment of this Polyline entity.

    Arguments:
    index (I) Segment *index*.
    
    Remarks:
    Bulge is the *tangent* of 1/4 the included angle of the arc segment, measured counterclockwise.
 */
  double getBulgeAt(
    unsigned int index) const;

  /**
  Gcad(Add)
  */
  OdResult getBulgeAt(unsigned int index,double&      bulge)      const;
  
  /** Description:
    Returns the vertex identifier of the specified segment of this Polyline entity.

    Arguments:
    index (I) Segment *index*.
 */
  OdInt32 getVertexIdentifierAt(
    unsigned int index) const;

  OdResult getVertexIdentifierAt(unsigned int index,OdInt32& vertexIdentifier) const;
  /** Description:
    Returns the start and end widths for the specified segment of this Polyline entity.

    Arguments:
    segmentIndex (I) Segment *index*.
    startWidth (O) Receives the start width for the vertex.
    endWidth (O) Receives the end width for the vertex.
  */
  OdResult getWidthsAt(
    unsigned int segmentIndex, 
    double& startWidth,  
    double& endWidth) const;

  /** Description:
    Sets the OCS *point* for the specified vertex of this Polyline entity.
    Arguments:
    vertexIndex (I) Vertex *index*.
    point2d (I) OCS *point* of vertex.
  */
  OdResult setPointAt(
    unsigned int vertexIndex, 
    const OdGePoint2d& point2d);

  /** Description:
    Sets the *bulge* of the specified segment of this Polyline entity.

    Arguments:
    index (I) Segment *index*.
    bulge (I) Bulge.
    
    Remarks:
    Bulge is the *tangent* of 1/4 the included angle of the arc segment, measured counterclockwise.

  */
  OdResult setBulgeAt(
    unsigned int index, 
    double bulge);

  /** Description:
    Sets the *vertex identifier* of the specified segment of this Polyline entity.

    Arguments:
    index (I) Segment *index*.
    suggestedId (I) Vertex identifier.
  */
  void setVertexIdentifierAt(
    unsigned int index,
    OdInt32 suggestedId);

  /** Description:
    Sets the start and end widths for the specified segment of this Polyline entity.

    Arguments:
    index (I) Segment *index*.
    startWidth (I) Start width for the vertex.
    endWidth (I) End width for the vertex.
  */
  OdResult setWidthsAt(
    unsigned int index, 
    double startWidth, 
    double endWidth);

  /** Description:
    Compresses this Polyline entity.
    
    Remarks:
    Takes processing time, and should not be used until all edits are complete.
  */
  OdResult minimizeMemory();

  /** Description:
    Decompresses this Polyline entity to expedite modifications.
  */
  OdResult maximizeMemory();

  /** Description:
    Resets the vertex data for this Polyline entity.

    Arguments:
    reuse (I) True to retain vertices.
    numVerts (I) Number of vertices to retain.
      
    Remarks:
    If reuse is true, the vertex list will be expanded or truncated 
    such that exactly numVerts vertices exist.
    
    If reuse is false, all vertices will be deleted.
  */
  void reset(
    OdBool reuse, 
    unsigned int numVerts);

  /** Description:
    Returns true if and only if any of the segments in this Polyline entity have non-zero bulges.
  */
  OdBool hasBulges() const;

  /** Description:
    Returns true if and only if any of the segments in this Polyline entity have non-zero vertex identifiers.
  */
  OdBool hasVertexIdentifiers() const;

  /** Description:
    Returns true if and only if any of the segments in this Polyline entity have start and end widths.
  */
  OdBool hasWidth() const;

  virtual OdResult applyPartialUndo(OdDbDwgFiler* filer, OdRxClass* classobj);

  bool isLocked() const;
  void lock(bool blLock);

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const ODRX_OVERRIDE;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd) ODRX_OVERRIDE;

  virtual void subViewportDraw(
    OdGiViewportDraw* pVd) ODRX_OVERRIDE;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler) ODRX_OVERRIDE;

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const ODRX_OVERRIDE;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler) ODRX_OVERRIDE;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler) ODRX_OVERRIDE;

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const ODRX_OVERRIDE;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const ODRX_OVERRIDE;

  virtual OdBool isPlanar() const ODRX_OVERRIDE;

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  virtual void    getEcs(OdGeMatrix3d& retVal) const;

  /** Description:
      OdDbCurveMethods
  */

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

  virtual OdResult getFirstDeriv (
    double param,
    OdGeVector3d& firstDeriv) const;

  virtual OdResult getSecondDeriv (
    double param,
    OdGeVector3d& secondDeriv) const;

  virtual OdResult getFirstDeriv (
	  const OdGePoint3d& unnamed,
	  OdGeVector3d& firstDeriv) const;

  virtual OdResult getSecondDeriv (
	  const OdGePoint3d& unnamed,
	  OdGeVector3d& secondDeriv) const;

  virtual OdResult getArea(
    double& area) const;

  TD_USING(OdDbCurve::getFirstDeriv);
  TD_USING(OdDbCurve::getSecondDeriv);

  virtual OdResult getDistAtParam( double param, double& dist ) const;

  virtual OdResult getParamAtDist( double dist, double& param ) const;

  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPoint,
    OdGePoint3d& pointOnCurve,
    OdBool extend = kFalse) const;

  virtual OdResult getClosestPointTo(
    const OdGePoint3d& givenPoint,
    const OdGeVector3d& normal,
    OdGePoint3d& pointOnCurve,
    OdBool extend = kFalse) const;

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  virtual void      saveAs(OdGiWorldDraw* mode,
                                     OdDb::SaveType st);
  /*
  //arx2008 
  virtual bool              castShadows() const;
  virtual bool              receiveShadows() const;
  */
  virtual OdResult getOdGeCurve(OdGeCurve3d*& pGeCurve, const OdGeTol& tol = OdGeContext::gTol) const;
  virtual OdResult setFromOdGeCurve(const OdGeCurve3d& geCurve, OdGeVector3d *normal = NULL, const OdGeTol& tol = OdGeContext::gTol);
  
  virtual int getUnknown(int type) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbPolyline object pointers.
*/
typedef OdSmartPtr<OdDbPolyline> OdDbPolylinePtr;

#include "TD_PackPop.h"

#endif //OD_DBPL_H

