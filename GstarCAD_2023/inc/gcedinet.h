/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "gcadapidef.h"

#if !defined(AFX_GCEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_)
#define AFX_GCEDINET_H__2357B7CE_20CE_11d2_A981_0060B0CD39AD__INCLUDED_
#pragma pack (push, 8)

GCAD_PORT Gsoft::Boolean
gcedCreateShortcut(void* pvHwndParent, const GCHAR* szLinkPath,
  const GCHAR* szObjectPath, const GCHAR* szDesc);

GCAD_PORT Gsoft::Boolean
gcedResolveShortcut(void* pvHwndParent, const GCHAR* szLinkPath,
  GCHAR* szObjectPath);

GCAD_PORT Gsoft::Boolean
gcedGetUserFavoritesDir(GCHAR* szFavoritesDir);

GCAD_PORT Gsoft::Boolean
gcedCreateInternetShortcut(const GCHAR* szURL, const GCHAR* szShortcutPath);

GCAD_PORT Gsoft::Boolean
gcedResolveInternetShortcut(const GCHAR* szLinkFile, GCHAR* szUrl);

#pragma pack (pop)
#endif	