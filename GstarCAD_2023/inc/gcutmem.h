/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCUTMEM_H
#define _GCUTMEM_H

#include "gcadstrc.h"   
#include "gsoft.h"      
#include "GdGChar.h"    
#include "GcDbCore2dDefs.h"     
#pragma pack (push, 8)

GCBASE_PORT Gcad::ErrorStatus gcutNewBuffer(void *&pOutput, size_t size);
GCBASE_PORT Gcad::ErrorStatus gcutNewString(GCHAR *&pOutput, Gsoft::Int32 nNumChars);
GCBASE_PORT Gcad::ErrorStatus gcutNewString(const GCHAR* pInput, GCHAR*& pOutput);
GCBASE_PORT Gcad::ErrorStatus gcutUpdString(const GCHAR* pInput, GCHAR*& pOutput);
GCBASE_PORT void gcutDelBuffer(void *& pBuffer);

inline Gcad::ErrorStatus gcutNewBuffer(char *&pOutput, size_t size)
{
  return ::gcutNewBuffer((void * &)pOutput, size);
}

inline void gcutDelBuffer(char *& pString)
{
  ::gcutDelBuffer((void * &)pString);
}

inline void gcutDelString(char *& pString)
{
  ::gcutDelBuffer((void * &)pString);
}

inline void gcutDelString(wchar_t *& pString)
{
  ::gcutDelBuffer((void * &)pString);
}

#pragma pack (pop)

GCBASE_PORT Gcad::ErrorStatus
gcutCopyStringToBuffer(const GCHAR * pInput, GCHAR * pOutput, size_t nOutputSize);

#endif 