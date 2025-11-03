#ifndef _DbBlockPointParameter_h_Included_
#define _DbBlockPointParameter_h_Included_

#include "DbBlock1PtParameter.h"

class DYNBLOCKS_EXPORT OdDbBlockPointParameter : public OdDbBlock1PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockPointParameter);
  OdDbBlockPointParameter();
protected:
  //OdGePoint3d definitionLabelPoint() const;
  //double definitionX() const;
  //double definitionY() const;
  //OdDbBlockXYGripPtr getAssociatedXYGrip( OdDb::OpenMode );
  //OdString positionDescription() const;
  //OdString positionName() const;
  //void setDefinitionLabelPoint( const OdGePoint3d& );
  //void setDefinitionX(double);
  //void setDefinitionY(double);
  //void setPositionDescription(const OdString&);
  //void setPositionName(const OdString&);
  //void setUpdatedX(double);
  //void setUpdatedY(double);
  //void setX(double);
  //void setY(double);
  //double updatedX();
  //double updatedY();
  //double X();
  //double Y();

public:
	virtual OdGePoint3d getLabelPosition() const;
	virtual void setLabelPosition(const OdGePoint3d &pnt);

	virtual OdString getLabel() const;
	virtual void setLabel(const OdString &str);

	virtual OdString getDescription() const;
	virtual void setDescription(const OdString &str);
};

#endif // _DbBlockPointParameter_h_Included_
