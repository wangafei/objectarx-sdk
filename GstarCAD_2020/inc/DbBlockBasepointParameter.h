#ifndef _DbBlockBasepointParameter_h_Included_
#define _DbBlockBasepointParameter_h_Included_

#include "DbBlock1PtParameter.h"

class DYNBLOCKS_EXPORT OdDbBlockBasepointParameter : public OdDbBlock1PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockBasepointParameter);
  OdDbBlockBasepointParameter();
  //double definitionX()const;
  //double definitionY()const;
  //void setDefinitionX(double);
  //void setDefinitionY(double);

  virtual OdGePoint3d getUnk1() const;
  virtual void setUnk1(const OdGePoint3d &pnt);

  virtual OdGePoint3d getUnk2() const;
  virtual void setUnk2(const OdGePoint3d &pnt);
  OdGePoint3d updatedBasePoint();
};

typedef OdSmartPtr<OdDbBlockBasepointParameter> OdDbBlockBasepointParameterPtr;

#endif // _DbBlockBasepointParameter_h_Included_
