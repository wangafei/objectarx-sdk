/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2002-2019, Open Design Alliance (the "Alliance"). 
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
//   This application incorporates Open Design Alliance software pursuant to a license 
//   agreement with Open Design Alliance.
//   Open Design Alliance Copyright (C) 2002-2019 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

// RxRcsFileServices.h - interface of module that handles .rcs files

#ifndef __OD_RCSFILESERVICES_MODULE__
#define __OD_RCSFILESERVICES_MODULE__

#include "RxModule.h"
#include "RootExport.h"

#include "TD_PackPush.h"
#include "SharedPtr.h"
#include "Ge/GePoint3d.h"
#include "Ge/GePoint3dArray.h"
#include "CmEntityColorArray.h"
#include "Ge/GeVector3d.h"
#include "Ge/GeMatrix3d.h"
#include "Ge/GeExtents3d.h"
#include "StringArray.h"

#include "Gi/GiViewport.h"

#define STL_USING_LIST
#include "OdaSTL.h"

/** <group OdRcs_Classes>
  \details
  This class is an interface class for the points data iterator that enables
  getting points from a voxel.

  \remarks
  Corresponding C++ library: RcsFileServices.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcsPointDataIterator
{
public:

  /** \details
    Default destructor for objects of the OdRcsPointDataIterator class.
  */
  virtual ~OdRcsPointDataIterator(){}

  /** \details
    Moves the current position to the beginning of the points data within the
    current voxel.
  */
  virtual void start() = 0;  
  
  /** \details
    Returns true if and only if the traversal by this iterator object is
    complete.

    \returns
    True if the traversal by this iterator object is complete; false otherwise.
  */
  virtual bool done() const = 0;

  /** \details
    Fills the coordinates and color arrays. The iterator object steps forward.

    \param requiredQty [in]  Required number of points to obtain.
    \param points     [out]  Points coordinates array to be filled.
    \param colorArray [out]  Points color array to be filled.

    \returns
    Returns the actual number of points obtained.
  */
  virtual OdUInt64 getPoints(OdGePoint3dArray& points, OdCmEntityColorArray& colorArray, 
    OdUInt64 requiredQty) = 0;

  /** \details
    Fills the coordinates and color arrays for LIDAR data. The iterator object
    steps forward.

    \param requiredQty [in]  Required number of points to obtain.
    \param points     [out]  Points coordinates array to be filled.
    \param colorArray [out]  Points color array to be filled.

    \remarks
    The method should be used instead of OdRcsPointDataIterator::getPoints() to
    obtain coordinates and colors if the OdRcsFileReader::isLidarData() call
    returns true.

    \returns
    Returns the actual number of points obtained.
  */
  virtual OdUInt64 getLidarPoints(OdGePoint3dArray& points, OdCmEntityColorArray& colorArray, 
    OdUInt64 requiredQty) = 0;
};

/** \details
  Smart pointer to objects of the OdRcsPointDataIterator class.
*/
typedef OdSharedPtr<OdRcsPointDataIterator> OdRcsPointDataIteratorPtr;

/** <group OdRcs_Classes>
  \details
  This is an interface class for the voxel cube containing points.

  \remarks
  Corresponding C++ library: RcsFileServices.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcsVoxel
{
public:

  /** \details
    Default destructor for objects of the OdRcsVoxel class.
  */
  virtual ~OdRcsVoxel(){}

  /** \details
    Creates a new points data iterator.

    \returns
    The smart pointer to the object of the OdRcsPointDataIterator class.
  */
  virtual OdRcsPointDataIteratorPtr newPointDataIterator() const = 0;

  /** \details
    Loads the visible points of this voxel corresponding to the specified level
    of detail (LOD).

    \param LOD [in] The LOD.
  */
  virtual void loadPointsForLOD(OdUInt32 LOD) = 0;

  /** \details
    Loads the visible LIDAR points of this voxel corresponding to the specified
    level of detail (LOD).

    \param LOD [in] The LOD.
  */
  virtual void loadLidarPointsForLOD(OdUInt32 LOD) = 0;

  /** \details
    Gets the extents of the voxel.

    \returns
    The extents of the voxel.
  */
  virtual OdGeExtents3d getBox1() const = 0;

  /** \details
    Gets the number of points within the currant voxel.

    \returns
    Number of points as an OdUInt64 value.
  */
  virtual OdUInt64 getPointsQty() const = 0;
};

/** \details
  Smart pointer to objects of the OdRcsVoxel class.
*/
typedef OdSharedPtr<OdRcsVoxel> OdRcsVoxelPtr;

/** <group OdRcs_Classes>
  \details
  This is an interface class for the voxel data iterator that enables getting
  voxels from an .rcs file.

  \remarks
  Corresponding C++ library: RcsFileServices.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcsVoxelDataIterator
{
public:

  /** \details
    Default destructor for objects of the OdRcsVoxelDataIterator class.
  */
  virtual ~OdRcsVoxelDataIterator(){}

  /** \details
    Creates a new OdRcsVoxel object and fills it with the voxel data that is
    currently pointed at by the voxel data iterator.

    \returns
    The pointer to the current voxel.

    \remarks
     The iterator object steps forward.
  */
  virtual OdRcsVoxelPtr getVoxel() = 0;

  /** \details
    Moves the current position to the beginning of the voxel data.
  */
  virtual void start() = 0;

  /** details
    Indicates whether the traversal by this iterator object is complete.

    \returns
    True if the traversal by this iterator object is complete; false otherwise.
  */
  virtual bool done() const = 0;
};

/** \details
  Smart pointer to objects of the OdRcsVoxelDataIterator class.
*/
typedef OdSharedPtr<OdRcsVoxelDataIterator> OdRcsVoxelDataIteratorPtr;

/** <group OdRcs_Classes>
  \details
  This is the interface class for point cloud data reader that enables getting
  information from an .rcs file.

  \remarks
  Corresponding C++ library: RcsFileServices.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcsFileReader
{
public:  

  /** \details
    Default destructor for objects of the OdRcsVoxelDataIterator class.
  */
  virtual ~OdRcsFileReader(){}

  /** \details
    Loads all voxels data from the file into an array.

    \param voxels [out] Array of voxels to be filled with voxel data.
  */
  virtual void loadAllVoxels(OdArray<OdRcsVoxelPtr>& voxels) = 0;

  /** \details
    Gets the amount of voxels in the file.

    \returns
    The amount of voxels as an OdUInt64 value.
  */
  virtual OdUInt64 getAmountOfVoxels() = 0;

  /** \details
    Creates a new voxel data iterator.

    \returns
    Smart pointer to the voxel data iterator.
  */
  virtual OdRcsVoxelDataIteratorPtr newVoxelDataIterator() const = 0;

  /** \details
    Gets the translation vector from the file header.

    \returns
    Translation vector.
  */
  virtual OdGeVector3d getTranslation() const = 0;

  /** \details
    Gets the rotation vector from the file header. Each of this vector's
    coordinates is a rotation angle around the corresponding axis.

    \returns
    Rotation vector.
  */
  virtual OdGeVector3d getRotation() const = 0;

  /** \details
    Gets the scale vector from the file header.

    \returns
    Scale vector.
  */
  virtual OdGeVector3d getScale() const = 0;

  /** \details
    Forms the complete transformation matrix which integrates translation,
    rotation and scale.

    \returns
    Transformation matrix.
  */
  virtual OdGeMatrix3d getTransformMatrix() const = 0;

  /** \details
    Gets the hasRGB flag value from the file header.

    \returns
    The value of the hasRGB flag.
  */
  virtual bool hasRGB() const = 0;
  
  /** \details
    Gets the hasNormals flag value from the file header.

    \returns
    The value of the hasNormals flag.
  */
  virtual bool hasNormals() const = 0;
  
  /** \details
    Gets the hasIntensity flag value from the file header.

    \returns
    The value of the hasIntensity flag.
  */
  virtual bool hasIntensity() const = 0;
  
  /** \details
    Gets the scan ID string.

    \returns
    The scan ID string.
  */
  virtual OdString getScanIdString() const = 0;

  /** \details
    Gets the extents of the point cloud from the file header.

    \returns
    The extents.
  */
  virtual OdGeExtents3d getExtents() const = 0;

  /** \details
    Returns the transformed extents.
  */
  /** \details
    Gets the extents of the point cloud and transforms it by the transformation
    matrix.

    \returns
    The transformed extents.
  */
  virtual OdGeExtents3d getTransformedExtents() const = 0;

  /** \details
    Indicates whether the file contains LIDAR data.

    \returns
    True if the file contains LIDAR data; false otherwise.
  */
  virtual bool isLidarData() const = 0;
};

/** \details
  Smart pointer to objects of the OdRcsFileReader class.
*/
typedef OdSharedPtr<OdRcsFileReader> OdRcsFileReaderPtr;

/** <group OdRcs_Classes>
  \details
  This is an interface class to iterate through the voxels visible in the
  current viewport.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcsVisibleVoxelsIterator
{
public:

  /** \details
    Default destructor for objects of the OdRcsVisibleVoxelsIterator class.
  */
  virtual ~OdRcsVisibleVoxelsIterator(){}

  /** \details
    Moves the current iterator position to the visible voxel in the current
    viewport that will be iterated first.
  */
  virtual void start() = 0;

  /** \details
    Pteps the current iterator position to the next visible voxel in the current
    viewport.
  */
  virtual void step() = 0;

  /** details
    Indicates whether the traversal by this iterator object is complete.

    \returns
    True if the traversal by this iterator object is complete; false otherwise.
  */
  virtual bool done() const = 0;

  /** \details
    Loads the voxel data from the voxel that is currently pointed at by the
    visible voxel data iterator.

    \param coords [out] List of loaded points coordinates for the currenly pointed voxel.
    \param colors [out] List of loaded points colors for the currenly pointed voxel.
    \param numberOfPointsToDraw [out] Total number of visible points to be drawn.

    \returns
    The total number of loaded points.
  */
  virtual OdUInt32 getBuffers(std::list<OdGePoint3dArray>*& coords,
                              std::list<OdCmEntityColorArray>*& colors,
                              OdUInt32& numberOfPointsToDraw) = 0;
};

/** \details
  Smart pointer to objects of the OdRcsVisibleVoxelsIterator class.
*/
typedef OdSharedPtr<OdRcsVisibleVoxelsIterator> OdRcsVisibleVoxelsIteratorPtr;

/** <group OdRcs_Classes>
  \details
  This is an interface class to calculate view-dependent LOD and to process
  visible voxels.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcsDataManager
{
public:

  /** \details
    Default destructor for objects of the OdRcsDataManager class.
  */
  virtual ~OdRcsDataManager(){}

  /** \details
    Gets the pointer to the file reader.

    \returns
    Pointer to the file reader.
 */
  virtual OdRcsFileReaderPtr getFileReader() const = 0;

  /** \details
    Calculates the total number of points in all voxels.

    \returns
    Total number of points as an OdUInt64 value.
 */
  virtual OdUInt64 pointsCount() const = 0;

  /** \details
    Updates the list of visible voxels within a viewport given the parameters.

    \param viewport [in] The viewport.
    \param pointSize [in] The point size that is considered visible.
    \param useExternalTransformToCalcLOD [in] Specifies whether the external transormation matrix is used to calculate the LOD.
    \param globalTransformToCalcLOD [in] Global transformation matrix.
    \param scanTransformToCalcLOD [in] Scan transformation matrix.
  */
  virtual void updateListOfVisibleVoxels(const OdGiViewport& viewport, OdUInt16 pointSize,
    bool useExternalTransformToCalcLOD = false, 
    const OdGeMatrix3d& globalTransformToCalcLOD = OdGeMatrix3d::kIdentity,
    const OdGeMatrix3d& scanTransformToCalcLOD = OdGeMatrix3d::kIdentity) = 0;

  /** \details
    Loads the visible points of all visible voxels for this rcs data manager.
  */
  virtual void loadPointsForVisibleVoxels() = 0;

  /** \details
    Creates a new visible voxels iterator.

    \returns
    Smart pointer to a OdRcsVisibleVoxelsIterator object.
  */
  virtual OdRcsVisibleVoxelsIteratorPtr newVisibleVoxelsIterator() const = 0;
};

/** \details
  Smart pointer to objects of the OdRcsDataManager class.
*/
typedef OdSharedPtr<OdRcsDataManager> OdRcsDataManagerPtr;

/** <group OdRcs_Classes>
  \details
  This is the interface class for reading data from an .rcp file.

  \remarks
  Corresponding C++ library: RcsFileServices.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRcpFileReader
{
public:

  /** \details
    Default destructor for objects of the OdRcpFileReader class.
  */
  virtual ~OdRcpFileReader(){}

  /** \details
    Gets the list of paths for all .rcs files associated with the .rcp file.
    
    \param list [in/out] An array of strings to be filled with paths to the .rcs
                         files.
  */
  virtual void getAllRcsFilePaths( OdStringArray &list ) const = 0;

  /** \details
    Gets the list of relative paths for all .rcs files associated with the .rcp
    file.
    
    \param list [in/out] An array of strings to be filled with relative paths to
                         the .rcs files.
  */
  virtual void getAllRcsRelativeFilePaths( OdStringArray &list ) const = 0;

  /** \details
    Gets the global transformation matrix.

    \returns
    Transformation matrix.
  */
  virtual OdGeMatrix3d getGlobalTransformation() const = 0;

  /** \details
    Gets the scan transformation matrix.

    \returns
    Transformation matrix.
  */
  virtual OdGeMatrix3d getScanTransform(const OdString &guid) const = 0;

  /** \details
    Gets the total regions count.

    \returns
    The number of regions as an OdUInt32 value.
  */
  virtual OdUInt32 getTotalRegionsCount() const = 0;

  /** \details
    Gets the total scans count.

    \returns
    The number of scans as an OdUInt32 value.
  */
  virtual OdUInt32 getTotalScansCount() const = 0;

  /** \details
    Gets the coordinate system name.

    \returns
    The coordinate system name.
  */
  virtual OdString getCoordinateSystemName() const = 0;

  /** \details
    Indicates whether the associated .rcs files contain colors.

    \returns
    1 if all .rcs files associated with the currant .rcp file contains colors.
    0 if at least one .rcs file associated with the currant .rcp file contains colors.
    -1 if no .rcs file associated with the currant .rcp file contain colors.
  */
  virtual OdInt8 hasRGB() const = 0;

  /** \details
    Indicates whether the associated .rcs files contain normals.

    \returns
    1 if all .rcs files associated with the currant .rcp file contains normals.
    0 if at least one .rcs file associated with the currant .rcp file contains normals.
    -1 if no .rcs file associated with the currant .rcp file contain normals.
  */
  virtual OdInt8 hasNormals() const = 0;

  /** \details
    Indicates whether the associated .rcs files contain intensity.

    \returns
    1 if all .rcs files associated with the currant .rcp file contains intensity.
    0 if at least one .rcs file associated with the currant .rcp file contains intensity.
    -1 if no .rcs file associated with the currant .rcp file contain intensity.
  */
  virtual OdInt8 hasIntensity() const = 0;

  /** \details
    Gets the path to an .rcs file specified by a guid.

    \param guid [in] guid of the .rcs file.

    \returns
    Path to the .rcs file.
  */
  virtual OdString getRcsFilePath(const OdString &guid) const = 0;

  /** \details
    Gets the relative path to an .rcs file specified by a guid.

    \param guid [in] guid of the .rcs file.

    \returns
    Relative path to the .rcs file.
  */
  virtual OdString getRcsRelativeFilePath(const OdString &guid) const = 0;

  /** \details
    Gets the total number of points for the point cloud project.

    \returns
    The total number of points as an OdUInt64 value.
  */
  virtual OdUInt64 getTotalAmountOfPoints() const = 0;

  /** \details
    Writes all point cloud project XML data to a specified stream.

    \param s [in/out] A stream to write data to.
  */
  virtual void writeAllXmlDataToStream(OdStreamBuf* s) = 0;

  /** \details
    Gets the full extents of the point cloud project.

    \returns
    The extents of the point cloud project.
  */
  virtual OdGeExtents3d getExtents() const = 0;
};

/** \details
  Smart pointer to objects of the OdRcpFileReader class.
*/
typedef OdSharedPtr<OdRcpFileReader> OdRcpFileReaderPtr;

/** <group OdRx_Classes>
  \details
  This is an interface class for the module that provides loading point cloud
  data from .rcs files.

  \remarks
  Corresponding C++ library: RcsFileServices.
*/
class ODRX_ABSTRACT FIRSTDLL_EXPORT OdRxRcsFileServices : public OdRxModule
{
public:

  /** \details
    Creates a new file reader object and associates it with the point cloud scan
    file (.rcs file) specified by its file path.

    \param filePath [in]  Path to the .rcs file.

    \returns
    The pointer to the OdRcsFileReader object.
  */
  virtual OdRcsFileReaderPtr getRcsFileReader(const OdString& filePath) const = 0;

  /** \details
    Creates a new data manager object for the specified .rcs file, reads the
    header of the .rcs file and loads all voxels from the file.

    \param filePath [in]  Path to the .rcs file.

    \returns
    The pointer to OdRcsDataManager object.
  */
  virtual OdRcsDataManagerPtr getRcsDataManager(const OdString& filePath) const = 0;

  /** \details
    Creates a new file reader object and associates it with the point cloud
    project file (.rcp file) specified by its file path.

    \param filePath [in] Path to the .rcp file.

    \returns
    The pointer to the OdRcpFileReader object.
  */
  virtual OdRcpFileReaderPtr getRcpFileReader(const OdString& filePath) const = 0;
};

/** \details
  Smart pointer to objects of the OdRxRcsFileServices class.
*/
typedef OdSmartPtr<OdRxRcsFileServices> OdRxRcsFileServicesPtr;

#include "TD_PackPop.h"

#endif // __OD_RCSFILESERVICES_MODULE__
