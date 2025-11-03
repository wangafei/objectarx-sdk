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


#ifndef _OD_RXMODULE_H_
#define _OD_RXMODULE_H_

#include "RxObject.h"

#include "TD_PackPush.h"

/** Description:
    This class is the base class that is overridden to create custom Teigha applications (TX modules).
    Library: TD_Db
    {group:OdRx_Classes} 
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRxModule : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdRxModule);

  /** Description:
    Returns the system data for this OdRxModule.
  */
  virtual void* sysData() = 0;

  /** Description:
    Deletes (unloads) this OdRxModule.
  */
  virtual void deleteModule() = 0;

  /** Description:
      Notification function called at the start of the client application.
      
      Remarks:
      Overrides of this module should register any custom objects or commands defined
      in the module.
  */
  virtual void initApp() = 0;

  /** Description:
      Notification function called at the end of the client application.
      Remarks:
      Overrides of this module should unregister any custom objects or commands defined
      in the module.
  */
  virtual void uninitApp() = 0;

  /** Description:
    Returns the name of this module.
  */
  virtual OdString moduleName() const = 0;

  virtual bool isGrxExtend() const;
  virtual void addLoadReference();
  virtual void releaseLoadReference();
  virtual long loadReference() const;
};

class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRxExtendModule : public OdRxModule
{
  OdRefCounter m_nloadCounter;
public:
  ODRX_DECLARE_MEMBERS(OdRxExtendModule);

  OdRxExtendModule();
  ~OdRxExtendModule();

  // gcrxEntryPoint (pkt ==> app)
  virtual OdRx::AppRetCode fireMsg(OdRx::AppMsgCode nmsg, void *pkt) = 0;

  virtual bool isGrxExtend() const;
  virtual void addLoadReference();
  virtual void releaseLoadReference();
  virtual long loadReference() const;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdRxModule object pointers.
*/
typedef OdSmartPtr<OdRxModule> OdRxModulePtr;


#include "TD_PackPop.h"

#endif // _OD_RXMODULE_H_

