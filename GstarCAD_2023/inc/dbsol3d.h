/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef GEOMENT_DBSOL3D_H
#define GEOMENT_DBSOL3D_H

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "gcarray.h"
#include "db3dProfile.h"
#include "geintarr.h"

#pragma pack(push, 8)

class GcDbSurface;

class GCDB_PORT GcDb3dSolid : public  GcDbEntity
{
public:
  GCDB_DECLARE_MEMBERS(GcDb3dSolid);
  GcDb3dSolid();
  ~GcDb3dSolid();

  virtual Gcad::ErrorStatus createBox(double xLen, double yLen, double zLen);
  virtual Gcad::ErrorStatus createFrustum(double height, double xRadius, double yRadius, double topXRadius);
  virtual Gcad::ErrorStatus createSphere(double radius);
  virtual Gcad::ErrorStatus createTorus(double majorRadius, double minorRadius);
  virtual Gcad::ErrorStatus createPyramid(double height, int sides, double radius, double topRadius = 0.0);
  virtual Gcad::ErrorStatus createWedge(double xLen, double yLen, double zLen);
  virtual Gcad::ErrorStatus extrude(const GcDbRegion* region, double height, double taperAngle = 0.0);
  virtual Gcad::ErrorStatus extrudeAlongPath(const GcDbRegion* region, const GcDbCurve* path, double taperAngle = 0.0);

  virtual Gcad::ErrorStatus revolve(const GcDbRegion* region,
    const GcGePoint3d& axisPoint, const GcGeVector3d& axisDir,
    double angleOfRevolution);

  virtual Gcad::ErrorStatus createRevolvedSolid(GcDbEntity* pRevEnt,
    const GcGePoint3d& axisPnt,
    const GcGeVector3d& axisDir,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions);
  virtual Gcad::ErrorStatus createRevolvedSolid(GcDbEntity* pRevEnt,
    const GcDbSubentId& faceSubentId,
    const GcGePoint3d& axisPnt,
    const GcGeVector3d& axisDir,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions);
  virtual Gcad::ErrorStatus createSweptSolid(GcDbEntity* pSweepEnt,
    GcDbEntity* pPathEnt,
    GcDbSweepOptions& sweepOptions);
  virtual Gcad::ErrorStatus createSweptSolid(GcDbEntity *pSweepEnt,
    const GcDbSubentId& faceSubentId,
    GcDbEntity* pPathEnt,
    GcDbSweepOptions& sweepOptions);
  virtual Gcad::ErrorStatus createExtrudedSolid(GcDbEntity* pSweepEnt,
    const GcGeVector3d& directionVec,
    GcDbSweepOptions& sweepOptions);
  virtual Gcad::ErrorStatus createExtrudedSolid(GcDbEntity* pSweepEnt,
    const GcDbSubentId& faceSubentId,
    const GcGeVector3d& directionVec,
    GcDbSweepOptions& sweepOptions);
  virtual Gcad::ErrorStatus createExtrudedSolid(GcDbEntity* pSweepEnt,
    const GcDbSubentId& faceSubentId,
    double height,
    GcDbSweepOptions& sweepOptions);
  virtual Gcad::ErrorStatus createLoftedSolid(
    GcArray<GcDbEntity*>& crossSectionCurves,
    GcArray<GcDbEntity*>& guideCurves,
    GcDbEntity* pPathCurve, GcDbLoftOptions& loftOptions);

  Gcad::ErrorStatus createLoftedSolid(
    const GcArray<GcDbLoftProfile*>& crossSections,
    const GcArray<GcDbLoftProfile*>& guides,
    GcDbLoftProfile *pPath, GcDbLoftOptions& loftOptions);

  virtual Gcad::ErrorStatus createFrom(const GcDbEntity* pFromEntity);
  virtual  Gcad::ErrorStatus getArea(double& area) const;
  void dragStatus(const GcDb::DragStat) override;

  virtual void* ASMBodyCopy(bool bDeepCopy = false) const;
  virtual void const * getLockedASMBody();
  virtual void unlockASMBody();
  virtual void*             getLockedWritableASMBody();
  virtual void              commitWritableASMBody();
  virtual Gcad::ErrorStatus setASMBody(const void* modelerBody);
  virtual Gcad::ErrorStatus checkInterference(const GcDb3dSolid* otherSolid,
    Gsoft::Boolean createNewSolid, Gsoft::Boolean& solidsInterfere,
    GcDb3dSolid*& commonVolumeSolid)const;
  virtual Gcad::ErrorStatus getMassProp(double& volume,
    GcGePoint3d& centroid, double momInertia[3], double prodInertia[3],
    double prinMoments[3], GcGeVector3d prinAxes[3],
    double radiiGyration[3], GcDbExtents& extents) const;
  virtual Gsoft::Boolean isNull() const;

  virtual Gcad::ErrorStatus getSection(const GcGePlane& plane, GcDbRegion*& sectionRegion) const;
  virtual Gcad::ErrorStatus stlOut(const GCHAR* fileName, Gsoft::Boolean asciiFormat, double maxSurfaceDeviation = 0.0) const;

  virtual GcDbSubentId internalSubentId(void* ent) const;
  virtual void* internalSubentPtr(const GcDbSubentId& id) const;

  virtual Gcad::ErrorStatus booleanOper(GcDb::BoolOperType operation, GcDb3dSolid* solid);
  virtual Gcad::ErrorStatus getSlice(const GcGePlane& plane, Gsoft::Boolean getNegHalfToo, GcDb3dSolid*& negHalfSolid);
  virtual Gcad::ErrorStatus getSlice(GcDbSurface* pSurface, bool bGetNegHalfToo, GcDb3dSolid*& pNegHalfSolid);

  virtual Gsoft::UInt32 numChanges() const;
  virtual Gcad::ErrorStatus copyEdge(const GcDbSubentId &subentId, GcDbEntity *&newEntity);
  virtual Gcad::ErrorStatus copyFace(const GcDbSubentId &subentId, GcDbEntity *&newEntity);
  virtual Gcad::ErrorStatus extrudeFaces(
    const GcArray<GcDbSubentId *> &faceSubentIds, double height,
    double taper);
  virtual Gcad::ErrorStatus extrudeFacesAlongPath(const GcArray<GcDbSubentId *> &faceSubentIds, const GcDbCurve* path);
  virtual Gcad::ErrorStatus imprintEntity(const GcDbEntity *pEntity);
  virtual Gcad::ErrorStatus cleanBody();
  virtual Gcad::ErrorStatus offsetBody(double offsetDistance);
  virtual Gcad::ErrorStatus offsetFaces(const GcArray<GcDbSubentId *> &faceSubentIds, double offsetDistance);
  virtual Gcad::ErrorStatus removeFaces(const GcArray<GcDbSubentId *> &faceSubentIds);
  virtual Gcad::ErrorStatus separateBody(GcArray<GcDb3dSolid *> &newSolids);
  virtual Gcad::ErrorStatus shellBody(const GcArray<GcDbSubentId *> &faceSubentIds, double offsetDistance);
  virtual Gcad::ErrorStatus taperFaces(
    const GcArray<GcDbSubentId *> &faceSubentIds,
    const GcGePoint3d &basePoint, const GcGeVector3d &draftVector,
    double draftAngle);
  virtual Gcad::ErrorStatus transformFaces(
    const GcArray<GcDbSubentId *> &faceSubentIds,
    const GcGeMatrix3d &matrix);
  virtual Gcad::ErrorStatus setSubentColor(const GcDbSubentId &subentId, const GcCmColor &color);
  virtual Gcad::ErrorStatus getSubentColor(const GcDbSubentId &subentId, GcCmColor &color) const;
  virtual Gcad::ErrorStatus setSubentMaterial(const GcDbSubentId &subentId, GcDbObjectId matId);
  virtual Gcad::ErrorStatus getSubentMaterial(const GcDbSubentId &subentId, GcDbObjectId& matId) const;
  virtual Gcad::ErrorStatus setSubentMaterialMapper(const GcDbSubentId &subentId, const GcGiMapper& mapper);
  virtual Gcad::ErrorStatus getSubentMaterialMapper(const GcDbSubentId &subentId, GcGiMapper& mapper) const;

  virtual bool recordHistory() const;
  virtual Gcad::ErrorStatus setRecordHistory(bool bRecord);

  virtual bool showHistory() const;
  virtual Gcad::ErrorStatus setShowHistory(bool bShow);

  virtual Gcad::ErrorStatus convertToBrepAtSubentPaths(const GcDbFullSubentPathArray& paths);
  virtual Gcad::ErrorStatus chamferEdges(
    const GcArray<GcDbSubentId *> &edgeSubentIds,
    const GcDbSubentId& baseFaceSubentId,
    double baseDist, double otherDist);
  virtual Gcad::ErrorStatus filletEdges(
    const GcArray<GcDbSubentId *> &edgeSubentIds,
    const GcGeDoubleArray& radius,
    const GcGeDoubleArray& startSetback,
    const GcGeDoubleArray& endSetback);
  virtual bool usesGraphicsCache();

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
  Gcad::ErrorStatus createSculptedSolid(
    const GcArray<GcDbEntity*>& limitingBodies,
    const GcGeIntArray& limitingFlags);

  Gcad::ErrorStatus projectOnToSolid(const GcDbEntity* pEntityToProject,
    const GcGeVector3d& projectionDirection,
    GcArray<GcDbEntity*>& projectedEntities) const;
};

#pragma pack(pop)
#endif