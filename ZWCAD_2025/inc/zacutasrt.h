
#ifndef _ZCUTASRT_H
#define _ZCUTASRT_H

#include "zacbasedefs.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

ZCBASE_PORT void zcutAssertMessage(
    const ZTCHAR *condition,
    const ZTCHAR *filename,
    int         lineNumber,
    const ZTCHAR *status);

#pragma pack (pop)
#endif
