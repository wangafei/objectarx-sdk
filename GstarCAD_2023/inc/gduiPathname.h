/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gsoft.h"
#include "gcbasedefs.h"
#include "gduipathenums.h"
#include "GcString.h"
#include <cstdio> 
#pragma pack (push, 8)

#ifndef _GSOFT_MAC_
#define  MAX_PATH 260
#endif

class CGdUiVolumeDescriptor;

GcString GetDriveForRoottypePath(const CGdUiVolumeDescriptor* const);
bool WasAbsoluteHelper(path_category pc);
bool IsValidOnColon(const GcString* work);

namespace Gssoft
{
  namespace Gscad
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

extern __declspec(selectany) const GCHAR kBackslash = GCRX_T('\\');
extern __declspec(selectany) const GCHAR kColon = GCRX_T(':');
extern __declspec(selectany) const GCHAR kDoubleQuote = GCRX_T('"');
extern __declspec(selectany) const GCHAR kEOS = GCRX_T('\0');
extern __declspec(selectany) const GCHAR kPeriod = GCRX_T('.');
extern __declspec(selectany) const GCHAR kSlash = GCRX_T('/');
extern __declspec(selectany) const GCHAR kSpace = GCRX_T(' ');
extern __declspec(selectany) const GCHAR kAsterisk = GCRX_T('*');
extern __declspec(selectany) const GCHAR kQuestionmark = GCRX_T('?');
extern __declspec(selectany) const GCHAR kZero = GCRX_T('0');

class GCAD_PORT CGdUiPathname {

  friend void GetDisplayNameHelper(
    const CGdUiPathname* pPathName,
    GcString& strResult,
    int maxchars);
  friend CGdUiVolumeDescriptor* NewVolDescriptorHelper(
    const CGdUiPathname* pPathName,
    const GcString& vol_name);
  friend bool IsPathValid(
    CGdUiPathname* pPathName,
    const CGdUiPathname* rel_path,
    const GcString* work);
  friend void HandleSpecialPath(
    CGdUiPathname* pPathName,
    const CGdUiPathname* rel_path,
    GcString* work,
    int index,
    bool wildcard_ok);
  friend bool IsValidOnColon(const GcString* work);
  friend void SetupVolForRoottypePath(
    CGdUiPathname* pPathName,
    const CGdUiPathname* pRelPath,
    const wchar_t * pPathStr);
  friend GcString GetDriveForRoottypePath(const CGdUiVolumeDescriptor*);
  friend bool WasAbsoluteHelper(path_category pc);

public:
  CGdUiPathname(void);
  CGdUiPathname(const CGdUiPathname&);
  virtual ~CGdUiPathname(void);

  void Empty(void);
  virtual PathErr Parse(const wchar_t *, bool wildcard_ok = false);
  PathErr ParseRelative(const wchar_t * name,
    const CGdUiPathname* relpath,
    bool wildcard_ok = false);
  bool ParseAndOSFind(const wchar_t *);

  const CGdUiPathname& operator=(const CGdUiPathname& pathSrc);
  const CGdUiPathname& operator=(const CGdUiPathname* pathSrc);

  bool GetUniqueName(CGdUiPathname&,
    bool alwaysMangle = false) const;
  void GetFilename(GcString&) const;
  void GetExtension(GcString&) const;
  void GetBasename(GcString&) const;
  void GetParent(CGdUiPathname&) const;

  PathErr Trim(void);
  PathErr TrimSlash(void);
  PathErr TrimComponent(void);

  PathErr Append(const wchar_t *);
  PathErr AppendSlash(void);
  PathErr AppendComponent(const wchar_t *);

  PathErr AddExtensionAlways(const wchar_t *);
  PathErr AddExtensionIfNoMatch(const wchar_t *);

  PathErr ReplaceExtensionAlways(const wchar_t *);
  PathErr ReplaceExtensionIfNoMatch(const wchar_t *);

  void RemoveExtensionAlways(void);
  void RemoveExtensionIfMatch(const wchar_t *);

  void BaseToLower(void);
  void BaseToUpper(void);

  void RemoveSpaces(void);

  void GetDisplayName(GcString& strResult, int maxchars) const;

  const wchar_t * GetPathString(void) const;

  bool GetFullPath(GcString&) const;
  bool GetFullPath(wchar_t* pBuf, size_t strBuffLen) const;

  template<size_t nBufLen> inline bool GetFullPath(wchar_t(&buf)[nBufLen]) const
  {
    return this->GetFullPath(buf, nBufLen);
  }

  void GetFullUNCPath(GcString&) const;
  bool IsPath(void) const;
  bool IsEmpty(void) const;
  path_type GetPathType(void) const;
  const CGdUiVolumeDescriptor* GetVolumeDescriptor(void) const;

  bool PathMatch(const CGdUiPathname*) const;
  bool PathMatch(const wchar_t *) const;

  bool Exists(void);
  bool VerifyExtension(const wchar_t * extlist) const;
  bool HadPrefix(void) const;
  bool WasAbsolute(void) const;
  bool WasRoot(void) const;

  GSOFT_DEPRECATED bool Open(FILE** fdp, const GCHAR *openmode);

  bool OpenReadOnly(Gssoft::Gscad::PAL::FileIO::File &);
  bool OpenWriteOnly(Gssoft::Gscad::PAL::FileIO::File &);
  bool Rename(const GCHAR *newname);
  bool Remove(void);
  path_status Status();

protected:
  path_type                       m_this_type;
  const CGdUiVolumeDescriptor*        m_pvolume;
  GcString*                        m_pathbuffer;
  GcString*                        m_relpath;
  path_category                   m_path_cat;
  GCHAR                           m_separator;
  bool                            m_had_prefix;

  const CGdUiVolumeDescriptor* FindVolumeDescriptor(const GcString& vol_name) const;
  const CGdUiVolumeDescriptor* NewVolDescriptor(const GcString& vol_name) const;
  FS_TYPE GetFileSystem(GcString& vol_name) const;
  inline bool IsDeviceName(const GcString& str) const;
  static void Unquote(GcString&);
  GCHAR GetSeparator(void) const;
  virtual void AssignCopy(const CGdUiPathname&);

  static GCHAR GetLastCharacter(const GcString&);

private:
  void GetFirstExtInList(const wchar_t *, GcString&) const;
  void lstrncpy_x(wchar_t* dest, size_t destLen, const wchar_t * src, int nchars) const;
  void StripSpaces(GcString& work);
  void GetAttributes(const GcString* path,
    const GcString* relpath,
    path_type* this_type);
};

inline CGdUiPathname::CGdUiPathname(const CGdUiPathname& pathSrc)
{
  m_pathbuffer = nullptr;
  m_relpath = nullptr;

  AssignCopy(pathSrc);
}

inline path_type CGdUiPathname::GetPathType(void) const
{
  return m_this_type;
}

inline bool CGdUiPathname::IsPath(void) const
{
  return ((m_this_type == FILE_PATH)
    || (m_this_type == DIR_PATH)
    || (m_this_type == NEW_PATH)
    || (m_this_type == WC_PATH));
}

inline bool CGdUiPathname::IsEmpty(void) const
{
  return (m_this_type == NO_PATH);
}

inline const CGdUiVolumeDescriptor* CGdUiPathname::GetVolumeDescriptor(void) const
{
  return m_pvolume;
}

inline bool CGdUiPathname::HadPrefix(void) const
{
  return m_had_prefix;
}

inline const CGdUiPathname& CGdUiPathname::operator=(const CGdUiPathname& pathSrc)
{
  AssignCopy(pathSrc);
  return *this;
}

inline const CGdUiPathname& CGdUiPathname::operator=(const CGdUiPathname* pathSrc)
{
  AssignCopy(*pathSrc);
  return *this;
}

inline bool CGdUiPathname::WasRoot(void) const
{
  return (m_path_cat == ROOT_TYPE);
}

#pragma pack (pop)
