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




#ifndef _ODASMARTPOINTER_INCLUDED_
#define _ODASMARTPOINTER_INCLUDED_

#include "TD_PackPush.h"
#include "Error_NotThatKindOfClass.h"

class OdRxObject;
#include "RxObject.h"

/** Description:
    {filename:OdBaseObjectPtr_Definition}
    {group:Other_Classes}

    This class is the base class for typified smart pointers.

    Library:
    TD_Db
    
    Remarks:
    Smart pointers relieve the programmer of having to determine when objects are no longer needed, or having to delete
    them at that time.

    Each object referenced by a SmartPointer (henceforth 'referenced object') 
    maintains a reference count; i.e., how many SmartPointers are referencing it.
    When the reference count reaches zero, the referenced object is deleted.

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 
*/
class FIRSTDLL_EXPORT OdBaseObjectPtr
{
protected:
  OdBaseObjectPtr() : m_pObject(0) {}
  
  OdRxObject* m_pObject;
  
public:
  /** Description:
    Returns the raw pointer to the referenced object. 
    
    Remarks:
    This class maintains the reference to the referenced object. 
    The reference counter of the referenced object is not changed.
  */
  OdRxObject* get() const {return m_pObject;}
  
  /** Description:
     Returns true if and only if the smart pointer stores a NULL.
  */
  bool isNull() const { return m_pObject == 0; }
	friend class OdRxClassProtocolExtImpl;
};

/** Description:
    {filename:OdSmartPtr_Definition}
    {group:Other_Classes}

    This template class provides the typified implementation of smart pointers for instances of classes derived from the OdRxObject class.

    Remarks:
    SmartPointers relieve the programmer of having to determine when objects are no longer needed, or having to delete them
    them at that time.

    Each object referenced by a SmartPointer (henceforth 'referenced object') 
    maintains a reference count; i.e., how many SmartPointers are referencing it.
    When the reference count reaches zero, the referenced object is deleted.

    Library:
    TD_Db

    Samples:
    {hyperlink:Example of Assigning Smart Pointers|smart_pointers_example_refexchange.html}

    {hyperlink:Example of a Typified Smart Pointer|smart_pointers_example_typified.html}

    See Also:
    {hyperlink:Overview of Smart Pointer Classes|smart_pointers_overview.html} 

    The OdRxObjectPtr class
*/
template <class T> class OdSmartPtr : public OdBaseObjectPtr
{
public:
  /** Description:
    Increments the reference counter of the referenced object.
  */
  void internalAddRef()
  {
    if(m_pObject)
      m_pObject->addRef();
  }
  
  /** Description:
    Assigns the pointer of specified object to the smart pointer.  
      
    Remarks:
    The reference counter of the specified object is incremented.

    If this SmartPointer is currently referencing another object, that object 
    is released prior to the assignment.  

    Arguments:
    pObject (I) Pointer to the specified object to be assigned.
  */
  void assign(const T* pObject)
  {
    release();
    m_pObject = const_cast<T*>(pObject);
    internalAddRef();
  }
  
  /** Description:
    Performs a "safe" assignment of the specified object to this SmartPointer object. 
      
    Arguments:
    pObject (I) Pointer to the object to be assigned.

    Throws:
    eNotThatKindOfClass if not successful. 
  */
  void internalQueryX(const OdRxObject* pObject)
  {
    if(pObject)
    {
      OdRxObject* pX = pObject->queryX(T::desc());
      if(pX)
        m_pObject = pX;
      else
        throw OdError_NotThatKindOfClass(pObject->isA(), T::desc());
    }
  }
  
  void assign(const OdRxObject* pObject)
  {
    release();
    internalQueryX(pObject);
  }
  
  // Note: Using of SmartPtr<T> as bool expression produce ambiguous call with some compilers.
  // Use isNull() method instead.

  /** Description:
    Declared private to prevent use.
    Note: 
    Use of SmartPtr<T> as a bool expression produces ambiguous calls with some compilers. Use isNull() instead. 
  */
  bool operator !() const { ODA_FAIL(); return false; }
  
  /** Description:
    Declared private to prevent use.
    Note: 
    Use of SmartPtr<T> as a bool expression produces ambiguous calls with some compilers. Use isNull() instead. 
  */
  operator bool() const { ODA_FAIL(); return false; }

  /** Description:
    Declared private to prevent use.
    Note: 
    Use of SmartPtr<T> as a bool expression produces ambiguous calls with some compilers. Use isNull() instead. 
  */
  operator bool() { ODA_FAIL(); return false; }
  
public:
  /** Description:
    Constructors for the typified smart pointer.

    Arguments:
    pObject (I) Pointer to the object to be assigned to the new SmartPointer object.

    Remarks:
    If pObject is specified, the smart pointer is set to the address of the specified object. If pObject is not specified, the smart pointer is set to a NULL.
    
    Remarks:
    If OdRxObjMod or const OdBaseObjectPtr& are specified, the reference counter of the specified object 
    is *not* incremented. 
  */
  OdSmartPtr()
  {
  }

  OdSmartPtr(const T* pObject, OdRxObjMod)
  {
    m_pObject = const_cast<T*>(pObject);
  }
  
  OdSmartPtr(const T* pObject)
  {
    m_pObject = const_cast<T*>(pObject);
    internalAddRef();
  }
  
  OdSmartPtr(const OdRxObject* pObject)
  {
    internalQueryX(pObject);
  }

  OdSmartPtr(OdRxObject* pObject, OdRxObjMod)
  {
    internalQueryX(pObject);
    if(pObject)
      pObject->release();
  }
  
  OdSmartPtr(const OdSmartPtr& pObject)
  {
    m_pObject = const_cast<T*>(pObject.get());
    internalAddRef();
  }

  OdSmartPtr(const OdRxObjectPtr& pObject)
  {
    internalQueryX(pObject.get());
  }

  OdSmartPtr(const OdBaseObjectPtr& pObject)
  {
    internalQueryX(pObject.get());
  }

  /** Description:
    Assigns the pointer of the specifed object to the smart pointer without incrementing its reference counter.  
      
    Arguments:
    pObject (I) Pointer to the specifed object to be assigned.

    Remarks:
    The reference counter of the specified object is not incremented.

    If the smart pointer is currently referencing to another object, that object 
    is released prior to the assignment.

    Samples:
    {hyperlink:Example of a Typified Smart Pointer|smart_pointers_example_typified.html}
  */
  void attach(const T* pObject)
  {
    release();
    m_pObject = const_cast<T*>(pObject);
  }
  
  void attach(OdRxObject* pObject)
  {
    release();
    internalQueryX(pObject);
    if(pObject)
      pObject->release();
  }
  
  /** Description:
    Destructor for the typified smart pointer.
 
    Remarks:
    Decrements the reference counter of the referenced object. When the reference count reaches zero, the referenced object is deleted.
  */
  ~OdSmartPtr()
  {
    release();
  }
  
  /** Description:
    Releases the smart pointer reference to the referenced object. 
    
    Remarks:
    Decrements the reference counter of the referenced object.  When the reference count reaches zero, 
    the referenced object is deleted. Smart pointer is set to a NULL.

    Samples:
    {hyperlink:Example of a Typified Smart Pointer|smart_pointers_example_typified.html}
  */
  void release()
  {
    if (m_pObject)
    {
      m_pObject->release();
      m_pObject = 0;
    }
  }
  
  /** Description:
    Releases the smart pointer reference to the referenced object without decrementing of the reference counter. 
      
    Remarks:
    Returns the raw pointer to the referenced object. The reference counter is not modified 
    for the referenced object. Smart pointer is set to a NULL.
 
    Samples:
    {hyperlink:Example of a Typified Smart Pointer|smart_pointers_example_typified.html}
 */
  T* detach()
  {
    T* pRes = static_cast<T*>(m_pObject);
    m_pObject = 0;
    return pRes;
  }
  
  /**
    Remarks:
    The assignment operator increments the reference counter of the referenced object and saves its address in the smart pointer.
     If the smart pointer is currently referencing to another object, that assignment operator releases the referenced object prior 
     to the assignment.  

    Samples:
    {hyperlink:Example of a Typified Smart Pointer|smart_pointers_example_typified.html}
  */
  OdSmartPtr& operator = (const OdSmartPtr& pObject)
  {
    assign(pObject);
    return *this;
  }
    
  OdSmartPtr& operator = (const OdBaseObjectPtr& pObject)
  {
    assign(pObject.get());
    return *this;
  }
  
  OdSmartPtr& operator = (const T* pObject)
  {
    assign(pObject);
    return *this;
  }
  
  /** Description:
    Returns the raw pointer to the referenced object.

    Remarks:
    The smart pointer maintains its reference to the referenced object. 
    The reference counter of the referenced object is not changed.
 
    Samples:
    {hyperlink:Example of a Typified Smart Pointer|smart_pointers_example_typified.html}
 */
  const T* get() const
  {
    return static_cast<const T*>(m_pObject);
  }
  
  T* get()
  {
    return static_cast<T*>(m_pObject);
  }
  
  /** Description:
    Returns the raw pointer to the referenced object.
      
    Remarks:
    The reference counter of the referenced object is not changed.
  */
  T* operator ->()
  {
    return static_cast<T*>(m_pObject);
  }
  
  const T* operator ->() const
  {
    return static_cast<const T*>(m_pObject);
  }
  
#ifdef ODA_GCC_2_95
  /** Description:
    Returns the raw pointrer to the referenced object.
    
    Remarks:
    The class maintains the reference to the referenced object.
    The reference counter of the referenced object is not changed.
  */
  operator T*() const
  {
    return const_cast<T*>(static_cast<const T*>(m_pObject));
  }
  
#else
  /** Description:
    Returns the raw pointer the  referenced object.
    
    Remarks:
    This SmartPointer maintains its reference to the referenced object.
    
    The reference counter of the referenced object is not changed.
  */
  operator T*()
  {
    return static_cast<T*>(m_pObject);
  }
  
  operator const T*() const
  {
    return static_cast<const T*>(m_pObject);
  }

#endif
    
  bool operator==(const void* pObject) const
  {
    return (m_pObject==pObject);
  }

  bool operator==(const OdSmartPtr& pObject) const
  {
    return operator==((void*)pObject.get());
  }
  
  bool operator!=(const void* pObject) const
  {
    return (m_pObject!=pObject);
  }

  bool operator!=(const OdSmartPtr& pObject) const
  {
    return operator!=((void*)pObject.get());
  }
};


#include "TD_PackPop.h"

#endif //_ODASMARTPOINTER_INCLUDED_
