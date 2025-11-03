#ifndef _GDUI_PALETTE_H_
#define _GDUI_PALETTE_H_

#include "gduiDropTarget.h"

class CGdUiPaletteSet;


// Palette Styles
#define PS_EDIT_NAME           0x00000001 // Support editing of palette set name through in-place editing


/////////////////////////////////////////////////////////////////////////////
//
// class CGdUiPalette
//
#pragma warning(push)
#pragma warning(disable : 4275)
class GDUI_PORT CGdUiPalette : public CWnd
{
    DECLARE_DYNAMIC(CGdUiPalette)

public:
    CGdUiPalette();
    virtual ~CGdUiPalette();

    // Creates the palette window
    BOOL Create(DWORD dwStyle, LPCTSTR pszName, CGdUiPaletteSet* pParent,
                DWORD dwPaletteStyle = 0);

    // Virtual method for "On demand" creation of palette windows.  Return TRUE for
    // successful creation.
     virtual BOOL Create(CGdUiPaletteSet* pParent);

    // Returns the palette style
    DWORD GetPaletteStyle();
    // Sets the palette style.
    void SetPaletteStyle(DWORD dwStyle);

    // Style access methods
    BOOL EditNameStyle()
        { return m_dwStyle & PS_EDIT_NAME; }

    // Load the data from xml.
    virtual BOOL Load(IUnknown* pUnk);
//    // Save the data to xml.
    virtual BOOL Save(IUnknown* pUnk);

    // Returns the palette set back pointer.
    CGdUiPaletteSet* GetPaletteSet() { return m_pPaletteSet; };
    // Sets the palette set back pointer.
    void SetPaletteSet(CGdUiPaletteSet* pSet);

    // Called by the palette set when the palette is made active
    virtual void OnSetActive();
    // Called by the palette set when this palette loses its current 
    // palette state and some other palette is going to be current 
    // palette. Override this member function to perform tasks when 
    // a palette is de-activated. The override of this member function 
    // should call the base class version before any other processing 
    // is done.
	virtual BOOL OnKillActive();
//
    virtual CString GetClassName();  // deprecated
    
    // Returns the name of the palette.
    CString GetName();

    // Sets the name of the palette.
    void SetName(CString strName);
    
    // Sets the minimum size of the palette in the palette set
    virtual BOOL GetMinimumSize(CSize& size);
//    // Sets the maximum size of the palette in the palette set
    virtual BOOL GetMaximumSize(CSize& size);
//
//    // Return false to indicate that the palette should not give up focus,
//    // true to indicate that the palette doesn't need focus.
    virtual bool CanFrameworkTakeFocus();
//
//    // In-place editing of palette name at a specified location
    virtual void EditName(CPoint & ptLoc);

    // In-place editing of palette name centered on the palette's tab.  Intended for use
    // only in cases where the palette has a visible tab in it's containing palette set.
    virtual void EditName();
//
//    // Called when the editing of the palette name using in-place editing is completed
//    // Return of TRUE means the name is valid.
    virtual BOOL NameEditValidation(CEdit* pEdit);

    static bool PaletteNameEditInProgress() { return m_bPaletteNameEditInProgress; }  // INTERNAL USE ONLY

protected:
    // Specialized background erasing
    afx_msg BOOL    OnEraseBkgnd(CDC *pdc);  // INTERNAL USE ONLY
    // Default "SetCursor" implementation
    afx_msg BOOL    OnSetCursor(CWnd *pwnd, UINT nHitTest, UINT msg);
    afx_msg void    OnLButtonDown(UINT nFlags, CPoint pt);
    afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);  // INTERNAL USE ONLY
    afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);  // INTERNAL USE ONLY

    DECLARE_MESSAGE_MAP()

private:
    CString                 m_sName;
    CGdUiPaletteSet *       m_pPaletteSet;
    CObArray                m_arrayColors;
    DWORD                   m_dwStyle;
    static UINT             m_nNextPaletteId;
    CEdit *                 m_pLabelEdit;
    static bool             m_bPaletteNameEditInProgress;
};
#pragma warning(pop)
#endif // _GDUI_PALETTE_H_
