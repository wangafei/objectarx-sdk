

#ifndef ZD_DBLYINDX_H
#define ZD_DBLYINDX_H

#include "zdbindex.h"

#pragma pack (push, 8)

class ZCDB_PORT ZcDbLayerIndex: public ZcDbIndex
{
public:
    ZCDB_DECLARE_MEMBERS(ZcDbLayerIndex);
	     ZcDbLayerIndex();
    virtual ~ZcDbLayerIndex();
    virtual ZcDbFilteredBlockIterator* newIterator(const ZcDbFilter* pFilter)
                                                   const override;

    virtual Zcad::ErrorStatus rebuildFull(ZcDbIndexUpdateData* pIdxData) override;

    Zcad::ErrorStatus compute(ZcDbLayerTable*       pLT,
                              ZcDbBlockTableRecord* pBTR);

protected:
    virtual Zcad::ErrorStatus rebuildModified(ZcDbBlockChangeIterator* iter) override;
};

class ZcDbImpLayerIndexIterator;
class ZcDbLayerFilter;

class ZCDB_PORT ZcDbLayerIndexIterator : public ZcDbFilteredBlockIterator
{
public:
    ZcDbLayerIndexIterator(const ZcDbLayerIndex*  pIndex,
                           const ZcDbLayerFilter* pFilter);
    virtual ~ZcDbLayerIndexIterator();

    virtual Zcad::ErrorStatus start() override;
    virtual ZcDbObjectId      next() override;
    virtual ZcDbObjectId      id() const override;
    virtual Zcad::ErrorStatus seek(ZcDbObjectId id) override;

    virtual double estimatedHitFraction() const override;
    virtual Zcad::ErrorStatus accepts(ZcDbObjectId id, 
                      ZSoft::Boolean& idPassesFilter) const override;

private:
        ZcDbImpLayerIndexIterator* mpImpIter;
};

#pragma pack (pop)

#endif 
