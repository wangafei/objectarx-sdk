#pragma once
#include "gchar.h"

namespace Atil {
  class ImageFormatCodec;
  class ProgressCallbackInterface;
};

class GdHostImageAppServices;

class __declspec(novtable) GdHostImageAppServices
{
public:
  virtual const GCHAR* imageFileExtensions(bool bRefresh = false) = 0;

  virtual const GCHAR* imageFilterString(bool bRefresh = false) = 0;

  virtual bool registerFormatCodec(Atil::ImageFormatCodec& codec) = 0;

  virtual bool formatCodecRegistered(Atil::ImageFormatCodec& codec) = 0;

  virtual bool reRegisterFormatCodec(Atil::ImageFormatCodec& codec) = 0;

  virtual bool unRegisterFormatCodec(Atil::ImageFormatCodec& codec) = 0;

  virtual Atil::ProgressCallbackInterface* registerProgressCallback(Atil::ProgressCallbackInterface* pCallback) = 0;
};

GdHostImageAppServices* getAdHostImageAppServices();


