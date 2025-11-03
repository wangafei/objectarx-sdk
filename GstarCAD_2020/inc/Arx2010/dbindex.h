#pragma once

#define AcDbIndex  GcDbIndex
#define GcDbIndex  OdDbIndex

#define AcDbBlockIterator  GcDbBlockIterator
#define GcDbBlockIterator  OdDbBlockIterator

#define AcDbFilteredBlockIterator  GcDbFilteredBlockIterator
#define GcDbFilteredBlockIterator  OdDbFilteredBlockIterator

#define AcDbCompositeFilteredBlockIterator  GcDbCompositeFilteredBlockIterator
#define GcDbCompositeFilteredBlockIterator  OdDbCompositeFilteredBlockIterator

#define AcDbIndexUpdateData  GcDbIndexUpdateData
#define GcDbIndexUpdateData  OdDbIndexUpdateData

#define AcDbIndexUpdateDataIterator  GcDbIndexUpdateDataIterator
#define GcDbIndexUpdateDataIterator  OdDbIndexUpdateDataIterator

#define AcDbBlockChangeIterator  GcDbBlockChangeIterator
#define GcDbBlockChangeIterator  OdDbBlockChangeIterator

#define AcDbIndexFilterManager  GcDbIndexFilterManager
#define GcDbIndexFilterManager  OdDbIndexFilterManager

#include "dbmain.h"
#include "../DbBlockIterator.h"
#include "../DbIndex.h"
#include "../DbIndexCompositeFilteredBlockIterator.h"
