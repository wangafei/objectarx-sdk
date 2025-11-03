#ifndef ZDATAMODELATTRIBUTES_H
#include "zDataModelAttributes.h"
#endif
#ifndef ZRGBGRAYMODEL_H
#include "zRgbGrayModel.h"
#endif

#ifndef ZTILEXCEPTION_H
#include "ZTILException.h"
#endif

#ifndef ZBITONALMODEL_H
#define ZBITONALMODEL_H
#if  __GNUC__ >= 4
#pragma GCC visibility push(default)
#endif

namespace Ztil
{
/// <summary>
/// The data model for 1-bit images that are part of the RgbModel space. 
/// This datamodel is derived from RgbGrayModel. The foreground "on" or "1" pixels 
/// are considered to be white(255), and the background "off" or "0" pixels are considered 
/// to be black(0).
/// </summary>
///
class DllImpExp BitonalModel : public RgbGrayModel
{
public:

    /// <summary>
    /// The class constructor will create an instance of the class.
    /// </summary>
    ///
    BitonalModel ();

    /// <summary>
    /// Palette initializing constructor.
    /// </summary>
    ///    
    /// <param name='nEntries'> The number of entries that in the palette.
    /// </param>
    ///
    /// <param name='colors'> A constant point to an array of <c>RgbColor</c> instances
    /// with at least <c>nEntries</c> members. The colors will be used to initialize the palette.
    /// </param>
    ///
    BitonalModel(int nEntries, const RgbColor* colors);

    /// <summary>
    /// Virtual destructor.
    /// </summary>
    ///
    virtual ~BitonalModel ();

    /// <summary>
    /// The implementation of the clone method used which is the safest way to
    /// make a copy of an existing <c>BitonalModel</c> instance.
    /// </summary>
    ///
    /// <returns>
    /// This will return a copy of the instance.
    /// </returns>
    ///
    virtual DataModel* clone () const;

    /// <summary>
    /// This query returns an entry of the DataModelType enum. It will always
    /// return <c>kBitonalModel</c>.
    /// </summary>
    ///
    /// <returns>
    /// An entry of the DataModelType enum that is <c>kBitonalModel</c>.
    /// </returns>
    ///
    DataModelAttributes::DataModelType dataModelType () const;

    /// <summary>
    /// Query the pixel type of the data represented which is always kBitonal.
    /// </summary>
    ///
    /// <returns>
    /// This method returns PixelType::kBitonal.
    /// </returns>
    ///
    virtual DataModelAttributes::PixelType pixelType () const;

    /// <summary>
    /// This method test for convertibility to a given <c>ColorModelInterface</c>.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be tested to see if this instance can convert into it.
    /// </param>
    /// 
    /// <returns>
    /// This should return if this class can supply a conversion filter.
    /// </returns>
    ///
    virtual bool canConvertTo (const ColorModelInterface* colorModel) const;

    /// <summary>
    /// This method asks for the conversion. The <c>canConvertTo</c> method will
    /// be called first to confirm that at a conversion is available.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be convert into it.
    /// </param>
    ///
    /// <param name='pConvert'> An instance of a <c>RowProviderInterface</c>
    /// that represents the source of the data to be converted.
    /// </param>
    ///
    /// <returns>
    /// This returns a new filter that has the conversion hooked into it. See the
    /// <c>ImageFilter</c> base class for more information on creating and linking
    /// together filters.
    /// </returns>
    ///
    virtual RowProviderInterface* getModelConversionTo (
        const ColorModelInterface* colorModel, RowProviderInterface* pConvert) const;

    /// <summary>
    /// This method test for convertibility into a given <c>ColorModelInterface</c>.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be tested to see if this instance can convert from it.
    /// </param>
    /// 
    /// <returns>
    /// This should return if this class can supply a conversion filter that will
    /// change the data into this instances color model.
    /// </returns>
    ///
    virtual bool canConvertFrom (const ColorModelInterface* colorModel) const;

    /// <summary>
    /// This method asks for the conversion. The <c>canConvertTo</c> method will
    /// be called first to confirm that at a conversion is available.
    /// </summary>
    ///
    /// <param name='colorModel'> A constant instance of a another <c>ColorModelInterface</c>
    /// that is to be converted from.
    /// </param>
    ///
    /// <param name='pConvert'> An instance of a <c>RowProviderInterface</c>
    /// that represents the source of the data to be converted.
    /// </param>
    ///
    /// <returns>
    /// This returns a new filter that has the conversion hooked into it. See the
    /// <c>ImageFilter</c> base class for more information on creating and linking
    /// together filters.
    /// </returns>
    ///
    virtual RowProviderInterface* getModelConversionFrom (
        const ColorModelInterface* colorModel, RowProviderInterface* pConvert) const;

    /// <summary>
    /// Simply returns the number of valid entries in the palette.
    /// </summary>
    ///
    /// <returns>
    /// The integer number of palette entries. 
    /// </returns>
    virtual int numEntries() const;

    // 
    /// <summary>
    /// This method will copy the colors in the palette to the specified array.
    /// </summary>
    ///
    /// <param name='numEntries'> The number of entries to be copied from the palette.
    /// </param>
    ///
    /// <param name='colors'> A pointer to an array of <c>RgbColor</c> instances
    /// with at least <c>nEntries</c> members. The colors will be set to those in the palette.
    /// </param>
    ///
    /// <exception cref="BitonalModelException">An exception will be thrown
    ///  if an invalid palette index is specified. <see cref="ATILException"/>.
    /// </exception>
    ///
    virtual void getEntries(int numEntries, RgbColor* colors) const;

    /// <summary>
    /// The equals operator.
    /// </summary>
    ///
    /// <param name= 'dm'>
    /// A const reference to the <c>DataModel</c> to be tested.
    /// </param>
    ///
    /// <returns>
    /// This method returns true if two DataModel objects are equivalent.
    /// </returns>
    ///
    /// <remarks>
    /// Each internal ZTIL derived <c>DataModel</c> will implement its own operators to 
    /// implement the correct and meaningful comparison.
    /// </remarks>
    ///
    virtual bool operator==(const DataModel& dm) const;

    /// <summary>
    /// The not equals operator.
    /// </summary>
    ///
    /// <param name= 'dm'>
    /// A const reference to the <c>DataModel</c> to be tested.
    /// </param>
    ///
    /// <returns>
    /// This method returns true if two DataModel objects are not equivalent.
    /// </returns>
    ///
    /// <remarks>
    /// Each internal ZTIL derived <c>DataModel</c> will implement its own operators to 
    /// implement the correct and meaningful comparison.
    /// </remarks>
    ///
    virtual bool operator!=(const DataModel& dm) const;

protected:
    /// <summary>
    /// (Protected) The palette of colors used by the datamodel.
    /// </summary>
    ///
    mutable RgbColor maPalette[2];

    /// <summary>
    /// (Protected) The number of entries int he palette.
    /// </summary>
    ///
    int mnEntries;

};

/// <summary>
/// A specialization of the <c>ATILException</c> class for use by <c>BitonalModel</c>
/// </summary>
///
class BitonalModelException : public ZTILException
{
public:
    /// <summary>
    /// This enum uses it's entries to indicate a general reason for the exception.
    /// </summary>
    ///
    enum ExceptionType {
        /// <summary> An invalid palette index was used or referenced.
        /// </summary>
        kInvalidPaletteIndex
    };
public:
    /// <summary>
    /// Constructor for the exception.
    /// </summary>
    ///
    /// <param name='sbMessage'> A message for the developer that may indicate the reason
    /// the exception was thrown. These are untranslated strings not intend for the end-user.
    /// </param>
    ///
    /// <param name='eType'> The enum entry indicating the reason or class of exception.
    /// </param>
    ///
    BitonalModelException(const StringBuffer& sbMessage,
        ExceptionType eType = kInvalidPaletteIndex);

    /// <summary>
    /// Cloning or copy constructor.
    /// </summary>
    ///
    /// <param name='x'> A constant reference to the exception to be copied.
    /// </param>
    ///
    BitonalModelException(const BitonalModelException& x);

    /// <summary>
    /// Virtual destructor.
    /// </summary>
    ///
    virtual ~BitonalModelException();

    /// <summary>
    /// This access method returns the enum entry indicating the reason for the exception.
    /// </summary>
    ///
    /// <returns>
    /// This method returns an entry from the enum of exception types.
    /// </returns>
    ///
    virtual ExceptionType getExceptionType();

private:
    ExceptionType eType;
};

}//namespace

#if  __GNUC__ >= 4
#pragma GCC visibility pop
#endif

#endif
