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


#ifndef _OD_ALLOC_INCLUDED_
#define _OD_ALLOC_INCLUDED_

#include "OdAllocExport.h"

/** Description:
    Defines the interface for Teigha memory management.
*/

//DD:EXPORT_ON

#ifdef __cplusplus
  extern "C" {
#endif

  /** Description:
    Allocates a block of memory.
    Arguments:
    nBytes (I) Number of bytes to allocate.
    Remarks:
    Returns a pointer to the newly allocated memory block.
    See Also:
    Memory Management
  */
  extern ALLOCDLL_EXPORT void* odrxAlloc  (size_t nBytes);
  /** Description:
    Reallocates a block of memory.
    Arguments:
    pMemBlock (I) Pointer to the previously allocated memory block.
    newSize (I) New size in bytes.
    oldSize (I) Old size in bytes.
    Remarks:
    Returns a pointer to the newly allocated memory block.
    See Also:
    Memory Management
  */
  extern ALLOCDLL_EXPORT void* odrxRealloc(void* pMemBlock, size_t newSize, size_t oldSize);
  /** Description:
    Allocates an array in memory with elements initialized to 0.
    Arguments:
    nElements (I) Number of elements.
    nLen (I) Length in bytes of each element.
    Remarks:
    Returns a pointer to the newly allocated memory block.
    See Also:
    Memory Management
  */
  extern ALLOCDLL_EXPORT void* odrxCalloc (size_t nElements, size_t nLen);
  /** Description:
    Frees a block of memory.
    Arguments:
    pMemBlock (I) Pointer to the previously allocated memory block.
    See Also:
    Memory Management
  */
  extern ALLOCDLL_EXPORT void  odrxFree   (void* pMemBlock);

  extern ALLOCDLL_EXPORT void  odrxRegBlockSize(size_t nBytes , size_t nMaxCount);

  extern ALLOCDLL_EXPORT size_t odrxGc();

  extern ALLOCDLL_EXPORT void odrxDumpStat(wchar_t * psz);

#ifdef __cplusplus
  }   // extern "C"
#endif


#ifdef __cplusplus
class GcAdMemoryAllocator
{
public:
  virtual OdULongPtr Alloc(OdUInt32 size) = 0;
  virtual void     Free (OdULongPtr p)    = 0;

  virtual void  *  Lock (OdULongPtr p)    = 0;
  virtual void  *  Unlock(OdULongPtr p)   = 0;

  virtual bool     IsAvailable() const  = 0;
};

#endif
//DD:EXPORT_OFF

#endif 
