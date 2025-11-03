#ifndef _DbBlock2PtParameter_h_Included
#define _DbBlock2PtParameter_h_Included

#include "DbBlockActions.h"
#include "DbBlockParameter.h"

class DYNBLOCKS_EXPORT OdDbBlock2PtParameter : public OdDbBlockParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlock2PtParameter);
  enum ParameterBaseLocation { start = 0, mid = 1 };
  OdGePoint3d basePoint() const;
  OdGePoint3d endPoint() const;
  double distance() const;
  double angle() const;
  ParameterBaseLocation baseLocation() const;
  OdGePoint3d definitionBasePoint() const;
  OdGePoint3d definitionEndPoint() const;
  double definitionDistance() const;
  double definitionAngle() const;
  OdGePoint3d updatedBasePoint() const;
  OdGePoint3d updatedEndPoint() const;
  double updatedDistance() const;
  double updatedAngle() const;
  OdGeVector3d normal() const;
  //OdDbBlockGripPtr getAssociatedGrip( OdDbBlockParameter::ParameterComponent, OdDb::OpenMode );
  //virtual void graphEvalEnd( bool );
  //bool parameterComponentDrivesAction( OdDbBlockParameter::ParameterComponent, const OdDbBlockAction* );
  bool parameterComponentHasAction( OdDbBlockParameter::ParameterComponent, const OdDbBlockAction*);
  void setBaseLocation(ParameterBaseLocation);
  void setBasePoint( const OdGePoint3d& );
  void setEndPoint(const OdGePoint3d &);
  void setDefinitionBasePoint( const OdGePoint3d& );
  void setDefinitionEndPoint( const OdGePoint3d&);
  void setUpdatedBasePoint(const OdGePoint3d &);
  void setUpdatedEndPoint(const OdGePoint3d &);

  virtual void getGripNodes(OdDbEvalNodeIdArray &ar) const;
  virtual void setGripNodes(const OdDbEvalNodeIdArray &ar);

  virtual OdDbBlockParameter::PropertyInfo getPropertyInfo(const int &idx) const;
  virtual void setPropertyInfo(const OdDbBlockParameter::PropertyInfo &pro, const int &idx);
};

typedef OdSmartPtr<OdDbBlock2PtParameter>OdDbBlock2PtParameterPtr;

#endif //_DbBlock2PtParameter_h_Included
