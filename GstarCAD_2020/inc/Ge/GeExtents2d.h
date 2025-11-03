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




#ifndef _ODGEEXTENTS2D_INCLUDED_
#define _ODGEEXTENTS2D_INCLUDED_ /* {Secret} */


#include "../Ge/GePoint2d.h"
#include "../Ge/GeVector2d.h"
#include "../Ge/GeMatrix2d.h"

#include "../TD_PackPush.h"

#define INVALIDEXTENTS 1.0e20 /* {Secret} */

/**
    Description:
    This class represents 2D bounding boxes as minimum and maximum 2d points.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeExtents2d
{
public:

  /**
    Arguments:
    min (I) Minimum *point*.
    max (I) Maximum *point*.
  */
  OdGeExtents2d ()
    : m_min (INVALIDEXTENTS,  INVALIDEXTENTS)
    , m_max (-INVALIDEXTENTS, -INVALIDEXTENTS)
  {}

  OdGeExtents2d (
    const OdGePoint2d& min, 
    const OdGePoint2d& max) 
  { set (min, max); }

  /**
    Description:
    Returns the minimum *point* of this Extents object.
  */
  const OdGePoint2d& minPoint () const 
  { return m_min; }

  /**
    Description:
    Returns the maximum *point* of this Extents object.
  */
  const OdGePoint2d& maxPoint () const 
  { return m_max; }

  /**
    Description:
    Sets the minimum and maximum points for this Extents object.
    
    Arguments:
    min (I) Minimum *point*.
    max (I) Maximum *point*.
  */
  void set (
    const OdGePoint2d& min, 
    const OdGePoint2d& max) 
  { 
    m_min = min;
    m_max = max;
  }

  void compareSet(
    const OdGePoint2d& p1, 
    const OdGePoint2d& p2) 
  {
    if (p1.x < p2.x)
    {
      m_min.x = p1.x;
      m_max.x = p2.x;
    }
    else
    {
      m_min.x = p2.x;
      m_max.x = p1.x;
    }
    if (p1.y < p2.y)
    {
      m_min.y = p1.y;
      m_max.y = p2.y;
    }
    else
    {
      m_min.y = p2.y;
      m_max.y = p1.y;
    }
  }

  /**
    Description:
    Updates the *extents* of this Extents object with the specified *point*.

    Arguments:
    point (I) Any 2D *point*.
  */
  void addPoint (
    const OdGePoint2d& point)
  {
    if ( !isValidExtents() )
    {
      m_max = m_min = point;
    }
    else
    {
      m_max.x = odmax (point.x, m_max.x);
      m_max.y = odmax (point.y, m_max.y);
      m_min.x = odmin (point.x, m_min.x);
      m_min.y = odmin (point.y, m_min.y);
    }
  }
    

  /**
    Description:
    Updates the *extents* of this Extents object with the specified Extents object.
    
    Arguments:
    extents (I) Any 2D Extents object.
  */
  void addExt (
    const OdGeExtents2d& extents)
  {
    if (extents.isValidExtents ())
    {
      addPoint (extents.minPoint ());
      addPoint (extents.maxPoint ());
    }
  }

  /**
    Description:
    Returns true if and only if this Extents object *contains* valid *extents*.
    
    Remarks:
    Extents are valid if and only if each member of the minimum *extents* 
    is less than or equal to the corresponding member of maximum *extents*.
  */
  bool isValidExtents () const
  {
    return ( (m_max.x >= m_min.x) && (m_max.y >= m_min.y) );
  }

  /* Description:
    Updates the *extents* of this Extents object by the specified vector.
    Arguments:
    vect (I) Any 2D vector.
  */  
  void expandBy (
    const OdGeVector2d& vect)
  {
    if (isValidExtents ())
    {
      OdGePoint2d p1 = m_min, p2 = m_max;
      p1 += vect;
      p2 += vect;
      addPoint (p1);
      addPoint (p2);
    }
  }

  /**
    Description:
    Applies the 2D transformation matrix to the *extents*.

    Arguments:
    xfm (I) 2D transformation matrix.
  */
  void transformBy (
    const OdGeMatrix2d& xfm)
  {
    OdGeVector2d vecX (OdGeVector2d::kXAxis * (m_max.x - m_min.x)),
      vecY (OdGeVector2d::kYAxis * (m_max.y - m_min.y));

    if (isValidExtents ())
    {
      m_max = m_min = (xfm * m_min);
      expandBy (xfm * vecX);
      expandBy (xfm * vecY);
    }
  }
   
    
  /**
    Description:
    Returns true if and only if this Extents object *contains* the specified object.
    
    Arguments:
    point (I) Any 2D *point*.
    extents (I) Any 2D Extents object.
  */
  bool contains (
    const OdGePoint2d& point) const
  {
    return ( point.x >= m_min.x  &&  point.y >= m_min.y  &&
              point.x <= m_max.x  &&  point.y <= m_max.y );
  }

  bool contains (
    const OdGeExtents2d& extents) const
  {
    return (extents.m_min.x >=         m_min.x && extents.m_min.y >=     m_min.y      &&
                    m_max.x >= extents.m_max.x &&          m_max.y >= extents.m_max.y );
  }


  /**
    Description:
    Returns true if and only if specified Extents object
    does not intersect this one.

    Arguments:
    extents (I) Any 2D Extents object.
  */
  bool isDisjoint (
    const OdGeExtents2d& extents) const
  {
    return (extents.m_min.x >         m_max.x || extents.m_min.y >         m_max.y ||
                    m_min.x > extents.m_max.x ||         m_min.y > extents.m_max.y );
  }    

  enum IntersectionStatus
  {
    kIntersectUnknown,// Either or both extents are invalid
    kIntersectNot,    // Extents are NOT intersecting
    kIntersectOpIn,   // Operand is completely within this extents
    kIntersectOpOut,  // This extents is completely within operand
    kIntersectOk      // Extents are intersecting, result is returned
  };

  /**
    Description:
    Determines the intersection of the specified Extents object with this one,
    and returns the resulting intersection box.
    
    Arguments:
    extents (I) Any 2D Extents object.
    pResult (O) Receives extents of the intersection.
    
    Remarks:
    pResult object should be created by the caller. Possible return values are as follows.
    
    @untitled table
    kIntersectUnknown   Either or both Extents objects are invalid
    kIntersectNot       The Extents objects are NOT intersecting
    kIntersectOpIn      The specified Extents object is completely within this one
    kIntersectOpOut     This Extents object is completely within the specified one
    kIntersectOk        The Extents objectes are intersecting, and a result is returned
    
  */
  IntersectionStatus intersectWith (
    const OdGeExtents2d& extents, 
    OdGeExtents2d* pResult = 0) const;

protected:
  OdGePoint2d m_min;
  OdGePoint2d m_max;
};


#undef INVALIDEXTENTS

#include "../TD_PackPop.h"

#endif //_ODGEEXTENTS2D_INCLUDED_


