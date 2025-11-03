/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include <AtilDefs.h>
#endif

#ifndef OFFSET_H
#include "Offset.h"
#endif

#ifndef SIZE_H
#define SIZE_H

namespace Gtil
{
  class GTIL_EXPORT Size
  {
  public:
    Int32 width;
    Int32 height;

    Size();
    Size(Int32 width, Int32 height);
    Size(const Size& rhs);
    ~Size();

    bool operator <= (const Size& rhs) const;
    bool operator >= (const Size& rhs) const;

    bool operator == (const Size& rhs) const;
    bool operator != (const Size& rhs) const;

    const Size& operator = (const Size& rhs);

    const Size& set(Int32 nWidth, Int32 nHeight);

    const Size& grow(Int32 valueWidth, Int32 valueHeight);
    const Size& grow(Int32 toEach);

    const Size& shrink(Int32 valueWidth, Int32 valueHeight);
    const Size& shrink(Int32 eachBy);
  };

  namespace SizeOps
  {
    inline Size getSizeOf(const Offset& oHigh, const Offset& oLow)
    {
      return Size(oHigh.x - oLow.x + 1, oHigh.y - oLow.y + 1);
    }
    inline Offset getHighOffset(const Size& extents)
    {
      return Offset(extents.width - 1, extents.height - 1);
    }

    inline Offset getHighOffset(const Offset& oOrigin, const Size& extents)
    {
      return Offset(oOrigin.x + extents.width - 1, oOrigin.y + extents.height - 1);
    }
  }
}

#ifndef SIZE_INL
#include <Size.inl>
#endif

#endif
