
#ifndef __RXCOPYONWRITEOBJECT_H__
#define __RXCOPYONWRITEOBJECT_H__

#include "rxobject.h"
#include "rxboiler.h"
#include "acbasedefs.h" 

#include "../../inc/zrxcopyonwriteobject.h"

#ifndef AcRxCopyOnWriteObject
#define AcRxCopyOnWriteObject	ZcRxCopyOnWriteObject
#endif 

#ifndef ACRX_DECLARE_MEMBERS_READWRITE
#define ACRX_DECLARE_MEMBERS_READWRITE	ZCRX_DECLARE_MEMBERS_READWRITE
#endif 

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef ACRX_DECLARE_MEMBERS_EXPIMP
#define ACRX_DECLARE_MEMBERS_EXPIMP		ZCRX_DECLARE_MEMBERS_EXPIMP
#endif //#ifndef ACRX_DECLARE_MEMBERS_EXPIMP

#ifndef ACBASE_PORT
#define ACBASE_PORT		ZCBASE_PORT
#endif //#ifndef ACBASE_PORT

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#endif //__RXCOPYONWRITEOBJECT_H__