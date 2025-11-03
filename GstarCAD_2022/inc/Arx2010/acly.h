#pragma once
#include "AdAChar.h"
#include "acadstrc.h"
#include "acarray.h"
#include "dbsymtb.h"
#include "dbxrecrd.h"
#include "../LyLayerFilter.h"

#define AcLyRelExpr GcLyRelExpr
#define GcLyRelExpr OdLyRelExpr

#define AcLyAndExpr GcLyAndExpr
#define GcLyAndExpr OdLyAndExpr

#define AcLyBoolExpr GcLyBoolExpr
#define GcLyBoolExpr OdLyBoolExpr

#define	AcLyLayerFilter GcLyLayerFilter
#define	GcLyLayerFilter OdLyLayerFilter

#define	AcLyLayerFilterManager GcLyLayerFilterManager
#define	GcLyLayerFilterManager OdLyLayerFilterManager

#define	AcLyLayerGroup GcLyLayerGroup
#define	GcLyLayerGroup OdLyLayerGroup

#define	aclyGetLayerFilterManager gclyGetLayerFilterManager
#define	gclyGetLayerFilterManager odlyGetLayerFilterManager