/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif
#ifndef BOUNDINGBOX_H
#include "BoundingBox.h"
#endif

#ifndef SPANPROVIDERINTERFACE_H
#define SPANPROVIDERINTERFACE_H

namespace GtilFilters
{
  class GTIL_EXPORT SpanProviderInterface
  {
  public:
    enum Mode
    {
      kInclusive,
      kExclusive
    };
  public:
    virtual ~SpanProviderInterface();

    virtual SpanProviderInterface* clone() const = 0;

    virtual Mode mode() = 0;

    virtual void begin() = 0;
    virtual void end() = 0;

    virtual bool nextRow() = 0;

    virtual int numRows() = 0;

    virtual bool getNextSpan(int& nStart, int& nCount) = 0;

    virtual int numSpans() = 0;

    virtual const Gtil::BoundingBox& bounds() const = 0;
  };
}

#endif
