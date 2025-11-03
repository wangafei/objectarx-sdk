/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _DBOSNAP2_H
#define _DBOSNAP2_H

#include "dbosnap.h"

class GcDbCustomOsnapMode2 : public GcDbCustomOsnapMode {
public:
  virtual HICON menuIcon()
  {
    return NULL;
  }

  virtual HICON menuIconForDarkTheme()
  {
    return NULL;
  }

  virtual const GCHAR * displayString()
  {
    return localModeString();
  }
};

#endif 