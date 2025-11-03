/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GEMAT3D_H
#define GC_GEMAT3D_H

#include "gegbl.h"
#include "gemat2d.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class GcGeLine3d;
class GcGeVector3d;
class GcGePlane;
class GcGeTol;

class GE_DLLDATAEXIMP GcGeMatrix3d
{
public:
  GcGeMatrix3d();
  GcGeMatrix3d(const GcGeMatrix3d& src);

  static const   GcGeMatrix3d    kIdentity;

  GcGeMatrix3d&  setToIdentity();

  GcGeMatrix3d   operator *      (const GcGeMatrix3d& mat) const;
  GcGeMatrix3d&  operator *=     (const GcGeMatrix3d& mat);
  GcGeMatrix3d&  preMultBy(const GcGeMatrix3d& leftSide);
  GcGeMatrix3d&  postMultBy(const GcGeMatrix3d& rightSide);
  GcGeMatrix3d&  setToProduct(const GcGeMatrix3d& mat1, const GcGeMatrix3d& mat2);

  GcGeMatrix3d&  invert();
  GcGeMatrix3d   inverse() const;
  GcGeMatrix3d   inverse(const GcGeTol& tol) const;
  Gsoft::Boolean isSingular(const GcGeTol& tol = GcGeContext::gTol) const;

  GcGeMatrix3d&  transposeIt();
  GcGeMatrix3d   transpose() const;

  bool operator ==     (const GcGeMatrix3d& mat) const;
  bool operator !=     (const GcGeMatrix3d& mat) const;
  bool isEqualTo(const GcGeMatrix3d& mat, const GcGeTol& tol = GcGeContext::gTol) const;

  Gsoft::Boolean isUniScaledOrtho(const GcGeTol& tol = GcGeContext::gTol) const;
  Gsoft::Boolean isScaledOrtho(const GcGeTol& tol = GcGeContext::gTol) const;
  double         det() const;
  GcGeMatrix3d&  setTranslation(const GcGeVector3d& vec);
  GcGeVector3d   translation() const;

  GcGeMatrix3d&  setCoordSystem(const GcGePoint3d&  origin,
                                                const GcGeVector3d& xAxis,
                                                const GcGeVector3d& yAxis,
                                                const GcGeVector3d& zAxis);
  void           getCoordSystem(GcGePoint3d&  origin,
                                                GcGeVector3d& xAxis,
                                                GcGeVector3d& yAxis,
                                                GcGeVector3d& zAxis) const;

  GcGeMatrix3d&  setToTranslation(const GcGeVector3d& vec);
  GcGeMatrix3d&  setToRotation(double              angle,
                                               const GcGeVector3d& axis,
                                               const GcGePoint3d&  center = GcGePoint3d::kOrigin);
  GcGeMatrix3d&  setToScaling(double scaleAll, const GcGePoint3d& center = GcGePoint3d::kOrigin);
  GcGeMatrix3d&  setToMirroring(const GcGePlane& pln);
  GcGeMatrix3d&  setToMirroring(const GcGePoint3d& pnt);
  GcGeMatrix3d&  setToMirroring(const GcGeLine3d& line);
  GcGeMatrix3d&  setToProjection(const GcGePlane& projectionPlane, const GcGeVector3d& projectDir);
  GcGeMatrix3d&  setToAlignCoordSys(const GcGePoint3d&  fromOrigin,
                                                    const GcGeVector3d& fromXAxis,
                                                    const GcGeVector3d& fromYAxis,
                                                    const GcGeVector3d& fromZAxis,
                                                    const GcGePoint3d&  toOrigin,
                                                    const GcGeVector3d& toXAxis,
                                                    const GcGeVector3d& toYAxis,
                                                    const GcGeVector3d& toZAxis);

  GcGeMatrix3d&  setToWorldToPlane(const GcGeVector3d& normal);
  GcGeMatrix3d&  setToWorldToPlane(const GcGePlane& plane);
  GcGeMatrix3d&  setToPlaneToWorld(const GcGeVector3d& normal);
  GcGeMatrix3d&  setToPlaneToWorld(const GcGePlane& plane);

  static GcGeMatrix3d   translation(const GcGeVector3d& vec);
  static GcGeMatrix3d   rotation(double              angle,
                                                 const GcGeVector3d& axis,
                                                 const GcGePoint3d&  center = GcGePoint3d::kOrigin);
  static GcGeMatrix3d   scaling(double scaleAll, const GcGePoint3d& center = GcGePoint3d::kOrigin);
  static GcGeMatrix3d   mirroring(const GcGePlane& pln);
  static GcGeMatrix3d   mirroring(const GcGePoint3d& pnt);
  static GcGeMatrix3d   mirroring(const GcGeLine3d& line);
  static GcGeMatrix3d   projection(const GcGePlane& projectionPlane, const GcGeVector3d& projectDir);
  static GcGeMatrix3d   alignCoordSys(const GcGePoint3d&  fromOrigin,
                                                      const GcGeVector3d& fromXAxis,
                                                      const GcGeVector3d& fromYAxis,
                                                      const GcGeVector3d& fromZAxis,
                                                      const GcGePoint3d&  toOrigin,
                                                      const GcGeVector3d& toXAxis,
                                                      const GcGeVector3d& toYAxis,
                                                      const GcGeVector3d& toZAxis);

  static GcGeMatrix3d   worldToPlane(const GcGeVector3d& normal);
  static GcGeMatrix3d   worldToPlane(const GcGePlane&);
  static GcGeMatrix3d   planeToWorld(const GcGeVector3d& normal);
  static GcGeMatrix3d   planeToWorld(const GcGePlane&);

  double scale(void) const;
  double norm() const;

  GcGeMatrix2d convertToLocal(GcGeVector3d& normal, double& elev) const;

  double         operator ()     (unsigned int, unsigned int) const;
  double&        operator ()     (unsigned int, unsigned int);

  double         entry[4][4];

  Gsoft::Boolean  inverse(GcGeMatrix3d& inv, double tol) const;

private:
  void           pivot(int, GcGeMatrix3d&);
  int            pivotIndex(int) const;
  void           swapRows(int, int, GcGeMatrix3d&);
};

inline bool GcGeMatrix3d::operator == (const GcGeMatrix3d& otherMatrix) const
{
  return this->isEqualTo(otherMatrix);
}

inline bool GcGeMatrix3d::operator != (const GcGeMatrix3d& otherMatrix) const
{
  return !this->isEqualTo(otherMatrix);
}

inline double  GcGeMatrix3d::operator () (unsigned int row, unsigned int column) const
{
  return entry[row][column];
}

inline double& GcGeMatrix3d::operator () (unsigned int row, unsigned int column)
{
  return entry[row][column];
}

#pragma pack (pop)
#endif
