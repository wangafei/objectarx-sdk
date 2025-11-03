/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "dbobjptr2.h"
#include "GcDbAssocActionBody.h"
#include "GcDbAssocDependencyBody.h"
#pragma pack (push, 8)

template<class GCDB_CLASS> class GcDbAssocObjectPointer
{
public:
  GcDbAssocObjectPointer(
    GcDbObjectId                   objectId,
    GcDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  GcDbAssocObjectPointer(
    GcDbAssocAction*               pActionBeingEvaluated,
    GcDbObjectId                   objectId,
    GcDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  GcDbAssocObjectPointer(
    const GcDbAssocActionBody*     pActionBodyBeingEvaluated,
    GcDbObjectId                   objectId,
    GcDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  GcDbAssocObjectPointer(
    const GcDbAssocDependency*     pDependencyBeingEvaluated,
    GcDbObjectId                   objectId,
    GcDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  GcDbAssocObjectPointer(
    const GcDbAssocDependencyBody* pDependencyBodyBeingEvaluated,
    GcDbObjectId                   objectId,
    GcDb::OpenMode                 openMode,
    bool                           openErased = false,
    bool                           openOnLockedLayer = false);

  GcDbAssocObjectPointer(
    GcDbAssocAction*               pActionBeingEvaluated,
    GCDB_CLASS*                    pObject);

  GcDbAssocObjectPointer(
    const GcDbAssocActionBody*     pActionBodyBeingEvaluated,
    GCDB_CLASS*                    pObject);

  ~GcDbAssocObjectPointer();

  Gcad::ErrorStatus openStatus() const;

  bool isSubstituteObject() const { return mpSubstituteObject != NULL; }

  const GCDB_CLASS* operator->() const { return mpObject; }
  GCDB_CLASS* operator->() { return mpObject; }

  operator const GCDB_CLASS*() const { return mpObject; }
  operator GCDB_CLASS*() { return mpObject; }

private:
  GcDbAssocAction* const               mpActionBeingEvaluated;
  const GcDbAssocActionBody* const     mpActionBodyBeingEvaluated;
  const GcDbAssocDependency* const     mpDependencyBeingEvaluated;
  const GcDbAssocDependencyBody* const mpDependencyBodyBeingEvaluated;
  const GcDbObjectId                   mObjectId;
  GcDbSmartObjectPointer<GCDB_CLASS>   mObjectPtr;
  GCDB_CLASS*                          mpObject;
  GcDbObject*                          mpSubstituteObject;
  Gcad::ErrorStatus                    mSubstituteObjectErrorStatus;

private:
  void setup(GcDbAssocAction* pActionBeingEvaluated,
    GcDb::OpenMode   openMode,
    bool             openErased,
    bool             openOnLockedLayer);

  GcDbAssocObjectPointer();
  GcDbAssocObjectPointer(const GcDbAssocObjectPointer&);

  GcDbAssocObjectPointer& operator = (const GcDbAssocObjectPointer&);
};

DBCONSTRAINTS_PORT GcDbAssocAction* gcdbAssocGetCurrentlyEvaluatedActionPointer(const GcDbDatabase*);

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(

  GcDbObjectId      objectId,
  GcDb::OpenMode    openMode,
  bool              openErased,
  bool              openOnLockedLayer)

  : mpActionBeingEvaluated(gcdbAssocGetCurrentlyEvaluatedActionPointer(objectId.database())),
  mpActionBodyBeingEvaluated(NULL),
  mpDependencyBeingEvaluated(NULL),
  mpDependencyBodyBeingEvaluated(NULL),
  mObjectId(objectId),
  mpObject(NULL),
  mpSubstituteObject(NULL),
  mSubstituteObjectErrorStatus(Gcad::eNullObjectId)
{
  setup(mpActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(

  GcDbAssocAction*  pActionBeingEvaluated,
  GcDbObjectId      objectId,
  GcDb::OpenMode    openMode,
  bool              openErased,
  bool              openOnLockedLayer)

  : mpActionBeingEvaluated(pActionBeingEvaluated),
  mpActionBodyBeingEvaluated(NULL),
  mpDependencyBeingEvaluated(NULL),
  mpDependencyBodyBeingEvaluated(NULL),
  mObjectId(objectId),
  mpObject(NULL),
  mpSubstituteObject(NULL),
  mSubstituteObjectErrorStatus(Gcad::eNullObjectId)
{
  setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(

  const GcDbAssocActionBody* pActionBodyBeingEvaluated,
  GcDbObjectId               objectId,
  GcDb::OpenMode             openMode,
  bool                       openErased,
  bool                       openOnLockedLayer)

  : mpActionBeingEvaluated(NULL),
  mpActionBodyBeingEvaluated(pActionBodyBeingEvaluated),
  mpDependencyBeingEvaluated(NULL),
  mpDependencyBodyBeingEvaluated(NULL),
  mObjectId(objectId),
  mpObject(NULL),
  mpSubstituteObject(NULL),
  mSubstituteObjectErrorStatus(Gcad::eNullObjectId)
{
#ifdef ASSERT
  ASSERT(mpActionBodyBeingEvaluated != NULL);
#endif
  GcDbSmartObjectPointer<GcDbAssocAction> pActionBeingEvaluated;

  if (mpActionBodyBeingEvaluated != NULL)
  {
    pActionBeingEvaluated.open(mpActionBodyBeingEvaluated->parentAction(), GcDb::kForRead, true);
  }

  setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(

  const GcDbAssocDependency* pDependencyBeingEvaluated,
  GcDbObjectId               objectId,
  GcDb::OpenMode             openMode,
  bool                       openErased,
  bool                       openOnLockedLayer)

  : mpActionBeingEvaluated(NULL),
  mpActionBodyBeingEvaluated(NULL),
  mpDependencyBeingEvaluated(pDependencyBeingEvaluated),
  mpDependencyBodyBeingEvaluated(NULL),
  mObjectId(objectId),
  mpObject(NULL),
  mpSubstituteObject(NULL),
  mSubstituteObjectErrorStatus(Gcad::eNullObjectId)
{
#ifdef ASSERT
  ASSERT(mpDependencyBeingEvaluated != NULL);
#endif
  GcDbSmartObjectPointer<GcDbAssocAction> pActionBeingEvaluated;

  if (mpDependencyBeingEvaluated != NULL)
  {
    pActionBeingEvaluated.open(mpDependencyBeingEvaluated->owningAction(), GcDb::kForRead, true);
  }

  setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(

  const GcDbAssocDependencyBody* pDependencyBodyBeingEvaluated,
  GcDbObjectId                   objectId,
  GcDb::OpenMode                 openMode,
  bool                           openErased,
  bool                           openOnLockedLayer)

  : mpActionBeingEvaluated(NULL),
  mpActionBodyBeingEvaluated(NULL),
  mpDependencyBeingEvaluated(NULL),
  mpDependencyBodyBeingEvaluated(pDependencyBodyBeingEvaluated),
  mObjectId(objectId),
  mpObject(NULL),
  mpSubstituteObject(NULL),
  mSubstituteObjectErrorStatus(Gcad::eNullObjectId)
{
#ifdef ASSERT
  ASSERT(mpDependencyBodyBeingEvaluated != NULL);
#endif
  GcDbSmartObjectPointer<GcDbAssocAction> pActionBeingEvaluated;

  if (mpDependencyBodyBeingEvaluated != NULL)
  {
    GcDbSmartObjectPointer<GcDbAssocDependency>
      pDependencyBeingEvaluated(mpDependencyBodyBeingEvaluated->parentDependency(), GcDb::kForRead, true);

    if (pDependencyBeingEvaluated.openStatus() == Gcad::eOk)
    {
      pActionBeingEvaluated.open(pDependencyBeingEvaluated->owningAction(), GcDb::kForRead, true);
    }
  }

  setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(

  GcDbAssocAction* pActionBeingEvaluated,
  GCDB_CLASS*      pObject)

  : mpActionBeingEvaluated(pActionBeingEvaluated),
  mpActionBodyBeingEvaluated(NULL),
  mpDependencyBeingEvaluated(NULL),
  mpDependencyBodyBeingEvaluated(NULL),
  mObjectId(GcDbObjectId::kNull),
  mpObject(pObject),
  mpSubstituteObject(pObject),
  mSubstituteObjectErrorStatus(pObject != NULL ? Gcad::eOk : Gcad::eNullObjectId)
{
#ifdef ASSERT
  ASSERT(mpActionBeingEvaluated != NULL);
#endif
  if (pActionBeingEvaluated != NULL)
  {
    GcDbAssocEvaluationCallback* const pCallback
      = pActionBeingEvaluated->currentEvaluationCallback();

    if (pCallback != NULL)
    {
      GcDbObject* pInputObject = pObject;

      pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated,
        GcDbObjectId::kNull,
        true,
        true,
        pInputObject);

#ifdef ASSERT
      ASSERT(pInputObject == pObject);
#endif
    }
  }
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::GcDbAssocObjectPointer(
  const GcDbAssocActionBody* pActionBodyBeingEvaluated,
  GCDB_CLASS*                pObject)
  : mpActionBeingEvaluated(NULL),
  mpActionBodyBeingEvaluated(pActionBodyBeingEvaluated),
  mpDependencyBeingEvaluated(NULL),
  mpDependencyBodyBeingEvaluated(NULL),
  mObjectId(GcDbObjectId::kNull),
  mpObject(pObject),
  mpSubstituteObject(pObject),
  mSubstituteObjectErrorStatus(pObject != NULL ? Gcad::eOk : Gcad::eNullObjectId)
{
#ifdef ASSERT
  ASSERT(mpActionBodyBeingEvaluated != NULL);
#endif
  if (mpActionBodyBeingEvaluated != NULL)
  {
    GcDbSmartObjectPointer<GcDbAssocAction>
      pActionBeingEvaluated(mpActionBodyBeingEvaluated->parentAction(),
        GcDb::kForRead, true);

    if (pActionBeingEvaluated != NULL)
    {
      GcDbAssocEvaluationCallback* const pCallback
        = pActionBeingEvaluated->currentEvaluationCallback();

      if (pCallback != NULL)
      {
        GcDbObject* pInputObject = pObject;

        pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated,
          GcDbObjectId::kNull,
          true,
          true,
          pInputObject);

#ifdef ASSERT
        ASSERT(pInputObject == pObject);
#endif
      }
    }
  }
}

template<class GCDB_CLASS> inline
void GcDbAssocObjectPointer<GCDB_CLASS>::setup(
  GcDbAssocAction* pActionBeingEvaluated,
  GcDb::OpenMode   openMode,
  bool             openErased,
  bool             openOnLockedLayer)
{
  mpObject = NULL;
  mpSubstituteObject = NULL;
  mSubstituteObjectErrorStatus = Gcad::eNullObjectId;

  if (mObjectId.isNull())
    return;

  if (pActionBeingEvaluated != NULL)
  {
    GcDbAssocEvaluationCallback* const pCallback
      = pActionBeingEvaluated->currentEvaluationCallback();

    if (pCallback != NULL)
    {
      pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated,
        mObjectId,
        true,
        openMode == GcDb::kForWrite,
        mpSubstituteObject);

      if (mpSubstituteObject != NULL)
      {
        mpObject = GCDB_CLASS::cast(mpSubstituteObject);
        mSubstituteObjectErrorStatus = mpObject != NULL ? Gcad::eOk : Gcad::eNotThatKindOfClass;
      }
    }
  }

  if (mpSubstituteObject == NULL)
  {
    if (mObjectPtr.open(mObjectId, openMode, openErased, openOnLockedLayer) == Gcad::eOk)
    {
      mpObject = mObjectPtr;
#ifdef ASSERT
      ASSERT(mpObject != NULL);
#endif
    }
  }
}

template<class GCDB_CLASS> inline
GcDbAssocObjectPointer<GCDB_CLASS>::~GcDbAssocObjectPointer()
{
  if (mObjectId.isNull() && mpSubstituteObject == NULL)
    return;

  if (mpActionBeingEvaluated != NULL)
  {
    GcDbAssocEvaluationCallback* const pCallback
      = mpActionBeingEvaluated->currentEvaluationCallback();

    if (pCallback != NULL)
    {
      pCallback->endActionEvaluationUsingObject(mpActionBeingEvaluated, mObjectId, mpObject);
    }
  }
  else
  {
    GcDbSmartObjectPointer<GcDbAssocAction> pActionBeingEvaluated;

    if (mpActionBodyBeingEvaluated != NULL)
    {
      pActionBeingEvaluated.open(mpActionBodyBeingEvaluated->parentAction(), GcDb::kForRead, true);
    }
    else if (mpDependencyBeingEvaluated != NULL)
    {
      pActionBeingEvaluated.open(mpDependencyBeingEvaluated->owningAction(), GcDb::kForRead, true);
    }
    else if (mpDependencyBodyBeingEvaluated != NULL)
    {
      GcDbSmartObjectPointer<GcDbAssocDependency>
        pDependencyBeingEvaluated(mpDependencyBodyBeingEvaluated->parentDependency(), GcDb::kForRead, true);

      if (pDependencyBeingEvaluated.openStatus() == Gcad::eOk)
      {
        pActionBeingEvaluated.open(pDependencyBeingEvaluated->owningAction(), GcDb::kForRead, true);
      }
    }

    if (pActionBeingEvaluated.openStatus() == Gcad::eOk)
    {
      GcDbAssocEvaluationCallback* const pCallback
        = pActionBeingEvaluated->currentEvaluationCallback();

      if (pCallback != NULL)
      {
        pCallback->endActionEvaluationUsingObject(pActionBeingEvaluated, mObjectId, mpObject);
      }
    }
  }
}

template<class GCDB_CLASS> inline
Gcad::ErrorStatus GcDbAssocObjectPointer<GCDB_CLASS>::openStatus() const
{
  return mpSubstituteObject != NULL ? mSubstituteObjectErrorStatus : mObjectPtr.openStatus();
}

#pragma pack (pop)