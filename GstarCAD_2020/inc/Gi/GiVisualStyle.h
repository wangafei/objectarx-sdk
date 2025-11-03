/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////


#ifndef __ODGIVISUALSTYLE_H__
#define __ODGIVISUALSTYLE_H__

#include "../TD_PackPush.h"

#include "../Gi/Gi.h"
#include "../Gi/GiVariant.h"

class OdCmColorBase;

/** Description:

    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiFaceStyle : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiFaceStyle);

  enum LightingModel
  {
    kInvisible = 0,
    kConstant  = 1,
    kPhong     = 2,
    kGooch     = 3
  };

  enum LightingQuality
  {
    kNoLighting        = 0,
    kPerFaceLighting   = 1,
    kPerVertexLighting = 2,
    kPerPixelLighting  = 3
  };

  enum FaceColorMode
  {
    kNoColorMode     = 0,
    kObjectColor     = 1,
    kBackgroundColor = 2,
    kMono            = 3,
    kTint            = 4,
    kDesaturate      = 5
  };

  enum FaceModifier
  {
    kNoFaceModifiers = 0,
    kOpacity         = 1,
    kSpecular        = 2
  };

  void set(const OdGiFaceStyle& style);
  OdGiFaceStyle& operator=(const OdGiFaceStyle& style);
  bool operator==(const OdGiFaceStyle& style) const;

  virtual void setLightingModel(LightingModel lightingModel) = 0;
  virtual LightingModel lightingModel() const = 0;

  virtual void setLightingQuality(LightingQuality lightingQuality) = 0;
  virtual LightingQuality lightingQuality() const = 0;

  virtual void setFaceColorMode(FaceColorMode mode) = 0;
  virtual FaceColorMode faceColorMode() const = 0;

  virtual void setFaceModifiers(unsigned long nModifiers) = 0;
  virtual void setFaceModifierFlag(FaceModifier flag, bool bEnable) = 0;
  virtual unsigned long faceModifiers() const = 0;
  virtual bool isFaceModifierFlagSet(FaceModifier flag) const = 0;

  virtual void setOpacityLevel(double nLevel, bool bEnableModifier) = 0;
  virtual double opacityLevel() const = 0;

  virtual void setSpecularAmount(double nAmount, bool bEnableModifier) = 0;
  virtual double specularAmount() const = 0;

  virtual void setMonoColor(const OdCmColorBase& color, bool bEnableMode) = 0;
  virtual const OdCmColorBase& monoColor() const = 0;
  virtual OdCmColorBase& monoColor() = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiFaceStyle object pointers.
*/
typedef OdSmartPtr<OdGiFaceStyle> OdGiFaceStylePtr;

/** Description:

    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiEdgeStyle : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiEdgeStyle);

  enum EdgeModel
  {
    kNoEdges    = 0,
    kIsolines   = 1,
    kFacetEdges = 2
  };

  enum EdgeStyle
  {
    kNoEdgeStyle  = 0,
    kVisible      = 1,
    kSilhouette   = 2,
    kObscured     = 4,
    kIntersection = 8
  };

  enum EdgeModifier
  {
    kNoEdgeModifiers = 0x000,
    kOverhang        = 0x001,
    kJitter          = 0x002,
    kWidth           = 0x004,
    kColor           = 0x008,
    kHaloGap         = 0x010,
    kLinetype        = 0x020,
    kAlwaysOnTop     = 0x040,
    kOpacity         = 0x080,
    kWiggle          = 0x100,
    kTexture         = 0x200
  };

  enum JitterAmount
  {
    kJitterLow    = 1,
    kJitterMedium = 2,
    kJitterHigh   = 3
  };

  enum WiggleAmount
  {
    kWiggleLow    = 1,
    kWiggleMedium = 2,
    kWiggleHigh   = 3
  };

  enum LineType
  {
    kSolid            = 1,
    kDashed           = 2,
    kDotted           = 3,
    kShortDash        = 4,
    kMediumDash       = 5,
    kLongDash         = 6,
    kDoubleShortDash  = 7,
    kDoubleMediumDash = 8,
    kDoubleLongDash   = 9,
    kMediumLongDash   = 10,
    kSparseDot        = 11
  };

  enum EdgeStyleApply
  {
    kDefault,
    kAll
  };

  void set(const OdGiEdgeStyle& style);
  OdGiEdgeStyle& operator=(const OdGiEdgeStyle& style);
  bool operator==(const OdGiEdgeStyle& style) const;

  virtual void setEdgeModel(EdgeModel model) = 0;
  virtual EdgeModel edgeModel() const = 0;

  virtual void setEdgeStyles(unsigned long nStyles) = 0;
  virtual void setEdgeStyleFlag(EdgeStyle flag, bool bEnable) = 0;
  virtual unsigned long edgeStyles() const = 0;
  virtual bool isEdgeStyleFlagSet(EdgeStyle flag) const = 0;

  virtual void setIntersectionColor(const OdCmColorBase& color) = 0;
  virtual const OdCmColorBase& intersectionColor() const = 0;
  virtual OdCmColorBase& intersectionColor() = 0;

  virtual void setObscuredColor(const OdCmColorBase& color) = 0;
  virtual const OdCmColorBase& obscuredColor() const = 0;
  virtual OdCmColorBase& obscuredColor() = 0;

  virtual void setObscuredLinetype(LineType ltype) = 0;
  virtual LineType obscuredLinetype() const = 0;

  virtual void setIntersectionLinetype(LineType ltype) = 0;
  virtual LineType intersectionLinetype() const = 0;

  virtual void setCreaseAngle(double nAngle) = 0;
  virtual double creaseAngle() const = 0;

  virtual void setEdgeModifiers(unsigned long nModifiers) = 0;
  virtual void setEdgeModifierFlag(EdgeModifier flag, bool bEnable) = 0;
  virtual unsigned long edgeModifiers() const = 0;
  virtual bool isEdgeModifierFlagSet(EdgeModifier flag) const = 0;

  virtual void setEdgeColor(const OdCmColorBase& color, bool bEnableModifier) = 0;
  virtual const OdCmColorBase& edgeColor() const = 0;
  virtual OdCmColorBase& edgeColor() = 0;

  virtual void setOpacityLevel(double nLevel, bool bEnableModifier) = 0;
  virtual double opacityLevel() const = 0;

  virtual void setEdgeWidth(int nWidth, bool bEnableModifier) = 0;
  virtual int edgeWidth() const = 0;

  virtual void setOverhangAmount(int nAmount, bool bEnableModifier) = 0;
  virtual int overhangAmount() const = 0;

  virtual void setJitterAmount(JitterAmount amount, bool bEnableModifier) = 0;
  virtual JitterAmount jitterAmount() const = 0;

  virtual void setWiggleAmount(WiggleAmount amount, bool bEnableModifier) = 0;
  virtual WiggleAmount wiggleAmount() const = 0;

  virtual void setSilhouetteColor(const OdCmColorBase& color) = 0;
  virtual const OdCmColorBase& silhouetteColor() const = 0;
  virtual OdCmColorBase& silhouetteColor() = 0;

  virtual void setSilhouetteWidth(short nWidth) = 0;
  virtual short silhouetteWidth() const = 0;

  virtual void setHaloGap(int nHaloGap, bool bEnableModifier) = 0;
  virtual int haloGap() const = 0;

  virtual void setIsolines(unsigned short nIsolines) = 0;
  virtual unsigned short isolines() const = 0;

  virtual void setHidePrecision(bool bHidePrecision) = 0;
  virtual bool hidePrecision() const = 0;

  virtual void setEdgeStyleApply(EdgeStyleApply apply) = 0;
  virtual EdgeStyleApply edgeStyleApply() const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiEdgeStyle object pointers.
*/
typedef OdSmartPtr<OdGiEdgeStyle> OdGiEdgeStylePtr;

/** Description:

    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiDisplayStyle : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiDisplayStyle);

  enum DisplaySettings
  {
    kNone        = 0x00,
    kBackgrounds = 0x01,
    kLights      = 0x02,
    kMaterials   = 0x04,
    kTextures    = 0x08
  };

  enum ShadowType
  {
    kShadowsNone          = 0,
    kShadowsGroundPlane   = 1,
    kShadowsFull          = 2,         
    kShadowsFullAndGround = 3
  };

  void set(const OdGiDisplayStyle& style);
  OdGiDisplayStyle& operator=(const OdGiDisplayStyle& style);
  bool operator==(const OdGiDisplayStyle& style) const;

  virtual void setDisplaySettings(unsigned long nSettings) = 0;
  virtual void setDisplaySettingsFlag(DisplaySettings flag, bool bEnable) = 0;
  virtual unsigned long displaySettings() const = 0;
  virtual bool isDisplaySettingsFlagSet(DisplaySettings flag) const = 0;

  virtual void setBrightness(double value) = 0;
  virtual double brightness() const = 0;

  virtual void setShadowType(ShadowType type) = 0;
  virtual ShadowType shadowType() const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiDisplayStyle object pointers.
*/
typedef OdSmartPtr<OdGiDisplayStyle> OdGiDisplayStylePtr;


/** Description:
  
    {group:TD_Namespaces}
*/
namespace OdGiVisualStyleProperties
{
  enum Property
  {
    kInvalidProperty              = -1,

    // Face properties

    kFaceLightingModel            =  0, // enum (integer)
    kFaceLightingQuality          =  1, // enum (integer)
    kFaceColorMode                =  2, // enum (integer)
    kFaceModifiers                =  3, // flags (integer)
    kFaceOpacity                  =  4, // double
    kFaceSpecular                 =  5, // double
    kFaceMonoColor                =  6, // color

    // Edge properties

    kEdgeModel                    =  7, // enum (integer)
    kEdgeStyles                   =  8, // flags (integer)
    kEdgeIntersectionColor        =  9, // color
    kEdgeObscuredColor            = 10, // color
    kEdgeObscuredLinePattern      = 11, // enum (integer)
    kEdgeIntersectionLinePattern  = 12, // enum (integer)
    kEdgeCreaseAngle              = 13, // double
    kEdgeModifiers                = 14, // flags (integer)
    kEdgeColor                    = 15, // color
    kEdgeOpacity                  = 16, // double
    kEdgeWidth                    = 17, // integer
    kEdgeOverhang                 = 18, // integer
    kEdgeJitterAmount             = 19, // enum (integer)
    kEdgeSilhouetteColor          = 20, // color
    kEdgeSilhouetteWidth          = 21, // integer
    kEdgeHaloGap                  = 22, // integer
    kEdgeIsolines                 = 23, // integer
    kEdgeHidePrecision            = 24, // boolean

    // Display properties

    kDisplayStyles                = 25, // flags (integer)
    kDisplayBrightness            = 26, // double
    kDisplayShadowType            = 27, // enum (integer)

    // New in AC2011, 2013
    kUseDrawOrder                 = 28, // boolean
    kViewportTransparency         = 29, // boolean
    kLightingEnabled              = 30, // boolean
    kPosterizeEffect              = 31, // boolean
    kMonoEffect                   = 32, // boolean

    // New in 2013
    kBlurEffect                   = 33, // boolean
    kPencilEffect                 = 34, // boolean
    kBloomEffect                  = 35, // boolean
    kPastelEffect                 = 36, // boolean
    kBlurAmount                   = 37, // integer
    kPencilAngle                  = 38, // double
    kPencilScale                  = 39, // -integer- (double)
    kPencilPattern                = 40, // integer
    kPencilColor                  = 41, // color
    kBloomThreshold               = 42, // -double- (integer)
    kBloomRadius                  = 43, // -double- (integer)
    kTintColor                    = 44, // color
    kFaceAdjustment               = 45, // boolean
    kPostContrast                 = 46, // -double? (integer)
    kPostBrightness               = 47, // -double? (integer)
    kPostPower                    = 48, // -double? (integer)
    kTintEffect                   = 49, // boolean
    kBloomIntensity               = 50, // -double- (integer)
    kColor                        = 51, // color
    kTransparency                 = 52, // double
    kEdgeWiggleAmount             = 53, // integer
    kEdgeTexturePath              = 54, // string
    kDepthOfField                 = 55, // boolean
    kFocusDistance                = 56, // double
    kFocusWidth                   = 57, // double

    kPropertyCount
  };

  //
  // Face properties
  //

  enum FaceLightingModel
  {
    kInvisible            = 0,
    kConstant             = 1,
    kPhong                = 2,
    kGooch                = 3,
    // New in 2011
    kZebra                = 4
  };

  enum FaceLightingQuality
  {
    kNoLighting           = 0,
    kPerFaceLighting      = 1,
    kPerVertexLighting    = 2,
    kPerPixelLighting     = 3
  };

  enum FaceColorMode    
  {                     
    kNoColorMode          = 0,
    kObjectColor          = 1,
    kBackgroundColor      = 2,
    kMono                 = 3,
    kTint                 = 4,
    kDesaturate           = 5
  };

  enum FaceModifiers    
  {                     
    kNoFaceModifiers      = 0,
    kFaceOpacityFlag      = 1,
    kSpecularFlag         = 2
  };

  //
  // Edge properties
  //

  enum  EdgeModel       
  {                     
    kNoEdges              = 0,
    kIsolines             = 1,
    kFacetEdges           = 2
  };

  enum EdgeStyles       
  {                     
    kNoEdgeStyle          = 0,
    kVisibleFlag          = 1,
    kSilhouetteFlag       = 2,
    kObscuredFlag         = 4,
    kIntersectionFlag     = 8
  };

  enum EdgeModifiers    
  {                     
    kNoEdgeModifiers      =   0,
    kEdgeOverhangFlag     =   1,
    kEdgeJitterFlag       =   2,
    kEdgeWidthFlag        =   4,
    kEdgeColorFlag        =   8,
    kEdgeHaloGapFlag      =  16,
    kAlwaysOnTopFlag      =  64,
    kEdgeOpacityFlag      = 128,
    // New in 2013
    kEdgeWiggleFlag       = 256,
    kEdgeTextureFlag      = 512
  };

  enum EdgeJitterAmount
  {
    kJitterLow            = 1,
    kJitterMedium         = 2,
    kJitterHigh           = 3
  };

  enum EdgeWiggleAmount
  {
    kWiggleLow            = 1,
    kWiggleMedium         = 2,
    kWiggleHigh           = 3
  };

  enum EdgeLinePattern
  {
    kSolid                =  1,
    kDashedLine           =  2,
    kDotted               =  3,
    kShortDash            =  4,
    kMediumDash           =  5,
    kLongDash             =  6,
    kDoubleShortDash      =  7,
    kDoubleMediumDash     =  8,
    kDoubleLongDash       =  9,
    kMediumLongDash       = 10,
    kSparseDot            = 11
  };

  //
  // Display properties
  //

  enum DisplayStyles
  {
    kNoDisplayStyle       = 0,
    kBackgroundsFlag      = 1,
    kLightingFlag         = 2,
    kMaterialsFlag        = 4,
    kTexturesFlag         = 8
  };

  enum DisplayShadowType
  {
    kShadowsNone          = 0,
    kShadowsGroundPlane   = 1,
    kShadowsFull          = 2,
    kShadowsFullAndGround = 3
  };
};

/** Description:
  
    {group:TD_Namespaces}
*/
namespace OdGiVisualStyleOperations
{
  enum Operation
  {
    kInvalidOperation = -1,
    kInherit          =  0,
    kSet              =  1,
    kDisable          =  2,
    kEnable           =  3
  };
};

/** Description:

    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiVisualStyle : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiVisualStyle);

  enum Type
  {
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
    kEmptyStyle
  };

  OdGiVisualStyle(void);
  OdGiVisualStyle(Type type);
  OdGiVisualStyle(const OdGiVisualStyle& visualStyle);
  ~OdGiVisualStyle(void);

  OdGiVisualStyle& operator=(const OdGiVisualStyle& visualStyle);
  bool operator==(const OdGiVisualStyle& visualStyle) const;

  virtual OdGiFaceStyle& faceStyle (void);
  virtual OdGiEdgeStyle& edgeStyle (void);
  virtual OdGiDisplayStyle& displayStyle (void);

  virtual const OdGiFaceStyle& faceStyle (void) const;
  virtual const OdGiEdgeStyle& edgeStyle (void) const;
  virtual const OdGiDisplayStyle& displayStyle (void) const;

  virtual void setFaceStyle (const OdGiFaceStyle& style);
  virtual void setEdgeStyle (const OdGiEdgeStyle& style);
  virtual void setDisplayStyle (const OdGiDisplayStyle& style);

  void configureForType (Type type);

  // New interface

  virtual bool setType(Type type);
  virtual Type type() const;

  typedef OdGiVisualStyleProperties::Property Property;
  typedef OdGiVisualStyleOperations::Operation Operation;

  virtual bool setTrait(Property prop, Operation op);
  virtual bool setTrait(Property prop, const OdGiVariant *pVal,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, OdInt32 nVal,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, bool bVal,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, double dVal,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, double red, double green, double blue,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, const OdCmColorBase &pColor,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, const OdCmEntityColor &pColor,
                        Operation op = OdGiVisualStyleOperations::kSet);
  virtual bool setTrait(Property prop, const OdString &pStr,
                        Operation op = OdGiVisualStyleOperations::kSet);

  virtual OdGiVariantPtr trait(Property prop, Operation *pOp = NULL) const;
  virtual Operation operation(Property prop) const;

  virtual bool setTraitFlag(Property flagProp, OdUInt32 flagVal, bool bEnable = true);
  virtual bool traitFlag(Property flagProp, OdUInt32 flagVal) const;

  static OdGiVariant::VariantType propertyType(Property prop);
private:
  void configureForFlat();
  void configureForFlatWithEdges();
  void configureForGouraud();
  void configureForGouraudWithEdges();
  void configureForBasic();
  void configureFor2DWireframe();
  void configureFor3DWireframe();
  void configureForHidden();
  void configureForRealistic();
  void configureForConceptual();
  void configureForDim();
  void configureForBrighten();
  void configureForThicken();
  void configureForLinePattern();
  void configureForFacePattern();
  void configureForColorChange();

  // Extended configurations
  void configureForFaceOnly();
  void configureForEdgeOnly();
  void configureForDisplayOnly();

  void configureForJitterOff();
  void configureForOverhangOff();
  void configureForEdgeColorOff();
  void configureForShadesOfGray();
  void configureForSketchy();
  void configureForXRay();
  void configureForShadedWithEdges();
  void configureForShaded();
  void configureForByViewport();
  void configureForByLayer();
  void configureForByBlock();
  void configureForEmptyStyle();

  // Extended flags configuration
  void configureForAc27(bool b2d = false);

  // Clear all changes which is made before
  void configureForInit();
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiVisualStyle object pointers.
*/
typedef OdSmartPtr<OdGiVisualStyle> OdGiVisualStylePtr;

/** Description:

    Library: TD_Gi
    {group:OdGi_Classes}
*/
class FIRSTDLL_EXPORT OdGiVisualStyleTraits : public OdGiDrawableTraits
{
public:
  ODRX_DECLARE_MEMBERS(OdGiVisualStyleTraits);

  virtual void setOdGiVisualStyle(const OdGiVisualStyle& visualStyle) = 0;
  virtual const OdGiVisualStyle& odgiVisualStyle() const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdGiVisualStyleTraits object pointers.
*/
typedef OdSmartPtr<OdGiVisualStyleTraits> OdGiVisualStyleTraitsPtr;

#include "../TD_PackPop.h"

#endif //__ODGIVISUALSTYLE_H__
