/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2015, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2015 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef __FMSEGMENT2D_H__
#define __FMSEGMENT2D_H__

#include "../FacetModeler/FMContoursBase.h"
#include <../Ge/GePoint2d.h>
#include <../Ge/GeVector2d.h>

class OdGeExtents2d;
class OdGeMatrix2d;
class OdGeLine2d;
class OdGeLineSeg2d;
class OdGeCircArc2d;

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

class IBulgeSeg2D;

/** \details
   2D Segment.
  
   \remarks
   Segment2D is a convex 2-D curve given by 2 points and a bulge value
   If the 2 points coincide, the segment has estCoincident type
   Otherwise, if bulge==0, the segment is a straight line segment
   otherwise it is a circular arc, and bulge=tan(Angle/4)
*/
class FMGEOMETRY_API Segment2D
{
    public:
        /** \details
           Constructor.
        */
        Segment2D();

        /** \details
           Constructor.
        */
        explicit Segment2D( SegmentImplClass eImplClass );

        /** \details
           Constructor.
        */
        Segment2D( const OdGePoint2d& ptA,
            const OdGePoint2d& ptB, double dBulge = 0.0, OdIntPtr uMetaData = 0, OdUInt32 uRawFlags = 0 );

        /** \details
           Constructor.
        */
        Segment2D( const OdGePoint2d& ptA,
            const OdGePoint2d& ptB, const OdGePoint2d& ptIntermediate );

        /** \details
           Constructor.
        */
        Segment2D( const Segment2D & rSeg,
            SegmentImplClass eImplClass = esicBulgeSeg2D );

        /** \details
           Constructor.
        */
        explicit Segment2D( const IBulgeSeg2D & rSeg,
            SegmentImplClass eImplClass = esicBulgeSeg2D );

        /** \details
           Destructor.
        */
        ~Segment2D();

        /** \details
           Copy operator.
        */
        Segment2D& operator = ( const Segment2D& rSeg );

        /** \details
           Copy operator.
        */
        Segment2D& operator = ( const IBulgeSeg2D& rSeg );

        /** \details
           Implementation type.
        */
        SegmentImplClass implClass() const;

        /** \details
           Returns start point.
        */
        const OdGePoint2d& startPt() const;

        /** \details
           Returns end point.
        */
        const OdGePoint2d& endPt() const;

        /** \details
           Returns bulge value.
        */
        double bulge() const;

        /** \details
           Returns segment type.
        */
        SegmentType type() const;

        /** \details
           Returns signed deviation from the line.
        */
        double deviation() const;

        /** \details
           Returns direction from end point to start point.
        */
        void getDir( OdGeVector2d& vDir ) const;

        /** \details
           Return the distance between start and end point.
        */
        double dirLength() const;

        /** \details
           Returns segment length.
        */
        double length() const;

        /** \details
           Returns line segment corresponding to this segment.
          
           \remarks
           Only works for line segments.
        */
        Result getLineSeg( OdGeLineSeg2d& rLine ) const;

        /** \details
           Returns arc segment corresponding to this segment.
          
           \remarks
           Only works for arc segments.
        */
        Result getArcSeg( OdGeCircArc2d& rArc ) const;

        /** \details
           Returns point at parameter in range [ 0, 1 ].
        */
        Result getPoint( double dParam,
            OdGePoint2d& ptPoint ) const;

        /** \details
           Returns tangent at parameter in range [ 0, 1 ].
        */
        Result getTangent( double dParam,
            OdGeVector2d& vTangent ) const;

        /** \details
           Adds extents of this segment (extended by dTol) to the given extents.
        */
        void addExtents( OdGeExtents2d& extExtents,
            double dTol = 0.0 ) const;

        /** \details
           Returns whether the point lies on the segment.
          
           \param ptTest [in]  Point to test.
           \param pParam [out]  Resulting parameter.
           \param gTol [in]  Tolerance.
        */
        bool isOn( const OdGePoint2d& ptTest, double* pParam = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns nearest parameter to the specified point.
          
           \param ptTest [in]  Point to test.
           \param ptNearest [out]  Nearest point.
        */
        double nearestParam( const OdGePoint2d& ptTest,
            OdGePoint2d* ptNearest = 0 ) const;

        /** \details
           Returns 2 * signed area of a contour bounded by this segment and 2 lines,
           connecting the ptOrigin and ends of this segment.
        */
        double integrate( const OdGePoint2d& ptOrigin = OdGePoint2d::kOrigin ) const;

        /** \details
           Returns subsegment given by 2 parameters.
          
           \remarks
           If (dStartParam > dEndParam) the rSubSeg will have opposite direction.
        */
        Result getSubSegment( double dStartParam, double dEndParam,
            IBulgeSeg2D & rSubSeg ) const;

        /** \details
           Returns parallel segment.
           
           \param dNormalOffset [in]  Signed offset along normal vector at each point of original segment.
           \param rParSeg [out]  Result.
        */
        Result getParallelSegment( double dNormalOffset,
            IBulgeSeg2D& rParSeg ) const;

        /** \details
           The method returns number of different intersection points of
           the segment (including end with minimal Y) with a ray, starting at ptTest and
           going in the X direction.
          
           \remarks
           *pOnSegment is set to true, if the test point lies on the segment.
        */
        OdUInt32 intersectXRay( const OdGePoint2d& ptTest, bool* pOnSegment = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns number of intersections (0, 1 or something) and intersection points.
        */
        OdUInt32 intersect( const IBulgeSeg2D& rSegB,
            OdGePoint2d* pPt1, OdGePoint2d* pPt2 = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns number of intersections (0, 1 or something) and Intersection objects.
        */
        OdUInt32 intersect( const IBulgeSeg2D& rSegB,
            Intersection* pInt1 = 0, Intersection* pInt2 = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Intersects this segment with an infinite line.
          
           \returns
           The number of intersections.
        */
        OdUInt32 intersectLine(
            const OdGeLine2d& rGeLine,
            Intersection* pInt1 = 0, Intersection* pInt2 = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns arc center.
        */
        OdGePoint2d arcCenter() const;

        /** \details
           Returns arc radius.
        */
        double arcRadius() const;

        /** \details
           Returns arc radius and center point.
        */
        Result getCircleData( OdGePoint2d& ptCenter,
            double& dRadius ) const;

        /** \details
           Returns signed included angle of the arc segment.
          
           \remarks
           The returned value belongs to range ( -2*Pi, 2*Pi ).
        */
        double arcAngle() const;

        /** \details
           Returns starting angle of the arc (direction from center to startPt).
          
           \remarks
           The returned value belongs to range [ 0, 2*Pi ).
        */
        double arcStartAngle() const;

        /** \details
           Returns arc center point, radius and angles.
        */
        Result getArcData( OdGePoint2d& ptCenter, double& dRadius,
            double& dStartAngle, double& dInclAngle ) const;

        /** \details
           Transforms segment with specified matrix.
        */
        Result transformBy( const OdGeMatrix2d& mTrans );

        /** \details
           Inverts the segment (makes it going in opposite direction).
        */
        Result reverse();

        /** \details
           Update ends and bulge.
        */
        Result set( const OdGePoint2d& ptA,
            const OdGePoint2d& ptB, double dBulge = 0.0, OdIntPtr iMetaData = 0, OdUInt32 iRawFlags = 0 );

        /** \details
           Update ends and calculate bulge using the intermediate point.
        */
        Result set( const OdGePoint2d& ptA,
            const OdGePoint2d& ptB, const OdGePoint2d& ptIntermediate );

        /** \details
           Copy from GeLineSeg2d and reset metadata.
        */
        Result set( const OdGeLineSeg2d& geLine );

        /** \details
           Copy from GeCircArc2d and reset metadata.
        */
        Result set( const OdGeCircArc2d& geArc );

        /** \details
           Copy from another segment
        */
        Result set( const IBulgeSeg2D& rSeg );

        //
        //
        Result shift( const double dAngle, const double dShiftDist );
         
        /** \details
           Returns metadata.
        */
        OdIntPtr metadata() const;
    
        /** \details
           Sets metadata.
        */
        Result setMetadata( OdIntPtr iNewData );

        /** \details
           Returns ecfHidden flag value.
        */
        bool isHidden() const;

        /** \details
           Sets or clears ecfHidden flag.
        */
        Result setHidden( bool bHidden = true );

        /** \details
           Returns orientation.
        */
        FaceOrientation orientation() const;

        /** \details
           Sets orientation.
        */
        Result setOrientation( FaceOrientation eOrientation );

        /** \details
           Returns ecfExplodedArc flag value.
        */
        bool isExplodedArc() const;

        /** \details
           Sets or clears ecfExplodedArc flag.
        */
        Result setExplodedArc( bool bExplodedArc = true );

        /** \details
           Returns internal flags ( orientation, visibility etc.).
        */
        OdUInt32 rawFlags() const;

        /** \details
           Sets internal flags ( orientation, visibility etc.).
        */
        Result setRawFlags( OdUInt32 iRawFlags );

    public:
        //!DOM
        inline operator const IBulgeSeg2D& () const
        { return *m_pImpl; }
        //!DOM
        inline operator IBulgeSeg2D& ()
        { return *m_pImpl; }
        //!DOM
        inline const IBulgeSeg2D& impl() const
        { return *m_pImpl; }
        //!DOM
        inline IBulgeSeg2D& impl()
        { return *m_pImpl; }

    private:
        //!DOM
        IBulgeSeg2D* m_pImpl;
};

}; // namespace FacetModeler

#endif  //__FMSEGMENT2D_H__
