/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#pragma warning( disable: 4275 4251 )

#include "gcarray.h"
#include "gepnt3d.h"

#include "dbmain.h"
#include "dbents.h"
#include "GcDbCore2dDefs.h"     

#pragma pack (push, 8)

class GcDbImpDataCell;
class GcDbImpDataColumn;

class GCDB_PORT GcDbDataCell : public GcRxObject
{
public:
  enum CellType {
    kUnknown = 0,
    kInteger,
    kDouble,
    kCharPtr,
    kPoint,
    kObjectId,
    kHardOwnerId,
    kSoftOwnerId,
    kHardPtrId,
    kSoftPtrId,
    kBool,
    kVector
  };

  GcDbDataCell();
  GcDbDataCell(const GcDbDataCell& rCell);

  GcDbDataCell(bool b);
  GcDbDataCell(int i);
  GcDbDataCell(double d);
  GcDbDataCell(const GCHAR * pChar);
  GcDbDataCell(const GcGePoint3d& point);
  GcDbDataCell(const GcGeVector3d& vec);
  GcDbDataCell(const GcDbObjectId& id);
  GcDbDataCell(const GcDbHardOwnershipId& hoId);
  GcDbDataCell(const GcDbSoftOwnershipId& soId);
  GcDbDataCell(const GcDbHardPointerId&   hpId);
  GcDbDataCell(const GcDbSoftPointerId&   spId);

  ~GcDbDataCell();
  GCRX_DECLARE_MEMBERS(GcDbDataCell);

  virtual void init();

  virtual GcDbDataCell& operator = (const GcDbDataCell &cell);
  virtual GcDbDataCell& operator = (bool b);
  virtual GcDbDataCell& operator = (int i);
  virtual GcDbDataCell& operator = (double d);
  virtual GcDbDataCell& operator = (const GCHAR * pChar);

  virtual GcDbDataCell& operator = (const GcString & s);
  virtual GcDbDataCell& operator = (const GcGePoint3d &pt);
  virtual GcDbDataCell& operator = (const GcGeVector3d &vec);
  virtual GcDbDataCell& operator = (const GcDbObjectId &id);
  virtual GcDbDataCell& operator = (const GcDbHardOwnershipId &hoId);
  virtual GcDbDataCell& operator = (const GcDbSoftOwnershipId &soId);
  virtual GcDbDataCell& operator = (const GcDbHardPointerId   &hpId);
  virtual GcDbDataCell& operator = (const GcDbSoftPointerId   &spId);

  virtual operator bool() const;
  virtual operator int() const;
  virtual operator double() const;
  virtual operator const GCHAR *() const;

  virtual operator GcString & () const;
  virtual operator GcGePoint3d&()const;
  virtual operator GcGeVector3d&()const;
  virtual operator GcDbObjectId&() const;
  virtual operator GcDbHardOwnershipId&() const;
  virtual operator GcDbSoftOwnershipId&() const;
  virtual operator GcDbHardPointerId&() const;
  virtual operator GcDbSoftPointerId&() const;

  virtual bool operator == (const GcDbDataCell &cell) const;
  virtual bool operator != (const GcDbDataCell &cell) const;

  virtual GcDbDataCell::CellType type() const;

private:
  friend class GcDbSystemInternals;
  GcDbImpDataCell* mpImpDataCell;
};

typedef GcArray<GcDbDataCell, GcArrayObjectCopyReallocator<GcDbDataCell> > GcDbDataCellArray;

class GCDB_PORT GcDbDataColumn : public GcRxObject
{
public:
  GcDbDataColumn();
  GcDbDataColumn(const GcDbDataColumn& rCol);
  GcDbDataColumn(const GcDbDataCell::CellType type, const GCHAR * pColName = NULL);

  ~GcDbDataColumn();
  GCRX_DECLARE_MEMBERS(GcDbDataColumn);

  virtual Gsoft::UInt32 physicalLength() const;
  virtual Gsoft::UInt32 growLength() const;
  virtual Gcad::ErrorStatus setPhysicalLength(Gsoft::UInt32 n);
  virtual Gcad::ErrorStatus setGrowLength(Gsoft::UInt32 n);

  virtual GcDbDataColumn& operator = (const GcDbDataColumn& col);

  virtual Gcad::ErrorStatus setColumnType(GcDbDataCell::CellType type);
  virtual GcDbDataCell::CellType columnType() const;
  virtual Gcad::ErrorStatus setColumnName(const GCHAR * pName);
  virtual const GCHAR * columnName() const;

  virtual Gcad::ErrorStatus getCellAt(Gsoft::UInt32 index, GcDbDataCell& outCell) const;
  virtual Gcad::ErrorStatus setCellAt(Gsoft::UInt32 index, const GcDbDataCell& cell);
  virtual Gcad::ErrorStatus appendCell(const GcDbDataCell& cell);
  virtual Gcad::ErrorStatus insertCellAt(Gsoft::UInt32 index, const GcDbDataCell& cell);
  virtual Gcad::ErrorStatus removeCellAt(Gsoft::UInt32 index);
  virtual Gcad::ErrorStatus getIndexAtCell(const GcDbDataCell& cell, Gsoft::UInt32& index) const;

  virtual Gsoft::UInt32 numCells() const;

private:
  friend class GcDbSystemInternals;
  friend class GcDbImpDataColumn;
  GcDbImpDataColumn* mpImpDataColumn;
};

class GCDB_PORT GcDbDataTable : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDataTable);

  GcDbDataTable();
  ~GcDbDataTable();

  virtual GcDbDataTable& operator = (const GcDbDataTable& table);

  virtual Gsoft::UInt32 numColumns() const;
  virtual Gsoft::UInt32 numRows() const;

  virtual Gcad::ErrorStatus setNumRowsPhysicalSize(Gsoft::UInt32 n);
  virtual Gcad::ErrorStatus setNumRowsGrowSize(Gsoft::UInt32 n);
  virtual Gsoft::UInt32 numRowsPhysicalSize() const;
  virtual Gsoft::UInt32 numRowsGrowSize() const;
  virtual Gcad::ErrorStatus setNumColsPhysicalSize(Gsoft::UInt32 n);
  virtual Gcad::ErrorStatus setNumColsGrowSize(Gsoft::UInt32 n);
  virtual Gsoft::UInt32 numColsPhysicalSize() const;
  virtual Gsoft::UInt32 numColsGrowSize() const;

  virtual const GCHAR * tableName() const;
  virtual Gcad::ErrorStatus setTableName(const GCHAR * pName);

  virtual Gcad::ErrorStatus getColumnAt(Gsoft::UInt32 index, const GcDbDataColumn*& pCol) const;

  virtual Gcad::ErrorStatus getColumnNameAt(Gsoft::UInt32 index, GcString & sName) const;
  virtual Gcad::ErrorStatus getColumnNameAt(Gsoft::UInt32 index, GCHAR *& pName) const final;
  virtual Gcad::ErrorStatus getColumnTypeAt(Gsoft::UInt32 index, GcDbDataCell::CellType& type) const;
  virtual Gcad::ErrorStatus getColumnIndexAtName(const GCHAR * pName, Gsoft::UInt32& index) const;

  virtual Gcad::ErrorStatus appendColumn(GcDbDataCell::CellType type, const GCHAR * pColName = NULL);
  virtual Gcad::ErrorStatus insertColumnAt(Gsoft::UInt32 index, GcDbDataCell::CellType type, const GCHAR * pColName = NULL);
  virtual Gcad::ErrorStatus removeColumnAt(Gsoft::UInt32 index);

  virtual Gcad::ErrorStatus getRowAt(Gsoft::UInt32 index, GcDbDataCellArray& outRow) const;
  virtual Gcad::ErrorStatus setRowAt(Gsoft::UInt32 index, const GcDbDataCellArray& row, bool bValidate = true);
  virtual Gcad::ErrorStatus appendRow(const GcDbDataCellArray& row, bool bValidate = true);

  virtual Gcad::ErrorStatus insertRowAt(Gsoft::UInt32 index, const GcDbDataCellArray& row, bool bValidate = true);
  virtual Gcad::ErrorStatus removeRowAt(Gsoft::UInt32 index);

  virtual Gcad::ErrorStatus getCellAt(Gsoft::UInt32 row, Gsoft::UInt32 col, GcDbDataCell& outCell) const;
  virtual Gcad::ErrorStatus setCellAt(Gsoft::UInt32 row, Gsoft::UInt32 col, const GcDbDataCell& cell);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  Gcad::ErrorStatus audit(GcDbAuditInfo* pAuditInfo) override;
};

inline Gcad::ErrorStatus GcDbDataTable::getColumnNameAt(Gsoft::UInt32 index, GCHAR *& pName) const
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, pName, this->getColumnNameAt(index, sName));
}

#pragma pack (pop)