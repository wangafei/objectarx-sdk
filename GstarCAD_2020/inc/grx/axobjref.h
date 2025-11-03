#pragma once

#include "dbobjptr.h"

#ifndef GCADAXEXP
#ifdef GVBADLL
#define GCADAXEXP __declspec(dllexport)
#else
#define GCADAXEXP __declspec(dllimport)
#endif
#endif

class GCADAXEXP GcAxObjectRef
{
public:

    GcAxObjectRef();
    GcAxObjectRef(GcDbObjectId objId);
    GcAxObjectRef(GcDbObject *&  pObj); 
    ~GcAxObjectRef();

public:

    bool isNull();
    GcDbObjectId objectId();
    Gcad::ErrorStatus acquire(GcDbObjectId objId);
    Gcad::ErrorStatus acquire(GcDbObject*& pObj);
    Gcad::ErrorStatus release(GcDbObjectId& objId, GcDbObject*& pObj);

private:
    // Disallow copy constructor and assignment
    GcAxObjectRef(GcAxObjectRef& ref);
    GcAxObjectRef& operator=(GcAxObjectRef& ref);

    void internalRelease();
    // Object references
    GcDbObjectId m_objId;
    GcDbObject *   m_pObj;
};

template<class T_OBJECT>
class GcAxObjectRefPtr : public GcDbObjectPointer<T_OBJECT>
{
public:

    GcAxObjectRefPtr();
    GcAxObjectRefPtr(GcAxObjectRef* const pRef, GcDb::OpenMode mode, bool openErased = false);
    ~GcAxObjectRefPtr();

private:

    // Disallow copy constructor, assignment operator
    GcAxObjectRefPtr(GcAxObjectRefPtr & pObj);
    GcAxObjectRefPtr& operator=(GcAxObjectRefPtr & pObj);

    GcAxObjectRef* const m_pRef;
};

template<class T_OBJECT>
inline GcAxObjectRefPtr<T_OBJECT>::GcAxObjectRefPtr(): GcDbObjectPointer<T_OBJECT>(), m_pRef(NULL)
{}

template<class T_OBJECT>
inline GcAxObjectRefPtr<T_OBJECT>::GcAxObjectRefPtr(GcAxObjectRef* const pRef, GcDb::OpenMode mode, bool openErased): m_pRef(pRef)
{
    //_ASSERTE(NULL != pRef);
    if (NULL == pRef || pRef->isNull())
    {
        m_status = Gcad::eNullObjectPointer;
        return;
    }

    GcDbObjectId objId = pRef->objectId();

    if (!objId.isNull()) 
    {
        m_status = gcdbOpenObject(m_ptr, objId, mode, openErased);
    }
    else 
    {
        GcDbObject* pTmp = NULL;
        m_pRef->release(objId, pTmp);

        // Check for downcast of GcDbObject pointer to T_OBJECT
        // Restore object reference if this cast fails
        T_OBJECT* pTyped = T_OBJECT::cast(pTmp);
        if (NULL == pTyped)
        {
            m_ptr = NULL;
            m_pRef->acquire(pTmp);
            m_status = Gcad::eNotThatKindOfClass;
        }
        else
        {
            acquire(pTyped);
        }
    }
}

template<class T_OBJECT>
inline GcAxObjectRefPtr<T_OBJECT>::~GcAxObjectRefPtr()
{
    if (NULL != m_ptr && m_ptr->objectId().isNull())
    {
        T_OBJECT* pTmp;
        release(pTmp);
        m_pRef->acquire(reinterpret_cast<GcDbObject*&>(pTmp));
    }
}

typedef GcAxObjectRefPtr<GcDbObject> GcDbObjectRefPtr;
typedef GcAxObjectRefPtr<GcDbEntity> GcDbEntityRefPtr;
