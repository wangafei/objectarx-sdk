/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCUTMIGR_H
#define _GCUTMIGR_H

#include "gcutmem.h"

#pragma pack (push, 8)

inline Gcad::ErrorStatus newBuffer(char *&pOutput, size_t size)
{
  return ::gcutNewBuffer(pOutput, size);
}

inline Gcad::ErrorStatus newString(const GCHAR* pInput, GCHAR*& pOutput)
{
  return ::gcutNewString(pInput, pOutput);
}

inline Gcad::ErrorStatus newString(GCHAR*& pOutput, int nNumChars)
{
  return ::gcutNewString(pOutput, nNumChars);
}

inline Gcad::ErrorStatus updString(const GCHAR* pInput, GCHAR*& pOutput)
{
  return ::gcutUpdString(pInput, pOutput);
}

inline void delString(GCHAR*& pString)
{
  ::gcutDelString(pString);
}

inline void delBuffer(char*& pString)
{
  ::gcutDelString(pString);
}

#pragma pack (pop)
#endif 
