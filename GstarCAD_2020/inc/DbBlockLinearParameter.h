#ifndef _DbBlockLinearParameter_h_Included_
#define _DbBlockLinearParameter_h_Included_

#include "DbBlock2PtParameter.h"
#include "DbBlockParamValueSet.h"

class OdDbBlockLinearGrip;
typedef OdSmartPtr<OdDbBlockLinearGrip> OdDbBlockLinearGripPtr;
class DYNBLOCKS_EXPORT OdDbBlockLinearParameter : public OdDbBlock2PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockLinearParameter);
  OdDbBlockLinearParameter();
  //OdString distanceDescription() const;
  //OdString distanceName() const;
  //OdDbBlockLinearGripPtr getAssociatedLinearGrip( OdDbBlockParameter::ParameterComponent, OdDb::OpenMode );
  //double offset() const;
  //void setDistanceDescription( const OdString& );
  //void setDistanceName( const OdString& );
  //void setOffset(double);
  //void setUpdatedDistance(double);
  void setValueSet(const OdDbBlockParamValueSet&);
  OdDbBlockParamValueSet valueSet();

  virtual OdString getLabel() const;
  virtual void setLabel(const OdString &str);

  virtual OdString getLabelDesc() const;
  virtual void setLabelDesc(const OdString &str);

  virtual double getLabelOffset() const;
  virtual void setLabelOffset(const double &d);
};

#endif //_DbBlockLinearParameter_h_Included_
