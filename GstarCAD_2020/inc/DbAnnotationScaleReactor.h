#pragma once

#include "RxObject.h"

class TOOLKIT_EXPORT OdDbAnnotationScaleReactor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbAnnotationScaleReactor);

  virtual void annotationScaleChanged(const OdDbDatabase* pDb,
    const OdDbViewport* pVP,
    const OdDbAnnotationScale* pScale,
    const bool bInitializing);
};
TOOLKIT_EXPORT bool oddbAddAnnotationScaleReactor(OdDbAnnotationScaleReactor* pReactor);
TOOLKIT_EXPORT bool oddbRemoveAnnotationScaleReactor(OdDbAnnotationScaleReactor* pReactor);