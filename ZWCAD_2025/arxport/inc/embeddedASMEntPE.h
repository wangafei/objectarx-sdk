
#pragma once

#include "acdbport.h"
#include "rxobject.h"

#include "../../inc/zembeddedASMEntPE.h"

#ifndef AcDbEmbeddedASMEntPropsPE
#define AcDbEmbeddedASMEntPropsPE		ZcDbEmbeddedZSMEntPropsPE
#endif //#ifndef AcDbEmbeddedASMEntPropsPE

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject
