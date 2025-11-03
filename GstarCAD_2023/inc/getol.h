/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GETOL_H
#define GC_GETOL_H

#ifndef unix
#include <stdlib.h>
#endif
#include "gedll.h"
#include "gedblar.h"
#pragma pack (push, 8)

class GE_DLLDATAEXIMP GcGeTol
{
public:
  GcGeTol();

  double  equalPoint() const;
  double  equalVector() const;
  void    setEqualPoint(double val);
  void    setEqualVector(double val);

private:
  double mTolArr[5];
  int    mAbs;

  friend class GcGeTolA;
};

inline void   GcGeTol::setEqualVector(double val)
{
  mTolArr[1] = val;
}
inline double GcGeTol::equalVector() const
{
  return mTolArr[1];
}

inline void   GcGeTol::setEqualPoint(double val)
{
  mTolArr[0] = val;
}
inline double GcGeTol::equalPoint() const
{
  return mTolArr[0];
}

#pragma pack (pop)
#endif