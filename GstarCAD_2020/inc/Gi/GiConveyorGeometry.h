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

#ifndef __ODGICONVEYORGEOMETRY_H__
#define __ODGICONVEYORGEOMETRY_H__

#include "../Gi/GiGeometry.h"
#include "../Gi/GiCommonDraw.h"
#include "../Gs/GsSelectionReactor.h"
#include "../Gi/GiSubEntityTraitsData.h"

class OdGiRasterImage;
class OdGiMetafile;
class OdGiViewport;
class OdGsView;
class OdGiCommonDraw;
class OdGiSubEntityTraitsData;
class OdGiDeviation;
class OdGeExtents3d;
class OdGeBoundBlock3d;

/** Description:
    This class implements an interface that allows conveyor nodes to interact with parent objects.
    
    Remarks:
    This interface gives
    abstract access to OdGiBaseVectorizer level data and services.
    Many conveyor nodes require a pointer to an OdGiConveyorContext interface,
    in order to be initialized.

    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class OdGiConveyorContext
{
public:
  /** Description:
    Returns the OdGiContext object associated with this ConveyorContext object.
  */
  virtual OdGiContext& giContext() const = 0;

  /** Description:
    Returns the OdGiSubEntityTraits instance associated with this ConveyorContext object.
    
    Remarks:
    The OdGiSubEntityTraits object is used to register attribute changes with
    the vectorization framework.
  */
  virtual OdGiSubEntityTraits& subEntityTraits() const = 0;

  /** Description:
    Returns the traits currently in effect for this ConveyorContext object.
  */
  virtual const OdGiSubEntityTraitsData& effectiveTraits() const = 0;
  virtual void getEffectiveTraits(OdGiSubEntityTraitsData& eTraits) const = 0;

  /** Description:
    Sets the traits currently in effect for this ConveyorContext object.
    Arguments:
    traits (I) New traits data which will be used for effective traits substitution.
    fillNormal (I) Optional fill normal.
  */
  virtual void setEffectiveTraits(const OdGiSubEntityTraitsData& traits,
                                  const OdGeVector3d* fillNormal = NULL) = 0;

  /** Description:
    Returns the current OdGiDrawableDesc instance for this ConveyorContext object.
    
    Remarks:
    This instance contains information about the current drawable object (the object itself, rendering flags, etc.).
  */
  virtual const OdGiDrawableDesc* currentDrawableDesc() const = 0;

  /** Description:
    Returns the current OdGiDrawable object for this ConveyorContext object.
    
    Remarks:
    This is the object currently being vectorized by the framework.
  */
  virtual const OdGiDrawable* currentDrawable() const = 0;

  /** Description:
    Returns the OdGiViewport associated with this ConveyorContext object.
  */
  virtual const OdGiViewport* giViewport() const = 0;

  /** Description:
      Returns the OdGsView associated with this ConveyorContext object.
  */
  virtual const OdGsView* gsView() const = 0;

  /** Description:
    Notification function called by the vectorization framework
    whenever the rendering attributes have changed.

    Remarks:
    This function is called before sending any *geometry* through the *geometry* conveyor.

    This function provides a hook
    for setting rendering attributes for the final *geometry* *handler* (e.g. Win GDI *device*).
  */
  virtual void onTraitsModified() = 0;

  /** Description:
    Returns true if and only if regen was aborted.
  */
  virtual OdBool regenAbort() const = 0;

  virtual const OdGiPathNode* currentGiPath() const = 0;

  virtual const OdGiDeviation& worldDeviation() const = 0;
  virtual const OdGiDeviation& modelDeviation() const = 0;
  virtual const OdGiDeviation& eyeDeviation() const = 0;

  enum ConveyorContextFlags
  {
    kSpatialFilterSimplPline = 1, // Simplify plineProc() by spatial filter
    kSpatialFilterSimplNurbs = 2, // Simplify nurbsProc() by spatial filter
    kSpatialFilterSimplText  = 4, // Simplify textProc () by spatial filter
    kSpatialFilterSimplShape = 8, // Simplify shapeProc() by spatial filter
    kSpatialFilterSimplAll   = (kSpatialFilterSimplPline | kSpatialFilterSimplNurbs |
                                kSpatialFilterSimplText  | kSpatialFilterSimplShape), // All spatial filter options
    kEmbranchmentSimplText   = 16, // Simplify textProc () by conveyor embranchment
    kEmbranchmentSimplNurbs  = 32, // Simplify nurbsProc() by conveyor embranchment
    kEmbranchmentSimplAll    = (kEmbranchmentSimplText | kEmbranchmentSimplNurbs),
    kConveyorSimplAll        = (kSpatialFilterSimplAll | kEmbranchmentSimplAll),
    kPlineMarkers            = 64
  };
  virtual OdUInt32 drawContextFlags() const { return 0; }
};

/** Description:
    This class defines the interface through which nodes in the Teigha vectorization
    pipeline transfer geometric data.
    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class OdGiConveyorGeometry
{
public:
  /** Description:
    Processes OdGiPolyline data.

    Arguments:
    polyline (I) Polyline data to be processed.
    pXfm (I) Pointer to a transformation matrix.
    fromIndex (I) Index of the first segment to be processed.
    numSegs (I) Number of segments to be processed.
    Remarks:
    numSegs == 0 indicates all segments starting at fromIndex are to be processed. 
      
  */
  virtual void plineProc(const OdGiPolyline& polyline,
    const OdGeMatrix3d* pXfm = 0,
    OdUInt32 fromIndex = 0,
    OdUInt32 numSegs = 0) = 0;

  /** Description:
    Processes simple *polyline* data.

    Arguments:
    numPoints (I) Number of points.
    vertexList (I) Array of *vertices*.
    pNormal (I) Pointer to the normal vector.
    pExtrusion (I) Pointer to the extrusion vector.
    baseSubEntMarker (I) Currently unused.
    Remarks:
    The extrusion vector specifies the *direction* and distance of the extrusion.
  */
  virtual void polylineProc(
    OdUInt32 numPoints, const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0,
    OdLongPtr baseSubEntMarker = -1) = 0;

  /** Description:
    Processes *polygon* data.

    Arguments:
    numPoints (I) Number of points.
    vertexList (I) Array of *vertices*.
    pNormal (I) Pointer to the normal vector.
    pExtrusion (I) Pointer to the extrusion vector.

    Remarks:
    The extrusion vector specifies the *direction* and distance of the extrusion.
  */
  virtual void polygonProc(
    OdInt32 numPoints, const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual void polyPointsProc(const OdUInt32 numVertices, const OdGePoint3d* vertexList , OdLongPtr baseSubEntMarker = -1)  = 0;
  virtual void lineSegsProc(const OdUInt32 numSegs , const OdGePoint3d * vertexList , const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1)  = 0;

  virtual bool dashLineEnable() {return false;}
  virtual void dashLineSegsProc(const OdUInt32 numSegs, const OdGeDashLine3d* dlList, const OdGeVector3d* pNormal = 0, OdLongPtr baseSubEntMarker = -1) = 0;
  virtual void dashLineSegsProc(const OdGeMultiDashLine3d* dlList,const OdGeVector3d* pNormal = 0,OdLongPtr baseSubEntMarker = -1) = 0;  

  /** Description:
    Processes Xline data.
    Arguments:
    firstPoint (I) First point.
    secondPoint (I) Second point.
    Remarks:
    An Xline is an infinite line passing through the 
    specified points.
  */
  virtual void xlineProc(
    const OdGePoint3d& firstPoint, const OdGePoint3d& secondPoint) = 0;

  /** Description:
    Processes Ray data.
    
    Arguments:
    basePoint (I) Base point.
    throughPoint (I) Through point
    
    Remarks:
    A Ray is a semi-infinite line that starts at the basePoint, and passes 
    through the throughPoint.
  */
  virtual void rayProc(
    const OdGePoint3d& basePoint, const OdGePoint3d& throughPoint) = 0;

  /** Description:
    Processes *mesh* data.

    Arguments:
    numRows (I) Number of rows.
    numColumns (I) Number of columns.
    vertexList (I) Array of *vertices*.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.
    pVertexData (I) Pointer to additional vertex data. 

    See Also:
    OdGiEdgeData
    OdGiFaceData
    OdGiVertexData
    Vectorization Primitives
  */
  virtual void meshProc(
    OdInt32 numRows, 
    OdInt32 numColumns,
    const OdGePoint3d* vertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) = 0;

  /** Description:
    Processes *shell* data.

    Arguments:
    numVertices (I) Number of *vertices*.
    vertexList (I) Array of *vertices*.
    faceListSize (I) Number of entries in faceList.
    faceList (I) Array of numbers that define the faces.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.
    pVertexData (I) Pointer to additional vertex data. 

    See Also:
    Vectorization Primitives      
  */
  virtual void shellProc(
    OdInt32 numVertices, const OdGePoint3d* vertexList,
    OdInt32 faceListSize, const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0) = 0;

  /** Description:
    Process circle data. 

    Arguments:
    center (I) Center point.
    radius (I) Radius.
    normal (I) Normal vector.
    pExtrusion (I) Pointer to the extrusion vector.
    Remarks:
    The extrusion vector specifies the *direction* and distance of the extrusion.
  */
  virtual void circleProc(
    const OdGePoint3d& center, 
    double radius, 
    const OdGeVector3d& normal, 
    const OdGeVector3d* pExtrusion = 0) = 0;

  /** Arguments:
    firstPoint (I) First point of a 3-point circle.
    secondPoint (I) Second point of a 3-point circle.
    thirdPoint (I) Third point of a 3-point circle.
    Remarks:
    If firstPoint, secondPoint, and thirdPoint are specified, they
    cannot be colinear and no two can be coincident.
  */
  virtual void circleProc(
    const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& thirdPoint, 
    const OdGeVector3d* pExtrusion = 0) = 0;
  
  /** Description:
    Processes circular arc data.

    Arguments:
    center (I) Center point.
    radius (I) Radius.
    normal (I) Normal vector.
    startVector (I) Defines the start of this arc.
    sweepAngle (I) Angle that defines the arc.
    arcType (I) Arc type.
    pExtrusion (I) Pointer to the extrusion vector.
    
    Remarks:
    arcType must be one of the following:
    
    @table
    Name              Value     Description
    kOdGiArcSimple    0         Unfilled.
    kOdGiArcSector    1         Filled area bounded by the arc and its center.
    kOdGiArcChord     2         Filled area bounded by the arc and its end points

    The extrusion vector specifies the *direction* and distance of the extrusion.
    
    Note:
    All angles are expressed in radians.
  */
  virtual void circularArcProc(
    const OdGePoint3d& center,
    double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    double sweepAngle,
    OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0) = 0;
  
  /** Arguments:
    firstPoint (I) First point of a 3-point arc.
    secondPoint (I) Second point of a 3-point arc.
    thirdPoint (I) Third point of a 3-point arc.
    Remarks:
    If firstPoint, secondPoint, and thirdPoint are specified, they
    cannot be colinear and no two can be coincident.
  */
  virtual void circularArcProc(
    const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0) = 0;

  /** Description:
    Processes OdGeEllipArc3d data.

    Arguments:
    ellipArc (I) Elliptical arc.
    endPointOverrides (I) Array of points to be used as the first and last points of the vectorized arc.
    arcType (I) Arc type.
    pExtrusion (I) Pointer to the extrusion vector.
        
    Remarks:
    arcType must be one of the following:
    
    @table
    Name              Value     Description
    kOdGiArcSimple    0         Unfilled.
    kOdGiArcSector    1         Filled area bounded by the arc and its center.
    kOdGiArcChord     3         Filled area bounded by the arc and its end points

    The extrusion vector specifies the *direction* and distance of the extrusion.

  */
  virtual void ellipArcProc(
    const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0) = 0;

  /** Description:
    Processes OdGeNurbCurve3d data.
    Arguments:
    nurbsCurve (I) NURBS curve data.
  */
  virtual void nurbsProc(
    const OdGeNurbCurve3d& nurbsCurve,const OdGeVector3d* pNormal = 0) = 0;

  /** Description:
    Processes text data.

    Arguments:
    position (I) Position of the text.
    direction (I) Baseline *direction* of the text.
    upVector (I) Up vector for the text.
    msg (I) Text string.
    numBytes (I) Number of *bytes* in msg.
    raw (I) If and only if true, escape sequences, such as %%P, will not be converted to special characters.
    pTextStyle (I) Pointer to the TextStyle for the text.
    pExtrusion (I) Pointer to the extrusion vector.

    Remarks:
    The extrusion vector specifies the *direction* and distance of the extrusion.
  */
  virtual void textProc(
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 numBytes, 
    bool raw, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0) = 0;

  virtual void textProc2(
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    const OdChar* msg, 
    OdInt32 numBytes, 
    bool raw, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0,
    const OdGeExtents3d* /*extentsBox*/ = 0)
  {
    textProc(position, direction, upVector, msg, numBytes, raw, pTextStyle, pExtrusion);
  }

  /** Description:
    Processes TTF Text(GDI)

    Arguments:
    position (I) Position of the text.
    u (I) Baseline *direction* of the text.
    v (I) Up vector for the text.
    pText (I) Text string.
    nLen (I) Length of string in pText. [same with charWidths.size().]
    height (I) Height of the text.
    allWidth (I) Width of the text. [all chars, NOT one.]
    charWidths (I) Width of each char in pText.
    pLOGFONT (I) Pointer to LOGFONT.

    Remarks:
    ONLY windows supported.
  */
  virtual void ttfTextProc(
    const OdGePoint3d& ,
    const OdGeVector3d&, const OdGeVector3d&,
    const OdChar*, OdInt32,
    double,
    double,
    const OdArray<double>&,
    const void*)
  {
    // The default implementation of this function does nothing but return.
  }

  /** Description:
    Processes shape data.

    Arguments:
    position (I) Position of the shape.
    direction (I) Baseline *direction* of the shape.
    upVector (I) Up vector for the shape.
    shapeNumber (I) Shape number.
    pTextStyle (I) Pointer to the TextStyle for the shape.
    pExtrusion (I) Pointer to the extrusion vector.

    Remarks:
    The extrusion vector specifies the *direction* and distance of the extrusion.
  */
  virtual void shapeProc(
    const OdGePoint3d& position,
    const OdGeVector3d& direction, 
    const OdGeVector3d& upVector,
    int shapeNumber, 
    const OdGiTextStyle* pTextStyle,
    const OdGeVector3d* pExtrusion = 0) = 0;

  /** Description:
    Processes raster images data.

    Arguments:
    origin (I) Lower-left corner. 
    u (I) Image width vector.
    v (I) Image height vector.
    pImage (I) Pointer to the RasterImage object.
    uvBoundary (I) Array of *image* boundary points (may not be null).
    numBoundPts (I) Number of boundary points.
    transparency (I) True if and only if *image* *transparency* is on.
    brightness (I) Image *brightness* [0.0 .. 100.0].
    contrast (I) Image *contrast* [0.0 .. 100.0].
    fade (I) Image *fade* value [0.0 .. 100.0].
  */
  virtual void rasterImageProc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiRasterImage* pImage, 
    const OdGePoint2d* uvBoundary, 
    OdUInt32 numBoundPts,
    bool transparency = false,
    double brightness = 50.0,
    double contrast = 50.0,
    double fade = 0.0) = 0;

  /** Description:
    Processes metafile data.

    Arguments:
    origin (I) Metafile *origin*.
    u (I) Metafile width vector.
    v (I) Metafile height vector.
    pMetafile (I) Pointer to the metafile object.
    dcAligned (I) reserved.
    allowClipping (I) reserved.
  */
  virtual void metafileProc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false) = 0;

  enum ETtfCharProcFlags
  {
    kTtfCharProcEnable     = 1,
    kTtfCharProcBoundBlock = 2
  };
  virtual int ttfCharProcFlags() const { return 0; }
  virtual bool ttfCharProc(OdChar /*character*/, const OdGePoint3d& /*position*/,
    const OdGeBoundBlock3d* /*pBoundBlock*/) { return false; }

  virtual void ttfPolyDrawProc(
    OdInt32 numVertices, const OdGePoint3d* vertexList,
    OdInt32 faceListSize, const OdInt32* faceList,
    const OdUInt8* /*pBezierTypes*/, const OdGiFaceData* pFaceData = 0)
  {
    shellProc(numVertices, vertexList, faceListSize, faceList, 0, pFaceData);
  }
  void polypointProc2(OdGiConveyorContext* pContext,
    OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors = 0,
    const OdCmTransparency *pTransparency = 0, const OdGeVector3d* pNormals = 0, const OdGeVector3d* pExtrusions = 0,
    const OdGsMarker* pSubEntMarkers = 0, OdInt32 nPointSize = 0);
  /** \details
    Processes array of points.

    \param numPoints [in]  Number of points.
    \param vertexList [in]  Array of vertices.
    \param pNormals [in]  Array of normal vectors.
    \param pExtrusions [in]  Array of extrusion vectors.
    \param pSubEntMarkers [in]  Array of subentity markers.
    \remarks
    The extrusion vectors specifies the direction and distance of the extrusion.
  */
  virtual void polypointProc(
    OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors,
    const OdCmTransparency* pTransparency = 0, const OdGeVector3d* pNormals = 0, const OdGeVector3d* pExtrusions = 0,
    const OdGsMarker* pSubEntMarkers = 0, OdInt32 nPointSize = 0) = 0;

  virtual int  selectState(){return 0;}
  virtual bool checkValidSelect(OdInt32,const OdGePoint3d*){return true;}

  
  virtual void polylineExProc(OdUInt32 nbPoints, const OdGePoint3d* pVertexList,
    const OdGeVector3d* pNormal = 0,
    const OdGeVector3d* pExtrusion = 0,
    OdLongPtr lBaseSubEntMarker = -1,
    int flags = 0)
  {
    if((flags & OdGiGeometry::kOnlyHighlight) == 0)
    {
      polylineProc(nbPoints, pVertexList, pNormal, pExtrusion, lBaseSubEntMarker);
    }
  }

  virtual bool drawOperatorProc(OdUInt32 op, void *pData)
  {    
    return false;
  }

  virtual bool dynSample() const {return false;}
  virtual bool dynCircleSample(const OdGePoint3d& center, double radius, const OdGeVector3d& normal, const OdGeVector3d* pExtrusion = 0){return false;}
  virtual bool dynCircularArcSample(const OdGePoint3d& center, double radius, const OdGeVector3d& normal, const OdGeVector3d& startVector, double sweepAngle, OdGiArcType arcType = kOdGiArcSimple, const OdGeVector3d* pExtrusion = 0){return false;}
};

inline
void OdGiConveyorGeometry::polypointProc2(OdGiConveyorContext* pContext,
  OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors,
  const OdCmTransparency* pTransparency, const OdGeVector3d* pNormals, const OdGeVector3d* pExtrusions,
  const OdGsMarker* pSubEntMarkers, OdInt32 /*nPointSize*/)
{
  OdGePoint3d tmpVerts[2];
  for (OdInt32 nPoint = 0; nPoint < numPoints; nPoint++)
  {
    OdGsMarker baseSubEntMarker = -1;
    if ((pColors || pTransparency || pSubEntMarkers) && pContext)
    {
      if (pColors)
        pContext->subEntityTraits().setTrueColor(pColors[nPoint]);
      if (pTransparency)
        pContext->subEntityTraits().setTransparency(pTransparency[nPoint]);
      if (pSubEntMarkers)
        pContext->subEntityTraits().setSelectionMarker(pSubEntMarkers[nPoint]);
      pContext->onTraitsModified();
    }
    else if (pSubEntMarkers)
      baseSubEntMarker = pSubEntMarkers[nPoint];
    const OdGeVector3d *pNormal = (pNormals) ? (pNormals + nPoint) : NULL;
    const OdGeVector3d *pExtrusion = (pExtrusions) ? (pExtrusions + nPoint) : NULL;
    tmpVerts[1] = tmpVerts[0] = vertexList[nPoint];
    polylineProc(2, tmpVerts, pNormal, pExtrusion, baseSubEntMarker);
  }
}
#endif //#ifndef __ODGICONVEYORGEOMETRY_H__
