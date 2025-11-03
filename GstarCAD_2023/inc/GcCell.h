/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

typedef struct GcCell
{
  int     mnRow;
  int     mnColumn;

} GcCell;

typedef GcArray<GcCell> GcCellArray;

typedef struct GcCellRange
{
  int     mnTopRow;
  int     mnLeftColumn;
  int     mnBottomRow;
  int     mnRightColumn;
  bool operator==(const GcCellRange& other) const;
} GcCellRange;
typedef GcArray<GcCellRange> GcCellRangeArray;