/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif
#ifndef DATAMODEL_H
#include "DataModel.h"
#endif
#ifndef COLORMODELINTERFACE_H
#include "ColorModelInterface.h"
#endif

#ifndef RGBMODEL_H
#define RGBMODEL_H

namespace Gtil
{
  class GTIL_EXPORT RgbModel : public DataModel, public ColorModelInterface
  {
  public:
    static bool isRgb(DataModelAttributes::DataModelType dmt);

    static RowProviderInterface* convertToRgba(RowProviderInterface* pPipe);
  public:
    RgbModel();
    RgbModel(RgbModelAttributes::Channels channels, DataModelAttributes::ChannelOrder order);
    RgbModel(RgbModelAttributes::Channels channels, DataModelAttributes::ChannelOrder order, DataModelAttributes::BitsPerPixel bpp, int nDataBits);
    RgbModel(int dataBits);
    RgbModel(const RgbModel &model);
    virtual ~RgbModel();

    virtual DataModel* clone() const;

    virtual DataModelAttributes::DataModelType dataModelType() const;

    virtual DataModelAttributes::PixelType pixelType() const;

    virtual bool canConvertTo(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* colorModel,
                                                       RowProviderInterface* pConvert) const;
    virtual bool canConvertFrom(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* colorModel,
                                                         RowProviderInterface* pConvert) const;

    DataModelAttributes::ChannelOrder channelOrder() const;

    virtual bool operator==(const DataModel& dm) const;
    virtual bool operator!=(const DataModel& dm) const;

  protected:
    RgbModel(DataModelAttributes::DataModelType dmt, DataModelAttributes::BitsPerPixel bpp);
    RgbModel(DataModelAttributes::DataModelType dmt, DataModelAttributes::BitsPerPixel bpp, int nBitsUsedPerPixel);

    DataModelAttributes::ChannelOrder mOrder;
  };
}

#endif
