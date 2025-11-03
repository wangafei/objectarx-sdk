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




#ifndef _OD_DB_ATTRDEF_
#define _OD_DB_ATTRDEF_

#include "TD_PackPush.h"

#include "DbText.h"
#include "DbMText.h"

/** Description:
    This class represents attribute defintion (Attdef) entities in an OdDbDatabase instance.
  
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbAttributeDefinition : public OdDbText
{
public:

  ODDB_DECLARE_MEMBERS(OdDbAttributeDefinition);
  OdDbAttributeDefinition();

  /** Gcad(Add):增加兼容接口	
  */
  OdDbAttributeDefinition(
        const OdGePoint3d& position,
        const OdChar *    text,
        const OdChar *    tag,
        const OdChar *    prompt,
        OdDbObjectId       style = OdDbObjectId::kNull);

  /** Gcad(Add):增加兼容接口	
  */
  ~OdDbAttributeDefinition();

  /** Description:
    Returns the *prompt* string of this Attdef entity (DXF 3).

	Gcad(Internal):接口冲突
  */
  OdString prompt(ODSYSDEF) const;

  /** Gcad(Add):增加兼容接口
  Note:
    The caller of this function is responsible for deallocating the memory used by the returned string.
  */
#ifdef ODARXDEF
  OdChar*  prompt() const;
#endif

  /** Gcad(Add):增加兼容接口
  */
  const OdChar* promptConst() const;

  /** Description:
    Sets the *prompt* string of this Attdef entity (DXF 3).
    Arguments:
    promptString (I) Prompt string

	Gcad(Modify):returns:void->OdResult
  */ 
  OdResult setPrompt(
    const OdChar * promptString);

  /** Description:
    Returns the *tag* string of this Attdef entity (DXF 2).

	Gcad(Internal):接口冲突
  */
  OdString tag(ODSYSDEF) const;
  
  /** Gcad(Add):增加兼容接口
  Note:
    The caller of this function is responsible for deallocating the memory used by the returned string.
  */
  OdChar*  tag() const;

  /** Gcad(Add):增加兼容接口
  */
  const OdChar* tagConst() const;

  /** Description:
    Sets the *tag* string of this Attdef entity (DXF 2).
    Arguments:
    tagString (I) Tag string.  

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setTag(const OdChar* tagString);
  
  /** Description:
    Returns true if and only if this Attdef entity is *invisible* (DXF 70, bit 0x01).
  */
  OdBool isInvisible() const;

  /** Description:
    Controls the invisibility of this Attdef entity (DXF 70, bit 0x01).

    Arguments:
    invisible (I) Controls invisibility.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setInvisible(
    bool invisible);

  /** Description:
    Returns true if and only if this Attdef entity is constant (DXF 70, bit 0x02).
  */
  bool isConstant() const;

  /** Description:
    Controls the *constant* status of this Attdef entity (DXF 70, bit 0x02).
    Arguments:
    constant (I) Controls *constant* status.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setConstant(bool constant);

  /** Description:
    Returns true if and only if this Attdef entity is verifiable (DXF 70, bit 0x04).
  */
  bool isVerifiable() const;

  /** Description:
    Controls the *verifiable* status of this Attdef entity (DXF 70, bit 0x04).
    Arguments:
    verifiable (I) Controls verifiable status.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setVerifiable(bool);

  /** Description:
    Returns true if and only if this Attdef entity is *preset* (DXF 70, bit 0x08).
  */
  bool isPreset() const;

  /** Description:
    Controls the *preset* status of this Attdef entity (DXF 70, bit 0x08).
    Arguments:
    preset (I) Controls *preset* status.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setPreset(bool);

  /** Description:
    Returns the field length of this Attdef entity (DXF 73).
  */
  OdUInt16 fieldLength() const;

  /** Description:
    Sets the field length of this Attdef entity (DXF 73).
    Arguments:
    fieldLength (I) Field length.

	Gcad(Modify):returns:void->OdResult
  */
  OdResult setFieldLength(
    OdUInt16 fieldLength);

  /** Description: Gcad(Add) 增加兼容接口
  */
  virtual OdResult adjustAlignment(
        const OdDbDatabase* pDb = NULL);
		
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

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

  OdBool subWorldDraw(
    OdGiWorldDraw* pWd);
  void subViewportDraw(
    OdGiViewportDraw* pVd);

  void appendToOwner(
    OdDbIdPair& Idpair, 
    OdDbObject* pOwnerObject, 
    OdDbIdMapping& ownerIdMap);

  bool lockPositionInBlock() const;
  OdResult setLockPositionInBlock(bool bValue);
  // multiline attribute definition support
  bool isMTextAttributeDefinition() const;
 #ifdef ODARXDEF
  OdDbMText* getMTextAttributeDefinition() const;
#endif
  const OdDbMText * getMTextAttributeDefinitionConst    () const;
  OdResult setMTextAttributeDefinition(OdDbMText*);
  OdResult convertIntoMTextAttributeDefinition (OdBool val = kTrue);
  OdResult updateMTextAttributeDefinition();

  virtual OdResult subClose();
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbAttributeDefinition object pointers.
*/
typedef OdSmartPtr<OdDbAttributeDefinition> OdDbAttributeDefinitionPtr;

#include "TD_PackPop.h"

#endif

