/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

namespace Gssoft {
  namespace RealityStudio {
    namespace SDK {
      namespace Interface {
        class ARCSpatialFilter;
      }
    }
  }
};

class GcDbPointCloudDxfHandler;

class DBPOINTCLOUDOBJ_PORT GcDbPointCloudCrop
{
public:
  enum CropType
  {
    kInvalid = 0,
    kRectangular,
    kPolygonal,
    kCircular
  };

public:
  GcDbPointCloudCrop();
  GcDbPointCloudCrop(const GcDbPointCloudCrop& other);
  virtual ~GcDbPointCloudCrop();

  bool operator == (const GcDbPointCloudCrop& other) const;
  bool operator != (const GcDbPointCloudCrop& other) const;
  GcDbPointCloudCrop& operator=(const GcDbPointCloudCrop& other);


  virtual Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler);
  virtual Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const;
  virtual Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler, Gsoft::Int16& dxfInt8, Gsoft::Int16& dxfInt32, Gsoft::Int16& dxfXCoord, Gsoft::Int16& dxfNormalX);
  virtual Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler, Gsoft::Int16& dxfInt8, Gsoft::Int16& dxfInt32, Gsoft::Int16& dxfXCoord, Gsoft::Int16& dxfNormalX) const;

  virtual Gssoft::RealityStudio::SDK::Interface::ARCSpatialFilter*  toSpatialFilter() const;

  virtual void                draw(GcGiGeometry& geom);

  void                        clear();

  bool                        isValid() const;

  CropType                    type() const;
  void                        setCropType(CropType type);

  bool                        isInside() const;
  void                        setInside(bool bInside);

  bool                        isInverted() const;
  void                        setInvert(bool toInvert);

  bool                        getCropPlane(GcGePlane& plane);
  void                        setCropPlane(const GcGePlane& plane);

  int                         length() const;

  void                        set(const GcGePoint3dArray& points);
  const GcGePoint3dArray&     get();

public:
  void                        setDxfHandler(GcDbPointCloudDxfHandler* dxfHandler);

private:
  CropType                    m_cropType;
  bool                        m_isInside;
  bool                        m_isInverted;
  GcGePlane                   m_cropPlane;
  GcGePoint3dArray            m_point3dArray;
  GcDbPointCloudDxfHandler*   m_dxfHandler;
};