
#ifndef __DBDATE_H__
#define __DBDATE_H__

#include "acdb.h"
#include "acadstrc.h"           
#include "AcDbCore2dDefs.h"     
#include "acdbport.h"           


#include "../../inc/zdbdate.h"

#ifndef AcDbDate
#define AcDbDate		ZcDbDate
#endif //#ifndef AcDbDate

#ifndef AcDbDwgFiler
#define AcDbDwgFiler		ZcDbDwgFiler
#endif //#ifndef AcDbDwgFiler

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#endif //#ifndef __DBDATE_H__
