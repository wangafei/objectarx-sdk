#ifndef __RXRESOURCE_H__
#define __RXRESOURCE_H__

#include "acbasedefs.h"
#include "PAL/api/def.h"
#include "adesk.h"
#include "pimplapi.h"
#include "AcHeapOpers.h"

#include "../../inc/zrxresource.h"

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef Autodesk
#define Autodesk	ZwSoft
#endif //#ifndef Autodesk

#ifndef Adesk
#define Adesk	ZSoft
#endif //#ifndef Adesk

#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#ifndef AcHeapOperators
#define AcHeapOperators		ZcHeapOperators
#endif //#ifndef AcHeapOperators

#ifndef AcRxResourceInstance
#define AcRxResourceInstance		ZcRxResourceInstance
#endif //#ifndef AcRxResourceInstance

#ifndef AcRxResourceInstanceImp
#define AcRxResourceInstanceImp		ZcRxResourceInstanceImp
#endif //#ifndef AcRxResourceInstanceImp

#endif //#ifndef __RXRESOURCE_H__
