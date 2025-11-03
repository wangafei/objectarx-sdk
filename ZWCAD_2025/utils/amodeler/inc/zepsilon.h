
#ifndef AECMODELER_INC_EPSILON_H
#define AECMODELER_INC_EPSILON_H

AECMODELER_NAMESPACE_BEGIN

class ZwInterval3d;

DllImpExp extern double gEpsAbs;
DllImpExp extern double gEpsAbsSqrd;
DllImpExp extern double gEpsNor;
DllImpExp extern double gEpsNorSqrd;

inline double ZwEpsAbs() { return gEpsAbs; }
inline double ZwEpsAbsSqrd() { return gEpsAbsSqrd; }

inline double ZwEpsNor() { return gEpsNor; }
inline double ZwEpsNorSqrd() { return gEpsNorSqrd; }

DllImpExp extern void setEpsAbs(double eps);
DllImpExp extern void setEpsNor(double eps);

DllImpExp extern void adjustEpsAbsByObject(const ZwInterval3d& objectInterval);

DllImpExp extern void setMaxEpsAbs(double maxEpsAbs);

DllImpExp extern bool setAdjustEpsAbsInFlatIntersections(bool);

AECMODELER_NAMESPACE_END

#endif
