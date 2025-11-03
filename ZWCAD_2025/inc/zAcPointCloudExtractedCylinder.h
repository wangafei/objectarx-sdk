#pragma once

#include <memory>

class ZcPointCloudExtractedCylinderImp;

class ZCDB_PORT ZcPointCloudExtractedCylinder
{
public:
    ZcPointCloudExtractedCylinder();
    ZcPointCloudExtractedCylinder(double radius, double height, ZcGeVector3d axis = ZcGeVector3d::kZAxis, ZcGePoint3d origin = ZcGePoint3d::kOrigin);
    virtual ~ZcPointCloudExtractedCylinder();

    ZcPointCloudExtractedCylinder(const ZcPointCloudExtractedCylinder& o);
    bool operator == (const ZcPointCloudExtractedCylinder& o) const;
    bool operator != (const ZcPointCloudExtractedCylinder& o) const;
    ZcPointCloudExtractedCylinder& operator = (const ZcPointCloudExtractedCylinder& o);

    const static ZcPointCloudExtractedCylinder kInvalid;

public:
    bool isValid() const;

    void clear();

    ZcGeVector3d getAxis() const;
    void setAxis(ZcGeVector3d axis);

    ZcGePoint3d getOrigin() const;
    void setOrigin(ZcGePoint3d origin);

    double getHeight() const;
    void setHeight(double height);

    double getRadius() const;
    void setRadius(double radius);

private:
    std::unique_ptr<ZcPointCloudExtractedCylinderImp> m_pImp;
};
