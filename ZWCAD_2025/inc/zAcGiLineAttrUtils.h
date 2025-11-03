

#pragma once

#include "zacdb.h"
#include "zAcDbCore2dDefs.h"

class ZCDBCORE2D_PORT ZcGiLineAttrUtils
{
public:
    static char zcgiLineWeightToIndex(ZcDb::LineWeight lw); 
    static ZcDb::LineWeight zcgiIndexToLineWeight(char index); 
};
