/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _RXDITER_H
#define _RXDITER_H 1

#include "rxobject.h"
#include "rxiter.h"
#include "GdGChar.h"
#pragma pack (push, 8)

class GcRxDictionaryIterator : public GcRxIterator
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcRxDictionaryIterator, GCBASE_PORT);

  virtual const GCHAR * key() const = 0;
          GcRxObject*   object() const override = 0;
  virtual Gsoft::UInt32 id() const = 0;
};

#pragma pack (pop)
#endif
