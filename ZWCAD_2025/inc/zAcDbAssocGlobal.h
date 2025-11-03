
#pragma once
#pragma warning (disable: 4996)
#include "zAcDbCore2dDefs.h"
#include "zacdb.h"
#include "zgepnt3d.h"
#include "zacadstrc.h"
#include "zdbid.h"
#include "zdbmain.h"
#pragma pack (push, 8)

class ZcDbAssocAction;
class ZcDbAssocActionBody;
class ZcDbAssocNetwork;
class ZcDbAssocDependency;
class ZcDbAssocDependencyBody;
class ZcDbAssocGeomDependency;
class ZcDbAssoc2dConstraintGroup;
class ZcDbAssocPersSubentId;
class ZcDbAssocSimplePersSubentId;
class ZcDbAssocSingleEdgePersSubentId;
class ZcDbAssocIndexPersSubentId;
class ZcDbAssocExternalIndexPersSubentId;
class ZcDbAssocPersSubentIdPE;
class ZcDbAssocVariable;
class ZcDbAssocValueDependency;
class ZcDbAssocValueProviderPE;
class ZcDbEvalContext;
class ZcDbAssocPersSubentManager;
class ZcDbAssocPersSubentManagerPE;
class ZcDbAssocPersSubentManagerCloner;
class ZcDbAssocNotificationData;

namespace PersSubentNaming
{
	class AnnotationData;
    class PersSubentManager;
}

class ENTITY;
class COEDGE;
class EDGE;
class LOOP;
class FACE;
class SHELL;
class LUMP;
class BODY;
typedef ZcArray<BODY*>            ZcDbZsmBodyArray;
typedef ZcArray<ENTITY*>          ZcDbZsmEntityArray;
typedef ZcArray<EDGE*>            ZcDbZsmEdgeArray;
typedef ZcArray<FACE*>            ZcDbZsmFaceArray;
typedef ZcArray<ZcDbZsmEdgeArray> ZcDbZsmEdgeArray2d;

enum ZcDbAssocStatus
{

    kIsUpToDateAssocStatus = 0,

    kChangedDirectlyAssocStatus,

    kChangedTransitivelyAssocStatus,

    kChangedNoDifferenceAssocStatus,

    kFailedToEvaluateAssocStatus,

    kErasedAssocStatus,

    kSuppressedAssocStatus,

    kUnresolvedAssocStatus,
};

inline int evaluationRequestSeverityLevel(ZcDbAssocStatus status)
{
    switch (status)
    {
    case kChangedDirectlyAssocStatus:
        return 3;
    case kChangedTransitivelyAssocStatus:
        return 2;
    case kChangedNoDifferenceAssocStatus:
        return 1;
    default:
        return 0;
    }
}

inline bool isEvaluationRequest(ZcDbAssocStatus status)
{
    return evaluationRequestSeverityLevel(status) > 0;
}

inline bool isToBeSkipped(ZcDbAssocStatus status)
{
    return status == kErasedAssocStatus || status == kSuppressedAssocStatus;
}

enum ZcDbAssocEvaluationPriority
{

    kCannotBeEvaluatedAssocEvaluationPriority = -1000,

    kCannotDermineAssocEvaluationPriority = 0,

    kCanBeEvaluatedAssocEvaluationPriority = 1000,
};

enum ZcDbAssocEvaluationMode
{

    kModifyObjectsAssocEvaluationMode,

    kModifyActionAssocEvaluationMode,
};

enum ZcDbAssocDraggingState
{

    kNotDraggingAssocDraggingState,

    kFirstSampleAssocDraggingState,

    kIntermediateSampleAssocDraggingState,

    kLastSampleAssocDraggingState,
};

enum ZcDbAssocTransformationType
{

    kNotSpecified,

    kStretch,

    kRotate,

    kMove,
};

class ZCDBCORE2D_PORT ZcDbAssocEvaluationCallback
{
public:

    ZcDbAssocEvaluationCallback() {}

    virtual ~ZcDbAssocEvaluationCallback() {}

    virtual ZcDbAssocEvaluationMode evaluationMode() const { return kModifyObjectsAssocEvaluationMode; }

    virtual void beginActionEvaluation(ZcDbAssocAction* pAction) = 0;

    virtual void endActionEvaluation(ZcDbAssocAction* pAction) = 0;

    virtual void setActionEvaluationErrorStatus(ZcDbAssocAction*    pAction,
                                                Zcad::ErrorStatus   errorStatus,
                                                const ZcDbObjectId& objectId   = ZcDbObjectId::kNull,
                                                ZcDbObject*         pObject    = NULL,
                                                void*               pErrorInfo = NULL) = 0;

    virtual void
    beginActionEvaluationUsingObject(ZcDbAssocAction*    pAction,
                                     const ZcDbObjectId& objectId,
                                     bool                objectIsGoingToBeUsed,
                                     bool                objectIsGoingToBeModified,
                                     ZcDbObject*&        pSubstituteObject) = 0;

    virtual void endActionEvaluationUsingObject(ZcDbAssocAction*    pAction,
                                                const ZcDbObjectId& objectId,
                                                ZcDbObject*         pObject) = 0;

    virtual void allDependentActionsMarkedToEvaluate(ZcDbAssocNetwork* ) {
    }

    virtual ZcDbAssocDraggingState draggingState() const { return kNotDraggingAssocDraggingState; }

    virtual bool cancelActionEvaluation() { return false; }

    virtual ZcDbEvalContext* getAdditionalData() const { return NULL; }

    virtual ZcDbAssocTransformationType getTransformationType() const { return kNotSpecified; }

};

inline bool isDraggingProvidingSubstituteObjects(const ZcDbAssocEvaluationCallback* pEvaluationCallback)
{
    if (pEvaluationCallback == NULL)
        return false;

    const ZcDbAssocDraggingState draggingState = pEvaluationCallback->draggingState();

    return draggingState == kFirstSampleAssocDraggingState ||
           draggingState == kIntermediateSampleAssocDraggingState;
}

class ZCDBCORE2D_PORT ZcDbActionsToEvaluateCallback
{
public:

    ZcDbActionsToEvaluateCallback() {}

    virtual ~ZcDbActionsToEvaluateCallback() {}

    virtual void needsToEvaluate(const ZcDbObjectId& objectId,
                                 ZcDbAssocStatus     newStatus,
                                 bool                ownedActionsAlso = true) = 0;

};

enum ZCDBCORE2D_PORT ZcDbAssocCreateImpObject
{

    kZcDbAssocCreateImpObject = 0,

    kZcDbAssocDoNotCreateImpObject = 1,
};

typedef unsigned                       ZcDbPersElemId;
typedef ZcDbPersElemId                 ZcDbPersStepId;
typedef ZcDbPersElemId                 ZcDbPersSubentId;
typedef ZcArray<ZcDbPersElemId>        ZcDbPersElemIdArray;
typedef ZcArray<ZcDbPersStepId>        ZcDbPersStepIdArray;
typedef ZcArray<ZcDbPersSubentId>      ZcDbPersSubentIdArray;
typedef ZcArray<ZcDbPersElemIdArray>   ZcDbPersElemIdArray2d;

const ZcDbPersElemId kZcDbPersNullId = 0;

ZCDBCORE2D_PORT Zcad::ErrorStatus checkTopLevelNetworkIntegrity(const ZcDbDatabase*);

enum ZcDbAssocConstraintType
{

    kNoneAssocConstraintType = 0,

    kDistanceAssocConstraintType,

    kHorizontalDistanceAssocConstraintType,

    kVerticalDistanceAssocConstraintType,

    kAngle0AssocConstraintType,

    kAngle1AssocConstraintType,

    kAngle2AssocConstraintType,

    kAngle3AssocConstraintType,

    kRadiusAssocConstraintType,

    kDiameterAssocConstraintType,
};

class ZcGeCurve3d;

class ZCDBCORE2D_PORT ZcDbSubentGeometry
{
public:

    ZcDbSubentGeometry() : mSubentType(ZcDb::kNullSubentType), mpCurve(NULL) {}

    ZcDbSubentGeometry(const ZcGePoint3d& pnt)
        : mSubentType(ZcDb::kVertexSubentType), mPoint(pnt), mpCurve(NULL) {}

    ZcDbSubentGeometry(ZcGeCurve3d* pCurve)
        : mSubentType(ZcDb::kEdgeSubentType), mpCurve(pCurve) {}

    ZcDb::SubentType type() const { return mSubentType; }

    ZcGePoint3d point() const { return mPoint; }

    ZcGeCurve3d* curve() const { return mpCurve; }

private:
    ZcDb::SubentType mSubentType;
    ZcGePoint3d      mPoint;
    ZcGeCurve3d*     mpCurve;
};

class ZcString;
class ZcDbEvalVariant;

ZCDBCORE2D_PORT bool zcdbIsExpressionAConstant(const ZcString& expression, ZcDbEvalVariant& val);
ZCDBCORE2D_PORT bool zcdbIsExpressionANegativeConstant(const ZcString& expression);
ZCDBCORE2D_PORT bool zcdbIsIdentifier(const ZcString& name);

#pragma pack (pop)

