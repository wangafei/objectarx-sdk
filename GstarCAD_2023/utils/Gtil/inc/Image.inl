/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef IMAGEREP_H
#include "ImageRep.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif

#ifndef IMAGE_INL
#define IMAGE_INL
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Gtil
{
  inline const Size& Image::size() const
  {
    return mImplementation->size();
  }
  inline Size Image::tileSize() const
  {
    return mImplementation->tileSize();
  }
  inline const DataModel& Image::dataModel() const
  {
    return mImplementation->dataModel();
  }
  inline const FileReadDescriptor* Image::fileReadDescriptor() const
  {
    return mImplementation->fileReadDescriptor();
  }
  inline int Image::numTiles(int& nRows, int& nColumns) const
  {
    return mImplementation->numTiles(nRows, nColumns);
  }
  inline const ImagePixel& Image::clearColor() const
  {
    return mImplementation->clearColor();
  }
  inline void Image::setClearColor(ImagePixel value)
  {
    mImplementation->setClearColor(value);
  }
  inline void Image::setDataModel(const DataModel& dataModel)
  {
    mImplementation->setDataModel(dataModel);
  }
  inline void Image::blend(RowProviderInterface* pPipe,
                           const Offset& at,
                           int nAlphaValue,
                           bool bRespectTransparency)
  {
    mImplementation->blend(pPipe, at, nAlphaValue, bRespectTransparency);
  }
  inline RowProviderInterface* Image::read(const Size& size, const Offset& offset) const
  {
    return mImplementation->read(size, offset);
  }
  inline RowProviderInterface* Image::read(const Size& size, const Offset& offset, Orientation orient) const
  {
    return mImplementation->read(size, offset, (int)orient);
  }
  inline bool Image::disablePerTileLocking(bool bDisable)
  {
    return mImplementation->disablePerTileLocking(bDisable);
  }
  inline void Image::clear()
  {
    mImplementation->clear();
  }
  inline bool Image::isValid() const
  {
    return (mImplementation != NULL && mImplementation->isValid());
  }
  inline bool Image::isModified() const
  {
    return mImplementation->isModified();
  }
  inline bool Image::usesUserBuffer() const
  {
    return mImplementation->usesUserBuffer();
  }
  inline void Image::addReactor(ImageReactorInterface* pReactor)
  {
    mImplementation->addReactor(pReactor);
  }

  inline void Image::removeReactor(ImageReactorInterface* pReactor)
  {
    mImplementation->removeReactor(pReactor);
  }
}
#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
