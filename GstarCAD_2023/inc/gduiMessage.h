/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiMessage_h
#define _gduiMessage_h
#pragma pack (push, 8)

#pragma once


typedef enum {
  kGdUiNotify_Nothing,
  kGdUiNotify_Generic,
  kGdUiNotify_AppMainWindow,
  kGdUiNotify_AppResourceInstance,
  kGdUiNotify_AutoLoad,
  kGdUiNotify_Reload,
  kGdUiNotify_GetTipSupport,
  kGdUiNotify_GetTipText,
  kGdUiNotify_GetTipRect,
  kGdUiNotify_HitTipRect,
  kGdUiNotify_DrawTip,
  kGdUiNotify_DrawTipText,
  kGdUiNotify_UpdateTip,
  kGdUiNotify_HideWindow,
  kGdUiNotify_ShowWindow,
  kGdUiNotify_RestoreFocus,
  kGdUiNotify_Change,
  kGdUiNotify_NotValid,
  kGdUiNotify_Valid,
  kGdUiNotify_Validate,
  kGdUiNotify_CommandState,
  kGdUiNotify_ModalState,
} GDUI_NOTIFY;

typedef enum {
  kGdUiReply_Nothing,
  kGdUiReply_Ok,
  kGdUiReply_NotValid,
  kGdUiReply_Valid,
  kGdUiReply_TextTip,
  kGdUiReply_ToolTip,
  kGdUiReply_DrawTip,
} GDUI_REPLY;

typedef enum {
  kGdUiCommand_Cancelled = -1,
  kGdUiCommand_Completed,
  kGdUiCommand_Begun,
} GDUI_COMMAND_STATE;

typedef enum {
  kGdUiModal_Begun = 1,
  kGdUiModal_Ended,
} GDUI_MODAL_STATE;

class GCAD_PORT CGdUiDrawTipText {
public:
  CGdUiDrawTipText(CDC& dc, CRect& rect, CString& text);

public:
  CDC&    m_dc;
  CRect&  m_rect;
  CString& m_text;
};

const UINT GCAD_PORT GdUiMessage();

GDUI_NOTIFY GCAD_PORT GdUiNotification(WPARAM wp);

#if !defined(_WIN64) && !defined (_GC64)
GDUI_REPLY GCAD_PORT GdUiNotify(CWnd& w, UINT id, GDUI_NOTIFY n, DWORD_PTR lParam);
GDUI_REPLY GCAD_PORT GdUiNotify(CWnd* w, UINT id, GDUI_NOTIFY n, DWORD_PTR lParam);
#else
GDUI_REPLY GCAD_PORT GdUiNotify(CWnd& w, UINT id, GDUI_NOTIFY n, LPARAM lParam);
GDUI_REPLY GCAD_PORT GdUiNotify(CWnd* w, UINT id, GDUI_NOTIFY n, LPARAM lParam);
#endif

UINT GCAD_PORT GdUiNotifyId(WPARAM wp);

#if !defined(_WIN64) && !defined (_GC64)
BOOL GCAD_PORT GdUiPostNotify(CWnd& w, UINT id, GDUI_NOTIFY n, DWORD_PTR lParam);
BOOL GCAD_PORT GdUiPostNotify(CWnd* w, UINT id, GDUI_NOTIFY n, DWORD_PTR lParam);
#else
BOOL GCAD_PORT GdUiPostNotify(CWnd& w, UINT id, GDUI_NOTIFY n, LPARAM lParam);
BOOL GCAD_PORT GdUiPostNotify(CWnd* w, UINT id, GDUI_NOTIFY n, LPARAM lParam);
#endif


#pragma pack (pop)
#endif
