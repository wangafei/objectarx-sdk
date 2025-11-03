#pragma once

class ZcDbPointCloudCropStateManagerImp;
class ZcDbPointCloudEx;

class ZCDB_PORT ZcDbPointCloudCropStateManager
{
public:

    Zcad::ErrorStatus  restoreCropState(const ZcString& name);

    Zcad::ErrorStatus  getAllCropStates(ZcArray<ZcString>& states) const;

    Zcad::ErrorStatus  removeCropState(const ZcString& name);

    Zcad::ErrorStatus  renameCropState(const ZcString& oldName, const ZcString& newName);

    Zcad::ErrorStatus  addCropState(const ZcString& state);

    ZcString           currentCropState() const;

private:
    ZcDbPointCloudCropStateManager();
    ZcDbPointCloudCropStateManager(ZcDbPointCloudEx* pCloud);
    virtual ~ZcDbPointCloudCropStateManager();

    ZcDbPointCloudCropStateManagerImp* m_pImpCropStatesManager;

    friend class PointCloudExImp;
    friend class PointCloudCropStateRoundtripManager;
};
