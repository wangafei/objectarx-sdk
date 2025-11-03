/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gcuiTabCtrl_h
#define _gcuiTabCtrl_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

class GCAD_PORT CGcUiTab : public CGdUiTab {
  DECLARE_DYNAMIC(CGcUiTab);
public:
  CGcUiTab();
  ~CGcUiTab();

protected:
  DECLARE_MESSAGE_MAP()
};

#pragma pack (pop)
#endif