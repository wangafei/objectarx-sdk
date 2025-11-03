/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEKVEC_H
#define GC_GEKVEC_H

#include "gegbl.h"
#include "gedblar.h"
#pragma pack (push, 8)

class GcGeInterval;

class GE_DLLDATAEXIMP GcGeKnotVector
{
public:
  static double globalKnotTolerance;
  GcGeKnotVector(double eps = globalKnotTolerance);
  GcGeKnotVector(int size, int growSize, double eps = globalKnotTolerance);
  GcGeKnotVector(int size, const double[], double eps = globalKnotTolerance);
  GcGeKnotVector(int plusMult, const GcGeKnotVector& src);
  GcGeKnotVector(const GcGeKnotVector& src);
  GcGeKnotVector(const GcGeDoubleArray& src, double eps = globalKnotTolerance);
  ~GcGeKnotVector();

  GcGeKnotVector&     operator =  (const GcGeKnotVector& src);
  GcGeKnotVector&     operator =  (const GcGeDoubleArray& src);
  double&             operator [] (int);
  const double        operator [] (int) const;

  Gsoft::Boolean      isEqualTo(const GcGeKnotVector& other) const;

  double              startParam() const;
  double              endParam() const;
  int                 multiplicityAt(int i) const;
  int                 multiplicityAt(double param) const;
  int                 numIntervals() const;

  int                 getInterval(int ord, double par, GcGeInterval& interval) const;
  void                getDistinctKnots(GcGeDoubleArray& knots) const;
  Gsoft::Boolean      contains(double param) const;
  Gsoft::Boolean      isOn(double knot) const;

  GcGeKnotVector&     reverse();
  GcGeKnotVector&     removeAt(int);
  GcGeKnotVector&     removeSubVector(int startIndex, int endIndex);

  GcGeKnotVector&     insertAt(int indx, double u, int multiplicity = 1);
  GcGeKnotVector&     insert(double u);
  int                 append(double val);
  GcGeKnotVector&     append(GcGeKnotVector& tail, double knotRatio = 0.);
  int                 split(double          par,
                                            GcGeKnotVector* pKnot1,
                                            int             multLast,
                                            GcGeKnotVector* pKnot2,
                                            int             multFirst) const;

  GcGeKnotVector&     setRange(double lower, double upper);

  double              tolerance() const;
  GcGeKnotVector&     setTolerance(double tol);

  int                 length() const;
  Gsoft::Boolean      isEmpty() const;
  int                 logicalLength() const;
  GcGeKnotVector&     setLogicalLength(int);
  int                 physicalLength() const;
  GcGeKnotVector&     setPhysicalLength(int);

  int                 growLength() const;
  GcGeKnotVector&     setGrowLength(int);

  const double*       asArrayPtr() const;
  double*             asArrayPtr();

  GcGeKnotVector&     set(int size, const double[], double eps = globalKnotTolerance);

protected:
  GcGeDoubleArray    mData;
  double             mTolerance;

  Gsoft::Boolean     isValid(int) const;
};

inline double GcGeKnotVector::tolerance() const
{
  return mTolerance;
}

inline GcGeKnotVector& GcGeKnotVector::setTolerance(double eps)
{
  mTolerance = eps;
  return *this;
}

inline Gsoft::Boolean GcGeKnotVector::isValid(int i) const
{
  return i >= 0 && i < mData.logicalLength();
}

inline double& GcGeKnotVector::operator [] (int i)
{
  assert(isValid(i));
  return mData[i];
}

inline const double GcGeKnotVector::operator [] (int i) const
{
  assert(isValid(i));
  return mData[i];
}

inline const double* GcGeKnotVector::asArrayPtr() const
{
  return mData.asArrayPtr();
}

inline double* GcGeKnotVector::asArrayPtr()
{
  return mData.asArrayPtr();
}

#pragma pack (pop)
#endif
