#pragma once
#include <stddef.h>
#include "AdAChar.h"
#include "../grx/gcmem.h"

#define  acad_malloc   gcad_malloc
#define  acad_free     gcad_free
#define  acad__msize   gcad__msize
#define  acad_realloc  gcad_realloc
#define  acad_calloc   gcad_calloc
#define  acad__strdup  gcad__strdup

