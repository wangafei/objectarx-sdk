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




#ifndef _ODGEEXTENTS3D_INCLUDED_
#define _ODGEEXTENTS3D_INCLUDED_ /* {Secret} */


#include "../Ge/GePoint3d.h"
#include "../Ge/GeVector3d.h"
#include "../Ge/GeMatrix3d.h"

#include "../TD_PackPush.h"

#define INVALIDEXTENTS 1.0e20  /* {Secret} */

/**
    Description:
    This class represents 3D bounding boxes as minimum and maximum 3d points.

    Library: TD_Ge

    {group:OdGe_Classes} 
*/
class GE_TOOLKIT_EXPORT OdGeExtents3d
{
public:

  /**
    Arguments:
    min (I) Minimum *point*.
    max (I) Maximum *point*.
  */
  OdGeExtents3d();

  OdGeExtents3d(
    const OdGePoint3d& min, 
    const OdGePoint3d& max);

  /**
    Description:
    Returns the minimum *point* of this Extents object.
  */
  const OdGePoint3d& minPoint() const;

  /**
    Description:
    Returns the maximum *point* of this Extents object.
  */
  const OdGePoint3d& maxPoint() const;

  /**
    Description:
    Sets the minimum and maximum points for this Extents object.
    
    Arguments:
    min (I) Minimum *point*.
    max (I) Maximum *point*.
  */
  OdResult set( // Gcad(Modify)
    const OdGePoint3d& min, 
    const OdGePoint3d& max);

  /**
    Description:
    Sets the minimum and maximum points for this Extents object to
    that of the box defined by pt1 and pt2.
    
    Arguments:
    pt1 (I) First *point*.
    pt2 (I) Second *point*.

    Remarks:
    pt1 and pt2 need only define a box. They need not be the minimum
    and maximum points of the box.
  */
  void comparingSet(
    const OdGePoint3d& pt1, 
    const OdGePoint3d& pt2);

  /**
    Description:
    Updates the *extents* of this Extents object with the specified *point*.

    Arguments:
    point (I) Any 3D *point*.
  */
  void addPoint(
    const OdGePoint3d& point);

  /**
    Description:
    Updates the *extents* of this Extents object with the specified Extents object.
    
    Arguments:
    extents (I) Any 3D Extents object.
  */
  void addExt(
    const OdGeExtents3d& extents);

  /**
    Description:
    Returns true if and only if this Extents object *contains* valid *extents*.
    
    Remarks:
    Extents are valid if and only if each member of the minimum *extents* 
    is less than or equal to the corresponding member of maximum *extents*.
  */
  inline bool isValidExtents() const
  {
    return ( (m_max.x >= m_min.x) && (m_max.y >= m_min.y) && (m_max.z >= m_min.z));
  }

  /* Description:
    Updates the *extents* of this Extents object by the specified vector.
    Arguments:
    vect (I) Any 3D vector.
  */  
  void expandBy(
    const OdGeVector3d& vect);

  /**
    Description:
    Applies the 3D transformation matrix to the *extents*.

    Arguments:
    xfm (I) 3D transformation matrix.
  */
  void transformBy(
    const OdGeMatrix3d& xfm);
    
  /**
    Description:
    Returns true if and only if this Extents object *contains* the specified object.
    
    Arguments:
    point (I) Any 3D *point*.
    extents (I) Any 3D Extents object.
  */
  bool contains(
    const OdGePoint3d& point, const OdGeTol& tol = OdGeContext::gTol) const;

  bool contains(
    const OdGeExtents3d& extents, const OdGeTol& tol = OdGeContext::gTol) const;

  /**
    Description:
    Returns true if and only if specified Extents object
    does not intersect this one.

    Arguments:
    extents (I) Any 3D Extents object.
  */
  bool isDisjoint(
    const OdGeExtents3d& extents, const OdGeTol& tol = OdGeContext::gTol) const;

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
    extents (I) Any 3D Extents object.
    pResult (O) Receives extents of the intersection.
    
    Remarks:
    pResult object should be created by the caller. Possible return values are as follows.
    
    @untitled table
    kIntersectUnknown   Either or both *extents* boxes are invalid
    kIntersectNot       The *extents* boxes are NOT intersecting
    kIntersectOpIn      The specified Extents object is completely within this one
    kIntersectOpOut     This Extents object is completely within the specified one
    kIntersectOk        The *extents* boxes are intersecting, and a result is returned
    
  */
  IntersectionStatus intersectWith(const OdGeExtents3d& extents, OdGeExtents3d* pResult = 0) const;

  OdGePoint3d center() const
  {
    return (m_min + m_max.asVector()) / 2.;
  }
protected:
  OdGePoint3d m_min;
  OdGePoint3d m_max;
};



inline OdGeExtents3d::OdGeExtents3d()
  : m_min(INVALIDEXTENTS,  INVALIDEXTENTS,  INVALIDEXTENTS)
  , m_max(-INVALIDEXTENTS, -INVALIDEXTENTS, -INVALIDEXTENTS)
{
}

inline OdGeExtents3d::OdGeExtents3d(const OdGePoint3d& min, const OdGePoint3d& max)
  : m_min(min)
  , m_max(max)
{
}

inline const OdGePoint3d& OdGeExtents3d::minPoint() const
{
  return m_min;
}

inline const OdGePoint3d& OdGeExtents3d::maxPoint() const
{
  return m_max;
}

// Gcad(Modify)
inline OdResult OdGeExtents3d::set(const OdGePoint3d& min, const OdGePoint3d& max)
{
  m_min = min;
  m_max = max;
  return Oda::eOk;
}

inline void OdGeExtents3d::comparingSet(const OdGePoint3d& pt1, const OdGePoint3d& pt2)
{
  if(pt1.x > pt2.x)
  {
    m_max.x = pt1.x;
    m_min.x = pt2.x;
  }
  else
  {
    m_min.x = pt1.x;
    m_max.x = pt2.x;
  }
  if(pt1.y > pt2.y)
  {
    m_max.y = pt1.y;
    m_min.y = pt2.y;
  }
  else
  {
    m_min.y = pt1.y;
    m_max.y = pt2.y;
  }
  if(pt1.z > pt2.z)
  {
    m_max.z = pt1.z;
    m_min.z = pt2.z;
  }
  else
  {
    m_min.z = pt1.z;
    m_max.z = pt2.z;
  }
}

#define ex_minmax(max, min, val) \
  if (max < val) max = val;\
  else if (min > val) min = val;

inline void OdGeExtents3d::addPoint(const OdGePoint3d& point)
{
  if ( ( (m_max.x < m_min.x) || (m_max.y < m_min.y) || (m_max.z < m_min.z)) )
  {
    m_max = m_min = point;
  }
  else
  {
    ex_minmax(m_max.x, m_min.x, point.x);
    ex_minmax(m_max.y, m_min.y, point.y);
    ex_minmax(m_max.z, m_min.z, point.z);
  }
}
#undef ex_minmax

inline void OdGeExtents3d::addExt(const OdGeExtents3d& extents)
{
  ODA_ASSERT(extents.isValidExtents());
  if(extents.isValidExtents())
  {
     addPoint(extents.minPoint());
     addPoint(extents.maxPoint());
   }
}

inline void OdGeExtents3d::expandBy(const OdGeVector3d& vect)
{
  ODA_ASSERT(isValidExtents());

  OdGePoint3d p1 = m_min, p2 = m_max;
  addPoint(p1 + vect);
  addPoint(p2 + vect);
}    

inline void OdGeExtents3d::transformBy(const OdGeMatrix3d& xfm)
{
  ODA_ASSERT(isValidExtents());

  OdGeVector3d d = m_max - m_min;
  
  m_max = m_min = (xfm * m_min);
  if(OdNonZero(d.x, 1.e-200))
    expandBy(xfm * (OdGeVector3d::kXAxis * d.x));
  if(OdNonZero(d.y, 1.e-200))
    expandBy(xfm * (OdGeVector3d::kYAxis * d.y));
  if(OdNonZero(d.z, 1.e-200))
    expandBy(xfm * (OdGeVector3d::kZAxis * d.z));
}    

inline bool OdGeExtents3d::contains(const OdGePoint3d& point, const OdGeTol& tol) const
{
  ODA_ASSERT(isValidExtents());

  return ( (point.x + tol.equalPoint()) >= m_min.x
    && (point.y + tol.equalPoint()) >= m_min.y
    && (point.z + tol.equalPoint()) >= m_min.z
    && (point.x - tol.equalPoint()) <= m_max.x
    && (point.y - tol.equalPoint()) <= m_max.y
    && (point.z - tol.equalPoint()) <= m_max.z );
}

inline bool OdGeExtents3d::contains(const OdGeExtents3d& extents, const OdGeTol& tol) const
{
  ODA_ASSERT(isValidExtents());

  return ((extents.m_min.x + tol.equalPoint()) >= m_min.x 
    && (extents.m_min.y + tol.equalPoint()) >= m_min.y 
    && (extents.m_min.z + tol.equalPoint()) >= m_min.z 
    && m_max.x >= (extents.m_max.x - tol.equalPoint()) 
    && m_max.y >= (extents.m_max.y - tol.equalPoint()) 
    && m_max.z >= (extents.m_max.z - tol.equalPoint()));
}    

inline bool OdGeExtents3d::isDisjoint(const OdGeExtents3d& extents, const OdGeTol& tol) const
{
  ODA_ASSERT(isValidExtents());

  return ((extents.m_min.x - tol.equalPoint()) > m_max.x 
    || (extents.m_min.y - tol.equalPoint()) > m_max.y 
    || (extents.m_min.z - tol.equalPoint()) > m_max.z
    || m_min.x > (extents.m_max.x + tol.equalPoint())
    || m_min.y > (extents.m_max.y + tol.equalPoint())
    || m_min.z > (extents.m_max.z + tol.equalPoint()));
}    

#undef INVALIDEXTENTS

#include "../TD_PackPop.h"

#endif //_ODGEEXTENTS3D_INCLUDED_


