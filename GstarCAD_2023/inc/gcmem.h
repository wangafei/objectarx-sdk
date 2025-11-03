/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCMEM_H
#define _GCMEM_H

#include <stddef.h>
#include "GdGChar.h"
#include "gccoredefs.h"

#pragma pack (push, 8)


GCCORE_PORT void  *gcad_malloc(size_t size);
GCCORE_PORT void   gcad_free(void *p);
GCCORE_PORT size_t gcad__msize(void *p);
GCCORE_PORT void  *gcad_realloc(void *p, size_t size);
GCCORE_PORT void  *gcad_calloc(size_t num, size_t size);
GCCORE_PORT GCHAR *gcad__strdup(const GCHAR *p);

#pragma pack (pop)
#endif 