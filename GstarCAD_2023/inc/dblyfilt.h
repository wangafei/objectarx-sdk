/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBLYFILT_H
#define GD_DBLYFILT_H

#include "dbfilter.h"
#include "GdGChar.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbLayerFilter : public  GcDbFilter
{
public:
  GCDB_DECLARE_MEMBERS(GcDbLayerFilter);
  GcDbLayerFilter();
  ~GcDbLayerFilter();

  GcRxClass* indexClass() const override;
  virtual Gsoft::Boolean isValid() const;

  Gcad::ErrorStatus add(const GCHAR * pLayer);
  Gcad::ErrorStatus remove(const GCHAR * pLayer);
  Gcad::ErrorStatus getAt(int index, const GCHAR *& pName) const;
  int layerCount() const;
};

#pragma pack (pop)

#endif 