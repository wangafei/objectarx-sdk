#ifndef _GCED_INET_H_
#define _GCED_INET_H_

#include "gcadstd.h"

#pragma pack (push, 8)

GCED_DLL_DECL Hccad::Boolean gcedCreateShortcut(void* pvHwndParent, const GCHAR* szLinkPath, const GCHAR* szObjectPath, const GCHAR* szDesc);

GCED_DLL_DECL Hccad::Boolean gcedResolveShortcut(void* pvHwndParent, const GCHAR* szLinkPath, GCHAR* szObjectPath);

GCED_DLL_DECL Hccad::Boolean gcedGetUserFavoritesDir(GCHAR* szFavoritesDir);

GCED_DLL_DECL Hccad::Boolean gcedCreateInternetShortcut(const GCHAR* szURL, const GCHAR* szShortcutPath);

GCED_DLL_DECL Hccad::Boolean gcedResolveInternetShortcut(const GCHAR* szLinkFile, GCHAR* szUrl);

#pragma pack (pop)

#endif//_GCED_INET_H_