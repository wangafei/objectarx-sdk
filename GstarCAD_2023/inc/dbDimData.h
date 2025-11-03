/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBDIMDATA_H
#define GD_DBDIMDATA_H

#include "gcdb.h"
#include "gcarray.h"
#include "dbdim.h"

class GcDbDimData;

typedef GcArray<GcDbDimData*> GcDbDimDataPtrArray;
typedef GcGeVector3d(*DimDataSetValueFuncPtr) (GcDbDimData* pThis,
  GcDbEntity* pEnt,
  double newValue,
  const GcGeVector3d& offset);
typedef GcGeVector3d(*DimDataSetCustomStringFuncPtr) (GcDbDimData* pThis,
  GcDbEntity* pEnt,
  const GCHAR* pCustomString,
  const GcGeVector3d& offset);
class GcDbDimData
{
public:
  enum DimDataFlags {
    kDimEditable = 0x1,
    kDimInvisible = 0x2,
    kDimFocal = 0x4,
    kDimHideIfValueIsZero = 0x8,
    kDimEmptyData = 0x10,
    kDimResultantLength = 0x20,
    kDimDeltaLength = 0x40,
    kDimResultantAngle = 0x80,
    kDimDeltaAngle = 0x100,
    kDimRadius = 0x200,
    kDimCustomValue = 0x400,
    kDimConstrained = 0x800,
    kDimCustomString = 0x1000
  };

  GcDbDimData();
  GcDbDimData(GcDbDimension* pDim,
    DimDataSetValueFuncPtr setDimFunc = NULL,
    unsigned int bitFlags = 0,
    void* appData = NULL,
    DimDataSetCustomStringFuncPtr setCustomStringFunc = NULL);
  ~GcDbDimData();
  GcDbDimData(const GcDbDimData&);
  GcDbDimData&  operator = (const GcDbDimData&);
  GcDbDimension* dimension() const;
  Gcad::ErrorStatus setDimension(GcDbDimension* pDim);
  GcDbObjectId ownerId() const;
  Gcad::ErrorStatus setOwnerId(const GcDbObjectId& objId);
  unsigned int bitFlags() const;
  Gcad::ErrorStatus setBitFlags(unsigned int flags);
  bool isDimFocal() const;
  Gcad::ErrorStatus setDimFocal(bool focal);
  bool isDimEditable() const;
  Gcad::ErrorStatus setDimEditable(bool editable);
  bool isDimInvisible() const;
  Gcad::ErrorStatus setDimInvisible(bool invisible);
  bool isDimHideIfValueIsZero() const;
  Gcad::ErrorStatus setDimHideIfValueIsZero(bool hide);
  void *appData() const;
  Gcad::ErrorStatus setAppData(void* appData);
  DimDataSetValueFuncPtr dimValueFunc() const;
  Gcad::ErrorStatus setDimValueFunc(DimDataSetValueFuncPtr funcPtr);
  DimDataSetCustomStringFuncPtr customStringFunc() const;
  Gcad::ErrorStatus setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr);
  bool isDimResultantLength() const;
  Gcad::ErrorStatus setDimResultantLength(bool bValue);
  bool isDimDeltaLength() const;
  Gcad::ErrorStatus setDimDeltaLength(bool bValue);
  bool isDimResultantAngle() const;
  Gcad::ErrorStatus setDimResultantAngle(bool bValue);
  bool isDimDeltaAngle() const;
  Gcad::ErrorStatus setDimDeltaAngle(bool bValue);
  bool isDimRadius() const;
  Gcad::ErrorStatus setDimRadius(bool bValue);
  bool isCustomDimValue() const;
  Gcad::ErrorStatus setCustomDimValue(bool custom);
  bool isConstrained() const;
  Gcad::ErrorStatus setConstrain(bool bValue);
  bool isCustomString() const;
  Gcad::ErrorStatus setCustomString(bool bValue);

private:
  GcDbDimension*      mpDim;
  GcDbObjectId        mOwnerId;
  unsigned int        mBitFlags;
  DimDataSetValueFuncPtr  mpSetDimValueFunc;
  void*               mpAppData;
  DimDataSetCustomStringFuncPtr  mpSetCustomStringFunc;
};

typedef GcArray<GcDbDimData> GcDbDimDataArray;

inline GcDbDimData::GcDbDimData() :
  mpDim(NULL),
  mBitFlags(0),
  mpSetDimValueFunc(NULL),
  mpAppData(NULL),
  mpSetCustomStringFunc(NULL)
{
}

inline GcDbDimData::GcDbDimData(GcDbDimension* pDim,
  DimDataSetValueFuncPtr setValueFunc,
  unsigned int bitFlags,
  void* appData,
  DimDataSetCustomStringFuncPtr setCustomStringFunc) :
  mpDim(pDim),
  mBitFlags(bitFlags),
  mpSetDimValueFunc(setValueFunc),
  mpAppData(appData),
  mpSetCustomStringFunc(setCustomStringFunc)
{
}

inline GcDbDimData::GcDbDimData(const GcDbDimData& src)
{
  *this = src;
}

inline GcDbDimData::~GcDbDimData()
{
  if (mpDim)
    delete mpDim;
}

inline GcDbDimData& GcDbDimData::operator = (const GcDbDimData& src)
{
  if (this == &src)
    return *this;

  mpDim = (GcDbDimension*)src.dimension()->clone();
  mOwnerId = src.ownerId();
  mpSetDimValueFunc = src.dimValueFunc();
  mpSetCustomStringFunc = src.customStringFunc();
  mBitFlags = src.bitFlags();
  mpAppData = src.appData();
  return *this;
}

inline GcDbDimension*
GcDbDimData::dimension() const
{
  return mpDim;
}

inline Gcad::ErrorStatus
GcDbDimData::setDimension(GcDbDimension* pDim)
{
  mpDim = pDim;
  return Gcad::eOk;
}

inline GcDbObjectId
GcDbDimData::ownerId() const
{
  return mOwnerId;
}

inline Gcad::ErrorStatus
GcDbDimData::setOwnerId(const GcDbObjectId& objId)
{
  mOwnerId = objId;
  return Gcad::eOk;
}

inline unsigned int
GcDbDimData::bitFlags() const
{
  return mBitFlags;
}

inline Gcad::ErrorStatus
GcDbDimData::setBitFlags(unsigned int flags)
{
  mBitFlags = flags;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isDimFocal() const
{
  return !!(mBitFlags & kDimFocal);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimFocal(bool focal)
{
  if (focal)
    mBitFlags |= kDimFocal;
  else
    mBitFlags &= ~kDimFocal;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isDimEditable() const
{
  return !!(mBitFlags & kDimEditable);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimEditable(bool editable)
{
  if (editable)
    mBitFlags |= kDimEditable;
  else
    mBitFlags &= ~kDimEditable;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isDimInvisible() const
{
  return !!(mBitFlags & kDimInvisible);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimInvisible(bool invisible)
{
  if (invisible)
    mBitFlags |= kDimInvisible;
  else
    mBitFlags &= ~kDimInvisible;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isDimHideIfValueIsZero() const
{
  return !!(mBitFlags & kDimHideIfValueIsZero);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimHideIfValueIsZero(bool hide)
{
  if (hide)
    mBitFlags |= kDimHideIfValueIsZero;
  else
    mBitFlags &= ~kDimHideIfValueIsZero;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isDimResultantLength() const
{
  return !!(mBitFlags & kDimResultantLength);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimResultantLength(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimResultantLength;
  else
    mBitFlags &= ~kDimResultantLength;
  return Gcad::eOk;
}
inline bool
GcDbDimData::isDimDeltaLength() const
{
  return !!(mBitFlags & kDimDeltaLength);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimDeltaLength(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimDeltaLength;
  else
    mBitFlags &= ~kDimDeltaLength;
  return Gcad::eOk;
}
inline bool
GcDbDimData::isDimResultantAngle() const
{
  return !!(mBitFlags & kDimResultantAngle);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimResultantAngle(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimResultantAngle;
  else
    mBitFlags &= ~kDimResultantAngle;
  return Gcad::eOk;
}
inline bool
GcDbDimData::isDimDeltaAngle() const
{
  return !!(mBitFlags & kDimDeltaAngle);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimDeltaAngle(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimDeltaAngle;
  else
    mBitFlags &= ~kDimDeltaAngle;
  return Gcad::eOk;
}
inline bool
GcDbDimData::isDimRadius() const
{
  return !!(mBitFlags & kDimRadius);
}

inline Gcad::ErrorStatus
GcDbDimData::setDimRadius(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimRadius;
  else
    mBitFlags &= ~kDimRadius;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isCustomDimValue() const
{
  return !!(mBitFlags & kDimCustomValue);
}

inline Gcad::ErrorStatus
GcDbDimData::setCustomDimValue(bool custom)
{
  if (custom)
    mBitFlags |= kDimCustomValue;
  else
    mBitFlags &= ~kDimCustomValue;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isConstrained() const
{
  return !!(mBitFlags & kDimConstrained);
}

inline Gcad::ErrorStatus
GcDbDimData::setConstrain(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimConstrained;
  else
    mBitFlags &= ~kDimConstrained;
  return Gcad::eOk;
}

inline bool
GcDbDimData::isCustomString() const
{
  return !!(mBitFlags & kDimCustomString);
}

inline Gcad::ErrorStatus
GcDbDimData::setCustomString(bool bValue)
{
  if (bValue)
    mBitFlags |= kDimCustomString;
  else
    mBitFlags &= ~kDimCustomString;
  return Gcad::eOk;
}

inline void*
GcDbDimData::appData() const
{
  return mpAppData;
}

inline Gcad::ErrorStatus
GcDbDimData::setAppData(void* appData)
{
  mpAppData = appData;
  return Gcad::eOk;
}

inline DimDataSetValueFuncPtr
GcDbDimData::dimValueFunc() const
{
  return mpSetDimValueFunc;
}

inline Gcad::ErrorStatus
GcDbDimData::setDimValueFunc(DimDataSetValueFuncPtr funcPtr)
{
  mpSetDimValueFunc = funcPtr;
  return Gcad::eOk;
}

inline DimDataSetCustomStringFuncPtr
GcDbDimData::customStringFunc() const
{
  return mpSetCustomStringFunc;
}

inline Gcad::ErrorStatus
GcDbDimData::setCustomStringFunc(DimDataSetCustomStringFuncPtr funcPtr)
{
  mpSetCustomStringFunc = funcPtr;
  return Gcad::eOk;
}

#endif 


