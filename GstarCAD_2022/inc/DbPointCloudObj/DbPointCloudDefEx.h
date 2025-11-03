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
//   Teigha(R) Copyright (C) 2002-2018 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef _ODDBPOINTCLOUDDEFEX_INCLUDED_
#define _ODDBPOINTCLOUDDEFEX_INCLUDED_


#include "DbPointCloudObjExports.h"
#include "../StringArray.h"
#include "../TD_PackPush.h"

#include "../DbObject.h"

/** <group OdDbPointCloud_Classes>
*/
class DBPOINTCLOUDOBJ_EXPORT OdDbPointCloudDefEx : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS( OdDbPointCloudDefEx );

  enum PropState
  {
    kNone = -1,
    kSome = 0,
    kAll = 1
  };

  enum Property
  {
    kColor = 1,
    kIntensity = 2,
    kClassification = 3,
    kNormal = 4,
    kSegmentation = 5,
    kGeoGraphic = 6
  };

  /** \details
  Default constructor. Constructs an empty OdDbPointCloudDefEx object.
  */
  OdDbPointCloudDefEx();

  virtual ~OdDbPointCloudDefEx(){}
  /** \details
    Returns the name of the external file containing the point cloud ex data (.rcp or .rcs) for this PointCloudEx Definition object (as it is stored in file).
    
    \remarks
    This PointCloudDefEx object must be open for reading.
  */
  const OdChar* sourceFileName() const;

  /** \details
    Returns Acad::eOk if erasing is successful. If this function returns anything other than Acad::eOk, then the erase operation is immediately terminated. 
    
	\remarks
    Called from within erase() before anything else is done.
  */
  virtual OdResult subErase( OdBool erasing );

  /** \details
    Sets the name of the external file containing the point cloud ex data (.rcp or .rcs) for this PointCloudEx Definition object (as it is stored in file).
    
    \returns
    Returns eOk if the file is accessible or eInvalidInput otherwise.
  */
  OdResult setSourceFileName(const OdChar* pPathName);

  /** \details
  Returns the path name of the actual point cloud file being currently used for this PointCloudEx Definition object.

  \remarks
  This PointCloudDef object must be open for reading.
  */
  const OdChar * activeFileName() const;


  /** \details
  Returns the path name of the actual point cloud file being currently used for this PointCloudEx Definition object.

  \returns
  Returns eOk if the file is accessible or eInvalidInput otherwise.
  */
  OdResult setActiveFileName( const OdChar * pPathName );

  /** \details
    Returns the type of the source file containing the point cloud data for this PointCloudEx Definition object (as it is stored in file).

    \remarks
    This PointCloudDefEx object must be open for reading.
  */
  const OdChar * fileType() const;

  // Helper functions to access Point Cloud Ex Definition dictionary
  /** \details
    Returns PointCloudEx Dictionary ID. Creates the dictionary, if one is not already present, in the specified OdDbDatabase instance.

    \param Db [in]  The database.
  */
  static OdDbObjectId createPointCloudExDictionary(OdDbDatabase *pDb);

  static OdResult createPointCloudExDictionary(OdDbDatabase* pDb, OdDbObjectId& dictId);
  
  /** \details
    Returns the Object ID of the point cloud dictionary in the specified OdDbDatabase instance.
    \param Db [in]  The database.  
  */
  static OdDbObjectId pointCloudExDictionary(const OdDbDatabase *pDb);

  /** \details
    
  */
  static OdDbDictionary* getPointCloudExDictionary( OdDbPointCloudDefEx *pDefEx );

  /** \details
    Returns true if and only if the point cloud file for this PointCloudEx definition object is loaded.
  */
  OdBool  isLoaded() const;

  /** \details

  */
  OdResult load();

  /** \details

  */
  OdResult unload();

  /** \details
    Returns the number of OdDbPointCloudEx entities in the current drawing that are dependent upon this object.
    
    \param pbLocked [in]  If it's non-zero, then this function will set the true value at that pointer if any dependent entities reside on locked layers, or set false otherwise.
  */
  int entityCount(OdBool *pbLocked) const;

  /** \details
    Returns the total number of points of this OdDbPointCloudDefEx object.
  */
  OdUInt64 totalPointsCount() const;

  /** \details
    Returns the default height of this OdDbPointCloudDefEx object.
  */
  double defaultHeight() const;

  /** \details
    Returns the default length of this OdDbPointCloudDefEx object.
  */
  double defaultLength() const;

  /** \details
    Returns the default width of this OdDbPointCloudDefEx object.
  */
  double defaultWidth() const;

  /** \details
    Calculates the extents of this OdDbPointCloudDefEx object.

    \returns
    Returns eOk if the extents are valid or eInvalidExtents otherwise.
  */
  OdResult extents( OdGeExtents3d &exts ) const;

  OdDbExtents  extents() const;

  /** \details  
  */
  int totalRegionsCount() const;

  /** \details

  */
  int totalScansCount() const;

  /** \details

  */
  const OdChar* coordinateSystemName() const;

  /** \details

  */
  const OdChar* getRcsFilePath( const OdString &guid) const;

  /** \details
  NOT INPLEMENTED
  */
  void getAllRcsFilePaths( OdStringArray &list ) const;

  /** \details
  NOT INPLEMENTED
  */
  PropState hasProperty( Property prop ) const;

  /** \details
  NOT INPLEMENTED
  */
  OdResult createThumbnailBitmap( BITMAPINFO*& pBmpInfo, int width, int height ) const;



  // File IO
  virtual OdResult  dwgInFields( OdDbDwgFiler * );
  virtual OdResult  dwgOutFields( OdDbDwgFiler * ) const;
  virtual OdResult  dxfInFields( OdDbDxfFiler * );
  virtual OdResult  dxfOutFields( OdDbDxfFiler * ) const;

  static int classVersion();

};

typedef OdSmartPtr<OdDbPointCloudDefEx> OdDbPointCloudDefExPtr;

/** <group OdDbPointCloud_Classes>
*/
class  DBPOINTCLOUDOBJ_EXPORT OdDbPointCloudDefReactorEx : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS( OdDbPointCloudDefReactorEx );
  OdDbPointCloudDefReactorEx( );

  static int classVersion();

  // File IO
  virtual OdResult  dwgInFields( OdDbDwgFiler * );
  virtual OdResult  dwgOutFields( OdDbDwgFiler * ) const;
  virtual OdResult  dxfInFields( OdDbDxfFiler * );
  virtual OdResult  dxfOutFields( OdDbDxfFiler * ) const;

  // Notifications
  virtual void erased( OdDbObject const *, OdBool );   // not implemented
  virtual void modified( OdDbObject const * );

  static OdBool isEnabled();
  static void setEnable( OdBool );
private:
  static OdBool m_bEnabled;
};

typedef OdSmartPtr<OdDbPointCloudDefReactorEx> OdDbPointCloudDefReactorExPtr;

#include "../TD_PackPop.h"

#endif //_ODDBPOINTCLOUDDEFEX_INCLUDED_
