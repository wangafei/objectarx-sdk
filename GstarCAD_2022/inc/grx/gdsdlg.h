#pragma once

#include "gcadstd.h"
#include "gds.h"

#ifndef CALLB
#define CALLB
#endif

typedef void *gds_hdlg;
typedef void *gds_htile;

typedef struct
{
	gds_hdlg  dialog;
	gds_htile tile;
	GCHAR*     value;
	void*     client_data;
	int       reason;
	long      x, y;
} gds_callback_packet;

#ifdef __cplusplus
	typedef void (*CLIENTFUNC) (gds_callback_packet *cpkt);
#else
	#define CLIENTFUNC void *
#endif

#define GDS_NULLCB ((CLIENTFUNC)0)

#define GDS_CBR_SELECT       1
#define GDS_CBR_LOST_FOCUS   2
#define GDS_CBR_DRAG         3
#define GDS_CBR_DOUBLE_CLICK 4

#define GDS_DLGALLDONE   -1
#define GDS_DLGCANCEL     0
#define GDS_DLGOK         1
#define GDS_DLGSTATUS     2

#define GDS_LIST_CHANGE   1
#define GDS_LIST_APPEND   2
#define GDS_LIST_NEW      3

#define GDS_MODE_ENABLE   0
#define GDS_MODE_DISABLE  1
#define GDS_MODE_SETFOCUS 2
#define GDS_MODE_SETSEL   3
#define GDS_MODE_FLIP     4

#define GDS_MAX_TILE_STR   40
#define GDS_TILE_STR_LIMIT 255

#define GDS_BAD_DIALOG	NULL

#define GDS_BGLCOLOR      -2
#define GDS_DBGLCOLOR     -15
#define GDS_DFGLCOLOR     -16
#define GDS_LINELCOLOR    -18

#pragma pack (push, 8)

#ifdef __cplusplus
    extern "C" {
#endif

GCED_DLL_DECL int dlg_load_dialog(const GCHAR *dclfile, int *dcl_id);
GCED_DLL_DECL int dlg_unload_dialog(int dcl_id);
GCED_DLL_DECL int dlg_new_dialog(const GCHAR *dlgname, int dcl_id,CLIENTFUNC def_callback, gds_hdlg *hdlg);
GCED_DLL_DECL int dlg_new_positioned_dialog(const GCHAR *dlgname, int dcl_id,CLIENTFUNC def_callback, int x, int y,gds_hdlg *hdlg);
GCED_DLL_DECL int dlg_start_dialog(gds_hdlg hdlg, int *status);
GCED_DLL_DECL int dlg_term_dialog(void);
GCED_DLL_DECL int dlg_action_tile(gds_hdlg hdlg, const GCHAR *key, CLIENTFUNC tilefunc);
GCED_DLL_DECL int dlg_done_dialog(gds_hdlg hdlg, int status);
GCED_DLL_DECL int dlg_done_positioned_dialog(gds_hdlg hdlg, int status, int *x_result,int *y_result);
GCED_DLL_DECL int dlg_set_tile(gds_hdlg hdlg, const GCHAR *key, const GCHAR *value);
GCED_DLL_DECL int dlg_client_data_tile(gds_hdlg hdlg, const GCHAR *key, void *clientdata);
GCED_DLL_DECL int dlg_get_tile(gds_hdlg hdlg, const GCHAR *key,GCHAR *value, int maxlen);
GCED_DLL_DECL int dlg_get_attr(gds_hdlg hdlg, const GCHAR *key,GCHAR *attr, GCHAR *value, int len);
GCED_DLL_DECL int dlg_get_attr_string(gds_htile tile, GCHAR *attr, GCHAR *value, int len);
GCED_DLL_DECL int dlg_start_list(gds_hdlg hdlg, const GCHAR *key, short operation, short index);
GCED_DLL_DECL int dlg_add_list(const GCHAR *item);
GCED_DLL_DECL int dlg_end_list(void);
GCED_DLL_DECL int dlg_get_list_string(gds_hdlg hDialog,const GCHAR *szControlKey, GCHAR *szListString, int nStringLength, int nWhichItem);//New
GCED_DLL_DECL int dlg_mode_tile(gds_hdlg hdlg, const GCHAR *key, short mode);
GCED_DLL_DECL int dlg_dimensions_tile(gds_hdlg hdlg, const GCHAR *key,short *cx, short *cy);
GCED_DLL_DECL int dlg_start_image(gds_hdlg hdlg, const GCHAR *key);
GCED_DLL_DECL int dlg_vector_image(short x1, short y1, short x2, short y2, short color);
GCED_DLL_DECL int dlg_fill_image(short x1, short y1, short x2, short y2, short color);
GCED_DLL_DECL int dlg_slide_image(short x1, short y1, short x2, short y2,const GCHAR *slnam);
GCED_DLL_DECL int dlg_end_image(void);

GCED_DLL_DECL int dlg_create_preview_image(gds_hdlg hDialog,const GCHAR *szControlKey,const void *pPreviewData);

#ifdef __cplusplus
	}
#endif

#pragma pack(pop)