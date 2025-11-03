/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2012, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) Copyright (C) 2003-2012 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////




#ifndef DBSYMUTL_DEFINED
#define DBSYMUTL_DEFINED

#include "TD_PackPush.h"

#include "OdString.h"
#include "DbObjectId.h"
#include "DbSymbolTable.h"
#include "DbSymbolTableRecord.h"
#include "DbTextStyleTableRecord.h"
#include "DbDictionary.h"
#include "DbDatabase.h"

// Predefined names
#define AC_STRING(name, val) \
extern TOOLKIT_EXPORT_GLOBAL const OdString name;
#include "StdStrings.h"
#undef AC_STRING

#define ODDBSYMUTIL_SERVICES_CURRENT_VERSION 106
/** Description:

    {group:TD_Namespaces}
*/
namespace OdDbSymUtil
{
  enum CompatibilityMode
  {
    kExtendedNames = true,
    kPreExtendedNames = false
  };

  enum NameCaseMode
  {
    kPreserveCase = true,
    kForceToUpper = false
  };

  enum NewNameMode
  {
    kAsNewName = true,
    kAsExistingName = false
  };

  enum VerticalBarMode
  {
    kAllowVerticalBar = true,
    kNoVerticalBar = false
  };

  /** Description:
    If the symbol name was repaired, then newName is a repaired symbol name. 
    newName is empty if oldName did not need any repairing.
    allowVerticalBar is a boolean to indicate if vertical bars are allowed in the symbol name 
    
    Returns:
    eInvalidInput      if the specified name is empty
    eOk                in else case 
  */
  TOOLKIT_EXPORT OdResult repairSymbolName(
    OdString& newName,
    const OdString& oldName,
    const OdDbDatabase* pDb,
    bool allowVerticalBar = false,
    const OdChar symSubst = L'_',
    bool insertPrefix = true);
  
  inline OdString getSymbolName(const OdDbObjectId& objId)
  {
    OdDbSymbolTableRecordPtr pRec
      = OdDbSymbolTableRecord::ODSYSCALL1(cast , objId.openObject(OdDb::kForRead, true).get());
    if (!pRec.isNull())
    {
      return pRec->getName();
    }
    return OdString::kEmpty;
  }
  inline OdResult getSymbolName(OdChar *&pName, OdDbObjectId objId)
  {
    OD_TRY()
    OdDbSymbolTableRecordPtr pRec = objId.safeOpenObject(OdDb::kForRead);
	if (!pRec.isNull()) 
        OD_ERR_RESULT = pRec->getName(pName);
    OD_CATCH()
  }
  inline OdResult getSymbolName(const OdChar *&pName, OdDbObjectId objId)
  {
    OD_TRY()
    OdDbSymbolTableRecordPtr pRec = objId.safeOpenObject(OdDb::kForRead);
	if (!pRec.isNull()) 
        OD_ERR_RESULT = pRec->getName(pName);
    OD_CATCH()
  }

  #define DBSYMUTL_MAKE_GETSYMBOLID_FUNC(T_TABLE) \
  inline OdDbObjectId \
  get ## T_TABLE ## Id(const OdString& name, const OdDbDatabase *pDb) \
  { \
    OdDbSymbolTablePtr pTable = pDb->get ## T_TABLE ## TableId().safeOpenObject(); \
    ODA_ASSERT(!pTable->isOdDbObjectIdsInFlux()); \
    return pTable->getAt(name); \
  }
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(Viewport)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(Block)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(DimStyle)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(Layer)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(Linetype)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(RegApp)
  //DBSYMUTL_MAKE_GETSYMBOLID_FUNC(TextStyle)

  inline OdDbObjectId getTextStyleId(const OdString& name, const OdDbDatabase *pDb)
  {
    OdDbSymbolTablePtr pTable = pDb->getTextStyleTableId().safeOpenObject();
    ODA_ASSERT(!pTable->isOdDbObjectIdsInFlux());
    OdDbTextStyleTableRecordPtr pRec = pTable->getAt(name, OdDb::kForRead);

    if (pRec.get())
      if (!pRec->isShapeFile())
        return pRec->objectId();
    return OdDbObjectId::kNull;
  }

  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(UCS)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNC(View)
  #undef DBSYMUTL_MAKE_GETSYMBOLID_FUNC

  inline OdDbObjectId getPlotstyleId(const OdString& name, const OdDbDatabase *pDb)
  {
    OdDbDictionaryPtr pDic = pDb->getPlotStyleNameDictionaryId(false).openObject();
    if (!pDic.isNull())
    {
      ODA_ASSERT(!pDic->isOdDbObjectIdsInFlux());
      return pDic->getAt(name);
    }
    return OdDbObjectId::kNull;
  }

  inline OdDbObjectId getMLStyleId(const OdString& name, const OdDbDatabase *pDb)
  {
    OdDbDictionaryPtr pDic = pDb->getMLStyleDictionaryId(false).openObject();
    if (!pDic.isNull())
    {
      ODA_ASSERT(!pDic->isOdDbObjectIdsInFlux());
      return pDic->getAt(name);
    }
    return OdDbObjectId::kNull;
  }

  inline OdDbObjectId getTableStyleId(const OdString& name, const OdDbDatabase *pDb)
  {
    OdDbDictionaryPtr pDic = pDb->getTableStyleDictionaryId(false).openObject();
    if (!pDic.isNull())
    {
      ODA_ASSERT(!pDic->isOdDbObjectIdsInFlux());
      return pDic->getAt(name);
    }
    return OdDbObjectId::kNull;
  }

  inline OdDbObjectId getMLeaderStyleId(const OdString& name, const OdDbDatabase *pDb)
  {
    OdDbDictionaryPtr pDic = pDb->getMLeaderStyleDictionaryId(false).openObject();
    if (!pDic.isNull())
    {
      ODA_ASSERT(!pDic->isOdDbObjectIdsInFlux());
      return pDic->getAt(name);
    }
    return OdDbObjectId::kNull;
  }

  inline OdDbObjectId getVisualStyleId(const OdString& name, const OdDbDatabase *pDb)
  {
    OdDbDictionaryPtr pDic = pDb->getVisualStyleDictionaryId(false).openObject();
    if (!pDic.isNull())
    {
      ODA_ASSERT(!pDic->isOdDbObjectIdsInFlux());
      return pDic->getAt(name);
    }
    return OdDbObjectId::kNull;
  }

  #define DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(T_TABLE) \
  inline OdResult get ## T_TABLE ## Id( OdDbObjectId &objId, const OdChar * name, OdDbDatabase *pDb) \
  { \
    if (pDb == NULL) \
        return Oda::eNullObjectPointer; \
    OD_TRY() \
      objId = get ## T_TABLE ## Id(name, pDb); \
      return objId.isValid() ? Oda::eOk : Oda::eKeyNotFound;\
    OD_CATCH() \
  } 

  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Viewport)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Block)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(DimStyle)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Layer)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Linetype)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(RegApp)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(TextStyle)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(UCS)
  DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(View)
  #undef DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION

  #define DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(T_TABLE) \
  inline bool has ## T_TABLE( OdDbObjectId objId, OdDbDatabase *pDb) \
  { \
    if (pDb == NULL) \
        return false; \
    OdDbSymbolTablePtr pTable = pDb->get ## T_TABLE ## TableId().safeOpenObject(); \
    ODA_ASSERT(!pTable->isOdDbObjectIdsInFlux()); \
    return pTable->has(objId); \
  }
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Block)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(DimStyle)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Layer)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Linetype)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(RegApp)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(TextStyle)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(UCS)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(View)
  DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(Viewport)
  #undef DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION

  #define DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(T_TABLE) \
  inline bool has ## T_TABLE( const OdChar * name, OdDbDatabase *pDb) \
  { \
    if (pDb == NULL) \
        return false; \
    OdDbSymbolTablePtr pTable = pDb->get ## T_TABLE ## TableId().safeOpenObject(); \
    ODA_ASSERT(!pTable->isOdDbObjectIdsInFlux()); \
    return pTable->has(name); \
  } /*\
  inline bool has ## T_TABLE( const OdChar * name, OdDbDatabase *pDb) \
  { \
    return has ## T_TABLE (OdString(name) , pDb); \
  }*/
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Block)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(DimStyle)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Layer)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Linetype)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(RegApp)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(TextStyle)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(UCS)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(View)
  DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION(Viewport)
  #undef DBSYMUTL_MAKE_HASSYMBOLNAME_FUNCTION
  inline const OdString& linetypeByLayerName()
  { return  byLayerNameStr; }

  inline bool isLinetypeByLayerName(const OdString& name)
  { return !odStrICmp(name, linetypeByLayerName()); }

  inline const OdString& linetypeByBlockName()
  { return  byBlockNameStr; }

  inline bool isLinetypeByBlockName(const OdString& name)
  { return !odStrICmp(name, linetypeByBlockName()); }

  inline const OdString& linetypeContinuousName()
  { return  linetypeContinuousNameStr; }

  inline bool isLinetypeContinuousName(const OdString& name)
  { return !odStrICmp(name, linetypeContinuousName()); }

  inline const OdString& layerZeroName()
  { return  layerZeroNameStr; }

  inline bool isLayerZeroName(const OdString& name)
  { return !odStrICmp(name, layerZeroName()); }

  inline const OdString& layerDefpointsName()
  { return  layerDefpointsNameStr; }

  inline bool isLayerDefpointsName(const OdString& name)
  { return !odStrICmp(name, layerDefpointsName()); }

  inline const OdString& textStyleStandardName()
  { return standardStr; }

  //inline const OdString regAppAcadName()
  //{ return regAppAcadNameStr; }

	inline bool isRegAppAcadName(const OdString& name)
	{ return !odStrICmp(name, regAppAcadName); }

  inline const OdString& MLineStyleStandardName()
  { return standardStr; }

  inline bool isMLineStandardName(const OdString& name)
  { return !odStrICmp(name, MLineStyleStandardName()); }

  inline const OdString& dimStyleStandardName(OdDb::MeasurementValue measurement)
  { return measurement == OdDb::kEnglish ? standardStr : metricDimStandardStr; }

  inline const OdString& viewportActiveName()
  { return viewportActiveNameStr; }

  inline bool isViewportActiveName(const OdString& name)
  { return !odStrICmp(name, viewportActiveName()); }

  inline bool isTextStyleStandardName(const OdString& name)
  { return !odStrICmp(name, textStyleStandardName()); }

  TOOLKIT_EXPORT const OdDbObjectId& textStyleStandardId(OdDbDatabase* pDb);
	TOOLKIT_EXPORT const OdDbObjectId& dimStyleStandardId(OdDbDatabase* pDb);
  TOOLKIT_EXPORT const OdDbObjectId  MLineStyleStandardId(OdDbDatabase* pDb);

  inline const OdString& blockModelSpaceName(OdDb::DwgVersion version = OdDb::kDHL_CURRENT)
  { return version <= OdDb::vAC12 ? modelSpaceStr_R12 : modelSpaceStr; }

  inline bool isBlockModelSpaceName(const OdString& pN, OdDb::DwgVersion version = OdDb::kDHL_CURRENT)
  { return odStrICmp(pN, blockModelSpaceName(version)) == 0; }

  inline const OdString& blockPaperSpaceName(OdDb::DwgVersion version = OdDb::kDHL_CURRENT)
  { return version <= OdDb::vAC12 ? paperSpaceStr_R12 : paperSpaceStr; }

  inline bool isBlockPaperSpaceName(const OdString& pN, OdDb::DwgVersion version = OdDb::kDHL_CURRENT)
  { return odStrICmp(pN, blockPaperSpaceName(version)) == 0; }

  inline const OdString& plotStyleNormalName()
  { return plotStyleNormalNameStr;}

  inline const OdString& TableStyleStandardName()
  { return standardStr; }

  inline bool isTableStandardName(const OdString& name)
  { return !odStrICmp(name, TableStyleStandardName()); }

  inline const OdString& MLeaderStyleStandardName()
  { return standardStr; }

  inline bool isMLeaderStandardName(const OdString& name)
  { return !odStrICmp(name, MLeaderStyleStandardName()); }
inline const OdString& DetailViewStyleStandardName(OdDbDatabase* pDb)
  {
    ODA_ASSERT_ONCE(pDb);
    return (pDb && pDb->getMEASUREMENT() == OdDb::kMetric) ? standardMetricDictStr : standardImperialDictStr;
  }

  inline bool isDetailViewStyleStandardName(OdDbDatabase* pDb, const OdString& name)
  { 
    return !odStrICmp(name, DetailViewStyleStandardName(pDb)); 
  }

  inline const OdString& SectionViewStyleStandardName(OdDbDatabase* pDb)
  {
    return DetailViewStyleStandardName(pDb);
  }

  inline bool isSectionViewStyleStandardName(OdDbDatabase* pDb, const OdString& name)
  { 
    return !odStrICmp(name, SectionViewStyleStandardName(pDb)); 
  }
  class Services
  {
  public:
    enum { kCurrentVersion = ODDBSYMUTIL_SERVICES_CURRENT_VERSION };
    virtual int version() const;
    virtual bool isBlockLayoutName        (const OdChar * name) const;
    virtual bool isBlockModelSpaceName    (const OdChar * name) const;
    virtual bool isBlockPaperSpaceName    (const OdChar * name) const;
    virtual bool isLayerDefpointsName     (const OdChar * name) const;
    virtual bool isLayerZeroName          (const OdChar * name) const;
    virtual bool isLinetypeByBlockName    (const OdChar * name) const;
    virtual bool isLinetypeByLayerName    (const OdChar * name) const;
    virtual bool isLinetypeContinuousName (const OdChar * name) const;
    virtual bool isRegAppAcadName         (const OdChar * name) const;
    virtual bool isTextStyleStandardName  (const OdChar * name) const;
    virtual bool isViewportActiveName     (const OdChar * name) const;

    virtual OdDbObjectId blockModelSpaceId    (OdDbDatabase * pDb) const;
    virtual OdDbObjectId blockPaperSpaceId    (OdDbDatabase * pDb) const;
    virtual OdDbObjectId layerDefpointsId     (OdDbDatabase * pDb) const;
    virtual OdDbObjectId layerZeroId          (OdDbDatabase * pDb) const;
    virtual OdDbObjectId linetypeByBlockId    (OdDbDatabase * pDb) const;
    virtual OdDbObjectId linetypeByLayerId    (OdDbDatabase * pDb) const;
    virtual OdDbObjectId linetypeContinuousId (OdDbDatabase * pDb) const;
    virtual OdDbObjectId regAppAcadId         (OdDbDatabase * pDb) const;
    virtual OdDbObjectId textStyleStandardId  (OdDbDatabase * pDb) const;

    virtual const OdChar * blockModelSpaceName    () const;
    virtual const OdChar * blockPaperSpaceName    () const;
    virtual const OdChar * layerDefpointsName     () const;
    virtual const OdChar * layerZeroName          () const;
    virtual const OdChar * linetypeByBlockName    () const;
    virtual const OdChar * linetypeByLayerName    () const;
    virtual const OdChar * linetypeContinuousName () const;
    virtual const OdChar * regAppAcadName         () const;
    virtual const OdChar * textStyleStandardName  () const;
    virtual const OdChar * viewportActiveName     () const;

    virtual int compareSymbolName(const OdChar * thisName, const OdChar * otherName) const;
    virtual bool hasVerticalBar(const OdChar * name) const;
    virtual OdResult makeDependentName(OdChar *& pNewName, const OdChar * dwgName, const OdChar * symbolName) const; 
    virtual OdResult repairPreExtendedSymbolName(OdChar *& pNewName, const OdChar * oldName, bool allowVerticalBar) const;
    virtual OdResult repairSymbolName(OdChar *& pNewName, const OdChar * oldName, bool allowVerticalBar) const;
    virtual bool splitDependentName(size_t & numLeftBytes, const OdChar *& pRight, const OdChar *  symbolName) const;
    virtual OdResult validatePreExtendedSymbolName(const OdChar * name, bool allowVerticalBar) const;
    virtual OdResult validateSymbolName(const OdChar * name,bool allowVerticalBar) const;

    virtual bool compatibilityMode(OdDbDatabase * pDb) const;
    virtual OdResult getBlockNameFromInsertPathName(OdChar *& pBlockName, const OdChar * pathName) const;
    virtual OdResult getInsertPathNameFromBlockName(OdChar *& pPathName, const OdChar * blockName) const;
    virtual bool getMaxSymbolNameLength(size_t & maxLength, size_t & maxSize, bool isNewName, bool compatibilityMode) const;
    virtual OdResult getPathNameFromSymbolName(OdChar *& pPathName, const OdChar * symbolName, const OdChar * extensions) const;
    virtual OdResult getSymbolNameFromPathName(OdChar *& pSymbolName, const OdChar * pathName, const OdChar * extensions) const;
    virtual OdResult preValidateSymbolName(OdChar *& pSymbolName, bool preserveCase) const;
    virtual OdResult validateCompatibleSymbolName(const OdChar * name, bool isNewName, bool allowVerticalBar, bool compatibilityMode) const;
  };

#define ODDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v) n ## v
#define ODDBSYMUTIL_SERVICESNAME_WITH_VERSION(n,v)	ODDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v)
#define ODDBSYMUTIL_SERVICES_NAME ODDBSYMUTIL_SERVICESNAME_WITH_VERSION(servicesPtr,ODDBSYMUTIL_SERVICES_CURRENT_VERSION)

  TOOLKIT_EXPORT const Services * ODDBSYMUTIL_SERVICES_NAME();

  inline const Services * servicesPtr()
  {
    return ODDBSYMUTIL_SERVICES_NAME();
  }
}
// namespace OdDbSymUtil

TOOLKIT_EXPORT OdResult getTableStyleNameFromDbById(const OdDbObjectId& objId, OdChar*& pName);

typedef OdDbSymUtil::Services OdDbSymUtilServices;

inline const OdDbSymUtilServices *
gcdbSymUtil()
{
    return OdDbSymUtil::servicesPtr();
}
#include "TD_PackPop.h"

#endif // DBSYMUTL_DEFINED

