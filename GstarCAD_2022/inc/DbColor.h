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


#ifndef _OD_DB_COLOR_
#define _OD_DB_COLOR_


#include "DbObject.h"
#include "CmColor.h"


#include "TD_PackPush.h"

/** Description:
  For Teigha internal use only.
  Library:
  TD_Db
  {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbColor : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbColor);

  OdDbColor();
  virtual ~OdDbColor();

  /** Description:
    For Teigha internal use only.
  */
  const OdCmColor& cmColor() const;

  void getColor(OdCmColor& color) const; // Gcad(Add)

  /** Description:
    For Teigha internal use only.
    
    Arguments:
    color (I) For Teigha internal use only.
  */
  void setColor(const OdCmColor& color);

  /** Description:
    For Teigha internal use only.
  */
  OdCmEntityColor entityColor() const; // Gcad(Modify):TODO

  virtual OdResult decomposeForSave(
    OdDb::DwgVersion ver,
    OdDbObject*& replaceObj,
    OdDbObjectId& replaceId,
    OdBool& exchangeXData);
  
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const; // Gcad(Modify)

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const; // Gcad(Modify)
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbColor object pointers.
*/
typedef OdSmartPtr<OdDbColor> OdDbColorPtr;

#include "TD_PackPop.h"

#endif
