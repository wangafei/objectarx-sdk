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

#ifndef FILESPECIFIER_H
#define FILESPECIFIER_H

namespace Gtil
{
  class GTIL_EXPORT FileSpecifier
  {
  public:
    enum Type
    {
      kFilePath,
      kOther,
      kStorageProtocol
    };

  public:
    FileSpecifier();
    FileSpecifier(const StringBuffer& sbString, Type type);
    FileSpecifier(const FileSpecifier& x);
    virtual ~FileSpecifier();

    virtual FileSpecifier::Type type() const;

    virtual const StringBuffer& string() const;

    virtual const FileSpecifier& operator= (const FileSpecifier& rhs);

    virtual bool operator== (const FileSpecifier& rhs);
    virtual bool operator!= (const FileSpecifier& rhs);

    virtual void set(const StringBuffer& sbString, Type type);

  private:
    StringBuffer msbString;
    FileSpecifier::Type mType;
  };
}

#endif
