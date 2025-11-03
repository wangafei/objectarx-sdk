
#ifndef __ACUTASRT_H__
#define __ACUTASRT_H__

#include "pal/api/def.h"
#include "AdAChar.h"

#include "../../inc/zacutasrt.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef acutAssertMessage
#define acutAssertMessage		zcutAssertMessage
#endif //#ifndef acutAssertMessage

#ifndef ACPAL_PORT
#define ACPAL_PORT		ZCPAL_PORT
#endif //#ifndef ACPAL_PORT

#endif //#ifndef __ACUTASRT_H__
