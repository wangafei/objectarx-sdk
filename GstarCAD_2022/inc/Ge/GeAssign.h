//Gcad Add
//xi hui
#ifndef OD_GE_ASSIGN_H
#define OD_GE_ASSIGN_H /* {Secret} */

#pragma pack (push, 8)

class OdGePoint2d;
class OdGeVector2d;
class OdGePoint3d;
class OdGeVector3d;

inline OdGePoint2d&
asPnt2d(const double* pnt)
{
	return *((OdGePoint2d*)pnt);
}

inline OdGeVector2d&
asVec2d(const double* vec)
{
	return *((OdGeVector2d*)vec);
}

inline double*
asDblArray(const OdGePoint2d& pnt)
{
	return (double*)&pnt;
}

inline double*
asDblArray(const OdGeVector2d& vec)
{
	return (double*)&vec;
}

inline OdGePoint3d&
asPnt3d(const double* pnt)
{
	return *((OdGePoint3d*)pnt);
}

inline OdGeVector3d&
asVec3d(const double* vec)
{
	return *((OdGeVector3d*)vec);
}

inline double*
asDblArray(const OdGePoint3d& pnt)
{
	return (double*)&pnt;
}

inline double*
asDblArray(const OdGeVector3d& vec)
{
	return (double*)&vec;
}

#pragma pack (pop)

#endif//OD_GE_ASSIGN_H