/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCPLPLOTREACTORMGR_H
#define GCPLPLOTREACTORMGR_H

#include "GcPl.h"

class GSOFT_NO_VTABLE GcPlPlotReactorMgr
{
public:
  GCPL_PORT void addReactor(GcPlPlotReactor* pReactor);
  GCPL_PORT void removeReactor(GcPlPlotReactor* pReactor);
};

GCPL_PORT GcPlPlotReactorMgr* __stdcall gcplPlotReactorMgrPtr();
#define gcplPlotReactorMgr gcplPlotReactorMgrPtr()

#endif 