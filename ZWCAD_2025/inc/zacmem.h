

#ifndef _ZCMEM_H
#define _ZCMEM_H

#include <stddef.h>
#include "zAdAChar.h"
#include "zAcDbCore2dDefs.h"

#pragma pack (push, 8)

ZCDBCORE2D_PORT void  *zcad_malloc  (size_t size);
ZCDBCORE2D_PORT void   zcad_free    (void *p);
ZCDBCORE2D_PORT size_t zcad__msize  (void *p);
ZCDBCORE2D_PORT void  *zcad_realloc (void *p, size_t size);
ZCDBCORE2D_PORT void  *zcad_calloc  (size_t num, size_t size);
ZCDBCORE2D_PORT ZTCHAR *zcad__strdup (const ZTCHAR *p);


#pragma pack (pop)
#endif 
