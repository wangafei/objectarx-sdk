

#ifndef ZC_GELIBVERSION_H
#define ZC_GELIBVERSION_H

#include "zadesk.h"
#include "zgedll.h"
#pragma pack (push, 8)

#define IMAGE_MAJOR_VER          2
#define IMAGE_MINOR_VER          0
#define IMAGE_CORRECTIVE_VER     0
#define IMAGE_INTERNAL_VER       0

class 
ZcGeLibVersion {
public:

    GE_DLLEXPIMPORT ZcGeLibVersion();
    GE_DLLEXPIMPORT ZcGeLibVersion(const ZcGeLibVersion&);
    GE_DLLEXPIMPORT ZcGeLibVersion(ZSoft::UInt8 major, ZSoft::UInt8 minor,
                   ZSoft::UInt8 corrective,
                   ZSoft::UInt8 internal_version);

    GE_DLLEXPIMPORT ZSoft::UInt8     majorVersion        () const;
    GE_DLLEXPIMPORT ZSoft::UInt8     minorVersion        () const;
    GE_DLLEXPIMPORT ZSoft::UInt8     correctiveVersion   () const;
    GE_DLLEXPIMPORT ZSoft::UInt8     schemaVersion       () const;

    GE_DLLEXPIMPORT ZcGeLibVersion&     setMajorVersion        (ZSoft::UInt8 val);
    GE_DLLEXPIMPORT ZcGeLibVersion&     setMinorVersion        (ZSoft::UInt8 val);
    GE_DLLEXPIMPORT ZcGeLibVersion&     setCorrectiveVersion   (ZSoft::UInt8 val);
    GE_DLLEXPIMPORT ZcGeLibVersion&     setSchemaVersion       (ZSoft::UInt8 val);

    GE_DLLEXPIMPORT ZSoft::Boolean operator ==      (const ZcGeLibVersion&) const; 
    GE_DLLEXPIMPORT ZSoft::Boolean operator !=      (const ZcGeLibVersion&) const; 
    GE_DLLEXPIMPORT ZSoft::Boolean operator <       (const ZcGeLibVersion&) const; 
    GE_DLLEXPIMPORT ZSoft::Boolean operator <=      (const ZcGeLibVersion&) const; 
    GE_DLLEXPIMPORT ZSoft::Boolean operator >       (const ZcGeLibVersion&) const; 
    GE_DLLEXPIMPORT ZSoft::Boolean operator >=      (const ZcGeLibVersion&) const;

	GE_DLLDATAEXIMP static const ZcGeLibVersion kRelease0_95;

    GE_DLLDATAEXIMP static const ZcGeLibVersion kReleaseSed;

    GE_DLLDATAEXIMP static const ZcGeLibVersion kReleaseTah;

private:
    ZSoft::UInt8   mVersion[10];
};

#pragma pack (pop)
#endif
