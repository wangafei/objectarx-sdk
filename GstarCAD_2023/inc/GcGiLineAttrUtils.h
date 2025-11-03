/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcdb.h"

class GCCORE_PORT GcGiLineAttrUtils
{
public:
  static char gcgiLineWeightToIndex(GcDb::LineWeight lw);
  static GcDb::LineWeight gcgiIndexToLineWeight(char index);
};