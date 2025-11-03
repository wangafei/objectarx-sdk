
#ifndef __OLEAPROT_H__
#define __OLEAPROT_H__

#include "dbmain.h"

#include "../../inc/zoleaprot.h"

#ifndef ADESK_WINDOWS_
#define ADESK_WINDOWS_		ZSOFT_WINDOWS_
#endif //#ifndef ADESK_WINDOWS_

#ifndef AcAxGetOleLinkManager
#define AcAxGetOleLinkManager		ZcAxGetOleLinkManager
#endif //#ifndef AcAxGetOleLinkManager

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcAxOleLinkManager
#define AcAxOleLinkManager		ZcAxOleLinkManager
#endif //#ifndef AcAxOleLinkManager

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbSubentId
#define AcDbSubentId		ZcDbSubentId
#endif //#ifndef AcDbSubentId

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#endif //#ifndef __OLEAPROT_H__
