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


#ifndef __OD_DB_UNDERLAY_HOST__
#define __OD_DB_UNDERLAY_HOST__

#include "TD_PackPush.h"

#include "Gi/GiRasterImage.h"
#include "DbDatabase.h"
#include "DbEntity.h"

class OdGePoint2d;
class OdUnderlayLayer;

const int kItemVersionNumber = 1;

class OdUnderlayLayerImpl;

class TOOLKIT_EXPORT OdUnderlayLayer
{
public:
    OdUnderlayLayer();
    ~OdUnderlayLayer();

    enum State
    {
      kOff = 0,
      kOn = 1
    };

    OdString name() const;
    State state() const;
    void setName(const OdString& name);
    OdResult setState(State state);

    OdUnderlayLayer& operator =(const OdUnderlayLayer& source);
    OdUnderlayLayer(const OdUnderlayLayer & source);

private:
    OdUnderlayLayerImpl* m_pImpl;
};

struct OdDbUnderlayDrawContext
{
   OdUInt8 contrast; 
   OdUInt8 fade;
   bool monochrome;
   bool adjustColorForBackground;
   OdArray<OdUnderlayLayer> layers;
};

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbUnderlayItem : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbUnderlayItem);

  virtual ~OdDbUnderlayItem() {}

  virtual OdString getName() const = 0;

  virtual OdGiRasterImagePtr getThumbnail() const = 0;
  virtual OdResult getThumbnail(
    BITMAPINFO*& thumbnail) const { return eNotImplementedYet; }

  virtual OdResult getExtents(OdGePoint2d& min, OdGePoint2d& max) const = 0;

  virtual OdDb::UnitsValue getUnits() const = 0;

  virtual bool usingPartialContent() const = 0;

  virtual OdResult draw(
    OdGiWorldDraw* pWorldDraw, 
    OdGiViewportDraw* pViewportDraw, 
    const OdDbUnderlayDrawContext& context) const { return eNotImplementedYet; }

  virtual bool worldDraw(OdGiWorldDraw* pWd, const OdDbUnderlayDrawContext& context) const = 0;

  virtual void viewportDraw(OdGiViewportDraw* pVd, const OdDbUnderlayDrawContext& context, OdUInt8 nTranspancy, const OdGeVector3d& vNormal, const OdGePoint3d& ptInsert, const OdGeScale3d& scale, const double dRotation, OdGiRasterImagePtr& pImage, OdGePoint3d* ptDrawOrigin = NULL, int* pInScreenStatus = NULL, int *pDrawStatus = NULL) const = 0;

  virtual OdGeMatrix3d modelTransform() const = 0;

  virtual OdResult getOsnapPoints(const OdGeMatrix3d& modelToWorld,
                                  OdDb::OsnapMode     osnapMode,
                                  OdGsMarker            gsSelectionMark,
                                  const OdGePoint3d&  pickPoint,
                                  const OdGePoint3d&  lastPoint,
                                  const OdGeMatrix3d& viewXform,
                                  const OdGeMatrix3d& ucs,
                                  OdGePoint3dArray&   snapPoints,
                                  OdIntArray&         geomIds) const = 0;

  virtual OdDbEntityPtr getSubEntityAtGsMarker(const OdGeMatrix3d& modelToWorld, OdGsMarker gsSelectionMark) const = 0;

  virtual OdResult intersectWith(const OdGeMatrix3d& modelToWorld,
                                 const OdDbEntity* pEnt,
                                 OdDb::Intersect intType,
                                 const OdGePlane* projPlane,
                                 OdGePoint3dArray& points,
                                 OdGsMarker thisGsMarker,
                                 OdGsMarker otherGsMarker) const = 0;

  virtual OdUInt32 underlayLayerCount() const { return 0; }
  virtual OdResult getUnderlayLayer(int /*idx*/, OdUnderlayLayer& /*layer*/) const { return Oda::eNotImplemented; }

  virtual OdDbDatabase* getDatabase() const { return NULL; }
  
  virtual void setIsForceRegen(bool bForceRegen) {};

  int version() const;
};

typedef OdSmartPtr<OdDbUnderlayItem> OdDbUnderlayItemPtr;


typedef bool (*GetPasswordFunPtr)(const OdString& path, bool bUser, OdString& password);
/** Description:

    Set a callback function to show a password input dialog for pdf documents loading.
    If pFun is NULL or do not call this function, it will show the default password input dialog in AppServices which is mostly used for DWG documents.
*/
extern "C" __declspec(dllexport) void odSetPdfCallBackGetPasswordFun(GetPasswordFunPtr pFun);

/** Description:

    Set a callback function to show a password input dialog for dwf documents loading.
    If pFun is NULL or do not call this function, it will show the default password input dialog in AppServices which is mostly used for DWG documents.
*/
extern "C" __declspec(dllexport) void odSetDwfCallBackGetPasswordFun(GetPasswordFunPtr pFun);


/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbUnderlayFile : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbUnderlayFile);

  virtual ~OdDbUnderlayFile() {}

  virtual int getItemCount() const = 0;
  virtual OdDbUnderlayItemPtr getItem(int i) const = 0;
  virtual OdDbUnderlayItemPtr getItem(OdString name) const = 0;
  virtual OdResult getItem(int i, OdDbUnderlayItem*& pItem) const = 0;
  virtual OdResult getItem(const OdChar* name, OdDbUnderlayItem*& pItem) const = 0;
};

typedef OdSmartPtr<OdDbUnderlayFile> OdDbUnderlayFilePtr;

// Instance of this PE should be registered for each OdDbUnderlayDefinition inheritant


/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbUnderlayHostPE : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbUnderlayHostPE);

  OdDbUnderlayHostPE();

  virtual OdResult load(OdString path, OdString password, OdDbUnderlayFilePtr& result) = 0;
  virtual OdResult getFile(const OdChar* fullPath, const wchar_t* password, OdDbUnderlayFile*& pFile) const = 0;
};

typedef OdSmartPtr<OdDbUnderlayHostPE> OdDbUnderlayHostPEPtr;
class IGcReadStream;
class TOOLKIT_EXPORT OdDbUnderlayHost
{
public:
	OdDbUnderlayHost();
     virtual OdResult getFile(
                                const OdChar* fullPath, 
                                const wchar_t* password, 
                                OdDbUnderlayFile*& pFile) const = 0;
    virtual OdResult getFile(
                                IGcReadStream* pFileStream,
                                const wchar_t* password, 
                                OdDbUnderlayFile*& pFile) const = 0;

   static void getAdjustedColor(
                               OdGeVector3d& rgbResult, 
                               const OdGeVector3d& rgbInputColor, 
                               const OdGeVector3d& rgbCurrentBackgroundColor, 
                               const OdGeVector3d& hslFadedContrastColor,
                               const OdDbUnderlayDrawContext& drawContext);
protected:
    ///<summary>Destructor.</summary>
    virtual ~OdDbUnderlayHost() = 0;
};

// DGNUnderlay extensions
#include "DbDgnUnderlayHost.h"

TOOLKIT_EXPORT OdDbUnderlayHost* oddbGetCurrentDwfHost();
TOOLKIT_EXPORT OdDbUnderlayHost* oddbSetCurrentDwfHost(OdDbUnderlayHost* pHost);

//TOOLKIT_EXPORT OdDbUnderlayHost* oddbGetCurrentPdfHost();
//TOOLKIT_EXPORT OdDbUnderlayHost* oddbSetCurrentPdfHost(OdDbUnderlayHost* pHost);

TOOLKIT_EXPORT OdDbUnderlayHost* oddbGetCurrentDgnHost();
TOOLKIT_EXPORT OdDbUnderlayHost* oddbSetCurrentDgnHost(OdDbUnderlayHost* pHost);

#include "TD_PackPop.h"

#endif // __OD_DB_UNDERLAY_HOST__
