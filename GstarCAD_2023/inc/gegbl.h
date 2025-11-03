/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEGBL_H
#define GC_GEGBL_H

#include <stdlib.h>
#include "gedll.h"
#include "gsoft.h"
#include "getol.h"

#include "gegblge.h"
#pragma pack (push, 8)

class GcGeVector3d;

struct
  GE_DLLDATAEXIMP
  GcGeContext
{
  static GcGeTol     gTol;

  static void(*gErrorFunc)();

#ifndef GELIB2D
  static void(*gOrthoVector)(const GcGeVector3d&, GcGeVector3d&);
#endif

#ifndef unix
  static void* (*gAllocMem)(size_t);
  static void(*gFreeMem)(void*);
#endif
#ifdef GE_LOCATED_NEW
  static void* (*gAllocMemNear) (size_t, GcGe::metaTypeIndex, const void*);
  static void* (*gAllocMemNearVector) (size_t, GcGe::metaTypeIndex, unsigned int, const void*);
  static void(*gSetExternalStore) (const void*);
#endif
#ifndef NDEBUG
  static void(*gAssertFunc)(const GCHAR *condition, const GCHAR *filename,
    int lineNumber, const GCHAR *status);
#endif
};


#pragma pack (pop)
#endif 