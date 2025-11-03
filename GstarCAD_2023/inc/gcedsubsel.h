/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcedsubsel_h
#define _gcedsubsel_h 1

#pragma once

class GcDbFullSubentPath;

#include "gcarray.h"
#include "gcdb.h"
#include "gdsdef.h"

#pragma pack (push, 8)

GCCORE_PORT int            gcedSSSubentLength(const gds_name sname, Gsoft::Int32 index, Gsoft::Int32* len);

GCCORE_PORT int            gcedSSSubentAdd(const GcDbFullSubentPath& subentity,
  const gds_name sname,
  gds_name result);

GCCORE_PORT int            gcedSSSubentDel(const GcDbFullSubentPath& subentity,
  const gds_name ss);

GCCORE_PORT int            gcedSSSubentMemb(const GcDbFullSubentPath& subentity,
  const gds_name ss);

GCCORE_PORT int            gcedSSSubentName(const gds_name ss,
  Gsoft::Int32 entIndex,
  Gsoft::Int32 subentIndex,
  GcDbFullSubentPath& subentity);

GCCORE_PORT int            gcedSSSubentNameX(struct resbuf** rbpp,
  const gds_name ss,
  const Gsoft::Int32 entIndex,
  const Gsoft::Int32 subentIndex,
  unsigned int flags);

GCCORE_PORT int            gcedSSSetSubentTypes(const GcArray<GcDb::SubentType>& types);

#pragma pack (pop)
#endif  