/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef RGBMODEL_H
#include "RgbModel.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif

#ifndef RGBGRAYMODEL_H
#define RGBGRAYMODEL_H

namespace Gtil
{
  class GTIL_EXPORT RgbGrayModel : public RgbModel
  {
  public:
    RgbGrayModel();
    RgbGrayModel(DataModelAttributes::DataModelType dm, DataModelAttributes::BitsPerPixel bpp);
    virtual ~RgbGrayModel();

    virtual DataModel* clone() const;

    virtual DataModelAttributes::DataModelType dataModelType() const;

    virtual DataModelAttributes::PixelType pixelType() const;

    virtual bool canConvertTo(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* colorModel,
                                                       RowProviderInterface* pConvert) const;
    virtual bool canConvertFrom(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* colorModel,
                                                         RowProviderInterface* pConvert) const;

    bool isTransparent(Data8 intensity) const;
    void setTransparent(Data8 intensity) const;

    bool isOpaque(Data8 intensity) const;
    void setOpaque(Data8 intensity) const;

    Data8 alpha(Data8 intensity) const;
    void setAlpha(Data8 intensity, Data8 alpha) const;

    virtual bool operator==(const DataModel& dm) const;
    virtual bool operator!=(const DataModel& dm) const;

  protected:
    mutable Data8 maAlphas[256];
  };
}

#endif
