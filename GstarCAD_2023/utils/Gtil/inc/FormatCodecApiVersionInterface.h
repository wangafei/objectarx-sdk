/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef FORMATCODECAPIVERSIONINTERFACE_H
#define FORMATCODECAPIVERSIONINTERFACE_H

#ifndef GTILVERSIONS_H
#include "AtilVersions.h"
#endif

namespace Gtil
{
  class GTIL_EXPORT FormatCodecApiVersionInterface
  {
  public:

    virtual ~FormatCodecApiVersionInterface();

    virtual int majorVersion() const;
    virtual int minorVersion() const;
  };
}

#endif
