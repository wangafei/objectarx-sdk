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




#ifndef OD_DBVBAPROJECT_H
#define OD_DBVBAPROJECT_H

#include "TD_PackPush.h"

#include "DbObject.h"

/** Description:
    This class represents VBA Project objects in an OdDbDatabase instance.

    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbVbaProject : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbVbaProject);

  OdDbVbaProject();

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  /** Description:
    Returns the project data for this VBA Project object.

    Arguments:
    vbaProject (O) Receives the project data.
  */
  void getVbaProject(OdBinaryData& vbaProject) const;

  /** Description:
    Sets the project data for this VBA Project object.

    Arguments:
    vbaProject (O) Project data.
  */
  void setVbaProject(const OdBinaryData& vbaProject);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbVbaProject object pointers.
*/
typedef OdSmartPtr<OdDbVbaProject> OdDbVbaProjectPtr;

#include "TD_PackPop.h"

#endif //OD_DBVBAPROJECT_H

