
#ifndef AECMODELER_INC_FLAGS_H
#define AECMODELER_INC_FLAGS_H

AECMODELER_NAMESPACE_BEGIN

typedef unsigned ZwFlag;

ZwFlag inline ZWFLAG(unsigned int i) { return (1 << i); }

inline int ZwIsSubset(ZwFlag a, ZwFlag b) { return ((a & b) == a); }

enum ZwOnOff { kOff, kOn };

AECMODELER_NAMESPACE_END

#endif
