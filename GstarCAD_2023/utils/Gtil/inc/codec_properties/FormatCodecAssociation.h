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

#ifndef FORMATCODECASSOCIATION_H
#define FORMATCODECASSOCIATION_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecAssociation : public FormatCodecPropertyInterface
  {
  public:
    enum AssociationType
    {
      kThumbnail,
      kPage,
      kTransparencyMask,
      kOther,
      kDisplayAbove,
      kSpatialLink
    };

  public:
    virtual ~FormatCodecAssociation();

    virtual FormatCodecPropertyInterface* clone() const;

    virtual AssociationType getType() const;

    virtual void setType(AssociationType type);

    virtual int associatedTo() const;

    virtual void setAssociatedFrameIndex(int nFrameIndex);

  protected:
    FormatCodecAssociation(AssociationType type, int nFrameIndex);

  protected:
    AssociationType mAType;

    int mnFrameIndex;
  };
}

#endif
