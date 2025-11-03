#ifndef _OD_DB_INDEXCOMPOSITEFILTEREDBLOCKITERATOR_
#define _OD_DB_INDEXCOMPOSITEFILTEREDBLOCKITERATOR_

#include "OdError.h"
#include "DbFilter.h"
#include "DbBlockTableRecord.h"

class OdDbCompositeFilteredBlockIterator
{
private:
  OdDbCompositeFilteredBlockIterator(
    const OdDbCompositeFilteredBlockIterator& copyFrom);

protected:
  OdDbCompositeFilteredBlockIterator() {}

public:
  virtual ~OdDbCompositeFilteredBlockIterator() {}

  virtual OdResult init(OdDbFilter* const * ppFilters,
    int numFilters,
    const OdDbBlockTableRecord* pBtr) = 0;

  virtual OdResult start() = 0;
  virtual OdDbObjectId next() = 0;
  virtual OdDbObjectId id() const = 0;

  virtual OdResult seek(OdDbObjectId id) = 0;
  static OdDbCompositeFilteredBlockIterator* newIterator();

private:
  static OdDbCompositeFilteredBlockIterator *m_pCls;
};

#endif