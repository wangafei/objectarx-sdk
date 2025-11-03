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

#ifndef _OD_UNITSFORMATTER_H_INCLUDED_
#define _OD_UNITSFORMATTER_H_INCLUDED_

#include "OdPlatform.h"
#include "DbExport.h"
#include "RxObject.h"
#include "OdString.h"
#include "OdDToStr.h"


class OdGePoint3d;


/** Description:
    This class defines the interface for a Units Formatter. 
    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdUnitsFormatter : public OdRxObject
{ 
public:
  ODRX_DECLARE_MEMBERS(OdUnitsFormatter);

  enum LUnits
  {
    kScientific    = 1,
    kDecimal       = 2,
    kEngineering   = 3, // feet and decimal inches
    kArchitectural = 4, // feet and fractional inches
    kFractional    = 5,
    kWindowsDesktop = 6
  };

  enum DimzinValues
  {
    kSuppressesZeroFeetAndPreciselyZeroInches = 0,
    kIncludesZeroFeetAndPreciselyZeroInches   = 1,
    kIncludesZeroFeetAndSuppressesZeroInches  = 2,
    kIncludesZeroInchesAndSuppressesZeroFeet  = 3,
    // for dimentions
    kSuppressesLeadingZeros                   = 4,
    kSuppressesTrailingZeros                  = 8,
    kSuppressesBothLeadingAndTrailingZeros    = 12
  };

  static bool isZeroFeetSuppressed(int dimzin);
  static bool isZeroInchesSuppressed(int dimzin);

  /** Description:  
    Returns the specified distance *value* as a *string*.
    Arguments:
    value (I) Value to format.
    lUnits (I) Length units. 
    precision (I) Number of decimal places.
    dimzin (I) A combination of ZeroSuppressionFlags.
    unitMode (I) UNITMODE *value*.
    decsep (I) Decimal separator.
    thsep (I) Thousands separator.
    Remarks:
    o  A zero *value* for decsep specifies the default seoarator is to be used.
    o  A zero *value* for thsep specifies that no separator is to be used.
  */
  static OdString formatL(double value, LUnits lUnits, int precision, int dimzin, int unitMode, OdChar decsep = 0, OdChar thsep = 0);
  static OdString formatArea(double value, LUnits lUnits, int precision, int dimzin, int unitMode, OdChar decsep = 0, OdChar thsep = 0);

  /** Description:  
    Returns the specified length *string* as a length *value*.
    Arguments:
    string (I) String to unformat.
  */
  static double unformatL(const OdString& string);

  enum AUnits
  {
    kDegrees    = 0,
    kDegMinSec  = 1,
    kGrads      = 2,
    kRadians    = 3,
    kSurveyors  = 4
  };


  /** Description:  
    Returns the specified angular *value* as a *string*.
    Arguments:
    value (I) Value to format.
    aUnits (I) Angle units. 
    precision (I) Number of decimal places.
    dimzin (I) A combination of ZeroSuppressionFlags.
    unitMode (I) UNITMODE *value*.
    decsep (I) Decimal separator.
    Remarks:
    o  A zero *value* for decsep specifies the default separator is to be used.
    Note:
    All angles are expressed as radians.
  */
  static OdString formatA(double value, AUnits aUnits, int precision, int dimzin, int unitMode, OdChar decsep = 0);

  /** Description:  
    Returns the specified *string* as an angular *value*.
    Arguments:
    string (I) String to unformat.
    Note:
    All angles are expressed as radians.
  */
  static double unformatA(const OdString& string);
  static double unformatA_unnorm(const OdString& string);

private:
  static OdString _formatL(double value, bool isItArea, LUnits lUnits, int precision, int dimzin, int unitMode, OdChar decsep = 0, OdChar thsep = 0);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbUnitsFormatter object pointers.
*/
typedef OdSmartPtr<OdUnitsFormatter> OdUnitsFormatterPtr;


class ODRX_ABSTRACT FIRSTDLL_EXPORT OdUnitsFormatterTool
{ 
public:
  OdUnitsFormatterTool()  {}
  ~OdUnitsFormatterTool() {}

  static OdString formatDecimal(double value, int precision, int dimzin, OdChar decsep, OdChar thsep = 0);
  static double angle(const OdChar*& buf);
  static int toInt(const OdString& sValue, int nMinValid = INT_MIN, int nMaxValid = INT_MAX);
  static bool isZero(double v, int precision);
  static OdString formatArchitectural(bool isNegative, int feet, int entier, int numerator, int denominator, int dimzin, int mode);
  static bool negative(const OdChar*& buf);
  static double integer(const OdChar*& buf);
  static double number(const OdChar*& buf, bool isExponentPossible = true);

  static void fraction(double value, int& entier, int& numerator, int& denominator, int precision)
  {
    denominator = 1 << precision;
    value = double(int(value * denominator + 0.5)) / double(denominator);
    entier = int(floor(value));
    numerator = int((value - entier) * double(denominator));
    while((numerator % 2) == 0 && (numerator != 0))
    {
      numerator   /= 2;
      denominator /= 2;
    }
  }

  static double base_denominator(int prec, double base)
  {
    double denom = 1.;
    for(int i = 0; i < prec; ++i)
      denom *= base;
    return denom;
  }

  static double linear_denominator(int prec)
  {
    return base_denominator(prec, 10.);
  }

  static bool digit(OdChar c)
  {
    return (c >= '0' && c <= '9');
  }

  static double denominator(int prec)
  {
    double denom = 1.;
    switch(prec)
    {
    default:
    {
      for(int i = prec; i >= 5; i--)
        denom *= 10.;
    }
      //case 8: // 19d58'58.8889"
      //  denom *= 10;
      //case 7: // 19d58'58.889"
      //  denom *= 10;
      //case 6: // 19d58'58.89"
      //  denom *= 10;
      //case 5: // 19d58'58.9"
      //  denom *= 10;
    case 4: // 19d58'59"
    case 3:
      denom *= 60;
    case 2: // 19d59'
    case 1:
      denom *= 60;
    case 0: // 20d
      break;
    }
    return denom;
  }

  static void decomp(double v, int& degs, int& mins, double& secs, int prec)
  {
    double denom = denominator(prec);
    v = floor(v * denom + 0.5) / double(denom);
    degs = int(floor(v));
    v -= degs;
    v *= 60.;
  
    v = floor(v * denom + 0.5) / double(denom);
    mins = int(floor(v));
    v -= mins; 
    secs = v * 60.;
  }

  static OdString format(int degs, int mins, double secs, int prec)
  {
      OdString res;
      switch (prec)
      {
      case 0:
        res.format(OD_T("%dd"), degs);
        break;
      case 1:
      case 2:
        res.format(OD_T("%dd%d'"), degs, mins);
        break;
      case 3:
        prec = 4;
        // no break
      default:
        prec -= 4;
        OdString s = odDToStr(secs, 'f', prec);
        res.format(OD_T("%dd%d'%ls\""), degs, mins, s.c_str());
        break;
      }

    return res;
  }

  static OdString next(OdString& list, const OdChar* delim = OD_T(","))
  {
    OdString res = list.spanExcluding(delim);
    if(res.getLength() != list.getLength())
    {
      list = list.mid(res.getLength()+1);
    }
    else
    {
      list.empty();
    }
    return res;
  }

  static int countOccurences(const OdString& string, OdChar delim = ',')
  {
    int nOccurences = 0;
    int nDigits = 0;
    int nSpec = 0;
    const OdChar *pBuffer = string.c_str();
    while (*pBuffer)
    {
      if (*pBuffer >= '0' && *pBuffer <= '9')
        nDigits++;
      else if (*pBuffer == '+' || *pBuffer == '-')
      {
        nSpec++;
        if (nDigits > 0)
          break;
        }
      else if (*pBuffer == delim && nDigits > 0 && nSpec <= 1)
      {
        nDigits = nSpec = 0;
        nOccurences++;
      }
      else
        break;
      pBuffer++;
    } 
    return nOccurences;
  }
};

#endif //#ifndef _OD_UNITSFORMATTER_H_INCLUDED_
