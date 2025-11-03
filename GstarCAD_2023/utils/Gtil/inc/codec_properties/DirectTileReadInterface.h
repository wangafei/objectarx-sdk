/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef READIMAGEFILEFRAMEINTERFACE_H
#include "ReadImageFileFrameInterface.h"
#endif

#ifndef DIRECTTILEREADINTERFACE_H
#define DIRECTTILEREADINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT DirectTileReadInterface
  {
  public:
    virtual ~DirectTileReadInterface();

    virtual int  getTileSize(int nLookingFor) = 0;
    virtual bool getTileData(UInt32 nRow, UInt32 nColumn, UInt8* pBuffer) = 0;
  };
}

#endif
