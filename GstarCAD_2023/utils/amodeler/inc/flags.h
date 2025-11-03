/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_FLAGS_H
#define GMODELER_INC_FLAGS_H

GMODELER_NAMESPACE_BEGIN

typedef unsigned Flag;

Flag inline FLAG(unsigned int i) { return (1 << i); }

inline int isSubset(Flag a, Flag b) { return ((a & b) == a); }

enum OnOff
{
  kOff,
  kOn
};

GMODELER_NAMESPACE_END
#endif
