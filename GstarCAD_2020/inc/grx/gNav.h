#ifndef _GNav_h
#define _GNav_h

#if _MSC_VER >= 1000
#pragma once
#endif

#ifdef _GNAV_BUILD
#define GNAV_PORT __declspec(dllexport)
#else
#define GNAV_PORT __declspec(dllimport)
#endif

#include "gdui.h"
#include <afxole.h>
#include "gnavListCtrl.h"
#include "gNavData.h"
#include "gNavFilter.h"
#include "gNavArray.h"
#include "gNavDataArray.h"
#include "gNavFilterArray.h"
#include "gNavDialog.h"

#endif
