
#pragma once




#ifndef  ZDHOSTWINDOW_H
#define ZDHOSTWINDOW_H

#include "zadhostableui.h"

class IZdHostWindow  
{
public:

    virtual HWND windowHandle() = 0;

};

#endif 

