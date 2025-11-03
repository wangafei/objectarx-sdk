#ifndef __ACLOCALE_H__
#define __ACLOCALE_H__

#include "def.h"
#include <string>

#include "../../../../inc/PAL/api/zAcLocale.h"

#ifndef AcLocaleImp
#define AcLocaleImp		ZcLocaleImp
#endif //#ifndef AcLocaleImp

#ifndef AcLocale
#define AcLocale		ZcLocale
#endif //#ifndef AcLocale

#ifndef AcLocaleService
#define AcLocaleService		ZcLocaleService
#endif //#ifndef AcLocaleService

#ifndef ACPAL_PORT
#define ACPAL_PORT		ZCPAL_PORT
#endif //#ifndef AcLocale

#ifndef ZC_NON_CROSS_PLATFORM_API
#define ZC_NON_CROSS_PLATFORM_API		AC_NON_CROSS_PLATFORM_API
#endif //#ifndef ZC_NON_CROSS_PLATFORM_API

#ifndef m_pImpAcLocale
#define m_pImpAcLocale		m_pImpZcLocale
#endif //#ifndef m_pImpAcLocale

#endif //ifndef __ACLOCALE_H__
