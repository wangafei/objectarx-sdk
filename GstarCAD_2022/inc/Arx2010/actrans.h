#pragma once
#include "rxnames.h"
#include "aced.h"
#include "dbptrar.h"
#include "dbtrans.h"
#include "acdocman.h"

#define  AcTransactionManager  GcTransactionManager
#define  GcTransactionManager  OdTransactionManager

#define  actrTransactionManager  gctrTransactionManager
#define  gctrTransactionManager  odtrTransactionManager

#define	 acTransactionManagerPtr gcTransactionManagerPtr
#define	 gcTransactionManagerPtr odTransactionManagerPtr