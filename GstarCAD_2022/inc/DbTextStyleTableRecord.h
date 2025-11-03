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




#ifndef _ODDBTEXTSTYLETABLERECORD_INCLUDED
#define _ODDBTEXTSTYLETABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"

class OdDbTextStyleTable;
/** Description:
    This class represents TextStyle records in the OdDbTextStyleTable in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbTextStyleTableRecord : public OdDbSymbolTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbTextStyleTableRecord);

  OdDbTextStyleTableRecord();
  virtual ~OdDbTextStyleTableRecord();
  
  typedef OdDbTextStyleTable TableType;

  /** Description:
    Returns true if and only if the text *font* file for this TextStyle is interpreted as a shape file (DXF 70, bit 0x01).
  */
  bool isShapeFile() const;

  /** Description:
    Controls if the text *font* file for this TextStyle is interpreted as a shape file (DXF 70, bit 0x01).

    Arguments:
    isShapeFile (I) As a shape file, if and only if true.
  */
  void setIsShapeFile(
    bool isShapeFile);

  /** Description:
    Returns true if and only if text is drawn vertically with this TextStyle (DXF 70, bit 0x04).
  */
  bool isVertical() const;

  /** Description:
    Controls the vertical drawing of text with this TextStyle (DXF 70, bit 0x04).
    
    Arguments:
    isVertical (I) Controls vertical drawing.
  */
  void setIsVertical(
    bool isVertical);

  /** Description:
      Returns the fixed text size for this TextStyle (DXF 40).
  */
  double textSize() const;

  /** Description:
    Sets the fixed text size for this TextStyle (DXF 40).

    Arguments:
    textSize (I) Fixed text size.
  */
  OdResult setTextSize(
    double textSize);

  /** Description:
    Returns the X-scale (width) factor for this TextStyle (DXF 41).
  */
  double xScale() const;

  /** Description:
    Sets the X-scale (width) factor for this TextStyle (DXF 41).
    
    Arguments:
    xScale (I) X-scale factor.
  */
  OdResult setXScale(
    double xScale);

  /** Description:
    Returns the obliquing angle for this TextStyle (DXF 50).
    
    Remarks:
    The range of obliquingAngle is ?.48335 radians (?5?. Negative angles will have Oda2PI added to them.

    Note:
    All angles are expressed in radians.
  */
  double obliquingAngle() const;

  /** Description:
    Sets the obliquing angle for this TextStyle (DXF 50).
    
    Arguments:
    obliquingAngle (I) Obliquing angle.

    Remarks:
    The range of obliquingAngle is ?.48335 radians (?5?. Negative angles will have Oda2PI added to them.

    Note:
    All angles are expressed in radians.
  */
  OdResult setObliquingAngle(
    double obliquingAngle);

  /** Description:
    Returns true if and only if text is drawn backwards with this TextStyle (DXF 71, bit 0x02).
  */
  bool isBackwards() const;

  /** Description:
    Controls the backwards drawing of text with this TextStyle (DXF 71, bit 0x02).
    
    Arguments:
    isBackwards (I) Controls backwards drawing.
  */
  void setIsBackwards(
    bool isBackwards);

  /** Description:
    Returns true if and only if text is drawn upside down with this TextStyle (DXF 71, bit 0x04).
  */
  bool isUpsideDown() const;

  /** Description:
    Controls the upside down drawing of text with this TextStyle (DXF 71, bit 0x04).
    
    Arguments:
    isUpsideDown (I) Controls upside down drawing.
  */
  void setIsUpsideDown(
    bool isUpsideDown);

  OdUInt8 flagBits() const;
  void setFlagBits(
    OdUInt8 flagBits);

  /** Description:
    Returns the size of the text most recently created with this TextStyle (DXF 42).
  */
  double priorSize() const;

  /** Description:
    Sets the size of the text most recently created with this TextStyle (DXF 42).
    
    Arguments:
    priorSize (I) Prior size.
  */
  OdResult setPriorSize(
    double priorSize);

  /** Description:
    Returns the name of the *font* file associated with this TextStyle (DXF 3).
  */
  OdString fileName() const;

  OdResult fileName (
    OdChar*& pName) const;
  OdResult fileName (
    const OdChar*& pName) const;
  /** Description:
    Sets the name of the *font* file associated with this TextStyle (DXF 3).

    Arguments:
    filename (I) Font filename.
  */
  OdResult setFileName(
    const OdChar * filename);

  /** Description:
    Returns the name of the BigFont file associated with this TextStyle (DXF 4).
  */
  OdString bigFontFileName() const;

  OdResult bigFontFileName (
    OdChar*& pName) const;
  OdResult bigFontFileName (
    const OdChar*& pName) const;
  /** Description:
    Sets the name of the BigFont file associated with this TextStyle (DXF 4).
    
    Arguments:
    bigFontFileName (I) BigFont filename.
  */
  OdResult setBigFontFileName(
    const OdChar * bigFontFileName);

  /** Description:
    Sets this TextStyle to use the specified Windows *font* characteristics.

    Arguments:
    typeface (I) Typeface name of the *font*.
    bold (I) Bold if and only if true.
    italic (I) Italic if and only if true.
    charset (I) Windows character set identitier.
    pitchAndFamily (I) Windows pitch and character family identifier.
    
    Remarks:
    If typeface is null, the Windows *font* information is removed from this text style.
  */
  OdResult setFont(
    const OdChar * typeface,
		bool bold,
		bool italic,
		int charset,
		int pitchAndFamily);

  /** Description:
    Returns the Windows *font* characteristics for this TextStyle.

    Arguments:
    typeface (O) Typeface name of the *font*.
    bold (O) True if and only if bold.
    italic (O) True if and only if italic.
    charset (O) Windows character set identitier.
    pitchAndFamily (O) Windows pitch and character family identifier.
  */
  void font(
    OdString& typeface,
		bool& bold,
		bool& italic,
		int& charset,
		int& pitchAndFamily) const;

  OdResult font (
    OdChar*& pTypeface,
    bool& bold,
    bool& italic,
    int& charset,
    int& pitchAndFamily) const;

  OdResult font (
    OdChar*& pTypeface,
    int & bold,
    int & italic,
    int& charset,
    int& pitchAndFamily) const;
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

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
  
  OdResult dxfIn(
    OdDbDxfFiler* pFiler);

  virtual OdResult subClose();
  virtual OdResult subErase(
    OdBool erasing);
  virtual OdResult subHandOverTo(
    OdDbObject* pNewObject);

  virtual OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  virtual OdResult subWblockClone(OdRxObject* pOwnerObject,
    OdDbObject*& pClonedObject,
    OdDbIdMapping& idMap,
    OdBool isPrimary) const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbTextStyleTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbTextStyleTableRecord> OdDbTextStyleTableRecordPtr;

class OdGiTextStyle;
TOOLKIT_EXPORT void giFromDbTextStyle(const OdDbTextStyleTableRecord* pTStyle, OdGiTextStyle& giStyle);
TOOLKIT_EXPORT void giFromDbTextStyle(OdDbObjectId styleId, OdGiTextStyle& giStyle);

TOOLKIT_EXPORT void giToDbTextStyle(OdGiTextStyle& giStyle, OdDbTextStyleTableRecord* pRecord);

#include "TD_PackPop.h"

#endif // _ODDBTEXTSTYLETABLERECORD_INCLUDED

