/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef READIMAGEFILEFRAMEINTERFACE_H
#include "ReadImageFileFrameInterface.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif

#ifndef SUBSAMPLINGINTERFACE_H
#define SUBSAMPLINGINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT SubSamplingInterface
  {
  public:
    virtual ~SubSamplingInterface();

    virtual bool getAvailableResolution(const Size& srcSize,
                                        const Size& outputSize,
                                        Size& lowerResSize,
                                        Size& higherResSize) = 0;

    SubSamplingInterface();
  };
}

#endif
