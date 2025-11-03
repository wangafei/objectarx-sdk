#ifndef _OD_DB_DBMOTIONPATH_
#define _OD_DB_DBMOTIONPATH_

#include "TD_PackPush.h"

#include "DbObject.h"

OdResult TOOLKIT_EXPORT gcdbGetMotionPathDictionary(OdDbDatabase* pDb, OdDbDictionary*& pDict, OdDb::OpenMode mode, bool createIfNonExist);
OdResult TOOLKIT_EXPORT gcdbGetMotionPathDictionary(OdDbDatabase* pDb, OdDbDictionary*& pDict, OdDb::OpenMode mode);

class OdGiDrawableTraits;
class OdDbImpMotionPath;

class TOOLKIT_EXPORT OdDbMotionPath : public OdDbObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbMotionPath);

  OdDbMotionPath();
  virtual ~OdDbMotionPath();

  OdDbObjectId        cameraPath() const;
  OdResult   setCameraPath(const OdDbObjectId& id);

  OdDbObjectId        targetPath() const;
  OdResult   setTargetPath(const OdDbObjectId& id);

  OdDbObjectId        viewTableRecordId() const;
  OdResult   setViewTableRecordId(const OdDbObjectId& id);

  OdUInt32       frames() const;
  OdResult   setFrames(OdUInt16 frames);

  OdUInt32       frameRate() const;
  OdResult   setFrameRate(OdUInt16 rate);

  bool				cornerDecel() const;
  OdResult   setCornerDecel(bool cornerDecel);

  virtual OdResult dwgInFields(OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;

protected:
  virtual OdUInt32  subSetAttributes(OdGiDrawableTraits* pTraits);

  OdDbImpMotionPath* imp() const;
};

#include "TD_PackPop.h"

#endif