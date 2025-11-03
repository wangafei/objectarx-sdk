#pragma once
#include "zacdbport.h"
#include "zdbmain.h"
#include "zrxboiler.h"
#include "zgepnt3d.h"
#include "zgevec3d.h"
#include "zAcString.h"

#pragma pack (push, 8)

class ZcDbMText;

class ZCDBCORE2D_PORT ZcDbGeoPositionMarker : public ZcDbEntity
{
public:

    enum TextAlignmentType {

        kLeftAlignment = 0,

        kCenterAlignment = 1,

        kRightAlignment = 2
    };

    ZCRX_DECLARE_MEMBERS(ZcDbGeoPositionMarker);

    ZcDbGeoPositionMarker();
    ZcDbGeoPositionMarker(const ZcGePoint3d &position, double radius, double landingGap);

    ZcGePoint3d          position() const;
    Zcad::ErrorStatus    setPosition(const ZcGePoint3d &position);

    double               radius() const;
    Zcad::ErrorStatus    setRadius(double radius);

    ZcString             text() const;
    Zcad::ErrorStatus    setText(const ZcString& text);

    ZcDbMText*           mtext() const;
    Zcad::ErrorStatus    setMText(const ZcDbMText* pMText);

    bool                 mtextVisible() const;
    Zcad::ErrorStatus    setMTextVisible(bool visible);

    double               landingGap() const;
    Zcad::ErrorStatus    setLandingGap(double landingGap);

    bool                 enableFrameText() const;
    Zcad::ErrorStatus    setEnableFrameText(bool enableFrameText);

    TextAlignmentType    textAlignmentType() const;
    Zcad::ErrorStatus    setTextAlignmentType(TextAlignmentType textAlignmentType);

    ZcString             notes() const;
    Zcad::ErrorStatus    setNotes(const ZcString& notes);

    ZcGePoint3d          geoPosition() const;
    Zcad::ErrorStatus    setGeoPosition(const ZcGePoint3d &position);
    Zcad::ErrorStatus    latLonAlt(double &lat, double &lon, double &alt) const;
    Zcad::ErrorStatus    setLatLonAlt(double lat, double lon, double alt);

    ZcGeVector3d        normal() const;

    ZcDbObjectId        textStyle() const;

protected:
    virtual Zcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)
