
#ifndef __ADCHARFMT_H__
#define __ADCHARFMT_H__

#include "adesk.h"
#include "casuppress.h"

#include "acbasedefs.h"
#include "PAL/api/codepgid.h"
#include <stddef.h>

#include "../../inc/zAdCharFmt.h"

#ifndef AdCharFmt_Assert
#define AdCharFmt_Assert		ZdCharFmt_Assert
#endif //#ifndef AdCharFmt_Assert

#ifndef AdCharFormatter
#define AdCharFormatter		ZdCharFormatter
#endif //#ifndef AdCharFormatter

#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#ifndef ADESK_DEPRECATED
#define ADESK_DEPRECATED		ZSOFT_DEPRECATED
#endif //#ifndef ADESK_DEPRECATED

#endif //#ifndef __ADCHARFMT_H__
