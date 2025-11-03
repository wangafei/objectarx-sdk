/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef STRINGBUFFER_H
#include "StringBuffer.h"
#endif

#ifndef GTILEXCEPTION_H
#define GTILEXCEPTION_H

namespace Gtil
{
  class GTIL_EXPORT GTILException
  {
  public:
    GTILException(const StringBuffer& sbMessage);
    GTILException();
    GTILException(const GTILException& x);
    virtual ~GTILException();

    virtual const StringBuffer* getMessage();

  protected:
    StringBuffer msbMessage;
  };
}

#endif
