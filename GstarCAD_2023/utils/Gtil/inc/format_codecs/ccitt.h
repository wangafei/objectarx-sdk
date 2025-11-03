/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif

#ifndef CCITT_H
#define CCITT_H

struct CCITT
{
  enum FillOrder
  {
    kLsb2Msb,
    kMsb2Lsb
  };
  enum EncodeMethod
  {
    kG3_RLE,
    kG3_1D,
    kG3_2d,
    kG4
  };

  enum EncodeFlags
  {
    kNone             = 0,
    kEOLFillBits      = 0x0001,
    kFaxModeByteAlign = 0x0010,
    kFaxModeWordAlign = 0x0110,
    kFaxModeNORTC     = 0x0100,
    kFaxModeNoEOL     = 0x1000
  };
};

namespace Gtil { class DataStreamInterface; }

class GTIL_EXPORT CCITTDecoder
{
public:
  static CCITTDecoder* construct();
public:
  virtual ~CCITTDecoder();

  virtual void setupDecoder(CCITT::EncodeMethod encoding,
                            CCITT::FillOrder bitOrder,
                            unsigned int nEncodeFlags,
                            int nRowWidth) = 0;
  virtual void decodeBlock(unsigned char* pIn, int nInBytes, unsigned char* pOut, int nOutBytes) = 0;
  virtual void decodeByRow(Gtil::DataStreamInterface* pStream) = 0;
  virtual bool decodeRow(unsigned char * pRow, int nRowBytes) = 0;
};

class GTIL_EXPORT CCITTEncoder
{
public:
  static CCITTEncoder* construct();
public:
  virtual ~CCITTEncoder();

  virtual void setupEncoder(CCITT::EncodeMethod encoding,
                            CCITT::FillOrder bitOrder,
                            CCITT::EncodeFlags options,
                            int nRowWidth) = 0;
  virtual bool encodeBlock(unsigned char* pIn,
                           int nInBytes,
                           unsigned char* pOut,
                           int nOutBytes,
                           int& nEncodedBytes) = 0;
  virtual void encodeByRow(unsigned char* pOut, int nOutBytes) = 0;
  virtual void resetOutputPointer() = 0;
  virtual bool encodeRow(unsigned char * pRow, int nRowBytes, int& nEncodedBytes) = 0;
  virtual void endEncodingRows(int& nEncodedBytes) = 0;
};

#endif
