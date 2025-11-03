
#ifndef __EOKTEST_H__
#define __EOKTEST_H__

#include "adesk.h"
#include "acadstrc.h"
#include "acestext.h"
#include "acutasrt.h"

#include "../../inc/zeoktest.h"

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef acutAssertMessage
#define acutAssertMessage		zcutAssertMessage
#endif //#ifndef acutAssertMessage

#ifndef acadErrorStatusText
#define acadErrorStatusText		zcadErrorStatusText
#endif //#ifndef acadErrorStatusText

#ifndef ACRX_T
#define ACRX_T		ZCRX_T
#endif //#ifndef ACRX_T

#endif //__EOKTEST_H__
