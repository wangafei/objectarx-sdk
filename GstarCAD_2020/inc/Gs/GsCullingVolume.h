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


#ifndef _ODGSCULLINGVOLUME_H_INCLUDED_
#define _ODGSCULLINGVOLUME_H_INCLUDED_

#include "../OdaCommon.h"
#include "../RxObject.h"
#include "../Gs/GsExport.h"
#include "../Ge/GeBoundBlock3d.h"
#include "../Ge/GeExtents3d.h"
#include "../Ge/GePoint3d.h"
#include "../Ge/GeSphere.h"
#include "../Ge/GeVector3d.h"

#include "../TD_PackPush.h"

// Culling primitives:
// BBox (AABB - Axis Aligned Bounding Box)
// BSphere (Bounding Sphere)
// OBBox (OBB - Oriented Bounding Box)

/** Description:
    Base class for culling primitives.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsCullingPrimitive
{
  public:
    /** Description:
      Type of culling primitive.

      Remarks:
      @table
      Name               Value    Description
      kPrimBBox          0        Axis Alligned Bounding Box.
      kPrimBSphere       1        Bounding Sphere.
      kPrimOBBox         2        Oriented Bounding Box.
    */
    enum PrimitiveType
    {
      kPrimBBox,
      kPrimBSphere,
      kPrimOBBox
    };
  public:
    OdGsCullingPrimitive()
    {
    }

    virtual ~OdGsCullingPrimitive()
    {
    }

    /** Description:
      Returns culling primitive type.
      
      Remarks:
      @table
      Name               Value    Description
      kPrimBBox          0        Axis Alligned Bounding Box.
      kPrimBSphere       1        Bounding Sphere.
      kPrimOBBox         2        Oriented Bounding Box.
    */
    virtual PrimitiveType primitiveType() const = 0;
};

/** Description:
    Culling primitive: axis alligned bounding box.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsCullingBBox : public OdGsCullingPrimitive, public OdGeExtents3d
{
  public:
    OdGsCullingBBox()
      : OdGsCullingPrimitive()
      , OdGeExtents3d()
    {
    }

    OdGsCullingBBox(const OdGePoint3d &min, const OdGePoint3d &max)
      : OdGsCullingPrimitive()
      , OdGeExtents3d(min, max)
    {
    }

    OdGsCullingBBox(const OdGeExtents3d &ext)
      : OdGsCullingPrimitive()
      , OdGeExtents3d(ext.minPoint(), ext.maxPoint())
    {
    }

    OdGsCullingBBox(const OdGsCullingBBox &aabb)
      : OdGsCullingPrimitive()
      , OdGeExtents3d(aabb.minPoint(), aabb.maxPoint())
    {
    }

    ~OdGsCullingBBox()
    {
    }

    OdGsCullingBBox &operator =(const OdGeExtents3d &ext)
    {
      set(ext.minPoint(), ext.maxPoint());
      return *this;
    }

    OdGsCullingBBox &operator =(const OdGsCullingBBox &aabb)
    {
      set(aabb.minPoint(), aabb.maxPoint());
      return *this;
    }

    operator OdGeExtents3d&()
    {
      return *this;
    }

    operator const OdGeExtents3d&() const
    {
      return *this;
    }

    // OdGsCullingPrimitive overrides

    /** Description:
      Returns culling primitive type.
    */
    PrimitiveType primitiveType() const
    {
      return kPrimBBox;
    }
};

/** Description:
    Culling primitive: bounding sphere.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsCullingBSphere : public OdGsCullingPrimitive, public OdGeSphere // GeSphere has many unnecessary data for culling
{
  public:
    OdGsCullingBSphere()
      : OdGsCullingPrimitive()
      , OdGeSphere()
    {
    }

    OdGsCullingBSphere(double radius, const OdGePoint3d &center)
      : OdGsCullingPrimitive()
      , OdGeSphere(radius, center)
    {
    }

    OdGsCullingBSphere(const OdGeSphere &sphere)
      : OdGsCullingPrimitive()
      , OdGeSphere(sphere)
    {
    }

    OdGsCullingBSphere(const OdGsCullingBSphere &bsphere)
      : OdGsCullingPrimitive()
      , OdGeSphere(bsphere)
    {
    }

    ~OdGsCullingBSphere()
    {
    }

    OdGsCullingBSphere &operator =(const OdGeSphere &sphere)
    {
      set(sphere.radius(), sphere.center());
      return *this;
    }

    OdGsCullingBSphere &operator =(const OdGsCullingBSphere &bsphere)
    {
      set(bsphere.radius(), bsphere.center());
      return *this;
    }

    operator OdGeSphere&()
    {
      return *this;
    }

    operator const OdGeSphere&() const
    {
      return *this;
    }

    // OdGsCullingPrimitive overrides

    /** Description:
      Returns culling volume type.
    */
    PrimitiveType primitiveType() const
    {
      return kPrimBSphere;
    }
};

/** Description:
    Culling primitive: oriented bounding box.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsCullingOBBox : public OdGsCullingPrimitive, public OdGeBoundBlock3d
{
  public:
    OdGsCullingOBBox()
      : OdGsCullingPrimitive()
      , OdGeBoundBlock3d()
    {
    }

    OdGsCullingOBBox(const OdGePoint3d &base, const OdGeVector3d &xAxis, const OdGeVector3d &yAxis, const OdGeVector3d &zAxis)
      : OdGsCullingPrimitive()
      , OdGeBoundBlock3d(base, xAxis, yAxis, zAxis)
    {
    }

    OdGsCullingOBBox(const OdGeBoundBlock3d &bb)
      : OdGsCullingPrimitive()
      , OdGeBoundBlock3d(bb)
    {
    }

    OdGsCullingOBBox(const OdGsCullingOBBox &obb)
      : OdGsCullingPrimitive()
      , OdGeBoundBlock3d(obb)
    {
    }

    ~OdGsCullingOBBox()
    {
    }

    OdGsCullingOBBox &operator =(const OdGeBoundBlock3d &bb)
    {
      OdGePoint3d base; OdGeVector3d side1, side2, side3;
      bb.get(base, side1, side2, side3);
      set(base, side1, side2, side3);
      return *this;
    }

    OdGsCullingOBBox &operator =(const OdGsCullingOBBox &obb)
    {
      OdGePoint3d base; OdGeVector3d side1, side2, side3;
      obb.get(base, side1, side2, side3);
      set(base, side1, side2, side3);
      return *this;
    }

    operator OdGeBoundBlock3d&()
    {
      return *this;
    }

    operator const OdGeBoundBlock3d&() const
    {
      return *this;
    }

    // OdGsCullingPrimitive overrides

    /** Description:
      Returns culling primitive type.
    */
    PrimitiveType primitiveType() const
    {
      return kPrimOBBox;
    }
};

// Projection culling primitives:
// Ortho (Orthogonal culling box merged with optimization for 2d mode)
// Frustum (Perspective culling box without near and far culling planes)

/** Description:
    Base class for orthogonal and perspective culling volumes.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsCullingVolume : public OdRxObject
{
  public:
    enum ProjectionType
    {
      kProjOrtho,
      kProjPerspective
    };
    enum IntersectionStatus
    {
      kIntersectNot, // No intersection detected
      kIntersectOk, // Intersects with projection boundary
      kIntersectIn // Primitive completely inside projection boundary
    };
  public:
    ODRX_DECLARE_MEMBERS(OdGsCullingVolume);

    /** Description:
        Returns type of projection for this culling volume object.

        Remarks:
        @table
        Name               Value    Description
        kProjOrtho         0        Orthogonal projection.
        kProjPerspective   1        Perspective projection.
    */
    virtual ProjectionType projectionType() const = 0;

    /** Description:
        Optimized intersection test between culling volume and culling primitive.
        Arguments:
        prim (I) Input primitive for culling detection.
    */
    virtual bool intersectWithOpt(const OdGsCullingPrimitive &prim) const = 0;
    /** Description:
        Intersection test between culling volume and culling primitive (returns complete and incomplete
        intersection statuses).

        Remarks:
        Return value intersection statuses:
        @table
        Name               Value    Description
        kIntersectNot      0        No intersection detected.
        kIntersectOk       1        Intersects with culling volume boundary.
        kIntersectIn       2        Culling volume primitive is completely inside culling volume boundary.

        Arguments:
        prim (I) Input primitive for culling detection.
    */
    virtual IntersectionStatus intersectWith(const OdGsCullingPrimitive &prim) const = 0;

    /** Description:
        Transform culling volume by transformation matrix.
        Arguments:
        xfm (I) Xform matrix.
    */
    virtual void transformBy(const OdGeMatrix3d& xfm) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsCullingVolume object pointers.
*/
typedef OdSmartPtr<OdGsCullingVolume> OdGsCullingVolumePtr;

/** Description:
    Orthogonal culling volume.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsOrthoCullingVolume : public OdGsCullingVolume
{
  public:
    ODRX_DECLARE_MEMBERS(OdGsOrthoCullingVolume);

    /** Description:
        Initialize frustum culling volume by new values.
        Arguments:
        position (I) View position.
        direction (I) View direction.
        upVector (I) View up vector.
        volumeWidth (I) Horizontal field of view.
        volumeHeight (I) Vertical field of view.
    */
    virtual void init(const OdGePoint3d &position, const OdGeVector3d &direction, const OdGeVector3d &upVector,
                      double volumeWidth, double volumeHeight) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsOrthoCullingVolume object pointers.
*/
typedef OdSmartPtr<OdGsOrthoCullingVolume> OdGsOrthoCullingVolumePtr;

/** Description:
    Perspective culling volume.

    Library: TD_Gs

    {group:OdGs_Classes} 
*/
class GS_TOOLKIT_EXPORT OdGsFrustumCullingVolume : public OdGsCullingVolume
{
  public:
    ODRX_DECLARE_MEMBERS(OdGsFrustumCullingVolume);

    /** Description:
        Initialize frustum culling volume by new values.
        Arguments:
        position (I) View position.
        direction (I) View direction.
        upVector (I) View up vector.
        fovY (I) Horizontal field of view in radians.
        aspect (I) Aspect ratio between horizontal and vertical field of view (aspect = h / v).
        nPlanes (I) Number of culling planes to test intersection (1,2,3,4 - enable only side planes, 5 - enable nearZ plane, 6 - enable farZ plane).
        nearZ (I) Near Z-axis culling plane (must be greater than zero).
        farZ (I) Far Z-axis culling plane.
    */
    virtual void init(const OdGePoint3d &position, const OdGeVector3d &direction, const OdGeVector3d &upVector,
                      double fovY, double aspect, OdUInt32 nPlanes = 4, double nearZ = 1.0, double farZ = 1e20) = 0;
    /** Description:
        Initialize frustum culling volume by new values.
        Arguments:
        position (I) View position.
        direction (I) View direction.
        upVector (I) View up vector.
        fovX (I) Horizontal field of view in radians.
        aspect (I) If enabled - then fovY is aspect ratio (fovY = h / v), elsewhere fovY is vertical field of view in radians.
        fovY (I) Aspect ratio or vertical field of view in radians (see aspect argument description).
        nPlanes (I) Number of culling planes to test intersection (1,2,3,4 - enable only side planes, 5 - enable nearZ plane, 6 - enable farZ plane).
        nearZ (I) Near Z-axis culling plane (must be greater than zero).
        farZ (I) Far Z-axis culling plane.
    */
    virtual void init(const OdGePoint3d &position, const OdGeVector3d &direction, const OdGeVector3d &upVector,
                      double fovX, bool aspect, double fovY, OdUInt32 nPlanes = 4, double nearZ = 1.0, double farZ = 1e20) = 0;
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdGsFrustumCullingVolume object pointers.
*/
typedef OdSmartPtr<OdGsFrustumCullingVolume> OdGsFrustumCullingVolumePtr;

#include "../TD_PackPop.h"

#endif // _ODGSCULLINGVOLUME_H_INCLUDED_
