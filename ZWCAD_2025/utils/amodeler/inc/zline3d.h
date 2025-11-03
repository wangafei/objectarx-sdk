
#ifndef AECMODELER_INC_LINE3D_H
#define AECMODELER_INC_LINE3D_H

#include "zpoint3d.h"

AECMODELER_NAMESPACE_BEGIN

class DllImpExp ZwLine3d
{
public:
    ZwLine3d() : point(ZwPoint3d::kNull), vector(ZwVector3d::kNull) {}
    ZwLine3d(const ZwPoint3d& p, const ZwVector3d& v) : point(p), vector(v) {}
    ZwLine3d(const ZwPoint3d& p1, const ZwPoint3d& p2) : point(p1), vector(p2 - p1) {}

    double dist(const ZwPoint3d&) const;
    ZwPoint3d project(const ZwPoint3d&) const;

    void operator *=(const ZwTransf3d&);

    bool intersect(const ZwLine3d&, ZwPoint3d& intersPoint) const;

    bool isEqual(const ZwLine3d&) const;
    bool isValid() const { return !vector.isNull(); }

    bool isCoincident(const ZwLine3d&, bool sameDirectionAlso) const;

    ZwPoint3d point;
    ZwVector3d vector;

    static const ZwLine3d kNull;
    static const ZwLine3d kXAxis;
    static const ZwLine3d kYAxis;
    static const ZwLine3d kZAxis;
};

AECMODELER_NAMESPACE_END

#endif
