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

#ifndef FORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H
#define FORMATCODECINCLUSIVEPROPERTYSETINTERFACE_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecInclusivePropertySetInterface : public FormatCodecPropertyInterface
  {
  public:
    virtual ~FormatCodecInclusivePropertySetInterface();

    virtual int getNumProperties() const;

    virtual FormatCodecPropertyInterface* getProperty(int nIndex) const;

  protected:
    FormatCodecInclusivePropertySetInterface(const FormatCodecInclusivePropertySetInterface& iter);
    FormatCodecInclusivePropertySetInterface();
    FormatCodecInclusivePropertySetInterface(int nNumToAlloc);

    void setProperty(int nIndex, FormatCodecPropertyInterface* pProperty);
    void appendProperty(FormatCodecPropertyInterface* pProperty);

    FormatCodecPropertyInterface** mppProperties;

    int mnNumProperties;
    int mnArraySize;
  private:
    FormatCodecInclusivePropertySetInterface& operator= (const FormatCodecInclusivePropertySetInterface& from);
  };
}

#endif
