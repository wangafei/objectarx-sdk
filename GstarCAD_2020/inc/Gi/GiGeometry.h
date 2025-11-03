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




#ifndef __ODGIGEOMETRY_H__
#define __ODGIGEOMETRY_H__

#include "../TD_PackPush.h"
#include "../RxObject.h"

#include "../Ge/GePoint3d.h"
#include "../Ge/GeMatrix3d.h"
#include "../Gi/GiClipBoundary.h"
#include "../Gi/GiImage.h"
#include "../Gi/GiRasterImage.h"

class OdDbStub;
class OdCmEntityColor;
class OdGeMatrix3d;
class OdGeVector3d;
//class OdGePoint3d;
class OdGePoint2d;
class OdGiPathNode;
class OdGiMapper;
class OdCmTransparency;
class OdGeDashLine3d;
class OdGeMultiDashLine3d;

class OdGiSilhouetteData
{
public:
  OdGeVector3d m_viewdir;
  struct SilhouetteData
  {
    OdInt32 faceIndex;
    OdInt32 edgeIndex;
    OdInt32 verticesIndices[2];
  };
  OdArray<SilhouetteData> m_data;
};
/** Description:
    This class represents arrays of edge attributes for meshes and shells.
    
    Remarks:
    EdgeData objects are optional; they can be optionally passed 
    to OdGiWorldGeometry and OdGiViewportGeometry when using their 
	mesh and shell methods. 
    
	Note: Setting an 'improper' size of any array will cause
    unpredictable or fatal results.

    Library:
    TD_Gi

    {group:OdGi_Classes} 
*/
class OdGiEdgeData
{
  const short*            m_pColors;
  const OdCmEntityColor*  m_pTrueColors;
        OdDbStub**        m_pLayerIds;
        OdDbStub**        m_pLinetypeIds;
  const OdGsMarker*       m_pSelectionMarkers;
  const OdUInt8*          m_pVisibilities;
  OdGiSilhouetteData*     m_pSilhouetteData;
public:
  OdGiEdgeData()
    : m_pColors(NULL)
    , m_pTrueColors(NULL)
    , m_pLayerIds(NULL)
    , m_pLinetypeIds(NULL)
    , m_pSelectionMarkers(NULL)
    , m_pVisibilities(NULL)
    , m_pSilhouetteData(NULL)
  {}

  /** Description:
    Sets the edge colors to be used by this object.

    Arguments:
    colors (I) Array of color indices.
        
    Note:
    You cannot call both setColors() and setTrueColors().
    
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setColors(
    const short *colors)                    { m_pColors = colors; }

  /** Description:
    Sets the edge colors to be used by this object.

    Arguments:
    colors (I) Array of OdCmEntityColor objects.
        
    Note:
    You cannot call both setColors() and setTrueColors().

    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setTrueColors(
    const OdCmEntityColor *colors)         { m_pTrueColors = colors; }

  /** Description:
    Sets the edge Layer Table Records to be used by this object.

    Arguments:
    layerIds (I) Array of LayerTableRecord Object IDs.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setLayers(
    OdDbStub* *layerIds)                       { m_pLayerIds = layerIds; }

  /** Description:
    Sets the edge Linetype Table Records to be used by this object.

    Arguments:
    linetypeIds (I) Array of LinetypeTableRecord Object IDs.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setLinetypes(
    OdDbStub* *linetypeIds)                 { m_pLinetypeIds = linetypeIds; }

  /** Description:
    Sets the edge graphics system selection markers to be used by this object.

    Arguments:
    selectionMarkers (I) Array of graphics system selection markers.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setSelectionMarkers(
    const OdGsMarker* selectionMarkers) { m_pSelectionMarkers = selectionMarkers; }

  /** Description:
    Sets the edge visibilities to be used by this object.

    Arguments:
    visibilities (I) Array of visibility values.

    Remarks:
    Each visibility must be one of the following:
     
    @table
    Name              Value   Description
    kOdGiInvisible    0       Invisible 
    kOdGiVisible      1       Visible 
    kOdGiSilhouette   2       Silhouette edge 
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setVisibility(
    const OdUInt8* visibilities)           { m_pVisibilities = visibilities; }
  
  /** Description:
    Returns the array of edge colors used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const short* colors() const           { return m_pColors; }

  /** Description:
    Returns the array of edge colors used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdCmEntityColor* trueColors() const       { return m_pTrueColors; }

  /** Description:
    Returns the array of edge LayerTableRecord Object IDs used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  OdDbStub** layerIds() const         { return m_pLayerIds; }

  /** Description:
    Returns the array of edge LinetypeTableRecord Object IDs used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  OdDbStub** linetypeIds() const      { return m_pLinetypeIds; }

  /** Description:
    Returns the array of edge graphics system selection markers used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdGsMarker* selectionMarkers() const { return m_pSelectionMarkers; }

  /** Description:
    Returns the array of edge visibilities used by this object.

    Remarks:
    Each visibility must be one of the following:
     
    @table
    Name              Value   Description
    kOdGiInvisible    0       Invisible 
    kOdGiVisible      1       Visible 
    kOdGiSilhouette   2       Silhouette edge 

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdUInt8* visibility() const       { return m_pVisibilities; }

  OdGiSilhouetteData*   silhouetteData() const { return m_pSilhouetteData; }
  void setSilhouetteData(OdGiSilhouetteData* pSilhouetteData) {   m_pSilhouetteData = pSilhouetteData; }
};


/** Description:
    This class contains arrays of face attributes for meshes and shells.

    Library:
    TD_Gi

    {group:OdGi_Classes} 
*/
class OdGiFaceData
{
  const short*            m_pColors;
  const OdCmEntityColor*  m_pTrueColors;
        OdDbStub**        m_pLayerIds;
  const OdGsMarker*       m_pSelectionMarkers;
  const OdUInt8*          m_pVisibilities;
  const OdGeVector3d*     m_pNormals;
        OdDbStub**        m_pMaterialIds;
  const OdGiMapper*       m_pMappers;
  const OdCmTransparency* m_pTransparency;
public:
  OdGiFaceData()
    : m_pColors(NULL)
    , m_pTrueColors(NULL)
    , m_pLayerIds(NULL)
    , m_pSelectionMarkers(NULL)
    , m_pVisibilities(NULL)
    , m_pNormals(NULL)
    , m_pMaterialIds(NULL)
    , m_pMappers(NULL)
    , m_pTransparency(NULL)
  {}

  /** Description:
    Sets the face colors to be used by this object.

    Arguments:
    colors (I) Array of color indices.
        
    Note:
    You cannot call both setColors() and setTrueColors().

    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setColors(
    const short *colors)                    { m_pColors = colors; }

  /** Description:
    Sets the face colors to be used by this object.

    Arguments:
    colors (I) Array of OdCmEntityColor objects.
        
    Note:
    You cannot call both setColors() and setTrueColors().

    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setTrueColors(
    const OdCmEntityColor *colors)         { m_pTrueColors = colors; }

  /** Description:
    Sets the face Layer Table Records to be used by this object.

    Arguments:
    layerIds (I) Array of LayerTableRecord Object IDs.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setLayers(
    OdDbStub* *layerIds)                       { m_pLayerIds = layerIds; }

  /** Description:
    Sets the face graphics system selection markers to be used by this object.

    Arguments:
    selectionMarkers (I) Array of graphics system selection markers.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setSelectionMarkers(
    const OdGsMarker* selectionMarkers) { m_pSelectionMarkers = selectionMarkers; }

  /** Description:
    Sets the face normal vectors to be used by this object.

    Arguments:
    normals (I) Array of normal vectors.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setNormals(
    const OdGeVector3d* normals)              { m_pNormals = normals; }

  /** Description:
    Sets the face visibilities to be used by this object.

    Arguments:
    visibilities (I) Array of visibility values.

    Remarks:
    Each visibility must be one of the following:
     
    @table
    Name              Value   Description
    kOdGiInvisible    0       Invisible 
    kOdGiVisible      1       Visible 
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setVisibility(
    const OdUInt8* visibilities)           { m_pVisibilities = visibilities; }

  /** Description:
    Sets the face material object IDs to be used by this object.

    Arguments:
    materialIds (I) Array of material object IDs.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setMaterials(
    OdDbStub* *materialIds)                { m_pMaterialIds = materialIds; }

  /** Description:
    Sets the face material mappers to be used by this object.

    Arguments:
    mappers (I) Array of material mappers.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setMappers(
    const OdGiMapper* mappers)             { m_pMappers = mappers; }

  /** Description:
    Sets the face transparency to be used by this object.

    Arguments:
    transparencies (I) Array of OdCmTransparency objects.
        
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setTransparency(
    const OdCmTransparency *transparencies) { m_pTransparency = transparencies; }

  /** Description:
    Returns the array of face colors used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const short* colors() const           { return m_pColors; }

  /** Description:
    Returns the array of face *colors* used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdCmEntityColor* trueColors() const       { return m_pTrueColors; }

  /** Description:
    Returns the array of face LayerTableRecord Object IDs used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  OdDbStub** layerIds() const         { return m_pLayerIds; }

  /** Description:
    Returns the array of face graphics system selection markers used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdGsMarker* selectionMarkers() const { return m_pSelectionMarkers; }

  /** Description:
    Returns the array of face normal vectors used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdGeVector3d* normals() const          { return m_pNormals; }

  /** Description:
    Returns the array of edge visibilities used by this object.

    Remarks:
    Each visibility must be one of the following:
     
    @table
    Name              Value   Description
    kOdGiInvisible    0       Invisible 
    kOdGiVisible      1       Visible 

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdUInt8* visibility() const       { return m_pVisibilities; }

  /** Description:
    Returns the array of face material object IDs used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  OdDbStub** materials() const            { return m_pMaterialIds; }

  /** Description:
    Returns the array of face material mappers used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdGiMapper* mappers() const       { return m_pMappers; }

  /** Description:
    Returns the array of face transparency used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdCmTransparency* transparency() const { return m_pTransparency; }
};

typedef enum
{
  kOdGiCounterClockwise = -1,
  kOdGiNoOrientation    = 0,
  kOdGiClockwise        = 1
} OdGiOrientationType;


/** Description:
    This class contains arrays of vertex attributes for meshes and shells.
    
    Remarks:
    VertexData objects are optional; they can be optionally passed 
    to OdGiWorldGeometry and OdGiViewportGeometry when using their 
	mesh and shell methods.
	
	Note: Setting an 'improper' size of any array will cause
    unpredictable or fatal results.

    Library:
    TD_Gi

    {group:OdGi_Classes} 
*/
class OdGiVertexData
{
  const OdGeVector3d*    m_pNormals;
  OdGiOrientationType    m_orientationFlag;
  const OdCmEntityColor* m_pTrueColors;
  const OdGePoint3d*     m_pMappingCoords;
public:
  OdGiVertexData()
    : m_pNormals(NULL)
    , m_orientationFlag(kOdGiNoOrientation)
    , m_pTrueColors(NULL)
    , m_pMappingCoords(NULL)
  {}

  enum MapChannel { kAllChannels = 0 };

  /** Description:
    Sets the vertex normal vectors to be used by this object.

    Arguments:
    normals (I) Array of normal vectors.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setNormals(
    const OdGeVector3d* normals)              { m_pNormals = normals; }

  /** Description:
    Sets the orientation type to be used by this object.
    
    Arguments:
    orientationFlag (I) Orientation type.
    
    Remarks:
    The orientation type defines the positive direction of the normal at the vertices.
    
    orientationFlag must be one of the following:
    
    @table
    Name                      Value 
    kOdGiCounterClockwise     -1
    kOdGiNoOrientation        0
    kOdGiClockwise            1

  */
  void setOrientationFlag(
    const OdGiOrientationType orientationType) { m_orientationFlag = orientationType; }

  /** Description:
    Sets the vertex colors to be used by this object.

    Arguments:
    colors (I) Array of OdCmEntityColor objects.
        
    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setTrueColors(
    const OdCmEntityColor *colors)         { m_pTrueColors = colors; }

  /** Description:
    Sets the mapping coordinates to be used by this object.

    Arguments:
    channel [in]  Specifies mapping channel.
    coords [in]  Array of OdGePoint3d objects.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. An incorrect number of elements will have unpredictable or fatal consequences.
  */
  void setMappingCoords(
    MapChannel channel,
    const OdGePoint3d *coords)             { ODA_ASSERT(channel == kAllChannels); m_pMappingCoords = coords; }

  /** Description:
    Returns the array of vertex normal vectors used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdGeVector3d* normals() const         { return m_pNormals; }

  /** Description:
    Returns the direction of the normal at the vertices that is used by this object.
    
    Remarks:  
    orientationFlag must be one of the following:
    
    @table
    Name                      Value 
    kOdGiCounterClockwise     -1
    kOdGiNoOrientation        0
    kOdGiClockwise            1

  */
  OdGiOrientationType orientationFlag() const { return m_orientationFlag; }

  /** Description:
    Returns the array of vertex colors used by this object.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdCmEntityColor* trueColors() const   { return m_pTrueColors; }

  /** Description:
    Returns the array of mapping coordinates used by this object.

    Arguments:
    channel [in]  Specifies mapping channel.

    Note:
    This function does not make a copy of the array, which should have the same number of elements as the 
    mesh or shell with which it is used. Writing beyond the array bounds will have unpredictable or fatal consequences.
  */
  const OdGePoint3d* mappingCoords(MapChannel channel) const { ODA_ASSERT(channel == kAllChannels); return m_pMappingCoords; }
};

class OdGiDrawable;
struct OdGiClipBoundary;
class OdGiAbstractClipBoundary;

class OdDbPolyline;
class OdPolyPolygon3d;
class OdGeNurbCurve3d;
class OdGiTextStyle;
class OdDbBody;
class OdGeEllipArc3d;
class OdGiPolyline;


/** Description:
    Arc types
*/
typedef enum
{
  kOdGiArcSimple = 0,   // Unfilled.
  kOdGiArcSector = 1,   // Filled area bounded by the arc and its center.
  kOdGiArcChord  = 2    // Filled area bounded by the arc and its end points
} OdGiArcType;


typedef enum 
{ 
  kOdGiWorldPosition,
  kOdGiViewportPosition,
  kOdGiScreenPosition,
  kOdGiScreenLocalOriginPosition,
  kOdGiWorldWithScreenOffsetPosition
}OdGiPositionTransformBehavior;

typedef enum 
{ 
  kOdGiWorldScale,
  kOdGiViewportScale,
  kOdGiScreenScale,
  kOdGiViewportLocalOriginScale,
  kOdGiScreenLocalOriginScale
}OdGiScaleTransformBehavior;

typedef enum 
{ 
  kOdGiWorldOrientation,
  kOdGiScreenOrientation,
  kOdGiZAxisOrientation
}OdGiOrientationTransformBehavior;

/** Description:
    This class defines functions that allow entities to vectorize themselves.

    Library:
    TD_Gi

    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiGeometry : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiGeometry);

  enum TransparencyMode
  {
    kTransparencyOff,  // pixel alpha ignored, all pixels are opaque
    kTransparency1Bit, // pixel alpha determines transparency on/off,
    // with 0 to 254 completely transparent and 255 completely opaque
    kTransparency8Bit, // pixel alpha determines transparency level,
    // from 0 (completely transparent) to 255 (completely opaque)
  };
  /** Description:
    Returns the model-to-world coordinate transform matrix for the entity being vectorized.
    
    Remarks:
    This is the inverse of the matrix returned by getWorldToModelTransform(). 

    If an entity is in one or more blocks, this matrix can be used to
    determine the WCS coordinates of the entity.  
  */
  virtual OdGeMatrix3d getModelToWorldTransform() const;
  //DD2ARX - xi hui - 2008-07-07 - AcGiGeometry::getXXXXXToXXXXXTransform
  virtual void getModelToWorldTransform(OdGeMatrix3d& unnamed) const = 0;

  /** Description:
    Returns the world-to-model coordinate transform matrix for the entity being vectorized.
    
    Remarks:
    This is the inverse of the matrix returned by getModelToWorldTransform(). 
  */
  virtual OdGeMatrix3d getWorldToModelTransform() const;
  //DD2ARX - xi hui - 2008-07-07 - AcGiGeometry::getXXXXXToXXXXXTransform
  virtual void getWorldToModelTransform(OdGeMatrix3d& unnamed) const = 0;
  
  /** Description:
    Specifies a model transformation matrix for the current transformation stack.  
    
    Remarks:
    When a vector is specified, the transformation is created using the arbitrary axis algorithm 
    on the vector. 
 
    The specified transformation is concatenated to the current model transformation 
	(which is initially the identity transform). The resulting model transformation 
	is subsequently applied to all geometry introduced into this vectorization context, 
	until popModelTransform() is called.
    
    Arguments:
    normal (I) Normal vector.
    xfm (I) Transformation matrix.
    
  */
  virtual OdBool pushModelTransform(
    const OdGeVector3d& normal) = 0;

  virtual OdBool pushModelTransform(
    const OdGeMatrix3d& xfm) = 0;

  /** Description:
    Removes the top transformation off the current transformation stack.
  */
  virtual OdBool popModelTransform() = 0;
  
  /** Description:
    Introduces a circle to this vectorization context.  
    
    Remarks:
    The circle is not filled and takes on the current color.
    
    If firstPoint, secondPoint, and thirdPoint are specified, they
    cannot be colinear and no two can be coincident.

    Arguments:
    center (I) Center point.
    radius (I) Radius.
    normal (I) Normal.
  */
  virtual OdBool circle(
    const OdGePoint3d& center, 
    const double radius, 
    const OdGeVector3d& normal) const = 0;
  
  /** Arguments:
    firstPoint (I) First point of a 3-point circle.
    secondPoint (I) Second point of a 3-point circle.
    thirdPoint (I) Third point of a 3-point circle.
  */
  virtual OdBool circle(
    const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint, 
    const OdGePoint3d& thirdPoint) const = 0;
  
/** Description:
    Introduces a circular arc to this vectorization context.  
    
    Arguments:
    center (I) Center point.
    radius (I) Radius.
    normal (I) Normal vector.
    startVector (I) Start of the arc.
    sweepAngle (I) Angle that defines the arc.
    arcType (I) Arc type.
    
    Remarks:
    The arc takes on the current color.      

    If firstPoint, secondPoint, and thirdPoint are specified, they
    cannot be colinear and no two can be coincident.
    
    arcType must be one of the following:
    
    @table
    Name              Value     Description
    kOdGiArcSimple    0         Unfilled.
    kOdGiArcSector    1         Filled area bounded by the arc and its center.
    kOdGiArcChord     2         Filled area bounded by the arc and its end points
    
    Note:
    All angles are expressed in radians.
  */
  virtual OdBool circularArc(
    const OdGePoint3d& center,
    const double radius,
    const OdGeVector3d& normal,
    const OdGeVector3d& startVector,
    const double sweepAngle,
    const OdGiArcType arcType = kOdGiArcSimple) const = 0;
  
  /** Arguments:
    firstPoint (I) First point of a 3-point arc.
    secondPoint (I) Second point of a 3-point arc.
    thirdPoint (I) Third point of a 3-point arc.
  */
  virtual OdBool circularArc(
    const OdGePoint3d& firstPoint,
    const OdGePoint3d& secondPoint,
    const OdGePoint3d& thirdPoint,
    const OdGiArcType arcType = kOdGiArcSimple) const = 0;

  /** Description:
    Introduces a polyline to this vectorization context.  
    
    Remarks:
    The polyline is unfilled and takes on the current color and thickness. Use polygon() to render filled areas.
    
    The polyline is rendered as a series of lines connecting the first point
    in vertexList to the second, the second to the third, etc.
    All points must be coplanar.

    Use polygon() to render closed areas.

    Arguments:
    numVertices (I) Number of vertices.
    vertexList (I) Array of vertices.
    pNormal (I) Pointer to the normal vector.
    baseSubEntMarker (I) Not used.
  */
  virtual OdBool polyline(
    const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1) const = 0;
#if 0 
#if defined(_MSC_VER) && (_MSC_VER >= 1400)
#pragma warning (push)
#pragma warning (disable: 4481) // Non-standard extension used

// The right function prototype was changed (see above). Old one left to cause compilation error
  virtual OdBool polyline(
    OdInt32 /* numVertices */,
    const OdGePoint3d* /* vertexList */,
    const OdGeVector3d* /* pNormal */,
    OdInt32 /* baseSubEntMarker */) sealed {ODA_FAIL();return ::kFalse;}
#pragma warning (pop)
#endif
#endif
  /** Description:
    Introduces a polygon to this vectorization context.  
    
    Remarks:
    The polygon is filled and takes on the current color. Use polyline() to render unfilled areas.

    The polygon is rendered as a series of lines connecting the first point
    in vertexList to the second, the second to the third, etc.
    All points must be coplanar.

    Arguments:
    numVertices (I) Number of vertices.
    vertexList (I) Array of vertices.
  */
  virtual OdBool polygon(
    const OdUInt32 numVertices, 
    const OdGePoint3d* vertexList) const = 0;

  virtual OdBool polyPoints(
    const OdUInt32 numVertices, 
    const OdGePoint3d* vertexList,
    OdLongPtr baseSubEntMarker = -1) const
  {
    return kFalse;
  }

  virtual OdBool lineSegs(
    const OdUInt32 numSegs , 
    const OdGePoint3d * vertexList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1) const 
  {
    return kFalse;
  }

  virtual OdBool dashLineSegs(
    const OdUInt32 numSegs,
    const OdGeDashLine3d* dlList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1) const 
  {
    return kFalse;
  }

  virtual OdBool dashLineSegs(
    const OdGeMultiDashLine3d* dlList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1) const
  {
    return kFalse;
  }

  /** Description:
    Introduces a lightweight polyline into this vectorization context.
    
    Remarks:
    The polyline may contain varying segment widths, straight segments
    and arc segments.    

    The polyline takes on the current color.
    
    All points must be coplanar.

    Arguments:
    polyline (I) Polyline.
    fromIndex (I) Index of the first segment to be processed.
    numSegs (I) Number of segments to be processed (0 indicates all segments).
  */
  virtual OdBool pline(
    const OdGiPolyline& polyline, 
    OdUInt32 fromIndex = 0, 
    OdUInt32 numSegs = 0) const
  {
    return kFalse;
  }

  virtual OdBool pline(
    const OdDbPolyline& polyline, 
    OdUInt32 fromIndex = 0, 
    OdUInt32 numSegs = 0) const = 0;

  /** Description:
    Introduces a mesh into this vectorization context.  
    
    Arguments:
    numRows (I) Number of rows.
    numColumns (I) Number of columns.
    vertexList (I) Array of vertices.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.
    pVertexData (I) Pointer to additional vertex data. 

    Remarks:
    A mesh is a surface defined by a grid of vertices, and corresponds to a Polygon Mesh.
    By default, a mesh takes on the current color. Color, linetype, and
    and other properties can be controlled supplying the appropriate
    data for the pEdgeData, pFaceData, and pVertexData arguments.

    Notes:
    o  vertexList must have numRows ?numColumns elements.
    
    o  The arrays in *pEdgeData must be NULL or contain (numRows - 1) ?numColumns + numRows ?(numColumns -1) elements.
    
    o  The arrays in *pFaceData must be NULL or contain (numRows - 1) ?(numColumns - 1) elements.
    
    o  The arrays in *pVertexData must be NULL or contain numRows ?numColumns elements. 
  */
  virtual OdBool mesh(
    const OdUInt32 numRows,
    const OdUInt32 numColumns,
    const OdGePoint3d* vertexList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0,const bool bAutoGenerateNormals = true) const = 0;
  
  /** Description:
    Introduces a shell into this vectorization context.  
    
    Remarks:
    A shell is a set of faces that can contain holes, and corresponds to a Polyface mesh.

    By default, a mesh takes on the current color. Color, linetype, and
    and other properties can be controlled supplying the appropriate
    data for the pEdgeData, pFaceData, and pVertexData arguments.
    
    See Also:
    Faces
      
    Arguments:
    numVertices (I) Number of vertices.
    vertexList (I) Array of vertices.
    faceListSize (I) Number of entries in facesList.
    faceList (I) Array of integers defining faces.
    pEdgeData (I) Pointer to additional edge data.
    pFaceData (I) Pointer to additional face data.
    pVertexData (I) Pointer to additional vertex data. 

    Notes:
    o  The arrays in *pEdgeData must be NULL or contain the same number of elements as there are edges.
    
    o  The arrays in *pFaceData must be NULL or contain the same number of elements as there are faces.
    
    o  The arrays in *pVertexData must be NULL or contain numVertices elements. 

  */
  virtual OdBool shell(
    const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdUInt32 faceListSize,
    const OdInt32* faceList,
    const OdGiEdgeData* pEdgeData = 0,
    const OdGiFaceData* pFaceData = 0,
    const OdGiVertexData* pVertexData = 0,
    const struct resbuf* pResBuf = NULL,
    const bool bAutoGenerateNormals = true) const = 0;
  
  /** Description:
    Introduces text into this vectorization context.
    
    Arguments:
    position (I) Position of the text string.
    normal (I) Normal vector of the text.
    direction (I) Baseline direction of the text.
    height (I) Height of the text.
    width (I) Width factor of the text.
    oblique (I) Oblique angle.
    msg (I) Text string.

    Remarks:
    The text takes on the current color.
 
    If numBytes is not specified, msg must be null terminated.
    
    Note:
    All angles are expressed in radians.

    As currently implemented, this function ignores width and oblique.
    They will be fully implemented in a future release.
  */
  virtual OdBool text(
    const OdGePoint3d& position,
    const OdGeVector3d& normal, 
    const OdGeVector3d& direction,
    const double height, 
    const double width, 
    const double oblique, 
	  const OdChar * msg) const = 0;
  /** Arguments:
    length (I) Number of characters in msg (not including the optional null character).
    raw (I) If and only if true, escape sequences, such as %%P, will not be converted to special characters.
    pTextStyle (I) Pointer to the TextStyle for the *text*.
  */
  virtual OdBool text(
    const OdGePoint3d& position,
    const OdGeVector3d& normal, 
    const OdGeVector3d& direction,
    const OdChar* msg, 
    const OdInt32 length, 
    const OdBool raw, 
    const OdGiTextStyle& pTextStyle) const = 0;
  /** Description:
    Introduces an Xline into this vectorization context.  
      
    Remarks:
    Xlines are infinite lines passing through two points.
 
    The *xline* takes on the current color.
    
    Arguments:
    firstPoint (I) First point.
    secondPoint (I) Second point.
  */
  virtual OdBool xline(
    const OdGePoint3d& firstPoint, 
    const OdGePoint3d& secondPoint) const = 0;

  /** Description:
    Introduces a Ray into this vectorization context.  
    
    Remarks:
    A Ray is a semi-infinite line that starts at the basePoint, and passes 
    through the throughPoint.

    The *ray* takes on the current *color*.
 
    Arguments:
    basePoint (I) Base point.
    throughPoint (I) Through point
  */
  virtual OdBool ray(
    const OdGePoint3d& basePoint, 
    const OdGePoint3d& throughPoint) const = 0;
  
  /** Description:
    Introduces a NURBS curve into this vectorization context.
      
    Remarks:
    The curve takes on the current *color*.
    
    Arguments:
    nurbsCurve (I) NURBS curve data.
  */
  virtual OdBool nurbs(
    const OdGeNurbCurve3d& nurbsCurve,const OdGeVector3d* pNormal = 0) const 
  {
    return kFalse;
  }

  /** Description:
    Introduces an elliptical arc into this vectorization context.
        
    Arguments:
    ellipArc (I) Elliptical arc.
    endPointsOverrides (I) Array of points to be used as the first and last points of the vectorized arc.
    arcType (I) Arc type.
        
    Remarks:
    arcType must be one of the following:
    
    @table
    Name              Value     Description
    kOdGiArcSimple    0         Unfilled.
    kOdGiArcSector    1         Filled area bounded by the arc and its center.
    kOdGiArcChord     3         Filled area bounded by the arc and its end points
  */
  virtual OdBool ellipArc(
    const OdGeEllipArc3d& ellipArc,
    const OdGePoint3d* endPointsOverrides = 0,
    OdGiArcType arcType = kOdGiArcSimple) const 
  {
    return kFalse;
  }

  /** Description:
    Introduces the specified object into this vectorization context.
    
    Arguments:
    pDrawable (I) Pointer to the Drawable object.

    Remarks:
    Implementations of this method are expected to do the following:

    o  Call OdGiDrawable::subSetAttributes to set attribute information for the object.
    o  Call subWorldDraw on the drawable object  to vectorize it into this context.
    o  If subWorldDraw returns false, call subViewportDraw each viewport.
  */
  virtual OdBool draw(
    OdGiDrawable* pDrawable) const = 0;

  /** Description:
    Specifies a clip boundary for the current clip stack.
    
    Remarks:
    Subsequent objects are clipped until popClipBoundary() is called.
    
    Arguments:
    pBoundary (I) Pointer to the boundary.
  */
  virtual OdBool pushClipBoundary(
    OdGiClipBoundary* pBoundary) = 0;

  /** Description:
    Removes the top clip boundary from the clip stack.
  */
  virtual void popClipBoundary() = 0;

  /** Description:
    Introduces a line into this vectorization context.  

	Arguments:
    points (I) Array of WCS start and end points.
    
	Remarks:
    The current model transformation is not applied to the line.
  */
  virtual OdBool worldLine(const OdGePoint3d pnts[2]) 
  {
    return kFalse;
  };
  /** Description:
  */
  virtual const OdGiPathNode* currentGiPath() const
  {
    return 0;
  }
 /** Description:
    Specifies a clip boundary with additional clipping information for the current clip stack.

    Remarks:
    Subsequent objects are clipped until popClipBoundary() is called.

    Arguments:
    pBoundary (I) Pointer to the boundary.
    pClipInfo (I) Additional clipping information.
  */
  virtual OdBool pushClipBoundary(
    OdGiClipBoundary* pBoundary, OdGiAbstractClipBoundary* pClipInfo)
	{
	  return pushClipBoundary(pBoundary);
	}

  /** \details
    Introduces an array of points to this vectorization context.

    \param numPoints [in]  Number of point in array.
    \param vertexList [in]  Array of points.
    \param pColors [in]  Array of colors.
    \param pTransparency [in]  Array of transparencies.
    \param pNormals [in]  Optional array of normal vectors.
    \param pSubEntMarkers [in]  Optional array of subentity markers.
    \param nPointSize [in]  Size of points in pixels.

    \remarks
    The points takes on the current color if pColors array doesn't specified.

    Lengths of pColors, pTransparency, pNormals and pSubEntMarkers arrays if them set must be equal to numPoints.
  */
  virtual OdBool polypoint(
    OdInt32 numPoints,
    const OdGePoint3d* vertexList,
    const OdCmEntityColor* pColors,
    const OdCmTransparency* pTransparency,
    const OdGeVector3d* pNormals = NULL,
    const OdGsMarker* pSubEntMarkers = NULL,
    OdInt32 nPointSize = 0);
  ODRX_SEALED_VIRTUAL OdBool polypoint(
    OdInt32 numPoints,
    const OdGePoint3d* vertexList,
    const OdCmEntityColor* pColors,
    const OdGeVector3d* pNormals = NULL,
    const OdGsMarker* pSubEntMarkers = NULL) ODRX_SEALED;
  ODRX_SEALED_VIRTUAL OdBool polypoint(
    OdInt32 numPoints,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormals = NULL,
    const OdGsMarker* pSubEntMarkers = NULL) ODRX_SEALED;

  virtual OdBool image(
    const OdGiImageBGRA32& imageSource,
    const OdGePoint3d& position,
    const OdGeVector3d& u,
    const OdGeVector3d& v,
    TransparencyMode transparencyMode = kTransparency8Bit) const;

  enum POLYLINEEXFLAGS
  {
    kNormal = 0,
    kOnlyHighlight = 0x01,
    kLinetypeGen   = 0x02
  };
  virtual OdBool polylineEx(
    const OdUInt32 numVertices,
    const OdGePoint3d* vertexList,
    const OdGeVector3d* pNormal = 0,
    OdLongPtr baseSubEntMarker = -1,
    int flags = 0) const
  {
    if((flags & kOnlyHighlight) == 0)
    {
      return polyline(numVertices, vertexList, pNormal, baseSubEntMarker);
    }
    return kFalse;
  }

  enum DrawOperator
  {
    kNone = 0,
    kBeginEdgeModelIsolines,
    kEndEdgeModelIsolines,
    kBeginEdge,
    kEndEdge,
    kBeginTransients,
    kEndTransients,
    kBeginOnlyHightlight,
    kEndOnlyHightlight
  };
  virtual OdBool drawOperator(OdUInt32 op, void *pData) const
  {
    return kFalse;
  }
};


inline OdBool OdGiGeometry::polypoint(OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* /*pColors*/,
  const OdCmTransparency* /*pTransparency*/, const OdGeVector3d* pNormals, const OdGsMarker* pSubEntMarkers,
  OdInt32 /*nPointSize*/)
{
  OdGePoint3d tmpVerts[2];
  for (OdInt32 nPoint = 0; nPoint < numPoints; nPoint++)
  {
    const OdGeVector3d *pNormal = (pNormals) ? (pNormals + nPoint) : NULL;
    const OdGsMarker baseSubEntMarker = (pSubEntMarkers) ? pSubEntMarkers[nPoint] : -1;
    tmpVerts[1] = tmpVerts[0] = vertexList[nPoint];
    polyline(2, tmpVerts, pNormal, baseSubEntMarker);
  }

  return kTrue;
}

inline OdBool OdGiGeometry::polypoint(OdInt32 numPoints, const OdGePoint3d* vertexList, const OdCmEntityColor* pColors,
  const OdGeVector3d* pNormals, const OdGsMarker* pSubEntMarkers)
{
  return polypoint(numPoints, vertexList, pColors, NULL, pNormals, pSubEntMarkers);
}

inline OdBool OdGiGeometry::polypoint(OdInt32 numPoints, const OdGePoint3d* vertexList,
  const OdGeVector3d* pNormals, const OdGsMarker* pSubEntMarkers)
{
  return polypoint(numPoints, vertexList, NULL, pNormals, pSubEntMarkers);
}

inline OdBool OdGiGeometry::image(const OdGiImageBGRA32& imageSource,
  const OdGePoint3d& position,
  const OdGeVector3d& u,
  const OdGeVector3d& v,
  TransparencyMode transparencyMode) const
{
  return kFalse;
}

/** Description:
This class is used to ensure OdGiGeometry::pushClipBoundary()/OdGiGeometry::popClipBoundary() 
consistency (exception safety).

Library:
TD_Gi

{group:OdGi_Classes} 
*/
class OdGiClipBoundarySaver
{
  bool m_bSave;
  OdGiGeometry& m_geom;
public:
  OdGiClipBoundarySaver(OdGiGeometry& geom, bool bSave) : m_bSave(bSave), m_geom(geom){}
  void setSave(bool bSave){m_bSave = bSave;}
  ~OdGiClipBoundarySaver()
  {
    if (m_bSave)
      m_geom.popClipBoundary();
  }
};

/** Description:
This class is used to ensure OdGiGeometry::pushModelTransform()/OdGiGeometry::popModelTransform() 
consistency (exception safety).

Library:
TD_Gi

{group:OdGi_Classes} 
*/
class OdGiModelTransformSaver
{
  OdGiGeometry& m_geom;
  OdBool        m_bIdentity;
public:
  OdGiModelTransformSaver(OdGiGeometry& geom, const OdGeMatrix3d& xMat) : m_geom(geom)
  {
    m_bIdentity = xMat.isEqualTo(OdGeMatrix3d::kIdentity);
    if (!m_bIdentity)
      m_geom.pushModelTransform(xMat);
  }
  ~OdGiModelTransformSaver()
  {
    if (!m_bIdentity)
      m_geom.popModelTransform();
  }
};

#include "../TD_PackPop.h"

#endif

