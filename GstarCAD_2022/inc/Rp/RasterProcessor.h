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


#ifndef _OD_ODRASTERPROCESSOR_H_
#define _OD_ODRASTERPROCESSOR_H_

#include "../RxObject.h"
#include "../RxModule.h"
#include "../Gi/GiRasterImage.h"

#include "../TD_PackPush.h"

/** Description:
    This class is the Raster Converter Protocol Extension class.
    Library: RasterProcessor
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdRasterConvertPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdRasterConvertPE);

  /** Description:
    This function applies the specified raster conversions to the specified RasterImage object.

    Remarks:
    These conversions include filtering, flips, resampling, resizing, rotations, and trimming.
    
    Arguments:
    pOrig (I) Pointer to the original image.
    convertPaletteToRGB (I) Convert palette to RGB.
    brightness (I) Brightness. [0.0 .. 100.0].
    contrast (I) Contrast. [0.0 .. 100.0].
    fade (I) Fade. [0.0 .. 100.0].
    backgroundColor (I) Background color.
    flipX (I) Flip along the X-axis.
    flipY (I) Flip along the Y-axis.
    rotate90 (I) Rotate 90CCW.
    pDestDesc (I) Pointer to the destination image description..
    transparency (I) Make transparent.
    
  */
  virtual OdGiRasterImagePtr convertImage(
    const OdGiRasterImage* pOrig,
    bool convertPaletteToRGB,
    double brightness = 50.0, double contrast = 50.0, double fade = 0.0, ODCOLORREF backgroundColor = 0,
    bool flipX = false, bool flipY = false, bool rotate90 = false,
    const OdGiRasterImage* pDestDesc = 0,
    bool transparency = false) = 0;

  /** Description:
    Brightness, contrast, fade adjustments behaviour.

    Remarks:
    kDwgBehaviour is default state for adjustments behaviour.
  */
  enum AdjustmentsBehaviour
  {
    kDwgBehaviour = 0,
    kDgnBehaviour = 1
  };

  /** Description:
    Setup adjustments behaviour for next *convertImage* calls.

    Arguments:
    newBehaviour (I) new adjustments behaviour state.
  */
  virtual void setAdjustmentsBehaviour(AdjustmentsBehaviour newBehaviour) = 0;

  /** Description:
    Returns current adjustments behaviour state.
  */
  virtual AdjustmentsBehaviour adjustmentsBehaviour() const = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdRasterConvertPE object pointers.
*/
typedef OdSmartPtr<OdRasterConvertPE> OdRasterConvertPEPtr;

/** Description:
    This class is the base class for classes that provide platform-dependent raster processing services for Teigha.

    Library: RasterProcessor
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdRasterProcessingServices : public OdRxModule
{
public:
  ODRX_DECLARE_MEMBERS(OdRasterProcessingServices);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdRasterProcessingServices object pointers.
*/
typedef OdSmartPtr<OdRasterProcessingServices> OdRasterProcessingServicesPtr;

#define ODRP_RASTERPROCESSING_SERVICES_APPNAME L"RasterProcessingServices"

#include "../TD_PackPop.h"

#endif //#ifndef _OD_ODRASTERPROCESSOR_H_
