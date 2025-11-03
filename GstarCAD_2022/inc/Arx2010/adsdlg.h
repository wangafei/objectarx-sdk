#pragma once
#include "ads.h"
#include "AdAChar.h"
#include "../grx/gdsdlg.h"

#define  ads_hdlg					gds_hdlg
#define  ads_htile					gds_htile
#define  ads_callback_packet		gds_callback_packet

#define ads_load_dialog				dlg_load_dialog
#define ads_unload_dialog			dlg_unload_dialog
#define ads_new_dialog				dlg_new_dialog
#define ads_new_positioned_dialog	dlg_new_positioned_dialog
#define ads_start_dialog			dlg_start_dialog
#define ads_done_dialog				dlg_done_dialog
#define ads_done_positioned_dialog	dlg_done_positioned_dialog
#define ads_term_dialog				dlg_term_dialog
#define ads_action_tile				dlg_action_tile
#define ads_set_tile				dlg_set_tile
#define ads_client_data_tile		dlg_client_data_tile
#define ads_get_tile				dlg_get_tile
#define ads_get_attr				dlg_get_attr
#define ads_get_attr_string			dlg_get_attr_string
#define ads_start_list				dlg_start_list
#define ads_add_list				dlg_add_list
#define ads_end_list				dlg_end_list
#define ads_get_list_string			dlg_get_list_string
#define ads_mode_tile				dlg_mode_tile
#define ads_dimensions_tile			dlg_dimensions_tile
#define ads_start_image				dlg_start_image
#define ads_vector_image			dlg_vector_image
#define ads_fill_image				dlg_fill_image
#define ads_slide_image				dlg_slide_image
#define ads_end_image				dlg_end_image

#define NULLCB GDS_NULLCB
#define CBR_LOST_FOCUS GDS_CBR_LOST_FOCUS
#define CBR_DRAG GDS_CBR_DRAG
#define CBR_DOUBLE_CLICK GDS_CBR_DOUBLE_CLICK
#define DLGALLDONE GDS_DLGALLDONE
#define DLGCANCEL  GDS_DLGCANCEL
#define DLGOK      GDS_DLGOK
#define DLGSTATUS  GDS_DLGSTATUS
#define LIST_CHANGE GDS_LIST_CHANGE
#define LIST_APPEND GDS_LIST_APPEND
#define LIST_NEW    GDS_LIST_NEW
#define MODE_ENABLE GDS_MODE_ENABLE
#define MODE_DISABLE  GDS_MODE_DISABLE
#define MODE_SETFOCUS GDS_MODE_SETFOCUS
#define MODE_SETSEL   GDS_MODE_SETSEL
#define MODE_FLIP     GDS_MODE_FLIP

#define MAX_TILE_STR   GDS_MAX_TILE_STR
#define TILE_STR_LIMIT GDS_TILE_STR_LIMIT
#define BAD_DIALOG     GDS_BAD_DIALOG

#define BGLCOLOR   GDS_BGLCOLOR
#define DBGLCOLOR  GDS_DBGLCOLOR
#define DFGLCOLOR  GDS_DFGLCOLOR
#define LINELCOLOR GDS_LINELCOLOR