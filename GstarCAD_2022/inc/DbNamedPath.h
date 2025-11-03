#ifndef _OD_DB_DBNAMEDPATH_
#define _OD_DB_DBNAMEDPATH_

#include "TD_PackPush.h"

#include "DbObject.h"

OdResult TOOLKIT_EXPORT gcdbGetNamedPathDictionary(OdDbDatabase* pDb, OdDbDictionary*& pDict, OdDb::OpenMode mode, bool createIfNonExist);
OdResult TOOLKIT_EXPORT gcdbGetNamedPathDictionary(OdDbDatabase* pDb, OdDbDictionary*& pDict, OdDb::OpenMode mode);

class TOOLKIT_EXPORT OdDbNamedPath : public OdDbObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbNamedPath);
  virtual ~OdDbNamedPath();

  virtual OdResult getGeometry(OdGeCurve3d *& pCurveGeometry) const = 0;
};

class TOOLKIT_EXPORT OdDbCurvePath : public OdDbNamedPath
{
public:
  ODRX_DECLARE_MEMBERS(OdDbCurvePath);
  OdDbCurvePath();
  virtual ~OdDbCurvePath();

  virtual OdResult getGeometry(OdGeCurve3d *& pCurveGeometry) const;

  OdResult setGeometry(const OdDbObjectId& id);
  OdDbObjectId entityId() const;

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
};

class TOOLKIT_EXPORT OdDbPointPath : public OdDbNamedPath
{
public:
  ODRX_DECLARE_MEMBERS(OdDbPointPath);
  OdDbPointPath();
  virtual ~OdDbPointPath();

  virtual OdResult getGeometry(OdGeCurve3d *& pCurveGeometry) const;

  OdResult setGeometry(const OdGePoint3d& pt);

  OdResult dwgInFields(OdDbDwgFiler* pFiler);
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
};

#include "TD_PackPop.h"

#endif