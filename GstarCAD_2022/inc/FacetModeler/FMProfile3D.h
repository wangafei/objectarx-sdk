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

#ifndef __FMPROFILE3D_H__
#define __FMPROFILE3D_H__

#include "../FacetModeler/FMProfile2D.h"
#include "../FacetModeler/FMWrapper3D.h"

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

/** \details
   2D Profile in 3D space.
  
   \remarks
   Contains 2D Profile and 3d transformation matrix.
*/
class FMGEOMETRY_API Profile3D : public Profile2D, public Wrapper3D
{
    public:
        /** \details
           Constructor.
        */
        Profile3D();

        /** \details
           Destructor.
        */
        ~Profile3D();

        /** \details
           Constructor.
        */
        explicit Profile3D( const Profile2D& cFrom2d );

        /** \details
           Constructor.
        */
        explicit Profile3D( const Profile2D& cFrom2d,
            const OdGeMatrix3d& mMatrix );
        
        /** \details
           Constructor.
        */
        explicit Profile3D( const Profile2D& cFrom2d,
            const OdGeVector3d& vXAxis, const OdGeVector3d& vYAxis );

        /** \details
           Constructor.
        */
        explicit Profile3D( const Profile2D& cFrom2d,
            const OdGePlane& rPlane );

        /** \details
           Constructor.
        */
        explicit Profile3D( const OdGeMatrix3d& mMatrix );
        
        /** \details
           Constructor.
        */
        explicit Profile3D( const OdGeVector3d& vXAxis, 
            const OdGeVector3d& vYAxis, const OdGePoint3d& ptOrigin = OdGePoint3d::kOrigin );

        /** \details
           Constructor.
        */
        explicit Profile3D( const OdGePlane& pPlane );

        /** \details
           Transforms all points of the profile.
        */
        Result transformBy(const OdGeMatrix2d& mMatrix,
            const DeviationParams& devDeviation = FMGeGbl::gDefDev );
    
        /** \details
           Transforms profile's matrix.
        */
        Result transformBy(const OdGeMatrix3d& mMatrix );

        /** \details
           Swap 2D data but keep 3D transform.
        */
        void swap( Profile2D& rAnother );

        /** \details
           Swap 2D data and 3D transform.
        */
        void swap( Profile3D& rAnother );

        /** \details
           Cast this profile to 2D
        */
        inline const Profile2D& as2d() const { return *this; }

        /** \details
           Cast this profile to 2D
        */
        inline       Profile2D& as2d()       { return *this; }
};

}; // namespace AECContours

#endif  //__FMPROFILE3D_H__
