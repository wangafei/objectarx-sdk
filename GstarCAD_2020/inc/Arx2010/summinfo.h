#pragma once

#define	AcDbDatabaseSummaryInfo                GcDbDatabaseSummaryInfo
#define	GcDbDatabaseSummaryInfo                OdDbDatabaseSummaryInfo
#define acdbGetSummaryInfo                     gcdbGetSummaryInfo
#define gcdbGetSummaryInfo                     oddbGetSummaryInfo
#define acdbPutSummaryInfo                     gcdbPutSummaryInfo
#define gcdbPutSummaryInfo                     oddbPutSummaryInfo
#define acdbValidateCustomSummaryInfoKey       gcdbValidateCustomSummaryInfoKey
#define gcdbValidateCustomSummaryInfoKey       oddbValidateCustomSummaryInfoKey
#define	AcDbSummaryInfoReactor                 GcDbSummaryInfoReactor
#define	GcDbSummaryInfoReactor                 OdDbSummaryInfoReactor
#define	AcDbSummaryInfoManager                 GcDbSummaryInfoManager
#define	GcDbSummaryInfoManager                 OdDbSummaryInfoManager
#define	acDbSummaryInfoManager                 gcDbSummaryInfoManager
#define	gcDbSummaryInfoManager                 oddbSummaryInfoManager
#define	initAcDbSummaryInfoManager             initGcDbSummaryInfoManager
#define	initGcDbSummaryInfoManager             initOdDbSummaryInfoManager
#define	deleteAcDbSummaryInfoManager           deleteGcDbSummaryInfoManager
#define	deleteGcDbSummaryInfoManager           deleteOdDbSummaryInfoManager

#include "adesk.h"
#include "eoktest.h"
#include "../summinfo.h"


