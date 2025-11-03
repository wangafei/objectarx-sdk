/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcdbport.h"
#include "dbmain.h"
#include "rxboiler.h"
#include "gepnt3d.h"
#include "gevec3d.h"
#include "GcString.h"

#pragma pack (push, 8)

class GcDbMText;

class GCDB_PORT GcDbGeoPositionMarker : public GcDbEntity
{
public:
  enum TextAlignmentType {
    kLeftAlignment = 0,
    kCenterAlignment = 1,
    kRightAlignment = 2
  };

  GCRX_DECLARE_MEMBERS(GcDbGeoPositionMarker);

  GcDbGeoPositionMarker();
  GcDbGeoPositionMarker(const GcGePoint3d &position, double radius, double landingGap);

  GcGePoint3d          position() const;
  Gcad::ErrorStatus    setPosition(const GcGePoint3d &position);

  double               radius() const;
  Gcad::ErrorStatus    setRadius(double radius);

  GcString             text() const;
  Gcad::ErrorStatus    setText(const GcString& text);

  GcDbMText*           mtext() const;
  Gcad::ErrorStatus    setMText(const GcDbMText* pMText);

  bool                 mtextVisible() const;
  Gcad::ErrorStatus    setMTextVisible(bool visible);

  double               landingGap() const;
  Gcad::ErrorStatus    setLandingGap(double landingGap);

  bool                 enableFrameText() const;
  Gcad::ErrorStatus    setEnableFrameText(bool enableFrameText);

  TextAlignmentType    textAlignmentType() const;
  Gcad::ErrorStatus    setTextAlignmentType(TextAlignmentType textAlignmentType);

  GcString             notes() const;
  Gcad::ErrorStatus    setNotes(const GcString& notes);

  GcGePoint3d          geoPosition() const;
  Gcad::ErrorStatus    setGeoPosition(const GcGePoint3d &position);

  Gcad::ErrorStatus    latLonAlt(double &lat, double &lon, double &alt) const;
  Gcad::ErrorStatus    setLatLonAlt(double lat, double lon, double alt);

  GcGeVector3d        normal() const;

  GcDbObjectId        textStyle() const;

protected:
  Gcad::ErrorStatus   subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)