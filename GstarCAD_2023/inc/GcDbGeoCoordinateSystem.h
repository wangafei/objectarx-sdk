/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gcdb.h"
#include "GcString.h"
#include "gepnt3d.h"
#pragma pack (push, 8)

class GcDbGeoCoordinateSystem;

struct GcDbGeoDatum
{
  GcString id;
  GcString desc;
};

struct GcDbGeoEllipsoid
{
  GcString id;
  GcString desc;
  double   polarRadius;
  double   eccentricity;
};

struct GcDbGeoProjectionParameter
{
  GcString name;
  double   value;
};

class GcDbGeoCoordinateSystemCategory
{
public:
  virtual ~GcDbGeoCoordinateSystemCategory() {};

  virtual Gcad::ErrorStatus          getId(GcString& categoryId) const = 0;
  virtual Gcad::ErrorStatus          getNumOfCoordinateSystem(int& num) const = 0;
  virtual Gcad::ErrorStatus          getCoordinateSystemAt(int index, GcDbGeoCoordinateSystem*& pCoordSys) const = 0;

  GCDB_PORT static Gcad::ErrorStatus createAll(GcArray<GcDbGeoCoordinateSystemCategory*>& allCategories);
};

class GCDB_PORT GcDbGeoCoordinateSystem
{
public:
  enum Type
  {
    kTypeUnknown = 0,
    kTypeArbitrary = 1,
    kTypeGeographic = 2,
    kTypeProjected = 3
  };

  enum ProjectionCode
  {
    kProjectionCodeUnknown = 0,
    kProjectionCodeAlber = 4,
    kProjectionCodeAzede = 59,
    kProjectionCodeAzmea = 11,
    kProjectionCodeAzmed = 7,
    kProjectionCodeBipolar = 31,
    kProjectionCodeBonne = 24,
    kProjectionCodeCassini = 22,
    kProjectionCodeEckert4 = 25,
    kProjectionCodeEckert6 = 26,
    kProjectionCodeEdcnc = 12,
    kProjectionCodeEdcyl = 20,
    kProjectionCodeGaussK = 46,
    kProjectionCodeGnomonic = 19,
    kProjectionCodeGoode = 28,
    kProjectionCodeHom1uv = 1281,
    kProjectionCodeHom1xy = 1282,
    kProjectionCodeHom2uv = 1283,
    kProjectionCodeHom2xy = 1284,
    kProjectionCodeKrovak = 47,
    kProjectionCodeKrvk95 = 51,
    kProjectionCodeLL = 1,
    kProjectionCodeLm1sp = 36,
    kProjectionCodeLm2sp = 37,
    kProjectionCodeLmblg = 38,
    kProjectionCodeLmtan = 8,
    kProjectionCodeMiller = 13,
    kProjectionCodeMndotl = 41,
    kProjectionCodeMndott = 42,
    kProjectionCodeModpc = 10,
    kProjectionCodeMollweid = 27,
    kProjectionCodeMrcat = 6,
    kProjectionCodeMrcatK = 49,
    kProjectionCodeMstero = 15,
    kProjectionCodeNeacyl = 29,
    kProjectionCodeNerth = 55,
    kProjectionCodeNzealand = 16,
    kProjectionCodeOblqM = 5,
    kProjectionCodeObqcyl = 56,
    kProjectionCodeOrtho = 18,
    kProjectionCodeOstn02 = 60,
    kProjectionCodeOstn97 = 58,
    kProjectionCodeOstro = 34,
    kProjectionCodePlycn = 9,
    kProjectionCodePstro = 33,
    kProjectionCodePstrosl = 53,
    kProjectionCodeRskew = 1285,
    kProjectionCodeRskewc = 1286,
    kProjectionCodeRskewo = 1287,
    kProjectionCodeRobinson = 23,
    kProjectionCodeSinus = 17,
    kProjectionCodeSotrm = 43,
    kProjectionCodeSstro = 35,
    kProjectionCodeSwiss = 32,
    kProjectionCodeSys34 = 57,
    kProjectionCodeSys34_99 = 61,
    kProjectionCodeTeacyl = 30,
    kProjectionCodeTm = 3,
    kProjectionCodeTrmeraf = 54,
    kProjectionCodeTrmrkrg = 62,
    kProjectionCodeTrmrs = 45,
    kProjectionCodeVdgrntn = 21,
    kProjectionCodeWccsl = 39,
    kProjectionCodeWccst = 40,
    kProjectionCodeUtm = 44,
    kProjectionCodeWinkl = 63,
    kProjectionCodeNrthsrt = 64,
    kProjectionCodeLmbrtaf = 65,
    kProjectionCodeSys34_01 = 66,
    kProjectionCodeEdcylE = 67,
    kProjectionCodePlateCarree = 68,
    kProjectionCodePvMercator = 69,
  };

  enum Unit
  {
    kUnitUnknown = 0,
    kUnitMeter = 1,
    kUnitFoot = 2,
    kUnitInch = 3,
    kUnitIFoot = 4,
    kUnitClarkeFoot = 5,
    kUnitIInch = 6,
    kUnitCentimeter = 7,
    kUnitKilometer = 8,
    kUnitYard = 9,
    kUnitSearsYard = 10,
    kUnitMile = 11,
    kUnitIYard = 12,
    kUnitIMile = 13,
    kUnitKnot = 14,
    kUnitNautM = 15,
    kUnitLat66 = 16,
    kUnitLat83 = 17,
    kUnitDecimeter = 18,
    kUnitMillimeter = 19,
    kUnitDekameter = 20,
    kUnitHectometer = 21,
    kUnitGermanMeter = 22,
    kUnitCaGrid = 23,
    kUnitClarkeChain = 24,
    kUnitGunterChain = 25,
    kUnitBenoitChain = 26,
    kUnitSearsChain = 27,
    kUnitClarkeLink = 28,
    kUnitGunterLink = 29,
    kUnitBenoitLink = 30,
    kUnitSearsLink = 31,
    kUnitRod = 32,
    kUnitPerch = 33,
    kUnitPole = 34,
    kUnitFurlong = 35,
    kUnitRood = 36,
    kUnitCapeFoot = 37,
    kUnitBrealey = 38,
    kUnitSearsFoot = 39,
    kUnitGoldCoastFoot = 40,
    kUnitMicroInch = 41,
    kUnitIndianYard = 42,
    kUnitIndianFoot = 43,
    kUnitIndianFt37 = 44,
    kUnitIndianFt62 = 45,
    kUnitIndianFt75 = 46,
    kUnitIndianYd37 = 47,
    kUnitDecameter = 48,
    kUnitInternationalChain = 49,
    kUnitInternationalLink = 50,
    kUnitDegree = 1001,
    kUnitGrad = 1002,
    kUnitGrade = 1003,
    kUnitMapInfo = 1004,
    kUnitMil = 1005,
    kUnitMinute = 1006,
    kUnitRadian = 1007,
    kUnitSecond = 1008,
    kUnitDecisec = 1009,
    kUnitCentisec = 1010,
    kUnitMillisec = 1011,
  };

  virtual ~GcDbGeoCoordinateSystem() {};

  virtual Gcad::ErrorStatus getId(GcString& coordSysId) const = 0;
  virtual Gcad::ErrorStatus getEpsgCode(int& epsgCode) const = 0;
  virtual Gcad::ErrorStatus getType(GcDbGeoCoordinateSystem::Type& type) const = 0;
  virtual Gcad::ErrorStatus getDescription(GcString& coordSysDesc) const = 0;
  virtual Gcad::ErrorStatus getUnit(GcDb::UnitsValue& unit) const = 0;
  virtual Gcad::ErrorStatus getUnit(GcDbGeoCoordinateSystem::Unit& unit) const = 0;
  virtual Gcad::ErrorStatus getUnitScale(double& unitScale) const = 0;
  virtual Gcad::ErrorStatus getProjectionCode(GcDbGeoCoordinateSystem::ProjectionCode& prjCode) const = 0;
  virtual Gcad::ErrorStatus getProjectionParameters(GcArray<GcDbGeoProjectionParameter>& prjParams,
    bool includeSpecialParams) const = 0;

  virtual Gcad::ErrorStatus getDatum(GcDbGeoDatum& datum) const = 0;
  virtual Gcad::ErrorStatus getEllipsoid(GcDbGeoEllipsoid& ellipsoid) const = 0;
  virtual Gcad::ErrorStatus getOffset(GcGeVector2d& offsetVec) const = 0;
  virtual Gcad::ErrorStatus getCartesianExtents(GcDbExtents2d& exts) const = 0;
  virtual Gcad::ErrorStatus getGeodeticExtents(GcDbExtents2d& exts) const = 0;
  virtual Gcad::ErrorStatus getXmlRepresentation(GcString& strXml) const = 0;
  virtual Gcad::ErrorStatus getWktRepresentation(GcString& strWkt) const = 0;

  static Gcad::ErrorStatus create(const GcString& coordSysIdOrFullDef,
    GcDbGeoCoordinateSystem*& pCoordSys);

  static Gcad::ErrorStatus createAll(const GcGePoint3d& geoPt,
    GcArray<GcDbGeoCoordinateSystem*>& allCoordSys);

  static Gcad::ErrorStatus createAll(GcArray<GcDbGeoCoordinateSystem*>& allCoordSys,
    const GcDbGeoCoordinateSystemCategory* pCategory = NULL);
};

class GCDB_PORT GcDbGeoCoordinateSystemTransformer
{
public:
  virtual ~GcDbGeoCoordinateSystemTransformer() {};

  virtual Gcad::ErrorStatus getSourceCoordinateSystemId(GcString& sourceCoordSysId) const = 0;
  virtual Gcad::ErrorStatus getTargetCoordinateSystemId(GcString& targetCoordSysId) const = 0;
  virtual Gcad::ErrorStatus transformPoint(const GcGePoint3d& pointIn, GcGePoint3d& pointOut) const = 0;
  virtual Gcad::ErrorStatus transformPoints(const GcGePoint3dArray& pointsIn, GcGePoint3dArray& pointsOut) const = 0;

  static Gcad::ErrorStatus transformPoint(const GcString& sourceCoordSysId,
    const GcString& targetCoordSysId,
    const GcGePoint3d& pointIn,
    GcGePoint3d& pointOut);

  static Gcad::ErrorStatus transformPoints(const GcString& sourceCoordSysId,
    const GcString& targetCoordSysId,
    const GcGePoint3dArray& pointsIn,
    GcGePoint3dArray& pointsOut);

  static Gcad::ErrorStatus create(const GcString& sourceCoordSysId,
    const GcString& targetCoordSysId,
    GcDbGeoCoordinateSystemTransformer*& pCoordSysTransformer);

};

#pragma pack (pop)