/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEASSIGN_H
#define GC_GEASSIGN_H

#pragma pack (push, 8)
class GcGePoint2d;
class GcGeVector2d;
class GcGePoint3d;
class GcGeVector3d;

inline GcGePoint2d&
asPnt2d(const double* pnt)
{
  return *((GcGePoint2d*)pnt);
}

inline GcGeVector2d&
asVec2d(const double* vec)
{
  return *((GcGeVector2d*)vec);
}
#ifdef  __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-align"
#endif
inline double*
asDblArray(const GcGePoint2d& pnt)
{
  return (double*)&pnt;
}

inline double*
asDblArray(const GcGeVector2d& vec)
{
  return (double*)&vec;
}
#ifdef  __clang__
#pragma clang diagnostic pop
#endif

inline GcGePoint3d&
asPnt3d(const double* pnt)
{
  return *((GcGePoint3d*)pnt);
}

inline GcGeVector3d&
asVec3d(const double* vec)
{
  return *((GcGeVector3d*)vec);
}
#ifdef  __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wcast-align"
#endif
inline double*
asDblArray(const GcGePoint3d& pnt)
{
  return (double*)&pnt;
}

inline double*
asDblArray(const GcGeVector3d& vec)
{
  return (double*)&vec;
}
#ifdef  __clang__
#pragma clang diagnostic pop
#endif

#pragma pack (pop)
#endif