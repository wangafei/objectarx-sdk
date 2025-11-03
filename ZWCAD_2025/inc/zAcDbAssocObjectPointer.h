
#include "zdbobjptr2.h"
#include "zAcDbAssocActionBody.h"
#include "zAcDbAssocDependencyBody.h"
#pragma pack (push, 8)

template<class ZCDB_CLASS> class ZcDbAssocObjectPointer
{
public:

    ZcDbAssocObjectPointer(
        ZcDbObjectId                   objectId,
        ZcDb::OpenMode                 openMode,
        bool                           openErased = false,
        bool                           openOnLockedLayer = false);

    ZcDbAssocObjectPointer(
        ZcDbAssocAction*               pActionBeingEvaluated,
        ZcDbObjectId                   objectId,
        ZcDb::OpenMode                 openMode,
        bool                           openErased = false,
        bool                           openOnLockedLayer = false);

    ZcDbAssocObjectPointer(
        const ZcDbAssocActionBody*     pActionBodyBeingEvaluated,
        ZcDbObjectId                   objectId,
        ZcDb::OpenMode                 openMode,
        bool                           openErased = false,
        bool                           openOnLockedLayer = false);

    ZcDbAssocObjectPointer(
        const ZcDbAssocDependency*     pDependencyBeingEvaluated,
        ZcDbObjectId                   objectId,
        ZcDb::OpenMode                 openMode,
        bool                           openErased = false,
        bool                           openOnLockedLayer = false);

    ZcDbAssocObjectPointer(
        const ZcDbAssocDependencyBody* pDependencyBodyBeingEvaluated,
        ZcDbObjectId                   objectId,
        ZcDb::OpenMode                 openMode,
        bool                           openErased = false,
        bool                           openOnLockedLayer = false);

    ZcDbAssocObjectPointer(
        ZcDbAssocAction*               pActionBeingEvaluated,
        ZCDB_CLASS*                    pObject);

    ZcDbAssocObjectPointer(
        const ZcDbAssocActionBody*     pActionBodyBeingEvaluated,
        ZCDB_CLASS*                    pObject);

    ~ZcDbAssocObjectPointer();

    Zcad::ErrorStatus openStatus() const;

    bool isSubstituteObject() const { return mpSubstituteObject != NULL; }

    const ZCDB_CLASS* operator->() const { return mpObject; }

    ZCDB_CLASS* operator->() { return mpObject; }

    operator const ZCDB_CLASS*() const { return mpObject; }

    operator ZCDB_CLASS*() { return mpObject; }

private:

    ZcDbAssocAction* const               mpActionBeingEvaluated;
    const ZcDbAssocActionBody* const     mpActionBodyBeingEvaluated;
    const ZcDbAssocDependency* const     mpDependencyBeingEvaluated;
    const ZcDbAssocDependencyBody* const mpDependencyBodyBeingEvaluated;
    const ZcDbObjectId                   mObjectId;
    ZcDbSmartObjectPointer<ZCDB_CLASS>   mObjectPtr;
    ZCDB_CLASS*                          mpObject;
    ZcDbObject*                          mpSubstituteObject;
    Zcad::ErrorStatus                    mSubstituteObjectErrorStatus;

private:

    void setup(ZcDbAssocAction* pActionBeingEvaluated,
        ZcDb::OpenMode   openMode,
        bool             openErased,
        bool             openOnLockedLayer);

    ZcDbAssocObjectPointer();

    ZcDbAssocObjectPointer(const ZcDbAssocObjectPointer&);

    ZcDbAssocObjectPointer& operator = (const ZcDbAssocObjectPointer&);

};

ZCDBCORE2D_PORT ZcDbAssocAction* zcdbAssocGetCurrentlyEvaluatedActionPointer(const ZcDbDatabase*);

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    ZcDbObjectId      objectId,
    ZcDb::OpenMode    openMode,
    bool              openErased ,
    bool              openOnLockedLayer)

  : mpActionBeingEvaluated        (zcdbAssocGetCurrentlyEvaluatedActionPointer(objectId.database())),
    mpActionBodyBeingEvaluated    (NULL),
    mpDependencyBeingEvaluated    (NULL),
    mpDependencyBodyBeingEvaluated(NULL),
    mObjectId                     (objectId),
    mpObject                      (NULL),
    mpSubstituteObject            (NULL),
    mSubstituteObjectErrorStatus  (Zcad::eNullObjectId)
{
    setup(mpActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    ZcDbAssocAction*  pActionBeingEvaluated,
    ZcDbObjectId      objectId,
    ZcDb::OpenMode    openMode,
    bool              openErased ,
    bool              openOnLockedLayer)

  : mpActionBeingEvaluated        (pActionBeingEvaluated),
    mpActionBodyBeingEvaluated    (NULL),
    mpDependencyBeingEvaluated    (NULL),
    mpDependencyBodyBeingEvaluated(NULL),
    mObjectId                     (objectId),
    mpObject                      (NULL),
    mpSubstituteObject            (NULL),
    mSubstituteObjectErrorStatus  (Zcad::eNullObjectId)
{
    setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    const ZcDbAssocActionBody* pActionBodyBeingEvaluated,
    ZcDbObjectId               objectId,
    ZcDb::OpenMode             openMode,
    bool                       openErased  ,
    bool                       openOnLockedLayer  )

  : mpActionBeingEvaluated        (NULL),
    mpActionBodyBeingEvaluated    (pActionBodyBeingEvaluated),
    mpDependencyBeingEvaluated    (NULL),
    mpDependencyBodyBeingEvaluated(NULL),
    mObjectId                     (objectId),
    mpObject                      (NULL),
    mpSubstituteObject            (NULL),
    mSubstituteObjectErrorStatus  (Zcad::eNullObjectId)
{
#ifdef ASSERT
    ASSERT(mpActionBodyBeingEvaluated != NULL);
#endif
    ZcDbSmartObjectPointer<ZcDbAssocAction> pActionBeingEvaluated;

    if (mpActionBodyBeingEvaluated != NULL)
    {
        pActionBeingEvaluated.open(mpActionBodyBeingEvaluated->parentAction(), ZcDb::kForRead, true);
    }

    setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    const ZcDbAssocDependency* pDependencyBeingEvaluated,
    ZcDbObjectId               objectId,
    ZcDb::OpenMode             openMode,
    bool                       openErased  ,
    bool                       openOnLockedLayer  )

  : mpActionBeingEvaluated        (NULL),
    mpActionBodyBeingEvaluated    (NULL),
    mpDependencyBeingEvaluated    (pDependencyBeingEvaluated),
    mpDependencyBodyBeingEvaluated(NULL),
    mObjectId                     (objectId),
    mpObject                      (NULL),
    mpSubstituteObject            (NULL),
    mSubstituteObjectErrorStatus  (Zcad::eNullObjectId)
{
#ifdef ASSERT
    ASSERT(mpDependencyBeingEvaluated != NULL);
#endif
    ZcDbSmartObjectPointer<ZcDbAssocAction> pActionBeingEvaluated;

    if (mpDependencyBeingEvaluated != NULL)
    {
        pActionBeingEvaluated.open(mpDependencyBeingEvaluated->owningAction(), ZcDb::kForRead, true);
    }

    setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    const ZcDbAssocDependencyBody* pDependencyBodyBeingEvaluated,
    ZcDbObjectId                   objectId,
    ZcDb::OpenMode                 openMode,
    bool                           openErased ,
    bool                           openOnLockedLayer)

  : mpActionBeingEvaluated        (NULL),
    mpActionBodyBeingEvaluated    (NULL),
    mpDependencyBeingEvaluated    (NULL),
    mpDependencyBodyBeingEvaluated(pDependencyBodyBeingEvaluated),
    mObjectId                     (objectId),
    mpObject                      (NULL),
    mpSubstituteObject            (NULL),
    mSubstituteObjectErrorStatus  (Zcad::eNullObjectId)
{
#ifdef ASSERT
    ASSERT(mpDependencyBodyBeingEvaluated != NULL);
#endif
    ZcDbSmartObjectPointer<ZcDbAssocAction> pActionBeingEvaluated;

    if (mpDependencyBodyBeingEvaluated != NULL)
    {
        ZcDbSmartObjectPointer<ZcDbAssocDependency>
            pDependencyBeingEvaluated(mpDependencyBodyBeingEvaluated->parentDependency(), ZcDb::kForRead, true);

        if (pDependencyBeingEvaluated.openStatus() == Zcad::eOk)
        {
            pActionBeingEvaluated.open(pDependencyBeingEvaluated->owningAction(), ZcDb::kForRead, true);
        }
    }

    setup(pActionBeingEvaluated, openMode, openErased, openOnLockedLayer);
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    ZcDbAssocAction* pActionBeingEvaluated,
    ZCDB_CLASS*      pObject)

  : mpActionBeingEvaluated        (pActionBeingEvaluated),
    mpActionBodyBeingEvaluated    (NULL),
    mpDependencyBeingEvaluated    (NULL),
    mpDependencyBodyBeingEvaluated(NULL),
    mObjectId                     (ZcDbObjectId::kNull),
    mpObject                      (pObject),
    mpSubstituteObject            (pObject),
    mSubstituteObjectErrorStatus  (pObject != NULL ? Zcad::eOk : Zcad::eNullObjectId)
{
#ifdef ASSERT
    ASSERT(mpActionBeingEvaluated != NULL);
#endif
    if (pActionBeingEvaluated != NULL)
    {
        ZcDbAssocEvaluationCallback* const pCallback
            = pActionBeingEvaluated->currentEvaluationCallback();

        if (pCallback != NULL)
        {
            ZcDbObject* pInputObject = pObject;

            pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated,
                ZcDbObjectId::kNull,
                true,
                true,
                pInputObject);

#ifdef ASSERT
            ASSERT(pInputObject == pObject);
#endif
        }
    }
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::ZcDbAssocObjectPointer(

    const ZcDbAssocActionBody* pActionBodyBeingEvaluated,
    ZCDB_CLASS*                pObject)

    : mpActionBeingEvaluated        (NULL),
    mpActionBodyBeingEvaluated    (pActionBodyBeingEvaluated),
    mpDependencyBeingEvaluated    (NULL),
    mpDependencyBodyBeingEvaluated(NULL),
    mObjectId                     (ZcDbObjectId::kNull),
    mpObject                      (pObject),
    mpSubstituteObject            (pObject),
    mSubstituteObjectErrorStatus  (pObject != NULL ? Zcad::eOk : Zcad::eNullObjectId)
{
#ifdef ASSERT
    ASSERT(mpActionBodyBeingEvaluated != NULL);
#endif
    if (mpActionBodyBeingEvaluated != NULL)
    {
        ZcDbSmartObjectPointer<ZcDbAssocAction>
            pActionBeingEvaluated(mpActionBodyBeingEvaluated->parentAction(),
            ZcDb::kForRead, true);

        if (pActionBeingEvaluated != NULL)
        {
            ZcDbAssocEvaluationCallback* const pCallback
                = pActionBeingEvaluated->currentEvaluationCallback();

            if (pCallback != NULL)
            {
                ZcDbObject* pInputObject = pObject;

                pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated,
                    ZcDbObjectId::kNull,
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

template<class ZCDB_CLASS> inline
void ZcDbAssocObjectPointer<ZCDB_CLASS>::setup(

    ZcDbAssocAction* pActionBeingEvaluated,
    ZcDb::OpenMode   openMode,
    bool             openErased,
    bool             openOnLockedLayer)
{
    mpObject                     = NULL;
    mpSubstituteObject           = NULL;
    mSubstituteObjectErrorStatus = Zcad::eNullObjectId;

    if (mObjectId.isNull())
        return;

    if (pActionBeingEvaluated != NULL)
    {
        ZcDbAssocEvaluationCallback* const pCallback
            = pActionBeingEvaluated->currentEvaluationCallback();

        if (pCallback != NULL)
        {
            pCallback->beginActionEvaluationUsingObject(pActionBeingEvaluated,
                mObjectId,
                true,
                openMode == ZcDb::kForWrite,
                mpSubstituteObject);

            if (mpSubstituteObject != NULL)
            {
                mpObject                     = ZCDB_CLASS::cast(mpSubstituteObject);
                mSubstituteObjectErrorStatus = mpObject != NULL ? Zcad::eOk : Zcad::eNotThatKindOfClass;
            }
        }
    }

    if (mpSubstituteObject == NULL)
    {
        if (mObjectPtr.open(mObjectId, openMode, openErased, openOnLockedLayer) == Zcad::eOk)
        {
            mpObject = mObjectPtr;
#ifdef ASSERT
            ASSERT(mpObject != NULL);
#endif
        }
    }
}

template<class ZCDB_CLASS> inline
ZcDbAssocObjectPointer<ZCDB_CLASS>::~ZcDbAssocObjectPointer()
{
    if (mObjectId.isNull() && mpSubstituteObject == NULL)
        return;

    if (mpActionBeingEvaluated != NULL)
    {
        ZcDbAssocEvaluationCallback* const pCallback
            = mpActionBeingEvaluated->currentEvaluationCallback();

        if (pCallback != NULL)
        {
            pCallback->endActionEvaluationUsingObject(mpActionBeingEvaluated, mObjectId, mpObject);
        }
    }
    else
    {
        ZcDbSmartObjectPointer<ZcDbAssocAction> pActionBeingEvaluated;

        if (mpActionBodyBeingEvaluated != NULL)
        {
            pActionBeingEvaluated.open(mpActionBodyBeingEvaluated->parentAction(), ZcDb::kForRead, true);
        }
        else if (mpDependencyBeingEvaluated != NULL)
        {
            pActionBeingEvaluated.open(mpDependencyBeingEvaluated->owningAction(), ZcDb::kForRead, true);
        }
        else if (mpDependencyBodyBeingEvaluated != NULL)
        {
            ZcDbSmartObjectPointer<ZcDbAssocDependency>
                pDependencyBeingEvaluated(mpDependencyBodyBeingEvaluated->parentDependency(), ZcDb::kForRead, true);

            if (pDependencyBeingEvaluated.openStatus() == Zcad::eOk)
            {
                pActionBeingEvaluated.open(pDependencyBeingEvaluated->owningAction(), ZcDb::kForRead, true);
            }
        }

        if (pActionBeingEvaluated.openStatus() == Zcad::eOk)
        {
            ZcDbAssocEvaluationCallback* const pCallback
                = pActionBeingEvaluated->currentEvaluationCallback();

            if (pCallback != NULL)
            {
                pCallback->endActionEvaluationUsingObject(pActionBeingEvaluated, mObjectId, mpObject);
            }
        }
    }
}

template<class ZCDB_CLASS> inline
Zcad::ErrorStatus ZcDbAssocObjectPointer<ZCDB_CLASS>::openStatus() const
{
    return mpSubstituteObject != NULL ? mSubstituteObjectErrorStatus : mObjectPtr.openStatus();
}

#pragma pack (pop)
