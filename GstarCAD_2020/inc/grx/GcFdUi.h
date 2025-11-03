#pragma once
#include "gcadstd.h"
#include "DbField.h"
#include <afxwin.h>

class CGcFdUiFieldManager;

GCED_DLL_DECL CGcFdUiFieldManager* GcFdUiGetFieldManager(void);

GCED_DLL_DECL int GcFdUiInvokeFieldDialog(GcDbField*& pNewField, BOOL bEdit, GcDbDatabase* pDb, CWnd* pParent = NULL);