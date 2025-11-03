/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBHATCH_H
#define GD_DBHATCH_H 1

#include "gcdb.h"
#include "dbmain.h"
#include "gelnsg2d.h"
#include "gelnsg3d.h"
#include "gearc2d.h"
#include "gearc3d.h"
#include "gept2dar.h"
#include "gevptar.h"
#include "geintarr.h"

#pragma pack(push, 8)

#define HATCH_PATTERN_NAME_LENGTH   35
#define GRADIENT_PATTERN_NAME_LENGTH    32
#define GRADIENT_COLOR_NAME_LENGTH    256

class GcDbRegion;

class GCDB_PORT GcDbHatch : public GcDbEntity
{
public:
  enum HatchObjectType {
    kHatchObject = 0,
    kGradientObject = 1
  };

  enum HatchLoopType {
    kDefault = 0,
    kExternal = 1,
    kPolyline = 2,
    kDerived = 4,
    kTextbox = 8,
    kOutermost = 0x10,
    kNotClosed = 0x20,
    kSelfIntersecting = 0x40,
    kTextIsland = 0x80,
    kDuplicate = 0x100,
    kIsAnnotative = 0x200,
    kDoesNotSupportScale = 0x400,
    kForceAnnoAllVisible = 0x800,
    kOrientToPaper = 0x1000,
    kIsAnnotativeBlock = 0x2000
  };

  enum HatchEdgeType {
    kLine = 1,
    kCirArc = 2,
    kEllArc = 3,
    kSpline = 4
  };

  enum HatchPatternType {
    kUserDefined = 0,
    kPreDefined = 1,
    kCustomDefined = 2
  };

  enum HatchStyle {
    kNormal = 0,
    kOuter = 1,
    kIgnore = 2
  };

  enum GradientPatternType {
    kPreDefinedGradient = 0,
    kUserDefinedGradient = 1
  };

  GcDbHatch();
  ~GcDbHatch();
  GCDB_DECLARE_MEMBERS(GcDbHatch);

  double elevation() const;
  Gcad::ErrorStatus setElevation(double elevation);

  GcGeVector3d normal() const;
  Gcad::ErrorStatus setNormal(const GcGeVector3d& normal);

  Gsoft::Boolean isPlanar() const  override { return true; }
  Gcad::ErrorStatus getPlane(GcGePlane&, GcDb::Planarity&) const override;

  GcCmColor backgroundColor() const;
  Gcad::ErrorStatus setBackgroundColor(const GcCmColor& color);

  int numLoops() const;
  Gsoft::Int32 loopTypeAt(int loopIndex) const;

  Gcad::ErrorStatus getLoopAt(int loopIndex,
    Gsoft::Int32& loopType,
    GcGeVoidPointerArray& edgePtrs,
    GcGeIntArray&  edgeTypes) const;
  Gcad::ErrorStatus getLoopAt(int loopIndex,
    Gsoft::Int32& loopType,
    GcGePoint2dArray& vertices,
    GcGeDoubleArray& bulges) const;
  Gcad::ErrorStatus appendLoop(Gsoft::Int32 loopType,
    const GcGeVoidPointerArray& edgePtrs,
    const GcGeIntArray&  edgeTypes);
  Gcad::ErrorStatus appendLoop(Gsoft::Int32 loopType,
    const GcGePoint2dArray& vertices,
    const GcGeDoubleArray& bulges);
  Gcad::ErrorStatus insertLoopAt(int loopIndex,
    Gsoft::Int32 loopType,
    const GcGeVoidPointerArray& edgePtrs,
    const GcGeIntArray&  edgeTypes);
  Gcad::ErrorStatus insertLoopAt(int loopIndex,
    Gsoft::Int32 loopType,
    const GcGePoint2dArray& vertices,
    const GcGeDoubleArray& bulges);
  Gcad::ErrorStatus removeLoopAt(int loopIndex);

  bool associative() const;
  Gcad::ErrorStatus setAssociative(bool isAssociative);
  Gcad::ErrorStatus appendLoop(Gsoft::Int32 loopType,
    const GcDbObjectIdArray& dbObjIds);
  Gcad::ErrorStatus insertLoopAt(int loopIndex,
    Gsoft::Int32 loopType,
    const GcDbObjectIdArray& dbObjIds);
  Gcad::ErrorStatus getAssocObjIdsAt(int loopIndex, GcDbObjectIdArray& dbObjIds) const;
  Gcad::ErrorStatus getAssocObjIds(GcDbObjectIdArray& dbObjIds) const;
  Gcad::ErrorStatus removeAssocObjIds();

  GcDbHatch::HatchObjectType hatchObjectType() const;
  Gcad::ErrorStatus setHatchObjectType(GcDbHatch::HatchObjectType type);

  virtual Gsoft::Boolean isGradient() const;
  virtual Gsoft::Boolean isHatch() const;

  GcDbHatch::GradientPatternType gradientType() const;
  const GCHAR* gradientName() const;
  Gcad::ErrorStatus setGradient(GcDbHatch::GradientPatternType gradType, const GCHAR* gradName);

  double gradientAngle() const;
  Gcad::ErrorStatus setGradientAngle(double angle);
  Gcad::ErrorStatus getGradientColors(unsigned int& count,
    GcCmColor*& colors,
    float*& values);
  Gcad::ErrorStatus setGradientColors(unsigned int count,
    GcCmColor* colors,
    float* values);
  Gsoft::Boolean    getGradientOneColorMode() const;
  Gcad::ErrorStatus setGradientOneColorMode(Gsoft::Boolean oneColorMode);

  float getShadeTintValue() const;
  Gcad::ErrorStatus setShadeTintValue(float value);
  Gcad::ErrorStatus setShadeTintValueAndColor2(float value);

  float gradientShift() const;
  Gcad::ErrorStatus setGradientShift(float shiftValue);
  Gcad::ErrorStatus evaluateGradientColorAt(float value, GcCmColor& color);

  GcDbHatch::HatchPatternType patternType() const;

  const GCHAR(&patternName()const)[HATCH_PATTERN_NAME_LENGTH];

  Gcad::ErrorStatus  setPattern(GcDbHatch::HatchPatternType patType, const GCHAR* patName);

  double patternAngle() const;
  Gcad::ErrorStatus setPatternAngle(double angle);
  double patternSpace() const;
  Gcad::ErrorStatus setPatternSpace(double space);
  double patternScale() const;
  Gcad::ErrorStatus setPatternScale(double scale);
  bool patternDouble() const;
  Gcad::ErrorStatus setPatternDouble(bool isDouble);
  int numPatternDefinitions() const;
  Gcad::ErrorStatus  getPatternDefinitionAt(int index,
    double& angle,
    double& baseX,
    double& baseY,
    double& offsetX,
    double& offsetY,
    GcGeDoubleArray& dashes)
    const;

  GcDbHatch::HatchStyle hatchStyle() const;
  Gcad::ErrorStatus  setHatchStyle(GcDbHatch::HatchStyle hstyle);
  Gcad::ErrorStatus  evaluateHatch(bool bUnderestimateNumLines = false);
  Gcad::ErrorStatus  evaluateHatchAllScales(bool bUnderestimateNumLines = false);
  bool               lineGenerationEnabled() const;
  bool               setLineGenerationEnabled(bool bEnable);

  int numHatchLines() const;
  bool isSolidFill() const;

  Gcad::ErrorStatus  getHatchLineDataAt(int index,
    GcGePoint2d& startPt,
    GcGePoint2d& endPt) const;
  Gcad::ErrorStatus  getHatchLinesData(GcGePoint2dArray& startPts,
    GcGePoint2dArray& endPts) const;

  void modifiedGraphics(const GcDbEntity* pObj) override;
  Gcad::ErrorStatus subSwapIdWith(GcDbObjectId otherId,
    Gsoft::Boolean swapXdata = false,
    Gsoft::Boolean swapExtDict = false) override;
  Gcad::ErrorStatus swapReferences(const GcDbIdMapping& idMap) override;
  Gcad::ErrorStatus getArea(double& a) const;
  Gcad::ErrorStatus setOriginPoint(const GcGePoint2d& pt);
  GcGePoint2d originPoint() const;

  GcDbRegion* getRegionArea() const;
  void removeHatchLines();

protected:
  Gcad::ErrorStatus  subGetClassID(CLSID* pClsid) const override;
};

#pragma pack(pop)

#endif 