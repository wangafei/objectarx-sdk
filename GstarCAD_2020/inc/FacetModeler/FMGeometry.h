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

#ifndef __FMGEOMETRY_H__
#define __FMGEOMETRY_H__

#include <../OdaCommon.h>
#include "../FacetModeler/FMBuildSettings.h"
#include "../FacetModeler/FMSTLHelper.h"
#include <../Ge/GeTol.h>
#include <../Ge/GePlane.h>
#include <../Ge/GeMatrix2d.h>
#include <../Ge/GeLine2d.h>

#define FMGE_ANGLE_TO_MINUSPI_PI(x) ( (x>OdaPI)?(x-Oda2PI):(x) ) 

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{
    struct FMGEOMETRY_API DeviationParams
    {
        DeviationParams();
        DeviationParams( double deviation, OdUInt16 maxpercircle, OdUInt16 minpercircle );

        double Deviation;
        OdUInt16 MaxPerCircle;
        OdUInt16 MinPerCircle;
    };

    /** \details
       Type of boolean operation.
    */
    enum BooleanOperation
    {
        eUnion        = 0,
        eIntersection = 1,
        eDifference   = 2,
        eXOR          = 3,
        eExtrusion = 4,
        eRevolution = 5,
        eInsideBody = 6,
        eInsideFrame = 7,
        eCustom = 8,
        eTemporaryExtensionByTwoContours = 9,
        eTemporaryExtensionExtrusionByTrs = 10,

        eclone = 100,
        enegate,
        emergeCoincidentVertices,
        emergeCoplanarEntities,
        ecombine,
        ebox,
        epyramid,
        eextrusion1,
        eextrusion2,
        eextrusion3,
        erevolution1,
        erevolution2,
        einsideBody,
        einsideFrame,
        ecustomInternal,
        esection,
        ecutWithExtrusion,
        ecutWithInfExtrusion,
        eextrude,
        eTemporary_Extension_byTwoContours,
        eTemporary_Extension_byTwoProfiles,
        eTemporary_Extension_extrusionByTrs
    };

    enum BoolOperType
    {
      kBoolOperUnite,
      kBoolOperSubtract,
      kBoolOperIntersect
    };


    enum BodyInterferenceType
    {
      kBodiesDoNotInterfere,
      kBodiesTouch,
      kBodiesInterfere
    };

    enum PointInBodyLocation
    {
      kPointOutsideBody,
      kPointAtVertex,
      kPointOnEdge,
      kPointInFace,
      kPointInsideBody
    };

    enum HiddenLinesDisplay
    {
      kHiddenLinesInvisible,
      kHiddenLinesDashed,
      kHiddenLinesVisible
    };

    enum HiddenLineDrawingImprove
    {
      kNoDrawingImprove,
      kConnectDrawingImprove,
      kArcReconstructDrawingImprove
    };

    enum TriangulationType
    {
      kGenerateTriangles,
      kGenerateQuadrilaterals,
      kGenerateTriStrips,
      kGenerateTriStripsPerSurface
    };
    
    /** \details
       Classification result.
    */
    enum Classification
    {
        eNo           = 0,
        eOn           = 1,
        eInner        = 2,
        eOuter        = 3,
        eSpanning     = 4
    };

    /** \details
       Face orientation.
      
       \remarks
       Default orientation is treated like efoFront.
       Should not be used.
    */
    enum FaceOrientation
    {
        efoDefault  = 0x00,
        efoTop      = 0x01,
        efoBottom   = 0x02,
        efoLeft     = 0x04,
        efoRight    = 0x08,
        efoFront    = 0x10,
        efoBack     = 0x20,
        efoDiscard  = 0x80
    };

    //!DOM
    // Substitute for Teigha for .dwg files analog.
    FMGEOMETRY_API bool isCoplanar( const OdGePlane& plane1, const OdGePlane& plane2 );


    //!DOM
    // Teigha for .dwg files foreign method, should be on OdGeMatrix2d.
    FMGEOMETRY_API void setToMirroring( OdGeMatrix2d& thisMatrix, const OdGePoint2d& mirrorPoint );

    //!DOM
    // Teigha for .dwg files foreign method, should be on OdGeMatrix2d.
    FMGEOMETRY_API void setToMirroring( OdGeMatrix2d& thisMatrix, const OdGeLine2d& mirrorLine );

// {group:API Auxiliary Classes}
struct FMGEOMETRY_API FMGeGbl
{
    /** \details
       Default deviation parameters.
      
       \remarks
       By default deviation is 0.5,
       maximum facets per full circle - 128,
       minimum facets per full circle - 8.
    */
    FMGEOMETRY_API_STATIC static DeviationParams gDefDev;

    /** \details
       Tolerance used in mesh operations.
      
       \remarks
       The default value for tolerance is 1E-6.
    */
    FMGEOMETRY_API_STATIC static OdGeTol gTol;

    /** \details
       Returns the number of linear segments for exploded arc,
       specified by sweep angle and radius.
    */
    FMGEOMETRY_API_STATIC static OdUInt16 GetSegmentCount( double dAngle, double dRadius,
        const DeviationParams& devDeviation );

    /** \details
       Returns orientation .
    */
    static FaceOrientation PlaneOrientation( const OdGeVector3d& normal );

    /** \details
       Returns inversed orientation.
    */
    FMGEOMETRY_API_STATIC static FaceOrientation
        GetReversedOrientation( FaceOrientation eOri );

};

inline FaceOrientation FMGeGbl::PlaneOrientation( const OdGeVector3d& normal ) {
  if ( normal.isParallelTo( OdGeVector3d::kXAxis ) ) {
    return normal.x > 0. ? efoRight : efoLeft;
  }
  else if ( normal.isParallelTo( OdGeVector3d::kYAxis ) ) {
    return normal.y > 0. ? efoBack : efoFront;
  }
  else if ( normal.isParallelTo( OdGeVector3d::kZAxis ) ) {
    return normal.z > 0. ? efoTop : efoBottom;
  }
  return efoDefault;
}

class Interval3d;

// Don't use the following global variables directly, use the inline functions
// instead. We have to keep these variables in the header file to be able to
// inline the access functions.
//
FMGEOMETRY_API extern double gEpsAbs;
FMGEOMETRY_API extern double gEpsAbsSqrd;
FMGEOMETRY_API extern double gEpsNor;     
FMGEOMETRY_API extern double gEpsNorSqrd; 


inline double epsAbs    () { return gEpsAbs;     }
inline double epsAbsSqrd() { return gEpsAbsSqrd; }

inline double epsNor    () { return gEpsNor;     }
inline double epsNorSqrd() { return gEpsNorSqrd; }

FMGEOMETRY_API extern void setEpsAbs(double eps);
FMGEOMETRY_API extern void setEpsNor(double eps); // Should not be called by end users

// Potentially grows the value of the global epsAbs so that it is also 
// appropriate for the given object. It only increates the value of epsAbs, 
// if needed, it never decreases it, thus maintaining the largest epsAbs that 
// is large enough for all objects.
//
FMGEOMETRY_API extern void adjustEpsAbsByObject(const Interval3d& objectInterval);

// Sets the maximum allowed value of epsAbs. Any larger values will be reduced 
// to maxEpsAbs. If maxEpsAbs is 0.0, no maximum is imposed. This limit has
// been introduced mainly to make sure adjustEpsAbsByObject() does not increase
// epsAbs beyond some reasonable value.
//
FMGEOMETRY_API extern void setMaxEpsAbs(double maxEpsAbs);


// Sets a global variable that is used to control how the Boolean operation
// algorithm handles intersections of faces that are almost coplanar
//
FMGEOMETRY_API extern bool setAdjustEpsAbsInFlatIntersections(bool);
}

#endif  //__FMGEOMETRY_H__
