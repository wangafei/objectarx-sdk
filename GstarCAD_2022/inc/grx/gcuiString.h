#ifndef _GcuiString_h
#define _GcuiString_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CGcUiString : public CString
{
public:
	GDUI_PORT CGcUiString ();
	GDUI_PORT CGcUiString (const CString& stringSrc);
	GDUI_PORT CGcUiString (TCHAR ch, int nRepeat = 1);
	GDUI_PORT CGcUiString (LPCTSTR psz);
	GDUI_PORT CGcUiString (LPCTSTR pch, int nLength);
	GDUI_PORT CGcUiString (UINT nStringResourceID);

	GDUI_PORT BOOL    IsTab (int nIndex)          const;
	GDUI_PORT BOOL    IsWhiteSpace (int nIndex)   const;
	GDUI_PORT BOOL    IsAlphabetic (int nIndex)   const;
	GDUI_PORT BOOL    IsAlphanumeric (int nIndex) const;
	GDUI_PORT BOOL    IsBlank (int nIndex)        const;
	GDUI_PORT BOOL    IsPunctuation (int nIndex)  const;
	GDUI_PORT BOOL    IsUppercase (int nIndex)    const;
	GDUI_PORT BOOL    IsLowercase (int nIndex)    const;
	GDUI_PORT BOOL    IsNumeric (int nIndex)      const;
	GDUI_PORT BOOL    IsHexNumeric (int nIndex)   const;

	GDUI_PORT void    MakeCharUpper (int nIndex);
	GDUI_PORT void    MakeCharLower (int nIndex);
	GDUI_PORT void    GetCurrentWorkingDirectory ();
	GDUI_PORT void    ReplaceCharWithChar (TCHAR chFrom, TCHAR chTo);

	GDUI_PORT void    StripMnemonic ();
	GDUI_PORT void    StripDiesel ();
	GDUI_PORT void    ConvertMenuExecString ();
	GDUI_PORT void    ConvertFromMenuExecString ();
	GDUI_PORT void    FixFileName ();
	GDUI_PORT void    WrapLine (CGcUiString& strRest, int nWrapAt);
	GDUI_PORT void    WrapLine (CStringList& strListWrapped, int nWrapAt);
	GDUI_PORT void    ExpandTabs (int nTabSize = 8);

	GDUI_PORT void    StripTrailingBlanks  ();
	GDUI_PORT void    StripPrecedingBlanks ();
	GDUI_PORT void    StripTrailingCharacters  (TCHAR cChar);
	GDUI_PORT void    StripPrecedingCharacters (TCHAR cChar);

	GDUI_PORT void    ShortenString ( CDC *pDC, CString OriginalString,	UINT width );
	GDUI_PORT CString CreateEllipsedString ( CDC *pDC, CString OriginalString, UINT width );
};

class CGcUiStringExp : public CGcUiString
{
public:
	GDUI_PORT CGcUiStringExp ();
	GDUI_PORT CGcUiStringExp (const CString& stringSrc);
	GDUI_PORT CGcUiStringExp (TCHAR ch, int nRepeat = 1);
	GDUI_PORT CGcUiStringExp (LPCTSTR psz);
	GDUI_PORT CGcUiStringExp (LPCTSTR pch, int nLength);
	GDUI_PORT CGcUiStringExp (UINT nStringResourceID);

public:
	GDUI_PORT virtual BOOL LoadString(UINT nID);
	GDUI_PORT void    ReplaceProductMacroStrings();
};

#pragma pack (pop)
#endif