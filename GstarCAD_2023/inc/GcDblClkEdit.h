/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DOUBLECLICKEDIT_H
#define DOUBLECLICKEDIT_H

#include "gcdb.h"
#include "dbmain.h"

#pragma pack (push, 8)

class GSOFT_NO_VTABLE GCCORE_PORT GcDbDoubleClickEdit : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbDoubleClickEdit);

  virtual void startEdit(GcDbEntity *pEnt, GcGePoint3d pt) = 0;
  virtual void finishEdit(void) = 0;
};

#pragma pack (pop)

#endif 