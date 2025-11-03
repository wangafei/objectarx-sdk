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




#ifndef OD_DBTEXT_H
#define OD_DBTEXT_H

#include "TD_PackPush.h"

#include "DbEntity.h"
#include "TextDefs.h"

/** Description:
    This class represents simple text (Text) entities in an OdDbDatabase instance.
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbText: public OdDbEntity
{
public:
  
  ODDB_DECLARE_MEMBERS(OdDbText);
  
  OdDbText();
    
  OdDbText(
      const OdGePoint3d&  position,
      const OdChar *     text,
      OdDbObjectId        style = OdDbObjectId::kNull,
      double              height = 0,
      double              rotation = 0);
  ~OdDbText();
  
  /** Description:
    Returns the *position* of this entity (WCS equivalent of DXF 10).
  */
  OdGePoint3d position() const;
  
  /** Description:
    Sets the *position* of this entity (WCS equivalent of DXF 10).

    Arguments:
    position (I) Position.
  */
  OdResult setPosition(
    const OdGePoint3d& position);
  
  /** Description:
    Returns the *alignment* point of this Text entity (WCS equivalent of DXF 11).
  */
  OdGePoint3d alignmentPoint() const;
  
  /** Description:
    Sets the *alignment* point of this Text entity (WCS equivalent of DXF 11).
    Arguments:
    alignment (I) Alignment point.
  */
  OdResult setAlignmentPoint(
    const OdGePoint3d& alignment);
  
  /** Description:
    Return true if and only if this Text entity is in the default alignment.
    Remarks:
    The default alignment is horizontalMode() == OdDb::kTextLeft and verticalMode() == OdDbKTextBase.
  */
  OdBool isDefaultAlignment() const;
  
  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  OdResult setNormal(
    const OdGeVector3d& normal);
 
  /** Remarks:
      Always returns true.
  */
  virtual OdBool isPlanar() const { return ::kTrue; }
  
  virtual OdResult getPlane(
    OdGePlane& plane, 
    OdDb::Planarity& planarity) const;
  
  /** Description:
    Returns the *thickness* of this entity (DXF 39).
    
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  double thickness() const;
  
  /** Description:
    Sets the *thickness* of this entity (DXF 39).
    Arguments:
    thickness (I) Thickness.
    Remarks:
    Thickness is the extrusion length along the *normal*.
  */
  OdResult setThickness(
    double thickness);
  
  /** Description:
    Returns the *oblique* angle of this Text entity (DXF 51).

    Remarks:
    The range of oblique is +-1.48335 radians (+-85).
    
    Oblique angles are measured clockwise from the vertical.

    Note:
    All angles are expressed in radians.  
  */
  double oblique() const;
  
  /** Description:
    Sets the *oblique* angle of this Text entity (DXF 51).
    Arguments:
    oblique (I) Oblique angle.
    
    Remarks:
    The range of oblique is +-1.48335 radians (+-85).
    
    Oblique angles are measured clockwise from the vertical.
     
    Note:
    All angles are expressed in radians.  
  */
  OdResult setOblique(
    double oblique);
  
  /** Description:
    Returns the *rotation* angle of this Text entity (DXF 50).
    Note:
    All angles are expressed in radians.
 */
  double rotation() const;
  
  /** Description:
    Sets the *rotation* angle of this Text entity (DXF 50).
    Arguments:
    rotation (I) Rotation angle.
    Note:
    All angles are expressed in radians.
  */
  OdResult setRotation(
    double rotation);
  
  /** Description:
    Returns the *height* of this Text entity (DXF 40).
  */
  double height() const;

  /** Description:
    Sets the *height* of this Text entity (DXF 40).
    Arguments:
    height (I) Text *height*.
  */
  OdResult setHeight(
    double height);
  
  /** Description:
    Returns the width factor of this Text entity (DXF 41).
  */
  double widthFactor() const;
  
  /** Description:
    Sets the width factor of this Text entity (DXF 40).
    Arguments:
    widthFactor (I) Width factor.  
  */
  OdResult setWidthFactor(
    double widthFactor);
  
  /**
    Returns true if and only if this Text entity is mirrored in the X (horizontal) direction (DXF 71, bit 0x02).
  */
  OdBool isMirroredInX() const;
  
  /**
    Controls the mirroring of this Text entity in the X (horizontal) direction (DXF 71, bit 0x02).
    Arguments:
    mirror (I) Controls mirroring.
  */
  OdResult mirrorInX(
    OdBool mirror);
  
  /**
    Returns true if and only if this Text entity is mirrored in the Y (vertical) direction (DXF 71, bit 0x04).
  */
  OdBool isMirroredInY() const;
  
  /**
    Controls the mirroring of this Text entity in the Y (vertical) direction (DXF 71, bit 0x04).
    Arguments:
    mirror (I) Controls mirroring.
  */
  OdResult mirrorInY(
    OdBool mirror);
  
  /** Description:
    Returns the text string of this Text entity (DXF 1).
  */
  OdString textString(ODSYSDEF) const;
#ifdef ODARXDEF 
  OdChar*  textString() const;
#endif
  const OdChar* textStringConst() const;
  /** Description:
    Sets the text string of this Text entity (DXF 1).
    Arguments:
    textString (I) Text string.
    
    Note:
    textString cannot exceed 256 characters excluding the null terminator.
  */
  OdResult setTextString(const OdChar * textString);
  
  /** Description:
    Returns the Object ID of the text style of this Text entity (DXF 7).
  */
  OdDbObjectId textStyle() const;
  
  /** Description:
    Sets the Object ID of the text style of this Text entity (DXF 7).
    Arguments:
    textStyleId (I) Text style Object ID.
  */
  OdResult setTextStyle(
    OdDbObjectId textStyleId);
  
  /** Description:
    Returns the horizontal mode of this Text entity (DXF 72).

    Remarks:
    horizontalMode returns one of the following:
    
    @table
    Name                 Value
    OdDb::kTextLeft      0
    OdDb::kTextCenter    1 
    OdDb::kTextRight     2
    OdDb::kTextAlign     3
    OdDb::kTextMid       4    
    OdDb::kTextFit       5
  */
  OdDb::TextHorzMode horizontalMode() const;
  
  /** Description:
    Returns the horizontal mode of this Text entity (DXF 72).

    Arguments:
    horizontalMode (I) Horizontal mode.

    Remarks:
    horizontalMode returns one of the following:
    
    @table
    Name                 Value
    OdDb::kTextLeft      0
    OdDb::kTextCenter    1 
    OdDb::kTextRight     2
    OdDb::kTextAlign     3
    OdDb::kTextMid       4    
    OdDb::kTextFit       5
  */
  OdResult setHorizontalMode(OdDb::TextHorzMode horizontalMode);
  
  /** Description:
    Returns the vertical mode of this Text entity (DXF 73).

    Remarks:
    verticalMode() returns one of the following:
    
    @table
    Name                 Value
    OdDb::kTextBase      0
    OdDb::kTextBottom    1 
    OdDb::kTextVertMid   2
    OdDb::kTextTop       3
  */
  OdDb::TextVertMode verticalMode() const;

  /** Description:
    Sets the vertical mode of this Text entity (DXF 73).

    Arguments:
    verticalMode (I) Vertical mode.
    Remarks:
    verticalMode must be one of the following:
    
    @table
    Name                 Value
    OdDb::kTextBase      0
    OdDb::kTextBottom    1 
    OdDb::kTextVertMid   2
    OdDb::kTextTop       3
  */
  OdResult setVerticalMode(
    OdDb::TextVertMode verticalMode);
  
  /** Description:
    Evokes the spell checker on this Text entity.
    
    Remarks:
    Returns 0 is successful, or 1 if not.
  */
  int correctSpelling();
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  
  /** Description:
    Adjusts the *position* of this Text entity if its alignent is not left baseline.
    
    Arguments:
    pDb (I) Pointer to *database* used to resolve the text style of this
            Text entity.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    Note:
    This function is called by Teigha when a Text entity is closed.

    If this Text entity is *database* resident, pDb is ignored.
    
    If this Text entity is not *database* resident, pDb cannot be NULL.
  */
  virtual OdResult adjustAlignment(
    const OdDbDatabase* pDb = 0);
  
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  
  virtual OdResult dwgOutFields( // OdResult
    OdDbDwgFiler* pFiler) const;
  
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  
  virtual OdResult dxfOutFields( // OdResult
    OdDbDxfFiler* pFiler) const;
  
  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);
  
  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;
  
  OdResult subClose();
  
  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);
  virtual void subViewportDraw(OdGiViewportDraw* pVd);
  virtual OdResult subTransformBy(
    const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  virtual OdResult subGetTransformedCopy(
    const OdGeMatrix3d& xfm, 
    OdDbEntity*& pCopy) const ODRX_OVERRIDE;

  virtual OdBool subCloneMeForDragging();

  /** Description:
    Returns the WCS bounding points of this Text entity.
    
    Arguments:
    boundingPoints (O) Receives the bounding points.
    
    Remarks:
    The points are returned as follows:
    
    @table
    Point                Corner
    boundingPoints[0]    Top left
    boundingPoints[1]    Top right
    boundingPoints[2]    Bottom right
    boundingPoints[3]    Bottom left
  */
  void getBoundingPoints(
    OdGePoint3dArray& boundingPoints) const;

  /* Constructor. */
  /*OdDbText(const OdGePoint3d& position,
      const OdChar* text,
      OdDbObjectId style = OdDbObjectId::kNull,
      double height = 0,
      double rotation = 0);
  */

  using OdDbObject::setField;
  virtual OdResult setField(
    const OdChar* pFieldName, 
    OdDbField* pField,
    OdDbObjectId& fieldId);
  using OdDbObject::removeField;
  virtual OdResult removeField(
    OdDbObjectId fieldId);

  /**Description:
    Converts the fields in this Text entity to text, and removes the fields.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    Note:
    The fields are not evaluated before conversion.
  */
  OdResult convertFieldToText();

  /** Note:
    This function is an override for OdDbEntity::subSetDatabaseDefaults() to set 
    the text style of this entity to the current style and text size for the specified *database*.
  */
  void subSetDatabaseDefaults(OdDbDatabase *pDb);

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    OdGePoint3dArray& points, OdGsMarker thisGsMarker = 0,
    OdGsMarker otherGsMarker = 0) const;

  virtual OdResult subIntersectWith(const OdDbEntity* pEnt, OdDb::Intersect intType,
    const OdGePlane& projPlane, OdGePoint3dArray& points,
    OdGsMarker thisGsMarker = 0, OdGsMarker otherGsMarker = 0) const;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbText object pointers.
*/
typedef OdSmartPtr<OdDbText> OdDbTextPtr;

#include "TD_PackPop.h"

#endif // ODDBTEXT_H

