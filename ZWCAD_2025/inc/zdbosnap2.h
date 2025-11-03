
#ifndef _ZDBOSNAP2_H
#define _ZDBOSNAP2_H

#include "zdbosnap.h"


class ZcDbCustomOsnapMode2 : public ZcDbCustomOsnapMode{
public:

    virtual HICON menuIcon()
    {
        return NULL;
    }

    virtual HICON menuIconForDarkTheme()
    {
        return NULL;
    }

    virtual const ZTCHAR * displayString()
    {
        return localModeString();
    }
};

#endif 
