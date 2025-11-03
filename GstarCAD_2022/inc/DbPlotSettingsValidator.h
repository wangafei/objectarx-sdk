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




#ifndef OD_DBPLOTSETVAL_H
#define OD_DBPLOTSETVAL_H

#include "RxObject.h"
#include "DbPlotSettings.h"
#include "OdArray.h"

class OdDbPlotSettings;

typedef OdDbPlotSettings::PlotPaperUnits PlotPaperUnits;
typedef OdDbPlotSettings::PlotRotation   PlotRotation;
typedef OdDbPlotSettings::PlotType       PlotType;
typedef OdDbPlotSettings::StdScaleType   StdScaleType;

/** Description:
    This class defines access methods that validate data for
    OdDbPlotSettings objects prior to setting the data on the
    objects.
    
    Library:
    TD_Db
    
    Remarks:
    Plot device and style lists should be refreshed with refreshLists() prior to
    using the other methods in this class, in case any plot devices, PC3 files, or plot style tables were changed
    after starting your application.
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPlotSettingsValidator : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbPlotSettingsValidator);

  /** Description:
    Sets the plot device and media names for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    plotDeviceName (I) Name of the system printer or PC3 file.
    mediaName (I) Media name.
    
    Note:
    (plotDeviceName == none_device) requires (mediaName == none_user_media)
  */
  virtual OdResult setPlotCfgName(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* plotDeviceName,
    const OdChar* mediaName = NULL) = 0;

  /** Description:
    Sets the canonical (locale-independent) media name for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    mediaName (I) Canonical media name.
    
    Remarks:
    The canonical media name is locale-independent.
    
    See Also:
    getLocaleMediaName()

    Note:
    Canonical media names are case-sensitive.
  */
  virtual OdResult setCanonicalMediaName(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* mediaName) = 0;

  /** Description:
    Sets the plot origin offset for the specified PlotSettings object.

    Arguments:
    xCoordinate (O) X-coordinate of the origin offset.
    yCoordinate (O) Y-coordinate of the origin offset.
    
    Remarks:
    The plot origin offset is measured with respect to the plot margin.
     
    Note:
    All distances are returned in millimeters, regardless of the drawing units. 
  */
  virtual OdResult setPlotOrigin(
    OdDbPlotSettings *pPlotSettings,
    double xCoordinate,
    double yCoordinate) = 0;


  /** Description:
    Sets the plot paper units for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    plotPaperUnits (I) Plot paper units.
        
    Remarks:
    The plot paper units determine the units of the margins, offsets, paper size, and drawing units.
    
    plotPaperUnits must be one of the following:
    
    @table
    Name            Value   Description
    kInches         0       Inches
    kMillimeters    1       Millimeters
    kPixels         2       Pixels
  */
  virtual OdResult setPlotPaperUnits(
    OdDbPlotSettings* pPlotSettings,
    const PlotPaperUnits plotPaperUnits) = 0;


  /** Description:
    Sets the plot rotation for specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    plotRotation (I) Plot rotation.
    
    Remarks:
    plotRotation must be one of the following:
    
    @table
    Name         Value    Description
    k0degrees    0        No rotation
    k90degrees   1        90?CCW
    k180degrees  2        Inverted?
    k270degrees  3        90?CW
  */
  virtual OdResult setPlotRotation(
    OdDbPlotSettings* pPlotSettings,
    const PlotRotation plotRotation) = 0;

  /** Description:
    Controls the centering of the plot for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    plotCentered (I) Plot centered.
  */
  virtual OdResult setPlotCentered(
    OdDbPlotSettings* pPlotSettings,
    OdBool plotCentered) = 0;

  /** Description:
    Sets the plot type for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    plotType (I) Plot type.

    Remarks:
    plotType must be one of the following:
    
    @table
    Name        Value   Description
    kDisplay    0       Display
    kExtents    1       Extents
    kLimits     2       Limits
    kView       3       View
    kWindow     4       Window
    kLayout     5       Layout
  */
  virtual OdResult setPlotType(
    OdDbPlotSettings* pPlotSettings,
    const PlotType plotType) = 0;

  /** Description:
    Sets the corners of the plot window area for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    xMin (I) X-coordinate of the lower-left corner.      
    yMin (I) Y-coordinate of the lower-left corner.      
    xMax (I) X-coordinate of the upper-right corner.      
    yMax (I) Y-coordinate of the upper-right corner.      
    
    Remarks:
    The corners define the area to be plotted if and only if plotType == kWindow.
  */
  virtual OdResult setPlotWindowArea(
    OdDbPlotSettings* pPlotSettings,
    double xMin,
    double yMin,
    double xMax,
    double yMax) = 0;

  /** Description:
    Sets the plot view name for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    plotViewName (I) Plot view name.
  
    Remarks:
    This string specifies the named view to be plotted if and only if plotType == kView. 
  */
  virtual OdResult setPlotViewName(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* plotViewName) = 0;

  /** Description:
    Controls the use of a standard *scale* for the specified PlotSettings object.

    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    useStandardScale (I) Use standard scale.
  */
  virtual OdResult setUseStandardScale(
    OdDbPlotSettings* pPlotSettings,
    OdBool useStandardScale) = 0;

  /** Description:
    Sets the custom print *scale* for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    numerator (I) Receives the PaperSpace units.
    denominator (I) Receives the media units.
    
    Remarks:  
    The custom print *scale* always reflects the *scale* that this PlotSettings object will use to plot.
  */
  virtual OdResult setCustomPrintScale(
    OdDbPlotSettings* pPlotSettings,
    const double numerator,
    const double denominator) = 0;

  /** Description:
    Sets the current style sheet for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    currentStyleSheet (I) Name of current style sheet.
  */
  virtual OdResult setCurrentStyleSheet(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* currentStyleSheet) = 0;

  /** Description:
    Sets the standard *scale* type for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    stdScaleType (I) Name of current style sheet.

    Remarks:
    stdScaleType must be one of the of the following
    
    @table
    Name            Value   Scale
    kScaleToFit     0       Scaled to Fit
    k1_128in_1ft    1       1/128=1'
    k1_64in_1ft     2       1/64=1'
    k1_32in_1ft     3       1/32=1'
    k1_16in_1ft     4       1/16=1'
    k3_32in_1ft     5       3/32=1'
    k1_8in_1ft      6       1/8=1'
    k3_16in_1ft     7       3/16=1'
    k1_4in_1ft      8       1/4=1'
    k3_8in_1ft      9       3/8=1'
    k1_2in_1ft      10      1/2=1'
    k3_4in_1ft      11      3/4=1'
    k1in_1ft        12      1=1'
    k3in_1ft        13      3=1'
    k6in_1ft        14      6=1'
    k1ft_1ft        15      1'=1'
    k1_1            16      1:1
    k1_2            17      1:2
    k1_4            18      1:4
    k1_8            19      1:8
    k1_10           20      1:10
    k1_16           21      1:16
    k1_20           22      1:20
    k1_30           23      1:30
    k1_40           24      1:40
    k1_50           25      1:50
    k1_100          26      1:100
    k2_1            27      2:1
    k4_1            28      4:1
    k8_1            29      8:1
    k10_1           30      10:1
    k100_1          31      100:1
    k1000_1         32      1000:1
  */
  virtual OdResult setStdScaleType(
    OdDbPlotSettings* pPlotSettings,
    const StdScaleType stdScaleType) = 0;

  /** Description:
    Sets the standard *scale*, as a floating point value, for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    standardScale (I) Standard scale.
  */
  virtual OdResult setStdScale(
    OdDbPlotSettings* pPlotSettings,
    const double standardScale) = 0;
  
  /** Description:
    Returns an array of all available system printers and PC3 files.
    
    Remarks:
    Plot device and style lists should be refreshed with refreshLists() prior to
    using the other methods in this class, in case any plot devices, PC3 files, or plot style tables were changed
    after starting your application.
    
    Arguments:
    deviceList (O) Receives the plot device list.
  */
  virtual OdResult plotDeviceList(
    OdArray<const OdChar*> & deviceList) = 0;

  /** Description:
    Returns an array canonical (locale-independent) media names for the specified
    PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    mediaList (O) Receives the media name list.

    Remarks:
    Plot device and style lists should be refreshed with refreshLists() prior to
    using the other methods in this class, in case any plot devices, PC3 files, or plot style tables were changed
    after starting your application.
  */
  virtual OdResult canonicalMediaNameList(
    OdDbPlotSettings* pPlotSettings,
    OdArray<const OdChar*> & mediaList) = 0;

  /** Description:
    Returns the locale-dependent media name for the specified PlotSettings object and canonical media name or index.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    canonicalName (O) Locale-independent media name.
    
    Remarks:
    Plot device and style lists should be refreshed with refreshLists() prior to
    using the other methods in this class, in case any plot devices were added or removed
    after starting your application.
  */
  virtual OdResult getLocaleMediaName(
    OdDbPlotSettings *pPlotSettings,
    const OdChar*  canonicalName,
	const OdChar *& localeName) = 0;

  /** Arguments:
    mediaIndex (I) Media index.
  */
  virtual OdResult getLocaleMediaName(
    OdDbPlotSettings *pPlotSettings,
    int mediaIndex,
	const OdChar *& localeName) = 0;

  /** Description:
    Sets the media name closest to the specified parameters for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    paperWidth (I) Paper width.
    paperHeight (I) Paper height.
    plotPaperUnits (I) Plot paper units.
    matchPrintableArea (I) True to match against printable area or physical media size.

    Remarks:
    The plot paper units determine the units of the margins, offsets, paper size, and drawing units.

    plotPaperUnits must be one of the following:
    
    @table
    Name            Value   Description
    kInches         0       Inches
    kMillimeters    1       Millimeters
    kPixels         2       Pixels
  */ 
  virtual OdResult setClosestMediaName(
    OdDbPlotSettings* pPlotSettings,
    const double paperWidth,
    const double paperHeight,
    const PlotPaperUnits plotPaperUnits,
    OdBool matchPrintableArea) = 0;

  /** Description:
    Returns an array of all available plot style tables.
    
    Remarks:
    Plot device and style lists should be refreshed with refreshLists() prior to
    using the other methods in this class, in case any plot devices, PC3 files, or plot style tables were changed
    after starting your application.
    
    Arguments:
    styleList (O) Receives the plot style list.
  */
  virtual OdResult plotStyleSheetList(
    OdArray<const OdChar*> & styleList) = 0;

  /** Description:
    Refreshes the plot device and style lists for the specified PlotSettings object.
    
    Remarks:
    Plot device and style lists should be refreshed with refreshLists() prior to
    using the other methods in this class, in case any plot devices, PC3 files, or plot style tables were changed
    after starting your application.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
  */
  virtual void refreshLists(
    OdDbPlotSettings* pPlotSettings) = 0;


  /** Description:
    Controls the Zoom to Paper on Update setting for the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
    zoomToPaperOnUpdate (I) Zoom to Paper on Update.
  */
  virtual OdResult setZoomToPaperOnUpdate(
    OdDbPlotSettings* pPlotSettings,
    OdBool zoomToPaperOnUpdate) = 0;

  /** Description:
    Applies the default plot configuration settings to the specified PlotSettings object.
    
    Arguments:
    pPlotSettings (I) Pointer to the PlotSettings object.
  */
  virtual OdResult setDefaultPlotConfig(
    OdDbPlotSettings* pPlotSettings) = 0;
};

class TOOLKIT_EXPORT OdDbPlotSettingsValidatorDirect : public OdDbPlotSettingsValidator
{
public:
  virtual OdResult setPlotCfgName(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* plotDeviceName,
    const OdChar* mediaName = NULL);

  virtual OdResult setCanonicalMediaName(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* mediaName);

  virtual OdResult setPlotPaperSize(
    OdDbPlotSettings* pPlotSettings,
    double paperWidth, 
    double paperHeight);

  virtual OdResult setPlotPaperMargins(
    OdDbPlotSettings* pPlotSettings,
    double leftMargin, 
    double bottomMargin,
    double rightMargin, 
    double topMargin);

  virtual OdResult setPlotOrigin(
    OdDbPlotSettings *pPlotSettings,
    double xCoordinate,
    double yCoordinate);

  virtual OdResult setPlotPaperUnits(
    OdDbPlotSettings* pPlotSettings,
    const PlotPaperUnits plotPaperUnits);

  virtual OdResult setPlotRotation(
    OdDbPlotSettings* pPlotSettings,
    const PlotRotation plotRotation);

  virtual OdResult setPlotCentered(
    OdDbPlotSettings* pPlotSettings,
    OdBool plotCentered);

  virtual OdResult setPlotType(
    OdDbPlotSettings* pPlotSettings,
    const PlotType plotType);

  virtual OdResult setPlotWindowArea(
    OdDbPlotSettings* pPlotSettings,
    double xMin,
    double yMin,
    double xMax,
    double yMax);

  virtual OdResult setPlotViewName(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* plotViewName);

  virtual OdResult setUseStandardScale(
    OdDbPlotSettings* pPlotSettings,
    OdBool useStandardScale);

  virtual OdResult setCustomPrintScale(
    OdDbPlotSettings* pPlotSettings,
    const double numerator,
    const double denominator);

  virtual OdResult setCurrentStyleSheet(
    OdDbPlotSettings* pPlotSettings,
    const OdChar* currentStyleSheet);

  virtual OdResult setStdScaleType(
    OdDbPlotSettings* pPlotSettings,
    const StdScaleType stdScaleType);

  virtual OdResult setStdScale(
    OdDbPlotSettings* pPlotSettings,
    const double standardScale);
  
  virtual OdResult plotDeviceList(
    OdArray<const OdChar*> & deviceList); // Nothing

  virtual OdResult canonicalMediaNameList(
    OdDbPlotSettings* pPlotSettings,
    OdArray<const OdChar*> & mediaList); // Nothing

  virtual OdResult getLocaleMediaName(
    OdDbPlotSettings *pPlotSettings,
    const OdChar*  canonicalName,
	const OdChar *& localeName); // Nothing

  virtual OdResult getLocaleMediaName(
    OdDbPlotSettings *pPlotSettings,
    int mediaIndex,
	const OdChar *& localeName); // Nothing

  virtual OdResult setClosestMediaName(
    OdDbPlotSettings* pPlotSettings,
    const double paperWidth,
    const double paperHeight,
    const PlotPaperUnits plotPaperUnits,
    OdBool matchPrintableArea); // Nothing

  virtual OdResult plotStyleSheetList(
    OdArray<const OdChar*> & styleList); // Nothing

  virtual void refreshLists(
    OdDbPlotSettings* pPlotSettings); // Nothing

  virtual OdResult setZoomToPaperOnUpdate(
    OdDbPlotSettings* pPlotSettings,
    OdBool zoomToPaperOnUpdate);

  virtual OdResult setDefaultPlotConfig(
    OdDbPlotSettings* pPlotSettings);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPlotSettingsValidator object pointers.
*/
typedef OdSmartPtr<OdDbPlotSettingsValidator> OdDbPlotSettingsValidatorPtr;

#endif // OD_DBPLOTSETVAL_H

