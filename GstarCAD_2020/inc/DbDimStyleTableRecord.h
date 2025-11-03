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




#ifndef _ODDBDIMSTYLETABLERECORD_INCLUDED
#define _ODDBDIMSTYLETABLERECORD_INCLUDED

#include "TD_PackPush.h"

#include "DbSymbolTableRecord.h"
#include "DbDimStyleTable.h"

/** Description: 
    This namespace contains utility functions for Dimension Style processing.

    {group:TD_Namespaces}
*/
namespace OdDmUtil
{
  /** Description:
    Returns the R14 DIMFIT value corresponding to the specified DIMATFIT and DIMTMOVE values.

    Arguments:
    dimatfit (I) DIMATFIT value.
    dimtmove (I) DIMTMOVE value.
    
    Remarks:
    The complete mapping is as follows:
    
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
    
    All other input combinations return 3.
  */
  int TOOLKIT_EXPORT dimfit(
    int dimatfit, 
    int dimtmove);
  
  /** Description:
    Returns the R14 DIMUNIT value corresponding to the specified DIMLUNIT and DIMFRAC values.

    Arguments:
    dimlunit (I) DIMLUNIT value.
    dimfrac (I) DIMFRAC value.    

    Remarks:
    The complete mapping is as follows:
    
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
  int TOOLKIT_EXPORT dimunit(
    int dimlunit, 
    int dimfrac);
  
  /** Description:
    Returns the R15 DIMATFIT value corresponding to the specified R14 DIMFIT value.

    Arguments:
    dimfit (I) DIMFIT value.
    
    Remarks:
    The complete mapping is as follows:
    
    @table
    dimfit  dimatfit
    0       0
    1       1
    2       2
    3       3
    4       3
    5       3
    other   3
    
  */
  int TOOLKIT_EXPORT dimatfit(
    int dimfit);
  
  /** Description:
    Returns the R15 DIMTMOVE value corresponding to the specified R14 DIMFIT value.
    
    Arguments:
    dimfit (I) DIMFIT value.
    
    Remarks:
    The complete mapping is as follows:
    
    @table
    dimfit  dimtmove
    0       0
    1       0
    2       0
    3       0
    4       1
    5       2
    other   0
  */
  int TOOLKIT_EXPORT dimtmove(
    int dimfit);
  
  /** Description:
    Returns the R15 DIMLUNIT value corresponding to the specified R14 DUMUNIT value.
    
    Arguments:
    dimunit (I) DIMUNIT value.
    
    Remarks:
    The complete mapping is as follows:
    
    @table
    dimunit    dimlunit
    1          1
    2          2
    3          3
    4          4
    5          5
    6          4
    7          5
    8          6
    other      2
  */
  int TOOLKIT_EXPORT dimlunit(
    int dimunit);
  
  /** Description:
    Returns the R15 DIMFRAC value corresponding to the specified R14 DUMUNIT value.
    
    Arguments:
    dimunit (I) DIMUNIT value.
    
    Remarks:
    The complete mapping is as follows:
    
    @table
    dimunit    dimfrac
    1          0
    2          0
    3          0
    4          0
    5          0
    6          2
    7          2
    8          0
    other      0
  */
  int TOOLKIT_EXPORT dimfrac(
    int dimunit);
    
  /** Description:
    Returns the local name of the specified dimension arrowhead.
    Arguments:
    blockId (I) Object ID of the dimension arrowhead.

	//Gcad(internal)
  */
  OdString TOOLKIT_EXPORT arrowName(ODSYSDEF,
    OdDbObjectId blockId);
  
  /*/Gcad(Add)
  /*/
  TOOLKIT_EXPORT const OdChar* globalArrowName(const OdString& pName);
  TOOLKIT_EXPORT const OdChar* globalArrowName(OdDbObjectId blockId);
  TOOLKIT_EXPORT const OdChar* arrowName(const OdString& pName);
  TOOLKIT_EXPORT const OdChar* arrowName(OdDbObjectId blockId);
  //*/
  /** Description:
    Returns true if and only if the specified arrowhead *name* is that of a built-in arrowhead.

    Arguments:
    arrowheadName (I) Arrowhead *name*.

    Remarks:
    The built-in arrowheads are as follows:
    
    @table
    BLOCK NAME    UI STRING
    ArchTick      "Architectural tick"
    BoxBlank      "Box"
    BoxFilled     "Box filled"
    Closed        "Closed"
    ClosedBlank   "Closed blank"
    DatumBlank    "Datum triangle"
    DatumFilled   "Datum triangle filled"
    Dot           "Dot"
    DotBlank      "Dot blank"
    DotSmall      "Dot small"
    Integral      "Integral"
    None          "None"
    Oblique       "Oblique"
    Open          "Open"
    Open30        "Open 30"
    Open90        "Right angle"
    Origin        "Origin indicator"
    Origin2       "Origin indicator 2"
    Small         "Dot small blank"
  */
  bool TOOLKIT_EXPORT isBuiltInArrow(
    const OdString& arrowheadName);
  
  /** Description:
    Returns true if and only if the specified arrowhead *name* is that of a built-in arrowhead 
    that is treated as having zero length.  
      
    Arguments:
    arrowheadName (I) Arrowhead *name*.

    Remarks:
    The built-in zero-length arrowheads are as follows:

    @table
    BLOCK NAME
    ArchTick
    DotSmall
    Integral
    None
    Oblique
    Small
  */
  bool TOOLKIT_EXPORT isZeroLengthArrow(
    const OdString& arrowheadName);
  
  /** Description:
    Returns the Object ID of the arrowhead block with the specified arrowhead *name*.

    Arguments:
    arrowheadName (I) Arrowhead *name*.
    pDb (I) Database containing the arrowhead.
  */
  OdDbObjectId TOOLKIT_EXPORT findArrowId(
    const OdString& arrowheadName, 
    const OdDbDatabase* pDb);
  /*/Gcad(Add)
  /*/
  OdResult	TOOLKIT_EXPORT findArrowId(const OdString& arrowheadName,
                        OdDbObjectId& blockId, 
                        OdDbDatabase* pDb = 0);
  //*/
  /** Description:
    Returns the Object ID of the arrowhead block with the specified arrowhead *name*, creating
    this block if necessary.

    Arguments:
    arrowheadName (I) Arrowhead *name*.
    pDb (I) Database containing the arrowhead.
  */
  OdDbObjectId TOOLKIT_EXPORT getArrowId(
    const OdString& arrowheadName, 
    OdDbDatabase* pDb);

  /*/Gcad(Add)
  /*/
  OdResult TOOLKIT_EXPORT getArrowId(const OdString& arrowheadName, 
                     OdDbObjectId& blockId, 
                     OdDbDatabase* pDb = 0);
  //*/
  /*
       OdString globalArrowName(const OdChar* pName);  
       OdString globalArrowName(OdDbObjectId blockId);
       OdString arrowName(const OdChar* pName);
  */

}

/** Description:

    {group:TD_Namespaces}
*/
#include "OdDb.h"

/** Description:
    This class represents Dimension Style records in the OdDbDimStyleTable in an OdDbDatabase instance.

    Library:
    TD_Db

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDimStyleTableRecord: public OdDbSymbolTableRecord
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDimStyleTableRecord);
  
  OdDbDimStyleTableRecord();

  typedef OdDbDimStyleTable TableType;

/** { Secret } */
#define VAR_DEF_STRING(type, name, dxf, def_value, metric_def_value, reserve1, reserve2)\
  const OdChar* dim##name() const; \
  OdResult setDim##name(const OdChar* val);

#define VAR_DEF(type, name, dxf, def_value, metric_def_value, reserve1, reserve2)\
  /** Description: Returns the DIM##NAME value of this Dimension Style. \
    Remarks: ##remarks \
    Notes: ##notes \
  */ \
  type dim##name() const; \
  \
  /** Description: Sets the DIM##NAME value for this Dimension Style.  \
    Arguments: val (I) New value for DIM##NAME.  ##RANGE \
    Remarks: ##remarks \
    Notes: ##notes \
    See Also: ##see_also \
  */ \
  OdResult setDim##name(type val);
  /** Gcad(Modify): 返回值 void -> OdResult 
    Gcad(TODO):这里有个麻烦问题，有两个函数
	要求：
    const char* dimapost () const;
    const char* dimpost  () const;
	而宏展开后是:
    OdString dimapost () const;
    OdString dimpost  () const;
  */

#include "DimVarDefs.h"
#undef VAR_DEF
#undef VAR_DEF_STRING

  bool dimfxlenOn() const;
  double dimfxlen() const;

  OdResult setDimfxlenOn(bool v);
  OdResult setDimfxlen(double v);
  
  /** Gcad(Modify): 返回值 void -> OdResult; 使用 OdString
  */
  OdResult setDimblk(
    const OdChar* val);

  OdResult setDimblk1(
    const OdChar* val);

  OdResult setDimblk2(
    const OdChar* val);

  OdResult setDimldrblk(
    const OdChar* val);

  // 2005-2006 support
  
  /** Description:
    Returns the background text color and flags for this Dimension Style.
    Arguments:
    bgrndTxtColor (O) Receives the background text color.
  */
  OdUInt16 getBgrndTxtColor(OdCmColor& bgrndTxtColor) const;
  
  /** Description:
    Sets the background text color and flags for this Dimension Style.
    Arguments:
    bgrndTxtColor (I) Background text color.
    bgrndTxtFlags (I) Background text flags.
  */
  void setBgrndTxtColor(const OdCmColor& bgrndTxtColor, OdUInt16 bgrndTxtFlags);

  /** Description:
    Returns the extension line fixed length enable flag for this Dimension Style.
  */
  bool getExtLineFixLenEnable() const;

  /** Description:
    Controls the extension line fixed length enable flag for this Dimension Style.
    Arguments:
    extLineFixLenEnable (I) Extension line fixed length flag.
  */
  void setExtLineFixLenEnable(bool extLineFixLenEnable);

  /** Description:
    Returns the extension line fixed length for this Dimension Style.
  */
  double getExtLineFixLen() const;

  /** Description:
    Sets the extension line fixed length for this Dimension Style.
    Arguments:
    extLineFixLen (I) Extension line fixed length.
  */
  void setExtLineFixLen(double extLineFixLen);

  /** Description:
    Returns the arc symbol type for this Dimension Style.
    Remarks:
    getArcSymbolType() returns one of the following:
    
    @table
    Value   Description
    0       Arc symbol precedes text.
    1       Arc symbol is above text.
    2       No arc symbol.
  */
  OdUInt16 getArcSymbolType() const;
  /** Description:
    Sets the arc symbol type for this Dimension Style.
    Arguments:
    arcSymbolType (I) Arc symbol type.

    Remarks:
    getArcSymbolType() must be one of the following:
    
    @table
    Value   Description
    0       Arc symbol precedes text.
    1       Arc symbol is above text.
    2       No arc symbol.
  */
  void setArcSymbolType(OdUInt16 arcSymbolType);

  /** Description:
    Returns the jog angle for this Dimension Style.
    Note:
    All angles are expressed in radians. 
  */
  double getJogAngle() const;
  /** Description:
    Sets the jog angle for this Dimension Style.
    Arguments:
    jogAngle (I) Jog angle. 
    Note:
    All angles are expressed in radians. 
  */
  void setJogAngle(double jogAngle);

  /** Description:
    Returns the Object ID of the dimension line linetype for this Dimension Style.
  */
  OdDbObjectId getDimLinetype() const;

  /** Description:
    Sets the Object ID of the dimension line linetype for this Dimension Style.

    Arguments:
    linetypeId (I) Dimension line linetype Object ID.
  */
  void setDimLinetype(const OdDbObjectId& linetypeId);

  /** Description:
    Returns the Object ID of the first extension line linetype for this Dimension Style.
  */
  OdDbObjectId getDimExt1Linetype() const;

  /** Description:
    Sets the Object ID of the first extension line linetype for this Dimension Style.
    
    Arguments:    
    linetypeId (I) First extension line linetype Object ID.
  */
  void setDimExt1Linetype(const OdDbObjectId& linetypeId);

  /** Description:
    Returns the Object ID of the second extension line linetype for this Dimension Style.
  */
  OdDbObjectId getDimExt2Linetype() const;
  /** Description:
    Sets the Object ID of the second extension line linetype for this Dimension entity.
    
    Arguments:    
    linetypeId (I) Second extension line linetype Object ID.
  */
  void setDimExt2Linetype(const OdDbObjectId& linetypeId);

  double jogSymbolHeight();

  void setJogSymbolHeight(double value);
  void setDIMTALN(bool value);
  bool getDIMTALN() const;

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
  
  virtual OdResult dxfInFields_R12(
    OdDbDxfFiler* pFiler);

  virtual void dxfOutFields_R12(
    OdDbDxfFiler* pFiler) const;
  
  virtual OdResult subGetClassID(
    CLSID* pClsid) const;

  /** Description:
    Returns the Object ID of the arrowhead block for the specified arrowhead type.

    Arguments:
    arrowType (I) Arrow type.
    
    Remarks:
    arrowType must be one of the following:
    
    @table
    Name           Value    Description    
    kFirstArrow    0        First arrowhead
    kSecondArrow   1        Second arrowhead
  */
  OdDbObjectId arrowId(
    OdDb::DimArrowFlags arrowType) const;

  /** Description:
    Returns true if and only if this Dimension Style has been *modified* for recompute.
  */
  bool isModifiedForRecompute() const;

  /*
  OdString dimpost() const;
  OdString dimapost() const;
  OdString dimblk() const;
  OdString dimblk1() const;
  OdString dimblk2() const;
  
  int dimfit() const;
  int dimunit() const;
    
  void setDimfit(int fit);
  void setDimunit(int unit);
  */

  /** Gcad(Add): 新增兼容非虚函数
  */ // {BEGIN
  OdResult getDimpost(OdChar*& pOutput) const;
  OdResult getDimapost(OdChar*& pOutput) const;
  OdResult getDimblk(OdChar*& pOutput) const;
  OdResult getDimblk1(OdChar*& pOutput) const;
  OdResult getDimblk2(OdChar*& pOutput) const;

  int dimfit() const;
  int dimunit() const;

  OdResult setDimfit(int fit);
  OdResult setDimunit(int unit);
  // END}

  virtual OdResult subClose();

};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbDimStyleTableRecord object pointers.
*/
typedef OdSmartPtr<OdDbDimStyleTableRecord> OdDbDimStyleTableRecordPtr;

#include "TD_PackPop.h"

#endif // _ODDBDIMSTYLETABLERECORD_INCLUDED

