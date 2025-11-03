/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef FORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H
#include "FormatCodecInclusivePropertySetInterface.h"
#endif

#ifndef FORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H
#define FORMATCODECEXCLUSIVEPROPERTYSETINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecExclusivePropertySetInterface : public FormatCodecInclusivePropertySetInterface
  {
  public:
    virtual ~FormatCodecExclusivePropertySetInterface();

    virtual int  getDefaultPropertyIndex() const;
    virtual int  getSelectedIndex() const;
    virtual void setSelectedIndex(int nSelectionIndex);

  protected:
    FormatCodecExclusivePropertySetInterface();
    FormatCodecExclusivePropertySetInterface(int nNumProperties);
    FormatCodecExclusivePropertySetInterface(const FormatCodecExclusivePropertySetInterface& from);

    int mnDefaultPropertyIndex;
    int mnSelectedIndex;
  private:
    FormatCodecExclusivePropertySetInterface& operator= (const FormatCodecExclusivePropertySetInterface& from);
  };
}

#endif
