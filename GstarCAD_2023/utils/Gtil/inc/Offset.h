/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef OFFSET_H
#define OFFSET_H

namespace Gtil
{
  class GTIL_EXPORT Offset
  {
  public:
    Int32 x;
    Int32 y;

    Offset();
    Offset(Int32 valueX, Int32 valueY);
    ~Offset();

    const Offset& set(Int32 valueX, Int32 valueY);

    Offset& operator=(const Offset& rhs);

    Offset operator+(Int32 nOffset) const;
    Offset& operator+=(Int32 nOffset);

    Offset operator-(Int32 nOffset) const;
    Offset& operator-=(Int32 nOffset);

    Offset operator*(Int32 nValue) const;
    Offset& operator*=(Int32 nValue);

    Offset operator+(const Offset& rhs) const;
    Offset& operator+=(const Offset& rhs);

    Offset operator-(const Offset& rhs) const;
    Offset& operator-=(const Offset& rhs);

    bool operator==(const Offset& rhs) const;
    bool operator!=(const Offset& rhs) const;
  };
}

#ifndef OFFSET_INL
#include <Offset.inl>
#endif

#endif
