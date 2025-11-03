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


#ifndef __OD_DB_DGNUNDERLAY_HOST__
#define __OD_DB_DGNUNDERLAY_HOST__

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDgnUnderlayItem : public OdDbUnderlayItem
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDgnUnderlayItem);

  virtual bool useMasterUnits() const = 0;
  virtual void setUseMasterUnits(bool useMaster) = 0;
  virtual bool showRasterRef() const = 0;
  virtual void setShowRasterRef(bool bShow) = 0;
};

typedef OdSmartPtr<OdDbDgnUnderlayItem> OdDbDgnUnderlayItemPtr;

#endif // __OD_DB_DGNUNDERLAY_HOST__
