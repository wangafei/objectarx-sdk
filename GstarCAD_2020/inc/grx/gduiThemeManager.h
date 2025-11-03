#ifndef _GDUI_THEME_MANAGER_H_
#define _GDUI_THEME_MANAGER_H_


class CGdUiThemeMgrReactor
{
public:
    CGdUiThemeMgrReactor();
    virtual void ThemeAdded(const CString & strThemeName) = 0;
    virtual void ThemeRemoved(const CString & strThemeName) = 0;
    virtual void SystemColorChanged() = 0;
    ~CGdUiThemeMgrReactor();
};


class CGdUiThemeManager 
{
    friend class CGdUiThemeMgrReactor;

public:
    CGdUiThemeManager();
    ~CGdUiThemeManager();

    CGdUiTheme * GetTheme(const TCHAR *pThemeName);
    BOOL ReleaseTheme(CGdUiTheme * pTheme);

    BOOL HasTheme(const TCHAR *pThemeName) const;

    void SystemColorChanged();

private:
    int  RemoveTheme(const TCHAR *pThemeName);
    void Cleanup();
    int  GetThemeIndex(const TCHAR *pThemeName) const;
    int  GetThemeIndex(const CGdUiTheme *pTheme) const;
    BOOL RegisterThemeMgrReactor(CGdUiThemeMgrReactor * pReactor);
    BOOL UnregisterThemeMgrReactor(CGdUiThemeMgrReactor * pReactor);
    void NotifyThemeAddedReactors(const CString & strThemeName);
    void NotifySysColorReactors();
    CObArray        m_list;
    CTypedPtrArray<CPtrArray, CGdUiThemeMgrReactor*> m_arrayThemeMgrReactors;
};
#endif  // _IDUI_THEME_MANAGER_H_
