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


#ifndef _ODRXMODULESOFTREFERENCE_H_
#define _ODRXMODULESOFTREFERENCE_H_

#include "DynamicLinker.h"
#include "RxDLinkerReactor.h"
#include "StaticRxObject.h"

#include "TD_PackPush.h"


/** Description:
    This interface represents client's atomic portion of code to execute via asynchronous call.
    Library: TD_Db
    {group:OdRx_Classes} 
*/
template <class TModule = OdRxModule>
class OdRxModuleSoftReference : protected OdStaticRxObject<OdRxDLinkerReactor> 
{
  TModule* m_pModule;

protected:
  void rxAppWillBeUnloaded(const OdChar* moduleName) 
  {
    OdRxModule* pModule = odrxDynamicLinker()->getModule(moduleName);

    if( pModule==m_pModule ) 
    {
      clear();
    }
  }

public:
  OdRxModuleSoftReference() : m_pModule(0) {}
  ~OdRxModuleSoftReference() { clear(); }
  OdSmartPtr<TModule> getModule( const OdString& appName ) {
    OdSmartPtr<TModule> pRes = m_pModule;
    if( pRes.isNull() ) {
      pRes = ::odrxDynamicLinker()->loadApp( appName );
      ::odrxDynamicLinker()->addReactor( this );
      m_pModule = pRes.get();
    }
    return pRes;
  }
  TModule* getRef() {
    return m_pModule;
  }
  void clear() {
    if( m_pModule ) {
      m_pModule = 0;
      ::odrxDynamicLinker()->removeReactor( this );
    }
  }
};

#include "TD_PackPop.h"

#endif // _ODRXMODULESOFTREFERENCE_H_

