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




#ifndef _PDFEXPORTPARAMS_INCLUDED_
#define _PDFEXPORTPARAMS_INCLUDED_ /** { Secret } *// 

#include "PdfExportDef.h"

#include "Gs/GsPageParams.h"

#include "DbBaseDatabase.h"
#include "OdStreamBuf.h"

class PDFExportParams
{
public:
  enum PDFExportVersions
  {
    kPDFv1_0 = 10,
    kPDFv1_1 = 11,
    kPDFv1_2 = 12,
    kPDFv1_3 = 13,
    kPDFv1_4 = 14,
    kPDFv1_5 = 15,
    kPDFv1_6 = 16,
    kLast    = kPDFv1_6
  };


  PDFExportParams()
    : pDb(0)
    , ver(kPDFv1_4)
    , background(ODRGB(255, 255, 255))
    , pPalette(0)
    , bEncodeStream(true)
    , flags(kDefault)
    , bUseHLR(false)
    , bAllViews(false)
  {
  }

  ~PDFExportParams()
  {
  }

  OdDbBaseDatabase     *pDb;
  PDFExportVersions ver;           // Only PDF 1.4 supported & 1.5 for layers functionality
  OdStreamBufPtr    outputStream;

  OdArray<OdString>      layouts;       // Layouts to export. if zero size array, àctive layout will be exported.
  OdArray<OdGsPageParams> pageParams;    // Page parameters - paper size, margins - in mm.

  ODCOLORREF        background;    // Background color. Default - white
  const ODCOLORREF* pPalette;      // Palette to be used.
                                   //  If NULL - one of two default palettes
                                   //  will be used depending on background color

  bool              bEncodeStream; // Enable encoding of geometry stream.

  enum PDFExportFlags
  {
    kZeroFlag               =   0, // all flags disabled
    kEmbededTTF             =   1, // enable embedding of True Type font program to PDF file.
    kTTFTextAsGeometry      =   2, // enable True Type font text to geometry conversion.
    kSHXTextAsGeometry      =   4, // enable SHX font text to geometry conversion.
    kSimpleGeomOptimization =   8, // enable simple geometry optimization (separated segments to one polyline, Bezier curve control points)
    kZoomToExtentsMode      =  16, // if enabled, layout geometry will be zoomed to paper size, else layout settings will be applied.
    kEnableLayers           =  32, // if enabled, layers support will be added to pdf document (1.5 version required)
    kIncludeOffLayers       =  64, // if enabled, invisible layers will be added to pdf document also (1.5 version required)
    kExactExtents           = 128, // if enabled, exact extents bounding box will be used for ZoomToExtents mode.

    kDefault           = kTTFTextAsGeometry|kSHXTextAsGeometry|kZoomToExtentsMode
  };

  int flags;

  // All next fields are optional (can be ""). If Producer is null, it will be "DDT PDF Export vX.X"
  OdString Title;    // The document’s title.
  OdString Author;   // The name of the person who created the document.
  OdString Subject;  // The subject of the document.
  OdString Keywords; // Keywords associated with the document.
  OdString Creator;  // If the document was converted to PDF from another format, the
                     // name of the application (for example, Adobe FrameMaker that created the
                     // original document from which it was converted.
  OdString Producer; // If the document was converted to PDF from another format, the
                     // name of the application (for example, Acrobat Distiller) that converted it to PDF.
  bool       bUseHLR;                    // Is software vector hidden-line removing used for 
                                         // corresponding viewports
  bool     bAllViews;// If it's true to export all views for this model/layout.
};

#endif //_PDFEXPORTPARAMS_INCLUDED_

