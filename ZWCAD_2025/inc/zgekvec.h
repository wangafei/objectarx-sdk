
#ifndef ZC_GEKVEC_H
#define ZC_GEKVEC_H

#include "zgegbl.h"
#include "zgedblar.h"
#pragma pack (push, 8)

class ZcGeInterval;

class
ZcGeKnotVector
{
public:

    GE_DLLDATAEXIMP static double globalKnotTolerance;
    GE_DLLEXPIMPORT ZcGeKnotVector(double eps = globalKnotTolerance);
    GE_DLLEXPIMPORT ZcGeKnotVector(int size, int growSize, double eps = globalKnotTolerance);
    GE_DLLEXPIMPORT ZcGeKnotVector(int size, const double [], double eps = globalKnotTolerance);

    GE_DLLEXPIMPORT ZcGeKnotVector(int plusMult, const ZcGeKnotVector& src);
    GE_DLLEXPIMPORT ZcGeKnotVector(const ZcGeKnotVector& src);
    GE_DLLEXPIMPORT ZcGeKnotVector(const ZcGeDoubleArray& src, double eps = globalKnotTolerance);

    GE_DLLEXPIMPORT ~ZcGeKnotVector();

    GE_DLLEXPIMPORT ZcGeKnotVector&     operator =  (const ZcGeKnotVector& src);
    GE_DLLEXPIMPORT ZcGeKnotVector&     operator =  (const ZcGeDoubleArray& src);

    GE_DLLEXPIMPORT double&             operator [] (int);
    GE_DLLEXPIMPORT const double        operator [] (int) const;

    GE_DLLEXPIMPORT ZSoft::Boolean      isEqualTo (const ZcGeKnotVector& other) const;

    GE_DLLEXPIMPORT double              startParam         () const;
    GE_DLLEXPIMPORT double              endParam           () const;
    GE_DLLEXPIMPORT int                 multiplicityAt     (int i) const;
    GE_DLLEXPIMPORT int                 multiplicityAt     (double param) const;
    GE_DLLEXPIMPORT int                 numIntervals       () const;

    GE_DLLEXPIMPORT int                 getInterval        (int ord, double par,
                                            ZcGeInterval& interval ) const;
    GE_DLLEXPIMPORT void                getDistinctKnots   (ZcGeDoubleArray& knots) const;
    GE_DLLEXPIMPORT ZSoft::Boolean      contains           (double param) const;
    GE_DLLEXPIMPORT ZSoft::Boolean      isOn               (double knot) const;

    GE_DLLEXPIMPORT ZcGeKnotVector&     reverse            ();
    GE_DLLEXPIMPORT ZcGeKnotVector&     removeAt           (int);
    GE_DLLEXPIMPORT ZcGeKnotVector&     removeSubVector    (int startIndex, int endIndex);

    GE_DLLEXPIMPORT ZcGeKnotVector&     insertAt           (int indx, double u,
                                            int multiplicity = 1);
    GE_DLLEXPIMPORT ZcGeKnotVector&     insert             (double u);
    GE_DLLEXPIMPORT int                 append             (double val);
    GE_DLLEXPIMPORT ZcGeKnotVector&     append             (ZcGeKnotVector& tail,
                                            double knotRatio = 0.);
    GE_DLLEXPIMPORT int                 split              (double par,
                                            ZcGeKnotVector* pKnot1,
                                            int multLast,
                                            ZcGeKnotVector* pKnot2,
                                            int multFirst ) const;

    GE_DLLEXPIMPORT ZcGeKnotVector&     setRange           (double lower, double upper);

    GE_DLLEXPIMPORT double              tolerance          () const;
    GE_DLLEXPIMPORT ZcGeKnotVector&     setTolerance       (double tol);

    GE_DLLEXPIMPORT int                 length             () const;
    GE_DLLEXPIMPORT ZSoft::Boolean      isEmpty            () const;
    GE_DLLEXPIMPORT int                 logicalLength      () const;
    GE_DLLEXPIMPORT ZcGeKnotVector&     setLogicalLength   (int);
    GE_DLLEXPIMPORT int                 physicalLength     () const;
    GE_DLLEXPIMPORT ZcGeKnotVector&     setPhysicalLength  (int);

    GE_DLLEXPIMPORT int                 growLength  () const;
    GE_DLLEXPIMPORT ZcGeKnotVector&     setGrowLength(int);

    GE_DLLEXPIMPORT const double*       asArrayPtr  () const;
    GE_DLLEXPIMPORT double*             asArrayPtr  ();

    GE_DLLEXPIMPORT ZcGeKnotVector&     set (int size, const double [], double eps = globalKnotTolerance);

protected:
    ZcGeDoubleArray    mData;
    double             mTolerance;

    ZSoft::Boolean     isValid (int) const;
};

inline double
ZcGeKnotVector::tolerance() const
{ return mTolerance;}

inline ZcGeKnotVector&
ZcGeKnotVector::setTolerance(double eps)
{ mTolerance = eps;	return *this;}

inline ZSoft::Boolean
ZcGeKnotVector::isValid(int i) const
{ return i >= 0 && i < mData.logicalLength(); }

inline double&
ZcGeKnotVector::operator [] (int i)
{ assert(isValid(i)); return mData[i]; }

inline const double
ZcGeKnotVector::operator [] (int i) const
{ assert(isValid(i)); return mData[i]; }

inline const double*
ZcGeKnotVector::asArrayPtr() const
{ return mData.asArrayPtr(); }

inline double*
ZcGeKnotVector::asArrayPtr()
{ return mData.asArrayPtr(); }

#pragma pack (pop)
#endif
