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

// Multithreading contexts and definitions

#ifndef __GSMTCONTEXT_H_INCLUDED_
#define __GSMTCONTEXT_H_INCLUDED_

#include "../TD_PackPush.h"

//#define ODGS_MT // Comment to remove meltithreading Gs support

#ifdef ODGS_MT

#include "RxObject.h"
#include "Gs/GsExport.h"

struct OdGsGeomPortion;
class OdGsBaseVectorizeView;
class OdGsMaterialNode;
class OdGsBaseModel;

class OdGsExtAccum;
typedef OdSmartPtr<OdGsExtAccum> OdGsExtAccumPtr;

struct GS_TOOLKIT_EXPORT OdGsMTContext : public OdRxObject
{
  enum Flags
  {
    kMultithread = (1 << 0)
  };

  OdUInt32 m_uFlags : 16;
  OdUInt32 m_nSlots : 16;
  OdRxObjectPtr m_pThreadPool;

  enum LockEvent
  {
    kLockLayer = 0,
    kLockMaterial,
    kLockSpatialIndex,
    kLockContainer /*= kLockSpatialIndex*/,
    kLockDevice, //kLockInvalidate,

    kNMaxLocks
  };

  OdGsMTContext()
    : m_uFlags(0)
    , m_nSlots(1)
    , m_pThreadPool()
  {
  }

  void setMultithread(bool bSet) { SETBIT(m_uFlags, kMultithread, bSet); }
  bool isMultithread() const { return GETBIT(m_uFlags, kMultithread); }

  void enterCriticalSection(LockEvent nEvent);
  void leaveCriticalSection(LockEvent nEvent);

  void addThread(OdRxObject *runObject, OdRxObject *runArg, OdUInt32 nSlot); // runObject should be OdApcAtom child
  void runThreads(); // Starts all accumulated threads and waits for completion
};

typedef OdSmartPtr<OdGsMTContext> OdGsMTContextPtr;

struct GS_TOOLKIT_EXPORT OdGsMTModelContext
{
  OdGsExtAccumPtr m_pExtAccum;
  OdGsGeomPortion *m_pGeomPortion;
  OdGsBaseVectorizeView *m_pGsMetafileWriter;
  OdGsMaterialNode *m_pCurMaterialNode;

  OdGsMTModelContext()
    : m_pExtAccum()
    , m_pGeomPortion(NULL)
    , m_pGsMetafileWriter(NULL)
    , m_pCurMaterialNode(NULL)
  {
  }
};

struct GS_TOOLKIT_EXPORT OdGsMTViewContext : public OdRxObject, public OdGsMTModelContext
{
  OdGsMTContext *m_pContext;
  OdUInt32 m_nSlot;

  OdGsMTViewContext()
    : m_pContext(NULL)
    , m_nSlot(0)
  {
  }

  bool isMultithread() const { return m_pContext->isMultithread(); }

  bool isGhostView() const { return m_nSlot > 0; }
  bool isBearingView() const { return m_nSlot == 0; }
};

typedef OdSmartPtr<OdGsMTViewContext> OdGsMTViewContextPtr;

class GS_TOOLKIT_EXPORT OdGsMTContextAutoLock
{
  OdGsMTContext* m_pMtCxt;
  OdGsMTContext::LockEvent m_lockEvent;
public:
  OdGsMTContextAutoLock( OdGsMTContext* pMtCxt, OdGsMTContext::LockEvent lockEvent );
  ~OdGsMTContextAutoLock();
};

#define ODGS_MT_VIEW_AUTOLOCK( pView, lockEvent ) OdGsMTContextAutoLock __view_autolock__( pView, lockEvent )

#else

#define ODGS_MT_VIEW_AUTOLOCK( pView, lockEvent )

#endif

#include "../TD_PackPop.h"

#endif // __GSMTCONTEXT_H_INCLUDED_
