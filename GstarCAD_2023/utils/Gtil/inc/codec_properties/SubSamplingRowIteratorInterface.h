/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef SUBREGIONROWITERATORINTERFACE_H
#include "SubRegionRowIteratorInterface.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif

#ifndef SUBSAMPLINGROWITERATORINTERFACE_H
#define SUBSAMPLINGROWITERATORINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT SubSamplingRowIteratorInterface : public SubRegionRowIteratorInterface
  {
  public:
    virtual ~SubSamplingRowIteratorInterface();

    virtual void setScaledSize(const Size& scaledSize) = 0;
    virtual void resetScaleFactor() = 0;

    SubSamplingRowIteratorInterface();
  };
}

#endif
