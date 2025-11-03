#pragma once

#ifndef ZCAPWINDOW_H
#define ZCAPWINDOW_H

#include "zIAdHostWindow.h"
class ZcApWindowImp;

class ZCCORE_PORT ZcApWindow : public IZdHostWindow
{
public:
    bool  preRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, ZSoft::LongPtr& lResult);
    bool  routeMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, ZSoft::LongPtr& lResult);
    bool  postRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, ZSoft::LongPtr& lResult);

protected:
	ZcApWindow();
	virtual ~ZcApWindow();
	virtual bool subPreRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, ZSoft::LongPtr& lResult);
	virtual bool subRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, ZSoft::LongPtr& lResult);
	virtual bool subPostRouteMessage(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam, ZSoft::LongPtr& lResult);

    friend class ZcApWindowImp;
    ZcApWindowImp* m_pImp;
};

#endif
