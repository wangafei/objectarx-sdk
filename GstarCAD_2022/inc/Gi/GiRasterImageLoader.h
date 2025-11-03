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

#ifndef __ODGIRASTERIMAGELOADER_H__
#define __ODGIRASTERIMAGELOADER_H__

#include "GiExport.h"
#include "RxObject.h"
#include "GiRasterImage.h"
#include "DbBaseHostAppServices.h"

#include "TD_PackPush.h"

class OdGiContext;

/** Description:
    Protocol extension for OdGiRasterImageLoader.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiRasterImageLoaderPE : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiRasterImageLoaderPE);

    OdGiRasterImageLoaderPE();

    virtual OdGiRasterImagePtr loadRasterImage(const OdString &fileName, OdDbBaseDatabase* pDb, OdDbBaseHostAppServices::FindFileHint hint = OdDbBaseHostAppServices::kDefault) = 0;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiRasterImageLoaderPE object pointers.
*/
typedef OdSmartPtr<OdGiRasterImageLoaderPE> OdGiRasterImageLoaderPEPtr;

/** Description:
    Loads OdGiRasterImage from file.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiRasterImageLoader : public OdRxObject
{
  public:
    ODRX_DECLARE_MEMBERS(OdGiRasterImageLoader);

    OdGiRasterImageLoader();

    virtual OdGiRasterImagePtr loadRasterImage(const OdString &fileName, const OdGiContext &giCtx, OdDbBaseHostAppServices::FindFileHint hint = OdDbBaseHostAppServices::kDefault);
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdGiRasterImageLoader object pointers.
*/
typedef OdSmartPtr<OdGiRasterImageLoader> OdGiRasterImageLoaderPtr;

#include "TD_PackPop.h"

#endif // __ODGIRASTERIMAGELOADER_H__
