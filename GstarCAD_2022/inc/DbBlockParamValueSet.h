#ifndef _DbBlockParamValueSet_h_Included_
#define _DbBlockParamValueSet_h_Included_

#include "DbEvalGraph.h"
#include "Ge/GeDoubleArray.h"
#include "RxObjectImpl.h"
class OdDbBlockParamValueSetImpl;

#if defined(WIN32) || defined(_WIN32_WCE) || defined(__MWERKS__)
#include <math.h>
#else
#include <complex>
#endif

class DYNBLOCKS_EXPORT OdDbBlockParamValueSet : public OdRxObject
{
protected:
  OdDbBlockParamValueSet(void *);
public: 
  ODRX_DECLARE_MEMBERS(OdDbBlockParamValueSet);
  OdDbBlockParamValueSet( const OdDbBlockParamValueSet&);
  OdDbBlockParamValueSet();
  virtual ~OdDbBlockParamValueSet();
  class OdDbBlockParamValueSet & operator=(const OdDbBlockParamValueSet &);
  bool angDir()const ;
  bool angular()const ;
  virtual double closestLegalValue( double value )const ;
  virtual double closestLegalValue( double value, const double &def)const ;
  virtual double closestLegalAngle( double value, const double &def)const ;
  virtual void dwgInFieldsHelper(OdDbDwgFiler *);
  virtual void dwgOutFieldsHelper(OdDbDwgFiler *)const ;
  virtual void dxfInFieldsHelper(OdDbDxfFiler *,short,short,short,short);
  virtual void dxfOutFieldsHelper(OdDbDxfFiler *,short,short,short,short)const ;
  double increment()const ;
  double maximum()const ;
  double minimum()const ;
  void setAngDir(bool);
  void setAngular(bool);
  void setIncrement(double);
  void setIncrement(double,bool);
  void setMaximum(double);
  void setMaximum(double,bool);
  void setMinimum(double);
  void setMinimum(double,bool);
  void setUseIncrement(bool);
  void setUseMaximum(bool);
  void setUseMinimum(bool);
  void setUseValueList(bool);
  void setValueList(OdGeDoubleArray const &);
  void setValueList(OdGeDoubleArray const &,bool);
  OdGeDoubleArray  sortedValueListIncluding(double)const ;
  void updateValue(double);
  bool useIncrement()const ;
  bool useMaximum()const ;
  bool useMinimum()const ;
  bool useValueList()const ;
  virtual bool valueIsLegal(double,double)const ;
  OdGeDoubleArray  valueList()const ;
private:
  OdDbBlockParamValueSetImpl* m_pImpl;
};

//typedef OdSmartPtr<OdDbBlockParamValueSet> OdDbBlockParamValueSetPtr;

#endif // _DbBlockParamValueSet_h_Included_
