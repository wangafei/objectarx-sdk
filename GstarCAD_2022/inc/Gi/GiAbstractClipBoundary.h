/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2013, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2013 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef _GI_ABSTRACT_CLIP_BOUNDARY_H_INCLUDED_
#define _GI_ABSTRACT_CLIP_BOUNDARY_H_INCLUDED_

#include "../TD_PackPush.h"

#include "../Gi/GiClipBoundary.h"
#include "../IntArray.h"

/** Description:
    Base class for pass additional clip boundary information from OdGiDrawable objects to the underlying OdGi system.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class OdGiAbstractClipBoundary
{
 protected:
   bool m_bHighlightDraw;
 public:
    enum BoundaryType
    {
      kNormal = 0, // Default clip boundary (not pass additional data, clip outside contour)
      kInverted,   // Inverted clip boundary (pass inverted clip array, clip inside contour)
      kExtended    // Extended clip boundary (pass clipping contours, clip by sorted contours array)
    };
  public:
    ODRX_HEAP_OPERATORS();

    OdGiAbstractClipBoundary():m_bHighlightDraw(false) { }
    virtual ~OdGiAbstractClipBoundary() { }
    
    bool highlightDraw() const {return m_bHighlightDraw;}
    void setHighlightDraw(bool hd){m_bHighlightDraw = hd;}
    /** Description:
        Returns type of the inherited boundary.
    */
    virtual BoundaryType type() const { return kNormal; }

    /** Description:
        Returns cloned object.
    */
    virtual OdGiAbstractClipBoundary *clone() const { return new OdGiAbstractClipBoundary(); }
};

/** Description:
    Class to pass inverted clip boundary information from OdGiDrawable objects to the underlying OdGi system.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class OdGiInvertedClipBoundary : public OdGiAbstractClipBoundary
{
  protected:
    OdGePoint2dArray m_Points; // Array of points that defines the inverted clip boundary.
  public:
    OdGiInvertedClipBoundary() { }
    ~OdGiInvertedClipBoundary() { }

    /** Description:
        Returns type of the inherited boundary.
    */
    BoundaryType type() const { return kInverted; }

    /** Description:
        Returns inverted clipping boundary.
    */
    const OdGePoint2dArray &invertedClipBoundary() const { return m_Points; }
    /** Description:
        Setup inverted clipping boundary.
        Arguments:
        pPoints (I) Input points array.
    */
    void setInvertedClipBoundary(const OdGePoint2dArray &pPoints) { m_Points = pPoints; }

    /** Description:
        Returns cloned object.
    */
    OdGiAbstractClipBoundary *clone() const {
      OdGiInvertedClipBoundary *pNew = new OdGiInvertedClipBoundary();
      pNew->setInvertedClipBoundary(invertedClipBoundary());
      return pNew;
    }
};

/** Description:
    Class to pass extended clip boundary information from OdGiDrawable objects to the underlying OdGi system.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
class OdGiExtendedClipBoundary : public OdGiAbstractClipBoundary
{
  protected:
    OdIntArray       m_Counts; // Array of contour points counts
    OdGePoint2dArray m_Points; // Array of points that defines the extended clip boundary contours.
  public:
    OdGiExtendedClipBoundary() { }
    ~OdGiExtendedClipBoundary() { }

    /** Description:
        Returns type of the inherited boundary.
    */
    BoundaryType type() const { return kExtended; }

    /** Description:
        Returns extended clipping boundary contour vertices counts.
    */
    const OdIntArray &clipBoundaryCounts() const { return m_Counts; }
    /** Description:
        Setup inverted extended boundary contour vertices counts.
        Arguments:
        pCounts (I) Input counts array.
    */
    void setClipBoundaryCounts(const OdIntArray &pCounts) { m_Counts = pCounts; }

    /** Description:
        Returns extended clipping boundary points.
    */
    const OdGePoint2dArray &clipBoundaryPoints() const { return m_Points; }
    /** Description:
        Setup extended clipping boundary points.
        Arguments:
        pPoints (I) Input points array.
    */
    void setClipBoundaryPoints(const OdGePoint2dArray &pPoints) { m_Points = pPoints; }

    /** Description:
        Returns cloned object.
    */
    OdGiAbstractClipBoundary *clone() const {
      OdGiExtendedClipBoundary *pNew = new OdGiExtendedClipBoundary();
      pNew->setClipBoundaryCounts(clipBoundaryCounts());
      pNew->setClipBoundaryPoints(clipBoundaryPoints());
      return pNew;
    }
};

/** Description:
    Container for OdGiClipBoundary and OdGiAbstractClipBoundary.
    Library: TD_Gi
    {group:OdGi_Classes} 
*/
struct OdGiClipBoundaryWithAbstractData : public OdGiClipBoundary
{
  OdGiAbstractClipBoundary *m_pAbstractData;

  OdGiClipBoundaryWithAbstractData() : m_pAbstractData(NULL) { }
  OdGiClipBoundaryWithAbstractData(const OdGiClipBoundary &pBoundary, const OdGiAbstractClipBoundary *pAbsData = NULL)
    : OdGiClipBoundary(pBoundary), m_pAbstractData(NULL)
  {
    if (pAbsData) m_pAbstractData = pAbsData->clone();
  }
  OdGiClipBoundaryWithAbstractData(const OdGiClipBoundaryWithAbstractData &pBoundary)
    : OdGiClipBoundary(pBoundary), m_pAbstractData(NULL)
  {
    if (pBoundary.m_pAbstractData) m_pAbstractData = pBoundary.m_pAbstractData->clone();
  }
  ~OdGiClipBoundaryWithAbstractData() {
    if (m_pAbstractData) delete m_pAbstractData;
  }
};

#include "../TD_PackPop.h"

#endif // _GI_ABSTRACT_CLIP_BOUNDARY_H_INCLUDED_
