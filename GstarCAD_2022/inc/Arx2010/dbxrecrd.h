#pragma once

#define AcDbXrecord                     GcDbXrecord
#define GcDbXrecord                     OdDbXrecord
#define AcDbXrecordIterator             GcDbXrecordIterator
#define GcDbXrecordIterator             OdDbXrecordIterator

#define ACDB_XRECORD_CLASS              GCDB_XRECORD_CLASS
#define GCDB_XRECORD_CLASS              ODDB_XRECORD_CLASS
#define ACDB_XRECORD_ITERATOR_CLASS     GCDB_XRECORD_ITERATOR_CLASS
#define GCDB_XRECORD_ITERATOR_CLASS     ODDB_XRECORD_ITERATOR_CLASS

#include "AdAChar.h"
#include "dbmain.h"
#include "../DbXrecord.h"

#define ODDB_XRECORD_ITERATOR_CLASS     "OdDbXrecordClass"
