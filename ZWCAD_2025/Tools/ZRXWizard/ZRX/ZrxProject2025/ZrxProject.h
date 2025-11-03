// $projectname$.h : main header file for the $projectname$ DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// C$projectname$App
// See $projectname$.cpp for the implementation of this class
//

class C$projectname$App : public CWinApp
{
public:
	C$projectname$App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
