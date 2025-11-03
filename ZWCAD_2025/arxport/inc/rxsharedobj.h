#ifndef __RXSHAREDOBJ_H__
#define __RXSHAREDOBJ_H__

#include "acbasedefs.h"
#include "adesk.h"
#include "pimplapi.h"
#include "AcHeapOpers.h"
#include "PAL/api/def.h"

#include "../../inc/zrxsharedobj.h"

#ifndef AcRxSharedObjImp
#define AcRxSharedObjImp	ZcRxSharedObjImp
#endif //#ifndef AcRxSharedObjImp

#ifndef AcRxSharedObject
#define AcRxSharedObject	ZcRxSharedObject
#endif //#ifndef AcRxSharedObject

#ifndef ACBASE_PORT
#define ACBASE_PORT	ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#ifndef Autodesk
#define Autodesk	ZwSoft
#endif //#ifndef Autodesk

#endif //#ifndef __RXSHAREDOBJ_H__
