
#ifndef _AD_DBID_H
#define _AD_DBID_H

#include "adesk.h"
#include "dbhandle.h"
#include "AcDbCore2dDefs.h"     

#include "../../inc/zdbid.h"

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbHandle
#define AcDbHandle		ZcDbHandle
#endif //#ifndef AcDbHandle

#ifndef AcDbHardOwnershipId
#define AcDbHardOwnershipId		ZcDbHardOwnershipId
#endif //#ifndef AcDbHardOwnershipId

#ifndef AcDbHardPointerId
#define AcDbHardPointerId		ZcDbHardPointerId
#endif //#ifndef AcDbHardPointerId

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbSoftOwnershipId
#define AcDbSoftOwnershipId		ZcDbSoftOwnershipId
#endif //#ifndef AcDbSoftOwnershipId

#ifndef AcDbSoftPointerId
#define AcDbSoftPointerId		ZcDbSoftPointerId
#endif //#ifndef AcDbSoftPointerId

#ifndef AcDbStub
#define AcDbStub		ZcDbStub
#endif //#ifndef AcDbStub

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef _ADESK_WINDOWS_
#define _ADESK_WINDOWS_		_ZSOFT_WINDOWS_
#endif //#ifndef _ADESK_WINDOWS_

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef ADESK_ACDBOBJECTID_DEFINED
#define ADESK_ACDBOBJECTID_DEFINED		ZSOFT_ZCDBOBJECTID_DEFINED
#endif //#ifndef ADESK_ACDBOBJECTID_DEFINED

#endif //#ifndef _AD_DBID_H
