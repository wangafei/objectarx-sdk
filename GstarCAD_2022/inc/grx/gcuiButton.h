#ifndef _gcuiButton_h
#define _gcuiButton_h

#include "gdui.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class GCUI_PORT CGcUiOwnerDrawButton : public CGdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CGcUiOwnerDrawButton)

public:
	            CGcUiOwnerDrawButton ();
virtual         ~CGcUiOwnerDrawButton ();

public:
	//{{AFX_VIRTUAL(CGcUiOwnerDrawButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiOwnerDrawButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiBitmapButton : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGcUiBitmapButton)

public:
	            CGcUiBitmapButton ();
virtual         ~CGcUiBitmapButton ();

public:
	//{{AFX_VIRTUAL(CGcUiBitmapButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiBitmapButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiBitmapStatic : public CGdUiBitmapStatic {
	DECLARE_DYNAMIC(CGcUiBitmapStatic)

public:
	            CGcUiBitmapStatic ();
virtual         ~CGcUiBitmapStatic ();

public:
	//{{AFX_VIRTUAL(CGcUiBitmapStatic)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiBitmapStatic)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiDropSite : public CGdUiDropSite {
	DECLARE_DYNAMIC(CGcUiDropSite)

public:
	            CGcUiDropSite ();
virtual         ~CGcUiDropSite ();

public:
	//{{AFX_VIRTUAL(CGcUiDropSite)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiDropSite)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiPickButton : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGcUiPickButton)

public:
	            CGcUiPickButton ();
virtual         ~CGcUiPickButton ();

protected:
virtual BOOL    OnLoadBitmap (LPCTSTR strResId);

public:
	//{{AFX_VIRTUAL(CGcUiPickButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiPickButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiSelectButton : public CGcUiPickButton {
	DECLARE_DYNAMIC(CGcUiSelectButton)

public:
	            CGcUiSelectButton ();
virtual         ~CGcUiSelectButton ();

public:
	//{{AFX_VIRTUAL(CGcUiSelectButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiSelectButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

class GCUI_PORT CGcUiToolButton : public CGdUiToolButton {
	DECLARE_DYNAMIC(CGcUiToolButton)

public:
	            CGcUiToolButton ();
virtual         ~CGcUiToolButton ();

public:
	//{{AFX_VIRTUAL(CGcUiToolButton)
	//}}AFX_VIRTUAL

protected:
	//{{AFX_MSG(CGcUiToolButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

#endif

//////////////////////////////////////////////////////////////////////////////
