/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcDbAssocArrayItem.h"
class GCDB_PORT GcDbArrayGripAppData : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbArrayGripAppData);

  GcDbArrayGripAppData(const GcGePoint3d& position = GcGePoint3d(),
                       unsigned int modes = 0);
  ~GcDbArrayGripAppData();

  const GcGePoint3d& position() const { return mPosition; }
  unsigned int modes() const { return mnModes; }
  void addGripMode(unsigned int mode) { mnModes |= mode; }

  void* getAppData(GcRxClass** ppClass = NULL) const
  {
    if (NULL != ppClass)
      *ppClass = mpAppDataClass;
    return mpAppData;
  }
  void setAppData(void* pData, GcRxClass* pClass)
  {
    mpAppData = pData; mpAppDataClass = pClass;
  }

  bool& arrowGrip() { return mbArrowGrip; }

  GcGeVector3d& xDir() { return mDirections[0]; }
  GcGeVector3d& yDir() { return mDirections[1]; }

  GcDbItemLocator& locator() { return mLocator; }

  const GcDbDimDataPtrArray& dimData() const { return mDimData; }
  void appendDimData(GcDbDimData* pData);
  void deleteDimData();

  void setBasePoint(GcGePoint3d &basePoint);
  const GcGePoint3d* basePoint() const { return mpBasePoint; }

private:
  GcGePoint3d mPosition;
  unsigned int mnModes;
  void* mpAppData;
  GcRxClass* mpAppDataClass;
  GcDbItemLocator mLocator;
  bool mbArrowGrip;
  GcGeVector3d mDirections[2];
  GcDbDimDataPtrArray mDimData;
  GcGePoint3d *mpBasePoint;
};
