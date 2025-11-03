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




#ifndef _OD_BLOCK_REFERENCE_
#define _OD_BLOCK_REFERENCE_

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DbDatabase.h"
#include "Ge/GeMatrix3d.h"
#include "DbObjectIterator.h"

class OdGeScale3d;
class OdDbAttribute;
class OdDbSequenceEnd;
class OdDbBlockReferenceImpl;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbAttribute object pointers.
*/
typedef OdSmartPtr<OdDbAttribute> OdDbAttributePtr;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSequenceEnd object pointers.
*/
typedef OdSmartPtr<OdDbSequenceEnd> OdDbSequenceEndPtr;

/** Description:
    This class represents block references (Inserts) in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbBlockReference : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockReference);

  OdDbBlockReference();

  /** Gcad(Add):增加兼容接口	
  */
  OdDbBlockReference(const OdGePoint3d&  position,
						   OdDbObjectId  blockTableRec);

  /** Gcad(Add):增加兼容接口	
  */
  ~OdDbBlockReference();

  virtual OdResult subWblockClone(OdRxObject* pOwnerObject,OdDbObject*& pClonedObject,OdDbIdMapping& idMap,OdBool isPrimary=true) const;

  /** Description:
    Returns the Object ID of the block table record associated with this OdDbBlockReference (DXF 2).
  */
  OdDbObjectId blockTableRecord() const;

  /** Description:
    Sets the Object ID of the block table record associated with this OdDbBlockReference (DXF 2).
    
    Arguments:
    objectId (I) Object ID of the block.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult setBlockTableRecord(
    OdDbObjectId objectId);

  /** Description:
    Returns the insertion point of this block reference (WCS equivalent of DXF 10).
  */
  OdGePoint3d position() const;

  /** Description:
    Sets the insertion point of this block reference. (WCS equivalent of DXF 10.)

    Arguments:
    position (I) Any 3D point.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult setPosition(
    const OdGePoint3d& position);

  /** Description:
    Returns the *scale* factors applied to this block reference (DXF 41, 42, 43).
  */
  OdGeScale3d scaleFactors() const;
  OdGeScale3d nonAnnotationScaleFactors() const;

  /** Description:
    Sets the scale factors to be applied to this block reference (DXF 41, 42, 43).

    Arguments:
    scale (I) Any 3D *scale* factor.
    
    Throws:
    @table
    Exception             Cause
    eInvalidInput         One or more *scale* factors is 0

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult setScaleFactors(
    const OdGeScale3d& scale);

  /** Description:
    Returns the *rotation* *angle* applied to this block reference (DXF 50).

    Remarks:
    Rotation is about the Z axis, relative the X-axis, in the coordinate system parallel to
    this object's OCS, but with its origin at this object's insertion point.

    Note:
    All angles are expressed in radians.
  */
  double rotation() const;

  /** Description:
    Sets the *rotation* *angle* to be applied to this block reference, in radians (DXF 50).

    Remarks:
    Rotation is about the Z axis, relative the X-axis, in the coordinate system parallel to
    this object's OCS, but with its origin at this object's insertion point.

    Arguments:
    angle (I) Rotation *angle*.
    
    Note:
    All angles are expressed in radians.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult setRotation(
    double angle);

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.

	Gcad(Modify):returns:void->OdResult
  */
  virtual OdResult setNormal(
    const OdGeVector3d& normal);

  virtual OdBool isPlanar() const { return ::kTrue; }

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;
  
  /** Description:
    Returns the transformation matrix mapping a point in the MCS
    to the WCS.
    
    Remarks:
    The Microspace Coordinate System (MCS) is the WCS within the block definition.
    Applying this matrix to the center of an arc within the block definition
    returns the center of the arc as it appears in the block reference.
  */
  OdGeMatrix3d blockTransform() const;
  OdGeMatrix3d nonAnnotationBlockTransform() const;

  /** Description:
    Sets the transformation matrix mapping a point in the MCS
    to the WCS.
    
    Arguments:
    xfm (I) Any 3D transformation matrix
    
    Remarks:
    The Microspace Coordinate System (MCS) is the WCS within the block definition.
    Applying this matrix to the center of an arc within the block definition
    returns the center of the arc as it appears in the block reference.
  */
  virtual OdResult setBlockTransform(
    const OdGeMatrix3d& xfm);

  /** Description:
    Appends the specified OdDbAttribute to the attribute list of this block reference.

    Arguments:
    pAttr (I) Pointer to the attribute to be added.

    Remarks:
    Returns the Object ID of the newly appended attribute.

    Note:
    This block reference becomes the owner of the passed in attribute, and the attribute
    is added to the *database* to which this block reference belongs.  
    
    This block reference must be added to a *database* before calling this function.
    
    The object's attribute list should not be added by the client application.

	Gcad(Internal):接口冲突
  */ 
  OdDbObjectId appendAttribute(
	ODSYSDEF,
    OdDbAttribute* pAttr);

  /** Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdResult appendAttribute(
	OdDbAttribute* pAttr);

  OdResult appendAttribute(
	OdDbObjectId& objId, 
	OdDbAttribute* pAttr);
#endif
  /** Description:
    Opens an attribute owned by this block reference.

    Arguments:
    objId (I) Object ID of the attribute to be opened.
    mode (I) Mode in which the attribute is to be opened.
    openErasedOne (I) If and only if true, *erased* objects will be opened.

    Remarks:
    Returns a SmartPointer to the opened object if successful, otherwise a null SmartPointer.
  */
  OdDbAttributePtr openAttribute(
    OdDbObjectId ObjId,
    OdDb::OpenMode mode, 
    bool openErasedOne = false);

  /** Gcad(Add):增加兼容接口
  */
  OdResult openAttribute(
    OdDbAttribute*& pAttr, 
    OdDbObjectId objId,
    OdDb::OpenMode mode,
    bool openErasedOne = false);

  /** Description:
    Opens the OdDbSequenceEnd entity for this block reference.

    Arguments:
    mode (I) Mode in which to open the OdDbSequenceEnd entity.

    Remarks:
    Returns a SmartPointer to the newly opened OdDbSequenceEnd, or a null SmartPointer.

    Note:
    This method is provided solely for applications that store XData on
    OdDbSequenceEnd entities; this is not recommended. 
  */
  OdDbSequenceEndPtr openSequenceEnd(
    OdDb::OpenMode mode);

  /** Gcad(Add):增加兼容接口
  */
  OdResult openSequenceEnd(
	  OdDbSequenceEnd*& pSeqEnd, 
	  OdDb::OpenMode mode);

  /** Description:
    Returns an AttributeIterator for this block reference.

	Gcad(Internal):接口冲突
  */
  OdDbObjectIteratorPtr attributeIterator(ODSYSDEF) const;

  /** Gcad(Add):增加兼容接口
  */
#ifdef ODARXDEF
  OdDbObjectIterator*   attributeIterator() const;
#endif

  // Gcad:增加兼容接口
  virtual OdBool treatAsOdDbBlockRefForExplode() const;

  /** Gcad(TODO):增加兼容接口
  virtual OdResult getSubentPathsAtGsMarker(
								OdDb::SubentType       type,
								GsMarker			   gsMark, 
								const OdGePoint3d&     pickPoint,
								const OdGeMatrix3d&    viewXform, 
								int&                   numPaths,
								OdDbFullSubentPath*&   subentPaths, 
								int                    numInserts = 0,
								OdDbObjectId*          entAndInsertStack = NULL) const;
  */

  /** Gcad(TODO):增加兼容接口
  virtual OdResult getGsMarkersAtSubentPath(
							 const OdDbFullSubentPath& subPath, 
							 OdDbIntArray& gsMarkers) const;
  */

  /** Gcad(TODO):增加兼容接口
  virtual OdDbEntity* subentPtr(
                      const OdDbFullSubentPath&) const;
  */

  /** Gcad(TODO):增加兼容接口
  OdResult geomExtentsBestFit( 
                      OdDbExtents& extents, 
                      const OdGeMatrix3d& parentXform = OdGeMatrix3d::kIdentity) const;
  */

  /** Gcad(TODO):增加兼容接口
  virtual OdResult explodeToOwnerSpace() const;
  */
  virtual OdResult explodeToBlock(
    OdDbBlockTableRecord *BlockRecord, 
    OdDbObjectIdArray *ids = 0);

  OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  virtual OdBool subWorldDraw(
    OdGiWorldDraw* pWd);
  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
  OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  /** Gcad(TODO): subClose
    returns: void->OdResult
  */
  OdResult subClose();

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  
  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm, 
    OdDbEntity*& pCopy) const ODRX_OVERRIDE;

 /* Replace OdRxObjectPtrArray */
 
  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const ODRX_OVERRIDE;

  OdResult subHandOverTo(
    OdDbObject* pNewObject);

  OdResult subGetGeomExtents( // Gcad(Modify)
    OdDbExtents& extents) const;

  OdResult explodeGeometry(OdDbVoidPtrArray& entitySet) const;

  /*
  OdDbBlockReference(const OdGePoint3d& position, OdDbObjectId blockTableRec);
  */
  OdResult geomExtentsBestFit(OdDbExtents& extents,
                              const OdGeMatrix3d& parentXform = OdGeMatrix3d::kIdentity) const;

  virtual OdResult explodeToOwnerSpace() const;

  ODRX_SEALED_VIRTUAL OdResult subGetCompoundObjectTransform(OdGeMatrix3d & xM) const ODRX_OVERRIDE;

  ODRX_SEALED_VIRTUAL OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type,
                                    OdGsMarker gsMark, 
                                    const OdGePoint3d& pickPoint,
                                    const OdGeMatrix3d& viewXform, 
                                    int& numPaths, OdDbFullSubentPath*& subentPaths, 
                                    int numInserts = 0,
	                                  OdDbObjectId* pEntAndInsertStack = 0) const ODRX_OVERRIDE;

  ODRX_SEALED_VIRTUAL OdResult subGetGsMarkersAtSubentPath(const OdDbFullSubentPath& subPath, 
                                    OdGsMarkerArray& gsMarkers) const ODRX_OVERRIDE;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, const OdGePlane& projPlane, 
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType, OdGePoint3dArray &points, 
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;


};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbBlockReference object pointers.
*/
typedef OdSmartPtr<OdDbBlockReference> OdDbBlockReferencePtr;

void decompTransform(
    const OdGeMatrix3d& mTrans,
    OdGePoint3d& pOrigin, 
    OdGeScale3d& sScale,
    double & dRotation, 
    OdGeVector3d& vNormal );

#include "TD_PackPop.h"

#endif

