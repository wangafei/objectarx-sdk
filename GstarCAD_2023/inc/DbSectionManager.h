/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "GdGChar.h"
#include "DbSection.h"

class GcDbSection;
class GcDbSectionManagerIterator;
class GcDbImpSectionManager;

class GCDB_PORT GcDbSectionManager : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbSectionManager);

  Gcad::ErrorStatus getSection(const GCHAR* pszName, GcDbObjectId& id) const;
  Gcad::ErrorStatus getSection(const GCHAR* pszName, GcDbSection*& pSecPlane, GcDb::OpenMode mode) const;
  Gcad::ErrorStatus getLiveSection(GcDbObjectId& id) const;
  Gcad::ErrorStatus getLiveSection(GcDbSection*& pSecPlane, GcDb::OpenMode mode) const;
  int   numSections(void) const;
  Gcad::ErrorStatus newIterator(GcDbSectionManagerIterator*& pIterator) const;
  Gcad::ErrorStatus getUniqueSectionName(const GCHAR* pszBaseName, GcString & sUniqueName) const;
  Gcad::ErrorStatus   getUniqueSectionName(const GCHAR* pszBaseName, GCHAR*& pszUniqueName) const;

  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* pFiler) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* pFiler) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* pFiler) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* pFiler) const override;

public:
  GcDbSectionManager(void);
  ~GcDbSectionManager(void);

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

inline Gcad::ErrorStatus GcDbSectionManager::getUniqueSectionName(const GCHAR* pszBaseName, GCHAR*& pszUniqueName) const
{
  GcString sUniqueName;
  return ::gcutGcStringToGChar(sUniqueName, pszUniqueName,
    this->getUniqueSectionName(pszBaseName, sUniqueName));
}

class GCDB_PORT GcDbSectionManagerIterator
{
public:
  virtual ~GcDbSectionManagerIterator(void);

  void  start(void);
  void  step(void);
  bool  done(void) const;

  GcDbObjectId      getSection(void) const;
  Gcad::ErrorStatus getSection(GcDbSection*& pSecPlane, GcDb::OpenMode openMode) const;

protected:
  GcDbSectionManagerIterator(GcDbSectionManager* pMgr);

protected:
  void*   mpImpObj = nullptr;

  friend class GcDbImpSectionManager;
};