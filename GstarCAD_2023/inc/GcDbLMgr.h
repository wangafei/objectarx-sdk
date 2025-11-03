/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCDBLMGR_H
#define   _GCDBLMGR_H

#include "gsoft.h"
#include "dbid.h"
#include "dblayout.h"
#include "dblaymgrrctr.h"
#pragma pack (push, 8)

#define  MAX_PSPACE_LAYOUTS     256

class GcDbObjectId;

class GcDbLayoutManager : public GcRxObject {
public:

  virtual Gcad::ErrorStatus
    setCurrentLayout(const GCHAR * newname,
      GcDbDatabase* pDb = NULL) = 0;

  virtual Gcad::ErrorStatus
    setCurrentLayoutId(GcDbObjectId layoutId) = 0;

  virtual Gcad::ErrorStatus   getActiveLayoutName(GcString & sName, bool allowModel,
    const GcDbDatabase* pDb = nullptr) = 0;

  virtual const GCHAR *               findActiveLayout(bool allowModel,
    const GcDbDatabase* pDb = nullptr) final;

  virtual GcDbObjectId
    getActiveLayoutBTRId(const GcDbDatabase* pDb = NULL) = 0;

  virtual GcDbObjectId
    findLayoutNamed(const GCHAR* name,
      const GcDbDatabase* pDb = NULL) = 0;

  Gcad::ErrorStatus
    getLayoutNamed(const GCHAR* name,
      GcDbLayout*& pLayout,
      GcDb::OpenMode mode = GcDb::kForRead,
      const GcDbDatabase* pDb = nullptr);

  bool
    layoutExists(const GCHAR* name,
      const GcDbDatabase* pDb = nullptr);

  virtual Gcad::ErrorStatus
    copyLayout(const GCHAR * copyname,
      const GCHAR * newname,
      GcDbDatabase* pDb = NULL) = 0;

  virtual Gcad::ErrorStatus
    deleteLayout(const GCHAR * delname,
      GcDbDatabase* pDb = NULL) = 0;

  virtual Gcad::ErrorStatus
    createLayout(const GCHAR *newname,
      GcDbObjectId& layoutId,
      GcDbObjectId& blockTableRecId,
      GcDbDatabase* pDb = NULL) = 0;

  virtual Gcad::ErrorStatus
    renameLayout(const GCHAR * oldname,
      const GCHAR * newname,
      GcDbDatabase* pDb = NULL) = 0;

  virtual Gcad::ErrorStatus
    cloneLayout(GcDbLayout* pLBTR,
      const GCHAR * newname,
      int newTabOrder = 0,
      GcDbDatabase* pDb = NULL) = 0;

  virtual GcDbObjectId
    getNonRectVPIdFromClipId(GcDbObjectId clipId) = 0;

  virtual bool
    isVpnumClipped(int index, const GcDbDatabase* pDb = NULL) = 0;

  virtual int
    countLayouts(GcDbDatabase *pDb = NULL) = 0;

  virtual void
    addReactor(GcDbLayoutManagerReactor * newObj) = 0;

  virtual void
    removeReactor(GcDbLayoutManagerReactor * delObj) = 0;
};

inline const GCHAR * GcDbLayoutManager::findActiveLayout(bool allowModel, const GcDbDatabase* pDb)
{
  static GcString sCachedName;
  this->getActiveLayoutName(sCachedName, allowModel, pDb);
  return sCachedName.constPtr();
}

inline Gcad::ErrorStatus GcDbLayoutManager::getLayoutNamed(const GCHAR* name,
  GcDbLayout*& pLayout, GcDb::OpenMode mode, const GcDbDatabase* pDb)
{
  GcDbObjectId id = findLayoutNamed(name, pDb);
  if (id.isNull())
    return Gcad::eKeyNotFound;

  return gcdbOpenObject(pLayout, id, mode);
}

inline bool GcDbLayoutManager::layoutExists(const GCHAR* name, const GcDbDatabase* pDb)
{
  return !(findLayoutNamed(name, pDb)).isNull();
}

GCCORE_PORT Gcad::ErrorStatus gcdbDoSetupForLayouts(GcDbDatabase* pDatabase,
  Gsoft::ULongPtr& contextHandle);

GCCORE_PORT Gcad::ErrorStatus gcdbClearSetupForLayouts(Gsoft::ULongPtr contextHandle);

#pragma pack (pop)
#endif 