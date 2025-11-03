#pragma once

#pragma pack (push, 8)

// This file is also built as part of the acdb dll separately from the rest of
// GdUi.  To do so, we can only use a part of MFC, so a little tweaking is
// needed.
// 
#ifdef GCUTIL_INTERNAL
#include <tchar.h>
#include <afx.h>
#ifdef GDUI_PORT
#undef GDUI_PORT
#endif
#define GDUI_PORT
#define _PUC    unsigned TCHAR *
#define _CPUC   const unsigned TCHAR *
#define _PC     TCHAR *
#define _CPC    const TCHAR *
#define _UI     unsigned int
#endif

#include "gduipathenums.h"
//#include "gdui.h"
// File system types.
enum FS_TYPE {
    NOFS,        // no media in drive (floppy, etc.)
    UKFS,        // unknown, never heard of it!
    NTFS,        // NT file system 
    FAT,         // DOS 8.3 file system
    VFAT,        // Win95 LFN file system
    HPFS,        // OS/2 File system
    CDFS,        // ISO9660/High Sierra
    HFS,         // Mac HFS volume type
    UFS          // UNIX volume type
};

// Some oft used TCHAR constants for volume and file names

extern __declspec(selectany) const TCHAR kBackslash =    _T( '\\' );
extern __declspec(selectany) const TCHAR kColon =        _T( ':' );
extern __declspec(selectany) const TCHAR kDoubleQuote=   _T( '"' );
extern __declspec(selectany) const TCHAR kEOS =          _T( '\0' );
extern __declspec(selectany) const TCHAR kPeriod =       _T( '.' );
extern __declspec(selectany) const TCHAR kSlash =        _T( '/' );
extern __declspec(selectany) const TCHAR kSpace =        _T( ' ' );
extern __declspec(selectany) const TCHAR kAsterisk =     _T( '*' );
extern __declspec(selectany) const TCHAR kQuestionmark = _T( '?' );   
extern __declspec(selectany) const TCHAR kZero =         _T( '0' );

/*******************************************************************
   The CGdUiVolumeDescriptor class is the base windows volume class.
   Derived classes corresponding to specific filesystem types are
   intended to perform the real work.
 *******************************************************************/
class GDUI_PORT CGdUiVolumeDescriptor {

friend class CGdUiPathname;

public:

// methods

    CGdUiVolumeDescriptor();
    CGdUiVolumeDescriptor(const CString&);
	virtual ~CGdUiVolumeDescriptor();

    /* return true if the volume is read-only, false otherwise */
    virtual inline BOOL CheckReadOnly() const {return m_d_readonly==1;};

    /* return true if the path is valid according to the rules of 
       this volume type  */
//    virtual BOOL ValidateFilename( const CString*,
//                         const BOOL wildcard_ok = false ) const =0;
//
//    /* validate a segment of a filename */
//    virtual BOOL ValidateSegment( const CString*,
//                          const BOOL wildcard_ok = false ) const =0;

    // Return true if the filesystem is case_sensitive.  Note that
    // we're talking about strict case sensitivity, as in Unix.
    virtual BOOL IsCaseSensitive(void) const;

    // Return true if the filesystem preserves case (like FAT, FAT32
    // and NTFS).
    virtual BOOL PreservesCase(void) const;

    // Return true if the filesystem "allows case sensitive lookup".
    // This is the Win32 FS_CASE_SENSITIVE bit.  It's not clear
    // how useful this is, but whatever...
    virtual BOOL AllowsCaseSensitiveLookup(void) const;

    /* convert the string to the upper case if the volume is not
       case sensitive */
    virtual void VolCase( CString& ) const;

    /* return true if the strings match according to volume
       rules on case */
    virtual BOOL VolMatch( const TCHAR* a, const CString* b ) const;
    virtual BOOL VolMatch( const CString* a, const CString* b) const;

    /* return the local drive letter or volume name in the format 
         required to build complete path strings */
    virtual inline const CString* GetLocalName() const { return m_vol_localname;};

    /* return the free space on this volume in units of 1024 bytes.
       As a general rule, if the available space exceeds 2 terabytes, 
       return -1.   */
    virtual LONG GetVolFreeSpace() const;

    /* check for available free space;  i.e. return true if the 
       specified number of bytes is available on this drive;  I 
       think it's safe to assume we won't be creating files 
       larger than 4 Gbytes  for quite a while. */
    virtual BOOL WillFit(DWORD) const;

    /* return true if the volume is still valid; i.e. if the network
       connection is still ok, if the same cd-rom is in the drive,
       etc.  Obviously a NO-OP for a fixed disk. */
     virtual BOOL VolumeValid() const;

//#ifdef _DEBUG
//    /* a debugging function to dump the contents of the volume
//       descriptor in some human readable format */
//    virtual void debug_dump(FILE*) const;
// #endif

    inline BOOL IsRemote() const { return m_d_remote == 1; }

    inline BOOL IsRemovable() const { return m_d_removable == 1; }

protected:

    void GetConnectionName( void );
    int Find(CString& str, UINT ch) const;
    int IsControl(int c) const;
    
// data elements

    /* the filesystem type for the drive */
    FS_TYPE m_vol_fs_type;

    /* flags for drive characteristics */
    typedef unsigned flagbits;

    flagbits m_d_fixed:    1;
    flagbits m_d_removable: 1;
    flagbits m_d_cdrom: 1;
    flagbits m_d_remote: 1;
    flagbits m_d_ramdisk: 1;
    flagbits m_d_readonly: 1;
    flagbits m_d_caseSensitive: 1;
    
    /* the local name for this volume */
    CString* m_vol_localname;

    /* the maximum length for any component of a path */
    int    m_max_component_size;

    /* the maximum path length for this volume type */
    int    m_max_path_length;

    /* The correct component separator for this volume type
       To be used in generating file references.  For normal
       work the native UI syntax is always used. */
    TCHAR    m_vol_slash;

    BOOL     m_amodeMultiByte;    
    DWORD    m_vol_serial;
    DWORD    m_fsflags;
    CString* m_vol_label;
    CString* m_connection_name;
    LPCTSTR  m_doubleslash;
};

class GDUI_PORT CGdUiNTFSVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiNTFSVolumeDescriptor(const CString&);
        ~CGdUiNTFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};


class GDUI_PORT CGdUiVFATVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiVFATVolumeDescriptor(const CString&);
        ~CGdUiVFATVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};


class GDUI_PORT CGdUiHPFSVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiHPFSVolumeDescriptor(const CString&);
        ~CGdUiHPFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};


class GDUI_PORT CGdUiCDFSVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiCDFSVolumeDescriptor(const CString&);
        ~CGdUiCDFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};


class GDUI_PORT CGdUiFATVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiFATVolumeDescriptor(const CString&);
        ~CGdUiFATVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;
    protected:
        
        int m_segc;
};


class GDUI_PORT CGdUiUFSVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiUFSVolumeDescriptor(const CString&);
        ~CGdUiUFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};


class GDUI_PORT CGdUiNOFSVolumeDescriptor : public CGdUiVolumeDescriptor {

    public:

        CGdUiNOFSVolumeDescriptor(const CString&);
        ~CGdUiNOFSVolumeDescriptor(){};

        BOOL ValidateFilename( const CString*,
                               const BOOL wildcard_ok = false ) const;
        BOOL ValidateSegment( const CString*,
                              const BOOL wildcard_ok = false ) const;

};

#pragma pack (pop)

