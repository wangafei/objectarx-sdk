/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif
#ifndef RGBGRAYMODEL_H
#include "RgbGrayModel.h"
#endif

#ifndef GTILEXCEPTION_H
#include "ATILException.h"
#endif

#ifndef BITONALMODEL_H
#define BITONALMODEL_H
namespace Gtil
{
  class GTIL_EXPORT BitonalModel : public RgbGrayModel
  {
  public:
    BitonalModel();
    BitonalModel(int nEntries, const RgbColor* colors);
    virtual ~BitonalModel();

    virtual DataModel* clone() const;

    DataModelAttributes::DataModelType     dataModelType() const;
    virtual DataModelAttributes::PixelType pixelType() const;

    virtual bool canConvertTo(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionTo(const ColorModelInterface* colorModel,
                                                       RowProviderInterface* pConvert) const;

    virtual bool canConvertFrom(const ColorModelInterface* colorModel) const;
    virtual RowProviderInterface* getModelConversionFrom(const ColorModelInterface* colorModel,
                                                         RowProviderInterface* pConvert) const;

    virtual int numEntries() const;

    virtual void getEntries(int numEntries, RgbColor* colors) const;

    virtual bool operator==(const DataModel& dm) const;
    virtual bool operator!=(const DataModel& dm) const;

  protected:
    mutable RgbColor maPalette[2];
    int mnEntries;
  };

  class GTIL_EXPORT BitonalModelException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kInvalidPaletteIndex
    };
  public:
    BitonalModelException(const StringBuffer& sbMessage, ExceptionType eType = kInvalidPaletteIndex);
    BitonalModelException(const BitonalModelException& x);
    virtual ~BitonalModelException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };

}
#endif
