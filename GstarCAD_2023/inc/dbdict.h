/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDICT_H
#define GD_DBDICT_H

#include "dbmain.h"

#pragma pack(push, 8)

class GcDbImpDictionary;
class GcString;

class GSOFT_NO_VTABLE GCDB_PORT GcDbDictionaryIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDictionaryIterator);
  GcDbDictionaryIterator(const GcDbDictionaryIterator &) = delete;
  GcDbDictionaryIterator & operator = (const GcDbDictionaryIterator &) = delete;
  ~GcDbDictionaryIterator() {}

  virtual const GCHAR*      name() const = 0;
  virtual bool              name(GcString &sName) const = 0;

  template<class ObjType>
  Gcad::ErrorStatus getObject(ObjType *& pObject, GcDb::OpenMode mode = GcDb::kForRead)
  {
    const GcDbObjectId id = this->objectId();
    return ::gcdbOpenObject(pObject, id, mode, false);
  }

  Gcad::ErrorStatus getObject(GcDbObject *& pObject, GcDb::OpenMode mode = GcDb::kForRead)
  {
    return this->getObject<GcDbObject>(pObject, mode);
  }

  virtual GcDbObjectId      objectId() const = 0;
  virtual bool              done() const = 0;
  virtual bool              next() = 0;
  virtual bool              setPosition(GcDbObjectId objId) = 0;

protected:
  GcDbDictionaryIterator() {}
};

class GCDB_PORT GcDbDictionary : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDictionary);
  GcDbDictionary();
  ~GcDbDictionary();
  GcDbDictionary(const GcDbDictionary &) = delete;
  GcDbDictionary & operator = (const GcDbDictionary &) = delete;

  template<class ObjType>
  Gcad::ErrorStatus getAt(const GCHAR* entryName, ObjType *& entryObj, GcDb::OpenMode mode = GcDb::kForRead) const
  {
    entryObj = nullptr;
    GcDbObjectId id;
    Gcad::ErrorStatus es = this->getAt(entryName, id);
    if (es == Gcad::eOk)
      es = ::gcdbOpenObject(entryObj, id, mode, false);
    return es;
  }
  Gcad::ErrorStatus getAt(const GCHAR* entryName, GcDbObject *& entryObj, GcDb::OpenMode mode = GcDb::kForRead)
  {
    return this->getAt<GcDbObject>(entryName, entryObj, mode);
  }
  Gcad::ErrorStatus getAt(const GCHAR*   entryName, GcDbObjectId&  entryId) const;

  Gcad::ErrorStatus nameAt(GcDbObjectId objId, GCHAR*&      name) const;
  Gcad::ErrorStatus nameAt(GcDbObjectId objId, GcString & sName) const;
  bool              has(const GCHAR*  entryName) const;
  bool              has(GcDbObjectId objId) const;
  Gsoft::UInt32     numEntries() const;
  Gcad::ErrorStatus remove(const GCHAR *  key);
  Gcad::ErrorStatus remove(const GCHAR *  key, GcDbObjectId& returnId);
  Gcad::ErrorStatus remove(GcDbObjectId  objId);
  bool              setName(const GCHAR*   oldName, const GCHAR*   newName);
  Gcad::ErrorStatus setAt(const GCHAR* srchKey, GcDbObject*   newValue, GcDbObjectId& retObjId);
  bool              isTreatElementsAsHard() const;
  void              setTreatElementsAsHard(bool doIt);
  virtual void      setMergeStyle(GcDb::DuplicateRecordCloning style);

  GcDbDictionaryIterator* newIterator() const;
  Gcad::ErrorStatus subErase(Gsoft::Boolean pErasing = Gsoft::kTrue) override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

  GcDb::DuplicateRecordCloning mergeStyle() const override;
  void goodbye(const GcDbObject* pObject) override;
  void erased(const GcDbObject* pObject, bool bErasing) override;
  Gcad::ErrorStatus decomposeForSave(
    GcDb::GcDbDwgVersion ver,
    GcDbObject*&         replaceObj,
    GcDbObjectId&        replaceId,
    Gsoft::Boolean&      exchangeXData) override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gcad::ErrorStatus GcDbDictionary::nameAt(GcDbObjectId objId, GCHAR*& pName) const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, pName, this->nameAt(objId, sName));
}

inline bool GcDbDictionary::has(const GCHAR*  entryName) const
{
  GcDbObjectId id;
  return this->getAt(entryName, id) == Gcad::eOk;
}

inline Gcad::ErrorStatus GcDbDictionary::remove(const GCHAR*  entryName)
{
  GcDbObjectId id;
  return this->remove(entryName, id);
}

#pragma pack(pop)

#endif