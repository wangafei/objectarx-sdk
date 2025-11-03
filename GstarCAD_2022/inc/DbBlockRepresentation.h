#ifndef _DbBlockRepresentation_h_Included_
#define _DbBlockRepresentation_h_Included_

#include "RxObjectImpl.h"
#include "DbBlockReference.h"
#include "DbEvalGraph.h"
#include "DbDynBlockReference.h"
#include "DbBlockParameter.h"

class OdDbBlockParameter;
class OdDbAttributeDefinition;
class OdDbAttribute;

class DYNBLOCKS_EXPORT OdDbBlockRepresentationContext : public OdRxObject
{
  OdDbObjectId m_pDynamicBlock;
  OdDbObjectId m_pAnonymousBlock;
  OdDbObjectId m_pBlockData;
  OdDbBlockReferencePtr m_pRef;
  OdDbEvalGraphPtr      m_NDBRO_Graph;
  OdDbObjectId          m_refId;
  OdDbObjectId          m_graphId;

  void updateAttributeMap();
  std::map<OdDbAttributeDefinition*, void*> m_pAttributeMap;
  bool m_bHasArray;
  void updateCachedData(OdDbBlockReference* ref);
  //
public:
  OdDbBlockRepresentationContext();
  OdDbBlockRepresentationContext( OdDbBlockReference* ref );
  ~OdDbBlockRepresentationContext();
  void init(const OdDbDynBlockReference* ref, OdDbBlockReference* dbref, OdDbEvalGraph* gr);
  void loadInstanceData(bool bRequireEvaluate = false);
  const OdDbBlockReference* getReference() const{ return m_pRef; }
  OdDbBlockReference* getReference() { return m_pRef; }
  bool originalPathToRepresentationPath( OdDbObjectIdArray&, bool bErase = true)const;
  void compactRepresentation();
  bool representationPathToOriginalPath( OdDbObjectIdArray& )const;
  // set RepBTag on representation block
  static void tagBlockRecord( OdDbBlockTableRecord* repBTR, const OdDbHandle& originalBlockHandle );
  // remove dynamic block related xdata && xdictionary entries
  static void clearRepBlock( OdDbBlockTableRecord* repRTR );
  //static bool hasRepresentation( OdDbBlockReference* ref );
  // create representation block for the insert
  void createRepresentation(bool dyn = true);
  static void addHistoryRecord( OdDbDictionary* dic2, const OdString& name, const OdDbEvalVariant& value, OdDbBlockElement* param );
  bool updateRepresentation();
  void updateRepresentation( OdDbEvalGraph* gr, const OdString& name, const OdDbEvalVariant& value, OdDbBlockElement* param, const OdDbEvalNodeIdArray* pNodeIds = NULL);
  
  OdDbObjectId getRepresentation() const { return m_pAnonymousBlock; }
  OdDbObjectId getOriginal() const { return m_pDynamicBlock; }
  OdDbEvalExprPtr getRepresentationNode(OdDbEvalNodeId id);
  OdDbEvalGraphPtr getGraph()
  {
    return m_NDBRO_Graph;
  }
  void writeUndo(OdDbEvalGraph* gr);
  void readUndo(OdDbObjectId refId, OdDbDwgFiler* pFiler);
  static OdDbBlockRepresentationContext* getRepresentationContext(OdDbBlockReference* br);
  static int getXDataPos(const OdResBufPtr buffPtr, const OdString& strXData);
  static bool isArrayCalcuteObject(OdDbObjectPtr pObj);

  OdDbAttributePtr getAttribute(OdDbAttributeDefinition*);
  OdGeMatrix3d getRelativeMatrix(const OdGeMatrix3d& m);
  OdGeVector3d getRelativeOffset(const OdGeVector3d& v);
  OdDbObjectId getBlockData() const { return m_pBlockData; }
  bool hasArray() {return m_bHasArray;}
  void setHasArray(bool hasArray) {m_bHasArray = hasArray;}
};

typedef bool(*DYN_SET_PARAM_VALUE_FUN)(LPVOID);
DYNBLOCKS_EXPORT OdResult OdDbUpdateDynBlockReferenceProperty(OdDbDynBlockReferenceProperty &pro, OdDbBlockElementPtr gripPtr, const OdDbEvalVariant& value, OdString name = OD_T("GRIPLOC"), DYN_SET_PARAM_VALUE_FUN pFun = NULL, LPVOID pParam = NULL);
DYNBLOCKS_EXPORT OdResult OdDbObtainDynBlockReferenceProperty(OdDbDynBlockReferenceProperty &pro, OdDbObjectId &paramId, OdDbBlkParamPropertyDescriptor &desptor);
DYNBLOCKS_EXPORT OdResult OdDbUpdateDynamicBlockReference(OdDbDynBlockReference &dynBlkRef, bool load = true);

#endif // _DbBlockRepresentation_h_Included_
