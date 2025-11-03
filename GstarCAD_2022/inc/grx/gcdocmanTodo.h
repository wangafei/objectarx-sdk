#pragma once
#include "gcadstrc.h"

GCED_DLL_DECL Gcad::ErrorStatus gcedUpgradeDocOpen();

GCED_DLL_DECL Gcad::ErrorStatus gcedDowngradeDocOpen(bool bPromptForSave);
