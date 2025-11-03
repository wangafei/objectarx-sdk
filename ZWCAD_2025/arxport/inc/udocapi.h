#pragma once

#ifndef acedGetCurrentView
#define acedGetCurrentView zcedGetCurrentView
#endif //#ifndef acedGetCurrentView
//Acad::ErrorStatus acedGetCurrentView(AcDbViewTableRecord& acVTRecord);

#ifndef acedLinetypeDialog
#define acedLinetypeDialog zcedLinetypeDialog
#endif // ifndef acedLinetypeDialog
//bool acedLinetypeDialog(AcDbDatabase* pDb, AcDbObjectId curLT, bool includeByBlockByLayer, ACHAR*& selectedLTname, AcDbObjectId& selectedLTid);
//bool acedLinetypeDialog(AcDbObjectId old_linetypeId, bool includeByBlockByLayer, ACHAR*& new_linetypeName, AcDbObjectId& new_linetypeId);

#ifndef acedGetPredefinedPattens
#define acedGetPredefinedPattens zcedGetPredefinedPattens
#endif // ifndef acedGetPredefinedPattens
//bool acedGetPredefinedPattens(AcStringArray& arrPredefinedPattern);

#ifndef acrxEntryPoint
#define acrxEntryPoint zcrxEntryPoint
#endif // ifndef acrxEntryPoint

#ifndef acedPostCommand
#define acedPostCommand zcedPostCommand
#endif // ifndef acedPostCommand
//Adesk::Boolean acedPostCommand(LPCTSTR cmd);

#ifndef acdbGetDbmod
#define acdbGetDbmod zcdbGetDbmod
#endif // ifndef acdbGetDbmod
//int acdbGetDbmod(AcDbDatabase* pDb);

#ifndef acedHatchPalletteDialog
#define acedHatchPalletteDialog zcedHatchPalletteDialog
#endif // ifndef acedHatchPalletteDialog
//bool acedHatchPalletteDialog(const ACHAR* pszCurrentPattern, bool bIsShowCustomPattern, ACHAR*& prefchNewSelectedPattern);

#ifndef acedNEntSelPEx
#define acedNEntSelPEx zcedNEntSelPEx
#endif // ifndef acedNEntSelPEx
//int acedNEntSelPEx(const ACHAR* str, ads_name entres, ads_point ptres, int pickflag, ads_matrix xformres, struct resbuf** refstkres, 
//    unsigned int uTransSpaceFlag, Adesk::GsMarker* gsmarker);

#ifndef acgsSetLineWeightDisplay
#define acgsSetLineWeightDisplay zcgsSetLineWeightDisplay
#endif // ifndef acgsSetLineWeightDisplay
//void acgsSetLineWeightDisplay(AcGsDevice* gsDevice, bool val);

#ifndef acedGetRecentUndoHistory
#define acedGetRecentUndoHistory zcedGetRecentUndoHistory
#endif // ifndef acedGetRecentUndoHistory
//extern "C" int acedGetRecentUndoHistory(AcStringArray&);

#ifndef acedGetRecentRedoHistory
#define acedGetRecentRedoHistory zcedGetRecentRedoHistory
#endif // ifndef acedGetRecentRedoHistory
//extern "C" int acedGetRecentRedoHistory(AcStringArray&);

#ifndef acedPlotStyleDialog
#define acedPlotStyleDialog zcedPlotStyleDialog
#endif // ifndef acedPlotStyleDialog
///bool acedPlotStyleDialog(BOOL bIsSelectPlotStyle, BOOL bByLayerBlock, ACHAR*& szPlotStyle);

#ifndef acedPlotstyleDialog
#define acedPlotstyleDialog zcedPlotstyleDialog
#endif // ifndef acedPlotstyleDialog
//bool zcedPlotstyleDialog(const ZTCHAR* szSelectPlotStyle, bool bByLayerBlock, ZTCHAR*& szPlotStyle);

#ifndef OPMxmark
#define OPMxmark ZwOPMxmark
#endif // #ifndef OPMxmark
//void OPMxmark(double x, double y, double z, LONG_PTR** pseg);

#ifndef OPMxemark
#define OPMxemark ZwOPMxemark
#endif // #ifndef OPMxemark
//void OPMxemark(LONG_PTR** pseg);

#ifndef acedLineWeightDialog
#define acedLineWeightDialog zcedLineWeightDialog
#endif // #ifndef acedLineWeightDialog
//bool acedLineWeightDialog(AcDb::LineWeight curlweight, bool bIncludeByLyerByBlk, AcDb::LineWeight& selectedlweight);
//bool acedLineWeightDialog(AcDb::LineWeight curlweight, bool bIncludeByLyerByBlk, AcDb::LineWeight& selectedlweight, AcDbDatabase* pDb, HWND hParentWindow);

#ifndef acedRegenLayers
#define acedRegenLayers zcedRegenLayers
#endif //#ifndef acedRegenLayers
//void acedRegenLayers(const AcDbObjectIdArray& layerIds, int nParam1, int nParam2);


//bool ExtensionLoader_IsLoaded(const ACHAR * fname);

//Acad::ErrorStatus LoadManagedDll(const ACHAR * fname);

//Acad::ErrorStatus purgeDatabase(AcDbDatabase* pDb);

//void zcmdRecordCRAddCallBack(void (*cbfunc)(const ACHAR*));

//void zcmdRecordCRRemoveCallBack(void (*cbfunc)(const ACHAR*));

//ACHAR* zwGetMainFrameCaptionTitle();

//bool saveThumbnail(AcDbDatabase* pCurDocDwg, bool bCurView = true);

//int Zw_GetLicenseSerial(int* retType, ACHAR* Serial, int chkLock, int* retIsNet);

//HBITMAP GetViewImage(AcGsView* pView, int width, int height);

//AcString zwExportLayout(AcDbDatabase*& pDb, bool bUsedForDotNet, ACHAR* DeFaultPath);
