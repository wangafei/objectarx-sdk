/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef OFFSET_INL
#define OFFSET_INL
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Gtil
{
  inline Offset::Offset() : x(0), y(0)
  {
  }
  inline Offset::Offset(Int32 nX, Int32 nY) : x(nX), y(nY)
  {
  }
  inline Offset::~Offset()
  {
  }
  inline const Offset& Offset::set(Int32 nX, Int32 nY)
  {
    x = nX;
    y = nY;
    return *this;
  }
  inline Offset& Offset::operator=(const Offset& rhs)
  {
    x = rhs.x;
    y = rhs.y;
    return *this;
  }
  inline Offset Offset::operator+(Int32 nOffset) const
  {
    return Offset(x + nOffset, y + nOffset);
  }
  inline Offset& Offset::operator+=(Int32 nOffset)
  {
    x += nOffset;
    y += nOffset;
    return *this;
  }
  inline Offset Offset::operator-(Int32 nOffset) const
  {
    return Offset(x - nOffset, y - nOffset);
  }
  inline Offset& Offset::operator-=(Int32 nOffset)
  {
    x -= nOffset;
    y -= nOffset;
    return *this;
  }
  inline Offset Offset::operator*(Int32 nValue) const
  {
    return Offset(x*nValue, y*nValue);
  }
  inline Offset& Offset::operator*=(Int32 nValue)
  {
    x *= nValue;
    y *= nValue;
    return *this;
  }
  inline Offset Offset::operator+(const Offset& rhs) const
  {
    return Offset(x + rhs.x, y + rhs.y);
  }
  inline Offset& Offset::operator+=(const Offset& rhs)
  {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
  inline Offset Offset::operator-(const Offset& rhs) const
  {
    return Offset(x - rhs.x, y - rhs.y);
  }
  inline Offset& Offset::operator-=(const Offset& rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }
  inline bool Offset::operator==(const Offset& rhs) const
  {
    return (x == rhs.x && y == rhs.y);
  }
  inline bool Offset::operator!=(const Offset& rhs) const
  {
    return (x != rhs.x || y != rhs.y);
  }

}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
