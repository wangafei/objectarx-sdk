/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

class GcDbPointCloudCropStateManagerImp;
class GcDbPointCloudEx;

class GCDB_PORT GcDbPointCloudCropStateManager
{
public:
  Gcad::ErrorStatus  restoreCropState(const GcString& name);
  Gcad::ErrorStatus  getAllCropStates(GcArray<GcString>& states) const;
  Gcad::ErrorStatus  removeCropState(const GcString& name);
  Gcad::ErrorStatus  renameCropState(const GcString& oldName, const GcString& newName);
  Gcad::ErrorStatus  addCropState(const GcString& state);
  GcString           currentCropState() const;

private:
  GcDbPointCloudCropStateManager();
  GcDbPointCloudCropStateManager(GcDbPointCloudEx* pCloud);
  virtual ~GcDbPointCloudCropStateManager();

  GcDbPointCloudCropStateManagerImp* m_pImpCropStatesManager;

  friend class PointCloudExImp;
  friend class PointCloudCropStateRoundtripManager;
};