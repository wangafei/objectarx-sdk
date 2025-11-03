/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2017, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2017 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////




#ifndef GEOMENT_DBSOL3D_H
#define GEOMENT_DBSOL3D_H /* {Secret} */

#include "TD_PackPush.h"
#include "ModelerDefs.h"
//#include "Db3dSolid.h"
#include "DbRegion.h"
#include "DbSubentId.h"

class OdDbSubentId;
class OdDbCurve;
class OdBrBrep;
class OdModelerGeometry;
class OdDbLoftOptions;
class OdDbSweepOptions;
class OdDbRevolveOptions;
class OdDbSurface;

#include "DbEntity.h"
#include "OdArray.h"



class OdDb3dSolid;

/** \details
This template class is a specialization of the OdSmartPtr class for OdDb3dSolid object pointers.
*/
typedef OdSmartPtr<OdDb3dSolid> OdDb3dSolidPtr;

/** \details
This template class is a specialization of the OdArray class for OdDb3dSolid object pointer arrays.
*/
typedef OdArray<OdDb3dSolidPtr> OdDb3dSolidPtrArray;


/** \details
    This class represents 3D Solid entities in an OdDbDatabase instance.

    \sa
    TD_Db
    
    \remarks
    An OdDb3dSolid entity is a wrapper for an ACIS model that represents
    the geometry of the OdDb3dSolid entity.
    
    <group OdDb_Classes> 

*/
class TOOLKIT_EXPORT OdDb3dSolid : public OdDbEntity
{
public:

  ODDB_DECLARE_MEMBERS(OdDb3dSolid);
  
  OdDb3dSolid();
  /** 
  Gcad(Add):增加兼容接口	
  */
  virtual ~OdDb3dSolid();

  /** Description:
    Returns true if and only if there is no ACIS model associated with this entity. 

	// Gcad(Modify):增加 virtual
  */
  virtual bool isNull() const;

  /** Description:
    Writes the ACIS data of this entity to the specified StreamBuf object.

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
    Reads the ACIS data for this entity from the specified StreamBuf object.

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

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual void subViewportDraw(
    OdGiViewportDraw* pVd);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  // Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  /** Description:
    Creates a WCS aligned solid box centered about the world origin. 
    
    Arguments:
    xLen (I) Dimension along the WCS X-axis.
    yLen (I) Dimension along the WCS Y-axis. 
    zLen (I) Dimension along the WCS Z-axis. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not. 
    
    Note:
    The following constraints apply:
    
    o xLen >= 1e-6.
    o yLen >= 1e-6.
    o zLen >= 1e-6.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult createBox(
    double xLen, 
    double yLen, 
    double zLen);
    
  /** Description:
    Creates a WCS aligned frustum centered about the world origin. 
    
    Arguments:
    height (I) Dimension along the WCS Z-axis.
    xRadius (I) Base radius along the WCS X-axis. 
    yRadius (I) Base radius along the WCS Y-axis.
    topXRadius (I) Top radius along the WCS X-axis. 

    Remarks:
    The function can generate a frustum that is any one of the following:
    
    o A circular cylinder
    o An elliptical cylinder
    o A circular cone
    o An elliptical cone
    o A truncated circular cone
    o A truncated elliptical cone
    
    Returns eOk if successful, or an appropriate error code if not. 

    Note:    
    The following constraints apply:
    
    o height >= 1e-6.
    o xRadius >= 1e-6.
    o yRadius >= 1e-6.
    o topXRadius >= 1e-6. 

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult createFrustum(
    double height, 
    double xRadius,
    double yRadius, 
    double topXRadius);
    
  /** Description:
    Creates a sphere with centered about the world origin. 
    
    Arguments:
    radius (I) Radius.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not. 

    Note:
    The following constraints apply:
    
    o radius >= 1e-6.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult createSphere(
    double radius);

  /** Description:
    Creates a WCS aligned torus with centered about the world origin
    and the Z-axis as its axis of rotation. 
    
    Arguments:
    majorRadius (I) Radius of the torus
    minorRadius (I) Radius of the tube.

    Remarks:

    Returns eOk if successful, or an appropriate error code if not. 

    Note:
    The following constraints apply:
    
    o minorRadius >= 1e-6.
    o |majorRadius| >= 1e-6
    o if majorRadius < 0, then minorRadius > |majorRadius| + 1e-6

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult createTorus(
    double majorRadius, 
    double minorRadius);
    
  /** Description:
    Creates a WCS aligned wedge centered about the world origin. 
    
    Arguments:
    xLen (I) Dimension along the WCS X-axis.
    yLen (I) Dimension along the WCS Y-axis. 
    zLen (I) Dimension along the WCS Z-axis. 

    Remarks:
    Returns eOk if successful, or an appropriate error code if not. 
    
    The inclined face is defined by the points 
    
              ( xLen/2, -yLen/2, -zLen/2)
              (-xLen/2, -yLen/2,  zLen/2)  
              ( xLen/2,  yLen/2, -zLen/2)
              (-xLen/2, +yLen/2,  zLen/2)  
    
    Note:
    The following constraints apply:
    
    o xLen >= 1e-6.
    o yLen >= 1e-6.
    o zLen >= 1e-6.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult createWedge(
    double xLen, 
    double yLen, 
    double zLen);

  /** Description:
    Creates a solid by extruding the specified region.
   
    Arguments:
    pRegion (I) Pointer to the region to be extruded.
    height (I) Height of the extrusion.
    taperAngle (I) Taper angle.

    Remarks:
    The extrusion direction is along the normal of the region. height may be negative.     


    Note:
    All angles are expressed in radians.
     
    The following constraints apply:
    
    o |height| >= 1e-6.
    o |taperAngle| < OdaPI2 - 1e-6.
     
    As implemented, taperAngle is ignored.
    It will be fully implemented in a future *release*.

  */
  virtual OdResult extrude(
    const OdDbRegion* pRegion, 
    double height, 
    double taperAngle = 0.0);

  /** Description:
    Creates a solid by revolving the specified region.
   
    Arguments:
    pRegion (I) Pointer to the region to be extruded.
    axisPoint (I) Point on the axis of revolution.
    axisDir (I) Vector defining the axis of revolution.
    angleOfRevolution (I) Angle of revolution.
    
    Remarks:
    The axis of revolution is projected onto the plane of the region, parallel to its normal.

    Note:
    All angles are expressed in radians.
    
    The following constraints apply:
    
    o The projected axis of revolution cannot intersect the region. 
    o angleOfRevolution >= 1e-6

    As implemented, angleOfRevolution is ignored.
    It will be fully implemented in a future *release*.
  */
  virtual OdResult revolve(
    const OdDbRegion* pRegion,
    const OdGePoint3d& axisPoint, 
    const OdGeVector3d& axisDir,
    double angleOfRevolution);

  virtual OdResult booleanOper(OdDb::BoolOperType operation, OdDb3dSolid* solid);

  virtual OdResult extrudeAlongPath(const OdDbRegion* region, const OdDbCurve* path, double taperAngle = 0.0);

  virtual OdResult imprintEntity(const OdDbEntity *pEntity);

  virtual OdResult getArea(double& area) const;

  virtual OdResult checkInterference(const OdDb3dSolid* otherSolid,
    OdBool createNewSolid, 
    OdBool& solidsInterfere,
    OdDb3dSolid*& commonVolumeSolid)//Gcad(Modify)
    const;

  virtual OdResult getMassProp(double& volume,
    OdGePoint3d& centroid,
    double momInertia[3],
    double prodInertia[3],
    double prinMoments[3],
    OdGeVector3d prinAxes[3], 
    double radiiGyration[3],
    OdGeExtents3d& extents) const;

  virtual OdResult getSection(const OdGePlane& plane, OdDbRegion*& sectionRegion) const;

  virtual OdResult getSlice(const OdGePlane& plane, bool bGetNegHalfToo, OdDb3dSolid*& pNegHalfSolid);
  virtual OdResult getSlice(OdDbSurface* pSurface,  bool bGetNegHalfToo, OdDb3dSolid*& pNegHalfSolid);

  virtual OdResult cleanBody();
  virtual OdResult offsetBody(double offsetDistance);

  virtual OdResult separateBody(OdArray<OdDb3dSolid *> &newSolids);

  virtual OdResult createExtrudedSolid ( OdDbEntity* pSweepEnt,
    const OdGeVector3d& directionVec,
    OdDbSweepOptions& sweepOptions );

  virtual OdResult createExtrudedSolid ( OdDbEntity* pSweepEnt,
    const OdDbSubentId& faceSubentId,
    const OdGeVector3d& directionVec, 
    OdDbSweepOptions& sweepOptions );

  virtual OdResult createExtrudedSolid ( OdDbEntity* pSweepEnt,
    const OdDbSubentId& faceSubentId,
    double height, 
    OdDbSweepOptions& sweepOptions );

  // Create lofted solid.
  virtual OdResult createLoftedSolid (
    OdDbEntityPtrArray& crossSectionCurves,
    OdDbEntityPtrArray& guideCurves,
    OdDbEntity* pPathCurve, OdDbLoftOptions& loftOptions );

	virtual OdResult createLoftedSolid (
		OdArray<OdDbEntity*>& crossSectionCurves,
		OdArray<OdDbEntity*>& guideCurves,
		OdDbEntity* pPathCurve, OdDbLoftOptions& loftOptions );

  virtual OdResult createPyramid(double height, int sides, 
    double radius, double topRadius = 0.0 );

  virtual OdResult createRevolvedSolid ( OdDbEntity* pRevEnt,
    const OdGePoint3d& axisPnt,
    const OdGeVector3d& axisDir,
    double revAngle, double startAngle,
    OdDbRevolveOptions& revolveOptions );

  virtual OdResult createRevolvedSolid ( OdDbEntity* pRevEnt,
    const OdDbSubentId& faceSubentId,
    const OdGePoint3d& axisPnt,
    const OdGeVector3d& axisDir,
    double revAngle, double startAngle,
    OdDbRevolveOptions& revolveOptions );

  virtual OdResult createSweptSolid ( OdDbEntity *pSweepEnt,
    const OdDbSubentId& faceSubentId,
    OdDbEntity* pPathEnt,
    OdDbSweepOptions& sweepOptions );

  virtual OdResult createSweptSolid ( OdDbEntity* pSweepEnt,
    OdDbEntity* pPathEnt,
    OdDbSweepOptions& sweepOptions );

  virtual void stlOut(const OdChar* filename, bool asciiFormat) const;

  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*& replaceObj,
    OdDbObjectId& replaceId,
    OdBool& exchangeXData);

  virtual OdResult subExplode(
    OdDbVoidPtrArray& output) const;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm );
  
  virtual void saveAs(
    OdGiWorldDraw* pWd,
    OdDb::SaveFileType ver );

  /** Description:
     Directly sets the contained modeler geometry of this entity.
     Arguments:
     pGeometry (I) Pointer to the modeler geometry.
  */
  virtual OdResult setBody( const void* pGeometry );
  virtual void *body( ) const;

  virtual OdResult copyEdge(const OdDbSubentId &subentId, OdDbEntity* &newEntity);
  virtual OdResult copyFace(const OdDbSubentId &subentId, OdDbEntity* &newEntity);

  virtual OdDbSubentId internalSubentId(void* ent) const;
  virtual void* internalSubentPtr(const OdDbSubentId& id) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& id) const;

  virtual OdResult subHighlight(const OdDbFullSubentPath& pPath, const OdBool highlightAll) const;
  virtual OdResult subUnhighlight(const OdDbFullSubentPath& pPath, const OdBool highlightAll) const;

  virtual OdResult extrudeFaces(const OdArray<OdDbSubentId *> &faceSubentIds, 
    double height, double taper);

  virtual OdResult extrudeFacesAlongPath(const OdArray<OdDbSubentId *> &faceSubentIds, 
    const OdDbCurve* path);

  virtual OdResult taperFaces(const OdArray<OdDbSubentId *> &faceSubentIds, 
    const OdGePoint3d &basePoint, 
    const OdGeVector3d &draftVector,
    double draftAngle);

  virtual OdResult transformFaces(const OdArray<OdDbSubentId *> &faceSubentIds,  const OdGeMatrix3d &matrix);
  virtual OdResult removeFaces(const OdArray<OdDbSubentId *> &faceSubentIds);
  virtual OdResult offsetFaces(const OdArray<OdDbSubentId *> &faceSubentIds, double offsetDistance);
  virtual OdResult shellBody(const OdArray<OdDbSubentId *> &faceSubentIds, double offsetDistance);

  virtual OdUInt32 numChanges() const;

  virtual OdResult setSubentColor(const OdDbSubentId &subentId, const OdCmColor &color);
  virtual OdResult getSubentColor(const OdDbSubentId &subentId, OdCmColor &color) const;
  virtual OdResult setSubentMaterial(const OdDbSubentId &subentId, OdDbObjectId matId);
  virtual OdResult getSubentMaterial(const OdDbSubentId &subentId, OdDbObjectId& matId) const;
  virtual OdResult setSubentMaterialMapper(const OdDbSubentId &subentId, const OdGiMapper& mapper);
  virtual OdResult getSubentMaterialMapper(const OdDbSubentId &subentId, OdGiMapper& mapper) const;
  
  virtual OdResult chamferEdges(const OdArray<OdDbSubentId *> &edgeSubentIds,
                                const OdDbSubentId& baseFaceSubentId, 
                                double baseDist, 
                                double otherDist);

  virtual OdResult filletEdges( const OdArray<OdDbSubentId *> &edgeSubentIds,
                                const OdGeDoubleArray& radius, 
                                const OdGeDoubleArray& startSetback, 
                                const OdGeDoubleArray& endSetback);

  virtual OdResult createFrom(const OdDbEntity* pFromEntity);

  /** \details
    Returns whether the solid records its operations history.

    \remarks
    This method is implemented only for Spatial modeler and returns eNotImplementedYet status
    for other modelers. 
  */
  virtual bool recordHistory() const;
  
  /** \details
    Returns whether to draw items from the solid's operation history.
	
    \remarks
    This method is implemented only for Spatial modeler and returns eNotImplementedYet status
    for other modelers. 
  */
    virtual bool showHistory() const;

  /** \details
    Sets a new value for the flag that determines whether the solid records its operation history.
	
    \param bRecord [in] Flag determining whether the solid records operation history.
	
    \returns Returns eOk if successful or an appropriate error code in other case
  */
    virtual OdResult setRecordHistory(bool bRecord);
  
  /** \details
    Sets a new value for the flag that determines whether to draw items from the solid's operation history.
	
    \param bShow [in] Flag determining whether the solid records operation history.
	
    \remarks Returns eOk if successful or an appropriate error code in other case.
  */
      virtual OdResult setShowHistory(bool bShow);

  /** \details
    Converts individual history items from a parameterized type to a simple boundary-representation without its parameter or type information.

    \param paths [in] Array of references to history items.

    \returns Returns eOk if successful or an appropriate error code in other case.
	
    \remarks 
    This method is not implemented. 
  */
  virtual OdResult convertToBrepAtSubentPaths(const OdDbFullSubentPathArray& /*paths*/) {return Oda::eNotImplemented;}

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  OdResult createSculptedSolid(const OdArray<OdDbEntity*>& limitingBodies,
                               const OdGeIntArray& limitingFlags);

  OdResult projectOnToSolid(const OdDbEntity*   pEntityToProject,
                            const OdGeVector3d& projectionDirection,
                            OdArray<OdDbEntity*>& projectedEntities) const;

  /** \details
    This method is not implemented. 
  */
  virtual OdResult subClose();

  virtual void dragStatus(const OdDb::DragStat);

};
#include "DbSurface.h"

#include "TD_PackPop.h"

#endif

