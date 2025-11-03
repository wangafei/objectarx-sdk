/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBSPINDX_H
#define GD_DBSPINDX_H

#include "dbindex.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbSpatialIndex : public GcDbIndex
{
public:
  GCDB_DECLARE_MEMBERS(GcDbSpatialIndex);
  GcDbSpatialIndex();
  ~GcDbSpatialIndex();

  GcDbFilteredBlockIterator* newIterator(const GcDbFilter* pFilter) const override;
  Gcad::ErrorStatus rebuildFull(GcDbIndexUpdateData* pIdxData) override;

protected:
  Gcad::ErrorStatus rebuildModified(GcDbBlockChangeIterator* iter) override;
};

class GcDbImpSpatialIndexIterator;
class GcDbSpatialFilter;

class GCDB_PORT GcDbSpatialIndexIterator : public GcDbFilteredBlockIterator
{
public:
  GcDbSpatialIndexIterator(const GcDbSpatialIndex*  pIndex, const GcDbSpatialFilter* pFilter);
  ~GcDbSpatialIndexIterator();

  virtual Gcad::ErrorStatus start();
  virtual GcDbObjectId      next();
  virtual GcDbObjectId      id() const;
  virtual Gcad::ErrorStatus seek(GcDbObjectId id);

  virtual double estimatedHitFraction() const;
  virtual Gcad::ErrorStatus accepts(GcDbObjectId id, Gsoft::Boolean& stat) const;

private:
  GcDbImpSpatialIndexIterator* mpImpIter;
};

#pragma pack (pop)

#endif 