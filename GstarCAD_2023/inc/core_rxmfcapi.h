/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_CORE_RXMFCAPI_H
#define GD_CORE_RXMFCAPI_H 1

#pragma pack (push, 8)

#include "gccoredefs.h"
#include "GcHeapOpers.h"

class GcCommandToolTipInfo;

struct GcColorSettings {
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

GCCORE_PORT bool gcedGetCurrentColors(GcColorSettings* pColorSettings);
GCCORE_PORT bool gcedSetCurrentColors(GcColorSettings* pColorSettings);
GCCORE_PORT bool gcedGetSystemColors(GcColorSettings* pColorSettings);

struct GcColorSettingsEx
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

GCCORE_PORT bool gcedGetCurrentColorsEx(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx);
GCCORE_PORT bool gcedSetCurrentColorsEx(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx);
GCCORE_PORT bool gcedGetSystemColorsEx(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx);

struct GcColorSettingsEx2
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

GCCORE_PORT bool gcedGetCurrentColorsEx2(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx,
  GcColorSettingsEx2* pColorSettingsEx2);
GCCORE_PORT bool gcedSetCurrentColorsEx2(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx,
  GcColorSettingsEx2* pColorSettingsEx2);
GCCORE_PORT bool gcedGetSystemColorsEx2(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx,
  GcColorSettingsEx2* pColorSettingsEx2);

struct GcColorSettingsEx3
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

GCCORE_PORT
bool gcedGetCurrentColorsEx3(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx,
  GcColorSettingsEx2* pColorSettingsEx2,
  GcColorSettingsEx3* pColorSettingsEx3);
GCCORE_PORT
bool gcedSetCurrentColorsEx3(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx,
  GcColorSettingsEx2* pColorSettingsEx2,
  GcColorSettingsEx3* pColorSettingsEx3);
GCCORE_PORT
bool gcedGetSystemColorsEx3(GcColorSettings* pColorSettings,
  GcColorSettingsEx* pColorSettingsEx,
  GcColorSettingsEx2* pColorSettingsEx2,
  GcColorSettingsEx3* pColorSettingsEx3);

typedef double gcedDwgPoint[3];

#ifndef _GSOFT_CROSS_PLATFORM_

GCCORE_PORT void gcedCoordFromPixelToWorld(const CPoint &ptIn, gcedDwgPoint ptOut);
GCCORE_PORT bool gcedCoordFromPixelToWorld(int windnum, CPoint ptIn, gcedDwgPoint ptOut);
GCCORE_PORT bool gcedCoordFromWorldToPixel(int windnum, const gcedDwgPoint ptIn, CPoint& ptOut);

#endif

GCAD_PORT int gcedSetStatusBarProgressMeter(const GCHAR* pszLabel, int nMinPos, int nMaxPos);
GCAD_PORT int gcedSetStatusBarProgressMeterPos(int nPos);
GCAD_PORT void gcedRestoreStatusBar();
GCCORE_PORT int gcedGetWinNum(int ptx, int pty);

typedef void(*GcedWatchWinMsgFn)(const MSG*);
typedef bool(*GcedFilterWinMsgFn)(MSG*);
typedef void(*GcedOnIdleMsgFn) ();
typedef void(*GcedOnModalFn) (bool bModal);

GCAD_PORT bool gcedRegisterFilterWinMsg(const GcedFilterWinMsgFn pfn);
GCAD_PORT bool gcedRemoveFilterWinMsg(const GcedFilterWinMsgFn pfn);
GCAD_PORT bool gcedRegisterWatchWinMsg(const GcedWatchWinMsgFn pfn);
GCAD_PORT bool gcedRemoveWatchWinMsg(const GcedWatchWinMsgFn pfn);
GCAD_PORT bool gcedRegisterOnIdleWinMsg(const GcedOnIdleMsgFn pfn);
GCAD_PORT bool gcedRemoveOnIdleWinMsg(const GcedOnIdleMsgFn pfn);
GCAD_PORT bool gcedRegisterOnModal(const GcedOnModalFn pfn);
GCAD_PORT bool gcedRemoveOnModal(const GcedOnModalFn pfn);

typedef void(*GcedRunLoopFn)(void* pContext);

typedef long long TaskId;

GCAD_PORT TaskId gcedExecuteOnMainThread(const GcedRunLoopFn pfn, void* pContext, bool bWaitUntilDone = false);

class IGcEdRunLoopTask : public GcHeapOperators
{
public:
  virtual ~IGcEdRunLoopTask() {}

  virtual void execute() = 0;
};

GCAD_PORT TaskId gcedExecuteOnMainThread(IGcEdRunLoopTask* pTask, bool bWaitUntilDone = false);

GCAD_PORT void gcedRemoveRunLoopTask(TaskId taskId);

GCAD_PORT HINSTANCE gcedGetGcadResourceInstance();

typedef HBITMAP(*GcedCommandBitmapQueryFn)(const wchar_t* cmdName,
  const COLORREF& backgroundColor);

GCAD_PORT bool      gcedRemoveCommandBitmapQuery(const GcedCommandBitmapQueryFn pfn);
GCAD_PORT bool      gcedRegisterCommandBitmapQuery(const GcedCommandBitmapQueryFn pfn);
GCAD_PORT HBITMAP   gcedGetBitmapForCommand(const wchar_t* cmdName,
  const COLORREF& backgroundColor);
GCAD_PORT HBITMAP   gcedGetCachedBitmapForCommand(const wchar_t* cmdName,
  const COLORREF& backgroundColor);
GCAD_PORT bool gcedGetToolTipInfoForCommand(const GCHAR* cmdName
  , GcCommandToolTipInfo* pInfo);

class GcApStatusBar;

GCAD_PORT
GcApStatusBar* gcedGetApplicationStatusBar();

GCAD_PORT bool gcedDrawingStatusBarsVisible();

GCAD_PORT bool gcedIsInputPending();

#pragma pack (pop)

#endif 