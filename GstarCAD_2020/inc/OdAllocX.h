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

#ifndef _OD_ALLOCX_INCLUDED_
#define _OD_ALLOCX_INCLUDED_

#include "OdAllocExport.h"
#include "OdAlloc.h"

/** Description:
    The following functions are used to handle string values and(or) memory
    returned to or from (or passed into) the Teigha API.
*/

//DD:EXPORT_ON

/** Description:
    Allocates a block of memory and sets pOutput to point to the memory allocated.
    Any memory currently pointed to by pOutput will be lost. 
    Arguments:
    pOutput (O) Pointer to the memory allocated.
    nBytes (I) Number of bytes to allocate.
    Remarks:
    Returns eOk if the allocation is successful; otherwise, returns eOutOfMemory. 
    See Also:
    Memory Management
  */
ALLOCDLL_EXPORT OdResult odutNewBuffer(void*& pOutput, size_t nBytes);

/** Description:
    Allocates a new string of length specified by nNumChars and sets pOutput to point
    to the string allocated. Any memory currently pointed to by pOutput will be lost. 
    Arguments:
    pOutput (O) Pointer to the string allocated.
    nBytes (I) Number of characters to allocate.
    Remarks:
    Returns eOk if the allocation is successful; otherwise, returns eOutOfMemory. 
    See Also:
    Memory Management
  */
ALLOCDLL_EXPORT OdResult odutNewString(OdChar*& pOutput, int nNumChars);

/** Description:
    Makes a copy of the pInput string and sets pOutput to point to the resulting copy.
    to the string allocated. Any memory currently pointed to by pOutput will be lost.
    Arguments:
    pInput (I) Pointer to te input string.
    pOutput (O) Pointer to the resulting copy.    
    Remarks:
    Returns eOk if successful; otherwise, returns eOutOfMemory. 
    See Also:
    Memory Management
  */
ALLOCDLL_EXPORT OdResult odutNewString(const OdChar* pInput, OdChar*& pOutput);

/** Description:
    Makes a copy of the pInput string and sets pOutput to point to the resulting copy.
    If pOutput is currently pointing to any allocated memory, then that memory is 
    deallocated even if pInput is NULL.
    Arguments:
    pInput (I) Pointer to te input string.
    pOutput (I) (O) Pointer to the resulting copy.    
    Remarks:
    Returns eOk if successful; otherwise, returns eOutOfMemory. 
    See Also:
    Memory Management
  */
ALLOCDLL_EXPORT OdResult odutUpdString(const OdChar* pInput, OdChar*& pOutput);

/** Description:
    Deallocates the memory pointed to by pString and sets pString to NULL.
    Arguments:
    pBuffer (I) Pointer to te memory to be deallocated.
    Remarks:
    This function is designed to be used on memory allocated via odutNewString(),
    odutNewBuffer(), and odutUpdString().
    See Also:
    Memory Management
  */
ALLOCDLL_EXPORT void odutDelBuffer(void*& pBuffer);

inline OdResult odutNewBuffer(wchar_t*& pOutput, size_t nBytes)
{
  return ::odutNewBuffer((void * &)pOutput, nBytes);
}

inline void odutDelBuffer(wchar_t*& pString)
{
  ::odutDelBuffer((void * &)pString);
}

inline OdResult odutNewBuffer(char*& pOutput, size_t nBytes)
{
  return ::odutNewBuffer((void * &)pOutput, nBytes);
}

inline void odutDelBuffer(char*& pString)
{
  ::odutDelBuffer((void * &)pString);
}

inline void odutDelString(char*& pString)
{
  ::odutDelBuffer((void * &)pString);
}

inline void odutDelString(wchar_t*& pString)
{
  ::odutDelBuffer((void * &)pString);
}

#ifdef __cplusplus
extern "C" {
#endif
/** Description:
    Allocates a new result buffer.
    Arguments:
    v (I) Result type field to set for the new result buffer.
    Remarks:
    Returns a pointer to the newly allocated.
  */
ALLOCDLL_EXPORT struct resbuf* odutNewRb(int v);

/** Description:
    Builds a linked list of result buffers from individual data items by allocating
    result buffers, assigning them the values specified by the gcutBuildList() 
    arguments, and linking the buffers together.
    Arguments:
    rtype (I) First argument in the pair, representing the type of the data in the 
    second argument.
    Remarks:
    Returns a pointer to the newly created list if successful; otherwise, returns NULL. 
  */
ALLOCDLL_EXPORT struct resbuf* odutBuildList (int rtype, ...);

/** Description:
    Releases the memory allocated to the specified result buffer, to all result buffers
    that follow it in its linked list, and to any memory allocated to string values in 
    those result buffers.
    Arguments:
    rb (I) First result buffer to deallocate.
    Remarks:
    returns RTNORM if successful; otherwise, returns an error code.
  */
ALLOCDLL_EXPORT int	odutRelRb (struct resbuf* rb);

/** Description:
    Makes a copy of the pInput result buffer and sets pOutput to point to the resulting copy.
    For internal use only.
    Arguments:
    pInput (I) Pointer to te input result buffer.
    pOutput (O) Pointer to the resulting copy.    
    Remarks:
    Returns RTNORM if successful; otherwise, returns an error code.
    See Also:
  */
ALLOCDLL_EXPORT int odutCopyRb(const resbuf* pInput, resbuf*& pOutput);

/** Description:
    Copies the linked list of result buffer and sets pOutput to point to the resulting copy.
    For internal use only.
    Arguments:
    pInput (I) Pointer to the linked list of the input result buffer.
    pOutput (O) Pointer to the resulting copy.    
    Remarks:
    Returns RTNORM if successful; otherwise, returns an error code.
    See Also:
  */
ALLOCDLL_EXPORT int odutDupList(const resbuf* pInput, resbuf*& pOutput);

#ifdef __cplusplus
}   // extern "C"
#endif

#endif
