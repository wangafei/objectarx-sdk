/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GDUI_THEME_MANAGER_H_
#define _GDUI_THEME_MANAGER_H_


class CGdUiThemeMgrReactor
{
public:
  CGdUiThemeMgrReactor();
  virtual void ThemeAdded(const CString & strThemeName) = 0;
  virtual void ThemeRemoved(const CString & strThemeName) = 0;
  virtual void SystemColorChanged() = 0;
  virtual ~CGdUiThemeMgrReactor();
};

class CGdUiThemeManager
{
  friend class CGdUiThemeMgrReactor;

public:
  CGdUiThemeManager();

  ~CGdUiThemeManager();

  CGdUiTheme * GetTheme(const GCHAR *pThemeName);
  BOOL ReleaseTheme(CGdUiTheme * pTheme);
  BOOL HasTheme(const GCHAR *pThemeName) const;

  void SystemColorChanged();
  void ActiveThemeChanged();

private:
  int  RemoveTheme(const GCHAR *pThemeName);
  void Cleanup();
  int  GetThemeIndex(const GCHAR *pThemeName) const;
  int  GetThemeIndex(const CGdUiTheme *pTheme) const;
  BOOL RegisterThemeMgrReactor(CGdUiThemeMgrReactor * pReactor);
  BOOL UnregisterThemeMgrReactor(CGdUiThemeMgrReactor * pReactor);
  void NotifyThemeAddedReactors(const CString & strThemeName);
  void NotifySysColorReactors();
  CObArray        m_list;
  CTypedPtrArray<CPtrArray, CGdUiThemeMgrReactor*> m_arrayThemeMgrReactors;
};
#endif  