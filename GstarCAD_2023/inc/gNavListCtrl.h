/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GNavListCtrl_h
#define _GNavListCtrl_h

#pragma once

class  CNavListCtrl;

class CNavDropSource : public COleDropSource
{
public:
  CNavDropSource();
  CNavListCtrl* m_pListCtrl;
  SCODE GiveFeedback(DROPEFFECT dropEffect);
};

class GCAD_PORT CNavListCtrl : public CGdUiListCtrl
{
public:
  CNavListCtrl();
public:
protected:
  afx_msg void OnBeginDrag(NMHDR* pNMHDR, LRESULT* pResult);
  afx_msg LRESULT OnHandleDrag(UINT_PTR pDataSource, LPARAM nSelectedItem);
  DECLARE_MESSAGE_MAP()

  CImageList* m_pDragImage;
  CNavDropSource m_dropSource;
};

#endif
