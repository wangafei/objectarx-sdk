#pragma once

#include "zadesk.h"
#ifdef _ZSOFT_WINDOWS_
#ifndef ZC_DO_NO_IMPORT
#pragma warning (push)
#pragma warning(disable : 4279)
#pragma warning(disable : 4192)
#import "msxml6.dll" named_guids rename_namespace("MSXML") rename("offset", "MSXMLoffset")
#pragma warning (pop)
#else
#include "msxml6.tlh"
#endif
__declspec(selectany) extern const GUID CLSID_DOMDocumentZcad = MSXML::CLSID_DOMDocument60;
#endif
