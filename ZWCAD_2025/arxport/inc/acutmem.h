
#ifndef __ACUTMEM_H__
#define __ACUTMEM_H__

#include "acadstrc.h"   // Acad::ErrorStatus
#include "adesk.h"      
#include "AdAChar.h"    // ACHAR
#include "AcDbCore2dDefs.h"     

#include "../../inc/zacutmem.h"

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef Acad
#define Acad		Zcad
#endif //#ifndef Acad

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acutDelBuffer
#define acutDelBuffer		zcutDelBuffer
#endif //#ifndef acutDelBuffer

#ifndef acutDelString
#define acutDelString		zcutDelString
#endif //#ifndef acutDelString

#ifndef acutNewBuffer
#define acutNewBuffer		zcutNewBuffer
#endif //#ifndef acutNewBuffer

#ifndef acutNewString
#define acutNewString		zcutNewString
#endif //#ifndef acutNewString

#ifndef acutUpdString
#define acutUpdString		zcutUpdString
#endif //#ifndef acutUpdString

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef acutCopyStringToBuffer
#define acutCopyStringToBuffer		zcutCopyStringToBuffer
#endif //#ifndef acutCopyStringToBuffer

#endif //#ifndef __ACUTMEM_H__
