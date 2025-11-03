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


#ifndef _ODDBSYSTEMSERVICES_INCLUDED_
#define _ODDBSYSTEMSERVICES_INCLUDED_

#include "RxSystemServices.h"

#include "TD_PackPush.h"

/** Description:
    This class is the base class for classes that provide platform-dependent file operations for
    Teigha.
*/
typedef OdRxSystemServices OdDbSystemServices;

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbSystemServices object pointers.
*/
typedef OdSmartPtr<OdDbSystemServices> OdDbSystemServicesPtr;

TOOLKIT_EXPORT OdDbSystemServices* odSystemServices();

/** Description:
    Performs Teigha system initialization.  
    
    Remarks:
    This function registers all classes supported by Teigha. Instances of these classes may
    Thus be created by client applications. 
    
    It also allows the user to specify the OdDbSystemServices instance that to be used for file creation and access.  
    
    Note:
    This function should be called once per process prior to any other Teigha calls.
    
    Arguments:
    pSystemServices (I) Pointer to SystemServices object.
	
    Library:
    TD_Db
*/
TOOLKIT_EXPORT void odInitialize(
  OdDbSystemServices* pSystemServices);

/** Description:
    Performs Teigha system uninitialization.  

    Remarks:
    This function releases the dynamic class registration data and the OdDbSystemServices pointer 
    associated with the earlier call to odInitialize.  
    
    Note:
    This function should be called once per process as the last operation performed by Teigha.

    Library:
    TD_Db
*/
TOOLKIT_EXPORT void odUninitialize();


#include "TD_PackPop.h"

#endif // _ODDBSYSTEMSERVICES_INCLUDED_
