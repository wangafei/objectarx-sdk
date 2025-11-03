/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#ifdef ASSERT
  #define GcFStream_Assert ASSERT
#elif defined assert
  #define GcFStream_Assert assert
#else
  #define GcFStream_Assert(T)
#endif

class GcIfstream : public std::wifstream {
public:
  GcIfstream() {};
  GcIfstream(const wchar_t *pName);

  void open(const wchar_t *pName);
  void open(const wchar_t *pName, ios_base::openmode nMode);
};

class GcOfstream : public std::wofstream {
public:
  GcOfstream() {};
  GcOfstream(const wchar_t *pName);

  void open(const wchar_t *pName);
  void open(const wchar_t *pName, ios_base::openmode nMode);
};

inline GcIfstream::GcIfstream(const wchar_t *pName)
{
  this->open(pName);
}

inline GcOfstream::GcOfstream(const wchar_t *pName)
{
  this->open(pName);
}

inline const std::locale& GcFStream_curLocale()
{
  static const std::locale loc(std::locale(), std::locale::classic(), LC_NUMERIC);
  return loc;
}

inline void GcIfstream::open(const wchar_t *pName)
{
#ifndef  _GSOFT_MAC_
  this->std::wifstream::open(pName);
  this->imbue(GcFStream_curLocale());
#else
  STUB_WARNING(GcIfstream::open);
#endif
}

inline void GcIfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
#ifndef  _GSOFT_MAC_
  this->std::wifstream::open(pName, nMode);
  this->imbue(GcFStream_curLocale());
#else
  STUB_WARNING(GcIfstream::open);
#endif
}

inline void GcOfstream::open(const wchar_t *pName)
{
#ifndef  _GSOFT_MAC_
  this->std::wofstream::open(pName);
  this->imbue(GcFStream_curLocale());
#else
  STUB_WARNING(GcOfstream::open);
#endif
}

inline void GcOfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
#ifndef  _GSOFT_MAC_
  this->std::wofstream::open(pName, nMode);
  this->imbue(GcFStream_curLocale());
#else
  STUB_WARNING(GcOfstream::open);
#endif
}