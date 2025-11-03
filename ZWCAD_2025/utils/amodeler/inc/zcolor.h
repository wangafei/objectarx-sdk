#ifndef AECMODELER_INC_COLOR_H
#define AECMODELER_INC_COLOR_H


#include "zglobal.h"

AECMODELER_NAMESPACE_BEGIN


enum ZwColor { kColor1            = 1, 
             kColor2            = 2,
             kColor3            = 3,
             kColor4            = 4, 
             kColorInvisible    = -1 };


DllImpExp extern ZwColor gDefaultColor;


inline ZwColor defaultColor   ()         { return gDefaultColor; }
inline void  setDefaultColor(ZwColor co) { gDefaultColor = co;   }
 
AECMODELER_NAMESPACE_END
#endif
