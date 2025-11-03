
#ifndef ZD_DBOBJPTR2_H
#define ZD_DBOBJPTR2_H

#include "zdbobjptr.h"


ZCDBCORE2D_PORT Zcad::ErrorStatus 
        accessZcDbObjectForRead(ZcDbObject * & pObj,
                                ZcDbObjectId id,
                                ZcRxClass * (*pfDesc)(),
                                bool &bWasOpened,
                                bool bOpenErased);

using getClassDescFuncType = decltype(ZcRxClass::desc);

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC = ZCDB_CLASS::desc> inline Zcad::ErrorStatus
        accessZcDbObjectForRead(ZCDB_CLASS * & pObj,
                                ZcDbObjectId id,
                                bool &bWasOpened,
                                bool bOpenErased = false)
{
    constexpr auto pGetClassDescFunc = ZCDB_GET_CLASS_DESC;
    DbObjPtr_Assert(pGetClassDescFunc);
    if (!pGetClassDescFunc)
        return Zcad::eInvalidInput;
    return ::accessZcDbObjectForRead((ZcDbObject * &)pObj,
                                     id,
                                     pGetClassDescFunc,
                                     bWasOpened, bOpenErased);
};


template<> inline Zcad::ErrorStatus
        accessZcDbObjectForRead<ZcDbObject, nullptr>(ZcDbObject * & pObj,
                                ZcDbObjectId id,
                                bool &bWasOpened,
                                bool bOpenErased)
{
    return ::accessZcDbObjectForRead(pObj, id, /*pfDesc*/nullptr,
                                     bWasOpened, bOpenErased);
}


template<class, getClassDescFuncType> class ZcDbSmartObjectPointer;

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC=ZCDB_CLASS::desc>
class ReadableZcDbObject {
public:
    ReadableZcDbObject()
    {
    }

    ReadableZcDbObject(ZCDB_CLASS*& pObj, ZcDbObjectId id,
                       bool bOpenErased, bool enableNow = true)
    {
        if (enableNow)
            enableRead(pObj, id, bOpenErased);
    }

    
    ReadableZcDbObject (const ReadableZcDbObject &) = delete;
    ReadableZcDbObject & operator = (const ReadableZcDbObject &) = delete;

    void enableRead(ZCDB_CLASS*& pObj,
                    ZcDbObjectId id,
                    bool bOpenErased)
    {
        revertRead();
        pObj = NULL;
        if (Zcad::eNotOpenForRead == mEs) {
            mEs = accessZcDbObjectForRead<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>(pObj,
                                          id,
                                          mbWasOpened,
                                          bOpenErased);
            DbObjPtr_Assert((Zcad::eOk == mEs) == (NULL != pObj));
            DbObjPtr_Assert((NULL != pObj) ? pObj->isReadEnabled() : true);
            mpObj = pObj;
        }
    };

    void revertRead()
    {
        if (mpObj) {
            if (mpObj->objectId().isNull()) {
                delete mpObj;
            }
            else if ((Zcad::eOk == mEs) && mbWasOpened)
            {
                mEs = mpObj->close();
            }
            mpObj = NULL;
        }
        mEs = Zcad::eNotOpenForRead;
    };

    ~ReadableZcDbObject()
    {
        revertRead();
    };

    bool isReadable() const
    {
        return ((NULL != mpObj) && mpObj->isReadEnabled());
    };

    const ZCDB_CLASS* object() const
    {
        return Zcad::eOk == mEs ? mpObj : NULL; 
    };

    
    
    
    ZCDB_CLASS*       object()
    {
        return Zcad::eOk == mEs ? mpObj : NULL; 
    };

    Zcad::ErrorStatus statusCode() const
    {
        return mEs;
    };
private:
    ZCDB_CLASS*       mpObj {nullptr};
    Zcad::ErrorStatus mEs {Zcad::eNotOpenForRead};
    bool              mbWasOpened {false};

    template<class, getClassDescFuncType>
    friend class ZcDbSmartObjectPointer;
    
    ReadableZcDbObject(ZcDbObjectId id,
                       bool bOpenErased, bool enableNow = true)
    :  mpObj(NULL),
    mEs(Zcad::eNotOpenForRead)
    {
        if (enableNow)
            enableRead(mpObj, id, bOpenErased);
    }
    
    void forgetCurrentAndAcceptNewAsIs(ZCDB_CLASS* pNewObj)
    {
        if (mpObj != pNewObj) {
            mpObj = pNewObj;
            mEs = (NULL == mpObj) ? Zcad::eNotOpenForRead : Zcad::eOk;
            mbWasOpened = (NULL != mpObj);
        }
    };
};

ZCDBCORE2D_PORT Zcad::ErrorStatus
accessZcDbObjectForWrite(ZcDbObject *pObj,
                         bool &bWasNotifyEnabled,
                         bool &bWasWriteEnabled,
                         int  &readCountClosed,
                         bool openOnLockedLayer);

ZCDBCORE2D_PORT Zcad::ErrorStatus
revertZcDbObjectFromWrite(ZcDbObject *pObj,
                          Zcad::ErrorStatus accessStatus,
                          bool bWasNotifyEnabled,
                          bool bWasWriteEnabled,
                          int  readCountClosed);

class WritableZcDbObject {
public:
    WritableZcDbObject()
        :  mbOpenOnLockedLayer(false)
    {
    }

    WritableZcDbObject(ZcDbObject* pObj, bool enableNow = true, bool openOnLockedLayer = false)
        : mbOpenOnLockedLayer(openOnLockedLayer)
    {
        replaceObject(pObj, enableNow);
    }

    
    WritableZcDbObject(const WritableZcDbObject &) = delete;
    WritableZcDbObject operator = (const WritableZcDbObject &) = delete;

    void replaceObject(ZcDbObject* pObj, bool enableNow = true)
    {
        revertWrite();
        mpObj = pObj;
        if (NULL == pObj) {
            mEs = Zcad::eNullObjectPointer;
            return;
        }
        mEs = Zcad::eNotOpenForWrite;
        if (enableNow)
            enableWrite();
    }

    bool enableWrite() {
        if (isWritable())
            return true;
        if (NULL == mpObj)
            return false;
        mEs = accessZcDbObjectForWrite(mpObj,
                                       mbWasNotifyEnabled,
                                       mbWasWriteEnabled,
                                       mReadCountClosed,
                                       mbOpenOnLockedLayer);
        return isWritable();
    };

    void revertWrite()
    {
        if ((NULL != mpObj) && !mpObj->objectId().isNull())
            mEs = revertZcDbObjectFromWrite(mpObj,
                                            mEs,
                                            mbWasNotifyEnabled,
                                            mbWasWriteEnabled,
                                            mReadCountClosed);
        forget();
    };

    ~WritableZcDbObject()
    {
        revertWrite();
    };

    bool isWritable() const
    {
        return (Zcad::eOk == mEs);
    };

    Zcad::ErrorStatus statusCode() const
    {
        return mEs;
    };

    void forget()
    {
        mpObj = NULL;
        mEs = Zcad::eNullObjectPointer;
    };

    void setOpenOnLockedLayer(bool openOnLockedLayer)
    {
        mbOpenOnLockedLayer = openOnLockedLayer;
    }

private:
    ZcDbObject*       mpObj {nullptr};
    Zcad::ErrorStatus mEs {Zcad::eNullObjectPointer};
    bool              mbWasNotifyEnabled = false;
    bool              mbWasWriteEnabled = false;
    bool              mbOpenOnLockedLayer;  
    int               mReadCountClosed {0};
};

#pragma pack (push, 8)

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC=ZCDB_CLASS::desc>
class ZcDbSmartObjectPointer
{
public:
    ZcDbSmartObjectPointer();
    ZcDbSmartObjectPointer(ZcDbObjectId   objId,
                           ZcDb::OpenMode mode = ZcDb::kForRead,
                           bool           openErased = false,
                           bool           openOnLockedLayer = false);
    ~ZcDbSmartObjectPointer();  
    
    ZcDbSmartObjectPointer(const ZcDbSmartObjectPointer &) = delete;
    ZcDbSmartObjectPointer & operator = (const ZcDbSmartObjectPointer &) = delete;

    const ZCDB_CLASS* object() const;
    ZCDB_CLASS*       object();

    const ZCDB_CLASS* operator->() const;
    ZCDB_CLASS*       operator->();
                      operator const ZCDB_CLASS*() const;
#if DBOBJPTR_EXPOSE_PTR_REF
                      ZcDbSmartObjectPointer(ZCDB_CLASS *pObject);
                      operator ZCDB_CLASS* &();
    void              operator=(ZCDB_CLASS *pObject);
#else
                      operator ZCDB_CLASS*();
#endif

    Zcad::ErrorStatus openStatus() const;

    Zcad::ErrorStatus open(ZcDbObjectId   objId,
                           ZcDb::OpenMode mode = ZcDb::kForRead,
                           bool           openErased = false,
                           bool           openOnLockedLayer = false);

    Zcad::ErrorStatus acquire(ZCDB_CLASS *& pObjToAcquire);
    Zcad::ErrorStatus release(ZCDB_CLASS *& pReleasedObj);
    Zcad::ErrorStatus close();

    Zcad::ErrorStatus create();
protected:
    ReadableZcDbObject<ZCDB_CLASS, ZCDB_GET_CLASS_DESC> mReadable;
    WritableZcDbObject             mWritable;

private:
    Zcad::ErrorStatus closeInternal();
    
    ZCDB_CLASS* mpObj {nullptr};
};

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::ZcDbSmartObjectPointer()
    : mReadable(),
      mWritable()
{
    
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::ZcDbSmartObjectPointer(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased,
    bool           openOnLockedLayer)
    : mReadable(objId, openErased),
      mWritable(mReadable.object(), ZcDb::kForWrite == mode, openOnLockedLayer)
{ 
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::~ZcDbSmartObjectPointer()
{
    
    mpObj = NULL;
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::open(
    ZcDbObjectId   objId,
    ZcDb::OpenMode mode,
    bool           openErased,
    bool           openOnLockedLayer)
{
    if (mReadable.isReadable()) {
        Zcad::ErrorStatus closeStatus = closeInternal();
        if (closeStatus != Zcad::eOk)
            return closeStatus;
    }
    mReadable.enableRead(mReadable.mpObj, objId, openErased);
    if (mReadable.isReadable()) {
        mWritable.setOpenOnLockedLayer(openOnLockedLayer);
        mWritable.replaceObject(mReadable.object(), (ZcDb::kForWrite == mode));
    }
    return openStatus();
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline const ZCDB_CLASS *
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::object() const
{
    DbObjPtr_Assert(mReadable.object() == NULL || mReadable.isReadable());
    return mReadable.object();
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline ZCDB_CLASS *
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::object()
{
    DbObjPtr_Assert(mReadable.object() == NULL || mReadable.isReadable());
    return mReadable.object();
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline const ZCDB_CLASS *
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::operator->() const
{
    return object();
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline ZCDB_CLASS *
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::operator->()
{
    return object();
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::operator const ZCDB_CLASS*() const
{
    return object();
}

#if DBOBJPTR_EXPOSE_PTR_REF
template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::operator ZCDB_CLASS* &()
{
    mWritable.forget();
    mReadable.forgetCurrentAndAcceptNewAsIs(mReadable.object());
    return mReadable.mpObj;
}
#else
template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::operator ZCDB_CLASS*()
{
    return object();
}
#endif

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::openStatus() const
{
    return (mWritable.isWritable() ||
            ((mWritable.statusCode() != Zcad::eNullObjectPointer) &&
             (mWritable.statusCode() != Zcad::eNotOpenForWrite)))
                                  ? mWritable.statusCode()
                                  : mReadable.statusCode();
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::acquire(ZCDB_CLASS *& pObjToAcquire)
{
    closeInternal();
    mReadable.forgetCurrentAndAcceptNewAsIs(pObjToAcquire);
    pObjToAcquire = NULL;
    return Zcad::eOk;
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::release(ZCDB_CLASS *& pReleasedObj)
{
    pReleasedObj = mReadable.object();
    mWritable.forget();
    mReadable.forgetCurrentAndAcceptNewAsIs(NULL);
    return Zcad::eOk;
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::close()
{
    closeInternal();
    return Zcad::eOk;
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::create()
{
    ZCDB_CLASS * pObject = new ZCDB_CLASS;
    if (pObject == NULL)
        return Zcad::eNullObjectPointer;
    closeInternal();
    mReadable.forgetCurrentAndAcceptNewAsIs(pObject);
    return Zcad::eOk;
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline Zcad::ErrorStatus
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::closeInternal()
{
    mWritable.revertWrite();
    mReadable.revertRead();

    return Zcad::eOk;
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline
ZcDbSmartObjectPointer<ZCDB_CLASS>::ZcDbSmartObjectPointer(ZCDB_CLASS *pObject)
{
    acquire(pObject);
}

template<class ZCDB_CLASS, getClassDescFuncType ZCDB_GET_CLASS_DESC> inline void
ZcDbSmartObjectPointer<ZCDB_CLASS, ZCDB_GET_CLASS_DESC>::operator=(ZCDB_CLASS *pObject)
{
    acquire(pObject);
}

#endif  

#pragma pack (pop)

#endif 
