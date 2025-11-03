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




#ifndef _OD_DBARCALIGNEDTEXT_INC_
#define _OD_DBARCALIGNEDTEXT_INC_

#include "TD_PackPush.h"

#include "DbEntity.h"

enum OdArcTextAlignment
{
  kFit    = 1,
  kLeft   = 2,
  kRight  = 3,
  kCenter = 4
};

enum OdArcTextPosition
{
  kOnConvexSide = 1,
  kOnConcaveSide = 2
};

enum OdArcTextDirection
{
  kOutwardFromCenter = 1,
  kInwardToTheCenter = 2
};

/** Description:
    This class represents Arc-Aligned Text entities in an OdDbDatabase instance.

    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbArcAlignedText : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbArcAlignedText);

  OdDbArcAlignedText();
  
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  
  /** Description:
    Returns the text string for this Text entity (DXF 1).
  */
  const OdString& textString() const;
  
  /** Description:
    Sets the text string for this Text entity (DXF 1).
    Arguments:
    textString (I) Text string.
    
    Note:
    textString cannot exceed 256 characters excluding the null terminator.
  */
  void setTextString(const OdString& textString);
  
  /** Description:
    Returns the Object ID of the Arc entity associated with this Text entity (DXF 330).
  */
  OdDbObjectId arcId() const;

  /** Description:
    Sets the Object ID of the Arc entity associated with this Text entity (DXF 330).
    Arguments:
    arcId (I) Arc Object ID.
  */
  void setArcId(OdDbObjectId arcId);

  /** Description:
    Returns the WCS *center* of the Arc entity associated with this Text entity (WCS equivalent of DXF 10).
  */
  OdGePoint3d center() const;

  /** Description:
    Sets the WCS *center* of the Arc entity associated with this Text entity (WCS equivalent of DXF 10).
    Arguments:
    center (I) Center.
  */
  void setCenter(const OdGePoint3d& center);
  
  /** Description:
    Returns the *radius* of the Arc entity associated with this Text entity (DXF 40).
  */
  double radius() const;

  /** Description:
    Sets the *radius* of the Arc entity associated with this Text entity (DXF 40).
    Arguments:
    radius (I) Radius.
  */
  void setRadius(double radius);

  /** Description:
    Sets the start angle of the Arc entity associated with this Text entity (DXF 50).
    
    Arguments:
    startAngle (I) Start angle.
    
    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  void setStartAngle(double startAngle);

  /** Description:
    Returns the start angle of the Arc entity associated with this Text entity (DXF 50).

    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  double startAngle() const;

  /** Description:
    Sets the end angle of the Arc entity associated with this Text entity (DXF 51).
    Arguments:
    endAngle (I) End angle.

    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  void setEndAngle(double endAngle);

  /** Description:
    Returns the end angle of the Arc entity associated with this Text entity (DXF 51).

    Remarks:
    The angle is measured counterclockwise from the OCS X-axis.

    Note:
    All angles are expressed in radians.
  */
  double endAngle() const;

  /** Description:
    Returns the WCS *normal* to the plane of this entity (DXF 210).
  */
  OdGeVector3d normal() const;
  
  /** Description:
    Sets the WCS *normal* to the plane of this entity (DXF 210).
    Arguments:
    normal (I) Normal.
  */
  void setNormal(const OdGeVector3d& normal);

  /** Description:
    Returns the offset from the Arc entity associated with this Text entity (DXF 44).  
  */
  double offsetFromArc() const;
  
  /** Description:
    Sets the offset from the Arc entity associated with this Text entity (DXF 44).
    Arguments:
    offsetFromArc (I) Offset from arc.  
  */
  void setOffsetFromArc(double offsetFromArc);
  
  /** Description:
    Returns the right offset for this Text entity (DXF 45).  
  */
  double rightOffset() const;
  
  /** Description:
    Sets the right offset for this Text entity (DXF 45).  
    Arguments:
    rightOffset (I) Right offset.  
  */
  void setRightOffset(double rightOffset);
  
  /** Description:
    Returns the left offset for this Text entity (DXF 46).  
  */
  double leftOffset() const;
  
  /** Description:
    Sets the left offset for this Text entity (DXF 46).  
    Arguments:
    leftOffset (I) Left offset.  
  */
  void setLeftOffset(double leftOffset);
  
  /** Description:
    Returns the text size for this Text entity (DXF 42).    
  */
  double textSize() const;
  
  /** Description:
    Sets the text size for this Text entity (DXF 42).
    Arguments:
    textSize (I) Text size.    
  */
  void setTextSize(double textSize);
  
  /** Description:
    Returns the X-scale (width) factor for this Text entity (DXF 41).
  */
  double xScale() const;
  
  /** Description:
    Sets the X-scale (width) factor for this Text entity (DXF 41).
    
    Arguments:
    xScale (I) X-scale factor.
  */
  void setXScale(double xScale);
  
  /** Description:
    Returns the character spacing for this Text entity (DXF 43).  
  */
  double charSpacing() const;
  
  /** Description:
    Sets the character spacing for this Text entity (DXF 43).
    Arguments:
    charSpacing (I) Character spacing.  
  */
  void setCharSpacing(double charSpacing);

  /** Description:
    Returns true if and only if the character order is reversed for this Text entity (DXF 70).
  */
  bool isReversedCharOrder() const;
  
  /** Description:
    Controls the reversal of character order for this Text entity (DXF 70).
    Arguments:
    reverse (I) Controls the reversal.
  */
  void reverseCharOrder(bool reverse);

  /** Description:
    Returns the wizard flag for this Text entity (DXF 280).  
  */
  bool wizardFlag() const;
  
  /** Description:
    Controls the wizard flag for this Text entity (DXF 280).  
    Arguments:
    wizardFlag (I) Controls the wizard flag.
  */
  void setWizardFlag(bool wizardFlag);

  /** Description:
    Returns the *alignment* for this Text entity (DXF 72).
    
    Remarks:
    alignment() returns one of the following:
    
    @table
    Name      Value
    kFit      1
    kLeft     2
    kRight    3
    kCenter   4
  */
  OdArcTextAlignment alignment() const;
  
  /** Description:
    Sets the *alignment* for this Text entity (DXF 72).
    
    Remarks:
    alignment must be one of the following:
    
    @table
    Name      Value
    kFit      1
    kLeft     2
    kRight    3
    kCenter   4
  */
  void setAlignment(OdArcTextAlignment alignment);

  /** Description:
    Returns the text position of this Text entity.
    Remarks:
    textPosition() returns one of the following:
    
    @table
    Name            Value
    kOnConvexSide   1
    kOnConcaveSide  2

  */
  OdArcTextPosition textPosition() const;
  
  /** Description:
    Sets the text position of this Text entity.

    Arguments:
    textPosition (I) Text position.
    Remarks:
    textPosition must be one of the following:
    
    @table
    Name            Value
    kOnConvexSide   1
    kOnConcaveSide  2
  */
  void setTextPosition(OdArcTextPosition textPosition);

  /** Description:
    Returns the text direction for this Text entity (DXF 71).
    
    Remarks:
    textDirection() returns one of the following:
    
    @table
    Name                 Value    
    kOutwardFromCenter   1
    kInwardToTheCenter   2
  */
  OdArcTextDirection textDirection() const;
  
  /** Description:
    Sets the text direction for this Text entity (DXF 71).
    
    Arguments:
    textDirection (I) Text direction.
    
    Remarks:
    textDirection must be one of the following:
    
    @table
    Name                 Value    
    kOutwardFromCenter   1
    kInwardToTheCenter   2
  */
  void setTextDirection(OdArcTextDirection textDir);

  /** Description:
    Returns true if and only if this Text entity is underlined (DXF 76).  
  */
  bool isUnderlined() const;
  
  /** Description:
    Controls the underlining of this Text entity (DXF 76).
    Arguments:
    underlined (I) Controls underlining.  
  */
  void setUnderlined(bool underlined);

  /** Description:
    Returns the Object ID of the text style of this Text entity (DXF 7).
  */
  OdDbObjectId textStyle() const;
  
  /** Description:
    Sets the Object ID of the text style of this Text entity (DXF 7).
    Arguments:
    textStyleId (I) Text style Object ID.
  */
  void setTextStyle(const OdDbObjectId &textStyleId);
  
  /** 
    Arguments:
    styleName (I) Style name.
  */
  void setTextStyle(const OdString& styleName);

  /** Description:
    Returns the name of the *font* file associated with this Text entity (DXF 3).
  */
  const OdString& fileName() const;
  
  /** Description:
    Sets the name of the *font* file associated with this Text entity (DXF 3).

    Arguments:
    filename (I) Font filename.
  */
  void setFileName(const OdString& filename);
  
  /** Description:
    Returns the name of the BigFont file associated with this Text entity (DXF 4).
  */
  const OdString& bigFontFileName() const;
  
  /** Description:
    Sets the name of the BigFont file associated with this Text entity (DXF 4).
    
    Arguments:
    bigFontFileName (I) BigFont filename.
  */
  void setBigFontFileName(const OdString& bigFontFileName);

  /** Description:
    Sets this Text entity to use the specified Windows *font* characteristics.

    Arguments:
    typeface (I) Typeface name of the *font*.
    bold (I) Bold if and only if true.
    italic (I) Italic if and only if true.
    charset (I) Windows character set identifier.
    pitchAndFamily (I) Windows pitch and character family identifier.
    
    Remarks:
    If typeface is null, the Windows *font* information is removed from this text style.
  */
  void setFont(
    const OdString& typeface,
		bool bold,
		bool italic,
		int charset,
		int pitchAndFamily);


  /** Description:
    Returns the Windows *font* characteristics for this Text entity.

    Arguments:
    typeface (O) Typeface name of the *font*.
    bold (O) True if and only if *bold*.
    italic (O) True if and only if *italic*.
    charset (O) Windows character set identifier.
    pitchAndFamily (O) Windows pitch and character family identifier.
  */
  void font(
    OdString& typeface,
		bool& bold,
		bool& italic,
		int& charset,
		int& pitchAndFamily) const;

  /** Description:
    Returns true if and only if this Text entity uses an SHX *font* (DXF 79).
  */
  bool isShxFont() const;

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd) ODRX_OVERRIDE;

  virtual OdResult subTransformBy(const OdGeMatrix3d& xfm) ODRX_OVERRIDE;

  /* Replace OdRxObjectPtrArray */

  virtual OdResult subExplode(OdDbVoidPtrArray& entitySet) const ODRX_OVERRIDE; 
  

  virtual OdResult subClose() ODRX_OVERRIDE;

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;
  /** Description:
      Support for persistent reactor to arc.
  */
  
  void modified(const OdDbObject* pObject);
  void erased(const OdDbObject* pObject, OdBool erasing);
};
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbArcAlignedText object pointers.
*/
typedef OdSmartPtr<OdDbArcAlignedText> OdDbArcAlignedTextPtr;

#include "TD_PackPop.h"

#endif 


