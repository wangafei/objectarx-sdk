#pragma once

#include "dbTableStyle.h"

#define AcCellRange  GcCellRange
#define GcCellRange  OdCellRange
#define AcCell GcCell

typedef struct GcCell
{
  int     mnRow;
  int     mnColumn;
} GcCell;

typedef OdArray<OdCellRange> OdCellRangeArray;