
#pragma once

#include "AdAChar.h"
#include "acadstrc.h"
#include "AcDbCore2dDefs.h"

#include "../../inc/zmgdhost-core2d.h"

#ifndef AcString
#define AcString  ZcString
#endif  //ifndef AcString

#ifndef AcDbManagedHost
#define AcDbManagedHost		ZcDbManagedHost
#endif //#ifndef AcDbManagedHost

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef acdbGetManagedHost
#define acdbGetManagedHost	zcdbGetManagedHost
#endif //#ifndef acdbGetManagedHost

#ifndef acdbSetManagedHost
#define acdbSetManagedHost		zcdbSetManagedHost
#endif //#ifndef acdbSetManagedHost

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT  ZCDBCORE2D_PORT
#endif  //ifndef ACDBCORE2D_PORT

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL
