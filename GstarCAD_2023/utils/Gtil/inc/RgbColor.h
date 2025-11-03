/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef DATAMODELATTRIBUTES_H
#include "DataModelAttributes.h"
#endif

#ifndef RGBCOLOR_H
#define RGBCOLOR_H

namespace Gtil
{
  struct GTIL_EXPORT RgbColor
  {
  public:
    RgbColor();
    RgbColor(Data32 color);
    RgbColor(Data8 red, Data8 green, Data8 blue);
    RgbColor(Data8 first, Data8 second, Data8 third, Data8 alpha);

    const RgbColor& set(Data8 red, Data8 green, Data8 blue);
    const RgbColor& set(Data8 red,
                        Data8 green,
                        Data8 blue,
                        Data8 alpha,
                        DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kRedGreenBlueAlpha);

    Data8 asGray(DataModelAttributes::ChannelOrder format = DataModelAttributes::kRedGreenBlueAlpha) const;

    union
    {
      struct
      {
        Data8 red;
        Data8 green;
        Data8 blue;
        Data8 alpha;
      } rgba;

      struct
      {
        Data8 blue;
        Data8 green;
        Data8 red;
        Data8 alpha;
      } bgra;

      Data32 packed;
    };

    const RgbColor& operator=(const RgbColor& rhs);
    const RgbColor& operator=(Data32 rhs);

    operator Data32() const;

    bool operator==(const RgbColor& rhs) const;
    bool operator==(Data32 rhs) const;
    bool operator!=(const RgbColor& rhs) const;
    bool operator!=(Data32 rhs) const;
  };

  struct GTIL_EXPORT RgbColor5b
  {
  public:
    enum Fields
    {
      k5551,
      k565,
    };

  public:
    RgbColor5b();
    RgbColor5b(Data16 color);
    RgbColor5b(Data8 red, Data8 green, Data8 blue);
    RgbColor5b(Data8 first,
               Data8 second,
               Data8 third,
               Data8 alpha,
               DataModelAttributes::BitFields fields = DataModelAttributes::k5551);

    const RgbColor5b& set(Data8 red, Data8 green, Data8 blue);
    const RgbColor5b& set(Data8 red,
                          Data8 green,
                          Data8 blue,
                          Data8 alpha,
                          DataModelAttributes::BitFields fields = DataModelAttributes::k5551,
                          DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha);

    void getChannelData(Data8& red,
                        Data8& green,
                        Data8& blue,
                        Data8& alpha,
                        DataModelAttributes::BitFields fields, DataModelAttributes::ChannelOrder fmt) const;

    RgbColor asRgbColor(DataModelAttributes::BitFields fields, DataModelAttributes::ChannelOrder fmt) const;
    RgbColor asBgrColor(DataModelAttributes::BitFields fields, DataModelAttributes::ChannelOrder fmt) const;

    Data8 asGray(DataModelAttributes::BitFields fields,
                 DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    Data16 packed;

    const RgbColor5b& operator=(const RgbColor5b& rhs);
    const RgbColor5b& operator=(Data16 rhs);

    operator Data16() const;

    bool operator==(const RgbColor5b& rhs) const;
    bool operator==(Data16 rhs) const;
    bool operator!=(const RgbColor5b& rhs) const;
    bool operator!=(Data16 rhs) const;
  };

  struct GTIL_EXPORT RgbColor10
  {
  public:
    RgbColor10();
    RgbColor10(Data32 color);
    RgbColor10(Data16 red, Data16 green, Data16 blue);
    RgbColor10(Data16 first, Data16 second, Data16 third, Data16 alpha);

    const RgbColor10& set(Data16 red, Data16 green, Data16 blue);
    const RgbColor10& set(Data16 red,
                          Data16 green,
                          Data16 blue,
                          Data16 alpha,
                          DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha);

    void getChannelData(Data16& red,
                        Data16& green,
                        Data16& blue,
                        Data16& alpha,
                        DataModelAttributes::ChannelOrder fmt) const;

    RgbColor asRgbColor(DataModelAttributes::ChannelOrder fmt) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder fmt) const;

    Data16 asGray(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    Data32 packed;

    const RgbColor10& operator=(const RgbColor10& rhs);
    const RgbColor10& operator=(Data32 rhs);

    operator Data32() const;

    bool operator==(const RgbColor10& rhs) const;
    bool operator==(Data32 rhs) const;
    bool operator!=(const RgbColor10& rhs) const;
    bool operator!=(Data32 rhs) const;
  };

  struct GTIL_EXPORT RgbColor16i
  {
  public:
    RgbColor16i();
    RgbColor16i(Data64 color);
    RgbColor16i(Data16 red, Data16 green, Data16 blue);
    RgbColor16i(Data16 first, Data16 second, Data16 third, Data16 alpha);

    const RgbColor16i& set(Data16 red, Data16 green, Data16 blue);
    const RgbColor16i& set(Data16 red,
                           Data16 green,
                           Data16 blue,
                           Data16 alpha,
                           DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha);

    RgbColor asRgbColor(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    Data16 asGray(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    union
    {
      struct
      {
        Data16 red;
        Data16 green;
        Data16 blue;
        Data16 alpha;
      } rgba;

      struct
      {
        Data16 blue;
        Data16 green;
        Data16 red;
        Data16 alpha;
      } bgra;

      Data64 packed;
    };

    const RgbColor16i& operator=(const RgbColor16i& rhs);
    const RgbColor16i& operator=(Data64 rhs);

    operator Data64() const;

    bool operator==(const RgbColor16i& rhs) const;
    bool operator==(Data64 rhs) const;
    bool operator!=(const RgbColor16i& rhs) const;
    bool operator!=(Data64 rhs) const;
  };

  struct GTIL_EXPORT RgbColor16f
  {
  public:
    RgbColor16f();
    RgbColor16f(Data64 color);
    RgbColor16f(half red, half green, half blue);
    RgbColor16f(half first, half second, half third, half alpha);

    const RgbColor16f& set(half red, half green, half blue);
    const RgbColor16f& set(half red,
                           half green,
                           half blue,
                           half alpha,
                           DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha);

    RgbColor asRgbColor(DataModelAttributes::ChannelOrder fmt) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder fmt) const;

    half asGray(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    typedef struct
    {
      half blue;
      half green;
      half red;
      half alpha;
    } Channels;

    union
    {
      struct
      {
        Data16 blue;
        Data16 green;
        Data16 red;
        Data16 alpha;
      } bgra;
      Data64 packed;
    };

    Channels getChannelData() const;

    const RgbColor16f& operator=(const RgbColor16f& rhs);
    const RgbColor16f& operator=(Data64 rhs);

    operator Data64() const;

    bool operator==(const RgbColor16f& rhs) const;
    bool operator==(Data64 rhs) const;
    bool operator!=(const RgbColor16f& rhs) const;
    bool operator!=(Data64 rhs) const;
  };

  struct GTIL_EXPORT RgbColor32f
  {
  public:
    RgbColor32f();
    RgbColor32f(Data128 color);
    RgbColor32f(float red, float green, float blue);
    RgbColor32f(float first, float second, float third, float alpha);

    const RgbColor32f& set(float red, float green, float blue);
    const RgbColor32f& set(float red,
                           float green,
                           float blue,
                           float alpha,
                           DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha);

    RgbColor asRgbColor(DataModelAttributes::ChannelOrder fmt) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder fmt) const;

    float asGray(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    Data128 pixel;

    const RgbColor32f& operator=(const RgbColor32f& rhs);
    const RgbColor32f& operator=(Data128 rhs);

    operator Data128() const;

    bool operator==(const RgbColor32f& rhs) const;
    bool operator==(Data128 rhs) const;
    bool operator!=(const RgbColor32f& rhs) const;
    bool operator!=(Data128 rhs) const;
  };

  struct GTIL_EXPORT RgbColor32i
  {
  public:
    RgbColor32i();
    RgbColor32i(Data128 color);
    RgbColor32i(Data32 red, Data32 green, Data32 blue);
    RgbColor32i(Data32 first, Data32 second, Data32 third, Data32 alpha);

    const RgbColor32i& set(Data32 red, Data32 green, Data32 blue);
    const RgbColor32i& set(Data32 red,
                           Data32 green,
                           Data32 blue,
                           Data32 alpha,
                           DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha);

    RgbColor asRgbColor(DataModelAttributes::ChannelOrder fmt) const;
    RgbColor asBgrColor(DataModelAttributes::ChannelOrder fmt) const;

    Data32 asGray(DataModelAttributes::ChannelOrder fmt = DataModelAttributes::kBlueGreenRedAlpha) const;

    Data128 pixel;

    const RgbColor32i& operator=(const RgbColor32i& rhs);
    const RgbColor32i& operator=(Data128 rhs);

    operator Data128() const;

    bool operator==(const RgbColor32i& rhs) const;
    bool operator==(Data128 rhs) const;
    bool operator!=(const RgbColor32i& rhs) const;
    bool operator!=(Data128 rhs) const;
  };

  namespace RgbColorFactors
  {
    const double kLuminanceRedFactor   = 0.299;
    const double kLuminanceGreenFactor = 0.587;
    const double kLuminanceBlueFactor  = 0.114;
  }
}

#ifndef RGBCOLOR_INL
#include <RgbColor.inl>
#endif

#endif
