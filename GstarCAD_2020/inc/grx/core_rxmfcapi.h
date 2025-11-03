#ifndef GD_CORE_RXMFCAPI_H
#define GD_CORE_RXMFCAPI_H 1

#include "gcadstd.h"

#pragma pack (push, 8)

class GcCommandToolTipInfo;

struct GcColorSettings {

    /* Solid background color for various contexts */
    DWORD dwGfxModelBkColor;    
    DWORD dwGfxLayoutBkColor;
    DWORD dwPaperBkColor;
    DWORD dwParallelBkColor;
    DWORD dwBEditBkColor;
    DWORD dwCmdLineBkColor;
    DWORD dwPlotPrevBkColor;

    /* Background color for 3D perspective projection */
    DWORD dwSkyGradientZenithColor;
    DWORD dwSkyGradientHorizonColor;
    DWORD dwGroundGradientOriginColor;
    DWORD dwGroundGradientHorizonColor;
    DWORD dwEarthGradientAzimuthColor; 
    DWORD dwEarthGradientHorizonColor;

    /* Crosshair color for various contexts */
    DWORD dwModelCrossHairColor;
    DWORD dwLayoutCrossHairColor;
    DWORD dwParallelCrossHairColor;
    DWORD dwPerspectiveCrossHairColor;
    DWORD dwBEditCrossHairColor;

    /* Ground plane grid major lines for various contexts */
    DWORD dwParallelGridMajorLines;
    DWORD dwPerspectiveGridMajorLines;

    /* Ground plane grid minor lines for various contexts */
    DWORD dwParallelGridMinorLines;
    DWORD dwPerspectiveGridMinorLines;

    /* Ground plane grid axis lines for various contexts */
    DWORD dwParallelGridAxisLines;
    DWORD dwPerspectiveGridAxisLines;

    /* Text window color */
    DWORD dwTextForeColor, dwTextBkColor;

    /* Command line text color */
    DWORD dwCmdLineForeColor;

    /* AutoTrack vector color for various contexts */
    // Note: dwAutoTrackingVecColor indicates autotrack vector color in model space.
    // We didn't change its name to dwModelATrackVecColor because that might break
    // existing arx app.
    DWORD dwAutoTrackingVecColor;
    DWORD dwLayoutATrackVecColor;
    DWORD dwParallelATrackVecColor;
    DWORD dwPerspectiveATrackVecColor;
    DWORD dwBEditATrackVecColor;

    /* Autosnap Marker color for various contexts */
    DWORD dwModelASnapMarkerColor;
    DWORD dwLayoutASnapMarkerColor;
    DWORD dwParallelASnapMarkerColor;
    DWORD dwPerspectiveASnapMarkerColor;
    DWORD dwBEditASnapMarkerColor;
    
    /* Drafting Tool tip color for various contexts */
    DWORD dwModelDftingTooltipColor;
    DWORD dwLayoutDftingTooltipColor;
    DWORD dwParallelDftingTooltipColor;
    DWORD dwPerspectiveDftingTooltipColor;
    DWORD dwBEditDftingTooltipColor;
        
    /* Drafting Tool tip background color for various contexts */    
    DWORD dwModelDftingTooltipBkColor;
    DWORD dwLayoutDftingTooltipBkColor;
    DWORD dwParallelDftingTooltipBkColor;
    DWORD dwPerspectiveDftingTooltipBkColor;
    DWORD dwBEditDftingTooltipBkColor;

    /* Light glyphs color for various contexts */
    DWORD dwModelLightGlyphs;
    DWORD dwLayoutLightGlyphs;
    DWORD dwParallelLightGlyphs;
    DWORD dwPerspectiveLightGlyphs;
    DWORD dwBEditLightGlyphs;

    /* Light Hotspot color for various contexts */
    DWORD dwModelLightHotspot;
    DWORD dwLayoutLightHotspot;
    DWORD dwParallelLightHotspot;
    DWORD dwPerspectiveLightHotspot;
    DWORD dwBEditLightHotspot;

    /* Light Falloff color for various contexts */
    DWORD dwModelLightFalloff;
    DWORD dwLayoutLightFalloff;
    DWORD dwParallelLightFalloff;
    DWORD dwPerspectiveLightFalloff;
    DWORD dwBEditLightFalloff;

    /* Light start limit color for various contexts */
    DWORD dwModelLightStartLimit;
    DWORD dwLayoutLightStartLimit;
    DWORD dwParallelLightStartLimit;
    DWORD dwPerspectiveLightStartLimit;
    DWORD dwBEditLightStartLimit;

    /* Light end limit color for various contexts */
    DWORD dwModelLightEndLimit;
    DWORD dwLayoutLightEndLimit;
    DWORD dwParallelLightEndLimit;
    DWORD dwPerspectiveLightEndLimit;
    DWORD dwBEditLightEndLimit;

    /* Camera glyphs color for various contexts */
    DWORD dwModelCameraGlyphs;
    DWORD dwLayoutCameraGlyphs;
    DWORD dwParallelCameraGlyphs;
    DWORD dwPerspectiveCameraGlyphs;

    /* Camera frustrum plane color for various contexts */
    DWORD dwModelCameraFrustrum;
    DWORD dwLayoutCameraFrustrum;
    DWORD dwParallelCameraFrustrum;
    DWORD dwPerspectiveCameraFrustrum;

    /* Camera clipping plane color for various contexts */
    DWORD dwModelCameraClipping;
    DWORD dwLayoutCameraClipping;
    DWORD dwParallelCameraClipping;
    DWORD dwPerspectiveCameraClipping;

    /* Flags - set if true */

    /* Flags for use tint X, Y, Z for crosshair */
    int nModelCrosshairUseTintXYZ;
    int nLayoutCrosshairUseTintXYZ;
    int nParallelCrosshairUseTintXYZ;
    int nPerspectiveCrosshairUseTintXYZ;
    int nBEditCrossHairUseTintXYZ;

    /* Flags for use tint X, Y, Z for AutoTrack Vector */
    int nModelATrackVecUseTintXYZ;
    int nLayoutATrackVecUseTintXYZ;
    int nParallelATrackVecUseTintXYZ;
    int nPerspectiveATrackVecUseTintXYZ;
    int nBEditATrackVecUseTintXYZ;

    /* Flags for use tint X, Y, Z for Drafting Tooltip Bk tint */
    int nModelDftingTooltipBkUseTintXYZ;
    int nLayoutDftingTooltipBkUseTintXYZ;
    int nParallelDftingTooltipBkUseTintXYZ;
    int nPerspectiveDftingTooltipBkUseTintXYZ;
    int nBEditDftingTooltipBkUseTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid major lines */
    int nParallelGridMajorLineTintXYZ;
    int nPerspectiveGridMajorLineTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid minor lines */
    int nParallelGridMinorLineTintXYZ;
    int nPerspectiveGridMinorLineTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid axis lines */
    int nParallelGridAxisLineTintXYZ;
    int nPerspectiveGridAxisLineTintXYZ;

};

GCED_DLL_DECL BOOL gcedGetCurrentColors(GcColorSettings* pColorSettings);
GCED_DLL_DECL BOOL gcedSetCurrentColors(GcColorSettings* pColorSettings);
GCED_DLL_DECL BOOL gcedGetSystemColors(GcColorSettings* pColorSettings);

// More color settings.
struct GcColorSettingsEx
{
    // Light Web color for various contexts 
    DWORD dwModelLightWeb;
    DWORD dwLayoutLightWeb;
    DWORD dwParallelLightWeb;
    DWORD dwPerspectiveLightWeb;
    DWORD dwBEditLightWeb;

    // Light Web(missingfile) color for various contexts
    DWORD dwModelLightWebMissingFile;
    DWORD dwLayoutLightWebMissingFile;
    DWORD dwParallelLightWebMissingFile;
    DWORD dwPerspectiveLightWebMissingFile;
    DWORD dwBEditLightWebMissingFile;

    // Light Web shape(extend source) color for various contexts
    DWORD dwModelLightWebShape;
    DWORD dwLayoutLightWebShape;
    DWORD dwParallelLightWebShape;
    DWORD dwPerspectiveLightWebShape;
    DWORD dwBEditLightWebShape;

    // Light Web lux at distance color for various contexts
    DWORD dwModelLightWebLuxAtDist;
    DWORD dwLayoutLightWebLuxAtDist;
    DWORD dwParallelLightWebLuxAtDist;
    DWORD dwPerspectiveLightWebLuxAtDist;
    DWORD dwBEditLightWebLuxAtDist;

    /* Block editor constraints colors */
    DWORD dwBEditUnconstrainedColor;
    DWORD dwBEditPartiallyConstrainedColor;
    DWORD dwBEditFullyConstrainedColor;
    DWORD dwBEditOverConstrainedColor;
};

GCED_DLL_DECL BOOL gcedGetCurrentColorsEx(GcColorSettings* pColorSettings, 
  GcColorSettingsEx* pColorSettingsEx);

GCED_DLL_DECL BOOL gcedSetCurrentColorsEx(GcColorSettings* pColorSettings, 
  GcColorSettingsEx* pColorSettingsEx);

GCED_DLL_DECL BOOL gcedGetSystemColorsEx(GcColorSettings* pColorSettings, 
  GcColorSettingsEx* pColorSettingsEx);

// More and More color settings.
struct GcColorSettingsEx2
{
    /* Ground plane grid major lines for various contexts */
    DWORD dw2DModelGridMajorLines;
    DWORD dwLayoutGridMajorLines;
    DWORD dwBEditGridMajorLines;

    /* Ground plane grid minor lines for various contexts */
    DWORD dw2DModelGridMinorLines;
    DWORD dwLayoutGridMinorLines;
    DWORD dwBEditGridMinorLines;

    /* Ground plane grid axis lines for various contexts */
    DWORD dw2DModelGridAxisLines;
    DWORD dwLayoutGridAxisLines;
    DWORD dwBEditGridAxisLines;

    /* Dynamic Dimension Line color for various contexts */
    DWORD dwModelDynamicDimensionLineColor;
    DWORD dwLayoutDynamicDimensionLineColor;
    DWORD dwParallelDynamicDimensionLineColor;
    DWORD dwPerspectiveDynamicDimensionLineColor;
    DWORD dwBEditDynamicDimensionLineColor;

    /* Drafting Tool tip contour color for various contexts */
    DWORD dwModelDftingTooltipContourColor;
    DWORD dwLayoutDftingTooltipContourColor;
    DWORD dwParallelDftingTooltipContourColor;
    DWORD dwPerspectiveDftingTooltipContourColor;
    DWORD dwBEditDftingTooltipContourColor;

    /* Flags for use tint X, Y, Z for Ground plane grid major lines */
    int n2DModelGridMajorLineTintXYZ;
    int nLayoutGridMajorLineTintXYZ;
    int nBEditGridMajorLineTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid minor lines */
    int n2DModelGridMinorLineTintXYZ;
    int nLayoutGridMinorLineTintXYZ;
    int nBEditGridMinorLineTintXYZ;

    /* Flags for use tint X, Y, Z for Ground plane grid axis lines */
    int n2DModelGridAxisLineTintXYZ;
    int nLayoutGridAxisLineTintXYZ;
    int nBEditGridAxisLineTintXYZ;

    /* Control vertices hull color for various contexts */
    DWORD dwControlVerticesHullColor;

};

GCED_DLL_DECL BOOL gcedGetCurrentColorsEx2(GcColorSettings* pColorSettings, 
                             GcColorSettingsEx* pColorSettingsEx,
                             GcColorSettingsEx2* pColorSettingsEx2);

GCED_DLL_DECL BOOL gcedSetCurrentColorsEx2(GcColorSettings* pColorSettings, 
                             GcColorSettingsEx* pColorSettingsEx,
                             GcColorSettingsEx2* pColorSettingsEx2);

GCED_DLL_DECL BOOL gcedGetSystemColorsEx2(GcColorSettings* pColorSettings, 
                            GcColorSettingsEx* pColorSettingsEx,
                            GcColorSettingsEx2* pColorSettingsEx2);


struct GcColorSettingsEx3
{
    /* 3d autosnap Marker color for various contexts */
    DWORD dwModel3dASnapMarkerColor;
    DWORD dwLayout3dASnapMarkerColor;
    DWORD dwParallel3dASnapMarkerColor;
    DWORD dwPerspective3dASnapMarkerColor;
    DWORD dwBEdit3dASnapMarkerColor;

    /* Viewport control for various contexts */
    DWORD dw2DModelVportControl;
    DWORD dwParallelVportControl;
    DWORD dwPerspectiveVportControl;
};

GCED_DLL_DECL BOOL gcedGetCurrentColorsEx3(GcColorSettings* pColorSettings, 
                             GcColorSettingsEx* pColorSettingsEx,
                             GcColorSettingsEx2* pColorSettingsEx2,
                             GcColorSettingsEx3* pColorSettingsEx3);

GCED_DLL_DECL BOOL gcedSetCurrentColorsEx3(GcColorSettings* pColorSettings, 
                             GcColorSettingsEx* pColorSettingsEx,
                             GcColorSettingsEx2* pColorSettingsEx2,
                             GcColorSettingsEx3* pColorSettingsEx3);

GCED_DLL_DECL BOOL gcedGetSystemColorsEx3(GcColorSettings* pColorSettings, 
                            GcColorSettingsEx* pColorSettingsEx,
                            GcColorSettingsEx2* pColorSettingsEx2,
                            GcColorSettingsEx3* pColorSettingsEx3);

#ifdef _AFXDLL
typedef double gcedDwgPoint[3];

GCED_DLL_DECL void gcedCoordFromPixelToWorld(const CPoint &ptIn, gcedDwgPoint ptOut);

GCED_DLL_DECL BOOL gcedCoordFromPixelToWorld(int windnum, CPoint ptIn, gcedDwgPoint ptOut);

GCED_DLL_DECL BOOL gcedCoordFromWorldToPixel(int windnum, const gcedDwgPoint ptIn, CPoint& ptOut);

GCED_DLL_DECL int gcedGetWinNum(int ptx, int pty);

GCED_DLL_DECL int gcedSetStatusBarProgressMeter(const GCHAR* pszLabel, int nMinPos, int nMaxPos);

GCED_DLL_DECL int gcedSetStatusBarProgressMeterPos(int nPos);

GCED_DLL_DECL void gcedRestoreStatusBar();

typedef void (* GcedWatchWinMsgFn)(const MSG*);
typedef BOOL (* GcedFilterWinMsgFn)(MSG*);
typedef void (* GcedOnIdleMsgFn) ();
typedef void (* GcedOnModalFn) (bool bModal);

GCAD_DLL_DECL BOOL gcedRegisterFilterWinMsg(const GcedFilterWinMsgFn pfn);

GCAD_DLL_DECL BOOL gcedRemoveFilterWinMsg(const GcedFilterWinMsgFn pfn); 

GCAD_DLL_DECL BOOL gcedRegisterWatchWinMsg(const GcedWatchWinMsgFn pfn);

GCAD_DLL_DECL BOOL gcedRemoveWatchWinMsg(const GcedWatchWinMsgFn pfn); 

GCAD_DLL_DECL BOOL gcedRegisterOnIdleWinMsg(const GcedOnIdleMsgFn pfn);

GCAD_DLL_DECL BOOL gcedRemoveOnIdleWinMsg(const GcedOnIdleMsgFn pfn); 


// Define callback function for apps that want bitmap query.
typedef HBITMAP (* GcedCommandBitmapQueryFn)(const TCHAR* cmdName, 
                                             const COLORREF& backgroundColor);

//GCED_DLL_DECL BOOL      gcedRemoveCommandBitmapQuery   (const gcedCommandBitmapQueryFn pfn); 

//GCED_DLL_DECL BOOL      gcedRegisterCommandBitmapQuery (const GcedCommandBitmapQueryFn pfn);

GCED_DLL_DECL HBITMAP   gcedGetBitmapForCommand        (const TCHAR* cmdName, 
                                                      const COLORREF& backgroundColor);

GCED_DLL_DECL bool gcedGetToolTipInfoForCommand( const GCHAR* cmdName
                                             , GcCommandToolTipInfo* pInfo );
#endif

#pragma pack (pop)

#endif // GD_CORE_RXMFCAPI_H
