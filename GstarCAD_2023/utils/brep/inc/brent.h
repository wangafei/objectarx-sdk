/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRENT_H
#define GC_BRENT_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "../../../inc/gegbl.h"
#include "brgbl.h"
#include "brprops.h"

class GcDbFullSubentPath;
class GcGeBoundBlock3d;
class GcGePoint3d;
class GcGeLinearEnt3d;
class GcBrHit;
class GcBrBrep;
class GcBrImpEntity;
class GcBrBrepData;

class GCBR_PORT GcBrEntity : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcBrEntity);
  virtual ~GcBrEntity();

  Gsoft::Boolean      isEqualTo(const GcRxObject* other) const;
  Gsoft::Boolean      isNull() const;
  GcBr::ErrorStatus   setSubentPath(GcDbFullSubentPath& subpath);
  GcBr::ErrorStatus   getSubentPath(GcDbFullSubentPath& subPath) const;

  Gsoft::Boolean      checkEntity() const;
  void*               getEntity() const;
  GcBr::ErrorStatus   setEntity(void* pData, GcDbFullSubentPath& subPath = *(GcDbFullSubentPath*)NULL);

  GcBr::ErrorStatus   getBoundBlock(GcGeBoundBlock3d& block) const;
  GcBr::ErrorStatus   getPointContainment(const GcGePoint3d& point,
                                     GcGe::PointContainment& containment,
                                                GcBrEntity*& container) const;

  GcBr::ErrorStatus   getLineContainment(const GcGeLinearEnt3d& line,
                                         const Gsoft::UInt32&   numHitsWanted,
                                         Gsoft::UInt32&         numHitsFound,
                                         GcBrHit*&              hits) const;

  GcBr::ErrorStatus   getBrep(GcBrBrep& brep) const;

  GcBr::ErrorStatus   setValidationLevel(const GcBr::ValidationLevel& level = *(GcBr::ValidationLevel*)NULL);
  GcBr::ErrorStatus   getValidationLevel(GcBr::ValidationLevel& level) const;
  Gsoft::Boolean      brepChanged() const;

  GcBr::ErrorStatus   set(const GcDbFullSubentPath& path);
  GcBr::ErrorStatus   get(GcDbFullSubentPath& path) const;
  GcBr::ErrorStatus   set(GcBrBrepData* data);
  GcBr::ErrorStatus   get(GcBrBrepData*& data) const;

  GcBr::ErrorStatus   getMassProps(GcBrMassProps& massProps,
                                   const double&  density = *(double*)NULL,
                                   const double&  tolRequired = *(double*)NULL,
                                   double&        tolAchieved = *(double*)NULL) const;
  GcBr::ErrorStatus   getVolume(double&       volume,
                                const double& tolRequired = *(double*)NULL,
                                double&       tolAchieved = *(double*)NULL) const;
  GcBr::ErrorStatus   getSurfaceArea(double&       area,
                                     const double& tolRequired = *(double*)NULL,
                                     double&       tolAchieved = *(double*)NULL) const;
  GcBr::ErrorStatus   getPerimeterLength(double&       length,
                                         const double& tolRequired = *(double*)NULL,
                                         double&       tolAchieved = *(double*)NULL) const;

protected:
  GcBrEntity();
  GcBrEntity(const GcBrEntity& src);
  GcBrEntity&         operator =      (const GcBrEntity& src);

  GcBrImpEntity*      mpImp;
};

#endif
