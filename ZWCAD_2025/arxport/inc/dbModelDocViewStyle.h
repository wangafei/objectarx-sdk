
#ifndef __DBMODELDOCVIEWSTYLE_H__
#define __DBMODELDOCVIEWSTYLE_H__

#include "acdbport.h"
#include "dbmain.h"
#include "dbmtext.h"
#include "AcString.h"

#include "../../inc/zdbModelDocViewStyle.h"

#ifndef AcDbImpModelDocViewStyle
#define AcDbImpModelDocViewStyle		ZcDbImpModelDocViewStyle
#endif //#ifndef AcDbImpModelDocViewStyle

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcDbModelDocViewStyle
#define AcDbModelDocViewStyle		ZcDbModelDocViewStyle
#endif //#ifndef AcDbModelDocViewStyle

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef ACDB_DECLARE_MEMBERS
#define ACDB_DECLARE_MEMBERS		ZCDB_DECLARE_MEMBERS
#endif //#ifndef ACDB_DECLARE_MEMBERS

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector2d
#define AcGeVector2d		ZcGeVector2d
#endif //#ifndef AcGeVector2d

#ifndef AcDbMText
#define AcDbMText		ZcDbMText
#endif //#ifndef AcDbMText

#ifndef AcDbIdMapping
#define AcDbIdMapping		ZcDbIdMapping
#endif //#ifndef AcDbIdMapping

#ifndef AcRxObject
#define AcRxObject		ZcRxObject
#endif //#ifndef AcRxObject

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acutGetAcStringConvertToAChar
#define acutGetAcStringConvertToAChar		zcutGetZcStringConvertToZTChar
#endif //#ifndef acutGetAcStringConvertToAChar

#endif //__DBMODELDOCVIEWSTYLE_H__

