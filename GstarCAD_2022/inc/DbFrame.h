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


#ifndef OD_DBFRAME_H
#define OD_DBFRAME_H

#include "TD_PackPush.h"

#include "DbEntity.h"

/** Description:
    This class is the abstract base class for OdDbOleFrame graphical objects 
    contained in an OdDbDatabase instance.
    
    Library:
    TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbFrame : public OdDbEntity
{
public:
  ODDB_DECLARE_MEMBERS(OdDbFrame);

  OdDbFrame();
  
  //Gcad(Add)
  virtual ~OdDbFrame();
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbFrame object pointers.
*/
typedef OdSmartPtr<OdDbFrame> OdDbFramePtr;

#include "TD_PackPop.h"

#endif  // OD_DBRAME_H

