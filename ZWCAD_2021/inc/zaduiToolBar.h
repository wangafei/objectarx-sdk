

#if !defined(_ZADUITOOLBAR_H__)
#define _ZADUITOOLBAR_H__

#if _MSC_VER > 1000
#pragma once
#endif 

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

#endif 

