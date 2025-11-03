#pragma once
#include "zAcPointCloudEngineAPI.h"

class ZCDB_PORT PointCloudBinaryOperatorFilter : public IPointCloudFilter
{
public:
    virtual ~PointCloudBinaryOperatorFilter();
    virtual int testCell(double minX, double minY,
                         double minZ, double maxX,
                         double maxY, double maxZ) const = 0;

    virtual bool testPoint(float x, float y, float z) const = 0;

    virtual IPointCloudFilter* clone() const = 0;

    virtual void freeObject(void) = 0;

    virtual bool isInverted() const;
    virtual void setIsInverted(bool bInverted);

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

class ZCDB_PORT PointCloudIntersectionFilter : public PointCloudBinaryOperatorFilter
{
public:
    PointCloudIntersectionFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
    virtual ~PointCloudIntersectionFilter();
    virtual int testCell(double minX, double minY, double minZ,
                        double maxX, double maxY, double maxZ) const;
    virtual bool testPoint(float x, float y, float z) const;
    virtual IPointCloudFilter* clone() const;
    virtual void freeObject(void);
};

class ZCDB_PORT PointCloudUnionFilter : public PointCloudBinaryOperatorFilter
{
public:
    PointCloudUnionFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
    virtual ~PointCloudUnionFilter();

    virtual int testCell(double minX, double minY, double minZ,
                        double maxX, double maxY, double maxZ) const;
    virtual bool testPoint(float x, float y, float z) const;
    virtual IPointCloudFilter* clone() const;
    virtual void freeObject(void);
};

class ZCDB_PORT PointCloudXORFilter : public PointCloudBinaryOperatorFilter
{
public:
    PointCloudXORFilter(IPointCloudFilter* pLeft, IPointCloudFilter* pRight);
    virtual ~PointCloudXORFilter();

    virtual int testCell(double minX, double minY, double minZ,
                        double maxX, double maxY, double maxZ) const;
    virtual bool testPoint(float x, float y, float z) const;
    virtual IPointCloudFilter* clone() const;
    virtual void freeObject(void);
};
