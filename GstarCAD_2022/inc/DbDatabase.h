/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////




#ifndef _ODDBDATABASE_INCLUDED_
#define _ODDBDATABASE_INCLUDED_

#include "TD_PackPush.h"

#include "RxObject.h"
#include "DbObjectId.h"
#include "RxObjectImpl.h"
#include "OdString.h"
#include "DbDate.h"
#include "OdCodePage.h"
#include "OdToolKit.h"
#include "DbObject.h"
#include "CmColor.h"
#include "DbSecurity.h"
#include "DbSystemServices.h"
#include "ViewportDefs.h"
#include "DbAnnotationScale.h"
#include "DbDatabaseReactor.h"
#include "DbSubentId.h"
#include "DbEntity.h"
#include "DbPtrArray.h"

#include "OdDb.h"
#include "DbHandle.h"
#include "DbFiler.h"
#include "Ge/GePoint3dArray.h"
#include "IntArray.h"
#include "DbAudit.h"
#include "TdxDefs.h"

class OdDbObject;

class OdDbSymbolTable;
class OdDbBlockTable;
class OdDbTextStyleTable;
class OdDbLinetypeTable;
class OdDbLayerTable;
class OdDbViewTable;
class OdDbUCSTable;
class OdDbUCSTable;
class OdDbViewportTable;
class OdDbRegAppTable;
class OdDbDimStyleTable;
class OdDbDimStyleTableRecord;
class OdDbBlockTableRecord;
class OdDbTextStyleTableRecord;
class OdDbRegAppTableRecord;
class OdDbLinetypeTableRecord;
class OdDbHostAppServices;
class OdDbLayout;
class OdDbLayoutManagerReactor;
class OdGsView;
class OdGsDevice;
class OdGsDCRect;

class OdDbDictionary;
class OdDbDictionaryWithDefault;
class OdDbFiler;
class OdDbIdMapping;
class OdDbDatabaseReactor;
class OdDbSpatialFilter;
class OdDbLayerFilter;
class OdDbAuditInfo;
class OdDbUndoController;
class OdDbTransactionReactor;
class OdDbTransactionManager;
class OdDbEntity;

class OdGePoint2d;
class OdGePoint3d;
class OdGeMatrix3d;
class OdGeVector3d;
class OdDbDwgFiler;

class OdGsModel;

class OdStreamBuf;
class OdThumbnailImage;

class OdDbDatabaseImpl;
class OdResBuf;
class OdDbUnitsFormatter;
//Gcad(Add)
class OdDbSectionManager;

class OdDbLayerStateManager;

class OdDbDataLinkManager;
class OdDwgFileHandle;
class IGcReadStream;
class OdDbObjectIdGraph;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdResBuf object pointers.
*/
typedef OdSmartPtr<OdResBuf> OdResBufPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDictionary object pointers.
*/
typedef OdSmartPtr<OdDbDictionary> OdDbDictionaryPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDictionaryWithDefault object pointers.
*/
typedef OdSmartPtr<OdDbDictionaryWithDefault> OdDbDictionaryWithDefaultPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbSymbolTable object pointers.
*/
typedef OdSmartPtr<OdDbSymbolTable> OdDbSymbolTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbBlockTable object pointers.
*/
typedef OdSmartPtr<OdDbBlockTable> OdDbBlockTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLayerTable object pointers.
*/
typedef OdSmartPtr<OdDbLayerTable> OdDbLayerTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbTextStyleTable object pointers.
*/
typedef OdSmartPtr<OdDbTextStyleTable> OdDbTextStyleTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbViewTable object pointers.
*/
typedef OdSmartPtr<OdDbViewTable> OdDbViewTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbUCSTable object pointers.
*/
typedef OdSmartPtr<OdDbUCSTable> OdDbUCSTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbViewportTable object pointers.
*/
typedef OdSmartPtr<OdDbViewportTable> OdDbViewportTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbRegAppTable object pointers.
*/
typedef OdSmartPtr<OdDbRegAppTable> OdDbRegAppTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDimStyleTable object pointers.
*/
typedef OdSmartPtr<OdDbDimStyleTable> OdDbDimStyleTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLinetypeTable object pointers.
*/
typedef OdSmartPtr<OdDbLinetypeTable> OdDbLinetypeTablePtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbBlockTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbBlockTableRecord> OdDbBlockTableRecordPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDimStyleTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbDimStyleTableRecord> OdDbDimStyleTableRecordPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbTextStyleTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbTextStyleTableRecord> OdDbTextStyleTableRecordPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbRegAppTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbRegAppTableRecord> OdDbRegAppTableRecordPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDimStyleTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbDimStyleTableRecord> OdDbDimStyleTableRecordPtr;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbLinetypeTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbLinetypeTableRecord> OdDbLinetypeTableRecordPtr;

class OdSecurityParams;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdSecurityParams object pointers.
*/
typedef OdSmartPtr<OdSecurityParams> OdSecurityParamsPtr;

class OdFileDependencyManager;
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdFileDependencyManager object pointers.
*/
typedef OdSmartPtr<OdFileDependencyManager> OdFileDependencyManagerPtr;

class OdDbObjectContextManager;
/** Description:
This template class is a specialization of the OdSmartPtr class for OdDbObjectContextManager object pointers.
*/
typedef OdSmartPtr<OdDbObjectContextManager> OdDbObjectContextManagerPtr;

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDatabase object pointers.
*/
typedef OdSmartPtr<OdDbDatabase> OdDbDatabasePtr;

class OdDbUndoController;
typedef OdSmartPtr<OdDbUndoController> OdDbUndoControllerPtr;

/** Description:

    {group:TD_Namespaces}
*/

namespace OdDb
{
  enum DuplicateLinetypeLoading
  {
    kDltNotApplicable = 0, // Not Applicable.
    kDltIgnore        = 1, // Ignore duplicate LineTypes.
    kDltReplace       = 2  // Replace duplicate LineTypes.
  };

  enum ProxyImage
  {
    kProxyNotShow	    = 0,
    kProxyShow	      = 1,
    kProxyBoundingBox	= 2
  };

  
  enum FilletTrimMode   
  { 
    kTrimNone      = 0, //!< No fillet is trimmed.
    kTrimFirst     = 1, //!< The first fillet is trimmed.
    kTrimSecond    = 2, //!< The second fillet is trimmed.
    kTrimBoth      = 3  //!< Both fillets are trimmed.
  };
  
  /** Description:
    Used in text file writing functions to force text file encoding.
  */
  enum TextFileEncoding
  {
    kTextFileEncodingDefault = 0, // Chooses current system encoding automaticly
    kTextFileEncodingANSI = 1, // Force ANSI character set encoding text writing
    kTextFileEncodingUTF8 = 11, // Use UTF8 encoding for write file
    kTextFileEncodingUTF16 = 21, // Chooses UTF16 endian automaticly
    kTextFileEncodingUTF16LE = 22, // UTF16 LittleEndian
    kTextFileEncodingUTF16BE = 23, // UTF16 BigEndian
    kTextFileEncodingUTF32 = 31, // Chooses UTF32 endian automaticly
    kTextFileEncodingUTF32LE = 32, // UTF32 LittleEndian
    kTextFileEncodingUTF32BE = 33 // UTF32 BigEndian
  };

  enum LayerAdskType
  {
    kLayerSystemLights = 0,
    kLayerConstraints  = 1
  };
}

/** Description:
    This class represents a complete drawing file.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDatabase : public OdDbObject
{
public:
  OdDbDatabase(bool buildDefaultDrawing = true, bool noDocument = false);

public:

  OdResult subGetClassID(
    CLSID* pClsid) const;

  ODRX_DECLARE_MEMBERS(OdDbDatabase);

  void addRef();

  void release();

  /** Description:
    Returns the OdDbHostAppServices object associated with this *database* object.
  */
  OdDbHostAppServices* appServices() const;

  /** Description:
    Adds the default set of objects and settings to this *database* object.

    Remarks:
    This includes the ModelSpace and PaperSpace blocks, default table entries, system variable settings, etc.

    Remarks:
    measurement must be one the following:

    @table
    Name              Value
    OdDb::kEnglish    0
    OdDb::kMetric     1

    Arguments:
    measurement (I) Units of *measurement*.
  */
  void initialize(
    OdDb::MeasurementValue measurement = OdDb::kEnglish);

  virtual ~OdDbDatabase();

  /** Description:
    Adds an object to this *database* object, and returns its Object ID.

    Arguments:
    pObject (I) Pointer to the object.
    ownerId (I) Object ID of the owner of pObject.
    handle (I) Handle for pObject

    Remarks:
    A unique *handle* will be generated if *handle* is not supplied or is 0.
	Gcad(Modify):冲突,去掉第2个参数的默认值= OdDbObjectId::kNull
  */
  OdDbObjectId addOdDbObject(
    OdDbObject* pObject,
    OdDbObjectId ownerId,
    OdDbHandle handle = 0);

  /*/Gcad(Add)
  /*/
  OdResult addOdDbObject(OdDbObject*    pObj);
  OdResult addOdDbObject(OdDbObjectId&  objId,OdDbObject*    pObj);
  //*/

  OdResult delOdDbObject(OdDbHandle &h);

  static OdResult markObjectNonPersistent(OdDbObjectId id, bool value);
  static bool isObjectNonPersistent(OdDbObjectId id);

  OdDbObjectId dataLinkDictionaryId(void) const;
  OdResult getDataLinkDictionary(OdDbDictionary*& pDict, OdDb::OpenMode mode);

  OdDbDataLinkManager* getDataLinkManager(void) const;
  OdResult updateDataLink(OdDb::UpdateDirection nDir, OdDb::UpdateOption nOption);

  OdResult reclaimMemoryFromErasedObjects(const OdDbObjectIdArray& erasedObjects);

  OdResult purge(OdDbObjectIdGraph& idGraph);

  bool hasClass(const OdRxClass* pClass) const;

  /** Description:
    Adds the specified *name* to the APPID table of this *database* object.

    Arguments:
    regAppName (I) Application *name*.

    Remarks:
    True if and only if the specified *name* had not been, and is now, in the APPID table.
  */
  bool newRegApp(
    const OdString& regAppName);

  /*/Gcad(Add)
  /*/
  OdResult getBlockTable     (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getLayerTable     (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getTextStyleTable (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getLinetypeTable  (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getViewTable      (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getUCSTable       (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getViewportTable  (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getRegAppTable    (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);
  OdResult getDimStyleTable  (OdDbSymbolTable*&    pTable, OdDb::OpenMode mode);

  OdResult getSymbolTable    (OdDbBlockTable*&     pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbLayerTable*&     pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbTextStyleTable*& pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbLinetypeTable*&  pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbViewTable*&      pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbUCSTable*&       pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbViewportTable*&  pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbRegAppTable*&    pTable, OdDb::OpenMode mode);
  OdResult getSymbolTable    (OdDbDimStyleTable*&  pTable, OdDb::OpenMode mode);

  OdResult getGroupDictionary        (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getMLStyleDictionary      (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getLayoutDictionary       (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getPlotStyleNameDictionary(OdDbDictionaryWithDefault*& pDict, OdDb::OpenMode mode);
  OdResult getMaterialDictionary     (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getVisualStyleDictionary  (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getColorDictionary        (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getScaleListDictionary    (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getNamedObjectsDictionary (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getPlotSettingsDictionary (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getTableStyleDictionary   (OdDbDictionary*& pDict, OdDb::OpenMode mode);
  OdResult getMLeaderStyleDictionary (OdDbDictionary*& pDict, OdDb::OpenMode mode);

  // The following getXXXTable(OdDbXXXTable*& ...) functions exist
  // for backwards compatibility and may be removed in future releases.
  OdResult getBlockTable     (OdDbBlockTable*&     pTable, OdDb::OpenMode mode);
  OdResult getLayerTable     (OdDbLayerTable*&     pTable, OdDb::OpenMode mode);
  OdResult getTextStyleTable (OdDbTextStyleTable*& pTable, OdDb::OpenMode mode);
  OdResult getLinetypeTable  (OdDbLinetypeTable*&  pTable, OdDb::OpenMode mode);
  OdResult getViewTable      (OdDbViewTable*&      pTable, OdDb::OpenMode mode);
  OdResult getUCSTable       (OdDbUCSTable*&       pTable, OdDb::OpenMode mode);
  OdResult getViewportTable  (OdDbViewportTable*&  pTable, OdDb::OpenMode mode);
  OdResult getRegAppTable    (OdDbRegAppTable*&    pTable, OdDb::OpenMode mode);
  OdResult getDimStyleTable  (OdDbDimStyleTable*&  pTable, OdDb::OpenMode mode);
  //*/

  /** Description:
    Returns the Object ID of the BlockTable of this *database* object.
  */
  OdDbObjectId getBlockTableId() const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId blockTableId() const { return getBlockTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the LayerTable of this *database* object.
  */
  OdDbObjectId getLayerTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId layerTableId() const { return getLayerTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the TextStyleTable of this *database* object.
  */
  OdDbObjectId getTextStyleTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId textStyleTableId() const { return getTextStyleTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the LinetypeTable of this *database* object.
  */
  OdDbObjectId getLinetypeTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId linetypeTableId() const { return getLinetypeTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the ViewTable of this *database* object.
  */
  OdDbObjectId getViewTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId viewTableId() const { return getViewTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the UCSTable of this *database* object.
  */
  OdDbObjectId getUCSTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId UCSTableId() const { return getUCSTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the ViewportTable of this *database* object.
  */
  OdDbObjectId getViewportTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId viewportTableId() const { return getViewportTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the RegAppTable of this *database* object.
  */
  OdDbObjectId getRegAppTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId regAppTableId() const { return getRegAppTableId(); }
  //*/
  /** Description:
    Returns the Object ID of the DimStyleTable of this *database* object.
  */
  OdDbObjectId getDimStyleTableId() const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId dimStyleTableId() const { return getDimStyleTableId(); }
  //*/

  /** Description:
    Returns the Object ID of the MLineStyle dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getMLStyleDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/ 
  inline OdDbObjectId mLStyleDictionaryId() const { return getMLStyleDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the Group dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getGroupDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId groupDictionaryId() const { return getGroupDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the Layout dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getLayoutDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId layoutDictionaryId() const { return getLayoutDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the PlotStyleName dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getPlotStyleNameDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId plotStyleNameDictionaryId() const { return getPlotStyleNameDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the NamedObjects dictionary of this *database* object.
  */
  OdDbObjectId getNamedObjectsDictionaryId() const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId namedObjectsDictionaryId() const { return getNamedObjectsDictionaryId(); }
  //*/
  /** Description:
    Returns the Object ID of the PlotSettings dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getPlotSettingsDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId plotSettingsDictionaryId() const { return getPlotSettingsDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the Color dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getColorDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId colorDictionaryId() const { return getColorDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the Material dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getMaterialDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId materialDictionaryId() const { return getMaterialDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the VisualStyle dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getVisualStyleDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId visualStyleDictionaryId() const { return getVisualStyleDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the TableStyle dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getTableStyleDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId tableStyleDictionaryId() const { return getTableStyleDictionaryId(false); }
  //*/
  /** Description:
  Returns the Object ID of the ScaleList dictionary of this *database* object.
  Arguments:
  createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getScaleListDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcad(Add)
  /*/
  inline OdDbObjectId scaleListDictionaryId() const { return getScaleListDictionaryId(false); }
  //*/
  /** Description:
    Returns the Object ID of the MLeaderStyle dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
  */
  OdDbObjectId getMLeaderStyleDictionaryId(
    bool createIfNotFound = true) const;
  /*/Gcadt(Add)
  /*/
  inline OdDbObjectId mleaderStyleDictionaryId() const { return getMLeaderStyleDictionaryId(false); }
  //*/

/** Description:
    Returns the Object ID of the DetailViewStyle dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Determines whether to create a DetailViewStyle dictionary if it does not exist.
  */
  OdDbObjectId getDetailViewStyleDictionaryId(
    bool createIfNotFound = true) const;
	
  /** Description:
    Returns the Object ID of the current DetailViewStyle of this *database* object.
  */
  OdDbObjectId detailViewStyle() const;

  /** Description:
    Sets the Object ID of the current DetailViewStyle of this *database* object.
    Arguments:
    objectId (I) Object ID.
  */
  void setDetailViewStyle(
    OdDbObjectId objectId);
	
	/** Description:
    Returns the Object ID of the SectionViewStyle dictionary of this *database* object.
    Arguments:
    createIfNotFound (I) Determines whether to create a SectionViewStyle dictionary if it does not exist.
  */
  OdDbObjectId getSectionViewStyleDictionaryId(
    bool createIfNotFound = true) const;

  /** Description:
    Returns the Object ID of the current SectionViewStyle of this *database* object.
  */
  OdDbObjectId sectionViewStyle() const;

  /** Description:
    Sets the Object ID of the current SectionViewStyle of this *database* object.
    Arguments:
    objectId (I) Object ID.
  */
  void setSectionViewStyle(
    OdDbObjectId objectId);
  /** Description:
    Returns the Object ID of the current TableStyle of this *database* object.
  */
  OdDbObjectId tablestyle() const;

  /** Description:
    Sets the Object ID of the current TableStyle of this *database* object.
    Arguments:
    objectId (I) Object ID.

	Gcad(modify)
  */
  OdResult setTablestyle(
    OdDbObjectId objectId);

  /** Description:
    Returns the Object ID of the current MLeaderStyle of this *database* object.
  */
  OdDbObjectId mleaderstyle() const;

  /** Description:
    Sets the Object ID of the current MLeaderStyle of this *database* object.
    Arguments:
    objectId (I) Object ID.

	Gcad(Modify)
  */
  OdResult setMLeaderstyle(
    OdDbObjectId objectId);

  /** Description:
    Returns the Object ID of the "ACAD" RegApp object of this *database* object.
  */
  OdDbObjectId getRegAppAcadId() const;

  /** Description:
    Returns the Object ID of the "Continuous" Linetype object of this *database* object.
  */
  OdDbObjectId getLinetypeContinuousId() const;
  inline OdDbObjectId continuousLinetype() const { return getLinetypeContinuousId(); }

  /** Description:
    Returns the Object ID of the "ByLayer" Linetype object of this *database* object.
  */
  OdDbObjectId getLinetypeByLayerId() const;
  inline OdDbObjectId byLayerLinetype() const { return getLinetypeByLayerId(); }

  /** Description:
    Returns the Object ID of the "ByBlock" Linetype object of this *database* object.
  */
  OdDbObjectId getLinetypeByBlockId() const;
  inline OdDbObjectId byBlockLinetype() const { return getLinetypeByBlockId(); }

  /** Description:
    Returns the Object ID of the ModelSpace Block object of this *database* object.
  */
  OdDbObjectId getModelSpaceId() const;

  /** Description:
    Returns the Object ID of the PaperSpace Block object of this *database* object.
  */
  OdDbObjectId getPaperSpaceId() const;

  OdDbObjectId currentSpaceId() const;

  /** Description:
    Returns the Object ID of the "Standard" text style object of this *database* object.
  */
  OdDbObjectId getTextStyleStandardId() const;

  /** Description:
    Returns the Object ID of the "Standard" dimension style object of this *database* object.
  */
  OdDbObjectId getDimStyleStandardId() const;

  /** Description:
    Returns the Object ID of the "0" layer object of this *database* object.
  */
  OdDbObjectId getLayerZeroId() const;
  inline OdDbObjectId layerZero() const { return getLayerZeroId(); }

  /** Description:
    Returns the Object ID of the "DEFPOINTS" layer object of this *database* object.
    Arguments:
    createIfNotFound (I) Controls the creation of the object if it does not exist.
 */
  OdDbObjectId getLayerDefpointsId(
    bool createIfNotFound = false) const;

  /** Description:
    Returns the Object ID of the specified system layer object of this *database* object.
    Arguments:
    layerType (I) Type of system layer.
    createIfNotFound (I) Controls the creation of the object if it does not exist.

    Remarks:
    layerType must be one of the following:

    @table
    Name                        Value       Layer name
    OdDb::kLayerSystemLights    0           *ADSK_SYSTEM_LIGHTS
    OdDb::kLayerConstraints     1           *ADSK_CONSTRAINTS
  */
  OdDbObjectId getLayerAdskId(
    OdDb::LayerAdskType layerType,
    bool createIfNotFound = false) const;

  /** Description:
    Returns the object ID of the section manager.

    Remarks:
    The ID may be null if the database
    has never contained any section planes.
  */
  OdDbObjectId getSectionManager() const;
  /*/Gcad(Add)
  /*/
  OdResult getSectionManager (OdDbSectionManager*& pMgr, 
                              OdDb::OpenMode mode) const;
  //*/

  /** \details
    Returns the object ID of the point cloud dictionary.

    \remarks
    The ID may be null if the database
    has never contained any point clouds.
  */
  OdDbObjectId getPointCloudDictionaryId() const;


	OdDbTransactionManager* transactionManager() const;
  /** Description:
    Returns the Class DXF Name for the specified class.

    Arguments:
    pClass (I) Pointer to the class object.

    See Also:
    OdRxClass
  */
  /** { Secret } */
  //Gcad(Modify)
  const OdChar* classDxfName(
    const OdRxClass* pClass);

  /** Description:
    Returns the Object ID corresponding to the specified *handle* object in this *database*.

    Arguments:
    objHandle (I) Database *handle*.
    createIfNotFound (I) Controls the creation of the object if it does not exist.
    xRefId (I) Not used.

    Remarks:
    If objHandle is 0, this function will create a new unique *handle* and return a
    newly created Object ID corresponding to this *handle*.

    Note:
    createIfNotFound is for Teigha for Teigha applications.

    See Also:
    OdDbObjectId
  */
  OdDbObjectId getOdDbObjectId(
    const OdDbHandle& objHandle,
    bool createIfNotFound = false,
    OdUInt32 xRefId = 0);

  /*/Gcad(Add)
  /*/
  OdResult getOdDbObjectId(OdDbObjectId& retId,
                          bool createIfNotFound,
                          const OdDbHandle& objHandle,
                          OdUInt32 xRefId = 0);
  //*/
  /** Description:
    Writes the contents of this *database* object to the specified StreamBuf object.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object to which the data are to be written.
    fileType (I) File type.
    fileVersion (I) File *version*.
    saveThumbnailImage (I) Controls the saving of a thumbnail *image* to the file.
    dxfPrecision (I) DXF file decimal digits precision. [0 .. 16].

    Remarks:
    fileType must be one of the following:

    @table
    Name          Value   Description
    OdDb::kDwg    0       .dwg file.
    OdDb::kDxf    1       .dxf file.
    OdDb::kDxb    2       Binary .dxf file.

    fileVersion must be one of the following:

    @table
    OdDb::kDwg?    Name          Value  Description
    n      OdDb::vAC09   11     Release 9
    n      OdDb::vAC10   13     Release 10
    y      OdDb::vAC12   16     Release 11-12
    y      OdDb::vAC13   19     Release 13
    y      OdDb::vAC14   21     Release 14
    y      OdDb::vAC15   23     2000-2002
    y      OdDb::vAC18   25     2004-2006
    y      OdDb::vAC21   27     2007-2009
    y      OdDb::vAC24   29     2010

    Throws:
    OdError if the write is unsuccessful.
  */
  void writeFile(
    OdStreamBuf* pStreamBuf,
    OdDb::SaveFileType fileType,
    OdDb::DwgVersion fileVersion,
    bool saveThumbnailImage = false,
    int dxfPrecision = 16);

  /**
    Arguments:
    filename (I) Name of the file to which the data are to be written.
  */
  void writeFile(
    const OdString& filename,
    OdDb::SaveFileType fileType,
    OdDb::DwgVersion fileVersion,
    bool saveThumbnailImage = false,
    int dxfPrecision = 16);

  /** Description:
    Reads the contents of the specified StreamBuf object or file into this *database* object.

    Arguments:
    pStreamBuf (I) Pointer to the StreamBuf object from which the data are to be read.
    partialLoad (I) Controls the partial loading of .dwg files.
    pAuditInfo (I) Pointer to an OdDbAuditInfo object.
    password (I) Password for file.
    allowCPConversion (I) If and only if true, allows code page conversion.

    Remarks:
    Using this function in .tx code is not recommended.
    In .tx modules use OdDbHostAppServices::readFile() or OdDbHostAppServices::recoverFile() instead.
    This provides more control for host application which may override these virtual methods.

    The specified OdDbAuditInfo object controls the *audit*, and receives the *audit* status.

    If pAuditInfo is non-zero, a recover will be performed instead of a load.

    Throws:
    OdError if the read is unsuccessful.
  */
  void readFile(
    OdStreamBuf* pStreamBuf,
    bool partialLoad = false,
    OdDbAuditInfo *pAuditInfo = 0,
    const OdPassword& password = OdPassword(),
    bool allowCPConversion = false,
    bool bFireEvent = true);

  /**
    Arguments:
    filename (I) Name of the file from which the data are to be read.
    shareMode (I) Share mode to use when opening the specified file.

    Remarks:
    shareMode must be one of the following:

    @table
    Name                         Value       Description
    Oda::kShareDenyReadWrite     0x10        deny read/write mode
    Oda::kShareDenyWrite         0x20        deny write mode
    Oda::kShareDenyRead          0x30        deny read mode
    Oda::kShareDenyNo            0x40        deny none mode

  */
  void readFile(
    const OdString& filename,
    bool partialLoad = false,
    Oda::FileShareMode shareMode = Oda::kShareDenyWrite,
    const OdPassword& password = OdPassword(),
    bool allowCPConversion = false );

  // Filing Operations
  //
  enum OpenMode {
    kForReadAndReadShare =    1,  // open for read and allow read sharing (_SH_DENYWR)
    kForReadAndWriteNoShare = 2,  // open for read/write and allow no sharing (_SH_DENYRW)
    kForReadAndAllShare =     3,  // open for read and allow read and write sharing (_SH_DENYNO)
    kTryForReadShare =        4   // try kForReadAndReadShare, and if that fails,
    // then try kForReadAndAllShare 
  };

  OdResult readDwgFile(const OdChar* filename,
    const int shmode = _SH_DENYWR,
    bool bAllowCPConversion = false,
    const wchar_t* wszPassword = 0);

  OdResult readDwgFile(const OdChar* fileName,
    OpenMode shmode,
    bool bAllowCPConversion = false,
    const wchar_t* wszPassword = NULL);

  OdResult readDwgFile(OdDwgFileHandle *pDwgFile,
    bool bAllowCPConversion = false,
    const wchar_t* wszPassword = NULL);
  
  inline OdResult saveAs(const OdChar* fileName, const SecurityParams* pSecParams = 0)
  {
    return saveAs(fileName, true, OdDb::kDHL_CURRENT, pSecParams);
  }

  OdResult saveAs(const OdChar* fileName,
    const bool bBakAndRename,
    const OdDb::DwgVersion dwgVer = OdDb::kDHL_CURRENT,
    const SecurityParams* pSecParams = 0);

  OdResult saveAs(OdDwgFileHandle * pOutputFiler,
    const SecurityParams* pSecParams = 0,
    bool crashing = false);

  OdResult dxfOut(const OdChar* fileName, 
    int precision = 16,
    OdDb::DwgVersion dwgVer = OdDb::kDHL_CURRENT, 
    bool saveThumbnailImage = false);

  OdResult save();
  OdResult dxfIn(const OdChar* dxfFilename, const OdChar*logFilename = NULL);
  OdResult dxfIn(IGcReadStream* pInputStream, const OdChar* logFilename = NULL);

  const OdChar* originalFileName() const;
  OdResult getFilename(const OdChar* & pOutput) const;
  OdResult getFilename(OdChar* & pOutput) const;

  OdDwgFileHandle * inputFiler() const;
  
  /** Description:
    Forces all data to be loaded from the input file associated with this *database* object, and closes the file.

    Remarks:
    Client applications will normally not need to call this function.

	//Gcad(Modify)
  */
  /** { Secret } */
  OdResult closeInput(bool bCloseFile = false);

  /** Description:
    Returns the approximate number of objects in this *database* object.

    Remarks:
    This function returns value greater than or equal to the number of objects
    in this *database* object.

    This number is used to construct an OdDbObjectIdArray that can hold all the objects in the *database*, avoiding
    memory fragmentation and increasing performance.
  */
  OdInt32 approxNumObjects() const;

  /** Description:
    Returns the *version* of this *database* object.

    Remarks:
    The maintenance *release* *version* is returned if and only if pMaintReleaseVer != 0.

    Arguments:
    pMaintReleaseVer (I) Pointer to the MaintReleaseVer object to receive the maintenance *release* *version*.
  */
  OdDb::DwgVersion version(
    OdDb::MaintReleaseVer* pMaintReleaseVer = 0) const;

  /** Description:
    Returns the number of times this *database* object has been saved since it was opened.

    Remarks:
    This number may be zero.
  */
  OdInt32 numberOfSaves() const;

  /** Description:
    Returns the *version* to which this *database* object was last saved.

    Arguments:
    pMaintReleaseVer (I) Pointer to the MaintReleaseVer object to receive the maintenance *release* *version*.

    Remarks:
    The maintenance *release* *version* is returned if and only if pMaintReleaseVer != 0.
  */
  OdDb::DwgVersion lastSavedAsVersion(
    OdDb::MaintReleaseVer* pMaintReleaseVer = 0) const;

  /** Description:
    Returns the FileType of the file from which this *database* object was read.

    Remarks:
    originalFileType() returns one of the following:

    @table
    Name         Value   Description
    OdDb::kDwg    0       .dwg file.
    OdDb::kDxf    0       .dxf file.
  */
  OdDb::SaveFileType originalFileType() const;

  /** Description:
    Returns the *version* of the file from which this *database* object was read.

    Arguments:
    pMaintReleaseVer (I) Pointer to the MaintReleaseVer object to receive the maintenance *release* *version*.

    Remarks:
    The maintenance *release* *version* is returned if and only if pMaintReleaseVer != 0.
  */
  OdDb::DwgVersion originalFileVersion(
    OdDb::MaintReleaseVer* pMaintReleaseVer = 0) const;

  /** Description:
    Returns the *version* of the application that created the file from which this *database* object was read.

    Arguments:
    pMaintReleaseVer (I) Pointer to the MaintReleaseVer object to receive the maintenance *release* *version*.

    Remarks:
    The maintenance *release* *version* is returned if and only if pMaintReleaseVer != 0.
  */
  OdDb::DwgVersion originalFileSavedByVersion(
    OdDb::MaintReleaseVer* pMaintReleaseVer = 0) const;

  /*/Gcad(Add)
  /*/
  OdDb::MaintReleaseVer lastSavedAsMaintenanceVersion() const;
  OdDb::MaintReleaseVer originalFileMaintenanceVersion() const;
  OdDb::MaintReleaseVer originalFileSavedByMaintenanceVersion() const;

  OdUInt8      maintenanceReleaseVersion() const;
  //*/
   /**
    Description:
    Adds the specified *reactor* to this object's *reactor* list.

    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  void addReactor(
    OdDbDatabaseReactor* pReactor) const;

  /** Description:
    Removes the specified *reactor* from this object's *reactor* list.

    Arguments:
    pReactor (I) Pointer to the *reactor* object.
  */
  void removeReactor(OdDbDatabaseReactor*
    pReactor) const;

  /** Description:
    Returns the R14 DIMFIT system variable of this *database* object.

    Remarks:
    The DIMATFIT and DIMTMOVE values will be converted to DIMFIT. The complete mapping is as follows:

    @table
    DIMTMOVE    DIMAFIT   DIMFIT
    0           0         0
    0           1         1
    0           2         2
    0           3         3
    1           0         4
    1           1         4
    1           2         4
    1           3         4
    2           0         5
    2           1         5
    2           2         5
    2           3         5
  */
  int dimfit() const;

  /** Description:
    Returns the R14 DIMUNIT system variable of this *database* object.

    Remarks:
    The DIMLUNIT and DIMFRAC values will be converted to DIMUNIT. The complete mapping is as follows:

    @table
    DIMFRAC   DIMLUNIT  DIMUNIT
    0         1         1
    0         2         2
    0         3         3
    0         4         4
    0         5         5
    0         6         8
    1         1         1
    1         2         2
    1         3         3
    1         4         4
    1         5         5
    1         6         8
    2         1         1
    2         2         2
    2         3         3
    2         4         6
    2         5         7
    2         6         8

    All other input combinations return 2.
  */
  int dimunit() const;

  /** Description:
    Sets the R14 DIMFIT system variable of this *database* object.

    Arguments:
    val (I) New value for DIMFIT. [0..5]

    Remarks:
    The DIMFIT value will be converted to DIMATFIT and DIMTMOVE values. The complete mapping is as follows:

    Gcad(Modify): OdResult 
  */
  OdResult setDimfit(
    int val);

  /** Description:
    Sets the R14 DIMUNIT system variable of this *database* object.

    Arguments:
    val (I) New value for DIMUNIT. [1..7]

    Remarks:
    The DIMUNIT value will be converted to DIMLUNIT and DIMFRAC values.

    //Gcad(Modify): OdResult 
  */
  OdResult setDimunit(
    int val);

  OdResult getDimRecentStyleList(OdDbObjectIdArray& objIds) const;

	OdInt16		pickstyle() const;
  OdResult	setPickstyle(OdInt16 style);
  /** Description:
    Deep clones a set of objects, and appends the clones to the specified in owner object.

    Arguments:
    objectIds (I) Array of Object IDs of the objects to be cloned.
    ownerId (I) Object ID of owner object.
    idMap (I/O) ID map.
    deferXlation (I) Defer translation.

    Remarks:
    idMap associates the Object IDs of the original objects with the Object IDs of the newly created clones.

    When cloning objects with different owner IDs, a separate call to this function is required for each
    ownerId. In this case, all but the final call to this function should be made with deferXlation == true.
    This defers translation until all objects have been cloned.

    A deep *clone* is a *clone* of the specified objects and everything they own.

    See also:
    wblockCloneObjects()

	//Gcad(Modify)
  */
  OdResult deepCloneObjects(
    const OdDbObjectIdArray& objectIds,
    OdDbObjectId ownerId,
    OdDbIdMapping& idMap,
    bool deferXlation = false);


  /** Description:
    Shallow clones a set of objects, and appends the clones to the specified in owner object.

    Arguments:
    objectIds (I) Array of Object IDs of the objects to be cloned.
    ownerId (I) Object ID of the owner object.
    idMap (I/O) ID map.
    deferXlation (I) Defer translation.

    Remarks:
    idMap associates the Object IDs of the original objects with the Object IDs of the newly created clones.

    When cloning objects with different owner IDs, a separate call to this function is required for each
    ownerId. In this case, all but the final call to this function should be made with deferXlation == true.
    This defers translation until all objects have been cloned.

    A shallow *clone* is a *clone* of the specified objects, but not what they own.

	duplicateRecordCloning must be one of the following:

    @table
    Name                        Value   Description
    OdDb::kDrcNotApplicable     0       Not applicable to the object.
    OdDb::kDrcIgnore            1       If a duplicate record exists, use the existing record in the *database*, and ignore the clone.
    OdDb::kDrcReplace           2       If a duplicate record exists, replace it with the cloned record.
    OdDb::kDrcXrefMangleName    3       Incoming record names are mangled with <Xref>$0$<name>
    OdDb::kDrcMangleName        4       Incoming record names are mangled with $0$<name>
    OdDb::kDrcUnmangleName      5       Unmangle the names mangled by OdDb::kDrcMangleName, then default to OdDb::kDrcIgnore. Typically used by RefEdit when checking records into the original *database*.

    See also:
    deepCloneObjects()

  //Gcad(Modify)
  */
  OdResult wblockCloneObjects(
    const OdDbObjectIdArray& objectIds,
    OdDbObjectId ownerId,
    OdDbIdMapping& idMap,
    OdDb::DuplicateRecordCloning duplicateRecordCloning,
    bool deferXlation = false);

  /** Description:
    Terminates a call to deepCloneObjects() or wblockCloneObjects().

    Arguments:
    idMap (I/O) ID map of the function call to be terminated.

    Remarks:
    idMap associates the Object IDs of the original objects with the Object IDs of the newly created clones.

    This call is necessary only when a call to deepCloneObjects() or wblockCloneObjects() is made with deferXlation == true,
    and no call will be made with deferXlation == false.
  */
  void abortDeepClone(
    OdDbIdMapping& idMap);

  /** Description:
    Performs an *audit* operation on the header of this *database* object.

    Arguments:
    pAuditInfo (I) Pointer to an OdDbAuditInfo object.

    Remarks:
    The specified OdDbAuditInfo object controls the *audit*, and receives the *audit* status.
  */
  //Gcad(modify)
  OdResult audit(
    OdDbAuditInfo* pAuditInfo);

  /*/Gcad(Add)
  /*/
  //Currently not implemented.
  OdResult auditXData(OdDbAuditInfo* pInfo);
  //*/
  /*/Gcad(Add)
  /*/
  void              disableUndoRecording(bool disable);
  bool              undoRecording() const ;
  //*/

  /** Description:
    Starts a new transaction of this *database* object.
  */
  virtual void startTransaction();

  /** Description:
    Ends the current transaction associated with this *database* object.

    Remarks:
    This function commits all changes to objects since the start of the current transaction.
  */
  virtual void endTransaction();

  /** Description:
    Aborts the current transaction associated with this *database* object.

    Remarks:
    This function initiates an immediate rollback of all changes to objects
    since the start of the current transaction. This rollback occurs for
    all transaction-resident objects.
  */
  virtual void abortTransaction();

  /** Description:
    Returns the number of active transactions associated with this *database* object.
  */
  virtual int numActiveTransactions();

  /** Description:
    Adds a transaction *reactor* to this *database* object.

    Arguments:
    reactor (I) Transaction *reactor*.
  */
  virtual void addTransactionReactor(
    OdDbTransactionReactor* reactor);

  /** Description:
    Removes the specified transaction *reactor* from this *database* object.

    Arguments:
    reactor (I) Transaction *reactor*.
  */
  virtual void removeTransactionReactor(
    OdDbTransactionReactor* reactor);


  /** Description:
    Returns the thumbnail bitmap associated with this *database* object.

    Remarks:
    The thumbnail is in Windows BITMAPINFO* format.

    Arguments:
    dataLength (O) Receives the data length of the thumbnail.
  */
  const void* thumbnailBitmap(
    OdUInt32& dataLength) const;

  // Gcad(Add)
  void* thumbnailBitmap() const;

  /** Description:
    Sets the thumbnail bitmap associated with this *database* object.

    Remarks:
    The thumbnail is in Windows BITMAPINFO* format.

    Arguments:
    dataLength (I) Data length of the thumbnail.
    pBMPData (I) Pointer to the bitmap data.
  */
  void setThumbnailBitmap(
    const void* pBMPData,
    OdUInt32 dataLength);

  // Gcad(Add)
  OdResult setThumbnailBitmap(void*);

  /** Description:
    Returns the state of the RetainOriginalThumbnailBitmap flag.
  */
  bool retainOriginalThumbnailBitmap() const;

  /** Description:
    Controls the state of the RetainOriginalThumbnailBitmap flag.

    Arguments:
    retain (I) Retain if and only if true.
  */
  void setRetainOriginalThumbnailBitmap(
    bool retain);

  OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

/** { Secret } */
#define VAR_DEF(type, name, def_value, metric_def_value, reserve1, reserve2)\
  /** Description: Returns the ##NAME system variable of this *database* object. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  type get##name() const;


#include "SysVarDefs.h"

#undef VAR_DEF
#undef RO_VAR_DEF

/** { Secret } */
#define RO_VAR_DEF(type, name, def_value, metric_def_value, reserve1, reserve2)
/** { Secret } */
#define VAR_DEF(type, name, def_value, metric_def_value, reserve1, reserve2)\
  /** Description: Sets the ##NAME system variable for this *database* object. \
    Arguments: val (I) New value for ##NAME.  ##RANGE  \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  void set##name(type val);

#include "SysVarDefs.h"

#undef RO_VAR_DEF
#undef VAR_DEF

/** { Secret } */
#define VAR_DEF(type, name, dxf, def_value, metric_def_value, reserve1, reserve2)\
  /** Description: Returns the DIM##NAME system variable of this *database* object. \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual type dim##name() const;\
  \
  /** Description: Sets the DIM##NAME system variable for this *database* object. \
    Arguments: val (I) New value for DIM##NAME.  ##RANGE  \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  virtual OdResult setDim##name(type val);

#include "DimVarDefs.h"

#undef VAR_DEF

  virtual bool dimfxlenOn() const;
  virtual double dimfxlen() const;

  virtual void setDimfxlenOn(bool v);
  virtual void setDimfxlen(double v);

  /** Description:
    Returns the TDCREATE system variable of this *database* object.
    Remarks:
    TDUCREATE represents the time and date, in Local Time, that the *database* was created.
  */
  OdDbDate getTDCREATE() const;

  /** Description:
    Returns the TDUPDATE system variable of this *database* object.
    Remarks:
    TDUUPDATE represents the time and date, in Local Time, that the *database* was last saved.
  */
  OdDbDate getTDUPDATE() const;

	OdDbDate getTDINDWG() const;
	OdDbDate getTDUSRTIMER() const;
	OdInt16	 getUSRTIMER() const;
	void		 setUSRTIMER(OdInt16 val);

  bool   dwgFileWasSavedByAutodeskSoftware() const;

  OdInt16 coords() const;
  OdResult setCoords(OdInt16 coords);

  OdInt16 delUsedObj() const;
  OdResult setDelUsedObj(OdInt16 deleteObj);

  OdInt16 dragmode() const;
  OdResult setDragmode(OdInt16 mode);

  OdUInt8 xclipFrame() const;
  OdResult setXclipFrame(OdUInt8 disp);

  OdInt8 pdfframe() const;
  OdResult setPdfframe(OdInt8 val);

  bool usrtimer() const{return !!getUSRTIMER();}
  OdResult setUsrtimer(bool timer){ setUSRTIMER(timer ? 1 : 0); return Oda::eOk; }
  /** Description:
    Returns the specified system variable of this *database* object.

    Arguments:
    name (I) Name of the system variable.

    Remarks:
    Returns a SmartPointer to an OdResBuf object that contains the value.

    System variable names are case-insensitive strings.

    See also:
    System Variables
  */
  OdResBufPtr getSysVar(
    const OdString& name) const;

  /** Description:
    Sets the specified system variable of this *database* object.

    Arguments:
    name (I) Name of the system variable.
    pValue (I) Pointer to an OdResBuf object that contains the new value.

    Remarks:
    System variable names are case-insensitive strings.

    See also:
    System Variables
  */
  void setSysVar(
    const OdString& name,
    const OdResBuf* pValue);

  /** Description:
    Returns the next available *handle* number of this *database* object.
    Remarks:
    Use OdDbHandle::getIntoAsciiBuffer() to return the hex string *version* of the *handle*.
  */
  OdDbHandle handseed() const;

  OdResult setHandseed(const OdDbHandle&);

  /** Description:
    Copies the dimension variables of this *database* object to the
    specified DimStyleTableRecord.

    Arguments:
    pDestination (I) Pointer to the destination record.
  */
  OdResult getDimstyleData(
    OdDbDimStyleTableRecord* pDestination) const;

  /** Description:
    Copies the dimension style data from the specified DimStyleTableRecord
    to the dimension variables of this *database* object.
    Arguments:
    pSource (I) Pointer to the source record.
  */
  OdResult setDimstyleData(
    const OdDbDimStyleTableRecord* pSource);

  /** Description:
    Arguments:
    objectId (I) Object ID of the source record.
  */
  OdResult setDimstyleData(
    OdDbObjectId objectId);

  /** Description:
    Loads a linetype into this *database* object.

    Arguments:
    ltName (I) Name of the linetype to load.
    filename (I) Name of the linetype file from which to load.

    Remarks:
    Wildcards are permitted in ltName; if "*" is specified, all LineTypes from filename will be loaded.

    dlt must be one of the following:

    @table
    Name                      Value   Description
    OdDb::kDltNotApplicable     0       Not Applicable.
    OdDb::kDltIgnore            1       Ignore duplicate LineTypes.
    OdDb::kDltReplace           2       Replace duplicate LineTypes.

    Throws:
    An appropriate error if not successful.
  */
  OdResult loadLineTypeFile(
    const OdChar* ltName,
    const OdChar* filename,
    OdDb::DuplicateLinetypeLoading dlt = OdDb::kDltNotApplicable);

  /** Description:
      Returns the *name* of the file associated with this *database* object.
  */
  virtual OdString getFilename() const;

  OdInt32 getFilesize() const;
  /** Description:
    Removes the Object IDs from the specified array that are hard referenced
    in this *database* object.

    Remarks:
    Any remaining Object IDs can be safely *erased*.

    Note:
    This function does not modify this *database* object.

    Arguments:
    objectIds (I/O) Array of Object IDs.
  */
  virtual OdResult purge(
    OdDbObjectIdArray& objectIds) const;

  /** Description:
      Returns a count of hard references to each of the specified Object IDs.

      Arguments:
      objectIds (I) Array of Object IDs.
      counts (O) Receives an array of hard reference counts.

      Note:
      counts must be the same size as objectIds.

      Each element of counts will be incremented for each hard reference of the corresponding *objectId*
      The caller must *initialize* the elements of count to zero or an appropriate value
      before calling this function.
  */
  virtual OdResult countHardReferences(
    const OdDbObjectIdArray& objectIds,
    OdUInt32* counts) const;

  /** Description:
      Returns the Object ID of the active layout of this *database* object.
  */
  OdDbObjectId currentLayoutId() const;

  /** Description:
    Sets the current layout of this *database* object.

    Arguments:
    layoutName (I) Name of the layout.
  */
  virtual void setCurrentLayout(
    const OdString& layoutName);

  /**
    Arguments:
    layoutId (I) Object ID of layout.
  */
  virtual void setCurrentLayout(
    const OdDbObjectId& layoutId);

  /** Description:
      Returns the *name* of the active layout of this *database* object.

      Arguments:
      allowModel (I) If and only if true, allows the ModelSpace layout *name* to be returned.

      Remarks:
      If allowModel == false, an empty string will be returned if the active layout is ModelSpace.

	  //Gcad(Modify)
  */
  virtual const OdChar* findActiveLayout(
    bool allowModel) const;

  /** Description:
    Returns the Object ID of the BlockTableRecord associated with the active
    layout of this *database* object.
  */
  virtual OdDbObjectId getActiveLayoutBTRId() const;

  /** Description:
    Returns the Object ID of the specified layout in this *database* object.

    Arguments:
    layoutName (I) Layout *name*.

    Remarks:
    Returns a null Object ID if the specified layout is not found.
  */
  virtual OdDbObjectId findLayoutNamed(
    const OdString& layoutName) const;

  /** Description:
    Deletes the specified layout from this *database* object.

    Arguments:
    layoutName (I) Layout *name*.
  */
  virtual void deleteLayout(
    const OdString& layoutName);

  /** Description:
    Creates a new layout with the specified *name* in this *database* object.

    Remarks:
    The newly created layout is added to this *database* object along with its
    newly created, associated OdDbBlockTableRecord.

    Arguments:
    layoutName (I) Layout *name*.
    pBlockTableRecId (I) Pointer to the BlockTableRecID to receive the Object ID of the new BlockTableRecord object.
  */
  virtual OdDbObjectId createLayout(
    const OdString& layoutName,
    OdDbObjectId* pBlockTableRecId = 0);

  /** Description:
    Returns the number of layouts in this *database* object.
  */
  virtual int countLayouts() const;

  /** Description:
    Renames the specified layout in this *database* object.
    Arguments:
    oldName (I) Old *name*.
    newName (I) New *name*.
  */
  virtual void renameLayout(
    const OdString& oldName,
    const OdString& newName);

  /** Description:
      Starts *undo* recording of this *database* object.
  */
  void startUndoRecord(const OdChar* pRecordName = 0);

  /** Description:
      Returns true if *undo* information exists of this *database* object.
  */
  bool hasUndo() const;
  bool hasCurUndo(bool *pIsNothing = 0) const;
  OdDbUndoController* undoController() const;

  /** Description:
    Performs an *undo* operation on this *database* object.

    Remarks:
    All operations performed since the
    last call to startUndoRecording will be undone.

    At least 1 undo step is always supported by Teigha for internal needs.
  */
  void undo();

  void blockUndoRecording(bool bBegin);

  bool isUndoBlockStarted();

  void setUndoMark();

  bool hasUndoMark() const;

  void undoBack();

  int getUNDOMARKS() const;

  void clearUndo();

  /** Description:
    Returns true if *redo* information exists of this *database* object.
  */
  bool hasRedo() const;
  OdDbUndoControllerPtr redoController() const;

  /** Description:
    Performs a *redo* operation on this *database* object.

    Remarks:
    Restores operations undone by the last *undo*.
  */
  void redo();

  /** Description:
    Performs an *audit* operation on the this entire *database* object.

    Arguments:
    pAuditInfo (I) Pointer to an AuditInfo object.

    Remarks:
    The specified AuditInfo object controls the *audit*, and receives the *audit* status.
  */
  void auditDatabase(
    OdDbAuditInfo *pAuditInfo);

  OdResult applyPartialUndo(
    OdDbDwgFiler* pUndoFiler,
    OdRxClass* pClassObj);

  OdDbDwgFiler* undoFiler();

  /** Description:
    Mimics the INSERT command of this *database* object.

    Arguments:
    sourceBlockName (I) Name of the OdDbBlockTableRecord in pSource.
    destinationBlockName (I) Name for the new OdDbBlockTableRecord.
    pSource (I) Source *database*.
    preserveSourceDatabase (I) True to *clone* entities, false to move entities.
    xfm (I) Transformation matrix.

    Remarks:
    If destinationBlockName is specified, a new OdDbBlockTableRecord is created.

    If both destinationBlockName and sourceBlockName are specified, all entities in the BlockTableRecord specified by sourceBlockName in pSource
    are *copied* (or moved) into the new OdDbBlockTableRecord.

    If destinationBlockName is specified, and sourceBlockName is not specified, all ModelSpace entities in pSource, are *copied* (or moved) into the new OdDbBlockTableRecord.

    If xfm is specified, all ModelSpace entities in pSource are *copied* (or moved) into the
    ModelSpace of this *database* object and transformed by xfm.
  */
  OdDbObjectId insert(
    const OdString& destinationBlockName,
    OdDbDatabase* pSource,
    bool preserveSourceDatabase = true);

  OdDbObjectId insert(
    const OdString& sourceBlockName,
    const OdString& destinationBlockName,
    OdDbDatabase* pSource,
    bool preserveSourceDatabase = true);

  //Gcad(Modify):returns:void->OdResult
  OdResult insert(
    const OdGeMatrix3d& xfm,
    OdDbDatabase* pSource,
    bool preserveSourceDatabase = true);

  /*/Gcad(Add)
  /*/
   OdResult insert(OdDbObjectId& blockId,
          const OdChar * destinationBlockName,
				  OdDbDatabase* pDb,
				  bool preserveSourceDatabase = true);

   OdResult insert(OdDbObjectId& blockId, 
          const OdChar * sourceBlockName,
          const OdChar * destinationBlockName,
				  OdDbDatabase* pDb,
				  bool preserveSourceDatabase = true);     
  //*/
  
  /** Description:
     Mimics the WBLOCK command of this *database* object.

     Arguments:
     outObjIds (I) Array of Object IDs to be wblocked.
     basePoint (I) WCS base point for the
     blockId (I) Object ID of the BlockTableRecord to be wblocked.

     Remarks:
     Creates a new OdDbDatabase object, and returns a SmartPointer to the new *database*.

     If called with no arguments, the entire contents of this *database* object are wblocked.
  */
  OdDbDatabasePtr wblock(
    const OdDbObjectIdArray& outObjIds,
    const OdGePoint3d& basePoint);

  OdDbDatabasePtr wblock(
    OdDbObjectId blockId);

  OdDbDatabasePtr wblock();

  /*/Gcad(Add)
  /*/
  OdResult wblock(OdDbDatabase*& pOutputDb,
             const OdDbObjectIdArray& outObjIds,
             const OdGePoint3d& basePoint);

  OdResult wblock(OdDbDatabase* pOutputDb,  // pre-existing (template) db
                 const OdDbObjectIdArray& outObjIds,
                 const OdGePoint3d& basePoint,
                 OdDb::DuplicateRecordCloning drc);  // kDrcIgnore

  OdResult wblock(OdDbDatabase*& pOutputDb, OdDbObjectId blockId);
	
  OdResult wblock(OdDbDatabase*& pOutputDb);

  void     forceWblockDatabaseCopy();
  //*/
 /**
    Note:
    As implemented, this function does nothing but return a null SmartPointer.
    It will be fully implemented in a future *release*.
  */
  OdDbObjectPtr subWblockClone(OdDbIdMapping& ownerIdMap, OdDbObject*) const;

  /** Description:
    Sets the security parameters of this *database* object.

    Arguments:
    secParams (I) Security params.
    setDbMod (I) If and only if true, the DBMOD variable will be set if the security settings *modified*.

    Note:
    As implemented, this function ignores setDbMod, and never modifies the DBMOD variable.
    It will be fully implemented in a future *release*.
  */
  void setSecurityParams(
    const OdSecurityParams& secParams,
    bool setDbMod = true);

  /** Description:
    Returns the security parameters of this *database* object.
    Arguments:
    secParams (I) Security params.
    Remarks:
    Returns true if and only if secParams.nFlags!=0 && secParams.password is not empty.
  */
  bool securityParams(
    OdSecurityParams& secParams) const;

  /*/Gcad(Add)
  /*/
  bool                  setSecurityParams(const SecurityParams* pSecParams,
										  bool bSetDbMod = true);
  const SecurityParams* cloneSecurityParams();
  static void           disposeSecurityParams(const SecurityParams* pSecParams);
  //*/
  /** Description:
    Returns the OdFileDependencyManager object of this *database* object.

	Gcad(internal)
  */
  OdFileDependencyManagerPtr fileDependencyManager(ODSYSDEF) const;
  /*/Gcad(Add)
  /*/
  OdFileDependencyManager* fileDependencyManager() const;
  //*/
  /** Description:
  Returns the OdDbObjectContextManager object of this *database* object.
  */
  OdDbObjectContextManagerPtr objectContextManager() const;

  /** Description:
    Recalculates the *extents* of this *database* object.
    Arguments:
    bExact (I) Enables more slow but exact extents calculation algorithm.
  */
  OdResult updateExt(bool bExact = false);

  /** Description:
      Returns true if and only if this *database* object was created by an educational *version* of the application.
  */
  bool isEMR() const;
  /** Description:
    Returns the Object ID of the OdDbBlockTableRecord that references this *database* object as an Xref.
  */
  OdDbObjectId xrefBlockId() const;

  /** Description:
    Returns true if and only if this *database* object is partially opened.
  */
  bool isPartiallyOpened() const;

  OdResult applyPartialOpenFilters(
    const OdDbSpatialFilter* pSpatialFilter,
    const OdDbLayerFilter* pLayerFilter);

  void disablePartialOpen();

  void setGsModel(OdGsModel*);
  OdGsModel* gsModel() const;

  void setGsHighlightModel(OdGsModel*);
  OdGsModel* gsHighlightModel() const;

  OdResult evaluateFields(int nContext,
    const OdChar* pszPropName = NULL,
    OdDbDatabase* pDb = NULL,
    int* pNumFound = NULL,
    int* pNumEvaluated = NULL);

  OdResult getViewportArray(OdDbObjectIdArray& vportIds,
    bool bGetPaperspaceVports = true) const;

  OdResult getTimeZoneInfo(OdDb::TimeZone tz, double& offset, OdString& desc) const;
  OdResult setTimeZoneAsUtcOffset(double offset);

  bool geoMarkerVisibility() const;
  OdResult setGeoMarkerVisibility(bool value);

  bool annotativeDwg() const;
  OdResult setAnnotativeDwg(bool anno);

  OdUInt8 lightingUnits() const;
  OdResult setLightingUnits(OdUInt8 val);

  bool lightsInBlocks() const;
  OdResult setLightsInBlocks(bool val);

  OdInt16 dxeVal() const;
  OdResult setDxeVal(OdInt16 val);

  double mleaderscale() const;
  OdResult setMLeaderscale(double scale);

  OdInt16 cDynDisplayMode() const;
  OdResult setCDynDisplayMode(OdInt16 val);

  OdInt16 previewType() const;
  OdResult setPreviewType(OdInt16 val);

  OdUInt8 indexctl() const;
  OdResult setIndexctl(OdUInt8 val);

  OdUInt8 layerEval() const;
  OdResult setLayerEval(OdUInt8 val);

  OdInt16 layerNotify() const;
  OdResult setLayerNotify(OdInt16 val);

  double msOleScale() const;
  OdResult setMsOleScale(double val);

  OdUInt8 updateThumbnail() const;
  OdResult setUpdateThumbnail(OdUInt8 val);

  enum EraseMask 
  {
    kZeroLengthCurve = 0x01,
    kEmptyText = 0x02,
    kAllEmptyObj = 0xFFFFFFFF
  };

  OdUInt32 eraseEmptyObjects(const OdUInt32 flags);
  OdUInt32 countEmptyObjects(const OdUInt32 flags);


  /** Description:
    Sets the current UCS of this *database* object.

    Arguments:
    origin (I) The WCS *origin* of the UCS.
    xAxis (I) The WCS X-axis of the UCS.
    yAxis (I) The WCS Y-axis of the UCS.
    viewType (I) Orthographic view type.
    ucsId (I) Object ID of the UCS.

    Remarks:
    viewType must be one of the following:

    @table
    Name                  Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS
    OdDb::kTopView        1       Top view with respect to the UCS
    OdDb::kBottomView     2       Bottom view with respect to the UCS
    OdDb::kFrontView      3       Front view with respect to the UCS
    OdDb::kBackView       4       Back view with respect to the UCS
    OdDb::kLeftView       5       Left view with respect to the UCS
    OdDb::kRightView      6       Right view with respect to the UCS
  */
  void setCurrentUCS(
    OdDb::OrthographicView viewType);
  void setCurrentUCS(
    const OdDbObjectId& ucsId);
  void setCurrentUCS(
    const OdGePoint3d& origin,
    const OdGeVector3d& xAxis,
    const OdGeVector3d& yAxis);

  /** Description:
    Returns the UCS *origin* and orthographic view type for the current UCS.

    Arguments:
    viewType (I) Orthographic view type.

    Remarks:
    viewType must be one of the following:

    @table
    Name            Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS
    OdDb::kTopView        1       Top view with respect to the UCS
    OdDb::kBottomView     2       Bottom view with respect to the UCS
    OdDb::kFrontView      3       Front view with respect to the UCS
    OdDb::kBackView       4       Back view with respect to the UCS
    OdDb::kLeftView       5       Left view with respect to the UCS
    OdDb::kRightView      6       Right view with respect to the UCS
  */
  OdGePoint3d getUCSBASEORG(
    OdDb::OrthographicView viewType) const;

  /** Description:
    Sets the UCS *origin* and orthographic view type for the current UCS.

    Arguments:
    origin (I) The WCS *origin* of the UCS.
    viewType (I) Orthographic view type.

    Remarks:
    viewType must be one of the following:

    @table
    Name            Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS
    OdDb::kTopView        1       Top view with respect to the UCS
    OdDb::kBottomView     2       Bottom view with respect to the UCS
    OdDb::kFrontView      3       Front view with respect to the UCS
    OdDb::kBackView       4       Back view with respect to the UCS
    OdDb::kLeftView       5       Left view with respect to the UCS
    OdDb::kRightView      6       Right view with respect to the UCS
  */
  void setUCSBASEORG(
    OdDb::OrthographicView viewType,
    const OdGePoint3d& origin);

  /** Description:
    Returns the UCS *origin* and orthographic view type for the current PaperSpace UCS.

    Arguments:
    viewType (I) Orthographic view type.

    Remarks:
    viewType must be one of the following:

    @table
    Name                  Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS
    OdDb::kTopView        1       Top view with respect to the UCS
    OdDb::kBottomView     2       Bottom view with respect to the UCS
    OdDb::kFrontView      3       Front view with respect to the UCS
    OdDb::kBackView       4       Back view with respect to the UCS
    OdDb::kLeftView       5       Left view with respect to the UCS
    OdDb::kRightView      6       Right view with respect to the UCS
  */
   OdGePoint3d getPUCSBASEORG(
    OdDb::OrthographicView viewType) const;

 /** Description:
    Sets the UCS *origin* and orthographic view type for the current PaperSpace UCS.

    Arguments:
    origin (I) The WCS *origin* of the UCS.
    viewType (I) Orthographic view type.

    Remarks:
    viewType must be one of the following:

    @table
    Name                  Value   View type
    OdDb::kNonOrthoView   0       Non-orthographic with respect to the UCS
    OdDb::kTopView        1       Top view with respect to the UCS
    OdDb::kBottomView     2       Bottom view with respect to the UCS
    OdDb::kFrontView      3       Front view with respect to the UCS
    OdDb::kBackView       4       Back view with respect to the UCS
    OdDb::kLeftView       5       Left view with respect to the UCS
    OdDb::kRightView      6       Right view with respect to the UCS
  */
  void setPUCSBASEORG(
    OdDb::OrthographicView viewType,
    const OdGePoint3d& origin);

  /** Description:
    Returns the DIMSTYLE system variable of this database object.
    Remarks:
    DIMSTYLE specifies the default dimension style for new entities.
    Arguments:
    val (I) New value for DIMSTYLE.
  */
  void setDIMSTYLE(const OdDbObjectId& val); // ARX: read only

  //void setTEXTSIZE(double val);
  //void setTEXTSTYLE(const OdDbObjectId& id);

  /** Description:
  Returns the database to its original state (when the xref was first read) by undoing
  any modifications.
  Remarks:
  This function should be used with restoreForwardingXrefSymbols when reading or
  writing any xref object. 
  */
  OdResult restoreOriginalXrefSymbols();

  /** Description:
  Returns the database to its modified state (before any original state restoration) by
  redoing modifications.
  Remarks:
  This function should be used with restoreOriginalXrefSymbols when reading or
  writing any xref object. The database requires write-access to symbol tables and 
  records.
  */
  OdResult restoreForwardingXrefSymbols();

  static bool isValidLineWeight(int weight);

  static OdDb::LineWeight getNearestLineWeight(int weight);

  OdResult getDimstyleChildData(const OdRxClass *pDimClass,
						  OdDbDimStyleTableRecord*& pRec,
						  OdDbObjectId &style) const;

  OdDbObjectId getDimstyleChildId(const OdRxClass *pDimClass,
								OdDbObjectId &parentStyle) const;

  OdDbObjectId getDimstyleParentId(OdDbObjectId &childStyle) const;
  
  /*
  bool plotStyleMode() const;

  void forceWblockDatabaseCopy();

  void auditXData(OdDbAuditInfo* pInfo);

  OdDbUndoController* undoController() const;


  void getDimRecentStyleList(OdDbObjectIdArray& objIds) const;

  void applyPartialOpenFilters(const OdDbSpatialFilter* pSpatialFilter,
                               const OdDbLayerFilter* pLayerFilter);

  void disablePartialOpen();

  void newFingerprintGuid();

  void newVersionGuid();

  double viewportScaleDefault() const;

  void setViewportScaleDefault(double newDefaultVPScale);

  virtual void copyLayout(const OdChar* copyname, const OdChar* newname);

  virtual void cloneLayout(const OdDbLayout* pLBTR, const OdChar* newname, int newTabOrder);

  virtual OdDbObjectId getNonRectVPIdFromClipId(const OdDbObjectId& clipId);

  virtual bool isViewportClipped(short index);

  */
	OdDbObjectId paperSpaceVportId() const { return getPaperSpaceVportId();};

  OdDbObjectId getPaperSpaceVportId() const;

  OdDbObjectId byLayerMaterialId() const;
  OdDbObjectId byBlockMaterialId() const;
  OdDbObjectId globalMaterialId() const;
  
  inline OdDbObjectId globalMaterial() const{return globalMaterialId();}
  inline OdDbObjectId byLayerMaterial() const{return byLayerMaterialId();}
  inline OdDbObjectId byBlockMaterial() const{return byBlockMaterialId();}

  OdDbObjectId activeViewportId() const;

#define OD_SYSVAR_DEF_R(RName, DDName, type) \
        type RName() const;
#define OD_SYSVAR_DEF_W(WName, DDName, type) \
        OdResult WName(type);
# include "DwgSysVar.h"
#undef OD_SYSVAR_DEF_R
#undef OD_SYSVAR_DEF_W

  OdResult getMenu(OdChar*&) const;
  OdResult getProjectName(OdChar*&) const;
  OdResult setProjectName(const OdChar*);
  OdResult getHyperlinkBase(OdChar*&) const;
  OdResult setHyperlinkBase(const OdChar*);
  OdResult getStyleSheet(OdChar*&) const;
  OdResult setStyleSheet(const OdChar*);
  
  OdDb::PlotStyleNameType getCePlotStyleNameId(OdDbObjectId& id) const;
  OdResult setCePlotStyleName(OdDb::PlotStyleNameType, OdDbObjectId newId = OdDbObjectId::kNull);

  OdResult getFingerprintGuid(OdChar*&) const;
  OdResult setFingerprintGuid(const OdChar*);
  //OdResult newFingerprintGuid(); // 不实现

  OdResult getVersionGuid(OdChar*&) const;
  OdResult setVersionGuid(const OdChar*);
  //OdResult newVersionGuid(); // 不实现

  OdDbAnnotationScale* cannoscale() const;
  OdResult setCannoscale(OdDbAnnotationScale*);

  OdGePoint3d worldPucsBaseOrigin(OdDb::OrthographicView) const;
  OdResult setWorldPucsBaseOrigin(const OdGePoint3d&, OdDb::OrthographicView);
  bool isPucsOrthographic(OdDb::OrthographicView&) const;

  OdGePoint3d worldUcsBaseOrigin(OdDb::OrthographicView) const;
  OdResult setWorldUcsBaseOrigin(const OdGePoint3d&, OdDb::OrthographicView);
  bool isUcsOrthographic(OdDb::OrthographicView&) const;

  OdResult getDimpost  (OdChar*&) const;
  OdResult getDimapost (OdChar*&) const;

  OdResult getDimblk   (OdChar*&) const;
  OdResult getDimblk1  (OdChar*&) const;
  OdResult getDimblk2  (OdChar*&) const;

  OdResult setDimblk   (const OdChar*);
  OdResult setDimblk1  (const OdChar*);
  OdResult setDimblk2  (const OdChar*);
  OdResult setDimldrblk(const OdChar*);

  OdResult getVisualStyleList(OdArray<const OdChar*> & vstyleList);

  //
  OdInt16 osmode() const;
  OdResult setOsmode(OdInt16 mode);

  bool blipmode() const;
  OdResult setBlipmode(bool mode);

  bool attreq () const;
  OdResult setAttreq (bool dia);

  bool attdia () const;
  OdResult setAttdia (bool dia);


  OdDbLayerStateManager *getLayerStateManager() const;

  virtual OdDbUnitsFormatter& formatter();

  void enableGraphicsFlush(bool bEnable);
  void flushGraphics();
  
  // ODA_MT_DB_BEGIN
  bool isMultiThreadedMode() const;
  virtual void setMultiThreadedMode(int threadsCount);
  // ODA_MT_DB_END
private:
  friend class OdDbDatabaseImpl;
  OdDbDatabaseImpl* m_pImpl;
};

TOOLKIT_EXPORT OdResult oddbGetExtnames(bool& value, OdDbDatabase* pDb);
TOOLKIT_EXPORT OdResult oddbSetExtnames(OdDbDatabase* pDb, bool value);

/** Fills in OdThumbnailImage object from stream. Throws appropriate exception if an error occurred.
*/

TOOLKIT_EXPORT void odDbGetPreviewBitmap(OdStreamBuf* pStreamBuf, OdThumbnailImage* pPreview);


// The functions below provide write access to "Read-Only" *database* variables.
// Actually they are a OdDb::kludge for bypassing non-implemented DD functionality
// or to repair invalid drawings.
// They should be used with care.

/** Description:
    Sets the DWGCODEPAGE value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for DWGCODEPAGE.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetDWGCODEPAGE(
  OdDbDatabase& db,
  OdCodePageId val);

/** Description:
    Sets the TDUCREATE system variable in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for TDUCREATE.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetTDUCREATE(
  OdDbDatabase& db,
  OdDbDate val);

/** Description:
    Sets the TDUUPDATE value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for TDUUPDATE.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetTDUUPDATE(
  OdDbDatabase& db,
  OdDbDate val);

/** Description:
    Sets the TDINDWG value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for TDINDWG.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetTDINDWG(
  OdDbDatabase& db,
  OdDbDate val);

/** Description:
    Sets the TDUSRTIMER value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for TDUSRTIMER.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetTDUSRTIMER(
  OdDbDatabase& db,
  OdDbDate val);

/** Description:
    Sets the PSTYLEMODE value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for PSTYLEMODE.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetPSTYLEMODE(
  OdDbDatabase& db,
  bool val);

/** Description:
    Sets the UCSORG system variable in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for UCSORG.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetUCSORG(
  OdDbDatabase& db,
  OdGePoint3d val);

/** Description:
    Sets the UCSXDIR value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for UCSXDIR.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetUCSXDIR(
  OdDbDatabase& db,
  OdGeVector3d val);

/** Description:
    Sets the UCSYDIR value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for UCSYDIR.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetUCSYDIR(
  OdDbDatabase& db,
  OdGeVector3d val);

/** Description:
    Sets the PUCSORG value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for PUCSORG.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetPUCSORG(
  OdDbDatabase& db,
  OdGePoint3d val);

/** Description:
    Sets the PUCSXDIR value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for PUCSXDIR.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetPUCSXDIR(
  OdDbDatabase& db,
  OdGeVector3d val);

/** Description:
    Sets the PUCSYDIR value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for PUCSYDIR.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetPUCSYDIR(
  OdDbDatabase& db,
  OdGeVector3d val);

/** Description:
    Sets the LASTPOINT value in the specified OdDbDatabase instance.

    Arguments:
    db (I) Database.
    val (I) Value for LASTPOINT.

    Note:
    This function provides write access to "Read-Only" system variables.
    It may be used to bypass non-implemented Teigha functionality or to repair drawings,
    and should be used with care.
*/
TOOLKIT_EXPORT void odDbSetLASTPOINT(
  OdDbDatabase& db,
  const OdGePoint3d& pnt);

 /** Description:
    Saves an line types to the specified file.
    Arguments:
    db (I) OdDbDatabase object.
    filename (I) Name of the MlineStyle file to save.
		encode (I) Encoding used for writing linetype text file.
  */
extern TOOLKIT_EXPORT void odDbSaveLineTypeFile(OdDbDatabase &Db, OdStreamBuf &filename, OdDb::TextFileEncoding encode = OdDb::kTextFileEncodingDefault);

 /** Description:
    Loads an MLineStyle into the specified *database* object.

    Arguments:
    db (I) OdDbDatabase object.
    patternName (I) Name of the pattern to load.
    filename (I) Name of the MlineStyle file from which to load.
    dlt (I) Duplicate linetype loading.
    Remarks:
    dlt must be one of the following:

    @table
    Name                        Value   Description
    OdDb::kDltNotApplicable     0       Not Applicable.
    OdDb::kDltIgnore            1       Ignore duplicate LineTypes.
    OdDb::kDltReplace           2       Replace duplicate LineTypes.

    Throws:
    An appropriate error if not successful.
  */
extern TOOLKIT_EXPORT void odDbLoadMlineStyleFile(
  OdDbDatabase &db,
  const OdString& patternName,
    OdStreamBuf &filename,
  OdDb::DuplicateLinetypeLoading dlt = OdDb::kDltNotApplicable );

 /** Description:
    Saves an MLineStyle to the specified file.
    Arguments:
    db (I) OdDbDatabase object.
    filename (I) Name of the MlineStyle file to save.
  */
extern TOOLKIT_EXPORT void odDbSaveMlineStyleFile(OdDbDatabase &Db, OdStreamBuf &filename );

namespace OdDb
{
  TOOLKIT_EXPORT const char* DwgVersionToStr(DwgVersion ver);
  TOOLKIT_EXPORT DwgVersion DwgVersionFromStr(const char* str);
}

TOOLKIT_EXPORT OdDb::DwgDataType oddbGroupCodeToType(OdDb::DxfCode pCode);
TOOLKIT_EXPORT OdResult oddbGetObjectId(OdDbObjectId& objId,const tdx_name objName);
TOOLKIT_EXPORT OdResult oddbGetAdsName(tdx_name& objName, OdDbObjectId objId);

TOOLKIT_EXPORT OdDbVoidPtrArray * gcdbActiveDatabaseArray();

TOOLKIT_EXPORT bool gcdbIsPersistentReactor(void * pSomething);
TOOLKIT_EXPORT OdDbObjectId gcdbPersistentReactorObjectId(void * pSomething);

TOOLKIT_EXPORT OdResult oddbSetReferenced(OdDbObjectId objId);

#include "TD_PackPop.h"

#endif /* _ODDBDATABASE_INCLUDED_ */

