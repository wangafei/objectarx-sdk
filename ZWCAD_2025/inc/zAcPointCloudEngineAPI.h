#pragma once
#include "zacdbport.h"

class ZCDB_PORT IPointCloudFilter
{
public:

    virtual int testCell(double minX, double minY, double minZ,
                        double maxX, double maxY, double maxZ) const = 0;

    virtual bool testPoint(float x, float y, float z) const = 0;

    virtual void prepareForCell(double& minX, double& minY, double& minZ,
                                double& maxX, double& maxY, double& maxZ,
                                long numTests)
    {
        UNREFERENCED_PARAMETER(minX);
        UNREFERENCED_PARAMETER(minY);
        UNREFERENCED_PARAMETER(minZ);
        UNREFERENCED_PARAMETER(maxX);
        UNREFERENCED_PARAMETER(maxY);
        UNREFERENCED_PARAMETER(maxZ);
        UNREFERENCED_PARAMETER(numTests);
    };

    virtual IPointCloudFilter* clone() const = 0;

    virtual void freeObject(void) = 0;

    virtual bool isInverted() const
    {
        return false;
    }

    virtual void setIsInverted(bool bInverted)
    {
        UNREFERENCED_PARAMETER(bInverted);
    }

};

class ZCDB_PORT IPointCloudFilter2 : public IPointCloudFilter
{
public:

    virtual IPointCloudFilter2* transformFilter(const double* transform4x4) const = 0;

    virtual int testPoint(const double* pointData) const = 0;

    virtual ~IPointCloudFilter2() {};
};
