/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GC_BRMESH2D_H
#define GC_BRMESH2D_H 1

#include "../../../inc/gsoft.h"
#include "../../../inc/rxobject.h"
#include "../../../inc/rxboiler.h"
#include "brgbl.h"
#include "brmesh.h"
#include "brm2dctl.h"

class GcBrEntity;
class GcBrMesh2dControl;
class GcBrMesh;
class GcBrMesh2dData;

static GcBrMesh2dControl GcBrMesh2dControlDefault;

struct pair
{
  GcBrEntity*       first;
  GcBrMesh2dControl second;
  pair() : first((GcBrEntity*)NULL), second(GcBrMesh2dControlDefault) {}
  pair(const GcBrEntity*& a, const GcBrMesh2dControl& b) : first((GcBrEntity*)a), second(b) {}
};

inline pair make_pair(const GcBrEntity*& entity, const GcBrMesh2dControl& control)
{
  return pair(entity, control);
}

typedef pair value_type;
typedef void iterator;

class GCBR_PORT GcBrMesh2dFilter
{
public:
  GcBrMesh2dFilter();
  ~GcBrMesh2dFilter();

  iterator insert(const value_type& x);

private:
  friend class GcBrImpMesh2d;

  GcBrMesh2dFilter(const GcBrMesh2dFilter& src);
  GcBrMesh2dFilter& operator =(const GcBrMesh2dFilter& src);

  value_type mKeyValuePair;
};

class GCBR_PORT GcBrMesh2d : public GcBrMesh
{
public:
  GCRX_DECLARE_MEMBERS(GcBrMesh2d);
  GcBrMesh2d();
  GcBrMesh2d(const GcBrMesh2d& src);
  ~GcBrMesh2d();

  GcBrMesh2d&         operator =      (const GcBrMesh2d& src);

  GcBr::ErrorStatus   set(GcBrMesh2dData* mesh2d);
  GcBr::ErrorStatus   get(GcBrMesh2dData*& mesh2d) const;
  GcBr::ErrorStatus   generate(const GcBrMesh2dFilter& meshFilter);
};

inline GcBrMesh2dFilter::GcBrMesh2dFilter()
{
}

inline GcBrMesh2dFilter::~GcBrMesh2dFilter()
{
}

inline iterator GcBrMesh2dFilter::insert(const value_type& x)
{
  mKeyValuePair.first = x.first;
  mKeyValuePair.second = x.second;
}

#endif
