/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GDUI_DROP_TARGET_H_
#define _GDUI_DROP_TARGET_H_

#if _MSC_VER > 1000
#pragma once
#endif 

#define UM_GDUI_DRAGENTER				(WM_USER + 120)
#define UM_GDUI_DRAGOVER				(WM_USER + 121)
#define UM_GDUI_DRAGLEAVE				(WM_USER + 122)
#define UM_GDUI_DROP					(WM_USER + 123)
#define UM_GDUI_DROPEX					(WM_USER + 124)
#define UM_GDUI_DRAGSCROLL				(WM_USER + 125)

#ifndef _GSOFT_MAC_

typedef struct tagGDUI_DRAGDATA
{
  CWnd				*	mpWnd;
  COleDataObject		*	mpDataObject;
  DWORD					mdwKeyState;
  POINTL					mPoint;
  DROPEFFECT				mDropEffect;
  DROPEFFECT				mDropList;

} GDUI_DRAGDATA, *PGDUI_DRAGDATA;

#pragma warning(push)
#pragma warning(disable : 4275)
class CGdUiDropTarget : public COleDropTarget
{
public:
  CGdUiDropTarget();
  CGdUiDropTarget(int nId);
  ~CGdUiDropTarget();

  BOOL            SetTargetWindowForMessages(CWnd* pWnd);

protected:
  DROPEFFECT 	OnDragEnter(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point) override;

  DROPEFFECT 	OnDragOver(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DWORD dwKeyState,
    CPoint point) override;

  BOOL		OnDrop(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT 	dropEffect,
    CPoint point) override;

  DROPEFFECT 	OnDropEx(
    CWnd* pWnd,
    COleDataObject* pDataObject,
    DROPEFFECT dropDefault,
    DROPEFFECT dropList,
    CPoint point) override;

  void		OnDragLeave(CWnd* pWnd) override;

  DROPEFFECT  OnDragScroll(
    CWnd* pWnd,
    DWORD dwKeyState,
    CPoint point) override;

protected:
  DWORD		mdwKeyState;
  int                 mnId;
  CWnd            *   mpTargetWnd;
};
#pragma warning(pop)
#endif  
#endif 