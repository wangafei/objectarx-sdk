/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "dbmain.h"
#include "dbsubeid.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "dbRevolveOptions.h"
#include "dbSweepOptions.h"
#include "dbLoftOptions.h"

#include "GcDbAssocGlobal.h"
#include "GcDbCompoundObjectId.h"

#pragma pack(push, 8)

class GcDbLoftProfile;
class GcDbBlendOptions;
class GcDbNurbSurface;
class GcDb3dProfile;
class GcDbRevolvedSurface;
class GcDbExtrudedSurface;
class GcDbSweptSurface;

class GcDbPathRef;

typedef GcArray<GcDbNurbSurface*> GcDbNurbSurfaceArray;

class GCDB_PORT GcDbSurface : public GcDbEntity
{
public:
  enum WireframeType {
    kIsolines = 0,
    kIsoparms = 1
  };

  enum EdgeExtensionType {
    kExtendEdge = 0x000,
    kStretchEdge = 0x001,
  };

  GcDbSurface();
  ~GcDbSurface();
  GEOMENT_DECLARE_MEMBERS(GcDbSurface);

  static Gcad::ErrorStatus createFrom(const GcDbEntity* pFromEntity, GcDbSurface*& pNewSurface);
  static Gcad::ErrorStatus createExtrudedSurface(GcDb3dProfile *pSweep,
    const GcGeVector3d& directionVec,
    GcDbSweepOptions& sweepOptions,
    GcDbExtrudedSurface*& newExtrudedSurface);
  static Gcad::ErrorStatus createExtrudedSurface(GcDb3dProfile *pSweep,
    const GcGeVector3d& directionVec,
    GcDbSweepOptions& sweepOptions,
    bool  bAssociativeEnabled,
    GcDbObjectId& newExtrudedSurfaceId);

  static Gcad::ErrorStatus createRevolvedSurface(GcDb3dProfile *pRev,
    const GcGePoint3d& axisPnt,
    const GcGeVector3d& axisDir,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions,
    GcDbRevolvedSurface*& newRevolvedSurface);
  static Gcad::ErrorStatus createRevolvedSurface(GcDb3dProfile *pRev,
    const GcGePoint3d& axisPnt,
    const GcGeVector3d& axisDir,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions,
    bool  bAssociativeEnabled,
    GcDbObjectId& newSurfaceId);
  static Gcad::ErrorStatus createRevolvedSurface(GcDb3dProfile *pRev,
    GcDb3dProfile *pAxis,
    bool flipAxisDirection,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions,
    GcDbRevolvedSurface*& newRevolvedSurface);
  static Gcad::ErrorStatus createRevolvedSurface(GcDb3dProfile *pRev,
    GcDb3dProfile *pAxis,
    bool flipAxisDirection,
    double revAngle, double startAngle,
    GcDbRevolveOptions& revolveOptions,
    bool  bAssociativeEnabled,
    GcDbObjectId& newRevolvedSurfaceId);
  static Gcad::ErrorStatus createSweptSurface(GcDb3dProfile *pSweep,
    GcDb3dProfile *pPath,
    GcDbSweepOptions& sweepOptions,
    GcDbSweptSurface*& newSweptSurface);
  static Gcad::ErrorStatus createSweptSurface(GcDb3dProfile *pSweep,
    GcDb3dProfile *pPath,
    GcDbSweepOptions& sweepOptions,
    bool  bAssociativeEnabled,
    GcDbObjectId& newSurfaceId);
  static Gcad::ErrorStatus createLoftedSurface(const GcArray<GcDbLoftProfile*>& crossSections,
    const GcArray<GcDbLoftProfile*>& guides,
    GcDbLoftProfile *pPath, GcDbLoftOptions& loftOptions,
    GcDbSurface*& newSurface);
  static Gcad::ErrorStatus createLoftedSurface(const GcArray<GcDbLoftProfile*>& crossSections,
    const GcArray<GcDbLoftProfile*>& guides,
    GcDbLoftProfile *pPath, GcDbLoftOptions& loftOptions,
    bool  bAssociativeEnabled,
    GcDbObjectId& newSurfaceId);
  static Gcad::ErrorStatus createNetworkSurface(const GcArray<GcDb3dProfile*>& uProfiles,
    const GcArray<GcDb3dProfile*>& vProfiles,
    GcDbSurface*& newSurface);
  static Gcad::ErrorStatus createNetworkSurface(const GcArray<GcDb3dProfile*>& uProfiles,
    const GcArray<GcDb3dProfile*>& vProfiles,
    bool  bAssociativeEnabled,
    GcDbObjectId& newSurfaceId);
  static Gcad::ErrorStatus createPatchSurface(const GcDbPathRef& pathRef,
    const GcDbObjectIdArray& constraintIds,
    int continuity,
    double bulge,
    GcDbSurface*& newSurface);
  static Gcad::ErrorStatus createPatchSurface(const GcDbPathRef& pathRef,
    const GcDbObjectIdArray& constraintIds,
    int continuity,
    double bulge,
    bool  bAssociativeEnabled,
    GcDbObjectId& newSurfaceId);
  static Gcad::ErrorStatus createBlendSurface(GcDbLoftProfile* startProfile,
    GcDbLoftProfile* endProfile,
    GcDbBlendOptions* blendOptions,
    GcDbSurface*& blendSurface);
  static Gcad::ErrorStatus createBlendSurface(GcDbLoftProfile* startProfile,
    GcDbLoftProfile* endProfile,
    GcDbBlendOptions* blendOptions,
    bool  bAssociativeEnabled,
    GcDbObjectId& blendSurfaceId);
  static Gcad::ErrorStatus createFilletSurface(const GcDbObjectId& surfId1,
    const GcGePoint3d& pickPt1,
    const GcDbObjectId& surfId2,
    const GcGePoint3d& pickPt2,
    double radius,
    GcDb::FilletTrimMode trimMode,
    const GcGeVector3d& projDir,
    GcDbSurface*& filletSurface);
  static Gcad::ErrorStatus createFilletSurface(const GcDbObjectId& surfId1,
    const GcGePoint3d& pickPt1,
    const GcDbObjectId& surfId2,
    const GcGePoint3d& pickPt2,
    double radius,
    GcDb::FilletTrimMode trimMode,
    const GcGeVector3d& projDir,
    bool  bAssociativeEnabled,
    GcDbObjectId& filletSurfaceId);
  static Gcad::ErrorStatus createOffsetSurface(GcDbEntity* pInputSurface,
    double offsetDistance,
    GcDbEntity*& offsetSurface);
  static Gcad::ErrorStatus createOffsetSurface(GcDbEntity* pInputSurface,
    double offsetDistance,
    bool  bAssociativeEnabled,
    GcDbObjectId& offsetSurfaceId);
  static Gcad::ErrorStatus createExtendSurface(GcDbObjectId sourceSurface,
    const GcArray<GcDbSubentId>& edges,
    double extDist,
    EdgeExtensionType extOption,
    bool  bAssociativeEnabled,
    GcDbObjectId& newExtendSurfaceId);
  static Gcad::ErrorStatus trimSurface(const GcDbObjectId &blankSurfaceId,
    const GcDbObjectIdArray &toolIds,
    const GcDbObjectIdArray &toolCurveIds,
    const GcArray<GcGeVector3d> projVectors,
    const GcGePoint3d& pickPoint,
    const GcGeVector3d& viewVector,
    bool bAutoExtend,
    bool bAssociativeEnabled);

  virtual Gcad::ErrorStatus convertToRegion(GcArray<GcDbEntity*>& regions);
  virtual Gcad::ErrorStatus thicken(double thickness, bool bBothSides, GcDb3dSolid*& pSolid) const;
  virtual Gcad::ErrorStatus createInterferenceObjects(
    GcArray<GcDbEntity*>& interferenceObjects,
    GcDbEntity* pEntity, unsigned int flags) const;
  virtual Gcad::ErrorStatus booleanUnion(const GcDbSurface* pSurface2, GcDbSurface*& pNewSurface);
  virtual Gcad::ErrorStatus booleanSubtract(const GcDbSurface* pSurface2, GcDbSurface*& pNewSurface);
  virtual Gcad::ErrorStatus booleanSubtract(const GcDb3dSolid* pSolid, GcDbSurface*& pNewSurface);
  virtual Gcad::ErrorStatus booleanIntersect(const GcDbSurface* pSurface2, GcArray<GcDbEntity*>& intersectionEntities);
  virtual Gcad::ErrorStatus booleanIntersect(const GcDb3dSolid* pSolid, GcArray<GcDbEntity*>& intersectionEntities);
  virtual Gcad::ErrorStatus imprintEntity(const GcDbEntity* pEntity);
  virtual Gcad::ErrorStatus createSectionObjects(const GcGePlane& sectionPlane, GcArray<GcDbEntity*>& sectionObjects) const;
  virtual Gcad::ErrorStatus sliceByPlane(const GcGePlane& slicePlane, GcDbSurface*& pNegHalfSurface, GcDbSurface*& pNewSurface);
  virtual Gcad::ErrorStatus sliceBySurface(const GcDbSurface* pSlicingSurface, GcDbSurface*& pNegHalfSurface,
    GcDbSurface*& pNewSurface);
  virtual Gcad::ErrorStatus chamferEdges(const GcArray<GcDbSubentId *> &edgeSubentIds,
    const GcDbSubentId& baseFaceSubentId,
    double baseDist, double otherDist);
  virtual Gcad::ErrorStatus filletEdges(const GcArray<GcDbSubentId *> &edgeSubentIds,
    const GcGeDoubleArray& radius,
    const GcGeDoubleArray& startSetback,
    const GcGeDoubleArray& endSetback);
  Gcad::ErrorStatus chamferEdges(const GcArray<GcDbSubentId *> &edgeSubentIds,
    const GcDbSubentId& baseFaceSubentId,
    double baseDist, double otherDist, bool bAssociativeEnabled);
  Gcad::ErrorStatus filletEdges(const GcArray<GcDbSubentId *> &edgeSubentIds, double radius, bool bAssociativeEnabled);

  virtual Gcad::ErrorStatus setSubentColor(const GcDbSubentId& subentId, const GcCmColor& color);
  virtual Gcad::ErrorStatus getSubentColor(const GcDbSubentId& subentId, GcCmColor& color) const;

  virtual Gcad::ErrorStatus setSubentMaterial(const GcDbSubentId& subentId, const GcDbObjectId& matId);
  virtual Gcad::ErrorStatus getSubentMaterial(const GcDbSubentId& subentId, GcDbObjectId& matId) const;

  virtual Gcad::ErrorStatus setSubentMaterialMapper(const GcDbSubentId& subentId, const GcGiMapper& mapper);
  virtual Gcad::ErrorStatus getSubentMaterialMapper(const GcDbSubentId& subentId, GcGiMapper& mapper) const;

  virtual Gcad::ErrorStatus getArea(double& area) const;
  void dragStatus(const GcDb::DragStat) override;

  virtual void* ASMBodyCopy(bool bDeepCopy = false) const;
  virtual void const *      getLockedASMBody();
  virtual void              unlockASMBody();
  virtual void*             getLockedWritableASMBody();
  virtual void              commitWritableASMBody();
  virtual Gcad::ErrorStatus setASMBody(const void* modelerBody);

  virtual GcDbSubentId internalSubentId(void* ent) const;
  virtual void* internalSubentPtr(const GcDbSubentId& id) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  virtual Gsoft::UInt16       uIsolineDensity() const;
  virtual Gcad::ErrorStatus   setUIsolineDensity(Gsoft::UInt16 numIsolines);

  virtual Gsoft::UInt16       vIsolineDensity() const;
  virtual Gcad::ErrorStatus   setVIsolineDensity(Gsoft::UInt16 numIsolines);

  WireframeType       getWireframeType() const;
  Gcad::ErrorStatus   setWireframeType(WireframeType type);
  Gcad::ErrorStatus   getPerimeter(double& perimeter) const;

  GcDbObjectId      creationActionBodyId() const;
  Gcad::ErrorStatus modificationActionBodyIds(GcDbObjectIdArray& modificationActionBodyIds) const;
  Gcad::ErrorStatus extendEdges(GcDbFullSubentPathArray& edges,
    double extDist, EdgeExtensionType extOption, bool  bAssociativeEnabled);
  Gcad::ErrorStatus rayTest(const GcGePoint3d& rayBasePoint, const GcGeVector3d& rayDir,
    double rayRadius, GcArray<GcDbSubentId>& subEntIds, GcGeDoubleArray& parameters) const;
  Gcad::ErrorStatus convertToNurbSurface(GcDbNurbSurfaceArray& nsArray);
  Gcad::ErrorStatus getPlane(GcGePlane& plane, GcDb::Planarity& planarity) const override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:
  Gcad::ErrorStatus projectOnToSurface(const GcDbEntity* pEntityToProject,
    const GcGeVector3d& projectionDirection,
    GcArray<GcDbEntity*>& projectedEntities) const;
  virtual bool usesGraphicsCache();
};
#pragma pack(pop)