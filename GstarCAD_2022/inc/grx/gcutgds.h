#pragma once

#include "gcadstd.h"
#include "gdsdef.h"

#include "../OdAllocX.h"
#pragma comment(lib, "TD_Alloc.lib")

#ifdef __cplusplus
    extern "C" {
#endif

#pragma pack (push, 8)

GCUT_DLL_DECL void gcutAssertMessage(const GCHAR * condition, const GCHAR * filename, 
  int lineNumber, const GCHAR * status);

GCUT_DLL_DECL int  gcutCvUnit(gds_real value, const GCHAR *oldunit,const GCHAR *newunit, gds_real *result);
GCUT_DLL_DECL int  gcutWcMatch(const GCHAR *string, const GCHAR *pattern);
GCUT_DLL_DECL bool gcutWcMatchEx(const GCHAR * string,const GCHAR * pattern,	bool	ignoreCase);

GCED_DLL_DECL int	 gcutPrintf(const GCHAR *format, ...);
GCUT_DLL_DECL int	 gcutSPrintf(GCHAR *buffer, const GCHAR *format, ...);

GCUT_DLL_DECL gds_real	gcutAngle(const gds_point pt1, const gds_point pt2);
GCUT_DLL_DECL gds_real	gcutDistance (const gds_point pt1, const gds_point pt2);
GCUT_DLL_DECL void		  gcutPolar(const gds_point pt, gds_real angle,gds_real dist, gds_point ptres);

GCUT_DLL_DECL int	 gcutIsAlpha(int c);
GCUT_DLL_DECL int	 gcutIsUpper(int c);
GCUT_DLL_DECL int	 gcutIsLower(int c);
GCUT_DLL_DECL int	 gcutIsDigit(int c);
GCUT_DLL_DECL int	 gcutIsXDigit(int c);
GCUT_DLL_DECL int	 gcutIsSpace(int c);
GCUT_DLL_DECL int	 gcutIsPunct(int c);
GCUT_DLL_DECL int	 gcutIsAlNum(int c);
GCUT_DLL_DECL int	 gcutIsPrint(int c);
GCUT_DLL_DECL int	 gcutIsGraph(int c);
GCUT_DLL_DECL int	 gcutIsCntrl(int c);
GCUT_DLL_DECL int	 gcutToUpper(int c);
GCUT_DLL_DECL int	 gcutToLower(int c);

#pragma pack (pop)

#ifdef __cplusplus
	}
#endif

#define gcutNewRb     odutNewRb
#define gcutBuildList odutBuildList
#define gcutRelRb     odutRelRb
#define gcutCopyRb    odutCopyRb
#define gcutDupList   odutDupList

#define gds_cvunit		gcutCvUnit
#define gds_wcmatch		gcutWcMatch
#define	gds_printf		gcutPrintf
#define	gds_sprintf		gcutSPrintf
#define gds_newrb		  gcutNewRb
#define gds_relrb		  gcutRelRb
#define gds_buildlist	gcutBuildList
#define gds_angle		  gcutAngle
#define gds_distance	gcutDistance
#define gds_polar		  gcutPolar
#define gds_isalpha		gcutIsAlpha
#define gds_isupper		gcutIsUpper
#define gds_islower		gcutIsLower
#define gds_isdigit		gcutIsDigit
#define gds_isxdigit	gcutIsXDigit
#define gds_isspace		gcutIsSpace
#define gds_ispunct		gcutIsPunct
#define gds_isalnum		gcutIsAlNum
#define gds_isprint		gcutIsPrint
#define gds_isgraph		gcutIsGraph
#define gds_iscntrl		gcutIsCntrl
#define gds_toupper		gcutToUpper
#define gds_tolower		gcutToLower