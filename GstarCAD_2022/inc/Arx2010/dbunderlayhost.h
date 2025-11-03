#pragma once

#define AcUnderlayLayer                    GcUnderlayLayer
#define GcUnderlayLayer                    OdUnderlayLayer
#define AcDbUnderlayDrawContext            GcDbUnderlayDrawContext
#define GcDbUnderlayDrawContext            OdDbUnderlayDrawContext
#define AcDbUnderlayItem                   GcDbUnderlayItem
#define GcDbUnderlayItem                   OdDbUnderlayItem
#define AcDbDgnUnderlayItem                GcDbDgnUnderlayItem
#define GcDbDgnUnderlayItem                OdDbDgnUnderlayItem
#define AcDbUnderlayFile                   GcDbUnderlayFile
#define GcDbUnderlayFile                   OdDbUnderlayFile
#define AcDbUnderlayHost                   GcDbUnderlayHost
#define GcDbUnderlayHost                   OdDbUnderlayHost

#define acdbGetCurrentDwfHost              gcdbGetCurrentDwfHost
#define gcdbGetCurrentDwfHost              oddbGetCurrentDwfHost
#define acdbSetCurrentDwfHost              gcdbSetCurrentDwfHost
#define gcdbSetCurrentDwfHost              oddbSetCurrentDwfHost
#define acdbGetCurrentDgnHost              gcdbGetCurrentDgnHost
#define gcdbGetCurrentDgnHost              oddbGetCurrentDgnHost
#define acdbSetCurrentDgnHost              gcdbSetCurrentDgnHost
#define gcdbSetCurrentDgnHost              oddbSetCurrentDgnHost
#define acdbGetCurrentDgnDocHost           gcdbGetCurrentDgnDocHost
#define gcdbGetCurrentDgnDocHost           oddbGetCurrentDgnDocHost
#define acdbSetCurrentDgnDocHost           gcdbSetCurrentDgnDocHost
#define gcdbSetCurrentDgnDocHost           oddbSetCurrentDgnDocHost
#define acdbConvertRgbToHsl                gcdbConvertRgbToHsl
#define gcdbConvertRgbToHsl                oddbConvertRgbToHsl
#define acdbConvertHslToRgb                gcdbConvertHslToRgb
#define gcdbConvertHslToRgb                oddbConvertHslToRgb
#define acdbIsDgnToDwgInProgress           gcdbIsDgnToDwgInProgress
#define gcdbIsDgnToDwgInProgress           oddbIsDgnToDwgInProgress
#define acdbGetCurrentPdfHost              gcdbGetCurrentPdfHost
#define gcdbGetCurrentPdfHost              oddbGetCurrentPdfHost
#define acdbSetCurrentPdfHost              gcdbSetCurrentPdfHost
#define gcdbSetCurrentPdfHost              oddbSetCurrentPdfHost

#include "dbmain.h"
#include "acstring.h"
#include "../grx/dbunderlayhost.h"
#include "../grx/dbunderlayhostTodo.h"


