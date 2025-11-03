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

#ifndef FORMATCODECPROPERTYSETITERATOR_H
#define FORMATCODECPROPERTYSETITERATOR_H

namespace Gtil
{
  class GTIL_EXPORT FormatCodecPropertySetIterator
  {
  public:
    virtual ~FormatCodecPropertySetIterator();

    virtual void start();
    virtual void step();

    virtual bool endOfList();

    virtual int numProperties();
    virtual FormatCodecPropertyInterface* openProperty();
    virtual FormatCodecPropertyInterface* openProperty(FormatCodecPropertyInterface::PropertyIdentifier identifier);
    virtual void closeProperty();

  protected:
    FormatCodecPropertySetIterator(const FormatCodecPropertySetIterator& iter);
    FormatCodecPropertySetIterator();
    FormatCodecPropertySetIterator(int nNumToAlloc);

    void setProperty(int nIndex, const FormatCodecPropertyInterface* pProperty);
    void appendProperty(const FormatCodecPropertyInterface* pProperty);

    FormatCodecPropertyInterface** mppProperties;
    int mnNumProperties;
    int mnArraySize;
    int mnIndex;

  private:
    FormatCodecPropertySetIterator& operator= (const FormatCodecPropertySetIterator& from);
  };
}

#endif
