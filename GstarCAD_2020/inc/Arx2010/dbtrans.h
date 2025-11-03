#pragma once

#define AcDbTransactionManager          GcDbTransactionManager
#define GcDbTransactionManager          OdDbTransactionManager
#define AcTransaction                   GcTransaction
#define GcTransaction                   OdTransaction
#define AcTransactionReactor            GcTransactionReactor
#define GcTransactionReactor            OdTransactionReactor

#define acdbTransactionManagerPtr       gcdbTransactionManagerPtr
#define gcdbTransactionManagerPtr       oddbTransactionManagerPtr
#define acdbTransactionManager          gcdbTransactionManager
#define gcdbTransactionManager          oddbTransactionManager


#include "dbapserv.h"
#include "../DbTransact.h"
#include "../DbTransactionReactor.h"
