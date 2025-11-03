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




#ifndef ODARRAY_H_INCLUDED
#define ODARRAY_H_INCLUDED

#include <new>

#include "TD_PackPush.h"

#include "OdArrayPreDef.h"
#include "OdHeap.h"
#include "OdMutex.h"
#include "OdError.h"
#include "RxSystemServices.h"

/** Description:
    This template class implements memory allocation functions within Teigha.
    
    Library:
    TD_Db
    
    {group:Other_Classes}
*/
template <class T> class OdMemoryAllocator
{
public:
	typedef OdSize size_type;
  /** Description:
    This function copies the specified number of elements from *source* to *destination*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    numElements (I) Number of elements.
    
    Note:
    If the *source* and *destination* regions overlap, the behavior of this function is undefined. Use move() to handle overlapping regions.
  */
  static inline void reallocateArray(
    T* pDestination, 
    const T* pSource, 
    size_type numElements)
  {
    memcpy(pDestination, pSource, numElements * sizeof(T));
  }
  
  /** Description:
    This function copies the specified number of elements from *source* to *destination*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    numElements (I) Number of elements.
    
    Remarks:
    If the *source* and *destination* regions overlap, move copies the overlapping region before it is overwritten.
    
    Note:
    Use copy() to handle non-overlapping regions. 
  */
  static inline void move(
    T* pDestination, 
    const T* pSource, 
    size_type numElements)
  {
    memmove(pDestination, pSource, numElements * sizeof(T));
  }
  /** Description:
    This function constructs an element.
    
    Arguments:
    pElement (O) Receives the element. 
    value (I) Value for the element.
  */
  static inline void construct(
    T* pElement, 
    const T& value = T())
  {
    *pElement = value;
  }

  /** Description:
    This function constructs an array of elements.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    value (I) Value for the elements.
    numElements (I) Number of elements.
    
    Note:
    When called with two arguments, this function does nothing but return.
  */
  static inline void constructn(
    T* pDestination, 
    size_type numElements, 
    const T& value)
  {
    while(numElements--)
    {
      pDestination[numElements] = value;
    }
  }
  
  static inline void constructn(
    T* pDestination, 
    const T* pSource, 
    size_type numElements)
  {
    reallocateArray(pDestination, pSource, numElements);
  }
  static inline void constructn(
    T*, 
    size_type)
  {
    // DOES NOTHING
  }
  /** Description:
    Destroys the specified element or elements.
    
    Note:
    This function does nothing but return.
  */
  static inline void destroy(
    T*)
  {
    // DOES NOTHING
  }
  static inline void destroy(
    T*, 
    size_type )
  {
    // DOES NOTHING
  }
  /** Description:
     Returns true if and only if odrxRealloc can be used to resize an array.
 
     Note:
     This function always returns true.
  */
  static inline bool useRealloc()
  {
    return true;
  }
};


/** Description:
    This template class implements object allocation functions within Teigha.
    
    Remarks:
    This class is for objects that must be copied with the assignment operator.
    For objects that can be copied with memcpy(), see OdPlainObjectsAllocator.
    
    Library:
    TD_Db

    {group:Other_Classes}
*/
template <class T> class OdObjectsAllocator
{
public:
  typedef OdSize size_type;
  
  /** Description:
    This function copies the specified number of *objects* from *source* to *destination*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    numObjects (I) Number of *objects*.
    
    Note:
    If the *source* and *destination* regions overlap, the behavior of this function is undefined. Use move() to handle overlapping regions.
  */
  static inline void reallocateArray(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      *pDestination = *pSource;
      pDestination++;
      pSource++;
    }
  }

  /** Description:
    This function copies the specified number of *objects* from *source* to *destination*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    numObjects (I) Number of *objects*.
    
    Remarks:
    If the *source* and *destination* regions overlap, move copies the overlapping region before it is overwritten.
    
    Note:
    Use copy() to handle non-overlapping regions. 
  */
  static inline void move(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    if (pDestination <= pSource || pDestination >= pSource + numObjects)
    {
      reallocateArray(pDestination, pSource, numObjects);
    }
    else
    {
      while(numObjects--)
      {
        pDestination[numObjects] = pSource[numObjects];
      }
    }
  }
  /** Description
    This function constructs an object.
    
    Arguments:
    pObject (O) Receives the object. 
    value (I) Value for the object.
  */
  static inline void construct(
    T* pObject)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T;
  }
  static inline void construct(
     T* pObject, 
     const T& value)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T(value);
  }
  /** Description:
    This function constructs an array of *objects*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    value (I) Value for the *objects*.
    numObjects (I) Number of *objects*.
    
  */
  static inline void constructn(
    T* pDestination, 
    size_type numObjects, 
    const T& value)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects, value);
    }
  }
  static inline void constructn(
    T* pDestination, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects);
    }
  }
  static inline void constructn(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination, *pSource);
      pDestination++;
      pSource++;
    }
  }
  /** Description:
    Destroys the specified object or *objects*.
    Arguments:
    pObject (I) Pointer to the object. 
    objects (I) Array of *objects*.
    numObjects (I) Number of *objects*.
  */
  static inline void destroy(
    T* pObject)
  {
    pObject->~T();
    pObject = 0;
  }
  static inline void destroy(
    T* objects, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      destroy(objects + numObjects);
    }
  }
  /** Description:
     Returns true if and only if odrxRealloc can be used to resize an array.
     
     Note:
     This function always returns false.
  */
  static inline bool useRealloc()
  {
    return false;
  }
};
/** Description:
    This template class implements object allocation functions for objects within Teigha.
    
    Remarks:
    This class is for objects that can copied with memcpy() (plain objects). For objects that must be copied with the assignment operator,
    see OdObjectsAllocator.
    
    Library:
    TD_Db

    {group:Other_Classes}
*/
template <class T> class OdPlainObjectsAllocator
{
public:
  typedef OdSize size_type;
  
  /** Description:
    This function copies the specified number of *objects* from *source* to *destination*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    numObjects (I) Number of *objects*.
    
    Note:
    If the *source* and *destination* regions overlap, the behavior of this function is undefined. Use move() to handle overlapping regions.
  */
  static inline void reallocateArray(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    memcpy(pDestination, pSource, numObjects * sizeof(T));
  }
  
  /** Description:
    This function copies the specified number of *objects* from *source* to *destination*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    numObjects (I) Number of *objects*.
    
    Remarks:
    If the *source* and *destination* regions overlap, move copies the overlapping region before it is overwritten.
    
    Note:
    Use copy() to handle non-overlapping regions. 
  */
  static inline void move(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    memmove(pDestination, pSource, numObjects * sizeof(T));
  }
  
  /** Description
    This function constructs an object.
    
    Arguments:
    pObject (O) Receives the object. 
    value (I) Value for the object.
  */
  static inline void construct(
    T* pObject)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T;
  }
  static inline void construct(
    T* pObject, 
    const T& value)
  {
#ifdef new
#undef new
#endif
    ::new (pObject) T(value);
  }
  
  /** Description:
    This function constructs an array of *objects*.
    
    Arguments:
    pDestination (I) Pointer to the *destination*.
    pSource (I) Pointer to the *source*.
    value (I) Value for the *objects*.
    numObjects (I) Number of *objects*.
    
  */
  static inline void constructn(
    T* pDestination, 
    size_type numObjects, 
    const T& value)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects, value);
    }
  }
  static inline void constructn(
    T* pDestination, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination+numObjects);
    }
  }
  static inline void constructn(
    T* pDestination, 
    const T* pSource, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      construct(pDestination, *pSource);
      pDestination++;
      pSource++;
    }
  }
  
  /** Description:
    Destroys the specified object or *objects*.
    Arguments:
    pObject (I) Pointer to the object. 
    objects (I) Array of *objects*.
    numObjects (I) Number of *objects*.
  */
  static inline void destroy(
    T* pObject)
  {
    pObject->~T();
    pObject = 0;
  }
  static inline void destroy(
    T* objects, 
    size_type numObjects)
  {
    while(numObjects--)
    {
      destroy(objects + numObjects);
    }
  }
  /** Description:
     Returns true if and only if odrxRealloc can be used to resize an array.
     
     Note:
     This function always returns true.
  */
  static inline bool useRealloc()
  {
    return true;
  }
};

/** Description:

    {group:Structs}
*/
struct FIRSTDLL_EXPORT OdArrayBuffer
{
  typedef OdSize size_type;

  mutable int		m_nRefCounter;
  int               m_nGrowBy;
  size_type         m_nAllocated;
  size_type         m_nLength;

  FIRSTDLL_EXPORT_STATIC static OdArrayBuffer g_empty_array_buffer;
};



/** Description:
    This template class implements dynamic Array *objects* within Teigha.

    Remarks:
    Methods are provided to access Array elements via both array indices and array pointers (iterators).

    Some definitions are in order:
    
    1. Logical Length or Size -- The number of entries in the array. Initially zero.
    2. Physical Length -- The maximum Logical Length of the array before it automatically grows.
    3. Grow Length -- The number of entries by which the Physical Length will grow as required.
    
    Library:
    TD_Db
    
    {group:Other_Classes}
*/
template <class T, class A> class OdArray
{
public:
  typedef typename A::size_type size_type;
  typedef T* iterator;
  typedef const T* const_iterator;
private:
  struct Buffer : OdArrayBuffer
  {
    T* data() const { return (T*)(this+1); }

    static Buffer* allocate(size_type nLength2Allocate, int nGrowBy)
    {
      size_type nBytes2Allocate = sizeof(Buffer) + nLength2Allocate * sizeof(T);
      ODA_ASSERT(nBytes2Allocate > nLength2Allocate); // size_type overflow
      if(nBytes2Allocate > nLength2Allocate)
      {
        Buffer* pBuffer = (Buffer*)::odrxAlloc(nBytes2Allocate);
        if (pBuffer)
        {
          pBuffer->m_nRefCounter = 1;
          pBuffer->m_nGrowBy     = nGrowBy;
          pBuffer->m_nAllocated  = nLength2Allocate;
          pBuffer->m_nLength     = 0;
          return pBuffer;
        }
      }
      throw OdError(Oda::eOutOfMemory);
    }
    static Buffer* _default()
    {
      return (Buffer*)&g_empty_array_buffer;
    }
    void release()
    {
      ODA_ASSERT(m_nRefCounter);
      if((--m_nRefCounter)==0 && this != _default())
      {
        A::destroy(data(), m_nLength);
        ::odrxFree(this);
      }
    }
    void addref() const { ++m_nRefCounter; }
  };
  class reallocator
  {
    Buffer* m_pBuffer;
    bool _may_use_realloc;
  public:
    inline reallocator( bool may_use_realloc = false ) : _may_use_realloc(may_use_realloc) 
    {
      if ( !_may_use_realloc )
      {
        m_pBuffer = Buffer::_default();
        m_pBuffer->addref(); 
      }
    }
    inline void reallocate(OdArray* pArray, size_type nNewLen )
    {
      if(!pArray->referenced())
      {
        if(nNewLen > pArray->physicalLength())
        {
          if ( !_may_use_realloc )
          {
            m_pBuffer->release();
            m_pBuffer = pArray->buffer();
            m_pBuffer->addref(); // save buffer to ensure copy from itself would work (e.g insertAt)
          }
          pArray->copy_buffer(nNewLen, _may_use_realloc);
        }
      }
      else
      {
        pArray->copy_buffer(nNewLen);
      }
    }
    inline ~reallocator() 
    {
      if ( !_may_use_realloc ) m_pBuffer->release();
    }
  };
  friend class reallocator;
  const_iterator begin_const() const { return begin(); }
  iterator begin_non_const() { return begin(); }
  const_iterator end_const() { return end(); }
  iterator end_non_const() { return end(); }
  void copy_before_write(size_type len, bool may_use_realloc = false )
  {
    if( referenced() )
      copy_buffer(len);
    else if ( len > physicalLength() )
      copy_buffer( len, may_use_realloc );
  }
  void copy_if_referenced() { if(referenced()) { copy_buffer(physicalLength()); } }
  void copy_buffer( size_type len, bool may_use_realloc = false, bool force_size = false )
  {
    Buffer* pOldBuffer = buffer();
    int nGrowBy = pOldBuffer->m_nGrowBy;
    size_type len2 = len;
    if ( !force_size )
    {
      if(nGrowBy > 0)
      {
        if(len2>pOldBuffer->m_nAllocated && len2>nGrowBy)
          len2 *= 2;
        else
          len2 += nGrowBy;
        len2 = ((--len2) / nGrowBy) * nGrowBy;
      }
      else
      {
        len2 = pOldBuffer->m_nLength;
        len2 = len2 + -nGrowBy * len2 / 100;
        if(len2 < len)
        {
          len2 = len;
        }
      }
    }
    if ( may_use_realloc && A::useRealloc() && !empty() )
    {
      Buffer* pNewBuffer = reinterpret_cast<Buffer*>( ::odrxRealloc( 
        pOldBuffer, len2 * sizeof(T) + sizeof(Buffer), pOldBuffer->m_nAllocated * sizeof(T) + sizeof(Buffer) ) );
      pNewBuffer->m_nAllocated = len2;
      pNewBuffer->m_nLength = odmin(pNewBuffer->m_nLength, len);
      m_pData = pNewBuffer->data();
    }
    else 
    {
      Buffer* pNewBuffer = Buffer::allocate(len2, nGrowBy);
      len = odmin(pOldBuffer->m_nLength, len);
      A::constructn(pNewBuffer->data(), pOldBuffer->data(), len);
      pNewBuffer->m_nLength = len;
      m_pData = pNewBuffer->data();
      pOldBuffer->release();
    }
  }
public:
  // STL-like interface
  
  /** Description:
    Returns an *iterator* that references the *first* element in this Array object.
  */
  iterator begin() 
  { 
    if(!empty()) 
    { 
      copy_if_referenced(); 
      return data(); 
    } 
    return 0;
  }
  const_iterator begin() const 
  { 
    if(!empty()) 
    { 
      return data(); 
    } 
    return 0; 
  }

  /** Description:
    Returns an *iterator* that references the location after the *last* element in this Array object.
  */
  iterator end() 
  { 
    if(!empty()) 
    { 
      copy_if_referenced(); 
      return data() + length(); 
    } 
    return 0; 
  }
  const_iterator end() const 
  { 
    if(!empty()) 
    { 
      return data() + length(); 
    } 
    return 0; 
  }
  
  /** Description:
    Inserts an element, number of elements, or range of elements, into this Array object. 
    
    Arguments:
    before (I) Position where *first* element is to be inserted.
    first (I) Position of *first* element to be inserted.
    afterLast (I) Position of *first* element after the *last* element to be inserted.
    
    Remarks:
    The range of elements may be from another Array object.
  */
  void insert(
    iterator before, 
    const_iterator first, 
    const_iterator afterLast)
  {
    size_type len = length();
    size_type index = (size_type)(before - begin_const());
    if(index <= len && afterLast>=first)
    {
      if(afterLast > first)
      {
        size_type num2copy = (size_type)(afterLast - first);
        reallocator r( first < begin() || first >= end() );
        r.reallocate(this, len + num2copy);
        A::constructn(m_pData + len, first, num2copy);
        buffer()->m_nLength = len + num2copy;
        T* pDestination = m_pData + index;
        if(index != len)
        {
          A::move(pDestination + num2copy, pDestination, len - index);
        }
        A::reallocateArray(pDestination, first, (size_type)(afterLast - first));
      }
    }
    else
    {
    }
  }
  /** Description:
    Specifies the logical *length* for this Array object.
    Arguments:
    logicalLength (I) Logical *length*.
    value (I) Value for the elements added to obtain the new logical length.
  */
  void resize( 
    size_type logicalLength, 
    const T& value )
  {
    if (logicalLength < 0)
      return;

    size_type len = length();
    int d = logicalLength - len;
    if ( d > 0 )
    {
      reallocator r( m_pData > &value || &value > (m_pData + len) );
      r.reallocate(this, logicalLength);
      A::constructn(m_pData + len, d, value);
    }
    else if ( d < 0 )
    {
      d=-d;
      if(!referenced())
      {
        A::destroy(m_pData + logicalLength, d);
      }
      else
      {
        copy_buffer(logicalLength);
      }
    }
    buffer()->m_nLength = logicalLength;
  }
  
  void resize( 
    size_type logicalLength )
  {
    if (logicalLength < 0)
      return;

    size_type len = length();
    int d = logicalLength - len;
    if ( d > 0 )
    {
      copy_before_write( len + d, true );
      A::constructn(m_pData + len, d);
    }
    else if ( d < 0 )
    {
      d = -d;
      if ( !referenced() )
      {
        A::destroy( m_pData + logicalLength, d );
      }
      else
      {
        copy_buffer(logicalLength);
      }
    }
    buffer()->m_nLength = logicalLength;
  }
  
  /** Description:
    Returns the logical *length* of this Array object.
  */
  size_type size() const 
  { 
    return buffer()->m_nLength; 
  }

  /** Description:
    Returns true if and only if this Array is *empty*.
  */
  bool empty() const 
  { 
    return size() == 0; 
  }
  
  /** Description:
    Returns the physical *length* of this Array object.
  */
  size_type capacity() const 
  { 
    return buffer()->m_nAllocated; 
  }

  /** Description:
    Sets the physical *length* of this Array object to the specified
    *reserve* *length* if the *reserve* *length* is greater than its physical *length*.

    Arguments:
    reserveLength (I) Minimum physical *length*.
  */
  void reserve(
    size_type reserveLength) 
  { 
    if(physicalLength() < reserveLength) 
    { 
      setPhysicalLength(reserveLength); 
    } 
  }

  /** Description:
    Assigns the specified range of elements to this Array object.

    Arguments:
    first (I) Position of *first* element to be assigned.
    afterLast (I) Position of *first* element after the *last* element to be assigned.
    
    Remarks:
    After this Array object is cleared, this function assigns the specified range of elements from
    another Array object.  
  */
  void assign(
    const_iterator first, 
    const_iterator afterLast)
  { 
    erase(begin_non_const(), end_non_const()); 
    insert(begin_non_const(), first, afterLast); 
  }
  
  /** Description:
    Removes the specified element or range of elements from this Array object.

    Arguments:
    first (I) Position of *first* element to be assigned.
    afterLast (I) Position of *first* element after the *last* element to be assigned.
  */
  iterator erase(
    iterator first, 
    iterator afterLast)
  {
    size_type i = (size_type)(first - begin_const());
    if(first != afterLast)
    {
      removeSubArray(i, (size_type)(afterLast-begin_const()-1));
    }
    return begin_non_const()+i;
  }
  /**
    Arguments:
    where (I) Element to *remove*.
  */
  iterator erase(
    iterator where)
  {
    size_type i = (size_type) (where - begin_const());
    removeAt(i);
    return begin_non_const()+i;
  }
  /** Description:
    Removes all elements from this Array object.
  */
  void clear() { erase(begin_non_const(), end_non_const()); }

  /** Description:
  Removes all elements from this Array object.
  */
  OdArray& removeAll() { erase(begin_non_const(), end_non_const()); return *this; }

  /** Description:
    Appends an element to the *end* of this Array object.
  */
  void push_back(
    const T& value) 
  { 
    insertAt(length(), value); 
  }
  
  /**
    Arguments:
    numElements (I) Number of elements to insert.
    value (I) Value to insert.
  */
  iterator insert(
    iterator before, 
    size_type numElements, 
    const T& value)
  {
    size_type len = length();
    size_type index = (size_type)(before - begin_const());
    reallocator r( m_pData > &value || &value > (m_pData + len) );
    r.reallocate(this, len + numElements);
    A::constructn(m_pData + len, numElements, value);
    buffer()->m_nLength = len + numElements;
    T* pData = data();
    pData += index;
    if(index != len)
    {
      A::move(pData + numElements, pData, len - index);
    }
    while(numElements--)
    {
      pData[numElements] = value;
    }
    return begin_non_const()+index;
  }
  
  iterator insert(
    iterator before, 
    const T& value = T())
  {
    size_type index = (size_type)(before - begin_const());
    insertAt(index, value);
    return (begin_non_const() + index);
  }  

  /** Description:
    Returns true if and only if this Array object *contains* ths specified *value*.
    
    Arguments:
    value (I) Value for which to search.
    start (I) Starting *index* of search.
  */
  bool contains(
    const T& value, 
    size_type start = 0) const
  { 
    size_type dummy; 
    return find(value, dummy, start); 
  }

  /** Description:
    Returns the number of elements in this Array object.
  */
  size_type length() const 
  { 
    return buffer()->m_nLength; 
  }
  
  /** Description:
    Returns true if and only if this Array is *empty*.
  */
  bool isEmpty() const 
  { 
    return length() == 0; 
  }
  
  /** Description:
    Returns the logical *length* of this Array object.
  */
  size_type logicalLength() const 
  { 
    return length(); 
  }
  
  /** Description:
    Returns the physical *length* of this Array object.
  */
  size_type physicalLength() const 
  { 
    return buffer()->m_nAllocated; 
  }
  
  /** Description:
    Returns the grow *length* of this Array object.
  */
  int growLength() const 
  { 
    return buffer()->m_nGrowBy; 
  }
  
  /** Description:
    Returns the data buffer of this Array object. 
  */
  const T* asArrayPtr() const 
  { 
    return data(); 
  }

  /** Description:
    Returns the data buffer of this Array object. 
  */
  const T* getPtr() const 
  { 
    return data(); 
  }

  T* asArrayPtr() 
  { 
    copy_if_referenced(); 
    return data(); 
  }
  
  /** Remarks:
    For convenient access to the *data*.
  */
  const T& operator [](
    size_type index) const 
  { 
    ODA_ASSERT(index >= 0 && index < length());
    return m_pData[index]; 
  }
  T& operator [](
    size_type index) 
  { 
    ODA_ASSERT(index >= 0 && index < length());
    copy_if_referenced(); 
    return m_pData[index]; 
  }

  /** Description:
    Returns the element of this Array object *at* the specified *index*.
    Arguments:
    arrayIndex (I) Array *index*. 
  */
  T& at(
    size_type arrayIndex) 
  { 
    ODA_ASSERT(arrayIndex >= 0 && arrayIndex < length());
    copy_if_referenced(); 
    return *(data() + arrayIndex); 
  }
  const T& at(size_type arrayIndex) const 
  { 
    ODA_ASSERT(arrayIndex >= 0 && arrayIndex < length());
    return *(data() + arrayIndex); 
  }
  
  /** Description:
    Sets the element of this Array object *at* the specified *index*.
    Arguments:
    arrayIndex (I) Array *index*.
    value (I) Value. 
  */
  OdArray& setAt(
    size_type arrayIndex, 
    const T& value)
  { 
    ODA_ASSERT(arrayIndex >= 0 && arrayIndex < length());
    copy_if_referenced(); 
    m_pData[arrayIndex] = value; 
    return *this; 
  }

  /** Description:
    Returns the element of this Array object *at* the specified position.
    Arguments:
    arrayIndex (I) Array *index*. 
  */
  const T& getAt(
    size_type arrayIndex) const 
  { 
    ODA_ASSERT(arrayIndex >= 0 && arrayIndex < length());
    return *(data() + arrayIndex); 
  }
  
  /** Description:
    Returns the *first* element of this Array object.
  */
  T& first() 
  { 
    return *begin(); 
  }
  const T& first() const 
  { 
    return *begin(); 
  }
  
  /** Description:
    Returns the *last* element of this Array object.
  */
  T& last() 
  { 
    return at(length() - 1); 
  }
  const T& last() const 
  { 
    return at(length() - 1); 
  }
  
  size_type append(
    const T& value) 
  { 
    insertAt(length(), value); 
    return length() - 1; 
  }
  
  iterator append() 
  { 
    size_type i = append(T()); 
    return begin_non_const() + i;
  }
  
  /** Description:
    Removes the *first* element in this Array object.
  */
  OdArray& removeFirst() 
  { 
    return removeAt(0); 
  }
  
  /** Description:
    Removes the *last* element in this Array object.
  */
  OdArray& removeLast() 
  { 
    return removeAt(length() - 1); 
  }
  
  /** Description:
    Sets the grow *length* of this Array object.
    Arguments:
    growLength (I) Grow *length*. 
  */
  OdArray& setGrowLength(
    int growLength)
  {
    if (growLength != 0)
    {
      copy_if_referenced();
      buffer()->m_nGrowBy = growLength;
    }
    else
    {
      ODA_FAIL();
    }
    return *this;
  }

  /**
    Arguments:
    physicalLength (I) Initial physical *length*.
    growLength (I) Initial grow *length*.
  */
  OdArray(
    size_type physicalLength, 
    int growLength = 8) : m_pData(0)
  {
    if (growLength == 0)
    {
      growLength = 8;
    }
    m_pData = Buffer::allocate(physicalLength, growLength)->data();
  }
  
  OdArray() : m_pData(Buffer::_default()->data()) 
  { 
    buffer()->addref(); 
  }
  
  OdArray(const OdArray& source) : m_pData((T*)source.data()) 
  { 
    buffer()->addref(); 
  }
  
  ~OdArray() 
  { 
    buffer()->release(); 
  }
  
  OdArray& operator =(
    const OdArray& source)
  {
    source.buffer()->addref();
    buffer()->release();
    m_pData = source.m_pData;
    return *this;
  }
  
  bool operator ==(
    const OdArray& array) const
  {
    if(length() == array.length())
    {
      for(size_type i = 0; i < length(); i++)
      {
        if(at(i) != array[i])
        {
          return false;
        }
      }
      return true;
    }
    return false;
  }
  
  /** Description:
    Sets all the elements in this Array object to the specified *value*.
    Arguments:
    value (I) Value to *assign*.
  */
  OdArray& setAll(
    const T& value)
  {
    copy_if_referenced();
    T* pData = data();
    size_type n = length();
    while(n)
    {
      pData[--n] = value;
    }
    return *this;
  }
  /** Description:
    Appends the specified *value* or Array object to the *end* of this Array object.

    Arguments:
    otherArray (I) Array to append.
    value (I) Value to append.
    
    Remarks:
    If called with otherArray, returns a reference to this Array object.
    
    If called with value, returns the index of the new *last* element.
    
    If called with no arguments, returns an interator (pointer) to the *first* element 
    after the *last* element in the array.
  */
  OdArray& append(
    const OdArray& otherArray)
  {
    insert(end_non_const(), otherArray.begin(), otherArray.end());
    return *this;
  }
  
  /** Description:
    Inserts the specified *value* into this Array object *at* the specified *index*.

    Arguments:
    arrayIndex (I) Array *index*.
    value (I) Value to *insert*.
    
    Remarks:
                0 <= arrayIndex <= length()
    
    Elements starting *at* arrayIndex will have their indices incremented.
     
    Returns a reference to this Array object.
  */
  OdArray& insertAt(
    size_type arrayIndex, 
    const T& value)
  {
    size_type len = length();
    if( arrayIndex == len )
    {
      resize( len + 1, value );
    }
    else if ( arrayIndex < len )
    {
      reallocator r( m_pData > &value || &value > (m_pData + len) );
      r.reallocate( this, len+1 );
      A::construct( m_pData + len );
      ++(buffer()->m_nLength);
      A::move(m_pData + arrayIndex + 1, m_pData + arrayIndex, len - arrayIndex);
      m_pData[arrayIndex] = value;
    }
    else
    {
    }
    return *this;
  }
  
  /** Description:
    Removes the element *at* the specified *index* from this Array object.

    Arguments:
    arrayIndex (I) Array *index*.
    
    Remarks:
                0 <= arrayIndex < length()
    
    Elements starting *at* arrayIndex+1 will have their indices decremented.
     
    Returns a reference to this Array object.
  */
  OdArray& removeAt(
    size_type arrayIndex)
  {
    if (arrayIndex >= 0)
    {
      size_type len = length();
      if (arrayIndex < --len)
      {
        copy_if_referenced();
        T* pData = data();
        A::move(pData + arrayIndex, pData + arrayIndex + 1, len - arrayIndex);
      }
      resize(len);
    }
    return *this;
  }
  
  /** Description:
    Removes the specified elements from this Array object.

    Arguments:
    startIndex (I) Start *index*.
    endIndex (I)  End *index*.
    
    Remarks:
    Elements from startIndex through endIndex inclusive will be removed.
    
    Returns a reference to this Array object.
  */
  OdArray& removeSubArray(
    size_type startIndex, 
    size_type endIndex)
  {
    if (!isValid(startIndex) || startIndex > endIndex)
    {
      ODA_ASSERT(false);
      return *this;
    }
    size_type len = length();
    if (endIndex >= len)
    {
      setLogicalLength(startIndex);
      return *this;
    }
    copy_if_referenced();
    T* pData = data();
    ++endIndex;
    size_type n2remove = endIndex - startIndex;
    A::move(pData + startIndex, pData + endIndex, len - endIndex);
    A::destroy(pData + len - n2remove, n2remove);
    buffer()->m_nLength -= n2remove;
    return *this;
  }
  
  /** Description:
    Returns true if and only if this Array object *contains* ths specified *value*.
    
    Arguments:
    value (I) Value for which to search.
    findIndex (O) Receives the *index* of the found *value*.
    start (I) Starting *index* of search.
    
    Remarks:
    Returns the *index* *at* which the element was found.
  */
  bool find(
    const T& value, 
    size_type& findIndex, 
    size_type start=0) const
  {
    if(!empty())
    {
      size_type len = length();
      for(size_type i = start; i<len; ++i)
      {
        if(m_pData[i] == value)
        {
          findIndex = i;
          return true;
        }
      }
    }
    return false;
  }

  int find(const T& value) const
  {
    int findIndex = -1;
    find(value,findIndex);
    return findIndex;
  }

  int findFrom(const T& value, int start) const
  {
    int findIndex = -1;
    find(value,findIndex,start);
    return findIndex;
  }
  
  /** Description:
    Sets the logical *length* of this Array object.
    Arguments:
    logLength (I) Logical *length*.
    Remarks:
    The physical *length* is increased as required. 
  */
  OdArray& setLogicalLength(
    size_type logLength)
  {
    resize(logLength);
    return *this;
  }
  
  /** Description:
    Sets the physical *length* of this Array object.
    Arguments:
    physLength (I) Physical *length*.
    Remarks:
    The logical *length* is decreased as required.
  */
  OdArray& setPhysicalLength(
    size_type physLength)
  {
    if(physLength==0)
    {
      *this = OdArray<T, A>();
    }
    else if(physLength != physicalLength())
    {
      copy_buffer(physLength, !referenced(), true);
    }
    return *this;
  }
  
  /** Description:
    Reverses the order of the elements in this Array object.
  */
  OdArray& reverse()
  {
    if(!empty())
    {
      copy_if_referenced();
      T tmp;
      iterator iter1 = begin_non_const();
      iterator iter2 = end_non_const();
      --iter2;
      while(iter1 < iter2)
      {
        tmp = *iter1;
        *iter1 = *iter2;
        *iter2 = tmp;
        ++iter1;
        --iter2;
      }
    }
    return *this;
  }
    
  /** Description:
    Swaps the specified elements in this Array object.
    Arguments:
    firstIndex (I) Index of *first* element.
    secondIndex (I) Index of second element. 
  */
  OdArray& swap(
    size_type firstIndex, 
    size_type secondIndex)
  {
    if(firstIndex != secondIndex)
    {
      const T tmp = at(firstIndex);
      at(firstIndex) = at(secondIndex);
      at(secondIndex) = tmp;
    }
    return *this;
  }
  /** Description:
    Removes the element with the specified *value* from this Array object.
    
    Arguments:
    value (I) Value for which to search.
    start (I) Starting *index* of search.
    
    Remarks:
    Removes the *first* occurance of value starting *at* start.
   
    Returns true if and only if an element was removed.
  */
  bool remove(
    const T& value, 
    size_type start = 0)
  {
    size_type i = 0;
    if(find(value, i, start))
    {
      removeAt(i);
      return true;
    }
    return false;
  }
private:

  T*    m_pData;

  bool isValid(size_type i) const
  {
    return (i >= 0 && i < length());
  }

  T* data() 
  { 
    return (length() ? m_pData : 0); 
  }

  const T* data() const 
  { 
    return m_pData; 
  }

  Buffer* buffer() const
  {
    return (reinterpret_cast<Buffer*>(const_cast<OdArray*>(this)->m_pData) - 1);
  }
  bool referenced() const
  {
    return (buffer()->m_nRefCounter>1);
  }
};

template <class T, class A = OdObjectsAllocator<T> > class OdObjectsArray : public OdArray<T, A>{};
#include "TD_PackPop.h"

#endif // ODARRAY_H_INCLUDED


