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




#ifndef _OD_ODGIRASTERIMAGE_H_
#define _OD_ODGIRASTERIMAGE_H_

#include "../RxObject.h"
#include "../OdPlatform.h"
#include "../Gi/Gi.h"

class OdGeVector2d;
class OdStreamBuf;

#include "../TD_PackPush.h"

/** Description:
    This class represents a raster image within the Teigha vectorization framework.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiRasterImage : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiRasterImage);

  enum Units
  {
    kNone = 0,
    kMillimeter,
    kCentimeter,
    kMeter,
    kKilometer,
    kInch,
    kFoot,
    kYard,
    kMile,
    kMicroinches,
    kMils,
    kAngstroms,
    kNanometers,
    kMicrons,
    kDecimeters,
    kDekameters,
    kHectometers,
    kGigameters,
    kAstronomical,
    kLightYears,
    kParsecs     
  };

  enum ImageSource
  {
    kUndefinedSource = -1, // Flag not set (unknown source)
    kFromDwg         = 0,  // Raster image loaded from raster image definition
    kFromOleObject   = 1,  // Raster image generated from ole data source
    kFromRender      = 2,  // Raster image generated from rendering

    kFromUnderlay    = 10, // Raster image is part of underlay
    kFromImageBGRA32 = 11, // Raster image wraps OdGiImageBGRA32 image

    // Aliases
    kFromPdfUnderlay = kFromOleObject, // Raster image generated from PdfUnderlay
    kFromFile        = kFromDwg        // Raster image generated from PdfUnderlay
  };

  enum TransparencyMode
  {
    kTransparencyDef  = -1, // Default for native raster image (alpha 0 - transparent, 1-255 opaque)
    kTransparencyOff  = 0,  // Alpha ignored for 32bpp formats
    kTransparency1Bit = 1,  // Alpha 0-254 transparent, 255 opaque
    kTransparency8Bit = 2   // Complete alpha level support for 32bpp formats
  };

  typedef struct tagPixelFormatInfo
  {
    OdUInt8 redOffset;
    OdUInt8 numRedBits;
    OdUInt8 greenOffset;
    OdUInt8 numGreenBits;
    OdUInt8 blueOffset;
    OdUInt8 numBlueBits;
    OdUInt8 alphaOffset;
    OdUInt8 numAlphaBits;
    OdUInt8 bitsPerPixel;

    bool operator ==(const struct tagPixelFormatInfo& other) const
    {
      return (redOffset == other.redOffset) && (greenOffset == other.greenOffset) &&
        (blueOffset == other.blueOffset) && (alphaOffset == other.alphaOffset) && (bitsPerPixel == other.bitsPerPixel) &&
        (numRedBits == other.numRedBits) && (numGreenBits == other.numGreenBits) && (numBlueBits == other.numBlueBits) &&
        (numAlphaBits == other.numAlphaBits);
    }

    tagPixelFormatInfo()
      : redOffset(0)
      , numRedBits(0)
      , greenOffset(0)
      , numGreenBits(0)
      , blueOffset(0)
      , numBlueBits(0)
      , alphaOffset(0)
      , numAlphaBits(0)
      , bitsPerPixel(0)
    {}

    /** Description:
      Returns true if and only if the pixel format of this RasterImage object is RGB.
    */
    bool isRGB() const
    {
      return bitsPerPixel == 24 && 
        redOffset == 0 && greenOffset == 8 && blueOffset == 16 && numRedBits == 8 && numGreenBits == 8 && numBlueBits == 8;
    }

    /** Description:
      Sets the pixel format of this RasterImage object to RGB.
      Note:
      No *palette* conversion is performed.
    */
    void setRGB()
    {
      bitsPerPixel = 24;
      redOffset    = 0;
      greenOffset  = 8;
      blueOffset   = 16;
      numRedBits   = 8;
      numGreenBits = 8;
      numBlueBits  = 8;
    }

    /** Description:
      Returns true if and only if the pixel format of this RasterImage object is BGR.
    */
    bool isBGR() const
    {
      return bitsPerPixel == 24 && 
        redOffset == 16 && greenOffset == 8 && blueOffset == 0 && numRedBits == 8 && numGreenBits == 8 && numBlueBits == 8;
    }

    /** Description:
      Sets the pixel format the pixel format of this RasterImage object to BGR.
      Note:
      No *palette* conversion is performed.
    */
    void setBGR()
    {
      bitsPerPixel = 24;
      redOffset    = 16;
      greenOffset  = 8;
      blueOffset   = 0;
      numRedBits   = 8;
      numGreenBits = 8;
      numBlueBits  = 8;
    }

    /** Description:
      Returns true if and only if the pixel format of this RasterImage object is 16 bit BGR.
    */
    bool is16bitBGR() const
    {
      return bitsPerPixel == 16 && 
        redOffset == 10 && greenOffset == 5 && blueOffset == 0 && numRedBits == 5 && numGreenBits == 5 && numBlueBits == 5;
    }

    /** Description:
      Sets the pixel format of this RasterImage object to 16 bit BGR.
      Note:
      No *palette* conversion is performed.
    */
    void set16bitBGR()
    {
      bitsPerPixel = 16;
      redOffset    = 10;
      greenOffset  = 5;
      blueOffset   = 0;
      numRedBits   = 5;
      numGreenBits = 5;
      numBlueBits  = 5;
    }

    /** Description:
      Returns true if and only if the pixel format of this RasterImage object is RGBA.
    */
    bool isRGBA() const
    {
      return bitsPerPixel == 32 && alphaOffset == 24 && numAlphaBits == 8 &&
        redOffset == 0 && greenOffset == 8 && blueOffset == 16 && numRedBits == 8 && numGreenBits == 8 && numBlueBits == 8;
    }

    /** Description:
      Sets the pixel format of this RasterImage object to RGBA.
      Note:
      No *palette* conversion is performed.
    */
    void setRGBA()
    {
      bitsPerPixel = 32;
      alphaOffset  = 24;
      numAlphaBits = 8;
      redOffset    = 0;
      greenOffset  = 8;
      blueOffset   = 16;
      numRedBits   = 8;
      numGreenBits = 8;
      numBlueBits  = 8;
    }

    /** Description:
      Returns true if and only if the pixel format of this RasterImage object is BGRA.
    */
    bool isBGRA() const
    {
      return bitsPerPixel == 32 && alphaOffset == 24 && numAlphaBits == 8 &&
        redOffset == 16 && greenOffset == 8 && blueOffset == 0 && numRedBits == 8 && numGreenBits == 8 && numBlueBits == 8;
    }

    /** Description:
      Sets the pixel format of this RasterImage object to BGRA.
      Note:
      No *palette* conversion is performed.
    */
    void setBGRA()
    {
      bitsPerPixel = 32;
      alphaOffset  = 24;
      numAlphaBits = 8;
      redOffset    = 16;
      greenOffset  = 8;
      blueOffset   = 0;
      numRedBits   = 8;
      numGreenBits = 8;
      numBlueBits  = 8;
    }
  } PixelFormatInfo;

  /** Description:
    Returns the image width in pixels of this RasterImage object.
  */
  virtual OdUInt32 pixelWidth() const = 0;

  /** Description:
    Returns the image height in pixels of this RasterImage object.
  */
  virtual OdUInt32 pixelHeight() const = 0;

  /** Description:
    Returns the default image resolution in pixels per unit of this RasterImage object.

    Arguments:
    xPelsPerUnit (O) Receives the pixels per unit value (*x* direction).
    yPelsPerUnit (O) Receives the pixels per unit value (*y* direction).

    Remarks:
    If the returned value is kNone, then xPelsPerUnit and yPelsPerUnit are not set.
*/ 
  virtual Units defaultResolution(double& xPelsPerUnit, double& yPelsPerUnit) const;

  /** Description:
    Returns the number of *bits* per pixel used for colors by this RasterImage object.
  */
  virtual OdUInt32 colorDepth() const = 0;

  /** Description:
    Returns the number of colors in the *palette* of this RasterImage object.
  */
  virtual OdUInt32 numColors() const = 0;

  /** Description:
    Returns the index of transparent *color* in the image.
    Remarks:
    If there is no transparent *color*, -1 should be returned.
    
    Note:
    The default implementation of this function returns -1.
  */
  virtual int transparentColor() const;

  /** Description:
    Returns the *color* for the specified index, from the *palette* of this RasterImage object.
    Arguments:
    colorIndex (I) Color index.
  */
  virtual ODCOLORREF color(OdUInt32 colorIndex) const = 0;

  /** Description:
    Returns the size (in bytes) of the *palette* data of this RasterImage object.
  */
  virtual OdUInt32 paletteDataSize() const = 0;

  /** Description:
    Returns the *palette* in BMP format of this RasterImage object.
    Arguments:
    bytes (O) Receives the *palette* data.
    
    Note:
    It is up to the caller to allocate sufficient memory for the *palette* data.
  */
  virtual void paletteData(OdUInt8* bytes) const = 0;

  /** Description:
    Returns the scan line size of this RasterImage object.
    
    Remarks:
    This function returns the number of bytes between the beginning of scan line N and
    the beginning of scan line N+1 (taking into account any padding that is added to the 
    end of the scan line).
  */
  virtual OdUInt32 scanLineSize() const;

  /** Description:
    Returns the specified set of scanlines in BMP format from this RasterImage object,
    or the pixel data in BMP format for this RasterImage object.

    Arguments:
    scnLines (O) Receives the scan line data.
    firstScanline (I) Index of first scanline to retrieve.
    numLines (I) Number of scanlines to retrieve.

    Remarks:

    o The number of accessible scanlines is equal to value returned by pixelHeight().
    o The number of accessible bytes in a scanline is equal to the value returned by scanLineSize().
    o The scanline returned by firstScanline == 0 is the first scanline in the image.
    o The scanline returned by firstScanline == (pixelHeight() - 1) is the last scanline in the image.

    Note:
    It us up to the caller to allocate sufficient memory for the scan line data.

    Note:
    Implementation of this function with no arguments is optional; NULL can be returned 
    if it is inconvenient to implement. The caller must take 
    into account that the return value can be NULL.
  */
  virtual const OdUInt8* scanLines() const = 0;
  virtual void scanLines(OdUInt8* scnLines, OdUInt32 firstScanline, OdUInt32 numLines = 1) const = 0;

  /** Description:
    Returns the pixel format for this RasterImage object.
    
    Note:
    This function returns the pixel format of the *palette*,
    unless there is no *palette*, in which case it returns
    the pixel format of the image itself.
  */
  virtual PixelFormatInfo pixelFormat() const = 0;

  /** Description:
    Returns the scan lines alignment, in bytes, for this RasterImage object.
    Example:
    scanLinesAlignment() returns 4 for Windows BMP.
  */
  virtual OdUInt32 scanLinesAlignment() const = 0;

	virtual void* internalData() const
	{
		return NULL;
	}
  /** Description:
    Returns image source.
  */
  virtual ImageSource imageSource() const;

  /** Description:
    Returns transparency mode for 32bpp formats.
  */
  virtual TransparencyMode transparencyMode() const;

  /** Description:
    Sets image source. Returns image with new image source.
    Arguments:
    source (I) New image source value.
  */
  OdSmartPtr<OdGiRasterImage> changeImageSource(ImageSource source);

  /** Description:
    Sets transparency mode for 32bpp formats. Returns image with new transparency mode.
    Arguments:
    mode (I) New transparency mode.
  */
  OdSmartPtr<OdGiRasterImage> changeTransparencyMode(TransparencyMode mode);

  /** Description:
    Returns the size of a single scan line in BMP format for this RasterImage object.
    Arguments:
    pixelWidth (I) Image width in pixels.
    colorDepth (I) Number of *bits* per pixel.
  */
  static OdUInt32 calcBMPScanLineSize(OdUInt32 pixelWidth, int colorDepth);

  /** Description:
    Converts this raster image as specified.
    Arguments:
    convertPaletteToRGB (I) Color is converted to RGB if and only if true.
    brightness (I) Image *brightness* [0 .. 100].
    fade (I) Image *fade* value [0 .. 100].
    backgroundColor (I) Background *color*.
    flipX (I) Image is flipped about X-axis if and only if true.
    flipY (I) Image is flipped about Y-axis if and only if true.
    rotate90 (I) Image is rotated 90if and only if true.
    pDestDesc (I) Pointer to an OdGiRasterImageDesc object to receive the image parameters.
    transparency (I) Image is transparent if true.
    Remarks:
    Returns a SmartPointer to the converted image.
  */
  OdSmartPtr<OdGiRasterImage> convert(bool convertPaletteToRGB,
    double brightness = 50.0, double contrast = 50.0, double fade = 0.0, ODCOLORREF backgroundColor = 0,
    bool flipX = false, bool flipY = false, bool rotate90 = false,
    const OdGiRasterImage* pDestDesc = 0,
    bool transparency = false) const;

  /** Description:
    Crops this raster image by rectangle.
    The format of returned raster image is identical to format of source raster image
    Arguments:
    x      (I) X-coordinate of start point
    y      (I) Y-coordinate of start point
    width  (I) Width of the crop rectangle
    height (I) Height of the crop rectangle
    All arguments are in pixels
  */
  OdSmartPtr<OdGiRasterImage> crop(OdUInt32 x, OdUInt32 y, OdUInt32 width, OdUInt32 height) const;
  virtual bool CreateFromHBITMAP(HBITMAP hbmp, HPALETTE hpall = 0, bool bTransparency = false){return false;}
  virtual HBITMAP acquireRGBBitmap(int w, int h, bool alpha,COLORREF foreColor,COLORREF bkColor) {return NULL;}
};

typedef OdSmartPtr<OdGiRasterImage> OdGiRasterImagePtr;

/** Description:
    This interface simply extends GiRasterImage to set image source and transparency mode values.
    If raster image could be casted to this interface, values will be setted within this interface,
    elsewhere raster image wrapper will be created to reset this values.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class FIRSTDLL_EXPORT OdGiRasterImageParam : public OdGiRasterImage
{
public:
  ODRX_DECLARE_MEMBERS(OdGiRasterImageParam);

  enum ParamType
  {
    kImageSource      = (1 << 0),
    kTransparencyMode = (1 << 1)
  };

  /** Description:
    Returns ParamType bitflags with which parameters are supported by this interface.
  */
  virtual OdUInt32 supportedParams() const = 0;

  /** Description:
    Sets image source.
    Arguments:
    source (I) New image source value.
  */
  virtual void setImageSource(ImageSource source) { }

  /** Description:
    Sets image transparency mode.
    Arguments:
    mode (I) New transparency mode value.
  */
  virtual void setTransparencyMode(TransparencyMode mode) { }


};

typedef OdSmartPtr<OdGiRasterImageParam> OdGiRasterImageParamPtr;

#include "../TD_PackPop.h"

#endif //#ifndef _OD_ODGIRASTERIMAGE_H_
