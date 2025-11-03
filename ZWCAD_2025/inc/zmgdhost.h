
#include "zadesk.h"
#include "zacdbport.h"
#include "zmgdhost-core2d.h"

#ifndef ZMGDHOST_H
#define ZMGDHOST_H 1
#pragma once

ZCDB_PORT HRESULT ZSOFT_STDCALL zcdbInitializeManagedLayer();
ZCDB_PORT HRESULT ZSOFT_STDCALL zcdbTerminateManagedLayer();

#endif 
