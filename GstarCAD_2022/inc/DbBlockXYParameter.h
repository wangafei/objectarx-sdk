#ifndef _DbBlockXYParameter_h_Included_
#define _DbBlockXYParameter_h_Included_

#include "DbBlock2PtParameter.h"
#include "DbBlockParamValueSet.h"

class OdDbBlockXYGrip;
typedef OdSmartPtr<OdDbBlockXYGrip>OdDbBlockXYGripPtr;

class DYNBLOCKS_EXPORT OdDbBlockXYParameter : public OdDbBlock2PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockXYParameter);
  OdDbBlockXYParameter();
  //double definitionHorzDistance()const;
  //double definitionVertDistance()const;
  //OdDbBlockXYGripPtr getAssociatedXYGrip(OdDbBlockParameter::ParameterComponent,OdDb::OpenMode);
  //OdString horzDescription() const;
  //double horzDistance()const;
  //OdString horzName()const;
  //void setDefinitionHorzDistance(double);
  //void setDefinitionVertDistance(double);
  //void setHorzDescription(const OdString&);
  //void setHorzDistance(double);
  //void setHorzName(const OdString&);
  //void setUpdatedHorzDistance(double);
  //void setUpdatedVertDistance(double);
  //void setVertDescription(const OdString&);
  //void setVertDistance(double);
  //void setVertName(const OdString&);
  //void setXOffset(double);
  //void setXValueSet(const OdDbBlockParamValueSet &);
  //void setYOffset(double);
  //void setYValueSet(const OdDbBlockParamValueSet &);
  //double updatedHorzDistance() const;
  //double updatedVertDistance() const;
  //OdString  vertDescription() const;
  //double vertDistance() const;
  //OdString  vertName() const;
  //double XOffset() const;
  //class OdDbBlockParamValueSet  xValueSet() const;
  //double YOffset() const;
  //class OdDbBlockParamValueSet  yValueSet() const;

  virtual OdString getYLabel() const;
  virtual void setYLabel(const OdString &str);

  virtual OdString getXLabel() const;
  virtual void setXLabel(const OdString &str);

  virtual OdString getYLabelDesc() const;
  virtual void setYLabelDesc(const OdString &str);

  virtual OdString getXLabelDesc() const;
  virtual void setXLabelDesc(const OdString &str);

  virtual double getYLabelOffset() const;
  virtual void setYLabelOffset(const double &d);

  virtual double getXLabelOffset() const;
  virtual void setXLabelOffset(const double &d);

  virtual OdDbBlockParamValueSet getX() const;
  virtual void setX(const OdDbBlockParamValueSet &set);

  virtual OdDbBlockParamValueSet getY() const;
  virtual void setY(const OdDbBlockParamValueSet &set);
};

#endif // _DbBlockXYParameter_h_Included_
