#ifndef _DbBlockParameter_h_Included_
#define _DbBlockParameter_h_Included_

#include "DbBlockElement.h"
#include "DbEvalGraph.h"
#include "Ge/GeMatrix3d.h"
#include "DbDynBlockReference.h"

class OdDbBlockGrip;
typedef OdSmartPtr<OdDbBlockGrip> OdDbBlockGripPtr;
typedef OdArray< OdDbBlockGripPtr, OdMemoryAllocator<OdDbBlockGripPtr> > OdDbBlockGripPtrArray;

struct DYNBLOCKS_EXPORT OdDbBlkParamPropertyDescriptor
{
  OdDbBlkParamPropertyDescriptor();
  OdString m_sName;
  OdString m_sConnection;
  OdDb::DwgDataType m_nType;
  bool m_bReadonly;
  bool m_bVisible;
  OdString m_sDescription;
  bool m_bListPresent;
  OdDbDynBlockReferenceProperty::UnitsType m_nUnitsType;
  OdDbEvalVariantArray m_pAllowedValues;
};
typedef OdArray< OdDbBlkParamPropertyDescriptor > OdDbBlkParamPropertyDescriptorArray;

class DYNBLOCKS_EXPORT OdDbBlockParameter : public OdDbBlockElement
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockParameter);
  enum ParameterComponent 
  {
    Base,
    End,
    BaseXEndY,
    EndXBaseY,
    InvalidComponent
  };
  struct DYNBLOCKS_EXPORT PropertyInfo
  {
	  PropertyInfo();
	  OdInt16 m_nMessages;
	  OdArray<OdDbConnectionPoint> m_pConnections;
	  void dwgIn(OdDbDwgFiler* pFiler);
	  void dwgOut(OdDbDwgFiler* pFiler);
	  void dxfIn(OdDbDxfFiler* pFiler,int n1, int n2, int n3);
	  void dxfOut(OdDbDxfFiler* pFiler,int n1, int n2, int n3);
	  void copyFrom(const PropertyInfo &proInfo);
  };
  //virtual void removedFromGraph( OdDbEvalGraph* );
  virtual OdString getPropertyConnectionName( const OdString& )const;
  virtual void getPropertyDescription( OdDbBlkParamPropertyDescriptorArray& )const;
  virtual OdDbEvalVariant getPropertyValue( const OdString& )const;
  virtual OdDbEvalVariant getPropertyValue( const OdString&, const OdGeMatrix3d& )const;
  //virtual void gripErased( ParameterComponent );
  //virtual bool historyRequired() const;
  //static bool isPropertyLabelUnique( OdDbEvalGraph*, const OdString &, class OdString* );
  //virtual void getGrips( OdDbBlockGripPtrArray&, OdDb::OpenMode );
  //virtual int getNumberOfGrips() const;
  //virtual OdDbEvalNodeId addGrip( ParameterComponent );
  virtual ParameterComponent getComponentForGrip( OdDbEvalNodeId );
  //virtual void removeGrip( ParameterComponent );
  //virtual void resetGrips();
  //virtual void setNumberOfGrips( int );
  virtual bool setPropertyValue( const OdString&, const OdResBuf* );
  virtual bool setPropertyValue( const OdString&, const OdDbEvalVariant& );
  virtual bool setPropertyValue(const OdString&, const OdGeMatrix3d&, const OdResBuf*);
  virtual bool setPropertyValue( const OdString&, const OdGeMatrix3d&, const OdDbEvalVariant& );
  virtual bool chainActions()const;
  virtual void setChainActions( bool );
  virtual bool showProperties()const;
  virtual void setShowProperties( bool );
};

typedef OdSmartPtr<OdDbBlockParameter>OdDbBlockParameterPtr;

#endif // _DbBlockParameter_h_Included_
