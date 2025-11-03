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


#ifndef _DbRenderSettings_h_Included_
#define _DbRenderSettings_h_Included_

#include "Gi/GiEnvironment.h"

/** Description:
    This class is a container class for the properties relevent to generic high-fidelity renderers.

    Remarks:
    Database-resident OdDbRenderSettings objects are stored in the NamedObjectsDictionary
    under ACAD_RENDER_SETTINGS. 
    
    In addition, the active RenderSettings are stored in the NamedObjectsDictionary 
    under ACAD_RENDER_ACTIVE_SETTINGS. 

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbRenderSettings : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRenderSettings);

  OdDbRenderSettings();
  virtual ~OdDbRenderSettings();

  /** Description:
    Returns the OdGiDrawable for this RenderSettings object.
  */
  virtual OdGiDrawable* drawable();

  /** Description:
    Sets the *name* of this RenderSettings object.
    Arguments:
    name (I) Name.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.    
    Note:
    No check is made for RenderSettings objects with duplicate names.
  */
  OdResult setName(const OdString& name);

  /** Description:
    Returns the *name* of this RenderSettings object.
  */
  OdString name() const;

  /** Description:
    Sets the *description* of this RenderSettings object.
    Arguments:
    description (I) Description.
  */
  void setDescription(const OdString& description);

  /** Description:
    Returns the *description* of this RenderSettings object.
  */
  OdString description() const;

  /** Description:
    Sets the DisplayIndex of this RenderSettings object.
    Arguments:
    displayIndex (I) DisplayIndex.
    Remarks:
    The DisplayIndex specfies the display order in the UI of the entries in the ACAD_RENDER_SETTINGS dictionary.
    
    DisplayIndices need not be positive or consecutive, and are not intended for use as ID numbers.
  */
  void setDisplayIndex(int displayIndex);

  /** Description:
    Returns the DisplayIndex of this RenderSettings object.
    Remarks:
    The DisplayIndex specfies the display order in the UI of the entries in the ACAD_RENDER_SETTINGS dictionary.
    
    DisplayIndices need not be positive or consecutive, and are not intended for use as ID numbers.
  */
  int displayIndex() const;

  
  /** Description:
    Controls the rendering of materials on a per-object basis for this RenderSettings object.
    Arguments:
    materialsEnabled (I) Controls MaterialsEnabled.
    Remarks:
    If true, materials are rendered on a per-object basis. If false, all objects
    are rendered with the global material.
    
    The default value for MaterialsEnabled == true.  
  */
  void setMaterialsEnabled(bool materialsEnabled);

  /** Description:
    Returns true if and only if materials are rendered on a per-object basis for this RenderSettings object.
    Remarks:
    If true, materials are rendered on a per-object basis. If false, all objects
    are rendered with the global material.
    
    The default value for MaterialsEnabled == true.  
  */
  bool materialsEnabled() const;

  /** Description:
    Controls the *sampling* of image textures for this RenderSettings object.
    Arguments:
    textureSampling (I) Controls TextureSampling.
  */
  void setTextureSampling(bool textureSampling);

  /** Description:
    Returns true if and only if texture *sampling* is enabled for this RenderSettings object.
  */
  bool textureSampling() const;

  /** Description:
    Controls the rendering of back-facing faces for this RenderSettings object.
    Arguments:
    backFacesEnabled (I) Controls BackFacesEnabled.
    Remarks:
    Back-facing faces are rendered if and only if BackFacesEanbled == true;
    
    Remarks:
    The default value for BackFacesEnabled == true;
  */
  void setBackFacesEnabled(bool backFacesEnabled);

  /** Description:
    Returns true if and only if back-facing faces are rendered for this RenderSettings object.
  */
  bool backFacesEnabled() const;

  /** Description:
    Controls the casting of shadows for this RenderSettings object.
    Arguments:
    shadowsEnabled (I) Controls ShadowsEnabled.
    Remarks:
    Shadows are *cast* if and only if ShadowsEnabled == true;
    
    Remarks:
    The default value for ShadowsEnabled == true;
  */
  void setShadowsEnabled(bool shadowsEnabled);

  /** Description:
    Returns true if and only if shadows are *cast* for this RenderSettings object.
  */
  bool shadowsEnabled() const;


  /** Description:
    Sets the full *filename* of the preview image for this RenderSettings object.
    Arguments:
    filename (I) Filename.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    If the PreviewImageFileName is blank, no preview image is associated with this RenderSettings object.
    
    The default value for PreviewImageFileName is blank.
  */
  OdResult setPreviewImageFileName(const OdString& filename);

  /** Description:
    Returns the full *filename* of the preview image for this RenderSettings object.
    Remarks:

    If the PreviewImageFileName is blank, no preview image is associated with this RenderSettings object.
    
  */
  OdString previewImageFileName() const;

  /** Description:
    Controls the rendering of the diagnostic background for this RenderSettings object.
    Arguments:
    diagnosticBackgroundEnabled (I) Controls DiagnosticBackgroundEnabled.
    Remarks:
    The diagnostic (checker) background overrides the background for this RenderSettings object.
    
    The default value of DiagnosticBackgroundEnabled == false.
  */
  void setDiagnosticBackgroundEnabled(bool diagnosticBackgroundEnabled);

  /** Description:
    Return true if and only if the diagnostic background is enabled for this RenderSettings object.
  */
  bool diagnosticBackgroundEnabled() const;

  // OdDbObject functions

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  virtual OdResult copyFrom(const OdRxObject* other);
  
  // OdGiDrawable functions

  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual bool operator==(const OdDbRenderSettings& settings);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRenderSettings object pointers.
*/
typedef OdSmartPtr<OdDbRenderSettings> OdDbRenderSettingsPtr;


/** Description:
    This class is a container class for the properties relevent to mental ray renderers.

    Remarks:
    Database-resident OdDbMentalRayRenderSettings objects are stored in the NamedObjectsDictionary
    under ACAD_RENDER_SETTINGS. 
    
    In addition, the active RenderSettings are stored in the NamedObjectsDictionary 
    under ACAD_RENDER_ACTIVE_SETTINGS. 

    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbMentalRayRenderSettings : public OdDbRenderSettings
{
public:
  ODDB_DECLARE_MEMBERS(OdDbMentalRayRenderSettings);

  OdDbMentalRayRenderSettings();

  virtual ~OdDbMentalRayRenderSettings();

  /** Description:
    Controls the minimum and maximum *sampling* rates when rendering a pixel for this MentalRayRenderSettings object.
    Arguments:
    min (I) Minimum *sampling* rate. [-3 .. 5]
    max (I) Maximum *sampling* rate. [-3 .. 5]
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    o  Negative values enable subsampling.
    o  -3 specifies one sample per 64 pixels
    o  5 specfies one sample per 1028 pixels
    o  The default value of min == -1
    o  The default value of max == 0
    o  Min <= Max
  */
  OdResult setSampling(int min, int max);

  /** Description:
    Returns the minimum and maximum *sampling* rates when rendering a pixel for this MentalRayRenderSettings object.
    Arguments:
    min (O) Receives the minimum *sampling* rate. [-3 .. 5]
    max (O) Receives the maximum *sampling* rate. [-3 .. 5]
    Remarks:
    o  Negative values enable subsampling.
    o  -3 specifies one sample per 64 pixels
    o  5 specfies one sample per 1028 pixels
    o  The default value of min == -1
    o  The default value of max == 0
  */
  void sampling(int& min, int& max) const;

  /** Description:
    Sets the *sampling* *filter* parameters for this MentalRayRenderSettings object.
    Arguments:
    filter (I) Filter method.
    width (I) Width of the *filter* area in pixels. [0.0 .. 8.0]
    height (I) Height of the *filter* area in pixels. [0.0 .. 8.0]
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    The defaults are as follows:
    
    @table
    Argument     Default
    *filter*     kBox
    *width*      1.0
    *height*     1.0
  */
  OdResult setSamplingFilter(OdGiMrFilter filter, double width,
    double height);

  /** Description:
    Returns the *sampling* *filter* parameters for this MentalRayRenderSettings object.
    Arguments:
    filter (O) Receives the *filter* method.
    width (O) Receives the *width* of the *filter* area in pixels.
    height (O) Receives the *height* of the *filter* area in pixels.
  */
  void SamplingFilter(OdGiMrFilter& filter, double& width, double& height)
    const;

  /** Description:
    Sets the SamplingContrastColor for this MentalRayRenderSettings object.
    Arguments:
    red (I) Red color channel threshold. [0.0 .. 1.0]
    green (I) Green channel threshold. [0.0 .. 1.0]
    blue (I) Blue channel threshold. [0.0 .. 1.0]
    alpha (I) Alpha channel threshold. [0.0 .. 1.0]
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    Additional color camples will be taken if the difference between
    a sample and its surrounding samples exceeds the SamplingContrastColor.

    The default value for each color channel is 1.0.
    
  */
  OdResult setSamplingContrastColor(float red, float green, float blue, float alpha);

  /** Description:
    Returns the SamplingContrastColor for this MentalRayRenderSettings object.
    Arguments:
    red (O) Receives the *red* color channel threshold.
    green (O) Receives the *green* channel threshold.
    blue (O) Receives the *blue* channel threshold. 
    alpha (O) Receives the *alpha* channel threshold.
  */
  void samplingContrastColor(float& red, float& green, float& blue, float& alpha) const;

  /** Description:
    Sets the method of computing ray-traced shadows for this MentalRayRenderSettings object.
    Remarks:
    The default value for ShadowMode == krSimple.
  */
  void setShadowMode(OdGiMrShadowMode shadowMode);

  /** Description:
    Returns the method of computing ray-traced shadows for this MentalRayRenderSettings object.
  */
  OdGiMrShadowMode shadowMode() const;

  /** Description:
    Controls the generation of shadow maps for this MentalRayRenderSettings object.
    Arguments:
    shadowMapsEnabled (I) Controls shadow maps.
    Remarks:
    The default value of ShadowMapsEnabled == true;
  */
  void setShadowMapsEnabled(bool shadowMapsEnabled);

  /** Description:
    Returns true if and only if shadow maps are generated for this MentalRayRenderSettings object.
  */
  bool shadowMapsEnabled() const;

  /** Description:
    Controls ray tracing for this MentalRayRenderSettings object.
    Arguments:
    rayTracingEnabled (I) Controls ray tracing.
    Remarks:
    The default value of RayTracing == true;
  */
  void setRayTracingEnabled(bool rayTracingEnabled);

  /** Description:
    Returns true if and only if ray tracing is enabled for this MentalRayRenderSettings object.
  */
  bool rayTracingEnabled() const;

  /** Description:
    Sets the maximum ray trace depths for this MentalRayRenderSettings object.
    
    Arguments:
    reflection (I) Maximum number of ray reflections. 
    refraction (I) Maximum number of ray refractions.
    sum (I) Maximum number of ray reflections and refractions.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    The defaults are as follows:
    
    @table
    Argument      Default
    reflection    2
    refraction    2
    sum           4
  */
  OdResult setRayTraceDepth(int reflection, int refraction,
    int sum);

  /** Description:
    Returns the maximum ray trace depths for this MentalRayRenderSettings object.
    
    Arguments:
    reflection (O) Receives the maximum number of ray reflections. 
    refraction (O) Receives the maximum number of ray refractions.
    sum (O) Receives the maximum number of ray reflections and refractions.
  */
  void rayTraceDepth(int& reflection, int& refraction, int& sum) const;

  /** Description:
    Controls global illumination using photon mapping for this MentalRayRenderSettings object.
    Arguments:
    globalIlluminationEnabled (I) Controls GlobalIllumination.
    
    Remarks:
    Global illumination permits indirect lighting effects such as color-bleeding.
    
    The default value of GlobalIllumination is false.
  */
  void setGlobalIlluminationEnabled(bool globalIlluminationEnabled);

  /** Description:
    Returns true if and only if global illumination using photon mapping is 
    enabled for this MentalRayRenderSettings object.
  */
  bool globalIlluminationEnabled() const;

  /** Description:
    Sets the number of photons used for computing global illumination
    near a sample point for this MentalRayRenderSettings object.
    Arguments:
    numPhotons (I) Number of photons.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    The default value for GISampleCount == 500
    See also:
    setGISampleRadius
    setGISampleRadiusEnabled
  */
  OdResult setGISampleCount(int numPhotons);

  /** Description:
    Returns the number of photons used for computing global illumination
    near a sample point for this MentalRayRenderSettings object.
  */
  int giSampleCount() const;

  /** Description:
    Controls the use of the GISampleRadius for computing global illumination 
    for this MentalRayRenderSettings object.
    Arguments:
    giSampleRadiusEnabled (I) Controls GISampleRadiusEnabled.
    Remarks:
    If GISampleRadiusEnabled == false, a default, the model space extents
    are used to computer a default radius.
    
    The default value of GISampleRadiusEnabled == false.
  */
  void setGISampleRadiusEnabled(bool giSampleRadiusEnabled);

  /** Description:
    Returns true if and only if the GISampleRadius is used for computing 
    global illumination for this MentalRayRenderSettings object.
  */
  bool giSampleRadiusEnabled() const;

  /** Description:
    Sets the *radius* for computing the photon count for global illumination for this 
    MentalRayRenderSettings object.
    
    Arguments:
    radius (I) Sample *radius*.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    The default value for GISampleRadius == 1.0.
    
    See also:
    setGISampleCount
    setGISampleRadiusEnabled
  */
  OdResult setGISampleRadius(double radius);

  /** Description:
    Returns the *radius* for computing the photon count for global illumination for this 
    MentalRayRenderSettings object.
  */
  double giSampleRadius() const;

  /** Description:
    Sets the average the number of photons shot per light for this 
    MentalRayRenderSettings object.
    Arguments:
    numPhotons (I) Number of photons.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    The default value for GIPhotonsPerLight == 10,000.
  */
  OdResult setGIPhotonsPerLight(int numPhotons);

  /** Description:
    Returns the average the number of photons shot per light for this 
    MentalRayRenderSettings object.
  */
  int giPhotonsPerLight() const;

  /** Description:
    Sets the maximum photon trace depths for this MentalRayRenderSettings object.
    
    Arguments:
    reflection (I) Maximum number of photon reflections. 
    refraction (I) Maximum number of photon refractions.
    sum (I) Maximum number of photon reflections and refractions.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    The defaults are as follows:
    
    @table
    Argument      Default
    reflection    5
    refraction    5
    sum           5
  */
  OdResult setPhotonTraceDepth(int reflection, int refraction,
    int sum);

  /** Description:
    Returns the maximum photon trace depths for this MentalRayRenderSettings object.
    
    Arguments:
    reflection (O) Receives the maximum number of photon reflections. 
    refraction (O) Receives the maximum number of photon refractions.
    sum (O) Receives the maximum number of photon reflections and refractions.
  */
  void photonTraceDepth(int& reflection, int& refraction, int& sum) const;

  /** Description:
    Controls the application of final gathering for this MentalRayRenderSettings object.
    Arguments:
    finalGatheringEnabled (I) Controls final gathering.
    Remarks:
    Final gathering permits indirect lighting effects such as color-bleeding.
  */
  void setFinalGatheringEnabled(bool finalGatheringEnabled);

  /** Description:
    Returns true if and only if final gathering is enabled for this MentalRayRenderSettings object.
  */
  bool finalGatheringEnabled() const;

  OdResult setFinalGatheringMode(OdGiMrFinalGatheringMode mode);

  OdGiMrFinalGatheringMode finalGatheringMode() const;

  /** Description:
    Sets the final gathering ray count for this MentalRayRenderSettings object.
    Arguments:
    fgRayCount (I) Final gathering ray count.
    
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.

    In order to compute indirect illumination of a scent,
    FGRayCount rays are shot into the scene for each final gathering point.
     
    The default value for FGRayCount = 1000.
  */
  OdResult setFGRayCount(int fgRayCount);

  /** Description:
    Returns the final gathering ray count for this MentalRayRenderSettings object.
    
    Remarks:
    In order to compute indirect illumination of a scent,
    FGRayCount rays are shot into the scene for each final gathering point.
  */
  int fgRayCount() const;

  /** Description:
    Controls the Final Gathering Sample Radius State for this MentalRayRenderSettings object.
    
    Arguments:
    useMin (I) True to use user-supplied minimum radius, false for default radius.
    useMax (I) True to use user-supplied maximum radius, false for default radius.
    inPixels (I) True if user-supplied radii are in pixels, false for drawing units.
    Remarks:
    The default values for all parameters == false.
  */
  void setFGRadiusState(bool useMin, bool useMax, bool inPixels);

  /** Description:
    Returns the the Final Gathering Sample Radius State for this MentalRayRenderSettings object.
    
    Arguments:
    useMin (O) Receives true if the user-supplied minimum radius is used, false for the default,
    useMax (O) Receives true if the user-supplied maximum radius is used, false for the default,
    inPixels (O) True if user-supplied radii are in pixels, false for drawing units.
  */
  void fgSampleRadiusState(bool& useMin, bool& useMax, bool& inPixels) const;

  /** Description:
    Sets the Final Gathering Sample Radii for this MentalRayRenderSettings object.
    Arguments:
    minRadius (I) Minimum radius.
    maxRadius (I) Maximum radius.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    Default values are are 0.1 for drawing units, and 0.5 for pixels.
    
    minRadius <= maxRadius 
  */
  OdResult setFGSampleRadius(double minRadius, double maxRadius);

  /** Description:
    Returns the Final Gathering Sample Radii for this MentalRayRenderSettings object.
    Arguments:
    minRadius (O) Receives the minimum radius.
    maxRadius (I) Receives the maximum radius.
  */
  void fgSampleRadius(double& minRadius, double& maxRadius) const;

  OdResult setLightLuminanceScale(double fLuminance);

  double lightLuminanceScale() const;

  OdResult setExportMIMode(OdGiMrExportMIMode eExportMIMode);

  OdGiMrExportMIMode exportMIMode() const;
  
  /** Description:
    Sets the magnitude of indirect illumination for this MentalRayRenderSettings object.
    Arguments:
    energyMultiplier (I) Energy multiplier.
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    The default value for EnergyMultiplier is 1.0.
    
    EnergyMultiplier serves as a volume control for the photon emmision of every light.
  */
  OdResult setEnergyMultiplier(float energyMultiplier);

  /** Description:
    Returns the magnitude of indirect illumination for this MentalRayRenderSettings object.
    Remarks:
    EnergyMultiplier serves as a volume control for the photon emmision of every light.
  */
  float energyMultiplier() const;

  /** Description:
    Sets the diagnostic image rendering mode for this MentalRayRenderSettings object.
    Arguments:
    diagnosticMode (I) Diagnostic mode.
  */
  void setDiagnosticMode(OdGiMrDiagnosticMode diagnosticMode);

  /** Description:
    Returns the diagnostic image rendering mode for this MentalRayRenderSettings object.
    Arguments:
    diagnosticMode (I) Diagnostic mode.
  */
  OdGiMrDiagnosticMode diagnosticMode() const;

  /** Description:
    Sets the Diagnostic Grid for this MentalRayRenderSettings object.
    Arguments:
    diagnosticGridMode (I) Coordinate system for the grid.
    gridSpace (I) Distance between grid lines.
    
    Remarks:
    The default mode is krObject, the default grid space is 10.0.
  */
  OdResult setDiagnosticGridMode(
    OdGiMrDiagnosticGridMode diagnosticGridMode, float gridSpace);

  /** Description:
    Returns the Diagnostic Grid for this MentalRayRenderSettings object.
    Arguments:
    diagnosticGridMode (O) Receives the coordinate system for the grid.
    gridSpace (O) Receives the distance between grid lines.
  */
  void diagnosticGridMode(
    OdGiMrDiagnosticGridMode& diagnosticGridMode, float& gridSpace) const;

  /** Description:
    Sets the Diagnostic Photon Mode for this MentalRayRenderSettings object.
    Arguments:
    diagnosticPhotonMode (I) Diagnostic Photon Mode.
    Remarks:
    The default value for DiagnosticPhotonMode == krDensity.
  */
  void setDiagnosticPhotonMode(
    OdGiMrDiagnosticPhotonMode diagnosticPhotonMode);

  /** Description:
    Returns the Diagnostic Photon Mode for this MentalRayRenderSettings object.
  */
  OdGiMrDiagnosticPhotonMode diagnosticPhotonMode() const;

  /** Description:
    Controls the Diagnostic Samples Mode for this MentalRayRenderSettings object.
    Arguments:
    diagnosticSamplesMode (I) Diagnostic Samples Mode
    Remarks:
    The default value for DiagnosticSamplesMode == false.
  */
  void setDiagnosticSamplesMode(bool diagnosticSamplesMode);

  /** Description:
    Returns the Diagnostic Samples Mode for this MentalRayRenderSettings object.
    Remarks:
    The default value for DiagnosticSamplesMode == false.
  */
  bool diagnosticSamplesMode() const;

  /** Description:
    Sets the Diagnostic BSP Mode for this MentalRayRenderSettings object.
    Arguments:
    diagnosticBSPMode (I) Diagnostic BSP Mode.
    Remarks:
    The default value for DiagnosticBSPMode is krDepth.
  */
  void setDiagnosticBSPMode(OdGiMrDiagnosticBSPMode diagnosticBSPMode);

  /** Description:
    Returns the Diagnostic BSP Mode for this MentalRayRenderSettings object.
    Arguments:
    diagnosticBSPMode (I) Diagnostic BSP Mode.
    Remarks:
    The default value for DiagnosticBSPMode is krDepth.
  */
  OdGiMrDiagnosticBSPMode diagnosticBSPMode() const;

  /** Description:
    Controls the creation of an MI file after rendering for this MentalRayRenderSettings object.
    Arguments:
    exportMIEnabled (I) Export MI Enabled.
    Remarks:
    The default value for ExportMIEnabled == false.
    See Also:
    setExportMIFileName
  */
  void setExportMIEnabled(bool exportMIEnabled);

  /** Description:
    Returns true if and only if an MI file is created after rendering for this MentalRayRenderSettings object.
  */
  bool exportMIEnabled() const;

  /** Description:
    Sets the full *filename* of the exported MI file for this MentalRayRenderSettings object.
    Arguments:
    filename (I) Filename.

    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    If the ExportMIFileName is blank, no MI file is associated with this MentalRayRenderSettings object.
    
    The default value for ExportMIFileName is blank.
  */
  OdResult setExportMIFileName(const OdString& filename);

  /** Description:
    Returns the full *filename* of the exported MI file for this MentalRayRenderSettings object.
  */
  OdString exportMIFileName() const;

  /** Description:
    Sets the image tile size used in rendering for this MentalRaySettings object.
    Arguments:
    tileSize (I) Tile size. [4..512]
    Remarks:
    Returns eOk if successful, or an appropriate error code if not.
    
    Larger values decrease rendering time and update frequency during rendering.
    
    The default value for TileSize is 32.
  */
  OdResult setTileSize(int tileSize);

  /** Description:
    Returns the image tile size used in rendering for this MentalRaySettings object.
  */
  int tileSize() const;

  /** Description:
    Sets the tile order used in tile rendering for this MentalRaySettings object.
    Arguments:
    tileOrder (I) Tile order.
    Remarks:
    The default value for TileOrder is krHilbert.
  */
  void setTileOrder(OdGiMrTileOrder tileOrder);

  /** Description:
    Returns the tile order used in tile rendering for this MentalRaySettings object.
  */
  OdGiMrTileOrder tileOrder() const;

 
  /** Description:
    Sets the maximum memory allocated for rendering for this MentalRaySettings object.
    Arguments:
    memoryLimit (I) Memory limit (MB) [>= 128]
    Remarks:
    
    Returns eOk if successful, or an appropriate error code if not.
    
    The renderer will decrease performance so as to stay below the memory limit.
    
    The default value for MemoryLimit is 1048.
  */
  OdResult setMemoryLimit(int memoryLimit);

  /** Description:
    Returns the maximum memory allocated for rendering for this MentalRaySettings object.
  */
  int memoryLimit() const;

  enum ShadowSamplingMultiplier 
  {
    kSamplingMultiplierZero = 0,
    kSamplingMultiplierOneEighth,
    kSamplingMultiplierOneFourth,
    kSamplingMultiplierOneHalf,
    kSamplingMultiplierOne,
    kSamplingMultiplierTwo
  };

  OdResult setShadowSamplingMultiplier(
    OdDbMentalRayRenderSettings::ShadowSamplingMultiplier multiplier);

  OdDbMentalRayRenderSettings::ShadowSamplingMultiplier shadowSamplingMultiplier() const;

  OdResult copyFrom(const OdRxObject* other);

  // OdDbObject functions
  
  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdGiDrawable functions
  
  virtual OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual bool operator==(const OdDbMentalRayRenderSettings& settings);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbMentalRayRenderSettings object pointers.
*/
typedef OdSmartPtr<OdDbMentalRayRenderSettings> OdDbMentalRayRenderSettingsPtr;


/** Description:

    Remarks:
    Database-resident OdDbRenderEnvironment objects are stored in the NamedObjectsDictionary
    under ACAD_RENDER_ENVIRONMENT. 
    
    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbRenderEnvironment : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRenderEnvironment);

  OdDbRenderEnvironment();
  virtual ~OdDbRenderEnvironment();

  void setFogEnabled(bool bEnable);

  bool fogEnabled() const;

  void setFogBackgroundEnabled(bool bEnable);

  bool fogBackgroundEnabled() const;

  void setFogColor(const OdCmEntityColor& color);

  OdCmEntityColor fogColor() const;

  OdResult setFogDensity(double dNear, double dFar);

  void fogDensity(double& dNear, double& dFar) const;

  OdResult setDistances(double dNear, double dFar);

  void distances(double& dNear, double& dFar) const;

  void setEnvironmentImageEnabled(bool bEnabled);

  bool environmentImageEnabled() const;

  OdResult setEnvironmentImageFileName(const OdString& sFileName);

  OdString environmentImageFileName() const;

  // OdDbObject functions

  OdGiDrawable* drawable();
  OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  // OdGiDrawable functions

  OdUInt32 subSetAttributes(OdGiDrawableTraits* pTraits);

  virtual bool operator==(const OdDbRenderEnvironment& environment);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRenderEnvironment object pointers.
*/
typedef OdSmartPtr<OdDbRenderEnvironment> OdDbRenderEnvironmentPtr;


/** Description:

    Remarks:
    Database-resident OdDbRenderEnvironment objects are stored in the NamedObjectsDictionary
    under ACAD_RENDER_GLOBAL.
    
    Library:
    TD_Db
    {group:OdDb_Classes} 
*/
class TOOLKIT_EXPORT OdDbRenderGlobal : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbRenderGlobal);

  enum Procedure
  {
    krView = 0,
    krCrop,
    krSelected
  };

  enum Destination
  {
    krWindow = 0,
    krViewport
  };

  OdDbRenderGlobal();
  virtual ~OdDbRenderGlobal();

  void setProcedureAndDestination(Procedure nProcedure, Destination nDestination);

  void procedureAndDestination(Procedure& nProcedure, Destination& nDestination) const;

  void setSaveEnabled(bool bEnabled);

  bool saveEnabled() const;

  OdResult setSaveFileName(const OdString& sFileName);

  OdString saveFileName() const;

  OdResult setDimensions(int w, int h);

  void dimensions(int& w, int& h) const;

  void setPredefinedPresetsFirst(bool bPredefinedPresetsFirst);

  bool predefinedPresetsFirst() const;

  void setHighInfoLevel(bool bHighInfoLevel);

  bool highInfoLevel() const;

  OdResult setExposureType(OdGiMrExposureType type);

  OdGiMrExposureType exposureType() const;

  // OdDbObject functions

  OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

  OdResult copyFrom(const OdRxObject* other);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbRenderGlobal object pointers.
*/
typedef OdSmartPtr<OdDbRenderGlobal> OdDbRenderGlobalPtr;

TOOLKIT_EXPORT OdDbObjectId oddbGetRenderSettingsDictionaryId(OdDbDatabase* pDb, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbDictionaryPtr oddbGetRenderSettingsDictionary(OdDbDatabase* pDb, OdDb::OpenMode mode, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbObjectId oddbGetRenderGlobalObjectId(OdDbDatabase* pDb, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbRenderGlobalPtr oddbGetRenderGlobalObject(OdDbDatabase* pDb, OdDb::OpenMode mode, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbObjectId oddbGetRenderEnvironmentObjectId(OdDbDatabase* pDb, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbRenderEnvironmentPtr oddbGetRenderEnvironmentObject(OdDbDatabase* pDb, OdDb::OpenMode mode, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbObjectId oddbGetActiveRenderSettingsObjectId(OdDbDatabase* pDb, bool createIfNotFound = false);
TOOLKIT_EXPORT OdDbRenderSettingsPtr oddbGetActiveRenderSettingsObject(OdDbDatabase* pDb, OdDb::OpenMode mode, bool createIfNotFound = false);

#endif
