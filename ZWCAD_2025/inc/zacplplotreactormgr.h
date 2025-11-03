

#ifndef ZCPLPLOTREACTORMGR_H
#define ZCPLPLOTREACTORMGR_H

#include "zacpl.h"

class ZCPL_PORT ZSOFT_NO_VTABLE ZcPlPlotReactorMgr
{
public:

    void addReactor(ZcPlPlotReactor* pReactor);

    void removeReactor(ZcPlPlotReactor* pReactor);
};

ZCPL_PORT ZcPlPlotReactorMgr* __stdcall zcplPlotReactorMgrPtr();
#define zcplPlotReactorMgr zcplPlotReactorMgrPtr()

#endif 
