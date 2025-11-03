#ifndef _DbBlockVisibilityParameter_h_Included_
#define _DbBlockVisibilityParameter_h_Included_

#include "DbBlock1PtParameter.h"

class DYNBLOCKS_EXPORT OdDbBlockVisibilityParameter : public OdDbBlock1PtParameter
{
public:
  struct VisibilityState
  {
	OdString m_sName;
	OdArray<OdDbSoftPointerId> m_pSelection;
	OdArray<OdDbSoftPointerId> m_pSelection2;
  };

  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockVisibilityParameter);
  OdDbBlockVisibilityParameter();
  //void blockEntityList( OdDbObjectIdArray& ) const;
  //void clearListOfVisibilityStates();
  //int currentVisibilityState()const;
  //void getPropertyDescription( OdDbBlkParamPropertyDescriptorArray& )const;
  //OdResBufPtr getPropertyValue( const OdString& )const;
  //OdResBufPtr getPropertyValue( const OdString&, const OdGeMatrix3d & ) const;
  //virtual OdDbBlockElement::HistoryCompression historyCompression() const;
  //virtual bool historyRequired() const;
  //bool isInitialized() const;
  //void listVisibleEntities( OdDbObjectIdArray& ) const;
  //int numberOfVisibilityStates() const;
  //void setBlockEntityList( OdDbObjectIdArray& );
  //void setCurrentVisibilityState(int);
  //void setInitiaized(bool);
  //void setPropertyValue(const OdString&, const OdResBuf* );
  //void setPropertyValue(const OdString&,const OdGeMatrix3d &,const OdResBuf*);
  //void setVisibilityDescription(const OdString&);
  //void setVisibilityName(const OdString&);
  //void setVisibilityState(int,const OdString&, OdDbObjectIdArray& );
  //OdString visibilityDescription() const;
  //OdString visibilityName() const;
  //void visibilityState( int, OdString &, OdDbObjectIdArray&);

  virtual bool getUnk() const;
  virtual void setUnk(const bool &b);

  virtual OdString getLabel() const;
  virtual void setLabel(const OdString &str);

  virtual OdString getDescription() const;
  virtual void setDescription(const OdString &str);

  virtual bool getUnk1() const;
  virtual void setUnk1(const bool &b);

  virtual void getTotalObjects(OdArray<OdDbSoftPointerId> &ar) const;
  virtual void setTotalObjects(const OdArray<OdDbSoftPointerId> &ar);

  virtual void getVisibilityStates(OdArray<OdDbBlockVisibilityParameter::VisibilityState> &ar) const;
  virtual void setVisibilityStates(const OdArray<OdDbBlockVisibilityParameter::VisibilityState> &ar);
};

#endif // _DbBlockVisibilityParameter_h_Included_
