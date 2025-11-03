
#pragma once

#include "zdbmain.h"
#include "zgevc3dar.h"

#pragma pack(push, 8)

class ZcDbSurface;
class ZcGiFaceData;
class ZcGiMapper;

class ZCDB_PORT ZcDbSubDMesh: public ZcDbEntity
{
    ZCDB_DECLARE_MEMBERS(ZcDbSubDMesh);

public:
                                ZcDbSubDMesh            ();
    virtual                    ~ZcDbSubDMesh            ();

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler);
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler);
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const;

    Zcad::ErrorStatus           setSubDMesh             (const ZcGePoint3dArray& vertexArray,
                                                         const ZcArray<ZSoft::Int32>& faceArray,
                                                         int subDLevel);

    Zcad::ErrorStatus           setSphere               (double radius,
                                                         int divAxis,
                                                         int divHeight,
                                                         int subDLevel);

    Zcad::ErrorStatus           setCylinder             (double majorRadius,
                                                         double minorRadius,
                                                         double height,
                                                         int divAxis,
                                                         int divHeight,
                                                         int divCap,
                                                         int subDLevel);

    Zcad::ErrorStatus           setCone                 (double majorRadius,
                                                         double minorRadius,
                                                         double height,
                                                         int divAxis,
                                                         int divHeight,
                                                         int divCap,
                                                         double radiusRatio,
                                                         int subDLevel);

    Zcad::ErrorStatus           setTorus                (double majorRadius,
                                                         int divSection,
                                                         int divSweepPath,
                                                         double sectionRadiusRatio,
                                                         double sectionRotate,
                                                         int subDLevel);

    Zcad::ErrorStatus           setBox                  (double xLen,
                                                         double yLen,
                                                         double zLen,
                                                         int divX,
                                                         int divY,
                                                         int divZ,
                                                         int subDLevel);

    Zcad::ErrorStatus           setWedge                (double xLen,
                                                         double yLen,
                                                         double zLen,
                                                         int divLength,
                                                         int divWidth,
                                                         int divHeight,
                                                         int divSlope,
                                                         int divCap,
                                                         int subDLevel);

    Zcad::ErrorStatus           setPyramid              (double radius,
                                                         double height,
                                                         int divLength,
                                                         int divHeight,
                                                         int divCap,
                                                         int nSides,
                                                         double radiusRatio,
                                                         int subDLevel);

    Zcad::ErrorStatus           subdDivideUp            ();
    Zcad::ErrorStatus           subdDivideDown          ();
    Zcad::ErrorStatus           subdRefine              ();
    Zcad::ErrorStatus           subdRefine              (const ZcDbFullSubentPathArray& subentPaths);
    Zcad::ErrorStatus           subdLevel               (ZSoft::Int32& result) const;

    Zcad::ErrorStatus           splitFace               (const ZcDbSubentId& subentFaceId,
                                                         const ZcDbSubentId& subent0,
                                                         const ZcGePoint3d& point0,
                                                         const ZcDbSubentId& subent1,
                                                         const ZcGePoint3d& point1);

    Zcad::ErrorStatus           extrudeFaces            (const ZcDbFullSubentPathArray& subentPaths,
                                                         double length,
                                                         const ZcGeVector3d& dir,
                                                         double taper);

    Zcad::ErrorStatus           extrudeFaces            (const ZcDbFullSubentPathArray& subentPaths,
                                                         const ZcGePoint3dArray& alongPath,
                                                         double taper);

    Zcad::ErrorStatus           extrudeConnectedFaces   (const ZcDbFullSubentPathArray& subentPaths,
                                                         double length,
                                                         const ZcGeVector3d& dir,
                                                         double taper);

    Zcad::ErrorStatus           extrudeConnectedFaces   (const ZcDbFullSubentPathArray& subentPaths,
                                                         const ZcGePoint3dArray& alongPath,
                                                         double taper);

    Zcad::ErrorStatus           mergeFaces              (const ZcDbFullSubentPathArray& subentPaths);
    Zcad::ErrorStatus           collapse                (const ZcDbSubentId& subent);
    Zcad::ErrorStatus           cap                     (const ZcDbFullSubentPathArray& edgePaths);
    Zcad::ErrorStatus           spin                    (const ZcDbSubentId& subent);

    Zcad::ErrorStatus           isWatertight            (bool& result) const;

    Zcad::ErrorStatus           numOfFaces              (ZSoft::Int32& result) const;
    Zcad::ErrorStatus           numOfSubDividedFaces    (ZSoft::Int32& result) const;
    Zcad::ErrorStatus           numOfSubDividedFacesAt  (const ZcDbFullSubentPathArray& subentPaths, ZSoft::Int32& result) const;
    Zcad::ErrorStatus           numOfVertices           (ZSoft::Int32& result) const;
    Zcad::ErrorStatus           numOfSubDividedVertices (ZSoft::Int32& result) const;
    Zcad::ErrorStatus           numOfEdges              (ZSoft::Int32& result) const;

    Zcad::ErrorStatus           getVertices             (ZcGePoint3dArray& vertexArray) const;
    Zcad::ErrorStatus           getEdgeArray            (ZcArray<ZSoft::Int32>& edgeArray) const;
    Zcad::ErrorStatus           getFaceArray            (ZcArray<ZSoft::Int32>& faceArray) const;
    Zcad::ErrorStatus           getNormalArray          (ZcGeVector3dArray& normalArray) const;

    Zcad::ErrorStatus           getSubDividedVertices   (ZcGePoint3dArray& vertexArray) const;
    Zcad::ErrorStatus           getSubDividedFaceArray  (ZcArray<ZSoft::Int32>& faceArray) const;
    Zcad::ErrorStatus           getSubDividedNormalArray(ZcGeVector3dArray& normalArray) const;

    Zcad::ErrorStatus           getVertexAt             (ZSoft::Int32 nIndex, ZcGePoint3d& vertex) const;
    Zcad::ErrorStatus           setVertexAt             (ZSoft::Int32 nIndex, const ZcGePoint3d& vertex);
    Zcad::ErrorStatus           getVertexAt             (const ZcDbSubentId& id, ZcGePoint3d& vertex) const;
    Zcad::ErrorStatus           setVertexAt             (const ZcDbSubentId& id, const ZcGePoint3d& vertex);

    Zcad::ErrorStatus           getSubDividedVertexAt   (ZSoft::Int32 nIndex, ZcGePoint3d& vertex) const;
    Zcad::ErrorStatus           getSubDividedVertexAt   (const ZcDbSubentId& id, ZcGePoint3d& vertex) const;

    Zcad::ErrorStatus           setCrease               (double creaseVal);
    Zcad::ErrorStatus           setCrease               (const ZcDbFullSubentPathArray& subentPaths, double creaseVal);
    Zcad::ErrorStatus           getCrease               (const ZcDbFullSubentPathArray& subentPaths, ZcArray<double>& result) const;
    Zcad::ErrorStatus           getCrease               (const ZcDbSubentId& id, double& result) const;

    Zcad::ErrorStatus           getAdjacentSubentPath   (const ZcDbFullSubentPath& path,
                                                         ZcDb::SubentType type,
                                                         ZcDbFullSubentPathArray& subentPaths) const;

    Zcad::ErrorStatus           getSubentPath           (ZSoft::Int32 nIndex,
                                                         ZcDb::SubentType type,
                                                         ZcDbFullSubentPathArray& subentPaths) const;

    Zcad::ErrorStatus           convertToSurface        (bool bConvertAsSmooth, const ZcDbSubentId& id, ZcDbSurface*& pSurface) const;
    Zcad::ErrorStatus           convertToSurface        (bool bConvertAsSmooth, bool optimize, ZcDbSurface*& pSurface) const;
    Zcad::ErrorStatus           convertToSolid          (bool bConvertAsSmooth, bool optimize, ZcDb3dSolid*& pSolid) const;

    Zcad::ErrorStatus           getSubentColor          (const ZcDbSubentId& id, ZcCmColor& color) const;
    Zcad::ErrorStatus           setSubentColor          (const ZcDbSubentId& id, const ZcCmColor& color);
    Zcad::ErrorStatus           getSubentMaterial       (const ZcDbSubentId& id, ZcDbObjectId& material) const;
    Zcad::ErrorStatus           setSubentMaterial       (const ZcDbSubentId& id, const ZcDbObjectId& material);
    Zcad::ErrorStatus           getSubentMaterialMapper (const ZcDbSubentId& id, ZcGiMapper& mapper) const;
    Zcad::ErrorStatus           setSubentMaterialMapper (const ZcDbSubentId& id, const ZcGiMapper& mapper);

    Zcad::ErrorStatus           getFacePlane            (const ZcDbSubentId& id, ZcGePlane& facePlane) const;

    Zcad::ErrorStatus           computeVolume           (double &retVolume) const;
    Zcad::ErrorStatus           computeSurfaceArea      (double &retSurfArea) const;

    virtual void                dragStatus              (const ZcDb::DragStat status) override;
    virtual Zcad::ErrorStatus   subGetClassID           (CLSID* pClsid) const override;

    virtual bool                bounds                  ( ZcDbExtents& retBounds ) const override;

    Zcad::ErrorStatus           setSphere               (const ZcGeMatrix3d& xForm,
                                                         int divAxis,
                                                         int divHeight,
                                                         int subDLevel);

    Zcad::ErrorStatus           setCylinder             (const ZcGeMatrix3d& xForm,
                                                         int divAxis,
                                                         int divHeight,
                                                         int divCap,
                                                         int subDLevel);

    Zcad::ErrorStatus           setCone                 (const ZcGeMatrix3d& xForm,
                                                         int divAxis,
                                                         int divHeight,
                                                         int divCap,
                                                         double radiusRatio,
                                                         int subDLevel);

    Zcad::ErrorStatus           setTorus                (const ZcGeMatrix3d& xForm,
                                                         int divSection,
                                                         int divSweepPath,
                                                         double sectionRadiusRatio,
                                                         double sectionRotate,
                                                         int subDLevel);

    Zcad::ErrorStatus           setBox                  (const ZcGeMatrix3d& xForm,
                                                         int divX,
                                                         int divY,
                                                         int divZ,
                                                         int subDLevel);

    Zcad::ErrorStatus           setWedge                (const ZcGeMatrix3d& xForm,
                                                         int divLength,
                                                         int divWidth,
                                                         int divHeight,
                                                         int divSlope,
                                                         int divCap,
                                                         int subDLevel);

    Zcad::ErrorStatus           setPyramid              (const ZcGeMatrix3d& xForm,
                                                         int divLength,
                                                         int divHeight,
                                                         int divCap,
                                                         int nSides,
                                                         double radiusRatio,
                                                         int subDLevel);

    Zcad::ErrorStatus           computeRayIntersection  (const ZcGePoint3d &rayStart,
                                                         const ZcGeVector3d &rayDir,
                                                         ZcArray<ZcDbSubentId> &retSubents,
                                                         ZcArray<double> &retIntersectDist,
                                                         ZcGePoint3dArray& retIntersectPoint) const;

    Zcad::ErrorStatus           setVertexNormalArray(ZcGeVector3dArray &arr);
    Zcad::ErrorStatus           setVertexTextureArray(ZcGePoint3dArray &arr);
    Zcad::ErrorStatus           setVertexColorArray(ZcArray<ZcCmEntityColor> &arr);

    Zcad::ErrorStatus           getVertexNormalArray(ZcGeVector3dArray &arr);
    Zcad::ErrorStatus           getVertexTextureArray(ZcGePoint3dArray &arr);
    Zcad::ErrorStatus           getVertexColorArray(ZcArray<ZcCmEntityColor> &arr);
};

struct MeshFaceterSettings
{
    double faceterDevSurface;
    double faceterDevNormal;
    double faceterGridRatio;
    double faceterMaxEdgeLength;
    ZSoft::UInt16 faceterMaxGrid;
    ZSoft::UInt16 faceterMinUGrid; 
    ZSoft::UInt16 faceterMinVGrid; 
    ZSoft::Int16 faceterMeshType;
};

typedef struct MeshFaceterSettings  ZcDbFaceterSettings;

ZCDB_PORT  Zcad::ErrorStatus zcdbGetObjectMesh(ZcDbObject *pObj, 
                                               const ZcDbFaceterSettings *faceter,
                                               ZcGePoint3dArray& vertexArray, 
                                               ZcArray<ZSoft::Int32>& faceArray,
                                               ZcGiFaceData*& faceData); 

#pragma pack(pop)
