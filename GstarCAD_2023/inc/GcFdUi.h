/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#if _MSC_VER > 1000
#pragma once
#endif 

#ifdef  GCFD_API
#  define   GCFDUI_PORT  __declspec(dllexport)
#else
#  define   GCFDUI_PORT  
#endif

class CGcFdUiFieldManager;
class GcDbField;
class GcDbDatabase;

#define GCFDUI_CATEGORY_ID_ALL              -1
#define GCFDUI_CATID_USER_FIRST             1000
#define GCFDUI_FIELDID_USER_FIRST           50000

GCAD_PORT CGcFdUiFieldManager* GcFdUiGetFieldManager(void);
GCAD_PORT int GcFdUiInvokeFieldDialog(GcDbField*& pNewField,
  BOOL bEdit,
  GcDbDatabase* pDb,
  CWnd* pParent = NULL);