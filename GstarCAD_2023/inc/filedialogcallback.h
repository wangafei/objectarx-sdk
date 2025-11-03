/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

class CGcUiNavDialog;

typedef void(*FileDiaCallbackFuncPtr)(CGcUiNavDialog*);

GCCORE_PORT void gcedRegisterNavDialogCallbackFunction(FileDiaCallbackFuncPtr funcPtr);
GCCORE_PORT void gcedUnregisterNavDialogCallbackFunction(FileDiaCallbackFuncPtr funcPtr);
