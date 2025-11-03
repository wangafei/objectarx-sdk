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


#ifndef _DBSURFACE_H_INCLUDED_
#define _DBSURFACE_H_INCLUDED_

#include "TD_PackPush.h"
#include "ModelerDefs.h"
#include "DbEntity.h"
#include "Db3dSolid.h"

class OdModelerGeometry;
class OdStreamBuf;
class OdBrBrep;
class OdDb3dProfile;
class OdDbExtrudedSurface;
class OdDbRevolvedSurface;
class OdDbSweptSurface;
class OdDbLoftProfile;
class OdDbPathRef;
class OdDbBlendOptions;
/** Description:
    This class implements a three-dimensional surface entity.
    
    Library:
    TD_Db
   
    {group:OdDb_Classes}
*/
class OdDbSurface;
typedef OdSmartPtr<OdDbSurface> OdDbSurfacePtr;

class OdDbNurbSurface;
typedef OdArray<OdDbNurbSurface*, OdMemoryAllocator<OdDbNurbSurface*> > OdDbNurbSurfaceArray;

class TOOLKIT_EXPORT OdDbSurface : public OdDbEntity
{
public:
  enum WireframeType 
  {
    kIsolines = 0,
    kIsoparms = 1
  };

  enum EdgeExtensionType
  {
    /** kExtendEdge (0x00) - Edges are extended.*/
    kExtendEdge = 0x00,
    /** kStretchEdge (0x01) - Edges are stretched.*/
    kStretchEdge = 0x01,
  };

  OdDbSurface();
  ODDB_DECLARE_MEMBERS(OdDbSurface);

  virtual ~OdDbSurface();
  /** Description:
     Returns the number of isolines in the U direction of the surface, displayed in wireframe mode for visualization.
  */
  virtual OdUInt16 uIsolineDensity() const;

  /** Description:
     Sets the number of isolines in the U direction of the surface, displayed in wireframe mode for visualization.
     Arguments:
     numIsolines (I) the number of isolines in the U direction of the surface, displayed in wireframe mode for visualization 
  */
  virtual OdResult setUIsolineDensity(OdUInt16 numIsolines);

  /** Description:
  */
  virtual OdUInt16 vIsolineDensity() const;
  virtual OdResult setVIsolineDensity(OdUInt16 numIsolines);

  /** Description:
    Creates an extruded surface from 2D entity with thickness
    or a planar surface from a closed curve or a region.
    Arguments:
    pFromEntity (I) input surface
    pNewSurface (O) resulting surface
  */
  static OdResult createFrom ( const OdDbEntity* pFromEntity, OdDbSurface*& pNewSurface );

  static OdResult createExtrudedSurface(OdDb3dProfile *pSweep,
                                        const OdGeVector3d& directionVec,
                                        OdDbSweepOptions& sweepOptions,
                                        OdDbExtrudedSurface*& newExtrudedSurface);

  static OdResult createExtrudedSurface(OdDb3dProfile *pSweep,
                                        const OdGeVector3d& directionVec,
                                        OdDbSweepOptions& sweepOptions,
                                        bool  bAssociativeEnabled,
                                        OdDbObjectId& newExtrudedSurfaceId);

  static OdResult createRevolvedSurface(OdDb3dProfile *pRev,
                                        const OdGePoint3d& axisPnt,
                                        const OdGeVector3d& axisDir,
                                        double revAngle, double startAngle,
                                        OdDbRevolveOptions& revolveOptions,
                                        OdDbRevolvedSurface*& newRevolvedSurface);

  static OdResult createRevolvedSurface(OdDb3dProfile *pRev,
                                        const OdGePoint3d& axisPnt,
                                        const OdGeVector3d& axisDir,
                                        double revAngle, double startAngle,
                                        OdDbRevolveOptions& revolveOptions,
                                        bool  bAssociativeEnabled,
                                        OdDbObjectId& newSurfaceId);

  static OdResult createRevolvedSurface(OdDb3dProfile *pRev,
                                        OdDb3dProfile *pAxis,
                                        bool flipAxisDirection,
                                        double revAngle, double startAngle,
                                        OdDbRevolveOptions& revolveOptions,
                                        OdDbRevolvedSurface*& newRevolvedSurface);

  static OdResult createRevolvedSurface(OdDb3dProfile *pRev,
                                        OdDb3dProfile *pAxis,
                                        bool flipAxisDirection,
                                        double revAngle, double startAngle,
                                        OdDbRevolveOptions& revolveOptions,
                                        bool  bAssociativeEnabled,
                                        OdDbObjectId& newRevolvedSurfaceId);

  static OdResult createSweptSurface(OdDb3dProfile *pSweep,
                                      OdDb3dProfile *pPath,
                                      OdDbSweepOptions& sweepOptions,
                                      OdDbSweptSurface*& newSweptSurface);

  static OdResult createSweptSurface(OdDb3dProfile *pSweep,
                                      OdDb3dProfile *pPath,
                                      OdDbSweepOptions& sweepOptions,
                                      bool  bAssociativeEnabled,
                                      OdDbObjectId& newSurfaceId);

  static OdResult createLoftedSurface(const OdArray<OdDbLoftProfile*>& crossSections,
                                      const OdArray<OdDbLoftProfile*>& guides,
                                      OdDbLoftProfile *pPath, OdDbLoftOptions& loftOptions,
                                      OdDbSurface*& newSurface);

  static OdResult createLoftedSurface(const OdArray<OdDbLoftProfile*>& crossSections,
                                      const OdArray<OdDbLoftProfile*>& guides,
                                      OdDbLoftProfile *pPath, OdDbLoftOptions& loftOptions,
                                      bool  bAssociativeEnabled,
                                      OdDbObjectId& newSurfaceId);

  static OdResult createNetworkSurface(const OdArray<OdDb3dProfile*>& uProfiles,
                                        const OdArray<OdDb3dProfile*>& vProfiles,
                                        OdDbSurface*& newSurface);

  static OdResult createNetworkSurface(const OdArray<OdDb3dProfile*>& uProfiles,
                                        const OdArray<OdDb3dProfile*>& vProfiles,
                                        bool  bAssociativeEnabled,
                                        OdDbObjectId& newSurfaceId);

  static OdResult createPatchSurface(const OdDbPathRef& pathRef,
                                      const OdDbObjectIdArray& constraintIds,
                                      int continuity,
                                      double bulge,
                                      OdDbSurface*& newSurface);

  static OdResult createPatchSurface(const OdDbPathRef& pathRef,
                                      const OdDbObjectIdArray& constraintIds,
                                      int continuity,
                                      double bulge,
                                      bool  bAssociativeEnabled,
                                      OdDbObjectId& newSurfaceId);

  static OdResult createBlendSurface(OdDbLoftProfile* startProfile,
                                      OdDbLoftProfile* endProfile,
                                      OdDbBlendOptions* blendOptions,
                                      OdDbSurface*& blendSurface);

  static OdResult createBlendSurface(OdDbLoftProfile* startProfile,
                                      OdDbLoftProfile* endProfile,
                                      OdDbBlendOptions* blendOptions,
                                      bool  bAssociativeEnabled,
                                      OdDbObjectId& blendSurfaceId);

  /** \details
  This method is not implemented.
  */
  static OdResult createFilletSurface(const OdDbObjectId&  surfId1,
                                      const OdGePoint3d&   pickPt1,
                                      const OdDbObjectId&  surfId2,
                                      const OdGePoint3d&   pickPt2,
                                      double               dRadius,
                                      OdDb::FilletTrimMode trimMode,
                                      const OdGeVector3d&  projDir,
                                      OdDbSurface*&        filletSurface);

  /** \details
  This method is not implemented.
  */
  static OdResult createFilletSurface(const OdDbObjectId&  surfId1,
                                      const OdGePoint3d&   pickPt1,
                                      const OdDbObjectId&  surfId2,
                                      const OdGePoint3d&   pickPt2,
                                      double               dRadius,
                                      OdDb::FilletTrimMode trimMode,
                                      const OdGeVector3d&  projDir,
                                      bool                 bAssociativeEnabled,
                                      OdDbObjectId&        filletSurfaceId);

  static OdResult createOffsetSurface(OdDbEntity* pInputSurface,
                                      double offsetDistance,
                                      OdDbEntity*& offsetSurface);

  static OdResult createOffsetSurface(OdDbEntity* pInputSurface,
                                      double offsetDistance,
                                      bool  bAssociativeEnabled,
                                      OdDbObjectId& offsetSurfaceId);

  /**  \details
  This method is not implemented.
  */
  static OdResult createExtendSurface(OdDbObjectId                 sourceSurface,
                                      const OdArray<OdDbSubentId>& edgesId,
                                      double                       dExtDist,
                                      EdgeExtensionType            extOption,
                                      bool                         bAssociativeEnabled,
                                      OdDbObjectId&                newExtendSurfaceId);

  static OdResult trimSurface(const OdDbObjectId &blankSurfaceId,
                              const OdDbObjectIdArray &toolIds,
                              const OdDbObjectIdArray &toolCurveIds,
                              const OdGeVector3dArray& projVectors,
                              const OdGePoint3d& pickPoint,
                              const OdGeVector3d& viewVector,
                              bool bAutoExtend,
                              bool bAssociativeEnabled);

  virtual OdResult convertToRegion ( OdArray<OdDbEntity*>& regions );

  virtual OdResult thicken(double thickness, bool bBothSides, OdDb3dSolid*& pSolid) const;

  virtual OdResult getArea(double& area) const;

  /** Description:
  Returns true if and only if there is no ACIS model associated with this entity. 
  */
  bool isNull() const;

  /** Description:
  Writes the ACIS data of this entity to the specified StreamBuf object, 
  or the specified ACIS solids to the specified file.

  Arguments:
  pStreamBuf (I) Pointer to the StreamBuf object to which the data are to be written. 
  typeVer (I) Type and version of the ACIS data to write.

  Remarks:
  Returns eOk if successful, or an appropriate error code if not. 
  */
  OdResult acisOut(
    OdStreamBuf* pStreamBuf, 
    AfTypeVer typeVer = kAfTypeVerAny);

  /** Description:
  Reads the ACIS data for this entity from the specified StreamBuf object,
  or an array of ACIS solids from the specified file.

  Arguments:
  pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.   
  pTypeVer (I) Receives the type and version of the ACIS data read.

  Remarks:

  If pTypeVer is not null, this function returns the version of the ACIS data
  of this 3D solid entity.
  */
  OdResult acisIn(
    OdStreamBuf* pStreamBuf, 
    AfTypeVer *pTypeVer = 0);

  /** Description:
  Returns the boundary representation of the 3D Solid Entity.
  Arguments:
  brep (O) Receives the boundary representation.
  */
  void brep(
    OdBrBrep& brep);

  virtual OdResult decomposeForSave(
	OdDb::DwgVersion ver,
	OdDbObject*& replaceObj,
	OdDbObjectId& replaceId,
	OdBool& exchangeXData);

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm );

  virtual void subSetDatabaseDefaults(OdDbDatabase *pDb);

  /** Description:
  Directly sets the contained modeler geometry of this entity.
  Arguments:
  pGeometry (I) Pointer to the modeler geometry.
  */
  virtual OdResult setBody( const void* pGeometry );
  virtual void *body( ) const;

  // OdDbObject methods
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  virtual OdDbSubentId internalSubentId(void* ent) const;
  virtual void* internalSubentPtr(const OdDbSubentId& id) const;

  virtual OdResult createInterferenceObjects(OdArray<OdDbEntity*>& interferenceObjects,
                                             OdDbEntity* pEntity, 
                                             unsigned int flags ) const;

  virtual OdResult booleanUnion(const OdDbSurface* pSurface, OdDbSurface*& pNewSurface);
  virtual OdResult booleanSubtract(const OdDbSurface* pSurface, OdDbSurface*& pNewSurface);
  
  virtual OdResult booleanSubtract(const OdDb3dSolid* pSolid, OdDbSurface*& pNewSurface);
  virtual OdResult booleanIntersect(const OdDbSurface* pSurface2, OdArray<OdDbEntity*>& intersectionEntities);
  virtual OdResult booleanIntersect(const OdDb3dSolid* pSolid, OdArray<OdDbEntity*>& intersectionEntities);

  virtual OdResult imprintEntity(const OdDbEntity* pEntity);
  virtual OdResult createSectionObjects(const OdGePlane& sectionPlane,OdArray<OdDbEntity*>& sectionObjects) const;
  
  virtual OdResult sliceByPlane(const OdGePlane& slicePlane,
                                OdDbSurface*& pNegHalfSurface, 
                                OdDbSurface*& pNewSurface);

  virtual OdResult sliceBySurface(const OdDbSurface* pSlicingSurface, 
                                  OdDbSurface*& pNegHalfSurface,
                                  OdDbSurface*& pNewSurface);

  virtual OdResult chamferEdges(const OdArray<OdDbSubentId *> &edgeSubentIds,
                                const OdDbSubentId& baseFaceSubentId, 
                                double baseDist, 
                                double otherDist);

  virtual OdResult filletEdges( const OdArray<OdDbSubentId *> &edgeSubentIds,
                                const OdGeDoubleArray& radius, 
                                const OdGeDoubleArray& startSetback, 
                                const OdGeDoubleArray& endSetback);

  OdResult chamferEdges(const OdArray<OdDbSubentId *> &edgeSubentIds,
                        const OdDbSubentId& baseFaceSubentId,
                        double baseDist, double otherDist, bool bAssociativeEnabled);

  OdResult filletEdges(const OdArray<OdDbSubentId *> &edgeSubentIds,
                       double radius, bool bAssociativeEnabled);

  virtual OdResult setSubentColor(const OdDbSubentId& subentId, const OdCmColor& color);
  virtual OdResult getSubentColor(const OdDbSubentId& subentId, OdCmColor& color) const;
  virtual OdResult setSubentMaterial(const OdDbSubentId& subentId, const OdDbObjectId& matId);
  virtual OdResult getSubentMaterial(const OdDbSubentId& subentId, OdDbObjectId& matId) const;
  virtual OdResult setSubentMaterialMapper(const OdDbSubentId& subentId, const OdGiMapper& mapper);
  virtual OdResult getSubentMaterialMapper(const OdDbSubentId& subentId, OdGiMapper& mapper) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& id) const;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& mat, OdDbEntity*& pCopy) const;
  
  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  WireframeType       getWireframeType() const;

  OdResult setWireframeType(WireframeType type);
  
  OdResult getPerimeter(double&) const;

  OdDbObjectId creationActionBodyId() const;
  OdResult modificationActionBodyIds(OdDbObjectIdArray& modificationActionBodyIds) const;

  OdResult extendEdges(OdDbFullSubentPathArray& edgesId,
                      double                   dExtDist,
                      EdgeExtensionType        extOption,
                      bool                     bAssociativeEnabled);

	OdResult rayTest(const OdGePoint3d& rayBasePoint,
		const OdGeVector3d&     rayDir,
		double                  rayRadius,
		OdArray<OdDbSubentId> & subEntIds,
		OdGeDoubleArray&        parameters) const;

  virtual void dragStatus(const OdDb::DragStat);

  virtual OdResult convertToNurbSurface(OdDbNurbSurfaceArray& nurbSurfaceArray);

  virtual OdResult getPlane(OdGePlane& plane, OdDb::Planarity& planarity) const;

  OdResult projectOnToSurface(const OdDbEntity* pEntityToProject,
    const OdGeVector3d& projectionDirection,
    OdArray<OdDbEntity*>& projectedEntities) const;
};

#include "TD_PackPop.h"
#endif //_DBSURFACE_H_INCLUDED_
