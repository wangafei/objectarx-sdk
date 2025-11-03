
#ifndef __ACEDINET_H__
#define __ACEDINET_H__

#include "acadapidef.h"
#include "../../inc/zacedInet.h"

#ifndef ACDB_PORT
#define ACDB_PORT		ZCDB_PORT
#endif //#ifndef ACDB_PORT

#ifndef ACAD_PORT
#define ACAD_PORT		ZCAD_PORT
#endif //#ifndef ACAD_PORT

#ifndef ACHAR
#define ACHAR		ZTCHAR
#endif //#ifndef ACHAR

#ifndef Adesk
#define Adesk		ZSoft
#endif //#ifndef Adesk

#ifndef acedCreateInternetShortcut
#define acedCreateInternetShortcut		zcedCreateInternetShortcut
#endif //#ifndef acedCreateInternetShortcut

#ifndef acedCreateShortcut
#define acedCreateShortcut		zcedCreateShortcut
#endif //#ifndef acedCreateShortcut

#ifndef acedGetUserFavoritesDir
#define acedGetUserFavoritesDir		zcedGetUserFavoritesDir
#endif //#ifndef acedGetUserFavoritesDir

#ifndef acedResolveInternetShortcut
#define acedResolveInternetShortcut		zcedResolveInternetShortcut
#endif //#ifndef acedResolveInternetShortcut

#ifndef acedResolveShortcut
#define acedResolveShortcut		zcedResolveShortcut
#endif //#ifndef acedResolveShortcut

#endif //#ifndef __ACEDINET_H__
