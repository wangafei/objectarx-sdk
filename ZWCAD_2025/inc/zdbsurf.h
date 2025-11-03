
#pragma once

#include "zdbmain.h"
#include "zdbsubeid.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zdbRevolveOptions.h"
#include "zdbSweepOptions.h"
#include "zdbLoftOptions.h"

#include "zAcDbAssocGlobal.h"
#include "zAcDbCompoundObjectId.h"

#pragma pack(push, 8)

class ZcDbLoftProfile;
class ZcDbBlendOptions;
class ZcDbNurbSurface;
class ZcDb3dProfile;
class ZcDbRevolvedSurface;
class ZcDbExtrudedSurface;
class ZcDbSweptSurface;

class ZcDbPathRef;

typedef ZcArray<ZcDbNurbSurface*> ZcDbNurbSurfaceArray;

class ZCDB_PORT ZcDbSurface: public ZcDbEntity
{
public:

    enum WireframeType {

        kIsolines = 0,

        kIsoparms = 1
    };

    enum EdgeExtensionType {

        kExtendEdge  = 0x000,

        kStretchEdge = 0x001,
    };

    ZcDbSurface();
    virtual ~ZcDbSurface();
    ZCDB_DECLARE_MEMBERS(ZcDbSurface);

    static Zcad::ErrorStatus createFrom ( const ZcDbEntity* pFromEntity,
                                          ZcDbSurface*& pNewSurface );

    static Zcad::ErrorStatus createExtrudedSurface ( ZcDb3dProfile *pSweep,
                                                               const ZcGeVector3d& directionVec,
                                                               ZcDbSweepOptions& sweepOptions,
                                                               ZcDbExtrudedSurface*& newExtrudedSurface );

    static Zcad::ErrorStatus createExtrudedSurface ( ZcDb3dProfile *pSweep,
                                                                    const ZcGeVector3d& directionVec,
                                                                    ZcDbSweepOptions& sweepOptions,
                                                                    bool  bAssociativeEnabled,
                                                                    ZcDbObjectId& newExtrudedSurfaceId );

    static Zcad::ErrorStatus createRevolvedSurface ( ZcDb3dProfile *pRev,
                                                               const ZcGePoint3d& axisPnt,
                                                               const ZcGeVector3d& axisDir,
                                                               double revAngle, double startAngle,
                                                               ZcDbRevolveOptions& revolveOptions,
                                                               ZcDbRevolvedSurface*& newRevolvedSurface );

    static Zcad::ErrorStatus createRevolvedSurface ( ZcDb3dProfile *pRev,
                                                                    const ZcGePoint3d& axisPnt,
                                                                    const ZcGeVector3d& axisDir,
                                                                    double revAngle, double startAngle,
                                                                    ZcDbRevolveOptions& revolveOptions,
                                                                    bool  bAssociativeEnabled,
                                                                    ZcDbObjectId& newSurfaceId );

    static Zcad::ErrorStatus createRevolvedSurface ( ZcDb3dProfile *pRev,
                                                               ZcDb3dProfile *pAxis,
                                                               bool flipAxisDirection,
                                                               double revAngle, double startAngle,
                                                               ZcDbRevolveOptions& revolveOptions,
                                                               ZcDbRevolvedSurface*& newRevolvedSurface );

    static Zcad::ErrorStatus createRevolvedSurface ( ZcDb3dProfile *pRev,
                                                                    ZcDb3dProfile *pAxis,
                                                                    bool flipAxisDirection,
                                                                    double revAngle, double startAngle,
                                                                    ZcDbRevolveOptions& revolveOptions,
                                                                    bool  bAssociativeEnabled,
                                                                    ZcDbObjectId& newRevolvedSurfaceId );

    static Zcad::ErrorStatus createSweptSurface ( ZcDb3dProfile *pSweep,
                                                            ZcDb3dProfile *pPath,
                                                            ZcDbSweepOptions& sweepOptions,
                                                            ZcDbSweptSurface*& newSweptSurface);

    static Zcad::ErrorStatus createSweptSurface ( ZcDb3dProfile *pSweep,
                                                                 ZcDb3dProfile *pPath,
                                                                 ZcDbSweepOptions& sweepOptions,
                                                                 bool  bAssociativeEnabled,
                                                                 ZcDbObjectId& newSurfaceId );

    static Zcad::ErrorStatus createLoftedSurface ( const ZcArray<ZcDbLoftProfile*>& crossSections,
                                                             const ZcArray<ZcDbLoftProfile*>& guides,
                                                             ZcDbLoftProfile *pPath, ZcDbLoftOptions& loftOptions,
                                                             ZcDbSurface*& newSurface );

    static Zcad::ErrorStatus createLoftedSurface ( const ZcArray<ZcDbLoftProfile*>& crossSections,
                                                                  const ZcArray<ZcDbLoftProfile*>& guides,
                                                                  ZcDbLoftProfile *pPath, ZcDbLoftOptions& loftOptions,
                                                                  bool  bAssociativeEnabled,
                                                                  ZcDbObjectId& newSurfaceId );

    static Zcad::ErrorStatus createNetworkSurface ( const ZcArray<ZcDb3dProfile*>& uProfiles,
                                                              const ZcArray<ZcDb3dProfile*>& vProfiles,
                                                              ZcDbSurface*& newSurface);

    static Zcad::ErrorStatus createNetworkSurface ( const ZcArray<ZcDb3dProfile*>& uProfiles,
                                                              const ZcArray<ZcDb3dProfile*>& vProfiles,
                                                              bool  bAssociativeEnabled,
                                                              ZcDbObjectId& newSurfaceId );

    static Zcad::ErrorStatus createPatchSurface ( const ZcDbPathRef& pathRef,
                                                            const ZcDbObjectIdArray& constraintIds,
                                                            int continuity,
                                                            double bulge,
                                                            ZcDbSurface*& newSurface);

    static Zcad::ErrorStatus createPatchSurface ( const ZcDbPathRef& pathRef,
                                                                 const ZcDbObjectIdArray& constraintIds,
                                                                 int continuity,
                                                                 double bulge,
                                                                 bool  bAssociativeEnabled,
                                                                 ZcDbObjectId& newSurfaceId);

    static Zcad::ErrorStatus createBlendSurface ( ZcDbLoftProfile* startProfile,
                                                            ZcDbLoftProfile* endProfile,
                                                            ZcDbBlendOptions* blendOptions,
                                                            ZcDbSurface*& blendSurface);

    static Zcad::ErrorStatus createBlendSurface ( ZcDbLoftProfile* startProfile,
                                                                 ZcDbLoftProfile* endProfile,
                                                                 ZcDbBlendOptions* blendOptions,
                                                                 bool  bAssociativeEnabled,
                                                                 ZcDbObjectId& blendSurfaceId);

    static Zcad::ErrorStatus createFilletSurface ( const ZcDbObjectId& surfId1,
                                                             const ZcGePoint3d& pickPt1,
                                                             const ZcDbObjectId& surfId2,
                                                             const ZcGePoint3d& pickPt2,
                                                             double radius,
                                                             ZcDb::FilletTrimMode trimMode,
                                                             const ZcGeVector3d& projDir,
                                                             ZcDbSurface*& filletSurface);

    static Zcad::ErrorStatus createFilletSurface ( const ZcDbObjectId& surfId1,
                                                                  const ZcGePoint3d& pickPt1,
                                                                  const ZcDbObjectId& surfId2,
                                                                  const ZcGePoint3d& pickPt2,
                                                                  double radius,
                                                                  ZcDb::FilletTrimMode trimMode,
                                                                  const ZcGeVector3d& projDir,
                                                                  bool  bAssociativeEnabled,
                                                                  ZcDbObjectId& filletSurfaceId);

    static Zcad::ErrorStatus createOffsetSurface ( ZcDbEntity* pInputSurface,
                                                             double offsetDistance,
                                                             ZcDbEntity*& offsetSurface);

    static Zcad::ErrorStatus createOffsetSurface ( ZcDbEntity* pInputSurface,
                                                                  double offsetDistance,
                                                                  bool  bAssociativeEnabled,
                                                                  ZcDbObjectId& offsetSurfaceId);

    static Zcad::ErrorStatus createExtendSurface ( ZcDbObjectId sourceSurface, 
                                                             const ZcArray<ZcDbSubentId>& edges,
                                                             double extDist,
                                                             EdgeExtensionType extOption,
                                                             bool  bAssociativeEnabled,
                                                             ZcDbObjectId& newExtendSurfaceId );

    static Zcad::ErrorStatus trimSurface( const ZcDbObjectId &blankSurfaceId, 
                                                    const ZcDbObjectIdArray &toolIds,
                                                    const ZcDbObjectIdArray &toolCurveIds,
                                                    const ZcArray<ZcGeVector3d> projVectors,
                                                    const ZcGePoint3d& pickPoint,
                                                    const ZcGeVector3d& viewVector,
                                                    bool bAutoExtend,
                                                    bool bAssociativeEnabled);

    virtual Zcad::ErrorStatus convertToRegion ( ZcArray<ZcDbEntity*>& regions );

    virtual Zcad::ErrorStatus thicken(double thickness,
        bool bBothSides, ZcDb3dSolid*& pSolid) const;

    virtual Zcad::ErrorStatus createInterferenceObjects(
        ZcArray<ZcDbEntity*>& interferenceObjects,
        ZcDbEntity* pEntity, unsigned int flags ) const;

    virtual Zcad::ErrorStatus booleanUnion(const ZcDbSurface* pSurface2,
        ZcDbSurface*& pNewSurface);
    virtual Zcad::ErrorStatus booleanSubtract(const ZcDbSurface* pSurface2,
        ZcDbSurface*& pNewSurface);
    virtual Zcad::ErrorStatus booleanSubtract(const ZcDb3dSolid* pSolid,
        ZcDbSurface*& pNewSurface);
    virtual Zcad::ErrorStatus booleanIntersect(const ZcDbSurface* pSurface2,
        ZcArray<ZcDbEntity*>& intersectionEntities);
    virtual Zcad::ErrorStatus booleanIntersect(const ZcDb3dSolid* pSolid,
        ZcArray<ZcDbEntity*>& intersectionEntities);
    virtual Zcad::ErrorStatus imprintEntity(const ZcDbEntity* pEntity);
    virtual Zcad::ErrorStatus createSectionObjects(const ZcGePlane& sectionPlane,
        ZcArray<ZcDbEntity*>& sectionObjects) const;
    virtual Zcad::ErrorStatus sliceByPlane(const ZcGePlane& slicePlane,
        ZcDbSurface*& pNegHalfSurface, ZcDbSurface*& pNewSurface);
    virtual Zcad::ErrorStatus sliceBySurface(
        const ZcDbSurface* pSlicingSurface, ZcDbSurface*& pNegHalfSurface,
        ZcDbSurface*& pNewSurface);
    virtual Zcad::ErrorStatus chamferEdges(
        const ZcArray<ZcDbSubentId *> &edgeSubentIds,
        const ZcDbSubentId& baseFaceSubentId,
        double baseDist, double otherDist);
    virtual Zcad::ErrorStatus filletEdges(
        const ZcArray<ZcDbSubentId *> &edgeSubentIds,
        const ZcGeDoubleArray& radius,
        const ZcGeDoubleArray& startSetback,
        const ZcGeDoubleArray& endSetback);

    Zcad::ErrorStatus chamferEdges(
        const ZcArray<ZcDbSubentId *> &edgeSubentIds,
        const ZcDbSubentId& baseFaceSubentId,
        double baseDist, double otherDist, bool bAssociativeEnabled);

    Zcad::ErrorStatus filletEdges(
        const ZcArray<ZcDbSubentId *> &edgeSubentIds,
        double radius, bool bAssociativeEnabled);

    virtual Zcad::ErrorStatus setSubentColor(const ZcDbSubentId& subentId,
        const ZcCmColor& color);
    virtual Zcad::ErrorStatus getSubentColor(const ZcDbSubentId& subentId,
        ZcCmColor& color) const;

    virtual Zcad::ErrorStatus setSubentMaterial(const ZcDbSubentId& subentId,
        const ZcDbObjectId& matId);
    virtual Zcad::ErrorStatus getSubentMaterial(const ZcDbSubentId& subentId,
        ZcDbObjectId& matId) const;

    virtual Zcad::ErrorStatus setSubentMaterialMapper(const ZcDbSubentId& subentId,
        const ZcGiMapper& mapper);
    virtual Zcad::ErrorStatus getSubentMaterialMapper(const ZcDbSubentId& subentId,
        ZcGiMapper& mapper) const;

    virtual Zcad::ErrorStatus getArea(double& area) const;

	virtual void dragStatus(const ZcDb::DragStat) override;

	virtual void* ZSMBodyCopy(bool bDeepCopy = false) const;      
	virtual void const *      getLockedZSMBody();                 
	virtual void              unlockZSMBody();                    
	virtual void*             getLockedWritableZSMBody();         
	virtual void              commitWritableZSMBody();            
	virtual Zcad::ErrorStatus setZSMBody(const void* modelerBody);

    virtual ZcDbSubentId internalSubentId(void* ent) const;
    virtual void* internalSubentPtr(const ZcDbSubentId& id) const;

	virtual Zcad::ErrorStatus dwgInFields(ZcDbDwgFiler* pFiler) override;
	virtual Zcad::ErrorStatus dwgOutFields(ZcDbDwgFiler* pFiler) const override;
	virtual Zcad::ErrorStatus dxfInFields(ZcDbDxfFiler* pFiler) override;
	virtual Zcad::ErrorStatus dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual ZSoft::UInt16       uIsolineDensity() const;
    virtual Zcad::ErrorStatus   setUIsolineDensity(ZSoft::UInt16 numIsolines);

    virtual ZSoft::UInt16       vIsolineDensity() const;
    virtual Zcad::ErrorStatus   setVIsolineDensity(ZSoft::UInt16 numIsolines);

	  WireframeType       getWireframeType() const;

	  Zcad::ErrorStatus   setWireframeType(WireframeType type);

	  Zcad::ErrorStatus   getPerimeter(double& perimeter) const;

	ZcDbObjectId   creationActionBodyId() const;

	Zcad::ErrorStatus   modificationActionBodyIds(ZcDbObjectIdArray& modificationActionBodyIds) const;

	Zcad::ErrorStatus extendEdges(ZcDbFullSubentPathArray& edges,  
        double extDist, EdgeExtensionType extOption, bool  bAssociativeEnabled);

	Zcad::ErrorStatus rayTest(const ZcGePoint3d& rayBasePoint, const ZcGeVector3d& rayDir,
                              double rayRadius, ZcArray<ZcDbSubentId>& subEntIds, ZcGeDoubleArray& parameters) const;

	Zcad::ErrorStatus convertToNurbSurface(ZcDbNurbSurfaceArray& nsArray);

	virtual Zcad::ErrorStatus getPlane(ZcGePlane& plane, ZcDb::Planarity& planarity) const override;

protected:

    virtual Zcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;

public:

    Zcad::ErrorStatus projectOnToSurface(const ZcDbEntity* pEntityToProject,
        const ZcGeVector3d& projectionDirection,
        ZcArray<ZcDbEntity*>& projectedEntities) const;

	virtual bool usesGraphicsCache();
};
#pragma pack(pop)
