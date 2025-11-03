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

#ifndef _ODRXTHREADPOOLSERVICE_INCLUDED_
#define _ODRXTHREADPOOLSERVICE_INCLUDED_ /** { Secret } **/ 

#include "RxModule.h"

class OdRxThreadPoolService;

typedef ptrdiff_t OdApcParamType;

/** Description:
    This interface represents client's atomic portion of code to execute via asynchronous call.
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcAtom : public OdRxObject {
protected:
  OdApcAtom( const OdApcAtom& ) {}
public:
  OdApcAtom() {}
  /** Description:
      Entry point for parallel thread.
  */
  virtual void apcEntryPoint( OdRxObject* pMessage ) {}

  /** Description:
      Entry point for parallel thread.
  */
  virtual void apcEntryPoint( OdApcParamType pMessage ) {}
};

/** Description:
    This template class is a specialization of the OdSmartPtr class template for OdRxApcQueue object pointers.
*/
typedef OdSmartPtr<OdApcAtom> OdApcAtomPtr;


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcObjectPool : public OdRxObject {
public:
  virtual void reserve( OdUInt32 n ) = 0;

  virtual OdRxObjectPtr take() = 0;

  virtual void put( OdRxObject* pObj ) = 0;
};

typedef OdSmartPtr<OdApcObjectPool> OdApcObjectPoolPtr;


class OdApcObjectPool;

/** Description:
    This interface represents APC framework queue.
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcQueue : public OdRxObject {
public:
  /** Description:
      Returns reference to the threading framework.
  */
  virtual OdRxThreadPoolService& framework() = 0;

  /** Description:
      Sets reference to helper atom pool object, where every atom objects is being put to after APC call is returned.
  */
  virtual void setAtomPoolRef( OdApcObjectPool* pAtomPool ) = 0;

  /** Description:
      Adds atomic portion of code encapsulated in OdRxAtom to queue and returns immediately.
  */
  virtual void addEntryPoint( OdApcAtom* pRecipient, OdRxObject* pMessage = 0 ) = 0;

  /** Description:
      Adds atomic portion of code encapsulated in OdRxAtom to queue and returns immediately.
  */
  virtual void addEntryPoint( OdApcAtom* pRecipient, OdApcParamType pMessage ) = 0;

  /** Description:
      Waits until all OdApcAtom objects in main and synchronized queues are processed.
      Remarks:
      Calling thread also utilized to process queued asynchronous calls.
  */
  virtual void wait() = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class template for OdApcQueue object pointers.
*/
typedef OdSmartPtr<OdApcQueue> OdApcQueuePtr;


/** Description:
    This interface represents APC framework gateway.
    It provides functionality useful for protecting data that
    usually is being accessed by many reading threads and few writing.
    It allows access protecting data simultaneously by reading threads
    until no thread gained write access.
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcGateway : public OdRxObject {
public:
  /** Description:
      A calling thread waits until area is unlocked and enters it to read only. 
  */
  virtual void enter() = 0;

  /** Description:
      A calling thread leave protected area. 
  */
  virtual void leave() = 0;

  /** Description:
      1. Locks the entrance.
      2. Waits all threads will exit read state.
      3. Returns
      Remarks:
      IMPORTANT: If calling thread called enter() without leave() it should call lockFromInside() to be not deadlocked.
  */
  virtual void lock() = 0;

  /** Description:
      Unlocks the entrance.
  */
  virtual void unlock() = 0;

  /** Description:
      Locks the entrance being in read state.
      Remarks:
      To unlock protected area the calling thread may either call unlock() or unlockFromInside() to stay in read state.
  */
  virtual void lockFromInside() = 0;

  /** Description:
      Unlocks the entrance staying in read state.
  */
  virtual void unlockFromInside() = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class template for OdApcGateway object pointers.
*/
typedef OdSmartPtr<OdApcGateway> OdApcGatewayPtr;

/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class FIRSTDLL_EXPORT OdRxThreadPoolService : public OdRxModule {
public:
  ODRX_DECLARE_MEMBERS(OdRxThreadPoolService);

  /** Description:
      Returns number of logical CPUs installed on this machine.
  */
  virtual int numCPUs() const = 0;

  /** Description:
      Creates synchronized (single thread) queue.
      Remarks:
      Returned queue is processed by one thread at one moment.
  */
  virtual OdApcQueuePtr newSTQueue() = 0;

  /** Description:
      Creates mutiple thread processing queue.
  */
  virtual OdApcQueuePtr newMTQueue() = 0;

  /** Description:
      Creates APC gateway object.
  */
  virtual OdApcGatewayPtr newGateway() = 0;

  /** Description:
      Creates APC object pool object.
  */
  virtual OdApcObjectPoolPtr newObjectPool() = 0;
};

typedef OdSmartPtr<OdRxThreadPoolService> OdRxThreadPoolServicePtr;


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcQueueHelper : public OdSmartPtr<OdApcQueue> {
public:
  OdApcQueueHelper( ) {}
  OdApcQueueHelper( const OdApcQueue* pObject, OdRxObjMod m ) : OdSmartPtr<OdApcQueue>( pObject, m ) {}
  OdApcQueueHelper( const OdApcQueue* pObject ) : OdSmartPtr<OdApcQueue>( pObject ) {}
  OdApcQueueHelper( const OdRxObject* pObject ) : OdSmartPtr<OdApcQueue>( pObject ) {}
  OdApcQueueHelper( OdRxObject* pObject, OdRxObjMod m ) : OdSmartPtr<OdApcQueue>( pObject, m ) {}
  OdApcQueueHelper( const OdSmartPtr<OdApcQueue>& pObject ) : OdSmartPtr<OdApcQueue>( pObject ) {}
  OdApcQueueHelper( const OdRxObjectPtr& pObject ) : OdSmartPtr<OdApcQueue>( pObject ) {}
  OdApcQueueHelper( const OdBaseObjectPtr& pObject ) : OdSmartPtr<OdApcQueue>( pObject ) {}

  using OdSmartPtr<OdApcQueue>::operator =;

  void initST( OdRxThreadPoolService* pThreadPool ) {
    *this = pThreadPool ? pThreadPool->newSTQueue().get() : 0;
  }

  void initMT( OdRxThreadPoolService* pThreadPool ) {
    *this = pThreadPool ? pThreadPool->newMTQueue().get() : 0;
  }

  void call( OdApcAtom* pAction, OdRxObject* pParam = 0 ) {
    if( m_pObject ) {
      get()->addEntryPoint( pAction, pParam );
    }
    else {
      pAction->apcEntryPoint( pParam );
    }
  }

  void call( OdApcAtom* pAction, OdApcParamType param ) {
    if( m_pObject ) {
      get()->addEntryPoint( pAction, param );
    }
    else {
      pAction->apcEntryPoint( param );
    }
  }

  void setAtomPoolRef( OdApcObjectPool* pAtomPool ) {
    if( m_pObject ) {
      get()->setAtomPoolRef( pAtomPool );
    }
  }

  void wait() {
    if( m_pObject ) {
      get()->wait();
    }
  }
};


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcGatewayHelper : public OdSmartPtr<OdApcGateway> {
public:
  OdApcGatewayHelper( ) {}
  OdApcGatewayHelper( const OdApcGateway* pObject, OdRxObjMod m ) : OdSmartPtr<OdApcGateway>( pObject, m ) {}
  OdApcGatewayHelper( const OdApcGateway* pObject ) : OdSmartPtr<OdApcGateway>( pObject ) {}
  OdApcGatewayHelper( const OdRxObject* pObject ) : OdSmartPtr<OdApcGateway>( pObject ) {}
  OdApcGatewayHelper( OdRxObject* pObject, OdRxObjMod m ) : OdSmartPtr<OdApcGateway>( pObject, m ) {}
  OdApcGatewayHelper( const OdSmartPtr<OdApcGateway>& pObject ) : OdSmartPtr<OdApcGateway>( pObject ) {}
  OdApcGatewayHelper( const OdRxObjectPtr& pObject ) : OdSmartPtr<OdApcGateway>( pObject ) {}
  OdApcGatewayHelper( const OdBaseObjectPtr& pObject ) : OdSmartPtr<OdApcGateway>( pObject ) {}

  using OdSmartPtr<OdApcGateway>::operator =;

  void init( OdRxThreadPoolService* pThreadPool ) {
    *this = pThreadPool ? pThreadPool->newGateway().get() : 0;
  }

  void enter() {
    if( m_pObject ) {
      get()->enter();
    }
  }

  void leave() {
    if( m_pObject ) {
      get()->leave();
    }
  }

  void lock() {
    if( m_pObject ) {
      get()->lock();
    }
  }

  void unlock() {
    if( m_pObject ) {
      get()->unlock();
    }
  }

  void lockFromInside() {
    if( m_pObject ) {
      get()->lockFromInside();
    }
  }

  void unlockFromInside() {
    if( m_pObject ) {
      get()->unlockFromInside();
    }
  }
};


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdGatewayAutoPass {
public:
  OdGatewayAutoPass( OdApcGatewayHelper& lock ) : m_lock( lock ) { m_lock.enter(); }
  ~OdGatewayAutoPass() { m_lock.leave(); }
private:
  OdApcGatewayHelper& m_lock;
};


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdGatewayAutoLock {
public:
  OdGatewayAutoLock( OdApcGatewayHelper& lock ) : m_lock( lock ) { m_lock.lock(); }
  ~OdGatewayAutoLock() { m_lock.unlock(); }
private:
  OdApcGatewayHelper& m_lock;
};


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdGatewayAutoLockFromInside {
public:
  OdGatewayAutoLockFromInside( OdApcGatewayHelper& lock ) : m_lock( lock ) { m_lock.lockFromInside(); }
  ~OdGatewayAutoLockFromInside() { m_lock.unlockFromInside(); }
private:
  OdApcGatewayHelper& m_lock;
};

#include "OdArray.h"


/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
class OdApcQueueHelperArray : public OdArray<OdApcQueueHelper> {
public:
  void initST( int n, OdRxThreadPoolService* pTP ) {
    resize( n );
    if ( pTP ) {
      for( int i=0; i<n; ++i ) {
        setAt( i, pTP->newSTQueue() );
      }
    }
  }
  void wait() {
    size_type n = size();
    for( size_type i=0; i<n; ++i ) {
      at( i ).wait();
    }
  }
};

#include "StaticRxObject.h"

/** Description:
    Library: TD_Db
    {group:OdApc_Classes} 
*/
template< class It, class Fn >
class OdAsyncForEach : public OdStaticRxObject<OdApcAtom> {
  OdMutex                 m_mutex;
  It                      m_cur, m_last;
  Fn                      m_fn;

  bool next( It& cur ) {
    OdMutexAutoLock lock( m_mutex );
    if ( m_cur < m_last ) {
      cur = m_cur;
      ++m_cur;
      return true;
    }
    return false;
  }

  void apcEntryPoint( OdRxObject* ) {
    It cur;
    if( next( cur ) ) {
      do {
        m_fn( *cur );
      }
      while( next( cur ) );
    }
  }
public:
  void for_each( OdApcQueue* pQueue, It first, It last, Fn fn ) {
    unsigned long n = last-first;
    if( pQueue && n>1 ) {
      m_cur = first;
      m_last = last;
      m_fn = fn;

      unsigned long numCPUs = pQueue->framework().numCPUs();
      n = ( n < numCPUs ) ? n : numCPUs;
      while( n-- ) {
        pQueue->addEntryPoint( this );
      }
      pQueue->wait();
    }
    else {
      std::for_each( first, last, fn );
    }
  }

};

template< class It, class Fn >
void od_async_for_each( OdApcQueue* pQueue, It first, It last, Fn fn ) {
  ODA_ASSERT_ONCE( first <= last );
  if( first < last ) {
    OdAsyncForEach< It, Fn >().for_each( pQueue, first, last, fn );
  }
}

template< class TObject >
struct OdApcObjectPoolHelperDummyInitFn {
  void operator () ( TObject& ) const {
    // does nothing
  }
};

template< class TObject, class TInitFn = OdApcObjectPoolHelperDummyInitFn<TObject> >
class OdApcObjectPoolHelper : public OdArray<TObject>, public OdApcObjectPoolPtr {
public:
  void init( OdRxThreadPoolService* pTP, int n = 0, const TInitFn* pInitFn = 0 ) {
    if ( pTP ) {
      if( n==0 ) {
        n = pTP->numCPUs();
      }
      OdArray<TObject>::resize( n );
      (*(OdApcObjectPoolPtr*)this) = pTP->newObjectPool();
      while( --n ) {
        TObject& obj = OdArray<TObject>::at( n );
        if( pInitFn ) {
          (*pInitFn)( obj );
        }
        get()->put( &obj );
      }
    }
    else {
      OdArray<TObject>::resize( 1 );
      if( pInitFn ) {
        (*pInitFn)( OdArray<TObject>::first() );
      }
    }
  }

  TObject* take() {
    if( m_pObject ) {
      return static_cast<TObject*>( get()->take().get() );
    }
    return &OdArray<TObject>::first();
  }

  operator OdApcObjectPool* () { return get(); }
  operator const OdApcObjectPool* () const { return get(); }
};

#endif //_ODRXTHREADPOOLSERVICE_INCLUDED_
