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

#ifndef __ODGIINDIRECTENTITYACCESSOR_H__
#define __ODGIINDIRECTENTITYACCESSOR_H__

#include "../TD_PackPush.h"

#include "../RxObject.h"
#include "../Gi/Gi.h"
#include "../SharedPtr.h"

#include "../Ge/GeMatrix3d.h"

class OdGeExtents2d;
class OdGeVector3d;
struct OdGiClipBoundary;
class OdGiAbstractClipBoundary;
/** Description:
    Basic interface for all subtypes

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataBase
{
  public:
    virtual ~OdGiIndirectEntityDataBase() { }

    virtual OdUInt32 getVersion() const { return 1; }
};

typedef OdGiIndirectEntityDataBase *OdGiIndirectEntityDataBasePtr;


// @@@mark_br
/** Description:
    For layout object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForLayout : public OdGiIndirectEntityDataBase
{
  public:
    virtual OdDbStub* getBlockTableRecordId(const OdGiDrawable *pDrw) const = 0;
    virtual bool isModelSpaceLayout(const OdGiDrawable *pDrw) const = 0;
    virtual bool getPSLTSCALE(const OdGiDrawable *pDrw) const = 0;
};

#define OdGiIndirectEntityDataForLayoutPtr(base) static_cast<OdGiIndirectEntityDataForLayout*>(base)
// @@@mark_br_


/** Description:
    For hatch object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForHatch : public OdGiIndirectEntityDataBase
{
  public:
    virtual bool getBoundaryExtents(const OdGiDrawable *pDrw, OdGeExtents2d &extents, double &elevation, OdGeVector3d &normal) const = 0;
    // @@@mark_br
    virtual bool isSolidFill(const OdGiDrawable *pDrw) const = 0;
    // @@@mark_br_
};

#define OdGiIndirectEntityDataForHatchPtr(base) static_cast<OdGiIndirectEntityDataForHatch*>(base)


/** Description:
    For block object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForBlock : public OdGiIndirectEntityDataBase
{
  public:
    class ODGI_EXPORT ObjectIterator
    {
      public:
        virtual ~ObjectIterator() { }
        virtual void start() = 0;
        virtual bool done() const = 0;
        virtual void step() = 0;
        virtual OdDbStub *objectId() const = 0;
        virtual OdGiDrawablePtr object() = 0;
    };
  public:
    virtual bool isBlockReferenceAdded(OdGiDrawable *pDrw) const = 0;

    virtual void verifyBlock(OdGiDrawable *pBlock) const = 0;

    virtual bool isFromExternalReference(const OdGiDrawable *pDrw) const = 0;
    virtual OdDbBaseDatabase *xrefDatabase(const OdGiDrawable *pDrw) const = 0;

    typedef OdSharedPtr<ObjectIterator> ObjectIteratorPtr;
    virtual ObjectIteratorPtr newObjectIterator(const OdGiDrawable *pDrw, bool bSkipErased = true) const = 0;

    // @@@mark_br
    virtual bool isLayout(const OdGiDrawable *pDrw) const = 0;
    // @@@mark_br_
};

#define OdGiIndirectEntityDataForBlockPtr(base) static_cast<OdGiIndirectEntityDataForBlock*>(base)

/** Description:
    For block reference object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForBlockRef : public OdGiIndirectEntityDataBase
{
  public:
    class ODGI_EXPORT AttribIterator
    {
      public:
        virtual ~AttribIterator() { }
        virtual void start() = 0;
        virtual bool done() const = 0;
        virtual void step() = 0;
        virtual OdDbStub *objectId() const = 0;
        virtual OdGiDrawablePtr object() = 0;
    };
  public:
    virtual OdDbStub *blockTableRecord(const OdGiDrawable *pDrw) const = 0;

    virtual OdGeMatrix3d blockTransform(const OdGiDrawable *pDrw) const = 0;

    typedef OdSharedPtr<AttribIterator> AttribIteratorPtr;
    virtual AttribIteratorPtr newAttribIterator(const OdGiDrawable *pDrw, bool bSkipErased = true) const = 0;

    virtual OdGiClipBoundary *getClipBoundary(const OdGiDrawable *pDrw, bool& enabled, bool plotting = false, OdGiAbstractClipBoundary** pClipInfo = NULL) const = 0;
};

#define OdGiIndirectEntityDataForBlockRefPtr(base) static_cast<OdGiIndirectEntityDataForBlockRef*>(base)

/** Description:
    For block reference object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForPdfRef : public OdGiIndirectEntityDataBase
{
  public:    
  public:
    virtual OdDbStub *blockTableRecord(const OdGiDrawable *pDrw) const = 0;

    virtual OdGeMatrix3d blockTransform(const OdGiDrawable *pDrw) const = 0;

    virtual OdGiClipBoundary *getClipBoundary(const OdGiDrawable *pDrw, bool& enabled, bool plotting = false, OdGiAbstractClipBoundary** pClipInfo = NULL) const = 0;
};

#define OdGiIndirectEntityDataForPdfRefPtr(base) static_cast<OdGiIndirectEntityDataForPdfRef*>(base)

/** Description:
    For MInsert block object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForMInsert : public OdGiIndirectEntityDataForBlockRef
{
  public:
    virtual void getParameters(const OdGiDrawable *pDrw, double &fRowSpacing, double &fColumnSpacing,
                               OdUInt16 &nRows, OdUInt16 &nColumns) = 0;
};

#define OdGiIndirectEntityDataForMInsertPtr(base) static_cast<OdGiIndirectEntityDataForMInsert*>(base)

/** Description:
    For attribute definition

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForAttributeDef : public OdGiIndirectEntityDataBase
{
  public:
    virtual bool isContant(const OdGiDrawable *pDrw) const = 0;
};

#define OdGiIndirectEntityDataForAttributeDefPtr(base) static_cast<OdGiIndirectEntityDataForAttributeDef*>(base)

/** Description:
    For sortents object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForSortents : public OdGiIndirectEntityDataBase
{
  public:
    virtual OdDbStub *blockId(const OdGiDrawable *pDrw) const = 0;
};

#define OdGiIndirectEntityDataForSortentsPtr(base) static_cast<OdGiIndirectEntityDataForSortents*>(base)

/** Description:
    For long transaction object

    Library:
    TD_Gi
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityDataForLongTransaction : public OdGiIndirectEntityDataBase
{
  public:
    class ODGI_EXPORT WorkSetIterator
    {
      public:
        virtual ~WorkSetIterator() { }
        virtual bool done() = 0;
        virtual void step() = 0;
        virtual OdDbStub *objectId() const = 0;
    };
  public:
    virtual OdDbStub *destinationBlock(const OdGiDrawable *pDrw) const = 0;

    virtual bool workSetHas(const OdGiDrawable *pDrw, OdDbStub *pId) const = 0;

    typedef OdSharedPtr<WorkSetIterator> WorkSetIteratorPtr;
    virtual WorkSetIteratorPtr newWorkSetIterator(const OdGiDrawable *pDrw, bool incRemoved = false, bool incSecondary = false) const = 0;

    virtual OdDbStub *currentLongTransationFor(const OdDbBaseDatabase *pDb) const = 0;
};

#define OdGiIndirectEntityDataForLongTransactionPtr(base) static_cast<OdGiIndirectEntityDataForLongTransaction*>(base)

/** Description:
    This protocol extension interface adds ability to access database entities data indirectly, using
    hardcoded interfaces.
    Remarks:
    This extension is necessary to make Gs more close to Database information. It may have different
    implementations for different databases.

    Library:
    TD_Gi 
    {group:OdGi_Classes} 
*/
class ODGI_EXPORT OdGiIndirectEntityAccessor : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdGiIndirectEntityAccessor);

  enum ProcType
  {
    kIsDefault,
    kIsLayout,
    kIsViewport,
    kIsHatch,
    kIsBlock,
    kIsBlockRef,
    kIsMInsert,
    kIsAttributeDef,
    kIsSortents,
    kIsLongTransaction,
    // @@@mark_br
    kIsAttribute,
    kIsDimension,
    kIsRay,
    kIsUnderlayReference,
    kIsXline,
    // @@@mark_br_
    kIsValidBlockRef,
    kIsSmallBlockRef,
    kIsExternalBlockRef,
    kIsXrefNotFound,
    kIsForceViewportDependence,
    kIsExtent,
    kIsBvModeFaded,
    kIsPdfRef,
    kIsSLine,
    kIsSPoint,
    kIsSLwPLine
  };

  /** Description:
    Returns true if specified RxObject is kind of specified type.
  */
  virtual bool isKindOfType(const OdRxObject *pObj, ProcType type) const = 0;
  virtual ProcType testProcType(const OdRxObject *pObj) const = 0;

  /** Description:
    Returns entity data accessing interface.
  */
  virtual OdGiIndirectEntityDataBasePtr getIndirectDataAccessor(const OdRxObject *pObj, ProcType type) const = 0;

  class DatabaseUnloadReactor
  {
    public:
      virtual ~DatabaseUnloadReactor() { }
      virtual void goodbye(const OdDbBaseDatabase* pDb) = 0;
  };
  virtual OdRxObjectPtr addDatabaseUnloadReactor(OdDbBaseDatabase* pDb, OdRxObject *pPrevReactor, DatabaseUnloadReactor *pReactorRedirect) const = 0;
  virtual void removeDatabaseUnloadReactor(OdDbBaseDatabase* pDb, OdRxObject *pReactor) const = 0;

  // @@@mark_br
  virtual void setMultiThreadedMode(OdDbBaseDatabase* pDb, int nThreads) const = 0;
  virtual int numActiveTransactions(OdDbBaseDatabase* pDb) const = 0;
  virtual bool isUndoing(OdDbBaseDatabase* pDb) const = 0;
  virtual OdDbStub* getModelSpaceId(OdDbBaseDatabase* pDb) const = 0;
  virtual OdDbStub* getPaperSpaceId(OdDbBaseDatabase* pDb) const = 0;
  virtual OdDbStub* currentLayoutId(OdDbBaseDatabase* pDb) const = 0;
  virtual OdGiDrawablePtr openErased(OdDbStub* id) const = 0;
  virtual bool isAProxy(OdGiDrawable* pDrw) const = 0;
  // @@@mark_br_
};

typedef OdSmartPtr<OdGiIndirectEntityAccessor> OdGiIndirectEntityAccessorPtr;

#include "../TD_PackPop.h"

#endif
