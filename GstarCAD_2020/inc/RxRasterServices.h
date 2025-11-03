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


// RasterModule.h - interface of module, performing different operations on raster images

#ifndef __OD_RASTER_MODULE__
#define __OD_RASTER_MODULE__

#include "RxModule.h"
#include "DbRootExport.h"

class OdGiRasterImage;
typedef OdSmartPtr<OdGiRasterImage> OdGiRasterImagePtr;

#include "TD_PackPush.h"

/** Description:
    This class is the base class for classes that provide platform-dependent loading and saving
    of Raster Image files for Teigha.
    Library: TD_Db
    {group:OdRx_Classes} 
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRxRasterServices : public OdRxModule
{
public:
  enum ImageType
  {
    kUnknown  = -1,
    kBMP      = 0,
    kICO      = 1,
    kJPEG     = 2,
    kJNG      = 3,
    kKOALA    = 4,
    kLBM      = 5,
    kIFF      = kLBM,
    kMNG      = 6,
    kPBM      = 7,
    kPBMRAW   = 8,
    kPCD      = 9,
    kPCX      = 10,
    kPGM      = 11,
    kPGMRAW   = 12,
    kPNG      = 13,
    kPPM      = 14,
    kPPMRAW   = 15,
    kRAS      = 16,
    kTARGA    = 17,
    kTIFF     = 18,
    kWBMP     = 19,
    kPSD      = 20,
    kCUT      = 21,
    kXBM      = 22,
    kXPM      = 23,
    kDDS      = 24,
    kGIF      = 25,
    kHDR      = 26,
    kFAXG3    = 27,
    kSGI      = 28,
    kEXR      = 29,
    kJ2K      = 30,
    kJP2      = 31,
    kPFM      = 32,
    kPICT     = 33,
    kRAW      = 34,

    kEmbeddedTiff
  }; 

  ODRX_DECLARE_MEMBERS(OdRxRasterServices);
  /** Description:
      Loads the specified Raster Image file. 
      Arguments:
      filename (I) Filename of the Raster Image file to be read.
      pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.
      
      Remarks:
      The returned pointer is expected to be passed to OdGiViewportGeometry::rasterImageDc().
  */
  virtual OdGiRasterImagePtr loadRasterImage(const OdString &filename) = 0;
  virtual OdGiRasterImagePtr loadRasterImage(OdStreamBuf *pStreamBuf) = 0;

  virtual OdGiRasterImagePtr createFromHBITMAP(HBITMAP hbmp, HPALETTE hpall = 0, bool bTransparency = false) = 0;

  /** Description:
      Saves specified Raster Image to the specified file.
      Arguments:
      rasterImage (I) Raster image to be saved.
      filename (I) Filename of the Raster Image file to be written.
      transparentColor (I) Palette index of transparent color.
  */
  virtual bool saveRasterImage( const OdGiRasterImage* rasterImage, 
    const OdString& filename, int transparentColor = -1 ) = 0;

  /** Description:
      Try to convert raster image (RGB) to JPEG or other type
  */
  virtual bool convertRasterImage( OdGiRasterImagePtr pRaster, OdRxRasterServices::ImageType type, OdStreamBuf* pStreamBuf) = 0;

  /** Description:
      Try to convert raster image to other type
  */
  virtual bool convertRasterImage(
    OdStreamBuf* pSrcStream,
    OdStreamBuf* pDstStream,
    OdRxRasterServices::ImageType type) = 0;
};

typedef OdSmartPtr<OdRxRasterServices> OdRxRasterServicesPtr;

#define RX_RASTER_SERVICES_APPNAME OD_T("RxRasterServices")

#include "TD_PackPop.h"

#endif // __OD_RASTER_MODULE__
