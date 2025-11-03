#pragma once

#define AcDbEvalVariant         GcDbEvalVariant

#define AcDbEvalIdMap           GcDbEvalIdMap
#define GcDbEvalIdMap           OdDbEvalIdMap

#define AcDbEvalGraph           GcDbEvalGraph
#define GcDbEvalGraph           OdDbEvalGraph

#define AcDbEvalEdgeInfo        GcDbEvalEdgeInfo
#define GcDbEvalEdgeInfo        OdDbEvalEdgeInfo

#define AcDbEvalExpr            GcDbEvalExpr
#define GcDbEvalExpr            OdDbEvalExpr

#define AcDbEvalConnectable     GcDbEvalConnectable
#define GcDbEvalConnectable     OdDbEvalConnectable

#define AcDbEvalContext         GcDbEvalContext
#define GcDbEvalContext         OdDbEvalContext

#define AcDbEvalContextPair     GcDbEvalContextPair
#define GcDbEvalContextPair     OdDbEvalContextPair

#define AcDbEvalContextIterator GcDbEvalContextIterator
#define GcDbEvalContextIterator OdDbEvalContextIterator

#include "dbmain.h"
#include "dbents.h"
#include "acstring.h"
#include "adscodes.h"
#include "adsdef.h"

#include "../DbEvalGraph.h"
#include "../DbEvalVariant.h"
#include "../DbEvalIdMap.h"
