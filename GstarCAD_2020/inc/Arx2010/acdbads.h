#pragma once
#include "adsdef.h"
#include "acmem.h"
#include "AdAChar.h"
#include "../grx/gcdbgds.h"

#define	acdbFail		gds_fail
#define	gds_fail	gcdbFail
#define acdbXdRoom		gds_xdroom
#define	gds_xdroom	gcdbXdRoom
#define acdbXdSize		gds_xdsize
#define	gds_xdsize	gcdbXdSize
#define acdbHandEnt		gds_handent
#define	gds_handent	gcdbHandEnt
#define acdbXStrSave	gds_xstrsave
#define	gds_xstrsave	gcdbXStrSave
#define acdbXStrCase	gds_xstrcase
#define	gds_xstrcase	gcdbXStrCase
#define acdbNameSet     gcdbNameSet