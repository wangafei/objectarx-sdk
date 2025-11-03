

#pragma once

#pragma pack (push, 8)

class IZwFile;

class ZCCORE_PORT CZcUiPathname : public CZdUiPathname {

public:

        CZcUiPathname(void);
		CZcUiPathname(const CZcUiPathname&);

		virtual ~CZcUiPathname(void);

		virtual PathErr Parse( const wchar_t* , bool wildcard_ok = false ) override;

        int Status(void);

        bool Open(IZwFile** fdp, const wchar_t *openmode);

        const CZcUiPathname& operator=(const CZcUiPathname& pathSrc);
        const CZcUiPathname& operator=(const CZcUiPathname* pathSrc);

protected:

		virtual void AssignCopy( const CZcUiPathname& );		

};

inline const CZcUiPathname& CZcUiPathname::operator=(const CZcUiPathname& pathSrc)
{
    AssignCopy( pathSrc);

    return *this;
}

inline const CZcUiPathname& CZcUiPathname::operator=(const CZcUiPathname* pathSrc)
{
    AssignCopy( *pathSrc);

    return *this;
}

#pragma pack (pop)

