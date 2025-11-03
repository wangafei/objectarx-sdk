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

#ifndef FORMATCODECDENSITY_H
#define FORMATCODECDENSITY_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecDensity : public FormatCodecPropertyInterface
  {
  public:
    enum Mode
    {
      kIntegralUnified,
      kIntegralDifferential,
      kDoubleUnified,
      kDoubleDifferential
    };

    enum Units
    {
      kNone,
      kCentimeters,
      kInches
    };

  public:
    FormatCodecDensity(const double& dXDefault, const double& dYDefault, Units units);
    virtual ~FormatCodecDensity();

    virtual FormatCodecPropertyInterface* clone() const = 0;

    virtual void getDefaultValue(double& dXDefault, double& dYDefault) const;
    virtual bool setValues(double dXDensity, double dYDensity);
    virtual void getValues(double& dXDensity, double& dYDensity) const;

    virtual void getDefaultUnits(Units& units) const;
    virtual void getUnits(Units& units) const;
    virtual bool setUnits(Units units);

    virtual Mode getCapabilty() const = 0;

  protected:
    double mdXDefault;
    double mdYDefault;
    double mdXDensity;
    double mdYDensity;
    Units  mDefaultUnits;
    Units  mUnits;
  };
}

#endif
