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

#ifndef _OdFontServices_h_Included_
#define _OdFontServices_h_Included_

#include "RxObject.h"
#include "DbBaseDatabase.h"
#include "Gi/GiTextStyle.h"
#include "Gi/GiExport.h"

/** Description:
    This class is the base class for classes that provide platform-dependent font services for Teigha.

    Library: TD_Gi
    {group:Other_Classes}
*/
class FIRSTDLL_EXPORT OdFontServices : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdFontServices);
  /** Description:
    Returns the specified OdGiTextStyle record for the specified OdDbDatabase object.
    Arguments:
    textStyle (O) Receives the TextStyle record.
    pDb (I) Pointer to the *database*.
  */
  virtual int loadStyleRec(OdGiTextStyle& textStyle, OdDbBaseDatabase* pDb) const = 0;
  /** Description:
    Returns the FontFilePath for the specified OdGiTextStyle and OdDbDatabase objects.
    Arguments:
    textStyle (I) TextStyle object.
    pDb (I) Pointer to the *database*.
  */
  virtual OdString getFontFilePath(OdGiTextStyle& textStyle, OdDbBaseDatabase* pDb) const = 0;
  /** Description:
    Returns the BigFontFilePath for the specified OdGiTextStyle and OdDbDatabase objects.
    Arguments:
    textStyle (I) TextStyle object.
    pDb (I) Pointer to the *database*.
  */
  virtual OdString getBigFontFilePath(OdGiTextStyle& textStyle, OdDbBaseDatabase* pDb) const = 0;
  /** Description:
    Returns the default OdFont object associated with this FontServices object.
  */
  virtual OdFontPtr defaultFont() const = 0;
  /** Description:
    Returns true when the an OdFont object associated with bigFontName.
  */
  virtual OdBool isBigFontLoaded(const OdString& bigFontName) const = 0;
};

#define ODDB_FONT_SERVICES OD_T("OdDbFontServices")

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdFontServices object pointers.
*/
typedef OdSmartPtr<OdFontServices> OdFontServicesPtr;

#endif
