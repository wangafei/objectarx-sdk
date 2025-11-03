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



#ifndef OD_AVEDEFS_H
#define OD_AVEDEFS_H

#include "../Ve/AveExport.h"
#include "../OdString.h"
#include "../RxIterator.h"

/** Description:

    {group:TD_Namespaces}
*/
namespace OdAve
{
  enum MaterialType
  {
    kStandard     = 0,
    kGranite      = 1,
    kMarble       = 2,
    kWood         = 3
  };

  enum MaterialAttrib
  {
    kAmbient        = 0x1,  
    kDiffuse        = 0x2,  
    kSpecular       = 0x4,  
    kTransparency   = 0x8,  
    kRoughness      = 0x20, 
    kBumpMap        = 0x40, 
    kReflectionProp = 0x100,
    kRefraction     = 0x200
  };

  enum RenderType
  {
    kRndSimple      = 30,
    kRndPhotoReal   = 50,
    kRndRaytrace    = 60
  };

  enum RenderDestination
  {
    kDestViewport   = 20,
    kDestWindow     = 30,
    kDestFile       = 40
  };

  enum RenderQuality
  {
    kGouraud        = 0,
    kPhong          = 1
  };

  enum AntiAliasing
  {
    kAntiAliasNone      = 1,
    kAntiAliasMinimal   = 2,
    kAntiAliasLow       = 3,
    kAntiAliasMedium    = 4,
    kAntiAliasHigh      = 5
  };

  enum TextureMapSampling
  {
    kTMapSampPoint    = 1,
    kTMapSampLinear   = 2,
    kTMapSampMipMap   = 3
  };

  enum BackgroundType
  {
    kBackgroundSolid      = 0,
    kBackgroundGradient   = 1,
    kBackgroundImage      = 2,
    kBackgroundMerge      = 3
  };

  enum OptionType
  {
    kRndPref              = 0,
    kRndFullOpt           = 1,
    kRndQuickOpt          = 2,
    kRndScanlOpt          = 3,
    kRndRaytrOpt          = 4, 
    kRndRFileOpt          = 5,
    kRndFogOpt            = 6,
    kRndBGOpt             = 7,  
    kRndOptAmount         = 8
  };

  enum ProjectionMethod
  {
    kPlanar               = 1,
    kBox                  = 2,
    kCylinder             = 3,
    kSphere               = 4
  };

  enum TileMethod
  {
    kTmDefault    = 0, // Tiling as set for the material.
    kTmTile       = 1, // Tiled.
    kTmCrop       = 2, // Cropped.
    kTmClamp      = 3  // Clamped.
  };

  enum SetuvType
  {
    kSetuvPlanar      = 1,
    kSetuvCylindrical = 2,
    kSetuvSpherical   = 3,
    kSetuvSolid       = 6
  };
}

/** Description:
    This class is the base class for AVE Bitmap objects.
    
    Library: TD_Ave
    {group:OdAve_Classes}
*/
class AVE_EXPORT OdAveBitmap
{
public:
  virtual ~OdAveBitmap() {}

  /** Description:
    Returns the blend factor for this Bitmap object.

    Remarks:
    Returns a value in the range [0.0 .. 1.0]

    A blend factor of 0.0 makes the Bitmap invisible. A blend factor of 1.0 makes it opaque.
    In between, the Bitmap is transparent.
  */
  virtual double blendFactor() = 0;
  
  /** Description:
    Sets the *source* *filename* of this Bitmap object.

    Remarks:
    filename (O) Receives the *filename*.
  */
  virtual void source(OdString& filename) = 0;
  
  /** Description:
    Returns the scale of this Bitmap object in the U-direction.
    
    Remarks:
    This is the number of repetitions of this Bitmap object in the specified direction.
  */
  virtual double scaleU() = 0;
  /** Description:
    Returns the scale of this Bitmap object in the V-direction.
    
    Remarks:
    This is the number of repetitions of this Bitmap object in the specified direction.
  */
  virtual double scaleV() = 0;
  /** Description:
    Returns the offset of this Bitmap object in the U-direction.
    Remarks:
    Returns a value in the range [-1.0 .. 1.0].
  */
  virtual double offsetU() = 0;
  /** Description:
    Returns the offset of this Bitmap object in the V-direction.
    Remarks:
    Returns a value in the range [-1.0 .. 1.0].
  */
  virtual double offsetV() = 0;
  /** Description:
    Returns the tile method of this Bitmap object.
    Remarks:
    Returns one of the following:
    
    @table
    Name          Value   Description
    kTmDefault    0       Tiling as set for the material.
    kTmTile       1       Tiled.
    kTmCrop       2       Cropped.
    kTmClamp      3       Clamped.
  */
  virtual OdAve::TileMethod tileMethod() = 0;
  /** Description:
    Returns true if and only if this Bitmap object uses Auto Axis.
    Remarks:
    AutoAxis automatically maps materials to surfaces 
    whose normals are the X, Y, and Z axes.
    
    If AutoAxis is not used, only surfaces whose normal is the Z axis are mapped.
  */
  virtual bool useAutoAxis() = 0;
  /** Description:
    Returns true if and only if this Bitmap object is automatically scaled
    to the object to which this bitmap is attached.
  */
  virtual bool fitToObject() = 0;

  /** Description:
    Sets the blend factor for this Bitmap object.
    Arguments:
    blendFactor (I) Blend factor. [0.0 .. 1.0]
    Remarks:
    A blend factor of 0.0 makes the Bitmap invisible. A blend factor of 1.0 makes it opaque.
    In between, the Bitmap is transparent.
  */
  virtual void setBlendFactor(double blendFactor) = 0;
  /** Description:
    Returns the *source* *filename* of this Bitmap object.

    Remarks:
    filename (I) Filename.
  */
  virtual void setSource(const OdString& filename) = 0;
  /** Description:
    Sets the scale of this Bitmap object in the U-direction.
    Arguments:
    scaleU (I) Scale in U-direction.
    Remarks:
    This is the number of repetitions of this Bitmap object in the specified direction.
  */
  virtual void setScaleU(double scaleU) = 0;
  /** Description:
    Sets the scale of this Bitmap object in the V-direction.
    Arguments:
    scaleV (I) Scale in V-direction.
    Remarks:
    This is the number of repetitions of this Bitmap object in the specified direction.
  */
  virtual void setScaleV(double scaleV) = 0;
  /** Description:
    Sets the offset of this Bitmap object in the U-direction.
    Arguments:
    offsetU (I) Offset in U-direction. [-1.0 .. 1.0].
  */
  virtual void setOffsetU(double offsetU) = 0;
  /** Description:
    Sets the offset of this Bitmap object in the V-direction.
    Arguments:
    offsetV (I) Offset in V-direction. [-1.0 .. 1.0].
  */
  virtual void setOffsetV(double offsetV) = 0;
  /** Description:
    Sets the tile method of this Bitmap object.
    
    Arguments:
    tileMethod (I) Tile method.
    
    Remarks:
    tileMethod must be one of the following:
    
    @table
    Name          Value   Description
    kTmDefault    0       Tiling as set for the material.
    kTmTile       1       Tiled.
    kTmCrop       2       Cropped.
    kTmClamp      3       Clamped.
  */
  virtual void setTileMethod(OdAve::TileMethod tileMethod) = 0;
  /** Description:
    Controls the use of Auto Axis by this Bitmap object.
    Arguments:
    useAutoAxis (I) Controls use of Auto Axis.
    Remarks:
    AutoAxis automatically maps materials to surfaces 
    whose normals are the X, Y, and Z axes.
    
    If AutoAxis is not used, only surfaces whose normal is the Z axis are mapped.
  */
  virtual void setUseAutoAxis(bool useAutoAxis) = 0;
 
  /** Description:
    Controls the automatically scaling of this Bitmap object to the object to which
    it is attached.
    Arguments:
    fitToObject (I) Controls automatic scaling.
  */
  virtual void setFitToObject(bool fitToObject) = 0;
};

#endif // OD_AVEDEFS_H
