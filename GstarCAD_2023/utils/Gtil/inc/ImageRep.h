/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef DATAMODEL_H
#include "DataModel.h"
#endif
#ifndef IMAGECONTEXT_H
#include "ImageContext.h"
#endif

#ifndef SIZE_H
namespace Gtil { class Size; }
#endif
#ifndef OFFSET_H
namespace Gtil { class Offset; }
#endif
#ifndef IMAGEPIXEL_H
namespace Gtil { struct ImagePixel; }
#endif
#ifndef ROWPROVIDERINTERFACE_H
namespace Gtil { class RowProviderInterface; }
#endif
#ifndef FILEREADDESCRIPTOR_H
namespace Gtil { class FileReadDescriptor; }
#endif
#ifndef FILEWRITEDESCRIPTOR_H
namespace Gtil { class FileWriteDescriptor; }
#endif
#ifndef IMAGECONTEXTREP_H
namespace Gtil { class ImageContextRep; }
#endif
#ifndef IMAGEREACTORINTERFACE_H
namespace Gtil { class ImageReactorInterface; }
#endif

#ifndef IMAGEREP_H
#define IMAGEREP_H

namespace Gtil
{
  class GTIL_EXPORT ImageRep
  {
  public:
    virtual ~ImageRep();

    virtual ImageRep* construct(ImageRep*  ToClone) = 0;
    virtual ImageRep* construct(const Size& size, const DataModel* colorspace, ImagePixel clearColor, DataModel::TileSize sz) = 0;
    virtual ImageRep* construct(void* pDataBuffer, int nBytesInBuffer, int nBytesPerRow, const Size& size, const DataModel* pDm) = 0;
    virtual ImageRep* construct(RowProviderInterface* pPipe, int oriented, DataModel::TileSize sz) = 0;
    virtual ImageRep* construct(FileReadDescriptor& readDesc, DataModel::TileSize sz) = 0;

    virtual bool operator== (const ImageRep& imageRep) const = 0;

    virtual const Size& size() const = 0;

    virtual int   numTiles(int& nRows, int& nCols) const = 0;

    virtual Size  tileSize() const = 0;

    virtual const DataModel& dataModel() const = 0;

    virtual const FileReadDescriptor* fileReadDescriptor() const = 0;

    virtual const ImagePixel& clearColor() const = 0;
    virtual void setClearColor(ImagePixel clearValue) = 0;

    virtual bool isValid() const = 0;

    virtual bool isModified() const = 0;

    virtual bool usesUserBuffer() const = 0;

    virtual void setDataModel(const DataModel& dataModel) = 0;

    virtual void* getUserBuffer() = 0;

    virtual ImageContextRep* createContext(ImageContext::Access accessMethod,
                                           const Size& size,
                                           const Offset& offset,
                                           int numTilesToCache) = 0;

    virtual RowProviderInterface* read(const Size& size, const Offset& offset) const = 0;
    virtual RowProviderInterface* read(const Size& size, const Offset& offset, int oriented) const = 0;

    virtual void clear() = 0;

    virtual void paste(RowProviderInterface* pPipe,
                       const Offset& at,
                       bool bRespectTransparency) = 0;

    virtual void blend(RowProviderInterface * pPipe,
                       const Offset& at,
                       int nAlphaValue,
                       bool bRespectTransparency) = 0;

    virtual void addReactor(ImageReactorInterface* pReactor) = 0;
    virtual void removeReactor(ImageReactorInterface* pReactor) = 0;

    virtual bool disablePerTileLocking(bool bDisable) = 0;
  };
}

#endif
