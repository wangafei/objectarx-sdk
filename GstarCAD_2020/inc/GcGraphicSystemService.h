
#ifndef __GCAD__GRAPHICS_SYSTEM_SERVICES__INCLUDED__
#define __GCAD__GRAPHICS_SYSTEM_SERVICES__INCLUDED__

#include "OdaCommon.h"
#include "RxObject.h"
#include "RxSysRegistry.h"

class GcPlotInterface;
class OdGsBaseModule;


class GcadGraphicSystemService : public OdRxObject
{
public:
  virtual GcPlotInterface* plotInterface() = 0;
  virtual OdGsBaseModule*  baseGsModule() = 0;
};


#define GCAD_GRAPHICSYS_SERVICE OD_T("GcadGraphicsSystemService")

inline GcadGraphicSystemService* gcadGraphicSysService()
{
  return static_cast<GcadGraphicSystemService*>(odrxSysRegistry()->getAt(GCAD_GRAPHICSYS_SERVICE).get());
}


#endif // __GCAD__GRAPHICS_SYSTEM_SERVICES__INCLUDED__

