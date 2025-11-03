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


#ifndef _ODREMOTEGEOMPROXY_INCLUDED_
#define _ODREMOTEGEOMPROXY_INCLUDED_

#include "TD_PackPush.h"

#include "Gi/GiWorldDraw.h"
#include "DbDatabase.h"
#include "SmartPtr.h"
#include "Ge/GeCircArc2d.h"
#include "UInt8Array.h"

TOOLKIT_EXPORT OdSmartPtr<OdGiWorldDraw> oddbBeginProxyGraphics( OdDbDatabase* pDbCtx );
TOOLKIT_EXPORT void oddbEndProxyGraphics( OdGiWorldDraw* pWdSaver, OdUInt8Array& graphics );

/** Description:
    This class is used for debugging purposes inside ODA libraries.
    It can be used in client code also to draw some geometry to the remote viewer.
    Remote Geometry Viewer functionality is implemented as part of OdaMfcApp example
    To run viewer run OdaMfcApp and press Ctrl+Alt+R.

    {group:Other_Classes}
*/
class OdRemoteGeomProxy {
protected:
  OdDbDatabasePtr           m_pDb;
  OdSmartPtr<OdGiWorldDraw> m_pWd;
public:

  // For the internal use.
  enum Opcode {
    kGraphics,
    kStringToExecute
  };

  // Constructor.
  OdRemoteGeomProxy();
  ~OdRemoteGeomProxy();

  // Initialize reference database that is used for some operations (e.g. font rendering).
  // If you certain that such operations would not be executed you can omit it.
  void setDatabase(OdDbDatabase* pDb);

  // Initializes collecting geometry to send.
  void begin();

  // Returns OdGiWorldDraw object to output geometry to
  OdGiWorldDraw& wDraw();

  // Returns OdGiWorldGeometry object to output geometry to.
  // Shortcut for wDraw().geometry() expression.
  OdGiWorldGeometry& wGeom();

  // Returns OdGiSubEntityTraits object to output geometry to.
  // Shortcut for wDraw().subEntityTraits() expression.
  OdGiSubEntityTraits& traits();

  // Sends geometry collected since last call of begin() method to
  // Remote Geometry Viewer over the named pipe.
  void end();

  // Sends a string for execution to Remote Geometry Viewer.
  // That string will be send to execution to RX command line engine.
  // See OdEdCommandStack for detailes.
  void sendStringToExecute( const OdString& s );
};

static const OdString g_strGeomBlockBegin = OD_T("rblock_begin");
static const OdString g_strGeomBlockEnd = OD_T("rblock_end");

/** \details

    <group Other_Classes>
*/
class OdRemoteGeomProxyAutoBlock
{
  OdRemoteGeomProxy* m_pProxy;

public:
  OdRemoteGeomProxyAutoBlock(OdRemoteGeomProxy& proxy) : m_pProxy(&proxy)
  {
    m_pProxy->sendStringToExecute(g_strGeomBlockBegin);
  }

  ~OdRemoteGeomProxyAutoBlock()
  {
    m_pProxy->sendStringToExecute(g_strGeomBlockEnd);
  }

};

inline
OdRemoteGeomProxy::OdRemoteGeomProxy()
{  
}

inline
OdRemoteGeomProxy::~OdRemoteGeomProxy()
{  
}

inline void
OdRemoteGeomProxy::setDatabase(OdDbDatabase* pDb) {
  m_pDb = pDb;
}

inline void OdRemoteGeomProxy::begin() {
  m_pWd = ::oddbBeginProxyGraphics( m_pDb );
}

inline OdGiWorldDraw&
OdRemoteGeomProxy::wDraw() {
  return *m_pWd;
}

inline OdGiWorldGeometry&
OdRemoteGeomProxy::wGeom() {
  return m_pWd->geometry();
}

inline OdGiSubEntityTraits&
OdRemoteGeomProxy::traits() {
  return m_pWd->subEntityTraits();
}

inline void
OdRemoteGeomProxy::end() {
  //if( m_pWd.get() ) {
  //  HANDLE hPipe = ::CreateFile( L"\\\\.\\pipe\\OdaRemoteGeometryViewer",
  //    FILE_READ_DATA|FILE_WRITE_DATA, 0, NULL, OPEN_EXISTING, 0, NULL );
  //  if( hPipe != INVALID_HANDLE_VALUE ) {
  //    OdUInt8Array graphics;
  //    ::oddbEndProxyGraphics( m_pWd, graphics );

  //    OdUInt32 n;
  //    OdUInt32 nWritten;
  //    n = kGraphics;
  //    ::WriteFile( hPipe, &n, sizeof(n), &nWritten, NULL );
  //    n = graphics.size();
  //    ::WriteFile( hPipe, &n, sizeof(n), &nWritten, NULL );
  //    ::WriteFile( hPipe, graphics.getPtr(), n, &nWritten, NULL );

  //    // wait for response for sync
  //    ::ReadFile( hPipe, &n, sizeof(n), &nWritten, NULL );
  //    ::CloseHandle( hPipe );
  //  }
  //  m_pWd.release();
  //}

  if( m_pWd.get() )
  { 
    HANDLE hBufferWritten = ::OpenEvent(EVENT_MODIFY_STATE | SYNCHRONIZE, FALSE, OD_T("OdaRemoteGeometryBufferWrittenEvent"));
    HANDLE hBufferProcessed = ::OpenEvent(EVENT_MODIFY_STATE | SYNCHRONIZE, FALSE, OD_T("OdaRemoteGeometryBufferProcessedEvent"));

    if(hBufferWritten != NULL && hBufferProcessed != NULL)
    {
      ::WaitForSingleObject(hBufferProcessed, INFINITE);      
      //::ResetEvent(hBufferProcessed);

      HANDLE hIPCFile = ::OpenFileMapping(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, OD_T("OdaRemoteGeometryViewerIPCBuffer"));
      if(hIPCFile != NULL)
      {
        void* pBuffer = ::MapViewOfFile(hIPCFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
        if(pBuffer != NULL)
        {
          OdInt8* pIpcFile = reinterpret_cast<OdInt8*>(pBuffer);

          OdUInt8Array graphics;
          ::oddbEndProxyGraphics( m_pWd, graphics );

          OdUInt32 n = kGraphics;        
          memcpy(pIpcFile, &n, sizeof(n)); 
          pIpcFile += sizeof(n);

          n = graphics.size();
          memcpy(pIpcFile, &n, sizeof(n)); 
          pIpcFile += sizeof(n);

          memcpy(pIpcFile, graphics.getPtr(), graphics.size());

          ::UnmapViewOfFile(pBuffer);
        }
        ::CloseHandle(hIPCFile);        
      }

      ::SetEvent(hBufferWritten);
    }
    ::CloseHandle(hBufferWritten);
    ::CloseHandle(hBufferProcessed);
    m_pWd.release();
  }
}

inline void
OdRemoteGeomProxy::sendStringToExecute( const OdString& s ) {
  HANDLE hPipe = ::CreateFile( L"\\\\.\\pipe\\OdaRemoteGeometryViewer",
    FILE_READ_DATA|FILE_WRITE_DATA, 0, NULL, OPEN_EXISTING, 0, NULL );
  if( hPipe != INVALID_HANDLE_VALUE ) {
    OdUInt32 n;
    OdUInt32 nWritten;
    n = kStringToExecute;
    ::WriteFile( hPipe, &n, sizeof(n), &nWritten, NULL );
    n = s.getLength() * 2;
    ::WriteFile( hPipe, &n, sizeof(n), &nWritten, NULL );
    ::WriteFile( hPipe, s.c_str(), n, &nWritten, NULL );

    // wait for respense for sync
    ::ReadFile( hPipe, &n, sizeof(n), &nWritten, NULL );
    ::CloseHandle( hPipe );
  }
}

#include "TD_PackPop.h"

#endif //_ODREMOTEGEOMPROXY_INCLUDED_
