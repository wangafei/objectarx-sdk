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

#ifndef FILER_INCLUDED
#define FILER_INCLUDED

#include <float.h>
#include "RxObject.h"
#include "OdStreamBuf.h"
#include "DbObjectId.h"
#include "TdxDefs.h"

class OdString;
class OdGeScale3d;
class OdBinaryData;
class OdDbFilerController;
class OdDbDatabase;
class OdResBuf;
typedef OdSmartPtr<OdResBuf> OdResBufPtr;
class OdDbObjectId;
class OdGePoint2d;
class OdGePoint3d;
class OdGeVector2d;
class OdGeVector3d;
class OdDbAuditInfo;

#include "TD_PackPush.h"

/** Description:
    This class is the abstract base class for classes that are used for file I/O operations
    utilizing the .dwg and .dxf file formats.
    
    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbFiler : public OdRxObject
{
public:
  OdDbFiler() {}

  ODRX_DECLARE_MEMBERS(OdDbFiler);

  /** Description:
    Returns the current status of this Filer object.    

    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual OdResult filerStatus() const;

  /** Description:
    Resets the current status of this Filer object to eOk.    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual void resetFilerStatus();

  /** Description:
    Returns the *type* of this Filer object.
  */
  virtual OdDb::FilerType filerType() const;

  /** Description:
    Returns the *database* with which this Filer object is associated.  
  */
  virtual OdDbDatabase* database() const;

  /** Description:
    Returns the *version* of this the file which this Filer object is associated.
    
    Remarks:
    The maintenance *release* *version* is returned if and only if pMaintReleaseVer != 0. 

    Arguments:
    pMaintReleaseVer (I) Pointer to the MaintReleaseVer to receive the maintenance *release* *version*.
  */
  virtual OdResult dwgVersion(OdDb::DwgVersion &, OdDb::MaintReleaseVer &) const;

  OdDb::DwgVersion dwgVersion(OdDb::MaintReleaseVer* pMaintReleaseVer = 0) const;

  /** Description:
    Returns the AuditInfo with which this Filer object is associated.  
  */
  virtual OdDbAuditInfo * getAuditInfo() const;

  /** Description:
    Sets the FilerController with which this Filer object is associated.
    
    Arguments:
    pFilerController (I) Pointer to the FilerController.
  */
  virtual void setController(
    OdDbFilerController * pFilerController);

  /** Description:
    Returns the FilerController with which this Filer object is associated.
  */
  virtual OdDbFilerController* controller() const;
};

///////////////////////////////////////////////////////////////////////
/** Description:
    This class defines a function that returns the type of a ResVal
    based on its ResType (DXF code). 
  
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdDxfCode
{
public:
  typedef enum
  {
    Unknown         = 0,
    Name            = 1,
    String          = 2,
    Bool            = 3,
    Integer8        = 4,
    Integer16       = 5,
    Integer32       = 6,
    Double          = 7,
    Angle           = 8,
    Point           = 9,
    BinaryChunk     = 10,
    LayerName       = 11,
    Handle          = 12,
    ObjectId        = 13,
    SoftPointerId   = 14,
    HardPointerId   = 15,
    SoftOwnershipId = 16,
    HardOwnershipId = 17,
    // New in R24 (AC24 support)
    Integer64       = 18, 
  } Type;

  /** Description:
    Returns the type of a ResVal based on its ResType (DXF code). 
  */
  static Type _getType(
    int code);
};

/** Description:
    This class is the abstract base class for classes that are used for file I/O operations
    with DXF formats.
    
    Library: TD_Db
    
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDxfFiler : public OdDbFiler
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDxfFiler);
  OdDbDxfFiler() {}
  virtual ~OdDbDxfFiler();
  virtual int rewindFiler();
  virtual OdResult filerStatus() const;
  virtual void resetFilerStatus();
  virtual OdDb::FilerType filerType() const;
  virtual OdDbDatabase* database() const;


  /** Description:
    Moves the I/O pointer to the specified location in this Filer object.
    
    Arguments:
    offset (I) Number of *bytes*.
    seekType (I) Seek type.
    
    Remarks:
    seekType must be one of the following:
    
    @table
    Name                    Value       Description.
    OdDb::kSeekFromStart    SEEK_SET    Start of file.
    OdDb::kSeekFromCurrent  SEEK_CUR    Current position of I/O pointer.
    OdDb::kSeekFromEnd      SEEK_END    End of file.

    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual OdResult seek(
    OdInt64 offset, 
    int seekType);
  
  /** Description:
    Returns the current I/O pointer position of this Filer object.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual OdInt64 tell() const;

  /** Description:
    Returns the number of decimal places for DxfOut filing with this Filer object.
    
    Remarks:
    Returns kDfltPrec for DxfIn filing.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual int precision() const;

  /** Description:
    Sets the number of decimal places DxfOut filing with this Filer object.
    
    Arguments:
    precision (I) Decimal places.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual void setPrecision(
    int decimalDigits);

  /** Description:
    Number of decimal digits written to ASCII DXF files.
  */
  enum 
  { 
    kDfltPrec = -1, 
    kMaxPrec = DBL_DIG + 1 
  };

  /** Description:
    Indicates the start of xdata in this Filer object.
    
    Remarks:
    
    o  For .dwg files, this function writes OdDbDxfXDataStart.
    o  For .dxf files, this function does nothing but return.
  */
  virtual OdResult writeXDataStart();
  
  //DRX-TODO
  virtual OdResult setError(OdResult, const OdChar *, ...);
  virtual OdResult setError(const OdChar *, ...);
  virtual const OdChar * errorMessage() const;

  // Gcad Modified - 读写函数ARX兼容
  //{{

  //        readXxx and writeXxx functions
  //
  virtual OdResult readResBuf(resbuf*);
  virtual OdResult writeResBuf(const resbuf& Rb);
  virtual OdResult writeObjectId(int groupCode, 
                     const OdDbObjectId& value) { return Oda::eOk; }
  virtual OdResult writeInt8(int groupCode, OdInt8 value) { return Oda::eOk; }
  inline  OdResult writeChar(OdDb::DxfCode c, OdInt8 n) { return this->writeInt8(c, n);}
  //todo{
  // This is to be removed in a future release
  //inline  OdResult writeChar(OdDb::DxfCode c, OdInt8 n) { return this->writeInt8(c, n); }
  //}

  virtual OdResult writeString(int groupCode, const OdString& value) { return Oda::eOk; }
  virtual OdResult writeString(int groupCode, const OdChar * value) = 0;
  virtual OdResult writeBChunk(int groupCode, const tdx_binary & value);
  virtual OdResult writeOdDbHandle(int groupCode, const OdDbHandle& value) { return Oda::eOk; }

  virtual OdResult writeInt64(int groupCode, OdInt64 value) { return Oda::eOk; }
  virtual OdResult writeInt32(int groupCode, OdInt32 value) { return Oda::eOk; }
  virtual OdResult writeInt16(int groupCode, OdInt16 value) { return Oda::eOk; }
  virtual OdResult writeUInt64(int groupCode, OdUInt64 value) { return Oda::eOk; }
  virtual OdResult writeUInt32(int groupCode, OdUInt32 value) { return Oda::eOk; }
  virtual OdResult writeUInt16(int groupCode, OdUInt16 value) { return Oda::eOk; }
  virtual OdResult writeUInt8(int groupCode, OdUInt8 value) { return Oda::eOk; }
  virtual OdResult writeBoolean(int groupCode , OdBool val) = 0;
  virtual OdResult writeBool(int groupCode, bool value) { return Oda::eOk; }
  virtual OdResult writeDouble(int groupCode, double value, int precision = kDfltPrec) { return Oda::eOk; }
  virtual OdResult writePoint2d(int groupCode, const OdGePoint2d&value, int precision = kDfltPrec) { return Oda::eOk; }
  virtual OdResult writePoint3d(int groupCode, const OdGePoint3d&value, int precision = kDfltPrec) { return Oda::eOk; }
  virtual OdResult writeVector2d(int groupCode, const OdGeVector2d&value, int precision = kDfltPrec) { return Oda::eOk; }
  virtual OdResult writeVector3d(int groupCode, const OdGeVector3d&value, int precision = kDfltPrec) { return Oda::eOk; }
  virtual OdResult writeScale3d(int groupCode, const OdGeScale3d&value, int precision = kDfltPrec) { return Oda::eOk; }

  //        readItem and writeItem functions
  //
  OdResult readItem  (resbuf* pItem);
  OdResult writeItem (const resbuf & pItem);
  OdResult writeItem (int, const OdDbObjectId&);

  OdResult writeItem (int, const OdChar *);
// #ifndef _MSC_VER    	
//   OdResult writeItem (int, const OdString &);
//   OdResult writeItem (int, const CString &);
// #endif
  OdResult writeItem (int, const tdx_binary& val);
  OdResult writeItem (int, const OdDbHandle&);
  OdResult writeItem (int, OdInt32);
  OdResult writeItem (int, OdInt16);
  OdResult writeItem (int, OdInt8);
  OdResult writeItem (int, OdUInt32);
  OdResult writeItem (int, OdUInt16);
  OdResult writeItem (int, OdUInt8);

#ifdef OdBool_is_bool
  OdResult writeItem (int, int);
#else
  OdResult writeItem (int, OdBool);
#endif

  OdResult writeItem (int, bool);
  OdResult writeItem (int, double, int = kDfltPrec);
  OdResult writeItem (int, const OdGePoint2d&, int = kDfltPrec);
  OdResult writeItem (int, const OdGePoint3d&, int = kDfltPrec);
  OdResult writeItem (int, const OdGeVector2d&,int = kDfltPrec);
  OdResult writeItem (int, const OdGeVector3d&,int = kDfltPrec);
  OdResult writeItem (int, const OdGeScale3d&, int = kDfltPrec);
  //}}

  /** Description:
    Returns true if and only if default values are normally written 
    to the file associated with this Filer object.

    Remarks:
    
    o  For .dwg files, this function always returns true.
    o  For .dxf files, this function always returns false.
  */  
  virtual bool includesDefaultValues() const;

  /** Description:
    Returns true if and only if this Filer object is at the end of an object's data.
    
    Remarks:
    This will be true when the filter is at any of the following:

    o  A subclass data marker.
    o  The start of an object's xdata.
    o  The start of another object's data.
    o  The end of a file.

    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual bool atEOF();
  
  /** Description:
    Returns true if and only if this Filer object is at the end of an object's data.
    
    Remarks:
    This will be true when the filter is at any of the following:
    
    o  The start of another object's data.
    o  The end of a file.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual bool atEndOfObject();
  
  virtual bool atEmbeddedObjectStart();
  virtual OdResult writeEmbeddedObjectStart();


  /** Description:
    Returns true if and only if this Filer object is at the start of an object's xdata.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual bool atExtendedData();

  /** Description:
    Returns true if and only if this Filer object is at a subclass data marker with the specified subClassName.

    Arguments:
    subClassName (I) Subclass name.
    
    Remarks:
    If true, the Filer advances the file pointer to the next item.
     
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual bool atSubclassData(
    const OdChar* subClassName);

  virtual void haltAtClassBoundries(bool);
  virtual double elevation() const;
  virtual double thickness() const;
  virtual bool isModifyingExistingObject() const;

  /** Description:
    Reads the next item of this Filer object, and returns its group code.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */
  virtual int nextItem();
  
  /** Description:
    Reads the next item of this Filer object, and returns a SmartPointer to its ResBuf.
  */
  virtual resbuf* nextRb();
  
  /** Description:
    Writes the specified ResBuf object to this Filer object.
    Arguments:
    pRb (I) Pointer to the ResBuf object.
  */
  OdResult writeRb(
    const OdResBufPtr& Rb);
  /** Description:
    Resets this Filer object to where it was before the last item was read.
    
    Note:
    The default implementation of this function does nothing but
    throw an exception.
  */  
  virtual OdResult pushBackItem();
  
  /** Description:
    Returns the *string* *value* of the current item of this Filer object.
    Arguments:
    value (O) Receives the *value*.
  */
  OdString rdString();
  virtual void rdString(
	  OdString &value) {}

  /** Description:
    Returns the bool *value* of the current item of this Filer object.
  */
  virtual bool rdBool() {return true;}

  /** Description:
    Returns the Int8 *value* of the current item of this Filer object.
  */
  virtual OdInt8 rdInt8() {return 0;}

  /** Description:
    Returns the Int16 *value* of the current item of this Filer object.
  */
  virtual OdInt16 rdInt16() {return 0;}

  /** Description:
    Returns the Int32 *value* of the current item of this Filer object.
  */
  virtual OdInt32 rdInt32() {return 0;}
  
  /** Description:
  Returns the Int64 *value* of the current item of this Filer object.
  */
  virtual OdInt64 rdInt64() {return 0;}

  /** Description:
    Returns the UInt8 *value* of the current item of this Filer object.
  */
  virtual OdUInt8 rdUInt8() {return 0;}
  
  /** Description:
    Returns the UInt16 *value* of the current item of this Filer object.
  */
  virtual OdUInt16 rdUInt16() {return 0;}
  
  /** Description:
    Returns the UInt32 *value* of the current item of this Filer object.
  */
  virtual OdUInt32 rdUInt32() {return 0;}
  
  /** Description:
  Returns the UInt64 *value* of the current item of this Filer object.
  */
  virtual OdUInt64 rdUInt64() {return 0;}

  /** Description:
    Returns the *handle* *value* of the current item of this Filer object.
  */
  virtual OdDbHandle rdHandle() {return OdDbHandle();}
  
  /** Description:
    Returns the Object ID *value* of the current item of this Filer object.
  */
  virtual OdDbObjectId rdObjectId() {return OdDbObjectId();}

  /** Description:
  Returns the angle *value* of the current item of this Filer object.
  */
  virtual double rdAngle() {return 0.0;}

  /** Description:
    Returns the double *value* of the current item of this Filer object.
  */
  virtual double rdDouble() {return 0.0;}
 
  /** Description:
    Returns the 2D *point* *value* of the current item of this Filer object.
    Arguments:
    value (O) Receives the *value*.
  */
  virtual void rdPoint2d(
	  OdGePoint2d& value) {}
    
  /** Description:
    Returns the 3D *point* *value* of the current item of this Filer object.
    Arguments:
    value (O) Receives the *value*.
  */
  virtual void rdPoint3d(
	  OdGePoint3d& value) {}

  /** Description:
    Returns the 2D *vector* *value* of the current item of this Filer object.
    Arguments:
    value (O) Receives the *value*.
  */
  virtual void rdVector2d(
	  OdGeVector2d& value) {}

  /** Description:
    Returns the 3D vector *value* of the current item of this Filer object.
    Arguments:
    value (O) Receives the *value*.
  */
  virtual void rdVector3d(
	  OdGeVector3d& value) {}
  
  /** Description:
    Returns the *scale* *value* of the current item of this Filer object.
    Arguments:
    value (O) Receives the *value*.
  */
  virtual void rdScale3d(
	  OdGeScale3d& value) {}
    
  /** Description:
    Returns the BinaryData *value* of the current item of this Filer object.
    
    Arguments:
    value (O) Receives the *value*.
  */
  virtual void rdBinaryChunk(
	  OdBinaryData& value) {}

  /** Description:
    Copies the current item from the specified Filer object to this one.
    Arguments:
    pSource (I) Pointer to the source Filer.
  */
  virtual void copyItem(
    OdDbDxfFiler * pSource);

  //DD2ARX - xi hui - 08-07-14 - OdDbDxfFiler::funcs
  //以下函数wr类型的改非虚,添加和ARX兼容的write类型函数
  //wrXXXXOpt函数未改动,内部调用改为调用write函数
  //wrName等函数ARX无,保留未改动

  /** Description:
    Writes the specified *name* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */
  virtual void wrName(
    int groupCode,
	  const OdString& value){}

  /** Description:
    Writes the specified *string* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrString(
    int groupCode, 
    const OdString& value) ODRX_SEALED;
  
  /** Description:
    Writes the specified optional *string* *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != NULL) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  void wrStringOpt(
    int groupCode, 
    const OdString& value);

  /** Description:
    Writes the specified subclass data marker to this Filer object.
      
    Arguments:
    value (I) Value.
  */  
  void wrSubclassMarker(
    const OdString &value);
  /** \details
    Writes the embedded object start marker to this Filer object.
  */
    void wrEmbeddedObjectStart();

  /** Description:
    Writes the specified bool *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrBool(
    int groupCode, 
    bool value) ODRX_SEALED;
  
  virtual OdResult writeInt(int groupCode , int val) { return eNotApplicable; }
    
  /** Description:
    Writes the specified optional bool *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrBoolOpt(
    int groupCode, 
    bool value, 
    bool defaultValue);

  /** Description:
    Writes the specified Int8 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrInt8(
    int groupCode, 
    OdInt8 value) ODRX_SEALED;
  
  /** Description:
    Writes the specified optional Int8 *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrInt8Opt(
    int groupCode, 
    OdInt8 value, 
    OdInt8 defaultValue);

  /** Description:
    Writes the specified UInt8 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrUInt8(
    int groupCode, 
    OdUInt8 value) ODRX_SEALED; 

  /** Description:
    Writes the specified optional UInt8 *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrUInt8Opt(
    int groupCode, 
    OdUInt8 value, 
    OdUInt8 defaultValue);

  /** Description:
    Writes the specified Int16 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrInt16(
    int groupCode, 
    OdInt16 value) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional Int16 *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrInt16Opt(
    int groupCode, 
    OdInt16 value, 
    OdInt16 defaultValue);

  /** Description:
    Writes the specified UInt16 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrUInt16(
    int groupCode, 
    OdUInt16 value) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional UInt16 *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrUInt16Opt(
    int groupCode, 
    OdUInt16 value, 
    OdUInt16 defaultValue);

  /** Description:
    Writes the specified Int32 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrInt32(
    int groupCode, 
    OdInt32 value) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional Int32 *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrInt32Opt(
    int groupCode, 
    OdInt32 value, 
    OdInt32 defaultValue);

  /** Description:
    Writes the specified UInt32 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrUInt32(
    int groupCode, OdUInt32 value) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional UInt32 *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrUInt32Opt(
    int groupCode, 
    OdUInt32 value, 
    OdUInt32 defaultValue);

  /** Description:
    Writes the specified Int64 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrInt64(
    int groupCode, 
    OdInt64 value) ODRX_SEALED;  

  /** Description:
    Writes the specified optional Int64 *value* to this Filer object.

    Remarks:
    value is written if and only if
    (value != default) || (includesDefaultValues() == true)

    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrInt64Opt(
    int groupCode, 
    OdInt64 value, 
    OdInt64 defaultValue);

  /** Description:
    Writes the specified UInt64 *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrUInt64(
    int groupCode, 
    OdUInt64 value) ODRX_SEALED;
  

  /** Description:
    Writes the specified optional UInt64 *value* to this Filer object.

    Remarks:
    value is written if and only if
    (value != default) || (includesDefaultValues() == true)

    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrUInt64Opt(
    int groupCode, 
    OdUInt64 value, 
    OdUInt64 defaultValue);

  /** Description:
    Writes the specified bool *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrHandle(
    int groupCode, 
    OdDbHandle value) ODRX_SEALED;

  /** Description:
    Writes the specified Object ID *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrObjectId(
    int groupCode, 
    OdDbObjectId value) ODRX_SEALED;

  /** Description:
    Writes the specified optional Object ID *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != NULL) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
  */
  void wrObjectIdOpt(
    int groupCode, 
    OdDbObjectId value);

  /** Description:
    Writes the specified *angle* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  virtual void wrAngle(
    int groupCode, 
    double value, 
    int precision = kDfltPrec){}
    
  /** Description:
    Writes the specified optional *angle* *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
    precision (I) Decimal places.
  */
  void wrAngleOpt(
    int groupCode, 
    double value, 
    double defaultValue = 0., 
    int precision = kDfltPrec);

  /** Description:
    Writes the specified double *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  ODRX_SEALED_VIRTUAL void wrDouble(
    int groupCode, 
    double value, 
    int precision = kDfltPrec) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional double *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
    precision (I) Decimal places.
  */
  void wrDoubleOpt(
    int groupCode, 
    double value, 
    double defaultValue = 0., 
    int precision = kDfltPrec);

  /** Description:
    Writes the specified 2D *point* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  ODRX_SEALED_VIRTUAL void wrPoint2d(
    int groupCode, 
    const OdGePoint2d& value, 
    int precision = kDfltPrec) ODRX_SEALED;
    
  /** Description:
    Writes the specified optional 2D *point* *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
    precision (I) Decimal places.
  */
  void wrPoint2dOpt(
    int groupCode, 
    const OdGePoint2d& value, 
    const OdGePoint2d& defaultValue, 
    int precision = kDfltPrec);

  /** Description:
    Writes the specified 3D *point* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  ODRX_SEALED_VIRTUAL void wrPoint3d(
    int groupCode, 
    const OdGePoint3d& value, 
    int precision = kDfltPrec) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional 3D *point* *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
    precision (I) Decimal places.
  */
  void wrPoint3dOpt(
    int groupCode, 
    const OdGePoint3d& value, 
    const OdGePoint3d& defaultValue, 
    int precision = kDfltPrec);

  /** Description:
    Writes the specified 2D *vector* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  ODRX_SEALED_VIRTUAL void wrVector2d(
    int groupCode, 
    const OdGeVector2d& value, 
    int precision = kDfltPrec) ODRX_SEALED;  
    
  /** Description:
    Writes the specified optional 2D *vector* *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
    precision (I) Decimal places.
  */
  void wrVector2dOpt(
    int groupCode, 
    const OdGeVector2d& value, 
    const OdGeVector2d& defaultValue, 
    int precision = kDfltPrec);

  /** Description:
    Writes the specified 3D *vector* *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  ODRX_SEALED_VIRTUAL void wrVector3d(
    int groupCode, 
    const OdGeVector3d& value, 
    int precision = kDfltPrec) ODRX_SEALED;
    
  /** Description:
    Writes the specified optional 3D *vector* *value* to this Filer object.
    
    Remarks:
    value is written if and only if
              (value != default) || (includesDefaultValues() == true)
     
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    defaultValue (I) Default *value*.
    precision (I) Decimal places.
  */
  void wrVector3dOpt(
    int groupCode, 
    const OdGeVector3d& value, 
    const OdGeVector3d& defaultValue, 
    int precision = kDfltPrec);

  /** Description:
    Writes the specified 2D *scale*  *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    precision (I) Decimal places.
  */  
  ODRX_SEALED_VIRTUAL void wrScale3d(
    int groupCode, 
    const OdGeScale3d& value, 
    int precision = kDfltPrec) ODRX_SEALED;

  /** Description:
    Writes the specified BinaryChunk *value* to this Filer object.
    Arguments:
    groupCode (I) Group code.
    value (I) Value.
    numBytes (I) Number of *bytes*.
    buffer (I) array of *bytes*.
  */  
  //下面函数ARX无,只有两个参数版本的,修改两参数版的函数名字,此虚函数不改
  virtual void wrBinaryChunk(
    int groupCode, 
    const OdUInt8* buffer, 
	  OdUInt32 numBytes) {}
    
  OdResult writeBChunk(
    int groupCode, 
    const OdBinaryData& value); 
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDxfFiler object pointers.
*/
typedef OdSmartPtr<OdDbDxfFiler> OdDbDxfFilerPtr;

/** Description:
    This class implements OdError objects with Result codes of eDwgObjectImproperlyRead.
    
    Library: TD_Db
    {group:Error_Classes} 
*/
class TOOLKIT_EXPORT OdError_DwgObjectImproperlyRead : public OdError
{
public:
  OdError_DwgObjectImproperlyRead() : OdError(eDwgObjectImproperlyRead){}
};

class OdDbIdRefQueue;

/** Description:
    This class is the abstract base class for classes that are used for file I/O operations
    with the .dwg file format.
    
    Library: TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDwgFiler : public OdDbFiler
{
public:
  OdDbDwgFiler() {}

  ODRX_DECLARE_MEMBERS(OdDbDwgFiler);

  virtual OdResult filerStatus() const;
  virtual OdDb::FilerType filerType() const;
  virtual void setFilerStatus(OdResult);
  virtual void resetFilerStatus();
  virtual OdResult addReferences(OdDbIdRefQueue& /*qToAbsorb*/);
  virtual OdDbAuditInfo *getAuditInfo() const;

  /** Description:
    Moves the I/O pointer to the specified location in this Filer object.
    
    Arguments:
    offset (I) Number of *bytes*.
    seekType (I) Seek type.
    
    Remarks:
    seekType must be one of the following:
    
    @table
    Name                    Value       Description.
    OdDb::kSeekFromStart    SEEK_SET    Start of file.
    OdDb::kSeekFromCurrent  SEEK_CUR    Current position of I/O pointer.
    OdDb::kSeekFromEnd      SEEK_END    End of file.
  */
  virtual OdResult seek(
    OdInt64 offset, 
	int seekType) {return Oda::eOk; }

  /** Description:
    Returns the current I/O pointer position of this Filer object.
  */
  virtual OdInt64 tell() const {return 0;}

  /*/DD2ARX - xi hui - 08-07-14 - OdDbDwgFiler::funcs
  /*/
	ODRX_SEALED_VIRTUAL OdDbHandle rdDbHandle() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void* rdAddress() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL bool rdBool() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void rdBytes(void* buffer, OdUInt32 numBytes) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL double rdDouble() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdDbHardOwnershipId rdHardOwnershipId() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdDbHardPointerId rdHardPointerId() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdInt8 rdInt8() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdInt16 rdInt16() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdInt32 rdInt32() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdGePoint2d rdPoint2d() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdGePoint3d rdPoint3d() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdGeScale3d rdScale3d() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdDbSoftOwnershipId rdSoftOwnershipId() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdDbSoftPointerId rdSoftPointerId() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdString rdString() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdUInt8 rdUInt8() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdGeVector2d rdVector2d() ODRX_SEALED;
	ODRX_SEALED_VIRTUAL OdGeVector3d rdVector3d() ODRX_SEALED;

	// These are to be removed in a future release.  Please use
    // readInt8 or writeInt8 instead.
	inline OdResult readChar(OdInt8* unnamed)
	{
	  return readInt8(unnamed);
	}

	inline OdResult writeChar(OdInt8 unnamed)
	{
	  return writeInt8(unnamed);
	}

	virtual OdResult readOdDbHandle(OdDbHandle* unnamed) { return Oda::eOk; }
	virtual OdResult readAddress(void** unnamed);
	virtual OdResult readBoolean(OdBool*){ return Oda::eOk; }
	virtual OdResult readBool(bool* unnamed) { return Oda::eOk; }
	virtual OdResult readBytes(void* buffer, OdUIntPtr numBytes) { return Oda::eOk; }
	virtual OdResult readDouble(double* unnamed) { return Oda::eOk; }
	virtual OdResult readHardOwnershipId(OdDbHardOwnershipId* unnamed) { return Oda::eOk; }
	virtual OdResult readHardPointerId(OdDbHardPointerId* unnamed) { return Oda::eOk; }
	virtual OdResult readInt8(OdInt8* unnamed) { return Oda::eOk; }
	virtual OdResult readInt16(OdInt16* unnamed) { return Oda::eOk; }
	virtual OdResult readInt32(OdInt32* unnamed) { return Oda::eOk; }
  virtual OdResult readInt64(OdInt64* unnamed) { return Oda::eOk; }
	virtual OdResult readPoint2d(OdGePoint2d* unnamed) { return Oda::eOk; }
	virtual OdResult readPoint3d(OdGePoint3d* unnamed) { return Oda::eOk; }
	virtual OdResult readScale3d(OdGeScale3d* unnamed) { return Oda::eOk; }
	virtual OdResult readSoftOwnershipId(OdDbSoftOwnershipId* unnamed) { return Oda::eOk; }
	virtual OdResult readSoftPointerId(OdDbSoftPointerId* unnamed) { return Oda::eOk; }
	virtual OdResult readString(OdString& unnamed) { return Oda::eOk; }
	virtual OdResult readUInt8(OdUInt8* unnamed) { return Oda::eOk; }
	virtual OdResult readVector2d(OdGeVector2d* unnamed) { return Oda::eOk; }
	virtual OdResult readVector3d(OdGeVector3d* unnamed) { return Oda::eOk; }
	virtual OdResult readString(OdChar** unnamed) { return Oda::eOk; }
	virtual OdResult readBChunk(tdx_binary* unnamed) { return Oda::eOk; }
	virtual OdResult readUInt16(OdUInt16* unnamed) { return Oda::eOk; }
	virtual OdResult readUInt32(OdUInt32* unnamed) { return Oda::eOk; }
  virtual OdResult readUInt64(OdUInt64* unnamed) { return Oda::eOk; }

	ODRX_SEALED_VIRTUAL void wrDbHandle(const OdDbHandle& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrAddress(const void* value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrBool(bool value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrBytes(const void* buffer, OdUInt32 numBytes) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrDouble(double value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrHardOwnershipId(const OdDbHardOwnershipId& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrHardPointerId(const OdDbHardPointerId& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrInt8(OdInt8 value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrInt16(OdInt16 value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrInt32(OdInt32 value) ODRX_SEALED;
  ODRX_SEALED_VIRTUAL void wrPoint2d(const OdGePoint2d& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrPoint3d(const OdGePoint3d& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrScale3d(const OdGeScale3d& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrSoftOwnershipId(const OdDbSoftOwnershipId& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrSoftPointerId(const OdDbSoftPointerId& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrString(const OdString &value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrUInt8(OdUInt8 value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrVector2d(const OdGeVector2d& value) ODRX_SEALED;
	ODRX_SEALED_VIRTUAL void wrVector3d(const OdGeVector3d& value) ODRX_SEALED;

	virtual OdResult writeOdDbHandle(const OdDbHandle& value) { return Oda::eOk; }
	virtual OdResult writeAddress(const void* value);
	virtual OdResult writeBoolean(OdBool){ return Oda::eOk; }
	virtual OdResult writeBool(bool value) { return Oda::eOk; }
	virtual OdResult writeBytes(const void* buffer, OdUIntPtr numBytes) { return Oda::eOk; }
	virtual OdResult writeDouble(double value) { return Oda::eOk; }
	virtual OdResult writeHardOwnershipId(const OdDbHardOwnershipId& value) { return Oda::eOk; }
	virtual OdResult writeHardPointerId(const OdDbHardPointerId& value) { return Oda::eOk; }
	virtual OdResult writeInt8(OdInt8 value) { return Oda::eOk; }
	virtual OdResult writeInt16(OdInt16 value) { return Oda::eOk; }
	virtual OdResult writeInt32(OdInt32 value) { return Oda::eOk; }
  virtual OdResult writeInt64(OdInt64 value) { return Oda::eOk; }
	virtual OdResult writePoint2d(const OdGePoint2d& value) { return Oda::eOk; }
	virtual OdResult writePoint3d(const OdGePoint3d& value) { return Oda::eOk; }
	virtual OdResult writeScale3d(const OdGeScale3d& value) { return Oda::eOk; }
	virtual OdResult writeSoftOwnershipId(const OdDbSoftOwnershipId& value) { return Oda::eOk; }
	virtual OdResult writeSoftPointerId(const OdDbSoftPointerId& value) { return Oda::eOk; }
	virtual OdResult writeString(const OdString &value) { return Oda::eOk; }
	virtual OdResult writeUInt8(OdUInt8 value) { return Oda::eOk; }
	virtual OdResult writeVector2d(const OdGeVector2d& value) { return Oda::eOk; }
	virtual OdResult writeVector3d(const OdGeVector3d& value) { return Oda::eOk; }
	virtual OdResult writeString(const OdChar* unnamed) { return Oda::eOk; }
	virtual OdResult writeBChunk(const tdx_binary& unnamed) { return Oda::eOk; }
	virtual OdResult writeUInt16(OdUInt16 unnamed) { return Oda::eOk; }
	virtual OdResult writeUInt32(OdUInt32 unnamed) { return Oda::eOk; }
  virtual OdResult writeUInt64(OdUInt64 unnamed) { return Oda::eOk; }

	virtual OdResult   readInt(int*){ return Oda::eOk; }
	virtual OdResult   writeInt(int){ return Oda::eOk; }

	OdResult   readItem(OdDbHardOwnershipId*);
	OdResult   writeItem(const OdDbHardOwnershipId&);

	OdResult   readItem(OdDbSoftOwnershipId*);
	OdResult   writeItem(const OdDbSoftOwnershipId&);

	OdResult   readItem(OdDbHardPointerId*);
	OdResult   writeItem(const OdDbHardPointerId&);

	OdResult   readItem(OdDbSoftPointerId*);
	OdResult   writeItem(const OdDbSoftPointerId&);

	OdResult   readItem(OdDbHandle*);
	OdResult   writeItem(const OdDbHandle&);
#ifdef OdBool_is_bool
	OdResult   readItem(int *);
	OdResult   writeItem(int);
#else
	OdResult   readItem(OdBool*);
	OdResult   writeItem(OdBool);
#endif
  OdResult   readItem(OdInt64*);
  OdResult   writeItem(OdInt64);

	OdResult   readItem(OdInt32*);
	OdResult   writeItem(OdInt32);

	OdResult   readItem(OdInt16*);
	OdResult   writeItem(OdInt16);

	OdResult   readItem(OdInt8*);
	OdResult   writeItem(OdInt8);

	OdResult   readItem(bool*);
	OdResult   writeItem(bool);

	OdResult   readItem(double*);
	OdResult   writeItem(double);

	OdResult   readItem(OdGePoint2d*);
	OdResult   writeItem(const OdGePoint2d&);

	OdResult   readItem(OdGePoint3d*);
	OdResult   writeItem(const OdGePoint3d&);

	OdResult   readItem(OdGeVector2d*);
	OdResult   writeItem(const OdGeVector2d&);

	OdResult   readItem(OdGeVector3d*);
	OdResult   writeItem(const OdGeVector3d&);

	OdResult   readItem(OdGeScale3d*);
	OdResult   writeItem(const OdGeScale3d&);

	OdResult   readItem(void *, OdUIntPtr);
	OdResult   writeItem(const void *, OdUIntPtr);

	OdResult   readItem(void **);
	OdResult   writeItem(const void *);

	OdResult   readItem(OdChar **);
	OdResult   writeItem(const OdChar *);

	OdResult   readItem(tdx_binary*);
	OdResult   writeItem(const tdx_binary&);

	OdResult   readItem(OdUInt8*);
	OdResult   writeItem(OdUInt8);

	OdResult   readItem(OdUInt16*);
	OdResult   writeItem(OdUInt16);

	OdResult   readItem(OdUInt32*);
	OdResult   writeItem(OdUInt32);

  OdResult   readItem(OdUInt64*);
  OdResult   writeItem(OdUInt64);

  OdResult   writeItem(const OdString& val);

#if  defined(_AFX) || defined(__ATLSTR_H__)
  OdResult   writeItem(const CStringW& val)
  {
    return writeItem((const OdChar*)val);
  }
#endif
  //*/

  /** Description:
    Returns the Int64 *value* of the current item of this Filer object.
  */
  ODRX_SEALED_VIRTUAL OdInt64 rdInt64() ODRX_SEALED;
  
  /** Description:
    Writes the specified Int64 *value* to this Filer object.
    Arguments:
    value (I) Value.
  */  
  ODRX_SEALED_VIRTUAL void wrInt64(OdInt64 value) ODRX_SEALED;
	
  /** Description:
    Returns true if and only if this Filer object wishes to see
    all object references.
    
    Remarks:
    The default implementation of this function always returns true. 
  */
  virtual bool usesReferences() const;
  
  /** { Secret } */
  /** Description:
  */
  virtual OdResult addReference(OdDbObjectId id, OdDb::ReferenceType rt);
};

/** Description:
  This template class is a specialization of the OdSmartPtr class for OdDbDwgFiler object pointers.
*/
typedef OdSmartPtr<OdDbDwgFiler> OdDbDwgFilerPtr;


/** Description:
    This class is the empty implementation of a base class 
    for classes that are used as ID Filers.
    
    Library: TD_Db
    
    {group:Other_Classes}
*/
class TOOLKIT_EXPORT OdIdFiler : public OdDbDwgFiler
{
public:
  OdIdFiler() : m_pController(NULL) {}

  OdResult seek(
    OdInt64 offset, 
    int seekType);
  
  OdInt64 tell() const;
  
  OdResult filerStatus() const;
  
  void resetFilerStatus();
  
  OdDb::FilerType filerType() const;
  
  OdResult dwgVersion(OdDb::DwgVersion &, OdDb::MaintReleaseVer &) const;
    
  //DD2ARX - xi hui - 08-07-14 - OdDbDwgFiler::funcs
  OdResult readOdDbHandle(OdDbHandle* unnamed);
	OdResult readBoolean(OdBool*);
  OdResult readBool(bool* unnamed);
  OdResult readBytes(void* buffer, OdUIntPtr numBytes);
  OdResult readDouble(double* unnamed);
  OdResult readHardOwnershipId(OdDbHardOwnershipId* unnamed);
  OdResult readHardPointerId(OdDbHardPointerId* unnamed);
  OdResult readInt8(OdInt8* unnamed);
  OdResult readInt16(OdInt16* unnamed);
  OdResult readInt32(OdInt32* unnamed);
  OdResult readInt64(OdInt64* unnamed);
  OdResult readPoint2d(OdGePoint2d* unnamed);
  OdResult readPoint3d(OdGePoint3d* unnamed);
  OdResult readScale3d(OdGeScale3d* unnamed);
  OdResult readSoftOwnershipId(OdDbSoftOwnershipId* unnamed);
  OdResult readSoftPointerId(OdDbSoftPointerId* unnamed);
  OdResult readString(OdString& unnamed);
  OdResult readUInt8(OdUInt8* unnamed);
  OdResult readVector2d(OdGeVector2d* unnamed);
  OdResult readVector3d(OdGeVector3d* unnamed);
  OdResult readString(OdChar** unnamed);
  OdResult readBChunk(tdx_binary* unnamed);
  OdResult readUInt16(OdUInt16* unnamed);
  OdResult readUInt32(OdUInt32* unnamed);
  OdResult readUInt64(OdUInt64* unnamed);

  OdResult writeOdDbHandle(const OdDbHandle& value);
	OdResult writeBoolean(OdBool);
  OdResult writeBool(bool value);
  OdResult writeBytes(const void* buffer, OdUIntPtr numBytes);
  OdResult writeDouble(double value);
  OdResult writeInt8(OdInt8 value);
  OdResult writeInt16(OdInt16 value);
  OdResult writeInt32(OdInt32 value);
  OdResult writeInt64(OdInt64 value);
  OdResult writePoint2d(const OdGePoint2d& value);
  OdResult writePoint3d(const OdGePoint3d& value);
  OdResult writeScale3d(const OdGeScale3d& value);
  OdResult writeString(const OdString &value);
  OdResult writeUInt8(OdUInt8 value);
  OdResult writeVector2d(const OdGeVector2d& value);
  OdResult writeVector3d(const OdGeVector3d& value);
  OdResult writeString(const OdChar* unnamed);
  OdResult writeBChunk(const tdx_binary& unnamed);
  OdResult writeUInt16(OdUInt16 unnamed);
  OdResult writeUInt32(OdUInt32 unnamed);
  OdResult writeUInt64(OdUInt64 unnamed);

	OdResult   readInt(int*);
	OdResult   writeInt(int);
	
  void setController(
    OdDbFilerController* pFilerController) { m_pController = pFilerController; }
  OdDbFilerController* controller() const { return m_pController; }
private:
  OdDbFilerController* m_pController;
};

inline OdResult OdDbDwgFiler::readItem(OdDbHardOwnershipId* pId)
{   return readHardOwnershipId(pId); }

inline OdResult OdDbDwgFiler::writeItem(const OdDbHardOwnershipId& pId)
{   return writeHardOwnershipId(pId); }

inline OdResult OdDbDwgFiler::readItem(OdDbSoftOwnershipId* pId)
{   return readSoftOwnershipId(pId); }

inline OdResult OdDbDwgFiler::writeItem(const OdDbSoftOwnershipId& pId)
{   return writeSoftOwnershipId(pId); }

inline OdResult OdDbDwgFiler::readItem(OdDbHardPointerId* pId)
{   return readHardPointerId(pId); }

inline OdResult OdDbDwgFiler::writeItem(const OdDbHardPointerId& pId)
{   return writeHardPointerId(pId); }

inline OdResult OdDbDwgFiler::readItem(OdDbSoftPointerId* pId)
{   return readSoftPointerId(pId); }

inline OdResult OdDbDwgFiler::writeItem(const OdDbSoftPointerId& pId)
{   return writeSoftPointerId(pId); }

inline OdResult OdDbDwgFiler::readItem(OdDbHandle* pVal)
{   return readOdDbHandle(pVal);    }

inline OdResult OdDbDwgFiler::writeItem(const OdDbHandle& val)
{   return writeOdDbHandle(val);    }

#ifdef OdBool_is_bool
inline OdResult OdDbDwgFiler::readItem(int* pVal)
{   return readInt(pVal); }

inline OdResult OdDbDwgFiler::writeItem(int val)
{   return writeInt(val);   }
#else
inline OdResult OdDbDwgFiler::readItem(OdBool* pVal)
{   return readBoolean(pVal); }

inline OdResult OdDbDwgFiler::writeItem(OdBool val)
{   return writeBoolean(val);   }
#endif

inline OdResult OdDbDwgFiler::readItem(OdInt64* pVal)
{   return readInt64(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(OdInt64 val)
{   return writeInt64(val);            }
inline OdResult OdDbDwgFiler::readItem(OdInt32* pVal)
{   return readInt32(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(OdInt32 val)
{   return writeInt32(val);            }

inline OdResult OdDbDwgFiler::readItem(OdInt16* pVal)
{   return readInt16(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(OdInt16 val)
{   return writeInt16(val);            }

inline OdResult OdDbDwgFiler::readItem(OdInt8* pVal)
{   return readInt8(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(OdInt8 val)
{   return writeInt8(val);            }

inline OdResult OdDbDwgFiler::readItem(bool* pVal)
{   return readBool(pVal);              }

inline OdResult OdDbDwgFiler::writeItem(bool val)
{   return writeBool(val);              }

inline OdResult OdDbDwgFiler::readItem(double* pVal)
{   return readDouble(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(double val)
{   return writeDouble(val);            }

inline OdResult OdDbDwgFiler::readItem(OdGePoint2d* pVal)
{   return readPoint2d(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(const OdGePoint2d& val)
{   return writePoint2d(val);            }

inline OdResult OdDbDwgFiler::readItem(OdGePoint3d* pVal)
{   return readPoint3d(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(const OdGePoint3d& val)
{   return writePoint3d(val);            }

inline OdResult OdDbDwgFiler::readItem(OdGeVector2d* pVal)
{   return readVector2d(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(const OdGeVector2d& val)
{   return writeVector2d(val);            }

inline OdResult OdDbDwgFiler::readItem(OdGeVector3d* pVal)
{   return readVector3d(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(const OdGeVector3d& val)
{   return writeVector3d(val);            }

inline OdResult OdDbDwgFiler::readItem(OdGeScale3d* pVal)
{   return readScale3d(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(const OdGeScale3d& val)
{   return writeScale3d(val);            }

inline OdResult OdDbDwgFiler::readItem(void *buf, OdUIntPtr cnt)
{   return readBytes(buf, cnt);     }

inline OdResult OdDbDwgFiler::writeItem(const void *buf, OdUIntPtr cnt)
{   return writeBytes(buf, cnt);    }

inline OdResult OdDbDwgFiler::readItem(void **pp)
{   return readAddress(pp);            }

inline OdResult OdDbDwgFiler::writeItem(const void *p)
{   return writeAddress(p);            }

inline OdResult OdDbDwgFiler::readItem(OdChar ** ppVal)
{   return readString(ppVal);          }

inline OdResult OdDbDwgFiler::writeItem(const OdChar *pVal)
{   return writeString(pVal);          }

inline OdResult OdDbDwgFiler::readItem(tdx_binary* pVal)
{   return readBChunk(pVal);           }

inline OdResult OdDbDwgFiler::writeItem(const tdx_binary& val)
{   return writeBChunk(val);           }

inline OdResult OdDbDwgFiler::readItem(OdUInt8* pVal)
{   return readUInt8(pVal);            }

inline OdResult OdDbDwgFiler::writeItem(OdUInt8 val)
{   return writeUInt8(val);            }

inline OdResult OdDbDwgFiler::readItem(OdUInt16* pVal)
{   return readUInt16(pVal);           }

inline OdResult OdDbDwgFiler::writeItem(OdUInt16 val)
{   return writeUInt16(val);           }

inline OdResult OdDbDwgFiler::readItem(OdUInt32* pVal)
{   return readUInt32(pVal);           }

inline OdResult OdDbDwgFiler::writeItem(OdUInt32 val)
{   return writeUInt32(val);           }

inline OdResult OdDbDwgFiler::readItem(OdUInt64* pVal)
{   return readUInt64(pVal);           }

inline OdResult OdDbDwgFiler::writeItem(OdUInt64 val)
{   return writeUInt64(val);           }

inline OdResult OdDbDwgFiler::writeItem(const OdString & val)
{
  return writeString(val);
}

//DD2ARX - xi hui - 08-07-14 - OdDbDxfFiler::funcs
inline OdResult OdDbDxfFiler::readItem(resbuf * pVal)
{   return readResBuf(pVal);         }

inline OdResult OdDbDxfFiler::writeItem(const resbuf& val)
{   return writeResBuf(val);            }

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdDbObjectId& id)
{   return writeObjectId(dc, id); }

inline OdResult OdDbDxfFiler::writeItem(int dc, OdInt8 val)
{   return writeInt8(dc, val);                }

inline OdResult OdDbDxfFiler::writeItem (int dc, const OdChar * val)
{	return writeString(dc , val);}

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdDbHandle& val)
{   return writeOdDbHandle(dc, val);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, OdInt32 val)
{   return writeInt32(dc, val);         }

inline OdResult OdDbDxfFiler::writeItem(int dc, OdInt16 val)
{   return writeInt16(dc, val);         }

inline OdResult OdDbDxfFiler::writeItem(int dc, OdUInt32 val)
{   return writeUInt32(dc, val);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, OdUInt16 val)
{   return writeUInt16(dc, val);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, OdUInt8 val)
{   return writeUInt8(dc, val);         }

inline OdResult OdDbDxfFiler::writeItem(int dc, bool val)
{   return writeBool(dc, val);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, double val, int prec)
{   return writeDouble(dc, val, prec);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdGePoint2d& val, int prec)
{   return writePoint2d(dc, val, prec); }

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdGePoint3d& val, int prec)
{   return writePoint3d(dc, val, prec); }

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdGeVector2d& val, int prec)
{   return writeVector2d(dc, val, prec);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdGeVector3d& val, int prec)
{   return writeVector3d(dc, val, prec);        }

inline OdResult OdDbDxfFiler::writeItem(int dc, const OdGeScale3d& val, int prec)
{   return writeScale3d(dc, val, prec); }

inline OdResult OdDbDxfFiler::writeItem(int dc, const tdx_binary& val)
{   return writeBChunk(dc, val); }

#ifdef OdBool_is_bool
inline OdResult OdDbDxfFiler::writeItem (int dc, int val)
{   return writeInt(dc,val);}
#else
inline OdResult OdDbDxfFiler::writeItem (int dc, OdBool val)
{   return writeBoolean(dc,val);}
#endif
#include "TD_PackPop.h"

#endif  // FILER_INCLUDED

