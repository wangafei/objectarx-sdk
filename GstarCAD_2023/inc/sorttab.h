/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_SORTTAB_H
#define GCDB_SORTTAB_H 1

#include "dbmain.h"

class GcDbImpSortentsTable;

class GCDB_PORT GcDbSortentsTable : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSortentsTable);
  GcDbSortentsTable();
  ~GcDbSortentsTable();

  Gsoft::Boolean      sortAs(GcDbObjectId, GcDbHandle&) const;
  void                getSortHandle(GcDbObjectId id, GcDbHandle& h) const;

  Gcad::ErrorStatus   remove(GcDbObjectId);
  Gcad::ErrorStatus   moveToBottom(const GcDbObjectIdArray& ar);
  Gcad::ErrorStatus   moveToTop(const GcDbObjectIdArray& ar);
  Gcad::ErrorStatus   moveBelow(const GcDbObjectIdArray& ar, GcDbObjectId target);
  Gcad::ErrorStatus   moveAbove(const GcDbObjectIdArray& ar, GcDbObjectId target);

  Gcad::ErrorStatus   swapOrder(GcDbObjectId, GcDbObjectId);

  Gcad::ErrorStatus   setBlockId(GcDbObjectId);
  GcDbObjectId        blockId() const;

  Gcad::ErrorStatus   firstEntityIsDrawnBeforeSecond(GcDbObjectId first, GcDbObjectId second, bool& result) const;

  Gcad::ErrorStatus   getFullDrawOrder(GcDbObjectIdArray& ents, Gsoft::UInt8 honorSortentsMask = 0) const;
  Gcad::ErrorStatus   getRelativeDrawOrder(GcDbObjectIdArray& ar, Gsoft::UInt8 honorSortentsMask = 0) const;
  Gcad::ErrorStatus   setRelativeDrawOrder(const GcDbObjectIdArray& ar);

  Gcad::ErrorStatus   applyPartialUndo(GcDbDwgFiler*, GcRxClass*) override;
  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler*) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler*) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler*) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler*) const override;
  Gcad::ErrorStatus   audit(GcDbAuditInfo* pAuditInfo) override;

private:
  friend class GcDbSystemInternals;
  GcDbImpSortentsTable*   mpImpObj;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

#endif
