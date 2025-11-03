#pragma once
#include "zdef.h"
#include <string>
class ZcLocaleImp;
class ZCPAL_PORT ZcLocale
{
public:
    ZcLocale(const wchar_t* iso2LangName, const wchar_t* iso2CountryName);
	~ZcLocale();
	ZcLocale(const ZcLocale& locale);
	ZcLocale& operator =(const ZcLocale& locale);
	ZcLocale(ZcLocale&& locale);
	ZcLocale& operator =(ZcLocale&& locale);
	bool operator ==(const ZcLocale& loc) const;
	bool operator !=(const ZcLocale& loc) const;
	const wchar_t*   iso2LangName() const;
	const wchar_t*   iso2CountryName() const;

    bool             isValid() const;

#if defined(ZC_NON_CROSS_PLATFORM_API)
    using LocaleId = int;

    ZcLocale(LocaleId lcid);

    operator LocaleId();
#endif

private:
    friend class ZcLocaleService;
    ZcLocale(const ZcLocaleImp* pImpLocale);

    ZcLocaleImp* m_pImpZcLocale;
};
