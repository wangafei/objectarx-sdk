//#pragma once
#ifndef __ZW_DBOBJECT_H__
#define __ZW_DBOBJECT_H__
#include "adesk.h"
#include "AcDbCore2dDefs.h"
#include "drawable.h"
#include "AcHeapOpers.h"
#include "rxobject.h"
#include "acdb.h"
#include "dbboiler.h"
#include "dbptrar.h"
#include "dbidar.h"
#include "../../inc/zdbObject.h"

#ifndef acdbOpenAcDbObject
#define acdbOpenAcDbObject		zcdbOpenZcDbObject
#endif //#ifndef acdbOpenAcDbObject

#ifndef acdbOpenObject
#define acdbOpenObject		zcdbOpenObject
#endif //#ifndef acdbOpenObject

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#endif
