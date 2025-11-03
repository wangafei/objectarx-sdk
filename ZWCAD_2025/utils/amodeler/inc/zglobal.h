#ifndef AECMODELER_INC_GLOBAL_H
#define AECMODELER_INC_GLOBAL_H

#if !defined(LIB_VERSION_OF_AMODELER) && !defined(unix)
#ifdef AECMODELER_EXPORTS
#define DllImpExp __declspec(dllexport)
#else
#define DllImpExp __declspec(dllimport)
#endif
#else
#define DllImpExp
#endif

#if defined(_ADESK_MAC_) || _MSC_VER >= 1000
#define AECMODELER_NAMESPACE		AECModeler
#define AECMODELER_NAMESPACE_BEGIN	namespace AECModeler {
#define AECMODELER_NAMESPACE_END	}
#else
#define AMODELER_NAMESPACE
#define AMODELER_NAMESPACE_BEGIN
#define AMODELER_NAMESPACE_END
#endif

AECMODELER_NAMESPACE_BEGIN

#if _MSC_VER < 1100
#if !defined(true) && !defined(__GNUC__)
    typedef int bool;
const int true = 1;
const int false = 0;
#endif
#endif

AECMODELER_NAMESPACE_END

#include <stdio.h>
#include <stdlib.h>
#include "zmassert.h"
#include "zerrcodes.h"
#include "zepsilon.h"
#include "zflags.h"

AECMODELER_NAMESPACE_BEGIN

DllImpExp extern const double kPi;
DllImpExp extern const double kTwoPi;
DllImpExp extern const double kHalfPi;

DllImpExp extern const double kMaxReal;
DllImpExp extern const double kMinReal;
DllImpExp extern const double kDeg2Rad;
DllImpExp extern const double kEpsZero;

const int kTooBigInt = 10000000;

inline double sqr(double a) { return a * a; }
inline int sign(double a) { return a > 0.0 ? 1 : a < 0.0 ? -1 : 0; }
inline bool odd(int a) { return a & 0x1; }

#ifndef _ADESK_MAC_
inline int round(double d) //Is there is a C function doing this?
{
    return d >= 0.0 ? (int)(d + 0.5) : (int)(d - 0.5);
}
#endif

#ifdef unix
#define __max(a,b) ((a) >= (b) ? (a) : (b))
#define __min(a,b) ((a) <= (b) ? (a) : (b))
#endif

inline int prevIndex(int i, int n) { return i == 0 ? n - 1 : i - 1; }
inline int nextIndex(int i, int n) { return i == n - 1 ? 0 : i + 1; }

class ZwPoint2d;
class ZwVector2d;
class ZwPoint3d;
class ZwVector3d;
class ZwIntPoint2d;
class ZwIntVector2d;
class ZwIntPoint3d;
class ZwIntVector3d;
class ZwTransf3d;
class ZwLine3d;
class ZwCircle3d;
class ZwPlane;
class ZwInterval1d;
class ZwInterval2d;
class ZwInterval3d;
class ZwIntInterval1d;
class ZwIntInterval2d;
class ZwIntInterval3d;
class ZwEntity;
class ZwBody;
class ZwFace;
class ZwEdge;
class ZwVertex;
class ZwSurface;
class ZwCylinderSurface;
class ZwConeSurface;
class ZwSphereSurface;
class ZwTorusSurface;
class ZwCurve;
class ZwCircleCurve;
class ZwPolygonVertexData;
class ZwOutputPolylineCallback;
class ZwOutputTriangleCallback;
class ZwSaveRestoreCallback;
class ZwSaveToSatCallback;
class ZwTopologyChangeCallback;
class ZwTriangleCache;
class ZwDarray;
class ZwMorphingMapElem;
class ZwMorphingMap;
class ZwVertexSurfaceData;
class ZwHideIntegerTransform;

typedef bool abool;
DllImpExp void ZwSetKeepInputBodiesWhenBooleanOperationsFail(bool yesNo);
DllImpExp bool ZwKeepInputBodiesWhenBooleanOperationsFail();

AECMODELER_NAMESPACE_END

#endif
