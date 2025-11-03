/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma warning (disable: 4996)
#include "GcDbCore2dDefs.h"
#include "gcdb.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class GcDbAssocAction;
class GcDbAssocActionBody;
class GcDbAssocNetwork;
class GcDbAssocDependency;
class GcDbAssocDependencyBody;
class GcDbAssocGeomDependency;
class GcDbAssoc2dConstraintGroup;
class GcDbAssocPersSubentId;
class GcDbAssocSimplePersSubentId;
class GcDbAssocSingleEdgePersSubentId;
class GcDbAssocIndexPersSubentId;
class GcDbAssocExternalIndexPersSubentId;
class GcDbAssocPersSubentIdPE;
class GcDbAssocVariable;
class GcDbAssocValueDependency;
class GcDbAssocValueProviderPE;
class GcDbEvalContext;
class GcDbAssocPersSubentManager;
class GcDbAssocPersSubentManagerPE;
class GcDbAssocPersSubentManagerCloner;
class GcDbAssocNotificationData;

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
typedef GcArray<BODY*>            GcDbAsmBodyArray;
typedef GcArray<ENTITY*>          GcDbAsmEntityArray;
typedef GcArray<EDGE*>            GcDbAsmEdgeArray;
typedef GcArray<FACE*>            GcDbAsmFaceArray;
typedef GcArray<GcDbAsmEdgeArray> GcDbAsmEdgeArray2d;

enum GcDbAssocStatus
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

inline int evaluationRequestSeverityLevel(GcDbAssocStatus status)
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

inline bool isEvaluationRequest(GcDbAssocStatus status)
{
  return evaluationRequestSeverityLevel(status) > 0;
}

inline bool isToBeSkipped(GcDbAssocStatus status)
{
  return status == kErasedAssocStatus || status == kSuppressedAssocStatus;
}

enum GcDbAssocEvaluationPriority
{
  kCannotBeEvaluatedAssocEvaluationPriority = -1000,
  kCannotDermineAssocEvaluationPriority = 0,
  kCanBeEvaluatedAssocEvaluationPriority = 1000,
};

enum GcDbAssocEvaluationMode
{
  kModifyObjectsAssocEvaluationMode,
  kModifyActionAssocEvaluationMode,
};

enum GcDbAssocDraggingState
{
  kNotDraggingAssocDraggingState,
  kFirstSampleAssocDraggingState,
  kIntermediateSampleAssocDraggingState,
  kLastSampleAssocDraggingState,
};

enum GcDbAssocTransformationType
{
  kNotSpecified,
  kStretch,
  kRotate,
  kMove,
};

class GcDbAssocEvaluationCallback
{
public:
  GcDbAssocEvaluationCallback() {}
  virtual ~GcDbAssocEvaluationCallback() {}

  virtual GcDbAssocEvaluationMode evaluationMode() const { return kModifyObjectsAssocEvaluationMode; }

  virtual void beginActionEvaluation(GcDbAssocAction* pAction) = 0;
  virtual void endActionEvaluation(GcDbAssocAction* pAction) = 0;

  virtual void setActionEvaluationErrorStatus(GcDbAssocAction*    pAction,
    Gcad::ErrorStatus   errorStatus,
    const GcDbObjectId& objectId = GcDbObjectId::kNull,
    GcDbObject*         pObject = NULL,
    void*               pErrorInfo = NULL) = 0;
  virtual void beginActionEvaluationUsingObject(GcDbAssocAction*    pAction,
      const GcDbObjectId& objectId,
      bool                objectIsGoingToBeUsed,
      bool                objectIsGoingToBeModified,
      GcDbObject*&        pSubstituteObject) = 0;
  virtual void endActionEvaluationUsingObject(GcDbAssocAction*    pAction,
    const GcDbObjectId& objectId,
    GcDbObject*         pObject) = 0;

  virtual void allDependentActionsMarkedToEvaluate(GcDbAssocNetwork*) {}
  virtual GcDbAssocDraggingState draggingState() const { return kNotDraggingAssocDraggingState; }
  virtual bool cancelActionEvaluation() { return false; }
  virtual GcDbEvalContext* getAdditionalData() const { return NULL; }
  virtual GcDbAssocTransformationType getTransformationType() const { return kNotSpecified; }
};

inline bool isDraggingProvidingSubstituteObjects(const GcDbAssocEvaluationCallback* pEvaluationCallback)
{
  if (pEvaluationCallback == NULL)
    return false;

  const GcDbAssocDraggingState draggingState = pEvaluationCallback->draggingState();

  return draggingState == kFirstSampleAssocDraggingState ||
    draggingState == kIntermediateSampleAssocDraggingState;
}

class GcDbActionsToEvaluateCallback
{
public:
  GcDbActionsToEvaluateCallback() {}
  virtual ~GcDbActionsToEvaluateCallback() {}

  virtual void needsToEvaluate(const GcDbObjectId& objectId,
    GcDbAssocStatus     newStatus,
    bool                ownedActionsAlso = true) = 0;

};

enum GcDbAssocCreateImpObject
{
  kGcDbAssocCreateImpObject = 0,
  kGcDbAssocDoNotCreateImpObject = 1,
};

typedef unsigned                       GcDbPersElemId;
typedef GcDbPersElemId                 GcDbPersStepId;
typedef GcDbPersElemId                 GcDbPersSubentId;
typedef GcArray<GcDbPersElemId>        GcDbPersElemIdArray;
typedef GcArray<GcDbPersStepId>        GcDbPersStepIdArray;
typedef GcArray<GcDbPersSubentId>      GcDbPersSubentIdArray;
typedef GcArray<GcDbPersElemIdArray>   GcDbPersElemIdArray2d;

const GcDbPersElemId kGcDbPersNullId = 0;

DBCONSTRAINTS_PORT Gcad::ErrorStatus checkTopLevelNetworkIntegrity(const GcDbDatabase*);

enum GcDbAssocConstraintType
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

class GcGeCurve3d;

class GcDbSubentGeometry
{
public:
  GcDbSubentGeometry() : mSubentType(GcDb::kNullSubentType), mpCurve(NULL) {}

  GcDbSubentGeometry(const GcGePoint3d& pnt)
    : mSubentType(GcDb::kVertexSubentType), mPoint(pnt), mpCurve(NULL) {}
  GcDbSubentGeometry(GcGeCurve3d* pCurve)
    : mSubentType(GcDb::kEdgeSubentType), mpCurve(pCurve) {}

  GcDb::SubentType type() const { return mSubentType; }
  GcGePoint3d      point() const { return mPoint; }
  GcGeCurve3d*     curve() const { return mpCurve; }

private:
  GcDb::SubentType mSubentType;
  GcGePoint3d      mPoint;
  GcGeCurve3d*     mpCurve;
};

class GcString;
class GcDbEvalVariant;

GCCORE_PORT bool gcdbIsExpressionAConstant(const GcString& expression, GcDbEvalVariant& val);
GCCORE_PORT bool gcdbIsExpressionANegativeConstant(const GcString& expression);
GCCORE_PORT bool gcdbIsIdentifier(const GcString& name);

#pragma pack (pop)