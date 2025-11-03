
#ifndef __ACCRTFILEWRAPPERS_H__
#define __ACCRTFILEWRAPPERS_H__
#include "stdio.h"      
#include "PAL/api/def.h"
#include "AdCharFmt.h"
#include "casuppress.h"
#include <cstdarg>
#include "acbasedefs.h"

#include "../../inc/zAcCrtFileWrappers.h"

#ifndef AcFILE
#define AcFILE		ZcFILE
#endif //#ifndef AcFILE

#ifndef AcFILE_Assert
#define AcFILE_Assert		ZcFILE_Assert
#endif //#ifndef AcFILE_Assert

#ifndef ADESK_DEPRECATED
#define ADESK_DEPRECATED		ZSOFT_DEPRECATED
#endif //#ifndef ADESK_DEPRECATED

#ifndef AdCharFormatter
#define AdCharFormatter		ZdCharFormatter
#endif //#ifndef AdCharFormatter

#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#endif //#ifndef __ACCRTFILEWRAPPERS_H__
