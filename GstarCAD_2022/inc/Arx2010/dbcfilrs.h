#pragma once

#define AcDbDeepCloneFiler    GcDbDeepCloneFiler
#define GcDbDeepCloneFiler    OdDbDeepCloneFiler

#define AcDbWblockCloneFiler  GcDbWblockCloneFiler
#define GcDbWblockCloneFiler  OdDbWblockCloneFiler

#define	readAcDbHandle 	readGcDbHandle
#define	readGcDbHandle 	readOdDbHandle

#define	writeAcDbHandle writeGcDbHandle
#define	writeGcDbHandle writeOdDbHandle

#include "dbfiler.h"
#include "../CloneFilers.h"