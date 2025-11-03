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




#ifndef _OD_DB_2DVERTEX_
#define _OD_DB_2DVERTEX_

#include "TD_PackPush.h"
#include "OdDb.h"

#include "DbVertex.h"

/** Description:
    This class represents OdDb2Polyline vertices in an OdDbDatabase instance.
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDb2dVertex: public OdDbVertex
{
public:

  ODDB_DECLARE_MEMBERS(OdDb2dVertex);

  /**
    Remarks:
    Newly created vertices are of type OdDb::k2dVertex.
  */
  OdDb2dVertex();

  /** 
  Gcad(Add):增加兼容接口	
  */
   OdDb2dVertex(
        const OdGePoint3d&  position,
        double   bulge      = 0,
        double   startWidth = 0,
        double   endWidth   = 0,
        double   tangent    = 0,
        OdInt32 vertexIdentifier = 0);

   /** 
  Gcad(Add):增加兼容接口	
  */
   ~OdDb2dVertex();

  /** Description:
    Returns the type of this Vertex entity.  
    
    Remarks:
    vertexType() returns one of the following:

    @table
    Name                        Value   DXF 70  Description    
    OdDb::k2dVertex             0       0x00    Standard vertex.
    OdDb::k2dSplineCtlVertex    1       0x10    Spline-fit or curve-fit control point.
    OdDb::k2dSplineFitVertex    2       0x08    Spline-fit generated vertex.
    OdDb::k2dCurveFitVertex     3       0x01    Curve-fit generated vertex.
  */
  OdDb::Vertex2dType vertexType() const;

  /** Description:
    Sets the type of this Vertex entity.

    Arguments:
    vertexType (I) Vertex type.

    Remarks:
    vertexType type must be one of the following:

    @table
    Name                        Value   DXF 70  Description    
    OdDb::k2dVertex             0       0x00    Standard vertex.
    OdDb::k2dSplineCtlVertex    1       0x10    Spline-fit or curve-fit control point.
    OdDb::k2dSplineFitVertex    2       0x08    Spline-fit generated vertex.
    OdDb::k2dCurveFitVertex     3       0x01    Curve-fit generated vertex.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setVertexType(
    OdDb::Vertex2dType vertexType);

  /** Description:
    Returns the OdDb2dPolyline OCS *position* of this entity (DXF 10).

    Remarks:
    Each OdDb2dPolyline is described a series of OCS AcDb2dVertices and an elevation.
    
    While Z coordinates are set and retrieved by setPosition() and position() respectively,
    they are ignored by the Polyline.
    
    The elevation of the Polyline can be changed only with OdDb2dPolyline::setElevation(). 
      
  */
  OdGePoint3d position() const;

  /** Description:
    Sets the OdDb2dPolyline OCS *position* of this entity (DXF 10).
    Arguments:
    position (I) Position.
    
    Remarks:
    Each OdDb2dPolyline is described a series of OCS AcDb2dVertices and an elevation.
    
    While Z coordinates are set and retrieved by setPosition() and position() respectively,
    they are ignored by the Polyline.
    
    The elevation of the Polyline can be changed only with OdDb2dPolyline::setElevation(). 

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setPosition(
    const OdGePoint3d& position);

  /** Description:
    Returns the starting width of the segment following this Vertex entity (DXF 40).
  */
  double startWidth() const;

  /** Description:
    Sets the starting width of the segment following this Vertex entity (DXF 40).

    Arguments:
    startWidth (I) Starting width.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setStartWidth(
    double startWidth);

  /** Description:
    Returns the ending width of the segment following this Vertex entity (DXF 41).
  */
  double endWidth() const;

  /** Description:
    Sets the ending width of the segment following this Vertex entity (DXF 41).
   
    Arguments:
    endWidth (I) Ending width.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setEndWidth(
    double endWidth);

  /** Description:
    Returns the *bulge* of the segment following this Vertex entity (DXF 42).
    
    Remarks:
    Bulge is the *tangent* of 1/4 the included angle of the arc segment, measured counterclockwise.
  */
  double bulge() const;

  /** Description:
    Sets the *bulge* of the arc segment following this Vertex entity (DXF 42).

    Arguments:
    bulge (I) Bulge.
    
    Remarks:
    Bulge is the *tangent* of 1/4 the included angle of the arc segment, measured counterclockwise.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setBulge(
    double bulge);

  /** Description:
    Returns true if and only if the curve fit *tangent* direction is used by this Vertex entity.(DXF 70, bit 0x02).
  */
  OdBool isTangentUsed() const;

  /** Description:
    Specifies the curve fit *tangent* direction is to be used by this Vertex entity.(DXF 70, bit 0x02).

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult useTangent();

  /** Description:
    Specifies the curve fit *tangent* direction is not to be used by this Vertex entity.(DXF 70, bit 0x02).

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult ignoreTangent();

  /** Description:
    Returns the curve fit *tangent* direction for this Vertex (DXF 50).

    Remarks:
    This is the angle between the OdDb2dPolyline OCS X-axis and the *tangent* direction.

    Note:
    All angles are expressed in radians.
  */
  double tangent() const;

  /** Description:
    Sets the curve fit *tangent* direction for this Vertex (DXF 50).

    Arguments:
    tangent (I) Tangent angle.
    
    Remarks:
    This is the angle between the OdDb2dPolyline OCS X-axis and the *tangent* direction.

    Note:
    All angles are expressed in radians.

	Gcad(Modify)::returns:void->OdResult
  */
  OdResult setTangent(
    double tangent);

  /** Description:
    Returns the *vertex identifier* of this Vertex entity.
  */
  OdInt32 vertexIdentifier() const;

  /** Description:
    Sets the *vertex identifier* of this Vertex entity.

    Arguments:
    suggestedId (I) Vertex identifier.
  */
  OdResult setVertexIdentifier(
    OdInt32 suggestedId);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetGeomExtents(// Gcad(Modify)
    OdDbExtents& extents) const ODRX_OVERRIDE;

  /*
      OdDb2dVertex(const OdGePoint3d&  position, double bulge = 0,
                   double startWidth = 0, double endWidth = 0, double tangent = 0);
  */


  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& mat, OdDbEntityPtr& pCopy) const;

  OdResult   setTangentUsed(OdBool);
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDb2dVertex object pointers.
*/
typedef OdSmartPtr<OdDb2dVertex> OdDb2dVertexPtr;

#include "TD_PackPop.h"

#endif

