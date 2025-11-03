/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GDUI_PALETTE_H_
#define _GDUI_PALETTE_H_

#include "gduiDropTarget.h"

class CGdUiPaletteSet;

#define PS_EDIT_NAME           0x00000001 

#ifndef _GSOFT_MAC_
#pragma warning(push)
#pragma warning(disable : 4275)
class GCAD_PORT CGdUiPalette : public CWnd
{
  DECLARE_DYNAMIC(CGdUiPalette)

public:
  CGdUiPalette();
  ~CGdUiPalette();

  BOOL Create(DWORD dwStyle, LPCTSTR pszName, CGdUiPaletteSet* pParent,
    DWORD dwPaletteStyle = 0);
  virtual BOOL Create(CGdUiPaletteSet* pParent);
  DWORD GetPaletteStyle();
  void SetPaletteStyle(DWORD dwStyle);
  BOOL EditNameStyle()
  {
    return m_dwStyle & PS_EDIT_NAME;
  }

  virtual BOOL Load(IUnknown* pUnk);
  virtual BOOL Save(IUnknown* pUnk);

  CGdUiPaletteSet* GetPaletteSet() { return m_pPaletteSet; };
  void SetPaletteSet(CGdUiPaletteSet* pSet);

  virtual void OnSetActive();
  virtual BOOL OnKillActive();

  __declspec(deprecated) virtual CString GetClassNameW();

  CString GetName();
  void SetName(CString strName);

  virtual BOOL GetMinimumSize(CSize& size);
  virtual BOOL GetMaximumSize(CSize& size);

  virtual bool CanFrameworkTakeFocus();

  virtual void EditName(CPoint & ptLoc);
  virtual void EditName();

  virtual BOOL NameEditValidation(CEdit* pEdit);
  virtual void InitPaletteTheme() {}
  static bool PaletteNameEditInProgress();

protected:
  afx_msg BOOL    OnEraseBkgnd(CDC *pdc);
  afx_msg BOOL    OnSetCursor(CWnd *pwnd, UINT nHitTest, UINT msg);
  afx_msg void    OnLButtonDown(UINT nFlags, CPoint pt);
  afx_msg LRESULT OnBeginNameEdit(WPARAM, LPARAM);
  afx_msg LRESULT OnEndNameEdit(WPARAM, LPARAM);

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
#endif 
#endif 