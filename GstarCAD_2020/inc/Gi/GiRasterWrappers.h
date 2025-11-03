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

#ifndef __OD_GI_RASTER_WRAPPERS__
#define __OD_GI_RASTER_WRAPPERS__

#include "../Gi/GiExport.h"
#include "../Gi/GiRasterImage.h"
#include "../Gi/GiImage.h"

#include "../TD_PackPush.h"

/** Description:
    This class is a dummy implementation of the OdGiRasterImage interface.

    Remarks:
    This class is intended to be used to preset image parameters for 
    OdDbRasterImageDef objects without the actual loading of raster image files.

    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiRasterImageDesc : public OdGiRasterImageParam
{
  OdUInt32                          m_pixelWidth, m_pixelHeight, m_colorDepth, m_palSize, m_alignment;
  OdGiRasterImage::PixelFormatInfo  m_pixFmt;
  Units                             m_units;
  double                            m_xPelsPerUnut, m_yPelsPerUnut;
  OdUInt8*                          m_pPal;
  OdGiRasterImage::ImageSource      m_imageSource;
  OdGiRasterImage::TransparencyMode m_transparencyMode;

public:
  OdGiRasterImageDesc();
  virtual ~OdGiRasterImageDesc();
  
  /** Description:
    Creates an OdGiRasterImage object with the specified parameters. 
    Arguments:
    pixelWidth (I) Image width in pixels.
    pixelHeight (I) Image height in pixels.
    units (I) *Units* / pixel.
    xPelsPerUnit (I) Pixels per unit value ( *x* direction ).
    yPelsPerUnit (I) Pixels per unit value ( *y* direction ).
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  static OdGiRasterImagePtr createObject(OdUInt32 pixelWidth, OdUInt32 pixelHeight, Units units = kNone, double xPelsPerUnit = 0.0, double yPelsPerUnit = 0.0);

  //DD2ARX - Li CC - 2008-06-13 - OdRxObject::clone
  virtual OdRxObject* clone() const;
  OdResult copyFrom(const OdRxObject *pSource);
  
  OdUInt32 pixelWidth() const;
  OdUInt32 pixelHeight() const;
  OdUInt32 colorDepth() const;
  OdUInt32 numColors() const;
  ODCOLORREF color(OdUInt32 colorIndex) const;
  OdUInt32 paletteDataSize() const;
  void paletteData(OdUInt8* bytes) const;
  OdUInt32 scanLineSize() const;
  const OdUInt8* scanLines() const;
  void scanLines(OdUInt8* scnLines, OdUInt32 firstScanline, OdUInt32 numLines = 1) const;
  PixelFormatInfo pixelFormat() const;
  OdUInt32 scanLinesAlignment() const;
  Units defaultResolution(double& xPelsPerUnit, double& yPelsPerUnit) const;

  /** Description:
    Sets the image width in pixels of this RasterImageDesc object.
    Arguments:
    pixelWidth (I) Pixel width.
  */
  void setPixelWidth(OdUInt32 pixelWidth);
  /** Description:
    Sets the image height in pixels of this RasterImageDesc object.
    Arguments:
    pixelHeight (I) Pixel height.
  */
  void setPixelHeight(OdUInt32 pixelHeight);

  /** Description:
    Setes the number of bits per pixel used for colors by this RasterImageDesc object.
    Arguments:
    colorDepth (I) Color depth.
  */
  void setColorDepth(OdUInt32 colorDepth);

  OdGiRasterImage::PixelFormatInfo& pixelFormat();

  /** Description:
    Sets the palette in BMP format for this RasterImageDesc object.
    Arguments:
    paletteData (I) Palette data.
    paletteSize (I) Palette size in bytes.
  */
  void setPalette(OdUInt32 paletteSize, OdUInt8* paletteData);
  /** Description:
    Sets the scan lines *alignment*, in bytes, for this RasterImage object.
    Arguments:
    alignment (I) Scan line *alignment*.
    Example:
    Alignment is 4 for Windows BMP.
  */
  void setScanLinesAlignment(OdUInt32 alignment);

  OdUInt32 supportedParams() const;
  OdGiRasterImage::ImageSource imageSource() const;
  void setImageSource(OdGiRasterImage::ImageSource source);
  OdGiRasterImage::TransparencyMode transparencyMode() const;
  void setTransparencyMode(OdGiRasterImage::TransparencyMode mode);
};

class OdGiImageBGRA32;

/** Description:
    Emulates OdGiImageBGRA32 within OdGiRasterImage interface.
    Remarks:
    Stores only pointer to original image, not a SmartPointer, so deletion of original image before
    this class may cause access violation error.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiRasterImageBGRA32 : public OdGiRasterImageParam
{
  friend class OdGiRasterImageBGRA32Copy;
protected:
  const OdGiImageBGRA32 *m_pBGRAImage;
  OdGiRasterImage::TransparencyMode m_transparencyMode;

public:
  OdGiRasterImageBGRA32();
  virtual ~OdGiRasterImageBGRA32();
  
  /** Description:
    Creates an OdGiRasterImage object with the specified parameters.
    Arguments:
    pImage (I) Input BGRA32 image.
    transparencyMode (I) Transparency mode.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  static OdGiRasterImagePtr createObject(const OdGiImageBGRA32 *pImage, OdGiRasterImage::TransparencyMode transparencyMode = OdGiRasterImage::kTransparency8Bit);

  OdUInt32 pixelWidth() const;
  OdUInt32 pixelHeight() const;
  OdUInt32 colorDepth() const;
  OdUInt32 numColors() const;
  ODCOLORREF color(OdUInt32 colorIndex) const;
  OdUInt32 paletteDataSize() const;
  void paletteData(OdUInt8* bytes) const;
  OdUInt32 scanLineSize() const;
  const OdUInt8* scanLines() const;
  void scanLines(OdUInt8* scnLines, OdUInt32 firstScanline, OdUInt32 numLines = 1) const;
  OdGiRasterImage::PixelFormatInfo pixelFormat() const;
  OdUInt32 scanLinesAlignment() const;
  OdGiRasterImage::Units defaultResolution(double& xPelsPerUnit, double& yPelsPerUnit) const;
  OdUInt32 supportedParams() const;
  OdGiRasterImage::ImageSource imageSource() const;
  OdGiRasterImage::TransparencyMode transparencyMode() const;
  void setTransparencyMode(OdGiRasterImage::TransparencyMode mode);

  virtual OdRxObject* clone() const;
  OdResult copyFrom(const OdRxObject *pSource);
};

/** Description:
    Extends OdGiRasterImageBGRA32 class to keep a copy of OdGiImageBGRA32 inside.
    Library: TD_Gi
    {group:OdGi_Classes}
*/
class ODGI_EXPORT OdGiRasterImageBGRA32Copy : public OdGiRasterImageBGRA32
{
private:
  OdGiImageBGRA32 m_ImageCopy;
  OdGiPixelBGRA32Array m_pxArray;
public:
  OdGiRasterImageBGRA32Copy();
  ~OdGiRasterImageBGRA32Copy();
  
  /** Description:
    Creates an OdGiRasterImage object with the specified parameters.
    Arguments:
    pImage (I) Input BGRA32 image.
    transparencyMode (I) Transparency mode.
    Remarks:
    Returns a SmartPointer to the newly created object.
  */
  static OdGiRasterImagePtr createObject(const OdGiImageBGRA32 *pImage, OdGiRasterImage::TransparencyMode transparencyMode = OdGiRasterImage::kTransparency8Bit);
  static OdGiRasterImagePtr createObject(const OdGiRasterImageBGRA32 *pImage);

  virtual OdRxObject* clone() const;
  OdResult copyFrom(const OdRxObject *pSource);
};

/** Description:
    This class is the base class for raster image transformer objects. 
        
    Library: TD_Gi
    
    Remarks:
    Transforming an image does not effect the orignal.
    
    The default methods for this class do nothing but return the
    corresponding values from the original object.

    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiRasterImageWrapper : public OdGiRasterImageParam
{
  OdGiRasterImagePtr m_pOrig;
public: 
  OdGiRasterImageWrapper();
  virtual ~OdGiRasterImageWrapper();
  /** Description:
    Sets the original OdGiRasterImage object associated with this RasterImageWrapper object.
    Arguments:
    pOrig (I) Pointer to the original image object.
  */
  void setOriginal(const OdGiRasterImage* pOrig);
  const OdGiRasterImage *original() const;
  OdGiRasterImagePtr cloneOriginal() const;

  OdUInt32 pixelWidth() const;
  OdUInt32 pixelHeight() const;
  Units defaultResolution(double& xPelsPerUnit, double& yPelsPerUnit) const;
  OdUInt32 colorDepth() const;
  OdUInt32 numColors() const;
  ODCOLORREF color(OdUInt32 colorIndex) const;
  OdUInt32 paletteDataSize() const;
  void paletteData(OdUInt8* bytes) const;
  OdUInt32 scanLineSize() const;
  void scanLines(OdUInt8* scnLines, OdUInt32 firstScanline, OdUInt32 numLines = 1) const;
  const OdUInt8* scanLines() const;
  PixelFormatInfo pixelFormat() const;
  OdUInt32 scanLinesAlignment() const;
  int transparentColor() const;
  ImageSource imageSource() const;
  TransparencyMode transparencyMode() const;
  OdUInt32 supportedParams() const;
  void setImageSource(ImageSource source);
  void setTransparencyMode(TransparencyMode mode);

  virtual OdRxObject* clone() const;
  OdResult copyFrom(const OdRxObject *pSource);
};

/** Description:
    This raster image transformer class transforms OdGiRasterImage objects to Bitonal images.
    
    Library: TD_Gi

    Remarks:
    Transforming an image does not effect the orignal.

    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiBitonalRasterTransformer : public OdGiRasterImageWrapper
{
  RGBQUAD m_palette[2];
  int m_transpColor;
public:
  OdGiBitonalRasterTransformer();
  virtual ~OdGiBitonalRasterTransformer();
  /**
    Arguments:
    foregroundColor (I) Foreground *color*.
    backgroundColor (I) Background *color*.
    transparent (I) Image is transparent if and only if true.
  */
  void setOriginal(const OdGiRasterImage* pOrig, ODCOLORREF foregroundColor, ODCOLORREF backgroundColor, bool transparent);
  OdUInt32 numColors() const;
  ODCOLORREF color(OdUInt32 colorIndex) const;
  OdUInt32 paletteDataSize() const;
  void paletteData(OdUInt8* bytes) const;
  PixelFormatInfo pixelFormat() const;
  int transparentColor() const;

  virtual OdRxObject* clone() const;
  OdResult copyFrom(const OdRxObject *pSource);
};

#include "../TD_PackPop.h"

#endif //  __OD_GI_RASTER_WRAPPERS__
