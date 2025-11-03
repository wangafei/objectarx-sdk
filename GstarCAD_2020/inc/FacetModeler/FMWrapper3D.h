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

#ifndef __FMWRAPPER3D_H__
#define __FMWRAPPER3D_H__

#include "../FacetModeler/FMContoursBase.h"
#include <../Ge/GeMatrix3d.h>
#include <../Ge/GePlane.h>
#include <../Ge/GePoint3d.h>
/**
  <group TA_Geometry>
*/
namespace FacetModeler
{

class FMGEOMETRY_API Wrapper3D
{
    public:
        /** \details
           Constructor.
        */
        Wrapper3D();

        /** \details
           Constructor.
        */
        explicit Wrapper3D( const OdGeMatrix3d& rMatrix );

        /** \details
           Constructor.
        */
        explicit Wrapper3D( const OdGeVector3d& vXAxis,
            const OdGeVector3d& vYAxis,
            const OdGePoint3d& ptOrigin = OdGePoint3d::kOrigin );

        /** \details
           Constructor.
        */
        explicit Wrapper3D( const OdGePlane& rPlane );

        /** \details
           Returns transformation matrix
        */
        const OdGeMatrix3d& transform() const;

        OdGePlane plane() const;

        /** \details
           Returns inversed transformation matrix
        */
        const OdGeMatrix3d& inversedTransform() const;

        /** \details
           Sets transformation matrix.
        */
        Result setTransform( const OdGeMatrix3d& mTransform );

        /** \details
           Sets transformation matrix.
        */
        Result setTransform( const OdGeVector3d& vXAxis,
            const OdGeVector3d& vYAxis,
            const OdGePoint3d& ptOrigin = OdGePoint3d::kOrigin );

        /** \details
           Applies given matrix to the matrix of transformation.
        */
        Result transformBy( const OdGeMatrix3d& mMatrix );

        /** \details
           Transforms to 3D coordinate system.
        */
        void to3D( const OdGePoint2d& rSource2D,
            OdGePoint3d& rDest3D ) const;

        /** \details
           Transforms to 3D coordinate system.
        */
        void to3D( const OdGeVector2d& rSource2D,
            OdGeVector3d& rDest3D ) const;

        /** \details
           Transforms from 3D coordinate system.
        */
        Result to2D( const OdGePoint3d& rSource3D,
            OdGePoint2d& rDest2D ) const;

        /** \details
           Transforms from 3D coordinate system.
        */
        Result to2D( const OdGeVector3d& rSource3D,
            OdGeVector2d& rDest2D ) const;

        /** \details
           Swaps 3d transform.
        */
        void swap( Wrapper3D& rAnother );

        /** \details
        */
        bool getUnifiedTransform(const OdGeMatrix3d& mDest, OdGeMatrix3d& mNewTrans3D, OdGeMatrix2d& mTrans2D ) const;

    private:
        OdGeMatrix3d m_mTrans;
        OdGeMatrix3d m_mInvertTrans;
};

}; // namespace AECContours

#endif  //__FMWRAPPER3D_H__
