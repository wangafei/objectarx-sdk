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




#ifndef __IMGVARS_H
#define __IMGVARS_H /* {Secret} */

#include "TD_PackPush.h"

class OdDbRasterVariables;

#include "DbRasterImageDef.h"

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRasterVariables object pointers.
*/
typedef OdSmartPtr<OdDbRasterVariables> OdDbRasterVariablesPtr;

/** Description:
    This class represents RasterVariables objects in an OdDbDatabase instance.
    
    Library:
    TD_Db
   
    Remarks:
    RasterVariables objects contain settings applicable to raster images.   
    A single instance of this class is stored with every OdDbDatabase that contains raster images.
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbRasterVariables : public OdDbObject
{
public:  
  
  ODDB_DECLARE_MEMBERS(OdDbRasterVariables);
  static OdDbRasterVariables* create();
  OdDbRasterVariables();
  virtual  ~OdDbRasterVariables();
  
  static ClassVersion classVersion();
  
  enum FrameSettings
  {
    kImageFrameInvalid  = -1, // Invalid
    kImageFrameOff      = 0,  // Frame is off
    kImageFrameAbove    = 1,  // Frame is above the image
    kImageFrameBelow    = 2,  // Frame is below the image
    kImageFrameOnNoPlot = 3   // New in R24 (AC24 support)
  };

  enum ImageQuality
  {
    kImageQualityInvalid  = -1, // Invalid
    kImageQualityDraft    = 0,  // Draft quality
    kImageQualityHigh     = 1   // High quality
  };
    
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields
    (OdDbDxfFiler* pFiler) const;
  
  /** Description:
    Returns the image frame display (DXF 70).
    
    Remarks:
    imageFrame() returns one of the following:
    
    @table
    Name                  Value   Description
    kImageFrameInvalid    -1      Invalid
    kImageFrameOff        0       Frame is off
    kImageFrameAbove      1       Frame is above the image
    kImageFrameBelow      2       Frame is below the image
    
  */
  virtual FrameSettings imageFrame() const;

  /** Description:
    Sets the image frame display (DXF 70).
    
    Arguments:
    imageFrame (I) Image frame display.

    Remarks:
    imageFrame must be one of the following:
    
    @table
    Name                  Value   Description
    kImageFrameOff        0       Frame is off
    kImageFrameAbove      1       Frame is above the image
    kImageFrameBelow      2       Frame is below the image
  */
  virtual OdResult setImageFrame( 
    FrameSettings imageFrame );

  /** Description:
    Returns the image display quality (DXF 71).

    Remarks:
    imageQuality() returns one of the following:
    
    @table
    Name                    Value   Description
    kImageQualityInvalid    -1      Invalid
    kImageQualityDraft       0      Draft quality
    kImageQualityHigh        1      High quality
  */
  virtual ImageQuality imageQuality() const;

  /** Description:
    Sets the image display quality (DXF 71).
    Arguments:
    imageQuality (I) Image Quality.

    Remarks:
    imageQuality must be one of the following:
    
    @table
    Name                    Value   Description
    kImageQualityInvalid    -1      Invalid
    kImageQualityDraft       0      Draft quality
    kImageQualityHigh        1      High quality
  */
  virtual OdResult setImageQuality(
    ImageQuality imageQuality );
  
  /** Description:
    Returns the real-world *units* corresponding to drawing units (DXF 72).

    Remarks:
    units() returns one of the following:
    
    @table
    Name                                 Value
    OdDbRasterImageDef::kNone            0 
    OdDbRasterImageDef::kMillimeter      1 
    OdDbRasterImageDef::kCentimeter      2 
    OdDbRasterImageDef::kMeter           3 
    OdDbRasterImageDef::kKilometer       4 
    OdDbRasterImageDef::kInch            5 
    OdDbRasterImageDef::kFoot            6 
    OdDbRasterImageDef::kYard            7 
    OdDbRasterImageDef::kMile            8 
    OdDbRasterImageDef::kMicroinches     9 
    OdDbRasterImageDef::kMils            10 
    OdDbRasterImageDef::kAngstroms       11 
    OdDbRasterImageDef::kNanometers      12 
    OdDbRasterImageDef::kMicrons         13 
    OdDbRasterImageDef::kDecimeters      14 
    OdDbRasterImageDef::kDekameters      15 
    OdDbRasterImageDef::kHectometers     16 
    OdDbRasterImageDef::kGigameters      17 
    OdDbRasterImageDef::kAstronomical    18 
    OdDbRasterImageDef::kLightYears      19 
    OdDbRasterImageDef::kParsecs         20
  */
  virtual OdDbRasterImageDef::Units userScale() const;

  /** Description:
    Specifies the real-world *units* corresponding to drawing units  (DXF 72).
    
    Arguments:
    units (I) Real-world *units*.
    
    Remarks:
    units must be one of the following:
    
    @table
    Name                                 Value
    OdDbRasterImageDef::kNone            0 
    OdDbRasterImageDef::kMillimeter      1 
    OdDbRasterImageDef::kCentimeter      2 
    OdDbRasterImageDef::kMeter           3 
    OdDbRasterImageDef::kKilometer       4 
    OdDbRasterImageDef::kInch            5 
    OdDbRasterImageDef::kFoot            6 
    OdDbRasterImageDef::kYard            7 
    OdDbRasterImageDef::kMile            8 
    OdDbRasterImageDef::kMicroinches     9 
    OdDbRasterImageDef::kMils            10 
    OdDbRasterImageDef::kAngstroms       11 
    OdDbRasterImageDef::kNanometers      12 
    OdDbRasterImageDef::kMicrons         13 
    OdDbRasterImageDef::kDecimeters      14 
    OdDbRasterImageDef::kDekameters      15 
    OdDbRasterImageDef::kHectometers     16 
    OdDbRasterImageDef::kGigameters      17 
    OdDbRasterImageDef::kAstronomical    18 
    OdDbRasterImageDef::kLightYears      19 
    OdDbRasterImageDef::kParsecs         20
  */
  virtual OdResult setUserScale(
    OdDbRasterImageDef::Units units);
  
  /** Description:
    Opens the RasterVariables object in the specified *database*.
    
    Arguments:
    openMode (I) Mode in which to open the RasterVariables object.
    pDb (I) Pointer to the *database* containg the RasterVariables object.


    Remarks:
    Returns a SmartPointer to the RasterVariables object.

    Creates a RasterVariables object if one does not exist.
  */
  static OdDbRasterVariablesPtr openRasterVariables(
    OdDbDatabase* pDb,
    OdDb::OpenMode openMode = OdDb::kForRead);
  static OdDbRasterVariables* openRasterVariables(
    OdDb::OpenMode mode,
    OdDbDatabase* pDatabase = 0);

  TOOLKIT_EXPORT_STATIC static const OdChar* szRasterVariablesDictName; // "ACAD_IMAGE_VARS"
};


#include "TD_PackPop.h"

#endif // __IMGVARS_H

