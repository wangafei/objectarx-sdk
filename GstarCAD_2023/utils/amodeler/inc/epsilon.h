/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_EPSILON_H
#define GMODELER_INC_EPSILON_H

GMODELER_NAMESPACE_BEGIN

class Interval3d;

DllImpExp extern double gEpsAbs;
DllImpExp extern double gEpsAbsSqrd;
DllImpExp extern double gEpsNor;
DllImpExp extern double gEpsNorSqrd;

inline double epsAbs() { return gEpsAbs; }
inline double epsAbsSqrd() { return gEpsAbsSqrd; }

inline double epsNor() { return gEpsNor; }
inline double epsNorSqrd() { return gEpsNorSqrd; }

DllImpExp extern void setEpsAbs(double eps);
DllImpExp extern void setEpsNor(double eps);

DllImpExp extern void adjustEpsAbsByObject(const Interval3d& objectInterval);

DllImpExp extern void setMaxEpsAbs(double maxEpsAbs);

DllImpExp extern bool setAdjustEpsAbsInFlatIntersections(bool);

GMODELER_NAMESPACE_END
#endif
