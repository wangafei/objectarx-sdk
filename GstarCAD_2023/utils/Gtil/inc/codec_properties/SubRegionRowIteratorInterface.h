/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef ROWITERATORINTERFACE_H
#include "RowIteratorInterface.h"
#endif

#ifndef SUBREGIONROWITERATORINTERFACE_H
#define SUBREGIONROWITERATORINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT SubRegionRowIteratorInterface : public RowIteratorInterface
  {
  public:
    virtual ~SubRegionRowIteratorInterface();

    virtual void setRegionToExtents() = 0;

    virtual void setStart(int nRow, int nCol) = 0;
    virtual void getStart(int& nRow, int& nCol) = 0;

    virtual void setEnd(int nRow, int nCol) = 0;
    virtual void getEnd(int& nRow, int& nCol) = 0;
  };
}

#endif
