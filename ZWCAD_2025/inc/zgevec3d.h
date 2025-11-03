

#ifndef ZC_GEVEC3D_H
#define ZC_GEVEC3D_H

#include "zadesk.h"
#include "zgegbl.h"
#include "zgegblabb.h"
#pragma pack (push, 8)

class ZcGeMatrix3d;
class ZcGeVector2d;
class ZcGePlane;
class ZcGePlanarEnt;

class 
ZcGeVector3d
{
public:
   GE_DLLEXPIMPORT  ZcGeVector3d();
   GE_DLLEXPIMPORT ZcGeVector3d(const ZcGeVector3d& vec);
   GE_DLLEXPIMPORT ZcGeVector3d(double x, double y, double z);
   GE_DLLEXPIMPORT ZcGeVector3d(const ZcGePlanarEnt&, const ZcGeVector2d&);

   GE_DLLDATAEXIMP static const   ZcGeVector3d kIdentity;
   GE_DLLDATAEXIMP static const   ZcGeVector3d kXAxis;
   GE_DLLDATAEXIMP static const   ZcGeVector3d kYAxis;
   GE_DLLDATAEXIMP static const   ZcGeVector3d kZAxis;

   friend GE_DLLEXPIMPORT
   ZcGeVector3d   operator *  (const ZcGeMatrix3d& mat, const ZcGeVector3d& vec);
   GE_DLLEXPIMPORT ZcGeVector3d&  setToProduct(const ZcGeMatrix3d& mat, const ZcGeVector3d& vec);
   
   GE_DLLEXPIMPORT ZcGeVector3d&  transformBy (const ZcGeMatrix3d& leftSide);
   GE_DLLEXPIMPORT ZcGeVector3d&  rotateBy    (double ang , const ZcGeVector3d& axis );
   GE_DLLEXPIMPORT ZcGeVector3d&  mirror      (const ZcGeVector3d& normalToPlane);
   GE_DLLEXPIMPORT ZcGeVector2d   convert2d   (const ZcGePlanarEnt& pln) const;

   GE_DLLEXPIMPORT ZcGeVector3d   operator *  (double scl) const;
   friend GE_DLLEXPIMPORT
   ZcGeVector3d   operator *  (double scl, const ZcGeVector3d& vec);
   GE_DLLEXPIMPORT ZcGeVector3d&  operator *= (double scl);
   GE_DLLEXPIMPORT ZcGeVector3d&  setToProduct(const ZcGeVector3d& vec, double scl);
   GE_DLLEXPIMPORT ZcGeVector3d   operator /  (double scl) const;
   GE_DLLEXPIMPORT ZcGeVector3d&  operator /= (double scl);

   GE_DLLEXPIMPORT ZcGeVector3d   operator +  (const ZcGeVector3d& vec) const;
   GE_DLLEXPIMPORT ZcGeVector3d&  operator += (const ZcGeVector3d& vec);
   GE_DLLEXPIMPORT ZcGeVector3d   operator -  (const ZcGeVector3d& vec) const;
   GE_DLLEXPIMPORT ZcGeVector3d&  operator -= (const ZcGeVector3d& vec);
   GE_DLLEXPIMPORT ZcGeVector3d&  setToSum    (const ZcGeVector3d& vec1, const ZcGeVector3d& vec2);
   GE_DLLEXPIMPORT ZcGeVector3d   operator -  () const;
   GE_DLLEXPIMPORT ZcGeVector3d&  negate      ();

   GE_DLLEXPIMPORT ZcGeVector3d   perpVector  () const;

   GE_DLLEXPIMPORT double         angleTo     (const ZcGeVector3d& vec) const;
   GE_DLLEXPIMPORT double         angleTo     (const ZcGeVector3d& vec,
                                const ZcGeVector3d& refVec) const;
   GE_DLLEXPIMPORT double         angleOnPlane(const ZcGePlanarEnt& pln) const;

   GE_DLLEXPIMPORT ZcGeVector3d   normal      (const ZcGeTol& tol = ZcGeContext::gTol) const;
   GE_DLLEXPIMPORT ZcGeVector3d&  normalize   (const ZcGeTol& tol = ZcGeContext::gTol);
   GE_DLLEXPIMPORT ZcGeVector3d&  normalize   (const ZcGeTol& tol, ZcGeError& flag);
		
   GE_DLLEXPIMPORT double         length      () const;
   GE_DLLEXPIMPORT double         lengthSqrd  () const;
   GE_DLLEXPIMPORT ZSoft::Boolean isUnitLength(const ZcGeTol& tol = ZcGeContext::gTol) const;
   GE_DLLEXPIMPORT ZSoft::Boolean isZeroLength(const ZcGeTol& tol = ZcGeContext::gTol) const;

   GE_DLLEXPIMPORT ZSoft::Boolean isParallelTo(const ZcGeVector3d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;
   GE_DLLEXPIMPORT ZSoft::Boolean isParallelTo(const ZcGeVector3d& vec,
                                const ZcGeTol& tol, ZcGeError& flag) const;

   GE_DLLEXPIMPORT ZSoft::Boolean isCodirectionalTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
   GE_DLLEXPIMPORT ZSoft::Boolean isCodirectionalTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol, ZcGeError& flag) const;

   GE_DLLEXPIMPORT ZSoft::Boolean isPerpendicularTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol = ZcGeContext::gTol) const;
   GE_DLLEXPIMPORT ZSoft::Boolean isPerpendicularTo(const ZcGeVector3d& vec,
                                     const ZcGeTol& tol, ZcGeError& flag) const;

   GE_DLLEXPIMPORT double         dotProduct  (const ZcGeVector3d& vec) const;
   GE_DLLEXPIMPORT ZcGeVector3d   crossProduct(const ZcGeVector3d& vec) const;

   GE_DLLEXPIMPORT ZcGeMatrix3d   rotateTo    (const ZcGeVector3d& vec, const ZcGeVector3d& axis
                                = ZcGeVector3d::kIdentity) const;

   GE_DLLEXPIMPORT ZcGeVector3d   project      (const ZcGeVector3d& planeNormal,
                                 const ZcGeVector3d& projectDirection) const;
   GE_DLLEXPIMPORT ZcGeVector3d   project      (const ZcGeVector3d& planeNormal,
                                 const ZcGeVector3d& projectDirection,  
								 const ZcGeTol& tol, ZcGeError& flag) const;

   GE_DLLEXPIMPORT ZcGeVector3d   orthoProject (const ZcGeVector3d& planeNormal) const;
   GE_DLLEXPIMPORT ZcGeVector3d   orthoProject (const ZcGeVector3d& planeNormal, 
								const ZcGeTol& tol, ZcGeError& flag) const;

   GE_DLLEXPIMPORT bool operator == (const ZcGeVector3d& vec) const;
   GE_DLLEXPIMPORT bool operator != (const ZcGeVector3d& vec) const;
   GE_DLLEXPIMPORT bool isEqualTo   (const ZcGeVector3d& vec,
                                const ZcGeTol& tol = ZcGeContext::gTol) const;

   GE_DLLEXPIMPORT double         operator [] (unsigned int i) const;
   GE_DLLEXPIMPORT double&        operator [] (unsigned int i);
   GE_DLLEXPIMPORT unsigned int   largestElement() const;
   GE_DLLEXPIMPORT ZcGeVector3d&  set         (double x, double y, double z);
   GE_DLLEXPIMPORT ZcGeVector3d&  set         (const ZcGePlanarEnt& pln, const ZcGeVector2d& vec);

   GE_DLLEXPIMPORT operator       ZcGeMatrix3d() const;

    double         x, y, z;
};

inline
ZcGeVector3d::ZcGeVector3d() : x(0.0), y(0.0), z(0.0)
{
}

inline
ZcGeVector3d::ZcGeVector3d(const ZcGeVector3d& src)
{
    constexpr size_t sizeOfDouble = sizeof(double);
    memcpy_s(&x, sizeOfDouble, &(src.x), sizeOfDouble);
    memcpy_s(&y, sizeOfDouble, &(src.y), sizeOfDouble);
    memcpy_s(&z, sizeOfDouble, &(src.z), sizeOfDouble);
}

inline
ZcGeVector3d::ZcGeVector3d(double xx, double yy, double zz) : x(xx),y(yy),z(zz)
{
}

inline bool
ZcGeVector3d::operator == (const ZcGeVector3d& v) const
{
    return this->isEqualTo(v);
}

inline bool
ZcGeVector3d::operator != (const ZcGeVector3d& v) const
{
    return !this->isEqualTo(v);
}

inline ZcGeVector3d
ZcGeVector3d::operator + (const ZcGeVector3d& v) const
{
    return ZcGeVector3d (x + v.x, y + v.y, z + v.z);
}

inline ZcGeVector3d&
ZcGeVector3d::operator += (const ZcGeVector3d& v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline ZcGeVector3d
ZcGeVector3d::operator - (const ZcGeVector3d& v) const
{
    return ZcGeVector3d (x - v.x, y - v.y, z - v.z);
}

inline ZcGeVector3d&
ZcGeVector3d::operator -= (const ZcGeVector3d& v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

inline ZcGeVector3d&
ZcGeVector3d::setToSum(const ZcGeVector3d& v1, const ZcGeVector3d& v2)
{
    x = v1.x + v2.x;
    y = v1.y + v2.y;
    z = v1.z + v2.z;
    return *this;
}

inline ZcGeVector3d
ZcGeVector3d::operator - () const
{
    return ZcGeVector3d (-x, -y, -z);
}

inline ZcGeVector3d&
ZcGeVector3d::negate()
{
    x = -x;
    y = -y;
    z = -z;
    return *this;
}

inline ZcGeVector3d
ZcGeVector3d::operator * (double s) const
{
    return ZcGeVector3d (x * s, y * s, z * s);
}

inline ZcGeVector3d&
ZcGeVector3d::operator *= (double s)
{
    x *= s;
    y *= s;
    z *= s;
    return *this;
}

inline ZcGeVector3d&
ZcGeVector3d::setToProduct(const ZcGeVector3d& v, double s)
{
    x = s * v.x;
    y = s * v.y;
    z = s * v.z;
    return *this;
}

inline ZcGeVector3d
ZcGeVector3d::operator / (double val) const
{
    return ZcGeVector3d (x/val, y/val, z/val);
}

inline ZcGeVector3d&
ZcGeVector3d::operator /= (double val)
{
    x /= val;
    y /= val;
    z /= val;
    return *this;
}

inline double
ZcGeVector3d::lengthSqrd() const
{
    return x*x + y*y + z*z;
}

inline double
ZcGeVector3d::dotProduct(const ZcGeVector3d& v) const
{
    return x * v.x + y * v.y + z * v.z;
}

inline ZcGeVector3d&
ZcGeVector3d::set(double xx, double yy, double zz)
{
    x = xx;
    y = yy;
    z = zz;
    return *this;
}

inline double
ZcGeVector3d::operator [] (unsigned int i) const
{
    return *(&x+i);
}

inline double& ZcGeVector3d::operator [] (unsigned int i)
{
    return *(&x+i);
}
#define ZSOFT_ZCGEVECTOR3D_DEFINED
#include "zacarrayhelper.h"

#pragma pack (pop)
#endif
