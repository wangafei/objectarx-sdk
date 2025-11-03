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

#ifndef __FMPROFILE2D_H__
#define __FMPROFILE2D_H__

#include "../FacetModeler/FMContour2D.h"
#include <../DbObjectId.h>

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

/** \details
   Describes 2D Profile.
*/
class FMGEOMETRY_API Profile2D
{
    public:
        /** \details
           Constructor.
        */
        Profile2D();

        /** \details
           Constructor.
        */
        explicit Profile2D( const Contour2D & rSrcCont );

        /** \details
           Destructor.
        */
        ~Profile2D();

        /** \details
           Copy constructor.
        */
        Profile2D(const Profile2D & rSrc );

        /** \details
           Copy operator.
        */
        Profile2D& operator = (const Profile2D & rSrc);

        //!DOM
        typedef       Contour2D   value_type;
        //!DOM
        typedef const Contour2D & const_reference;
        //!DOM
        typedef       Contour2D & reference;
        //!DOM
        typedef const Contour2D * const_pointer;
        //!DOM
        typedef       Contour2D * pointer;
        //!DOM
        typedef       OdUInt32    size_type;
        //!DOM
        typedef const Contour2D * const_iterator;
        //!DOM
        typedef       Contour2D * iterator;
        //!DOM
        size_type       size () const;
        //!DOM
        bool            empty() const;
        //!DOM
        size_type       capacity () const;
        //!DOM
        size_type       max_size () const;
        //!DOM
        const_reference operator [] ( size_type iPos ) const;
        //!DOM
              reference operator [] ( size_type iPos );
        //!DOM
        const_reference front() const;
        //!DOM
              reference front();
        //!DOM
        const_reference back () const;
        //!DOM
              reference back ();
        //!DOM
        const_iterator  begin() const;
        //!DOM
              iterator  begin();
        //!DOM
        const_iterator  end  () const;
        //!DOM
              iterator  end  ();

        /** \details
           Clears the profile.
        */
        void clear();

        /** \details
           Resizes the profile.
        */
        void resize( size_type iSize );

        //!DOM
        void reserve( size_type iNewCapacity );
        //!DOM
        Contour2D & push_back( );
        //!DOM
        Contour2D & push_back( ContourImplClass eCC );
        //!DOM
        void push_back( const Contour2D & rVal );
        //!DOM
        void pop_back ( );
        //!DOM
        void     erase ( size_type iPos );
        //!DOM
        iterator erase ( iterator itWhere );
        //!DOM
        iterator erase ( iterator itFirst, iterator itLast );
        //!DOM
        void     insert( size_type iPos, const Contour2D & rVal );
        //!DOM
        iterator insert( iterator itWhere, const Contour2D & rVal );
        //!DOM
        void     insert( iterator itWhere, const_iterator itFirst, const_iterator itLast );

        //!DOM
        void swap( Profile2D& rAnother );

        /** \details
           Appends the extents of the profile to the specified extents structure.
        */
        Result addExtents( OdGeExtents2d& extExtents ) const;

        /** \details
           Returns true if this profile contains at least one non-empty contour
        */
        bool hasNonEmptyContours() const;

        /** \details
           Reverses all contours.
        */
        void reverse();

        /** \details
           Transforms all contours.
        */
        Result transformBy(const OdGeMatrix2d& mMatrix,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev );

        /** \details
           Removes redundant segments with zero length for all contours.
        */
        void deleteCoincident( const OdGeTol& gTol = FMGeGbl::gTol );
    
        /** \details
           Merges adjacent segments for all contours.
          
           \param iMergeFlags [in]  combination of AECGe::FilletType flags (emfMergeArcs,emfIgnoreMetadata,emfMergeOrigin)
           \param gTol [in]  Tolerance.
        */
        void mergeSegments( int iMergeFlags = 0, const OdGeTol & gTol = FMGeGbl::gTol  );

        /** \details
           Explodes all contours.
        */
        Result explode( const DeviationParams& devDeviation = FMGeGbl::gDefDev,
            OdUInt32 uArcMetadata = 0 );

        /** \details
           Explodes all contours.
        */
        Result explodeTo( Profile2D& rDestProfile,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev,
            OdUInt32 uArcMetadata = 0 ) const;

        /** \details
           Returns the perimeter of the profile.
        */
        double perimeter() const;

        /** \details
           Returns the centroid of the profile.
        */
        OdGePoint2d centroid() const;

        /** \details
           Returns adjusted profile.
          
           \param dWidth [in]  Width of desired extents.
           \param dDepth [in]  Depth of desired extents.
           \param bAdjustWidth [in]  Adjusts the width to extents.
           \param bAdjustDepth [in]  Adjusts the depth to extents.
           \param bMirrorInX [in]  Mirror in X.
           \param bMirrorInY [in]  Mirror in Y.
           \param dRotation [in]  Rotation around Z axis.
           \param rResult [out]  Resulting profile.
        */
        void getAdjustedProfile( double dWidth, double dDepth,
            bool bAdjustWidth,bool bAdjustDepth,
            bool bMirrorInX, bool bMirrorInY,
            double dRotation, Profile2D& rResult ) const;

        /** \details
           Adjusts profile to bounding box extents.
        */
        void fit( const OdGeExtents2d& extBoundingBox,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev );

        /** \details
           Adjusts profile to bounding box extents.
        */
        void fit( const OdGeExtents2d& extBoundingBox,
            bool bFitX, bool bFitY,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev );

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

        /** \details
           Returns all hole contours reversed.
        */
        void getHoles( Profile2D& rHolesProfile ) const;

        /** \details
           Returns all non-hole contours.
        */
        void getWithoutHoles( Profile2D& rNoHolesProfile ) const;

        /** \details
           Returns profiles. Each of the returned profiles bounds 
           a connected domain, and contains one (the first one) big CCW contour 
           and possibly few smaller CW "holes".
          
           \remarks
           This profile should be "regular" (no self-intersections, valid nesting of CCW/CW ).
        */
        Result getFaces( std::vector<Profile2D>& aFaces ) const;

        /** \details
           Splits profile with a line.
        */
        void split( const OdGeLine2d& lCutter,
            Profile2D& rRght,
            Profile2D& rLeft ) const;

        /** \details
           Updates metadata for all segments in all contours.
        */
        Result setAllMetadata( OdUInt32 uNewData,
            OdUInt32 uBitsToModify = UINT_MAX );

        /** \details
           Performs boolean operation on 2D profiles.
          
           \remarks
           Each argument is a set of points on the plane, not necessary convex or connected.
           All contours must be non-selfintersecting, closed.
           Segments in contours must usually go counterclockwise, otherwise they will be counted as holes in other contours.
           The method performs operation on arguments and returns true if the operation is successful.
        */
        static bool PerformOperation( BooleanOperation eOperation,
            const Profile2D& rArg1, const Profile2D& rArg2, Profile2D& rResult, const OdGeTol& tol = FMGeGbl::gTol );

        /** \details
           Removes self-intersecting parts oriented clockwise
           and leaves counter-clockwise parts intact.
        */
        Result regularizeTo( Profile2D& rDest,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns whether this profile contains only closed contours
           and coincides with a directional boundary of some open 2D-region.
           
           \remarks
           - returns false for empty and for non-closed contours;
           - returns false, if there are coincident bounds with opposite directions (e.g. O-O shape);
           - returns false, if there are sub-contours with incorrect orientation (e.g. 8 shape)
           - returns true otherwise
        */
        bool isValidRegion( const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Returns signed area 
        */
        double signedArea() const;

        /** \details
           Returns single contour describing the profile with bridges
           between initial contours.
          
           \remarks
           The contour is not self-intersecting unless initial contours intersect.
          
           This profile should be "regular" (no self-intersections and valid nesting of
           CW/CCW contours )
        */
        Result getSingleContour( Contour2D& rDest,
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

        /** \details
           Tries to create a profile from standard ACAD object's geometry.
          
           \param idEntity [in]  Object ID of ACAD entity to convert geometry from. 
           \param mResult [out]  Result.
          
           \remarks
           Currently works for the following entities:
           * OdDbPolyline
        */
        /*static void convertFromObject( const OdDbObjectId& idEntity,
            const OdGeMatrix3d& mOCS, AECGe::Profile2D& rResult );*/

        /** \details
           Returns true if the point lies inside the profile or on it's border.
          
           \remarks
           Contours of the profile should be closed.
           pOnBorder is true, if the point lies on the border of the contour.
           The return value is equal to ( iNumCCW - iNumCW > 0 ), where the iNum(C)CW is 
               number of (C)CW contours, containing the point
               Default value (e.g. empty profile) is true
        */
        bool contains( const OdGePoint2d& ptTest, bool* pOnBorder = 0, 
            const OdGeTol& gTol = FMGeGbl::gTol ) const;

    private:
        //!DOM
        Contour2D* _insertItems( size_type iPos, size_type iCount = 1 );
        //!DOM
        void _uninsertItems( size_type iPos, size_type iCount = 1 );

    private:
        OdUInt32 m_iSize;
        OdUInt32 m_iCapacity;
        Contour2D * m_pContours;

    public:
        /** \details
           An empty static profile
        */
        FMGEOMETRY_API_STATIC static const Profile2D kNull;
};

Result FMGEOMETRY_API GetProfileWithOffsetSegment(const Profile2D& rSrc, Profile2D& rDest, OdUInt32 uContour, OdUInt32 uSegment, double dNormalOffset);

}; // namespace AECContours

#endif  //__FMPROFILE2D_H__
