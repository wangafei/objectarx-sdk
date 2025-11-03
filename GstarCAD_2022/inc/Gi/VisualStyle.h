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

#ifndef __ODVISUALSTYLE_H__
#define __ODVISUALSTYLE_H__

#include "../CmColor.h"

#include "../TD_PackPush.h"

/** Description:
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdFaceStyle
{
public:

  enum LightingModel {
    kInvisible = 0,
    kConstant  = 1,
    kPhong     = 2,
    kGooch     = 3
  };

  enum LightingQuality {
    kNoLighting        = 0,
    kPerFaceLighting   = 1,
    kPerVertexLighting = 2
  };

  enum FaceColorMode {
    kNoColorMode       = 0,
    kObjectColor       = 1,
    kBackgroundColor   = 2,
    kCustomColor       = 3,
    kMono              = 4,
    kTint              = 5,
    kDesaturate        = 6
  };

  enum FaceModifier {
    kNoFaceModifiers   = 0,
    kOpacity           = 1,
    kSpecular          = 2
  };

  OdFaceStyle( );
  
//  OdFaceStyle (const OdFaceStyle& style);

  ~OdFaceStyle (void) {}

/*void set (const OdFaceStyle& style);
  OdFaceStyle& operator= (const OdFaceStyle& style);
  bool operator== (const OdFaceStyle& style) const;
*/

  void setLightingModel (LightingModel lightingModel) { m_LightingModel = lightingModel; }
  LightingModel lightingModel (void) const { return m_LightingModel; }

  void setLightingQuality (LightingQuality lightingQuality) { m_LightingQuality  = lightingQuality; }
  LightingQuality lightingQuality (void) const { return m_LightingQuality; }

  void setFaceColorMode (FaceColorMode mode) { m_FaceMode = mode; }
  FaceColorMode faceColorMode (void) const { return m_FaceMode; }

  void setFaceModifiers (unsigned long nModifiers) { m_FaceModifiers = (FaceModifier)nModifiers; }
  void setFaceModifierFlag (FaceModifier flag, bool bEnable)
  { 
    unsigned long nModifiers = (unsigned long)m_FaceModifiers;
    SETBIT(nModifiers , (unsigned long)flag, bEnable);
    m_FaceModifiers = (FaceModifier)nModifiers;
  }
  unsigned long faceModifiers (void) const { return m_FaceModifiers; }
  bool isFaceModifierFlagSet (FaceModifier flag) const { return GETBIT((unsigned long)m_FaceModifiers, (unsigned long)flag); }

  void setOpacityLevel (double nLevel, bool bEnableModifier) 
  { 
    m_nOpacityLevel = nLevel;
    if (bEnableModifier)
      setFaceModifierFlag (kOpacity, true);
  }
  double opacityLevel (void) const { return m_nOpacityLevel; }

  void setSpecularAmount (double nAmount, bool bEnableModifier) 
  { 
    m_nSpecularLevel = nAmount; 
    if (bEnableModifier)
      setFaceModifierFlag (kSpecular, true);
  }
  double specularAmount (void) const { return m_nSpecularLevel; }

  void setCustomColor (const OdCmColor& color, bool bEnableMode);
  const OdCmColor& customColor (void) const;
  OdCmColor& customColor (void);

  void setMonoColor (const OdCmColor& color, bool bEnableMode);
  const OdCmColor& monoColor (void) const;
  OdCmColor& monoColor (void);

private:
  FaceModifier m_FaceModifiers;
  LightingModel m_LightingModel;
  LightingQuality m_LightingQuality;
  FaceColorMode m_FaceMode;
  double m_nOpacityLevel;
  double m_nSpecularLevel;
  OdCmColor m_CustomColor; 
  OdCmColor m_MonoColor; 
};

/** Description:
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdEdgeStyle
{
public:
  enum EdgeModel {
    kNoEdges     = 0,
    kIsolines    = 1,
    kFacetEdges  = 2
  };

  enum EdgeStyle {
    kNoEdgeStyle    = 0,
    kVisible        = 1,
    kCrease         = 2,
    kSilhouette     = 4,
    kObscured       = 8,
    kIntersection   = 16
  };

  enum EdgeModifier {
    kNoEdgeModifiers  = 0x00,
    kOverhang         = 0x01,
    kJitter           = 0x02,
    kWidth            = 0x04,
    kColor            = 0x08,
    kHaloGap          = 0x10,
    kLinetype         = 0x20,
    kAlwaysOnTop      = 0x40,
    kOpacity          = 0x80
  };

  enum JitterAmount {
    kJitterLow      = 1,
    kJitterMedium   = 2,
    kJitterHigh     = 3
  };

  enum LineType {
    kSolid              = 1,
    kDashed             = 2,
    kDotted             = 3,
    kShortDash          = 4,
    kMediumDash         = 5,
    kLongDash           = 6,
    kDoubleShortDash    = 7,
    kDoubleMediumDash   = 8,
    kDoubleLongDash     = 9,
    kMediumLongDash     = 10,
    kSparseDot          = 11
  };

  enum EdgeStyleApply {
    kDefault,
    kAll
  };

  OdEdgeStyle (void);
  //OdEdgeStyle (const OdEdgeStyle& style);

  ~OdEdgeStyle (void) {}
/*
  void set (const OdEdgeStyle& style);
  OdEdgeStyle& operator= (const OdEdgeStyle& style);
  bool operator== (const OdEdgeStyle& style) const;
*/

  void setEdgeModel (EdgeModel model) { m_EdgeModel = model; }
  EdgeModel edgeModel (void) const { return m_EdgeModel; }

  void setEdgeStyles (unsigned long nStyles) { m_EdgeStyles = (EdgeStyle)nStyles; }
  void setEdgeStyleFlag (EdgeStyle flag, bool bEnable) 
  { 
    unsigned long nModifiers = (unsigned long)m_EdgeStyles;
    SETBIT(nModifiers , (unsigned long)flag, bEnable);
    m_EdgeStyles = (EdgeStyle)nModifiers;
  }
  unsigned long edgeStyles (void) const { return m_EdgeStyles; }
  bool isEdgeStyleFlagSet (EdgeStyle flag) const { return GETBIT((unsigned long)m_EdgeStyles, (unsigned long)flag); }

  void setIntersectionColor (const OdCmColor& color);
  const OdCmColor& intersectionColor (void) const;
  OdCmColor& intersectionColor (void);

  void setObscuredColor (const OdCmColor& color);
  const OdCmColor& obscuredColor (void) const;
  OdCmColor& obscuredColor (void);

  void setObscuredLinetype (LineType ltype) { m_ObscuredLinetype = ltype; }
  LineType obscuredLinetype (void) const { return m_ObscuredLinetype; }

  void setIntersectionLinetype (LineType ltype) { m_IntersectionLinetype = ltype; }
  LineType intersectionLinetype () const { return m_IntersectionLinetype; }

  void setCreaseAngle (double nAngle) { m_dCreaseAngle = nAngle; }
  double creaseAngle (void) const { return m_dCreaseAngle; }

  void setEdgeModifiers (unsigned long nModifiers) { m_EdgeModifier = (EdgeModifier)nModifiers; }
  void setEdgeModifierFlag (EdgeModifier flag, bool bEnable)
  { 
    unsigned long nModifiers = (unsigned long)m_EdgeModifier;
    SETBIT(nModifiers , (unsigned long)flag, bEnable);
    m_EdgeModifier = (EdgeModifier)nModifiers;
  }
  unsigned long edgeModifiers (void) const { return m_EdgeModifier;}
  bool isEdgeModifierFlagSet (EdgeModifier flag) const { return GETBIT((unsigned long)m_EdgeStyles, (unsigned long)flag); }

  void setEdgeColor (const OdCmColor& color, bool bEnableModifier);
  const OdCmColor& edgeColor (void) const;
  OdCmColor& edgeColor (void);

  void setOpacityLevel (double nLevel, bool bEnableModifier) 
  { 
    m_nOpacityLevel = nLevel; 
    if (bEnableModifier) 
      setEdgeModifierFlag (kOpacity, true);
  }
  double opacityLevel (void) const { return m_nOpacityLevel; }

  void setEdgeWidth (int nWidth, bool bEnableModifier) 
  { 
    m_nEdgeWidth = nWidth; 
    if (bEnableModifier) 
      setEdgeModifierFlag (kWidth, true);
  }
  int edgeWidth (void) const { return m_nEdgeWidth; }

  void setOverhangAmount (int nAmount, bool bEnableModifier) 
  { 
    m_nOverhangAmount = nAmount; 
    if (bEnableModifier) 
      setEdgeModifierFlag (kOverhang, true);
  }
  int overhangAmount (void) const { return m_nOverhangAmount; }

  void setJitterAmount (JitterAmount amount, bool bEnableModifier) 
  { 
    m_JitterAmount = amount; 
    if (bEnableModifier) 
      setEdgeModifierFlag (kJitter, true);
  }
  JitterAmount jitterAmount (void) const { return m_JitterAmount; }

  void setSilhouetteColor (const OdCmColor& color);
  const OdCmColor& silhouetteColor (void) const;
  OdCmColor& silhouetteColor (void);

  void setSilhouetteWidth (short nWidth) { m_nSilhouetteWidth = nWidth; }
  short silhouetteWidth (void) const { return m_nSilhouetteWidth; }

  void setHaloGap (int nHaloGap, bool bEnableModifier) 
  { 
    m_nHaloGap = nHaloGap; 
    if (bEnableModifier) 
      setEdgeModifierFlag (kHaloGap, true);
  }
  int haloGap (void) const { return m_nHaloGap; }

  void setIsolines (unsigned short nIsolines) { m_nIsolines = nIsolines; }
  unsigned short isolines (void) const { return m_nIsolines; }

  void setHidePrecision (bool bHidePrecision) { m_bHidePrecision = bHidePrecision; }
  bool hidePrecision (void) const { return m_bHidePrecision; }

  void setEdgeStyleApply (EdgeStyleApply apply) { m_EdgeStyleApply = apply; }
  EdgeStyleApply edgeStyleApply() const { return m_EdgeStyleApply; }

private:
  int       m_nOverhangAmount;
  JitterAmount m_JitterAmount;
  short     m_nSilhouetteWidth;
  int       m_nHaloGap;
  unsigned short m_nIsolines;
  bool      m_bHidePrecision;
  EdgeModel m_EdgeModel;
  EdgeStyle m_EdgeStyles;
  LineType  m_ObscuredLinetype;
  LineType  m_IntersectionLinetype;
  double    m_dCreaseAngle;
  EdgeModifier m_EdgeModifier;
  double    m_nOpacityLevel;
  int       m_nEdgeWidth;
  OdCmColor m_EdgeColor;
  OdCmColor m_SilhouetteColor;
  OdCmColor m_IntersectionColor;
  OdCmColor m_ObscuredColor;
  EdgeStyleApply m_EdgeStyleApply;
};

/** Description:
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdDisplayStyle
{
public:
  enum DisplaySettings {
    kNone           = 0x00,
    kBackgrounds    = 0x01,
    kLights         = 0x02,
    kMaterials      = 0x04,
    kTextures       = 0x08
  };

  enum TransparencyQuality {
    kTransparencyLow     = 0,
    kTransparencyMedium  = 1,
    kTransparencyHigh    = 2
  };

  enum ShadowType {
    kShadowsNone           = 0,
    kShadowsGroundPlane    = 1,
    kShadowsFull           = 2,         
    kShadowsFullAndGround  = 3
  };

  OdDisplayStyle (void)
    : m_DisplaySettings(kNone)
    , m_TransparencyQuality(kTransparencyLow)
    , m_ShadowType(kShadowsNone)
    , m_dBrightness(0.)
  { }

  // OdDisplayStyle (const OdDisplayStyle& style);
  ~OdDisplayStyle (void) {}

  //void set (const OdDisplayStyle& style);
  //OdDisplayStyle& operator= (const OdDisplayStyle& style);

  //bool operator== (const OdDisplayStyle& style) const;

  void setDisplaySettings (unsigned long nSettings) { m_DisplaySettings = (DisplaySettings)nSettings; }
  void setDisplaySettingsFlag (DisplaySettings flag, bool bEnable) 
    { 
      unsigned long nSettings = (unsigned long)m_DisplaySettings;
      SETBIT(nSettings , (unsigned long)flag, bEnable);
      m_DisplaySettings = (DisplaySettings)nSettings;
    }
  unsigned long displaySettings (void) const { return m_DisplaySettings; }
  bool isDisplaySettingsFlagSet(DisplaySettings flag) const 
    { return GETBIT((unsigned long)m_DisplaySettings, (unsigned long)flag); }

  void setTransparencyQuality (TransparencyQuality quality) { m_TransparencyQuality = quality; }
  TransparencyQuality transparencyQuality (void) const { return m_TransparencyQuality; }

  void setBrightness (double value) { m_dBrightness = value; }
  double brightness (void) const { return m_dBrightness; }

  void setShadowType (ShadowType type) { m_ShadowType = type; }
  ShadowType shadowType (void) const { return m_ShadowType; }

private:
  DisplaySettings     m_DisplaySettings;
  TransparencyQuality m_TransparencyQuality;
  ShadowType          m_ShadowType;
  double              m_dBrightness;
};

/** Description:
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdVisualStyle
{
public:
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
    kColorChange
  };

  OdVisualStyle () {}
/*
  OdVisualStyle (Type type);
  OdVisualStyle (const OdVisualStyle& visualStyle);
  ~OdVisualStyle (void);

  OdVisualStyle& operator= (const OdVisualStyle& visualStyle);
  bool operator== (const OdVisualStyle& visualStyle) const;
*/

  void configureForType (Type type);

  OdFaceStyle& faceStyle (void) { return m_FaceStyle; }
  OdEdgeStyle& edgeStyle (void) { return m_EdgeStyle; }
  OdDisplayStyle& displayStyle (void) { return m_DisplayStyle; }

  const OdFaceStyle& faceStyle (void) const { return m_FaceStyle; }
  const OdEdgeStyle& edgeStyle (void) const { return m_EdgeStyle; }
  const OdDisplayStyle& displayStyle (void) const { return m_DisplayStyle; }

  void setFaceStyle (const OdFaceStyle& style) { m_FaceStyle = style; }
  void setEdgeStyle (const OdEdgeStyle& style) { m_EdgeStyle = style; }
  void setDisplayStyle (const OdDisplayStyle& style) { m_DisplayStyle = style; }

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

  OdFaceStyle m_FaceStyle;
  OdEdgeStyle m_EdgeStyle;
  OdDisplayStyle m_DisplayStyle;
};
/*
class TOOLKIT_EXPORT OdVisualStyleTraits : public OdGiDrawableTraits
{
public:
  void setOdVisualStyle (const OdVisualStyle& visualStyle) = 0;

  const OdVisualStyle& acgiVisualStyle (void) const = 0;
};
*/
#include "../TD_PackPop.h"

#endif //__ODVISUALSTYLE_H__
