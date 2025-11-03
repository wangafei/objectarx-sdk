/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_GLOBAL_H
#define GMODELER_INC_GLOBAL_H


#if !defined(LIB_VERSION_OF_GMODELER) && !defined(unix)
#ifdef BUILD_AECMODELER
#define DllImpExp __declspec(dllexport)
#else
#define DllImpExp __declspec(dllimport)
#endif
#else
#define DllImpExp
#endif



#if defined(_GSOFT_MAC_) || _MSC_VER >= 1000
#define GMODELER_NAMESPACE         GModeler
#define GMODELER_NAMESPACE_BEGIN   namespace GModeler {
#define GMODELER_NAMESPACE_END     }
#else
#define GMODELER_NAMESPACE         
#define GMODELER_NAMESPACE_BEGIN  
#define GMODELER_NAMESPACE_END
#endif

GMODELER_NAMESPACE_BEGIN

#if _MSC_VER < 1100
#if !defined(true) && !defined(__GNUC__)
  typedef int bool;
const   int true = 1;
const   int false = 0;
#endif
#endif

GMODELER_NAMESPACE_END


#include <stdio.h>
#include <stdlib.h>
#include "massert.h"   
#include "errcodes.h"
#include "epsilon.h"
#include "flags.h"

GMODELER_NAMESPACE_BEGIN

DllImpExp extern const double kPi;
DllImpExp extern const double kTwoPi;
DllImpExp extern const double kHalfPi;
DllImpExp extern const double kMaxReal;
DllImpExp extern const double kMinReal;
DllImpExp extern const double kDeg2Rad;
DllImpExp extern const double kEpsZero;

const int kTooBigInt = 10000000;

inline double sqr(double a) { return a * a; }
inline int    sign(double a) { return a > 0 ? 1 : a < 0 ? -1 : 0; }
inline bool   odd(int    a) { return a & 0x1; }

#ifndef _GSOFT_MAC_
inline int round(double d)
{
  return d >= 0 ? (int)(d + 0.5) : (int)(d - 0.5);
}
#endif

#ifdef unix
#define __max(a,b)  ((a) >= (b) ? (a) : (b))
#define __min(a,b)  ((a) <= (b) ? (a) : (b))
#endif

inline int prevIndex(int i, int n) { return i == 0 ? n - 1 : i - 1; }
inline int nextIndex(int i, int n) { return i == n - 1 ? 0 : i + 1; }

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
class Entity;
class Body;
class Face;
class Edge;
class Vertex;
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
class Darray;
class MorphingMapElem;
class MorphingMap;
class VertexSurfaceData;
class HideIntegerTransform;

typedef bool abool;

DllImpExp void setKeepInputBodiesWhenBooleanOperationsFail(bool yesNo);
DllImpExp bool keepInputBodiesWhenBooleanOperationsFail();

GMODELER_NAMESPACE_END
#endif
