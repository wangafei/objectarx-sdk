/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbmain.h"

#pragma pack(push, 8)

#pragma warning( disable: 4275 4251 )

#ifdef SCENEDLLIMPEXP
#undef SCENEDLLIMPEXP
#endif
#ifdef SCENEOE
#define SCENEDLLIMPEXP __declspec( dllexport )
#else
#define SCENEDLLIMPEXP 
#endif

const GCHAR GCDB_NAMEDPATH_DICTIONARY[] = GCRX_T("ACAD_NAMEDPATH");

Gcad::ErrorStatus GCDB_PORT gcdbGetNamedPathDictionary(GcDbDatabase* pDb, GcDbDictionary*& pDict, GcDb::OpenMode mode, bool createIfNonExist);
Gcad::ErrorStatus GCDB_PORT gcdbGetNamedPathDictionary(GcDbDatabase* pDb, GcDbDictionary*& pDict, GcDb::OpenMode mode);

class GcDbImpNamedPath;
class GcGeCurve3d;

class GCDB_PORT GcDbNamedPath : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbNamedPath);
  ~GcDbNamedPath();

  virtual Gcad::ErrorStatus   getGeometry(GcGeCurve3d *& pCurveGeometry) const = 0;

protected:
  GcDbNamedPath(GcDbImpNamedPath* pImp);
  GcDbImpNamedPath* imp() const;

private:
  friend class GcDbImpNamedPath;
  GcDbImpNamedPath* mpImp;
};

class GCDB_PORT GcDbCurvePath : public GcDbNamedPath
{
public:
  GCRX_DECLARE_MEMBERS(GcDbCurvePath);
  GcDbCurvePath();
  ~GcDbCurvePath();

  Gcad::ErrorStatus   getGeometry(GcGeCurve3d *& pCurveGeometry) const override;
  Gcad::ErrorStatus   setGeometry(const GcDbObjectId& id);
  GcDbObjectId        entityId() const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
  friend class GcDbImpCurvePath;
};

class GCDB_PORT GcDbPointPath : public GcDbNamedPath
{
public:
  GCRX_DECLARE_MEMBERS(GcDbPointPath);
  GcDbPointPath();
  ~GcDbPointPath();

  Gcad::ErrorStatus   getGeometry(GcGeCurve3d *& pCurveGeometry) const override;
  Gcad::ErrorStatus   setGeometry(const GcGePoint3d& pt);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;

private:
#ifndef _GSOFT_MAC_
  friend class GcDbPointPath;
#endif
};

#pragma pack(pop)