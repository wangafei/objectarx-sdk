/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEINTRVL_H
#define GC_GEINTRVL_H

#include "gegbl.h"
#pragma pack (push, 8)

class
  GE_DLLDATAEXIMP
  GcGeInterval
{
public:
  GcGeInterval(double tol = 1.e-12);
  GcGeInterval(const GcGeInterval& src);
  GcGeInterval(double lower, double upper, double tol = 1.e-12);
  GcGeInterval(Gsoft::Boolean boundedBelow, double bound,
    double tol = 1.e-12);
  ~GcGeInterval();

  GcGeInterval&  operator =       (const GcGeInterval& otherInterval);

  double         lowerBound() const;
  double         upperBound() const;
  double         element() const;
  void           getBounds(double& lower, double& upper) const;
  double         length() const;
  double         tolerance() const;

  GcGeInterval&  set(double lower, double upper);
  GcGeInterval&  set(Gsoft::Boolean boundedBelow, double bound);
  GcGeInterval&  set();
  GcGeInterval&  setUpper(double upper);
  GcGeInterval&  setLower(double lower);
  GcGeInterval&  setTolerance(double tol);
  void           getMerge(const GcGeInterval& otherInterval, GcGeInterval& result) const;
  int            subtract(const GcGeInterval& otherInterval,
    GcGeInterval& lInterval,
    GcGeInterval& rInterval) const;
  Gsoft::Boolean intersectWith(const GcGeInterval& otherInterval, GcGeInterval& result) const;

  Gsoft::Boolean isBounded() const;
  Gsoft::Boolean isBoundedAbove() const;
  Gsoft::Boolean isBoundedBelow() const;
  Gsoft::Boolean isUnBounded() const;
  Gsoft::Boolean isSingleton() const;
  Gsoft::Boolean isDisjoint(const GcGeInterval& otherInterval) const;

  Gsoft::Boolean contains(const GcGeInterval& otherInterval) const;
  Gsoft::Boolean contains(double val) const;

  Gsoft::Boolean isContinuousAtUpper(const GcGeInterval& otherInterval) const;
  Gsoft::Boolean isOverlapAtUpper(const GcGeInterval& otherInterval,
    GcGeInterval& overlap) const;
  Gsoft::Boolean operator ==      (const GcGeInterval& otherInterval) const;
  Gsoft::Boolean operator !=      (const GcGeInterval& otherInterval) const;
  Gsoft::Boolean isEqualAtUpper(const GcGeInterval& otherInterval) const;
  Gsoft::Boolean isEqualAtUpper(double value) const;
  Gsoft::Boolean isEqualAtLower(const GcGeInterval& otherInterval) const;
  Gsoft::Boolean isEqualAtLower(double value) const;
  Gsoft::Boolean isPeriodicallyOn(double period, double& val);

  friend
    GE_DLLEXPIMPORT
    Gsoft::Boolean operator >       (double val, const GcGeInterval& intrvl);
  Gsoft::Boolean operator >       (double val) const;
  Gsoft::Boolean operator >       (const GcGeInterval& otherInterval) const;
  friend
    GE_DLLEXPIMPORT
    Gsoft::Boolean operator >=      (double val, const GcGeInterval& intrvl);
  Gsoft::Boolean operator >=      (double val) const;
  Gsoft::Boolean operator >=      (const GcGeInterval& otherInterval) const;
  friend
    GE_DLLEXPIMPORT
    Gsoft::Boolean operator <       (double val, const GcGeInterval& intrvl);
  Gsoft::Boolean operator <       (double val) const;
  Gsoft::Boolean operator <       (const GcGeInterval& otherInterval) const;
  friend
    GE_DLLEXPIMPORT
    Gsoft::Boolean operator <=      (double val, const GcGeInterval& intrvl);
  Gsoft::Boolean operator <=      (double val) const;
  Gsoft::Boolean operator <=      (const GcGeInterval& otherInterval) const;

protected:
  friend class GcGeImpInterval;
  class GcGeImpInterval  *mpImpInt;

  GcGeInterval(GcGeImpInterval&, int);

private:
  int              mDelInt;
};

#pragma pack (pop)
#endif