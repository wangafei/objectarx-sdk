/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef PIXELSELECTORINTERFACE_H
#define PIXELSELECTORINTERFACE_H

namespace GtilFilters
{
  class PixelSelectorInterface
  {
  public:
    virtual ~PixelSelectorInterface() {};

    virtual bool isSelected(Gtil::Int32 x, Gtil::Int32 y) = 0;
    virtual void setSelected(Gtil::Int32 y, Gtil::Int32 x, int nCount) = 0;

    virtual void flush() = 0;
  };
}

#endif
