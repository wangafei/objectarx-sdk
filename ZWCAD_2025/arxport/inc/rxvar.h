#ifndef __RXVAR_H__
#define __RXVAR_H__

#include "AcDbCore2dDefs.h"
#include "acadstrc.h"
#include "AcString.h"
#include "acarray.h"
#include "rxobject.h"

#include "../../inc/zrxvar.h"

#ifndef ADESK_NO_VTABLE
#define ADESK_NO_VTABLE		ZSOFT_NO_VTABLE
#endif //#ifndef ADESK_NO_VTABLE

#ifndef AcRxVariableChangingEventArgs
#define AcRxVariableChangingEventArgs		ZcRxVariableChangingEventArgs
#endif //#ifndef AcRxVariableChangingEventArgs

#ifndef AcRxVariableChangedEventArgs
#define AcRxVariableChangedEventArgs	ZcRxVariableChangedEventArgs
#endif //#ifndef AcRxVariableChangedEventArgs   

#ifndef AcRxVariablesDictionary
#define AcRxVariablesDictionary		ZcRxVariablesDictionary
#endif //#ifndef AcRxVariablesDictionary

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcRxVariable
#define AcRxVariable		ZcRxVariable
#endif //#ifndef AcRxVariable

#ifndef AcRxImpVariableChangingEventArgs
#define AcRxImpVariableChangingEventArgs	ZcRxImpVariableChangingEventArgs
#endif //#ifndef AcRxImpVariableChangingEventArgs   

#ifndef AcRxImpVariablesDictionary
#define AcRxImpVariablesDictionary		ZcRxImpVariablesDictionary
#endif //#ifndef AcRxImpVariablesDictionary

#ifndef AcRxImpVariablesDirectory
#define AcRxImpVariablesDirectory		ZcRxImpVariablesDirectory
#endif //#ifndef AcRxImpVariablesDirectory

#ifndef AcRxImpVariable
#define AcRxImpVariable		ZcRxImpVariable
#endif //#ifndef AcRxImpVariable

#ifndef AcRxVariableReactor
#define AcRxVariableReactor		ZcRxVariableReactor
#endif //#ifndef AcRxVariableReactor

#ifndef Acad
#define Acad	Zcad
#endif //#ifndef Acad

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef AcArray
#define AcArray	ZcArray
#endif //#ifndef AcArray

#ifndef AcRxObject
#define AcRxObject	ZcRxObject
#endif //#ifndef AcRxObject

#endif //#ifndef __RXVAR_H__
