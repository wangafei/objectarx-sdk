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




#ifndef OD_DBDICTIONARYVAR_H
#define OD_DBDICTIONARYVAR_H

#include "TD_PackPush.h"

#include "DbObject.h"

/** Description:
    This class represents Dictionary Variable objects in an OdDbDatabase instance.
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDictionaryVar : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDictionaryVar);

  OdDbDictionaryVar();

  /** Description:
    Returns the schema number of this Dictionary Variable object (DXF 280).
  */
  OdInt16 getSchema() const;

  /** Description:
    Sets the schema number of this Dictionary Variable object (DXF 280).
    Arguments:
    schemaNumber (I) Schema number.
  */
  void setSchema(OdInt16 schemaNumber);

  /** Description:
      Returns the *value* of this Dictionary Variable object  (DXF 1).
  */
  OdString value() const;
  
  /** Description:
      Returns the *value* of this Dictionary Variable object as a string, int, or bool.

      Arguments:
      val (O) Receives the *value* of this object.
  */
  bool valueAs(OdString& val) const { val = value(); return true; }
  bool valueAs(int& val) const;
  bool valueAs(bool& val) const;
  bool valueAs(double& val) const;
  bool valueAs(OdGePoint2d& val) const;
  bool valueAs(OdGePoint3d& val) const;

  /** Description:
      Sets the *value* of this Dictionary Variable object  (DXF 1).
      Arguments:
      val (I) Value for this object.
  */
  void setValue(const OdString& val);
  void setValue(int val);
  void setValue(bool val);
  void setValue(double val);
  void setValue(const OdGePoint2d& val);
  void setValue(const OdGePoint3d& val);

  virtual OdResult dxfIn(OdDbDxfFiler* pFiler);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

};
 
/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDictionaryVar object pointers.
*/
typedef OdSmartPtr<OdDbDictionaryVar> OdDbDictionaryVarPtr;

#include "TD_PackPop.h"

#endif  // OD_DBDICTIONARYVAR_H

