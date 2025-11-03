/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCPROFILE_H__
#define   _GCPROFILE_H__

#include "gcarray.h"
#include "GdGChar.h"
#include "gcprofile-reactor.h"
#pragma pack (push, 8)

class GcApProfileStorage;
typedef GcArray<GCHAR *> GcApProfileNameArray;

class GcApProfileManager
{
public:
  virtual ~GcApProfileManager() { }

  virtual void ProfileRegistryKey(GCHAR *& strRegProfileKey,
    const GCHAR * strProfileName) = 0;
  virtual Gcad::ErrorStatus ProfileStorage(GcApProfileStorage*& pStore,
    const GCHAR * strProfileName,
    BOOL bCreateIfNotExists = TRUE) = 0;
  virtual Gcad::ErrorStatus FixedProfileStorage(GcApProfileStorage*& pStore,
    BOOL bCreateIfNotExists = TRUE) = 0;
  virtual int ProfileListNames(GcApProfileNameArray& nameList) = 0;
  virtual Gcad::ErrorStatus ProfileExport(const GCHAR * strProfileName,
    const GCHAR * exportFileName) = 0;
  virtual Gcad::ErrorStatus ProfileImport(const GCHAR * strProfileName,
    const GCHAR * importFileName,
    const GCHAR * profileDescription,
    Gsoft::Boolean bImportPathInfo) = 0;
  virtual Gcad::ErrorStatus ProfileDelete(const GCHAR * strProfileName) = 0;
  virtual Gcad::ErrorStatus ProfileReset(const GCHAR * strProfileName) = 0;
  virtual Gcad::ErrorStatus ProfileSetCurrent(const GCHAR * strProfileName) = 0;
  virtual Gcad::ErrorStatus ProfileCopy(const GCHAR * newProfileName,
    const GCHAR * oldProfileName,
    const GCHAR * newProfileDesc) = 0;
  virtual Gcad::ErrorStatus ProfileRename(const GCHAR * newProfileName,
    const GCHAR * oldProfileName,
    const GCHAR * newProfileDesc) = 0;
  virtual void addReactor(GcApProfileManagerReactor*) = 0;
  virtual void removeReactor(GcApProfileManagerReactor*) = 0;
};

GCCORE_PORT GcApProfileManager* gcProfileManagerPtr();
#define gcProfileManager gcProfileManagerPtr()

class GcApProfileStorage
{
public:
  virtual ~GcApProfileStorage() {}
  virtual Gcad::ErrorStatus CreateNode(const GCHAR * pszNodePath,
    IUnknown*& pUnknown) = 0;
  virtual Gcad::ErrorStatus GetNode(const GCHAR * pszNodePath,
    IUnknown*& pUnknown) = 0;
  virtual Gcad::ErrorStatus ReplaceNode(const GCHAR * pszNodePath,
    IUnknown* pUnknown) = 0;
  virtual Gcad::ErrorStatus DeleteNode(const GCHAR * pszNodePath) = 0;
  virtual Gcad::ErrorStatus GetStorageFile(GcString& pszFile) = 0;
  virtual Gcad::ErrorStatus Save(void) = 0;
};

#pragma pack (pop)
#endif 