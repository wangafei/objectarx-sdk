#ifndef _DbBlockLookUpParameter_h_Included_
#define _DbBlockLookUpParameter_h_Included_

#include "DbBlock1PtParameter.h"

class OdDbBlockLookupGrip;
typedef OdSmartPtr<OdDbBlockLookupGrip> OdDbBlockLookupGripPtr;

class DYNBLOCKS_EXPORT OdDbBlockLookUpParameter : public OdDbBlock1PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockLookUpParameter);
  OdDbBlockLookUpParameter();
  //OdDbBlockLookupGripPtr getAssociatedLookupGrip( OdDb::OpenMode );
  //virtual bool historyRequired() const;
  //OdString lookupActionName() const;
  //OdString lookupDescription() const;
  //OdString lookupName() const;
  //void setLookupActionName(const OdString&);
  //void setLookupDescription(const OdString&);
  //void setLookupName(const OdString&);

  virtual OdString getLabel() const;
  virtual void setLabel(const OdString &str);

  virtual OdString getDescription() const;
  virtual void setDescription(const OdString &str);

  virtual int getLabelPosition() const;
  virtual void setLabelPosition(const int &i);
};

typedef OdSmartPtr<OdDbBlockLookUpParameter> OdDbBlockLookUpParameterPtr;

#endif // _DbBlockLookUpParameter_h_Included_
