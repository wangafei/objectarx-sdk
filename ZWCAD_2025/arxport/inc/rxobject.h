
#ifndef __RXOBJECT_H__
#define __RXOBJECT_H__

#include "acbasedefs.h"
#include "adesk.h"
#include "rxdefs.h"
#include "rxboiler.h"
#include "acadstrc.h"
#include "acdbport.h"
#include "AcDbCore2dDefs.h"
#include "rxclass.h"
#include "rxdict.h"

#include "../../inc/zrxoverrule.h"


#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#ifndef AcRxQueryXOverrule
#define AcRxQueryXOverrule		ZcRxQueryXOverrule
#endif //#ifndef AcRxQueryXOverrule

#ifndef ACDB_API
#define ACDB_API		ZCDB_API
#endif //#ifndef ACDB_API

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ACRX_PE_PTR
#define ACRX_PE_PTR		ZCRX_PE_PTR
#endif //#ifndef ACRX_PE_PTR

#ifndef ACRX_X_CALL
#define ACRX_X_CALL		ZCRX_X_CALL
#endif //#ifndef ACRX_X_CALL

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcRx
#define AcRx		ZcRx
#endif //#ifndef AcRx

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#endif //#ifndef __RXOBJECT_H__
