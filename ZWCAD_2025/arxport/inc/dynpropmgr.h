
#ifndef __DYNPROPMGR_H__
#define __DYNPROPMGR_H__

#include "adesk.h"
#include "AdAChar.h"
#include "acdbport.h"
#include "dynprops-AcFilterablePropertyContext.h"

#include "../../inc/zdynpropmgr.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcRxDynPropManager
#define AcRxDynPropManager		ZcRxDynPropManager
#endif //#ifndef AcRxDynPropManager

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ACRX_DECLARE_MEMBERS_EXPIMP
#define ACRX_DECLARE_MEMBERS_EXPIMP		ZCRX_DECLARE_MEMBERS_EXPIMP
#endif //#ifndef ACRX_DECLARE_MEMBERS_EXPIMP

#ifndef AcFilterablePropertyContext
#define AcFilterablePropertyContext		ZcFilterablePropertyContext
#endif //#ifndef AcFilterablePropertyContext

#endif //#ifndef __DYNPROPMGR_H__
