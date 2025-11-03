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


#ifndef OD_GE_INTERVAL_H
#define OD_GE_INTERVAL_H /* {Secret} */

#include "../Ge/GeExport.h"
#include "../Ge/GeGbl.h"
#include "../TD_PackPush.h"

/**
    Description:
    This class represents a finite, infinite, or semi-infinite
    interval as the real axis.
  
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeInterval
{
public:
  /**
    Arguments:
    lower (I) Lower *bound*.
    upper (I) Upper *bound*.
    tol (I) Boundary *tolerance*.
    boundedBelow (I) Determines if *bound* specifies a *lower* or an *upper* *bound*.
    bound (I) Specifies a *lower* *bound* if boundedBelow is true, or an *upper*
              *bound* if it is false.     

    Remarks:
    With no arguments other than tol, creates an unbounded interval.
  */
  OdGeInterval(
    double tol = 1.e-12);
  OdGeInterval(
    const OdGeInterval& interval);
  OdGeInterval(
    double lower,
    double upper,
    double tol = 1.e-12);
  OdGeInterval(
    OdBool boundedBelow,
    double bound,
    double tol = 1.e-12);

  ~OdGeInterval();

  OdGeInterval& operator =(const OdGeInterval& interval);

  /** 
    Description:
    Returns the *lower* *bound* of this interval.
    
    Remarks:
    This value is meaningful if and only if the interval has a *lower* *bound*.
  */
  double lowerBound() const;

  /** 
    Description:
    Returns the *upper* *bound* of this interval.
    
    Remarks:
    This value is meaningful if and only if the interval has an *upper* *bound*.
  */
  double upperBound() const;

  /**
    Description:
    Returns a point on this interval.
    
    Remarks:
    @table
    Bounded Above   Bounded Below          Returns
    Yes             ---                    Upper Bound
    No              Yes                    Lower Bound
    No              No                     0.0

   */  
  double element() const;

  /** 
    Description:
    Returns the bounds of this interval.
    
    Arguments:
    lower (O) Receives the Lower *bound*.
    upper (O) Receives the Upper *bound*.
  */
  void getBounds(
    double& lower,
    double& upper) const;
    
  /** \details
  Returns the parameter of interval's end.

  \param index  Must be 0 (interval start) or 1 (interval end), otherwise behavior is undefined.
  */
  double getEnd(
    int index) const;

  /** \details
    Returns the length of this interval.
    
    \returns
    Returns -1.0 if this interval is unbounded above or below.
  */
  double length() const;
  
  /**
    Description:
    Returns the boundary *tolerance* for this interval.
  */
  double tolerance() const;

  /**
    Description:
    Sets the parameters for this interval according to the arguments.

    Arguments:
    lower (I) Lower *bound*.
    upper (I) Upper *bound*.
    boundedBelow (I) Determines if bound specifies a *lower* or an *upper* *bound*.
    bound (I) Specifies a *lower* *bound* if boundedBelow is true, or an *upper*
              *bound* if it is false.
              
    Remarks:
    Returns a reference to this interval.
    
    If called with no parameters, unbounds this interval.     
  */
  OdGeInterval& set(
    double lower,
    double upper);
  OdGeInterval& set(
    OdBool boundedBelow,
    double bound);
  OdGeInterval& set();

  /**
    Description:
    Sets the *upper* *bound* for this interval.

    Arguments:
    upper (I) Upper *bound*.
    
  */
  OdGeInterval& setUpper(
    double upper);
    
  /**
    Description:
    Sets the *lower* *bound* for this interval.

    Arguments:
    *lower* (I) Lower *bound*.
    Remarks:
    Returns a reference to this interval.
  */
  OdGeInterval& setLower(
    double lower);

  /**
    Description:
    Sets the boundary *tolerance* for this interval.

    Arguments:
    tol (I) Boundary *tolerance*.

    Remarks:
    Returns a reference to this interval.
  */
  OdGeInterval& setTolerance(
    double tol);

  /**
    Description:
    Returns the smallest interval containing both the specified interval and this interval.

    Arguments:
    otherInterval (I) The interval to be merged with this one.
    result (O) Receives the merged interval.
  */
  void getMerge(
    const OdGeInterval& otherInterval,
    OdGeInterval& result) const;
    
  /**
    Description:
    Subtracts the specified interval from this interval.
    Remarks:
    Returns the number of intervals, and the intervals, resulting from the subtraction

    Arguments:
    otherInterval (I) The interval to be subtracted from this one.
    lInterval (O) Receives the Left (or only) interval.
    rInterval (O) Receives the right interval.
    
    Remarks:
    @table
    return value   Results
    0              Empty result
    1              Single interval in lInterval
    2              Left in lInterval, Right in rInterval.
  */
  int subtract(
    const OdGeInterval& otherInterval,
    OdGeInterval& lInterval,
    OdGeInterval& rInterval) const;

  /**
    Description:
    Intersects the specified interval from this one.
    Remarks:
    Returns true if and only this specified interval intersects with this one, 
    and the interval of intersection.

    Arguments:
    otherInterval (I) The interval to be intersected.
    result (O) Receives the intersected interval.
  */
  OdBool intersectWith(
    const OdGeInterval& otherInterval,
    OdGeInterval& result) const;
  bool finiteIntersectWith(const OdGeInterval& range, OdGeInterval& result) const;
    
  /**
    Description:
    Returns true if and only if this interval is bounded above and below.
  */
  OdBool isBounded() const;
    
  /**
    Description:
    Returns true if and only if this interval is bounded above.
  */
  OdBool isBoundedAbove() const;
    
  /**
    Description:
    Returns true if and only if this interval is bounded below.
  */
  OdBool isBoundedBelow() const;

  /**
    Description:
    Returns true if and only if this interval is unbounded above or below.
  */
  OdBool isUnBounded() const;
  
  /**
    Description:
    Returns true if and only if this interval object is a singleton.
    Remarks:
    Returns true if and only if this interval is bounded, and the *upper* and *lower* bounds are equal within tolerance().
  */
  OdBool isSingleton() const;

  /**
    Description:
    Returns true if and only if the specified interval is disjoint from this interval.
    Remarks:
    Returns true if and only if this interval does not intersect otherInterval within tolerance().
    
    Arguments:
    otherInterval (I) The interval to be tested.
  */
  OdBool isDisjoint(
    const OdGeInterval& otherInterval) const;

  /**
    Description:
    Returns true if and only if this interval *contains* the specified *value* or Interval.
    Remarks:
    Returns true if and only if this Interval *contains* value or otherInterval within tolerance().
    
    Arguments:
    otherInterval (I) The Interval to be tested.
    value (I) The *value* to be tested.
  */
  OdBool contains(
    const OdGeInterval& otherInterval) const;
  OdBool contains(
    double value) const;

  /**
    Description:
    Returns true if and only if the specified Interval is continuous with the upper bound of this Interval.
    Remarks:
    Returns true if and only if this Interval is bounded above, otherInterval is bounded below, 
    and the *upper* bound of this Interval is equal to the *lower* bound of otherInterval within tolerance().
    
    Arguments:
    otherInterval (I) The Interval to be tested.
  */
  OdBool isContinuousAtUpper(
    const OdGeInterval& otherInterval) const;

  /**
    Description:
    Returns true if and only if the specified Interval and this Interval overlap at the upper bound of this Interval.
    Remarks:
    Returns true if and only if
     
    1.  This Interval is bounded above, otherInterval is bounded below. 
    2.  Neither Interval is a singleton.
    3.  The Intervals Intersect.
    4.  otherInterval does not contain this one.
    5.  The *upper* bound of this Interval is contained in otherInterval.
    6.  The *lower* bound of otherInterval is contained within this one. 
    
    If all these conditions are met, this function returns the intersection of the Intervals.
    
    Arguments:
    otherInterval (I) The Interval to be tested.
    overlap (O) Receives the *overlap* of the Intervals.
  */
  OdBool isOverlapAtUpper(
    const OdGeInterval& otherInterval,
    OdGeInterval& overlap) const;

  OdBool operator ==(
    const OdGeInterval& otherInterval) const;
  OdBool operator !=(
    const OdGeInterval& otherInterval) const;
    
  /**
    Description:
    Returns true if and only if upper bounds of the specified Interval and this Interval are equal.
    Remarks:
    
    Returns true if and only if
    
    1. Both this Interval and otherInterval are unbounded above or bounded 
       above with their *upper* bounds equal within tolerance().
    2. This Interval is bounded above, and the *upper* bound is equal to value within tolerance(). 

    Arguments:
    otherInterval (I) The Interval to be tested.
    value (I) The *value* to be tested.
 */
  OdBool isEqualAtUpper(
    const OdGeInterval& otherInterval) const;
  OdBool isEqualAtUpper(
    double value) const;
    
  /**
    Description:
    Returns true if and only if lower bounds of the specified Interval and this Interval are equal.
    Remarks:
    Returns true if and only if
    
    1. Both this Interval and otherInterval are unbounded below or bounded 
       below with their *lower* bounds equal within tolerance.
    2. This Interval is bounded below, and the *lower* bound is equal to value within tolerance. 

    
    Arguments:
    otherInterval (I) The Interval to be tested.
    value (I) The *value* to be tested.
  */
  OdBool isEqualAtLower(
    const OdGeInterval& otherInterval) const;
  OdBool isEqualAtLower(
    double value) const;

  /**
    Description:
    Returns true if and only if the specified value is periodically on this Interval.
    Remarks:
    Returns true if and only if there is a positive integer N such that
    
            value + N * period
            
    is on this Interval. If so, returns that *value*.         
    
    Arguments:
    period (I) Period.
    value (I/O) Value.
  */
  OdBool isPeriodicallyOn(
    double period,
    double& value);

  friend 
    GE_TOOLKIT_EXPORT OdBool operator > (
    double value,
    const OdGeInterval& interval);
  OdBool operator > (
    double value) const;
  OdBool operator > (
    const OdGeInterval& otherInterval) const;
  friend 
    GE_TOOLKIT_EXPORT OdBool operator >= (
    double value,
    const OdGeInterval& interval);
  OdBool operator >= (
    double value) const;
  OdBool operator >= (
    const OdGeInterval& otherInterval) const;
  friend 
    GE_TOOLKIT_EXPORT OdBool operator < (
    double value,
    const OdGeInterval& interval);
  OdBool operator < (
    double value) const;
  OdBool operator < (
    const OdGeInterval& otherInterval) const;
  friend 
    GE_TOOLKIT_EXPORT OdBool operator <= (
    double value,
    const OdGeInterval& interval);
  OdBool operator <= (
    double value) const;
  OdBool operator <= (
    const OdGeInterval& otherInterval) const;

private:
  double m_LowerParam;
  double m_UpperParam;
  double m_Tol;
  OdBool m_bBoundedAbove;
  OdBool m_bBoundedBelow;
};

#include "../TD_PackPop.h"
#endif // OD_GE_INTERVAL_H

