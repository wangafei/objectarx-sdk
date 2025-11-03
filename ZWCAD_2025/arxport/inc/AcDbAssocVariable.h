#ifndef __ACDBASSOCVARIABLE_H__
#define __ACDBASSOCVARIABLE_H__

#include "AcDbAssocValueProviderPE.h"
#include "AcDbAssocAction.h"

#include "../../inc/zAcDbAssocVariable.h"

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT	ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT  

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS	ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef AcDbAssocCreateImpObject
#define AcDbAssocCreateImpObject	ZcDbAssocCreateImpObject
#endif //#ifndef AcDbAssocCreateImpObject

#ifndef AcDbAssocAction
#define AcDbAssocAction	ZcDbAssocAction
#endif //#ifndef AcDbAssocAction

#ifndef kAcDbAssocCreateImpObject
#define kAcDbAssocCreateImpObject	kZcDbAssocCreateImpObject
#endif //#ifndef kAcDbAssocCreateImpObject

#ifndef Acad
#define Acad	Zcad
#endif //#ifndef Acad

#ifndef AcDbObjectId
#define AcDbObjectId	ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcRxClass
#define AcRxClass	ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray	ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcArray
#define AcArray	ZcArray
#endif //#ifndef AcArray

#ifndef AcDbAssocVariable 
#define AcDbAssocVariable ZcDbAssocVariable
#endif //#ifndef AcDbAssocVariable    

#ifndef AcDbEvalVariant
#define AcDbEvalVariant		ZcDbEvalVariant
#endif //#ifndef AcDbEvalVariant

#ifndef AcDbAssocVariableCallback
#define AcDbAssocVariableCallback		ZcDbAssocVariableCallback
#endif //#ifndef AcDbAssocVariableCallback

#endif //#ifndef __ACDBASSOCVARIABLE_H__
