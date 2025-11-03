
#pragma once

#include "zadui_port.h"
#include "zaduiToolBarCtrl.h"

class ZDUI_PORT CZdUiToolBar : public CToolBar
{
    DECLARE_DYNAMIC(CZdUiToolBar)
public:

    CZdUiToolBar();

    virtual ~CZdUiToolBar();

    BOOL LoadToolBar(LPCTSTR lpszResourceName);

    BOOL LoadToolBar(UINT nIDResource);

protected:

    afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);

    DECLARE_MESSAGE_MAP()
};

