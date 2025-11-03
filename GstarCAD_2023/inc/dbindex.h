/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBINDEX_H
#define GD_DBINDEX_H

#include "dbmain.h"

#pragma pack(push, 8)

class GcDbIndexIterator;
class GcDbFilter;
class GcDbIndexUpdateData;
class GcDbBlockChangeIterator;
class GcDbFilteredBlockIterator;
class GcDbFilter;
class GcDbImpDatabase;
class GcDbBlockTableRecord;
class GcDbBlockChangeIterator;
class GcDbIndexUpdateData;

class GCDB_PORT GcDbIndex : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbIndex);
  GcDbIndex();
  ~GcDbIndex();

  virtual GcDbFilteredBlockIterator* newIterator(const GcDbFilter* pFilter) const;

  virtual Gcad::ErrorStatus rebuildFull(GcDbIndexUpdateData* pIdxData);
  virtual GcDbObjectId objectBeingIndexedId()  const;
  void           setLastUpdatedAt(const GcDbDate& time);
  GcDbDate       lastUpdatedAt() const;
  void           setLastUpdatedAtU(const GcDbDate& time);
  GcDbDate       lastUpdatedAtU() const;
  Gsoft::Boolean isUptoDate() const;

protected:
  virtual Gcad::ErrorStatus rebuildModified(GcDbBlockChangeIterator* iter);
  friend class GcDbImpIndex;
  friend Gcad::ErrorStatus processBTRIndexObjects(
    GcDbBlockTableRecord* pBTR,
    int indexCtlVal,
    GcDbBlockChangeIterator* pBlkChgIter,
    GcDbIndexUpdateData*     pIdxUpdData);
};

class GCDB_PORT GcDbFilteredBlockIterator
{
public:
  GcDbFilteredBlockIterator() {}
  virtual ~GcDbFilteredBlockIterator() {}

  virtual Gcad::ErrorStatus start() = 0;
  virtual GcDbObjectId      next() = 0;
  virtual GcDbObjectId      id() const = 0;
  virtual Gcad::ErrorStatus seek(GcDbObjectId id) = 0;

  virtual double estimatedHitFraction() const = 0;
  virtual Gcad::ErrorStatus accepts(GcDbObjectId id, Gsoft::Boolean& idPassesFilter) const = 0;
  virtual Gsoft::Boolean    buffersForComposition() const;
  virtual Gcad::ErrorStatus addToBuffer(GcDbObjectId id);
};

class GCCORE_PORT GcDbCompositeFilteredBlockIterator
{
private:
  GcDbCompositeFilteredBlockIterator(
    const GcDbCompositeFilteredBlockIterator& copyFrom);

protected:
  GcDbCompositeFilteredBlockIterator() {}

public:
  virtual ~GcDbCompositeFilteredBlockIterator() {}

  virtual Gcad::ErrorStatus init(GcDbFilter* const * ppFilters, int numFilters, const GcDbBlockTableRecord* pBtr) = 0;
  virtual Gcad::ErrorStatus start() = 0;
  virtual GcDbObjectId      next() = 0;
  virtual GcDbObjectId      id() const = 0;
  virtual Gcad::ErrorStatus seek(GcDbObjectId id) = 0;
  static GcDbCompositeFilteredBlockIterator* newIterator();
};

class GcDbBlockTableRecord;
class GcDbBlockReference;

namespace GcDbIndexFilterManager
{
  GCDB_PORT Gcad::ErrorStatus updateIndexes(GcDbDatabase* pDb);
  GCDB_PORT Gcad::ErrorStatus addIndex(GcDbBlockTableRecord* pBTR,
    GcDbIndex*            pIndex);
  GCDB_PORT Gcad::ErrorStatus removeIndex(GcDbBlockTableRecord* pBTR,
    const GcRxClass*      key);
  GCDB_PORT Gcad::ErrorStatus getIndex(const GcDbBlockTableRecord* pBTR,
    const GcRxClass* key,
    GcDb::OpenMode readOrWrite,
    GcDbIndex*& pIndex);
  GCDB_PORT Gcad::ErrorStatus getIndex(const GcDbBlockTableRecord* pBTR,
    int index,
    GcDb::OpenMode readOrWrite,
    GcDbIndex*& pIndex);
  GCDB_PORT int numIndexes(const GcDbBlockTableRecord* pBtr);
  GCDB_PORT Gcad::ErrorStatus addFilter(GcDbBlockReference* pBlkRef,
    GcDbFilter*         pFilter);
  GCDB_PORT Gcad::ErrorStatus removeFilter(GcDbBlockReference* pBlkRef,
    const GcRxClass*    key);
  GCDB_PORT Gcad::ErrorStatus getFilter(const GcDbBlockReference* pRef,
    const GcRxClass*          key,
    GcDb::OpenMode readOrWrite,
    GcDbFilter*&   pFilter);
  GCDB_PORT Gcad::ErrorStatus getFilter(const GcDbBlockReference* pRef,
    int index,
    GcDb::OpenMode readOrWrite,
    GcDbFilter*& pFilter);
  GCDB_PORT int  numFilters(const GcDbBlockReference* pBlkRef);
};

class GcDbHandleTable;
class GcDbHandleTableIterator;

class GCDB_PORT GcDbIndexUpdateData
{
public:
  enum UpdateFlags
  {
    kModified = 1,
    kDeleted = 2,
    kProcessed = 4,
    kUnknownKey = 8
  };

  Gcad::ErrorStatus addId(GcDbObjectId id);
  Gcad::ErrorStatus setIdFlags(GcDbObjectId id, Gsoft::UInt8 flags);
  Gcad::ErrorStatus setIdData(GcDbObjectId id, Gsoft::ULongPtr data);
  Gcad::ErrorStatus getIdData(GcDbObjectId id, Gsoft::ULongPtr& data)  const;
  Gcad::ErrorStatus getIdFlags(GcDbObjectId id, Gsoft::UInt8&  flags) const;
  Gcad::ErrorStatus getFlagsAndData(GcDbObjectId   id, Gsoft::UInt8&  flags, Gsoft::ULongPtr& data) const;

private:
  GcDbIndexUpdateData();
  ~GcDbIndexUpdateData();
  GcDbIndexUpdateData(const GcDbIndexUpdateData&);
  GcDbHandleTable* mpTable;

  friend class GcDbIndexUpdateDataIterator;
  friend class GcDbImpDatabase;
};

class GCDB_PORT GcDbIndexUpdateDataIterator
{
public:
  GcDbIndexUpdateDataIterator(const GcDbIndexUpdateData* p);
  ~GcDbIndexUpdateDataIterator();

  void start();
  void next();
  bool done();

  Gcad::ErrorStatus currentData(GcDbObjectId&  id,
    Gsoft::UInt8&  flags,
    Gsoft::ULongPtr& data) const;

private:
  GcDbHandleTableIterator* mpIter;
};

class GCDB_PORT GcDbBlockChangeIterator
{
private:
  GcDbBlockChangeIterator();
  GcDbBlockChangeIterator(const GcDbBlockChangeIterator&);
  GcDbBlockChangeIterator(GcDbObjectId btrId, GcDbIndexUpdateData* pIdxUpdData);
  ~GcDbBlockChangeIterator();

public:
  void         start();
  GcDbObjectId id() const;
  void         next();
  bool         done();

  Gcad::ErrorStatus    curIdInfo(GcDbObjectId&  id, Gsoft::UInt8&  flags, Gsoft::ULongPtr& data) const;
  Gcad::ErrorStatus    setCurIdInfo(Gsoft::UInt8   flags, Gsoft::ULongPtr data);
  GcDbIndexUpdateData* updateData() const;
  void clearProcessedFlags();

private:
  GcDbIndexUpdateData*         mpIds;
  GcDbObjectId                 mBTRId;
  GcDbIndexUpdateDataIterator* mpIter;
  friend class GcDbImpDatabase;
};

#pragma pack(pop)

#endif 