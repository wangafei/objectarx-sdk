/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef   _GCCMD_DEFS_H
#define   _GCCMD_DEFS_H

#define GCRX_CMD_MODAL              0x00000000
#define GCRX_CMD_TRANSPARENT        0x00000001
#define GCRX_CMD_USEPICKSET         0x00000002
#define GCRX_CMD_REDRAW	            0x00000004
#define GCRX_CMD_NOPERSPECTIVE      0x00000008 
#define GCRX_CMD_NOMULTIPLE         0x00000010
#define GCRX_CMD_NOTILEMODE         0x00000020 
#define GCRX_CMD_NOPAPERSPACE       0x00000040 

#define GCRX_CMD_DEPRECATED         GCRX_CMD_UNDEFINED 

#define GCRX_CMD_NOOEM              0x00000100
#define GCRX_CMD_UNDEFINED          0x00000200
#define GCRX_CMD_INPROGRESS         0x00000400
#define GCRX_CMD_DEFUN              0x00000800
#define GCRX_CMD_LISPASCMD          0x00001000 
#define GCRX_CMD_PGPINIT            0x00002000 
#define GCRX_CMD_NONEWSTACK         0x00010000 
#define GCRX_CMD_NOINTERNALLOCK     0x00020000
#define GCRX_CMD_DOCREADLOCK        0x00080000 
#define GCRX_CMD_DOCEXCLUSIVELOCK   0x00100000 
#define GCRX_CMD_SESSION            0x00200000 
#define GCRX_CMD_INTERRUPTIBLE      0x00400000 
#define GCRX_CMD_NOHISTORY          0x00800000 
#define GCRX_CMD_NO_UNDO_MARKER     0x01000000 
#define GCRX_CMD_NOBEDIT            0x02000000 
#define GCRX_CMD_NOACTIONRECORDING  0x04000000 
#define GCRX_CMD_ACTIONMACRO        0x08000000 
#define GCRX_CMD_RELAXASSOC         0x10000000 
#define GCRX_CMD_CORE               0x20000000 
#define GCRX_CMD_NOINFERCONSTRAINT  0x40000000 
#define GCRX_CMD_TEMPSHOWDYNDIM     0x80000000 

#define GCRX_MAX_CMDNAME_LEN  	64

#endif