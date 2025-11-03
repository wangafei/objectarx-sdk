/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2016, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2002-2016 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef _OD_DB_POINTCLOUDEX_
#define _OD_DB_POINTCLOUDEX_

#include "DbPointCloudObjExports.h"
#include "DbPointCloudCropping.h"
#include "DbPointCloudIntensityStyle.h"
#include "../TD_PackPush.h"

#include "../DbEntity.h"
#include "DbPointCloudHostPE.h"

class IOdDbPointCloudAttributeFilter;
class IOdDbPointCloudSpatialFilter;
class OdDbPointCloudCropStateManager;
class OdPointCloudExtractedCylinder;
class IOdDbPointCloudDataBuffer;
class OdDbPointCloudItem;
/** \details
This class represents PointCloudEx entities in an OdDbDatabase instance.

Library: GcDbPointCloudObj

<group OdDbPointCloud_Classes>
*/
class DBPOINTCLOUDOBJ_EXPORT OdDbPointCloudEx : public OdDbEntity
{
public:

  ODDB_DECLARE_MEMBERS( OdDbPointCloudEx );

  enum DispOptionOutOfRange {
    kUseMinMaxColors = 0,
    kUseRGBScanColors,
    kHidePoints
  };

  enum PointCloudOSnapMode {
    kOsModePNod = 0,
    kOsModePNea = 1,
    kOsModePPer = 2,
    kOsModePEdgeNea = 3,
    kOsModePEdgePer = 4,
    kOsModePInt = 5,
    kOsModePCL = 6,
    kOsModePCorner = 7
  };

  /** \details
    Default constructor.
  */
  OdDbPointCloudEx();

  /** \details
    Destructor.
  */
  ~OdDbPointCloudEx() {}

  /** \details
  Returns the Object ID of the OdDbPointCloudDefEx object associated with this point cloud ex entity.
  */
  OdDbObjectId pointCloudDefExId() const;

  /** \details
  Sets the Object ID of the OdDbPointCloudDefEx object associated with this point cloud ex entity.

  \param pointCloudDefExId [in]  Object ID of the point cloud ex to be associated with this point cloud ex entity.
  */
  void setPointCloudDefExId( const OdDbObjectId pointCloudDefExId );  

  /** \details
  Returns the Object ID of the OdDbPointCloudDefReactorEx object associated with this point cloud ex entity.

  \remarks
  Each OdDbPointCloudEx object must have an OdDbPointCloudDefReactorEx associated with the OdDbPointCloudDefEx object it is using.

  */
  OdDbObjectId reactorId() const;

  virtual OdResult subGetClassID(CLSID* pClsid) const;

  /** \details
  Sets the Object ID of the OdDbPointCloudDefReactorEx object associated with this point cloud entity.

  \param pointCloudDefReactorExId [in]  Object ID of a reactor for this point cloud ex entity.

  \remarks
  Each OdDbPointCloudEx object must have an OdDbPointCloudDefReactorEx associated with the OdDbPointCloudDefEx object it is using.
  */
  void setReactorId( const OdDbObjectId pointCloudDefReactorExId );

  /** \details
  Returns true if the point cloud entity ex is locked or false otherwise.
  */
  bool locked() const;

  /** \details
  Sets the point cloud entity ex to be locked.
  */
  void setLocked( bool bLocked );

  /** \details
  
  */
  double scale() const;

  /** \details
  
  */
  OdResult setScale( double scale );

  /** \details

  */
  double rotation() const;

  /** \details

  */
  OdResult setRotation( double newRotation );

  /** \details

  */
  OdGePoint3d location() const;

  /** \details

  */
  void setLocation( OdGePoint3d newLocation );

  /** \details

  */
  void getNativeCloudExtent( OdGeExtents3d extents ) const;

  /** \details

  */
  unsigned int getVisiblePointCount( OdGeExtents3d extents );

  /** \details

  */
  unsigned int getLoadedVisiblePointCount( OdGeExtents3d extents );

  /** \details

  */
  unsigned int getDisplayedVisiblePointCount( OdGeExtents3d extents );

  /** \details

  */
  bool getActiveFileName( OdString& fileName ) const;

  /** \details

  */
  bool setActiveFileName( const OdChar* strActiveFileName );

  /** \details

  */
  OdString getPointCloudName() const;

  /** \details

  */
  OdResult setPointCloudName( const OdString& name );

  //

  /** \details

  */
  OdDbPointCloudCropping* getConstPointCloudCropping( int index );

  /** \details

  */
  OdDbPointCloudCropping const* getConstPointCloudCropping( int index ) const;

  /** \details

  */
  void addCroppingBoundary( OdDbPointCloudCropping const &boundary );

  /** \details
  
  */
  OdResult clearCropping();

  /** \details

  */
  OdResult removeLastCropping();

  /** \details

  */
  bool getCroppingInvert() const;

  /** \details

  */
  OdResult setCroppingInvert( bool bInvert );

  /** \details

  */
  OdResult setInCreatingCroppingMode( bool bCreating );

  /** \details
  Returns true only if this point cloud ex entity is displayed as clipped.
  */
  bool showCropping() const;

  /** \details
  Set whether this point cloud ex entity is displayed as clipped.

  \param cropping [in]  Value for option.

  \note
  Returns eOk.
  */
  OdResult setShowCropping( bool bShowCropping );

  //

  enum StylizationType
  {
    kTrueColor = 1,
    kSingleColor,
    kNormalRamp,
    kHeightRamp,
    kIntensityRamp,
    kClassificationRamp
  };

  /** \details

  */
  StylizationType stylizationType() const;

  /** \details

  */
  OdResult setStylizationType( StylizationType type );

  //

  /** \details

  */
  OdString getCurrentColorScheme() const;

  /** \details

  */
  OdResult setCurrentColorScheme( const OdString &guid );

  /** \details
  test 
  */
  OdString getColorSchemeForStylization( StylizationType type ) const;

  /** \details
  test
  */
  OdResult setColorSchemeForStylization( const OdString &guid, StylizationType type );

  /** \details

  */
  bool showIntensityAsGradient() const;

  /** \details

  */
  void setShowIntensityAsGradient( bool bShowAsGradient );

  /** \details

  */
  OdInt32 minIntensity() const;

  /** \details

  */
  OdInt32 maxIntensity() const;

  /** \details

  */
  OdResult setMinMaxIntensity( OdInt32 min, OdInt32 max );

  /** \details

  */
  DispOptionOutOfRange intensityOutOfRangeBehavior() const;

  /** \details

  */
  void setIntensityOutOfRangeBehavior( DispOptionOutOfRange displayOption );

  /** \details

  */
  bool showElevationAsGradient() const;

  /** \details

  */
  void setShowElevationAsGradient( bool bShowAsGradient );

  /** \details

  */
  double minElevation() const;

  /** \details

  */
  double maxElevation() const;

  /** \details

  */
  OdResult setMinMaxElevation( double min, double max );

  /** \details

  */
  bool elevationApplyToFixedRange() const;

  /** \details

  */
  void setElevationApplyToFixedRange( bool bFixedRange );

  /** \details

  */
  DispOptionOutOfRange elevationOutOfRangeBehavior() const;

  /** \details

  */
  void setElevationOutOfRangeBehavior( DispOptionOutOfRange displayOption );

  /** \details

  */
  OdResult  addAttributeFilter( IOdDbPointCloudAttributeFilter* pFilter );

  /** \details

  */
  OdResult addSpatialFilter( IOdDbPointCloudSpatialFilter* pFilter );

  /** \details

  */
  void  clearAttributeFilters();

  /** \details

  */
  void applyGeoLocation( bool useDrawingGeo = false, const OdString& geoCS = L"" );

  /** \details

  */
  void clearGeoLocation();

  /** \details

  */
  void clearSpatialFilters();

  /** \details
  Returns Acad::eOk if successful.
  \remarks
  Copy the contents of the "other" parameter into this messaged object, whenever feasible.
  */
  virtual OdResult copyFrom( const OdRxObject* pObj );

  /** \details

  */
  OdDbPointCloudCropStateManager* cropStatesManager();

  /** \details

  */
  OdResult decomposeForSave( OdDb::DwgVersion ver, OdDbObject*& replaceObj, OdDbObjectId& replaceId, OdBool& exchangeXData );

  /** \details

  */
  OdResult detectPointBelonger( const OdGePoint3d& ptInWCS, OdString& scanGuid, OdInt16& segmentIndex ) const;

  /** \details
  The function is called when a drag operation involving this entity is starting, ending, or aborting
  */
  virtual void dragStatus( const OdDb::DragStat status );

  /** \details

 */
  OdDbPointCloudItem* findRegionItem( int regionId );

  /** \details

  */
  OdDbPointCloudItem* findScanItem( const OdString& scanGuid );

  /** \details

  */
  bool geolocate() const;

  /** \details

  */
  OdResult getCandidatePlane( const class CPoint& pt, OdGePlane &result, double &distToEdge, double &objWidth, double &objHeight, void*& context ) const;

  /** \details
  Returns the number of cropping boundaries that are set on this entity.
  */
  int getCroppingCount() const;

  /** \details

  */
  OdResult getCustomOsnapInfo( PointCloudOSnapMode snapMode,
    const OdGePoint3d& pickPoint,
    const OdGePoint3d& lastPoint,
    const OdGeMatrix3d& viewXform,
    OdArray<OdGePoint3d>& snapPoints );

  /** \details

   */
  OdResult getCylinderAt( const OdGeMatrix3d& viewXform, const OdGePoint3d& pickPt, OdGePoint3d& origin, OdGeVector3d& axis, double& height, double& radius );

  /** \details

   */
  OdResult getCylinderAt( const OdGeMatrix3d& viewXform, const OdGePoint3d& pickPt, OdPointCloudExtractedCylinder& extractedCylinder );

  /** \details

   */
  OdResult getEstimatedPointCountByPrecision( unsigned long long &pointCount, double distPrecision, IOdDbPointCloudSpatialFilter* pSpatialFilter = NULL, IOdDbPointCloudAttributeFilter* pAttributeFilter = NULL ) const;

  /** \details

   */
  OdResult getMinDistPrecision( double& minDistPrecision ) const;

  /** \details

   */
  bool  getPlaneBoundaryAt( const OdGeMatrix3d& viewXform, const OdGePoint3d& pickPt, OdGePoint3dArray& arrPlaneVertices );

  /** \details

   */
  bool  getPlaneOrPointAt( const OdGeMatrix3d & viewXform, const OdGePoint3d & pickPt, OdArray<OdGePoint3d> & points );

  /** \details
   Returns the cropping boudary at the given index. Returns NULL if index is out of range of (0 ~ cropping count).
   \remarks
   Returns a cropping boundary by index, for editing. Requires that the AcDbPointCloudEx be open for writing.
   */
  OdDbPointCloudCropping* getPointCloudCropping( int index );

  /** \details
   Returns the cropping boudary at the given index. Returns NULL if index is out of range of (0 ~ cropping count).
   \remark
   Returns a cropping boundary index for read only. Requires that the AcDbPointCloudEx be open for reading.
   */
  const OdDbPointCloudCropping* getPointCloudCroppingConst( int index ) const;

  /** \details

   */
  const OdPointCloudItemArray*    getPointCloudDataList() const;

  /** \details

  */
  OdResult getPointDataByPointCount( IOdDbPointCloudDataBuffer*& pointData, OdInt32 pointCount,
    IOdDbPointCloudSpatialFilter* pSpatialFilter, IOdDbPointCloudAttributeFilter* pAttributeFilter, OdInt32 dataTypes, OdInt32 maxPointLimitation ) const;

  /** \details

 */
  OdResult getPointDataByPointCount( IOdDbPointCloudDataBuffer*& pointData, OdInt32 pointCount, const OdArray<OdString>& arrScanGuids, IOdDbPointCloudSpatialFilter* pSpatialFilter,
    IOdDbPointCloudAttributeFilter* pAttributeFilter, OdInt32 dataTypes, OdInt32 maxPointLimitation ) const;

  /** \details

 */
  OdResult getPointDataByPrecision( IOdDbPointCloudDataBuffer*& pointData, double distPrecision, IOdDbPointCloudSpatialFilter* pSpatialFilter = NULL,
    IOdDbPointCloudAttributeFilter* pAttributeFilter = NULL, OdInt32 dataTypes = 0, OdInt32 maxPointLimitation = 1000000uLL ) const;

  /** \details

  */
  void setRegionVisibility( int regionId, bool bVisible );

  /** \details

  */
  void setScanVisibility( const OdString& scanGuid, bool bVisible );

  virtual void getEcs(OdGeMatrix3d& retVal) const;
  OdResult subGetGeomExtents(OdDbExtents& ext) const;


  void objectToWorldMatrix(OdGeMatrix3d& mat) const;

  OdResult subTransformBy( const OdGeMatrix3d& xform );
  //bool subWorldDraw( OdGiWorldDraw* pWd ) const;
  virtual OdBool subWorldDraw(OdGiWorldDraw* pWd);
  virtual void subViewportDraw( OdGiViewportDraw* pVd );

  // File IO
  virtual OdResult  dwgInFields( OdDbDwgFiler * );
  virtual OdResult  dwgOutFields( OdDbDwgFiler * ) const;
  virtual OdResult  dxfInFields( OdDbDxfFiler * );
  virtual OdResult  dxfOutFields( OdDbDxfFiler * ) const;

};

typedef OdSmartPtr<OdDbPointCloudEx> OdDbPointCloudExPtr;

#include "../TD_PackPop.h"


#endif //_OD_DB_POINTCLOUDEX_
