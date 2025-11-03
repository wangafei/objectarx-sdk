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
#ifndef __ODGICHUNKALLOCATOR_H__
#define __ODGICHUNKALLOCATOR_H__

#include "../Gi/GiExport.h"
#include "../RxObjectImpl.h"

#include "../TD_PackPush.h"

/** Description:
    Speed up performance allocator.

    Library: TD_Gi
   {group:OdGi_Classes} 
*/
class ODGI_EXPORT ODRX_ABSTRACT OdGiChunkAllocator
{
  public:
    virtual void* alloc(size_t) = 0;
    virtual void* alloc(size_t, size_t) = 0;
    virtual void  release(void*) = 0;
    virtual void  release(void*, size_t) = 0;
    virtual ~OdGiChunkAllocator() {}
};

ODGI_EXPORT OdGiChunkAllocator* odgiGetChunkAllocator(OdInt32 id, bool bGet = true);

#define ODGI_USE_HEAP() \
protected: \
  static OdGiChunkAllocator* s_Allocator; \
public: \
  static void xInitHeapAllocator(OdGiChunkAllocator *p); \
  void* operator new(size_t); \
  void  operator delete(void*); 

#define ODGI_USE_HEAP_DEFINE(baseClass) \
  OdGiChunkAllocator* baseClass::s_Allocator = NULL; \
  void  baseClass::xInitHeapAllocator(OdGiChunkAllocator *p) { s_Allocator = p; } \
  void* baseClass::operator new(size_t size) { return s_Allocator->alloc(size); } \
  void  baseClass::operator delete(void* p)  { s_Allocator->release(p); }

enum OdGiHeapType
{
  HeapGsNode = 0,
  HeapGiMetafile = 1
};

#define ODGI_HEAP_ALLOCATOR_INIT(baseClass, id) \
  baseClass::xInitHeapAllocator(::odgiGetChunkAllocator(id))
#define ODGI_HEAP_ALLOCATOR_UNINIT(baseClass, id) \
  baseClass::xInitHeapAllocator(::odgiGetChunkAllocator(id, false));

#define ODGI_HEAP_OPERATORS() \
  void* operator new(size_t); \
  void  operator delete(void*); 


/** Description:

    Library: TD_Gi
   {group:OdGi_Classes} 
*/
template<class T, class TInterface = T>
class OdGiRxObjectReImpl : public OdRxObjectImpl<T, TInterface>
{
  /** Description:
      Assignment operator prohibited.
  */
  OdGiRxObjectReImpl& operator = (const OdGiRxObjectReImpl&) { return *this; }

  protected:
    void* operator new (size_t size) { return T::operator new (size); }
    void  operator delete (void* p) { T::operator delete (p); }

  public:
    /** Description:
        Creates an instance of OdGiRxObjectReImpl<T, TInterface>
        and returns SmartPointer to it.
    */
    static OdSmartPtr<TInterface> createObject()
    {
      return OdSmartPtr<TInterface>(static_cast<TInterface*>(new OdGiRxObjectReImpl<T, TInterface>), kOdRxObjAttach);
    }
};

#define GIRXREIMPL_CONSTR(ClassName) OdGiRxObjectReImpl<ClassName>::createObject()

#include "../TD_PackPop.h"

#endif //#ifndef __ODGICHUNKALLOCATOR_H__
