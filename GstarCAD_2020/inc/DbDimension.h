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




#ifndef OD_DBDIM_H
#define OD_DBDIM_H

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "DbMText.h"
#include "Ge/GeScale3d.h"

class OdDbDimStyleTableRecord;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDimStyleTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbDimStyleTableRecord> OdDbDimStyleTableRecordPtr;

/** Description:
    This class is the base class for all Dimension classes in an OdDbDatabase instance.
    
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDimension : public OdDbEntity
{
protected:
  OdDbDimension(); 
public:
  ODDB_DECLARE_MEMBERS(OdDbDimension);
  /** 
  Gcad(Add):增加兼容接口	
  */
  ~OdDbDimension();

  /** Description:
    Returns the position of the dimension text for this Dimension entity (DXF 11 as WCS).

    Remarks:
    This position is the middle center point of the dimension text, which is itself a 
    middle-center justified MText entity.  
  */
  OdGePoint3d textPosition() const;

  /** Description:
    Sets the position of the dimension text for this Dimension entity (DXF 11 as WCS).

    Arguments:
    textPosition (I) Text position.  
    
    Remarks:
    This position is the middle center point of the dimension text, which is itself a 
    middle-center justified MText entity.  

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTextPosition(
    const OdGePoint3d& textPosition);

  /** Description:
    Returns true if and only if the dimension text for this Dimension entity
    is in the default position (DXF 70, bit 0x80 == 0).
  */
  bool isUsingDefaultTextPosition() const;

  /** Description:
    Sets the dimension text for this Dimension entity to not use the default position (DXF 70, sets bit 0x80).

	Gcad(Modify):returns:void->OdResult
  */
  OdResult useSetTextPosition();

  /** Description:
    Sets the dimension text for this Dimension entity to use the default position (DXF 70, clears bit 0x80).

	Gcad(Modify):returns:void->OdResult
  */
  OdResult useDefaultTextPosition();

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
  OdResult setNormal(
    const OdGeVector3d& normal);

  virtual OdBool isPlanar() const { return ::kTrue; }

  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;

  /** Description:
    Returns the *elevation* of this entity in the OCS (DXF 30).
    
    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.
  */
  double elevation() const;

  /** Description:
    Sets the *elevation* of this entity in the OCS (DXF 30).

    Arguments:
    elevation (I) Elevation.    

    Remarks:
    The *elevation* is the *distance* from the WCS origin to the plane of this entity.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setElevation(
    double elevation);

  /** Description:
    Returns the user-supplied dimension text for this Dimension Entity (DXF 1).

    Remarks:
    o If no text is to appear, "." will be returned.
    o If only the default text is to appear, "" will be returned.
    o The default text is represented as "<>" within the returned text.

	Gcad(Internal):接口冲突
  */
  const OdString& dimensionText(ODSYSDEF) const;
  /**
  Gcad(Add):增加兼容接口
  */
  OdChar*   dimensionText() const;
  const OdChar* dimensionTextConst() const;

  /** Description:
    Sets the user-supplied dimension text for this Dimension Entity (DXF 1).
    
    Arguments:
    dimensionText (I) Dimension text.

    Remarks:
    o If no text is to appear, supply ".".
    o If only the default text is to appear, supply an empty string "".
    o The default text is represented as "<>" within the supplied text.
    
	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimensionText(
    const OdChar * dimensionText);
    
  /** Description:
    Returns the rotation angle for the dimension text for this Dimension entity (DXF 53).

    Note:
    All angles are expressed in radians.
 */
  double textRotation() const;

  /** Description:
    Sets the rotation angle for the dimension text for this Dimension entity (DXF 53).
    
    Arguments:
    textRotation (I) Text rotation.
    Note:
    All angles are expressed in radians.

	Gcad(Modify):returns:void->OdResult
 */
  OdResult setTextRotation(
    double textRotation);

  /** Description:
    Returns the Object ID of the dimension style (OdDbDimStyleTableRecord) for this Dimension entity (DXF 3).
  */
  OdDbObjectId dimensionStyle() const;

  /** Description:
    Sets the Object ID of the dimension style (OdDbDimStyleTableRecord) for this Dimension entity (DXF 3).
    Arguments:
    objectID (I) Object ID.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimensionStyle(
    OdDbObjectId objectID);

  /** Description:
    Returns the dimension text attachment point for this Dimension entity (DXF 71).
  */
  OdDbMText::AttachmentPoint textAttachment() const;

  /** Description:
    Sets the dimension text attachment point for this Dimension entity (DXF 71).
    Arguments:
    attachmentPoint (I) Attachment Point.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTextAttachment(
    OdDbMText::AttachmentPoint attachmentPoint);

  /** Description:
    Returns the dimension text line spacing style for this Dimension entity (DXF 72).
  */
  OdDb::LineSpacingStyle textLineSpacingStyle() const;

  /** Description:
    Sets the dimension text line spacing style for this Dimension entity (DXF 72).
    Arguments:
    lineSpacingStyle (I) Line spacing style.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTextLineSpacingStyle(
    OdDb::LineSpacingStyle lineSpacingStyle);

  /** Description:
    Returns the dimension text line spacing factor for this Dimension entity (DXF 41).
    
    See also:
    OdDb::LineSpacingStyle
  */
  double textLineSpacingFactor() const;

  /** Description:
    Sets the dimension text line spacing factor for this Dimension entity (DXF 41).
    
    Arguments:
    lineSpacingFactor (I) Line spacing factor. [0.25 .. 4.0]
    
    See also:
    OdDb::LineSpacingStyle

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTextLineSpacingFactor(
    double lineSpacingFactor);

  /** Description:
    Copies the dimension style settings, including overrides, of this Dimension entity into the specified
    dimension style table record.
    
    Arguments:
    pRecord (O) Receives the effective dimension style data associated with entity.
    
    Remarks:
    The *copied* data includes the dimension style data with all applicable overrides. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult getDimstyleData(
    OdDbDimStyleTableRecord *pRecord) const;

  /** Description:
    Copies the dimension style settings, including overrides, from the specified
    dimension style table record to this Dimension entity.
    
    Arguments:
    pDimstyle (I) Pointer to a non- *database* -resident dimension style record.
    dimstyleID (I) Database-resident dimension style record.

    Remarks:
    The *copied* data includes the dimension style with all applicable overrides. 

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimstyleData(
    const OdDbDimStyleTableRecord* pDimstyle);
  // Gcad(Modify):returns:void->OdResult
  OdResult setDimstyleData(
    OdDbObjectId dimstyleID);

   // Gcad(Add)
  // virtual void        objectClosed(const OdDbObjectId dbObj);
  /** Description:
    Returns the horizontal rotation angle for this Dimension entity (DXF 51).
    Note:
    All angles are expressed in radians.
  */
  double horizontalRotation() const;

  /** Description:
    Sets the horizontal rotation angle for this Dimension entity (DXF 51).
    Arguments:
    horizontalRotation (I) Horizontal rotation angle.
    Note:
    All angles are expressed in radians.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setHorizontalRotation(
    double horizontalRotation);


  /** Description:
    Returns the Object ID of the dimension block (OdDbBlockTableRecord) associated with this Dimension entity (DXF 2).
  */
  OdDbObjectId dimBlockId() const;

  /** Description:
    Sets the Object ID of the dimension block (OdDbBlockTableRecord) associated with this Dimension entity.
   
    Arguments:
    dimBlockId (I) Object ID of the OdDbBlockTableRecord.
    singleReferenced (I) True if and only if the dimension block is referenced only by this Dimension entity (DXF 70 bit 0x20).

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimBlockId(
    const OdDbObjectId& dimBlockId, 
    bool singleReferenced = true);

  /** Description:
    Returns true and only if this Dimension entity has the only reference to its 
    associated OdDbBlockTableRecord (DXF 70 bit 0x20).
  */
  bool isSingleDimBlockReference() const;

  /** Description:
    Returns the WCS relative position of the block associated with this Dimension entity (DXF 12).
      
    Remarks:
    dimBlockPosition is the insertion point of the block with respect to the primary
    definition point (DXF 10) of the dimension block.      
  */
  OdGePoint3d dimBlockPosition() const;

  /** Description:
    Sets the relative position of the dimension block referenced by this Dimension entity,
    in WCS (DXF 12). 
    
    Note:
    For Teigha internal use only. Dimension update sets it to 0,0,0
    
    Argument
    dimBlockPosition (I) Dimension block position.
    {Secret}

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimBlockPosition(
    const OdGePoint3d& dimBlockPosition);


  /** Description:
    Returns the rotation angle of the dimension block referenced by this Dimension entity (DXF 54).
    Note:
    All angles are expressed in radians.    
  */
  double dimBlockRotation() const;

  /** Description:
    Sets the rotation of the dimension block referenced by this Dimension entity (DXF 54). 
    
    Note:
    For Teigha internal use only. Dimension update sets it to 0.
    
    Argument
    dimBlockRotation (I) Dimension block rotation in radians.
    {Secret}

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimBlockRotation(
    double dimBlockRotation);

  /** Description:
    Returns the scale of the dimension block referenced by this Dimension entity.
    
    Note:
    This is not saved to a DXF file.
  */
  OdGeScale3d dimBlockScale() const;

  /** Description:
    Sets the scale of the dimension block referenced by this Dimension entity.
    
    Note:
    For Teigha internal use only. Dimension update sets it to 1,1,1
    
    Argument
    dimBlockScale (I) Dimension block scale.
    {Secret}

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimBlockScale(
    const OdGeScale3d& dimBlockScale);

  /** Description:
    Returns the transformation matrix applied to dimension block referenced by this Dimension entity.
    
    Remarks
    The transformation consists of position, scale, rotation angle and *normal*.
    It does not include block's base point.
  */
  OdGeMatrix3d dimBlockTransform() const;

  //Gcad(Add)
  OdGeMatrix3d blockTransform() const;
  
  /** Description:
    Recomputes the dimension block referenced by this Dimension entity.
    
    Remarks:
    The OdDbBlockTableRecord of the dimension block is updated to reflect any changes made to this Dimension
    entity since the last time the block table record was updated.

    Arguments:
    forceUpdate (I) If true, the OdDbBlockTableRecord is updated even if the dimension has not been changed.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult recomputeDimBlock(
    bool forceUpdate = true);

  /** Description:
    Returns the *measurement* (DXF 42) stored in this Dimension entity.
      
    Remarks:
    Returns -1.0 if the stored *measurement* value is invalid. 

    Does not recompute the *measurement*.

    This Dimension entity need not be opened for write to call this function.
    
    See also:
    measurement()
  */
  double getMeasurement() const;

  /** Description:
    Returns the *measurement* (DXF 42) for this Dimension entity.
    
    Remarks:
    Recomputes the *measurement* if the stored *measurement* value is invalid (-1.0).
    
    This Dimension entity must be opened for write to call this function.

    See also:
    getMeasurement()
  */
  double measurement();


  // 2005-2006 support
  
  /** Description:
    Returns the background text *color* and flags for this Dimension entity.
    Arguments:
    bgrndTxtColor (O) Receives the background text *color*.
  */
  OdUInt16 getBgrndTxtColor(OdCmColor& bgrndTxtColor) const;
  
  /** Description:
    Sets the background text *color* and flags for this Dimension entity.
    Arguments:
    bgrndTxtColor (I) Background text *color*.
    bgrndTxtFlags (I) Background text flags.

 */
  OdResult setBgrndTxtColor(const OdCmColor& bgrndTxtColor, OdUInt16 bgrndTxtFlags );

  /** Description:
    Returns the extension line fixed length enable flag for this Dimension entity.
  */
  bool getExtLineFixLenEnable() const;

  /** Description:
    Controls the extension line fixed length enable flag for this Dimension entity.
    Arguments:
    extLineFixLenEnable (I) Extension line fixed length flag.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setExtLineFixLenEnable(bool extLineFixLenEnable);

  /** Description:
    Returns the extension line fixed length for this Dimension entity.
  */
  double getExtLineFixLen() const;

  /** Description:
    Sets the extension line fixed length for this Dimension entity.
    Arguments:
    extLineFixLen (I) Extension line fixed length.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setExtLineFixLen(double extLineFixLen);

  /** Description:
    Returns the Object ID of the dimension line *linetype* for this Dimension entity.
  */
  OdDbObjectId dimLineLinetype() const;

  /** Description:
    Sets the Object ID of the dimension line *linetype* for this Dimension entity.

    Arguments:
    linetypeId (I) Dimension line *linetype* Object ID.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimLineLinetype(const OdDbObjectId& linetypeId);
  
  /** Description:
    Returns the Object ID of the first extension line *linetype* for this Dimension entity.
  */
  OdDbObjectId dimExt1Linetype() const;

  /** Description:
    Sets the Object ID of the first extension line *linetype* for this Dimension entity.
    
    Arguments:    
    linetypeId (I) First extension line *linetype* Object ID.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimExt1Linetype(const OdDbObjectId& linetypeId);

  /** Description:
    Returns the Object ID of the second extension line *linetype* for this Dimension entity.
  */
  OdDbObjectId dimExt2Linetype() const;

  /** Description:
    Sets the Object ID of the second extension line *linetype* for this Dimension entity.
    
    Arguments:    
    linetypeId (I) Second extension line *linetype* Object ID.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setDimExt2Linetype(const OdDbObjectId& linetypeId);

  /** Description:
    Returns the flip flag of the first arrowhead for this Dimension entity.
  */
  bool getArrowFirstIsFlipped() const;

  /** Description:
    Returns the flip flag of the second arrowhead for this Dimension entity.
  */
  bool getArrowSecondIsFlipped() const;
  
  /** Description:
    Sets the flip flag of the first arrowhead for this Dimension entity.

    Arguments:
    bIsFlipped (I) Flip flag value.
  */
  OdResult setArrowFirstIsFlipped(bool bIsFlipped);

  /** Description:
    Sets the flip flag of the second arrowhead for this Dimension entity.

    Arguments:
    bIsFlipped (I) Flip flag value.
  */
  OdResult setArrowSecondIsFlipped(bool bIsFlipped);

  enum DimInspect 
  {
    kShapeRemove  = 0x00,     // No inspection label displays.
    kShapeRound   = 0x01,     // Inspection label displays with a rounded end (this is the default).
    kShapeAngular = 0x02,     // Inspection label displays with an angular end.
    kShapeNone    = 0x04,     // Inspection label displays without a bounding shape.
    kShapeLabel   = 0x10,     // Inspection label displays with a prefix, including a separator and alpha field.
    kShapeRate    = 0x20      // Inspection label displays at a specified frequency.
  };

  bool inspection() const;
  // Gcad(Modify):returns:void->OdResult
  OdResult setInspection(bool val);

  int inspectionFrame() const;
  // Gcad(Modify):returns:void->OdResult
  OdResult setInspectionFrame(int frame);

  const OdChar* inspectionLabel() const;
  // Gcad(Modify):returns:void->OdResult
  OdResult setInspectionLabel(const OdChar* label);

  const OdChar* inspectionRate() const;
  // Gcad(Modify):returns:void->OdResult
  OdResult setInspectionRate(const OdChar* label);

/** { Secret } */
#define VAR_DEF_STRING(type, name, dxf, def_value, metric_def_value, reserve1, reserve2)\
  virtual const OdChar* dim##name() const;\
  virtual OdResult setDim##name(const OdChar* val);

#define VAR_DEF(type, name, dxf, def_value, metric_def_value, reserve1, reserve2)\
  /** Description: Returns the DIM##NAME value of this Dimension entity.  \
    Remarks: ##remarks \
    \
    Remarks: \
    The value from the dimension style of this Dimension entity will be returned unless \
    that value has been overridden, in which case, the override value will be returned. \
    \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual type dim##name() const; \
\
  /** Description: Sets the DIM##NAME override for this Dimension entity. \
    Arguments: val (I) New value for DIM##NAME.  ##RANGE \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
	// Gcad(Modify):returns:void->OdResult
  */ \
virtual OdResult setDim##name(type val);

#include "DimVarDefs.h"
#undef  VAR_DEF
#undef  VAR_DEF_STRING

    int dimfit() const;
    int dimunit() const;

    OdResult setDimfit (int );
    OdResult setDimunit(int );

    virtual bool dimfxlenOn() const;
    virtual double dimfxlen() const;

    virtual OdResult setDimfxlenOn(bool v);
    virtual OdResult setDimfxlen(double v);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  //Gcad(Modify):returns:void->OdResult
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  OdResult subGetClassID(CLSID* pClsid) const;

  OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);

  void subViewportDraw(
    OdGiViewportDraw* pVd);

  /* Replace OdRxObjectPtrArray */
  
  virtual OdResult subExplode(
    OdDbVoidPtrArray& entitySet) const ODRX_OVERRIDE; 

  //Gcad(Modify):returns:void->OdResult
  OdResult subClose();

  virtual void modified (
    const OdDbObject* pObject);

  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdBool subCloneMeForDragging();
  
  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm, 
    OdDbEntity*& pCopy) const ODRX_OVERRIDE;

  /** Note:
     This function is an override for OdDbEntity::subSetDatabaseDefaults() to set 
     the dimension style of this entity to the current style for the specified *database*.
  */
  void subSetDatabaseDefaults(OdDbDatabase *pDb);

  void appendToOwner(
    OdDbIdPair& idPair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  /** Description:
    Returns the formatted measurement value.
    
    Arguments:
    formattedMeasurement (O) Receives the formatted measurement.
    measurementValue (I) Measurement value to be formatted.
    dimensionText (I) Dimension text for formatting
    
    Remarks:
    measurementValue is formatted per the specified dimension text and the 
    effective dimension style.
  */
  void formatMeasurement(
    OdString& formattedMeasurement, 
    double measurementValue, 
    const OdString& dimensionText);

  /** Gcad(Add)
  */
   OdResult   formatMeasurement(OdChar *MTextContentBuffer,
                                          double measurement,
                                          OdChar *dimensionText);


  OdResult explodeGeometry(OdDbVoidPtrArray& entitySet) const;

  OdDbObjectPtr dimBlock(OdDb::OpenMode openMode = OdDb::kForRead);

  /** Gcad(Add)
  */
  OdResult generateLayout();

  OdResult setDimblk   (const OdChar*);
  OdResult setDimblk1  (const OdChar*);
  OdResult setDimblk2  (const OdChar*);
  OdResult setDimldrblk(const OdChar*);

  /** Gcad(Add)
  
  OdResult getOsnapPoints(OdDb::OsnapMode osnapMode, const OdDbFullSubentPath& subentId,
                      const OdGePoint3d& pickPoint, const OdGePoint3d& lastPoint,
                      const OdGeMatrix3d& viewXform, OdGePoint3dArray& snapPoints,
                      OdDbIntArray& geomIds ) const;
  OdResult   getOsnapPoints(OdDb::OsnapMode     osnapMode,
                                       int     gsSelectionMark,
                                       const OdGePoint3d&  pickPoint,
                                       const OdGePoint3d&  lastPoint,
                                       const OdGeMatrix3d& viewXform,
                                       OdGePoint3dArray&   snapPoints,
                                       OdDbIntArray &   geomIds) const; 
  */

  virtual OdResult subGetCompoundObjectTransform(OdGeMatrix3d & xM) const ODRX_OVERRIDE;

  /**
  Gcad(Add)
  */
  OdResult   measurement(double &val);
  
  // Dynamic dimensions support
  // (The methods are NOT related to constraint support)

  bool isDynamicDimension() const;
  void setDynamicDimension(
    bool bDynamic);

  // Dimensional constraint support

  bool isConstraintObject() const;
  OdResult isConstraintObject(
    bool& isConstraintObject,
    bool& hasExpression,
    bool& isReferenceConstraint) const;

  bool  isConstraintDynamic() const;
  OdResult setConstraintDynamic(
    bool bDynamic);

  bool  shouldParticipateInOPM() const;
  void  setShouldParticipateInOPM(
    bool bShouldParticipate);
  
  void setDIMTALN(bool val);
  bool getDIMTALN() const;

  void removeTextField();
  void fieldToMText(OdDbMTextPtr& pDimMText);
  void fieldFromMText(OdDbMTextPtr& pDimMText);

  virtual void getEcs(OdGeMatrix3d& retVal) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDimension object pointers.
*/
typedef OdSmartPtr<OdDbDimension> OdDbDimensionPtr;

class OdDbDimensionObjectContextData;

  /** Description:
    This class is the Dimension Recompute Protocol Extension class.
   
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDimensionRecomputePE : public OdRxObject
{
public:
  /** Description:
    Sets the measurement value for the specified Dimension entity.
    
    Arguments:
    pDimension (I) Pointer to the dimension entity.
    measurementValue (I) Measurement value.
  */
  static void setMeasurementValue(OdDbDimension* pDimension, double measurementValue);
  /** Description:
    Resets the dimension block insertion parameters for the specified Dimension entity.
    
    Arguments:
    pDimension (I) Pointer to the dimension entity.

    Remarks:
    o  The insertion point is set to (0,0).
    o  The X-, Y- and Z-scale factors are set 1.0.
    o  The rotation angle is set to 0.0. 
  */
  static void resetDimBlockInsertParams(OdDbDimension* pDimension);

  ODRX_DECLARE_MEMBERS(OdDbDimensionRecomputePE);

  /** Description:
    Recomputes the dimension measurement for the specified Dimension entity.
    
    Arguments:
    pDimension (I) Pointer to the dimension entity.
  */
  virtual void recomputeDimMeasurement(OdDbDimension* pDimension) = 0;

  /** Description:
    Recomputes the dimension block referenced by the specified Dimension entity.
    
    Remarks:
    The OdDbBlockTableRecord of the dimension block is updated to reflect any changes made to this Dimension
    entity since the last time the block table record was updated.

    Arguments:
    pDimension (I) Pointer to the dimension entity.
  */
  virtual void recomputeDimBlock(OdDbDimension* pDimension, OdDbDimensionObjectContextData* ctx) = 0;


  /** Description:
    Returns the formatted measurement value.
    
    Arguments:
    pDimension (I) Pointer to the dimension entity.
    formattedMeasurement (O) Receives the formatted measurement.
    measurementValue (I) Measurement value to be formatted.
    dimensionText (I) Dimension text for formatting
    
    Remarks:
    measurementValue is formatted per the specified dimension text and the 
    effective dimension style.
  */
  virtual void formatMeasurement(OdDbDimension* pDimension, OdString& formattedMeasurement, 
     double measurementValue, const OdString& dimensionText ) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDimensionRecomputePE object pointers.
*/
typedef OdSmartPtr<OdDbDimensionRecomputePE> OdDbDimensionRecomputePEPtr;

#include "TD_PackPop.h"

#endif

