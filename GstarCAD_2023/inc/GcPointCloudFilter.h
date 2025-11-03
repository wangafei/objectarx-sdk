/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcPointCloudEngineAPI.h"


class GCDB_PORT PointCloudBinaryOperatorFilter : public IPointCloudFilter
{
public:
  virtual ~PointCloudBinaryOperatorFilter();
  int testCell(double minX, double minY,
    double minZ, double maxX,
    double maxY, double maxZ) const  override = 0;
  bool testPoint(float x, float y, float z) const override = 0;
  IPointCloudFilter* clone() const override = 0;
  void freeObject(void) override = 0;
  bool isInverted() const override;
  void setIsInverted(bool bInverted) override;

protected:
  PointCloudBinaryOperatorFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
  PointCloudBinaryOperatorFilter(const PointCloudBinaryOperatorFilter& other);

  IPointCloudFilter*  mpLeftFilter;
  IPointCloudFilter*  mpRightFilter;

private:
  bool                mbIsInverted;

private:
  PointCloudBinaryOperatorFilter& operator = (const PointCloudBinaryOperatorFilter&);
};

class GCDB_PORT PointCloudIntersectionFilter : public PointCloudBinaryOperatorFilter
{
public:
  PointCloudIntersectionFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
  ~PointCloudIntersectionFilter();
  int testCell(double minX, double minY, double minZ,
    double maxX, double maxY, double maxZ) const override;
  bool testPoint(float x, float y, float z) const override;
  IPointCloudFilter* clone() const override;
  void freeObject(void) override;
};

class GCDB_PORT PointCloudUnionFilter : public PointCloudBinaryOperatorFilter
{
public:
  PointCloudUnionFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
  ~PointCloudUnionFilter();

  int testCell(double minX, double minY, double minZ,
    double maxX, double maxY, double maxZ) const override;
  bool testPoint(float x, float y, float z) const override;
  IPointCloudFilter* clone() const override;
  void freeObject(void) override;
};

class GCDB_PORT PointCloudXORFilter : public PointCloudBinaryOperatorFilter
{
public:
  PointCloudXORFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
  ~PointCloudXORFilter();

  int testCell(double minX, double minY, double minZ,
    double maxX, double maxY, double maxZ) const override;
  bool testPoint(float x, float y, float z) const override;
  IPointCloudFilter* clone() const override;
  void freeObject(void) override;
};