

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for ..\..\..\..\..\Extensions\win\gcax\GcadVbaDefs.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __GcadVbaDefs_h__
#define __GcadVbaDefs_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_GcadVbaDefs_0000_0000 */
/* [local] */ 

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E58E14BD-9B8C-4956-957B-C58CC9F26F5B") 
enum GcWindowState
    {
        gcNorm	= 1,
        gcMin	= 2,
        gcMax	= 3,
        acNorm	= 1,
        acMin	= 2,
        acMax	= 3
    } 	GcWindowState;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("10C06A62-09AC-41B7-B5FA-ADEE6F45DFF7") 
enum GcZoomScaleType
    {
        gcZoomScaledAbsolute	= 0,
        acZoomScaledAbsolute	= 0,
        gcZoomScaledRelative	= 1,
        acZoomScaledRelative	= 1,
        gcZoomScaledRelativePSpace	= 2,
        acZoomScaledRelativePSpace	= 2
    } 	GcZoomScaleType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("18C2A01F-C58C-4A61-953D-BC4DC78FA1E9") 
enum GcActiveSpace
    {
        gcPaperSpace	= 0,
        acPaperSpace	= 0,
        gcModelSpace	= 1,
        acModelSpace	= 1
    } 	GcActiveSpace;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("2A6D4C96-A005-4D60-80B4-D27072B2B1EF") 
enum GcRegenType
    {
        gcActiveViewport	= 0,
        acActiveViewport	= 0,
        gcAllViewports	= 1,
        acAllViewports	= 1
    } 	GcRegenType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("071D7B07-B29D-4296-B2B0-4882C54A03AA") 
enum GcColor
    {
        gcByBlock	= 0,
        acByBlock	= 0,
        gcRed	= 1,
        acRed	= 1,
        gcYellow	= 2,
        acYellow	= 2,
        gcGreen	= 3,
        acGreen	= 3,
        gcCyan	= 4,
        acCyan	= 4,
        gcBlue	= 5,
        acBlue	= 5,
        gcMagenta	= 6,
        acMagenta	= 6,
        gcWhite	= 7,
        acWhite	= 7,
        gcByLayer	= 256,
        acByLayer	= 256
    } 	GcColor;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("BCAD5B78-893D-4369-8674-435A60CAEADA") 
enum GcExtendOption
    {
        gcExtendNone	= 0,
        acExtendNone	= 0,
        gcExtendThisEntity	= 1,
        acExtendThisEntity	= 1,
        gcExtendOtherEntity	= 2,
        acExtendOtherEntity	= 2,
        gcExtendBoth	= 3,
        acExtendBoth	= 3
    } 	GcExtendOption;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("0DEC8F4B-E5F9-4D61-9AED-981A677D74B2") 
enum GcLineWeight
    {
        gcLnWt000	= 0,
        acLnWt000	= 0,
        gcLnWt005	= 5,
        acLnWt005	= 5,
        gcLnWt009	= 9,
        acLnWt009	= 9,
        gcLnWt013	= 13,
        acLnWt013	= 13,
        gcLnWt015	= 15,
        acLnWt015	= 15,
        gcLnWt018	= 18,
        acLnWt018	= 18,
        gcLnWt020	= 20,
        acLnWt020	= 20,
        gcLnWt025	= 25,
        acLnWt025	= 25,
        gcLnWt030	= 30,
        acLnWt030	= 30,
        gcLnWt035	= 35,
        acLnWt035	= 35,
        gcLnWt040	= 40,
        acLnWt040	= 40,
        gcLnWt050	= 50,
        acLnWt050	= 50,
        gcLnWt053	= 53,
        acLnWt053	= 53,
        gcLnWt060	= 60,
        acLnWt060	= 60,
        gcLnWt070	= 70,
        acLnWt070	= 70,
        gcLnWt080	= 80,
        acLnWt080	= 80,
        gcLnWt090	= 90,
        acLnWt090	= 90,
        gcLnWt100	= 100,
        acLnWt100	= 100,
        gcLnWt106	= 106,
        acLnWt106	= 106,
        gcLnWt120	= 120,
        acLnWt120	= 120,
        gcLnWt140	= 140,
        acLnWt140	= 140,
        gcLnWt158	= 158,
        acLnWt158	= 158,
        gcLnWt200	= 200,
        acLnWt200	= 200,
        gcLnWt211	= 211,
        acLnWt211	= 211,
        gcLnWtByLayer	= -1,
        acLnWtByLayer	= -1,
        gcLnWtByBlock	= -2,
        acLnWtByBlock	= -2,
        gcLnWtByLwDefault	= -3,
        acLnWtByLwDefault	= -3
    } 	GcLineWeight;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("0AF01CAA-3BF8-4C3F-BB2C-7B4A0A2E9E58") 
enum GcBoolean
    {
        gcFalse	= 0,
        acFalse	= 0,
        gcTrue	= 1,
        acTrue	= 1
    } 	GcBoolean;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("DB376413-1337-4B51-83A8-6BC5A183E613") 
enum GcOnOff
    {
        gcOff	= 0,
        acOff	= 0,
        gcOn	= 1,
        acOn	= 1
    } 	GcOnOff;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("07766B20-4833-4DD3-BC11-3C9E2371499C") 
enum GcEntityName
    {
        gc3dFace	= 1,
        ac3dFace	= 1,
        gc3dPolyline	= 2,
        ac3dPolyline	= 2,
        gc3dSolid	= 3,
        ac3dSolid	= 3,
        gcArc	= 4,
        acArc	= 4,
        gcAttribute	= 5,
        acAttribute	= 5,
        gcAttributeReference	= 6,
        acAttributeReference	= 6,
        gcBlockReference	= 7,
        acBlockReference	= 7,
        gcCircle	= 8,
        acCircle	= 8,
        gcDimAligned	= 9,
        acDimAligned	= 9,
        gcDimAngular	= 10,
        acDimAngular	= 10,
        gcDimDiametric	= 12,
        acDimDiametric	= 12,
        gcDimOrdinate	= 13,
        acDimOrdinate	= 13,
        gcDimRadial	= 14,
        acDimRadial	= 14,
        gcDimRotated	= 15,
        acDimRotated	= 15,
        gcEllipse	= 16,
        acEllipse	= 16,
        gcHatch	= 17,
        acHatch	= 17,
        gcLeader	= 18,
        acLeader	= 18,
        gcLine	= 19,
        acLine	= 19,
        gcMtext	= 21,
        acMtext	= 21,
        gcPoint	= 22,
        acPoint	= 22,
        gcPolyline	= 23,
        acPolyline	= 23,
        gcPolylineLight	= 24,
        acPolylineLight	= 24,
        gcPolymesh	= 25,
        acPolymesh	= 25,
        gcRaster	= 26,
        acRaster	= 26,
        gcRay	= 27,
        acRay	= 27,
        gcRegion	= 28,
        acRegion	= 28,
        gcShape	= 29,
        acShape	= 29,
        gcSolid	= 30,
        acSolid	= 30,
        gcSpline	= 31,
        acSpline	= 31,
        gcText	= 32,
        acText	= 32,
        gcTolerance	= 33,
        acTolerance	= 33,
        gcTrace	= 34,
        acTrace	= 34,
        gcPViewport	= 35,
        acPViewport	= 35,
        gcXline	= 36,
        acXline	= 36,
        gcGroup	= 37,
        acGroup	= 37,
        gcMInsertBlock	= 38,
        acMInsertBlock	= 38,
        gcPolyfaceMesh	= 39,
        acPolyfaceMesh	= 39,
        gcMLine	= 40,
        acMLine	= 40,
        gcDim3PointAngular	= 41,
        acDim3PointAngular	= 41,
        gcExternalReference	= 42,
        acExternalReference	= 42,
        gcTable	= 43,
        acTable	= 43,
        gcDimArcLength	= 44,
        acDimArcLength	= 44,
        gcDimRadialLarge	= 45,
        acDimRadialLarge	= 45,
        gcDwfUnderlay	= 46,
        acDwfUnderlay	= 46,
        gcDgnUnderlay	= 47,
        acDgnUnderlay	= 47,
        gcMLeader	= 48,
        acMLeader	= 48,
        gcSubDMesh	= 49,
        acSubDMesh	= 49,
        gcPdfUnderlay	= 50,
        acPdfUnderlay	= 50,
        gcNurbSurface	= 51,
        acNurbSurface	= 51
    } 	GcEntityName;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("FE53D116-FCDE-41F5-B10F-2F4733FB26ED") 
enum GcKeyboardAccelerator
    {
        gcPreferenceClassic	= 0,
        acPreferenceClassic	= 0,
        gcPreferenceCustom	= 1,
        acPreferenceCustom	= 1
    } 	GcKeyboardAccelerator;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("4D5378F6-C5F6-4464-B1EA-E8A414261DF8") 
enum GcPlotOrientation
    {
        gcPlotOrientationPortrait	= 0,
        acPlotOrientationPortrait	= 0,
        gcPlotOrientationLandscape	= 1,
        acPlotOrientationLandscape	= 1
    } 	GcPlotOrientation;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("FF933394-C9D5-4B83-B870-A865C199413E") 
enum GcAttachmentPoint
    {
        gcAttachmentPointTopLeft	= 1,
        acAttachmentPointTopLeft	= 1,
        gcAttachmentPointTopCenter	= 2,
        acAttachmentPointTopCenter	= 2,
        gcAttachmentPointTopRight	= 3,
        acAttachmentPointTopRight	= 3,
        gcAttachmentPointMiddleLeft	= 4,
        acAttachmentPointMiddleLeft	= 4,
        gcAttachmentPointMiddleCenter	= 5,
        acAttachmentPointMiddleCenter	= 5,
        gcAttachmentPointMiddleRight	= 6,
        acAttachmentPointMiddleRight	= 6,
        gcAttachmentPointBottomLeft	= 7,
        acAttachmentPointBottomLeft	= 7,
        gcAttachmentPointBottomCenter	= 8,
        acAttachmentPointBottomCenter	= 8,
        gcAttachmentPointBottomRight	= 9,
        acAttachmentPointBottomRight	= 9
    } 	GcAttachmentPoint;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5AA48FF1-756A-4486-8648-AE22ED440C9E") 
enum GcDrawingDirection
    {
        gcLeftToRight	= 1,
        acLeftToRight	= 1,
        gcRightToLeft	= 2,
        acRightToLeft	= 2,
        gcTopToBottom	= 3,
        acTopToBottom	= 3,
        gcBottomToTop	= 4,
        acBottomToTop	= 4,
        gcByStyle	= 5,
        acByStyle	= 5
    } 	GcDrawingDirection;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E2F61504-62D6-4989-9C43-4EAEB85E364F") 
enum GcLeaderType
    {
        gcLineNoArrow	= 0,
        acLineNoArrow	= 0,
        gcSplineNoArrow	= 1,
        acSplineNoArrow	= 1,
        gcLineWithArrow	= 2,
        acLineWithArrow	= 2,
        gcSplineWithArrow	= 3,
        acSplineWithArrow	= 3
    } 	GcLeaderType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("8C92E50B-3391-4EA4-8D70-740490E5C2F5") 
enum GcAttributeMode
    {
        gcAttributeModeNormal	= 0,
        acAttributeModeNormal	= 0,
        gcAttributeModeInvisible	= 1,
        acAttributeModeInvisible	= 1,
        gcAttributeModeConstant	= 2,
        acAttributeModeConstant	= 2,
        gcAttributeModeVerify	= 4,
        acAttributeModeVerify	= 4,
        gcAttributeModePreset	= 8,
        acAttributeModePreset	= 8,
        gcAttributeModeLockPosition	= 16,
        acAttributeModeLockPosition	= 16,
        gcAttributeModeMultipleLine	= 32,
        acAttributeModeMultipleLine	= 32
    } 	GcAttributeMode;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("54F94B66-BF9D-405D-960A-FACE622C3D51") 
enum GcHorizontalAlignment
    {
        gcHorizontalAlignmentLeft	= 0,
        acHorizontalAlignmentLeft	= 0,
        gcHorizontalAlignmentCenter	= 1,
        acHorizontalAlignmentCenter	= 1,
        gcHorizontalAlignmentRight	= 2,
        acHorizontalAlignmentRight	= 2,
        gcHorizontalAlignmentAligned	= 3,
        acHorizontalAlignmentAligned	= 3,
        gcHorizontalAlignmentMiddle	= 4,
        acHorizontalAlignmentMiddle	= 4,
        gcHorizontalAlignmentFit	= 5,
        acHorizontalAlignmentFit	= 5
    } 	GcHorizontalAlignment;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("02864038-861D-4FE6-82E1-082EB75F4AAF") 
enum GcVerticalAlignment
    {
        gcVerticalAlignmentBaseline	= 0,
        acVerticalAlignmentBaseline	= 0,
        gcVerticalAlignmentBottom	= 1,
        acVerticalAlignmentBottom	= 1,
        gcVerticalAlignmentMiddle	= 2,
        acVerticalAlignmentMiddle	= 2,
        gcVerticalAlignmentTop	= 3,
        acVerticalAlignmentTop	= 3
    } 	GcVerticalAlignment;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F13BF626-C1D3-4493-983B-D33E43D3E659") 
enum GcTextGenerationFlag
    {
        gcTextFlagBackward	= 2,
        acTextFlagBackward	= 2,
        gcTextFlagUpsideDown	= 4,
        acTextFlagUpsideDown	= 4
    } 	GcTextGenerationFlag;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C04F177C-EFEB-4F3B-8212-66DF6507D83C") 
enum GcSelect
    {
        gcSelectionSetWindow	= 0,
        acSelectionSetWindow	= 0,
        gcSelectionSetCrossing	= 1,
        acSelectionSetCrossing	= 1,
        gcSelectionSetFence	= 2,
        acSelectionSetFence	= 2,
        gcSelectionSetPrevious	= 3,
        acSelectionSetPrevious	= 3,
        gcSelectionSetLast	= 4,
        acSelectionSetLast	= 4,
        gcSelectionSetAll	= 5,
        acSelectionSetAll	= 5,
        gcSelectionSetWindowPolygon	= 6,
        acSelectionSetWindowPolygon	= 6,
        gcSelectionSetCrossingPolygon	= 7,
        acSelectionSetCrossingPolygon	= 7
    } 	GcSelect;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("82E29BCE-69C2-4F7A-A205-D18C64A4D9B5") 
enum GcPatternType
    {
        gcHatchPatternTypeUserDefined	= 0,
        acHatchPatternTypeUserDefined	= 0,
        gcHatchPatternTypePreDefined	= 1,
        acHatchPatternTypePreDefined	= 1,
        gcHatchPatternTypeCustomDefined	= 2,
        acHatchPatternTypeCustomDefined	= 2
    } 	GcPatternType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E8B82DF9-3F05-4726-9C67-E534C531E891") 
enum GcLoopType
    {
        gcHatchLoopTypeDefault	= 0,
        acHatchLoopTypeDefault	= 0,
        gcHatchLoopTypeExternal	= 1,
        acHatchLoopTypeExternal	= 1,
        gcHatchLoopTypePolyline	= 2,
        acHatchLoopTypePolyline	= 2,
        gcHatchLoopTypeDerived	= 4,
        acHatchLoopTypeDerived	= 4,
        gcHatchLoopTypeTextbox	= 8,
        acHatchLoopTypeTextbox	= 8
    } 	GcLoopType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("4F0EC160-89D8-417C-B92B-CC28C15EBEF9") 
enum GcHatchStyle
    {
        gcHatchStyleNormal	= 0,
        acHatchStyleNormal	= 0,
        gcHatchStyleOuter	= 1,
        acHatchStyleOuter	= 1,
        gcHatchStyleIgnore	= 2,
        acHatchStyleIgnore	= 2
    } 	GcHatchStyle;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("89ED668B-8A29-4B96-B537-7E19CC07744A") 
enum GcPolylineType
    {
        gcSimplePoly	= 0,
        acSimplePoly	= 0,
        gcFitCurvePoly	= 1,
        acFitCurvePoly	= 1,
        gcQuadSplinePoly	= 2,
        acQuadSplinePoly	= 2,
        gcCubicSplinePoly	= 3,
        acCubicSplinePoly	= 3
    } 	GcPolylineType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("86482173-7EE1-4C06-B005-B91D6B00290B") 
enum Gc3DPolylineType
    {
        gcSimple3DPoly	= 0,
        acSimple3DPoly	= 0,
        gcQuadSpline3DPoly	= 1,
        acQuadSpline3DPoly	= 1,
        gcCubicSpline3DPoly	= 2,
        acCubicSpline3DPoly	= 2
    } 	Gc3DPolylineType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("44881ED7-B66F-45CA-A7F7-DB737AA53578") 
enum GcViewportSplitType
    {
        gcViewport2Horizontal	= 0,
        acViewport2Horizontal	= 0,
        gcViewport2Vertical	= 1,
        acViewport2Vertical	= 1,
        gcViewport3Left	= 2,
        acViewport3Left	= 2,
        gcViewport3Right	= 3,
        acViewport3Right	= 3,
        gcViewport3Horizontal	= 4,
        acViewport3Horizontal	= 4,
        gcViewport3Vertical	= 5,
        acViewport3Vertical	= 5,
        gcViewport3Above	= 6,
        acViewport3Above	= 6,
        gcViewport3Below	= 7,
        acViewport3Below	= 7,
        gcViewport4	= 8,
        acViewport4	= 8
    } 	GcViewportSplitType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("917F4E52-B6E2-45E8-ADB1-3F9EC7FFDCCE") 
enum GcBooleanType
    {
        gcUnion	= 0,
        acUnion	= 0,
        gcIntersection	= 1,
        acIntersection	= 1,
        gcSubtraction	= 2,
        acSubtraction	= 2
    } 	GcBooleanType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("75BC7087-4647-4B18-AC96-431F60313875") 
enum GcAngleUnits
    {
        gcDegrees	= 0,
        acDegrees	= 0,
        gcDegreeMinuteSeconds	= 1,
        acDegreeMinuteSeconds	= 1,
        gcGrads	= 2,
        acGrads	= 2,
        gcRadians	= 3,
        acRadians	= 3
    } 	GcAngleUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("6AD34E29-95A5-4365-9EA6-ADBA3F00A69E") 
enum GcUnits
    {
        gcDefaultUnits	= -1,
        acDefaultUnits	= -1,
        gcScientific	= 1,
        acScientific	= 1,
        gcDecimal	= 2,
        acDecimal	= 2,
        gcEngineering	= 3,
        acEngineering	= 3,
        gcArchitectural	= 4,
        acArchitectural	= 4,
        gcFractional	= 5,
        acFractional	= 5
    } 	GcUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("EC188510-9E74-4FF2-82E4-A5E7D99C6724") 
enum GcCoordinateSystem
    {
        gcWorld	= 0,
        acWorld	= 0,
        gcUCS	= 1,
        acUCS	= 1,
        gcDisplayDCS	= 2,
        acDisplayDCS	= 2,
        gcPaperSpaceDCS	= 3,
        acPaperSpaceDCS	= 3,
        gcOCS	= 4,
        acOCS	= 4
    } 	GcCoordinateSystem;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("4AF20B3F-1AAB-42B4-B342-74750EE1C727") 
enum GcMeasurementUnits
    {
        gcEnglish	= 0,
        acEnglish	= 0,
        gcMetric	= 1,
        acMetric	= 1
    } 	GcMeasurementUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("9890F720-6D8E-4E1F-A7DC-118B9735A0AB") 
enum GcXRefDemandLoad
    {
        gcDemandLoadDisabled	= 0,
        acDemandLoadDisabled	= 0,
        gcDemandLoadEnabled	= 1,
        acDemandLoadEnabled	= 1,
        gcDemandLoadEnabledWithCopy	= 2,
        acDemandLoadEnabledWithCopy	= 2
    } 	GcXRefDemandLoad;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D68089F7-0B64-4963-8607-A23733CA9209") 
enum GcPreviewMode
    {
        gcPartialPreview	= 0,
        acPartialPreview	= 0,
        gcFullPreview	= 1,
        acFullPreview	= 1
    } 	GcPreviewMode;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("24F3F75A-9945-40F7-A8A8-FAB20FBE98B4") 
enum GcPolymeshType
    {
        gcSimpleMesh	= 0,
        acSimpleMesh	= 0,
        gcQuadSurfaceMesh	= 5,
        acQuadSurfaceMesh	= 5,
        gcCubicSurfaceMesh	= 6,
        acCubicSurfaceMesh	= 6,
        gcBezierSurfaceMesh	= 8,
        acBezierSurfaceMesh	= 8
    } 	GcPolymeshType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E9782AAC-0FA0-4B86-88EE-BCD8276C32AF") 
enum GcDragDisplayMode
    {
        gcDragDoNotDisplay	= 0,
        acDragDoNotDisplay	= 0,
        gcDragDisplayOnRequest	= 1,
        acDragDisplayOnRequest	= 1,
        gcDragDisplayAutomatically	= 2,
        acDragDisplayAutomatically	= 2
    } 	GcDragDisplayMode;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("8E215F23-F5A6-433E-A81C-F029B5DF67FB") 
enum GcGRXDemandLoad
    {
        gcDemanLoadDisable	= 0,
        acDemanLoadDisable	= 0,
        gcDemandLoadOnObjectDetect	= 1,
        acDemandLoadOnObjectDetect	= 1,
        gcDemandLoadCmdInvoke	= 2,
        acDemandLoadCmdInvoke	= 2
    } 	GcGRXDemandLoad;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("6E8D2242-259E-4115-A79C-C8D58A4DB4EF") 
enum GcTextFontStyle
    {
        gcFontRegular	= 0,
        acFontRegular	= 0,
        gcFontItalic	= 1,
        acFontItalic	= 1,
        gcFontBold	= 2,
        acFontBold	= 2,
        gcFontBoldItalic	= 3,
        acFontBoldItalic	= 3
    } 	GcTextFontStyle;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("260A770F-3B89-472B-AF43-647774C9281A") 
enum GcProxyImage
    {
        gcProxyNotShow	= 0,
        acProxyNotShow	= 0,
        gcProxyShow	= 1,
        acProxyShow	= 1,
        gcProxyBoundingBox	= 2,
        acProxyBoundingBox	= 2
    } 	GcProxyImage;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("A86FC808-8A55-42C8-A7B3-7F8E4DAB9F20") 
enum GcKeyboardPriority
    {
        gcKeyboardRunningObjSnap	= 0,
        acKeyboardRunningObjSnap	= 0,
        gcKeyboardEntry	= 1,
        acKeyboardEntry	= 1,
        gcKeyboardEntryExceptScripts	= 2,
        acKeyboardEntryExceptScripts	= 2
    } 	GcKeyboardPriority;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("B4C20857-5AA7-4A75-AE4D-C7CD5D8914D6") 
enum GcMenuGroupType
    {
        gcBaseMenuGroup	= 0,
        acBaseMenuGroup	= 0,
        gcPartialMenuGroup	= 1,
        acPartialMenuGroup	= 1
    } 	GcMenuGroupType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5E3F7629-2082-4329-9FD1-C16BFBF178A7") 
enum GcMenuFileType
    {
        gcMenuFileCompiled	= 0,
        acMenuFileCompiled	= 0,
        gcMenuFileSource	= 1,
        acMenuFileSource	= 1
    } 	GcMenuFileType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F46A4118-9177-442F-BBDB-AF94C07AF088") 
enum GcMenuItemType
    {
        gcMenuItem	= 0,
        acMenuItem	= 0,
        gcMenuSeparator	= 1,
        acMenuSeparator	= 1,
        gcMenuSubMenu	= 2,
        acMenuSubMenu	= 2
    } 	GcMenuItemType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D4FD2B0B-9A0F-47CC-8D6C-22FF6FD14ADC") 
enum GcToolbarItemType
    {
        gcToolbarButton	= 0,
        acToolbarButton	= 0,
        gcToolbarSeparator	= 1,
        acToolbarSeparator	= 1,
        gcToolbarControl	= 2,
        acToolbarControl	= 2,
        gcToolbarFlyout	= 3,
        acToolbarFlyout	= 3
    } 	GcToolbarItemType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("66EE74F1-1A2D-47C3-B0A6-8516C646B213") 
enum GcToolbarDockStatus
    {
        gcToolbarDockTop	= 0,
        acToolbarDockTop	= 0,
        gcToolbarDockBottom	= 1,
        acToolbarDockBottom	= 1,
        gcToolbarDockLeft	= 2,
        acToolbarDockLeft	= 2,
        gcToolbarDockRight	= 3,
        acToolbarDockRight	= 3,
        gcToolbarFloating	= 4,
        acToolbarFloating	= 4
    } 	GcToolbarDockStatus;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("54D2CD94-3570-4831-9B87-9E55604252B9") 
enum GcPlotPaperUnits
    {
        gcInches	= 0,
        acInches	= 0,
        gcMillimeters	= 1,
        acMillimeters	= 1,
        gcPixels	= 2,
        acPixels	= 2
    } 	GcPlotPaperUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E0AFD1C5-32FF-49D3-B184-78F1D4B5F9B7") 
enum GcPlotRotation
    {
        gc0degrees	= 0,
        ac0degrees	= 0,
        gc90degrees	= 1,
        ac90degrees	= 1,
        gc180degrees	= 2,
        ac180degrees	= 2,
        gc270degrees	= 3,
        ac270degrees	= 3
    } 	GcPlotRotation;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("6D244C08-D437-41CA-B21D-54EBE58D41AC") 
enum GcPlotType
    {
        gcDisplay	= 0,
        acDisplay	= 0,
        gcExtents	= 1,
        acExtents	= 1,
        gcLimits	= 2,
        acLimits	= 2,
        gcView	= 3,
        acView	= 3,
        gcWindow	= 4,
        acWindow	= 4,
        gcLayout	= 5,
        acLayout	= 5
    } 	GcPlotType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("0DF3C0C4-34CA-4C93-BC0F-DF67E084DA9F") 
enum GcPlotScale
    {
        gcScaleToFit	= 0,
        acScaleToFit	= 0,
        gc1_128in_1ft	= 1,
        ac1_128in_1ft	= 1,
        gc1_64in_1ft	= 2,
        ac1_64in_1ft	= 2,
        gc1_32in_1ft	= 3,
        ac1_32in_1ft	= 3,
        gc1_16in_1ft	= 4,
        ac1_16in_1ft	= 4,
        gc3_32in_1ft	= 5,
        ac3_32in_1ft	= 5,
        gc1_8in_1ft	= 6,
        ac1_8in_1ft	= 6,
        gc3_16in_1ft	= 7,
        ac3_16in_1ft	= 7,
        gc1_4in_1ft	= 8,
        ac1_4in_1ft	= 8,
        gc3_8in_1ft	= 9,
        ac3_8in_1ft	= 9,
        gc1_2in_1ft	= 10,
        ac1_2in_1ft	= 10,
        gc3_4in_1ft	= 11,
        ac3_4in_1ft	= 11,
        gc1in_1ft	= 12,
        ac1in_1ft	= 12,
        gc3in_1ft	= 13,
        ac3in_1ft	= 13,
        gc6in_1ft	= 14,
        ac6in_1ft	= 14,
        gc1ft_1ft	= 15,
        ac1ft_1ft	= 15,
        gc1_1	= 16,
        ac1_1	= 16,
        gc1_2	= 17,
        ac1_2	= 17,
        gc1_4	= 18,
        ac1_4	= 18,
        gc1_8	= 19,
        ac1_8	= 19,
        gc1_10	= 20,
        ac1_10	= 20,
        gc1_16	= 21,
        ac1_16	= 21,
        gc1_20	= 22,
        ac1_20	= 22,
        gc1_30	= 23,
        ac1_30	= 23,
        gc1_40	= 24,
        ac1_40	= 24,
        gc1_50	= 25,
        ac1_50	= 25,
        gc1_100	= 26,
        ac1_100	= 26,
        gc2_1	= 27,
        ac2_1	= 27,
        gc4_1	= 28,
        ac4_1	= 28,
        gc8_1	= 29,
        ac8_1	= 29,
        gc10_1	= 30,
        ac10_1	= 30,
        gc100_1	= 31,
        ac100_1	= 31
    } 	GcPlotScale;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C433FCA5-F491-4B0A-8F90-09F590DF4579") 
enum GcAlignment
    {
        gcAlignmentLeft	= 0,
        acAlignmentLeft	= 0,
        gcAlignmentCenter	= 1,
        acAlignmentCenter	= 1,
        gcAlignmentRight	= 2,
        acAlignmentRight	= 2,
        gcAlignmentAligned	= 3,
        acAlignmentAligned	= 3,
        gcAlignmentMiddle	= 4,
        acAlignmentMiddle	= 4,
        gcAlignmentFit	= 5,
        acAlignmentFit	= 5,
        gcAlignmentTopLeft	= 6,
        acAlignmentTopLeft	= 6,
        gcAlignmentTopCenter	= 7,
        acAlignmentTopCenter	= 7,
        gcAlignmentTopRight	= 8,
        acAlignmentTopRight	= 8,
        gcAlignmentMiddleLeft	= 9,
        acAlignmentMiddleLeft	= 9,
        gcAlignmentMiddleCenter	= 10,
        acAlignmentMiddleCenter	= 10,
        gcAlignmentMiddleRight	= 11,
        acAlignmentMiddleRight	= 11,
        gcAlignmentBottomLeft	= 12,
        acAlignmentBottomLeft	= 12,
        gcAlignmentBottomCenter	= 13,
        acAlignmentBottomCenter	= 13,
        gcAlignmentBottomRight	= 14,
        acAlignmentBottomRight	= 14
    } 	GcAlignment;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("81D84749-A42C-4FFA-88A5-849F7A3C6536") 
enum GcLineSpacingStyle
    {
        gcLineSpacingStyleAtLeast	= 1,
        acLineSpacingStyleAtLeast	= 1,
        gcLineSpacingStyleExactly	= 2,
        acLineSpacingStyleExactly	= 2
    } 	GcLineSpacingStyle;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F7583221-4C62-4fff-B845-63D682E36B07") 
enum GcDimPrecision
    {
        gcDimPrecisionZero	= 0,
        acDimPrecisionZero	= 0,
        gcDimPrecisionOne	= 1,
        acDimPrecisionOne	= 1,
        gcDimPrecisionTwo	= 2,
        acDimPrecisionTwo	= 2,
        gcDimPrecisionThree	= 3,
        acDimPrecisionThree	= 3,
        gcDimPrecisionFour	= 4,
        acDimPrecisionFour	= 4,
        gcDimPrecisionFive	= 5,
        acDimPrecisionFive	= 5,
        gcDimPrecisionSix	= 6,
        acDimPrecisionSix	= 6,
        gcDimPrecisionSeven	= 7,
        acDimPrecisionSeven	= 7,
        gcDimPrecisionEight	= 8,
        acDimPrecisionEight	= 8
    } 	GcDimPrecision;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F1CB5F61-E39D-4395-8DB4-95ADDDBB2273") 
enum GcDimUnits
    {
        gcDimScientific	= 1,
        acDimScientific	= 1,
        gcDimDecimal	= 2,
        acDimDecimal	= 2,
        gcDimEngineering	= 3,
        acDimEngineering	= 3,
        gcDimArchitecturalStacked	= 4,
        acDimArchitecturalStacked	= 4,
        gcDimFractionalStacked	= 5,
        acDimFractionalStacked	= 5,
        gcDimArchitectural	= 6,
        acDimArchitectural	= 6,
        gcDimFractional	= 7,
        acDimFractional	= 7,
        gcDimWindowsDesktop	= 8,
        acDimWindowsDesktop	= 8
    } 	GcDimUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("2D0CF989-F429-4E84-B227-6759FDA79792") 
enum GcDimLUnits
    {
        gcDimLScientific	= 1,
        acDimLScientific	= 1,
        gcDimLDecimal	= 2,
        acDimLDecimal	= 2,
        gcDimLEngineering	= 3,
        acDimLEngineering	= 3,
        gcDimLArchitectural	= 4,
        acDimLArchitectural	= 4,
        gcDimLFractional	= 5,
        acDimLFractional	= 5,
        gcDimLWindowsDesktop	= 6,
        acDimLWindowsDesktop	= 6
    } 	GcDimLUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("BC9ED119-6094-43BB-877D-3D420F1F5C3F") 
enum GcDimArrowheadType
    {
        gcArrowDefault	= 0,
        acArrowDefault	= 0,
        gcArrowClosedBlank	= 1,
        acArrowClosedBlank	= 1,
        gcArrowClosed	= 2,
        acArrowClosed	= 2,
        gcArrowDot	= 3,
        acArrowDot	= 3,
        gcArrowArchTick	= 4,
        acArrowArchTick	= 4,
        gcArrowOblique	= 5,
        acArrowOblique	= 5,
        gcArrowOpen	= 6,
        acArrowOpen	= 6,
        gcArrowOrigin	= 7,
        acArrowOrigin	= 7,
        gcArrowOrigin2	= 8,
        acArrowOrigin2	= 8,
        gcArrowOpen90	= 9,
        acArrowOpen90	= 9,
        gcArrowOpen30	= 10,
        acArrowOpen30	= 10,
        gcArrowDotSmall	= 11,
        acArrowDotSmall	= 11,
        gcArrowDotBlank	= 12,
        acArrowDotBlank	= 12,
        gcArrowSmall	= 13,
        acArrowSmall	= 13,
        gcArrowBoxBlank	= 14,
        acArrowBoxBlank	= 14,
        gcArrowBoxFilled	= 15,
        acArrowBoxFilled	= 15,
        gcArrowDatumBlank	= 16,
        acArrowDatumBlank	= 16,
        gcArrowDatumFilled	= 17,
        acArrowDatumFilled	= 17,
        gcArrowIntegral	= 18,
        acArrowIntegral	= 18,
        gcArrowNone	= 19,
        acArrowNone	= 19,
        gcArrowUserDefined	= 20,
        acArrowUserDefined	= 20
    } 	GcDimArrowheadType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D6D9B7BD-C989-4A67-AD6D-BA4C4C46BF5E") 
enum GcDimCenterType
    {
        gcCenterMark	= 0,
        acCenterMark	= 0,
        gcCenterLine	= 1,
        acCenterLine	= 1,
        gcCenterNone	= 2,
        acCenterNone	= 2
    } 	GcDimCenterType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("FE545CC8-A847-4A57-A418-698DF0DC220E") 
enum GcDimFit
    {
        gcTextAndArrows	= 0,
        acTextAndArrows	= 0,
        gcArrowsOnly	= 1,
        acArrowsOnly	= 1,
        gcTextOnly	= 2,
        acTextOnly	= 2,
        gcBestFit	= 3,
        acBestFit	= 3
    } 	GcDimFit;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D6119675-290B-416C-BF94-DC232D9DAF7D") 
enum GcDimFractionType
    {
        gcHorizontal	= 0,
        acHorizontal	= 0,
        gcDiagonal	= 1,
        acDiagonal	= 1,
        gcNotStacked	= 2,
        acNotStacked	= 2
    } 	GcDimFractionType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("19494851-E03A-4FE5-A42C-6092079119B4") 
enum GcDimArcLengthSymbol
    {
        gcSymInFront	= 0,
        acSymInFront	= 0,
        gcSymAbove	= 1,
        acSymAbove	= 1,
        gcSymNone	= 2,
        acSymNone	= 2
    } 	GcDimArcLengthSymbol;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("00372B5F-7DC6-417D-81B6-56C034B066B5") 
enum GcDimHorizontalJustification
    {
        gcHorzCentered	= 0,
        acHorzCentered	= 0,
        gcFirstExtensionLine	= 1,
        acFirstExtensionLine	= 1,
        gcSecondExtensionLine	= 2,
        acSecondExtensionLine	= 2,
        gcOverFirstExtension	= 3,
        acOverFirstExtension	= 3,
        gcOverSecondExtension	= 4,
        acOverSecondExtension	= 4
    } 	GcDimHorizontalJustification;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("A419D684-C4F1-4ABE-988D-D4BEE3CB0FE5") 
enum GcDimVerticalJustification
    {
        gcVertCentered	= 0,
        acVertCentered	= 0,
        gcAbove	= 1,
        acAbove	= 1,
        gcOutside	= 2,
        acOutside	= 2,
        gcJIS	= 3,
        acJIS	= 3,
        gcUnder	= 4,
        acUnder	= 4
    } 	GcDimVerticalJustification;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("613161E9-D04B-4CFD-99DD-9FA649C7B905") 
enum GcDimTextMovement
    {
        gcDimLineWithText	= 0,
        acDimLineWithText	= 0,
        gcMoveTextAddLeader	= 1,
        acMoveTextAddLeader	= 1,
        gcMoveTextNoLeader	= 2,
        acMoveTextNoLeader	= 2
    } 	GcDimTextMovement;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("167018D5-DA79-42D0-98CA-8C1F6E6B6500") 
enum GcDimToleranceMethod
    {
        gcTolNone	= 0,
        acTolNone	= 0,
        gcTolSymmetrical	= 1,
        acTolSymmetrical	= 1,
        gcTolDeviation	= 2,
        acTolDeviation	= 2,
        gcTolLimits	= 3,
        acTolLimits	= 3,
        gcTolBasic	= 4,
        acTolBasic	= 4
    } 	GcDimToleranceMethod;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("149F3F09-9AF2-4BB9-9ACB-737020A6F739") 
enum GcDimToleranceJustify
    {
        gcTolBottom	= 0,
        acTolBottom	= 0,
        gcTolMiddle	= 1,
        acTolMiddle	= 1,
        gcTolTop	= 2,
        acTolTop	= 2
    } 	GcDimToleranceJustify;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("3CE1F2EE-5EB4-4D65-9DFD-AD136DB5D6C1") 
enum GcViewportScale
    {
        gcVpScaleToFit	= 0,
        acVpScaleToFit	= 0,
        gcVpCustomScale	= 1,
        acVpCustomScale	= 1,
        gcVp1	= 2,
        acVp1	= 2,
        gcVp2	= 3,
        acVp2	= 3,
        gcVp3	= 4,
        acVp3	= 4,
        gcVp4	= 5,
        acVp4	= 5,
        gcVp5	= 6,
        acVp5	= 6,
        gcVp6	= 7,
        acVp6	= 7,
        gcVp7	= 8,
        acVp7	= 8,
        gcVp8	= 9,
        acVp8	= 9,
        gcVp9	= 10,
        acVp9	= 10,
        gcVp10	= 11,
        acVp10	= 11,
        gcVp11	= 12,
        acVp11	= 12,
        gcVp12	= 13,
        acVp12	= 13,
        gcVp13	= 14,
        acVp13	= 14,
        gcVp14	= 15,
        acVp14	= 15,
        gcVp15	= 16,
        acVp15	= 16,
        gcVp16	= 17,
        acVp16	= 17,
        gcVp17	= 18,
        acVp17	= 18,
        gcVp18	= 19,
        acVp18	= 19,
        gcVp19	= 20,
        acVp19	= 20,
        gcVp20	= 21,
        acVp20	= 21,
        gcVp21	= 22,
        acVp21	= 22,
        gcVp22	= 23,
        acVp22	= 23,
        gcVp23	= 24,
        acVp23	= 24,
        gcVp24	= 25,
        acVp24	= 25,
        gcVp25	= 26,
        acVp25	= 26,
        gcVp26	= 27,
        acVp26	= 27,
        gcVp27	= 28,
        acVp27	= 28,
        gcVp28	= 29,
        acVp28	= 29,
        gcVp29	= 30,
        acVp29	= 30,
        gcVp30	= 31,
        acVp30	= 31,
        gcVp31	= 32,
        acVp31	= 32,
        gcVp32	= 33,
        acVp32	= 33,
        gcVp33	= 34,
        acVp33	= 34,
        gcVp34	= 35,
        acVp34	= 35,
        gcVp35	= 36,
        acVp35	= 36,
        gcVp36	= 37,
        acVp36	= 37,
        gcVp37	= 38,
        acVp37	= 38,
        gcVp38	= 39,
        acVp38	= 39,
        gcVp39	= 40,
        acVp39	= 40,
        gcVp40	= 41,
        acVp40	= 41,
        gcVp41	= 42,
        acVp41	= 42,
        gcVp42	= 43,
        acVp42	= 43,
        gcVp43	= 44,
        acVp43	= 44,
        gcVp44	= 45,
        acVp44	= 45,
        gcVp45	= 46,
        acVp45	= 46,
        gcVp46	= 47,
        acVp46	= 47,
        gcVp47	= 48,
        acVp47	= 48,
        gcVp48	= 49,
        acVp48	= 49,
        gcVp49	= 50,
        acVp49	= 50,
        gcVp50	= 51,
        acVp50	= 51,
        gcVp51	= 52,
        acVp51	= 52,
        gcVp52	= 53,
        acVp52	= 53,
        gcVp53	= 54,
        acVp53	= 54,
        gcVp54	= 55,
        acVp54	= 55,
        gcVp55	= 56,
        acVp55	= 56,
        gcVp56	= 57,
        acVp56	= 57,
        gcVp57	= 58,
        acVp57	= 58,
        gcVp58	= 59,
        acVp58	= 59,
        gcVp59	= 60,
        acVp59	= 60,
        gcVp60	= 61,
        acVp60	= 61,
        gcVp61	= 62,
        acVp61	= 62,
        gcVp62	= 63,
        acVp62	= 63,
        gcVp63	= 64,
        acVp63	= 64,
        gcVp64	= 65,
        acVp64	= 65,
        gcVp65	= 66,
        acVp65	= 66,
        gcVp66	= 67,
        acVp66	= 67,
        gcVp67	= 68,
        acVp67	= 68,
        gcVp68	= 69,
        acVp68	= 69,
        gcVp69	= 70,
        acVp69	= 70,
        gcVp70	= 71,
        acVp70	= 71,
        gcVp71	= 72,
        acVp71	= 72,
        gcVp72	= 73,
        acVp72	= 73,
        gcVp73	= 74,
        acVp73	= 74,
        gcVp74	= 75,
        acVp74	= 75,
        gcVp75	= 76,
        acVp75	= 76,
        gcVp76	= 77,
        acVp76	= 77,
        gcVp77	= 78,
        acVp77	= 78,
        gcVp78	= 79,
        acVp78	= 79,
        gcVp79	= 80,
        acVp79	= 80,
        gcVp80	= 81,
        acVp80	= 81,
        gcVp81	= 82,
        acVp81	= 82,
        gcVp82	= 83,
        acVp82	= 83,
        gcVp83	= 84,
        acVp83	= 84,
        gcVp84	= 85,
        acVp84	= 85,
        gcVp85	= 86,
        acVp85	= 86,
        gcVp86	= 87,
        acVp86	= 87,
        gcVp87	= 88,
        acVp87	= 88,
        gcVp88	= 89,
        acVp88	= 89,
        gcVp89	= 90,
        acVp89	= 90,
        gcVp90	= 91,
        acVp90	= 91,
        gcVp91	= 92,
        acVp91	= 92,
        gcVp92	= 93,
        acVp92	= 93,
        gcVp93	= 94,
        acVp93	= 94,
        gcVp94	= 95,
        acVp94	= 95,
        gcVp95	= 96,
        acVp95	= 96,
        gcVp96	= 97,
        acVp96	= 97,
        gcVp97	= 98,
        acVp97	= 98,
        gcVp98	= 99,
        acVp98	= 99,
        gcVp99	= 100,
        acVp99	= 100,
        gcVp100	= 101,
        acVp100	= 101,
        gcVp1_1	= 2,
        acVp1_1	= 2,
        gcVp1_2	= 3,
        acVp1_2	= 3,
        gcVp1_4	= 4,
        acVp1_4	= 4,
        gcVp1_8	= 5,
        acVp1_8	= 5,
        gcVp1_10	= 6,
        acVp1_10	= 6,
        gcVp1_16	= 7,
        acVp1_16	= 7,
        gcVp1_20	= 8,
        acVp1_20	= 8,
        gcVp1_30	= 9,
        acVp1_30	= 9,
        gcVp1_40	= 10,
        acVp1_40	= 10,
        gcVp1_50	= 11,
        acVp1_50	= 11,
        gcVp1_100	= 12,
        acVp1_100	= 12,
        gcVp2_1	= 13,
        acVp2_1	= 13,
        gcVp4_1	= 14,
        acVp4_1	= 14,
        gcVp8_1	= 15,
        acVp8_1	= 15,
        gcVp10_1	= 16,
        acVp10_1	= 16,
        gcVp100_1	= 17,
        acVp100_1	= 17,
        gcVp1_128in_1ft	= 18,
        acVp1_128in_1ft	= 18,
        gcVp1_64in_1ft	= 19,
        acVp1_64in_1ft	= 19,
        gcVp1_32in_1ft	= 20,
        acVp1_32in_1ft	= 20,
        gcVp1_16in_1ft	= 21,
        acVp1_16in_1ft	= 21,
        gcVp3_32in_1ft	= 22,
        acVp3_32in_1ft	= 22,
        gcVp1_8in_1ft	= 23,
        acVp1_8in_1ft	= 23,
        gcVp3_16in_1ft	= 24,
        acVp3_16in_1ft	= 24,
        gcVp1_4in_1ft	= 25,
        acVp1_4in_1ft	= 25,
        gcVp3_8in_1ft	= 26,
        acVp3_8in_1ft	= 26,
        gcVp1_2in_1ft	= 27,
        acVp1_2in_1ft	= 27,
        gcVp3_4in_1ft	= 28,
        acVp3_4in_1ft	= 28,
        gcVp1in_1ft	= 29,
        acVp1in_1ft	= 29,
        gcVp1and1_2in_1ft	= 30,
        acVp1and1_2in_1ft	= 30,
        gcVp3in_1ft	= 31,
        acVp3in_1ft	= 31,
        gcVp6in_1ft	= 32,
        acVp6in_1ft	= 32,
        gcVp1ft_1ft	= 33,
        acVp1ft_1ft	= 33
    } 	GcViewportScale;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("9ED0E80B-4BDC-4EC6-B703-67C38D3EA6E0") 
enum GcISOPenWidth
    {
        gcPenWidth013	= 13,
        acPenWidth013	= 13,
        gcPenWidth018	= 18,
        acPenWidth018	= 18,
        gcPenWidth025	= 25,
        acPenWidth025	= 25,
        gcPenWidth035	= 35,
        acPenWidth035	= 35,
        gcPenWidth050	= 50,
        acPenWidth050	= 50,
        gcPenWidth070	= 70,
        acPenWidth070	= 70,
        gcPenWidth100	= 100,
        acPenWidth100	= 100,
        gcPenWidth140	= 140,
        acPenWidth140	= 140,
        gcPenWidth200	= 200,
        acPenWidth200	= 200,
        gcPenWidthUnk	= -1,
        acPenWidthUnk	= -1
    } 	GcISOPenWidth;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("DD77B50F-47F9-4B43-995E-AFF6BE7DC9D1") 
enum GcSaveAsType
    {
        gcR09_dxf	= -5,
        acR09_dxf	= -5,
        gcR10_dxf	= -4,
        acR10_dxf	= -4,
        gcR12_dwg	= -3,
        acR12_dwg	= -3,
        gcUnknown	= -1,
        acUnknown	= -1,
        gcR12_dxf	= 1,
        acR12_dxf	= 1,
        gcR13_dwg	= 4,
        acR13_dwg	= 4,
        gcR13_dxf	= 5,
        acR13_dxf	= 5,
        gcR14_dwg	= 8,
        acR14_dwg	= 8,
        gcR14_dxf	= 9,
        acR14_dxf	= 9,
        gc2000_dwg	= 12,
        ac2000_dwg	= 12,
        gc2000_dxf	= 13,
        ac2000_dxf	= 13,
        gc2000_Template	= 14,
        ac2000_Template	= 14,
        gc2004_dwg	= 24,
        ac2004_dwg	= 24,
        gc2004_dxf	= 25,
        ac2004_dxf	= 25,
        gc2004_Template	= 26,
        ac2004_Template	= 26,
        gc2007_dwg	= 36,
        ac2007_dwg	= 36,
        gc2007_dxf	= 37,
        ac2007_dxf	= 37,
        gc2007_Template	= 38,
        ac2007_Template	= 38,
        gc2010_dwg	= 48,
        ac2010_dwg	= 48,
        gc2010_dxf	= 49,
        ac2010_dxf	= 49,
        gc2010_Template	= 50,
        ac2010_Template	= 50,
        gc2013_dwg	= 60,
        ac2013_dwg	= 60,
        gc2013_dxf	= 61,
        ac2013_dxf	= 61,
        gc2013_Template	= 62,
        ac2013_Template	= 62,
        gcNative	= 60,
        acNative	= 60,
        gcR15_dwg	= 12,
        acR15_dwg	= 12,
        gcR15_dxf	= 13,
        acR15_dxf	= 13,
        gcR15_Template	= 14,
        acR15_Template	= 14,
        gcR18_dwg	= 24,
        acR18_dwg	= 24,
        gcR18_dxf	= 25,
        acR18_dxf	= 25,
        gcR18_Template	= 26,
        acR18_Template	= 26
    } 	GcSaveAsType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("154899D6-9732-4A89-9C06-CD8F607257DF") 
enum GcPrinterSpoolAlert
    {
        gcPrinterAlwaysAlert	= 0,
        acPrinterAlwaysAlert	= 0,
        gcPrinterAlertOnce	= 1,
        acPrinterAlertOnce	= 1,
        gcPrinterNeverAlertLogOnce	= 2,
        acPrinterNeverAlertLogOnce	= 2,
        gcPrinterNeverAlert	= 3,
        acPrinterNeverAlert	= 3
    } 	GcPrinterSpoolAlert;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F1C56304-DD71-4B56-A0B5-8E6452EA55D8") 
enum GcPlotPolicyForNewDwgs
    {
        gcPolicyNewDefault	= 0,
        acPolicyNewDefault	= 0,
        gcPolicyNewLegacy	= 1,
        acPolicyNewLegacy	= 1
    } 	GcPlotPolicyForNewDwgs;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("7E6FE0C4-AC5F-460A-99B8-9D3982B4501D") 
enum GcPlotPolicyForLegacyDwgs
    {
        gcPolicyLegacyDefault	= 0,
        acPolicyLegacyDefault	= 0,
        gcPolicyLegacyQuery	= 1,
        acPolicyLegacyQuery	= 1,
        gcPolicyLegacyLegacy	= 2,
        acPolicyLegacyLegacy	= 2
    } 	GcPlotPolicyForLegacyDwgs;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("36B01405-AB6B-4FF0-9659-3C9308A88740") 
enum GcOleQuality
    {
        gcOQLineArt	= 0,
        acOQLineArt	= 0,
        gcOQText	= 1,
        acOQText	= 1,
        gcOQGraphics	= 2,
        acOQGraphics	= 2,
        gcOQPhoto	= 3,
        acOQPhoto	= 3,
        gcOQHighPhoto	= 4,
        acOQHighPhoto	= 4
    } 	GcOleQuality;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C8221DEF-7852-43BD-B619-857CB837B17D") 
enum GcLoadPalette
    {
        gcPaletteByDrawing	= 0,
        acPaletteByDrawing	= 0,
        gcPaletteBySession	= 1,
        acPaletteBySession	= 1
    } 	GcLoadPalette;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("8081B0CA-52CC-4FD6-883B-847B76AA85BA") 
enum GcInsertUnits
    {
        gcInsertUnitsUnitless	= 0,
        acInsertUnitsUnitless	= 0,
        gcInsertUnitsInches	= 1,
        acInsertUnitsInches	= 1,
        gcInsertUnitsFeet	= 2,
        acInsertUnitsFeet	= 2,
        gcInsertUnitsMiles	= 3,
        acInsertUnitsMiles	= 3,
        gcInsertUnitsMillimeters	= 4,
        acInsertUnitsMillimeters	= 4,
        gcInsertUnitsCentimeters	= 5,
        acInsertUnitsCentimeters	= 5,
        gcInsertUnitsMeters	= 6,
        acInsertUnitsMeters	= 6,
        gcInsertUnitsKilometers	= 7,
        acInsertUnitsKilometers	= 7,
        gcInsertUnitsMicroinches	= 8,
        acInsertUnitsMicroinches	= 8,
        gcInsertUnitsMils	= 9,
        acInsertUnitsMils	= 9,
        gcInsertUnitsYards	= 10,
        acInsertUnitsYards	= 10,
        gcInsertUnitsAngstroms	= 11,
        acInsertUnitsAngstroms	= 11,
        gcInsertUnitsNanometers	= 12,
        acInsertUnitsNanometers	= 12,
        gcInsertUnitsMicrons	= 13,
        acInsertUnitsMicrons	= 13,
        gcInsertUnitsDecimeters	= 14,
        acInsertUnitsDecimeters	= 14,
        gcInsertUnitsDecameters	= 15,
        acInsertUnitsDecameters	= 15,
        gcInsertUnitsHectometers	= 16,
        acInsertUnitsHectometers	= 16,
        gcInsertUnitsGigameters	= 17,
        acInsertUnitsGigameters	= 17,
        gcInsertUnitsAstronomicalUnits	= 18,
        acInsertUnitsAstronomicalUnits	= 18,
        gcInsertUnitsLightYears	= 19,
        acInsertUnitsLightYears	= 19,
        gcInsertUnitsParsecs	= 20,
        acInsertUnitsParsecs	= 20
    } 	GcInsertUnits;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("524CB9B8-6E1A-419B-A1D6-6300175C1701") 
enum GcAlignmentPointAcquisition
    {
        gcAlignPntAcquisitionAutomatic	= 0,
        acAlignPntAcquisitionAutomatic	= 0,
        gcAlignPntAcquisitionShiftToAcquire	= 1,
        acAlignPntAcquisitionShiftToAcquire	= 1
    } 	GcAlignmentPointAcquisition;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("CA754D76-7B9C-4915-9895-CFE8ADA27D48") 
enum GcInsertUnitsAction
    {
        gcInsertUnitsPrompt	= 0,
        acInsertUnitsPrompt	= 0,
        gcInsertUnitsAutoAssign	= 1,
        acInsertUnitsAutoAssign	= 1
    } 	GcInsertUnitsAction;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("FA20315F-EB0B-4340-A721-16B777176382") 
enum GcPlotPolicy
    {
        gcPolicyNamed	= 0,
        acPolicyNamed	= 0,
        gcPolicyLegacy	= 1,
        acPolicyLegacy	= 1
    } 	GcPlotPolicy;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("B66D4F70-FCDA-4468-AB0D-968B86CB003F") 
enum GcDrawingAreaShortCutMenu
    {
        gcNoDrawingAreaShortCutMenu	= 0,
        acNoDrawingAreaShortCutMenu	= 0,
        gcUseDefaultDrawingAreaShortCutMenu	= 1,
        acUseDefaultDrawingAreaShortCutMenu	= 1
    } 	GcDrawingAreaShortCutMenu;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F309DBBA-B7E4-4E32-847A-53EA5907697A") 
enum GcDrawingAreaSCMDefault
    {
        gcRepeatLastCommand	= 0,
        acRepeatLastCommand	= 0,
        gcSCM	= 1,
        acSCM	= 1
    } 	GcDrawingAreaSCMDefault;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("4005A53D-6C00-4DE2-8E25-5EE23671D4A5") 
enum GcDrawingAreaSCMEdit
    {
        gcEdRepeatLastCommand	= 0,
        acEdRepeatLastCommand	= 0,
        gcEdSCM	= 1,
        acEdSCM	= 1
    } 	GcDrawingAreaSCMEdit;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5320C61F-A6BB-4450-8640-A9F761D2518A") 
enum GcDrawingAreaSCMCommand
    {
        gcEnter	= 0,
        acEnter	= 0,
        gcEnableSCMOptions	= 1,
        acEnableSCMOptions	= 1,
        gcEnableSCM	= 2,
        acEnableSCM	= 2
    } 	GcDrawingAreaSCMCommand;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("2E4CA1E1-38A4-4C41-B386-9C86F4B8F228") 
enum GcLayerStateMask
    {
        gcLsNone	= 0,
        acLsNone	= 0,
        gcLsOn	= 1,
        acLsOn	= 1,
        gcLsFrozen	= 2,
        acLsFrozen	= 2,
        gcLsLocked	= 4,
        acLsLocked	= 4,
        gcLsPlot	= 8,
        acLsPlot	= 8,
        gcLsNewViewport	= 16,
        acLsNewViewport	= 16,
        gcLsColor	= 32,
        acLsColor	= 32,
        gcLsLineType	= 64,
        acLsLineType	= 64,
        gcLsLineWeight	= 128,
        acLsLineWeight	= 128,
        gcLsPlotStyle	= 256,
        acLsPlotStyle	= 256,
        gcLsAll	= 65535,
        acLsAll	= 65535
    } 	GcLayerStateMask;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("47FA2128-83D4-4292-B7A4-5FC0496F18C5") 
enum GcShadePlot
    {
        gcShadePlotAsDisplayed	= 0,
        acShadePlotAsDisplayed	= 0,
        gcShadePlotWireframe	= 1,
        acShadePlotWireframe	= 1,
        gcShadePlotHidden	= 2,
        acShadePlotHidden	= 2,
        gcShadePlotRendered	= 3,
        acShadePlotRendered	= 3
    } 	GcShadePlot;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("96F1B537-6E4E-45CE-B595-29144D88C6BF") 
enum GcHatchObjectType
    {
        gcHatchObject	= 0,
        acHatchObject	= 0,
        gcGradientObject	= 1,
        acGradientObject	= 1
    } 	GcHatchObjectType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("AC423A6D-C5C3-4290-A7BC-446AD3C06FE3") 
enum GcTableDirection
    {
        gcTableTopToBottom	= 0,
        acTableTopToBottom	= 0,
        gcTableBottomToTop	= 1,
        acTableBottomToTop	= 1
    } 	GcTableDirection;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5091E438-AEB0-4D38-AE7B-D016ED7CE557") 
enum GcCellAlignment
    {
        gcTopLeft	= 1,
        acTopLeft	= 1,
        gcTopCenter	= 2,
        acTopCenter	= 2,
        gcTopRight	= 3,
        acTopRight	= 3,
        gcMiddleLeft	= 4,
        acMiddleLeft	= 4,
        gcMiddleCenter	= 5,
        acMiddleCenter	= 5,
        gcMiddleRight	= 6,
        acMiddleRight	= 6,
        gcBottomLeft	= 7,
        acBottomLeft	= 7,
        gcBottomCenter	= 8,
        acBottomCenter	= 8,
        gcBottomRight	= 9,
        acBottomRight	= 9
    } 	GcCellAlignment;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("130D8BEB-AF4D-4B59-BE89-E09D29FD9420") 
enum GcRowType
    {
        gcUnknownRow	= 0,
        acUnknownRow	= 0,
        gcDataRow	= 1,
        acDataRow	= 1,
        gcTitleRow	= 2,
        acTitleRow	= 2,
        gcHeaderRow	= 4,
        acHeaderRow	= 4
    } 	GcRowType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("07DDCA6D-C072-42F4-9EE8-A61F6409E87B") 
enum GcValueDataType
    {
        gcUnknownDataType	= 0,
        acUnknownDataType	= 0,
        gcLong	= 1,
        acLong	= 1,
        gcDouble	= 2,
        acDouble	= 2,
        gcString	= 4,
        acString	= 4,
        gcDate	= 8,
        acDate	= 8,
        gcPoint2d	= 16,
        acPoint2d	= 16,
        gcPoint3d	= 32,
        acPoint3d	= 32,
        gcObjectId	= 64,
        acObjectId	= 64,
        gcBuffer	= 128,
        acBuffer	= 128,
        gcResbuf	= 256,
        acResbuf	= 256,
        gcGeneral	= 512,
        acGeneral	= 512
    } 	GcValueDataType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5EC8EE84-3325-41C6-AEA9-90F5F5DDF5D3") 
enum GcValueUnitType
    {
        gcUnitless	= 0,
        acUnitless	= 0,
        gcUnitDistance	= 1,
        acUnitDistance	= 1,
        gcUnitAngle	= 2,
        acUnitAngle	= 2,
        gcUnitArea	= 4,
        acUnitArea	= 4,
        gcUnitVolume	= 8,
        acUnitVolume	= 8
    } 	GcValueUnitType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("BCA62356-13B3-4AFD-8FCE-432CF4E5341C") 
enum GcParseOption
    {
        gcParseOptionNone	= 0,
        acParseOptionNone	= 0,
        gcSetDefaultFormat	= 1,
        acSetDefaultFormat	= 1,
        gcPreserveMtextFormat	= 2,
        acPreserveMtextFormat	= 2
    } 	GcParseOption;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D94D842E-F9EF-4B94-BAFC-F32526D6773A") 
enum GcFormatOption
    {
        kFormatOptionNone	= 0,
        gcForEditing	= 1,
        acForEditing	= 1,
        gcForExpression	= 2,
        acForExpression	= 2,
        gcUseMaximumPrecision	= 4,
        acUseMaximumPrecision	= 4,
        gcIgnoreMtextFormat	= 8,
        acIgnoreMtextFormat	= 8
    } 	GcFormatOption;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("4EF134AB-8CC9-4115-977E-49C437F564D0") 
enum GcCellContentType
    {
        gcCellContentTypeUnknown	= 0,
        acCellContentTypeUnknown	= 0,
        gcCellContentTypeValue	= 1,
        acCellContentTypeValue	= 1,
        gcCellContentTypeField	= 2,
        acCellContentTypeField	= 2,
        gcCellContentTypeBlock	= 4,
        acCellContentTypeBlock	= 4
    } 	GcCellContentType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E5B98E75-2C92-4E50-9FEE-D6177D5BA156") 
enum GcCellMargin
    {
        gcCellMarginTop	= 1,
        acCellMarginTop	= 1,
        gcCellMarginLeft	= 2,
        acCellMarginLeft	= 2,
        gcCellMarginBottom	= 4,
        acCellMarginBottom	= 4,
        gcCellMarginRight	= 8,
        acCellMarginRight	= 8,
        gcCellMarginHorzSpacing	= 16,
        acCellMarginHorzSpacing	= 16,
        gcCellMarginVertSpacing	= 32,
        acCellMarginVertSpacing	= 32
    } 	GcCellMargin;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("9D91B008-50A6-4130-A813-62E403574F86") 
enum GcCellContentLayout
    {
        gcCellContentLayoutFlow	= 1,
        acCellContentLayoutFlow	= 1,
        gcCellContentLayoutStackedHorizontal	= 2,
        acCellContentLayoutStackedHorizontal	= 2,
        gcCellContentLayoutStackedVertical	= 4,
        acCellContentLayoutStackedVertical	= 4
    } 	GcCellContentLayout;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("349FF703-207A-4676-BDCA-9FAD6B985881") 
enum GcCellProperty
    {
        gcInvalidCellProperty	= 0,
        acInvalidCellProperty	= 0,
        gcLock	= 1,
        acLock	= 1,
        gcDataType	= 2,
        acDataType	= 2,
        gcDataFormat	= 4,
        acDataFormat	= 4,
        gcRotation	= 8,
        acRotation	= 8,
        gcScale	= 16,
        acScale	= 16,
        gcAlignmentProperty	= 32,
        acAlignmentProperty	= 32,
        gcContentColor	= 64,
        acContentColor	= 64,
        gcBackgroundColor	= 128,
        acBackgroundColor	= 128,
        gcTextStyle	= 256,
        acTextStyle	= 256,
        gcTextHeight	= 512,
        acTextHeight	= 512,
        gcMarginLeft	= 1024,
        acMarginLeft	= 1024,
        gcMarginTop	= 2048,
        acMarginTop	= 2048,
        gcMarginRight	= 4096,
        acMarginRight	= 4096,
        gcMarginBottom	= 8192,
        acMarginBottom	= 8192,
        gcEnableBackgroundColor	= 16384,
        acEnableBackgroundColor	= 16384,
        gcAutoScale	= 32768,
        acAutoScale	= 32768,
        gcMergeAll	= 0x10000,
        acMergeAll	= 0x10000,
        gcFlowDirBtoT	= 0x20000,
        acFlowDirBtoT	= 0x20000,
        gcContentLayout	= 0x40000,
        acContentLayout	= 0x40000,
        gcDataTypeAndFormat	= 6,
        acDataTypeAndFormat	= 6,
        gcContentProperties	= 33662,
        acContentProperties	= 33662,
        gcBitProperties	= 0x3c000,
        acBitProperties	= 0x3c000,
        gcAllCellProperties	= 0x7ffff,
        acAllCellProperties	= 0x7ffff
    } 	GcCellProperty;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("51A1B2D1-CA96-4AED-AB1D-A5273D55E345") 
enum GcGridLineStyle
    {
        gcGridLineStyleSingle	= 1,
        acGridLineStyleSingle	= 1,
        gcGridLineStyleDouble	= 2,
        acGridLineStyleDouble	= 2
    } 	GcGridLineStyle;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("15ABB9C9-1F3A-4252-BA8C-D5452C900DE1") 
enum GcCellState
    {
        gcCellStateNone	= 0,
        acCellStateNone	= 0,
        gcCellStateContentLocked	= 1,
        acCellStateContentLocked	= 1,
        gcCellStateContentReadOnly	= 2,
        acCellStateContentReadOnly	= 2,
        gcCellStateFormatLocked	= 4,
        acCellStateFormatLocked	= 4,
        gcCellStateFormatReadOnly	= 8,
        acCellStateFormatReadOnly	= 8,
        gcCellStateLinked	= 16,
        acCellStateLinked	= 16,
        gcCellStateContentModified	= 32,
        acCellStateContentModified	= 32,
        gcCellStateFormatModified	= 64,
        acCellStateFormatModified	= 64
    } 	GcCellState;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("79E64B1E-435B-4BE0-8A40-005FE32A39FD") 
enum GcTableFlowDirection
    {
        gcTableFlowRight	= 1,
        acTableFlowRight	= 1,
        gcTableFlowDownOrUp	= 2,
        acTableFlowDownOrUp	= 2,
        gcTableFlowLeft	= 4,
        acTableFlowLeft	= 4
    } 	GcTableFlowDirection;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("FB0093A5-4264-4F4B-BA9E-D0A586737906") 
enum GcGridLineType
    {
        gcInvalidGridLine	= 0,
        acInvalidGridLine	= 0,
        gcHorzTop	= 1,
        acHorzTop	= 1,
        gcHorzInside	= 2,
        acHorzInside	= 2,
        gcHorzBottom	= 4,
        acHorzBottom	= 4,
        gcVertLeft	= 8,
        acVertLeft	= 8,
        gcVertInside	= 16,
        acVertInside	= 16,
        gcVertRight	= 32,
        acVertRight	= 32
    } 	GcGridLineType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("998EA56C-8C41-4050-9962-933E13FD9096") 
enum GcCellType
    {
        gcUnknownCell	= 0,
        acUnknownCell	= 0,
        gcTextCell	= 1,
        acTextCell	= 1,
        gcBlockCell	= 2,
        acBlockCell	= 2
    } 	GcCellType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("76C80C51-1D3B-4BC9-880D-CA0DF3BFACA0") 
enum GcCellEdgeMask
    {
        gcTopMask	= 1,
        acTopMask	= 1,
        gcRightMask	= 2,
        acRightMask	= 2,
        gcBottomMask	= 4,
        acBottomMask	= 4,
        gcLeftMask	= 8,
        acLeftMask	= 8
    } 	GcCellEdgeMask;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("B1DC4737-025C-4772-9AEC-837A6DED8ADE") 
enum GcRotationAngle
    {
        gcDegreesUnknown	= -1,
        acDegreesUnknown	= -1,
        gcDegrees000	= 0,
        acDegrees000	= 0,
        gcDegrees090	= 1,
        acDegrees090	= 1,
        gcDegrees180	= 2,
        acDegrees180	= 2,
        gcDegrees270	= 3,
        acDegrees270	= 3
    } 	GcRotationAngle;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5B9DDE2E-F234-44AC-A468-C6B9A566F539") 
enum GcSelectType
    {
        gcTableSelectWindow	= 1,
        acTableSelectWindow	= 1,
        gcTableSelectCrossing	= 2,
        acTableSelectCrossing	= 2
    } 	GcSelectType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("0D98070A-89CB-4BCB-82A6-2346F1A21466") 
enum GcOleType
    {
        gcOTLink	= 1,
        acOTLink	= 1,
        gcOTEmbedded	= 2,
        acOTEmbedded	= 2,
        gcOTStatic	= 3,
        acOTStatic	= 3
    } 	GcOleType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("1086960D-E9F9-4794-B027-6DC6BCBAFD95") 
enum GcOlePlotQuality
    {
        gcOPQMonochrome	= 0,
        acOPQMonochrome	= 0,
        gcOPQLowGraphics	= 1,
        acOPQLowGraphics	= 1,
        gcOPQHighGraphics	= 2,
        acOPQHighGraphics	= 2
    } 	GcOlePlotQuality;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("85FA3B51-E42C-4526-8C18-3E5C11821E79") 
enum GcTableStyleOverrides
    {
        gcTitleSuppressed	= 1,
        acTitleSuppressed	= 1,
        gcHeaderSuppressed	= 2,
        acHeaderSuppressed	= 2,
        gcFlowDirection	= 3,
        acFlowDirection	= 3,
        gcHorzCellMargin	= 4,
        acHorzCellMargin	= 4,
        gcVertCellMargin	= 5,
        acVertCellMargin	= 5,
        gcTitleRowColor	= 6,
        acTitleRowColor	= 6,
        gcHeaderRowColor	= 7,
        acHeaderRowColor	= 7,
        gcDataRowColor	= 8,
        acDataRowColor	= 8,
        gcTitleRowFillNone	= 9,
        acTitleRowFillNone	= 9,
        gcHeaderRowFillNone	= 10,
        acHeaderRowFillNone	= 10,
        gcDataRowFillNone	= 11,
        acDataRowFillNone	= 11,
        gcTitleRowFillColor	= 12,
        acTitleRowFillColor	= 12,
        gcHeaderRowFillColor	= 13,
        acHeaderRowFillColor	= 13,
        gcDataRowFillColor	= 14,
        acDataRowFillColor	= 14,
        gcTitleRowAlignment	= 15,
        acTitleRowAlignment	= 15,
        gcHeaderRowAlignment	= 16,
        acHeaderRowAlignment	= 16,
        gcDataRowAlignment	= 17,
        acDataRowAlignment	= 17,
        gcTitleRowTextStyle	= 18,
        acTitleRowTextStyle	= 18,
        gcHeaderRowTextStyle	= 19,
        acHeaderRowTextStyle	= 19,
        gcDataRowTextStyle	= 20,
        acDataRowTextStyle	= 20,
        gcTitleRowTextHeight	= 21,
        acTitleRowTextHeight	= 21,
        gcHeaderRowTextHeight	= 22,
        acHeaderRowTextHeight	= 22,
        gcDataRowTextHeight	= 23,
        acDataRowTextHeight	= 23,
        gcTitleRowDataType	= 24,
        acTitleRowDataType	= 24,
        gcHeaderRowDataType	= 25,
        acHeaderRowDataType	= 25,
        gcDataRowDataType	= 26,
        acDataRowDataType	= 26,
        gcTitleHorzTopColor	= 40,
        acTitleHorzTopColor	= 40,
        gcTitleHorzInsideColor	= 41,
        acTitleHorzInsideColor	= 41,
        gcTitleHorzBottomColor	= 42,
        acTitleHorzBottomColor	= 42,
        gcTitleVertLeftColor	= 43,
        acTitleVertLeftColor	= 43,
        gcTitleVertInsideColor	= 44,
        acTitleVertInsideColor	= 44,
        gcTitleVertRightColor	= 45,
        acTitleVertRightColor	= 45,
        gcHeaderHorzTopColor	= 46,
        acHeaderHorzTopColor	= 46,
        gcHeaderHorzInsideColor	= 47,
        acHeaderHorzInsideColor	= 47,
        gcHeaderHorzBottomColor	= 48,
        acHeaderHorzBottomColor	= 48,
        gcHeaderVertLeftColor	= 49,
        acHeaderVertLeftColor	= 49,
        gcHeaderVertInsideColor	= 50,
        acHeaderVertInsideColor	= 50,
        gcHeaderVertRightColor	= 51,
        acHeaderVertRightColor	= 51,
        gcDataHorzTopColor	= 52,
        acDataHorzTopColor	= 52,
        gcDataHorzInsideColor	= 53,
        acDataHorzInsideColor	= 53,
        gcDataHorzBottomColor	= 54,
        acDataHorzBottomColor	= 54,
        gcDataVertLeftColor	= 55,
        acDataVertLeftColor	= 55,
        gcDataVertInsideColor	= 56,
        acDataVertInsideColor	= 56,
        gcDataVertRightColor	= 57,
        acDataVertRightColor	= 57,
        gcTitleHorzTopLineWeight	= 70,
        acTitleHorzTopLineWeight	= 70,
        gcTitleHorzInsideLineWeight	= 71,
        acTitleHorzInsideLineWeight	= 71,
        gcTitleHorzBottomLineWeight	= 72,
        acTitleHorzBottomLineWeight	= 72,
        gcTitleVertLeftLineWeight	= 73,
        acTitleVertLeftLineWeight	= 73,
        gcTitleVertInsideLineWeight	= 74,
        acTitleVertInsideLineWeight	= 74,
        gcTitleVertRightLineWeight	= 75,
        acTitleVertRightLineWeight	= 75,
        gcHeaderHorzTopLineWeight	= 76,
        acHeaderHorzTopLineWeight	= 76,
        gcHeaderHorzInsideLineWeight	= 77,
        acHeaderHorzInsideLineWeight	= 77,
        gcHeaderHorzBottomLineWeight	= 78,
        acHeaderHorzBottomLineWeight	= 78,
        gcHeaderVertLeftLineWeight	= 79,
        acHeaderVertLeftLineWeight	= 79,
        gcHeaderVertInsideLineWeight	= 80,
        acHeaderVertInsideLineWeight	= 80,
        gcHeaderVertRightLineWeight	= 81,
        acHeaderVertRightLineWeight	= 81,
        gcDataHorzTopLineWeight	= 82,
        acDataHorzTopLineWeight	= 82,
        gcDataHorzInsideLineWeight	= 83,
        acDataHorzInsideLineWeight	= 83,
        gcDataHorzBottomLineWeight	= 84,
        acDataHorzBottomLineWeight	= 84,
        gcDataVertLeftLineWeight	= 85,
        acDataVertLeftLineWeight	= 85,
        gcDataVertInsideLineWeight	= 86,
        acDataVertInsideLineWeight	= 86,
        gcDataVertRightLineWeight	= 87,
        acDataVertRightLineWeight	= 87,
        gcTitleHorzTopVisibility	= 100,
        acTitleHorzTopVisibility	= 100,
        gcTitleHorzInsideVisibility	= 101,
        acTitleHorzInsideVisibility	= 101,
        gcTitleHorzBottomVisibility	= 102,
        acTitleHorzBottomVisibility	= 102,
        gcTitleVertLeftVisibility	= 103,
        acTitleVertLeftVisibility	= 103,
        gcTitleVertInsideVisibility	= 104,
        acTitleVertInsideVisibility	= 104,
        gcTitleVertRightVisibility	= 105,
        acTitleVertRightVisibility	= 105,
        gcHeaderHorzTopVisibility	= 106,
        acHeaderHorzTopVisibility	= 106,
        gcHeaderHorzInsideVisibility	= 107,
        acHeaderHorzInsideVisibility	= 107,
        gcHeaderHorzBottomVisibility	= 108,
        acHeaderHorzBottomVisibility	= 108,
        gcHeaderVertLeftVisibility	= 109,
        acHeaderVertLeftVisibility	= 109,
        gcHeaderVertInsideVisibility	= 110,
        acHeaderVertInsideVisibility	= 110,
        gcHeaderVertRightVisibility	= 111,
        acHeaderVertRightVisibility	= 111,
        gcDataHorzTopVisibility	= 112,
        acDataHorzTopVisibility	= 112,
        gcDataHorzInsideVisibility	= 113,
        acDataHorzInsideVisibility	= 113,
        gcDataHorzBottomVisibility	= 114,
        acDataHorzBottomVisibility	= 114,
        gcDataVertLeftVisibility	= 115,
        acDataVertLeftVisibility	= 115,
        gcDataVertInsideVisibility	= 116,
        acDataVertInsideVisibility	= 116,
        gcDataVertRightVisibility	= 117,
        acDataVertRightVisibility	= 117,
        gcCellAlign	= 130,
        acCellAlign	= 130,
        gcCellBackgroundFillNone	= 131,
        acCellBackgroundFillNone	= 131,
        gcCellBackgroundColor	= 132,
        acCellBackgroundColor	= 132,
        gcCellContentColor	= 133,
        acCellContentColor	= 133,
        gcCellTextStyle	= 134,
        acCellTextStyle	= 134,
        gcCellTextHeight	= 135,
        acCellTextHeight	= 135,
        gcCellTopGridColor	= 136,
        acCellTopGridColor	= 136,
        gcCellRightGridColor	= 137,
        acCellRightGridColor	= 137,
        gcCellBottomGridColor	= 138,
        acCellBottomGridColor	= 138,
        gcCellLeftGridColor	= 139,
        acCellLeftGridColor	= 139,
        gcCellTopGridLineWeight	= 140,
        acCellTopGridLineWeight	= 140,
        gcCellRightGridLineWeight	= 141,
        acCellRightGridLineWeight	= 141,
        gcCellBottomGridLineWeight	= 142,
        acCellBottomGridLineWeight	= 142,
        gcCellLeftGridLineWeight	= 143,
        acCellLeftGridLineWeight	= 143,
        gcCellTopVisibility	= 144,
        acCellTopVisibility	= 144,
        gcCellRightVisibility	= 145,
        acCellRightVisibility	= 145,
        gcCellBottomVisibility	= 146,
        acCellBottomVisibility	= 146,
        gcCellLeftVisibility	= 147,
        acCellLeftVisibility	= 147,
        gcCellDataType	= 148,
        acCellDataType	= 148
    } 	GcTableStyleOverrides;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("3613E445-A5BF-4C86-930F-9A6969F150A6") 
enum GcMLineJustification
    {
        gcTop	= 0,
        acTop	= 0,
        gcZero	= 1,
        acZero	= 1,
        gcBottom	= 2,
        acBottom	= 2
    } 	GcMLineJustification;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("D19793D5-F0A1-4443-A7EE-8515980E98C4") 
enum GcBlockScaling
    {
        gcAny	= 0,
        acAny	= 0,
        gcUniform	= 1,
        acUniform	= 1
    } 	GcBlockScaling;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("4144395C-34BA-4F41-8979-805D3B4FB8D6") 
enum GcDynamicBlockReferencePropertyUnitsType
    {
        gcNoUnits	= 0,
        acNoUnits	= 0,
        gcAngular	= 1,
        acAngular	= 1,
        gcDistance	= 2,
        acDistance	= 2,
        gcArea	= 3,
        acArea	= 3
    } 	GcDynamicBlockReferencePropertyUnitsType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("002F82D2-B56B-4531-B0CB-04A150BE8C46") 
enum GcSectionState
    {
        gcSectionStatePlane	= 1,
        acSectionStatePlane	= 1,
        gcSectionStateBoundary	= 2,
        acSectionStateBoundary	= 2,
        gcSectionStateVolume	= 4,
        acSectionStateVolume	= 4
    } 	GcSectionState;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("DE369A2A-81C5-412C-8645-5EBE24DBC1D4") 
enum GcSectionState2
    {
        gcSectionState2Plane	= 1,
        acSectionState2Plane	= 1,
        gcSectionState2Slice	= 2,
        acSectionState2Slice	= 2,
        gcSectionState2Boundary	= 4,
        acSectionState2Boundary	= 4,
        gcSectionState2Volume	= 8,
        acSectionState2Volume	= 8
    } 	GcSectionState2;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("FB0D348E-F33B-454A-BF18-ABF28F351722") 
enum GcSectionSubItem
    {
        gcSectionSubItemkNone	= 0,
        acSectionSubItemkNone	= 0,
        gcSectionSubItemSectionLine	= 1,
        acSectionSubItemSectionLine	= 1,
        gcSectionSubItemSectionLineTop	= 2,
        acSectionSubItemSectionLineTop	= 2,
        gcSectionSubItemSectionLineBottom	= 4,
        acSectionSubItemSectionLineBottom	= 4,
        gcSectionSubItemBackLine	= 8,
        acSectionSubItemBackLine	= 8,
        gcSectionSubItemBackLineTop	= 16,
        acSectionSubItemBackLineTop	= 16,
        gcSectionSubItemBackLineBottom	= 32,
        acSectionSubItemBackLineBottom	= 32,
        gcSectionSubItemVerticalLineTop	= 64,
        acSectionSubItemVerticalLineTop	= 64,
        gcSectionSubItemVerticalLineBottom	= 128,
        acSectionSubItemVerticalLineBottom	= 128
    } 	GcSectionSubItem;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E1FA71D0-4DEF-4EDD-88C3-EF07E758C62C") 
enum GcSectionType
    {
        gcSectionTypeLiveSection	= 1,
        acSectionTypeLiveSection	= 1,
        gcSectionType2dSection	= 2,
        acSectionType2dSection	= 2,
        gcSectionType3dSection	= 4,
        acSectionType3dSection	= 4
    } 	GcSectionType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("89935D38-42FE-4218-BC47-32C7A9F89625") 
enum GcSectionGeneration
    {
        gcSectionGenerationSourceAllObjects	= 1,
        acSectionGenerationSourceAllObjects	= 1,
        gcSectionGenerationSourceSelectedObjects	= 2,
        acSectionGenerationSourceSelectedObjects	= 2,
        gcSectionGenerationDestinationNewBlock	= 16,
        acSectionGenerationDestinationNewBlock	= 16,
        gcSectionGenerationDestinationReplgceBlock	= 32,
        acSectionGenerationDestinationReplaceBlock	= 32,
        gcSectionGenerationDestinationFile	= 64,
        acSectionGenerationDestinationFile	= 64
    } 	GcSectionGeneration;

typedef /* [public][uuid] */  DECLSPEC_UUID("3FEBD731-0853-4C10-A5F3-C91FCEC42DCB") GcColor GCAD_COLOR;

typedef /* [public][uuid] */  DECLSPEC_UUID("4ACC7443-4D44-4D38-97EF-B72F10630A7B") double GCAD_NOUNITS;

typedef /* [public][uuid] */  DECLSPEC_UUID("D8A8233B-23BA-4378-90BC-F28E9360B61B") GcLineWeight GCAD_LWEIGHT;

typedef /* [public][uuid] */  DECLSPEC_UUID("AC861966-88F9-4519-9536-1E5361CD349C") BSTR GCAD_LTYPE;

typedef /* [public][uuid] */  DECLSPEC_UUID("249ECBDE-DC36-48AB-B88E-EC8AA54F6165") double GCAD_ANGLE;

typedef /* [public][uuid] */  DECLSPEC_UUID("9C77FA7E-BE57-4BF7-A2E2-67D966E6F3E0") double GCAD_DISTANCE;

typedef /* [public][uuid] */  DECLSPEC_UUID("8BCA3712-3A69-4686-9A29-753AB938CD26") 
enum GcHelixConstrainType
    {
        gcTurnHeight	= 0,
        acTurnHeight	= 0,
        gcTurns	= 1,
        acTurns	= 1,
        gcHeight	= 2,
        acHeight	= 2
    } 	GcHelixConstrainType;

typedef /* [public][uuid] */  DECLSPEC_UUID("EE6FB2D2-F082-4CE1-8BB6-A4534A4AD729") 
enum GcShadowDisplayType
    {
        gcCastsAndReceivesShadows	= 0,
        acCastsAndReceivesShadows	= 0,
        gcCastsShadows	= 1,
        acCastsShadows	= 1,
        gcReceivesShadows	= 2,
        acReceivesShadows	= 2,
        gcIgnoreShadows	= 3,
        acIgnoreShadows	= 3
    } 	GcShadowDisplayType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5CB44EAB-50AD-41F7-B91A-4A3F05F1EE1F") 
enum GcLoftedSurfaceNormalType
    {
        gcRuled	= 0,
        acRuled	= 0,
        gcSmooth	= 1,
        acSmooth	= 1,
        gcFirstNormal	= 2,
        acFirstNormal	= 2,
        gcLastNormal	= 3,
        acLastNormal	= 3,
        gcEndsNormal	= 4,
        acEndsNormal	= 4,
        gcAllNormal	= 5,
        acAllNormal	= 5,
        gcUseDraftAngles	= 6,
        acUseDraftAngles	= 6
    } 	GcLoftedSurfaceNormalType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("063B8C72-868A-4F22-8DBE-0F533B574376") 
enum GcHelixTwistType
    {
        gcCCW	= 0,
        acCCW	= 0,
        gcCW	= 1,
        acCW	= 1
    } 	GcHelixTwistType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("3A06D7F0-A251-4A6F-8696-3192D0C44F28") 
enum GcColorMethod
    {
        gcColorMethodByLayer	= 192,
        acColorMethodByLayer	= 192,
        gcColorMethodByBlock	= 193,
        acColorMethodByBlock	= 193,
        gcColorMethodByRGB	= 194,
        acColorMethodByRGB	= 194,
        gcColorMethodByACI	= 195,
        acColorMethodByACI	= 195,
        gcColorMethodForeground	= 197,
        acColorMethodForeground	= 197
    } 	GcColorMethod;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("359F9903-B057-40C3-A39D-29B162A39A68") 
enum GcUnderlayLayerOverrideType
    {
        gcNoOverrides	= 0,
        acNoOverrides	= 0,
        gcApplied	= 1,
        acApplied	= 1
    } 	GcUnderlayLayerOverrideType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("A30AD009-45D0-497B-B534-0DE26FF8C2CF") 
enum GcMLeaderType
    {
        acStraightLeader	= 1,
        gcStraightLeader	= 1,
        acSplineLeader	= 2,
        gcSplineLeader	= 2,
        acInVisibleLeader	= 0,
        gcInVisibleLeader	= 0
    } 	GcMLeaderType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("72794339-4681-433A-8F4F-03F4E090B91F") 
enum GcBlockConnectionType
    {
        acConnectExtents	= 0,
        gcConnectExtents	= 0,
        acConnectBase	= 1,
        gcConnectBase	= 1
    } 	GcBlockConnectionType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("153E71E9-9508-4E9B-AEBE-A4B070F9D99B") 
enum GcTextAttachmentDirection
    {
        acAttachmentHorizontal	= 0,
        gcAttachmentHorizontal	= 0,
        acAttachmentVertical	= 1,
        gcAttachmentVertical	= 1
    } 	GcTextAttachmentDirection;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("28083680-AD31-4071-BDF3-DA8BDC95E96F") 
enum GcTextAttachmentType
    {
        acAttachmentTopOfTop	= 0,
        gcAttachmentTopOfTop	= 0,
        acAttachmentMiddleOfTop	= 1,
        gcAttachmentMiddleOfTop	= 1,
        acAttachmentBottomOfTop	= 2,
        gcAttachmentBottomOfTop	= 2,
        acAttachmentBottomOfTopLine	= 3,
        gcAttachmentBottomOfTopLine	= 3,
        acAttachmentMiddle	= 4,
        gcAttachmentMiddle	= 4,
        acAttachmentMiddleOfBottom	= 5,
        gcAttachmentMiddleOfBottom	= 5,
        acAttachmentBottomOfBottom	= 6,
        gcAttachmentBottomOfBottom	= 6,
        acAttachmentBottomLine	= 7,
        gcAttachmentBottomLine	= 7,
        acAttachmentAllLine	= 8,
        gcAttachmentAllLine	= 8
    } 	GcTextAttachmentType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("663A1779-0419-45B7-AB8D-190072BF9E3F") 
enum GcVerticalTextAttachmentType
    {
        acAttachmentCenter	= 0,
        gcAttachmentCenter	= 0,
        acAttachmentLinedCenter	= 1,
        gcAttachmentLinedCenter	= 1
    } 	GcVerticalTextAttachmentType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("5039C9B4-62D3-452C-8443-3D6C2F6B4B23") 
enum GcPredefBlockType
    {
        acBlockImperial	= 0,
        gcBlockImperial	= 0,
        acBlockSlot	= 1,
        gcBlockSlot	= 1,
        acBlockCircle	= 2,
        gcBlockCircle	= 2,
        acBlockBox	= 3,
        gcBlockBox	= 3,
        acBlockHexagon	= 4,
        gcBlockHexagon	= 4,
        acBlockTriangle	= 5,
        gcBlockTriangle	= 5,
        acBlockUserDefined	= 6,
        gcBlockUserDefined	= 6
    } 	GcPredefBlockType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("0BF7838A-0EB1-40A7-951F-4B10DE10E201") 
enum GcMLeaderContentType
    {
        acNoneContent	= 0,
        gcNoneContent	= 0,
        acBlockContent	= 1,
        gcBlockContent	= 1,
        acMTextContent	= 2,
        gcMTextContent	= 2
    } 	GcMLeaderContentType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("C19EEAF3-D5E2-44C9-A0DB-5D145F0D559B") 
enum GcDrawMLeaderOrderType
    {
        acDrawContentFirst	= 0,
        gcDrawContentFirst	= 0,
        acDrawLeaderFirst	= 1,
        gcDrawLeaderFirst	= 1
    } 	GcDrawMLeaderOrderType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("995F3DF3-37C7-4F8D-AC1A-EFB5F349702B") 
enum GcDrawLeaderOrderType
    {
        acDrawLeaderHeadFirst	= 0,
        gcDrawLeaderHeadFirst	= 0,
        acDrawLeaderTailFirst	= 1,
        gcDrawLeaderTailFirst	= 1
    } 	GcDrawLeaderOrderType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("1D20E331-6E53-480A-AAA5-553C47ABBA26") 
enum GcSegmentAngleType
    {
        acDegreesAny	= 0,
        gcDegreesAny	= 0,
        acDegrees15	= 1,
        gcDegrees15	= 1,
        acDegrees30	= 2,
        gcDegrees30	= 2,
        acDegrees45	= 3,
        gcDegrees45	= 3,
        acDegrees60	= 4,
        gcDegrees60	= 4,
        acDegrees90	= 6,
        gcDegrees90	= 6,
        acDegreesHorz	= 12,
        gcDegreesHorz	= 12
    } 	GcSegmentAngleType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("E9D31142-9F86-4168-AC39-580EAA6C848E") 
enum GcTextAngleType
    {
        acInsertAngle	= 0,
        gcInsertAngle	= 0,
        acHorizontalAngle	= 1,
        gcHorizontalAngle	= 1,
        acAlwaysRightReadingAngle	= 2,
        gcAlwaysRightReadingAngle	= 2
    } 	GcTextAngleType;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("F25C2BB3-8E9F-419D-9EA5-5F4279192688") 
enum GcTextAlignmentType
    {
        acLeftAlignment	= 0,
        gcLeftAlignment	= 0,
        acCenterAlignment	= 1,
        gcCenterAlignment	= 1,
        acRightAlignment	= 2,
        gcRightAlignment	= 2
    } 	GcTextAlignmentType;

typedef /* [public][uuid] */  DECLSPEC_UUID("1CE9367A-1C0E-48C2-8190-B2F9ABB0706E") 
enum __MIDL___MIDL_itf_GcadVbaDefs_0000_0000_0001
    {
        kCellOptionNone	= 0,
        kInheritCellFormat	= 1
    } 	GcCellOption;

typedef /* [public][uuid] */  DECLSPEC_UUID("64A4F8D0-D5D7-47A4-9232-9E7DE9FC51A6") 
enum __MIDL___MIDL_itf_GcadVbaDefs_0000_0000_0002
    {
        acMergeCellStyleNone	= 0,
        acMergeCellStyleCopyDuplicates	= 1,
        acMergeCellStyleOverwriteDuplicates	= 2,
        acMergeCellStyleConvertDuplicatesToOverrides	= 4,
        acMergeCellStyleIgnoreNewStyles	= 8,
        gcMergeCellStyleNone	= 0,
        gcMergeCellStyleCopyDuplicates	= 1,
        gcMergeCellStyleOverwriteDuplicates	= 2,
        gcMergeCellStyleConvertDuplicatesToOverrides	= 4,
        gcMergeCellStyleIgnoreNewStyles	= 8
    } 	GcMergeCellStyleOption;

typedef /* [v1_enum][uuid] */  DECLSPEC_UUID("ADA4DE16-78E4-4C28-A1AB-EAD76066DFF6") 
enum GcWireframeType
    {
        acIsolines	= 0,
        gcIsolines	= 0,
        acIsoparms	= 1,
        gcIsoparms	= 1
    } 	GcWireframeType;



extern RPC_IF_HANDLE __MIDL_itf_GcadVbaDefs_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_GcadVbaDefs_0000_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


