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

#ifndef DATABUFFER_H
namespace Gtil { class DataBuffer; }
#endif
#ifndef DATAMODEL_H
namespace Gtil { class DataModel; }
#endif
#ifndef IMAGEPIXEL_H
namespace Gtil { struct ImagePixel; }
#endif

#ifndef ROWPROVIDERINTERFACE_H
#define ROWPROVIDERINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT RowProviderInterface
  {
  public:
    virtual ~RowProviderInterface();

    virtual void getNextRow(DataBuffer& oneRow) = 0;

    virtual int rowsRemaining() = 0;

    virtual Size size() const = 0;

    virtual const DataModel& dataModel() const = 0;

    virtual bool hasSpanInfo() const = 0;

    virtual bool getNextSpan(int& nStart, int& nCount) = 0;

    virtual void restartSpans() = 0;

    virtual int numSpans() = 0;

    virtual int bytesPerRow() const = 0;

    virtual bool isValid() const = 0;
  };
}

#endif
