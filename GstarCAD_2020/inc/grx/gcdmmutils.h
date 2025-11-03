#include "gcarray.h"

#ifndef GcDMMUtils_h
#define GcDMMUtils_h

typedef const wchar_t * PCWIDESTR;
typedef wchar_t * PWIDESTR;

/////////////////////////////////////////////////////////////////////
// GcDMMWideString
/////////////////////////////////////////////////////////////////////

/// <summary>
/// a simple unicode string class
/// </summary>
///
/// <remarks>
/// Cheap Unicode string class.  No fancy use-counting.
/// Just meant to "look" like CString as far as we use it.
/// </remarks>
class GcDMMWideString
{
public:
    /// <summary>
    /// default constructor
    /// </summary>
    ///
    GcDMMWideString();

    /// <summary>
    /// copy constructor
    /// </summary>
    ///
    /// <param name="ws">
    /// the string to be copied into this
    /// </param>
    ///
    GcDMMWideString(const GcDMMWideString& ws);

    /// <summary>
    /// Constructs this from a pointer to a Unicode string
    /// </summary>
    ///
    /// <param name="pwsz">
    /// a pointer to the null terminated Unicode string from which this
    /// object shall be constructed.
    /// </param>
    ///
    GcDMMWideString(PCWIDESTR pwsz);

    /// <summary>
    /// destructor
    /// </summary>
    ///
    virtual ~GcDMMWideString();

    /// <summary>
    /// operator= for copying another GcDMMWideString
    /// </summary>
    ///
    /// <param name="ws">
    /// a const reference to the GcDMMWideString which is to be
    /// copied to this
    /// </param>
    ///
    /// <returns>
    /// a const reference to this
    /// </returns>
    ///
    const GcDMMWideString& operator= (const GcDMMWideString& ws);

    /// <summary>
    /// operator= for copying a null terminated Unicode string into this
    /// </summary>
    ///
    /// <param name ="pwsz">
    /// a const pointer to a null terminated Unicode string to be copied
    /// to this
    /// </param>
    ///
    /// <returns>
    /// a const reference to this
    /// </returns>
    ///
    const GcDMMWideString& operator= (PCWIDESTR pwsz);

    /// <summary>
    /// returns a const pointer to the Unicode string contained by this
    /// </summary>
    ///
    /// <returns>
    /// returns a const pointer to the Unicode string contained by this
    /// </returns>
    ///
    operator PCWIDESTR() const;

    /// <summary>
    /// deletes the contained Unicode string
    /// </summary>
    ///
    void   Empty();

    /// <summary>
    /// tells the caller if this contains an empty string
    /// </summary>
    ///
    /// <returns>
    /// returns true if this contains an empty string
    /// </returns>
    bool   IsEmpty() const;

    /// <summary>
    /// get the length of the contained string, in Unicode characters
    /// </summary>
    ///
    /// <returns>
    /// the length of the contained string, in Unicode characters
    /// </returns>
    ///
    unsigned GetLength() const;  // not size_t.  lengths are < 4G.

    /// <summary>
    /// concatenates a second GcDMMWideString to this one
    /// </summary>
    ///
    /// <param name="ws">
    /// the GcDMMWideString to concatenate with this one
    /// </param>
    ///
    /// <returns>
    /// a const reference to this
    /// </returns>
    const GcDMMWideString& operator+= (GcDMMWideString ws);

    friend GcDMMWideString operator+ 
        (const GcDMMWideString& wsLeft, wchar_t wch);
    friend GcDMMWideString operator+ 
        (wchar_t wch, const GcDMMWideString& wsRight);
    friend GcDMMWideString operator+ 
        (const GcDMMWideString& wsLeft, const GcDMMWideString& wsRight);

private:
    void Alloc(size_t iLen);
    void Alloc(PCWIDESTR pwsz,size_t iLen);
    void Alloc(PCWIDESTR pwsz);
    static void Release(PWIDESTR pwsz);
    void Release();

    void MoveChars(int iStartOffset,PCWIDESTR pwsz,size_t iChars);

    PWIDESTR  m_pData;
    unsigned  m_iLength;   // not using size_t.  lengths are < 4G.
};


inline void GcDMMWideString::MoveChars(int iStartOffset,
                                       PCWIDESTR pwsz, size_t iChars)
{
    const unsigned n32Chars = (unsigned)iChars;
    assert(n32Chars == iChars);
    assert(iStartOffset >=0);
    assert((unsigned)iStartOffset <= m_iLength);
    assert(iStartOffset + iChars <= m_iLength+1);

    memmove(m_pData+iStartOffset,
            pwsz,
            iChars * sizeof(wchar_t));
}



inline GcDMMWideString operator+ (const GcDMMWideString& wsLeft, wchar_t wch)
{
    GcDMMWideString wsRet;

    wsRet.Alloc(wsLeft.m_pData,wsLeft.GetLength()+1);
    wsRet.m_pData[wsLeft.GetLength()] = wch;
    wsRet.m_pData[wsLeft.GetLength()+1] = 0;

    return(wsRet);
}


inline GcDMMWideString operator+ (wchar_t wch, const GcDMMWideString& wsRight)
{
    GcDMMWideString wsRet;

    wsRet.Alloc(wsRight.GetLength()+1);
    wsRet.m_pData[0] = wch;
    wsRet.MoveChars(1,wsRight.m_pData,wsRight.GetLength()+1);

    return(wsRet);
}

inline GcDMMWideString operator+ (const GcDMMWideString& wsLeft, 
    const GcDMMWideString& wsRight)
{
    GcDMMWideString wsRet(wsLeft);
    wsRet += wsRight;
    return(wsRet);
}

inline const GcDMMWideString& GcDMMWideString::operator += (GcDMMWideString ws)
{
    if(!ws.IsEmpty()) {
        GcDMMWideString wsOldThis = *this;
        Empty();
        Alloc(wsOldThis.GetLength() + ws.GetLength());

        MoveChars(0,wsOldThis.m_pData,wsOldThis.GetLength());

        MoveChars(wsOldThis.GetLength(),ws.m_pData,ws.GetLength()+1);
    }

    return(*this);
}

inline GcDMMWideString::GcDMMWideString()
: m_pData(NULL),
  m_iLength(0)
{
}

inline GcDMMWideString::GcDMMWideString(const GcDMMWideString& ws)
: m_pData(NULL),
  m_iLength(0)
{
    Alloc(ws.m_pData? ws.m_pData: L"",ws.m_iLength);
}

inline GcDMMWideString::GcDMMWideString(PCWIDESTR pwsz)
: m_pData(NULL),
  m_iLength(0)
{
    Alloc(pwsz);
}

inline GcDMMWideString::~GcDMMWideString()
{
    Empty();
}

inline bool GcDMMWideString::IsEmpty() const
{
    return(m_iLength == 0);
}

inline void GcDMMWideString::Empty()
{
    if(m_pData)
        Release();

    m_iLength = 0;
}


inline GcDMMWideString::operator PCWIDESTR() const
{
    return(m_pData ? m_pData : L"");
}


inline const GcDMMWideString& GcDMMWideString::operator=
    (const GcDMMWideString& ws)
{
    Empty();
    m_iLength = ws.m_iLength;
    Alloc(ws.m_pData,ws.m_iLength);

    return(*this);
}

inline const GcDMMWideString& GcDMMWideString::operator= (PCWIDESTR pwsz)
{
    Empty();
    m_iLength = (unsigned)wcslen(pwsz);
    Alloc(pwsz,m_iLength);

    return(*this);
}

inline unsigned GcDMMWideString::GetLength() const
{
    return this->m_iLength;
}


inline void GcDMMWideString::Alloc(size_t iLen)
// Makes an allocation of the size indicated
{
    assert(m_pData == NULL);
    assert(iLen == (unsigned)iLen);
    m_iLength = (unsigned)iLen;
    m_pData = new wchar_t[m_iLength+1];
}

inline void GcDMMWideString::Alloc(PCWIDESTR pwsz,size_t iLen)
// Makes an allocation of the size indicated, copies that amount
{
    assert(m_pData == NULL);
    assert(pwsz != NULL);

    if(iLen > 0) {
        Alloc(iLen);
        MoveChars(0,pwsz,iLen+1);
    }
}

inline void GcDMMWideString::Alloc(PCWIDESTR pwsz)
// Makes an allocation, copies entire string
{
    assert(m_pData == NULL);
    assert(pwsz != NULL);
    if (pwsz == NULL)
        return;

    Alloc(pwsz,wcslen(pwsz));
}


inline void GcDMMWideString::Release(PWIDESTR pwsz)
// Static function: deallocates the backing store.
{
    if (pwsz)
        delete[] pwsz;
}


inline void GcDMMWideString::Release()
{
    Release(m_pData);
    m_pData = NULL;
    m_iLength = 0;
}

typedef GcArray<GcDMMWideString> GcDMMStringVec;

///////////////////////////////////////////////////////////////////////
/// class GcDMMNode
///////////////////////////////////////////////////////////////////////
/// <summary>
/// a lightweight object to hold the data needed to describe a Node in
/// a DWF w2d
/// </summary>
class GcDMMNode 
{
public:
    /// <summary>
    /// default constructor
    /// </summary>
    ///
    /// <remarks>
    /// creates an empty node with number 0
    /// </remarks>
    GcDMMNode()
    : m_nodeNumber(0),
      m_nodeName(NULL)
    {
    }

    /// <summary>
    /// constructs a node from a name and number
    /// </summary>
    ///
    /// <param name="number">
    /// The integer Node number.
    /// </param>
    ///
    /// <param name="name">
    /// a Unicode string defining the Node name
    /// </param>
    ///
    GcDMMNode(int number, wchar_t * name)
    {
        m_nodeNumber = number;
        if (NULL != name) {
            size_t nSize = ::wcslen(name) + 1;
            m_nodeName = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_nodeName, nSize, name);
            assert(err == 0);
        } else
            m_nodeName = NULL;
    }

    /// <summary>
    /// Copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object to be copied
    /// </param>
    ///
    GcDMMNode(const GcDMMNode &src) 
    : m_nodeName(NULL)
    { 
        *this = src;
    }


    /// <summary>
    /// destructor
    /// </summary>
    ///
    ~GcDMMNode()
    {
        if (NULL != m_nodeName)
            delete [] m_nodeName;
    }

    /// <summary>
    /// accessor for the Node number
    /// </summary>
    ///
    /// <returns>
    /// the integer Node number
    /// </returns>
    int nodeNumber() const {return m_nodeNumber;};

    /// <summary>
    /// mutator for the Node number
    /// </summary>
    ///
    /// <param name="number">
    /// the integer value to assign as Node number
    /// </param>
    void SetNodeNumber(int number) {m_nodeNumber = number;};


    /// <summary>
    /// accessor for the Node name
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the null terminated Unicode Node name string
    /// </returns>
    const wchar_t * nodeName() const {return m_nodeName;};

    /// <summary>
    /// mutator for the Node name
    /// </summary>
    ///
    /// <param name="name">
    /// a const pointer to a Unicode string to be assigned as Node name
    /// </param>
    void SetNodeName(const wchar_t * name)
    {
        if (NULL != m_nodeName) {
            delete [] m_nodeName;
            m_nodeName = NULL;
        }
        if (NULL != name) {
            size_t nSize = ::wcslen(name) + 1;
            m_nodeName = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_nodeName, nSize, name);
            assert(err == 0);
        } else
            m_nodeName = NULL;
    }

    /// <summary>
    /// operator= also used by copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object whose values will be copied to this object
    /// </param>
    ///
    /// <returns>
    /// returns this object
    /// </returns>
    GcDMMNode & operator= (const GcDMMNode &src)
    {
        if (this == &src)
            return *this;

        SetNodeNumber(src.m_nodeNumber);
        SetNodeName(src.m_nodeName);
        return *this;
    }

private:
    int m_nodeNumber;
    wchar_t * m_nodeName;
};

/////////////////////////////////////////////////////////////////////////
// class GcDMMResourceInfo
/////////////////////////////////////////////////////////////////////////

/// <summary>
/// This class describes a resource to be added to the DWF page or global 
/// section
/// The resource is an existing file which will be added to the zip
/// file and listed in the page descriptor as a page resource or added
/// to the ePlot global section as a global resource
/// </summary>
class GcDMMResourceInfo
{
public:
    /// <summary>
    /// the default constructor, creates an empty object
    /// </summary>
    GcDMMResourceInfo()
    : m_mime(NULL),
      m_role(NULL),
      m_path(NULL)
    {
    }

    /// <summary>
    /// creates an GcDMMResourceInfo object from 3 Unicode strings
    /// </summary>
    ///
    /// <param name="role">
    /// a null terminated Unicode string to be assigned to the role attribute
    /// This string describes the resource, e.g, "thumbnail", "font", etc.
    /// </param>
    ///
    /// <param name="mime">
    /// this is a null terminated Unicode strings to be assigned to the mime
    /// type attribute. 
    /// </param>
    ///
    /// <param name="path">
    /// This is a Unicode string holding the full path to the resource file
    /// </param>
    GcDMMResourceInfo(const wchar_t *role, const wchar_t *mime, 
        const wchar_t *path)
    {
        if (NULL != role) {
            size_t nSize = ::wcslen(role) + 1;
            m_role = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_role, nSize, role);
            assert(err == 0);
        } else
            m_role = NULL;

        if (NULL != mime) {
            size_t nSize = ::wcslen(mime) + 1;
            m_mime = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_mime, nSize, mime);
            assert(err == 0);
        } else
            m_mime = NULL;

        if (NULL != path) {
            size_t nSize = ::wcslen(path) + 1;
            m_path = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_path, nSize, path);
            assert(err == 0);
        } else
            m_path = NULL;
    }

    /// <summary>
    /// Copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object to be copied
    /// </param>
    ///
    GcDMMResourceInfo(const GcDMMResourceInfo & src) 
    : m_role(NULL),
      m_mime(NULL),
      m_path(NULL)
    {
        *this = src;
    }


    /// <summary>
    /// destructor
    /// </summary>    
    ~GcDMMResourceInfo()
    {
        if (NULL != m_role)
            delete [] m_role;
        if (NULL != m_mime)
            delete [] m_mime;
        if (NULL != m_path)
            delete [] m_path;
    }

    /// <summary>
    /// mutator for the Role attribute
    /// </summary>
    ///
    /// <param name="role">
    /// a const pointer to a Unicode string to be assigned as role
    /// </param>
    void SetRole(wchar_t * role)
    {
        if (NULL != m_role) {
            delete [] m_role;
            m_role = NULL;
        }
        if (NULL != role) {
            size_t nSize = ::wcslen(role) + 1;
            m_role = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_role, nSize, role);
            assert(err == 0);
        } else
            m_role = NULL;
    }

    /// <summary>
    /// mutator for the Role attribute
    /// </summary>
    ///
    /// <param name="role">
    /// a const pointer to a Unicode string to be assigned as role
    /// </param>
    void SetRole(const wchar_t * role)
    {
        if (NULL != m_role) {
            delete [] m_role;
            m_role = NULL;
        }
        if (NULL != role) {
            size_t nSize = ::wcslen(role) + 1;
            m_role = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_role, nSize, role);
            assert(err == 0);
        } else
            m_role = NULL;
    }

    /// <summary>
    /// accessor for the Role attribute
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the null terminated Unicode Node role string
    /// </returns>
    const wchar_t * GetRole() const {return m_role;};

    /// <summary>
    /// mutator for the Mime attribute
    /// </summary>
    ///
    /// <param name="mime">
    /// a const pointer to a Unicode string to be assigned as mime
    /// </param>
    void SetMime(wchar_t * mime)
    {
        if (NULL != m_mime) {
            delete [] m_mime;
            m_mime = NULL;
        }
        if (NULL != mime) {
            size_t nSize = ::wcslen(mime) + 1;
            m_mime = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_mime, nSize, mime);
            assert(err == 0);
        } else
            m_mime = NULL;
    }

    /// <summary>
    /// mutator for the Mime attribute
    /// </summary>
    ///
    /// <param name="mime">
    /// a const pointer to a Unicode string to be assigned as mime
    /// </param>
    void SetMime(const wchar_t * mime)
    {
        if (NULL != m_mime) {
            delete [] m_mime;
        }
        if (NULL != mime) {
            size_t nSize = ::wcslen(mime) + 1;
            m_mime = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_mime, nSize, mime);
            assert(err == 0);
        } else
            m_mime = NULL;
    }

    /// <summary>
    /// accessor for the Mime type attribute
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the null terminated Unicode mime type string
    /// </returns>
    const wchar_t * GetMime() const {return m_mime;};

    /// <summary>
    /// mutator for the Path attribute
    /// </summary>
    ///
    /// <param name="path">
    /// a const pointer to a Unicode string to be assigned as path to the
    /// resource file
    /// </param>
    void SetPath(wchar_t * path)
    {
        if (NULL != m_path) {
            delete [] m_path;
            m_path = NULL;
        }
        if (NULL != path) {
            size_t nSize = ::wcslen(path) + 1;
            m_path = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_path, nSize, path);
            assert(err == 0);
        } else
            m_path = NULL;
    }

    /// <summary>
    /// mutator for the Path attribute
    /// </summary>
    ///
    /// <param name="path">
    /// a const pointer to a Unicode string to be assigned as path to the
    /// resource file
    /// </param>
    void SetPath(const wchar_t * path)
    {
        if (NULL != m_path) {
            delete [] m_path;
            m_path = NULL;
        }
        if (NULL != path) {
            size_t nSize = ::wcslen(path) + 1;
            m_path = new wchar_t[nSize];
            errno_t err = ::wcscpy_s(m_path, nSize, path);
            assert(err == 0);
        } else
            m_path = NULL;
    }

    /// <summary>
    /// accessor for the path to the resource file
    /// </summary>
    ///
    /// <returns>
    /// a const pointer to the null terminated Unicode path string
    /// </returns>
    const wchar_t * GetPath() const {return m_path;};

    /// <summary>
    /// operator= also used by copy constructor
    /// </summary>
    ///
    /// <param name="src">
    /// the object whose values will be copied to this object
    /// </param>
    ///
    /// <returns>
    /// returns this object
    /// </returns>
    GcDMMResourceInfo& operator= (const GcDMMResourceInfo &src)
    {
        if (this == &src)
            return *this;

        SetRole(src.m_role);
        SetMime(src.m_mime);
        SetPath(src.m_path);
        return *this;
    }

private:
    wchar_t * m_role;
    wchar_t * m_mime;
    wchar_t * m_path; // full path to resource file   
};

typedef GcArray<GcDMMResourceInfo> GcDMMResourceVec;

#endif // GcDMMUtils_h
