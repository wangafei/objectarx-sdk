#ifndef _GCEDSUBSEL_H
#define _GCEDSUBSEL_H

#pragma once

class OdDbFullSubentPath;

#include "gcadstd.h"
#include "gcarray.h"
#include "gcdb.h"
#include "gdsdef.h"

#pragma pack (push, 8)

/* AutoCAD Sub-entity selection set routines */

GCED_DLL_DECL int gcedSSSubentLength(const gds_name sname, Hccad::Int32 index, Hccad::Int32* len);

GCED_DLL_DECL int gcedSSSubentAdd(const OdDbFullSubentPath& subentity, 
  const gds_name sname, 
  gds_name result);

GCED_DLL_DECL int gcedSSSubentDel(const OdDbFullSubentPath& subentity, 
  const gds_name ss);

GCED_DLL_DECL int gcedSSSubentMemb(const OdDbFullSubentPath& subentity,
  const gds_name ss);

GCED_DLL_DECL int gcedSSSubentName(const gds_name ss, 
  Hccad::Int32 entIndex, 
  Hccad::Int32 subentIndex, 
  OdDbFullSubentPath& subentity);

GCED_DLL_DECL int gcedSSSubentNameX(gds_resbuf** rbpp, 
  const gds_name ss,
  const Hccad::Int32 entIndex, 
  const Hccad::Int32 subentIndex,
  unsigned int flags);

GCED_DLL_DECL int gcedSSSetSubentTypes(const GcArray<GcDb::SubentType>& types);


#pragma pack (pop)
#endif  /* !_GCEDADS_H */
