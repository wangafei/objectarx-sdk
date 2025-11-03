#pragma once

#include <stddef.h>
#include "gcadstd.h"
#include "gcstring.h"
#include "dbcolor.h"

#pragma pack (push, 8)

GCUT_DLL_DECL bool	gcutSplitString(size_t & numLeftBytes,	const GCHAR *& pRight,	const GCHAR  * source,	unsigned int  delimiter);
GCUT_DLL_DECL void	gcutTrimWhiteSpace(GCHAR * pStr);

GCUT_DLL_DECL GcString gcutTokenizeString(GcString& str, const GcString& strTokens, int& iStart);

GCUT_DLL_DECL size_t	gcutXStrLength(const GCHAR * str);

GCUT_DLL_DECL Gcad::ErrorStatus gcutXStrNormalize(GCHAR *& pStr,bool preserveCase);

inline Gcad::ErrorStatus gcutXStrUppercase(GCHAR *& pStr)
{	
  return gcutXStrNormalize(pStr, false); 
}

GCUT_DLL_DECL bool gcutStrncpy(GCHAR * dest,const GCHAR * source,size_t count);

GCUT_DLL_DECL GcString gcutColorToStr(short colnum);

GCUT_DLL_DECL GcString gcutColorToStr(const GcCmColor &clrr);

#pragma pack (pop)
