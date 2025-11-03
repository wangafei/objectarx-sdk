/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GXOBJREF_H_
#define __GXOBJREF_H_

#include "dbobjptr.h"
#pragma pack (push, 8)

#pragma warning (disable : 4786)

class GcAxObjectRef
{
public:
  GcAxObjectRef();
  GcAxObjectRef(GcDbObjectId objId);
  GcAxObjectRef(GcDbObject *&  pObj);
  ~GcAxObjectRef();

  Gcad::ErrorStatus acquire(GcDbObjectId objId);
  Gcad::ErrorStatus acquire(GcDbObject *& pObj);
  Gcad::ErrorStatus release(GcDbObjectId& objId, GcDbObject *& pObj);

  bool isNull();
  GcDbObjectId objectId();

private:
  GcAxObjectRef(GcAxObjectRef & ref);
  GcAxObjectRef& operator=(GcAxObjectRef & ref);

  void internalRelease();
  GcDbObjectId m_objId;
  GcDbObject * m_pObj;
};

inline
GcAxObjectRef::GcAxObjectRef()
  : m_objId(NULL),
  m_pObj(NULL)
{
}

inline
GcAxObjectRef::GcAxObjectRef(GcDbObjectId objId)
  : m_objId(NULL),
  m_pObj(NULL)
{
  acquire(objId);
}

inline GcAxObjectRef::GcAxObjectRef(GcDbObject *& pObj)
  : m_objId(NULL),
  m_pObj(NULL)
{
  acquire(pObj);
}

inline GcAxObjectRef::~GcAxObjectRef()
{
  internalRelease();
}

inline Gcad::ErrorStatus GcAxObjectRef::acquire(GcDbObjectId objId)
{
  if (objId.isNull())
    return Gcad::eNullObjectId;

  internalRelease();

  m_objId = objId;
  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcAxObjectRef::acquire(GcDbObject *& pObj)
{
  if (NULL == pObj)
    return Gcad::eNullObjectPointer;

  if (!pObj->objectId().isNull())
    return acquire(pObj->objectId());

  internalRelease();

  m_pObj = pObj;
  pObj = NULL;

  return Gcad::eOk;
}

inline Gcad::ErrorStatus GcAxObjectRef::release(GcDbObjectId& objId, GcDbObject *& pObj)
{
  if (isNull())
    return Gcad::eNullObjectPointer;

  pObj = m_pObj;
  objId = m_objId;

  m_pObj = NULL;
  m_objId.setNull();

  return Gcad::eOk;
}

inline void GcAxObjectRef::internalRelease()
{
  if (NULL != m_pObj)
  {
    if (m_pObj->objectId().isNull())
      delete m_pObj;
    else
    {
    }
    m_pObj = NULL;
  }
  m_objId.setNull();
}

inline bool GcAxObjectRef::isNull()
{
  return (NULL == m_pObj && m_objId.isNull());
}

inline GcDbObjectId GcAxObjectRef::objectId()
{
  return m_objId;
}

template<class T_OBJECT>
class GcAxObjectRefPtr : public GcDbObjectPointer<T_OBJECT>
{
public:
  GcAxObjectRefPtr();
  GcAxObjectRefPtr(GcAxObjectRef* const pRef,
                   GcDb::OpenMode       mode,
                   bool                 openErased = false);
  ~GcAxObjectRefPtr();

private:
  GcAxObjectRefPtr(GcAxObjectRefPtr & pObj);
  GcAxObjectRefPtr& operator=(GcAxObjectRefPtr & pObj);

  GcAxObjectRef* const m_pRef;
};

template<class T_OBJECT> inline
GcAxObjectRefPtr<T_OBJECT>::GcAxObjectRefPtr()
  : GcDbObjectPointer<T_OBJECT>(),
  m_pRef(NULL)
{}

template<class T_OBJECT> inline
GcAxObjectRefPtr<T_OBJECT>::GcAxObjectRefPtr(GcAxObjectRef* const pRef, GcDb::OpenMode mode, bool openErased)
  : m_pRef(pRef)
{
  if (NULL == pRef)
  {
    this->m_status = Gcad::eNullObjectPointer;
    return;
  }

  GcDbObjectId objId = pRef->objectId();

  if (!objId.isNull())
    this->m_status = gcdbOpenObject(this->m_ptr, objId, mode, openErased);
  else
  {
    GcDbObject* pTmp = NULL;
    m_pRef->release(objId, pTmp);

    T_OBJECT* pTyped = T_OBJECT::cast(pTmp);
    if (NULL == pTyped)
    {
      this->m_ptr = NULL;
      m_pRef->acquire(pTmp);
      this->m_status = Gcad::eNotThatKindOfClass;
    }
    else
      acquire(pTyped);
  }
}

template<class T_OBJECT> inline
GcAxObjectRefPtr<T_OBJECT>::~GcAxObjectRefPtr()
{
  if (NULL != this->m_ptr && this->m_ptr->objectId().isNull())
  {
    T_OBJECT* pTmp;
    release(pTmp);
    m_pRef->acquire(reinterpret_cast<GcDbObject*&>(pTmp));
  }
}

typedef GcAxObjectRefPtr<GcDbObject> GcDbObjectRefPtr;
typedef GcAxObjectRefPtr<GcDbEntity> GcDbEntityRefPtr;

#pragma pack (pop)
#endif
