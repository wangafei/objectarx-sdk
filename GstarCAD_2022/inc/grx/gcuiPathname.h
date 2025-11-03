#pragma once
#pragma pack (push, 8)

class GFILE;

class GCUI_PORT CGcUiPathname : public CGdUiPathname {

public:
        CGcUiPathname(void);
        CGcUiPathname(const CGcUiPathname&);
        ~CGcUiPathname(void);

virtual PathErr Parse( LPCTSTR, const BOOL wildcard_ok = FALSE );
        int Status(void);
        BOOL Open(GFILE** fdp, const TCHAR *openmode);

		const CGcUiPathname& CGcUiPathname::operator=(const CGcUiPathname& pathSrc);
        const CGcUiPathname& CGcUiPathname::operator=(const CGcUiPathname* pathSrc);
        
protected:
        virtual void AssignCopy( const CGcUiPathname& );    
};

inline const CGcUiPathname& CGcUiPathname::operator=(const CGcUiPathname& pathSrc)
{
     AssignCopy( pathSrc);
    return *this;
}

inline const CGcUiPathname& CGcUiPathname::operator=(const CGcUiPathname* pathSrc)
{
     AssignCopy( *pathSrc);
    return *this;
}

#pragma pack (pop)