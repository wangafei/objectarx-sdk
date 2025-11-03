/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef _HALF_H_
#define _HALF_H_

#include <iostream>

class GTIL_EXPORT half
{
public:
  half();
  half(float f);

  operator float() const;

  half    operator - () const;

  half &    operator = (half  h);
  half &    operator = (float f);

  half &    operator += (half  h);
  half &    operator += (float f);

  half &    operator -= (half  h);
  half &    operator -= (float f);

  half &    operator *= (half  h);
  half &    operator *= (float f);

  half &    operator /= (half  h);
  half &    operator /= (float f);

  half    round(unsigned int n) const;

  bool    isFinite() const;
  bool    isNormalized() const;
  bool    isDenormalized() const;
  bool    isZero() const;
  bool    isNan() const;
  bool    isInfinity() const;
  bool    isNegative() const;

  static half    posInf();
  static half    negInf();
  static half    qNan();
  static half    sNan();

  unsigned short  bits() const;
  void    setBits(unsigned short bits);

public:
  union uif
  {
    unsigned int  i;
    float    f;
  };

private:
  static short  convert(int i);
  static float  overflow();

  unsigned short  _h;

#ifndef OPENEXR_DLL
  static const uif            _toFloat[1 << 16];
  static const unsigned short _eLut[1 << 9];
#endif
};

#if defined(OPENEXR_DLL)
#if defined(HALF_EXPORTS)
extern __declspec(dllexport) half::uif       _toFloat[1 << 16];
extern __declspec(dllexport) unsigned short  _eLut[1 << 9];
#else
extern __declspec(dllimport) half::uif       _toFloat[1 << 16];
extern __declspec(dllimport) unsigned short  _eLut[1 << 9];
#endif
#endif

std::ostream &    operator << (std::ostream &os, half  h);
std::istream &    operator >> (std::istream &is, half &h);

void      printBits(std::ostream &os, half  h);
void      printBits(std::ostream &os, float f);
void      printBits(char  c[19], half  h);
void      printBits(char  c[35], float f);

#if (defined _WIN32 || defined _WIN64) && defined _MSC_VER

#define HALF_MIN      5.96046448e-08f
#define HALF_NRM_MIN  6.10351562e-05f
#define HALF_MAX      65504.0f
#define HALF_EPSILON  0.00097656f
#else

#define HALF_MIN      5.96046448e-08
#define HALF_NRM_MIN  6.10351562e-05
#define HALF_MAX      65504.0
#define HALF_EPSILON  0.00097656

#endif

#define HALF_MANT_DIG    11
#define HALF_DIG         2
#define HALF_RADIX       2
#define HALF_MIN_EXP     -13
#define HALF_MAX_EXP     16
#define HALF_MIN_10_EXP  -4
#define HALF_MAX_10_EXP  4

inline half::half()
{
}

inline half::half(float f)
{
  uif x;
  x.f = f;

  if (f == 0)
  {
    _h = (x.i >> 16);
  }
  else
  {
    register int e = (x.i >> 23) & 0x000001ff;
    e = _eLut[e];

    if (e)
    {
      register int m = x.i & 0x007fffff;
      _h = (unsigned short)(e + ((m + 0x00000fff + ((m >> 13) & 1)) >> 13));
    }
    else
    {
      _h = convert(x.i);
    }
  }
}

inline half::operator float() const
{
  return _toFloat[_h].f;
}

inline half half::round(unsigned int n) const
{
  if (n >= 10)
    return *this;

  unsigned short s = _h & 0x8000;
  unsigned short e = _h & 0x7fff;

  e >>= 9 - n;
  e += e & 1;
  e <<= 9 - n;

  if (e >= 0x7c00)
  {
    e = _h;
    e >>= 10 - n;
    e <<= 10 - n;
  }

  half h;
  h._h = s | e;
  return h;
}

inline half half::operator - () const
{
  half h;
  h._h = _h ^ 0x8000;
  return h;
}

inline half & half::operator = (half h)
{
  _h = h._h;
  return *this;
}

inline half & half::operator = (float f)
{
  *this = half(f);
  return *this;
}

inline half & half::operator += (half h)
{
  *this = half(float(*this) + float(h));
  return *this;
}

inline half & half::operator += (float f)
{
  *this = half(float(*this) + f);
  return *this;
}

inline half & half::operator -= (half h)
{
  *this = half(float(*this) - float(h));
  return *this;
}

inline half & half::operator -= (float f)
{
  *this = half(float(*this) - f);
  return *this;
}

inline half & half::operator *= (half h)
{
  *this = half(float(*this) * float(h));
  return *this;
}

inline half & half::operator *= (float f)
{
  *this = half(float(*this) * f);
  return *this;
}

inline half & half::operator /= (half h)
{
  *this = half(float(*this) / float(h));
  return *this;
}

inline half & half::operator /= (float f)
{
  *this = half(float(*this) / f);
  return *this;
}

inline bool half::isFinite() const
{
  unsigned short e = (_h >> 10) & 0x001f;
  return e < 31;
}

inline bool half::isNormalized() const
{
  unsigned short e = (_h >> 10) & 0x001f;
  return e > 0 && e < 31;
}

inline bool half::isDenormalized() const
{
  unsigned short e = (_h >> 10) & 0x001f;
  unsigned short m = _h & 0x3ff;
  return e == 0 && m != 0;
}

inline bool half::isZero() const
{
  return (_h & 0x7fff) == 0;
}

inline bool half::isNan() const
{
  unsigned short e = (_h >> 10) & 0x001f;
  unsigned short m = _h & 0x3ff;
  return e == 31 && m != 0;
}

inline bool half::isInfinity() const
{
  unsigned short e = (_h >> 10) & 0x001f;
  unsigned short m = _h & 0x3ff;
  return e == 31 && m == 0;
}

inline bool half::isNegative() const
{
  return (_h & 0x8000) != 0;
}

inline half half::posInf()
{
  half h;
  h._h = 0x7c00;
  return h;
}

inline half half::negInf()
{
  half h;
  h._h = 0xfc00;
  return h;
}

inline half half::qNan()
{
  half h;
  h._h = 0x7fff;
  return h;
}

inline half half::sNan()
{
  half h;
  h._h = 0x7dff;
  return h;
}

inline unsigned short half::bits() const
{
  return _h;
}

inline void half::setBits(unsigned short bits)
{
  _h = bits;
}

#undef HALF_EXPORT_CONST

#endif
