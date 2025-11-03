/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef RGBMODEL_H
#include "RgbModel.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif
#ifndef RGBCOLOR_H
#include "RgbColor.h"
#endif
#ifndef GTILEXCEPTION_H
#include "ATILException.h"
#endif
#ifndef RGBPALETTEMODEL_H
#define RGBPALETTEMODEL_H

namespace Gtil
{
  class GTIL_EXPORT RgbPaletteModel : public RgbModel
  {
  public:
    RgbPaletteModel(int nPaletteEntries = 256);
    RgbPaletteModel(int nEntries, const RgbColor* colors);
    RgbPaletteModel(int nBitsUsedPerPixel, int nEntries, const RgbColor* colors);
    RgbPaletteModel(int nEntries, DataModelAttributes::ChannelOrder order, const RgbColor* colors);
    virtual ~RgbPaletteModel();

    virtual DataModel* clone() const;

    virtual DataModelAttributes::DataModelType dataModelType() const;

    virtual DataModelAttributes::PixelType pixelType() const;

    virtual bool canConvertTo(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* colorModel,
                                                       RowProviderInterface* pConvert) const;
    virtual bool canConvertFrom(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* colorModel,
                                                         RowProviderInterface* pConvert) const;

    virtual int numEntries() const;
    virtual void setEntries(int startAt, int numEntries, const RgbColor* colors);
    virtual void getEntries(int startAt, int numEntries, RgbColor* colors) const;

    bool isTransparent(int index) const;
    void setTransparent(int index) const;

    bool isOpaque(int index) const;
    void setOpaque(int index) const;

    Data8 alpha(int index) const;
    void setAlpha(int index, Data8 alpha) const;

    virtual bool operator==(const DataModel& rhs) const;
    virtual bool operator!=(const DataModel& rhs) const;

    Gtil::UInt8 nearestColorIndex(Gtil::RgbColor color) const;

    DataModelAttributes::ChannelOrder channelOrder() const;

  protected:
    RgbPaletteModel(DataModelAttributes::DataModelType dm,
                    DataModelAttributes::BitsPerPixel bpp,
                    int nEntries);

    mutable RgbColor maPalette[256];

    int mnEntries;
  };

  class GTIL_EXPORT RgbPaletteModelException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kInvalidPaletteIndex
    };
  public:
    RgbPaletteModelException(const StringBuffer& sbMessage,
                             ExceptionType eType = kInvalidPaletteIndex);
    RgbPaletteModelException(const RgbPaletteModelException& x);
    virtual ~RgbPaletteModelException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };
}

#endif
