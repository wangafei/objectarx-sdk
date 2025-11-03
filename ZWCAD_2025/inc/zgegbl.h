
#ifndef ZC_GEGBL_H
#define ZC_GEGBL_H

#include <stdlib.h>
#include "zgedll.h"
#include "zadesk.h"
#include "zgetol.h"

#include "zgegblge.h"
#pragma pack (push, 8)

class ZcGeVector3d;

struct
ZcGeContext
{

    GE_DLLDATAEXIMP static ZcGeTol     gTol;

    GE_DLLDATAEXIMP static void (*gErrorFunc)();

#ifndef GELIB2D

    GE_DLLDATAEXIMP static void (*gOrthoVector)(const ZcGeVector3d&,ZcGeVector3d&);
#endif

    GE_DLLDATAEXIMP static void* (*gAllocMem)(size_t);
    GE_DLLDATAEXIMP static void  (*gFreeMem)(void*);

#ifdef GE_LOCATED_NEW
    GE_DLLDATAEXIMP static void* (*gAllocMemNear) (size_t, ZcGe::metaTypeIndex, const void* );
    GE_DLLDATAEXIMP static void* (*gAllocMemNearVector) (size_t, ZcGe::metaTypeIndex, unsigned int, const void* );
    GE_DLLDATAEXIMP static void (*gSetExternalStore) (const void* );
#endif
#ifndef NDEBUG
    GE_DLLDATAEXIMP static void (*gAssertFunc)(const ZTCHAR *condition, const ZTCHAR *filename,
                                    int lineNumber, const ZTCHAR *status);
#endif
};

#pragma pack (pop)
#endif
