/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FORMATCODECPROPERTYINTERFACE_H
#include "FormatCodecPropertyInterface.h"
#endif
#ifndef STRINGBUFFER_H
#include "StringBuffer.h"
#endif

#ifndef FORMATCODECSTRINGPROPERTY_H
#define FORMATCODECSTRINGPROPERTY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecStringProperty : public FormatCodecPropertyInterface
  {
  public:
    enum StringType
    {
      kSingleLine,
      kMultiLine
    };

    virtual ~FormatCodecStringProperty();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual void getDefaultValue(StringBuffer& sbDefault);
    virtual void getValue(StringBuffer& sbValue) const;
    virtual bool setValue(const StringBuffer& sbValue);

    virtual int maximumStringBytes() const;

    virtual StringType getStringType() const;

  protected:
    FormatCodecStringProperty(const StringBuffer& sbDefault, int nMaximumBytes);

  protected:
    StringBuffer msbDefault;
    StringBuffer msbValue;
    int          mnMaximumBytes;
    StringType   mStringType;
  };
}

#endif
