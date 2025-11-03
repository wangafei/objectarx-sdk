#pragma once
#include "gcadstd.h"
#include "gcutmem.h"

#pragma pack (push, 8)

inline Gcad::ErrorStatus
newBuffer(GCHAR *&pOutput, size_t size)
{ return gcutNewBuffer(pOutput, size); }

inline Gcad::ErrorStatus
newString(const GCHAR* pInput, GCHAR*& pOutput)
{ return gcutNewString(pInput, pOutput); }

inline Gcad::ErrorStatus
newString(GCHAR*& pOutput, int nNumChars)
{ return gcutNewString(pOutput, nNumChars); }

inline Gcad::ErrorStatus
updString(const GCHAR* pInput, GCHAR*& pOutput)
{ return gcutUpdString(pInput, pOutput); }

inline void
delString(GCHAR*& pString)
{ gcutDelString(pString); }

inline void
delBuffer(GCHAR*& pString)
{ gcutDelString(pString); }

#pragma pack (pop)
