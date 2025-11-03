
#pragma once

#include "zAdAChar.h"
#include "zadesk.h"

namespace Ztil {
    class ImageFormatCodec;
    class ProgressCallbackInterface;
};

class ZdHostImageAppServices;

class ZSOFT_NO_VTABLE ZdHostImageAppServices	
{
public:
    virtual const ZTCHAR* imageFileExtensions (bool bRefresh = false) = 0;

    virtual const ZTCHAR* imageFilterString (bool bRefresh = false) = 0;

    virtual bool registerFormatCodec (Ztil::ImageFormatCodec& codec) = 0;
    virtual bool formatCodecRegistered (Ztil::ImageFormatCodec& codec) = 0;
    virtual bool reRegisterFormatCodec (Ztil::ImageFormatCodec& codec) = 0;
    virtual bool unRegisterFormatCodec (Ztil::ImageFormatCodec& codec) = 0;
    virtual Ztil::ProgressCallbackInterface* registerProgressCallback (Ztil::ProgressCallbackInterface* pCallback ) = 0;
};

ZdHostImageAppServices* getZdHostImageAppServices();
