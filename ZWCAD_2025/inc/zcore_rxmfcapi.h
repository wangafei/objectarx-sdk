

#ifndef _ZCORE_RXMFCAPI_H_H
#define _ZCORE_RXMFCAPI_H_H	1

#pragma pack (push, 8)

#include "zaccoredefs.h"
#include "zacHeapOpers.h"

class ZcCommandToolTipInfo;

struct ZcColorSettings {
	DWORD dwGfxModelBkColor;
	DWORD dwGfxLayoutBkColor;
	DWORD dwPaperBkColor;
	DWORD dwParallelBkColor;
	DWORD dwBEditBkColor;
	DWORD dwCmdLineBkColor;
	DWORD dwPlotPrevBkColor;
	DWORD dwSkyGradientZenithColor;
	DWORD dwSkyGradientHorizonColor;
	DWORD dwGroundGradientOriginColor;
	DWORD dwGroundGradientHorizonColor;
	DWORD dwEarthGradientAzimuthColor;
	DWORD dwEarthGradientHorizonColor;
	DWORD dwModelCrossHairColor;
	DWORD dwLayoutCrossHairColor;
	DWORD dwParallelCrossHairColor;
	DWORD dwPerspectiveCrossHairColor;
	DWORD dwBEditCrossHairColor;
	DWORD dwParallelGridMajorLines;
	DWORD dwPerspectiveGridMajorLines;
	DWORD dwParallelGridMinorLines;
	DWORD dwPerspectiveGridMinorLines;
	DWORD dwParallelGridAxisLines;
	DWORD dwPerspectiveGridAxisLines;
	DWORD dwTextForeColor, dwTextBkColor;
	DWORD dwCmdLineForeColor;
    DWORD dwCmdLineTempPromptBkColor;
    DWORD dwCmdLineTempPromptTextColor;
    DWORD dwCmdLineCmdOptKeywordColor;
    DWORD dwCmdLineCmdOptBkColor;
    DWORD dwCmdLineCmdOptHighlightedColor;
	DWORD dwAutoTrackingVecColor;
	DWORD dwLayoutATrackVecColor;
	DWORD dwParallelATrackVecColor;
	DWORD dwPerspectiveATrackVecColor;
	DWORD dwBEditATrackVecColor;
	DWORD dwModelASnapMarkerColor;
	DWORD dwLayoutASnapMarkerColor;
	DWORD dwParallelASnapMarkerColor;
	DWORD dwPerspectiveASnapMarkerColor;
	DWORD dwBEditASnapMarkerColor;
	DWORD dwModelDftingTooltipColor;
	DWORD dwLayoutDftingTooltipColor;
	DWORD dwParallelDftingTooltipColor;
	DWORD dwPerspectiveDftingTooltipColor;
	DWORD dwBEditDftingTooltipColor;
	DWORD dwModelDftingTooltipBkColor;
	DWORD dwLayoutDftingTooltipBkColor;
	DWORD dwParallelDftingTooltipBkColor;
	DWORD dwPerspectiveDftingTooltipBkColor;
	DWORD dwBEditDftingTooltipBkColor;
	DWORD dwModelLightGlyphs;
	DWORD dwLayoutLightGlyphs;
	DWORD dwParallelLightGlyphs;
	DWORD dwPerspectiveLightGlyphs;
	DWORD dwBEditLightGlyphs;
	DWORD dwModelLightHotspot;
	DWORD dwLayoutLightHotspot;
	DWORD dwParallelLightHotspot;
	DWORD dwPerspectiveLightHotspot;
	DWORD dwBEditLightHotspot;
	DWORD dwModelLightFalloff;
	DWORD dwLayoutLightFalloff;
	DWORD dwParallelLightFalloff;
	DWORD dwPerspectiveLightFalloff;
	DWORD dwBEditLightFalloff;
	DWORD dwModelLightStartLimit;
	DWORD dwLayoutLightStartLimit;
	DWORD dwParallelLightStartLimit;
	DWORD dwPerspectiveLightStartLimit;
	DWORD dwBEditLightStartLimit;
	DWORD dwModelLightEndLimit;
	DWORD dwLayoutLightEndLimit;
	DWORD dwParallelLightEndLimit;
	DWORD dwPerspectiveLightEndLimit;
	DWORD dwBEditLightEndLimit;
	DWORD dwModelCameraGlyphs;
	DWORD dwLayoutCameraGlyphs;
	DWORD dwParallelCameraGlyphs;
	DWORD dwPerspectiveCameraGlyphs;
	DWORD dwModelCameraFrustrum;
	DWORD dwLayoutCameraFrustrum;
	DWORD dwParallelCameraFrustrum;
	DWORD dwPerspectiveCameraFrustrum;
	DWORD dwModelCameraClipping;
	DWORD dwLayoutCameraClipping;
	DWORD dwParallelCameraClipping;
	DWORD dwPerspectiveCameraClipping;
	int nModelCrosshairUseTintXYZ;
	int nLayoutCrosshairUseTintXYZ;
	int nParallelCrosshairUseTintXYZ;
	int nPerspectiveCrosshairUseTintXYZ;
	int nBEditCrossHairUseTintXYZ;
	int nModelATrackVecUseTintXYZ;
	int nLayoutATrackVecUseTintXYZ;
	int nParallelATrackVecUseTintXYZ;
	int nPerspectiveATrackVecUseTintXYZ;
	int nBEditATrackVecUseTintXYZ;
	int nModelDftingTooltipBkUseTintXYZ;
	int nLayoutDftingTooltipBkUseTintXYZ;
	int nParallelDftingTooltipBkUseTintXYZ;
	int nPerspectiveDftingTooltipBkUseTintXYZ;
	int nBEditDftingTooltipBkUseTintXYZ;
	int nParallelGridMajorLineTintXYZ;
	int nPerspectiveGridMajorLineTintXYZ;
	int nParallelGridMinorLineTintXYZ;
	int nPerspectiveGridMinorLineTintXYZ;
	int nParallelGridAxisLineTintXYZ;
	int nPerspectiveGridAxisLineTintXYZ;
};

ZCCORE_PORT bool zcedGetCurrentColors(ZcColorSettings* pColorSettings);
ZCCORE_PORT bool zcedSetCurrentColors(ZcColorSettings* pColorSettings);
ZCCORE_PORT bool zcedGetSystemColors(ZcColorSettings* pColorSettings);

struct ZcColorSettingsEx
{

	DWORD dwModelLightWeb;
	DWORD dwLayoutLightWeb;
	DWORD dwParallelLightWeb;
	DWORD dwPerspectiveLightWeb;
	DWORD dwBEditLightWeb;
	DWORD dwModelLightWebMissingFile;
	DWORD dwLayoutLightWebMissingFile;
	DWORD dwParallelLightWebMissingFile;
	DWORD dwPerspectiveLightWebMissingFile;
	DWORD dwBEditLightWebMissingFile;
	DWORD dwModelLightWebShape;
	DWORD dwLayoutLightWebShape;
	DWORD dwParallelLightWebShape;
	DWORD dwPerspectiveLightWebShape;
	DWORD dwBEditLightWebShape;
	DWORD dwModelLightWebLuxAtDist;
	DWORD dwLayoutLightWebLuxAtDist;
	DWORD dwParallelLightWebLuxAtDist;
	DWORD dwPerspectiveLightWebLuxAtDist;
	DWORD dwBEditLightWebLuxAtDist;
    DWORD dwBEditUnconstrainedColor;
    DWORD dwBEditPartiallyConstrainedColor;
    DWORD dwBEditFullyConstrainedColor;
    DWORD dwBEditOverConstrainedColor;
};


ZCCORE_PORT bool zcedGetCurrentColorsEx(ZcColorSettings* pColorSettings, 
	ZcColorSettingsEx* pColorSettingsEx);

ZCCORE_PORT bool zcedSetCurrentColorsEx(ZcColorSettings* pColorSettings, 
	ZcColorSettingsEx* pColorSettingsEx);

ZCCORE_PORT bool zcedGetSystemColorsEx(ZcColorSettings* pColorSettings, 
	ZcColorSettingsEx* pColorSettingsEx);

struct ZcColorSettingsEx2
{
	DWORD dw2DModelGridMajorLines;
	DWORD dwLayoutGridMajorLines;
	DWORD dwBEditGridMajorLines;

	DWORD dw2DModelGridMinorLines;
	DWORD dwLayoutGridMinorLines;
	DWORD dwBEditGridMinorLines;

	DWORD dw2DModelGridAxisLines;
	DWORD dwLayoutGridAxisLines;
	DWORD dwBEditGridAxisLines;

	DWORD dwModelDynamicDimensionLineColor;
	DWORD dwLayoutDynamicDimensionLineColor;
	DWORD dwParallelDynamicDimensionLineColor;
	DWORD dwPerspectiveDynamicDimensionLineColor;
	DWORD dwBEditDynamicDimensionLineColor;

	DWORD dwModelRubberBandLineColor;
	DWORD dwLayoutRubberBandLineColor;
	DWORD dwParallelRubberBandLineColor;
	DWORD dwPerspectiveRubberBandLineColor;
	DWORD dwBEditRubberBandLineColor;

	DWORD dwModelDftingTooltipContourColor;
	DWORD dwLayoutDftingTooltipContourColor;
	DWORD dwParallelDftingTooltipContourColor;
	DWORD dwPerspectiveDftingTooltipContourColor;
	DWORD dwBEditDftingTooltipContourColor;

	int n2DModelGridMajorLineTintXYZ;
	int nLayoutGridMajorLineTintXYZ;
	int nBEditGridMajorLineTintXYZ;

	int n2DModelGridMinorLineTintXYZ;
	int nLayoutGridMinorLineTintXYZ;
	int nBEditGridMinorLineTintXYZ;

	int n2DModelGridAxisLineTintXYZ;
	int nLayoutGridAxisLineTintXYZ;
	int nBEditGridAxisLineTintXYZ;

	DWORD dwControlVerticesHullColor;

};


ZCCORE_PORT bool zcedGetCurrentColorsEx2(ZcColorSettings* pColorSettings, 
	ZcColorSettingsEx* pColorSettingsEx,
	ZcColorSettingsEx2* pColorSettingsEx2);

ZCCORE_PORT bool zcedSetCurrentColorsEx2(ZcColorSettings* pColorSettings, 
	ZcColorSettingsEx* pColorSettingsEx,
	ZcColorSettingsEx2* pColorSettingsEx2);

ZCCORE_PORT bool zcedGetSystemColorsEx2(ZcColorSettings* pColorSettings, 
	ZcColorSettingsEx* pColorSettingsEx,
	ZcColorSettingsEx2* pColorSettingsEx2);

struct ZcColorSettingsEx3
{
	DWORD dwModel3dASnapMarkerColor;
	DWORD dwLayout3dASnapMarkerColor;
	DWORD dwParallel3dASnapMarkerColor;
	DWORD dwPerspective3dASnapMarkerColor;
	DWORD dwBEdit3dASnapMarkerColor;

	DWORD dw2DModelVportControl;
	DWORD dwParallelVportControl;
	DWORD dwPerspectiveVportControl;
};


ZCCORE_PORT
bool zcedGetCurrentColorsEx3(ZcColorSettings* pColorSettings,
                            ZcColorSettingsEx* pColorSettingsEx,
                            ZcColorSettingsEx2* pColorSettingsEx2,
                            ZcColorSettingsEx3* pColorSettingsEx3);

ZCCORE_PORT
bool zcedSetCurrentColorsEx3(ZcColorSettings* pColorSettings,
                            ZcColorSettingsEx* pColorSettingsEx,
                            ZcColorSettingsEx2* pColorSettingsEx2,
                            ZcColorSettingsEx3* pColorSettingsEx3);

ZCCORE_PORT
bool zcedGetSystemColorsEx3(ZcColorSettings* pColorSettings,
                            ZcColorSettingsEx* pColorSettingsEx,
                            ZcColorSettingsEx2* pColorSettingsEx2,
                            ZcColorSettingsEx3* pColorSettingsEx3);


typedef double zcedDwgPoint[3];

#ifndef	_ZSOFT_CROSS_PLATFORM_		

ZCCORE_PORT void zcedCoordFromPixelToWorld(const CPoint &ptIn, zcedDwgPoint ptOut);

ZCCORE_PORT bool zcedCoordFromPixelToWorld(int windnum, CPoint ptIn, zcedDwgPoint ptOut);

ZCCORE_PORT bool zcedCoordFromWorldToPixel(int windnum, const zcedDwgPoint ptIn, CPoint& ptOut);
#endif


int zcedSetStatusBarProgressMeter(const ZTCHAR* pszLabel, int nMinPos,
	int nMaxPos);

int zcedSetStatusBarProgressMeterPos(int nPos);

void zcedRestoreStatusBar();

int zcedGetWinNum(int ptx, int pty);
typedef void (* ZcedWatchWinMsgFn)(const MSG*);
typedef bool (* ZcedFilterWinMsgFn)(MSG*);
typedef void (* ZcedOnIdleMsgFn) ();
typedef void (* ZcedOnModalFn) (bool bModal);


ZCCORE_PORT bool zcedRegisterFilterWinMsg(const ZcedFilterWinMsgFn pfn);

ZCCORE_PORT bool zcedRemoveFilterWinMsg(const ZcedFilterWinMsgFn pfn); 

ZCCORE_PORT bool zcedRegisterWatchWinMsg(const ZcedWatchWinMsgFn pfn);

ZCCORE_PORT bool zcedRemoveWatchWinMsg(const ZcedWatchWinMsgFn pfn); 
ZCCORE_PORT bool zcedRegisterOnIdleWinMsg(const ZcedOnIdleMsgFn pfn);
ZCCORE_PORT bool zcedRemoveOnIdleWinMsg(const ZcedOnIdleMsgFn pfn);
ZCCORE_PORT bool zcedRegisterOnModal(const ZcedOnModalFn pfn);
ZCCORE_PORT bool zcedRemoveOnModal(const ZcedOnModalFn pfn); 



typedef void (*ZcedRunLoopFn)(void* pContext);

typedef long long TaskId;

ZCCORE_PORT TaskId zcedExecuteOnMainThread(const ZcedRunLoopFn pfn, void* pContext, bool bWaitUntilDone = false);

class IZcEdRunLoopTask : public ZcHeapOperators
{
public:
	virtual ~IZcEdRunLoopTask() {}

	virtual void execute() = 0;
};

ZCCORE_PORT TaskId zcedExecuteOnMainThread(IZcEdRunLoopTask* pTask, bool bWaitUntilDone = false);

ZCCORE_PORT void zcedRemoveRunLoopTask(TaskId taskId);

HINSTANCE zcedGetZcadResourceInstance();


typedef HBITMAP (* ZcedCommandBitmapQueryFn)(const wchar_t* cmdName, 
	const COLORREF& backgroundColor);

ZCCORE_PORT bool      zcedRemoveCommandBitmapQuery   (const ZcedCommandBitmapQueryFn pfn); 

ZCCORE_PORT bool      zcedRegisterCommandBitmapQuery (const ZcedCommandBitmapQueryFn pfn);

ZCCORE_PORT HBITMAP   zcedGetBitmapForCommand        (const wchar_t* cmdName, 
	const COLORREF& backgroundColor);

ZCCORE_PORT HBITMAP   zcedGetCachedBitmapForCommand  (const wchar_t* cmdName, 
	const COLORREF& backgroundColor);

ZCCORE_PORT bool zcedGetToolTipInfoForCommand( const ZTCHAR* cmdName
	, ZcCommandToolTipInfo* pInfo );

class ZcApStatusBar;

ZCCORE_PORT
	ZcApStatusBar* zcedGetApplicationStatusBar();

ZCCORE_PORT bool zcedDrawingStatusBarsVisible();


ZCCORE_PORT bool zcedIsInputPending();


#pragma pack (pop)
#endif 

