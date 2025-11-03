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


///////////////////////////////////////////////////////////////////////////////
//
// PdfExport.h - Open Design Pdf Export definitions
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _PDF_EXPORT_INCLUDED_
#define _PDF_EXPORT_INCLUDED_

#include "PdfExportDef.h"
#include "PdfExportParams.h"


// exportPdf export DWG\DXF to PDF file
// 
// Input : params - input parameters
//
// Return : 0 is ok
//          non zero - error code

OdUInt32 PDFEXPORT_DLL exportPdf(PDFExportParams &params);

// exportPdfErrorCode return error code description string.
// 
// Input : errorCode - error code returned by exportPdf
//
// Return : OdString - description string.

OdString PDFEXPORT_DLL exportPdfErrorCode(OdUInt32 errorCode);

#endif // _PDF_EXPORT_INCLUDED_

