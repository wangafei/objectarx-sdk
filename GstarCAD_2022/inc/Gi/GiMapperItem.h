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

// Mapper item.

#ifndef __ODGIMAPPERITEM_H__
#define __ODGIMAPPERITEM_H__

#include "GiExport.h"
#include "GiMaterial.h"
#include "GiMaterialTraitsData.h"
#include "GiGeometry.h"

#include "../Ge/GePoint2d.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeMatrix3d.h"
#include "../Ge/GeExtents3d.h"

#include "../RxObject.h"

#include "../TD_PackPush.h"

/** Description:
    Material mapper item entry for separate texture channel.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMapperItemEntry : public OdRxObject
{
  public:
    /** Description:
      Input mapper triangle type.
    */
    struct MapInputTriangle {
      OdGePoint3d inPt[3]; // Mapping xyz
    };
    /** Description:
      Output mapper vertices texture coordinates.
    */
    struct MapOutputCoords {
      OdGePoint2d outCoord[3]; // Mapped uv
    };
  public:
    ODRX_DECLARE_MEMBERS(OdGiMapperItemEntry);

    /** Description:
      Return mapper (return result mapper combination for *pMapper* and *pInheritMapper*).
      See also:
      setMapper
    */
    virtual const OdGiMapper &mapper() const = 0;
    /** Description:
      Set mapper combination.
      Arguments:
      pMapper (I) Entity mapper.
      pInheritMapper (I) Material (default) mapper.
    */
    virtual void setMapper(const OdGiMapper &pMapper, const OdGiMapper &pInheritMapper) = 0;
    /** Description:
      Set mapper combination and object/model matrix.
      Arguments:
      pMapper (I) Entity mapper.
      pInheritMapper (I) Material (default) mapper.
      tm (I) Model or object matrix.
    */
    virtual void setMapper(const OdGiMapper &pMapper, const OdGiMapper &pInheritMapper, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for material (entity mapper not specified).
      Arguments:
      pMaterialMapper (I) Material mapper.
    */
    virtual void setMapper(const OdGiMapper &pMaterialMapper) = 0;
    /** Description:
      Set mapper for material and object/model matrix.
      Arguments:
      pMaterialMapper (I) Material mapper.
      tm (I) Model or object matrix.
    */
    virtual void setMapper(const OdGiMapper &pMaterialMapper, const OdGeMatrix3d &tm) = 0;

    /** Description:
      Return input vertices transformation matrix.
    */
    virtual const OdGeMatrix3d &inputTransform() const = 0;
    /** Description:
      Set input vertices transformation matrix.
    */
    virtual void setInputTransform(const OdGeMatrix3d &tm) = 0;

    /** Description:
      Return input vertices device transformation matrix.

      Remarks:
      This is a device-dependant optional transformation matrix.
    */
    virtual const OdGeMatrix3d &deviceTransform() const = 0;
    /** Description:
      Set input vertices device transformation matrix.

      Remarks:
      This is a device-dependant optional transformation matrix.
    */
    virtual void setDeviceTransform(const OdGeMatrix3d &dtm) = 0;

    /** Description:
      Return model transformation matrix (used only for kModel mappers).
    */
    virtual const OdGeMatrix3d &modelTransform() const = 0;
    /** Description:
      Set model transformation matrix (used only for kModel mappers).
    */
    virtual void setModelTransform(const OdGeMatrix3d &mtm) = 0;

    /** Description:
      Return object transformation matrix (used only for kObject mappers).
    */
    virtual const OdGeMatrix3d &objectTransform() const = 0;
    /** Description:
      Set object transformation matrix (used only for kObject mappers).
    */
    virtual void setObjectTransform(const OdGeMatrix3d &otm) = 0;

    /** Description:
      Return output texture coordinates transformation matrix.
    */
    virtual const OdGeMatrix3d &outputTransform() const = 0;
    /** Description:
      Set output texture coordinates transformation matrix.
    */
    virtual void setOutputTransform(const OdGeMatrix3d &tm) = 0;

    /** Description:
      Recompute transformation matrices.
      Remarks:
      Must be called after mapper or model transforms set.
      See also:
      setMapper, setModelTransform
    */
    virtual void recomputeTransformations() = 0;

    /** Description:
      Calculate texture coordinates for input triangle.
      Arguments:
      trg (I) Input triangle coordinates (X, Y, Z).
      uv (O) Output texture coordinates (U, V).
    */
    virtual void mapCoords(const MapInputTriangle &trg, MapOutputCoords &uv) const = 0;
    /** Description:
      Calculate texture coordinates for input triangle.
      Arguments:
      trg (I) Input triangle coordinates (X, Y, Z).
      uv (O) Output texture coordinates (U, V).
    */
    virtual void mapCoords(const OdGePoint3d *trg, OdGePoint2d *uv) const = 0;
    /** Description:
      Calculate texture coordinates for input triangle.
      Arguments:
      trg (I) Input triangle coordinates (X, Y, Z).
      uv (O) Output texture coordinates (U, V).
    */
    virtual void mapCoords(const double *trg, double *uv) const = 0;
    /** Description:
      Calculate texture coordinates for input triangle.
      Arguments:
      trg (I) Input triangle coordinates (X, Y, Z).
      normal (I) Input triangle normal (X, Y, Z).
      uv (O) Output texture coordinates (U, V).
    */
    virtual void mapCoords(const MapInputTriangle &trg, const OdGeVector3d &normal, MapOutputCoords &uv) const = 0;
    /** Description:
      Calculate texture coordinates for input triangle.
      Arguments:
      trg (I) Input triangle coordinates (X, Y, Z).
      normal (I) Input triangle normal (X, Y, Z).
      uv (O) Output texture coordinates (U, V).
    */
    virtual void mapCoords(const OdGePoint3d *trg, const OdGeVector3d &normal, OdGePoint2d *uv) const = 0;
    /** Description:
      Calculate texture coordinates for input triangle.
      Arguments:
      trg (I) Input triangle coordinates (X, Y, Z).
      normal (I) Input triangle normal (X, Y, Z).
      uv (O) Output texture coordinates (U, V).
    */
    virtual void mapCoords(const double *trg, const double *normal, double *uv) const = 0;

    // Shell mapping extensions for 3.4

    enum MappingIteratorType
    {
      kShellMapIt = 0, // Shell-style iterator
      kTriListMapIt, // Triangles list { { 0, 1, 2 }, { 1, 2, 3 } }
      kPolyIt // Simple list of indices (probably shell/mesh face, polygon or unstructured data)
      // kTriListMapIt makes subdividing of vertices without indices on triangles. Set kShellMapIt or
      // kPolyIt if input data doesn't stored as triangles list.
    };

    /** Description:
      Calculate texture coordinates for input shell/mesh/polygon vertices.
      Arguments:
      nVerts (I) Count of input vertices.
      pVerts (I) Array of input vertices (should be equal with vertices count).
      pUV (O) Output array of texture coordinates (should be equal with vertices count).
      nList (I) Count of indices in indices array (include face sizes for shell-style arrays).
      pIds (I) Vertex indices array.
      mapIt (I) Type of indices iterator.
      pNormal (I) Optional normal (if already precalculated and doesn't specified in face/vertex data).
      pFaceNormals (I) Optional face normals array (have greater priority than optional normal).
      pVertNormals (I) Optional vertex normals array (have greater priority than optional face normals).
      oType (I) Used for calculation of normal if doesn't specified.
    */
    virtual void mapCoords(OdUInt32 nVerts, const OdGePoint3d *pVerts, OdGePoint2d *pUV,
                           OdUInt32 nList = 0, const OdInt32 *pIds = NULL, MappingIteratorType mapIt = kTriListMapIt,
                           const OdGeVector3d *pNormal = NULL, const OdGeVector3d *pFaceNormals = NULL,
                           const OdGeVector3d *pVertNormals = NULL, OdGiOrientationType oType = kOdGiNoOrientation) = 0;

    //

    /** Description:
      Return true if entity mapper is specified.
    */
    virtual bool isEntityMapper() const = 0;
    /** Description:
      Return true if mapper needs object matrix.
    */
    virtual bool isObjectMatrixNeed() const = 0;
    /** Description:
      Return true if mapper needs model matrix.
    */
    virtual bool isModelMatrixNeed() const = 0;
    /** Description:
      Return true if mapper requires object or vertex transform.
    */
    virtual bool isDependsFromObjectMatrix() const = 0;
    /** Description:
      Returns true if mapper requires vertex transform.
    */
    virtual bool isVertexTransformRequired() const = 0;

    /** Description:
      Sets vertex transform from points array.
    */
    virtual void setVertexTransform(OdInt32 nCount, const OdGePoint3d *pPoints) = 0;
    /** Description:
      Sets vertex transform from object extents.
    */
    virtual void setVertexTransform(const OdGeExtents3d &exts) = 0;
    /** Description:
      Sets vertex transform from points array.
    */
    virtual void setObjectTransform(OdInt32 nCount, const OdGePoint3d *pPoints) = 0;
    /** Description:
      Sets object transform from extents.
    */
    virtual void setObjectTransform(const OdGeExtents3d &exts) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMapperItemEntry object pointers.
	
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMapperItemEntry> OdGiMapperItemEntryPtr;

/** Description:
    Container item for material data storage.
    *OdGiMapperItem* used for real-time devices, such as DirectX or OpenGL.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMapperItem : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMapperItem);

    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setDiffuseMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setDiffuseMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setDiffuseMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setDiffuseMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for diffuse texture channel.
    */
    virtual OdGiMapperItemEntryPtr diffuseMapper() const = 0;
    /** Description:
      Return mapper for diffuse texture channel.
    */
    virtual OdGiMapperItemEntryPtr diffuseMapper() = 0;

    /** Description:
      Set mapper for all texture channels.
      Arguments:
      traitsData (I) Input traits data.
      pMaterial (I) Material ID for input traits data.
    */
    virtual void setMapper(const OdGiMaterialTraitsData &traitsData, const OdDbStub *pMaterial = NULL) = 0;
    /** Description:
      Set mapper for all texture channels.
      Arguments:
      traitsData (I) Input traits data.
      pMaterial (I) Material ID for input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm, const OdDbStub *pMaterial = NULL) = 0;
    /** Description:
      Set mapper for all texture channels.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      pMaterial (I) Material ID for input traits data.
    */
    virtual void setMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdDbStub *pMaterial = NULL) = 0;
    /** Description:
      Set mapper for all texture channels.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      pMaterial (I) Material ID for input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm, const OdDbStub *pMaterial = NULL) = 0;

    /** Description:
      Set model transformation for all texture channels which needs model transformation.
      Arguments:
      mtm (I) Model transformation matrix.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setModelTransform(const OdGeMatrix3d &mtm, bool recomputeTransforms = true) = 0;

    /** Description:
      Set object transformation for all texture channels which needs object transformation.
      Arguments:
      otm (I) Object transformation matrix.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setObjectTransform(const OdGeMatrix3d &otm, bool recomputeTransforms = true) = 0;
    /** Description:
      Set object transformation for all texture channels which needs object transformation.
      Arguments:
      nCount (I) Number of points into *pPoints* array.
      pPoints (I) Array of points.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setObjectTransform(OdInt32 nCount, const OdGePoint3d *pPoints, bool recomputeTransforms = true) = 0;
    /** Description:
      Set object transformation for all texture channels which needs object transformation.
      Arguments:
      exts (I) Object extents.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix set.
    */
    virtual void setObjectTransform(const OdGeExtents3d &exts, bool recomputeTransforms = true) = 0;

    /** Description:
      Set device-dependant transformation for all texture channels.
      Arguments:
      dtm (I) Device transformation matrix.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix set.
    */
    virtual void setDeviceTransform(const OdGeMatrix3d &dtm, bool recomputeTransforms = true) = 0;

    /** Description:
      Test whether the current material is valid for use with previously set up mapper data.
      Arguments:
      pMaterial (I) Material ID.
    */
    virtual bool isLastProcValid(const OdDbStub *pMaterial) = 0;
    /** Description:
      Test whether the current material and matrix are valid for use with previously set up mapper data.
      Arguments:
      pMaterial (I) Material ID.
      tm (I) Object/model transformation matrix.
    */
    virtual bool isLastProcValid(const OdDbStub *pMaterial, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Test whether the current mapper and material are valid for use with previously set up mapper data.
      Arguments:
      pMapper (I) Entity mapper.
      pMaterial (I) Material ID.
    */
    virtual bool isLastProcValid(const OdGiMapper *pMapper, const OdDbStub *pMaterial) = 0;
    /** Description:
      Test whether the current mapper, material, and matrix are valid for use with previously set up mapper data.
      Arguments:
      pMapper (I) Entity mapper.
      pMaterial (I) Material ID.
      tm (I) Object/model transformation matrix.
    */
    virtual bool isLastProcValid(const OdGiMapper *pMapper, const OdDbStub *pMaterial, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Test whether the current object/model matrix is valid for use with previously set up mapper data.
      Arguments:
      tm (I) Object/model transformation matrix.
    */
    virtual bool isLastProcValid(const OdGeMatrix3d &tm) = 0;

    /** Description:
      Return true if entity mapper is specified.
    */
    virtual bool isEntityMapper() const = 0;
    /** Description:
      Return true if mapper needs object matrix.
    */
    virtual bool isObjectMatrixNeed() const = 0;
    /** Description:
      Return true if mapper needs model matrix.
    */
    virtual bool isModelMatrixNeed() const = 0;
    /** Description:
      Return true if mapper requires object or vertex transform.
    */
    virtual bool isDependsFromObjectMatrix() const = 0;
    /** Description:
      Returns true if mapper requires vertex transform.
    */
    virtual bool isVertexTransformRequired() const = 0;

    /** Description:
      Sets vertex transform from points array for channels which needs vertex transformation.
    */
    virtual void setVertexTransform(OdInt32 nCount, const OdGePoint3d *pPoints) = 0;
    /** Description:
      Sets vertex transform from object extents for channels which needs vertex transformation.
    */
    virtual void setVertexTransform(const OdGeExtents3d &exts) = 0;

    /** Description:
      Sets input tranform for all channels.
      Arguments:
      tm (I) Input transformation matrix.
      bVertexDependantOnly (I) Set to channels which require vertex tranform only.
    */
    virtual void setInputTransform(const OdGeMatrix3d &tm, bool bVertexDependantOnly = true) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMapperItem object pointers.

	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMapperItem> OdGiMapperItemPtr;

/** Description:
    Container item for material data storage.
    *OdGiMapperRenderItem* used for rendering devices.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiMapperRenderItem : public OdGiMapperItem
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiMapperRenderItem);

    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setDiffuseMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setDiffuseMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setDiffuseMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for diffuse texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setDiffuseMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for diffuse texture channel.
    */
    virtual OdGiMapperItemEntryPtr diffuseMapper() const = 0;
    /** Description:
      Return mapper for diffuse texture channel.
    */
    virtual OdGiMapperItemEntryPtr diffuseMapper() = 0;

    /** Description:
      Set mapper for specular texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setSpecularMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for specular texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setSpecularMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for specular texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setSpecularMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for specular texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setSpecularMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for specular texture channel.
    */
    virtual OdGiMapperItemEntryPtr specularMapper() const = 0;
    /** Description:
      Return mapper for specular texture channel.
    */
    virtual OdGiMapperItemEntryPtr specularMapper() = 0;

    /** Description:
      Set mapper for reflection texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setReflectionMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for reflection texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setReflectionMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for reflection texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setReflectionMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for reflection texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setReflectionMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for reflection texture channel.
    */
    virtual OdGiMapperItemEntryPtr reflectionMapper() const = 0;
    /** Description:
      Return mapper for reflection texture channel.
    */
    virtual OdGiMapperItemEntryPtr reflectionMapper() = 0;

    /** Description:
      Set mapper for opacity texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setOpacityMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for opacity texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setOpacityMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for opacity texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setOpacityMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for opacity texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setOpacityMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for opacity texture channel.
    */
    virtual OdGiMapperItemEntryPtr opacityMapper() const = 0;
    /** Description:
      Return mapper for opacity texture channel.
    */
    virtual OdGiMapperItemEntryPtr opacityMapper() = 0;

    /** Description:
      Set mapper for bump texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setBumpMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for bump texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setBumpMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for bump texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setBumpMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for bump texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setBumpMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for bump texture channel.
    */
    virtual OdGiMapperItemEntryPtr bumpMapper() const = 0;
    /** Description:
      Return mapper for bump texture channel.
    */
    virtual OdGiMapperItemEntryPtr bumpMapper() = 0;

    /** Description:
      Set mapper for reflection texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setRefractionMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for refraction texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setRefractionMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for reflection texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setRefractionMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for refraction texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setRefractionMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for reflection texture channel.
    */
    virtual OdGiMapperItemEntryPtr refractionMapper() const = 0;
    /** Description:
      Return mapper for reflection texture channel.
    */
    virtual OdGiMapperItemEntryPtr refractionMapper() = 0;

    /** Description:
      Set mapper for normal map texture channel.
      Arguments:
      traitsData (I) Input traits data.
    */
    virtual void setNormalMapMapper(const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for normal map texture channel.
      Arguments:
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setNormalMapMapper(const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Set mapper for normal map texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
    */
    virtual void setNormalMapMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData) = 0;
    /** Description:
      Set mapper for normal map texture channel.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      tm (I) Object/model transformation matrix.
    */
    virtual void setNormalMapMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Return mapper for normal map texture channel.
    */
    virtual OdGiMapperItemEntryPtr normalMapMapper() const = 0;
    /** Description:
      Return mapper for normal map texture channel.
    */
    virtual OdGiMapperItemEntryPtr normalMapMapper() = 0;

    /** Description:
      Set mapper for all texture channels.
      Arguments:
      traitsData (I) Input traits data.
      pMaterial (I) Material ID for input traits data.
    */
    virtual void setMapper(const OdGiMaterialTraitsData &traitsData, const OdDbStub *pMaterial = NULL) = 0;
    /** Description:
      Set mapper for all texture channels.
      Arguments:
      pMapper (I) Entity mapper.
      traitsData (I) Input traits data.
      pMaterial (I) Material ID for input traits data.
    */
    virtual void setMapper(const OdGiMapper *pMapper, const OdGiMaterialTraitsData &traitsData, const OdDbStub *pMaterial = NULL) = 0;

    /** Description:
      Set model transformation for all texture channels which needs model transformation.
      Arguments:
      mtm (I) Model transformation matrix.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setModelTransform(const OdGeMatrix3d &mtm, bool recomputeTransforms = true) = 0;

    /** Description:
      Set object transformation for all texture channels which needs object transformation.
      Arguments:
      otm (I) Object transformation matrix.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setObjectTransform(const OdGeMatrix3d &otm, bool recomputeTransforms = true) = 0;
    /** Description:
      Set object transformation for all texture channels which needs object transformation.
      Arguments:
      nCount (I) Number of points into *pPoints* array.
      pPoints (I) Array of points.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setObjectTransform(OdInt32 nCount, const OdGePoint3d *pPoints, bool recomputeTransforms = true) = 0;
    /** Description:
      Set object transformation for all texture channels which needs object transformation.
      Arguments:
      exts (I) Object extents.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setObjectTransform(const OdGeExtents3d &exts, bool recomputeTransforms = true) = 0;

    /** Description:
      Set device-dependant transformation for all texture channels.
      Arguments:
      dtm (I) Device transformation matrix.
      recomputeTransforms (I) Call recomputeTransformations() for all texture channels after matrix is set.
    */
    virtual void setDeviceTransform(const OdGeMatrix3d &dtm, bool recomputeTransforms = true) = 0;

    /** Description:
      Test whether the current material is valid for use with previously set up mapper data.
      Arguments:
      pMaterial (I) Material ID.
    */
    virtual bool isLastProcValid(const OdDbStub *pMaterial) = 0;
    /** Description:
      Test whether the current material and matrix are valid for use with previously set up mapper data.
      Arguments:
      pMaterial (I) Material ID.
      tm (I) object/model transformation matrix.
    */
    virtual bool isLastProcValid(const OdDbStub *pMaterial, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Test whether the current mapper and material are valid for use with previously set up mapper data.
      Arguments:
      pMapper (I) Entity mapper.
      pMaterial (I) Material ID.
    */
    virtual bool isLastProcValid(const OdGiMapper *pMapper, const OdDbStub *pMaterial) = 0;
    /** Description:
      Test whether the current mapper, material, and matrix are valid for use with previously set up mapper data.
      Arguments:
      pMapper (I) Entity mapper.
      pMaterial (I) Material ID.
      tm (I) Object/model transformation matrix.
    */
    virtual bool isLastProcValid(const OdGiMapper *pMapper, const OdDbStub *pMaterial, const OdGeMatrix3d &tm) = 0;
    /** Description:
      Test whether the current object/model matrix is valid for use with previously set up mapper data.
      Arguments:
      tm (I) Object/model transformation matrix.
    */
    virtual bool isLastProcValid(const OdGeMatrix3d &tm) = 0;

    /** Description:
      Return true if entity mapper is specified for all channels.
    */
    virtual bool isEntityMapper() const = 0;
    /** Description:
      Return true if at least one mapper needs object matrix.
    */
    virtual bool isObjectMatrixNeed() const = 0;
    /** Description:
      Return true if at least one mapper needs model matrix.
    */
    virtual bool isModelMatrixNeed() const = 0;
    /** Description:
      Return true if mapper requires object or vertex transform.
    */
    virtual bool isDependsFromObjectMatrix() const = 0;
    /** Description:
      Returns true if mapper requires vertex transform.
    */
    virtual bool isVertexTransformRequired() const = 0;

    /** Description:
      Set vertex transform from points array for channels which needs vertex transformation.
    */
    virtual void setVertexTransform(OdInt32 nCount, const OdGePoint3d *pPoints) = 0;
    /** Description:
      Set vertex transform from object extents for channels which needs vertex transformation.
    */
    virtual void setVertexTransform(const OdGeExtents3d &exts) = 0;

    /** Description:
      Sets input tranform for all channels.
      Arguments:
      tm (I) Input transformation matrix.
      bVertexDependantOnly (I) Set to channels which require vertex tranform only.
    */
    virtual void setInputTransform(const OdGeMatrix3d &tm, bool bVertexDependantOnly = true) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiMapperRenderItem object pointers.
	
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiMapperRenderItem> OdGiMapperRenderItemPtr;

#include "../TD_PackPop.h"

#endif // __ODGIMAPPERITEM_H__
