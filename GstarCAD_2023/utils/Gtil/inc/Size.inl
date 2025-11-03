/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef SIZE_INL
#define SIZE_INL
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Gtil
{
  inline Size::Size(Int32 nWidth, Int32 nHeight) : width(nWidth), height(nHeight)
  {
  }
  inline Size::Size() : width(0), height(0)
  {
  }
  inline Size::Size(const Size& rhs) : width(rhs.width), height(rhs.height)
  {
  }
  inline Size::~Size()
  {
  }
  inline bool Size::operator <= (const Size& rhs) const
  {
    return width <= rhs.width && height <= rhs.height;
  }
  inline bool Size::operator >= (const Size& rhs) const
  {
    return width >= rhs.width && height >= rhs.height;
  }
  inline bool Size::operator == (const Size& rhs) const
  {
    return width == rhs.width && height == rhs.height;
  }
  inline bool Size::operator != (const Size& rhs) const
  {
    return width != rhs.width || height != rhs.height;
  }
  inline const Size& Size::operator = (const Size& rhs)
  {
    width = rhs.width; height = rhs.height;
    return *this;
  }
  inline const Size& Size::set(Int32 nWidth, Int32 nHeight)
  {
    width = nWidth; height = nHeight;
    return *this;
  }
  inline const Size& Size::grow(Int32 nWidth, Int32 nHeight)
  {
    width += nWidth;
    height += nHeight;
    return *this;
  }
  inline const Size& Size::grow(Int32 toEach)
  {
    width += toEach;
    height += toEach;
    return *this;
  }
  inline const Size& Size::shrink(Int32 byWidth, Int32 byHeight)
  {
    width -= byWidth;
    height -= byHeight;
    return *this;
  }
  inline const Size& Size::shrink(Int32 eachBy)
  {
    width -= eachBy;
    height -= eachBy;
    return *this;
  }
}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
