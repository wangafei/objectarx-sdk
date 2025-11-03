/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcgi.h"

class GcGiImpVisualStyle;

namespace GcGiVisualStyleProperties
{
  enum Property {
    kInvalidProperty = -1,

    kFaceLightingModel,
    kFaceLightingQuality,
    kFaceColorMode,
    kFaceModifiers,
    kFaceOpacity,
    kFaceSpecular,
    kFaceMonoColor,

    kEdgeModel,
    kEdgeStyles,
    kEdgeIntersectionColor,
    kEdgeObscuredColor,
    kEdgeObscuredLinePattern,
    kEdgeIntersectionLinePattern,
    kEdgeCreaseAngle,
    kEdgeModifiers,
    kEdgeColor,
    kEdgeOpacity,
    kEdgeWidth,
    kEdgeOverhang,
    kEdgeJitterAmount,
    kEdgeSilhouetteColor,
    kEdgeSilhouetteWidth,
    kEdgeHaloGap,
    kEdgeIsolines,
    kEdgeHidePrecision,

    kDisplayStyles,
    kDisplayBrightness,
    kDisplayShadowType,
    kUseDrawOrder,
    kViewportTransparency,
    kLightingEnabled,
    kPosterizeEffect,
    kMonoEffect,
    kBlurEffect,
    kPencilEffect,
    kBloomEffect,
    kPastelEffect,
    kBlurAmount,
    kPencilAngle,
    kPencilScale,
    kPencilPattern,
    kPencilColor,
    kBloomThreshold,
    kBloomRadius,
    kTintColor,
    kFaceAdjustment,
    kPostContrast,
    kPostBrightness,
    kPostPower,
    kTintEffect,
    kBloomIntensity,
    kColor,
    kTransparency,
    kEdgeWiggleAmount,
    kEdgeTexturePath,
    kDepthOfField,
    kFocusDistance,
    kFocusWidth,
    kPropertyCount,
    kPropertyCountPre2013 = kUseDrawOrder,
  };

  enum FaceLightingModel {
    kInvisible,
    kConstant,
    kPhong,
    kGooch,
    kZebra
  };

  enum FaceLightingQuality {
    kNoLighting,
    kPerFaceLighting,
    kPerVertexLighting,
    kPerPixelLighting
  };

  enum FaceColorMode {
    kNoColorMode,
    kObjectColor,
    kBackgroundColor,
    kMono,
    kTint,
    kDesaturate
  };

  enum FaceModifiers {
    kNoFaceModifiers = 0,
    kFaceOpacityFlag = 1,
    kSpecularFlag = 2
  };

  enum  EdgeModel {
    kNoEdges,
    kIsolines,
    kFacetEdges,
  };

  enum EdgeStyles {
    kNoEdgeStyle = 0,
    kVisibleFlag = 1,
    kSilhouetteFlag = 2,
    kObscuredFlag = 4,
    kIntersectionFlag = 8
  };

  enum EdgeModifiers {
    kNoEdgeModifiers = 0,
    kEdgeOverhangFlag = 1,
    kEdgeJitterFlag = 2,
    kEdgeWidthFlag = 4,
    kEdgeColorFlag = 8,
    kEdgeHaloGapFlag = 16,
    kAlwaysOnTopFlag = 64,
    kEdgeOpacityFlag = 128,
    kEdgeWiggleFlag = 256,
    kEdgeTextureFlag = 512,
  };

  enum EdgeJitterAmount {
    kJitterLow = 1,
    kJitterMedium,
    kJitterHigh,
  };

  enum EdgeWiggleAmount {
    kWiggleLow = 1,
    kWiggleMedium,
    kWiggleHigh,
  };

  enum EdgeLinePattern {
    kSolid = 1,
    kDashedLine,
    kDotted,
    kShortDash,
    kMediumDash,
    kLongDash,
    kDoubleShortDash,
    kDoubleMediumDash,
    kDoubleLongDash,
    kMediumLongDash,
    kSparseDot
  };

  enum DisplayStyles {
    kNoDisplayStyle = 0,
    kBackgroundsFlag = 1,
    kLightingFlag = 2,
    kMaterialsFlag = 4,
    kTexturesFlag = 8,
  };

  enum DisplayShadowType {
    kShadowsNone,
    kShadowsGroundPlane,
    kShadowsFull,
    kShadowsFullAndGround,
  };
};

namespace GcGiVisualStyleOperations
{
  enum Operation {
    kInvalidOperation = -1,
    kInherit = 0,
    kSet,
    kDisable,
    kEnable
  };
};

class GCBASE_PORT GcGiVisualStyle : public GcRxObject
{
public:
  friend class            GcDbImpVisualStyle;

  GCRX_DECLARE_MEMBERS(GcGiVisualStyle);

  typedef GcGiVisualStyleProperties::Property Property;
  typedef GcGiVisualStyleOperations::Operation Operation;

  enum Type {
    kFlat,
    kFlatWithEdges,
    kGouraud,
    kGouraudWithEdges,
    k2DWireframe,
    k3DWireframe,
    kHidden,
    kBasic,
    kRealistic,
    kConceptual,
    kCustom,
    kDim,
    kBrighten,
    kThicken,
    kLinePattern,
    kFacePattern,
    kColorChange,
    kFaceOnly,
    kEdgeOnly,
    kDisplayOnly,
    kJitterOff,
    kOverhangOff,
    kEdgeColorOff,
    kShadesOfGray,
    kSketchy,
    kXRay,
    kShadedWithEdges,
    kShaded,
    kByViewport,
    kByLayer,
    kByBlock,
    kEmptyStyle,
  };

  GcGiVisualStyle(void);
  GcGiVisualStyle(Type type);
  GcGiVisualStyle(const GcGiVisualStyle& visualStyle);
  ~GcGiVisualStyle(void);

  GcGiVisualStyle& operator=(const GcGiVisualStyle& visualStyle);
  bool operator==(const GcGiVisualStyle& visualStyle) const;

  bool              setType(Type type);
  Type              type(void) const;
  virtual bool      setTrait(Property prop, Operation op);
  virtual bool      setTrait(Property prop,
    const GcGiVariant *pVal,
    Operation op = GcGiVisualStyleOperations::kSet);
  virtual bool      setTrait(Property prop,
    int nVal,
    Operation op = GcGiVisualStyleOperations::kSet);
  virtual bool      setTrait(Property prop,
    bool bVal,
    Operation op = GcGiVisualStyleOperations::kSet);
  virtual bool      setTrait(Property prop,
    double dVal,
    Operation op = GcGiVisualStyleOperations::kSet);
  virtual bool      setTrait(Property prop,
    double red,
    double green,
    double blue,
    Operation op = GcGiVisualStyleOperations::kSet);
  virtual bool      setTrait(Property prop,
    const GcCmColor *pColor,
    Operation op = GcGiVisualStyleOperations::kSet);
  virtual bool      setTrait(GcGiVisualStyleProperties::Property prop,
    const GcString *pStr,
    GcGiVisualStyleOperations::Operation op
    = GcGiVisualStyleOperations::kSet);
  virtual const GcGiVariant& trait(Property prop,
    Operation *pOp = NULL) const;
  virtual Operation          operation(Property prop) const;
  virtual bool      setTraitFlag(Property flagProp,
    Gsoft::UInt32 flagVal,
    bool bEnable = true);
  virtual bool      traitFlag(Property flagProp,
    Gsoft::UInt32 flagVal) const;
  static GcGiVariant::VariantType propertyType(Property prop);

private:
  const GcGiImpVisualStyle* readImp(void) const;
  GcGiImpVisualStyle*       writeImp(void);
  GcGiImpVisualStyle* mpGcGiImpVisualStyle;
};

class GCBASE_PORT GcGiVisualStyleTraits : public GcGiDrawableTraits
{
public:
  GCRX_DECLARE_MEMBERS(GcGiVisualStyleTraits);

  virtual void                   setGcGiVisualStyle(const GcGiVisualStyle& visualStyle) = 0;
  virtual const GcGiVisualStyle& gcgiVisualStyle(void) const = 0;
};