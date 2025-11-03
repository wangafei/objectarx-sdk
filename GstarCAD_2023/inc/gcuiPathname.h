/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#pragma pack (push, 8)

class GFILE;

class GCAD_PORT CGcUiPathname : public CGdUiPathname {

public:
  CGcUiPathname(void);
  CGcUiPathname(const CGcUiPathname&);
  ~CGcUiPathname(void);

  PathErr Parse(const wchar_t*, bool wildcard_ok = false) override;
  int Status(void);
  bool Open(GFILE** fdp, const wchar_t *openmode);
  const CGcUiPathname& operator=(const CGcUiPathname& pathSrc);
  const CGcUiPathname& operator=(const CGcUiPathname* pathSrc);

protected:
  virtual void AssignCopy(const CGcUiPathname&);
};

inline const CGcUiPathname& CGcUiPathname::operator=(const CGcUiPathname& pathSrc)
{
  AssignCopy(pathSrc);
  return *this;
}

inline const CGcUiPathname& CGcUiPathname::operator=(const CGcUiPathname* pathSrc)
{
  AssignCopy(*pathSrc);
  return *this;
}

#pragma pack (pop)
