#ifndef _DbBlockPolarParameter_h_Included_
#define _DbBlockPolarParameter_h_Included_

#include "DbBlock2PtParameter.h"
#include "DbBlockParamValueSet.h"

class OdDbBlockPolarGrip;
typedef OdSmartPtr<OdDbBlockPolarGrip>OdDbBlockPolarGripPtr;
class DYNBLOCKS_EXPORT OdDbBlockPolarParameter : public OdDbBlock2PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockPolarParameter);
  OdDbBlockPolarParameter();
  //OdString angleDescription() const;
  //OdString angleName() const;
  //OdDbBlockParamValueSet angleValueSet() const;
  //double baseAngle() const;
  //OdGePoint3d baseAnglePoint() const;
  //OdString distanceDescription() const;
  //OdString distanceName() const;
  //OdDbBlockParamValueSet distanceValueSet() const;
  //OdDbBlockPolarGripPtr getAssociatedPolarGrip( OdDbBlockParameter::ParameterComponent, OdDb::OpenMode );
  //double offset();
  //void setAngleDescription(const OdString&);
  //void setAngleName(const OdString&);
  //void setAngleValueSet(class OdDbBlockParamValueSet const &);
  //void setDistanceDescription( const OdString&);
  //void setDistanceName( const OdString&);
  //void setDistanceValueSet(const OdDbBlockParamValueSet &);
  //void setOffset(double);
  //void setUpdatedAngle(double);
  //void setUpdatedDistance(double);

  virtual OdString getLabel() const;
  virtual void setLabel(const OdString &str);

  virtual OdString getLabelDesc() const;
  virtual void setLabelDesc(const OdString &str);

  virtual OdString getAngleLabel() const;
  virtual void setAngleLabel(const OdString &str);

  virtual OdString getAngleLabelDesc() const;
  virtual void setAngleLabelDesc(const OdString &str);

  virtual double getLabelOffset() const;
  virtual void setLabelOffset(const double &d);

  virtual OdDbBlockParamValueSet getDistValueSet() const;
  virtual void setDistValueSet(const OdDbBlockParamValueSet &set);

  virtual OdDbBlockParamValueSet getAngleValueSet() const;
  virtual void setAngleValueSet(const OdDbBlockParamValueSet &set);

};

#endif //_DbBlockPolarParameter_h_Included_
