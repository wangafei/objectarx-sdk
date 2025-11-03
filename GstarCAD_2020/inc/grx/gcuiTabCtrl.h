#ifndef _GcuiTabCtrl_h
#define _GcuiTabCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class GCUI_PORT CGcUiTab : public CGdUiTab {
    DECLARE_DYNAMIC(CGcUiTab);

public:
	            CGcUiTab ();
virtual         ~CGcUiTab ();

public:
	//{{AFX_VIRTUAL(CGcUiTab)
	//}}AFX_VIRTUAL

protected:
    //{{AFX_MSG(CGcUiTab)
    //}}AFX_MSG

    DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif