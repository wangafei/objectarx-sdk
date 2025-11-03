/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef DATABUFFER_H
namespace Gtil { class DataBuffer; }
#endif

#ifndef ROWITERATORINTERFACE_H
#define ROWITERATORINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT RowIteratorInterface
  {
  public:
    virtual ~RowIteratorInterface();

    virtual int rowBytes() = 0;

    virtual void getRow(DataBuffer* pRowBuffer) = 0;

    virtual bool incrementRowPointer() = 0;

    virtual int numRows() = 0;
    virtual int numColumns() = 0;

    virtual void beginReadingRows() = 0;
    virtual void doneReadingRows() = 0;
  };
}

#endif
