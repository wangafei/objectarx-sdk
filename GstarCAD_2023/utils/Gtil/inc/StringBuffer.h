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
#define STRINGBUFFER_H

namespace Gtil
{
  class GTIL_EXPORT StringBuffer
  {
  public:
    enum CharacterType
    {
      kASCII,
      kUTF_8,
      kUTF_16,
      kUTF_32,
      kMBCS
    };

    static int bytesInString(const Byte* pString, CharacterType type);

    static void convertString(const StringBuffer& sbString, StringBuffer& sbResult, CharacterType type);

    static CharacterType defaultCharacterType();

  public:
    StringBuffer();
    StringBuffer(int nNumBytes, CharacterType type = StringBuffer::kASCII);
    StringBuffer(int nNumBytes, const Byte* pBytes, CharacterType type = StringBuffer::kASCII);
    StringBuffer(const StringBuffer& x);
    virtual ~StringBuffer();

    virtual const Byte* data() const;

    virtual int numDataBytes() const;

    virtual CharacterType type() const;

    virtual StringBuffer& set(const StringBuffer& string);
    virtual StringBuffer& set(int numBytes, const Byte* pChar, CharacterType type = StringBuffer::kASCII);

    virtual bool isZero() const;

    StringBuffer& operator=(const StringBuffer& rhs);

    bool operator==(const StringBuffer& rhs) const;
    bool operator!=(const StringBuffer& rhs) const;

    operator const char_t*() const;
  private:
    int mNumBytes;
    Byte* mpData;
    CharacterType  meCharType;
  };
}

#endif
