
#ifndef __DBBLENDOPTIONS_H__
#define __DBBLENDOPTIONS_H__

#include "acdb.h"

#include "../../inc/zdbBlendOptions.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef AcDbBlendOptions
#define AcDbBlendOptions		ZcDbBlendOptions
#endif //#ifndef AcDbBlendOptions

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef AcGePoint3d
#define AcGePoint3d		ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcGeVector3d
#define AcGeVector3d		ZcGeVector3d
#endif //#ifndef AcGeVector3d

#ifndef AcDbImpBlendOptions
#define AcDbImpBlendOptions		ZcDbImpBlendOptions
#endif //#ifndef AcDbImpBlendOptions

#endif	//__DBBLENDOPTIONS_H__
