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

#ifndef __FMMDL_BASE_H__
#define __FMMDL_BASE_H__

#include "../FacetModeler/FMGeometry.h"
#include "../FacetModeler/FMErrorCodes.h"

#include <../Ge/GeExtents3d.h>
#include <../Ge/GePlane.h>
#include <../Ge/GePoint3d.h>
#include <../Ge/GeVector3d.h>
#include <../Ge/GePoint2d.h>
#include <../Ge/GeVector2d.h>

/**
  <group TA_Geometry>
*/
namespace FacetModeler
{
    class Entity;
    class Body;
    class Face;
    class Edge;
    class Vertex;

    class Point2d;
    class Vector2d;
    class Point3d;
    class Vector3d;
    class IntPoint2d;
    class IntVector2d;
    class IntPoint3d;
    class IntVector3d;
    class Transf3d;
    class Line3d;
    class Circle3d;
    class Plane;
    class Interval1d;
    class Interval2d;
    class Interval3d;
    class IntInterval1d;
    class IntInterval2d;
    class IntInterval3d;
    class Surface;
    class CylinderSurface;
    class ConeSurface;
    class SphereSurface;
    class TorusSurface;
    class Curve;
    class CircleCurve;
    class PolygonVertexData;
    class OutputPolylineCallback;
    class OutputTriangleCallback;
    class SaveRestoreCallback;
    class SaveToSatCallback;
    class TopologyChangeCallback;
    class TriangleCache;
    //class Darray;
    class MorphingMapElem;
    class MorphingMap;
    class VertexSurfaceData;
    class HideIntegerTransform;

    typedef OdArray<void*, OdMemoryAllocator<void*> > Darray;
    typedef ptrdiff_t AecTagType;

    FMGEOMETRY_API extern const double kPi;      
    FMGEOMETRY_API extern const double kTwoPi;    
    FMGEOMETRY_API extern const double kHalfPi;

    FMGEOMETRY_API extern const double kMaxReal; 
    FMGEOMETRY_API extern const double kMinReal;
    FMGEOMETRY_API extern const double kDeg2Rad;
    FMGEOMETRY_API extern const double kEpsZero; 

    inline double sqr (double a) { return a * a;                      }
    inline int    sign(double a) { return a > 0 ? 1 : a < 0 ? -1 : 0; }
    inline bool   odd (int    a) { return a & 0x1;                    }


    FMGEOMETRY_API void setKeepInputBodiesWhenBooleanOperationsFail(bool yesNo);
    FMGEOMETRY_API bool keepInputBodiesWhenBooleanOperationsFail();
};

#endif //__FMMDL_BASE_H__
