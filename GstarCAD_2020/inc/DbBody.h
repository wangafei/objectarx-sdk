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




#ifndef GEOMENT_DBBODY_H
#define GEOMENT_DBBODY_H

#include "TD_PackPush.h"
#include "ModelerDefs.h"
#include "DbEntity.h"
#include "DbSubentId.h"

class OdModelerGeometry;
class OdStreamBuf;
class OdBrBrep;
class OdBrEntity;

/** Description:
    This class represents 3D Body entities in an OdDbDatabase instance.

    Library:
    TD_Db
    
    Remarks:
    An OdDbBody entity is a wrapper for an ACIS model cannot be
    represented as an OdDb3dSolid entity or anOdDbRegion entity.
    
   {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbBody : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBody);

  OdDbBody();
  /** 
  Gcad(Add):增加兼容接口	
  */
  virtual ~OdDbBody();
  /** Description:
    Returns true if and only if there is no ACIS model associated with this entity. 
  */
  virtual OdBool isNull() const;

  /** Description:
    Writes the ACIS data of this entity to the specified StreamBuf object, 
    or the specified ACIS solids to the specified file.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object to which the data are to be written. 
    typeVer (I) Type and version of the ACIS data to write.
    filename (I) Filename to write.
    solids (I) Array of SmartPointers to ACIS solids.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not. 
  */
  OdResult acisOut(
    OdStreamBuf* pStreamBuf, 
    AfTypeVer typeVer = kAfTypeVerAny);
  static OdResult acisOut(
    const OdChar * filename, 
    const OdDbEntityPtrArray& solids, 
    AfTypeVer typeVer = kAfVer700|kAfTypeASCII);

  static OdResult acisOut(
    const OdChar * filename, 
    const OdDbVoidPtrArray& solids, 
    AfTypeVer typeVer = kAfVer700|kAfTypeASCII);

  /** Description:
    Reads the ACIS data for this entity from the specified StreamBuf object,
    or an array of ACIS solids from the specified file.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.   
    pTypeVer (I) Receives the type and version of the ACIS data read.
    filename (I) Filename to read.
    solids (O) Receives the array of SmartPointers to the ACIS solids.
   
    Remarks:
    
    If pTypeVer is not null, this function returns the version of the ACIS data
    of this 3D solid entity.
  */
  OdResult acisIn(
    OdStreamBuf* pStreamBuf, 
    AfTypeVer *pTypeVer = 0);
  static OdResult acisIn(
    const OdChar * filename, 
    OdDbEntityPtrArray& solids);
  static OdResult acisIn(
    const OdChar * filename, 
    OdDbVoidPtrArray& solids);

  /** Description:
    Returns the boundary representation of the 3D Solid Entity.
    Arguments:
    brep (O) Receives the boundary representation.
  */
  void brep(
    OdBrBrep& brep);

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

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  virtual void subViewportDraw(
    OdGiViewportDraw* pVd);

  ///////////////////////////////Gcad(Add)///////////////////////
  /*/Gcad(Modify)
  virtual OdDbObjectPtr decomposeForSave(
    OdDb::DwgVersion ver, 
    OdDbObjectId& replaceId, 
    bool& exchangeXData);
  /*/
  virtual OdResult decomposeForSave(
	OdDb::DwgVersion ver,
	OdDbObject*& replaceObj,
	OdDbObjectId& replaceId,
	OdBool& exchangeXData);
  //*/
  
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
    const OdGeMatrix3d& xfn );

  virtual void saveAs(
    OdGiWorldDraw* pWd,
    OdDb::SaveFileType ver );

  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& id) const;

  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
    OdDbObjectId* pEntAndInsertStack = 0) const;

  virtual OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;


  virtual OdUInt32 numChanges() const;

  virtual OdDbSubentId internalSubentId(void* ent) const;
  virtual void* internalSubentPtr(const OdDbSubentId& id) const;
  
  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);
  static OdResult setSubentPath(OdBrEntity &ent, OdDbFullSubentPath& subpath);

  // Only used for solprof command
  static OdResult getProfile(const OdDbVoidPtrArray &allSolids, const OdGePoint3d &eyePos, const OdGePoint3d &target, 
    const OdGePoint3d &viewCenter, const OdGeVector3d &viewDir, OdDbVoidPtrArray &visibleEnts, OdDbVoidPtrArray &hideEnts, 
    bool isProjected = true, bool isTangent = true, bool isShowHideLines = true );

  void invalidateCachedBodySubentIds();
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbBody object pointers.
*/
typedef OdSmartPtr<OdDbBody> OdDbBodyPtr;

#include "TD_PackPop.h"

#endif

