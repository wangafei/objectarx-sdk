
#ifndef __AXLOCK_H__
#define __AXLOCK_H__

#include "acadstrc.h"
#include "AcDbCore2dDefs.h"

#include "../../inc/zaxlock.h"

#ifndef AcAxDocLock
#define AcAxDocLock		ZcAxDocLock
#endif //#ifndef AcAxDocLock

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbObjectId
#define AcDbObjectId		ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#endif //#ifndef __AXLOCK_H__
