#pragma once
#include "rxobject.h"
#include "AdAChar.h"
#include "dbpl.h"
#include "gemat3d.h"
#include "gemat2d.h"
#include "gepnt2d.h"
#include "dbcolor.h"
#include "acdb.h"
#include "AcGiStyleAttributes.h"
#include "assert.h"

#include "../Gi/GiCommonDraw.h"
#include "../Gi/Gi.h"
#include "../Gi/GiGeometry.h"
#include "../Gi/GiClipBoundary.h"
#include "../Gi/GiLightTraits.h"
#include "../Gi/GiImage.h"
#include "../Gi/GiVariant.h"
#include "../Gi/GiViewportDraw.h"
#include "../Gi/GiViewport.h"
#include "../Gi/GiPolyline.h"
#include "../Gi/GiWorldGeometry.h"
#include "../Gi/GiViewportGeometry.h"

#define  AcGiRegenType               GcGiRegenType 
#define  GcGiRegenType               OdGiRegenType

#define  eAcGiRegenTypeInvalid  eGcGiRegenTypeInvalid       
#define  eGcGiRegenTypeInvalid  eOdGiRegenTypeInvalid

#define  kAcGiStandardDisplay  kGcGiStandardDisplay
#define  kGcGiStandardDisplay  kOdGiStandardDisplay 

#define  kAcGiHideOrShadeCommand  kGcGiHideOrShadeCommand
#define  kGcGiHideOrShadeCommand  kOdGiHideOrShadeCommand

#define  kAcGiRenderCommand  kGcGiRenderCommand
#define  kGcGiRenderCommand  kOdGiRenderCommand

#define  kAcGiShadedDisplay  kGcGiShadedDisplay
#define  kGcGiShadedDisplay  kOdGiShadedDisplay

#define  kAcGiSaveWorldDrawForR12  kAcGiForExplode

#define  kAcGiForExplode  kGcGiForExplode
#define  kGcGiForExplode  kOdGiForExplode

#define  kAcGiSaveWorldDrawForProxy  kGcGiSaveWorldDrawForProxy
#define  kGcGiSaveWorldDrawForProxy  kOdGiSaveWorldDrawForProxy

#define  AcGiFillType     GcGiFillType
#define  GcGiFillType     OdGiFillType

#define  kAcGiFillAlways  kGcGiFillAlways
#define  kGcGiFillAlways  kOdGiFillAlways

#define  kAcGiFillNever  kGcGiFillNever 
#define  kGcGiFillNever  kOdGiFillNever

#define  AcGiVisibility   GcGiVisibility
#define  GcGiVisibility   OdGiVisibility

#define  kAcGiInvisible  kGcGiInvisible
#define  kGcGiInvisible  kOdGiInvisible

#define  kAcGiVisible  kGcGiVisible
#define  kGcGiVisible  kOdGiVisible

#define  kAcGiSilhouette  kGcGiSilhouette
#define  kGcGiSilhouette  kOdGiSilhouette

#define  AcGiArcType     GcGiArcType
#define  GcGiArcType     OdGiArcType

#define  kAcGiArcSimple  kGcGiArcSimple
#define  kGcGiArcSimple  kOdGiArcSimple

#define  kAcGiArcSector  kGcGiArcSector
#define  kGcGiArcSector  kOdGiArcSector

#define  kAcGiArcChord  kGcGiArcChord
#define  kGcGiArcChord   kOdGiArcChord

#define  AcGiOrientationType    GcGiOrientationType
#define  GcGiOrientationType    OdGiOrientationType

#define  kAcGiCounterClockwise  kOdGiCounterClockwise
#define  kAcGiNoOrientation     kOdGiNoOrientation
#define  kAcGiClockwise         kOdGiClockwise

#define  AcGiDeviationType       GcGiDeviationType
#define  GcGiDeviationType       OdGiDeviationType

#define  kAcGiMaxDevForCircle  kGcGiMaxDevForCircle
#define  kGcGiMaxDevForCircle  kOdGiMaxDevForCircle

#define  kAcGiMaxDevForCurve  kGcGiMaxDevForCurve
#define  kGcGiMaxDevForCurve  kOdGiMaxDevForCurve

#define  kAcGiMaxDevForBoundary  kGcGiMaxDevForBoundary
#define  kGcGiMaxDevForBoundary  kOdGiMaxDevForBoundary

#define  kAcGiMaxDevForIsoline  kGcGiMaxDevForIsoline
#define  kGcGiMaxDevForIsoline  kOdGiMaxDevForIsoline

#define  kAcGiMaxDevForFacet  kGcGiMaxDevForFacet
#define  kGcGiMaxDevForFacet  kOdGiMaxDevForFacet

#define  AcGiImageOrg  GcGiImageOrg
#define  GcGiImageOrg  OdGiImageOrg

#define  kAcGiBitonal  kGcGiBitonal
#define  kGcGiBitonal  kOdGiBitonal 

#define  kAcGiPalette  kGcGiPalette
#define  kGcGiPalette  kOdGiPalette

#define  kAcGiGray  kGcGiGray
#define  kGcGiGray  kOdGiGray

#define  kAcGiRGBA  kGcGiRGBA
#define  kGcGiRGBA  kOdGiRGBA

#define  kAcGiBGRA  kGcGiBGRA
#define  kGcGiBGRA  kOdGiBGRA

#define  kAcGiARGB  kGcGiARGB
#define  kGcGiARGB  kOdGiARGB

#define  kAcGiABGR  kGcGiABGR
#define  kGcGiABGR  kOdGiABGR

#define  kAcGiBGR  kGcGiBGR
#define  kGcGiBGR  kOdGiBGR

#define  kAcGiRGB  kGcGiRGB
#define  kGcGiRGB  kOdGiRGB

#define  AcGiImageOrient               GcGiImageOrient
#define  GcGiImageOrient               OdGiImageOrient

#define  kAcGiXLeftToRightTopFirst  kGcGiXLeftToRightTopFirst
#define  kGcGiXLeftToRightTopFirst  kOdGiXLeftToRightTopFirst

#define  kAcGiXLeftToRightBottomFirst  kGcGiXLeftToRightBottomFirst
#define  kGcGiXLeftToRightBottomFirst  kOdGiXLeftToRightBottomFirst

#define  kAcGiXRightToLeftTopFirst  kGcGiXRightToLeftTopFirst
#define  kGcGiXRightToLeftTopFirst  kOdGiXRightToLeftTopFirst

#define  kAcGiXRightToLeftBottomFirst  kGcGiXRightToLeftBottomFirst
#define  kGcGiXRightToLeftBottomFirst  kOdGiXRightToLeftBottomFirst

#define  kAcGiYTopToBottomLeftFirst  kGcGiYTopToBottomLeftFirst
#define  kGcGiYTopToBottomLeftFirst  kOdGiYTopToBottomLeftFirst

#define  kAcGiYTopToBottomRightFirst   kOdGiYTopToBottomRightFirst
#define  kAcGiYBottomToTopLeftFirst    kOdGiYBottomToTopLeftFirst
#define  kAcGiYBottomToTopRightFirst   kOdGiYBottomToTopRightFirst

#define  AcGiScaleFilterType  GcGiScaleFilterType
#define  GcGiScaleFilterType  OdGiScaleFilterType

#define  AcGiRotationFilterType  GcGiRotationFilterType
#define  GcGiRotationFilterType  OdGiRotationFilterType

#define  AcGiScaleType  GcGiScaleType
#define  GcGiScaleType  OdGiScaleType

#define  AcGiEdgeStyleMaskValues  GcGiEdgeStyleMaskValues
#define  GcGiEdgeStyleMaskValues  OdGiEdgeStyleMaskValues
#define  kAcGiNoEdgeStyleMask  kOdGiNoEdgeStyleMask
#define  kAcGiJitterMask  kOdGiJitterMask
#define  kAcGiOverhangMask 	   kOdGiOverhangMask
#define  kAcGiEdgeColorMask    kOdGiEdgeColorMask

#define  AcGiSentScanLines  GcGiSentScanLines
#define  GcGiSentScanLines  OdGiSentScanLines

#define  AcGiRequestScanLines  GcGiRequestScanLines
#define  GcGiRequestScanLines  OdGiRequestScanLines

#define  AcGiClipBoundary  GcGiClipBoundary
#define  GcGiClipBoundary  OdGiClipBoundary

#define  AcGiColorIntensity  GcGiColorIntensity
#define  GcGiColorIntensity  OdGiColorIntensity
#define  kAcGiMinColorIntensity  kOdGiMinColorIntensity 
#define  kAcGiColorIntensity1	 kOdGiColorIntensity1   
#define  kAcGiColorIntensity2	 kOdGiColorIntensity2   
#define  kAcGiColorIntensity3	 kOdGiColorIntensity3   
#define  kAcGiColorIntensity4	 kOdGiColorIntensity4   
#define  kAcGiColorIntensity5	 kOdGiColorIntensity5   
#define  kAcGiColorIntensity6	 kOdGiColorIntensity6   
#define  kAcGiMaxColorIntensity	 kOdGiMaxColorIntensity 

#define  AcGiColorRGBA  GcGiColorRGBA
#define  GcGiColorRGBA  OdGiColorRGBA

#define  AcGiPixelBGRA32  GcGiPixelBGRA32
#define  GcGiPixelBGRA32  OdGiPixelBGRA32

#define  AcGiImageBGRA32  GcGiImageBGRA32
#define  GcGiImageBGRA32  OdGiImageBGRA32

#define  acgiIsValidClipBoundary    odgiIsValidClipBoundary
#define  acgiGetRegenBlockRefStack  odgiGetRegenBlockRefStack

#define  AcGiWorldDraw  GcGiWorldDraw
#define  GcGiWorldDraw  OdGiWorldDraw

#define  AcGiCommonDraw  GcGiCommonDraw
#define  GcGiCommonDraw  OdGiCommonDraw

#define  AcGiContext  GcGiContext
#define  GcGiContext  OdGiContext

#define  AcGiVariant  GcGiVariant
#define  GcGiVariant  OdGiVariant

#define  AcGiViewport  GcGiViewport
#define  GcGiViewport  OdGiViewport

#define  AcGiPositionTransformBehavior  GcGiPositionTransformBehavior
#define  GcGiPositionTransformBehavior  OdGiPositionTransformBehavior

#define  AcGiScaleTransformBehavior  GcGiScaleTransformBehavior
#define  GcGiScaleTransformBehavior  OdGiScaleTransformBehavior

#define  AcGiOrientationTransformBehavior  GcGiOrientationTransformBehavior
#define  GcGiOrientationTransformBehavior  OdGiOrientationTransformBehavior

#define  AcGiGeometry  GcGiGeometry
#define  GcGiGeometry  OdGiGeometry

#define  AcGiWorldGeometry  GcGiWorldGeometry
#define  GcGiWorldGeometry  OdGiWorldGeometry

#define  AcGiViewportGeometry  GcGiViewportGeometry
#define  GcGiViewportGeometry  OdGiViewportGeometry

#define  AcGiEdgeData  GcGiEdgeData
#define  GcGiEdgeData  OdGiEdgeData

#define  AcGiFaceData  GcGiFaceData
#define  GcGiFaceData  OdGiFaceData

#define  AcGiVertexData  GcGiVertexData
#define  GcGiVertexData  OdGiVertexData

#define  AcGiViewportDraw  GcGiViewportDraw
#define  GcGiViewportDraw  OdGiViewportDraw

#define  AcGiTextStyle  GcGiTextStyle
#define  GcGiTextStyle  OdGiTextStyle

#define  AcGiSubEntityTraits GcGiSubEntityTraits
#define  GcGiSubEntityTraits OdGiSubEntityTraits

#define  AcGiPolyline GcGiPolyline
#define  GcGiPolyline OdGiPolyline

#define	AcGiDrawableTraits GcGiDrawableTraits
#define	GcGiDrawableTraits 	OdGiDrawableTraits

#define AcGiColorRGB GcGiColorRGB
#define GcGiColorRGB OdGiColorRGB

#define	kAcGiForExtents kGcGiForExtents
#define	kGcGiForExtents kOdGiForExtents

#define kAcGiWorldPosition kGcGiWorldPosition
#define kGcGiWorldPosition kOdGiWorldPosition

#define kAcGiViewportPosition kGcGiViewportPosition
#define kGcGiViewportPosition kOdGiViewportPosition

#define kAcGiScreenPosition kGcGiScreenPosition
#define kGcGiScreenPosition kOdGiScreenPosition

#define kAcGiScreenLocalOriginPosition kGcGiScreenLocalOriginPosition
#define kGcGiScreenLocalOriginPosition kOdGiScreenLocalOriginPosition

#define kAcGiWorldWithScreenOffsetPosition kGcGiWorldWithScreenOffsetPosition
#define kGcGiWorldWithScreenOffsetPosition kOdGiWorldWithScreenOffsetPosition

#define kAcGiWorldScale kGcGiWorldScale
#define kGcGiWorldScale kOdGiWorldScale

#define kAcGiViewportScale kGcGiViewportScale
#define kGcGiViewportScale kOdGiViewportScale

#define kAcGiScreenScale kGcGiScreenScale
#define kGcGiScreenScale kOdGiScreenScale

#define kAcGiViewportLocalOriginScale kGcGiViewportLocalOriginScale
#define kGcGiViewportLocalOriginScale kOdGiViewportLocalOriginScale

#define kAcGiScreenLocalOriginScale kGcGiScreenLocalOriginScale
#define kGcGiScreenLocalOriginScale kOdGiScreenLocalOriginScale

#define kAcGiWorldOrientation kGcGiWorldOrientation
#define kGcGiWorldOrientation kOdGiWorldOrientation

#define kAcGiScreenOrientation kGcGiScreenOrientation
#define kGcGiScreenOrientation kOdGiScreenOrientation

#define kAcGiZAxisOrientation kGcGiZAxisOrientation
#define kGcGiZAxisOrientation kOdGiZAxisOrientation