
#ifndef ZD_DBDICTUTIL_H
#define ZD_DBDICTUTIL_H 1

#include <stddef.h>
#include "zdbdict.h"
#include "zAcString.h"

namespace ZcDbDictUtil
{

inline Zcad::ErrorStatus
dictionaryNameAt(ZcString& name, ZcDbObjectId itemId, ZcDbObjectId ownerDictId)
{
	name.setEmpty();
    ZcDbDictionary* pDict;
    Zcad::ErrorStatus es = ::zcdbOpenObject(pDict, ownerDictId, ZcDb::kForRead);
    if (es == Zcad::eOk) {
        es = pDict->nameAt(itemId, name);
        pDict->close();
    }
    return es;
}

inline Zcad::ErrorStatus
dictionaryNameAt(ZTCHAR*& pName, ZcDbObjectId itemId, ZcDbObjectId ownerDictId)
{
    ZcString sName;
    return ::zcutZcStringToZTChar(sName, pName,
        ZcDbDictUtil::dictionaryNameAt(sName, itemId, ownerDictId));
}


inline Zcad::ErrorStatus
dictionaryNameAt(ZcString& name, ZcDbObjectId itemId)
{
	name.setEmpty();
    ZcDbObject* pObject;
    Zcad::ErrorStatus es = ::zcdbOpenObject(pObject, itemId, ZcDb::kForRead);
    if (es != Zcad::eOk)
        return es;
    const ZcDbObjectId dictId = pObject->ownerId();
    es = pObject->close();
    return ZcDbDictUtil::dictionaryNameAt(name, itemId, dictId);
}

inline Zcad::ErrorStatus
dictionaryNameAt(ZTCHAR*& pName, ZcDbObjectId itemId)
{
    ZcString sName;
    return ::zcutZcStringToZTChar(sName, pName, ZcDbDictUtil::dictionaryNameAt(sName, itemId));
}

inline Zcad::ErrorStatus
dictionaryGetAt(ZcDbObjectId& id, const ZTCHAR* name, ZcDbObjectId ownerDictId)
{
	id.setNull();
    ZcDbDictionary* pDict;
    Zcad::ErrorStatus es = ::zcdbOpenObject(pDict, ownerDictId, ZcDb::kForRead);
    if (es == Zcad::eOk) {
        es = pDict->getAt(name, id);
        pDict->close();
    }
    return es;
}

#define DBDICTUTIL_MAKE_DICTIONARY_UTILS(LOWERNAME, UPPERNAME) \
inline Zcad::ErrorStatus \
get##UPPERNAME##Id(ZcDbObjectId& id, const ZTCHAR* name, ZcDbDatabase* pDb) \
{ \
    id.setNull(); \
    if (pDb == nullptr) \
        return Zcad::eNoDatabase; \
    return ZcDbDictUtil::dictionaryGetAt(id, name, pDb->LOWERNAME##DictionaryId()); \
} \
inline Zcad::ErrorStatus \
get##UPPERNAME##Name(ZcString& name, ZcDbObjectId itemId) \
{ \
    name.setEmpty(); \
    ZcDbDatabase* pDb = itemId.database(); \
    if (pDb == nullptr) \
        return Zcad::eNoDatabase; \
    return ZcDbDictUtil::dictionaryNameAt(name, itemId, pDb->LOWERNAME##DictionaryId()); \
} \
inline Zcad::ErrorStatus \
get##UPPERNAME##Name(ZTCHAR*& name, ZcDbObjectId itemId) \
{ \
    ZcString sName; \
    return ::zcutZcStringToZTChar(sName, name, ZcDbDictUtil::get##UPPERNAME##Name(sName, itemId)); \
} \
inline bool \
has##UPPERNAME(const ZTCHAR* name, ZcDbDatabase* pDb) \
{ \
    ZcDbObjectId id; \
    return ZcDbDictUtil::get##UPPERNAME##Id(id, name, pDb) == Zcad::eOk; \
}

DBDICTUTIL_MAKE_DICTIONARY_UTILS( color,         Color)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( group,         Group)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( layout,        Layout)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( material,      Material)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( mLStyle,       MLStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( namedObjects,  NamedObjects)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( plotSettings,  PlotSettings)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( plotStyleName, PlotStyleName)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( scaleList,     ScaleList)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( tableStyle,    TableStyle)
DBDICTUTIL_MAKE_DICTIONARY_UTILS( visualStyle,    VisualStyle)

#undef DBDICTUTIL_MAKE_DICTIONARY_UTILS

}

#endif 
