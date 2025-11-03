/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef     _GCGRADTHUMB_H
#define     _GCGRADTHUMB_H

#include "dbcolor.h"

class CGcGradientThumbnailEngine
{
public:
  virtual ~CGcGradientThumbnailEngine() {};

  virtual Gcad::ErrorStatus gradientThumbnailsSetRotation(double angle) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsSetShift(bool bShifted) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsSetStartColor(GcCmEntityColor startColor) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsSetStopColor(GcCmEntityColor stopColor) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsRender(void) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsDrawBitmap(int gradientNumber, HDC hDC, int xPos, int yPos) = 0;
};

GCAD_PORT CGcGradientThumbnailEngine *createGradientThumbnailEngine();

#endif 