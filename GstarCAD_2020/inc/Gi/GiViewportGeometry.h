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




#ifndef _OD_GIVIEWPORT_GEOMETRY_H_
#define _OD_GIVIEWPORT_GEOMETRY_H_

#include "../Gi/Gi.h"
#include "../Gi/GiGeometry.h"

class OdGePoint3d;
class OdGeVector3d;
class OdGeMatrix2d;
class OdGiRasterImage;
class OdGiMetafile;
class OdGiCommonDraw;
class OdGsDCRect;

#include "../TD_PackPush.h"


/** Description:
  This class defines the interface for objects that *draw* themselves.
  { Group:OdGi_Classes } 
*/
class FIRSTDLL_EXPORT OdGiSelfGdiDrawable : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiSelfGdiDrawable);

  /** Description:
    This function is called to have a GDI self-drawable to *draw* itself.
    Arguments:
    drawObj (I) Object to be drawn.
    hdc (I) Handle to the device context.
    screenRect (I) Screen rectangle in *device* coordinates (pixels).
  */
  virtual void draw(const OdGiCommonDraw& drawObj,
                    void* hdc,
                    const OdGsDCRect& screenRect) const = 0;
};



/** Description:
    This class defines functions that allow entities to vectorize themselves.
    
    Remarks:
    Vectorization with the methods of this class are viewport dependent. 
    For viewport specific vectorization, use subViewportDraw() instead of subWorldDraw().

    An OdGiViewportGeometry object passed to the subViewportDraw()
    method of an entity.

    Model coordinates are applied to all *geometry* in this class except for setExtents(). 
   
    You can obtain objects of the following classes fromOdGiViewportDraw:

    @table
    Class                 Description
    OdGiSubEntityTraits   Control of drawing attributes and selection markers. 
    OdGiViewportGeometry  Drawing model coordinate geometry and transforms. 

    Library:
    TD_Gi
    
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiViewportGeometry : public OdGiGeometry
{
public:
  ODRX_DECLARE_MEMBERS(OdGiViewportGeometry);

  /** Description:
    Draws a *polyline*, with coordinates specified in Eye Coordinates.

    Arguments:
    numVertices (I) Number of vertices.
    vertexList (I) Array of vertices.

    Remarks:
    This *polyline* is drawn with a continuous linetype.

    See Also:
    Coordinate Systems
  */
  virtual void polylineEye(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) = 0;

  /** Description:
    Draws a filled *polygon*, with coordinates specified in Eye Coordinates.

    Arguments:
    numVertices (I) Number of vertices in the *polygon*.
    vertexList (I) Vertices of the *polygon*.

    See Also:
    Coordinate Systems
  */
  virtual void polygonEye(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) = 0;

  /** Description:
    Draws a *polyline*, with coordinates specified in normalized *device* Coordinates.

    Arguments:
    numVertices (I) Number of vertices in the *polyline*.
    vertexList (I) Vertices of the *polyline*.

    Remarks:
    This *polyline* is drawn with a continuous linetype.

    See Also:
    Coordinate Systems
  */
  virtual void polylineDc(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) = 0;

  /** Description:
    Draws a filled *polygon*, with coordinates specified in normalized *device* Coordinates.

    Arguments:
    numVertices (I) Number of vertices in the *polygon*.
    vertexList (I) Vertices of the *polygon*.

    See Also:
    Coordinate Systems
  */
  virtual void polygonDc(
    OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) = 0;

  enum ImageSource
  {
    kFromDwg        = 0,
    kFromOleObject  = 1,
    kFromRender     = 2
  };

  /** Description:
    Draws the specified raster *image*.

    Arguments:
    origin (I) Image *origin*.
    u (I) Image width vector.
    v (I) Image height vector.
    pImage (I) Pointer to the *image* object.
    uvBoundary (I) Array of *image* boundary points (may not be null).
    numBoundPts (I) Number of boundary points.
    transparency (I) True if and only if *image* *transparency* is on.
    brightness (I) Image *brightness* [0 .. 100].
    contrast (I) Image *contrast* [0 .. 100].
    fade (I) Image *fade* value [0 .. 100].
    
    Note:
    All coordinates are in Model coordinates.
*/
  virtual void rasterImageDc(
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
    Draws the specified Windows Metafile.

    Arguments:
    origin (I) Metafile *origin*.
    u (I) Metafile width vector.
    v (I) Metafile height vector.
    pMetafile (I) Pointer to the Metafile object.
    dcAligned (I) reserved.
    baAllowClipping (I) reserved.

    Note:
    All coordinates are in Model coordinates.
  */
  virtual void  metafileDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiMetafile* pMetafile,
    bool dcAligned = true,
    bool allowClipping = false) = 0;

  /** Description:
    Passes to the rendering framework an object that can render itself.

    Arguments:
    origin (I) Object *origin*.
    u (I) Object width vector.
    v (I) Object height vector.
    dcAligned (I) reserved.
    allowClipping (I) reserved.
    pDrawable (I) Pointer to the drawable.
    Remarks:
    Teigha uses this function to render Ole2Frame entities. 
    
    Note:
    ownerDrawDc is not conveyor primitive, so Teigha's rendering framework performs no processing 
    (transformation, linetyping, or clipping) for this object. 

    All coordinates are in Model coordinates.
    
    See also:
    OdGiSelfGdiDrawable.
  */
  virtual void ownerDrawDc(
    const OdGePoint3d& origin,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    const OdGiSelfGdiDrawable* pDrawable,
    bool dcAligned = true,
    bool allowClipping = false);
};

#include "../TD_PackPop.h"

#endif

