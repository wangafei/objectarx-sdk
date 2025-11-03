/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "gsoft.h"
#ifdef _GSOFT_WINDOWS_
#ifndef GC_DO_NO_IMPORT
#pragma warning (push)
#pragma warning(disable : 4279)
#pragma warning(disable : 4192)
#import "msxml6.dll" named_guids rename_namespace("MSXML") rename("offset", "MSXMLoffset")
#pragma warning (pop)
#else 
#include "msxml6.tlh"
#endif
__declspec(selectany) extern const GUID CLSID_DOMDocumentGcad = MSXML::CLSID_DOMDocument60;
#endif 