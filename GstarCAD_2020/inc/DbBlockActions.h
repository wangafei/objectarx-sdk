#ifndef _DbBlocksActions_h_Included_
#define _DbBlocksActions_h_Included_

//#include "DbObjectImpl.h"
#include "DbEvalGraph.h"
//#include "DbEvalGraphImpl.h"
#include "Ge/GePoint2dArray.h"
#include "DbBlockElement.h"
#include "DbBlockParameter.h"

struct OdDbBlockStretchEntityItem
{
	OdDbSoftPointerId m_pId;
	OdIntArray m_pStretchPointIndices;
	OdDbBlockStretchEntityItem() : m_pId(0){}
};

struct OdDbBlockStretchNodeItem
{
	OdDbEvalNodeId m_nId;
	OdIntArray m_pStretchPointIndices;
	OdDbBlockStretchNodeItem() : m_nId(0){}
};

class DYNBLOCKS_EXPORT OdDbBlockAction : public OdDbBlockElement
{
public:
  enum OdDbBlockActionXYType{ XY, X, Y };
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockAction);
  virtual OdGePoint3d displayLocation() const;
  virtual void setDisplayLocation( const OdGePoint3d& );
  virtual bool isActivatable();
  virtual OdDbEvalNodeId drivingParameterNodeId()const;
  //virtual OdDbObjectIdArray elementSelectionSet()const;

  virtual OdDbObjectIdArray selectionSet() const;
  virtual OdDbObjectIdArray getSelectionSet() const;
  virtual void setSelectionSet(const OdDbObjectIdArray &objIds);
  virtual OdDbBlockParameterPtr getAssociatedParameter( OdDb::OpenMode mode = OdDb::kForRead ) const;
  //virtual void setSelectionSet( const OdDbObjectIdArray& );

  virtual void getElementsSelectionSet(OdDbEvalNodeIdArray &nodes) const;
  virtual void setElementsSelectionSet(const OdDbEvalNodeIdArray &nodes);

  virtual double getDistanceMultiplier() const;
  virtual void setDistanceMultiplier(const double &d);

  virtual double getAngleOffset() const;
  virtual void setAngleOffset(const double &d);

  virtual OdDbBlockActionXYType getXYScaleType() const;
  virtual void setXYScaleType(const OdDbBlockActionXYType &t);

  virtual OdInt32 getUnkXYScaleTypeRelated() const;
  virtual void setUnkXYScaleTypeRelated(const OdInt32 &d);
};


class DYNBLOCKS_EXPORT OdDbBlockMoveAction : public OdDbBlockAction
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockMoveAction);
  OdDbBlockMoveAction();
  //double angleOffset();
  //double distanceMultiplier();
  //OdDbBlockActionXYType distanceType();
  //void setAngleOffset(double);
  //void setDistanceMultiplier(double);
  //void setDistanceType(OdDbBlockActionXYType);

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);
};

class DYNBLOCKS_EXPORT OdDbBlockStretchAction : public OdDbBlockAction
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockStretchAction);
  OdDbBlockStretchAction();
  //double angleOffset()const;
  //double distanceMultiplier()const;
  //OdDbBlockActionXYType distanceType()const;
  //void setAngleOffset(double);
  //void setDistanceMultiplier(double);
  //void setDistanceType(OdDbBlockActionXYType);
  //void setStretchFrame(const OdGePoint2dArray&);
  //OdGePoint2dArray stretchFrame() const;

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);

  virtual void getStretchFrame(OdGePoint2dArray &ar) const;
  virtual void setStretchFrame(const OdGePoint2dArray &ar);

  virtual void getEntitySelection(OdArray<OdDbBlockStretchEntityItem> &ar) const;
  virtual void setEntitySelection(const OdArray<OdDbBlockStretchEntityItem> &ar);

  virtual void getNodeSelection(OdArray<OdDbBlockStretchNodeItem> &ar) const;
  virtual void setNodeSelection(const OdArray<OdDbBlockStretchNodeItem> &ar);
};

class DYNBLOCKS_EXPORT OdDbBlockActionWithBasePt : public OdDbBlockAction
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockActionWithBasePt);
  //OdGePoint3d basePoint() const;
  //OdGeVector3d basePointOffset() const;
  //bool dependent() const;
  //void setBasePoint(OdGePoint3d const &);
  //void setBasePointOffset(OdGeVector3d const &);
  //void setDependent(bool);

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);

  virtual OdGePoint3d getBasePoint() const;
  virtual void setBasePoint(const OdGePoint3d &p);

  virtual bool getIndependent() const;
  virtual void setIndependent(const bool &b);

  virtual OdGePoint3d getOffset() const;
  virtual void setOffset(const OdGePoint3d &p);
};

class DYNBLOCKS_EXPORT OdDbBlockScaleAction : public OdDbBlockActionWithBasePt
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockScaleAction);
  OdDbBlockScaleAction();
  //OdDbBlockActionXYType scaleType();
  //void setScaleType( OdDbBlockActionXYType );

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);
};

class DYNBLOCKS_EXPORT OdDbBlockRotateAction : public OdDbBlockActionWithBasePt
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockRotateAction);
  OdDbBlockRotateAction();

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);
};

class DYNBLOCKS_EXPORT OdDbBlockFlipAction : public OdDbBlockAction
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockFlipAction);
  OdDbBlockFlipAction();

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);
};

class DYNBLOCKS_EXPORT OdDbBlockArrayAction : public OdDbBlockAction
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockArrayAction);
  OdDbBlockArrayAction();
  //double columnOffset() const;
  //double rowOffset() const;
  //void setColumnOffset(double);
  //void setRowOffset(double);

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);

  virtual double getRowOffset() const;
  virtual void setRowOffset(const double &d);

  virtual double getColumnOffset() const;
  virtual void setColumnOffset(const double &d);
};

class OdDbDataTable;
typedef OdSmartPtr<OdDbDataTable>OdDbDataTablePtr;

class DYNBLOCKS_EXPORT OdDbBlockLookupAction : public OdDbBlockAction
{
public:
	struct ColumnInfo
	{
		OdDbEvalNodeId m_nParameterId;
		int m_nResType;
		int m_nType; // unit type?
		bool m_bLookupProperty; // or input property
		OdString m_sUnmatched;
		bool m_bNotReadonly;
		OdString m_sConnection;
		OdDbObjectId m_IdParameter;
		ColumnInfo() : m_nParameterId(0)
			, m_nResType(0)
			, m_nType(0)
			, m_bLookupProperty(true)
			, m_bNotReadonly(true)
			, m_IdParameter(OdDbObjectId::kNull){}
	};
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockLookupAction);
  OdDbBlockLookupAction();
  //bool duplicateCellsInLookupColumn(int,int *);
  //bool duplicateCellsInLookupColumn( const OdResBufArray&, const OdArray<void*>&,int,int *);
  //bool duplicateRowsOverInputColumns(int *);
  //bool duplicateRowsOverInputColumns( const OdResBufArray &, const OdArray<void*>&,int *);
  //OdDbDataTablePtr getLookupTable( OdArray<void*> & );

  void getLookupTable( OdDbEvalVariantArray&, OdArray<void*>& );
  //bool nonSingletonRangeInInputColumns(int *);
  //bool nonSingletonRangeInInputColumns( const OdResBufArray &,const OdArray<void*>&,int *);
  //bool nullsInInputColumns(int *);
  //bool nullsInInputColumns( const OdResBufArray&, const OdArray<void*>&,int *);

  OdUInt32 numberOfInputColumns() const;
  OdUInt32 numberOfOutputColumns()const;
  OdUInt32 numberOfColumns() const;
  OdUInt32 numberOfRows()const;
  //void setLookupTable( const OdResBufArray &, OdArray<void*> const &);
  //void setLookupTable( const OdDbDataTable *, OdArray<void*>&);

  void getTableValue(OdStringArray &values) const;
  void getColumnsInfo(OdArray<OdDbBlockLookupAction::ColumnInfo> &infos) const;
  void setTableValueAndColumnsInfo(const OdUInt32 &rows, const OdUInt32 &cols, const OdStringArray &values, const OdArray<OdDbBlockLookupAction::ColumnInfo> &infos);

  bool getUnk1() const;
  void setUnk1(const bool &b);
};
typedef OdSmartPtr<OdDbBlockLookupAction>OdDbBlockLookupActionPtr;

class DYNBLOCKS_EXPORT OdDbBlockPolarStretchAction : public OdDbBlockAction
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockPolarStretchAction);
  OdDbBlockPolarStretchAction();
  //double angleOffset() const;
  //double distanceMultiplier() const;
  //OdDbObjectIdArray rotateOnlyElementSelectionSet();
  //OdDbObjectIdArray rotateOnlySelectionSet();
  //void setAngleOffset(double);
  //void setDistanceMultiplier(double);
  //void setRotateOnlySelectionSet(const OdDbObjectIdArray&);
  //void setStretchFrame(const OdGePoint2dArray &);
  //OdGePoint2dArray stretchFrame();

  virtual void getConnections(OdDbConnectionPoint &cpt, const int &idx) const;
  virtual void setConnections(const OdDbConnectionPoint &cpt, const int &idx);

  virtual void getStretchFrame(OdGePoint2dArray &ar) const;
  virtual void setStretchFrame(const OdGePoint2dArray &ar);

  virtual void getRotateSelection(OdArray<OdDbSoftPointerId> &ar) const;
  virtual void setRotateSelection(const OdArray<OdDbSoftPointerId> &ar);

  virtual void getEntitySelection(OdArray<OdDbBlockStretchEntityItem> &ar) const;
  virtual void setEntitySelection(const OdArray<OdDbBlockStretchEntityItem> &ar);

  virtual void getNodeSelection(OdArray<OdDbBlockStretchNodeItem> &ar) const;
  virtual void setNodeSelection(const OdArray<OdDbBlockStretchNodeItem> &ar);
};

#endif // _DbBlocksActions_h_Included_
