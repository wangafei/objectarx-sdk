/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcdbgds_h
#define _gcdbgds_h 1

#include "gdsdef.h"
#include "gcmem.h"
#include "GdGChar.h"

#pragma pack (push, 8)

#ifdef __cplusplus
#include "gsoft.h"
#include "gcdbport.h"
#endif

GCCORE_PORT void gcdbFail (const GCHAR *str);
GCCORE_PORT int  gcdbHandEnt (const GCHAR *handle, gds_name entres);

#ifdef __cplusplus

GCCORE_PORT int  gcdbXdRoom (const gds_name ent, Gsoft::Int32 *result);
GCCORE_PORT int  gcdbXdSize (const resbuf *rb, Gsoft::Int32 *result);

GCCORE_PORT GCHAR * gcdbXStrSave (GCHAR *pSource, GCHAR **pDest);
GCCORE_PORT int     gcdbXStrCase (GCHAR *str, size_t strLen);

#endif

#ifdef __STDC__
#define gcdbNameSet(from, to)  (memcpy(to, from, sizeof(gds_name)))
#define gcdbPointSet(from,to)  (memcpy(to, from, sizeof(gds_point)))
#else
#define gcdbNameSet(from, to)  (*(to)= *(from), (to)[1]=(from)[1])
#define gcdbPointSet(from, to) (*(to)= *(from), (to)[1]=(from)[1], (to)[2]=(from)[2])
#endif  

#define gcdbNameClear(name)    name[0] = name[1] = 0
#define gcdbNameNil(name)      (name[0] == 0 && name[1] == 0)
#define gcdbNameEqual(name1, name2)  (name1[0]==name2[0] \
                                       && name1[1]==name2[1])
#pragma pack (pop)

#endif 