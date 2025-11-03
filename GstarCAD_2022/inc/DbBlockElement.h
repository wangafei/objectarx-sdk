#ifndef _DbBlockElement_h_Included_
#define _DbBlockElement_h_Included_

#include "DbEvalGraph.h"
#include "IntArray.h"
#include "Ge/GePoint3dArray.h"

class OdDbBlockTableRecord;

// Gcad(Modify): void->OdResult
#define ODDB_EVAL_DECLARE_MEMBERS(ClassName) \
  ODDB_DECLARE_MEMBERS(ClassName);\
  OdResult dwgInFields(OdDbDwgFiler* pFiler);\
  OdResult dwgOutFields(OdDbDwgFiler* pFiler) const;\
  OdResult dxfInFields(OdDbDxfFiler* pFiler);\
  OdResult dxfOutFields(OdDbDxfFiler* pFiler) const

class DYNBLOCKS_EXPORT OdDbBlockElement : public OdDbEvalConnectable
{
public:
  enum HistoryCompression{kHistoryCompression0,kHistoryCompression1,kHistoryCompression2,kHistoryCompression3};
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockElement);

  // EvalExpr interface
  //virtual void adjacentNodeRemoved( const OdDbEvalNodeId& );
  // Gcad(Modify): bool->OdResult
  virtual OdResult evaluate( const OdDbEvalContext* );

  // OdDbEvalConnectable interface
  // Gcad(Modify): bool->OdResult
  virtual bool connectionAllowed(const OdString&, const OdDbEvalNodeId,const OdString&) const;
  virtual OdResult connectTo(const OdString&, const OdDbEvalNodeId,const OdString&);
  virtual OdResult disconnectFrom(const OdString&, const OdDbEvalNodeId,const OdString&);
  virtual bool hasConnectionNamed(const OdString&) const;
  virtual OdResult getConnectedNames(const OdString&, const OdDbEvalNodeId,OdStringArray&) const;
  virtual OdResult getConnectedObjects(const OdString&,OdDbEvalNodeIdArray&) const;
  virtual OdResult getConnectionNames(OdStringArray&) const;

  virtual OdResult getConnectionType (const OdString& name, OdResBuf::ValueType& type) const;
  virtual OdResult getConnectionValue(const OdString& name, OdDbEvalVariant& value) const;
  virtual OdResult setConnectionValue(const OdString& name, const OdDbEvalVariant& value);

  virtual OdString name() const;
  virtual void setName( const OdString& );

  virtual OdInt32 getUnk5() const;
  virtual void setUnk5(const OdInt32 &unk);

  //virtual unsigned long alertState() const;
  //virtual void auditAlertState();
  //OdDbObjectId getEntity();
  //OdRxClass* OdDbBlockElement::getRxEntity(void)

  virtual OdDb::MaintReleaseVer getInstanceMaintenanceVersion();
  virtual OdDb::DwgVersion  getInstanceVersion();
  virtual OdResult getStretchPoints( OdGePoint3dArray& )const;
  virtual OdResult moveStretchPointsAt( const OdIntArray &, const OdGeVector3d &);
  virtual HistoryCompression historyCompression() const;
  virtual bool historyRequired() const;

  //static bool isNameUnique(class OdDbEvalGraph* graph, const OdString& name, OdString* result );

  virtual bool hasInstanceData()const; // has instance data loaded
  virtual bool loadInstanceData(const OdResBuf*); // loads instance data from xdata chain
  virtual OdResBufPtr saveInstanceData()const; // saves instance data to xdata chain
  //virtual OdResult OdDbBlockElement::loadInstanceData(struct resbuf * *,bool);
  virtual void updateConnections();
  virtual bool onBeginEdit( OdDbBlockTableRecord* );

  /*
  void OdDbBlockElement::OnBeginEditCancelled(OdDbObjectId,OdDbObjectId)
  void OdDbBlockElement::OnBeginEditEnded(OdDbObjectId,OdDbObjectId)
  void OdDbBlockElement::OnBeginSaveCancelled(OdDbObjectId,OdDbObjectId)
  void OdDbBlockElement::OnBeginSaveEnded(OdDbObjectId,OdDbObjectId)
  void OdDbBlockElement::OnBeginSaveStarted(OdDbObjectId,OdDbObjectId)
  bool OdDbBlockElement::onEndEdit(OdDbBlockTableRecord *)
  void OdDbBlockElement::OnEndEditCancelled(OdDbObjectId,OdDbObjectId)
  void OdDbBlockElement::OnEndEditStarted(OdDbObjectId,OdDbObjectId)
  */

  virtual bool isMemberOfCurrentVisibilitySet()const;
  virtual void setMemberOfCurrentVisibilitySet(bool);

  //enum OdResult OdDbBlockElement::sync(OdDbBlockElementEntity *)
  //virtual void transformDefinitionBy(const OdGeMatrix3d &);

  virtual OdResult transformBy( const OdGeMatrix3d& );
};

typedef OdSmartPtr<OdDbBlockElement>OdDbBlockElementPtr;

struct OdDbConnectionPoint
{
	OdDbConnectionPoint() : m_nId(0){}
	OdDbEvalNodeId m_nId;
	OdString m_sConnection;
	void copyFrom(const OdDbConnectionPoint &cpt)
	{
		m_nId = cpt.m_nId;
		m_sConnection = cpt.m_sConnection;
	}
};

typedef OdArray<OdDbConnectionPoint> OdDbConnectionPointArray;

template<int N> class OdDbConnectionPointArrayT
{
public:
	OdDbConnectionPoint m_pData[N];
	OdDbConnectionPoint& operator[](int n){ return m_pData[n]; }
	const OdDbConnectionPoint& operator[](int n) const { return m_pData[n]; }
	int size() const { return N; }

	void dwgIn( OdDbDwgFiler* pFiler )
	{
		for ( int i = 0; i < N; i++ )
		{
			m_pData[i].m_nId = pFiler->rdInt32();
			m_pData[i].m_sConnection = pFiler->rdString();
		}
	}

	void dwgOut( OdDbDwgFiler* pFiler )
	{
		for ( int i = 0; i < N; i++ )
		{
			pFiler->wrInt32( m_pData[i].m_nId );
			pFiler->wrString( m_pData[i].m_sConnection );
		}
	}

	void dxfIn( OdDbDxfFiler* pFiler, int idGroupCode, int stringGroupCode)
	{
		while (!pFiler->atEOF())
		{
			int gc = pFiler->nextItem();
			if ( gc >= idGroupCode && (gc-idGroupCode) < N )
				m_pData[ gc - idGroupCode ].m_nId = pFiler->rdInt32();
			else if ( gc >= stringGroupCode && (gc-stringGroupCode) < N )
				m_pData[ gc - stringGroupCode ].m_sConnection = pFiler->rdString();
			else
			{
				pFiler->pushBackItem();
				return;
			}
		}
	}
	void dxfOut( OdDbDxfFiler* pFiler, int idGroupCode, int stringGroupCode, bool sequential = false )
	{
		if (sequential)
		{
			for ( int i = 0; i < N; i++ )
				pFiler->wrInt32( idGroupCode + i, m_pData[i].m_nId );
			for ( int j = 0; j < N; j++ )
				pFiler->wrString( stringGroupCode + j, m_pData[j].m_sConnection );
		}
		else
		{
			for ( int i = 0; i < N; i++ )
			{
				pFiler->wrInt32( idGroupCode + i, m_pData[i].m_nId );
				pFiler->wrString( stringGroupCode + i, m_pData[i].m_sConnection );
			}
		}
	}
};

#endif // _DbBlockElement_h_Included_
