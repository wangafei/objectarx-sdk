#pragma once

GCED_DLL_DECL Gcad::ErrorStatus
gcedXrefNotifyCheckFileChanged(GcDbObjectId btrId, bool& hasChanged);

GCED_DLL_DECL Gcad::ErrorStatus
gcedSkipXrefNotification(GcDbDatabase* pHostDb, const GCHAR* xrefName);

GCED_DLL_DECL Gcad::ErrorStatus
gcedSetXrefResolvedWithUpdateStatus(GcDbBlockTableRecord* pBTR);

