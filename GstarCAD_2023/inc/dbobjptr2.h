/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBOBJPTR2_H
#define GD_DBOBJPTR2_H

#include "dbobjptr.h"

GCCORE_PORT Gcad::ErrorStatus
accessGcDbObjectForRead(GcDbObject * & pObj,
  GcDbObjectId id,
  GcRxClass * (*pfDesc)(),
  bool &bWasOpened,
  bool bOpenErased);

template<class GCDB_CLASS> inline Gcad::ErrorStatus
accessGcDbObjectForRead(GCDB_CLASS * & pObj,
  GcDbObjectId id,
  bool &bWasOpened,
  bool bOpenErased = false)
{
  return ::accessGcDbObjectForRead((GcDbObject * &)pObj,
    id,
    &GCDB_CLASS::desc,
    bWasOpened, bOpenErased);
};

template<> inline Gcad::ErrorStatus
accessGcDbObjectForRead<GcDbObject>(GcDbObject * & pObj,
  GcDbObjectId id,
  bool &bWasOpened,
  bool bOpenErased)
{
  return ::accessGcDbObjectForRead(pObj, id, nullptr,
    bWasOpened, bOpenErased);
}

template<class GCDB_CLASS> class GcDbSmartObjectPointer;

template<class GCDB_CLASS>
class ReadableGcDbObject {
public:
  ReadableGcDbObject()
  {
  }

  ReadableGcDbObject(GCDB_CLASS*& pObj, GcDbObjectId id,
    bool bOpenErased, bool enableNow = true)
  {
    if (enableNow)
      enableRead(pObj, id, bOpenErased);
  }

  ReadableGcDbObject(const ReadableGcDbObject &) = delete;
  ReadableGcDbObject & operator = (const ReadableGcDbObject &) = delete;

  void enableRead(GCDB_CLASS*& pObj,
    GcDbObjectId id,
    bool bOpenErased)
  {
    revertRead();
    pObj = NULL;
    if (Gcad::eNotOpenForRead == mEs) {
      mEs = accessGcDbObjectForRead(pObj,
        id,
        mbWasOpened,
        bOpenErased);
      DbObjPtr_Assert((Gcad::eOk == mEs) == (NULL != pObj));
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
      else if ((Gcad::eOk == mEs) && mbWasOpened)
      {
        mEs = mpObj->close();
      }
      mpObj = NULL;
    }
    mEs = Gcad::eNotOpenForRead;
  };

  ~ReadableGcDbObject()
  {
    revertRead();
  };

  bool isReadable() const
  {
    return ((NULL != mpObj) && mpObj->isReadEnabled());
  };

  const GCDB_CLASS* object() const
  {
    return Gcad::eOk == mEs ? mpObj : NULL;
  };

  GCDB_CLASS*       object()
  {
    return Gcad::eOk == mEs ? mpObj : NULL;
  };

  Gcad::ErrorStatus statusCode() const
  {
    return mEs;
  };
private:
  GCDB_CLASS*       mpObj{ nullptr };
  Gcad::ErrorStatus mEs{ Gcad::eNotOpenForRead };
  bool              mbWasOpened{ false };

  friend class GcDbSmartObjectPointer<GCDB_CLASS>;

  ReadableGcDbObject(GcDbObjectId id,
    bool bOpenErased, bool enableNow = true)
    : mpObj(NULL),
    mEs(Gcad::eNotOpenForRead)
  {
    if (enableNow)
      enableRead(mpObj, id, bOpenErased);
  }

  void forgetCurrentAndAcceptNewAsIs(GCDB_CLASS* pNewObj)
  {
    if (mpObj != pNewObj) {
      mpObj = pNewObj;
      mEs = (NULL == mpObj) ? Gcad::eNotOpenForRead : Gcad::eOk;
      mbWasOpened = (NULL != mpObj);
    }
  };
};

GCCORE_PORT Gcad::ErrorStatus
accessGcDbObjectForWrite(GcDbObject *pObj,
  bool &bWasNotifyEnabled,
  bool &bWasWriteEnabled,
  int  &readCountClosed,
  bool openOnLockedLayer);

GCCORE_PORT Gcad::ErrorStatus
revertGcDbObjectFromWrite(GcDbObject *pObj,
  Gcad::ErrorStatus accessStatus,
  bool bWasNotifyEnabled,
  bool bWasWriteEnabled,
  int  readCountClosed);

class WritableGcDbObject {
public:
  WritableGcDbObject()
    : mbOpenOnLockedLayer(false)
  {
  }

  WritableGcDbObject(GcDbObject* pObj, bool enableNow = true, bool openOnLockedLayer = false)
    : mbOpenOnLockedLayer(openOnLockedLayer)
  {
    replaceObject(pObj, enableNow);
  }

  WritableGcDbObject(const WritableGcDbObject &) = delete;
  WritableGcDbObject operator = (const WritableGcDbObject &) = delete;

  void replaceObject(GcDbObject* pObj, bool enableNow = true)
  {
    revertWrite();
    mpObj = pObj;
    if (NULL == pObj) {
      mEs = Gcad::eNullObjectPointer;
      return;
    }
    mEs = Gcad::eNotOpenForWrite;
    if (enableNow)
      enableWrite();
  }

  bool enableWrite() {
    if (isWritable())
      return true;
    if (NULL == mpObj)
      return false;
    mEs = accessGcDbObjectForWrite(mpObj,
      mbWasNotifyEnabled,
      mbWasWriteEnabled,
      mReadCountClosed,
      mbOpenOnLockedLayer);
    return isWritable();
  };

  void revertWrite()
  {
    if ((NULL != mpObj) && !mpObj->objectId().isNull())
      mEs = revertGcDbObjectFromWrite(mpObj,
        mEs,
        mbWasNotifyEnabled,
        mbWasWriteEnabled,
        mReadCountClosed);
    forget();
  };

  ~WritableGcDbObject()
  {
    revertWrite();
  };

  bool isWritable() const
  {
    return (Gcad::eOk == mEs);
  };

  Gcad::ErrorStatus statusCode() const
  {
    return mEs;
  };

  void forget()
  {
    mpObj = NULL;
    mEs = Gcad::eNullObjectPointer;
  };

  void setOpenOnLockedLayer(bool openOnLockedLayer)
  {
    mbOpenOnLockedLayer = openOnLockedLayer;
  }

private:
  GcDbObject*       mpObj{ nullptr };
  Gcad::ErrorStatus mEs{ Gcad::eNullObjectPointer };
  bool              mbWasNotifyEnabled = false;
  bool              mbWasWriteEnabled = false;
  bool              mbOpenOnLockedLayer;
  int               mReadCountClosed{ 0 };
};

#pragma pack (push, 8)

template<class GCDB_CLASS>
class GcDbSmartObjectPointer
{
public:
  GcDbSmartObjectPointer();
  GcDbSmartObjectPointer(GcDbObjectId   objId,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false,
    bool           openOnLockedLayer = false);
  ~GcDbSmartObjectPointer();
  GcDbSmartObjectPointer(const GcDbSmartObjectPointer &) = delete;
  GcDbSmartObjectPointer & operator = (const GcDbSmartObjectPointer &) = delete;

  const GCDB_CLASS* object() const;
  GCDB_CLASS*       object();

  const GCDB_CLASS* operator->() const;
  GCDB_CLASS*       operator->();
  operator const GCDB_CLASS*() const;
#if DBOBJPTR_EXPOSE_PTR_REF
  GcDbSmartObjectPointer(GCDB_CLASS *pObject);
  operator GCDB_CLASS* &();
  void              operator=(GCDB_CLASS *pObject);
#else
  operator GCDB_CLASS*();
#endif

  Gcad::ErrorStatus openStatus() const;
  Gcad::ErrorStatus open(GcDbObjectId   objId,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false,
    bool           openOnLockedLayer = false);
  Gcad::ErrorStatus acquire(GCDB_CLASS *& pObjToAcquire);
  Gcad::ErrorStatus release(GCDB_CLASS *& pReleasedObj);
  Gcad::ErrorStatus close();
  Gcad::ErrorStatus create();
protected:
  ReadableGcDbObject<GCDB_CLASS> mReadable;
  WritableGcDbObject             mWritable;

private:
  Gcad::ErrorStatus closeInternal();
  GCDB_CLASS* mpObj{ nullptr };
};

template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::GcDbSmartObjectPointer()
  : mReadable(),
  mWritable()
{
}

template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::GcDbSmartObjectPointer(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased,
  bool           openOnLockedLayer)
  : mReadable(objId, openErased),
  mWritable(mReadable.object(), GcDb::kForWrite == mode, openOnLockedLayer)
{
}

template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::~GcDbSmartObjectPointer()
{
  mpObj = NULL;
}

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::open(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased,
  bool           openOnLockedLayer)
{
  if (mReadable.isReadable()) {
    Gcad::ErrorStatus closeStatus = closeInternal();
    if (closeStatus != Gcad::eOk)
      return closeStatus;
  }
  mReadable.enableRead(mReadable.mpObj, objId, openErased);
  if (mReadable.isReadable()) {
    mWritable.setOpenOnLockedLayer(openOnLockedLayer);
    mWritable.replaceObject(mReadable.object(), (GcDb::kForWrite == mode));
  }
  return openStatus();
}

template<class GCDB_CLASS> inline const GCDB_CLASS *
GcDbSmartObjectPointer<GCDB_CLASS>::object() const
{
  DbObjPtr_Assert(mReadable.object() == NULL || mReadable.isReadable());
  return mReadable.object();
}

template<class GCDB_CLASS> inline GCDB_CLASS *
GcDbSmartObjectPointer<GCDB_CLASS>::object()
{
  DbObjPtr_Assert(mReadable.object() == NULL || mReadable.isReadable());
  return mReadable.object();
}

template<class GCDB_CLASS> inline const GCDB_CLASS *
GcDbSmartObjectPointer<GCDB_CLASS>::operator->() const
{
  return object();
}

template<class GCDB_CLASS> inline GCDB_CLASS *
GcDbSmartObjectPointer<GCDB_CLASS>::operator->()
{
  return object();
}

template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::operator const GCDB_CLASS*() const
{
  return object();
}

#if DBOBJPTR_EXPOSE_PTR_REF
template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::operator GCDB_CLASS* &()
{
  mWritable.forget();
  mReadable.forgetCurrentAndAcceptNewAsIs(mReadable.object());
  return mReadable.mpObj;
}
#else
template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::operator GCDB_CLASS*()
{
  return object();
}
#endif

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::openStatus() const
{
  return (mWritable.isWritable() ||
    ((mWritable.statusCode() != Gcad::eNullObjectPointer) &&
    (mWritable.statusCode() != Gcad::eNotOpenForWrite)))
    ? mWritable.statusCode()
    : mReadable.statusCode();
}

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::acquire(GCDB_CLASS *& pObjToAcquire)
{
  closeInternal();
  mReadable.forgetCurrentAndAcceptNewAsIs(pObjToAcquire);
  pObjToAcquire = NULL;
  return Gcad::eOk;
}

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::release(GCDB_CLASS *& pReleasedObj)
{
  pReleasedObj = mReadable.object();
  mWritable.forget();
  mReadable.forgetCurrentAndAcceptNewAsIs(NULL);
  return Gcad::eOk;
}

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::close()
{
  closeInternal();
  return Gcad::eOk;
}

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::create()
{
  GCDB_CLASS * pObject = new GCDB_CLASS;
  if (pObject == NULL)
    return Gcad::eNullObjectPointer;
  closeInternal();
  mReadable.forgetCurrentAndAcceptNewAsIs(pObject);
  return Gcad::eOk;
}

template<class GCDB_CLASS> inline Gcad::ErrorStatus
GcDbSmartObjectPointer<GCDB_CLASS>::closeInternal()
{
  mWritable.revertWrite();
  mReadable.revertRead();

  return Gcad::eOk;
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class GCDB_CLASS> inline
GcDbSmartObjectPointer<GCDB_CLASS>::GcDbSmartObjectPointer(GCDB_CLASS *pObject)
{
  acquire(pObject);
}

template<class GCDB_CLASS> inline void
GcDbSmartObjectPointer<GCDB_CLASS>::operator=(GCDB_CLASS *pObject)
{
  acquire(pObject);
}

#endif  

#pragma pack (pop)

#endif 