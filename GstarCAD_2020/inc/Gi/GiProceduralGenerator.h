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

// Procedural textures generator.

#ifndef __ODGIPROCEDURALGENERATOR_H__
#define __ODGIPROCEDURALGENERATOR_H__

#include "RootExport.h"
#include "GiExport.h"
#include "CmColor.h"
#include "UInt32Array.h"
#include "GiImage.h"
#include "GiMaterial.h"

#include "RxObject.h"

#include "TD_PackPush.h"

/** Description:
    Protocol extension for OdGiProceduralGenerator.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiProceduralGeneratorPE : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiProceduralGeneratorPE);

    OdGiProceduralGeneratorPE();

    /** Description:
      Generate procedural texture.
      Returns false if protocol extension not initialized or does not support current procedural texture type.
      Arguments:
      pTexture (I) Procedural texture pointer.
      image (O) Output image.
      renderCoef (I) Texture detail multiplier. 1.0 - is most standard device value, 10.0 - for normal rendering.
                     This value can be calculated from raster resolution.
    */
    virtual bool generateProceduralTexture(OdGiProceduralTexturePtr pTexture,
                                           OdGiImageBGRA32 &image, double renderCoef = 1.0) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiProceduralGeneratorPE object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiProceduralGeneratorPE> OdGiProceduralGeneratorPEPtr;

/** Description:
    Color gradient generator.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiGradientGenerator
{
  public:
    /** Description:
        Type of color interpolation function (linear, exponential, inverted exponential, cosine).
    */
    enum InterpolationType
    {
      kLinearInterpolation = 0,
      kExpInterpolation,
      kInvExpInterpolation,
      kCosInterpolation
    };
    /** Description:
        Color interval addressing mode.
		Remarks:
        kClampMode Clamp color address coordinates to the [0.0, 1.0] range.
        kWrapMode Repeat color address on every integer junction.
    */
    enum AddressMode
    {
      kClampMode = 0,
      kWrapMode
    };
  protected:
    OdUInt32Array m_colorGradient;
    AddressMode m_addressMode;
  public:
    OdGiGradientGenerator();
    OdGiGradientGenerator(const OdGiGradientGenerator &other);
    ~OdGiGradientGenerator();

    /** Description:
      Create gradient colors array, filled with black color.
      Arguments:
      nColors (I) Count of colors in gradient array.
    */
    void createColorArray(OdUInt32 nColors);
    /** Description:
      Create gradient colors array, filled with specified color.
      Arguments:
      color (I) Color for all elements in array.
      nColors (I) Count of colors in gradient array.
    */
    void createColorArrayFilled(ODCOLORREF color, OdUInt32 nColors);
    /** Description:
      Create gradient colors array from other colors array.
      Arguments:
      other (I) Input colors array for copy from.
    */
    void copyGradient(const OdUInt32Array &other);
    /** Description:
      Create gradient colors array from other colors array.
      Arguments:
      colors (I) Linear array of colors.
      nColors (I) Count of colors in *colors* linear array.
    */
    void copyGradient(const ODCOLORREF *colors, OdUInt32 nColors);
    /** Description:
      Create gradient from two input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl (I) Interpolation function.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation);
    /** Description:
      Create gradient from three input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      color3 (I) Third color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl (I) Interpolation function.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, ODCOLORREF color3, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation);
    /** Description:
      Create gradient from three input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      color3 (I) Third color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl1 (I) Interpolation function for interval between *color1* and *color2*.
      ipl2 (I) Interpolation function for interval between *color2* and *color3*.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, ODCOLORREF color3, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl1, OdGiGradientGenerator::InterpolationType ipl2);
    /** Description:
      Create gradient from four input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      color3 (I) Third color.
      color4 (I) Four color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl (I) Interpolation function.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, ODCOLORREF color3, ODCOLORREF color4, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation);
    /** Description:
      Create gradient from four input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      color3 (I) Third color.
      color4 (I) Fourth color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl1 (I) Interpolation function for interval between *color1* and *color2*.
      ipl2 (I) Interpolation function for interval between *color2* and *color3*.
      ipl3 (I) Interpolation function for interval between *color3* and *color4*.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, ODCOLORREF color3, ODCOLORREF color4, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl1, OdGiGradientGenerator::InterpolationType ipl2,
                        OdGiGradientGenerator::InterpolationType ipl3);
    /** Description:
      Create gradient from five input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      color3 (I) Third color.
      color4 (I) Fourth color.
      color5 (I) Fifth color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl (I) Interpolation function.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, ODCOLORREF color3, ODCOLORREF color4, ODCOLORREF color5, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation);
    /** Description:
      Create gradient from five input colors.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      color3 (I) Third color.
      color4 (I) Fourth color.
      color5 (I) Fifth color.
      nColors (I) Number of color entries to be created in gradient colors array.
      ipl1 (I) Interpolation function for interval between *color1* and *color2*.
      ipl2 (I) Interpolation function for interval between *color2* and *color3*.
      ipl3 (I) Interpolation function for interval between *color3* and *color4*.
      ipl4 (I) Interpolation function for interval between *color4* and *color5*.
    */
    void createGradient(ODCOLORREF color1, ODCOLORREF color2, ODCOLORREF color3, ODCOLORREF color4, ODCOLORREF color5, OdUInt32 nColors,
                        OdGiGradientGenerator::InterpolationType ipl1, OdGiGradientGenerator::InterpolationType ipl2,
                        OdGiGradientGenerator::InterpolationType ipl3, OdGiGradientGenerator::InterpolationType ipl4);

    /** Description:
      Fill gradient range between *from* and *to*.
      Arguments:
      color (I) Fill color.
      from (I) Start of range for fill.
      to (I) End of range for fill.
    */
    void fillInterval(ODCOLORREF color, double from = 0.0, double to = 1.0);
    /** Description:
      Fill gradient range between *from* and *to*.
      Arguments:
      color (I) Fill color.
      from (I) Start of range for fill.
      to (I) End of range for fill.
    */
    void fillInterval(ODCOLORREF color, OdUInt32 from, OdUInt32 to);
    /** Description:
      Fill range of gradient colors array with another gradient.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      from (I) Start of range for fill.
      to (I) End of range for fill.
      ipl (I) Interpolation function.
    */
    void generateInterval(ODCOLORREF color1, ODCOLORREF color2, double from = 0.0, double to = 1.0,
                          OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation);
    /** Description:
      Fill range of gradient colors array by another gradient.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      from (I) Start of range for fill.
      to (I) End of range for fill.
      ipl (I) Interpolation function.
    */
    void generateInterval(ODCOLORREF color1, ODCOLORREF color2, OdUInt32 from, OdUInt32 to,
                          OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation);

    /** Description:
      Get count of colors in gradient colors array.
    */
    OdUInt32 colorsCount() const;
    /** Description:
      Get color from gradient colors array.
      Arguments:
      nColor (I) Index of color in array.
    */
    ODCOLORREF colorAt(OdUInt32 nColor) const;
    /** Description:
      Get color from gradient colors array.
      Arguments:
      at (I) Color coordinate (0.0 equals 0 in array; 1.0 equals colorsCount() - 1 in array).
    */
    ODCOLORREF colorAt(double at) const;
    /** Description:
      Test whether gradient is initialized.
    */
    bool isInitialized() const;
    /** Description:
      Get reference to array of gradient colors.
    */
    const OdUInt32Array &asArray() const;

    /** Description:
      Set addressing mode.
      Arguments:
      mode (I) New addressing mode.
    */
    void setAddressMode(OdGiGradientGenerator::AddressMode mode);
    /** Description:
      Get addressing mode.
    */
    OdGiGradientGenerator::AddressMode addressMode() const;

    /** Description:
      Interpolate color between *color1* and *color2*.
      Arguments:
      color1 (I) First color.
      color2 (I) Second color.
      at (I) Interpolation coordinate (0.0 - 1.0 for range without additional addressing).
      to (I) End of range for fill.
      ipl (I) Interpolation function.
      mode (I) Addressing mode.
    */
    static ODCOLORREF interpolateColor(ODCOLORREF color1, ODCOLORREF color2, double at,
                                       OdGiGradientGenerator::InterpolationType ipl = OdGiGradientGenerator::kLinearInterpolation,
                                       OdGiGradientGenerator::AddressMode mode = OdGiGradientGenerator::kWrapMode);

    const OdGiGradientGenerator &operator =(const OdGiGradientGenerator &other);

    static OdGiGradientGenerator createSpectrumGradient(OdUInt32 nColors);

    void appendGradient(const OdGiGradientGenerator &other);
    void operator +=(const OdGiGradientGenerator &other);
    friend OdGiGradientGenerator operator +(const OdGiGradientGenerator &g1, const OdGiGradientGenerator &g2);
  protected:
    /** Description:
      *inVal* addressing.
    */
    OdUInt32 clampToRange(OdUInt32 inVal) const;
    /** Description:
      *inVal* addressing.
    */
    OdUInt32 clampToRange(double inVal) const;
    /** Description:
      Convert *inVal* to [0.0 - 1.0] range.
    */
    double toDoubleRange(OdUInt32 inVal) const;

    /** Description:
      Linear interpolation function.
    */
    static double linterp(double a, double b, double t);
    /** Description:
      Exponential interpolation function.
    */
    static double einterp(double a, double b, double t);
    /** Description:
      Cosine interpolation function.
    */
    static double cinterp(double a, double b, double t);
    /** Description:
      Inverted exponential interpolation function.
    */
    static double ieinterp(double a, double b, double t);
};

/** Description:
    Procedural textures generator.

    Library:
    TD_Gi

    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiProceduralGenerator : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiProceduralGenerator);

    // High-level functions

    /** Description:
      Generate procedural texture.
      Returns false if protocol extension not initialized or no support for current procedural texture type.
      Arguments:
      pTexture (I) Procedural texture pointer.
      image (O) Output image.
      renderCoef (I) Texture detail multiplier. 1.0 - most standard device value, 10.0 - normal rendering.
                     This value can be calculated from raster resolution.
    */
    virtual bool generateProceduralTexture(OdGiProceduralTexturePtr pTexture,
                                           OdGiImageBGRA32 &image, double renderCoef = 1.0) = 0;

    /** Description:
      Generate procedural wood texture.
      Arguments:
      color1 (I) First wood texture color.
      color2 (I) Second wood texture color.
      radialNoise (I) Radial noise amount.
      axialNoise (I) Axial noise amount.
      grainThickness (I) Thickness of wood grains.
      image (O) Output image.
      renderCoef (I) Texture detail multiplier. 1.0 - most standard device value, 10.0 - normal rendering.
                     This value can be calculated from raster resolution.
    */
    virtual void generateProceduralWood(OdGiPixelBGRA32 color1, OdGiPixelBGRA32 color2, double radialNoise, double axialNoise, double grainThickness,
                                        OdGiImageBGRA32 &image, double renderCoef = 1.0) = 0;
    /** Description:
      Generate procedural marble texture.
      Arguments:
      veinColor (I) Color of marble veins.
      veinSpacing (I) Distance between veins multiplier.
      veinWidth (I) Marble veins width multiplier.
      image (O) Output image.
      renderCoef (I) Texture detail multiplier. 1.0 - most standard device value, 10.0 - normal rendering.
                     This value can be calculated from raster resolution.
    */
    virtual void generateProceduralMarble(OdGiPixelBGRA32 stoneColor, OdGiPixelBGRA32 veinColor, double veinSpacing, double veinWidth,
                                          OdGiImageBGRA32 &image, double renderCoef = 1.0) = 0;

    // Low-level functions

    /** Description:
      Set color gradient. 
	  
	  Remarks:
	  If gradient is not set up, it will be generated in generateProceduralXXX
      functions. This function may be called before a generateProceduralXXX call for changing palettes
      in procedural texture generation.
    */
    virtual void setColorGradient(const OdGiGradientGenerator &gradient) = 0;
    /** Description:
      Get color gradient.
    */
    virtual const OdGiGradientGenerator &colorGradient() const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGiProceduralGenerator object pointers.
		
	{group:Type Definitions}
*/
typedef OdSmartPtr<OdGiProceduralGenerator> OdGiProceduralGeneratorPtr;

#include "TD_PackPop.h"

#endif // __ODGIPROCEDURALGENERATOR_H__
