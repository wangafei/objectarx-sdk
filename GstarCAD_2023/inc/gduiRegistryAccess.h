/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _gduiRegistryAccess_h
#define _gduiRegistryAccess_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif 

#ifdef GCUTIL_INTERNAL
#ifdef GDUI_PORT
#undef GDUI_PORT
#endif
#ifdef GCCORE_BUILD
#define GDUI_PORT __declspec(dllexport)
#else
#define GDUI_PORT
#endif
#endif

#ifndef GDUI_PORT
#define GDUI_PORT
#endif

class GCAD_PORT CGdUiRegistryAccess
{
public:
  CGdUiRegistryAccess();
  CGdUiRegistryAccess(HKEY hKey, const CString& sSubkey);
  virtual ~CGdUiRegistryAccess();

  operator HKEY() const;

  virtual BOOL Open(HKEY hKey, const CString &sSubkey);
  virtual void Close();
  BOOL IsOpen();

  BOOL EnumKeyNames(DWORD dwEntryIndex, CString& sKeyName);
  BOOL EnumValueNames(DWORD dwEntryIndex, CString& sValueName, LPDWORD lpdwType = NULL);

  DWORD   ValueType(const CString& sValueName, LPDWORD lpdwSize = NULL);
  CString GetString(const CString& sValueName);
  DWORD   GetDWord(const CString&  sValueName);
  DWORD   GetDWordWithDefaultValue(const CString &sValueName, DWORD dwDefault);
  BOOL    GetBinary(const CString& sValueName, LPBYTE pbData, DWORD& dwSize);

protected:
  void CommonConstruction();

  HKEY    m_hKey;
  CString m_sSubkey;

};

class GCAD_PORT CGdUiRegistryWriteAccess : public CGdUiRegistryAccess
{
public:
  CGdUiRegistryWriteAccess();
  CGdUiRegistryWriteAccess(HKEY hKey, const CString& sSubkey);
  ~CGdUiRegistryWriteAccess();

  BOOL Open(HKEY hKey, const CString& sSubkey) override;
  BOOL    SetString(const CString& cValueName, const CString& sValue);
  BOOL    SetDWord(const CString&  sValueName, DWORD dwValue);
  BOOL    SetBinary(const CString& sValueName, const BYTE* pbData, DWORD dwLen);
};

class GCAD_PORT CGdUiRegistryDeleteAccess : public CGdUiRegistryWriteAccess
{
public:
  CGdUiRegistryDeleteAccess();
  CGdUiRegistryDeleteAccess(HKEY hKey, const CString& sSubkey);
  ~CGdUiRegistryDeleteAccess();

  BOOL    DeleteValue(const CString& sValueName);
  BOOL    DeleteAllValues();
  BOOL    DeleteKey(const CString&  sKeyName);
  BOOL    DeleteKeyAndSubkeys(const CString&  sKeyName);
  BOOL    DeleteAllKeys();
};

#pragma pack (pop)
#endif
