/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBSYMUTL_H
#define GD_DBSYMUTL_H 1

#include "dbsymtb.h"

#pragma pack (push, 8)

#define GCDBSYMUTIL_SERVICES_CURRENT_VERSION 106

namespace GcDbSymbolUtilities
{

  enum CompatibilityMode {
    kExtendedNames = true,
    kPreExtendedNames = false
  };

  enum NameCaseMode {
    kPreserveCase = true,
    kForceToUpper = false
  };

  enum NewNameMode {
    kAsNewName = true,
    kAsExistingName = false
  };

  enum VerticalBarMode {
    kAllowVerticalBar = true,
    kNoVerticalBar = false
  };

  class GCDB_PORT Services
  {
  public:
    enum { kCurrentVersion = GCDBSYMUTIL_SERVICES_CURRENT_VERSION };
    virtual int version() const = 0;

    virtual bool isBlockLayoutName(const GCHAR * name) const = 0;
    virtual bool isBlockModelSpaceName(const GCHAR * name) const = 0;
    virtual bool isBlockPaperSpaceName(const GCHAR * name) const = 0;
    virtual bool isLayerDefpointsName(const GCHAR * name) const = 0;
    virtual bool isLayerZeroName(const GCHAR * name) const = 0;
    virtual bool isLinetypeByBlockName(const GCHAR * name) const = 0;
    virtual bool isLinetypeByLayerName(const GCHAR * name) const = 0;
    virtual bool isLinetypeContinuousName(const GCHAR * name) const = 0;
    virtual bool isRegAppAcadName(const GCHAR * name) const = 0;
    virtual bool isTextStyleStandardName(const GCHAR * name) const = 0;
    virtual bool isViewportActiveName(const GCHAR * name) const = 0;

    virtual GcDbObjectId blockModelSpaceId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId blockPaperSpaceId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId layerDefpointsId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId layerZeroId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId linetypeByBlockId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId linetypeByLayerId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId linetypeContinuousId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId regAppAcadId(GcDbDatabase * pDb) const = 0;
    virtual GcDbObjectId textStyleStandardId(GcDbDatabase * pDb) const = 0;

    virtual const GCHAR * blockModelSpaceName() const = 0;
    virtual const GCHAR * blockPaperSpaceName() const = 0;
    virtual const GCHAR * layerDefpointsName() const = 0;
    virtual const GCHAR * layerZeroName() const = 0;
    virtual const GCHAR * linetypeByBlockName() const = 0;
    virtual const GCHAR * linetypeByLayerName() const = 0;
    virtual const GCHAR * linetypeContinuousName() const = 0;
    virtual const GCHAR * regAppAcadName() const = 0;
    virtual const GCHAR * textStyleStandardName() const = 0;
    virtual const GCHAR * viewportActiveName() const = 0;

    virtual int               compareSymbolName(const GCHAR * thisName, const GCHAR * otherName) const = 0;
    virtual bool              hasVerticalBar(const GCHAR * name) const = 0;
    virtual Gcad::ErrorStatus makeDependentName(
      GCHAR *&      pNewName,
      const GCHAR * dwgName,
      const GCHAR * symbolName) const = 0;
    virtual Gcad::ErrorStatus repairPreExtendedSymbolName(
      GCHAR *&      pNewName,
      const GCHAR * oldName,
      bool         allowVerticalBar) const = 0;
    virtual Gcad::ErrorStatus repairSymbolName(
      GCHAR *&      pNewName,
      const GCHAR * oldName,
      bool         allowVerticalBar) const = 0;
    virtual bool              splitDependentName(
      size_t &      numLeftBytes,
      const GCHAR *& pRight,
      const GCHAR *  symbolName) const = 0;
    virtual Gcad::ErrorStatus validatePreExtendedSymbolName(
      const GCHAR * name,
      bool         allowVerticalBar) const = 0;
    virtual Gcad::ErrorStatus validateSymbolName(
      const GCHAR * name,
      bool         allowVerticalBar) const = 0;
    virtual bool              compatibilityMode(GcDbDatabase * pDb) const = 0;
    virtual Gcad::ErrorStatus getBlockNameFromInsertPathName(
      GCHAR *&      pBlockName,
      const GCHAR * pathName) const = 0;
    virtual Gcad::ErrorStatus getInsertPathNameFromBlockName(
      GCHAR *&      pPathName,
      const GCHAR * blockName) const = 0;
    virtual bool              getMaxSymbolNameLength(
      size_t &     maxLength,
      size_t &     maxSize,
      bool         isNewName,
      bool         compatibilityMode) const = 0;
    virtual Gcad::ErrorStatus getPathNameFromSymbolName(
      GCHAR *&      pPathName,
      const GCHAR * symbolName,
      const GCHAR * extensions) const = 0;
    virtual Gcad::ErrorStatus getSymbolNameFromPathName(
      GCHAR *&      pSymbolName,
      const GCHAR * pathName,
      const GCHAR * extensions) const = 0;
    virtual Gcad::ErrorStatus preValidateSymbolName(
      GCHAR *&      pSymbolName,
      bool         preserveCase) const = 0;
    virtual Gcad::ErrorStatus validateCompatibleSymbolName(
      const GCHAR * name,
      bool         isNewName,
      bool         allowVerticalBar,
      bool         compatibilityMode) const = 0;
  };

  inline Gcad::ErrorStatus getSymbolName(GcString & sName, GcDbObjectId objId)
  {
    sName.setEmpty();
    GcDbSymbolTableRecord *pRec = NULL;
    Gcad::ErrorStatus es = ::gcdbOpenObject(pRec, objId, GcDb::kForRead);
    if (es == Gcad::eOk) {
      es = pRec->getName(sName);
      pRec->close();
    }
    return es;
  }

  inline Gcad::ErrorStatus getSymbolName(GCHAR *&pName, GcDbObjectId objId)
  {
    GcString sName;
    return ::gcutGcStringToGChar(sName, pName, GcDbSymbolUtilities::getSymbolName(sName, objId));
  }

#define GCDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v) n ## v
#define GCDBSYMUTIL_SERVICESNAME_WITH_VERSION(n,v) \
        GCDBSYMUTIL_SERVICESNAME_WITH_VERSION_1(n,v)
#define GCDBSYMUTIL_SERVICES_NAME \
        GCDBSYMUTIL_SERVICESNAME_WITH_VERSION( \
            servicesPtr, \
            GCDBSYMUTIL_SERVICES_CURRENT_VERSION)

  GCDB_PORT const Services * GCDBSYMUTIL_SERVICES_NAME();

  inline const Services* servicesPtr()
  {
    const Services * pSymUtil = GCDBSYMUTIL_SERVICES_NAME();
    return pSymUtil;
  }

#define DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(T_TABLE) \
inline Gcad::ErrorStatus \
get ## T_TABLE ## Id( \
    GcDbObjectId &objId, \
    const GCHAR  *name, \
    GcDbDatabase *pDb) \
{ \
    if (pDb == NULL) \
        return Gcad::eNullObjectPointer; \
    GcDb ## T_TABLE ## Table *pTable = NULL; \
    Gcad::ErrorStatus es = pDb->getSymbolTable(pTable, GcDb::kForRead); \
    if (es == Gcad::eOk) { \
        es = pTable->getAt(name, objId); \
        pTable->close(); \
    } \
    return es; \
}
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Block)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(DimStyle)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Layer)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(Linetype)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(RegApp)

inline Gcad::ErrorStatus getTextStyleId(GcDbObjectId &objId, const GCHAR  *name, GcDbDatabase *pDb)
{
  if (pDb == NULL)
    return Gcad::eNullObjectPointer;
  GcDbTextStyleTable *pTable = NULL;
  Gcad::ErrorStatus es = pDb->getSymbolTable(pTable, GcDb::kForRead);
  if (es == Gcad::eOk) {
    GcDbTextStyleTableRecord *pRec = NULL;
    es = pTable->getAt(name, pRec, GcDb::kForRead);
    if (es == Gcad::eOk) {
      if (pRec->isShapeFile())
        es = Gcad::eKeyNotFound;
      else
        objId = pRec->objectId();
      pRec->close();
    }
    pTable->close();
  }
  return es;
}

DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(UCS)
DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION(View)
#undef DBSYMUTL_MAKE_GETSYMBOLID_FUNCTION


#define DBSYMUTL_MAKE_HASSYMBOLID_FUNCTION(T_TABLE) \
inline bool \
has ## T_TABLE( \
    GcDbObjectId  objId, \
    GcDbDatabase *pDb) \
{ \
    if (pDb == NULL) \
        return false; \
    bool hasSymbol = false; \
    GcDb ## T_TABLE ## Table *pTable = NULL; \
    Gcad::ErrorStatus es = pDb->getSymbolTable(pTable, GcDb::kForRead); \
    if (es == Gcad::eOk) { \
        hasSymbol = !!pTable->has(objId); \
        pTable->close(); \
    } \
    return hasSymbol; \
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
inline bool \
has ## T_TABLE( \
    const GCHAR  *name, \
    GcDbDatabase *pDb) \
{ \
    if (pDb == NULL) \
        return false; \
    bool hasSymbol = false; \
    GcDb ## T_TABLE ## Table *pTable = NULL; \
    Gcad::ErrorStatus es = pDb->getSymbolTable(pTable, GcDb::kForRead); \
    if (es == Gcad::eOk) { \
        hasSymbol = !!pTable->has(name); \
        pTable->close(); \
    } \
    return hasSymbol; \
}
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

}

namespace GcDbSymUtil = GcDbSymbolUtilities;

GCDB_PORT Gcad::ErrorStatus  getTableStyleNameFromDbById(const GcDbObjectId& objId, GcString & sName);

inline Gcad::ErrorStatus  getTableStyleNameFromDbById(const GcDbObjectId& objId, GCHAR*& pName)
{
  GcString sName;
  return ::gcutGcStringToGChar(sName, pName, ::getTableStyleNameFromDbById(objId, sName));
}

typedef GcDbSymbolUtilities::Services GcDbSymUtilServices;

inline const GcDbSymUtilServices *
gcdbSymUtil()
{
  return GcDbSymbolUtilities::servicesPtr();
}

#pragma pack (pop)
#endif 