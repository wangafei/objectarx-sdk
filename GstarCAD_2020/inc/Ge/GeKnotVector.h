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


#ifndef OD_GE_KNOT_VECTOR
#define OD_GE_KNOT_VECTOR /* {Secret} */

#include "../Ge/GeExport.h"
#include "../Ge/GeGbl.h"
#include "../Ge/GeDoubleArray.h"
#include "../Ge/GeIntArray.h"

class OdGeInterval;

#include "../TD_PackPush.h"

/**
    Description:
    This class represents an ordered series of monotonically increasing doubles used by spline entities.
 
    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeKnotVector
{
public:
  /** Arguments:
    tol (I) Knot equality *tolerance*.
    size (I) Length of vector.
    plusMult (I) Multiplicity increment for each *knot*.
    source (I) Object to be cloned.

  */
  OdGeKnotVector(
    double tol = 1.e-9); 
  OdGeKnotVector(
    int size, 
    int growSize, 
    double tol = 1.e-9);
  OdGeKnotVector(
    int size, 
    const double source[], 
    double tol = 1.e-9);
  OdGeKnotVector(
    int plusMult, 
    const OdGeKnotVector& source);
  OdGeKnotVector(
    const OdGeKnotVector& source);
  OdGeKnotVector(
    const OdGeDoubleArray& source, 
    double tol = 1.e-9);
  ~OdGeKnotVector();

  OdGeKnotVector& operator =(
      const OdGeKnotVector& knotVector);
  OdGeKnotVector& operator =(
      const OdGeDoubleArray& dblArray);

  /**
    Arguments:
    i (I) Index of knot.
    
    Remarks:
    Returns or references the ith knot of the knot vector.
  */
  double& operator [](
    int i);
  double operator [](
    int i) const;
   
  /**
    Description:
    Returns true if and only if knotVector is identical to this one.
    
    Arguments:
    knotVector (I) Knot vector. 
  */
  OdBool isEqualTo (
    const OdGeKnotVector& knotVector) const;

  /**
    Description:
    Returns the first *knot* value of this vector.
  */
  double startParam() const;

  /**
    Description:
    Returns the last *knot* value of this vector.
  */
  double endParam() const;
  
  /**
    Description:
    Returns *knot* multiplicity (repetitions) of the *knot* value at the specified index.
    
    Arguments:
    knotIndex (I) Knot *index*.
    
    Remarks:
    If consecutive *knots* are within the *knot* equality *tolerance*,
    the *knots* are considered identical, and their multiplicities combined.
  */
  int multiplicityAt(
    int knotIndex) const;
    
  /**
    Description:
    Returns the number of intervals between distinct *knots*. 

    Remarks:
    Consecutive *knots* are considered distinct if and only if
    they are not within the *knot* equality *tolerance*.
  */
  int numIntervals() const;
  
  /**
    Description:
    Returns the *knot* *interval*, and the index of the *knot* *interval*, containing the point specified by param. 

    Arguments:
    order (I) The *order* of the spline.
    param (I) Parameter to specify a point on the vector.
    interval (O) Receives the *interval* containing the point specified by param.
    Remarks:
    param must lie between the *knot* values indexed by order -1 and length() - order, where order is the *order* of the spline. 
  */
  int getInterval(
    int order, 
    double param, 
    OdGeInterval& interval) const;

  /**
    Description:
    Returns the number of distinct *knots*. 
    
    Arguments:
    knots (I) Array of *knots*.
    multiplicity (O) Receives an array of multiplicities (repetitions) of each *knot*.

    Remarks:
    If consecutive *knots* are within the *knot* equality *tolerance*,
    the *knots* are considered identical, and their multiplicities combined.
  */    
  void getDistinctKnots(
    OdGeDoubleArray& knots, 
    OdGeIntArray *multiplicity = NULL) const;

  /**
    Description:
    Returns true if an only if the specified parameter is
    between the first and last *knots*.
    
    Arguments:
    param (I) Parameter to be tested. 
  */
  OdBool contains (
    double param) const;

  /**
    Description:
    Returns true if and only if knot is a member of this vector within the *knot* equality *tolerance*.
  */
  OdBool isOn (
    double knot) const;

  /**
    Description:
    Reverses the *order* of this vector, and returns a reference to this vector.
  */
  OdGeKnotVector& reverse();

  /**
    Description:
    Removes the specified *knot* from this vector, and returns a reference to this vector.
    
    Arguments:
    knotIndex (I) Knot *index*.
  */
  OdGeKnotVector& removeAt(
    int knotIndex);

  /**
    Description:
    Removes the specified range of *knots* from this vector, and returns a reference to this vector.
    
    Arguments:
    startIndex (I) Index of the first *knot* to be removed.
    endIndex (I) Index of the last *knot* to be removed.
  */
  OdGeKnotVector& removeSubVector(
    int startIndex, 
    int endIndex);

  /**
    Description:
    Inserts the specified *knot* the specified number of times at the specified index, and returns a reference to 
    this vector.
    
    Arguments:
    knotIndex (I) Knot *index*.
    knot (I) Value to be inserted
    multiplicity (I) Number ot times to *insert* the *knot*.
  */
  OdGeKnotVector& insertAt(
    int knotIndex, 
    double knot, 
    int multiplicity = 1);

  /**
    Description:
    Inserts a knot in the appropriate *knot* interval as specified
    by param, and returns a reference to this vector.
    
    Arguments:
    param (I) Parameter to specify a point on the vector.
    
    Remarks:
    If the specified point is within the *knot* equality *tolerance* of another *knot*,
    said knot's multiplicity is incremented.
  */  
  OdGeKnotVector& insert(
    double param);

  /**
    Description:
    Appends a vector, or single *knot*, to this vector, and returns a reference to this vector, or the value of the single *knot*. 
   
    Arguments:
    knot (I) New last *knot* value.
    tail (I) Knot vector to be appended.
    knotRatio (I) Knot ratio.
    
    Remarks:
    If knotRatio > 0, append performs a linear transformations on this vector and on tail,
    such that the ratio of their lengths is equal to knotRatio, and that tail immediately follows
    this vector. tail is modified by this operation.
  */
  int append(
    double knot);
  OdGeKnotVector& append(
    OdGeKnotVector& tail, 
    double knotRatio = 0.0);

  /**
    Description:
    
    Splits this vector at the point corresponding to param.
    
    Arguments:
    param (I) Parameter to specify a point on the vector.
    pKnotHead (O) Receives the head portion of the *split*.
    multLast (I) Multiplicity of the last *knot* in the head portion.
    pKnotTail (O) Receives the tail portion of the *split*.
    multFirst (I) Multiplicity of the first knot in the tail portion.
  */
  int split(
    double param,
    OdGeKnotVector* pKnotHead,
    int multLast,
    OdGeKnotVector* pKnotTail,
    int multFirst) const;

  /**
    Description:
    Transforms this vector such that the first *knot* has a value
    of lower, and the last *knot* has a value of *upper*, and 
    returns a reference to this vector. 
  
    Arguments:
    lower (I) New *lower* knot.
    upper (I) New *upper* knot.
  */
  OdGeKnotVector& setRange(
    double lower, 
    double upper);

  /**
    Description:
    Returns the *knot* equality *tolerance*.
  */
  double tolerance() const;
  
  /**
    Description:
    Sets the *knot* equality *tolerance* for this vector, 
    and returns a reference to this vector.

    Arguments:
     tol (I) Knot equality *tolerance*.
  */
  OdGeKnotVector& setTolerance(
    double tol); 

  /**
    Description:
    Returns the *length* of this vector.
  */
  int length() const;

  /**
    Description:
    Returns true if and only if length() == 0.
  */
  OdBool isEmpty() const;
  
  /**
    Description:
    Returns the logical *length* of this vector.
    
    Remarks:
    The logical *length* is the number of elements in the array returned
    by asArrayPtr() and getPtr().
  */  
  int logicalLength() const;

  /**
    Description:
    Sets the logical *length* of this vector, 
    and returns a reference to this vector.
    
    Arguments:
    size (I) Logical *length* of vector.
    
    Remarks:
    The logical *length* is the number of elements in the array returned
    by asArrayPtr() and getPtr().
  */  
  OdGeKnotVector& setLogicalLength(
    int size);
    
  int physicalLength() const;
  OdGeKnotVector& setPhysicalLength(int);

  int growLength() const;
  OdGeKnotVector& setGrowLength(int rowLength);

  /**
    Description:
    Returns this vector as an array of doubles.
    
    Remarks:
    The number of elements in this array is returned by
    logicalLength(), and *set* by setLogicalLength().
  */
  const double* getPtr() const;

  /**
    Description:
    Returns this vector as an array of doubles.
    
    Remarks:
    The number of elements in this array is returned by
    logicalLength(), and *set* by setLogicalLength().
  */
  const double* asArrayPtr() const;
  double* asArrayPtr();

  /**
    Description:
    Sets the parameters for this vector according to the arguments, 
    and returns a reference to this vector.

    Arguments:
    tol (I) Knot equality *tolerance*.
    size (I) Length of vector.
  */
  OdGeKnotVector& set(
    int size, 
    const double source[], 
    double tol = 1.e-9);

  int multiplicityAt(
    double param) const;

  OdGeDoubleArray& getArray();
  const OdGeDoubleArray& getArray() const;

protected:
  /** Description:
    Returns true if and only if index < length()
    
    Arguments:
    knotIndex (I) Knot *index*.
  */
   OdBool isValid(
    OdUInt32 knotIndex) const;

   OdGeDoubleArray m_Data;
   double m_Tolerance;
};

#include "../TD_PackPop.h"

#endif // OD_GE_KNOT_VECTOR

