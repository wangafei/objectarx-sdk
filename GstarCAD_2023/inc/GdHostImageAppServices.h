/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GdGChar.h"
#include "gsoft.h"

namespace Gtil {
  class ImageFormatCodec;
  class ProgressCallbackInterface;
};

class GdHostImageAppServices;

class GSOFT_NO_VTABLE GdHostImageAppServices
{
public:
  virtual const GCHAR* imageFileExtensions(bool bRefresh = false) = 0;
  virtual const GCHAR* imageFilterString(bool bRefresh = false) = 0;
  virtual bool registerFormatCodec(Gtil::ImageFormatCodec& codec) = 0;
  virtual bool formatCodecRegistered(Gtil::ImageFormatCodec& codec) = 0;
  virtual bool reRegisterFormatCodec(Gtil::ImageFormatCodec& codec) = 0;
  virtual bool unRegisterFormatCodec(Gtil::ImageFormatCodec& codec) = 0;
  virtual Gtil::ProgressCallbackInterface* registerProgressCallback(Gtil::ProgressCallbackInterface* pCallback) = 0;
};

GdHostImageAppServices* getGdHostImageAppServices();