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

#ifndef __FMCONTOUR3D_H__
#define __FMCONTOUR3D_H__

#include "../FacetModeler/FMContour2D.h"
#include "../FacetModeler/FMWrapper3D.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

/** \details
   2D Contour in 3D space.
  
   \remarks
   Contains 2D contour and 3d transformation matrix.
*/
class FMGEOMETRY_API Contour3D : public Contour2D, public Wrapper3D
{
    public:
        /** \details
           Constructor.
        */
        Contour3D();

        /** \details
           Destructor.
        */
        ~Contour3D();

        /** \details
           Constructor.
        */
        explicit Contour3D( const Contour2D& rFrom2d,
            const OdGeMatrix3d& rMatrix = OdGeMatrix3d::kIdentity );

        /** \details
           Constructor.
        */
        explicit Contour3D( const Contour2D& rFrom2d,
            const OdGeVector3d& vXAxis, const OdGeVector3d& vYAxis );

        /** \details
           Constructor.
        */
        explicit Contour3D( const OdGeVector3d& vXAxis,
            const OdGeVector3d& vYAxis, const OdGePoint3d& ptOrigin = OdGePoint3d::kOrigin );

        /** \details
           Constructor.
        */
        explicit Contour3D( const OdGePlane& rPlane );

        /** \details
           Transforms all points of the contour.
        */
        Result transformBy( const OdGeMatrix2d& mMatrix );

        /** \details
           Transforms contour's matrix.
        */
        Result transformBy(const OdGeMatrix3d& geMatrix );

        /** \details
           Returns 3D point at specified index.
        */
        Result getPoint3DAt( OdUInt32 iIndex,
            OdGePoint3d& ptPoint3D ) const;

        /** \details
           Returns 3D point at specified parameter.
        */
        Result getPoint3D( double dParam,
            OdGePoint3d& ptPoint3D ) const;

        /** \details
           Returns 3D tangent at specified parameter.
        */
        Result getTangent3D( double dParam,
            OdGeVector3d& vTangent3D ) const;
};

}; // namespace AECContours

#endif  //__FMCONTOUR3D_H__
