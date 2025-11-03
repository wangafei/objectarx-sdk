#ifndef _DbBlocksGrips_h_Included_
#define _DbBlocksGrips_h_Included_

//#include "DbObjectImpl.h"
#include "DbEvalGraph.h"
//#include "DbEvalGraphImpl.h"
#include "DbBlockParameter.h"
#include "DbBlockElement.h"
#include "DbBlockFlipParameter.h"

class DYNBLOCKS_EXPORT OdDbBlockGripExpr : public OdDbEvalExpr
{
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockGripExpr);
  OdDbBlockGripExpr();

  virtual void getMessage(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setMessage(const OdDbConnectionPoint &cpt, const int &idx);
};
class OdDbGripData;
class DYNBLOCKS_EXPORT OdDbBlockGrip : public OdDbBlockElement
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockGrip);
  OdDbBlockGrip();
  //virtual void addedToGraph( OdDbEvalGraph* );
  //virtual void removedFromGraph( OdDbEvalGraph* );
  //OdGeVector3d definitionGripOffset() const;
  OdGePoint3d displayLocation() const;
  OdDbBlockParameterPtr getAssociatedParameter(OdDb::OpenMode mode = OdDb::kForRead) const;
  OdDbBlockParameter::ParameterComponent getAssociatedParameterComponent() const;
  //OdGeVector3d gripOffset();
  //bool insertionCycling() const;
  //long insertionCyclingWeight() const;
  //OdGePoint3d location() const;
  //OdGePoint3d paramBasePoint() const;
  //void setDisplayLocation(class OdGePoint3d const &);
  //void setGripDataCallbacks( class OdDbGripData* );
  //void setInsertionCycling(bool);
  //void setInsertionCyclingWeight(long);
  void setUpdatedLocation(class OdGePoint3d const &);
  OdGePoint3d updatedLocation();

  virtual OdDbEvalNodeId getNodeId1() const;
  virtual void setNodeId1(const OdDbEvalNodeId &id);

  virtual OdDbEvalNodeId getNodeId2() const;
  virtual void setNodeId2(const OdDbEvalNodeId &id);

  virtual OdGePoint3d getBasePosition() const;
  virtual void setBasePosition(const OdGePoint3d &pnt);

  virtual bool getCycling() const;
  virtual void setCycling(const bool &b);

  virtual int  getType() const;
  virtual void setType(const int &type);
};

//class OdDbBlockPointParameter;
//typedef OdSmartPtr<OdDbBlockPointParameter>OdDbBlockPointParameterPtr;
//class OdDbBlockXYParameter
//typedef OdSmartPtr<OdDbBlockXYParameter>OdDbBlockXYParameterPtr;
class DYNBLOCKS_EXPORT OdDbBlockXYGrip : public OdDbBlockGrip
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockXYGrip);
  OdDbBlockXYGrip();
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  // Gcad(Modify): void->OdResult
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  //OdDbBlockPointParameterPtr getAssociatedPointParameter( OdDb::OpenMode )
  //OdDbBlockXYParameterPtr getAssociatedXYParameter( OdDb::OpenMode )
  //void setGripDataCallbacks( OdDbGripData* );
};

class DYNBLOCKS_EXPORT OdDbBlockPolarGrip : public OdDbBlockGrip
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockPolarGrip);
  OdDbBlockPolarGrip();
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  // Gcad(Modify): void->OdResult
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  //OdDbBlockPolarParameterPtr getAssociatedPolarParameter( OdDb::OpenMode );
  //void setGripDataCallbacks( OdDbGripData* );
};

class DYNBLOCKS_EXPORT OdDbBlockRotationGrip : public OdDbBlockGrip
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockRotationGrip);
  OdDbBlockRotationGrip();
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  // Gcad(Modify): void->OdResult
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  //AcDbBlockRotationParameterPtr AcDbBlockRotationGrip::getAssociatedRotationParameter( OdDb::OpenMode );
  //void setGripDataCallbacks( OdDbGripData* );
};

class DYNBLOCKS_EXPORT OdDbBlockLinearGrip : public OdDbBlockGrip
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockLinearGrip);
  OdDbBlockLinearGrip();
  //OdDbBlockLinearParameterPtr getAssociatedLinearParameter( OdDb::OpenMode );
  OdGeVector3d orientation() const;
  //void setGripDataCallbacks( OdDbGripData* );
  void setOrientation( const OdGeVector3d &);

  virtual OdGeVector3d getInitDist() const;
  virtual void setInitDist(const OdGeVector3d &vec);
};

class DYNBLOCKS_EXPORT OdDbBlockFlipGrip : public OdDbBlockGrip
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockFlipGrip);
  OdDbBlockFlipGrip();
  //void cycleFlipState();
  //OdDbBlockFlipParameterPtr getAssociatedFlipParameter( OdDb::OpenMode );
  //void setGripDataCallbacks( OdDbGripData* );

  OdDbBlockFlipParameter::FlipState flipState() const;
  void setFlipState( OdDbBlockFlipParameter::FlipState );

  void setUpdatedFlipState( OdDbBlockFlipParameter::FlipState );
  OdDbBlockFlipParameter::FlipState updatedFlipState();

  OdGeVector3d orientation();
  void setOrientation(const OdGeVector3d & );

  virtual OdGeVector3d getFlipLine() const;
  virtual void setFlipLine(const OdGeVector3d &vec);

  virtual int  getUnk() const;
  virtual void setUnk(const int &unk);

  virtual int getFlipped() const;
  virtual void setFlipped(const int &i);
};

class DYNBLOCKS_EXPORT OdDbBlockLookupGrip : public OdDbBlockGrip
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockLookupGrip);
  OdDbBlockLookupGrip();
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  // Gcad(Modify): void->OdResult
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  //OdDbBlock1PtParameterPtr AcDbBlockLookupGrip::getAssociatedLookupParameter( OdDb::OpenMode );
  //void getValueList( OdResBufArray& );
  //void setGripDataCallbacks( OdDbGripData* );
  //bool showGrip() const;
};

class DYNBLOCKS_EXPORT OdDbBlockAlignmentGrip : public OdDbBlockGrip
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockAlignmentGrip);
  OdDbBlockAlignmentGrip();
  //OdDbBlockAlignmentParameterPtr getAssociatedAlignmentParameter( OdDb::OpenMode );
  //OdGeVector3d orientation();
  //void setGripDataCallbacks( OdDbGripData* );
  //void setOrientation( const OdGeVector3d& )

  virtual OdGeVector3d getAlignmentLine() const;
  virtual void setAlignmentLine(const OdGeVector3d &vec);

  virtual int getFlipped() const;
  virtual void setFlipped(const int &i);
};

class DYNBLOCKS_EXPORT OdDbBlockVisibilityGrip : public OdDbBlockGrip
{
public:
  ODDB_DECLARE_MEMBERS(OdDbBlockVisibilityGrip);
  OdDbBlockVisibilityGrip();
  OdResult dxfInFields(OdDbDxfFiler* pFiler);
  // Gcad(Modify): void->OdResult
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const;
  //void getValueList( OdResBufArray& );
  //void setGripDataCallbacks( OdDbGripData* );
  //bool showGrip() const;
};

#endif // _DbBlocksGrips_h_Included_
