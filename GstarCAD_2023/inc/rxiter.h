/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _rxiter_h
#define _rxiter_h 1

#include "rxobject.h"
#include "rxboiler.h"
#include "gcbasedefs.h" 
#pragma pack (push, 8)

class GcRxIterator : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxIterator, GCBASE_PORT);
  virtual bool done() const = 0;
  virtual bool next() = 0;
  virtual GcRxObject*    object() const = 0;
};

#pragma pack (pop)
#endif
