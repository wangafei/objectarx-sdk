#ifndef __ACDBASSOCGLOBAL_H__
#define __ACDBASSOCGLOBAL_H__

#include "AcDbCore2dDefs.h"
#include "acdb.h"
#include "gepnt3d.h"

#include "../../inc/zAcDbAssocGlobal.h"

#ifndef kAcDbAssocCreateImpObject
#define kAcDbAssocCreateImpObject	kZcDbAssocCreateImpObject
#endif //#ifndef kAcDbAssocCreateImpObject

#ifndef kAcDbAssocDoNotCreateImpObject
#define kAcDbAssocDoNotCreateImpObject	kZcDbAssocDoNotCreateImpObject
#endif //#ifndef kAcDbAssocDoNotCreateImpObject

#ifndef kAcDbPersNullId
#define kAcDbPersNullId	kZcDbPersNullId
#endif //#ifndef kAcDbPersNullId

#ifndef acdbIsExpressionAConstant
#define acdbIsExpressionAConstant	zcdbIsExpressionAConstant
#endif //#ifndef acdbIsExpressionAConstant

#ifndef acdbIsExpressionANegativeConstant
#define acdbIsExpressionANegativeConstant	zcdbIsExpressionANegativeConstant
#endif //#ifndef acdbIsExpressionANegativeConstant

#ifndef acdbIsIdentifier
#define acdbIsIdentifier	zcdbIsIdentifier
#endif //#ifndef acdbIsIdentifier

#ifndef AcArray
#define AcArray	ZcArray
#endif //#ifndef AcArray

#ifndef Acad
#define Acad	Zcad
#endif //#ifndef Acad

#ifndef AcDbObjectId
#define AcDbObjectId	ZcDbObjectId
#endif //#ifndef AcDbObjectId

#ifndef AcDbAssocCreateImpObject
#define AcDbAssocCreateImpObject	ZcDbAssocCreateImpObject
#endif //#ifndef AcDbAssocCreateImpObject

#ifndef AcGeCurve3d
#define AcGeCurve3d	ZcGeCurve3d
#endif //#ifndef AcGeCurve3d

#ifndef AcDb
#define AcDb	ZcDb
#endif //#ifndef AcDb

#ifndef ACDBCORE2D_PORT
#define ACDBCORE2D_PORT	ZCDBCORE2D_PORT
#endif //#ifndef ACDBCORE2D_PORT  

#ifndef AcGePoint3d
#define AcGePoint3d	ZcGePoint3d
#endif //#ifndef AcGePoint3d

#ifndef AcString
#define AcString	ZcString
#endif //#ifndef AcString

#ifndef AcDbAssocActionBody
#define AcDbAssocActionBody		ZcDbAssocActionBody
#endif //#ifndef AcDbAssocActionBody

#ifndef AcDbAssocNetwork
#define AcDbAssocNetwork		ZcDbAssocNetwork
#endif //#ifndef AcDbAssocNetwork

#ifndef AcDbAssocDependency
#define AcDbAssocDependency		ZcDbAssocDependency
#endif //#ifndef AcDbAssocDependency

#ifndef AcDbAssocDependencyBody
#define AcDbAssocDependencyBody		ZcDbAssocDependencyBody
#endif //#ifndef AcDbAssocDependencyBody

#ifndef AcDbAssocGeomDependency
#define AcDbAssocGeomDependency	ZcDbAssocGeomDependency
#endif //#ifndef AcDbAssocGeomDependency   

#ifndef AcDbAssoc2dConstraintGroup
#define AcDbAssoc2dConstraintGroup		ZcDbAssoc2dConstraintGroup
#endif //#ifndef AcDbAssoc2dConstraintGroup

#ifndef AcDbAssocPersSubentId
#define AcDbAssocPersSubentId		ZcDbAssocPersSubentId
#endif //#ifndef AcDbAssocPersSubentId

#ifndef AcDbAssocSimplePersSubentId
#define AcDbAssocSimplePersSubentId		ZcDbAssocSimplePersSubentId
#endif //#ifndef AcDbAssocSimplePersSubentId

#ifndef AcDbAssocSingleEdgePersSubentId
#define AcDbAssocSingleEdgePersSubentId		ZcDbAssocSingleEdgePersSubentId
#endif //#ifndef AcDbAssocSingleEdgePersSubentId

#ifndef AcDbAssocIndexPersSubentId
#define AcDbAssocIndexPersSubentId	ZcDbAssocIndexPersSubentId
#endif //#ifndef AcDbAssocIndexPersSubentId   

#ifndef AcDbAssocExternalIndexPersSubentId
#define AcDbAssocExternalIndexPersSubentId		ZcDbAssocExternalIndexPersSubentId
#endif //#ifndef AcDbAssocExternalIndexPersSubentId

#ifndef AcDbAssocPersSubentIdPE
#define AcDbAssocPersSubentIdPE		ZcDbAssocPersSubentIdPE
#endif //#ifndef AcDbAssocPersSubentIdPE

#ifndef AcDbAssocVariable
#define AcDbAssocVariable		ZcDbAssocVariable
#endif //#ifndef AcDbAssocVariable

#ifndef AcDbAssocValueDependency
#define AcDbAssocValueDependency		ZcDbAssocValueDependency
#endif //#ifndef AcDbAssocValueDependency

#ifndef AcDbAssocValueProviderPE
#define AcDbAssocValueProviderPE	ZcDbAssocValueProviderPE
#endif //#ifndef AcDbAssocValueProviderPE   

#ifndef AcDbEvalContext
#define AcDbEvalContext		ZcDbEvalContext
#endif //#ifndef AcDbEvalContext

#ifndef AcDbAssocPersSubentManager
#define AcDbAssocPersSubentManager		ZcDbAssocPersSubentManager
#endif //#ifndef AcDbAssocPersSubentManager

#ifndef AcDbAssocPersSubentManagerPE
#define AcDbAssocPersSubentManagerPE		ZcDbAssocPersSubentManagerPE
#endif //#ifndef AcDbAssocPersSubentManagerPE

#ifndef AcDbAssocPersSubentManagerCloner
#define AcDbAssocPersSubentManagerCloner		ZcDbAssocPersSubentManagerCloner
#endif //#ifndef AcDbAssocPersSubentManagerCloner

#ifndef AcDbAssocNotificationData
#define AcDbAssocNotificationData	ZcDbAssocNotificationData
#endif //#ifndef AcDbAssocNotificationData   

#ifndef AcDbAsmBodyArray
#define AcDbAsmBodyArray		ZcDbZsmBodyArray
#endif //#ifndef AcDbAsmBodyArray

#ifndef AcDbAsmEntityArray
#define AcDbAsmEntityArray		ZcDbZsmEntityArray
#endif //#ifndef AcDbAsmEntityArray

#ifndef AcDbAsmEdgeArray
#define AcDbAsmEdgeArray		ZcDbZsmEdgeArray
#endif //#ifndef AcDbAsmEdgeArray

#ifndef AcDbAsmFaceArray
#define AcDbAsmFaceArray		ZcDbZsmFaceArray
#endif //#ifndef AcDbAsmFaceArray

#ifndef AcDbAsmEdgeArray2d
#define AcDbAsmEdgeArray2d	ZcDbZsmEdgeArray2d
#endif //#ifndef AcDbAsmEdgeArray2d   

#ifndef AcDbAssocStatus
#define AcDbAssocStatus		ZcDbAssocStatus
#endif //#ifndef AcDbAssocStatus

#ifndef AcDbAssocEvaluationPriority
#define AcDbAssocEvaluationPriority		ZcDbAssocEvaluationPriority
#endif //#ifndef AcDbAssocEvaluationPriority

#ifndef  AcDbAssocEvaluationMode
#define  AcDbAssocEvaluationMode		 ZcDbAssocEvaluationMode
#endif //#ifndef  AcDbAssocEvaluationMode

#ifndef AcDbAssocDraggingState
#define AcDbAssocDraggingState		ZcDbAssocDraggingState
#endif //#ifndef AcDbAssocDraggingState

#ifndef AcDbAssocTransformationType
#define AcDbAssocTransformationType	ZcDbAssocTransformationType
#endif //#ifndef AcDbAssocTransformationType   

#ifndef AcDbAssocEvaluationCallback
#define AcDbAssocEvaluationCallback		ZcDbAssocEvaluationCallback
#endif //#ifndef AcDbAssocEvaluationCallback

#ifndef AcDbObject
#define AcDbObject		ZcDbObject
#endif //#ifndef AcDbObject

#ifndef AcDbPersSubentIdArray
#define AcDbPersSubentIdArray	ZcDbPersSubentIdArray
#endif //#ifndef AcDbPersSubentIdArray   

#ifndef AcDbPersElemIdArray2d
#define AcDbPersElemIdArray2d		ZcDbPersElemIdArray2d
#endif //#ifndef AcDbPersElemIdArray2d

#ifndef AcDbDatabase
#define AcDbDatabase		ZcDbDatabase
#endif //#ifndef AcDbDatabase

#ifndef AcDbPersStepIdArray
#define AcDbPersStepIdArray		ZcDbPersStepIdArray
#endif //#ifndef AcDbPersStepIdArray

#ifndef AcDbPersElemIdArray
#define AcDbPersElemIdArray		ZcDbPersElemIdArray
#endif //#ifndef AcDbPersElemIdArray


#ifndef AcDbPersSubentId
#define AcDbPersSubentId	ZcDbPersSubentId
#endif //#ifndef AcDbPersSubentId   

#ifndef AcDbPersStepId
#define AcDbPersStepId		ZcDbPersStepId
#endif //#ifndef AcDbPersStepId

#ifndef AcDbPersElemId
#define AcDbPersElemId		ZcDbPersElemId
#endif //#ifndef AcDbPersElemId

#ifndef AcDbActionsToEvaluateCallback
#define AcDbActionsToEvaluateCallback		ZcDbActionsToEvaluateCallback
#endif //#ifndef AcDbActionsToEvaluateCallback

#ifndef AcDbAssocAction
#define AcDbAssocAction		ZcDbAssocAction
#endif //#ifndef AcDbAssocAction

#ifndef AcDbEvalVariant
#define AcDbEvalVariant		ZcDbEvalVariant
#endif //#ifndef AcDbEvalVariant

#ifndef AcDbSubentGeometry
#define AcDbSubentGeometry		ZcDbSubentGeometry
#endif //#ifndef AcDbSubentGeometry

#ifndef AcDbAssocConstraintType
#define AcDbAssocConstraintType		ZcDbAssocConstraintType
#endif //#ifndef AcDbAssocConstraintType

#endif //#ifndef __ACDBASSOCGLOBAL_H__
