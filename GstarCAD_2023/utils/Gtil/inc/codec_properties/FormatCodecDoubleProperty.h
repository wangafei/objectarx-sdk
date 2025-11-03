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

#ifndef FORMATCODECDOUBLEPROPERTY_H
#define FORMATCODECDOUBLEPROPERTY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecDoubleProperty : public FormatCodecPropertyInterface
  {
  public:
    virtual ~FormatCodecDoubleProperty();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual void getDefaultValue(double& dDefault) const;
    virtual bool setValue(const double& dValue);
    virtual void getValue(double& dValue) const;
    virtual void getPropertyLimits(double& dMinimum, double& dMaximum) const;

  protected:
    FormatCodecDoubleProperty(const double& dMin, const double& dMax, const double& dDefault);
  protected:
    double mdDefault;
    double mdMax;
    double mdMin;
    double mdValue;
  };
}

#endif
