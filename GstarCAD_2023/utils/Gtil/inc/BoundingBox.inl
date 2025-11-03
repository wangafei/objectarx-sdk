/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef BOUNDINGBOX_INL
#define BOUNDINGBOX_INL

#ifndef OFFSET_H
#include "Offset.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif
namespace Gtil
{
  inline BoundingBox::BoundingBox(Offset offset, Size size) : mOrigin(offset)
  {
    mExtent = SizeOps::getHighOffset(offset, size);
  }
  inline BoundingBox::BoundingBox(Offset origin, Offset extent) : mOrigin(origin), mExtent(extent)
  {
  }
  inline BoundingBox::BoundingBox(int nPoints, const Offset* aOffsets)
  {
    set(nPoints, aOffsets);
  }
  inline BoundingBox::~BoundingBox()
  {
  }
  inline void BoundingBox::set(Offset offset, Size size)
  {
    mOrigin = offset; mExtent = SizeOps::getHighOffset(offset, size);
  }
  inline void BoundingBox::set(Offset origin, Offset extent)
  {
    mOrigin = origin; mExtent = extent;
  }
  inline bool BoundingBox::inBounds(const Offset& offset) const
  {
    return (offset.x >= mOrigin.x && offset.y >= mOrigin.y && offset.x <= mExtent.x && offset.y <= mExtent.y);
  }
  inline bool BoundingBox::inBounds(int x, int y) const
  {
    return (x >= mOrigin.x && y >= mOrigin.y && x <= mExtent.x && y <= mExtent.y);
  }
  inline void BoundingBox::getExtents(Offset& origin, Offset& extent) const
  {
    origin = mOrigin; extent = mExtent;
  }
  inline Size BoundingBox::size() const
  {
    return SizeOps::getSizeOf(mExtent, mOrigin);
  }
  inline Offset BoundingBox::origin() const
  {
    return mOrigin;
  }
  inline bool BoundingBox::contains(const BoundingBox& otherBox) const
  {
    return (inBounds(otherBox.mOrigin) && inBounds(otherBox.mExtent));
  }
}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif
#endif
