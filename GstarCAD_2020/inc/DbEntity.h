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

#ifndef _ODDBENTITY_INCLUDED_
#define _ODDBENTITY_INCLUDED_ /** {Secret} */

#include "TD_PackPush.h"

#include "DbObject.h"
#include "Ge/GePoint3d.h"
#include "Ge/GeLine3d.h"
#include "Ge/GePlane.h"
#include "CmColor.h"
#include "IntArray.h"
#include "DbDatabase.h"
#include "DbSubentId.h"
#include "GsMarkerArray.h"
#include "DbPtrArray.h"

#include "Gi/Gi.h"
#include "Gi/GiCommonDraw.h"
#include "Gi/GiGeometry.h"
#include "Gi/GiWorldDraw.h"
#include "Gi/GiViewportDraw.h"
#include "Gi/GiViewport.h"
#include "Gi/GiWorldGeometry.h"
#include "Gi/GiViewportGeometry.h"
#include "Gi/GiTextStyle.h"

class OdGePlane;
class OdGeMatrix3d;
class OdDbFullSubentPath;
class OdGePoint3d;
class OdGeVector3d;
class OdDbBlockTableRecord;
class OdDbBlockTableRecord; // Gcad(Add): (Used in OdDbExtents)

class OdDbGripData;
template <class T> class OdSharedPtr;
typedef OdSharedPtr<OdDbGripData> OdDbGripDataPtr;
typedef OdArray<OdDbGripDataPtr> OdDbGripDataPtrArray;

/**
    Description:
    This template class is a specialization of the OdArray class template for OdDbGripData smart pointers.
*/
typedef OdArray<OdDbGripDataPtr> OdDbGripDataPtrArray;


/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbEntity pointers.
*/
typedef OdSmartPtr<OdDbEntity> OdDbEntityPtr;

/** Description:
  This template class is a specialization of the OdArray class for OdDbEntity object SmartPointers.
*/
typedef OdArray<OdDbEntityPtr> OdDbEntityPtrArray;

/** Description:

    {group:TD_Namespaces}
*/

// Gcad(Add) {{
class TOOLKIT_EXPORT OdDbExtents : public OdGeExtents3d
{
public:
  /**
   Arguments:
   min (I) Minimum *point*.
   max (I) Maximum *point*.
  */
  OdDbExtents();
  OdDbExtents(const OdDbExtents& src);
  OdDbExtents(const OdGeExtents3d& src);
  OdDbExtents(const OdGePoint3d& min, const OdGePoint3d& max);

public:
  /** Description:
    Compute the minimum box that encloses all of the entities in the block pointed to by pBTR
    and the box already defined by this object.
  */
  OdResult addBlockExt(OdDbBlockTableRecord* pBTR);
};

inline OdDbExtents::OdDbExtents() 
  : OdGeExtents3d()
{
}

inline OdDbExtents::OdDbExtents(const OdDbExtents& src)
  : OdGeExtents3d(src.minPoint(), src.maxPoint())
{

}

inline OdDbExtents::OdDbExtents(const OdGeExtents3d& src) 
  : OdGeExtents3d(src)
{
}

inline OdDbExtents::OdDbExtents(const OdGePoint3d& min, const OdGePoint3d& max)
  : OdGeExtents3d(min, max)
{
}
// Gcad(Add) }}

/** Description:
    This class is the base class for all graphical objects contained in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbEntity : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbEntity);

  OdDbEntity();
  //Gcad(Add)
  virtual ~OdDbEntity();
  
  /** Description:
    Returns the Object ID of the OdDbBlockTableRecord that owns this entity.
  */
  OdDbObjectId blockId() const;

  /** Description:
    Returns the *color* information of this entity as an OdCmColor instance.
  */
  OdCmColor color() const;

  /** Description:
    Sets the *color* information of this entity from an OdCmColor instance.

    Arguments:
    color (I) OdCmColor object.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                  this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setColor(
    const OdCmColor &color,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the *color* index of this entity (DXF 62).

    Remarks:
    Returns a value in the range [0 .. 256].

    o 0 indicates a *color* of BYBLOCK.
    o 256 indicates a *color* of BYLAYER.
  */
  OdUInt16 colorIndex() const;

  /** Description:
    Returns the OdCmEntityColor settings of this object.
  */
  virtual OdCmEntityColor entityColor() const;

  /** Description:
    Sets the *color* index of this entity (DXF 62).

    Arguments:
    colorIndex (I) Color index.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                  this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    colorIndex will be in the range [0 .. 256].
    o 0 indicates a *color* of BYBLOCK.
    o 256 indicates a *color* of BYLAYER.
  */
  virtual OdResult setColorIndex(
    OdUInt16 colorIndex,
    OdBool doSubents = kTrue);

  /** Description:
      Returns the Object ID of the OdDbColor object referenced by this entity.
  */
  OdDbObjectId colorId() const;

  /** Description:
    Assigns the specified OdDbColor object to this entity.

    Arguments:
    colorId (I) Object ID of the OdDbColor object.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                  this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setColorId(
    OdDbObjectId colorId,
    bool doSubents = true);

  /** Description:
    Returns the *transparency* setting of this entity.
  */
  OdCmTransparency transparency() const;

  /** Description:
    Sets the *transparency* setting of this entity, and returns eOk if successful.

    Arguments:
    transparency (I) OdCmTransparency object be assigned.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                  this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    If you override this function, you must call OdDbEntity::setTransparency(), passing to it the calling arguments.
  */
  virtual OdResult setTransparency(
    const OdCmTransparency& transparency,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the name of the *plotStyleName* string associated with this entity (DXF 390).
	Gcad(internal)
  */
  OdString plotStyleName(ODSYSDEF) const;

  //Gcad(Add)
#ifdef ODARXDEF
  OdChar* plotStyleName() const;
#endif
  /** Description:
    Returns the PlotStyleName of this entity. 

    Arguments:
    plotStyleNameId (O) Receives the Object ID of the Plot Style Name of this entity.
  */
  OdDb::PlotStyleNameType getPlotStyleNameId(OdDbObjectId& plotStyleNameId) const;

  /** Description:
    Sets the plot style of this entity.

    Arguments:
    plotStyleName (I) Name of the plot style.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                  this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setPlotStyleName( // Gcad(Modify)
    const OdChar* plotStyleName,
    OdBool doSubents = kTrue);

  /**
    Arguments:
    plotStyleNameType (I) Plot Style Name Type.
    plotStyleNameId (I) Object ID of the plot style name.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    plotStyleNameId is used only when plotStyleNameType == kPlotStyleNameById.

    plotStyleNameType must be one of the following:

    @table
    Name                                 Value
    OdDb::kPlotStyleNameByLayer          0
    OdDb::kPlotStyleNameByBlock          1
    OdDb::kPlotStyleNameIsDictDefault    2
    OdDb::kPlotStyleNameById             3
  */
  virtual OdResult setPlotStyleName(
    OdDb::PlotStyleNameType plotStyleNameType,
    OdDbObjectId plotStyleNameId = OdDbObjectId::kNull,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the name of the *layer* referenced by this entity (DXF 8).

	Gcad(internal)
  */
  OdString layer(ODSYSDEF) const;
  //Gcad(Add)
#ifdef ODARXDEF
  OdChar* layer() const;
#endif
  /** Description:
    Returns the Object ID of the OdDbLayerTableRecord referenced by this entity.
  */
  OdDbObjectId layerId() const;

  /** Description:
    Sets the *layer* to be referenced by this entity (DXF 8).

    Arguments:
    layerName (I) Name of the *layer*.
    layerId (I) Object ID of the LayerTableRecord.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setLayer( // Gcad(Modify)
    const OdChar* layerName,
    OdBool doSubents = kTrue,
    bool allowHiddenLayer = false);

  virtual OdResult setLayer(
    OdDbObjectId layerId,
    OdBool doSubents = kTrue,
     bool allowHiddenLayer = false);


  /** Description:
    Returns the name of the *linetype* referenced by this entity (DXF 6).

	Gcad(internal)
  */
  OdString linetype(ODSYSDEF) const;
  //Gcad(Add)
#ifdef ODARXDEF
  OdChar* linetype() const;
#endif
  /** Description:
    Returns the Object ID of the *linetype* referenced by this entity (DXF 6).
  */
  OdDbObjectId linetypeId() const;

  /** Description:
    Sets the *linetype* to be referenced by this entity (DXF 6).

    Arguments:
    linetypeName (I) Name of the *linetype*.
    linetypeID (I) Object ID of the *linetype*.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setLinetype( // Gcad(Modify)
    const OdChar* linetypeName, 
    OdBool doSubents = kTrue);
  virtual OdResult setLinetype(
    OdDbObjectId linetypeID,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the name of the *material* referenced by this entity (DXF 347).
  */
  OdString material(ODSYSDEF) const;
 //Gcad(Add)
#ifdef ODARXDEF
  OdChar* material() const;
#endif

  /** Description:
    Returns the Object ID of the *material* referenced by this entity (DXF 347).
  */
  OdDbObjectId materialId() const;

  /** Description:
    Sets the *material* to be referenced by this entity (DXF 347).

    Arguments:
    materialName (I) Name of the *material*.
    materialID (I) Object ID of the *material*.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setMaterial( // Gcad(Modify)
    const OdChar* materialName, 
    OdBool doSubents = kTrue);
  virtual OdResult setMaterial(
    OdDbObjectId materialID,
    OdBool doSubents = kTrue);


  enum VisualStyleType
  {
    kFullVisualStyle,
    kFaceVisualStyle,
    kEdgeVisualStyle
  };

  /** Description:
    Returns the Object ID of the *visual style* used by this entity.
  */
  OdDbObjectId visualStyleId(
    VisualStyleType vstype = kFullVisualStyle) const;

  /** Description:
    Sets the *visual style* to be used by this entity.

    Arguments:
    visualStyleId (I) Object ID of the *visual style*.
    vstype (I) Type of the *visual style*.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setVisualStyle(
    OdDbObjectId visualStyleId,
    VisualStyleType vstype = kFullVisualStyle,
    OdBool doSubents = kTrue);

  /** Description:
    Returns OdGiMapper used to map a material to the entity.
    Returns null if the default mapper is used.
  */
  /*/Gcad(Modify)
  virtual const OdGiMapper* materialMapper() const;
  /*/
  virtual OdResult getMaterialMapper(OdGiMapper& mapper) const;
  //*/

  /** Description:
    Sets the mapper used to map a material to the entity.

    Arguments:
    mapper (I) The mapper of a material.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Use null to apply the default mapper.
  */
  //Gcad(Modify)
  virtual OdResult setMaterialMapper(
    const OdGiMapper& mapper, 
    OdBool doSubents = kTrue);

  /** Description:
    Returns the *linetype* scale of this entity (DXF 48).
  */
  double linetypeScale() const;

  /** Description:
    Sets the Linetype scale of this entity (DXF 48).

    Arguments:
    linetypeScale (I) Linetype scale factor.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setLinetypeScale(
    double linetypeScale,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the *visibility* status of this entity (DXF 60).

    Remarks:
    visibility() returns one of the following:

    @table
    Name                 Value
    OdDb::kInvisible     1
    OdDb::kVisible       0
  */
  OdDb::Visibility visibility() const;

  /** Description:
    Sets the *visibility* status of this entity (DXF 60).

    Arguments:
    visibility (I) Visibility status.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    visibility must be one of the following:

    @table
    Name                 Value
    OdDb::kInvisible     1
    OdDb::kVisible       0
  */
  virtual OdResult setVisibility(
    OdDb::Visibility visibility,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the lineweight property of this entity (DXF 370).
  */
  OdDb::LineWeight lineWeight() const;

  /** Description:
    Sets the lineweight property of this entity (DXF 370).

    Arguments:
    lineWeight (I) Lineweight.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  virtual OdResult setLineWeight(
    OdDb::LineWeight lineWeight,
    OdBool doSubents = kTrue);

  /** Description:
    Returns the CastShadows flag for this entity..
  */
  virtual bool                castShadows() const;

  /** Description:
    Controls the CastShadows flag for this entity.
    Arguments:
    castShadows (I) CastShadows flag.
  */
  virtual void                setCastShadows(bool castShadows);

  /** Description:
    Returns the ReceiveShadows flag for this entity..
  */
  virtual bool                receiveShadows() const;

  /** Description:
    Controls the Receivehadows flag for this entity.
    Arguments:
    receiveShadows (I) ReceiveShadows flag.
  */
  virtual void                setReceiveShadows(bool receiveShadows);

  /** Description:
    Returns the CollisionType for this entity.
    Remarks:
    Subclasses may override this method to customize how the class interacts
    in collision-aware features.
  */
  virtual OdDb::CollisionType collisionType() const;

 /** Description:
    Copies the properties from the specified entity to this entity.
    Arguments:
    pSource (I) Pointer to the source entity.
    doSubents (I) If and only if true, applies the change to all sub-entities owned by
                this entity.

	Gcad(modify)
  */
  OdResult setPropertiesFrom(
    const OdDbEntity* pSource, 
    OdBool doSubents = kTrue);

  /** Description:
    Returns true if and only if this entity is planar.
  */
  virtual OdBool isPlanar() const;

  /** Description:
    Returns the *plane* that contains this entity.

    Arguments:
    plane (O)  Receives the *plane* that contains this entity.
    planarity (O) Receives the *planarity* of this entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    planarity and plane return values as follows::

    @table
    planarity     Value    Description    plane
    kNonPlanar    0        Non-planar     Not set
    kPlanar       1        Planar         Entity *plane*
    kLinear       2        Linear         Arrbitrary *plane* containing this entity
  */
  virtual OdResult getPlane(
    OdGePlane& plane,
    OdDb::Planarity& planarity) const;

  //Gcad(Add);
  virtual void    getEcs(OdGeMatrix3d& retVal) const;
  /** Description:
    Returns the WCS geometric *extents* of this entity.

    Arguments:
    extents (O) Receives the *extents*.

    Remarks:
    Returns eOk if successful, or eInvalidExtents if not.

    The *extents* are the WCS corner points of a box, aligned with the
    WCS axes, that encloses the 3D *extents* of this entity.
  */

  OdResult subHandOverTo(
    OdDbObject* pNewObject);

  /**
    Description:
    Applies the specified 3D transformation matrix to this entity.

    Arguments:
    xfm (I) 3D transformation matrix.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  ODRX_SEALED_VIRTUAL OdResult transformBy(
    const OdGeMatrix3d& xfm) ODRX_SEALED;

  /** Description:
    Creates a copy of this entity, and applies the supplied transformation
    to the newly created copy.

    Arguments:
    xfm (I) 3D transformation matrix.
    pCopy (O) Receives a SmartPointer to the newly created copy.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
  */
  ODRX_SEALED_VIRTUAL OdResult getTransformedCopy(
    const OdGeMatrix3d& xfm,
    OdDbEntity*& pCopy) const ODRX_SEALED;

  /** Description:
    Explodes this entity into a set of simpler entities.

    Arguments:
    entitySet (I/O) Receives an array of pointers to the new entities.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    Note:
    Entities resulting from the explosion are appended to the specified array.

    The newly created entities are not *database* resident.

    The default implementation of this function returns eNotApplicable. This function can be
    overridden in custom classes.
  */
  ODRX_SEALED_VIRTUAL OdResult explode(
    OdDbVoidPtrArray& entitySet) const ODRX_SEALED; /* Replace OdRxObjectPtrArray */

  /** Description:
    Explodes this entity into a set of simpler entities, and adds them to the specified block table record.

    Arguments:
    pBlockRecord (I) Pointer to the Block Table Record.
    ids (I/O) Receives an array of Object IDs of the new entities.

    Note:
    Entities resulting from the explosion are appended to the specified array.

    The newly created entities are *database* resident or not depending on the block table record
    they are appended to. If block table record is *database* resident the entities are *database*
    resident as well. If block table record is not *database* resident newly created entities are not
    *database* resident.

    The default implementation of this function returns eNotApplicable. This function can be
    overridden in custom classes.
  */
  virtual OdResult explodeToBlock(
    OdDbBlockTableRecord *pBlockRecord,
    OdDbObjectIdArray *ids = 0);

  /** Description:
    Explodes this entity into a set of simpler entities.

    Arguments:
    entitySet (I/O) Receives an array of pointers to the new entities.

    Remarks:
    The newly created entities will be not *database* resident.

    Returns eOk if successful, or an appropriate error code if not.

    Note:
    Entities resulting from the explosion are appended to the specified array.


    The default implementation of this function calls subWorldDraw() and makes
    entities from *geometry* generated by subWorldDraw(). This function can be
    overridden in custom classes.
  */
  virtual OdResult explodeGeometry(
    OdDbVoidPtrArray& entitySet) const;

  /** Description:
    Explodes this entity into a set of simpler entities, and adds them to the specified block.

    Arguments:
    pBlockRecord (I) Pointer to the Block Table Record.
    ids (I/O) Receives array of Object IDs of the new entities.

    Remarks:
    The newly created entities are *database* resident or not depending on the block table record
    they are appended to. If block table record is *database* resident the entities are *database*
    resident too. If block table record is not *database* resident newly created entities are not
    *database* resident.

    Note:
    Entities resulting from the explosion are appended to the specified array.


    The default implementation of this function calls subWorldDraw() and makes
    entities from *geometry* generated by subWorldDraw(). This function can be
    overridden in custom classes.
  */
  virtual OdResult explodeGeometryToBlock(
    OdDbBlockTableRecord *pBlockRecord,
    OdDbObjectIdArray *ids = 0);

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);

  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  /** Description:
    Applies the default properties of the specified *database* to this entity.

    Arguments:
    pDb (I) Pointer to the *database* whose default values are to be used.
    doSubents (I) Set to true if subentities should be processed

    Remarks:
    If pDb is null, the *database* containing this entity is used.

    The following properties are set

    o *color*
    o *layer*
    o *linetype*
    o *linetype* scale
    o *lineweight*
    o *plotstyle*
    o *visibility*
  */
  void setDatabaseDefaults(
    OdDbDatabase* pDb = 0,
    bool doSubents = false);
  virtual OdResult audit(OdDbAuditInfo* pAuditInfo);

  virtual void setGsNode(OdGsNode* pNode);
  virtual OdGsNode* gsNode() const;

  /** Description:
    Called by setDatabaseDefaults() after the values are set.

    Arguments:
    pDb (I) Pointer to the *database* whose default values are to be used.
    doSubents (I) Set to true if subentities should be processed

    Remarks:
    If pDb is null, the *database* containing this entity is used.

    This function allows custom classes to inspect and modify the values set by setDatabaseDefaults.

    The default implementation of this function returns eNotApplicable. This function can be
    overridden in custom classes.

    Note:
    This function is not intended to be called by the user.
  */
  virtual void subSetDatabaseDefaults(OdDbDatabase* pDb);

  // Gcad(Modify): void => OdResult
  virtual OdResult applyPartialUndo(
    OdDbDwgFiler* pUndoFiler, 
    OdRxClass* pClassObj);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  void appendToOwner(
    OdDbIdPair& idPair,
    OdDbObject* pOwnerObject,
    OdDbIdMapping& ownerIdMap);

  virtual OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOut(
    OdDbDxfFiler* pFiler,
    OdBool allXdFlag = kTrue,
    unsigned char* regAppTable = NULL) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdGiDrawable* drawable();

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

    virtual void subList() const;
    virtual OdResult subGetClassID(CLSID* pClsid) const;

  /** Description:
    This function is called as the first operation of the swapIdWith() function.

    Arguments:
    otherId (I) Object ID of object with which to swap.
    swapXdata (I) XData will be swaped if and only if swapXData is true.
    swapExtDict (I) Extension dictionaries will be swapped if and only if swapExtDict is true.

    Remarks:
    This function allows derived classes
    to implement custom behavior during the swapIdWith operation.

    The default implementation of this function does nothing. This function can be
    overridden in custom classes.



    See Also:
    OdDbObject::swapIdWith
  */
  //Gcad(modify)
  OdResult subSwapIdWith(
    OdDbObjectId otherId, //const OdDbObjectId& otherId, 
    bool swapXdata = false,
    bool swapExtDict = false);

  // virtual OdResult subErase(
    // OdBool erasing);

  /** Description:
    Sets the bit flag indicating the entity's geometry is changed.

    Arguments:
    graphicsModified (I) New value.

    Remarks:
    If true, assures that modifiedGraphics() will be called as the entity is being closed, even
    if the object was not opened for write.
  */
  void recordGraphicsModified(OdBool graphicsModified = kTrue);

  virtual OdResult copyFrom(const OdRxObject* pSource);

/* No implementation
  Cause this entity, and any other entity who's draw bit is set, to be be drawn.
    void draw();
  */
  OdResult           draw();
  /** Description:
    This method is triggered by the standard LIST command and is to be display
    the dxf format contents of the entity to the display.
  */
  ODRX_SEALED_VIRTUAL void list() const ODRX_SEALED;

  virtual OdResult getGeomExtents(OdDbExtents& extents) const ODRX_SEALED;

  virtual bool bounds(OdDbExtents& bounds) const;

  ODRX_SEALED_VIRTUAL OdResult highlight(const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false) const ODRX_SEALED;

  ODRX_SEALED_VIRTUAL OdResult getGripEntityUCS(const void* pGripAppData,
    OdGeVector3d& normalVec,
    OdGePoint3d& origin,
    OdGeVector3d& xAxis) const ODRX_SEALED;

  //Gcad modified:
  ODRX_SEALED_VIRTUAL OdResult unhighlight (const OdDbFullSubentPath& pSubId = kNullSubent,const OdBool highlightAll = false) const ODRX_SEALED;
  /** Description:
    Returns all appropriate object snap points of this entity.

    Arguments:
    osnapMode (I) The object snap mode being queried.
    gsSelectionMark (I) The GS marker of the subentity being queried.
    pickPoint (I) The WCS point being queried.
    lastPoint (I) The WCS point picked before pickPoint.
    xWorldToEye (I) The WCS->DCS transformation matrix.
    snapPoints (I/O) Receives an array of UCS object snap points.

    Remarks:
    Object snap points are appended to the specified array.

    osnapMode must be one of the following:

    @table
    Name                      Value   Description
    OdDb::kOsModeEnd          1       Endpoint
    OdDb::kOsModeMid          2       Midpoint
    OdDb::kOsModeCen          3       Center
    OdDb::kOsModeNode         4       Node
    OdDb::kOsModeQuad         5       Quadrant
    OdDb::kOsModeIntersec     6       Intersection
    OdDb::kOsModeIns          7       Insertion point
    OdDb::kOsModePerp         8       Perpendicular
    OdDb::kOsModeTan          9       Tangent
    OdDb::kOsModeNear         10      Nearest
    OdDb::kOsModeApint        11      Apparent intersection
    OdDb::kOsModePar          12      Parallel
    OdDb::kOsModeStart        13      Unknown

  */
  ODRX_SEALED_VIRTUAL OdResult getOsnapPoints(
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& viewXform,
    OdGePoint3dArray& snapPoints,
    OdDbIntArray &   geomIds ) const ODRX_SEALED;

  ODRX_SEALED_VIRTUAL OdResult getOsnapPoints(
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
	const OdGeMatrix3d& viewXform,
	OdGePoint3dArray&   snapPoints,
	OdDbIntArray &   geomIds,
	const OdGeMatrix3d& insertionMat) const;
  
  ODRX_SEALED_VIRTUAL bool isContentSnappable() const ODRX_SEALED;

  /** Description:
    Returns all grip points of this entity.

    Arguments:
    gripPoints (I/O) Receives an array of WCS grip points.

    Remarks:
    Grip points are appended to the specified array.
  */
  ODRX_SEALED_VIRTUAL OdResult getGripPoints( OdGePoint3dArray& gripPoints,
                                              OdDbIntArray &     osnapModes,//not currently in use
                                              OdDbIntArray &  geomIds) const ODRX_SEALED;//not currently in use

  /**
    Description:
    Moves the specified grip points of this entity.

    Arguments:
    indices (I) Array of indicies.
    offset(I) The direction and magnitude of the grip points offset (WCS).

    Remarks:
    Each element in gripPoints has a corresponding entry in indices, which specifies the index of
    the grip point as returned by getGripPoints.
  */
  ODRX_SEALED_VIRTUAL OdResult moveGripPointsAt(
    const OdIntArray& indices,
    const OdGeVector3d& offset ) ODRX_SEALED;

  /** Description:
    Returns OdDbGripData objects for grip points of this entity.

    Arguments:
    grips (I/O) Receives an array of OdDbGripData objects.

    Remarks:
    Grip points are appended to the specified array.
  */
  ODRX_SEALED_VIRTUAL OdResult getGripPoints(
    OdDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const OdGeVector3d& curViewDir,
    const int bitFlags ) const ODRX_SEALED;

  /**
    Description:
    Moves the specified grip points of this entity.

    Arguments:
    gripAppData (I) Array of appData pointers from the OdDbGripData objects (one for each grip point to be moved).
    offset(I) The direction and magnitude of the grip points offset (WCS).
  */
  ODRX_SEALED_VIRTUAL OdResult moveGripPointsAt(
    const OdDbVoidPtrArray& grips,
    const OdGeVector3d& offset,
    const int bitFlags ) ODRX_SEALED;

  /** Description:
    Returns all stretch points of this entity.

    Arguments:
    stretchPoints (I/O) Receives an array of WCS stretch points.

    Remarks:
    Stretch points are appended to the specified array.
  */
  ODRX_SEALED_VIRTUAL OdResult getStretchPoints( OdGePoint3dArray& stretchPoints ) const ODRX_SEALED;

  /**
    Description:
    Moves the specified stretch points of this entity.

    Arguments:
    stretchPoints (I) Array of moved grip points.
    indices (I) Array of indicies.
    offset(I) The direction and magnitude of the stretch points offset (WCS).

    Remarks:
    Each element in stretchPoints has a corresponding entry in indices, which specifies the index of
    the stretch point as returned by getStretchPoints.
  */
  ODRX_SEALED_VIRTUAL OdResult moveStretchPointsAt(
    const OdIntArray& indices,
    const OdGeVector3d& offset ) ODRX_SEALED;

  /**
    Description:
    Notification function called when this entity is involved in a drag operation.

    Arguments:
    status (I) Status of the drag operation.
  */
  virtual void dragStatus( const OdDb::DragStat status );

  /**
    Description:
    Notification function called when this entity is involved in a grip operation.

    Arguments:
    status (I) Status of the grip operation.
  */
  ODRX_SEALED_VIRTUAL void gripStatus( const OdDb::GripStat status ) ODRX_SEALED;

  /**
    Description:
    Returns the cloneMeForDragging flag for this entity.
  */
  ODRX_SEALED_VIRTUAL OdBool cloneMeForDragging() ODRX_SEALED;

  /**
    Description:
    Returns the hideMeForDragging flag for this entity.
  */
  ODRX_SEALED_VIRTUAL bool hideMeForDragging() const ODRX_SEALED;

  /**
    Description:
    Creates a geometric representation of this entity for saving proxy graphics or converting to previous formats.

    Arguments:
    pWd (I) Pointer to the OdGiWorldDraw object.
    ver (I) Specifies the reason why the method is called.

    Remarks:
    The default implementation of this function calls worldDraw().
    This function can be overridden in custom classes.
  */
  virtual void saveAs(
    OdGiWorldDraw* pWd,
    OdDb::SaveType ver );



  /**
    Description:
    Is applicable for compound objects only which return the kDrawableIsCompoundObject flag
    from subSetAttributes(). The matrix returned is the one that
    is passed to pushModelTransform before rendering nested objects.
    Default implementation returns OdDb::eNotApplicable and the identity matrix in xM.
  */
  ODRX_SEALED_VIRTUAL OdResult getCompoundObjectTransform(OdGeMatrix3d & xM) const ODRX_SEALED;


  /**
    Description:
    Intersects this entity with other entity if possible.

    Arguments:
    pEnt   (I) Pointer to other entity
    inType (I) Determines type of intersection to be calculated
  */
  ODRX_SEALED_VIRTUAL OdResult intersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
                             OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
                             OdGsMarker otherGsMarker = 0) const ODRX_SEALED;

  ODRX_SEALED_VIRTUAL OdResult intersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
                             const OdGePlane& projPlane, OdGePoint3dArray& points,
                             OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const ODRX_SEALED;


  /**
    Description:
    Uses the bounding box of this object to determine an intersection array of points.
  */
  OdResult boundingBoxIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
                                OdGePoint3dArray& points, OdGsMarker thisGsMarker, OdGsMarker otherGsMarker) const;

  OdResult boundingBoxIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
                                const OdGePlane& projPlane, OdGePoint3dArray& points,
                                OdGsMarker thisGsMarker, OdGsMarker otherGsMarker) const;

  /** Description:
	Returns all subentity paths by graphic system marker for complex entities, that has
	the ability to associate an integer identifier (GS marker) with each graphic primitive or 
	with groups of primitives during draw themself.

	Arguments:
	type (I) The subentity type being queried.
	gsMarker (I) The GS marker of the subentity being queried.
	pickPoint (I) The WCS point being queried.
	xrm (I) The WCS->DCS transformation matrix.
	subentPaths (0) The array of OdDbFullSubentPath objects.
	pEntAndInsertStack (I) The array of objectIds of the objects that are the nested containers of the subentity.

	Remarks:
	Subentity type must be one of the following:

	@table
    Name                      Value   Description
    OdDb::kFaceSubentType     1		  Face subentity
    OdDb::kEdgeSubentType     2		  Edge subentity
    OdDb::kVertexSubentType   3		  Vertex subentity
    OdDb::kMlineSubentCache   4		  Not used yet
	OdDb::kClassSubentType    5		  MultiType subentity
  */

  ODRX_SEALED_VIRTUAL OdResult getSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
										const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
										int& numPaths, OdDbFullSubentPath*& subentPaths, 
                    int numInserts = 0,
										OdDbObjectId* pEntAndInsertStack = 0) const ODRX_SEALED;

  /** Description:
	Returns all graphic system marker by subentity paths for complex entities, that has
	the ability to associate an integer identifier (GS marker) with each graphic primitive or 
	with groups of primitives during draw themself.

	Arguments:
	subPath (I) The OdDbFullSubentPath to the subentity.
	gsMarkers (I/O) The array of integer identifiers (GS markers).
  */

  ODRX_SEALED_VIRTUAL OdResult getGsMarkersAtSubentPath( const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const ODRX_SEALED;

  /** Description:
	Gets the grip points and supporting information about the grips for a subentity.

	Arguments:
	path (I) The OdDbFullSubentPath to the subentity.
	grips (I/O) Receives an array of pointers of OdDbGripData objects, one object for each grip point in the subentity.
	curViewUnitSize (I) The size (in pixels) of one drawing unit in the current viewport.
	gripSize (I) The current grip size (in pixels).
	curViewDir (I) The view direction in the current viewport.
	bitflags (I) The bitmap of one or more flags specified by the GetGripPointsFlags enumeration.
  */

  ODRX_SEALED_VIRTUAL OdResult getGripPointsAtSubentPath( const OdDbFullSubentPath& path, OdDbGripDataPtrArray& grips,
											  const double curViewUnitSize, const int gripSize,
                        const OdGeVector3d& curViewDir, const OdUInt32 bitflags) const ODRX_SEALED;

  /** Description:
	Applies a vector offset to one or more grip points exposed by subentities on the object.

	Arguments:
	paths (I) The array of OdDbFullSubentPath objects.
	gripAppData (I) The array of pointers of OdDbGripData objects.
	offset (I) The vector (in WCS coordinates) indicating the direction and magnitude of the translation.
	bitflags (I) The bitmap of one or more flags specified by the GetGripPointsFlags enumeration.
  */

  ODRX_SEALED_VIRTUAL OdResult moveGripPointsAtSubentPaths( const OdDbFullSubentPathArray& paths,
    const OdDbVoidPtrArray& gripAppData, const OdGeVector3d& offset, const OdUInt32 bitflags) ODRX_SEALED;

  /** Description:
	Deletes one or more subentities from an entity.

	Arguments:
	paths (I) The array of OdDbFullSubentPath objects.
  */

  ODRX_SEALED_VIRTUAL OdResult deleteSubentPaths(const OdDbFullSubentPathArray& paths) ODRX_SEALED;

  /** Description:
  Add one or more subentities to an entity.

  Arguments:
  paths (I) The array of OdDbFullSubentPath objects.
  */

  ODRX_SEALED_VIRTUAL OdResult addSubentPaths(const OdDbFullSubentPathArray& paths) ODRX_SEALED;

  /** Description:
	Create an object by OdDbFullSubentPath to the subentity.

	Arguments:
	path (I) The OdDbFullSubentPath to the subentity.
  */

  ODRX_SEALED_VIRTUAL OdDbEntity* subentPtr(const OdDbFullSubentPath& path) const ODRX_SEALED;

  /** Description:
	Applies a geometric transformation to one or more subentities on an object. 

	Arguments:
	paths (I) The array of OdDbFullSubentPath objects.
	xform (I) The WCS transformation to apply to each of the supplied subentities.
  */

  ODRX_SEALED_VIRTUAL OdResult transformSubentPathsBy(const OdDbFullSubentPathArray &paths, const OdGeMatrix3d & xform) ODRX_SEALED;

  /** Description:
	Obtains the CLSID of the wrapper coclass for the subentity.

	Arguments:
	path (I) The OdDbFullSubentPath to the subentity.
	clsId (I/O) The pointer to a CLSID structure whose contents are set to the CLSID of the wrapper for the subentity.
  */

  ODRX_SEALED_VIRTUAL OdResult getSubentClassId( const OdDbFullSubentPath& path, void* clsId ) ODRX_SEALED;
  ODRX_SEALED_VIRTUAL OdResult getSubentClassId( const OdDbFullSubentPath& path, CLSID* clsId ) ODRX_SEALED;

  /** Description:
	Returns the geometric extents for a subentity.

	Arguments:
	path (I) The OdDbFullSubentPath to the subentity.
	extents (I/O) The geometric extents, expressed in world coordinates, of the subentity.
  */

  ODRX_SEALED_VIRTUAL OdResult getSubentPathGeomExtents( const OdDbFullSubentPath& path, OdGeExtents3d& extents ) ODRX_SEALED;
  ODRX_SEALED_VIRTUAL OdResult getSubentPathGeomExtents( const OdDbFullSubentPath& path, OdDbExtents& extents ) ODRX_SEALED;

  ODRX_SEALED_VIRTUAL  void  subentGripStatus(const OdDb::GripStat status, const OdDbFullSubentPath& subentity) ODRX_SEALED;
  
protected:
  virtual OdResult subWblockClone(OdRxObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary = true) const ODRX_OVERRIDE;
  virtual OdResult subDeepClone(OdDbObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary = true) const ODRX_OVERRIDE;

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm);
  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm,
    OdDbEntity*& pCopy) const;
  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const;
  virtual OdResult subGetCompoundObjectTransform(OdGeMatrix3d & xM) const;

  virtual OdBool subCloneMeForDragging();
  virtual bool subHideMeForDragging() const;

  virtual void subGripStatus( const OdDb::GripStat status );

  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& xWorldToEye,
    OdGePoint3dArray& snapPoints,
    OdDbIntArray &   geomIds) const;
  
  virtual OdResult subGetOsnapPoints(
    OdDb::OsnapMode osnapMode,
    OdGsMarker gsSelectionMark,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& xWorldToEye,
    OdGePoint3dArray& snapPoints,
    OdDbIntArray &   geomIds,
    const OdGeMatrix3d& insertionMat) const;
  
  virtual bool subIsContentSnappable() const;

  virtual OdResult subGetGripPoints( OdGePoint3dArray& gripPoints ,
                                    OdDbIntArray &     osnapModes,//not currently in use
                                    OdDbIntArray &  geomIds) const;
  virtual OdResult subMoveGripPointsAt(const OdIntArray& indices,const OdGeVector3d& offset );
  virtual OdResult subGetGripPoints(
    OdDbGripDataPtrArray& grips,
    const double curViewUnitSize,
    const int gripSize,
    const OdGeVector3d& curViewDir,
    const int bitFlags ) const;
  virtual OdResult subMoveGripPointsAt(
    const OdDbVoidPtrArray& grips,
    const OdGeVector3d& offset,
    const int bitFlags );
  virtual OdResult subGetStretchPoints( OdGePoint3dArray& stretchPoints ) const;
  virtual OdResult subMoveStretchPointsAt(
    const OdIntArray& indices,
    const OdGeVector3d& offset );

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subHighlight(const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false) const;

  virtual OdResult subUnhighlight(const OdDbFullSubentPath& subId = kNullSubent,
    const OdBool highlightAll = false) const;

  virtual OdResult subGetGeomExtents(OdDbExtents& extents) const;
  virtual OdResult subDeleteSubentPaths(const OdDbFullSubentPathArray& paths);
  virtual OdResult subAddSubentPaths(const OdDbFullSubentPathArray& paths);

  virtual OdResult subMoveGripPointsAtSubentPaths( const OdDbFullSubentPathArray& paths, 
    const OdDbVoidPtrArray& gripAppData, const OdGeVector3d& offset, const OdUInt32 bitflags);
  virtual OdResult subGetGripPointsAtSubentPath( const OdDbFullSubentPath& path, OdDbGripDataPtrArray& grips,
    const double curViewUnitSize, const int gripSize,
    const OdGeVector3d& curViewDir, const OdUInt32 bitflags) const;
  virtual OdResult subGetSubentPathsAtGsMarker(OdDb::SubentType type, OdGsMarker gsMark, 
    const OdGePoint3d& pickPoint,const OdGeMatrix3d& xfm, 
    int& numPaths, OdDbFullSubentPath*& subentPaths, 
    int numInserts = 0,
	  OdDbObjectId* pEntAndInsertStack = 0) const;
  virtual OdResult subGetGsMarkersAtSubentPath( const OdDbFullSubentPath& subPath, 
    OdGsMarkerArray& gsMarkers) const;
  virtual OdDbEntity* subSubentPtr(const OdDbFullSubentPath& path) const;
  virtual OdResult subTransformSubentPathsBy(const OdDbFullSubentPathArray &paths, const OdGeMatrix3d & xform);
  virtual OdResult subGetSubentClassId( const OdDbFullSubentPath& path, void* clsId ) const;
  virtual OdResult subGetSubentPathGeomExtents( const OdDbFullSubentPath& path, OdGeExtents3d& extents ) const;
  virtual void subSubentGripStatus(const OdDb::GripStat status, const OdDbFullSubentPath& subentity);

  friend class OdDbPropertiesOverrule;
  friend class OdDbOsnapOverrule;
  friend class OdDbTransformOverrule;
  friend class OdDbGripOverrule;
  friend class OdDbSubentityOverrule;
  friend class OdDbHighlightOverrule;
  friend class OdDbGeometryOverrule;
};

#include "TD_PackPop.h"

#endif /* _ODDBENTITY_INCLUDED_ */

