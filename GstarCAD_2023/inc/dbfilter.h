/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBFILTER_H
#define GD_DBFILTER_H

#include "dbmain.h"

#pragma pack (push, 8)

class GcDbFilteredBlockIterator;

class GCDB_PORT GcDbFilter : public  GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbFilter);
  GcDbFilter();
  ~GcDbFilter();
  virtual GcRxClass* indexClass() const;
};

#pragma pack (pop)

#endif 