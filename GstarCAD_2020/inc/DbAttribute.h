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




#ifndef _OD_DB_ATTRIBUTE_
#define _OD_DB_ATTRIBUTE_

#include "TD_PackPush.h"

#include "DbText.h"
#include "DbMText.h"

class OdDbAttributeDefinition;
/** Description:
    This class represents Attribute entities in an OdDbDatabase instance.
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbAttribute : public OdDbText
{
public:
  
  ODDB_DECLARE_MEMBERS(OdDbAttribute);

  OdDbAttribute();

  /** Gcad(Add):增加兼容接口	
  */  
  OdDbAttribute(
    const OdGePoint3d& position,
    const OdChar*      text,
    const OdChar*      tag,
    OdDbObjectId       style = OdDbObjectId::kNull);

  /** Gcad(Add):增加兼容接口	
  */
  ~OdDbAttribute();

  /** Description:
    Returns the *tag* string of this Attribute entity (DXF 2).

	Gcad(Internal):接口冲突
  */
  OdString tag(ODSYSDEF) const;

  /** Gcad(Add):增加兼容接口
  Note:
    The caller of this function is responsible for deallocating the memory used by the returned string.
  */
#ifdef ODARXDEF
  OdChar*  tag() const;
#endif
  /** Gcad(Add):增加兼容接口
  */
  const OdChar* tagConst() const;

  /** Description:
    Sets the *tag* string of this Attribute entity (DXF 2).
    Arguments:
    tagString (I) Tag string.  

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTag(const OdChar* tagString);
  /** Description:
    Returns true if and only if this Attribute entity is *invisible* (DXF 70, bit 0x01).
  */
  OdBool isInvisible() const;

  /** Description:
    Controls the invisibility of this Attribute entity (DXF 70, bit 0x01).

    Arguments:
    invisible (I) Controls invisibility.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setInvisible(
    OdBool invisible);

  /** Description:
    Returns true if and only if this Attribute entity is constant (DXF 70, bit 0x02).
  */
  OdBool isConstant() const;

  /** Description:
    Returns true if and only if this Attribute entity is verifiable (DXF 70, bit 0x04).
  */
  OdBool isVerifiable() const;

  /** Description:
    Returns true if and only if this Attribute entity is preset (DXF 70, bit 0x08).
  */
  OdBool isPreset() const;

  /** Description:
    Returns the field length of this Attribute entity (DXF 73).
  */
  OdUInt16 fieldLength() const;

  /** Description:
    Sets the field length of this Attribute entity (DXF 73).
    Arguments:
    fieldLength (I) Field length.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setFieldLength(
    OdUInt16 fieldLength);

  /** Gcad(TODO): in & out
    returns: void->OdResult
  */
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

  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  OdUInt32 subSetAttributes(
    OdGiDrawableTraits* pTraits);

  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);
  virtual void subViewportDraw(OdGiViewportDraw* pVd);

  /** Description:
    Applies the settings from the specified attribute definition,
    then applies the specified block transformation matrix to
    to this Attribute entity.
    
    Arguments:
    pAttDef (I) Pointer to the attribute definition entity.
    blkXform (I) Block transformation matrix.
    
    Remarks:
    Equivalent to the ATTREDEF and INSERT commands.
    
    blkXform is the transformation matrix returned by the OdDbBlockReference::blockTransform() function
    of the OdDbBlockReference that will own this attribute.
    
	Gcad(Modify):returns:void->OdResult
  */
  OdResult setAttributeFromBlock(
    const OdGeMatrix3d& blkXform);
  
  OdResult setAttributeFromBlock(
    const OdDbAttributeDefinition* pAttDef, 
    const OdGeMatrix3d& blkXform);

  /** Description:
    Returns true if and only if the position of this Attribute entity is 
    fixed relative to the block geometry.
  */
  bool lockPositionInBlock() const;
  /** Gcad(Modify):returns:void->OdResult
  */
  OdResult setLockPositionInBlock(bool lock);

  // multiline attribute support
  bool isMTextAttribute() const;
#ifdef ODARXDEF
  OdDbMText* getMTextAttribute() const;
#endif
  const OdDbMText* getMTextAttributeConst() const;
  OdResult setMTextAttribute(OdDbMText*);
  OdResult convertIntoMTextAttribute (OdBool val = kTrue);
  OdResult updateMTextAttribute();
  bool isReallyLocked() const;

  virtual OdResult subClose();
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbAttribute object pointers.
*/
typedef OdSmartPtr<OdDbAttribute> OdDbAttributePtr;

#include "TD_PackPop.h"

#endif

