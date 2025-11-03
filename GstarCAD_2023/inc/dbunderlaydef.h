/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBUNDERLAYDEF_H
#define GCDB_DBUNDERLAYDEF_H
#pragma once

#include "dbmain.h"
#include "GcString.h"

#pragma pack (push, 8)

class GcDbUnderlayItem;
class GcDbUnderlayHost;
class IGcReadStream;

class GSOFT_NO_VTABLE GCDB_PORT GcDbUnderlayDefinition : public GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbUnderlayDefinition);
  GcDbUnderlayDefinition();
  ~GcDbUnderlayDefinition() = 0;
  Gcad::ErrorStatus setSourceFileName(const GCHAR* file);
  const GCHAR* getSourceFileName() const;
  IGcReadStream* getReadStream() const;
  Gcad::ErrorStatus getActiveFileName(const GCHAR*& file) const;
  Gcad::ErrorStatus getActiveFileName(GcString& file) const;
  Gcad::ErrorStatus setItemName(const GCHAR* item);
  const GCHAR* getItemName() const;
  Gcad::ErrorStatus setUnderlayItem(const GCHAR* sourceFileName, const GCHAR* activeFileName, GcDbUnderlayItem* pItem);
  const GcDbUnderlayItem* getUnderlayItem() const;
  Gcad::ErrorStatus load(const wchar_t* password);
  void unload();
  bool isLoaded() const;
  static GcString dictionaryKey(const GcRxClass* underlayDefinitionType);
private:
  virtual const GcDbUnderlayHost* getUnderlayHost() const = 0;
};

class GCDB_PORT GcDbDwfDefinition : public GcDbUnderlayDefinition
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDwfDefinition);
  GcDbDwfDefinition();
  ~GcDbDwfDefinition();
  Gsoft::Boolean isDWFx(void) const;
private:
  const GcDbUnderlayHost* getUnderlayHost() const override;
};

class GCDB_PORT GcDbDgnDefinition : public GcDbUnderlayDefinition
{
public:
  GCDB_DECLARE_MEMBERS(GcDbDgnDefinition);
  GcDbDgnDefinition();
  ~GcDbDgnDefinition();
  bool useMasterUnits() const;
  void setUseMasterUnits(bool useMaster);
  int  xrefDepth() const;
  void setXrefDepth(int depth);
  bool showRasterRef() const;
  void setShowRasterRef(bool bShow);
private:
  const GcDbUnderlayHost* getUnderlayHost() const override;
};

class GCDB_PORT GcDbPdfDefinition : public GcDbUnderlayDefinition
{
public:
  GCDB_DECLARE_MEMBERS(GcDbPdfDefinition);
  GcDbPdfDefinition();
  virtual ~GcDbPdfDefinition();
private:
  const GcDbUnderlayHost* getUnderlayHost() const override;
};
#pragma pack (pop)

#endif