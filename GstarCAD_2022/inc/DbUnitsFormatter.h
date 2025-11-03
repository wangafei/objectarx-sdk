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

#ifndef _ODDBUNITSFORMATTER_H_INCLUDED_
#define _ODDBUNITSFORMATTER_H_INCLUDED_

#include "OdUnitsFormatter.h"


class OdGePoint3d;
class OdCmColor;


/** Description:
    This class defines the interface for a Units Formatter. 
    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbUnitsFormatter : public OdUnitsFormatter
{ 
public:
  ODRX_DECLARE_MEMBERS(OdDbUnitsFormatter);

  /** Description:
    Returns the specified color *value* or OdDbColor object as a *string*.
    Arguments:
    value (I) Value to format.
  */
  static OdString formatColor(const OdCmColor& value);

  /** Description:
    Returns the specified *string* as an OdCmColor object.
    Arguments:
    string (I) String to unformat.
  */
  static OdCmColor unformatColor(const OdString& string);

  /** Description:
    Returns the specified distance *value* as a *string*.
    Arguments:
    value (I) Value to format.
    Remarks:
    The returned *value* depends on the DIMZIN, LUNITS, LUPREC, and UNITMODE system variables.
  */
  virtual OdString formatLinear(double value) const = 0;

  /** Description:
    Returns the specified *string* as a distance *value*.
    Arguments:
    string (I) String to unformat.
    Remarks:
    The returned *value* depends on the UNITMODE system variable.
  */
  virtual double unformatLinear(const OdString& string) const = 0;

  /** Description:
    Returns the specified angle *value* as a *string*.
    Arguments:
    value (I) Value to format.
    Remarks:
    The returned *value* depends on the ANGBASE, AUNITS, AUPREC, DIMZIN, and UNITMODE system variables.
    Note:
    All angles are expressed in radians.
  */
  virtual OdString formatAngle(double value) const = 0;

  /** Description:
    Returns the specified *string* as an angle *value*.
    Arguments:
    string (I) String to unformat.
    Remarks:
    The returned *value* depends on the ANGBASE system variable.
    Note:
    All angles are expressed in radians.
  */
  virtual double unformatAngle(const OdString& string) const = 0;

  /** Description:
    Returns the specified WCS angle as an angle in the UCS.
    Arguments:
    wcsAngle (I) WCS angle.
    Note:
    All angles are expressed in radians.
  */
  virtual double toUserAngle(double wcsAngle) const = 0;

  /** Description:
    Returns the specified UCS angle as an angle in the WCS.
    Arguments:
    ucsAngle (I) UCS angle.
    Note:
    All angles are expressed in radians.
  */
  virtual double fromUserAngle(double ucsAngle) const = 0;

  /** Description:
    Returns the specified 3D point *value* as a *string*.
    Arguments:
    value (I) Value to format.
    Remarks:
    The returned *value* depends on the DIMZIN, LUNITS, LUPREC, and UNITMODE system variables.
  */
  virtual OdString formatPoint(const OdGePoint3d& value) const = 0;

  /** Description:
    Returns the specified *string* as a point *value*.
    Arguments:
    string (I) String to unformat.
  */
  virtual OdGePoint3d unformatPoint(const OdString& string) const = 0;

  /** Description:
    Returns the specified WCS *point* as a UCS *point*.
    Arguments:
    wcsPt (I) WCS *point*.
  */
  virtual OdGePoint3d toUCS(const OdGePoint3d& wcsPt) const = 0;

  /** Description:
    Returns the specified UCS *point* as a WCS *point*.
    Arguments:
    ucsPt (I) UCS *point*.
  */
  virtual OdGePoint3d fromUCS(const OdGePoint3d& ucsPt) const = 0;
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbUnitsFormatter object pointers.
*/
typedef OdSmartPtr<OdDbUnitsFormatter> OdDbUnitsFormatterPtr;


#endif //#ifndef _ODDBUNITSFORMATTER_H_INCLUDED_
