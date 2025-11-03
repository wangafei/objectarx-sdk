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




#ifndef _OD_DB_SUBDMESH
#define _OD_DB_SUBDMESH

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DoubleArray.h"
#include "DbSurface.h"
#include "Db3dSolid.h"
#include "CmEntityColorArray.h"

#include "Int32Array.h"
#include "Gi/GiGeometry.h"

class OdDbSurface;
class OdDb3dSolid;

/** Description:
 This class represents SubDMesh entities in an OdDbDatabase instance.

 Library:
 TD_Db

 {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbSubDMesh : public OdDbEntity
{
public:
 ODDB_DECLARE_MEMBERS(OdDbSubDMesh);
 
 OdDbSubDMesh();
 
 virtual ~OdDbSubDMesh();

 virtual OdBool subWorldDraw(
   OdGiWorldDraw* pWd);

 virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
 virtual OdResult dwgInFields(
   OdDbDwgFiler* pFiler);

 virtual OdResult dwgOutFields(
   OdDbDwgFiler* pFiler) const;

 virtual OdResult dxfInFields(
   OdDbDxfFiler* pFiler);

 virtual OdResult dxfOutFields(
   OdDbDxfFiler* pFiler) const;

 virtual OdResult subTransformBy(
   const OdGeMatrix3d& xfm);

 virtual OdResult subExplode(
   OdDbVoidPtrArray& entitySet) const;

 OdResult subGetGeomExtents(
   OdDbExtents& extents) const;

 OdResult setSubDMesh (const OdGePoint3dArray& vertexArray,
   const OdInt32Array& faceArray,
   OdInt32 subDLevel);

 OdResult setSphere (double radius,
   OdInt32 divAxis,
   OdInt32 divHeight,
   OdInt32 subDLevel);

 OdResult setSphere(const OdGeMatrix3d& xForm,
   int divAxis,
   int divHeight,
   int subDLevel);

 OdResult setCylinder (double majorRadius,
   double minorRadius,
   double height,
   OdInt32 divAxis,
   OdInt32 divHeight,
   OdInt32 divCap,
   OdInt32 subDLevel);
   
 OdResult setCylinder (const OdGeMatrix3d& xForm,
   int divAxis,
   int divHeight,
   int divCap,
   int subDLevel);

 OdResult setCone (double majorRadius,
   double minorRadius,
   double height,
   OdInt32 divAxis,
   OdInt32 divHeight,
   OdInt32 divCap,
   double radiusRatio,
   OdInt32 subDLevel);
   
 OdResult setCone (const OdGeMatrix3d& xForm,
   int divAxis,
   int divHeight,
   int divCap,
   double radiusRatio,
   int subDLevel);

 OdResult setTorus (double majorRadius,
   OdInt32 divSection,
   OdInt32 divSweepPath,
   double sectionRadiusRatio,
   double sectionRotate,
   OdInt32 subDLevel);
   
 OdResult setTorus (const OdGeMatrix3d& xForm,
   int divSection,
   int divSweepPath,
   double sectionRadiusRatio,
   double sectionRotate,
   int subDLevel);

 OdResult setBox (double xLen,
   double yLen,
   double zLen,
   OdInt32 divX,
   OdInt32 divY,
   OdInt32 divZ,
   OdInt32 subDLevel);
   
 OdResult setBox (const OdGeMatrix3d& xForm,
   int divX,
   int divY,
   int divZ,
   int subDLevel);   

 OdResult setWedge (double xLen,
   double yLen,
   double zLen,
   OdInt32 divLength,
   OdInt32 divWidth,
   OdInt32 divHeight,
   OdInt32 divSlope,
   OdInt32 divCap,
   OdInt32 subDLevel);
   
 OdResult setWedge (const OdGeMatrix3d& xForm,
   int divLength,
   int divWidth,
   int divHeight,
   int divSlope,
   int divCap,
   int subDLevel);   

 OdResult setPyramid (double radius,
   double height,
   OdInt32 divLength,
   OdInt32 divHeight,
   OdInt32 divCap,
   OdInt32 nSides,
   double radiusRatio,
   OdInt32 subDLevel);
   
 OdResult setPyramid (const OdGeMatrix3d& xForm,
   int divLength,
   int divHeight,
   int divCap,
   int nSides,
   double radiusRatio,
   int subDLevel);   

 OdResult subdDivideUp ();
 OdResult subdDivideDown ();
 OdResult subdRefine ();
 OdResult subdRefine (const OdDbFullSubentPathArray& subentPaths);
 OdResult subdLevel (OdInt32& result) const;

 OdResult splitFace (const OdDbSubentId& subentFaceId,
   const OdDbSubentId& subent0,
   const OdGePoint3d& point0,
   const OdDbSubentId& subent1,
   const OdGePoint3d& point1);

 OdResult extrudeFaces (const OdDbFullSubentPathArray& subentPaths,
   double length,
   const OdGeVector3d& dir,
   double taper);

 OdResult extrudeFaces (const OdDbFullSubentPathArray& subentPaths,
   const OdGePoint3dArray& alongPath,
   double taper);

 OdResult extrudeConnectedFaces(const OdDbFullSubentPathArray& subentPaths,
   double length,
   const OdGeVector3d& dir,
   double taper);

 OdResult extrudeConnectedFaces(const OdDbFullSubentPathArray& subentPaths,
   const OdGePoint3dArray& alongPath,
   double taper);

 OdResult mergeFaces(const OdDbFullSubentPathArray& subentPaths);
 OdResult collapse(const OdDbSubentId& subent);
 OdResult cap(const OdDbFullSubentPathArray& edgePaths);
 OdResult spin(const OdDbSubentId& subent);

 OdResult isWatertight (bool& result) const;

 OdResult numOfFaces (OdInt32& result) const;
 OdResult numOfSubDividedFaces (OdInt32& result) const;
 OdResult numOfSubDividedFacesAt (const OdDbFullSubentPathArray& subentPaths, OdInt32& result) const;
 OdResult numOfVertices (OdInt32& result) const;
 OdResult numOfSubDividedVertices (OdInt32& result) const;
 OdResult numOfEdges (OdInt32& result) const;

 OdResult getVertices (OdGePoint3dArray& vertexArray) const;
 OdResult getEdgeArray (OdInt32Array& edgeArray) const;
 OdResult getFaceArray (OdInt32Array& faceArray) const;
 OdResult getNormalArray (OdGeVector3dArray& normalArray) const;

 OdResult getSubDividedVertices (OdGePoint3dArray& vertexArray) const;
 OdResult getSubDividedFaceArray (OdInt32Array& faceArray) const;
 OdResult getSubDividedNormalArray(OdGeVector3dArray& normalArray) const;

 OdResult getVertexAt (OdInt32 nIndex, OdGePoint3d& vertex) const;
 OdResult setVertexAt (OdInt32 nIndex, const OdGePoint3d& vertex);
 OdResult getVertexAt (const OdDbSubentId& id, OdGePoint3d& vertex) const;
 OdResult setVertexAt (const OdDbSubentId& id, const OdGePoint3d& vertex);

 OdResult getSubDividedVertexAt (OdInt32 nIndex, OdGePoint3d& vertex) const;
 OdResult getSubDividedVertexAt (const OdDbSubentId& id, OdGePoint3d& vertex) const;

 OdResult setCrease (double creaseVal);
 OdResult setCrease (const OdDbFullSubentPathArray& subentPaths, double creaseVal);
 OdResult getCrease (const OdDbFullSubentPathArray& subentPaths, OdDoubleArray& result) const;
 OdResult getCrease (const OdDbSubentId& id, double& result) const;

 OdResult getAdjacentSubentPath (const OdDbFullSubentPath& path,
   OdDb::SubentType type,
   OdDbFullSubentPathArray& subentPaths) const;

 OdResult getSubentPath (OdInt32 nIndex,
   OdDb::SubentType type,
   OdDbFullSubentPathArray& subentPaths) const;

 OdResult convertToSurface (bool bConvertAsSmooth, const OdDbSubentId& id, OdDbSurface*& pSurface) const;
 OdResult convertToSurface (bool bConvertAsSmooth, bool optimize, OdDbSurface*& pSurface) const;
 OdResult convertToSolid (bool bConvertAsSmooth, bool optimize, OdDb3dSolid*& pSolid) const;

 OdResult getSubentColor (const OdDbSubentId& id, OdCmColor& color) const;
 OdResult setSubentColor (const OdDbSubentId& id, const OdCmColor& color);
 OdResult getSubentMaterial (const OdDbSubentId& id, OdDbObjectId& material) const;
 OdResult setSubentMaterial (const OdDbSubentId& id, const OdDbObjectId& material);
 OdResult getSubentMaterialMapper (const OdDbSubentId& id, OdGiMapper& mapper) const;
 OdResult setSubentMaterialMapper (const OdDbSubentId& id, const OdGiMapper& mapper);

 OdResult getFacePlane (const OdDbSubentId& id, OdGePlane& facePlane) const;
 
 virtual void dragStatus (const OdDb::DragStat status);
 virtual bool bounds ( OdDbExtents& retBounds ) const;
 
 OdResult computeVolume (double &retVolume) const;
 OdResult computeSurfaceArea (double &retSurfArea) const;
 virtual OdResult subGetClassID(
	 CLSID* pClsid) const;

 virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
   const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
   int& numPaths, OdDbFullSubentPath*& subentPaths, 
   int numInserts = 0,
   OdDbObjectId* pEntAndInsertStack = 0) const;

 virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
   OdGsMarkerArray& gsMarkers) const;

 virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;

 virtual OdResult decomposeForSave(
   OdDb::DwgVersion ver,
   OdDbObject*& replaceObj,
   OdDbObjectId& replaceId,
   OdBool& exchangeXData);

 OdResult getVertexNormalArray(OdGeVector3dArray& arrNorm);
 OdResult getVertexTextureArray(OdGePoint3dArray& arrPts);
 OdResult getVertexColorArray(OdCmEntityColorArray& arrColor);
 OdResult setVertexNormalArray(OdGeVector3dArray& arrNorm);
 OdResult setVertexTextureArray(OdGePoint3dArray& arrPts);
 OdResult setVertexColorArray(OdCmEntityColorArray& arrColor);
 OdResult clearVertexNormalArray();
 OdResult clearVertexTextureArray();
 OdResult clearVertexColorArray();

 OdResult computeRayIntersection(const OdGePoint3d &rayStart,
	 const OdGeVector3d &rayDir,
	 OdArray<OdDbSubentId> &retSubents,
	 OdArray<double> &retIntersectDist,
	 OdGePoint3dArray& retIntersectPoint) const;
	 
 OdResult computeRayIntersection(const OdGePoint3d  &rayStart,
     const OdGeVector3d &rayDir,
     OdArray<OdDbSubentId> &retSubents,
     OdDoubleArray &retIntersectDist) const;
};

/** Description:
 This template class is a specialization of the OdSmartPtr class for OdDbSubDMesh object pointers.
*/
typedef OdSmartPtr<OdDbSubDMesh> OdDbSubDMeshPtr;

struct MeshFaceterSettings
{
  double faceterDevSurface;
  double faceterDevNormal;
  double faceterGridRatio;
  double faceterMaxEdgeLength;
  OdUInt16 faceterMaxGrid;
  OdUInt16 faceterMinUGrid;
  OdUInt16 faceterMinVGrid;
  OdInt16 faceterMeshType;

  MeshFaceterSettings()
    : faceterDevSurface(0.)
    , faceterDevNormal(0.)
    , faceterGridRatio(0.)
    , faceterMaxEdgeLength(0)
    , faceterMaxGrid(0)
    , faceterMinUGrid(0)
    , faceterMinVGrid(0)
    , faceterMeshType(0)  {}
};

typedef struct MeshFaceterSettings  OdDbFaceterSettings;

TOOLKIT_EXPORT OdResult oddbGetObjectMesh(OdDbObject *pObj, 
                                           const OdDbFaceterSettings *faceter,
                                           OdGePoint3dArray& vertexArray, 
                                           OdInt32Array& faceArray,
                                           OdGiFaceData*& faceData);

#include "TD_PackPop.h"

#endif
