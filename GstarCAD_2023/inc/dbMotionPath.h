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

const GCHAR GCDB_MOTIONPATH_DICTIONARY[] = GCRX_T("ACAD_MOTION");

Gcad::ErrorStatus SCENEDLLIMPEXP gcdbGetMotionPathDictionary(GcDbDatabase* pDb, GcDbDictionary*& pDict, GcDb::OpenMode mode, bool createIfNonExist);
Gcad::ErrorStatus SCENEDLLIMPEXP gcdbGetMotionPathDictionary(GcDbDatabase* pDb, GcDbDictionary*& pDict, GcDb::OpenMode mode);

class GcDbImpMotionPath;

class SCENEDLLIMPEXP GcDbMotionPath : public GcDbObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbMotionPath);
  GcDbMotionPath();
  ~GcDbMotionPath();

  GcDbObjectId        cameraPath() const;
  Gcad::ErrorStatus   setCameraPath(const GcDbObjectId& id);

  GcDbObjectId        targetPath() const;
  Gcad::ErrorStatus   setTargetPath(const GcDbObjectId& id);

  GcDbObjectId        viewTableRecordId() const;
  Gcad::ErrorStatus   setViewTableRecordId(const GcDbObjectId& id);

  Gsoft::UInt32       frames() const;
  Gcad::ErrorStatus   setFrames(Gsoft::UInt16 frames);

  Gsoft::UInt32       frameRate() const;
  Gcad::ErrorStatus   setFrameRate(Gsoft::UInt16 rate);

  bool				        cornerDecel() const;
  Gcad::ErrorStatus   setCornerDecel(bool cornerDecel);

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

protected:
  Gsoft::UInt32  subSetAttributes(GcGiDrawableTraits* pTraits) override;
  GcDbImpMotionPath* imp() const;

private:
  friend class GcDbImpMotionPath;
  GcDbImpMotionPath* mpImp;
};

#pragma pack(pop)