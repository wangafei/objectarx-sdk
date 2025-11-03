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




#ifndef GEOMENT_DBREGION_H
#define GEOMENT_DBREGION_H

#include "TD_PackPush.h"
#include "ModelerDefs.h"
#include "DbEntity.h"
#include "DbSubentId.h"

class OdBrBrep;
class OdModelerGeometry;

/** Description:
    This class represents Region entities in an OdDbDatabase instance.

    Library:
    TD_Db
    
    An OdDbRegion entity is a wrapper for an ACIS model that represents
    the geometry of the OdDbRegion entity.
    
   {group:OdDb_Classes} 

*/
class TOOLKIT_EXPORT OdDbRegion : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRegion);

  OdDbRegion();
  virtual ~OdDbRegion();
  
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
    typeVer (O) Receives the type and version of the ACIS data to return.
    
    Remarks:
    
    If typeVer is null, this function uses the type and version 
    of this Region entity.
  */
  OdResult acisIn(
    OdStreamBuf* pStreamBuf, 
    AfTypeVer *typeVer = 0);

  /** Description:
    Returns the boundary representation of the 3D Solid Entity.
    Arguments:
    brep (O) Receives the boundary representation.
  */
  void brep(
    OdBrBrep& brep);

  /** Description:
    Returns true if and only if there is no ACIS model associated with this entity. 
  */
  OdBool isNull() const;

  /** Description:
    Creates OdDbRegion entities from the closed loops defined by the specified curve segments.
    
    Arguments:
    curveSegments (I) Array of curve segments.
    regions (O) Receives an array of pointers to the *regions*.
    
    Remarks:
    Each curve segment must be one of the following
    
    @untitled table
    OdDb3dPolyline
    OdDbArc
    OdDbCircle
    OdDbEllipse
    OdDbLine
    OdDbPolyline
    OdDbSpline
    
    The newly created *regions* are non- *database* -resident. It is up to the caller to either add them
    to an OdDbDatabase or to delete them.
    
    Returns eOk if successful, or an appropriate error code if not. 
  */
  static OdResult createFromCurves( 
    const OdDbVoidPtrArray& curveSegments,
    OdDbVoidPtrArray& regions );

  static OdResult createFromCurves(
    const OdDbVoidPtrArray& curveSegments,
    OdDbRegion* &region, bool split = true);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).

    Arguments:
    normal (O) Receives the *normal*.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not. 
  */
  virtual OdResult getNormal(
  OdGeVector3d& normal) const;

  virtual OdBool isPlanar() const;
  
  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

	virtual OdResult getPlane(
		OdGePlane& regionPlane) const;
  TD_USING(OdDbEntity::getPlane);

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

  virtual OdResult decomposeForSave(
	OdDb::DwgVersion ver,
	OdDbObject*& replaceObj,
	OdDbObjectId& replaceId,
	OdBool& exchangeXData);

  /** Description:
  Directly sets the contained modeler geometry of this entity.
  Arguments:
  pGeometry (I) Pointer to the modeler geometry.
  */
  virtual OdResult setBody( const void* pGeometry );
  virtual void *body( ) const;

  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;
  
  virtual OdResult subTransformBy( 
    const OdGeMatrix3d& xfm );

  virtual void saveAs(
    OdGiWorldDraw* pWd,
    OdDb::SaveFileType ver );

  virtual OdResult booleanOper(OdDb::BoolOperType operation, OdDbRegion* otherRegion);

  virtual OdResult getArea(double& regionArea) const;

  virtual OdResult getPerimeter(double&) const;
  virtual OdResult getAreaProp( const OdGePoint3d& origin, const OdGeVector3d& xAxis,
    const OdGeVector3d& yAxis, double& perimeter,
    double& area, OdGePoint2d& centroid,
    double momInertia[2], double& prodInertia,
    double prinMoments[2], OdGeVector2d prinAxes[2],
    double radiiGyration[2], OdGePoint2d& extentsLow,
    OdGePoint2d& extentsHigh ) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& id) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;

  virtual OdUInt32 numChanges() const;

  virtual OdResult subGetGeomExtents(OdDbExtents& extents) const;
  virtual OdDbSubentId internalSubentId(void* ent) const;
  virtual void* internalSubentPtr(const OdDbSubentId& id) const;

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual void dragStatus(const OdDb::DragStat);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRegion object pointers.
*/
typedef OdSmartPtr<OdDbRegion> OdDbRegionPtr;

#include "TD_PackPop.h"

#endif

