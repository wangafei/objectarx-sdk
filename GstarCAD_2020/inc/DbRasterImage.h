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




#ifndef __IMGENT_H
#define __IMGENT_H /* {Secret} */

#include "TD_PackPush.h"

#include "Ge/GePoint2dArray.h"

class OdRasterImageImpl;
class RasterImageImp;

#include "DbImage.h"
#include "DbRasterImageDef.h"

#pragma warning( disable : 4239 )
/** Description:
    This class represents RasterImage entities in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRasterImage : public OdDbImage
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRasterImage);

  static ClassVersion classVersion();

  OdDbRasterImage();
  virtual ~OdDbRasterImage();
  
  enum ClipBoundaryType
  {
    kInvalid, // Invalid
    kRect,    // Rectangular
    kPoly     // Polygonal
  };

  enum ImageDisplayOpt
  {
    kShow          = 1,   // Show
    kShowUnAligned = 2,   // Show unaligned
    kClip          = 4,   // Clip
    kTransparent   = 8    // Transparent
  };
  
  RasterImageImp*  ptrImp() const;
  RasterImageImp*  setPtrImp(RasterImageImp* pImp);

  /** Description:
    Sets the Object ID of the OdDbRasterImageDef object associated with this raster image entity (DXF 340).
    Arguments:
    imageDefId (I) Object ID of image to be displayed.
  */
  OdResult setImageDefId(
    OdDbObjectId imageDefId);

  /** Description:
    Returns the Object ID of the OdDbRasterImageDef object associated with this raster image entity (DXF 340).
  */
  OdDbObjectId imageDefId() const;

  /** Description:
    Sets the OdDbRasterImageDefReactor object associated with this raster image entity (DXF 360).
    Arguments:
    reactorId (I) Object ID of reactor for this image.
    
    Remarks:
    Each OdDbRasterImage object must have an OdDbRasterImageDefReactor associated with the OdDbRasterImageDef
    object it is using. This call makes this OdDbRasterImage object the owner of the reactor object.
  */
  void setReactorId(
    OdDbObjectId reactorId);

  /** Description:
    Returns the Object ID of the OdDbRasterImageDefReactor object associated with this raster image entity (DXF 360).

    Remarks:
    Each OdDbRasterImage object must have an OdDbRasterImageDefReactor associated with the OdDbRasterImageDef
    object it is using.
  */
  OdDbObjectId reactorId() const;

  /** Description:
    Sets the clip boundary for this raster image entity (DXF 71, 14, 24).

    Arguments:
    clipPoints (I) Array of 2D points in pixel coordinates.
  */
  OdResult setClipBoundary(ClipBoundaryType type,
    const OdGePoint2dArray& clipPoints);

  OdResult setClipBoundary(
    const OdGePoint2dArray& clipPoints);

  /** Description:
    Returns the clip boundary for this raster image entity (DXF 14, 24).
    Remarks:
    The clip boundary is specified in pixel coordinates.
  */
  const OdGePoint2dArray& clipBoundary() const;

  /** Description:
    Returns the clipping state for this raster image entity (DXF 280).
  */
  OdBool isClipped() const;

  /** Description:
    Adds the frame *vertices* of this raster image entity to the specified array.
    
    Arguments:
    vertices (I/O) Receives the vertices of the image frame.

    Remarks:
    If isClipped(), these are the *vertices* of the clip boundary. 
    
    If !isClipped(), these are the corners of the image.
  */
  OdResult getVertices(
    OdGePoint3dArray& vertices) const;

  /** Description:
    Sets the clip boundary to coincide with the image corners of this raster image entity. 
    
    Remarks:
    Any existing boundary is deleted.
  */
  virtual OdResult setClipBoundaryToWholeImage(OdGeVector2d& size = OdGeVector2d(0,0));

  /** Description:
    Returns the clip boundary type of this this raster image entity (DXF 71).
  */
  ClipBoundaryType clipBoundaryType() const;

  /** Description
    Returns the pixel-to-model coordinate transformation matrix for this raster image entity.
  */
  virtual OdGeMatrix3d getPixelToModelTransform() const;

  virtual OdResult	getPixelToModelTransform(OdGeMatrix3d&) const;
  virtual void    getEcs(OdGeMatrix3d& retVal) const;
  /** Description:
    Sets the *brightness* value for this raster image entity (DXF 281).
    Arguments:
    brightness (I) Image *brightness* [0.0 .. 100.0].
  */
  OdResult setBrightness( 
    OdInt8 brightness );

  /** Description:
    Returns the *brightness* value for this raster image entity (DXF 281).
    Remarks:
    Returns a value in the range [0.0 .. 100.0].
  */
  OdInt8 brightness() const;

  /** Description:
    Sets the *contrast* value for this raster image entity (DXF 282).
    Arguments:
    contrast (I) Image *contrast*. [0.0 .. 100.0]
  */
  OdResult setContrast( 
    OdInt8 contrast );

  /** Description:
    Returns the *contrast* value for this raster image entity (DXF 282).
    Remarks:
    Returns a value in the range [0.0 .. 100.0].  
  */
  OdInt8 contrast() const;

  /** Description:
    Sets the *fade* value for this raster image entity (DXF 283).

    Arguments:
    fade (I) Image *fade*. [0.0 .. 100.0].
  */
  OdResult setFade( 
    OdInt8 fade );

  /** Description:
    Returns the *fade* value for this raster image entity (DXF 283).
    Remarks:
    Returns a value in the range [0.0 .. 100.0].  
  */
  OdInt8 fade() const;

  /** Description:
    Sets the specified image *display* option for this raster image entity (DXF 70).

    Arguments:
    optionIndex (I) Option index.
    value (I) Value for option.
    
    Remarks:
    option is one of the following:
    
    @table
    Name              Value   Description
    kShow             1       Show
    kShowUnAligned    2       Show unaligned
    kClip             4       Clip
    kTransparent      8       Transparent
  */
  void setDisplayOpt(
    ImageDisplayOpt optionIndex, 
    OdBool value);

  /** Description:
    Returns the specified image *display* *option* for this raster *image* entity (DXF 70).

    Arguments:
    optionIndex (I) Option to return.

  */
  OdBool isSetDisplayOpt(
    ImageDisplayOpt option) const;

  /** Description:
    Returns the size in pixels of this raster *image* entity (DXF 13, 23).
      
    Arguments:
    getCachedValue (I) True to always return cached value. False to return the value from the OdDbRasterImageDef
                        object of available.  
  */
  OdGeVector2d imageSize(
    OdBool getCachedValue = false) const;

  /** Description:
    Returns the effective *scale* factor of this raster *image* entity.
    
    Remarks:
    The effective *scale* factor is the *image* size in drawing units divided by the original *image* size.
    
    If the original *image* size is unavalable, or the user has not defined a drawing unit, the
    *image* width is assumed to be one drawing unit. 
  */
  OdGeVector2d scale() const;

  /** Description:
    Sets the orientation and *origin* of this raster *image* entity.

    Arguments:
    origin (I) Lower-left corner. 
    u (I) Image width vector.
    v (I) Image height vector.
    
    Remarks:
    Returns true if and only if successful.
    
    Note:
    The actual height of the *image* is determined by the width and aspect ratio fo the original *image*. 
    
    These vectors define the outer edges of the raster *image* entity. 
  */
  OdBool setOrientation(
    const OdGePoint3d& origin, 
    const OdGeVector3d& u,
    const OdGeVector3d& v);

  /** Description:
    Returns the orientation and *origin* of this raster *image* entity.

    Arguments:
    origin (O) Receives the lower-left corner. 
    u (O) Receives the vector defining the *image* direction and width. 
    v (O) Receives the vector defining the *direction* of the height of the image.
    
    Note:
    These vectors define the outer edges of the raster image entity.
  */
  void getOrientation(
    OdGePoint3d& origin, 
    OdGeVector3d& u, 
    OdGeVector3d& v) const;

  /** Description:
    Sets the *ClipInverted* flag value for this raster image entity.

    Arguments:
    val (I) The *ClipInverted* flag value.
  */
  void setClipInverted(OdBool val);

  /** Description:
    Returns the *ClipInverted* flag value for this raster image entity.
  */
  OdBool isClipInverted() const;

  OdGiSentScanLines* getScanLines(const OdGiRequestScanLines& req) const;
  OdBool freeScanLines(OdGiSentScanLines* pSSL) const;

  /** Description:
       coment it for a while, because we do not know what it do
     static Oda::ClassVersion classVersion();
  */

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  OdResult subClose();

  virtual OdResult subSwapIdWith(
    OdDbObjectId otherId,
    OdBool swapXdata = false,
    OdBool swapExtDict = false);

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  void subViewportDraw(
    OdGiViewportDraw* pVd);

  OdResult subGetGeomExtents(
    OdDbExtents& extents) const;

  OdResult subGetClassID(
    CLSID* pClsid) const;

  OdResult subTransformBy(
    const OdGeMatrix3d& xfm);

  virtual OdResult subDeepClone(OdDbObject* pOwnerObject,OdDbObject*& pClonedObject,OdDbIdMapping& idMap, OdBool isPrimary = true) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, const OdGePlane& projPlane, OdGePoint3dArray& points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0 ) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,  OdGePoint3dArray& points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0 ) const;

  virtual OdResult subGetTransformedCopy(const OdGeMatrix3d& xfm, OdDbEntity*& pCopy) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const;
  
  virtual void saveAs(OdGiWorldDraw* mode, OdDb::SaveType st);
  virtual bool castShadows() const;
  virtual void setCastShadows(bool newVal);
  virtual bool receiveShadows() const;
  virtual void setReceiveShadows(bool newVal);
  void  baseList() const;
  /*
  virtual void getOsnapPoints( OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark, const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint, const OdGeMatrix3d& viewXform,
    OdGePoint3dArray& snapPoints, OdDbIntArray& geomIds) const;

  virtual void getGripPoints(OdGePoint3dArray& gripPoints,
    OdDbIntArray& osnapModes, OdDbIntArray& geomIds) const;

  virtual void moveGripPointsAt(const OdDbIntArray& indices, const OdGeVector3d& offset);

  virtual void getStretchPoints(OdGePoint3dArray& stretchPoints) const;

  virtual void moveStretchPointsAt(const OdDbIntArray& indices, const OdGeVector3d& offset);

  virtual void transformBy(const OdGeMatrix3d& xform);
  virtual void getTransformedCopy(const OdGeMatrix3d& xform, OdDbEntity** ent) const;
  virtual OdResult explode(OdRxObjectPtrArray& entitySet) const; //Replace OdRxObjectPtrArray
  virtual bool subGetGeomExtents(OdDbExtents& extents) const;

  virtual void getSubentPathsAtGsMarker(OdDb::SubentType type,
    OdGsMarker gsMark, const OdGePoint3d& pickPoint,
    const OdGeMatrix3d& viewXform, int& numPaths,
    OdDbFullSubentPath*& subentPaths, int numInserts = 0,
    OdDbObjectId* entAndInsertStack = 0) const;

  virtual void getGsMarkersAtSubentPath(
    const OdDbFullSubentPath& subPath,
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntityPtr subentPtr(const OdDbFullSubentPath& id) const;
  virtual void saveAs(OdGiWorldDraw* mode, OdDb::EntSaveAsType st);
  virtual void intersectWith(const OdDbEntity* ent,
    OdDb::Intersect intType, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual void intersectWith(const OdDbEntity* ent,
    OdDb::Intersect intType, const OdGePlane& projPlane,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;
  */
};

/** Description:
  Translates the specified point from pixel coordinates to model coordinates.
  Arguments:
  xf, (I) Pixel->Model transformation matrix.
  pixelPoint (I) Pixel point.
  modelPoint (O) Receives the Model point.
*/
inline void pixelToModel(
  const OdGeMatrix3d& xfm,
  const OdGePoint2d& pixelPoint,
  OdGePoint3d& modelPoint)
{
  modelPoint.set(pixelPoint.x, pixelPoint.y, 0);
  modelPoint.transformBy(xfm);
}

/** Description:
  Translates the specified point from model coordinates to pixel coordinates.
  Arguments:
  xfm (I) Model->Pixel transformation matrix.
  pixelPoint (O) Receives the pixel point.
  modelPoint (I) Model point.
  plane (I) Plane on which modelPoint is to be projected prior to transformation.
  viewDir (I) Vector defining the projection direction.
*/
inline void modelToPixel(
  const OdGeMatrix3d& xfm,
  const OdGePoint3d& modelPoint,
  OdGePoint2d& pixelPoint)
{
  OdGePoint3d modelPt = modelPoint;
  modelPt.transformBy(xfm);
  pixelPoint.set(modelPt.x, modelPt.y);
}

inline void modelToPixel(
  const OdGeVector3d& viewDir,
  const OdGeMatrix3d& xfm,
  const OdGePlane& plane,
  const OdGePoint3d& modelPoint,
  OdGePoint2d& pixelPoint)
{
  OdGePoint3d ptOnPlane = modelPoint.project(plane, viewDir);
  ptOnPlane.transformBy(xfm);
  pixelPoint.set(ptOnPlane.x, ptOnPlane.y);
}

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbRasterImage object pointers.
*/
typedef OdSmartPtr<OdDbRasterImage> OdDbRasterImagePtr;

#pragma warning( default : 4239 ) 
#include "TD_PackPop.h"

#endif // __IMGENT_H

