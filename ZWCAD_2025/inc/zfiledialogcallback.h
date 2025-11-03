
#pragma once




class CZcUiNavDialog;

typedef void (*FileDiaCallbackFuncPtr)(CZcUiNavDialog*);

ZCAD_PORT void zcedRegisterNavDialogCallbackFunction(FileDiaCallbackFuncPtr funcPtr);
ZCAD_PORT void zcedUnregisterNavDialogCallbackFunction(FileDiaCallbackFuncPtr funcPtr);


