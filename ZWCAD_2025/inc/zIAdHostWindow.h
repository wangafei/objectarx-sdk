
#pragma once




#ifndef  ZDHOSTWINDOW_H
#define ZDHOSTWINDOW_H


class IZdHostWindow  
{
public:
    using WindowHandle = HWND;

    virtual WindowHandle windowHandle() const = 0;

};

#endif 

