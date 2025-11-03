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

#ifndef __FMCONTOUR2D_H__
#define __FMCONTOUR2D_H__

#include "../FacetModeler/FMGeometry.h"
#include "../FacetModeler/FMContoursBase.h"
#include "../FacetModeler/FMSegment2D.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{
  
class IContour2D;
class IBulgeSeg2D;
class Profile2D;

class ODRX_ABSTRACT Contour2DTraversingReactor {
public:
  virtual bool onLineSeg( int nSegment ) = 0;

  virtual bool onArcSeg( int nSegment, DeviationParams** ppDev ) = 0;

  virtual bool onArcStartPoint( int nSegment, const OdGePoint2d& pt, int nTotalPts ) = 0;

  virtual bool onArcPoint( int nSegment, const OdGePoint2d& pt ) = 0;

  virtual bool onArcEndPoint( int nSegment, const OdGePoint2d& pt ) = 0;

  virtual bool onCoincidentSeg( int nSegment ) = 0;
};

/** \details
   Representation of 2D Contour.
  
   \remarks
   Contour2D may contain linear and circular segments.
   
   There are 3 ways to pick some (non-vertex) point on the contour:
   a) use an integer index to get a segment and then
      use parameter on the segment (GeLine or GeArc).
   b) use a distance along the curve from the starting point.
   c) use a "parameter" value.
  
   The last way is the fastest (and preferred in most cases) because of
   the "parameter" structure:
     dParam = startParam() + iIndex * (dOffsetOnSegment/dSegmentLength)
  
   So the point given by parameter value can be found at constant time.
*/
class FMGEOMETRY_API Contour2D
{
    public:
        /** \details
           Creates contour of eSimple implementation type.
        */
        Contour2D();

        /** \details
           Creates contour of specified implementation type.
          
           \param eImplClass [in]  Implementation type.
        */
        explicit Contour2D( ContourImplClass eImplClass );

        /** \details
           Creates contour and initializes it with specified segment.
        */
        explicit Contour2D( const IBulgeSeg2D& rSrcSeg,
            ContourImplClass eImplClass = ecicSimple );

        /** \details
           Creates contour and initializes it with specified contour.
          
           \remarks
           By default the copy has simple implementation type.
        */
        Contour2D( const Contour2D& rSrcCont,
            ContourImplClass eImplClass = ecicSimple );

        //!DOM
        explicit Contour2D( const IContour2D& rSrcCont,
            ContourImplClass eImplClass = ecicSimple );

        /** \details
           Creates rectangular contour and initializes it with extens points
        */
        Contour2D(const OdGeExtents2d& ext);

        /** \details
           Destructor.
        */
        ~Contour2D();

        /** \details
           Creates a copy of specified contour.
          
           \remarks
           The implementation type remains intact.
        */
        Contour2D& operator = ( const  Contour2D& rSrcCont );

        //!DOM
        Contour2D& operator = ( const IContour2D& rSrcCont );

        /** \details
           Copies the contents of the specified contour.
          
           \remarks
           The implementation type may change.
        */
        Contour2D& cloneFrom( const IContour2D& rSrcCont );

        /** \details
           Clears the contents of the contour.
          
           \param eImplClass [in]  Implementation type.
          
           \remarks
           By default the implementation type will not change.
           Contour will be made open.
        */
        Contour2D& reset( ContourImplClass eImplClass = ecicUnknown );

        /** \details
           Returns the implementation type.
        */
        ContourImplClass implClass() const;

        /** \details
           Swaps the contents of the contour.
        */
        void swap ( Contour2D& rAnother );

        /** \details
           Returns true if the contour is closed, false otherwise.
        */
        bool isClosed() const;

        bool isEndsEqual(const OdGeTol& gTol = FMGeGbl::gTol) const;

        /** \details
           Makes the contour closed (open).
        */
        void setClosed( bool bClosed = true );

        /** \details
           Returns true if contour has no vertices.
        */
        bool isEmpty() const;

        /** \details
           Returns the number of vertices.
        */
        OdUInt32 numVerts() const;

        /** \details
           Returns the number of segments.
          
           \remarks
           It is less than or equal (if the contour is closed) to the number of vertices.
        */
        OdUInt32 numSegments() const;

        /** \details
           Returns true, if the contour contains at least one arc
        */
        bool hasArcs() const;

        /** \details
           Returns the type of the segment that begins at the specified vertex.
          
           \remarks
           If the index is out of range estUnknown is returned
           Otherwise one of estArc, estLine, estCoincident is returned
        */
        SegmentType segmentType( OdUInt32 iIndex ) const;

        /** \details
           Returns segment by index.
        */
        Result getSegmentAt( OdUInt32 iIndex,
            Segment2D& rSegment ) const;

        /** \details
           Returns segment paramters by index.
        */
        Result getSegmentAt( OdUInt32 iIndex,
            OdGePoint2d& ptStart,
            OdGePoint2d& ptEnd,
            double& dBulge ) const;

        /** \details
           Returns linear segment by index.
        */
        Result getLineSegAt( OdUInt32 iIndex,
            OdGeLineSeg2d& geLine ) const;

        /** \details
           Returns linear segment by index.
        */
        Result getArcSegAt( OdUInt32 iIndex,
            OdGeCircArc2d& geArc ) const;

        /** \details
           Returns point by index.
        */
        Result getPointAt( OdUInt32 iIndex,
            OdGePoint2d& ptPoint ) const;

        /** \details
           Returns bulge value for segment with specified index.
        */
        Result getBulgeAt( OdUInt32 iIndex,
            double& dBulge ) const;

        /** \details
           Returns vertex data by specified index.
        */
        Result getVertexAt( OdUInt32 iIndex,
            OdGePoint2d* pPoint, double* pBulge = 0, OdIntPtr* pMetadata = 0, OdUInt32* puRawFlags = 0 ) const;

        /** \details
           Returns internal angle of vertex by specified index.
        */
        Result getInternalAngleAt( OdUInt32 iIndex, double & dAngle ) const;

        /** \details
           Sets point by index.
        */
        Result setPointAt( OdUInt32 iIndex,
            const OdGePoint2d& ptPoint );

        /** \details
           Sets bulge by index.
        */
        Result setBulgeAt( OdUInt32 iIndex,
            double dBulge );

        /** \details
           Sets point and bulge by index.
        */
        Result setVertexAt( OdUInt32 iIndex,
            const OdGePoint2d& ptPoint, double dBulge );

        /** \details
           Sets capacity of the contour data to the specified vertex number.
        */
        void reserveVertices( OdUInt32 iReservedSize );

        /** \details
           Returns metadata for the specified segment.
          
           \remarks
           By default metadata value is 0.
        */
        OdIntPtr metadataAt( OdUInt32 iIndex ) const;

        /** \details
           Sets metadata for the specified segment.
          
           \remarks
           By default metadata value is 0.
        */
        Result setMetadataAt( OdUInt32 iIndex,
            OdIntPtr iNewData );

        /** \details
           Updates metadata for all segments.
        */
        Result setAllMetadata( OdIntPtr iNewData,
            OdIntPtr iBitsToModify = (OdIntPtr)-1 );

        /** \details
           Returns true if the segment with specified index in hidden.
        */
        bool isHiddenAt( OdUInt32 iIndex ) const;

        /** \details
           Sets or clears ecfHidden flag at specified segment.
        */
        Result setHiddenAt( OdUInt32 iIndex,
            bool bHidden = true );

        /** \details
           Returns segment orientation.
        */
        FaceOrientation orientationAt( OdUInt32 iIndex ) const;

        /** \details
           Sets segment orientation.
        */
        Result setOrientationAt( OdUInt32 iIndex,
            FaceOrientation eOrientation );

        /** \details
           Returns "smooth" flag value.
           It used to create smooth surfases when generating extrusion or revolution body.
        */
        bool threatAsSmoothCurveAt( OdUInt32 iIndex ) const;

        /** \details
           Sets "smooth" flag value.
           It used to create smooth surfases when generating extrusion or revolution body.
        */
        void setThreatAsSmoothCurveAt( OdUInt32 iIndex, bool bSmooth );

        /** \details
           Returns true if the segment with specified index is a part of an exploded arc.
        */
        bool isExplodedArcAt( OdUInt32 iIndex ) const;

        /** \details
           Sets or clears ecfExplodedArc flag at specified segment.
        */
        Result setExplodedArcAt( OdUInt32 iIndex,
            bool bExplodedArc = true );

        /** \details
           Returns all built-in flags (orientation, visibility etc.) for the specified segment.
          
           \remarks
           By default flags value is 0.
        */
        OdUInt32 rawFlagsAt( OdUInt32 iIndex ) const;

        /** \details
           Updates all built-in flags (orientation, visibility etc.) for the specified segment.
        */
        Result setRawFlagsAt( OdUInt32 iIndex, OdUInt32 iRawFlags );

        /** \details
           Adds a vertex at the specified index.
          
           \remarks
           The index should not be greater than the number of vertices in contour.
          
           If it is equal to numVerts(), a new vertex will be appended to the array,
           otherwise it`ll be inserted before the old iIndex vertex.
        */
        Result addVertexAt( OdUInt32 iIndex,
            const OdGePoint2d& ptStart, double dBulge = 0.0, OdIntPtr uMetadata = 0, OdUInt32 uRawFlags = 0 );

        /** \details
           Appends a new vertex to the end of contour.
          
           \remarks
           The bulge value relates to the segment starting at this point.
        */
        Result appendVertex( const OdGePoint2d& ptStart,
            double dBulge = 0.0, OdIntPtr uMetadata = 0, OdUInt32 uRawFlags = 0 );

        /** \details
           Appends a new vertex to the end of contour.
        */
        Result appendVertex( const OdGePoint2d& ptStart,
            const OdGePoint2d& ptMid, OdIntPtr uMetadata = 0, OdUInt32 uRawFlags = 0 );

        /** \details
           Appends vertex data to this contour.
        */
        Result appendVertices( const OdGePoint2dArray & vecSource );        

        /** \details
           Appends segment to the end of this contour. 
          
           \remarks
           Returns erPointNotOnThis if rSeg.startPt() is not equal to the end of this (open) contour
           if bShiftToHit is true, the rSeg is shifted and the return code is erWarnPointNotOnThis
          
           If the contour is closed, the last (closing) segment is wiped out.
        */
        Result appendSegment( const Segment2D& rSeg,
            bool bShiftToHit = false );

        /** \details
           Appends contour to the end of this contour.
          
           \remarks
           Returns erPointNotOnThis if rCont.startPoint is not equal to the end of this (open) contour
          
           If bCloseGap is true, a segment, connecting the points is inserted and
           the return code is erWarnPointNotOnThis.
        */
        Result appendContour( const Contour2D& rCont,
            bool bCloseGap = false, double dMaxGap = 1e99 );

        /** \details
           Removes a vertex and corresponding segment.
          
           \remarks
           Bulge values of the other segments are left intact.
        */
        Result removeVertexAt( OdUInt32 iIndex );

        /** \details
           Returns start contour parameter.
        */
        inline double startParam() const
        { return 0.0; };

        /** \details
           Returns end contour parameter.
        */
        double endParam() const;

        // Returns true and a period value, if the contour is closed
        // Returns false otherwise
        //bool getPeriodParam( double & dPeriod ) const;

        /** \details
           Returns start point of the contour.
          
           \remarks
           If the contour is empty than contour has no start point.
        */
        Result getStartPoint( OdGePoint2d& ptPoint ) const;

        /** \details
           Returns end point of the contour.
          
           \remarks
           If the contour is empty than contour has no end point.
        */
        Result getEndPoint( OdGePoint2d & ptPoint ) const;

        /** \details
           Returns the length of the contour.
        */
        double length() const;

        /** \details
           Returns tangent at parameter.
        */
        Result getTangent( double dParam,
            OdGeVector2d& vTangent ) const;

        /** \details
           Returns tangent at distance.
        */
        Result getTangentAtDist( double dDist,
            OdGeVector2d& vTangent ) const;

        /** \details
           Returns point at parameter.
        */
        Result getPoint( double dParam,
            OdGePoint2d& ptPoint ) const;

        /** \details
           Returns point at distance.
        */
        Result getPointAtDist( double dDist,
            OdGePoint2d& ptPoint ) const;

        /** \details
           Returns distance at parameter.
        */
        Result getDistAtParam( double dParam,
            double& dDist ) const;

        /** \details
           Returns parameter at distance.
        */
        Result getParamAtDist( double dDist,
            double& dParam ) const;

        //Result getParamAtPoint(const OdGePoint2d& ptPoint, double& dParam) const;
        //Result getDistAtPoint (const OdGePoint2d& ptPoint, double& dDist) const;

        /** \details
           Converts parameter to [start param, end param] range.
          
           \returns
           eOk if dParam is valid.
          
           \remarks
           Works for closed contours.
        */
        Result getNormalizedParam( double& dParam ) const;
        
        /** \details
           Converts distance to [0, length] range.
          
           \returns
           eOk if dParam is valid.
          
           \remarks
           Works for closed contours.
        */
        Result getNormalizedDist( double& dDist ) const;

        /** \details
           Returns true if the parameters are valid and equal (after normalization).
          
           \remarks
           The result is useless unless both parameter are valid.
        */
        bool areEqualParams( double dParam1,
            double dParam2, double dParamTol = 1e-10 ) const;
        
        /** \details
           Returns true if the distances are equal (after normalization).
          
           \remarks
           The result is useless unless both distances are valid.
        */
        bool areEqualDists( double dDist1,
            double dDist2, double dTol = 1e-6/*FMGeGbl::gTol.equalPoint()*/ ) const;

        /** \details
           Appends the extents of the contour to the specified extents structure.
        */
        Result addExtents( OdGeExtents2d& extExtents ) const;

        /** \details
           Returns non-negative area of the contour.
          
           \remarks
           For open contours the first and last vertices are considered
           to be connected with a straight line.
        */
        double area() const;

        /** \details
           Returns signed area of the contour
        */
        double signedArea() const;

        /** \details
           Returns true if contour is convex and false otherwise
        */
        bool isConvex() const;

        /** \details
           Returns true if the contour has counter-clockwise orientation.
          
           \remarks
           The area of the contour is positive for counter-clockwise contour
           and negative for clockwise contour.
        */
        bool isCCW() const;

        /** \details
           Makes contour counter-clockwise or clockwise.
        */
        void makeCCW( bool bCCW = true );

        /** \details
           Returns whether the point is located on contour.
          
           \param ptTest [in]  Point to test.
           \param pParam [out]  Resulting parameter.
           \param gTol [in]  Tolerance.
          
           \returns
           Returns true if the point lies on contour.
        */
        bool isOn( const OdGePoint2d& ptTest, double* pParam = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns nearest parameter on contour.
          
           \param ptTest [in]  Point to test.
           \param ptNearest [out]  Nearest point on contour.
          
           \returns
           Nearest parameter on contour.
        */
        double nearestParam( const OdGePoint2d& ptTest,
            OdGePoint2d* ptNearest = 0 ) const;

        /** \details
           Returns whether the point is located inside contour.
          
           \param ptPoint [in]  Point to test.
           \param pOnBorder [out]  Filled with true if point is located on contour.
           \param gTol [in]  Tolerance.
          
           \returns
           Returns true if the point lies inside contour.
        */
        bool contains( const OdGePoint2d& ptPoint, bool* pOnBorder = 0,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns whether the contour intersects itself.
          
           \remarks
           Runs in O( N * log(N) ) time at the average.
          
           Returns true if and only if there exists a pair of intersecting segments
           and the shortest distance along the contour between the intersections is
           greater than tolerance. 
           E.g. The method returns true for 8 - shaped contour regardless of 
                central intersection type (touch or crossing).
           The method returns false for O - shaped closed contour, 
                but returns true for the open one.
        */
        bool isSelfIntersecting( const OdGeTol& gTol = FMGeGbl::gTol, bool bExcludeTouch = false  ) const;

        /** \details
           Returns whether this contour is closed and coincides with a directional 
           boundary of some open 2D-region.
           
           \remarks
           - returns false for empty and for non-closed contours;
           - returns false, if there are coincident bounds with opposite directions (e.g. O-O shape);
           - returns false, if there are sub-contours with incorrect orientation (e.g. 8 shape)
           - returns true otherwise
        */
        bool isValidRegion( const OdGeTol& gTol = FMGeGbl::gTol ) const;

        bool isInsideContour(const Contour2D& c2dOuter, bool fAllowBordersTouch = false, const OdGeTol& gTol = FMGeGbl::gTol) const;

        /** \details
           Calculates all intersections with specified segment and appends the result to vecPoints.
          
           \param rSegB [in]  Segment this contour is intersected with.
           \param vecPoints [out]  Intersection container the result is appended to.
           \param gTol [in]  Tolerance.
          
           \returns
           The number of intersections.
        */
        OdUInt32 intersect( const Segment2D& rSegB,
            std::vector< Intersection >& vecPoints,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Calculates all intersections with specified contour and appends the result to vecPoints.
          
           \param rContB [in]  Contour this contour is intersected with.
           \param vecPoints [out]  Intersection container the result is appended to.
           \param gTol [in]  Tolerance.
          
           \returns
           The number of intersections.
        */
        OdUInt32 intersect( const Contour2D& rContB,
            std::vector< Intersection >& vecPoints,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Calculates all intersections with specified line and appends the result to vecPoints.
          
           \param rLine [in]  Line this contour is intersected with.
           \param vecPoints [out]  Intersection container the result is appended to.
           \param gTol [in]  Tolerance.
          
           \returns
           The number of intersections.
        */
        OdUInt32 intersectLine( const OdGeLine2d& rLine, 
            std::vector< Intersection >& vecPoints,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Transforms the contour.
        */
        Result transformBy( const OdGeMatrix2d& mMatrix,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev );

        /** \details
           Reverses the contour.
        */
        void reverse();

        /** \details
           Removes redundant segments with zero length.
        */
        void deleteCoincident( const OdGeTol& gTol = FMGeGbl::gTol );

        /** \details
           Merges adjacent segments.
          
           \param iMergeFlags [in]  combination of AECGe::FilletType flags (emfMergeArcs,emfIgnoreMetadata,emfMergeOrigin)
           \param gTol [in]  Tolerance.
        */
        void mergeSegments( int iMergeFlags = 0, const OdGeTol & gTol = FMGeGbl::gTol  );

        /** \details
           Explodes all arc segments to lines.
           Sets uArcMetadata flag on exploded segments.
        */
        Result explode( const DeviationParams& devDeviation = FMGeGbl::gDefDev, OdIntPtr uArcMetadata = 0);

        /** \details
           Explodes all arc segments to lines.
           Sets uArcMetadata flag on exploded segments.
        */
        Result explodeTo( Contour2D& rDestCont,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev, OdIntPtr uArcMetadata = 0 ) const;

        /** \details
           Adds a vertex corresponding to the specified parameter into the contour.
          
           \param dParam [in]  Parameter on contour.
           \param gTol [in]  Tolerance.
           
           \returns
           Index of created (or found) point.
          
           \remarks
           If vertex at specified parameter exists than method does nothing.
           
           Insertion or removal of a vertex at dParam invalidates all parameters greater than floor(dParam).
        */
        OdUInt32 createVertexAt( double dParam,
            const OdGeTol& gTol = FMGeGbl::gTol );

        /** \details
           Adds a vertex corresponding to the specified distance into the contour.
          
           \param dDist [in]  Distance on contour.
           \param gTol [in]  Tolerance.
           
           \returns
           Index of created (or found) point.
          
           \remarks
           If vertex at specified parameter exists than method does nothing.
        */
        OdUInt32 createVertexAtDist( double dDist,
            const OdGeTol & gTol = FMGeGbl::gTol );

        /** \details
           Adds vertices at the specified parameters into the contour
          
           \param vecParams [in]  Array of parameters.
           \param gTol [in]  Tolerance.
          
           \remarks
           If some vertices already exist this method doesn't create them.
        */
        Result createVerticesAt( const std::vector<double> & vecParams,
            const OdGeTol& gTol = FMGeGbl::gTol );

        /** \details
          Returns sub-contour given by 2 parameters.
                    
           \remarks
           If (dStartParam > dEndParam) the rSubContour will have opposite direction
           
        */
        Result getSubContour(double dStartParam, double dEndParam,
            Contour2D & rSubContour, const OdGeTol & gTol = FMGeGbl::gTol ) const;


        /** \details
           Return the profile that is shifted in normal direction from this closed(!) 
           contour.
           E.g. counter-clockwise circle is extended, if dOffset is negative.
           It is contracted, if dOffset is positive and small enough,
           and it becomes empty, if dOffset > radius
          
           \param dOffset [in]  Signed offset along normal direction. Positive offset is to inside for CCW contours.
           \param rResult [out]  Resulting profile.
           \param eFilletType [in]  Gap filling strategy for the segments sliding apart
           \param tTol [in]  Tolerance.
          
           \returns
           Success status.
        */
        Result getOffsetProfile( double dOffset, Profile2D& rResult, 
            FilletType eFilletType = eftExtend,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        Result getProfileByOffsets( const std::vector< double >& adOffset,
                                          Profile2D& rResult,
                                    const OdGeTol& gTol = FMGeGbl::gTol ) const;


        /** \details
           Traverses the contour.
        */
        bool traverse( Contour2DTraversingReactor& reactor ) const;

        /** \details
           Returns geometry extens
        */
        void getGeomExtens(OdGeExtents2d& extens);

    public:
        //!DOM
        inline operator const IContour2D& () const
        { return *m_pImpl; }

        //!DOM
        inline operator IContour2D& ()
        { return *m_pImpl; }

        //!DOM
        inline const IContour2D & impl() const
        { return *m_pImpl; }

        //!DOM
        inline IContour2D & impl()
        { return *m_pImpl; }

    private:
        IContour2D* m_pImpl;

    public:
        /** \details
           An empty static contour
        */
        FMGEOMETRY_API_STATIC static const Contour2D kNull;
};

/** \details
   Representation of 2D Contour.
  
   \remarks
   The only difference between Contour2D and CachedContour2D is the default implementation type.
   CachedContour2D uses ecicCached while Contour2D uses ecicSimple.
  
   For cached implementation type
   some calls will be faster if made consequently.
  
   CachedContour2D can also use ecicSimple implementation.
   For example if cloned from simple contour.
*/
class FMGEOMETRY_API CachedContour2D : public Contour2D
{
    public:
        /** \details
           Constructor.
        */
        CachedContour2D( ) 
            : Contour2D( ecicCached )
        { }
    
        /** \details
           Constructor.
        */
        CachedContour2D( ContourImplClass eImplClass ) 
            : Contour2D( eImplClass )
        { }
        
        /** \details
           Constructor.
        */
        CachedContour2D( const IBulgeSeg2D& rSrcSeg, ContourImplClass eImplClass = ecicCached )
            : Contour2D( rSrcSeg, eImplClass )
        { }
    
        /** \details
           Constructor.
        */
        CachedContour2D( const Contour2D & rSrcCont, ContourImplClass eImplClass = ecicCached )
            : Contour2D( rSrcCont, eImplClass )
        { }

        /** \details
           = operator.
        */
        inline CachedContour2D& operator = ( const Contour2D& rSrcCont )
        {
            Contour2D::operator=(rSrcCont);
            return *this;
        };
        
        /** \details
           Contour2D override.
        */
        inline CachedContour2D& cloneFrom( const Contour2D& rSrcCont ) 
        {
            Contour2D::cloneFrom(rSrcCont);
            return *this;
        };
        
        /** \details
           Contour2D override.
        */
        inline CachedContour2D& reset( ContourImplClass eImplClass = ecicUnknown )
        {
            Contour2D::reset(eImplClass);
            return *this;
        };
};


FMGEOMETRY_API void ExtendContourStart(Contour2D& rContour);
FMGEOMETRY_API void ExtendContourEnd(Contour2D& rContour);

FMGEOMETRY_API void ExtendContour(Contour2D& rContour);

FMGEOMETRY_API bool FindClosestIntToBaseStart(const Contour2D& cBase, const Contour2D& cCutter, Intersection& intClosest);
FMGEOMETRY_API bool FindClosestIntToBaseEnd(const Contour2D& cBase, const Contour2D& cCutter, Intersection& intClosest);

FMGEOMETRY_API Intersection FindIntClosestToPt(const OdGePoint2d& ptBase, const std::vector< Intersection >& vecPoints);
FMGEOMETRY_API bool IsIntersectionCloserToPt(const OdGePoint2d& ptBase, const Intersection& intCurrent, const Intersection& intToCheck);

}; // namespace AECContours

#endif  //__FMCONTOUR2D_H__
