/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBFRAME_H
#define GD_DBFRAME_H

#include "dbmain.h"
#include "gepnt3d.h"

#pragma pack (push, 8)

class GSOFT_NO_VTABLE GCDB_PORT GcDbFrame : public GcDbEntity
{
protected:
  GcDbFrame();
public:
  GCDB_DECLARE_MEMBERS(GcDbFrame);
  ~GcDbFrame();
};

#pragma pack (pop)

#endif  
