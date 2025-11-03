/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "dbmain.h"

static const TCHAR* kpPointCloudExDictionaryName = GCRX_T("GCAD_POINTCLOUD_EX_DICT");

class PointCloudDefExImp;
namespace Gssoft {
  namespace RealityStudio {
    namespace SDK {
      namespace Interface {
        class IRCData;
      }
    }
  }
}

class DBPOINTCLOUDOBJ_PORT GcDbPointCloudDefEx : public GcDbObject
{
public:
  enum PropState
  {
    kNone = -1,
    kSome = 0,
    kAll = 1
  };

  enum Property
  {
    kColor = 1,
    kIntensity = 2,
    kClassification = 3,
    kNormal = 4,
    kSegmentation = 5,
    kGeoGraphic = 6
  };

  GCRX_DECLARE_MEMBERS(GcDbPointCloudDefEx);

  GcDbPointCloudDefEx();
  ~GcDbPointCloudDefEx();

  static int                  classVersion();

  static Gcad::ErrorStatus    createPointCloudExDictionary(GcDbDatabase* pDb, GcDbObjectId& dictId);
  static GcDbObjectId         pointCloudExDictionary(GcDbDatabase* pDb);
  static GcDbDictionary*      getPointCloudExDictionary(GcDbPointCloudDefEx* pDefEx);

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;

  Gcad::ErrorStatus   subErase(Gsoft::Boolean erasing) override;

  Gssoft::RealityStudio::SDK::Interface::IRCData*   getRCData();

  Gcad::ErrorStatus   load();
  Gcad::ErrorStatus   unload();
  Gsoft::Boolean      isLoaded() const;

  int                 entityCount(Gsoft::Boolean* pbLocked = 0) const;

  Gcad::ErrorStatus   setSourceFileName(const TCHAR* pPathName);
  const TCHAR*        sourceFileName() const;

  Gcad::ErrorStatus   setActiveFileName(const TCHAR* pPathName);
  const TCHAR*        activeFileName() const;

  const TCHAR*        fileType() const;

  unsigned long long  totalPointsCount() const;
  int                 totalRegionsCount() const;
  int                 totalScansCount() const;

  double              defaultWidth() const;
  double              defaultLength() const;
  double              defaultHeight() const;

  PropState           hasProperty(Property prop) const;
  Gcad::ErrorStatus   createThumbnailBitmap(BITMAPINFO*& pBmpInfo,
    int width,
    int height) const;
  GcDbExtents         extents() const;
  const TCHAR*        coordinateSystemName() const;

  const TCHAR*        getRcsFilePath(const GcString& guid) const;
  void                getAllRcsFilePaths(GcStringArray& list) const;

private:
  PointCloudDefExImp*   m_pImp;
  static int          m_nVersion;
};

class PointCloudDefReactorExImp;

class DBPOINTCLOUDOBJ_PORT GcDbPointCloudDefReactorEx : public GcDbObject
{
public:
  static int                  classVersion();

  static void                 setEnable(Gsoft::Boolean bEnable);
  static Gsoft::Boolean       isEnabled();

  GCRX_DECLARE_MEMBERS(GcDbPointCloudDefReactorEx);

  GcDbPointCloudDefReactorEx();
  ~GcDbPointCloudDefReactorEx();

  Gcad::ErrorStatus   dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus   dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus   dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus   dxfOutFields(GcDbDxfFiler* pFiler) const override;

  void erased(const GcDbObject* dbObj, Gsoft::Boolean pErasing = true) override;
  void modified(const GcDbObject* dbObj) override;

private:
  static int m_version;
  static Gsoft::Boolean m_bIsEnabled;
  PointCloudDefReactorExImp*  m_pImp;
};