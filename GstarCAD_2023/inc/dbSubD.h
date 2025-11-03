/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "gevc3dar.h"

#pragma pack(push, 8)

class GcDbSurface;
class GcGiFaceData;
class GcGiMapper;

class  GcDbSubDMesh : public GcDbEntity
{
  GCDB_DECLARE_MEMBERS_EXPIMP(GcDbSubDMesh, GCDB_PORT);

public:
  GCDB_PORT GcDbSubDMesh();
  GCDB_PORT ~GcDbSubDMesh();

  GCDB_PORT Gcad::ErrorStatus           setSubDMesh(const GcGePoint3dArray& vertexArray,
    const GcArray<Gsoft::Int32>& faceArray,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setSphere(double radius,
    int divAxis,
    int divHeight,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setCylinder(double majorRadius,
    double minorRadius,
    double height,
    int divAxis,
    int divHeight,
    int divCap,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setCone(double majorRadius,
    double minorRadius,
    double height,
    int divAxis,
    int divHeight,
    int divCap,
    double radiusRatio,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setTorus(double majorRadius,
    int divSection,
    int divSweepPath,
    double sectionRadiusRatio,
    double sectionRotate,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setBox(double xLen,
    double yLen,
    double zLen,
    int divX,
    int divY,
    int divZ,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setWedge(double xLen,
    double yLen,
    double zLen,
    int divLength,
    int divWidth,
    int divHeight,
    int divSlope,
    int divCap,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setPyramid(double radius,
    double height,
    int divLength,
    int divHeight,
    int divCap,
    int nSides,
    double radiusRatio,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           subdDivideUp();
  GCDB_PORT Gcad::ErrorStatus           subdDivideDown();
  GCDB_PORT Gcad::ErrorStatus           subdRefine();
  GCDB_PORT Gcad::ErrorStatus           subdRefine(const GcDbFullSubentPathArray& subentPaths);
  GCDB_PORT Gcad::ErrorStatus           subdLevel(Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           splitFace(const GcDbSubentId& subentFaceId,
    const GcDbSubentId& subent0,
    const GcGePoint3d& point0,
    const GcDbSubentId& subent1,
    const GcGePoint3d& point1);
  GCDB_PORT Gcad::ErrorStatus           extrudeFaces(const GcDbFullSubentPathArray& subentPaths,
    double length,
    const GcGeVector3d& dir,
    double taper);
  GCDB_PORT Gcad::ErrorStatus           extrudeFaces(const GcDbFullSubentPathArray& subentPaths,
    const GcGePoint3dArray& alongPath,
    double taper);
  GCDB_PORT Gcad::ErrorStatus           extrudeConnectedFaces(const GcDbFullSubentPathArray& subentPaths,
    double length,
    const GcGeVector3d& dir,
    double taper);
  GCDB_PORT Gcad::ErrorStatus           extrudeConnectedFaces(const GcDbFullSubentPathArray& subentPaths,
    const GcGePoint3dArray& alongPath,
    double taper);
  GCDB_PORT Gcad::ErrorStatus           mergeFaces(const GcDbFullSubentPathArray& subentPaths);
  GCDB_PORT Gcad::ErrorStatus           collapse(const GcDbSubentId& subent);
  GCDB_PORT Gcad::ErrorStatus           cap(const GcDbFullSubentPathArray& edgePaths);
  GCDB_PORT Gcad::ErrorStatus           spin(const GcDbSubentId& subent);
  GCDB_PORT Gcad::ErrorStatus           isWatertight(bool& result) const;
  GCDB_PORT Gcad::ErrorStatus           numOfFaces(Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           numOfSubDividedFaces(Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           numOfSubDividedFacesAt(const GcDbFullSubentPathArray& subentPaths, Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           numOfVertices(Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           numOfSubDividedVertices(Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           numOfEdges(Gsoft::Int32& result) const;
  GCDB_PORT Gcad::ErrorStatus           getVertices(GcGePoint3dArray& vertexArray) const;
  GCDB_PORT Gcad::ErrorStatus           getEdgeArray(GcArray<Gsoft::Int32>& edgeArray) const;
  GCDB_PORT Gcad::ErrorStatus           getFaceArray(GcArray<Gsoft::Int32>& faceArray) const;
  GCDB_PORT Gcad::ErrorStatus           getNormalArray(GcGeVector3dArray& normalArray) const;
  GCDB_PORT Gcad::ErrorStatus           getSubDividedVertices(GcGePoint3dArray& vertexArray) const;
  GCDB_PORT Gcad::ErrorStatus           getSubDividedFaceArray(GcArray<Gsoft::Int32>& faceArray) const;
  GCDB_PORT Gcad::ErrorStatus           getSubDividedNormalArray(GcGeVector3dArray& normalArray) const;
  GCDB_PORT Gcad::ErrorStatus           getVertexAt(Gsoft::Int32 nIndex, GcGePoint3d& vertex) const;
  GCDB_PORT Gcad::ErrorStatus           setVertexAt(Gsoft::Int32 nIndex, const GcGePoint3d& vertex);
  GCDB_PORT Gcad::ErrorStatus           getVertexAt(const GcDbSubentId& id, GcGePoint3d& vertex) const;
  GCDB_PORT Gcad::ErrorStatus           setVertexAt(const GcDbSubentId& id, const GcGePoint3d& vertex);
  GCDB_PORT Gcad::ErrorStatus           getSubDividedVertexAt(Gsoft::Int32 nIndex, GcGePoint3d& vertex) const;
  GCDB_PORT Gcad::ErrorStatus           getSubDividedVertexAt(const GcDbSubentId& id, GcGePoint3d& vertex) const;
  GCDB_PORT Gcad::ErrorStatus           setCrease(double creaseVal);
  GCDB_PORT Gcad::ErrorStatus           setCrease(const GcDbFullSubentPathArray& subentPaths, double creaseVal);
  GCDB_PORT Gcad::ErrorStatus           getCrease(const GcDbFullSubentPathArray& subentPaths, GcArray<double>& result) const;
  GCDB_PORT Gcad::ErrorStatus           getCrease(const GcDbSubentId& id, double& result) const;
  GCDB_PORT Gcad::ErrorStatus           getAdjacentSubentPath(const GcDbFullSubentPath& path,
    GcDb::SubentType type,
    GcDbFullSubentPathArray& subentPaths) const;
  GCDB_PORT Gcad::ErrorStatus           getSubentPath(Gsoft::Int32 nIndex,
    GcDb::SubentType type,
    GcDbFullSubentPathArray& subentPaths) const;
  GCDB_PORT Gcad::ErrorStatus           convertToSurface(bool bConvertAsSmooth, const GcDbSubentId& id, GcDbSurface*& pSurface) const;
  GCDB_PORT Gcad::ErrorStatus           convertToSurface(bool bConvertAsSmooth, bool optimize, GcDbSurface*& pSurface) const;
  GCDB_PORT Gcad::ErrorStatus           convertToSolid(bool bConvertAsSmooth, bool optimize, GcDb3dSolid*& pSolid) const;
  GCDB_PORT Gcad::ErrorStatus           getSubentColor(const GcDbSubentId& id, GcCmColor& color) const;
  GCDB_PORT Gcad::ErrorStatus           setSubentColor(const GcDbSubentId& id, const GcCmColor& color);
  GCDB_PORT Gcad::ErrorStatus           getSubentMaterial(const GcDbSubentId& id, GcDbObjectId& material) const;
  GCDB_PORT Gcad::ErrorStatus           setSubentMaterial(const GcDbSubentId& id, const GcDbObjectId& material);
  GCDB_PORT Gcad::ErrorStatus           getSubentMaterialMapper(const GcDbSubentId& id, GcGiMapper& mapper) const;
  GCDB_PORT Gcad::ErrorStatus           setSubentMaterialMapper(const GcDbSubentId& id, const GcGiMapper& mapper);
  GCDB_PORT Gcad::ErrorStatus           getFacePlane(const GcDbSubentId& id, GcGePlane& facePlane) const;
  GCDB_PORT Gcad::ErrorStatus           computeVolume(double &retVolume) const;
  GCDB_PORT Gcad::ErrorStatus           computeSurfaceArea(double &retSurfArea) const;
  GCDB_PORT void                        dragStatus(const GcDb::DragStat status) override;
  GCDB_PORT Gcad::ErrorStatus           subGetClassID(CLSID* pClsid) const override;
  GCDB_PORT bool                        bounds(GcDbExtents& retBounds) const override;
  GCDB_PORT Gcad::ErrorStatus           setSphere(const GcGeMatrix3d& xForm,
    int divAxis,
    int divHeight,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setCylinder(const GcGeMatrix3d& xForm,
    int divAxis,
    int divHeight,
    int divCap,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setCone(const GcGeMatrix3d& xForm,
    int divAxis,
    int divHeight,
    int divCap,
    double radiusRatio,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setTorus(const GcGeMatrix3d& xForm,
    int divSection,
    int divSweepPath,
    double sectionRadiusRatio,
    double sectionRotate,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setBox(const GcGeMatrix3d& xForm,
    int divX,
    int divY,
    int divZ,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setWedge(const GcGeMatrix3d& xForm,
    int divLength,
    int divWidth,
    int divHeight,
    int divSlope,
    int divCap,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           setPyramid(const GcGeMatrix3d& xForm,
    int divLength,
    int divHeight,
    int divCap,
    int nSides,
    double radiusRatio,
    int subDLevel);
  GCDB_PORT Gcad::ErrorStatus           computeRayIntersection(const GcGePoint3d &rayStart,
    const GcGeVector3d &rayDir,
    GcArray<GcDbSubentId> &retSubents,
    GcArray<double> &retIntersectDist,
    GcGePoint3dArray& retIntersectPoint) const;
  GCDB_PORT Gcad::ErrorStatus           setVertexNormalArray(GcGeVector3dArray &arr);
  GCDB_PORT Gcad::ErrorStatus           setVertexTextureArray(GcGePoint3dArray &arr);
  GCDB_PORT Gcad::ErrorStatus           setVertexColorArray(GcArray<GcCmEntityColor> &arr);
  GCDB_PORT Gcad::ErrorStatus           getVertexNormalArray(GcGeVector3dArray &arr);
  GCDB_PORT Gcad::ErrorStatus           getVertexTextureArray(GcGePoint3dArray &arr);
  GCDB_PORT Gcad::ErrorStatus           getVertexColorArray(GcArray<GcCmEntityColor> &arr);
};

struct MeshFaceterSettings
{
  double faceterDevSurface;
  double faceterDevNormal;
  double faceterGridRatio;
  double faceterMaxEdgeLength;
  Gsoft::UInt16 faceterMaxGrid;
  Gsoft::UInt16 faceterMinUGrid;
  Gsoft::UInt16 faceterMinVGrid;
  Gsoft::Int16 faceterMeshType;
};

typedef struct MeshFaceterSettings  GcDbFaceterSettings;

GCDB_PORT  Gcad::ErrorStatus gcdbGetObjectMesh(GcDbObject *pObj,
  const GcDbFaceterSettings *faceter,
  GcGePoint3dArray& vertexArray,
  GcArray<Gsoft::Int32>& faceArray,
  GcGiFaceData*& faceData);

#pragma pack(pop)