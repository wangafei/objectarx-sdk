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




#ifndef _OD_MEMORY_H_
#define _OD_MEMORY_H_

#define STL_USING_MEMORY
#include "OdaSTL.h"

#include "OdPlatform.h"
#include "OdAlloc.h"

// TEMPLATE CLASS allocator
// Some compilers don't have support for construct & destroy functions.

#ifndef OD_STD_ALLOCATOR
/** Description:
    This template class extends the functionality of the standard STL class std::allocator
    for those compilers that not support for construct and destroy.
    
    Note:
    If construct and destroy are supported, as indicated by #define OD_STD_ALLOCATOR,
    this class is does nothing to std::allocator.
    
    {group:Other_Classes}
*/
template<class T>
class OdAllocator : public std::allocator<T>
{
public:
  typedef typename std::allocator<T>::size_type       size_type;
  typedef typename std::allocator<T>::difference_type difference_type;
  typedef typename std::allocator<T>::pointer         pointer;
  typedef typename std::allocator<T>::const_pointer   const_pointer;
  typedef typename std::allocator<T>::reference       reference;
  typedef typename std::allocator<T>::const_reference const_reference;
  typedef typename std::allocator<T>::value_type      value_type;

private:
  inline void constructn(size_type N, pointer ptr, const T& _V = T())
  {
    while(N--) construct(ptr + N, _V);
  }
  inline void destroyn(size_type N, pointer ptr)
  {
    while(N--) destroy(ptr + N);
  }
public:
  /** Description:
    Allocates a block of memory sufficient to store the specified number of elements.
    Arguments:
    N (I) Number of elements. 
    Remarks:
    Returns a *pointer* to the allocated memory.
  */
  pointer allocate(size_type N, const void * = 0)
  {
    pointer res = NULL;
    if (N)
    {
      res = (pointer)::odrxAlloc(N * sizeof(T));
      constructn(N, res);
    }
    return res;
  }
  
  // For CodeWarrior

  pointer allocate(size_type N, const_pointer = 0)
  {
    pointer res = NULL;
    if (N)
    {
      res = (pointer)::odrxAlloc(N * sizeof(T));
      constructn(N, res);
    }
    return res;
  }

#ifdef _MSC_VER
#if _MSC_VER > 1600
#ifndef _FARQ /* specify standard memory model */
#define _FARQ
#define _PDFT ptrdiff_t
#define _SIZT size_t
#endif
#endif //!DOM _MSC_VER > 1600
  /** Description:
    Allocates a block of memory sufficient to store the specified number of characters.
    Arguments:
    N (I) Number of characters. 
    Remarks:
    Returns a *pointer* to the allocated memory.
    
    Note:
    Prevents "Freeing Mismatched Memory" errors in Purify.
  */
  char _FARQ *_Charalloc(size_type N)
  {
    return (char _FARQ*)::odrxAlloc(N);
  }
#endif

  /** Description:
    Frees a block of memory allocated with allocate.
    Arguments:
    P (I) Pointer to the memory.
  */
  void deallocate(void* P, size_type = 0 ) { ::odrxFree(P); }
};

#else
/** Description:
    
    {group:Other_Classes}
*/
template<class T>
class OdAllocator : public std::allocator<T>
{};


#endif


#endif //_OD_MEMORY_H_

