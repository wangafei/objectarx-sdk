

#pragma once

#include "zadesk.h"
#include "zacbasedefs.h"
#include "zaduipathenums.h"
#include "zAcString.h"
#include <cstdio> 

typedef void * HANDLE;

#pragma pack (push, 8)


#ifndef _ZSOFT_MAC_
#define  MAX_PATH 260
#endif

class CZdUiVolumeDescriptor;

ZCBASE_PORT ZcString GetDriveForRoottypePath(const CZdUiVolumeDescriptor* const);
ZCBASE_PORT bool WasAbsoluteHelper(path_category pc);
ZCBASE_PORT bool IsValidOnColon(const ZcString* work);


namespace ZwSoft
{
	namespace ZwCAD
	{
		namespace PAL
		{
			namespace FileIO
			{
				class File;
			}
		}
	}
}


extern __declspec(selectany) const ZTCHAR kBackslash = ZCRX_T('\\');
extern __declspec(selectany) const ZTCHAR kColon = ZCRX_T(':');
extern __declspec(selectany) const ZTCHAR kDoubleQuote = ZCRX_T('"');
extern __declspec(selectany) const ZTCHAR kEOS = ZCRX_T('\0');
extern __declspec(selectany) const ZTCHAR kPeriod = ZCRX_T('.');
extern __declspec(selectany) const ZTCHAR kSlash = ZCRX_T('/');
extern __declspec(selectany) const ZTCHAR kSpace = ZCRX_T(' ');
extern __declspec(selectany) const ZTCHAR kAsterisk = ZCRX_T('*');
extern __declspec(selectany) const ZTCHAR kQuestionmark = ZCRX_T('?');
extern __declspec(selectany) const ZTCHAR kZero = ZCRX_T('0');


class ZCBASE_PORT CZdUiPathname {	

	
	friend void GetDisplayNameHelper(
		const CZdUiPathname* pPathName, 
		ZcString& strResult, 
		int maxchars );

	friend CZdUiVolumeDescriptor* NewVolDescriptorHelper(
		const CZdUiPathname* pPathName, 
		const ZcString& vol_name);

	friend bool IsPathValid(
		CZdUiPathname* pPathName,
		const CZdUiPathname* rel_path,
		const ZcString* work);

	friend void HandleSpecialPath(
		CZdUiPathname* pPathName, 
		const CZdUiPathname* rel_path, 
		ZcString* work, 
		int index, 
		bool wildcard_ok);

	friend bool IsValidOnColon(const ZcString* work);

	friend void SetupVolForRoottypePath(
		CZdUiPathname* pPathName,
		const CZdUiPathname* pRelPath,
		const wchar_t * pPathStr);

	friend ZcString GetDriveForRoottypePath(const CZdUiVolumeDescriptor* );

	friend bool WasAbsoluteHelper(path_category pc);

public:

        CZdUiPathname(void);
        CZdUiPathname(const CZdUiPathname&);

        virtual ~CZdUiPathname(void);

        void Empty(void);
		
		virtual PathErr Parse( const wchar_t *, bool wildcard_ok = false );

        PathErr ParseRelative( const wchar_t * name,
                               const CZdUiPathname* relpath,
                               bool wildcard_ok = false );

        bool ParseAndOSFind( const wchar_t * );
	
        const CZdUiPathname& operator=(const CZdUiPathname& pathSrc);
        const CZdUiPathname& operator=(const CZdUiPathname* pathSrc);

        bool GetUniqueName(CZdUiPathname&, 
                               bool alwaysMangle = false ) const;

        void GetFilename(ZcString&) const;

        void GetExtension(ZcString&) const;

        void GetBasename(ZcString&) const;

        void GetParent(CZdUiPathname& ) const;

        PathErr Trim(void);

        PathErr TrimSlash(void);

        PathErr TrimComponent(void);

        PathErr Append( const wchar_t * );	

        PathErr AppendSlash(void);

        PathErr AppendComponent( const wchar_t * );

        PathErr AddExtensionAlways( const wchar_t * );

        PathErr AddExtensionIfNoMatch( const wchar_t * );

        PathErr ReplaceExtensionAlways( const wchar_t * );

        PathErr ReplaceExtensionIfNoMatch( const wchar_t * );

        void RemoveExtensionAlways(void);

        void RemoveExtensionIfMatch( const wchar_t * );	

        void BaseToLower( void );
        void BaseToUpper( void );

        void RemoveSpaces( void );

        void GetDisplayName( ZcString& strResult, int maxchars ) const;

        const wchar_t *  GetPathString(void) const;	

        bool GetFullPath( ZcString& ) const;	
        bool GetFullPath( wchar_t * pBuf, size_t strBuffLen) const;	
		template<size_t nBufLen> inline bool GetFullPath(wchar_t(& buf)[nBufLen]) const
		{
			return this->GetFullPath(buf, nBufLen);
		}

        void GetFullUNCPath(ZcString&) const;

        bool IsPath(void) const;		

        bool IsEmpty(void) const;	

        path_type GetPathType(void) const;

        const CZdUiVolumeDescriptor* GetVolumeDescriptor(void) const;

        bool PathMatch( const CZdUiPathname* ) const;
        bool PathMatch( const wchar_t * ) const;

        bool Exists(void);

        bool VerifyExtension( const wchar_t * extlist ) const;

        bool HadPrefix(void) const;

        bool WasAbsolute(void) const;

        bool WasRoot(void) const;

       ZSOFT_DEPRECATED bool Open(FILE** fdp, const ZTCHAR *openmode);

        bool OpenReadOnly(ZwSoft::ZwCAD::PAL::FileIO::File  & );
        bool OpenWriteOnly(ZwSoft::ZwCAD::PAL::FileIO::File  & );
        bool OpenReadOnly(HANDLE &rFileHandle);  
		bool OpenWriteOnly(HANDLE &rFileHandle);  

        bool Rename(const ZTCHAR *newname);

        bool Remove(void);

		path_status Status();	

protected:

        path_type                       m_this_type;

        const CZdUiVolumeDescriptor*        m_pvolume;

        ZcString*                        m_pathbuffer;

        ZcString*                        m_relpath;

        path_category                   m_path_cat;

        ZTCHAR                           m_separator;

        bool                            m_had_prefix;

        const CZdUiVolumeDescriptor* FindVolumeDescriptor(const ZcString& vol_name) const;

        const CZdUiVolumeDescriptor* NewVolDescriptor( const ZcString& vol_name) const;

        FS_TYPE GetFileSystem(ZcString& vol_name) const;

       inline bool IsDeviceName(const ZcString& str) const;

        static void Unquote( ZcString& );

        ZTCHAR GetSeparator(void) const;

virtual void AssignCopy( const CZdUiPathname& );

        static ZTCHAR GetLastCharacter( const ZcString& );
        
private:

        void GetFirstExtInList( const wchar_t *, ZcString&) const;	

        void lstrncpy_x( wchar_t * dest, size_t destnChars, const wchar_t * src, int srcnChars) const;		
        void StripSpaces(ZcString& work);
        void GetAttributes(const ZcString* path,
                const ZcString* relpath,
                path_type* this_type);
};

inline CZdUiPathname::CZdUiPathname(const CZdUiPathname& pathSrc)
{
        m_pathbuffer = nullptr;
        m_relpath = nullptr;

        AssignCopy( pathSrc );
}

inline path_type CZdUiPathname::GetPathType(void) const
{
        return m_this_type;
}

inline bool CZdUiPathname::IsPath(void) const
{
        return ((m_this_type == FILE_PATH)
                || (m_this_type == DIR_PATH)
                || (m_this_type == NEW_PATH) 
                || (m_this_type == WC_PATH) );
        
}        

inline bool CZdUiPathname::IsEmpty(void) const
{
        return (m_this_type == NO_PATH);
}        

inline const CZdUiVolumeDescriptor* CZdUiPathname::GetVolumeDescriptor(void) const
{
        return m_pvolume;
}

inline bool CZdUiPathname::HadPrefix(void) const
{
        return m_had_prefix;
}

inline const CZdUiPathname& CZdUiPathname::operator=(const CZdUiPathname& pathSrc)
{
        AssignCopy( pathSrc);

        return *this;
}

inline const CZdUiPathname& CZdUiPathname::operator=(const CZdUiPathname* pathSrc)
{
        AssignCopy( *pathSrc);

        return *this;
}


inline bool CZdUiPathname::WasRoot(void) const
{
	return (m_path_cat == ROOT_TYPE);
}



#pragma pack (pop)

