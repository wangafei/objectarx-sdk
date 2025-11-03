#pragma once
#include "zdbmain.h"

static const TCHAR* kpPointCloudExDictionaryName = ZCRX_T("ZCAD_POINTCLOUD_EX_DICT");

class PointCloudDefExImp;
namespace ZwSoft { namespace RealityStudio { namespace SDK { namespace Interface {
    class IRCData;
}}}}

class ZCDB_PORT ZcDbPointCloudDefEx : public ZcDbObject
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

        kColor          = 1,

        kIntensity      = 2,

        kClassification = 3,

        kNormal         = 4,

        kSegmentation   = 5,

        kGeoGraphic     = 6
    };

    ZCRX_DECLARE_MEMBERS(ZcDbPointCloudDefEx);

    ZcDbPointCloudDefEx();

    virtual ~ZcDbPointCloudDefEx();

    static int                  classVersion();

    static Zcad::ErrorStatus    createPointCloudExDictionary(ZcDbDatabase* pDb, ZcDbObjectId& dictId);

    static ZcDbObjectId         pointCloudExDictionary(ZcDbDatabase* pDb);

    static ZcDbDictionary*      getPointCloudExDictionary(ZcDbPointCloudDefEx* pDefEx);

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler) override;

    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler) override;

    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual Zcad::ErrorStatus   subErase(ZSoft::Boolean erasing) override;

    ZwSoft::RealityStudio::SDK::Interface::IRCData*   getRCData();

    Zcad::ErrorStatus   load();

    Zcad::ErrorStatus   unload();

    ZSoft::Boolean      isLoaded() const;

    int                 entityCount(ZSoft::Boolean* pbLocked = 0) const;

    Zcad::ErrorStatus   setSourceFileName(const TCHAR* pPathName);

    const TCHAR*        sourceFileName() const;

    Zcad::ErrorStatus   setActiveFileName(const TCHAR* pPathName);

    const TCHAR*        activeFileName() const;

    const TCHAR*        fileType() const;

    unsigned long long  totalPointsCount() const;

    int                 totalRegionsCount() const;

    int                 totalScansCount() const;

    double              defaultWidth() const;

    double              defaultLength() const;

    double              defaultHeight() const;

    PropState           hasProperty(Property prop) const;

    Zcad::ErrorStatus   createThumbnailBitmap( BITMAPINFO*& pBmpInfo,
                                               int width,
                                               int height ) const;

    ZcDbExtents         extents() const;

    const TCHAR*        coordinateSystemName() const;

    const TCHAR*        getRcsFilePath(const ZcString& guid) const;

    void                getAllRcsFilePaths(ZcStringArray& list) const;

private:
    PointCloudDefExImp*   m_pImp;
    static int          m_nVersion;
};

class PointCloudDefReactorExImp;

class ZCDB_PORT ZcDbPointCloudDefReactorEx : public ZcDbObject
{
public:

    static int                  classVersion();

    static void                 setEnable(ZSoft::Boolean bEnable);

    static ZSoft::Boolean       isEnabled();

    ZCRX_DECLARE_MEMBERS(ZcDbPointCloudDefReactorEx);

    ZcDbPointCloudDefReactorEx();

    virtual ~ZcDbPointCloudDefReactorEx();

    virtual Zcad::ErrorStatus   dwgInFields(ZcDbDwgFiler* pFiler) override;

    virtual Zcad::ErrorStatus   dwgOutFields(ZcDbDwgFiler* pFiler) const override;

    virtual Zcad::ErrorStatus   dxfInFields(ZcDbDxfFiler* pFiler) override;

    virtual Zcad::ErrorStatus   dxfOutFields(ZcDbDxfFiler* pFiler) const override;

    virtual void                erased(const ZcDbObject* dbObj,
                                        ZSoft::Boolean pErasing = true) override;

    virtual void                modified(const ZcDbObject* dbObj) override;

private:
    static int m_version;
    static ZSoft::Boolean       m_bIsEnabled;

    PointCloudDefReactorExImp*  m_pImp;
};
