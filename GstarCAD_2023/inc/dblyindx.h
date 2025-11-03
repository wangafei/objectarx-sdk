/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBLYINDX_H
#define GD_DBLYINDX_H

#include "dbindex.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbLayerIndex : public GcDbIndex
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLayerIndex);
  GcDbLayerIndex();
  ~GcDbLayerIndex();
  GcDbFilteredBlockIterator* newIterator(const GcDbFilter* pFilter) const override;
  Gcad::ErrorStatus rebuildFull(GcDbIndexUpdateData* pIdxData) override;
  Gcad::ErrorStatus compute(GcDbLayerTable* pLT, GcDbBlockTableRecord* pBTR);

protected:
  Gcad::ErrorStatus rebuildModified(GcDbBlockChangeIterator* iter) override;
};

class GcDbImpLayerIndexIterator;
class GcDbLayerFilter;

class GCDB_PORT GcDbLayerIndexIterator : public GcDbFilteredBlockIterator
{
public:
  GcDbLayerIndexIterator(const GcDbLayerIndex*  pIndex, const GcDbLayerFilter* pFilter);
  ~GcDbLayerIndexIterator();

  Gcad::ErrorStatus start() override;
  GcDbObjectId      next() override;
  GcDbObjectId      id() const override;
  Gcad::ErrorStatus seek(GcDbObjectId id) override;

  double estimatedHitFraction() const override;
  Gcad::ErrorStatus accepts(GcDbObjectId id, Gsoft::Boolean& idPassesFilter) const override;

private:
  GcDbImpLayerIndexIterator* mpImpIter;
};

#pragma pack (pop)

#endif 