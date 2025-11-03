/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef GTILEXCEPTION_H
#include "ATILException.h"
#endif
#ifndef ROWPROVIDERINTERFACE_H
#include "RowProviderInterface.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif
#ifndef IMAGEPIXEL_H
#include "ImagePixel.h"
#endif

#ifndef DATAMODEL_H
namespace Gtil { class DataModel; }
#endif
#ifndef DATABUFFER_H
namespace Gtil { class DataBuffer; }
#endif
#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

namespace Gtil
{
  class GTIL_EXPORT ImageFilter : public RowProviderInterface
  {
  public:
    virtual Size size() const;

    virtual const DataModel& dataModel() const;

    virtual int bytesPerRow() const;

    virtual bool isValid() const;

    virtual bool hasSpanInfo() const;

    virtual int rowsRemaining() = 0;

    virtual void getNextRow(DataBuffer &oneRow) = 0;

    virtual bool getNextSpan(int& nStart, int& nCount);

    virtual void restartSpans();

    virtual int numSpans();

    virtual void convertColor(ImagePixel& color) const;

  protected:
    ImageFilter();
    virtual ~ImageFilter();

    bool connectInput(RowProviderInterface*& input);
    bool connectInput(RowProviderInterface*& input, const DataModel& dmConvertTo);

    void init(const Size& size);
    void init(const Size& size, const DataModel& colorspace);

    int numInputs() const;

    RowProviderInterface* input(int nInputIndex) const;

  private:
    RowProviderInterface* mapDefault[5];
    RowProviderInterface** mapInputs;
    int mnElements;
    int mnInputs;
    DataModel* mpOutputDm;
    Size mOutputSize;
  };

  class GTIL_EXPORT ImageFilterException : public GTILException
  {
  public:
    enum ExceptionType
    {
      kNotInitialized,
      kNoValidInput,
      kInvalidClearColor,
      kOverConnected,
      kAlreadyInitialized,
      kUnSpecified
    };

  public:
    ImageFilterException(const StringBuffer& sbMessage,
                         ExceptionType type = ImageFilterException::kUnSpecified);
    ImageFilterException(const ImageFilterException& x);
    virtual ~ImageFilterException();

    virtual ExceptionType getExceptionType();

  private:
    ExceptionType eType;
  };
}

#endif
