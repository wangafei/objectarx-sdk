/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _rxdict_h
#define _rxdict_h 1

#include "rxobject.h"
#include "GdGChar.h"

#pragma pack (push, 8)

class GcRxDictionaryIterator;

class GcRxDictionary : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxDictionary, GCBASE_PORT);

  virtual GcRxObject*    at(const GCHAR* key) const = 0;
  virtual GcRxObject*    at(Gsoft::UInt32 id) const = 0;

  GcRxObject*            atPut(const GCHAR* key, GcRxObject* pObject);
  virtual GcRxObject*    atPut(const GCHAR* key, GcRxObject* pObject, Gsoft::UInt32& retId) = 0;
  virtual GcRxObject*    atPut(Gsoft::UInt32 id, GcRxObject* pObject) = 0;

  virtual Gsoft::Boolean resetKey(const GCHAR* oldKey, const GCHAR* newKey) = 0;
  virtual Gsoft::Boolean resetKey(Gsoft::UInt32 id, const GCHAR* newKey) = 0;

  virtual Gsoft::Boolean atKeyAndIdPut(const GCHAR* newKey, Gsoft::UInt32 id, GcRxObject* pObject) = 0;

  virtual GcRxObject*    remove(const GCHAR* key) = 0;
  virtual GcRxObject*    remove(Gsoft::UInt32 id) = 0;

  virtual Gsoft::Boolean has(const GCHAR* entryName) const = 0;
  virtual Gsoft::Boolean has(Gsoft::UInt32 id) const = 0;

  virtual Gsoft::UInt32  idAt(const GCHAR* key) const = 0;
  virtual const GCHAR*   keyAt(Gsoft::UInt32 id) const = 0;

  virtual Gsoft::UInt32  numEntries() const = 0;

  virtual GcRxDictionaryIterator* newIterator(GcRx::DictIterType type = GcRx::kDictSorted) = 0;

  virtual Gsoft::Boolean deletesObjects() const = 0;
  virtual Gsoft::Boolean isCaseSensitive() const = 0;
  virtual Gsoft::Boolean isSorted() const = 0;
};

extern "C" GCBASE_PORT GcRxDictionary* gcrxSysRegistry();

inline GcRxObject* GcRxDictionary::atPut(const GCHAR* key, GcRxObject* pObj)
{
  Gsoft::UInt32 temp;
  return atPut(key, pObj, temp);
}

#define gcrxClassDictionary \
GcRxDictionary::cast(gcrxSysRegistry()->at(GCRX_CLASS_DICTIONARY))

#define gcrxServiceDictionary \
GcRxDictionary::cast(gcrxSysRegistry()->at(GCRX_SERVICE_DICTIONARY))

#pragma pack (pop)
#endif
