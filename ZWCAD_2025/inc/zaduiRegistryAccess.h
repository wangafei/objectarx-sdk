
#pragma once

#ifdef ZCUTIL_INTERNAL

//#include	"fake_windows_zaccore.h"	
#ifdef ZDUI_PORT
#undef ZDUI_PORT
#endif
#ifdef ZCCORE_BUILD
#define ZDUI_PORT __declspec(dllexport)
#else
#define ZDUI_PORT
#endif
#endif

#ifndef ZDUI_PORT
#define ZDUI_PORT
#endif

#pragma pack (push, 8)

class ZDUI_PORT CZdUiRegistryAccess
{
public:

    CZdUiRegistryAccess();
    CZdUiRegistryAccess(HKEY hKey,const CString& sSubkey);
    virtual ~CZdUiRegistryAccess();

    operator HKEY() const;

    virtual BOOL Open(HKEY hKey,const CString &sSubkey);
    virtual void Close();
    BOOL IsOpen();

    BOOL EnumKeyNames(DWORD dwEntryIndex,CString& sKeyName);
    BOOL EnumValueNames(DWORD dwEntryIndex,CString& sValueName,LPDWORD lpdwType = NULL);

    DWORD   ValueType(const CString& sValueName,LPDWORD lpdwSize = NULL);

    CString GetString(const CString& sValueName);

    DWORD   GetDWord(const CString&  sValueName);

    DWORD   GetDWordWithDefaultValue(const CString &sValueName, DWORD dwDefault);

    BOOL    GetBinary(const CString& sValueName, LPBYTE pbData, DWORD& dwSize);

protected:

    void CommonConstruction();

    HKEY    m_hKey;
    CString m_sSubkey;

};

class ZDUI_PORT CZdUiRegistryWriteAccess: public CZdUiRegistryAccess

{
public:

    CZdUiRegistryWriteAccess();
    CZdUiRegistryWriteAccess(HKEY hKey,const CString& sSubkey);
    virtual ~CZdUiRegistryWriteAccess();

    virtual BOOL Open(HKEY hKey,const CString& sSubkey) override;

    BOOL    SetString(const CString& sValueName,const CString& sValue); 
    BOOL    SetDWord(const CString&  sValueName, DWORD dwValue);
    BOOL    SetBinary(const CString& sValueName, const BYTE* pbData, DWORD dwLen);
};

class ZDUI_PORT CZdUiRegistryDeleteAccess: public CZdUiRegistryWriteAccess

{
public:
    CZdUiRegistryDeleteAccess();
    CZdUiRegistryDeleteAccess(HKEY hKey,const CString& sSubkey);
    virtual ~CZdUiRegistryDeleteAccess();

    BOOL    DeleteValue(const CString& sValueName);

    BOOL    DeleteAllValues();

    BOOL    DeleteKey(const CString&  sKeyName);

    BOOL    DeleteKeyAndSubkeys(const CString&  sKeyName);

    BOOL    DeleteAllKeys();

};

#pragma pack (pop)

