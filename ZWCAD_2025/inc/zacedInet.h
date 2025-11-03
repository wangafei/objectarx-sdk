#include "zacadapidef.h"

#ifndef _ZACEDINET_H_
#define _ZACEDINET_H_
#pragma pack (push, 8)

ZCAD_PORT ZSoft::Boolean
zcedCreateShortcut(void* pvHwndParent, const ZTCHAR* szLinkPath,
				   const ZTCHAR* szObjectPath, const ZTCHAR* szDesc);

ZCAD_PORT ZSoft::Boolean
zcedResolveShortcut(void* pvHwndParent, const ZTCHAR* szLinkPath,
					ZTCHAR* szObjectPath);

ZCAD_PORT ZSoft::Boolean
zcedResolveShortcut(void* pvHwndParent, const ZTCHAR* szLinkPath,ZcString& sObjectPath);

ZCAD_PORT ZSoft::Boolean
zcedGetUserFavoritesDir(ZTCHAR* szFavoritesDir);

ZCAD_PORT ZSoft::Boolean
zcedGetUserFavoritesDir(ZcString& szFavoritesDir);

ZCAD_PORT ZSoft::Boolean
zcedCreateInternetShortcut(const ZTCHAR* szURL, const ZTCHAR* szShortcutPath);

ZCAD_PORT ZSoft::Boolean
zcedResolveInternetShortcut(const ZTCHAR* szLinkFile, ZTCHAR* szUrl);

ZCAD_PORT ZSoft::Boolean
zcedResolveInternetShortcut(const ZTCHAR* szLinkFile, ZcString& szUrl);

#pragma pack (pop)
#endif	
