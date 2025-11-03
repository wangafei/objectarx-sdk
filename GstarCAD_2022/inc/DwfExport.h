/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2014, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2014 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
//
// DwfExport.h - Open Design DWF Export definitions
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _DWF_EXPORT_INCLUDED_
#define _DWF_EXPORT_INCLUDED_


#include "OdPlatformSettings.h"

#ifdef DWFEXPORT_EXPORTS
  #define DWFEXPORT_TOOLKIT           OD_TOOLKIT_EXPORT
  #define DWFEXPORT_TOOLKIT_STATIC    OD_STATIC_EXPORT
#else                                 
  #define DWFEXPORT_TOOLKIT           OD_TOOLKIT_IMPORT
  #define DWFEXPORT_TOOLKIT_STATIC    OD_STATIC_IMPORT
#endif

///////////////////////////////////////////////////////////////////////////////

#if defined(WIN32) || defined(WIN64)
  #include <tchar.h>
#endif

#include "OdArray.h"
#include "OdString.h"
#include "StringArray.h"
#include "OdPlatform.h"
#include "DbBaseDatabase.h"

class OdDbDatabase;
class OdDbLayout;
// Output format types
//

/** Description:
  DWF export content.

  {group:OdExport_Classes} 
*/
namespace TD_DWF_EXPORT {
typedef enum {
  DW_COMPRESSED_BINARY = 0,     // NOTE: only for the DWF v5.5 (and earlier)
  DW_UNCOMPRESSED_BINARY,
  DW_ASCII,
  DW_XPS
} DW_FORMAT;


const long lMaxDwfResolution = 0x7FFFFFFE;  // Max X and Y size

// The version is calculated as follows: (major_version * 100) + minor_version.
const int  nDwf_v55 = 55;                   // DWF v5.5
const int  nDwf_v42 = 42;                   // DWF v4.2
const int  nDwf_v60 = 600;                  // DWF v6.0


//
// DW_EXPORT_PARAMS - Export parameters
//

/** Description:
  The ImageResource element is used to describe an image (raster) file resource.
*/
struct ImageResource
{
  ImageResource()
    : sFileName(OD_T(""))
    , ColorDepth(0)
    , Width(0)
    , Height(0)
  {
  };

  ImageResource(const ImageResource& data)
  {
    Copy(data);
  }

  void Copy(const ImageResource& from)
  {
    sFileName = from.sFileName;
    ColorDepth = from.ColorDepth;
    Width = from.Width;
    Height = from.Height;
  }

  OdString  sFileName;
  int       ColorDepth;       // the number of colors used in the image
  int       Width;
  int       Height;
};

/** Description:
  The structure stores the page parameters for DWF export.
*/
struct DwfPageData
{
  DwfPageData()
    : sLayout(OD_T(""))
    , sPageAuthor(OD_T(""))
    , sPageTitle(OD_T(""))
    , sPageSubject(OD_T(""))
    , sPageCompany(OD_T(""))
    , sPageComments(OD_T(""))
    , sPageReviewers(OD_T(""))
    , sPageKeywords(OD_T(""))
    , sPageDescription(OD_T(""))
    , sPageCopyright(OD_T(""))
  {
  }

  DwfPageData(const DwfPageData& data)
  {
    Copy(data);
  }

  void Copy(const DwfPageData& from)
  {
    sLayout         = from.sLayout;
    sPageAuthor     = from.sPageAuthor;
    sPageTitle      = from.sPageTitle;
    sPageSubject    = from.sPageSubject;
    sPageCompany    = from.sPageCompany;
    sPageComments   = from.sPageComments;
    sPageReviewers  = from.sPageReviewers;
    sPageKeywords   = from.sPageKeywords;
    sPageDescription= from.sPageDescription;
    sPageCopyright  = from.sPageCopyright;

    thumbnail = from.thumbnail;
    preview   = from.preview;
    arFonts   = from.arFonts;
  }

  OdString  sLayout;

  // list of Page (section) data
  OdString  sPageAuthor;
  OdString  sPageTitle;
  OdString  sPageSubject;
  OdString  sPageCompany;
  OdString  sPageComments;
  OdString  sPageReviewers;
  OdString  sPageKeywords;
  OdString  sPageDescription;
  OdString  sPageCopyright;

  ImageResource         thumbnail;  // Raster Graphics (e.g. .jpeg, .png)
  ImageResource         preview;    // Raster Graphics (e.g. .jpeg, .png)

  OdStringArray arFonts;    // the list of the embedded fonts
};

/** Description:
   {filename:DwExportParams_Definition}

   This class implements the parameters for DWF export.
*/
class DwExportParams
{
public:

  DwExportParams()
    : pDb(NULL)
    , sDwfFileName(OD_T(""))
    , xSize(36000)
    , ySize(24000)
    , Format(DW_ASCII)
    , Version(nDwf_v55)
    , background(ODRGB(255, 255, 255))
    , pPalette(NULL)
    , bExportInvisibleLayers(false)
    , bForceInitialViewToExtents(false)
    , bSkipLayerInfo(false)
    , bSkipNamedViewsInfo(false)
    , bInkedArea(false)                                                                   // MKU 1/21/2004
    , bColorMapOptimize(false)                                                            // MKU 1/21/2004
    , bRGBToJpeg(true)
    , bUseHLR(true)
    , nMaxPointsInPolygon(0)
    , nMaxRasterResolution(0)
    , bExportInvisibleText(true)
    , bEmbedAllFonts(false)
  {
  }

  ~DwExportParams()
  {
  }

  //OdDbDatabase* pDb; // before 21.12.2011
  OdDbBaseDatabase*     pDb; // dgn dwf export
  OdString      sDwfFileName;

  long          xSize;            // DWF file resolution (less resolution - less file size
  long          ySize;            //

  // Optional parameters. May be zeroed to use defaults
  //
  DW_FORMAT     Format;           // Output format (compressed, binary, ASCII)
  int           Version;          // DWF version (currently 42 or 55)

  ODCOLORREF  background;          // Background color. Default - white
  const ODCOLORREF* pPalette;      // Palette to be used. It's size depends on the highest
                                  //  index in ad3parm.colors array.
                                  //  If NULL - one of two default palettes
                                  //  will be used depending on background color

  bool          bExportInvisibleLayers;     // If non-zero invisible and frozen layers will be exported
                                            //  Note: not supported
  bool          bForceInitialViewToExtents; // If non-zero Initial view will be set
                                            //  to extents else - active view saved in drawing
                                            //  Note: for Model Space only
  bool          bSkipLayerInfo;             // Don't save layer info
  bool          bSkipNamedViewsInfo;        // Don't save named views
  bool          bInkedArea;                 // Sets on/off the Inked Area
                                            //  The Inked Area opcode specifies a rectangle, in logical
                                            //  coordinates, in which all of the .dwf file? geometric
                                            //  primitives fit tightly inside.
                                            // ATTENTION: The slowing-down of performance is possible
                                            //            in case that this option is set on.
  bool          bColorMapOptimize;          // True - to set on the color map optimization;
                                            //  as a result this one keeps the actual colors only.
                                            //  false - to set off the optimization
                                            //  and to export whole color map always
                                            // ATTENTION: The slowing-down of performance is possible
                                            //            in case that this option is set on.
  bool          bRGBToJpeg;                 // If it is true an attempt to save JPEG images in DWF file
                                            //  rather than RGB will be made - less output size.
                                            // The result is depend on RX_RASTER_SERVICES implementation.
  bool          bUseHLR;                    // Is software vector hidden-line removing used for
                                            // corresponding viewports

  /*
   * DWF format describes polygon entity with
   * great (>65000) number of vertices. It's the most compact representation of
   * filled areas (more compact that polytriangles).
   * But AutoDesk's viewer which probably will be used to display DWF files
   * has problems with rendering polygons.
   * First it does not render correctly polygons with number of vertices > 64.
   * It often crashes while zooming polygons with more than 32 vertices.
   * BTW AutoCAD 2000 does not export filled polygons to DWF (tristrips only)
   */
  unsigned long nMaxPointsInPolygon;        // Max number of points in polygon
                                            //  Default is 0 - polygons will be triangulated to tristrips.

  unsigned short nMaxRasterResolution;      // If non zero sets the limit of raster image resolution


  OdString        sPassword;
  // dwf-wide metadata
  OdString        sPublisher;
  OdString        sWideComments;
  OdString        sSourceProductName;         // Brief description of the application from
                                              //  which the source data was created
  OdArray<DwfPageData>  arPageData;
  
  // AutoCAD 2004 and earlier exported invisible text along with vectorized SHX text, 
  // to allow text search in DWF. In version 2005 this feature was removed.
  // This flags controls the behaviour of our export.
  bool bExportInvisibleText;
  // embed all the fonts encountered in the document to DWFx file
  bool bEmbedAllFonts;
}; // DwExportParams

}

using namespace TD_DWF_EXPORT;
DWFEXPORT_TOOLKIT void exportDwf(const DwExportParams& pParams);


#endif // _DWF_EXPORT_INCLUDED_

