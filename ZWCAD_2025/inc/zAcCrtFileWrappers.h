
#pragma once
#include "PAL/api/zdef.h"
#include "stdio.h"
#include "zAdCharFmt.h"
#include "zcasuppress.h"
#include <cstdarg>
#include "zacbasedefs.h"

#pragma warning(push)
#pragma warning(disable:4996)

#ifdef ASSERT
#define ZcFILE_Assert ASSERT
#elif defined assert
#define ZcFILE_Assert assert
#elif defined _ASSERTE
#define ZcFILE_Assert _ASSERTE
#else
#define ZcFILE_Assert(T)
#endif

class ZCBASE_PORT ZcFILE {
  public:

    ZcFILE()
        : mpFILE(NULL),
          mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
    {}
    ZcFILE(FILE *pFILE)
        : mpFILE(pFILE),
          mChFmtr(ZdCharFormatter::kAnsi,
                  false,
                  false)
    {}
    ~ZcFILE() {
        ZcFILE_Assert(this->mpFILE == NULL);
    }
    FILE * fopen(const wchar_t *pName, const wchar_t *pMode);
    FILE * fsopen(const wchar_t *pName, const wchar_t *pMode, int shflag);
    void attach(FILE *pFILE);
    FILE * detach();
    int fclose();
    int fputs(const wchar_t *pStr);
    wchar_t * fgets(wchar_t *pBuf, int nChars);
    int fprintf(const wchar_t *pFmtStr, ...);
    int vfprintf(const wchar_t *pFmtStr, va_list va);
    int fscanf(const wchar_t *pFmtStr, ...);
    int fputc(wchar_t c);
    int ungetc(wchar_t c);
    int fgetc();
    bool isOpen() const { return this->mpFILE != NULL; }
    FILE * pFILE() const { return this->mpFILE; }

    unsigned getCharFormat() const { return this->mChFmtr.getFormat(); }
    unsigned setCharFormat(unsigned nFmt) {
            return this->mChFmtr.setFormat(nFmt); }
    bool getUseCIF() const { return this->mChFmtr.getUseCIF(); }
    bool setUseCIF(bool bUseCIF) {
            return this->mChFmtr.setUseCIF(bUseCIF); }
    bool getExpandLF() const { return this->mChFmtr.getExpandLF(); }
    bool setExpandLF(bool bExpandLF) {
            return this->mChFmtr.setExpandLF(bExpandLF); }

    bool readBOM();
    bool writeBOM();

private:
    bool parseAnsiOrCIF(wchar_t &wch);
    bool parseUtf8(wchar_t &wch);
    bool parseUtf16(wchar_t &wch);
    int  fputsWorker(const wchar_t* pSrc, int nOptions);

    FILE *mpFILE;
    ZdCharFormatter mChFmtr;
};

inline void ZcFILE::attach(FILE *pFILE)
{
    ZcFILE_Assert(this->mpFILE == NULL);
    this->mpFILE = pFILE;
}

inline FILE * ZcFILE::detach()
{
    FILE *pRet = this->mpFILE;
    this->mpFILE = NULL;
    return pRet;
}

inline int ZcFILE::fclose()
{
    int nRet = 0;
    if (this->mpFILE != NULL) {
        nRet = ::fclose(this->mpFILE);
        this->mpFILE = NULL;
    }
    return nRet;
}

inline int ZcFILE::fputs(const wchar_t *pStr)
{
    ZcFILE_Assert(this->mpFILE != NULL);
    return fputsWorker(pStr, 0);
}

inline wchar_t * ZcFILE::fgets(wchar_t *pBuf, int nChars)
{
    ZcFILE_Assert(this->mpFILE != NULL);

    ZcFILE_Assert(nChars > 1);

    wchar_t *pSavePtr = pBuf;
    for (;;) {
        if (nChars <= 1)
            break;
        const int ch = this->fgetc();
        if (ch == EOF)
            break;
        ZcFILE_Assert((ch & ~0xffff) == 0);
        ZcFILE_Assert((wchar_t)ch == ch);
        *pSavePtr = (wchar_t)ch;
        pSavePtr++;
        if (ch == '\n')
            break;
        nChars--;
    }
    *pSavePtr = 0;

    if (pSavePtr == pBuf)
        return NULL;

    return pBuf;
}

ZSOFT_DEPRECATED
inline int ZcFILE::fscanf(const wchar_t *pFmtStr, ...)
{
    ZcFILE_Assert(this->mpFILE != NULL);

    pFmtStr = NULL;

    ZcFILE_Assert(false);
    return -1;
}

inline int ZcFILE::fputc(wchar_t c)
{
    ZcFILE_Assert(this->mpFILE != NULL);

    char chBuf[8];
    const unsigned nBytes = this->mChFmtr.wcharToBytes(c, chBuf,
                                                       sizeof(chBuf));
    ZcFILE_Assert(nBytes >= 1);
    ZcFILE_Assert(nBytes <= 8);
    const unsigned nNumWrote = (unsigned)fwrite(chBuf, 1,
                                                nBytes, this->mpFILE);
    if (nNumWrote == nBytes)
        return c;
    else
        return -1;
}

inline int ZcFILE::ungetc(wchar_t c)
{
    ZcFILE_Assert(this->mpFILE != NULL);

    char chBuf[8];
    const unsigned nBytes = this->mChFmtr.wcharToBytes(c, chBuf,
                                                       sizeof(chBuf));
    ZcFILE_Assert(nBytes >= 1);
    ZcFILE_Assert(nBytes <= 8);

    if (nBytes == 1 && ::ungetc(chBuf[0], this->mpFILE) == chBuf[0])
        return c;
    else
        return -1;
}

inline bool ZcFILE::readBOM()
{
    ZcFILE_Assert(this->mpFILE != NULL);
    const long lFilePos = ::ftell(this->mpFILE);
    ZcFILE_Assert(lFilePos == 0L);
    if (lFilePos != 0L)
        return false;

    unsigned short nVal;
    if (::fread(&nVal, 1, 2, this->mpFILE) == 2) {
        if (nVal == 0xfeff) {
            this->setCharFormat(ZdCharFormatter::kUtf16LE);
            return true;
        }
        if (nVal == 0xfffe) {
            this->setCharFormat(ZdCharFormatter::kUtf16BE);
            return true;
        }
        if (nVal == 0xbbef) {
            unsigned char nByte3;
            if (::fread(&nByte3, 1, 1, this->mpFILE) == 1) {
                if (nByte3 == 0xbf) {
                    this->setCharFormat(ZdCharFormatter::kUtf8);
                    return true;
                }
            }
        }
        else if (nVal == 0 || nVal == 0xfeff) {
            unsigned nVal2;
            if (::fread(&nVal2, 1, 2, this->mpFILE) == 2) {
                if (nVal == 0 && nVal2 == 0xfffe) {
                    this->setCharFormat(ZdCharFormatter::kUtf32BE);
                    return true;
                }
                else if (nVal == 0xfeff && nVal2 == 0) {
                    this->setCharFormat(ZdCharFormatter::kUtf32LE);
                    return true;
                }
            }
        }
    }

    ::rewind(this->mpFILE);
    return false;
}

inline bool ZcFILE::writeBOM()
{
    ZcFILE_Assert(this->mpFILE != NULL);
    if (this->mpFILE == NULL)
        return false;

    const long lFilePos = ::ftell(this->mpFILE);
    ZcFILE_Assert(lFilePos == 0L);
    if (lFilePos != 0L)
        return false;

    unsigned nBom = 0;
    const int cbBomSize = ZdCharFormatter::getBOM(nBom,
                                this->getCharFormat());
    if (cbBomSize == 0)
        return false;

    const int cbWritten = (int) ::fwrite(&nBom,
                                         1,
                                         cbBomSize,
                                         this->mpFILE);

    ZcFILE_Assert(cbWritten == cbBomSize);
    if (cbWritten != cbBomSize)
    {
        ::rewind(this->mpFILE);
        return false;
    }

    return true;
}

inline bool ZcFILE::parseUtf16(wchar_t &wch)
{
    wchar_t wchLocal = 0;
    int nBytesRead = (int) ::fread(&wchLocal, 1, 2, this->mpFILE);
    if (nBytesRead <= 0)
        return false;

    const unsigned nFormat = this->mChFmtr.getFormat();
    if (nFormat == ZdCharFormatter::kUtf16BE)
        wchLocal = (wchLocal >> 8) | (wchLocal << 8);

    wch = wchLocal;
    if (wchLocal == L'\r' && mChFmtr.getExpandLF()) {
        wchar_t wchNewLine = L'\n';
        nBytesRead = (int) ::fread(&wchNewLine, 1, 2, this->mpFILE);
        if (nBytesRead <= 0)
            return true;

        if (nFormat == ZdCharFormatter::kUtf16BE)
            wchNewLine = (wchNewLine >> 8) | (wchNewLine << 8);
        if (wchNewLine != L'\n') {
            ::fseek(this->mpFILE, -2L, SEEK_CUR);
            return true;
        }
        wch = L'\n';
    }

    return true;
}

inline int ZcFILE::fputsWorker(const wchar_t* pSrc, int nOptions)
{
    ZcFILE_Assert(this->mpFILE != NULL);
    ZcFILE_Assert(pSrc != NULL);

    int nNumInput = 0;
    for (;;) {
        const wchar_t wch = *pSrc;
        if (wch == 0)
            break;
        char chBuf[8];
        const unsigned nBytes = this->mChFmtr.wcharToBytes(wch, chBuf,
                                                           sizeof(chBuf));
        ZcFILE_Assert(nBytes >= 1);
        ZcFILE_Assert(nBytes <= 8);
        const unsigned nNumWrote = (unsigned)fwrite(chBuf, 1,
                                                    nBytes, this->mpFILE);
        if (nNumWrote != nBytes)
            return -1;
        nNumInput++;
        pSrc++;
    }

    if (nOptions == 0)
        return 0;
    else if (nOptions == 1)
        return nNumInput;
    else {
        ZcFILE_Assert(false);
    }

    return -1;
}

#pragma warning(pop)

