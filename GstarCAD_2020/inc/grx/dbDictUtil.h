#ifndef GC_DBDICTUTIL_H
#define GC_DBDICTUTIL_H 1
#include <assert.h>
#include <stddef.h>
#include "dbdict.h"
#include "GcString.h"

namespace GcDbDictUtil
{
  inline Gcad::ErrorStatus dictionaryNameAt(GCHAR*& pName, GcDbObjectId itemId, GcDbObjectId ownerDictId)
  {
    assert(!itemId.isNull() && !ownerDictId.isNull());

    GcDbDictionary* pDict;
    Gcad::ErrorStatus es = gcdbOpenObject(pDict, ownerDictId, GcDb::kForRead);
    if (es == Gcad::eOk) 
    {
      es = pDict->nameAt(itemId, pName);
      pDict->close();
    }
    return es;
  }

  inline Gcad::ErrorStatus dictionaryNameAt(GcString& name, GcDbObjectId itemId, GcDbObjectId ownerDictId)
  {
    assert(!itemId.isNull() && !ownerDictId.isNull());

    GcDbDictionary* pDict;
    Gcad::ErrorStatus es = gcdbOpenObject(pDict, ownerDictId, GcDb::kForRead);
    if (es == Gcad::eOk) 
    {
      es = pDict->nameAt(itemId, name);
      pDict->close();
    }

    return es;
  }

  inline Gcad::ErrorStatus dictionaryNameAt(GCHAR*& pName, GcDbObjectId itemId)
  {
    assert(!itemId.isNull());

    GcDbObject* pObject;
    Gcad::ErrorStatus es = gcdbOpenObject(pObject, itemId, GcDb::kForRead);
    if (es != Gcad::eOk)
      return es;
    GcDbObjectId dictId = pObject->ownerId(); 
    es = pObject->close();
    assert(es == Gcad::eOk);

    return dictionaryNameAt(pName, itemId, dictId);
  }

  inline Gcad::ErrorStatus dictionaryNameAt(GcString& name, GcDbObjectId itemId)
  {
    assert(!itemId.isNull());

    GcDbObject* pObject;
    Gcad::ErrorStatus es = gcdbOpenObject(pObject, itemId, GcDb::kForRead);
    if (es != Gcad::eOk)
      return es;
    GcDbObjectId dictId = pObject->ownerId(); //get the owner id
    es = pObject->close();
    assert(es == Gcad::eOk);

    return dictionaryNameAt(name, itemId, dictId);
  }

  inline Gcad::ErrorStatus dictionaryGetAt(GcDbObjectId& id, const GCHAR* name, GcDbObjectId ownerDictId)
  {
    assert(!ownerDictId.isNull());

    GcDbDictionary* pDict;
    Gcad::ErrorStatus es = gcdbOpenObject(pDict, ownerDictId, GcDb::kForRead);
    assert(es == Gcad::eOk);

    if (es == Gcad::eOk) 
    {
      es = pDict->getAt(name, id);
      pDict->close();
    }
    return es;
  }

#define DBDICTUTIL_MAKE_DICTIONARY_UTILS(LOWERNAME, UPPERNAME) \
inline Gcad::ErrorStatus \
get##UPPERNAME##Id(GcDbObjectId& id, const GCHAR* name, GcDbDatabase* pDb) \
{ \
    assert(pDb != NULL); \
    return (pDb != NULL) \
        ? dictionaryGetAt(id, name, pDb->LOWERNAME##DictionaryId()) \
        : Gcad::eInvalidInput; \
} \
inline Gcad::ErrorStatus \
get##UPPERNAME##Name(GCHAR*& name, GcDbObjectId itemId) \
{ \
    GcDbDatabase* pDb = itemId.database(); \
    return (pDb != NULL) \
        ? dictionaryNameAt(name, itemId, pDb->LOWERNAME##DictionaryId()) \
        : Gcad::eInvalidInput; \
} \
inline Gcad::ErrorStatus \
get##UPPERNAME##Name(GcString& name, GcDbObjectId itemId) \
{ \
    GcDbDatabase* pDb = itemId.database(); \
    return (pDb != NULL) \
        ? dictionaryNameAt(name, itemId, pDb->LOWERNAME##DictionaryId()) \
        : Gcad::eInvalidInput; \
} \
inline bool \
has##UPPERNAME(const GCHAR* name, GcDbDatabase* pDb) \
{ \
    GcDbObjectId id; \
    return (get##UPPERNAME##Id(id, name, pDb) == Gcad::eOk); \
}

DBDICTUTIL_MAKE_DICTIONARY_UTILS( mLStyle,       MLStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( group,         Group)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( layout,        Layout)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( plotSettings,  PlotSettings)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( plotStyleName, PlotStyleName)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( material,      Material)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( color,         Color)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( tableStyle,    TableStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( visualStyle,    VisualStyle)

#undef DBDICTUTIL_MAKE_DICTIONARY_UTILS

} // end GcDbDictUtil namespace

#endif // !GC_DBDICTUTIL_H
