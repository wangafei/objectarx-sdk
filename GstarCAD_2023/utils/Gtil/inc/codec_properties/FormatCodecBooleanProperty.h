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

#ifndef FORMATCODECBOOLEANPROPERTY_H
#define FORMATCODECBOOLEANPROPERTY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecBooleanProperty : public FormatCodecPropertyInterface
  {
  public:
    FormatCodecBooleanProperty(bool bDefault);
    virtual ~FormatCodecBooleanProperty();

    virtual FormatCodecPropertyInterface* clone() const;

    bool getDefaultValue(bool& bDefault) const;

    void setValue(bool bState);
    void getValue(bool& bState) const;

  protected:
    bool mbDefault;
    bool mbValue;
  };
}

#endif
