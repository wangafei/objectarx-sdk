#pragma once
#include "grxdefs.h"
#include "gcadstrc.h"
#include "..\CmColorBase.h"

class CGcGradientThumbnailEngine
{
public:
  virtual ~CGcGradientThumbnailEngine() {}
  
  virtual Gcad::ErrorStatus gradientThumbnailsSetRotation(double angle) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsSetShift(bool bShifted) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsSetStartColor(GcCmEntityColor startColor) = 0;
  virtual Gcad::ErrorStatus gradientThumbnailsSetStopColor(GcCmEntityColor stopColor) = 0;
  
  virtual Gcad::ErrorStatus  gradientThumbnailsRender(void) = 0;
  virtual Gcad::ErrorStatus  gradientThumbnailsDrawBitmap(int gradientNumber, HDC hDC, int xPos, int yPos) = 0;

};

GCAP_DLL_DECL CGcGradientThumbnailEngine* createGradientThumbnailEngine();

















