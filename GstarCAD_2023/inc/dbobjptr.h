/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBOBJPTR_H
#define GD_DBOBJPTR_H

#include <assert.h>
#include "dbsymtb.h"

#ifdef ASSERT
#define DbObjPtr_Assert ASSERT
#elif defined assert
#define DbObjPtr_Assert assert
#elif defined _ASSERTE
#define DbObjPtr_Assert _ASSERTE
#else
#define DbObjPtr_Assert(T)
#endif

#pragma pack (push, 8)

template<class T_OBJECT>
class GcDbObjectPointerBase
{
public:
  GcDbObjectPointerBase();
  ~GcDbObjectPointerBase();

  const T_OBJECT *  object() const;
  T_OBJECT *        object();

  const T_OBJECT *  operator->() const;
  T_OBJECT *        operator->();
  operator const T_OBJECT*() const;
#if DBOBJPTR_EXPOSE_PTR_REF
  operator T_OBJECT* &();
#else
  operator T_OBJECT*();
#endif

  Gcad::ErrorStatus openStatus() const;
  Gcad::ErrorStatus open(GcDbObjectId   objId,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false);
  Gcad::ErrorStatus acquire(T_OBJECT *& pObjToAcquire);
  Gcad::ErrorStatus release(T_OBJECT *& pReleasedObj);
  Gcad::ErrorStatus close();
  Gcad::ErrorStatus create();

protected:
  GcDbObjectPointerBase(GcDbObjectId   objId,
    GcDb::OpenMode mode,
    bool           openErased);

#if DBOBJPTR_EXPOSE_PTR_REF
  GcDbObjectPointerBase(T_OBJECT * pObject);
  void operator=(T_OBJECT *pObject);
#endif

  T_OBJECT *        m_ptr;
  Gcad::ErrorStatus m_status;

private:
  GcDbObjectPointerBase(const GcDbObjectPointerBase &) = delete;
  GcDbObjectPointerBase& operator=(const GcDbObjectPointerBase &) = delete;
  Gcad::ErrorStatus closeInternal();
};

template<class T_OBJECT>
class GcDbObjectPointer : public GcDbObjectPointerBase<T_OBJECT>
{
public:
  GcDbObjectPointer();
  GcDbObjectPointer(GcDbObjectId   objId,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false);

#if DBOBJPTR_EXPOSE_PTR_REF
  GcDbObjectPointer(T_OBJECT * pObject);
  void operator=(T_OBJECT *pObject);
#endif

  Gcad::ErrorStatus open(GcDbObjectId objId,
    GcDb::OpenMode    mode = GcDb::kForRead,
    bool              openErased = false);

private:
  GcDbObjectPointer(const GcDbObjectPointer &) = delete;
  GcDbObjectPointer& operator=(const GcDbObjectPointer &) = delete;
};

typedef GcDbObjectPointer<GcDbDictionary> GcDbDictionaryPointer;
typedef GcDbObjectPointer<GcDbEntity>     GcDbEntityPointer;

template<class T_OBJECT>
class GcDbSymbolTablePointer : public GcDbObjectPointerBase<T_OBJECT>
{
public:
  GcDbSymbolTablePointer();
  GcDbSymbolTablePointer(GcDbObjectId objId, GcDb::OpenMode mode = GcDb::kForRead);
  GcDbSymbolTablePointer(GcDbDatabase * pDb, GcDb::OpenMode mode = GcDb::kForRead);
#if DBOBJPTR_EXPOSE_PTR_REF
  GcDbSymbolTablePointer(T_OBJECT * pObject);
  void operator=(T_OBJECT *pObject);
#endif

  Gcad::ErrorStatus open(GcDbObjectId objId, GcDb::OpenMode mode = GcDb::kForRead);
  Gcad::ErrorStatus open(GcDbDatabase* pDb, GcDb::OpenMode mode = GcDb::kForRead);

private:
  GcDbSymbolTablePointer(const GcDbSymbolTablePointer &) = delete;
  GcDbSymbolTablePointer& operator=(const GcDbSymbolTablePointer &) = delete;
  typedef typename T_OBJECT::RecordType T2;
};

typedef GcDbSymbolTablePointer<GcDbBlockTable>     GcDbBlockTablePointer;
typedef GcDbSymbolTablePointer<GcDbDimStyleTable>  GcDbDimStyleTablePointer;
typedef GcDbSymbolTablePointer<GcDbLayerTable>     GcDbLayerTablePointer;
typedef GcDbSymbolTablePointer<GcDbLinetypeTable>  GcDbLinetypeTablePointer;
typedef GcDbSymbolTablePointer<GcDbRegAppTable>    GcDbRegAppTablePointer;
typedef GcDbSymbolTablePointer<GcDbTextStyleTable> GcDbTextStyleTablePointer;
typedef GcDbSymbolTablePointer<GcDbUCSTable>       GcDbUCSTablePointer;
typedef GcDbSymbolTablePointer<GcDbViewTable>      GcDbViewTablePointer;
typedef GcDbSymbolTablePointer<GcDbViewportTable>  GcDbViewportTablePointer;

template<class T_OBJECT>
class GcDbSymbolTableRecordPointer : public GcDbObjectPointerBase<T_OBJECT>
{
public:
  GcDbSymbolTableRecordPointer();
  GcDbSymbolTableRecordPointer(GcDbObjectId   objId,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false);
  GcDbSymbolTableRecordPointer(const GCHAR *   name,
    GcDbDatabase * pDb,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false);

#if DBOBJPTR_EXPOSE_PTR_REF
  GcDbSymbolTableRecordPointer(T_OBJECT * pObject);
  void operator=(T_OBJECT *pObject);
#endif

  Gcad::ErrorStatus open(GcDbObjectId   objId,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false);
  Gcad::ErrorStatus open(const GCHAR *   name,
    GcDbDatabase * pDb,
    GcDb::OpenMode mode = GcDb::kForRead,
    bool           openErased = false);

private:
  GcDbSymbolTableRecordPointer(const GcDbSymbolTableRecordPointer &) = delete;
  GcDbSymbolTableRecordPointer& operator=(const GcDbSymbolTableRecordPointer &) = delete;

  typedef typename T_OBJECT::TableType T2;
};

typedef GcDbSymbolTableRecordPointer<GcDbBlockTableRecord>
GcDbBlockTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbDimStyleTableRecord>
GcDbDimStyleTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbLayerTableRecord>
GcDbLayerTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbLinetypeTableRecord>
GcDbLinetypeTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbRegAppTableRecord>
GcDbRegAppTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbTextStyleTableRecord>
GcDbTextStyleTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbUCSTableRecord>
GcDbUCSTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbViewTableRecord>
GcDbViewTableRecordPointer;
typedef GcDbSymbolTableRecordPointer<GcDbViewportTableRecord>
GcDbViewportTableRecordPointer;

template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::GcDbObjectPointerBase()
  : m_ptr(NULL),
  m_status(Gcad::eNullObjectPointer)
{
}

template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::GcDbObjectPointerBase(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased)
  : m_ptr(NULL),
  m_status(gcdbOpenObject(m_ptr, objId, mode, openErased))
{
}

template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::~GcDbObjectPointerBase()
{
  if (m_ptr != NULL) {
    assert(m_status == Gcad::eOk);
    Gcad::ErrorStatus closeStatus = closeInternal();
    (void)closeStatus;
    assert(closeStatus == Gcad::eOk);
  }
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::open(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased)
{
  if (m_ptr != NULL) {
    assert(m_status == Gcad::eOk);
    Gcad::ErrorStatus closeStatus = closeInternal();
    if (closeStatus != Gcad::eOk)
      return closeStatus;
  }
  m_status = gcdbOpenObject(m_ptr, objId, mode, openErased);
  return m_status;
}

template<class T_OBJECT> inline const T_OBJECT *
GcDbObjectPointerBase<T_OBJECT>::object() const
{
  assert(m_status == Gcad::eOk);
  assert(m_ptr != NULL);
  DbObjPtr_Assert(m_ptr == NULL || m_ptr->isReadEnabled());
  return m_ptr;
}

template<class T_OBJECT> inline T_OBJECT *
GcDbObjectPointerBase<T_OBJECT>::object()
{
  assert(m_status == Gcad::eOk);
  assert(m_ptr != NULL);
  DbObjPtr_Assert(m_ptr == NULL || m_ptr->isReadEnabled());
  return m_ptr;
}

template<class T_OBJECT> inline const T_OBJECT *
GcDbObjectPointerBase<T_OBJECT>::operator->() const
{
  return object();
}

template<class T_OBJECT> inline T_OBJECT *
GcDbObjectPointerBase<T_OBJECT>::operator->()
{
  return object();
}

template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::operator const T_OBJECT*() const
{
  return object();
}

#if DBOBJPTR_EXPOSE_PTR_REF
template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::operator T_OBJECT* &()
{
  return this->m_ptr;
}
#else
template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::operator T_OBJECT*()
{
  return object();
}
#endif

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::openStatus() const
{
  return m_status;
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::acquire(T_OBJECT *& pObjToAcquire)
{
  if (pObjToAcquire == NULL)
    return Gcad::eNullObjectPointer;
  if (m_ptr != NULL) {
    assert(m_status == Gcad::eOk);
    Gcad::ErrorStatus closeStatus = closeInternal();
    if (closeStatus != Gcad::eOk)
      return closeStatus;
  }
  m_ptr = pObjToAcquire;
  m_status = Gcad::eOk;
  pObjToAcquire = NULL;
  return Gcad::eOk;
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::release(T_OBJECT *& pReleasedObj)
{
  if (m_ptr == NULL)
    return Gcad::eNullObjectPointer;
  assert(m_status == Gcad::eOk);
  pReleasedObj = m_ptr;
  m_ptr = NULL;
  m_status = Gcad::eNullObjectPointer;
  return Gcad::eOk;
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::close()
{
  if (m_ptr == NULL)
    return Gcad::eNullObjectPointer;
  assert(m_status == Gcad::eOk);
  Gcad::ErrorStatus closeStatus = closeInternal();
  GSOFT_UNREFED_PARAM(closeStatus);
  assert(closeStatus == Gcad::eOk);
  return Gcad::eOk;
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::create()
{
  T_OBJECT * pObject = new T_OBJECT;
  if (pObject == NULL)
    return Gcad::eNullObjectPointer;
  if (m_ptr != NULL) {
    assert(m_status == Gcad::eOk);
    Gcad::ErrorStatus closeStatus = closeInternal();
    if (closeStatus != Gcad::eOk) {
      delete pObject;
      return closeStatus;
    }
  }
  m_ptr = pObject;
  m_status = Gcad::eOk;
  return Gcad::eOk;
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointerBase<T_OBJECT>::closeInternal()
{
  if (m_ptr == NULL)
    return Gcad::eOk;
  Gcad::ErrorStatus es = Gcad::eOk;
  if (m_ptr->objectId().isNull()) {
    delete m_ptr;
    es = Gcad::eOk;
  }
  else {
    es = m_ptr->close();
  }
  m_ptr = NULL;
  m_status = Gcad::eNullObjectPointer;
  return es;
}

template<class T_OBJECT> inline
GcDbObjectPointer<T_OBJECT>::GcDbObjectPointer()
  : GcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT> inline
GcDbObjectPointer<T_OBJECT>::GcDbObjectPointer(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased)
  : GcDbObjectPointerBase<T_OBJECT>(objId, mode, openErased)
{
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbObjectPointer<T_OBJECT>::open(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased)
{
  return GcDbObjectPointerBase<T_OBJECT>::open(objId, mode, openErased);
}

template<class T_OBJECT> inline
GcDbSymbolTablePointer<T_OBJECT>::GcDbSymbolTablePointer()
  : GcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT> inline
GcDbSymbolTablePointer<T_OBJECT>::GcDbSymbolTablePointer(
  GcDbObjectId   objId,
  GcDb::OpenMode mode)
  : GcDbObjectPointerBase<T_OBJECT>(objId, mode, false)
{
}

template<class T_OBJECT> inline
GcDbSymbolTablePointer<T_OBJECT>::GcDbSymbolTablePointer(
  GcDbDatabase * pDb,
  GcDb::OpenMode mode)
  : GcDbObjectPointerBase<T_OBJECT>()
{
  this->m_status = (pDb == NULL) ? Gcad::eNullObjectPointer
    : pDb->getSymbolTable(this->m_ptr, mode);
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbSymbolTablePointer<T_OBJECT>::open(
  GcDbObjectId   objId,
  GcDb::OpenMode mode)
{
  return GcDbObjectPointerBase<T_OBJECT>::open(objId, mode, false);
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbSymbolTablePointer<T_OBJECT>::open(
  GcDbDatabase* pDb,
  GcDb::OpenMode mode)
{
  if (pDb == NULL)
    return Gcad::eInvalidInput;
  Gcad::ErrorStatus es = Gcad::eOk;
  if (this->m_ptr != NULL)
    es = this->close();
  if (es == Gcad::eOk) {
    es = pDb->getSymbolTable(this->m_ptr, mode);
    this->m_status = es;
  }
  return es;
}

template<class T_OBJECT> inline
GcDbSymbolTableRecordPointer<T_OBJECT>::GcDbSymbolTableRecordPointer()
  : GcDbObjectPointerBase<T_OBJECT>()
{
}

template<class T_OBJECT> inline
GcDbSymbolTableRecordPointer<T_OBJECT>::GcDbSymbolTableRecordPointer(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased)
  : GcDbObjectPointerBase<T_OBJECT>(objId, mode, openErased)
{
}

template<class T_OBJECT> inline
GcDbSymbolTableRecordPointer<T_OBJECT>
::GcDbSymbolTableRecordPointer(
  const GCHAR *   name,
  GcDbDatabase * pDb,
  GcDb::OpenMode mode,
  bool           openErased)
  : GcDbObjectPointerBase<T_OBJECT>()
{
  if (name == NULL)
    this->m_status = Gcad::eInvalidInput;
  else {
    GcDbSymbolTablePointer<typename T_OBJECT::TableType>
      pTable(pDb, GcDb::kForRead);
    this->m_status = pTable.openStatus();
    if (this->m_status == Gcad::eOk)
      this->m_status = pTable->getAt(name, this->m_ptr, mode, openErased);
  }
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbSymbolTableRecordPointer<T_OBJECT>::open(
  GcDbObjectId   objId,
  GcDb::OpenMode mode,
  bool           openErased)
{
  return GcDbObjectPointerBase<T_OBJECT>::open(objId, mode, openErased);
}

template<class T_OBJECT> inline Gcad::ErrorStatus
GcDbSymbolTableRecordPointer<T_OBJECT>
::open(const GCHAR *   name,
  GcDbDatabase * pDb,
  GcDb::OpenMode mode,
  bool           openErased)
{
  if (name == NULL)
    return Gcad::eInvalidInput;
  else {
    GcDbSymbolTablePointer<typename T_OBJECT::TableType>
      pTable(pDb, GcDb::kForRead);
    Gcad::ErrorStatus es = pTable.openStatus();
    if (es == Gcad::eOk) {
      if (this->m_ptr != NULL)
        es = this->close();
      if (es == Gcad::eOk) {
        es = pTable->getAt(name, this->m_ptr, mode, openErased);
        this->m_status = es;
      }
    }
    return es;
  }
}

#if DBOBJPTR_EXPOSE_PTR_REF

template<class T_OBJECT> inline
GcDbObjectPointerBase<T_OBJECT>::GcDbObjectPointerBase(T_OBJECT *pObject)
  : m_ptr(NULL),
  m_status(Gcad::eNullObjectPointer)
{
  if (pObject != NULL)
    this->acquire(pObject);
}

template<class T_OBJECT> inline void
GcDbObjectPointerBase<T_OBJECT>::operator=(T_OBJECT *pObject)
{
  if (pObject == NULL) {
    DbObjPtr_Assert(this->m_ptr == NULL);
  }
  else
    this->acquire(pObject);
}

template<class T_OBJECT> inline
GcDbObjectPointer<T_OBJECT>::GcDbObjectPointer(T_OBJECT *pObject)
  : GcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT> inline GcDbSymbolTablePointer<T_OBJECT>::
GcDbSymbolTablePointer(T_OBJECT *pObject)
  : GcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT> inline GcDbSymbolTableRecordPointer<T_OBJECT>::
GcDbSymbolTableRecordPointer(T_OBJECT *pObject)
  : GcDbObjectPointerBase<T_OBJECT>(pObject)
{
}

template<class T_OBJECT> inline void
GcDbObjectPointer<T_OBJECT>::operator=(T_OBJECT *pObject)
{
  GcDbObjectPointerBase<T_OBJECT>::operator =(pObject);
}

template<class T_OBJECT> inline void
GcDbSymbolTablePointer<T_OBJECT>::operator=(T_OBJECT *pObject)
{
  GcDbObjectPointerBase<T_OBJECT>::operator =(pObject);
}

template<class T_OBJECT> inline void
GcDbSymbolTableRecordPointer<T_OBJECT>::operator=(T_OBJECT *pObject)
{
  GcDbObjectPointerBase<T_OBJECT>::operator =(pObject);
}

#endif  

#pragma pack (pop)

#endif 