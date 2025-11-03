#pragma once

class AcRxDLinkerReactor;
class AcRxService;

#include "rxobject.h"
#include "LoadReasons.h"
#pragma pack (push, 8)

#define GcadApp OdaApp
namespace GcadApp
{
	enum ErrorStatus {
		eOk             = 0,
		eInvalidKey     = 1,
		eInvalidSubKey  = 2,
		eKeyNotFound    = 3,
		eOutOfMemory    = 4,
		eInvalidValue   = 5,
		eValueNotFound  = 6,
		eKeyExists      = 7,
		eRegAccessDenied= 8,
		eRejected       = 9,
		eUnknownError   = 10,
        eInetOk         = 11,
        eInetInCache    = 12
	};
};


//  The kernel creates the one and only dynamic linker, at
//
//#define gcrxDynamicLinker                                               \
//  OdRxDynamicLinker::cast(odrxSysRegistry()->at(ODRX_DYNAMIC_LINKER))

#pragma pack (pop)

