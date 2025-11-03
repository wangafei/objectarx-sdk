/*****************************************************************************
/*
/*     Copyright (C) 2008 Gcad Software Company Ltd.
/*     All rights reserved.
/*
/*     Use of the information contained herein, in part or in whole,
/*     in/as source code and/or in/as object code, in any way by anyone 
/*     other than authorized employees of Gcad Software Company Ltd
/*     use is illegal.
/*
*****************************************************************************/
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

#include "adui.h"
#include <afxole.h>
#include "AnavListCtrl.h"
#include "ANavData.h"
#include "ANavFilter.h"
#include "ANavArray.h"
#include "ANavDataArray.h"
#include "ANavFilterArray.h"
#include "ANavDialog.h"

#endif
