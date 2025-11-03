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

#ifndef _ODEDUSERIO_H_INCLUDED_
#define _ODEDUSERIO_H_INCLUDED_

#include "../OdPlatform.h"
#include "../DbExport.h"
#include "../Gi/GiDrawable.h"
#include "../OdString.h"


class OdGePoint3d;
class OdEdFormater;

#include "../TD_PackPush.h"

/** Description: 
  
    {group:TD_Namespaces}
*/
namespace OdEd
{
  enum CommonInputOptions
  {
    kInpDefault       = 0x00000000,
    kInpDisallowEmpty = kInpDefault,
    kInpDisallowOther = kInpDisallowEmpty,
    kInpThrowEmpty    = (long)0x80000000,
    kInpThrowOther    = 0x40000000,
    kInpNonZero       = 0x20000000, // Disallow zero input 
    kInpNonNeg        = 0x10000000  // Disallow negative input 
  };

  enum GetFilePathFlags
  {
    kGfpForOpen  = 0, // For Open.
    kGfpForSave  = 1  // For Save.
  };

  enum GetStringOptions
  {
    kGstDefault      = 0, // Spaces disallowed, no KeywordExceptions
    kGstNoSpaces     = 0, // Spaces disallowed
    kGstAllowSpaces  = 1, // The first space character will not terminate the input.
    kGstNoEmpty      = 2  // The first space character will not terminate the input.
  };

  enum OdDbInputOptions
  {
    kGptDefault         = 0x00000000,
    kGptNoLimCheck      = 0x00000001, // Ignore the LIMMIN and LIMMAX system variables
    kGptNoUCS           = 0x00000002, // Do not project result point onto UCS plane (input point in eye plane)
    kGptRubberBand      = 0x00000004,
    kGptRectFrame       = 0x00000008,
    kGptBeginDrag       = 0x00000010,
    kGptEndDrag         = 0x00000020,
    kGptNoOSnap         = 0x00000040, // Disables object snaps
    kGanFromLastPoint   = 0x00000080,
    kGdsFromLastPoint   = kGanFromLastPoint,
    kGanNoAngBase       = 0x00000100,
    kGds2d              = 0x00000200 // Restrict (getDistance) to 2D
  };

  enum SelectOptions
  {
    kSelDefault         = 0x00000000,
    kSelPickLastPoint   = 0x00000001,
    kSelSingleEntity    = 0x00000002,
    kSelIgnorePickFirst = 0x00000004,
    kSelSinglePass      = 0x00000008,
    kSelAllowEmpty      = 0x00000010,
    kSelRemove          = 0x00000020,
    kSelLeaveHighlighted= 0x00000040,
    kSelAllowInactSpaces= 0x00000080,
    kSelAllowObjects    = 0x00000100,
    kSelAllowPSVP       = 0x00000200,
    kSelAllowSubents    = 0x00000400
  };
}

class OdGsView;
class OdGsModel;

class OdCmColorBase;

//
// OdEd_Classes
//

/** Description:
    This class allows commands to track object
    changes and redraw the entities while user sets parameter values.

    Library: TD_Root
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdInputTracker : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdEdInputTracker);

  virtual int addDrawables(OdGsView* pView) = 0;
  virtual void removeDrawables(OdGsView* pView) = 0;
};

typedef OdSmartPtr<OdEdInputTracker> OdEdInputTrackerPtr;


/** Description:
    This notification interface template allows commands to track object
    changes and redraw the entities while user sets parameter values.

    Library: TD_Root
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdIntegerTracker : public OdEdInputTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdIntegerTracker);

  virtual void setValue(int value) = 0;
};

typedef OdSmartPtr<OdEdIntegerTracker> OdEdIntegerTrackerPtr;


/** Description:
    This notification interface template allows commands to track object
    changes and redraw the entities while user sets parameter values.

    Library: TD_Root
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdRealTracker : public OdEdInputTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdRealTracker);

  virtual void setValue(double value) = 0;
};

typedef OdSmartPtr<OdEdRealTracker> OdEdRealTrackerPtr;


/** Description:
    This notification interface template allows commands to track object
    changes and redraw the entities while user sets parameter values.

    Library: TD_Root
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdStringTracker : public OdEdInputTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdStringTracker);

  virtual void setValue(const OdString& value) = 0;
};

/** Description:
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdPointTracker : public OdEdInputTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdPointTracker);

  virtual void setValue(const OdGePoint3d& value) = 0;
};

typedef OdSmartPtr<OdEdPointTracker> OdEdPointTrackerPtr;


/** Description:
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdPointDefTracker : public OdEdPointTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdPointDefTracker);

  virtual OdGePoint3d basePoint() const = 0;
};

typedef OdSmartPtr<OdEdPointDefTracker> OdEdPointDefTrackerPtr;


/** Description:
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdColorTracker : public OdEdInputTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdColorTracker);

  virtual void setValue(const OdCmColorBase& value) = 0;
};

typedef OdSmartPtr<OdEdColorTracker> OdEdColorTrackerPtr;


//
// OdEd_Exceptions
//

#define OdException OdError


/** Description:
    This class will be thrown whenever the user cancels input from query function of this UserIO object.

    Library: TD_Root
    {group:OdEd_Exceptions}
*/
class FIRSTDLL_EXPORT OdEdException : public OdException
{
protected:
  OdEdException();
  OdEdException(OdErrorContext* pErrCtx);
};


/** Description:
    This class will be thrown whenever the user cancels input from query function of this UserIO object.

    Library: TD_Root
    {group:OdEd_Exceptions}
*/
class FIRSTDLL_EXPORT OdEdCancel : public OdEdException
{
public:
  OdEdCancel();
  OdEdCancel(OdErrorContext* pErrCtx);
};


/** Description:
    This class will be thrown whenever a *keyword* is input to query function of this UserIO object.

    Library: TD_Root
    {group:OdEd_Exceptions}
*/
class FIRSTDLL_EXPORT OdEdKeyword : public OdEdException
{
public:
  OdEdKeyword(int nKeyword, const OdString& sKeyword);

  int keywordIndex() const;
  const OdString& keyword() const;
};


/** Description:

    Library: TD_Root
    {group:OdEd_Exceptions}
*/
class FIRSTDLL_EXPORT OdEdOtherInput : public OdEdCancel
{
public:
  OdEdOtherInput(const OdString& sInput);
  const OdString& string() const;
};


/** Description:

    Library: TD_Root
    {group:OdEd_Exceptions}
*/
class FIRSTDLL_EXPORT OdEdEmptyInput : public OdEdCancel
{
public:
  OdEdEmptyInput();
};


/** Description:
    This class implements non-geometric interactive user IO functionality for custom interactive command objects.
    
    Library: TD_Root
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdEdUserIO : public OdRxObject
{ 
public:
  ODRX_DECLARE_MEMBERS(OdEdUserIO);

  /** Description:
    Returns user input of a keyword.
 
    Arguments:
    prompt (I) Prompt output before pausing for user input.
    keywords (I) Keyword list.
    options (I) Bitwise OR combination of OdEd::CommonInputOptions enum.
    defVal (I) Returned if user input nothing.

    Remarks:
    Returns the *index* of the entered keyword in the *keyword* list, or -1 it's not there.
    
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.  
    
    Note:
    This function does not throw a KeywordException.
  */
  virtual int getKeyword(
    const OdString& prompt,
    const OdString& keywords,
    int defVal = -1,
    int options = OdEd::kInpDefault,
    OdEdIntegerTracker* pTracker = 0) = 0;

  /** Description:
    Returns user input of an integer.
 
    Arguments:
    prompt (I) Prompt output before pausing for user input.
    pTracker (I/O) Pointer to an IO Tracker for this user input.
    options (I) Bitwise OR combination of OdEd::CommonInputOptions enum.
    defVal (I) Returned if user input nothing and OdEd::kInpReturnDefVal flag is set.
    
    Remarks:
    If prompt is empty, a default *prompt* is used.    
    
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.  
  */
  virtual int getInt(
    const OdString& prompt,
    int options = OdEd::kInpDefault,
    int defVal = 0,
    const OdString& keywords = OdString::kEmpty,
    OdEdIntegerTracker* pTracker = 0) = 0;

  /** Description:
    Returns user input of a double.
 
    Arguments:
    prompt (I) Prompt output before pausing for user input.
    options (I) Bitwise OR combination of OdEd::CommonInputOptions enum.
    defVal (I) Returned if user input nothing and OdEd::kInpReturnDefVal flag is set.
    pTracker (I) Pointer to an IO Tracker for this user input.
    
    Remarks:
    If prompt is empty, a default *prompt* is used.    
    
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.  
  */
  virtual double getReal(
    const OdString& prompt, 
    int options = OdEd::kInpDefault,
    double defVal = 0.0,
    const OdString& keywords = OdString::kEmpty,
    OdEdRealTracker* pTracker = 0) = 0;

  /** Description:
    Returns user input of a string.
 
    Arguments:
    options (I) combination of OdEd::CommonInputOptions and OdEd::GetStringOptions enum values.
    prompt (I) Prompt output before pausing for user input.
    pTracker (I) Pointer to an IO Tracker for this user input.
    defValue (I) Default value.
    keywords (I) Keyword string.
    
    Remarks:
    If prompt is empty, a default *prompt* is used.    
    
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.  
  */
  virtual OdString getString(
    const OdString& prompt, 
    int options = OdEd::kInpDefault, 
    const OdString& defValue = OdString::kEmpty,
    const OdString& keywords = OdString::kEmpty,
    OdEdStringTracker* pTracker = 0) = 0;
                                 
  /** Description:
    Writes the specified *string* to the data source associated with this IO User object.
    Arguments:
    string (O) Output *string*.
  */
  virtual void putString(const OdString& string) = 0;

  /** Description:
    Returns user input of a filename obtained in some manner.

    Arguments:
    options (I) combination of OdEd::CommonInputOptions and OdEd::GetFilePathFlags enum values.
    prompt (I) Prompt output before pausing for user input.
    dialogCaption (I) Dialog caption.
    defExt (I) Default file extension without "."
    fileName (I) Initial filename to initialize dialog with.
    filter (I) Filter pattern.
    pTracker (I/O) File path tracker; may be used to display file preview.
    
    Remarks:
    flags must be one of the following:

    @table
    Name                Value   Description
    OdEd::kGfpForOpen   0       For Open.
    OdEd::kGfpForSave   1       For Save.

    The default implementation of this function utilizes getString().  
  */
  virtual OdString getFilePath(
      const OdString& prompt, 
      int options = OdEd::kGfpForOpen,
      const OdString& dialogCaption = OdString::kEmpty, 
      const OdString& defExt = OdString::kEmpty,
      const OdString& fileName = OdString::kEmpty,
      const OdString& filter = OdString::kEmpty,
      const OdString& keywords = OdString::kEmpty,
      OdEdStringTracker*  pTracker = 0);
};

#include "../TD_PackPop.h"

#endif //#ifndef _ODEDUSERIO_H_INCLUDED_
