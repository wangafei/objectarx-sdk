/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef STRINGBUFFER_H
#include "StringBuffer.h"
#endif

#ifndef FORMATCODECPROPERTYINTERFACE_H
#define FORMATCODECPROPERTYINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecPropertyInterface
  {
  public:
    enum PropertyIdentifier
    {
      kIdCustom = 0,
      kSimpleType,
      kCompression,
      kDensity,
      kDataOrganization,
      kAssociation,
      kTransparency,
      kCorrelation,
      kColor,
      kMultispectralReferenceName,
      kMultispectralBandName,
      kMultispectralBucket,
      kLatLon,
      kPoint,
      kSampleFormat,
      kVoidData,
      kCorrelationSet,
      kChannelOrder
    };

    enum PropertyDataType
    {
      kCustom = 0,
      kVoid,
      kBoolean,
      kInteger,
      kDouble,
      kString,
      kInclusiveSet,
      kExclusiveSet,
      kDate,
      kClass
    };

    enum PropertyUsage
    {
      kUsageUnknown,
      kReadOnly,
      kReadWrite,
      kWriteOnly
    };

    enum PropertyLevel
    {
      kLevelUnknown,
      kLevelFrame,
      kLevelAssociation,
      kLevelFile
    };

    virtual ~FormatCodecPropertyInterface();

    virtual FormatCodecPropertyInterface* clone() const = 0;

    virtual PropertyIdentifier getIdentifier() const;

    virtual PropertyDataType getDataType() const;

    virtual bool isRequired() const;
    virtual bool isContextSensitive() const;

    virtual const StringBuffer& getDescription() const;
    virtual const StringBuffer& getName() const;
    virtual PropertyUsage getUsage() const;
    virtual PropertyLevel getLevel() const;

  protected:
    FormatCodecPropertyInterface();
    FormatCodecPropertyInterface(const FormatCodecPropertyInterface& from);

    PropertyIdentifier mId;
    PropertyDataType   mType;
    bool               mbRequired;
    bool               mbContextSensitive;
    StringBuffer       msbName;
    StringBuffer       msbDescription;
    PropertyUsage      mUsage;
    PropertyLevel      mLevel;

    FormatCodecPropertyInterface& operator= (const FormatCodecPropertyInterface& from);
  private:
  };
}

#endif
