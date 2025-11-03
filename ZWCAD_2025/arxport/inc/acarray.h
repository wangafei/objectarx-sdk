#ifndef __ACARRAY_H__
#define __ACARRAY_H__

#include "adesk.h"
#include "assert.h"

#include "../../inc/zacarray.h"

#ifndef ACARRAY_GROWTH_THRESHOLD
#define ACARRAY_GROWTH_THRESHOLD		ZCARRAY_GROWTH_THRESHOLD
#endif //#ifndef ACARRAY_GROWTH_THRESHOLD

#ifndef AC_ARRAY_ASSERT
#define AC_ARRAY_ASSERT		ZC_ARRAY_ASSERT
#endif //#ifndef AC_ARRAY_ASSERT

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcArrayMemCopyReallocator
#define AcArrayMemCopyReallocator		ZcArrayMemCopyReallocator
#endif //#ifndef AcArrayMemCopyReallocator

#ifndef AcArrayObjectCopyReallocator
#define AcArrayObjectCopyReallocator		ZcArrayObjectCopyReallocator
#endif //#ifndef AcArrayObjectCopyReallocator

#ifndef AcArrayItemCopierSelector
#define AcArrayItemCopierSelector		ZcArrayItemCopierSelector
#endif //#ifndef AcArrayItemCopierSelector

#ifndef ADESK_UNREFED_PARAM
#define ADESK_UNREFED_PARAM		ZSOFT_UNREFED_PARAM
#endif //#ifndef ADESK_UNREFED_PARAM

#ifndef AcArrayValidateParams
#define AcArrayValidateParams		ZcArrayValidateParams
#endif //#ifndef AcArrayValidateParams

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcStringArray
#define AcStringArray		ZcStringArray
#endif //#ifndef AcStringArray

#ifndef AcArrayUtil
#define AcArrayUtil		ZcArrayUtil
#endif //#ifndef AcArrayUtil

#endif //#ifndef __ACARRAY_H__
