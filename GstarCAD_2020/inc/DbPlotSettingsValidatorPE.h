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




#ifndef OD_DBPLOTSETVALPE_H
#define OD_DBPLOTSETVALPE_H

#include "TD_PackPush.h"

#include "RxObject.h"
#include "OdString.h"
#include "DbPlotSettings.h"

/** Description:
    This class is the Plot Settings Validator Protocol Extension class.
   
    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPlotSettingsValidatorPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbPlotSettingsValidatorPE);

  struct psvPaperInfo
  {
    OdString canonicalName;
    OdString localeName;

    double w;
    double h;

    // ImageableArea
    double left;
    double top;
    double right;
    double bottom;

    OdDbPlotSettings::PlotPaperUnits units;

    psvPaperInfo()
      : w(0.)
      , h(0.)
      , left(-HUGE_VAL)
      , top(-HUGE_VAL)
      , right(-HUGE_VAL)
      , bottom(-HUGE_VAL)
      , units(OdDbPlotSettings::kMillimeters)
    {
    }
  };
  
  virtual OdResult getDeviceList(OdArray<OdString> &pDeviceList) = 0;
  virtual OdResult getMediaList(const OdString &deviceName, OdArray<psvPaperInfo> &pMediaList, bool bUpdateMediaMargins) = 0;
  virtual OdResult getDefaultMedia(const OdString &, OdString &) { return Oda::eNotImplemented; }
  virtual OdResult getMediaMargins(const OdString &deviceName, psvPaperInfo &pMediaInfo) = 0;
  virtual OdResult getPlotStyleSheetList(OdArray<OdString> &pPlotStyleSheetList) = 0;
  virtual OdResult getPlotStyleExt(const OdString &, OdString&,OdString &,OdString&,OdString&,OdInt16&) { return Oda::eNotImplemented; }
  virtual OdResult getDefaultDevice(OdString &deviceName) = 0;
  virtual OdResult getDefaultPlotStyleSheet(OdString &plotStyleSheet) = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbPlotSettingsValidatorPE object pointers.
*/
typedef OdSmartPtr<OdDbPlotSettingsValidatorPE> OdDbPlotSettingsValidatorPEPtr;

#include "TD_PackPop.h"

#endif // OD_DBPLOTSETVALPE_H

