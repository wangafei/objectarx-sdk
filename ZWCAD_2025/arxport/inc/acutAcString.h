
#pragma once
#include "AcDbCore2dDefs.h"
#include "acadstrc.h"
#include "AcString.h"

#include "../../inc/zacutAcString.h"

#ifndef acutNewString
#define acutNewString zcutNewString
#endif

#ifndef ACHAR
#define ACHAR ZTCHAR
#endif

#ifndef acutNewString
#define acutNewString zcutNewString
#endif

#ifndef acutGetAcStringConvertToAChar
#define acutGetAcStringConvertToAChar zcutGetZcStringConvertToZTChar
#endif

#ifndef acutAcStringToAChar
#define acutAcStringToAChar zcutZcStringToZTChar
#endif

