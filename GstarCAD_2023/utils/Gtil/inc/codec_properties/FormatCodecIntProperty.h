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

#ifndef FORMATCODECINTPROPERTY_H
#define FORMATCODECINTPROPERTY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecIntProperty : public FormatCodecPropertyInterface
  {
  public:
    virtual ~FormatCodecIntProperty();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual void getDefaultValue(int& defaultValue);
    virtual int  getValue() const;
    virtual bool setValue(int value);

    virtual void getPropertyLimits(int& nMinimum, int& nMaximum) const;

  protected:
    FormatCodecIntProperty(int nMinValue, int nMaxValue, int nDefaultValue);

  protected:
    int mnValue;
    int mnDefaultValue;
    int mnMaxValue;
    int mnMinValue;
  };
}

#endif
