#ifndef __GCAD__MEMORY__INCLUDE__
#define __GCAD__MEMORY__INCLUDE__

#define gcad_malloc  ::malloc
#define gcad_realloc ::realloc
#define gcad_calloc  ::calloc
#define gcad_free    ::free
#define gcad__msize  ::_msize
#define gcad__strdup ::_wcsdup

#endif //__GCAD__MEMORY__INCLUDE__