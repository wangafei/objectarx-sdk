#pragma once

namespace ZwSoft { namespace RealityStudio { namespace SDK { namespace Interface {
    class ARCSpatialFilter;
}}}};

class ZcDbPointCloudDxfHandler;

class ZCDB_PORT ZcDbPointCloudCrop
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

    ZcDbPointCloudCrop();

    ZcDbPointCloudCrop(const ZcDbPointCloudCrop& other);

    virtual ~ZcDbPointCloudCrop();

    bool operator == (const ZcDbPointCloudCrop& other) const;

    bool operator != (const ZcDbPointCloudCrop& other) const;

    ZcDbPointCloudCrop& operator=(const ZcDbPointCloudCrop& other);

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler);

    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler , ZSoft::Int16& dxfInt8, ZSoft::Int16& dxfInt32, ZSoft::Int16& dxfXCoord, ZSoft::Int16& dxfNormalX);

    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler, ZSoft::Int16& dxfInt8, ZSoft::Int16& dxfInt32, ZSoft::Int16& dxfXCoord, ZSoft::Int16& dxfNormalX) const;

    virtual ZwSoft::RealityStudio::SDK::Interface::ARCSpatialFilter*  toSpatialFilter() const;

    virtual void                draw(ZcGiGeometry& geom);

    void                        clear();

    bool                        isValid() const;

    CropType                    type() const;

    void                        setCropType(CropType type);

    bool                        isInside() const;

    void                        setInside(bool bInside);

    bool                        isInverted() const;

    void                        setInvert(bool toInvert);

    bool                        getCropPlane(ZcGePlane& plane);

    void                        setCropPlane(const ZcGePlane& plane);

    int                         length() const;

    void                        set(const ZcGePoint3dArray& points);

    const ZcGePoint3dArray&     get();

public:

    void                        setDxfHandler(ZcDbPointCloudDxfHandler* dxfHandler);

private:

    CropType                    m_cropType;
    bool                        m_isInside;
    bool                        m_isInverted;
    ZcGePlane                   m_cropPlane;
    ZcGePoint3dArray            m_point3dArray;
    ZcDbPointCloudDxfHandler*   m_dxfHandler;
};
