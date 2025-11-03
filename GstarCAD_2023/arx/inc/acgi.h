/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "../../inc/gcgi.h"
#include "adesk.h"
#include "acgidefs.h"   

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
#include "acgiparameter.h"
#include "PAL/api/charset.h"
#include "PAL/api/FontPitchAndFamily.h"

#define ACGI_SERVICES GCGI_SERVICES
#define AcGiSentScanLines GcGiSentScanLines
#define AcGiRequestScanLines GcGiRequestScanLines
#define AcGiClipBoundary GcGiClipBoundary
#define AcGiColorIntensity GcGiColorIntensity
#define AcGiColorRGB GcGiColorRGB
#define AcGiColorRGBA GcGiColorRGBA
#define AcGiPixelBGRA32 GcGiPixelBGRA32
#define AcGiImageBGRA32 GcGiImageBGRA32
#define AcGiSubEntityTraits GcGiSubEntityTraits
#define AcGiDrawableTraits GcGiDrawableTraits
#define AcGiSubEntityTraitsImp GcGiSubEntityTraitsImp
#define AcGiWorldGeometry GcGiWorldGeometry
#define AcGiViewport GcGiViewport
#define AcGiViewportGeometry GcGiViewportGeometry
#define AcGiImpEdgeData GcGiImpEdgeData
#define AcGiImpFaceData GcGiImpFaceData
#define AcGiImpVertexData GcGiImpVertexData
#define AcGiImpTextStyle GcGiImpTextStyle
#define AcGiImpPolyline GcGiImpPolyline
#define AcGiTextStyle GcGiTextStyle
#define AcGiEdgeData GcGiEdgeData
#define AcGiFaceData GcGiFaceData
#define AcGiVertexData GcGiVertexData
#define AcGiImpVariant GcGiImpVariant
#define AcGiVariant GcGiVariant
#define AcGiContextImp GcGiContextImp
#define AcGiContext GcGiContext
#define AcGiCommonDraw GcGiCommonDraw
#define AcGiGeometry GcGiGeometry
#define AcCmEntityColor GcCmEntityColor
#define AcGiMapper GcGiMapper
#define AcGiViewportTraits GcGiViewportTraits
#define AcGiVisualStyleTraits GcGiVisualStyleTraits
#define AcGiContextualColors GcGiContextualColors
#define AcGiGdiDrawObject GcGiGdiDrawObject
#define AcGiImpHatchPatternDefinition GcGiImpHatchPatternDefinition
#define AcGiImpHatchPattern GcGiImpHatchPattern
#define AcGiFill GcGiFill
#define AcGiImpFill GcGiImpFill
#define AcGiImpGradientFill GcGiImpGradientFill
#define AcUniqueString GcUniqueString
#define AcFontHandle GcFontHandle
#define AcGiWorldSegmentCallback GcGiWorldSegmentCallback
#define acgiIsValidClipBoundary gcgiIsValidClipBoundary
#define acgiGetRegenBlockRefStack gcgiGetRegenBlockRefStack
#define AcGiVariant GcGiVariant
#define AcGiKernelDescriptor GcGiKernelDescriptor
#define AcGiGraphicsKernel GcGiGraphicsKernel
#define AcGiContext GcGiContext
#define AcGiCommonDraw GcGiCommonDraw
#define AcGiWorldDraw GcGiWorldDraw
#define AcGiViewportDraw GcGiViewportDraw
#define AcGiViewport GcGiViewport
#define AcGiContextualColors GcGiContextualColors
#define AcGiContextualColors2 GcGiContextualColors2
#define AcGiSelectionMarkerACADReserveStart GcGiSelectionMarkerGCADReserveStart
#define AcGiSelectionMarkerACADReserveEnd GcGiSelectionMarkerGCADReserveEnd
#define AcGiSelectionMarkerACADSelectionPreviewOff GcGiSelectionMarkerGCADSelectionPreviewOff
#define AcGiSelectionMarkerACADSelectionPreviewOn GcGiSelectionMarkerGCADSelectionPreviewOn
#define AcGiSubEntityTraits GcGiSubEntityTraits
#define AcGiDrawableTraits GcGiDrawableTraits
#define AcGiNonEntityTraits GcGiNonEntityTraits
#define AcGiGdiDrawObject GcGiGdiDrawObject
#define AcGiPolyline GcGiPolyline
#define AcGiPositionTransformBehavior GcGiPositionTransformBehavior
#define AcGiScaleTransformBehavior GcGiScaleTransformBehavior
#define kAcGiWorldPosition kGcGiWorldPosition
#define kAcGiViewportPosition kGcGiViewportPosition
#define kAcGiScreenPosition kGcGiScreenPosition
#define kAcGiScreenLocalOriginPosition kGcGiScreenLocalOriginPosition
#define kAcGiWorldWithScreenOffsetPosition kGcGiWorldWithScreenOffsetPosition
#define kAcGiWorldScale kGcGiWorldScale
#define kAcGiViewportScale kGcGiViewportScale
#define kAcGiScreenScale kGcGiScreenScale
#define kAcGiViewportLocalOriginScale kGcGiViewportLocalOriginScale
#define kAcGiScreenLocalOriginScale kGcGiScreenLocalOriginScale
#define kAcGiWorldOrientation kGcGiWorldOrientation
#define kAcGiScreenOrientation kGcGiScreenOrientation
#define kAcGiZAxisOrientation kGcGiZAxisOrientation
#define AcGiGeometry GcGiGeometry
#define AcGiWorldGeometry GcGiWorldGeometry
#define AcGiViewportGeometry GcGiViewportGeometry
#define AcGiEdgeData GcGiEdgeData 
#define AcGiFaceData GcGiFaceData
#define AcGiVertexData GcGiVertexData
#define AcGiTextStyle GcGiTextStyle
#define AcGiFill GcGiFill
#define AcGiHatchPatternDefinition GcGiHatchPatternDefinition
#define AcGiHatchPattern GcGiHatchPattern
#define AcGiGradientFill GcGiGradientFill
#define kAcGiMinColorIntensity     kGcGiMinColorIntensity
#define kAcGiColorIntensity1       kGcGiColorIntensity1
#define kAcGiColorIntensity2       kGcGiColorIntensity2
#define kAcGiColorIntensity3       kGcGiColorIntensity3
#define kAcGiColorIntensity4       kGcGiColorIntensity4
#define kAcGiColorIntensity5       kGcGiColorIntensity5
#define kAcGiColorIntensity6       kGcGiColorIntensity6
#define kAcGiMaxColorIntensity     kGcGiMaxColorIntensity
#define AcGiOrientationTransformBehavior GcGiOrientationTransformBehavior
#define kDrawUseAcGiEntityForDgnLineType kDrawUseGcGiEntityForDgnLineType