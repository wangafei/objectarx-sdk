/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef   _GCDB_LAYOUT_MANAGER_REACTOR_H
#define   _GCDB_LAYOUT_MANAGER_REACTOR_H

#include "rxobject.h"
#include "dbid.h"
#include "GdGChar.h"
#pragma pack (push, 8)

class GCDB_PORT GcDbLayoutManagerReactor : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbLayoutManagerReactor);

  virtual void layoutCreated(const GCHAR * newLayoutName,
    const GcDbObjectId& layoutId);
  virtual void layoutToBeRemoved(const GCHAR * layoutName,
    const GcDbObjectId& layoutId);
  virtual void layoutRemoved(const GCHAR * layoutName,
    const GcDbObjectId& layoutId);
  virtual void abortLayoutRemoved(const GCHAR * layoutName,
    const GcDbObjectId& layoutId);
  virtual void layoutToBeCopied(const GCHAR * layoutName,
    const GcDbObjectId& oldLayoutId);
  virtual void layoutCopied(const GCHAR * oldLayoutName,
    const GcDbObjectId& oldLayoutId,
    const GCHAR * newLayoutname,
    const GcDbObjectId& newLayoutId);
  virtual void abortLayoutCopied(const GCHAR * layoutName,
    const GcDbObjectId& layoutId);
  virtual void layoutToBeRenamed(const GCHAR * oldName,
    const GCHAR * newName,
    const GcDbObjectId& layoutId);
  virtual void layoutRenamed(const GCHAR * oldName,
    const GCHAR * newName,
    const GcDbObjectId& layoutId);
  virtual void abortLayoutRename(const GCHAR * oldName,
    const GCHAR * newName,
    const GcDbObjectId& layoutId);
  virtual void layoutSwitched(const GCHAR * newLayoutname,
    const GcDbObjectId& newLayoutId);
  virtual void plotStyleTableChanged(const GCHAR * newTableName,
    const GcDbObjectId& layoutId);
  virtual void layoutsReordered();
  virtual void refreshLayoutTabs();
};

#pragma pack (pop)
#endif 