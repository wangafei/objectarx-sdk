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


#ifndef ODA_CM_COLOR
#define ODA_CM_COLOR

#include "OdString.h"
#include "Gi/Gi.h"
#include "CmColorBase.h"
#include "DbExport.h"

class OdCmEntityColor;
class OdDbDwgFiler;
class OdDbDxfFiler;
class OdDbAuditInfo;

#include "TD_PackPush.h"

class OdDbObject;
class OdDbFiler;

class OdCmComplexColor;

/** Description:
    This class implements Color objects, which represent the colors of OdDbEntity objects, including RGB and ACI.

    {group:OdCm_Classes}
*/
class TOOLKIT_EXPORT OdCmColor : public OdCmColorBase
{ // Gcad(Modify)
public:
  OdCmColor();
  OdCmColor(
    const OdCmColor& color);
  OdCmColor(
    const OdCmColorBase& color);
  OdCmColor(
    OdCmEntityColor::ColorMethod color,OdUInt32 rgbm = 0);
  OdCmColor& operator=(
    const OdCmColor& color);
  OdCmColor& operator=(
    const OdCmColorBase& color);
  ~OdCmColor();

  bool operator ==(
    const OdCmColor& color) const;
  bool operator !=(
    const OdCmColor& color) const;
  bool operator ==(
    const OdCmColorBase& color) const;
  bool operator !=(
    const OdCmColorBase& color) const;
  
  /** Description:
    Returns the description string of this Color object.
  */
  OdString getDescription() const;

  /** Description:
    Returns the explanation string of this Color object.
  */
 OdString getExplanation() const;

  virtual OdCmEntityColor::ColorMethod colorMethod() const;
  virtual OdResult setColorMethod(
    OdCmEntityColor::ColorMethod colorMethod);

  virtual bool isByColor() const;
  virtual bool isByLayer() const;
  virtual bool isByBlock() const;
  virtual bool isByACI() const;

  virtual bool isForeground() const;
  virtual bool isByDgnIndex() const;

  /** Description:
    Returns true if and only if the *color* *method* for this object is kNone or the
    *color* *method* is kByACI and the ACI is kACInone.
  */
  bool isNone() const;

  virtual OdUInt32 color() const;
  virtual OdResult setColor(
    OdUInt32 color);

  virtual OdResult setRGB(
    OdUInt8 red, 
    OdUInt8 green, 
    OdUInt8 blue);
  virtual OdResult setRed(
    OdUInt8 red);
  virtual OdResult setGreen(
    OdUInt8 green);
  virtual OdResult setBlue(
    OdUInt8 blue);
  virtual OdUInt8 red() const;
  virtual OdUInt8 green() const;
  virtual OdUInt8 blue() const;

  virtual OdUInt16 colorIndex() const;
  virtual OdResult setColorIndex(
    OdUInt16 colorIndex);

  virtual OdResult setNames( // Gcad(Modify) bool=>OdResult
    const OdChar* colorName,
    const OdChar* bookName = NULL);
  virtual const OdChar* colorName() const;
  virtual const OdChar* bookName() const;
  virtual const OdChar* colorNameForDisplay();

  // Gcad(Add) {{
  virtual bool hasColorName() const;
  virtual bool hasBookName() const;
  virtual bool isByPen() const;
  virtual OdUInt16 penIndex() const;
  virtual OdResult setPenIndex(OdUInt16 penIndex);
  // Gcad(Add) }}

  /** Description:
    Returns the OdCmEntityColor settings of this object.
  */
  OdCmEntityColor entityColor() const;
  /** Description:
    Returns a dictionary key based on the *color* name and book name of this object.
   
    Remarks:
    OdCmColor objects with *color* names can be stored in the form of an OdDbColor in a dictionary.
    getDictionaryKey() returns the key for that dictionary.
  */
  OdString getDictionaryKey() const;
  
  /** Description:
    Sets the book name and *color* name from the dictionary entry.
    Remarks:
    Returns true if and only if successful.

    Arguments:
    dictionaryKey (I) Dictionary key.   
  */
  OdResult setNamesFromDictionaryKey( // Gcad(Modify) bool=>OdResult
    const OdChar* dictionaryKey);

  /** 
    Description:
    Reads the .dwg file format data of this object from the specified file.
       
    Arguments:   
    pFiler (I) Pointer to the filer from which the data are to be read.
    
  */
  OdResult dwgIn(
    OdDbDwgFiler* pFiler);

  /** 
    Description:
    Writes the .dwg file format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
  */
  OdResult dwgOut(
    OdDbDwgFiler* pFiler) const;

  /** 
    Description:
    Reads the DXF format data of this object from the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer from which the data are to be read.
    groupCodeOffset (I) Group code offset.
  */
  OdResult dxfIn(
    OdDbDxfFiler* pFiler, 
    int groupCodeOffset = 0);

  /** 
    Description:
    Writes the DXF format data of this object to the specified filer. 
    
    Arguments:
    pFiler (I) Pointer to the filer to which the data are to be written.
    groupCodeOffset (I) Group code offset.
  */
  OdResult dxfOut(
    OdDbDxfFiler* pFiler, 
    int groupCodeOffset = 0) const;

  /** 
    Description:
    Perform an *audit* operation on this object.

    Arguments:
    pAuditInfo (I) Pointer to an AuditInfo object.
    
    Remarks:
    When overriding this function for a custom class, first call OdCmColorBase::audit(pAuditInfo) 
    to validate the *audit* operation.
  */
  //Gcad(modify)
  OdResult audit(
    OdDbAuditInfo* pAuditInfo);

  /** Description:
	Returns the length of the key.

    Remarks:
    OdCmColor objects with *color* names can be stored in the form of an OdDbColor in a dictionary.
    getDictionaryKeyLength() returns the length of the key string for that dictionary or 0 if a key can not be made.
  */
  int dictionaryKeyLength() const; // Gcad(Add)

  /** Description:
	Returns the key.

    Remarks:
    OdCmColor objects with *color* names can be stored in the form of an OdDbColor in a dictionary.
    getDictionaryKey() returns the key string for that dictionary or NULL if a key can not be made.
  */
  void getDictionaryKey(OdChar* dictKey) const;
  void getDictionaryKey(OdChar *pKey, size_t nLen) const;

  OdResult serializeOut(void *pBuff, int *pBuflen, OdDb::DwgVersion ver = OdDb::kDHL_CURRENT) const;
  OdResult serializeIn(const void *pBuff, int *pBuflen);

  OdCmComplexColor* complexColor() const;
  void setComplexColor(OdCmComplexColor* pComplex);

  /**
	This function sets desc to point to a copy of the OdCmColor object's description string, or,
	if the OdCmColor object is complex, then a copy of that OdCmComplexColor object's description
	string is returned instead.
   */
  OdResult getDescription(OdChar*& desc) const;
  
  /**
	This function sets desc to point to a copy of the OdCmColor object's explanation string, or,
	if the OdCmColor object is complex, then a copy of that OdCmComplexColor object's explanation
	string is returned instead.
  */
  OdResult getExplanation(OdChar*& exp) const;
  
  // For internal use
  /** { Secret } */
  OdResult dwgInAsTrueColor (
    OdDbDwgFiler* pFiler);
  /** { Secret } */
  OdResult dwgOutAsTrueColor(
    OdDbDwgFiler* pFiler) const;

  TOOLKIT_EXPORT_STATIC static const OdUInt16 MaxColorIndex;

private:
  enum NameFlags
  {    
    kNoNames      = 0,
    kHasColorName = 1,
    kHasBookName  = 2
  };
  OdCmEntityColor::RGBM   m_RGBM;
  OdString                m_colorName;
  OdString                m_bookName;
};

#include "TD_PackPop.h"

#endif // ODA_CM_COLOR
