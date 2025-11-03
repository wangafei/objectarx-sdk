/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef HLR_INC_BASEPEX_H_
#define HLR_INC_BASEPEX_H_

#include "Hlr.h"

class EXP_IMP GsoftHiddenLineBase : public GcRxObject
{
protected:
  std::map<GcDbEntity *, GcDbVoidPtrArray *> m_entityBodies;

public:
  GCRX_DECLARE_MEMBERS(GsoftHiddenLineBase);

  virtual Gcad::ErrorStatus prepare(GcDbEntity *pEnt, GcDbVoidPtrArray &bodies, int control, const GcDbViewport *pVp);
  virtual Gcad::ErrorStatus getBody(void *pBodyData, int control);

  static Gcad::ErrorStatus saveData(GcDbEntity *pEnt, void *pBodyData);
  static Gsoft::Boolean retrieveData(GcDbEntity *pEnt, GcDbVoidPtrArray &bodies, const GcDbViewport *pVp = nullptr);

  static void clear();
  static void clear(GcDbEntity *pEnt);
  static void clear(GcDbEntity *pEnt, GcDbViewport *pVp);

  static Gcad::ErrorStatus getBodyEntities(GcDbEntity *pEnt, GcDbVoidPtrArray &ents, int control, const GcDbViewport *pVp);
};
#endif