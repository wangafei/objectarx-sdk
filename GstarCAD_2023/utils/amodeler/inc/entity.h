/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_ENTITY_H
#define GMODELER_INC_ENTITY_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

class DllImpExp Entity
{
public:
  Entity() : mFlags(0) {}
  virtual ~Entity() {}

  Flag flags()           const { return mFlags; }
  void setFlags(Flag flags) { mFlags = flags; }
  bool isFlagOn(Flag flag)  const { return (mFlags & flag) != 0; }
  bool isFlagOff(Flag flag)  const { return (mFlags & flag) == 0; }
  void setFlagOn(Flag flag) { mFlags |= flag; }
  void setFlagOff(Flag flag) { mFlags &= ~flag; }
  void flipFlag(Flag flag) { mFlags ^= flag; }

#undef new
#undef delete

  void* operator new   (size_t);
  void  operator delete(void*);

#ifdef _DEBUG
  void* operator new   (size_t, const char* lpszFileName, int nLine);
  void operator  delete(void*, const char* lpszFileName, int nLine);
#endif

private:
  Flag mFlags;
};

GMODELER_NAMESPACE_END
#endif
