#pragma once

#include <assert.h>
#include "Tables.h"
#include "DbDictionary.h"
#include "gcadstrc.h"

#pragma pack (push, 8)

template<class T>
class OdDbObjectPointerBase
{
public:
    OdDbObjectPointerBase();
    virtual ~OdDbObjectPointerBase();

    const T *  object() const;
    T *        object();

    const T *  operator->() const;
    T *        operator->();

    operator T*();

    OdResult openStatus() const;

    OdResult open(OdDbObjectId   objId,
                  OdDb::OpenMode mode,
                  bool           openErased = false);

    OdResult open(const OdChar*   pName,
      OdDbDatabase*   pDB,
      OdDb::OpenMode mode);

    OdResult acquire(T *& pObjToAcquire);
    OdResult release(T *& pReleasedObj);
    OdResult close();

    OdResult create();

protected:
    OdDbObjectPointerBase(OdDbObjectId   objId,
                          OdDb::OpenMode mode,
                          bool           openErased);

    T *        m_ptr;
    OdResult m_status;

private:
    OdDbObjectPointerBase(OdDbObjectPointerBase & pObject);
    OdDbObjectPointerBase& operator=(OdDbObjectPointerBase & pObject);

    OdResult closeInternal();
};

template<class T>
class OdDbObjectPointer : public OdDbObjectPointerBase<T>
{
public:
    OdDbObjectPointer();
    OdDbObjectPointer(OdDbObjectId   objId,
                      OdDb::OpenMode mode,
                      bool           openErased = false);

    OdResult open(OdDbObjectId objId,
                      OdDb::OpenMode    mode,
                      bool              openErased = false);

private:
    OdDbObjectPointer(OdDbObjectPointer & pObject);
    OdDbObjectPointer& operator=(OdDbObjectPointer & pObject);
};

typedef OdDbObjectPointer<OdDbDictionary> OdDbDictionaryPointer;
typedef OdDbObjectPointer<OdDbEntity>     OdDbEntityPointer;

template<class T>
class OdDbSymbolTablePointer : public OdDbObjectPointerBase<T>
{
public:
    OdDbSymbolTablePointer();
    OdDbSymbolTablePointer(OdDbObjectId objId, OdDb::OpenMode mode);
    OdDbSymbolTablePointer(OdDbDatabase * pDb, OdDb::OpenMode mode);

private:
    OdDbSymbolTablePointer(OdDbSymbolTablePointer & pObject);
    OdDbSymbolTablePointer& operator=(OdDbSymbolTablePointer & pObject);

    typedef typename T::RecordType T2;
};

typedef OdDbSymbolTablePointer<OdDbBlockTable>     OdDbBlockTablePointer;
typedef OdDbSymbolTablePointer<OdDbDimStyleTable>  OdDbDimStyleTablePointer;
typedef OdDbSymbolTablePointer<OdDbLayerTable>     OdDbLayerTablePointer;
typedef OdDbSymbolTablePointer<OdDbLinetypeTable>  OdDbLinetypeTablePointer;
typedef OdDbSymbolTablePointer<OdDbRegAppTable>    OdDbRegAppTablePointer;
typedef OdDbSymbolTablePointer<OdDbTextStyleTable> OdDbTextStyleTablePointer;
typedef OdDbSymbolTablePointer<OdDbUCSTable>       OdDbUCSTablePointer;
typedef OdDbSymbolTablePointer<OdDbViewTable>      OdDbViewTablePointer;
typedef OdDbSymbolTablePointer<OdDbViewportTable>  OdDbViewportTablePointer;

template<class T>
class OdDbSymbolTableRecordPointer : public OdDbObjectPointerBase<T>
{
public:
    OdDbSymbolTableRecordPointer();
    OdDbSymbolTableRecordPointer(OdDbObjectId   objId,
                                 OdDb::OpenMode mode,
                                 bool           openErased = false);
    OdDbSymbolTableRecordPointer(const OdChar * name,
                                 OdDbDatabase * pDb,
                                 OdDb::OpenMode mode,
                                 bool           openErased = false);

private:
    OdDbSymbolTableRecordPointer(OdDbSymbolTableRecordPointer & pObject);
    OdDbSymbolTableRecordPointer&
                       operator=(OdDbSymbolTableRecordPointer & pObject);

    typedef typename T::TableType T2;
};

typedef OdDbSymbolTableRecordPointer<OdDbBlockTableRecord>
                                     OdDbBlockTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbDimStyleTableRecord>
                                     OdDbDimStyleTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbLayerTableRecord>
                                     OdDbLayerTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbLinetypeTableRecord>
                                     OdDbLinetypeTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbRegAppTableRecord>
                                     OdDbRegAppTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbTextStyleTableRecord>
                                     OdDbTextStyleTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbUCSTableRecord>
                                     OdDbUCSTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbViewTableRecord>
                                     OdDbViewTableRecordPointer;
typedef OdDbSymbolTableRecordPointer<OdDbViewportTableRecord>
                                     OdDbViewportTableRecordPointer;

template<class T> inline
OdDbObjectPointerBase<T>::OdDbObjectPointerBase()
    : m_ptr(NULL),
      m_status(Gcad::eNullObjectPointer)
{
}

template<class T> inline
OdDbObjectPointerBase<T>::OdDbObjectPointerBase(
    OdDbObjectId   objId,
    OdDb::OpenMode mode,
    bool           openErased)
    : m_ptr(NULL),
      m_status(oddbOpenObject(m_ptr, objId, mode, openErased))
{
}

template<class T> inline
OdDbObjectPointerBase<T>::~OdDbObjectPointerBase()
{
    if (m_ptr != NULL) {
        assert(m_status == Gcad::eOk);
        OdResult closeStatus = closeInternal();
        assert(closeStatus == Gcad::eOk);
    }
}

template<class T> inline OdResult 
OdDbObjectPointerBase<T>::open(
    OdDbObjectId   objId,
    OdDb::OpenMode mode,
    bool           openErased)
{
    if (m_ptr != NULL) {
        assert(m_status == Gcad::eOk);
        OdResult closeStatus = closeInternal();
        if (closeStatus != Gcad::eOk)
            return closeStatus;
    }
    m_status = oddbOpenObject(m_ptr, objId, mode, openErased);
    return m_status;
}


template<class T> inline OdResult 
  OdDbObjectPointerBase<T>::open(
  const OdChar*   pName,
  OdDbDatabase*   pDB,
  OdDb::OpenMode mode)
{
  if (m_ptr != NULL) {
    assert(m_status == Gcad::eOk);
    OdResult closeStatus = closeInternal();
    if (closeStatus != Gcad::eOk)
      return closeStatus;
  }
  
  if (NULL == pDB || NULL == pName)
  {
    return Oda::eNullObjectId;
  }
  OdDbBlockTable* pTable = NULL;
  if (Gcad::eOk != pDB->getBlockTable(pTable, OdDb::kForRead))
  {
    pTable->close();
    return Oda::eNullObjectId;
  }
  OdDbObjectId objId = OdDbObjectId::kNull;
  pTable->getAt(pName, objId);
  pTable->close();
  
  m_status = oddbOpenObject(m_ptr, objId, mode);
  return m_status;
}

template<class T> inline const T *
OdDbObjectPointerBase<T>::object() const
{
    assert(m_status == Gcad::eOk);
    assert(m_ptr != NULL);
    return m_ptr;
}

// This function does not modify the object, but we may not make
// it const.  Doing so will overload it with the const operator->()
// function above, which is not allowed (we're overloading on
// const-ness).
template<class T> inline T *
OdDbObjectPointerBase<T>::object()
{
    assert(m_status == Gcad::eOk);
    assert(m_ptr != NULL);
    return m_ptr;
}

template<class T> inline const T *
OdDbObjectPointerBase<T>::operator->() const
{
    return object();
}

template<class T> inline T *
OdDbObjectPointerBase<T>::operator->()
{
    return object();
}

template<class T> inline 
  OdDbObjectPointerBase<T>::operator T*()
{
  return object();
}

template<class T> inline OdResult
OdDbObjectPointerBase<T>::openStatus() const
{
    return m_status;
}

template<class T> inline OdResult
OdDbObjectPointerBase<T>::acquire(T *& pObjToAcquire)
{
    if (pObjToAcquire == NULL)
        return Gcad::eNullObjectPointer;
    if (m_ptr != NULL) {
        assert(m_status == Gcad::eOk);
        OdResult closeStatus = closeInternal();
        if (closeStatus != Gcad::eOk)
            return closeStatus;
    }
    m_ptr = pObjToAcquire;
    m_status = Gcad::eOk;
    pObjToAcquire = NULL;
    return Gcad::eOk;
}

template<class T> inline OdResult
OdDbObjectPointerBase<T>::release(T *& pReleasedObj)
{
    if (m_ptr == NULL)
        return Gcad::eNullObjectPointer;
    assert(m_status == Gcad::eOk);
    pReleasedObj = m_ptr;
    m_ptr    = NULL;
    m_status = Gcad::eNullObjectPointer;
    return Gcad::eOk;
}

template<class T> inline OdResult
OdDbObjectPointerBase<T>::close()
{
    if (m_ptr == NULL)
        return Gcad::eNullObjectPointer;
    assert(m_status == Gcad::eOk);
    OdResult closeStatus = closeInternal();
    assert(closeStatus == Gcad::eOk);
    return Gcad::eOk;
}

template<class T> inline OdResult
OdDbObjectPointerBase<T>::create()
{
	T * pObject = (T*)(T::desc()->create());
    if (pObject == NULL)
        return Gcad::eNullObjectPointer;
    if (m_ptr != NULL) {
        assert(m_status == Gcad::eOk);
        OdResult closeStatus = closeInternal();
        if (closeStatus != Gcad::eOk) {
            pObject->release();
            return closeStatus;
        }
    }
    m_ptr = pObject;
    m_status = Gcad::eOk;
    return Gcad::eOk;
}

template<class T> inline OdResult
OdDbObjectPointerBase<T>::closeInternal()
{
    if (m_ptr == NULL)
        return Gcad::eOk;
    Gcad::ErrorStatus es = Gcad::eOk;
    if (m_ptr->objectId().isNull()) {
        delete m_ptr;
        es = Gcad::eOk;
    } else {
        es = m_ptr->close();
    }
    m_ptr       = NULL;
    m_status    = Gcad::eNullObjectPointer;
    return es;
}

template<class T> inline
OdDbObjectPointer<T>::OdDbObjectPointer()
    : OdDbObjectPointerBase<T>()
{
}

template<class T> inline
OdDbObjectPointer<T>::OdDbObjectPointer(
    OdDbObjectId   objId,
    OdDb::OpenMode mode,
    bool           openErased)
    : OdDbObjectPointerBase<T>(objId, mode, openErased)
{
}

template<class T> inline OdResult
OdDbObjectPointer<T>::open(
    OdDbObjectId   objId,
    OdDb::OpenMode mode,
    bool           openErased)
{
    return OdDbObjectPointerBase<T>::open(objId, mode, openErased);
}

template<class T> inline
OdDbSymbolTablePointer<T>::OdDbSymbolTablePointer()
    : OdDbObjectPointerBase<T>()
{
}

template<class T> inline
OdDbSymbolTablePointer<T>::OdDbSymbolTablePointer(
    OdDbObjectId   objId,
    OdDb::OpenMode mode)
    : OdDbObjectPointerBase<T>(objId, mode, ::kFalse)
{
}

template<class T> inline
OdDbSymbolTablePointer<T>::OdDbSymbolTablePointer(
    OdDbDatabase * pDb,
    OdDb::OpenMode mode)
    : OdDbObjectPointerBase<T>()
{
    m_status = (pDb == NULL) ? Gcad::eNullObjectPointer
                             : pDb->getSymbolTable(m_ptr, mode);
}

template<class T> inline
OdDbSymbolTableRecordPointer<T>
    ::OdDbSymbolTableRecordPointer()
    : OdDbObjectPointerBase<T>()
{
}

template<class T> inline
OdDbSymbolTableRecordPointer<T>
    ::OdDbSymbolTableRecordPointer(
    OdDbObjectId   objId,
    OdDb::OpenMode mode,
    bool           openErased)
    : OdDbObjectPointerBase<T>(objId, mode, openErased)
{
}

template<class T> inline
OdDbSymbolTableRecordPointer<T>
    ::OdDbSymbolTableRecordPointer(
    const OdChar * name,
    OdDbDatabase * pDb,
    OdDb::OpenMode mode,
    bool           openErased)
    : OdDbObjectPointerBase<T>()
{
    if (name == NULL)
        m_status = Gcad::eInvalidInput;
    else {
        OdDbSymbolTablePointer<T::TableType>
            pTable(pDb, OdDb::kForRead);
        m_status = pTable.openStatus();
        if (m_status == Gcad::eOk)
            m_status = pTable->getAt(name, m_ptr, mode, openErased);
    }
}

#pragma pack (pop)
