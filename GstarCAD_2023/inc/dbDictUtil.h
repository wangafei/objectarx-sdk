/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDICTUTIL_H
#define GD_DBDICTUTIL_H 1

#include <stddef.h>
#include "dbdict.h"
#include "GcString.h"

namespace GcDbDictUtil
{

  inline Gcad::ErrorStatus
    dictionaryNameAt(GcString& name, GcDbObjectId itemId, GcDbObjectId ownerDictId)
  {
    name.setEmpty();
    GcDbDictionary* pDict;
    Gcad::ErrorStatus es = ::gcdbOpenObject(pDict, ownerDictId, GcDb::kForRead);
    if (es == Gcad::eOk) {
      es = pDict->nameAt(itemId, name);
      pDict->close();
    }
    return es;
  }

  inline Gcad::ErrorStatus
    dictionaryNameAt(GCHAR*& pName, GcDbObjectId itemId, GcDbObjectId ownerDictId)
  {
    GcString sName;
    return ::gcutGcStringToGChar(sName, pName,
      GcDbDictUtil::dictionaryNameAt(sName, itemId, ownerDictId));
  }

  inline Gcad::ErrorStatus
    dictionaryNameAt(GcString& name, GcDbObjectId itemId)
  {
    name.setEmpty();
    GcDbObject* pObject;
    Gcad::ErrorStatus es = ::gcdbOpenObject(pObject, itemId, GcDb::kForRead);
    if (es != Gcad::eOk)
      return es;
    const GcDbObjectId dictId = pObject->ownerId();
    es = pObject->close();
    return GcDbDictUtil::dictionaryNameAt(name, itemId, dictId);
  }

  inline Gcad::ErrorStatus
    dictionaryNameAt(GCHAR*& pName, GcDbObjectId itemId)
  {
    GcString sName;
    return ::gcutGcStringToGChar(sName, pName, GcDbDictUtil::dictionaryNameAt(sName, itemId));
  }

  inline Gcad::ErrorStatus
    dictionaryGetAt(GcDbObjectId& id, const GCHAR* name, GcDbObjectId ownerDictId)
  {
    id.setNull();
    GcDbDictionary* pDict;
    Gcad::ErrorStatus es = ::gcdbOpenObject(pDict, ownerDictId, GcDb::kForRead);
    if (es == Gcad::eOk) {
      es = pDict->getAt(name, id);
      pDict->close();
    }
    return es;
  }

#define DBDICTUTIL_MAKE_DICTIONARY_UTILS(LOWERNAME, UPPERNAME) \
inline Gcad::ErrorStatus \
get##UPPERNAME##Id(GcDbObjectId& id, const GCHAR* name, GcDbDatabase* pDb) \
{ \
    id.setNull(); \
    if (pDb == nullptr) \
        return Gcad::eNoDatabase; \
    return GcDbDictUtil::dictionaryGetAt(id, name, pDb->LOWERNAME##DictionaryId()); \
} \
inline Gcad::ErrorStatus \
get##UPPERNAME##Name(GcString& name, GcDbObjectId itemId) \
{ \
    name.setEmpty(); \
    GcDbDatabase* pDb = itemId.database(); \
    if (pDb == nullptr) \
        return Gcad::eNoDatabase; \
    return GcDbDictUtil::dictionaryNameAt(name, itemId, pDb->LOWERNAME##DictionaryId()); \
} \
inline Gcad::ErrorStatus \
get##UPPERNAME##Name(GCHAR*& name, GcDbObjectId itemId) \
{ \
    GcString sName; \
    return ::gcutGcStringToGChar(sName, name, GcDbDictUtil::get##UPPERNAME##Name(sName, itemId)); \
} \
inline bool \
has##UPPERNAME(const GCHAR* name, GcDbDatabase* pDb) \
{ \
    GcDbObjectId id; \
    return GcDbDictUtil::get##UPPERNAME##Id(id, name, pDb) == Gcad::eOk; \
}

  DBDICTUTIL_MAKE_DICTIONARY_UTILS(color, Color)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(group, Group)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(layout, Layout)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(material, Material)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(mLStyle, MLStyle)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(namedObjects, NamedObjects)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(plotSettings, PlotSettings)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(plotStyleName, PlotStyleName)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(scaleList, ScaleList)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(tableStyle, TableStyle)
    DBDICTUTIL_MAKE_DICTIONARY_UTILS(visualStyle, VisualStyle)

#undef DBDICTUTIL_MAKE_DICTIONARY_UTILS

}

#endif 