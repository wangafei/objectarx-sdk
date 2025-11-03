#ifndef _GNavFilter_h
#define _GNavFilter_h

#if _MSC_VER >= 1000
#pragma once
#endif 

#pragma warning(push)
#pragma warning(disable : 4275)

class GNAV_PORT CNavFilter : public CStringArray {
public:
                CNavFilter ();
virtual         ~CNavFilter ();

private:
        BOOL    m_bFullDescription;  
protected:
        CString m_description;
        int     m_tagIndex;

public:
        LPCTSTR GetDescription ();
        void    SetDescription (LPCTSTR desc);
        void    GetFullDescription (CString& desc);
        void    SetFullDescription (LPCTSTR desc);
        int     GetTagIndex ();                     
        void    SetTagIndex (int tagIndex);
        int     Find (LPCTSTR str);
        int     GetCount ();
        BOOL    IsAllowed (LPCTSTR fileName);
        LPTSTR SetFrom (LPTSTR str, BOOL bUseFullDescrition = FALSE);        
};

#pragma warning(pop)
#endif