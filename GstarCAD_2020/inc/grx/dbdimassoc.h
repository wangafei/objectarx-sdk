#pragma once
#include "gcadstd.h"
#include "dbmain.h"
#include "../DbDimassoc.h"


GCDB_DLL_DECL Gcad::ErrorStatus gcdbGetDimAssocId(GcDbObjectId dimId, GcDbObjectId& dimAssocId);
GCDB_DLL_DECL Gcad::ErrorStatus gcdbGetDimAssocIds(GcDbObjectId entId, GcDbObjectIdArray& dimAssocIds);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbPostDimAssoc(GcDbObjectId dimId, GcDbDimAssoc* pDimAssoc, 
                                                  GcDbObjectId& dimAssocId, bool isActive = true);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbUpdateDimension(GcDbObjectId dimId);

GCDB_DLL_DECL Gcad::ErrorStatus gcdbUpdateAllDimensions(GcDbDatabase* pDb);

GCDB_DLL_DECL bool gcdbIsTransSpatial(const GcDbFullSubentPath& idPath);