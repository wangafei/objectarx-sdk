#ifndef _DbBlockAlignmentParameter_h_Included_
#define _DbBlockAlignmentParameter_h_Included_

#include "DbBlock2PtParameter.h"

class OdDbBlockAlignmentGrip;
typedef OdSmartPtr<OdDbBlockAlignmentGrip> OdDbBlockAlignmentGripPtr;

class DYNBLOCKS_EXPORT OdDbBlockAlignmentParameter : public OdDbBlock2PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockAlignmentParameter);
  OdDbBlockAlignmentParameter();
  //bool alignPerpendicular();
  //OdDbBlockAlignmentGripPtr getAssociatedAlignmentGrip( OdDb::OpenMode );
  //virtual OdDbBlockElement::HistoryCompression historyCompression() const;
  //virtual bool historyRequired() const;
  //void setAlignPerpendicular(bool);

  virtual bool getPerpendicular() const;
  virtual void setPerpendicular(const bool &b);
};



#endif // _DbBlockAlignmentParameter_h_Included_
