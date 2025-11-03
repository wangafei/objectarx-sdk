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

#ifndef __FMCONTOURSBASE_H__
#define __FMCONTOURSBASE_H__

#include "../FacetModeler/FMGeometry.h"
#include <../Ge/GePoint2d.h>
#include "../DoubleArray.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{
    /** \details
       Holds possible result codes used in Contour2D and Profile2D classes.
      
       \remarks
       Warnings are in range [erWarnings.. erErrors).
       Errors are greater than erErrors.
    */
    enum Result
    {
        // All correct.
        erOk = 0,

        // 
        erWarnings,

        // Parameter on contour is not valid.
        erWarnParamBounds,

        // Input point or vector is not on this entity. But it should be.
        erWarnPointNotOnThis,

        // Contour is empty.
        erWarnEmptyContour,

        // Contour is too small.
        erWarnSmallContour,

        // Region/Profile contours are not valid
        erWarnImproperAreas,

        // Some contour is not closed, but it should be.
        erWarnContourNotClosed,

        //
        erErrors = 0x1000,

        // Not implemented.
        erNotImplementedYet,

        // Array/segment index is out of range
        erInvalidIndex,

        // Parameter value is out of range.
        erParamBounds,

        // Input point or vector is not on this entity.
        erPointNotOnThis,

        // Invalid (singular) transformation matrix.
        erInvalidTransform,

        // wrong segment type. Another type expected.
        erWrongSegType,

        // Contour is empty.
        erEmptyContour,

        // Some points are invalid.
        erSingularPoints,

        // Metadata is not available and/or can`t be updated.
        erNoMetadata,

        // Some input parameters are completely invalid.
        erInvalidArgs,

        // Contour is too small.
        erContourIsTooSmall,

        // Contour or profile is self-intersecting.
        erSelfIntersecting,

        // Contour orientation is not applicable.
        erInvalidDirection,

        // Some contour is not closed, but it should be.
        erContourNotClosed,

        // Operation is not applicable.
        erOperationNotApplicable,

        // Invalid result in area operation.
        erFailedToCloseContours,

        // Region/Profile is not valid in regional operation.
        erImproperRegionBounds,

        // Region/Profile is not valid in regional operation.
        erImproperRegionAreas,

        // Tolerance is too small, or input contours are singular.
        erToleranceViolation,

        // Unknown error.
        erFail,

        //
        erLastError
    };

    /** \details
       Returns true unless eRes is an error.
    */
    inline bool isOk( Result eRes )
    { return eRes < erErrors;  };

    /** \details
       Returns true if eRes is a warning.
    */
    inline bool isWarning( Result eRes )
    { return eRes < erErrors && eRes >= erWarnings; };

    /** \details
       Returns true if eRes is an error.
    */
    inline bool isError( Result eRes )
    { return eRes >= erErrors; };

    /** \details
       Type of segment.
    */
    enum SegmentType
    {
        //
        estUnknown = 0,

        // Straight segment with length greater than 0.
        estLine,

        // Arc segment with length greater than 0.
        estArc,

        // Segment with 0 length.
        estCoincident
    };

    /** \details
       Object placement with respect to some other object.
    */
    enum Locations
    {
        elUnknown = 0,
        elInside,
        elOutside,
        elOnBound
    };

    /** \details
       Flags for mergeSegments method
    */
    enum MergeFlags
    {
        // Merge circular segments
        emfMergeArcs = 1,

        // Merge segments with different metadata
        emfIgnoreMetadata = 2,

        // Merge first and last segments of a closed contour
        emfMergeOrigin = 4
    };

    /** \details
       Gap filling strategy for offset curve generation
    */
    enum FilletType
    {
        // Close gaps with straight line segments
        eftChamfer,

        // Extend segments with tangential rays
        eftTangents,

        // Extend segments with tangential rays or circular arcs, 
        //  depending on segment types
        eftExtend,

        // Close gaps with circular arcs
        eftCircular
    };

    //!DOM
    enum ContourImplClass
    {
        ecicUnknown = 0,
        ecicSimple,
        ecicCached,
        ecicLast
    };

    //!DOM
    enum SegmentImplClass
    {
        esicUnknown = 0,
        esicBulgeSeg2D,
        esicCachedSeg2D,
        esicLast
    };

    /** \details
       Describes an intersection between 2 curves/segments.
    */
    class FMGEOMETRY_API Intersection
    {
        public:
            /** \details
               Intersection types.
            */
            enum Types
            {
                // No intersection
                eitNone = 0,

                // Intersection of any type (the type was not defined).
                eitAny,

                // Curves cross each other at the point.
                eitCrossing,

                // Curves touch each other at the point.
                eitTouch
            };

            /** \details
               Constructor.
            */
            Intersection() : dParamA( 0 ), dParamB( 0 ), eType( eitNone )
            { }

            /** \details
               Constructor.
            */
            Intersection( const OdGePoint2d& rPt, double dPA = 0, double dPB = 0, Types eIT = eitNone )
                : ptPoint( rPt ), dParamA( dPA ), dParamB( dPB ), eType( eIT )
            { }

            /** \details
               Swaps parameters of intersection.
            */
            inline Intersection & swapParams()
            {
                std::swap( dParamA, dParamB );
                return *this;
            };

            /** \details
               Returns whether parameter A in rI1 intersection is less than parameter A in rI2.
            */
            inline static bool lessParamA( const Intersection& rI1, const Intersection& rI2 )
            { return rI1.dParamA < rI2.dParamA; };

            /** \details
               Returns whether parameter B in rI1 intersection is less than parameter B in rI2.
            */
            inline static bool lessParamB( const Intersection& rI1, const Intersection& rI2 )
            { return rI1.dParamB < rI2.dParamB; };

        public:
            /** \details
               Intersection point.
            */
            OdGePoint2d ptPoint;

            /** \details
               Parameter on the curve A.
            */
            OdDouble dParamA;

            /** \details
               Parameter on the curve B.
            */
            OdDouble dParamB;

            /** \details
               Type of intersection.
            */
            Types eType; 
    };
};

#endif  //__FMCONTOURSBASE_H__
