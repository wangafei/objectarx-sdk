#ifndef __ACDBASSOCACTION_H__
#define __ACDBASSOCACTION_H__

#include "AcDbAssocGlobal.h"
#include "dbEval.h"
#include "AcValue.h"

#include "../../inc/zAcDbAssocAction.h"

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT		ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT

#ifndef AcDbAssocAction
#define AcDbAssocAction		ZcDbAssocAction
#endif //#ifndef AcDbAssocAction

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef ACRX_DECLARE_MEMBERS
#define ACRX_DECLARE_MEMBERS		ZCRX_DECLARE_MEMBERS
#endif //#ifndef ACRX_DECLARE_MEMBERS

#ifndef kAcDbAssocCreateImpObject
#define kAcDbAssocCreateImpObject		kZcDbAssocCreateImpObject
#endif //#ifndef kAcDbAssocCreateImpObject

#ifndef AcDbAssocCreateImpObject
#define AcDbAssocCreateImpObject		ZcDbAssocCreateImpObject
#endif //#ifndef AcDbAssocCreateImpObject

#ifndef     AcDbIdMapping
#define     AcDbIdMapping		    ZcDbIdMapping
#endif //#ifndef    AcDbIdMapping

#ifndef     AcDbObjectId
#define     AcDbObjectId		    ZcDbObjectId
#endif //#ifndef    AcDbObjectId

#ifndef     AcDb
#define     AcDb		    ZcDb
#endif //#ifndef    AcDb

#ifndef     Acad
#define     Acad		    Zcad
#endif //#ifndef     Acad

#ifndef AcDbAssocStatus
#define AcDbAssocStatus		ZcDbAssocStatus
#endif //#ifndef AcDbAssocStatus

#ifndef AcDbObjectIdArray
#define AcDbObjectIdArray		ZcDbObjectIdArray
#endif //#ifndef AcDbObjectIdArray

#ifndef AcRxClass
#define AcRxClass		ZcRxClass
#endif //#ifndef AcRxClass

#ifndef AcDbAssocDependency
#define AcDbAssocDependency		ZcDbAssocDependency
#endif //#ifndef AcDbAssocDependency

#ifndef AcDbAssocNotificationData
#define AcDbAssocNotificationData		ZcDbAssocNotificationData
#endif //#ifndef AcDbAssocNotificationData

#ifndef AcDbAssocEvaluationCallback
#define AcDbAssocEvaluationCallback		ZcDbAssocEvaluationCallback
#endif //#ifndef AcDbAssocEvaluationCallback

#ifndef AcDbAssocStatus
#define AcDbAssocStatus		ZcDbAssocStatus
#endif //#ifndef AcDbAssocStatus

#ifndef AcDbAssocEvaluationPriority
#define AcDbAssocEvaluationPriority		ZcDbAssocEvaluationPriority
#endif //#ifndef AcDbAssocEvaluationPriority

#ifndef AcDbActionsToEvaluateCallback
#define AcDbActionsToEvaluateCallback		ZcDbActionsToEvaluateCallback
#endif //#ifndef AcDbActionsToEvaluateCallback

#ifndef AcString
#define AcString		ZcString
#endif //#ifndef AcString

#ifndef AcArray
#define AcArray		ZcArray
#endif //#ifndef AcArray

#ifndef AcDbEvalVariant
#define AcDbEvalVariant		ZcDbEvalVariant
#endif //#ifndef AcDbEvalVariant

#ifndef AcValue
#define AcValue		ZcValue
#endif //#ifndef AcValue

#ifndef AcGeMatrix3d
#define AcGeMatrix3d		ZcGeMatrix3d
#endif //#ifndef AcGeMatrix3d

#ifndef AcDbImpAssocAction
#define AcDbImpAssocAction		ZcDbImpAssocAction
#endif //#ifndef AcDbImpAssocAction

#endif