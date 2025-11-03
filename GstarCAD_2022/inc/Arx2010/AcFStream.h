#pragma once
#include "malloc.h"             
#include "AdAChar.h"
#include "AdCharFmt.h"
#include "../grx/GcFStream.h"

#define  AcFStream_Assert  GcFStream_Assert
#define  GcFStream_Assert  OdFStream_Assert

#define  AcFStream_wideToMulti  GcFStream_wideToMulti
#define  GcFStream_wideToMulti  OdFStream_wideToMulti

#define  AcFStream_curLocale  GcFStream_curLocale
#define  GcFStream_curLocale  OdFStream_curLocale

#define  AcIfstream  GcIfstream
#define  GcIfstream  OdIfstream
                     
#define  AcOfstream  GcOfstream
#define  GcOfstream  OdOfstream