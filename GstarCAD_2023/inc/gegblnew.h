/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEGBLNEW_H
#define GC_GEGBLNEW_H

#ifdef GE_LOCATED_NEW

#include "gegblge.h"
#include "gegetmti.h"

GE_DLLDATAEXIMP
void* operator new (size_t, enum GcGe::metaTypeIndex, const void*);

GE_DLLDATAEXIMP
void* operator new (size_t, enum GcGe::metaTypeIndex, unsigned int, const void*);

#define GENEWLOC( T, ptr)  new (GcGeGetMetaTypeIndex<T >(), (ptr)) T
#define GENEWLOCVEC( T, count, ptr) new (GcGeGetMetaTypeIndex<T >(),(count),(ptr)) T [ (count) ]
#else   
#define GENEWLOC( T, ptr)  new T
#define GENEWLOCVEC( T, count, ptr) new T [ (count) ]
#endif


#endif  