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




// GiBaseVectorizer.h: interface for the OdGiBaseVectorizer class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ODGIFASTEXTCALC_INCLUDED_
#define _ODGIFASTEXTCALC_INCLUDED_

#include "../Gi/GiBaseVectorizer.h"
#include "../Gi/GiTransformed.h"
#include "../OdStack.h"

#include "../TD_PackPush.h"

/** Description:
    This class is an implementation of the subWorldDraw() framework to quickly calculate the WCS *extents* of an OdGiDrawable object.
    Remarks:
    This class is the same as OdGiExtCalc, but calculates the *extents* with lower precision to improve speed.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT ODRX_ABSTRACT OdGiFastExtCalc : public OdGiTransformed<OdGiWorldDrawImpl>
{
  typedef OdGeExtents3d Extents;
  OdGeExtents3d         m_worldExt;
  OdStack<Extents>      m_extStack;
  OdGeExtents3d*        m_pCurrExt;

  mutable bool          m_bSetExtentsCalled;

  void addTextExtents(
    const OdGePoint3d& locExtMin,
    const OdGePoint3d& locExtMax,
    const OdGePoint3d& position,
    const OdGeVector3d& normal,
    const OdGeVector3d& direction);
protected:
  ODRX_USING_HEAP_OPERATORS(OdGiTransformed<OdGiWorldDrawImpl>);

  OdGiFastExtCalc();
public:

  /** Description:
    Resets the accumulated *extents* for the OdGiDrawable object associated with this Vectorization object.
  */
  void resetExtents();
  
  /** Description:
    Returns the accumulated *extents* for the OdGiDrawable object associated with this Vectorization object.
    Arguments:
    extents (O) Receives the *extents*.
  */
  void getExtents(OdGeExtents3d& extents) const;

  /////////////////////////////////////////////////////////////////////////////
  // OdGiCommonDraw Overrides

  OdBool regenAbort() const;
  double deviation(const OdGiDeviationType deviationType, const OdGePoint3d& pointOnCurve) const;
  OdGiRegenType regenType() const;

   /////////////////////////////////////////////////////////////////////////////
  // OdGiGeometry Overrides

  OdBool circle(const OdGePoint3d& center, const double radius, const OdGeVector3d& normal) const;

  OdBool circle(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint, const OdGePoint3d& thirdPoint) const;

  OdBool circularArc(const OdGePoint3d& center,
    const double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    const double sweepAngle,
    const OdGiArcType arcType = kOdGiArcSimple) const;

  OdBool circularArc(const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    const OdGiArcType arcType = kOdGiArcSimple) const;

  OdBool polyline(const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1) const;

  OdBool polygon(const OdUInt32 numVertices, const OdGePoint3d* vertexList) const;
  OdBool polyPoints(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker = -1) const;
  OdBool lineSegs(const OdUInt32 numSegs , const OdGePoint3d * vertexList , const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;
  OdBool dashLineSegs(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1) const;
  OdBool dashLineSegs(const OdGeMultiDashLine3d* dlList,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) const;

  OdBool pline(const OdGiPolyline& polyline, OdUInt32 fromIndex = 0, OdUInt32 numSegs = 0) const;
  OdBool pline(const OdDbPolyline& polyline, OdUInt32 fromIndex = 0, OdUInt32 numSegs = 0) const;


  /** Description:
    Introduces a *shape* into this vectorization *context*.
    
    Arguments:
    position (I) Position of the shape.
    shapeNumber (I) Shape number.
    pTextStyle (I) Pointer to the TextStyle for the shape.
    direction (I) Baseline *direction* for the *shape*.
    normal (I) Normal vector.
  */
  void shape(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    int shapeNumber, const OdGiTextStyle* pTextStyle);

  OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const double height, const double width, const double oblique, const OdChar* msg) const;

  OdBool text(const OdGePoint3d& position,
    const OdGeVector3d& normal, const OdGeVector3d& direction,
    const OdChar* msg, const OdInt32 length, const OdBool raw, const OdGiTextStyle& pTextStyle) const;


  OdBool xline(const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint) const;

  OdBool ray(const OdGePoint3d& basePoint, const OdGePoint3d& throughPoint ) const;

  OdBool nurbs(const OdGeNurbCurve3d& nurbsCurve,const OdGeVector3d* pNormal = 0) const;

  OdBool ellipArc(const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointsOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple) const;

  OdBool mesh(const OdUInt32 numRows,
    const OdUInt32 numColumns,
    const OdGePoint3d* vertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0,const bool bAutoGenerateNormals = true) const;

  OdBool shell(const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdUInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0,
    const struct resbuf* pResbuf = NULL,
    const bool bAutoGenerateNormals = true) const;

  OdBool worldLine(const OdGePoint3d points[2]);


  OdBool polypoint(OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors, const OdCmTransparency* pTransparency,
                 const OdGeVector3d* pNormals, const OdGsMarker* pSubEntMarkers, OdInt32 nPointSize);

  void setExtents(OdGePoint3d *newExtents) const;

  OdBool pushClipBoundary(OdGiClipBoundary* pBoundary);
  void popClipBoundary();

  OdBool pushModelTransform(const OdGeMatrix3d& xfm);
  OdBool pushModelTransform(const OdGeVector3d& normal);
  OdBool popModelTransform();

  OdBool draw(OdGiDrawable* pDrawable) const;
};


#include "../TD_PackPop.h"

#endif // #ifndef _ODGIFASTEXTCALC_INCLUDED_
