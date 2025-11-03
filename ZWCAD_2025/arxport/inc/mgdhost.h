
#ifndef __MGDHOST_H__
#define __MGDHOST_H__

#include "adesk.h"
#include "acdbport.h"
#include "mgdhost-core2d.h"

#include "../../inc/zmgdhost.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ADESK_STDCALL
#define ADESK_STDCALL		ZSOFT_STDCALL
#endif //#ifndef ADESK_STDCALL

#ifndef acdbInitializeManagedLayer
#define acdbInitializeManagedLayer		zcdbInitializeManagedLayer
#endif //#ifndef acdbInitializeManagedLayer

#ifndef acdbTerminateManagedLayer
#define acdbTerminateManagedLayer		zcdbTerminateManagedLayer
#endif //#ifndef acdbTerminateManagedLayer

#endif //#ifndef __MGDHOST_H__
