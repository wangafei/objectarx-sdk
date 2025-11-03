/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef DB3DPROFILE_H
#define DB3DPROFILE_H

#include "dbsurf.h"
#include "GcDbGeomRef.h"

class GcDb3dProfileData;

#pragma pack(push, 8)

class  GcDb3dProfile : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDb3dProfile, GCDB_PORT);

  GCDB_PORT GcDb3dProfile();
  GCDB_PORT GcDb3dProfile(GcDbEntity *pEntity);
  GCDB_PORT GcDb3dProfile(const GcDbFullSubentPath& faceSubentPath);
  GCDB_PORT GcDb3dProfile(const GcDbPathRef & pathRef);
  GCDB_PORT GcDb3dProfile(const GcDbVertexRef & vertexRef);
  GCDB_PORT GcDb3dProfile(const GcDb3dProfile& src);
  GCDB_PORT ~GcDb3dProfile();

  GCDB_PORT Gcad::ErrorStatus copyFrom(const GcRxObject *src) override;
  GCDB_PORT GcDbEntity*  entity() const;
  GCDB_PORT Gcad::ErrorStatus getPathRef(GcDbPathRef &pathRef) const;
  GCDB_PORT Gcad::ErrorStatus getVertexRef(GcDbVertexRef &vertexRef) const;
  GCDB_PORT Gcad::ErrorStatus  convertProfile(bool explodeMultiFaceRegions, bool convertSurfaceToEdges,
    bool nonPlanarOnly, bool outerLoopOnly,
    GcArray<GcDb3dProfile*>& convertedProfileArr) const;
  GCDB_PORT static GcDb3dProfile* convertProfile(const GcArray<GcDbPathRef>&);
  GCDB_PORT Gcad::ErrorStatus set(const GcDbPathRef &pathRef);
  GCDB_PORT Gcad::ErrorStatus set(const GcDbVertexRef &vertexRef);
  GCDB_PORT Gcad::ErrorStatus set(GcDbEntity *pEntity);

  GCDB_PORT bool  isClosed() const;
  GCDB_PORT bool  isPlanar() const;
  GCDB_PORT bool  isSubent() const;
  GCDB_PORT bool  isFace() const;
  GCDB_PORT bool  isEdge() const;
  GCDB_PORT bool  isValid() const;

  GCDB_PORT static Gcad::ErrorStatus mergeProfiles(const GcArray<GcDb3dProfile*>& profileArr,
    bool mergeEdges, bool mergeCurves,
    GcArray<GcDb3dProfile*>& mergedProfileArr);

  GCDB_PORT GcDb3dProfile& operator = (const GcDb3dProfile& src);
private:
  friend class GcDb3dProfileData;
  friend class GcDbLoftProfile;

  GcDb3dProfileData *mProfileData;
};

class  GcDbLoftProfile : public GcDb3dProfile
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbLoftProfile, GCDB_PORT);

  GCDB_PORT GcDbLoftProfile();
  GCDB_PORT GcDbLoftProfile(GcDbEntity *pEntity);
  GCDB_PORT GcDbLoftProfile(const GcDbPathRef & pathRef);
  GCDB_PORT GcDbLoftProfile(const GcGePoint3d& pnt);
  GCDB_PORT GcDbLoftProfile(const GcDbLoftProfile& src);

  GCDB_PORT Gcad::ErrorStatus copyFrom(const GcRxObject *src) override;
  GCDB_PORT Gsoft::Int16  continuity() const;
  GCDB_PORT void          setContinuity(Gsoft::Int16 value);
  GCDB_PORT double        magnitude() const;
  GCDB_PORT void          setMagnitude(double value);

  GCDB_PORT GcDbLoftProfile& operator = (const GcDbLoftProfile& src);
  GCDB_PORT GcDbLoftProfile& operator = (const GcDb3dProfile& src);
};

#pragma pack(pop)
#endif 