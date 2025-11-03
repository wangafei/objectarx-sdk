#ifndef _DbBlock1PtParameter_h_Included_
#define _DbBlock1PtParameter_h_Included_

#include "DbBlockParameter.h"

class DYNBLOCKS_EXPORT OdDbBlock1PtParameter : public OdDbBlockParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlock1PtParameter);
  //OdDbBlockGripPtr getAssociatedGrip( OdDb::OpenMode );
  //virtual void graphEvalEnd(bool);
  //OdGePoint3d definitionPoint() const;
  //void setDefinitionPoint( const OdGePoint3d& );
  //OdGePoint3d point();
  //void setPoint( const OdGePoint3d& );
  //OdGePoint3d updatedPoint();
  //void setUpdatedPoint( const OdGePoint3d& );

  virtual OdGePoint3d updatedPoint() const;
  virtual void setUpdatedPoint(const OdGePoint3d &pnt);

  virtual OdGePoint3d getBasePoint() const;
  virtual void setBasePoint(const OdGePoint3d &pnt);

  virtual OdDbEvalNodeId getGripId() const;
  virtual void setGripId(const OdDbEvalNodeId &id);

  virtual OdDbBlockParameter::PropertyInfo getPropertyInfo(const int &idx) const;
  virtual void setPropertyInfo(const OdDbBlockParameter::PropertyInfo &pro, const int &idx);
};


#endif // _DbBlock1PtParameter_h_Included_
