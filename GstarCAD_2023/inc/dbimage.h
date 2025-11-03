/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBIMAGE_H
#define GD_DBIMAGE_H

#include "dbmain.h"
#include "gcgi.h"
#pragma pack (push, 8)

class GCDB_PORT GcDbImage : public GcDbEntity
{
public:
  GCRX_DECLARE_MEMBERS(GcDbImage);

  virtual GcGiSentScanLines* getScanLines(const GcGiRequestScanLines&) const = 0;
  virtual Gsoft::Boolean     freeScanLines(GcGiSentScanLines*) const = 0;
};

#pragma pack (pop) 
#endif  