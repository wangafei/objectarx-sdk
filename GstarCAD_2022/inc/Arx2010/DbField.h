#pragma once

#define AcDbFieldArray                    GcDbFieldArray
#define GcDbFieldArray                    OdDbFieldArray
#define AcFd                              GcFd
#define GcFd                              OdFd
#define AcDbField                         GcDbField
#define GcDbField                         OdDbField
#define AcHyperlink                       GcHyperlink
#define GcHyperlink                       OdHyperlink

#define acdbGetFieldEngine                gcdbGetFieldEngine
#define gcdbGetFieldEngine                oddbGetFieldEngine

#define acdbGetFieldMarkers               gcdbGetFieldMarkers
#define acdbHasFields                     gcdbHasFields
#define acdbFindField                     gcdbFindField
#define acdbEvaluateFields                gcdbEvaluateFields
#define acdbConvertFieldsToText           gcdbConvertFieldsToText
#define acdbMakeFieldCode                 gcdbMakeFieldCode

#include "AdAChar.h"
#include "AcField.h"
#include "acstring.h"
#include "../grx/DbField.h"
#include "../grx/DbFieldTodo.h"



