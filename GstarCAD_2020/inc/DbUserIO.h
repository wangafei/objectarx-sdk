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

#ifndef _ODDBUSERIO_H_INCLUDED_
#define _ODDBUSERIO_H_INCLUDED_

#include "DbExport.h"
#include "OdPlatform.h"
#include "Ed/EdUserIO.h"
#include "DbSSet.h"

class OdDbUnitsFormatter;
class OdCmColor;
class OdDbEntity;
class OdSelectionSet;
class OdGsModel;

/** Description:
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdSSetTracker : public OdEdInputTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdSSetTracker);

  virtual bool append(OdDbStub* id, const OdDbSelectionMethod* pMethod) = 0;
  virtual bool remove(OdDbStub* id, const OdDbSelectionMethod* pMethod) = 0;
};

typedef OdSmartPtr<OdSSetTracker> OdSSetTrackerPtr;

/** Description:
    {group:OdEd_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdEdSSetTracker : public OdSSetTracker
{
public:
  ODRX_DECLARE_MEMBERS(OdEdSSetTracker);

  virtual bool append(OdDbStub* id, const OdDbSelectionMethod* pMethod);
  virtual bool remove(OdDbStub* id, const OdDbSelectionMethod* pMethod);

  virtual bool append(const OdDbObjectId& entId, const OdDbSelectionMethod* pMethod) = 0;
  virtual bool remove(const OdDbObjectId& entId, const OdDbSelectionMethod* pMethod) = 0;
};

typedef OdSmartPtr<OdEdSSetTracker> OdEdSSetTrackerPtr;


/** Description:
    This class implements geometric interactive user IO functionality for custom interactive command objects.
    Library: TD_Db
    {group:OdDb_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdDbUserIO : public OdEdUserIO
{
public:
  ODRX_DECLARE_MEMBERS(OdDbUserIO);

  virtual OdGePoint3d getLASTPOINT() const = 0;

  virtual void setLASTPOINT(const OdGePoint3d& pt) = 0;

  virtual void setPickfirst(OdSelectionSet* pSSet) = 0;

  virtual OdSelectionSetPtr pickfirst() = 0;

  virtual OdEdPointDefTrackerPtr createRubberBand(const OdGePoint3d& base,
                                                  OdGsModel* pModel = NULL) const = 0;

  virtual OdEdPointDefTrackerPtr createRectFrame(const OdGePoint3d& base,
                                                 OdGsModel* pModel = NULL) const = 0;

  /** Description:
    Returns user input of a point.

    Arguments:
    prompt (I) Message displayed to *prompt* the user.
    options (I) Combination of OdEd::GetPointOptions enum values. 
    pDefaultValue (I) Pointer to a default value to return if an empty string is received as input.
    keywords (I) Keyword string.
    pTracker (I) Pointer to a User IO tracker.

    Remarks:
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.
    
    If *prompt* is an empty string, a default *prompt* string is used.  
  */
  virtual OdGePoint3d getPoint(const OdString& prompt,
                               int options = OdEd::kGptDefault,
                               const OdGePoint3d* pDefaultValue  = 0,
                               const OdString& keywords = OdString::kEmpty,
                               OdEdPointTracker* pTracker = 0) = 0;

  /** Description:
    Returns user input of an angle.

    Arguments:
    prompt (I) Message displayed to *prompt* the user.
    options (I) Combination of OdEd::GetPointOptions enum values. 
    defaultValue (I) Default value to return if an empty string is received as input.
    keywords (I) Keyword string.
    pTracker (I) Pointer to a User IO tracker.
    
    Remarks:
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.
    
    If *prompt* is an empty string, a default *prompt* string is used.  
    
    Note:
    All angles are expressed in radians.
  */
  virtual double getAngle(const OdString& prompt,
                          int options = OdEd::kInpDefault,
                          double defaultValue = 0.0,
                          const OdString& keywords = OdString::kEmpty,
                          OdEdRealTracker* pTracker = 0) = 0;

  /** Description:
    Returns user input of a distance.

    Arguments:
    prompt (I) Message displayed to *prompt* the user.
    options (I) Combination of OdEd::GetPointOptions enum values. 
    defaultValue (I) Default value to return if an empty string is received as input.
    keywords (I) Keyword string.
    pTracker (I) Pointer to a User IO tracker.
   
    Remarks:
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.
    
    If *prompt* is an empty string, a default *prompt* string is used.  
  */
  virtual double getDist(const OdString& prompt,
                         int options = OdEd::kInpDefault,
                         double defaultValue = 0.0,
                         const OdString& keywords = OdString::kEmpty,
                         OdEdRealTracker* pTracker = 0) = 0;

  /** Description:
    Returns user input of a color.

    Arguments:
    prompt (I) Message displayed to *prompt* the user.
    options (I) Combination of OdEd::GetPointOptions enum values. 
    pDefaultValue (I) Pointer to a default value to return if an empty string is received as input.
    keywords (I) Keyword string.
    pTracker (I) Pointer to a User IO tracker.
    
    Remarks:
    This function uses the underlying OdEdBaseIO functions putString and getString for low
    level output and input.
    
    If *prompt* is an empty string, a default *prompt* string is used.  
  */
  virtual OdCmColor getColor(const OdString& prompt,
                             int options = OdEd::kInpDefault,
                             const OdCmColor* pDefaultValue = 0,
                             const OdString& keywords = OdString::kEmpty,
                             OdEdColorTracker* pTracker = 0) = 0;

  /** Description:
      Launches interactive object selection to fill selection set.

      Arguments:
      prompt (I) Message displayed to *prompt* the user.
      options (I) Combination of OdEd::GetPointOptions enum values. 
      pDefaultValue (I) Pointer to a default value to return if an empty string is received as input.
      keywords (I) Keyword string.
      pTracker (I) Pointer to a User IO tracker.

      Remarks:
      Each subsequent call to this function modifies current selection set.
      Returned value is guaranteed to be not null.
  */
  virtual OdSelectionSetPtr select(const OdString& prompt = OdString::kEmpty,
                                   int options = OdEd::kSelDefault,
                                   const OdSelectionSet* pDefaultValue = 0,
                                   const OdString& keywords = OdString::kEmpty,
                                   OdSSetTracker* pTracker = 0) = 0;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbUserIO object pointers.
*/
typedef OdSmartPtr<OdDbUserIO> OdDbUserIOPtr;

#endif //#ifndef _ODDBUSERIO_H_INCLUDED_
