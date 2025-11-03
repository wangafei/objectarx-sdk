/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GRX_DBMATCH_H
#define GRX_DBMATCH_H

#include "gcdb.h"
#include "dbmain.h"

#pragma pack (push, 8)

class GCDB_PORT  GcDbMatchProperties : public GcRxObject
{
public:
  enum Flags {
    kColorFlag = 0x1,
    kLayerFlag = 0x2,
    kLtypeFlag = 0x4,
    kThicknessFlag = 0x8,
    kLtscaleFlag = 0x10,
    kTextFlag = 0x20,
    kDimensionFlag = 0x40,
    kHatchFlag = 0x80,
    kLweightFlag = 0x100,
    kPlotstylenameFlag = 0x200,
    kPolylineFlag = 0x400,
    kViewportFlag = 0x800,
    kTableFlag = 0x1000,
    kMaterialFlag = 0x2000,
    kShadowDisplayFlag = 0x4000,
    kMultileaderFlag = 0x8000,
    kTransparencyFlag = 0x10000,
    kCenterObjectFlag = 0x20000,
    kSetAllFlagsOn = 0x3FFFF
  };

  GCRX_DECLARE_MEMBERS(GcDbMatchProperties);

  virtual void copyProperties(GcDbEntity* pSrcEntity, GcDbEntity* pTrgEntity, unsigned int flag) const = 0;
};

#pragma pack (pop)

#endif
