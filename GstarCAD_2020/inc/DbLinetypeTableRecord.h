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




#ifndef _ODDBLINETYPETABLERECORD_INCLUDED
#define _ODDBLINETYPETABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"
#include "DbLinetypeTable.h"

class OdGeVector2d;

/** Description:
    This class represents Linetype records in the OdDbLinetypeTable in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbLinetypeTableRecord : public OdDbSymbolTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbLinetypeTableRecord);

  OdDbLinetypeTableRecord();
  virtual ~OdDbLinetypeTableRecord();

  typedef OdDbLinetypeTable TableType;

  /** Description:
    Returns the simple ASCII representation of this Linetype (DXF 3).
  */
  OdString comments() const;

  /** Gcad(Add): 新增兼容非虚函数
  */
  OdResult comments(OdChar*& pString) const;
  OdResult comments(const OdChar*& pString) const;

  /** Description:
    Sets the simple ASCII representation for this Linetype (DXF 3).
    Arguments:
    comments (I) Comment string

    Gcad(Modify): 返回值 void -> OdResult; 使用 OdString
  */
  OdResult setComments(
    const OdChar* comments);

  /** Gcad(Add): 新增兼容函数
    注意: 以后这 3 个函数会丢弃, 请使用 comments() & setComments()
  */
  OdResult asciiDescription(OdChar*& pString) const
  { return comments(pString); }
  OdResult asciiDescription(const OdChar*& pString) const
  { return comments(pString); }
  OdResult setAsciiDescription(const OdChar* pString)
  { return setComments(pString); }

  /** Description:
    Returns the length of this Linetype pattern (DXF 40).
    
    Remarks:
    patternLength is the total length in drawing units of all the dashes in this Linetype pattern.
  */
  double patternLength() const;

  /** Description:
    Sets the length of this Linetype pattern (DXF 40).
    
    Arguments:
    patternLength (I) Pattern length.
    
    Remarks:
    patternLength is the total length in drawing units of all the dashes in this Linetype pattern.
  */
  void setPatternLength(
    double patternLength);

  /** Description:
    Returns the number of dashes in this Linetype (DXF 73).
  */
  int numDashes() const;

  /** Description:
    Sets the number of dashes for this Linetype (DXF 73).
    Arguments:
    numDashes (I) Number of dashes. [0,2..12]
    
    Note:
    Setting the number of dashes results in said number of zero-length dashes with no shape
    or text string associated with them.
  */
  void setNumDashes(
    int numDashes);

  /** Description:
    Returns the length of the dash at the specified index (DXF 49).  
    
    Arguments:
    dashIndex (I) Dash index.
    
    Remarks:
    0 <= dashIndex < numDashes().

  */
  double dashLengthAt(
    int dashIndex) const;

  /** Description:
    Sets the length of the dash at the specified index (DXF 49).  
    
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    dashLength (I) Dash length.
  */
  void setDashLengthAt(
    int dashIndex, 
    double dashLength);

  /** Description:
    Returns the Object ID of the OdDbTextStyleTableRecord of
    the shape or TextStyle at the specified index (DXF 340).  
      
    Remarks:
    Returns NULL if there is no shape or text at the specified index.
    
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.

  */
  OdDbObjectId shapeStyleAt(
    int dashIndex) const;

  /** Description:
    Sets the Object ID of the OdDbTextStyleTableRecord of
    the shape or TextStyle for the specified index (DXF 340).  
      
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    objectId (I) Object Id.
  */
  void setShapeStyleAt(
    int dashIndex, 
    OdDbObjectId objectId);

  /** Description:
    Returns the shape number of the shape at the specified
    index (DXF 75).  

    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
  */
  int shapeNumberAt(
    int dashIndex) const;

  /** Description:
    Sets the shape number of the shape at the specified
    index (DXF 75).  

    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    shapeNumber (I) Shape number.
  */
  void setShapeNumberAt(
    int dashIndex, 
    int shapeNumber);

  /** Description:
    Returns the shape offset of the shape or text string at the specified
    index (DXF 44, 45).  
    
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
  */
  OdGeVector2d shapeOffsetAt(int dashIndex) const;

  /** Description:
    Sets the shape offset of the shape or text string at the specified
    index (DXF 44, 45).  
    
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    shapeOffset (I) Shape offset.
  */
  void setShapeOffsetAt(
    int dashIndex, 
    const OdGeVector2d& shapeOffset);

  /** Description:
    Returns the scale of the shape or text string at the specified
    index (DXF 46).  
      
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
  */
  double shapeScaleAt(
    int dashIndex) const;

  /** Description:
    Specifies the scale of the shape or text string at the specified
    index (DXF 46).  
      
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    shapeScale (I) Shape scale.
  */
  void setShapeScaleAt(
    int dashIndex, 
    double shapeScale);

  /** Description:
    Returns the alignment type for this Linetype (DXF 72). 
    
    Remarks:
    A value of true indicates that DXF 72 code contains the letter 'S' (scaled to fit), 
    false indicates that it contains the letter 'A' (not scaled to fit).
  */
  bool isScaledToFit() const;

  /** Description:
    Sets the alignment type for this Linetype (DXF 72).  
    
    Arguments:
    scaledToFit (I) Controls the ScaledToFit flag. 

    Remarks:
    A value of true indicates that DXF 72 code contains the letter 'S' (scaled to fit), 
    false indicates that it contains the letter 'A' (not scaled to fit).
  */
  void setIsScaledToFit(
    bool scaledToFit);

  /** Description:
    Returns the UcsOriented flag for the shape or text string at the specified index (DXF 74, bit 0x01).

    Arguments:
    dashIndex (I) Dash index.

    Remarks:
    Returns true if and only if the shape or text string is UcsOriented.
    
    0 <= dashIndex < numDashes().
  */
  bool shapeIsUcsOrientedAt(
    int dashIndex) const;

  /** Description:
    Specifies the UcsOriented flag for the shape or text string at the specified index (DXF 74, bit 0x01).

    Arguments:
    dashIndex (I) Dash index.
    isUcsOriented (I) True for UcsOriented, false for line-segment oriented.

    Remarks:
    0 <= dashIndex < numDashes().
  */
  void setShapeIsUcsOrientedAt(
    int dashIndex, 
    bool isUcsOriented);

  /** Description:
    Returns the rotation angle of the shape or text string at the specified
    index (DXF 50).  
      
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    
    Note:
    All angles are expressed in radians.
  */
  double shapeRotationAt(
    int dashIndex) const;

  /** Description:
    Sets the rotation angle of the shape or text string at the specified
    index (DXF 50).  
      
    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    shapeRotation (I) Shape rotation angle.
    
    Note:
    All angles are expressed in radians.
  */
  void setShapeRotationAt(
    int dashIndex, 
    double shapeRotation);

  /** Description:
    Returns the text string at the specified
    index (DXF 9).  

    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
  */
  OdString textAt(int dashIndex) const;

  /** Gcad(Add): 新增兼容非虚函数
  */
  OdResult textAt(int index, OdChar*& text) const;
  OdResult textAt(int index, const OdChar*& text) const;

  /** Description:
    Sets the *text* string at the specified
    index (DXF 9).  

    Remarks:
    0 <= dashIndex < numDashes().

    Arguments:
    dashIndex (I) Dash index.
    text (I) Text string.

    Gcad(Modify): 返回值 void -> OdResult; 使用 OdString
  */
  OdResult setTextAt(
    int dashIndex, 
    const OdChar* text);

  /** in & out
  */
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;

  virtual OdResult subGetClassID(CLSID* pClsid) const;

  virtual OdGiDrawable* drawable();

  void setGsNode(OdGsNode* pNode);
  OdGsNode* gsNode() const;

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);
  
  virtual OdResult subErase(
    OdBool erasing);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLinetypeTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbLinetypeTableRecord> OdDbLinetypeTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBLINETYPETABLERECORD_INCLUDED

