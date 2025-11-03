/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GMODELER_INC_COLOR_H
#define GMODELER_INC_COLOR_H

#include "global.h"

GMODELER_NAMESPACE_BEGIN

enum Color
{
  kColor1         = 1,
  kColor2         = 2,
  kColor3         = 3,
  kColor4         = 4,
  kColorInvisible = -1
};

DllImpExp extern Color gDefaultColor;

inline Color defaultColor() { return gDefaultColor; }
inline void  setDefaultColor(Color co) { gDefaultColor = co; }

GMODELER_NAMESPACE_END
#endif
