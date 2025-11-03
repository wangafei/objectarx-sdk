/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcuiButton_h
#define _gcuiButton_h

#if _MSC_VER >= 1000
#pragma once
#endif 


class GCAD_PORT CGcUiOwnerDrawButton : public CGdUiOwnerDrawButton {
	DECLARE_DYNAMIC(CGcUiOwnerDrawButton)

public:
	            CGcUiOwnerDrawButton ();
                ~CGcUiOwnerDrawButton ();

protected:
	DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiBitmapButton : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGcUiBitmapButton)

public:
	            CGcUiBitmapButton ();
                ~CGcUiBitmapButton ();

protected:
	DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiBitmapStatic : public CGdUiBitmapStatic {
	DECLARE_DYNAMIC(CGcUiBitmapStatic)

public:
	            CGcUiBitmapStatic ();
                ~CGcUiBitmapStatic ();

protected:
	DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiDropSite : public CGdUiDropSite {
	DECLARE_DYNAMIC(CGcUiDropSite)

public:
	            CGcUiDropSite ();
                ~CGcUiDropSite ();

protected:
	DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiPickButton : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGcUiPickButton)

public:
	            CGcUiPickButton ();
                ~CGcUiPickButton ();

protected:
	DECLARE_MESSAGE_MAP()
};


class GCAD_PORT CGcUiSelectButton : public CGcUiPickButton {
	DECLARE_DYNAMIC(CGcUiSelectButton)

public:
	            CGcUiSelectButton ();
                ~CGcUiSelectButton ();

protected:
	DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiQuickSelectButton : public CGdUiBitmapButton {
	DECLARE_DYNAMIC(CGcUiQuickSelectButton)

public:
	            CGcUiQuickSelectButton ();
                ~CGcUiQuickSelectButton ();

protected:
	DECLARE_MESSAGE_MAP()
};

class GCAD_PORT CGcUiToolButton : public CGdUiToolButton {
	DECLARE_DYNAMIC(CGcUiToolButton)

public:
	            CGcUiToolButton ();
                ~CGcUiToolButton ();

protected:
	DECLARE_MESSAGE_MAP()
};


#endif
