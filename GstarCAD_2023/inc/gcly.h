/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef _GC_LY_H
#define _GC_LY_H

#include "GdGChar.h"
#include "gcadstrc.h"
#include "gcarray.h"
#include "dbsymtb.h"
#include "dbxrecrd.h"

class GcLySystemInternals;

class GcLyRelExpr
{
public:
  virtual ~GcLyRelExpr() { }

  virtual const GCHAR * getVariable() const = 0;
  virtual const GCHAR * getConstant() const = 0;
};

class GcLyAndExpr
{
public:
  virtual ~GcLyAndExpr() { }
  virtual const GcArray<GcLyRelExpr*>& getRelExprs() const = 0;
};

class GcLyBoolExpr
{
public:
  virtual ~GcLyBoolExpr() { }
  virtual const GcArray<GcLyAndExpr*>& getAndExprs() const = 0;
};

#ifndef HIMAGELIST
struct _IMAGELIST;
typedef struct _IMAGELIST* HIMAGELIST;
#endif

class GCDB_PORT GcLyLayerFilter : public GcRxObject, public GcHeapOperators
{
public:
  GCRX_DECLARE_MEMBERS(GcLyLayerFilter);
  GcLyLayerFilter();
  ~GcLyLayerFilter();

  virtual const GCHAR * name() const;
  virtual Gcad::ErrorStatus setName(const GCHAR *);
  virtual bool allowRename() const;

  virtual Gcad::ErrorStatus getImages(HIMAGELIST& imageList, Gsoft::UInt32& normalImage, Gsoft::UInt32& selected) const;
  virtual GcLyLayerFilter* parent() const;
  virtual const GcArray<GcLyLayerFilter*>& getNestedFilters() const;
  virtual Gcad::ErrorStatus addNested(GcLyLayerFilter* filter);
  virtual Gcad::ErrorStatus removeNested(GcLyLayerFilter* filter);
  virtual Gcad::ErrorStatus generateNested();
  virtual bool dynamicallyGenerated() const;
  virtual bool allowNested() const;
  virtual bool allowDelete() const;
  virtual bool isProxy() const;
  virtual bool isIdFilter() const;
  virtual bool filter(GcDbLayerTableRecord* layer) const;

  enum DialogResult { kOk = 0, kCancel = 1, kUseDefault = 2 };
  virtual  DialogResult showEditor();
  virtual const GCHAR * filterExpression() const;
  virtual Gcad::ErrorStatus setFilterExpression(const GCHAR * expr);
  virtual const GcLyBoolExpr* filterExpressionTree() const;
  virtual bool compareTo(const GcLyLayerFilter* pOther) const;
  virtual Gcad::ErrorStatus readFrom(GcDbDxfFiler* filer);
  virtual Gcad::ErrorStatus writeTo(GcDbDxfFiler* pFiler) const;

private:
  void *mp_impObj;
  friend class GcLySystemInternals;

protected:
  GcLyLayerFilter(GcLySystemInternals*);
};


class GCDB_PORT GcLyLayerGroup : public GcLyLayerFilter
{
public:
  GCRX_DECLARE_MEMBERS(GcLyLayerGroup);
  GcLyLayerGroup();

  virtual Gcad::ErrorStatus        addLayerId(const GcDbObjectId& id);
  virtual Gcad::ErrorStatus        removeLayerId(const GcDbObjectId& id);
  virtual const GcDbObjectIdArray& layerIds() const;

protected:
  GcLyLayerGroup(GcLySystemInternals*);
};


class GcLyLayerFilterManager
{
public:
  virtual ~GcLyLayerFilterManager() { }

  virtual Gcad::ErrorStatus getFilters(GcLyLayerFilter*& pRoot, GcLyLayerFilter*& pCurrent) = 0;
  virtual Gcad::ErrorStatus setFilters(const GcLyLayerFilter* pRoot, const GcLyLayerFilter* pCurrent) = 0;
};

GCDB_PORT GcLyLayerFilterManager* gclyGetLayerFilterManager(
  GcDbDatabase* pDb);

#endif  