
#pragma once

#ifdef ASSERT
#define ZcFStream_Assert ASSERT
#elif defined assert
#define ZcFStream_Assert assert
#else
#define ZcFStream_Assert(T)
#endif

class ZcIfstream : public std::wifstream {
public:
    ZcIfstream() {};
    ZcIfstream(const wchar_t *pName);

    void open(const wchar_t *pName);
    void open(const wchar_t *pName, ios_base::openmode nMode);
};

class ZcOfstream : public std::wofstream {
public:
    ZcOfstream() {};
    ZcOfstream(const wchar_t *pName);

    void open(const wchar_t *pName);
    void open(const wchar_t *pName, ios_base::openmode nMode);
};

inline ZcIfstream::ZcIfstream(const wchar_t *pName)
{
    this->open(pName);
}

inline ZcOfstream::ZcOfstream(const wchar_t *pName)
{
    this->open(pName);
}

inline const std::locale& ZcFStream_curLocale()
{

    static const std::locale loc(std::locale(), std::locale::classic(), LC_NUMERIC);
    return loc;
}

inline void ZcIfstream::open(const wchar_t *pName)
{
#ifndef  _ZSOFT_MAC_
    this->std::wifstream::open(pName);
    this->imbue(ZcFStream_curLocale());
#else
    STUB_WARNING(ZcIfstream::open);
#endif
}

inline void ZcIfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
#ifndef  _ZSOFT_MAC_
    this->std::wifstream::open(pName, nMode);
    this->imbue(ZcFStream_curLocale());
#else
     STUB_WARNING(ZcIfstream::open);
#endif
}

inline void ZcOfstream::open(const wchar_t *pName)
{
#ifndef  _ZSOFT_MAC_
    this->std::wofstream::open(pName);
    this->imbue(ZcFStream_curLocale());
#else
    STUB_WARNING(ZcOfstream::open);
#endif
}

inline void ZcOfstream::open(const wchar_t *pName, ios_base::openmode nMode)
{
#ifndef  _ZSOFT_MAC_
    this->std::wofstream::open(pName, nMode);
    this->imbue(ZcFStream_curLocale());
#else
    STUB_WARNING(ZcOfstream::open);
#endif
}

