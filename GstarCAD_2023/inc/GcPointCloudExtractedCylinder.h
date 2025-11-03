/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include <memory>

class GcPointCloudExtractedCylinderImp;

class DBPOINTCLOUDOBJ_PORT GcPointCloudExtractedCylinder
{
public:
  GcPointCloudExtractedCylinder();
  GcPointCloudExtractedCylinder(double radius, double height, GcGeVector3d axis = GcGeVector3d::kZAxis, GcGePoint3d origin = GcGePoint3d::kOrigin);
  virtual ~GcPointCloudExtractedCylinder();

  GcPointCloudExtractedCylinder(const GcPointCloudExtractedCylinder& o);
  bool operator == (const GcPointCloudExtractedCylinder& o) const;
  bool operator != (const GcPointCloudExtractedCylinder& o) const;
  GcPointCloudExtractedCylinder& operator = (const GcPointCloudExtractedCylinder& o);

  const static GcPointCloudExtractedCylinder kInvalid;

public:
  bool isValid() const;
  void clear();

  GcGeVector3d getAxis() const;
  void setAxis(GcGeVector3d axis);

  GcGePoint3d getOrigin() const;
  void setOrigin(GcGePoint3d origin);

  double getHeight() const;
  void setHeight(double height);

  double getRadius() const;
  void setRadius(double radius);

private:
  std::unique_ptr<GcPointCloudExtractedCylinderImp> m_pImp;
};