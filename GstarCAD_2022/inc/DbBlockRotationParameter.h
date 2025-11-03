#ifndef _DbBlockRotationParameter_h_Included_
#define _DbBlockRotationParameter_h_Included_

#include "DbBlock2PtParameter.h"
#include "DbBlockParamValueSet.h"

class OdDbBlockRotationGrip;
typedef OdSmartPtr<OdDbBlockRotationGrip> OdDbBlockRotationGripPtr;
class DYNBLOCKS_EXPORT OdDbBlockRotationParameter : public OdDbBlock2PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockRotationParameter);
  OdDbBlockRotationParameter();
  //OdString angleDescription() const;
  //OdString angleName() const;
  //double baseAngle() const;
  //OdGePoint3d baseAnglePoint() const;
  //double definitionBaseAngle() const;
  //OdGePoint3d definitionBaseAnglePoint() const;
  //OdDbBlockRotationGripPtr getAssociatedRotationGrip( OdDb::OpenMode );
  //double offset() const;
  //void setAngleDescription(const OdString &);
  //void setAngleName(const OdString &);
  //void setDefinitionBaseAnglePoint( const OdGePoint3d& );
  //void setOffset(double);
  //void setUpdatedAngle(double);
  //void setValueSet( const OdDbBlockParamValueSet&);
  //OdDbBlockParamValueSet valueSet() const;

  virtual OdString getLabel() const;
  virtual void setLabel(const OdString &str);

  virtual OdString getLabelDesc() const;
  virtual void setLabelDesc(const OdString &str);

  virtual OdGePoint3d getStartPoint() const;
  virtual void setStartPoint(const OdGePoint3d &pnt);

  virtual double getLabelOffset() const;
  virtual void setLabelOffset(const double &d);

  virtual OdDbBlockParamValueSet getAngleValueSet() const;
  virtual void setAngleValueSet(const OdDbBlockParamValueSet &set);
};

typedef OdSmartPtr<OdDbBlockRotationParameter> OdDbBlockRotationParameterPtr;

#endif // _DbBlockRotationParameter_h_Included_
