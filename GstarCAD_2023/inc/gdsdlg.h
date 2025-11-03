/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gdsdlg_h
#define _gdsdlg_h 1

#include "gds.h"
#include "GdGChar.h"
#pragma pack (push, 8)

#ifndef CALLB
#define CALLB
#endif

#ifdef __ZTC__
#pragma ZTC align 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

  typedef void *gds_hdlg;
  typedef void *gds_htile;

  typedef struct {
    gds_hdlg  dialog;
    gds_htile tile;
    GCHAR*     value;
    void*     client_data;
    int       reason;
    long      x, y;
  } gds_callback_packet;

#define CBR_SELECT       1
#define CBR_LOST_FOCUS   2
#define CBR_DRAG         3
#define CBR_DOUBLE_CLICK 4

#ifndef _PROTEUS_H
  typedef void(*CLIENTFUNC) (gds_callback_packet *cpkt);
#endif 

#define NULLCB ((CLIENTFUNC)0)
#define BAD_DIALOG NULL

#define DLGCANCEL     0 
#define DLGOK         1 
#define DLGALLDONE   -1 
#define DLGSTATUS     2 

#ifndef _PROCONST_H
#define LIST_CHANGE ((short) 1) 
#define LIST_APPEND ((short) 2) 
#define LIST_NEW    ((short) 3) 
#define MODE_ENABLE   ((short) 0) 
#define MODE_DISABLE  ((short) 1) 
#define MODE_SETFOCUS ((short) 2) 
#define MODE_SETSEL   ((short) 3) 
#define MODE_FLIP     ((short) 4) 
#endif  

#ifndef _PROTEUS_H
#define MAX_TILE_STR  40
#endif

#define TILE_STR_LIMIT 2035 

  GCCORE_PORT int gds_load_dialog(const GCHAR *dclfile, int *dcl_id);
  GCCORE_PORT int gds_unload_dialog(int dcl_id);
  GCCORE_PORT int gds_new_dialog(const GCHAR *dlgname, int dcl_id,
    CLIENTFUNC def_callback, gds_hdlg *hdlg);
  GCCORE_PORT int gds_new_positioned_dialog(const GCHAR *dlgname, int dcl_id,
    CLIENTFUNC def_callback, int x, int y,
    gds_hdlg *hdlg);
  GCCORE_PORT int gds_start_dialog(gds_hdlg hdlg, int *status);
  GCCORE_PORT int gds_term_dialog(void);
  GCCORE_PORT int gds_action_tile(gds_hdlg hdlg, const GCHAR *key, CLIENTFUNC tilefunc);
  GCCORE_PORT int gds_done_dialog(gds_hdlg hdlg, int status);
  GCCORE_PORT int gds_done_positioned_dialog(gds_hdlg hdlg, int status, int *x_result,
    int *y_result);
  GCCORE_PORT int gds_set_tile(gds_hdlg hdlg, const GCHAR *key, const GCHAR *value);
  GCCORE_PORT int gds_client_data_tile(gds_hdlg hdlg, const GCHAR *key, void *clientdata);
  GCCORE_PORT int gds_get_tile(gds_hdlg hdlg, const GCHAR *key,
    GCHAR *value, int maxlen);
  GCCORE_PORT int gds_get_attr(gds_hdlg hdlg, const GCHAR *key,
    GCHAR *attr, GCHAR *value, int len);
  GCCORE_PORT int gds_get_attr_string(gds_htile tile, GCHAR *attr, GCHAR *value, int len);
  GCCORE_PORT int gds_start_list(gds_hdlg hdlg, const GCHAR *key, short operation, short index);
  GCCORE_PORT int gds_add_list(const GCHAR *item);
  GCCORE_PORT int gds_end_list(void);
  GCCORE_PORT int gds_mode_tile(gds_hdlg hdlg, const GCHAR *key, short mode);
  GCCORE_PORT int gds_dimensions_tile(gds_hdlg hdlg, const GCHAR *key,
    short *cx, short *cy);
  GCCORE_PORT int gds_start_image(gds_hdlg hdlg, const GCHAR *key);
  GCCORE_PORT int gds_vector_image(short x1, short y1, short x2, short y2, short color);
  GCCORE_PORT int gds_fill_image(short x1, short y1, short x2, short y2, short color);
  GCCORE_PORT int gds_slide_image(short x1, short y1, short x2, short y2,
    const GCHAR *slnam);
  GCCORE_PORT int gds_end_image(void);

#ifdef __cplusplus
}
#endif

#pragma pack (pop)

#endif