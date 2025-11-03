/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

struct GcCell;
struct GcCellRange;
class GcDbTable;
class GcDbLinkedTableData;

class GCDB_PORT GcDbTableIterator
{
public:
  GcDbTableIterator(const GcDbTable* pTable);
  GcDbTableIterator(const GcDbTable* pTable, const GcCellRange* pRange, GcDb::TableIteratorOption nOption);
  GcDbTableIterator(const GcDbLinkedTableData* pTable);
  GcDbTableIterator(const GcDbLinkedTableData* pTable, const GcCellRange* pRange, GcDb::TableIteratorOption nOption);
  GcDbTableIterator(const GcCellRange& range);
  GcDbTableIterator(const GcCellRange& range, GcDb::TableIteratorOption nOption);
  ~GcDbTableIterator();

  void            start(void);
  void            step(void);
  bool            done(void);
  bool            seek(const GcCell& cell);
  const GcCell&   getCell(void) const;
  int             getRow(void) const;
  int             getColumn(void) const;

protected:
  GcDbTableIterator(void);

protected:
  void        *   mpImpObj;
};