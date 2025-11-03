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




// RxDLinkerReactor.h: interface for the OdRxDLinkerReactor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_ODRXDLINKERREACTOR_H_INCLUDED_)
#define _ODRXDLINKERREACTOR_H_INCLUDED_

#include "TD_PackPush.h"

/** Description:
    This class is the base class for custom classes that receive notification
    of OdRxDLinker events.
    
    Remarks:
    Events consist of the loading and unloading of OdRxModules.
    
    Note:
    The default implementations of all methods in this class do nothing.

    Library:
    TD_Root

    {group:OdRx_Classes} 
*/
class FIRSTDLL_EXPORT OdRxDLinkerReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdRxDLinkerReactor);

  /** Description:
    Notification function called whenever an OdRxModule (TX application) will be loaded.
    Arguments:
    moduleName (I) Module name.
    Note:
    This function is called before the operation. 
  */
  virtual void rxAppWillBeLoaded(const OdChar* moduleName);
  /** Description:
    Notification function called whenever an OdRxModule (TX application) has been loaded.
    Arguments:
    pModule (I) Pointer to the OdRxModule.
    Note:
    This function is called after the operation. 
  */
  virtual void rxAppLoaded(const OdChar* moduleName);
  /** Description:
    Notification function called whenever the loading of an OdRxModule (TX application) has been aborted.
    Arguments:
    moduleName (I) Module name.
    Note:
    This function is after before the operation. 
  */
  virtual void rxAppLoadAborted(const OdChar* moduleName);

  /** Description:
    Notification function called whenever an OdRxModule (TX application) is about to be unloaded.
    Arguments:
    pModule (I) Pointer to the OdRxModule.
    Note:
    This function is called before the operation. 
  */
  virtual void rxAppWillBeUnloaded(const OdChar* moduleName);
  /** Description:
    Notification function called whenever an OdRxModule (TX application) has been unloaded.
    Arguments:
    moduleName (I) Module name.
    Note:
    This function is called after the operation. 
  */
  virtual void rxAppUnloaded(const OdChar* moduleName);
  /** Description:
    Notification function called whenever the unloading of an OdRxModule (TX application) has been aborted.
    Arguments:
    moduleName (I) Module name.
    Note:
    This function is after before the operation. 
  */
  virtual void rxAppUnloadAborted(const OdChar* moduleName);
};

#include "TD_PackPop.h"

#endif // !defined(_ODRXDLINKERREACTOR_H_INCLUDED_)

