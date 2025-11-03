// DrawableOverrule.h : main header file for the DrawableOverrule DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDrawableOverruleApp
// See DrawableOverrule.cpp for the implementation of this class
//

class CDrawableOverruleApp : public CWinApp
{
public:
	CDrawableOverruleApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
