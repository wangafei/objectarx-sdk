#ifndef _GduiRegistryAccess_h
#define _GduiRegistryAccess_h
#pragma pack (push, 8)

//#include "gdui.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

//////////////////////////////////////////////////////////////////////////////
// Note: These classes are for INTERNAL USE ONLY and may be slated for removal.

class GDUI_PORT CGdUiRegistryAccess // pure virtual class?
{
public:
    // Construction/destruction:
    CGdUiRegistryAccess();
    CGdUiRegistryAccess(HKEY hKey,const CString& sSubkey); // Implicitly opens
    virtual ~CGdUiRegistryAccess();

    // Allows this class to be used anywhere an HKEY is valid...
    operator HKEY() const;

    // Access control: Opens to (another) key.
     virtual BOOL Open(HKEY hKey,const CString &sSubkey);
     virtual void Close();
    BOOL IsOpen();

    // Enumeration mechanism:
    BOOL EnumKeyNames(DWORD dwEntryIndex,CString& sKeyName);
    BOOL EnumValueNames(DWORD dwEntryIndex,CString& sValueName,LPDWORD lpdwType = NULL); // throw CMemoryException*;
    // Note: 1) Enumerate from 0 up to end, or from end back to 0.
    //       2) do not alter the key or value being enumerated during the enumeration
    // (These are caveats presented by the underlying API calls...)

    // returns REG_... types, or REG_NONE if the key doesn't exist.
    DWORD   ValueType(const CString& sValueName,LPDWORD lpdwSize = NULL);

    // GetAccess:
    CString GetString(const CString& sValueName); // throw CMemoryException*;

    // NOTE that GetDWord returns 0 on failure! It also returns 0
    // if the value is indeed 0. BEWARE USING THIS FUNCTION!
    DWORD   GetDWord(const CString&  sValueName);

protected:
    // Derivation for write permission can override this:
    void CommonConstruction();

    HKEY    m_hKey;
    CString m_sSubkey;
};

class GDUI_PORT CGdUiRegistryWriteAccess: public CGdUiRegistryAccess
// Adds write capabilities to the registry access object;
//
// Remember: do not write to keys or values during
// an enumeration loop...  (Registry API limitation)
{
public:
    // Construction/destruction:
    CGdUiRegistryWriteAccess();
    CGdUiRegistryWriteAccess(HKEY hKey,const CString& sSubkey);
    virtual ~CGdUiRegistryWriteAccess();
    virtual BOOL Open(HKEY hKey,const CString& sSubkey);

    BOOL    SetString(const CString& sValueName,const CString& sValue); // throw CMemoryException*;
    BOOL    SetDWord(const CString&  sValueName,DWORD dwValue);
};

class GDUI_PORT CGdUiRegistryDeleteAccess: public CGdUiRegistryWriteAccess
//
// Adds deletion capabilities to the registry access object.
// Deliberately left as a derived class (rather than folded
// into the Write class, because of the potential harm
// possible by accidental use.
//
// Remember: do not delete or write to keys or values during
// an enumeration loop...  (Registry API limitation)
//
{
public:
    CGdUiRegistryDeleteAccess();
    CGdUiRegistryDeleteAccess(HKEY hKey,const CString& sSubkey);
	virtual ~CGdUiRegistryDeleteAccess();

    // Deletes a specific value
    BOOL    DeleteValue(const CString& sValueName);

    // Deletes all values under this key
    BOOL    DeleteAllValues();

    // Deletes a specific subkey; (note: in Win95, this is the same as below)
    BOOL    DeleteKey(const CString&  sKeyName);

    // Deletes a specific subkey, and all sub-keys beneath it (needed in NT)
    BOOL    DeleteKeyAndSubkeys(const CString&  sKeyName); // recursive

    // Deletes all subkeys in the current key; like "del *.* /s" is to DOS (dangerous!)
    BOOL    DeleteAllKeys(); // recursive

};

//////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

//////////////////////////////////////////////////////////////////////////////
