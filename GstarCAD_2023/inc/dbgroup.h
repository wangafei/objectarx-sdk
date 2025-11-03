/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBGROUP_H
#define GCDB_DBGROUP_H

#include "dbmain.h"
#include "dbapserv.h"

#pragma pack(push, 8)

class GcDbGroupIterator;

class GCDB_PORT GcDbGroup : public  GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbGroup);
  GcDbGroup();
  GcDbGroup(const GCHAR * grpDesc, bool selectable = true);
  ~GcDbGroup();

  GcDbGroupIterator*  newIterator();
  const GCHAR *       description() const;
  Gcad::ErrorStatus   setDescription(const GCHAR * grpDesc);
  bool                isSelectable() const;
  Gcad::ErrorStatus   setSelectable(bool selectable);
  Gcad::ErrorStatus   getName(GCHAR *& pName) const;
  Gcad::ErrorStatus   getName(const GCHAR *& pName) const;
  Gcad::ErrorStatus   getName(GcString & sName) const;

  const wchar_t * name() const
  {
    const wchar_t *pName;
    if (this->getName(pName) != Gcad::eOk)
      pName = nullptr;
    return pName;
  }

  Gcad::ErrorStatus   setName(const GCHAR * newName);
  bool                isNotAccessible() const;
  bool                isAnonymous() const;
  Gcad::ErrorStatus   setAnonymous();
  Gcad::ErrorStatus   append(GcDbObjectId id);
  Gcad::ErrorStatus   append(const GcDbObjectIdArray & ids);
  Gcad::ErrorStatus   prepend(GcDbObjectId id);
  Gcad::ErrorStatus   prepend(const GcDbObjectIdArray & ids);
  Gcad::ErrorStatus   insertAt(Gsoft::UInt32 idx, GcDbObjectId id);
  Gcad::ErrorStatus   insertAt(Gsoft::UInt32 idx, const GcDbObjectIdArray & ids);
  Gcad::ErrorStatus   remove(GcDbObjectId id);
  Gcad::ErrorStatus   removeAt(Gsoft::UInt32 idx);
  Gcad::ErrorStatus   remove(const GcDbObjectIdArray & ids);
  Gcad::ErrorStatus   removeAt(Gsoft::UInt32 idx, const GcDbObjectIdArray & ids);
  Gcad::ErrorStatus   replace(GcDbObjectId oldId, GcDbObjectId newId);
  Gcad::ErrorStatus   transfer(Gsoft::UInt32 fromIndex,
    Gsoft::UInt32 toIndex,
    Gsoft::UInt32 numItems);
  Gcad::ErrorStatus   clear();
  Gsoft::UInt32       numEntities() const;
  bool                has(const GcDbEntity* pEntity) const;
  Gsoft::UInt32       allEntityIds(GcDbObjectIdArray& ids) const;
  Gcad::ErrorStatus   getIndex(GcDbObjectId id, Gsoft::UInt32& idx) const;
  Gcad::ErrorStatus   reverse();
  Gcad::ErrorStatus   setColor(const GcCmColor& color);
  Gcad::ErrorStatus   setColorIndex(Gsoft::UInt16 color);
  Gcad::ErrorStatus   setLayer(const GCHAR * newVal);
  Gcad::ErrorStatus   setLayer(GcDbObjectId newVal);
  Gcad::ErrorStatus   setLinetype(const GCHAR * newVal);
  Gcad::ErrorStatus   setLinetype(GcDbObjectId newVal);
  Gcad::ErrorStatus   setLinetypeScale(double newval);
  Gcad::ErrorStatus   setVisibility(GcDb::Visibility newVal);
  Gcad::ErrorStatus   setHighlight(bool newVal);
  Gcad::ErrorStatus   setMaterial(const GCHAR * newVal);
  Gcad::ErrorStatus   setMaterial(GcDbObjectId newVal);
  Gcad::ErrorStatus   applyPartialUndo(GcDbDwgFiler* undoFiler,
    GcRxClass*    classObj) override;
  Gcad::ErrorStatus subClose() override;
  Gcad::ErrorStatus subErase(Gsoft::Boolean erasing) override;
  void              erased(const GcDbObject* dbObj,
    Gsoft::Boolean erasing) override;
  void              goodbye(const GcDbObject* dbObj) override;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

class GSOFT_NO_VTABLE GCDB_PORT GcDbGroupIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbGroupIterator);
  ~GcDbGroupIterator() {}

  virtual Gcad::ErrorStatus getObject(GcDbObject*& pObject, GcDb::OpenMode) = 0;
  virtual GcDbObjectId      objectId() const = 0;
  virtual bool              done() const = 0;
  virtual bool              next() = 0;
protected:
  GcDbGroupIterator() {}
};

#pragma pack(pop)

#endif