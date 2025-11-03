/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GCGI_DEFS_H
#define _GCGI_DEFS_H 1

#include "gsoft.h"

typedef enum {
  eGcGiRegenTypeInvalid = 0,
  kGcGiStandardDisplay = 2,
  kGcGiHideOrShadeCommand,
  kGcGiRenderCommand,
  kGcGiShadedDisplay = kGcGiRenderCommand,
  kGcGiForExplode,
  kGcGiSaveWorldDrawForProxy
} GcGiRegenType;

#define kGcGiSaveWorldDrawForR12 kGcGiForExplode 

typedef enum {
  kGcGiFillAlways = 1,
  kGcGiFillNever
} GcGiFillType;

typedef enum {
  kGcGiInvisible = 0,
  kGcGiVisible,
  kGcGiSilhouette
} GcGiVisibility;

typedef enum {
  kGcGiArcSimple = 0,
  kGcGiArcSector,
  kGcGiArcChord
} GcGiArcType;

typedef enum {
  kGcGiCounterClockwise = -1,
  kGcGiNoOrientation = 0,
  kGcGiClockwise = 1
} GcGiOrientationType;

typedef enum {
  kGcGiMaxDevForCircle = 0,
  kGcGiMaxDevForCurve,
  kGcGiMaxDevForBoundary,
  kGcGiMaxDevForIsoline,
  kGcGiMaxDevForFacet
} GcGiDeviationType;

typedef enum {
  kGcGiBitonal,
  kGcGiPalette,
  kGcGiGray,
  kGcGiRGBA,
  kGcGiBGRA,
  kGcGiARGB,
  kGcGiABGR,
  kGcGiBGR,
  kGcGiRGB
} GcGiImageOrg;

typedef enum {
  kGcGiXLeftToRightTopFirst,
  kGcGiXLeftToRightBottomFirst,
  kGcGiXRightToLeftTopFirst,
  kGcGiXRightToLeftBottomFirst,
  kGcGiYTopToBottomLeftFirst,
  kGcGiYTopToBottomRightFirst,
  kGcGiYBottomToTopLeftFirst,
  kGcGiYBottomToTopRightFirst
} GcGiImageOrient;

typedef enum {
  kDefaultScaleFilter,
  kNearestScaleFilter,
  kBellScaleFilter,
  kMitchellScaleFilter,
  kTriangleScaleFilter,
  kCubicScaleFilter,
  kBsplineScaleFilter,
  kLanczos3ScaleFilter
} GcGiScaleFilterType;

typedef enum {
  kDefaultRotationFilter,
  kInterpolatedRotationFilter,
  kNearestRotationFilter,
} GcGiRotationFilterType;

typedef enum {
  kDefaultScale,
  kRelativeScale,
  kUnTransformedScale
} GcGiScaleType;

enum GcGiHighlightStyle {
  kGcGiHighlightNone,
  kGcGiHighlightCustom,
  kGcGiHighlightDashedAndThicken,
  kGcGiHighlightDim,
  kGcGiHighlightThickDim,
  kGcGiHighlightGlow
};

enum GcGiEdgeStyleMaskValues {
  kGcGiNoEdgeStyleMask = 0,
  kGcGiJitterMask = 1,
  kGcGiOverhangMask = 2,
  kGcGiEdgeColorMask = 4
};
typedef unsigned int GcGiEdgeStyleMask;

#endif