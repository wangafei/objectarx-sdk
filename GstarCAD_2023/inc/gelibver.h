/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_GELIBVERSION_H
#define GC_GELIBVERSION_H

#include "gsoft.h"
#include "gedll.h"
#pragma pack (push, 8)

#define IMAGE_MAJOR_VER          2
#define IMAGE_MINOR_VER          0
#define IMAGE_CORRECTIVE_VER     0
#define IMAGE_INTERNAL_VER       0

class GE_DLLDATAEXIMP GcGeLibVersion
{
public:
  GcGeLibVersion();
  GcGeLibVersion(const GcGeLibVersion&);
  GcGeLibVersion(Gsoft::UInt8 major,
                                 Gsoft::UInt8 minor,
                                 Gsoft::UInt8 corrective,
                                 Gsoft::UInt8 internal_version);

  Gsoft::UInt8     majorVersion() const;
  Gsoft::UInt8     minorVersion() const;
  Gsoft::UInt8     correctiveVersion() const;
  Gsoft::UInt8     schemaVersion() const;

  GcGeLibVersion&     setMajorVersion(Gsoft::UInt8 val);
  GcGeLibVersion&     setMinorVersion(Gsoft::UInt8 val);
  GcGeLibVersion&     setCorrectiveVersion(Gsoft::UInt8 val);
  GcGeLibVersion&     setSchemaVersion(Gsoft::UInt8 val);

  Gsoft::Boolean operator ==      (const GcGeLibVersion&) const;
  Gsoft::Boolean operator !=      (const GcGeLibVersion&) const;
  Gsoft::Boolean operator <       (const GcGeLibVersion&) const;
  Gsoft::Boolean operator <=      (const GcGeLibVersion&) const;
  Gsoft::Boolean operator >       (const GcGeLibVersion&) const;
  Gsoft::Boolean operator >=      (const GcGeLibVersion&) const;

  static const GcGeLibVersion kRelease0_95;
  static const GcGeLibVersion kReleaseSed;
  static const GcGeLibVersion kReleaseTah;
private:
  Gsoft::UInt8   mVersion[10];
};

#pragma pack (pop)
#endif
