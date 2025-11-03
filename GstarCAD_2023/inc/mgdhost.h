/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#include "gsoft.h"
#include "gcdbport.h"
#include "mgdhost-core2d.h"

#ifndef MGDHOST_H
#define MGDHOST_H 1
#pragma once

GCCORE_PORT HRESULT GSOFT_STDCALL gcdbInitializeManagedLayer();
GCCORE_PORT HRESULT GSOFT_STDCALL gcdbTerminateManagedLayer();

#endif
