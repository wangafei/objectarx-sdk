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


#ifndef OD_DBDATATABLE_H
#define OD_DBDATATABLE_H

#include "TD_PackPush.h"
#include "RxObject.h"
#include "DbObject.h"

class OdDbDataCellImpl;
/** Description:
    Library: TD_Db 
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDataCell : public OdRxObject
{ // Gcad(Modify)
public:
  ODDB_DECLARE_MEMBERS(OdDbDataCell);

  // Constructors
  OdDbDataCell();
  OdDbDataCell(const OdDbDataCell& rCell);

  enum CellType {
      kUnknown      = 0,
      kInteger      = 1,
      kDouble       = 2,
      kCharPtr      = 3,
      kPoint        = 4,
      kObjectId     = 5,
      kHardOwnerId  = 6,
      kSoftOwnerId  = 7,
      kHardPtrId    = 8,
      kSoftPtrId    = 9,
      kBool         = 10,
      kVector       = 11
  };

  OdDbDataCell(bool b);
  OdDbDataCell(OdInt i);
  OdDbDataCell(double d);
  OdDbDataCell(const OdChar* pChar);
  OdDbDataCell(const OdGePoint3d& point);
  OdDbDataCell(const OdGeVector3d& vec);
  OdDbDataCell(const OdDbObjectId& id);
  OdDbDataCell(const OdDbHardOwnershipId& id);
  OdDbDataCell(const OdDbSoftOwnershipId& id);
  OdDbDataCell(const OdDbHardPointerId&   id);
  OdDbDataCell(const OdDbSoftPointerId&   id);
  
  virtual ~OdDbDataCell();
  
  virtual void init();

  void set(const OdDbDataCell& cell);
  void set(bool b);
  void set(OdInt32 i);
  void set(double d);
  void set(const OdString& str);
  void set(const OdGePoint3d& pt);
  void set(const OdGeVector3d& vec);
  void set(const OdDbObjectId& id);
  void set(const OdDbHardOwnershipId& id);
  void set(const OdDbSoftOwnershipId& id);
  void set(const OdDbHardPointerId& id);
  void set(const OdDbSoftPointerId& id);

  void get(OdDbDataCell& cell);
  void get(bool& b);
  void get(OdInt32& i);
  void get(double& d);
  void get(OdString& str);
  void get(OdGePoint3d& pt);
  void get(OdGeVector3d& vec);
  void get(OdDbObjectId& id);
  void get(OdDbHardOwnershipId& id);
  void get(OdDbSoftOwnershipId& id);
  void get(OdDbHardPointerId& id);
  void get(OdDbSoftPointerId& id);

public:
  virtual OdDbDataCell& operator = (const OdDbDataCell &cell);
  virtual OdDbDataCell& operator = (bool b);
  virtual OdDbDataCell& operator = (OdInt i);
  virtual OdDbDataCell& operator = (double d);
  virtual OdDbDataCell& operator = (const OdChar* pChar);
  virtual OdDbDataCell& operator = (const OdGePoint3d &pt);
  virtual OdDbDataCell& operator = (const OdGeVector3d &vec);
  virtual OdDbDataCell& operator = (const OdDbObjectId &id);
  virtual OdDbDataCell& operator = (const OdDbHardOwnershipId &hoId);
  virtual OdDbDataCell& operator = (const OdDbSoftOwnershipId &soId);
  virtual OdDbDataCell& operator = (const OdDbHardPointerId   &hpId);
  virtual OdDbDataCell& operator = (const OdDbSoftPointerId   &spId);

  virtual operator bool() const;
  virtual operator OdInt() const;
  virtual operator double() const;
  virtual operator const OdChar*() const;
  virtual operator OdGePoint3d&()const;
  virtual operator OdGeVector3d&()const;
  virtual operator OdDbObjectId&() const;
  virtual operator OdDbHardOwnershipId&() const;
  virtual operator OdDbSoftOwnershipId&() const;
  virtual operator OdDbHardPointerId&() const;
  virtual operator OdDbSoftPointerId&() const;
	
  virtual bool operator == (const OdDbDataCell &cell) const;
  virtual bool operator != (const OdDbDataCell &cell) const;

  virtual OdDbDataCell::CellType type() const;
  OdDbDataCell(OdDbDataCellImpl* pValImpl);

protected:
  friend class OdDbSystemInternals;
  OdDbDataCellImpl* m_pImpl;
};

typedef OdSmartPtr<OdDbDataCell> OdDbDataCellPtr;

typedef OdArray<OdDbDataCellPtr> OdDbDataCellArray; 

class OdDbDataColumnImpl;

/** Description:
    Library: TD_Db 
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDataColumn : public OdRxObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDataColumn);

  OdDbDataColumn();
  OdDbDataColumn(const OdDbDataColumn& rCol);
  OdDbDataColumn(const OdDbDataCell::CellType type,
    const OdChar* pColName = NULL);

  virtual ~OdDbDataColumn();

  virtual OdUInt32 physicalLength() const;
  virtual OdUInt32 growLength() const;

  virtual OdResult setPhysicalLength(OdUInt32 n); // Gcad(Modify)
  virtual OdResult setGrowLength(OdUInt32 n);	  // Gcad(Modify)

  virtual OdDbDataColumn& operator = (const OdDbDataColumn& col); // Gcad(Uncomment)
																	 
  virtual OdResult setColumnType(OdDbDataCell::CellType type);    // Gcad(Modify)
  virtual OdDbDataCell::CellType columnType() const;

  virtual OdResult setColumnName(const OdChar* pName);            // Gcad(Modify)
  virtual const OdChar* columnName() const;		                  // Gcad(Modify)

  OdDbDataCellPtr getCellAt(OdUInt32 index) const;                // Gcad(Modify)
  void setCellAt(OdUInt32 index, const OdDbDataCellPtr cell);     // Gcad(Modify)

  virtual OdResult getCellAt(OdUInt32 index, OdDbDataCell& outCell) const; // Gcad(Add)
  virtual OdResult setCellAt(OdUInt32 index, const OdDbDataCell& cell);    // Gcad(Add)
  
  void appendCell(const OdDbDataCellPtr cell);           // Gcad(Modify)
  virtual OdResult appendCell(const OdDbDataCell& cell); // Gcad(Add)

  void insertCellAt(OdUInt32 index, const OdDbDataCellPtr& cell);          // Gcad(Modify)
  virtual OdResult insertCellAt(OdUInt32 index, const OdDbDataCell& cell); // Gcad(Add)
  
  virtual OdResult removeCellAt(OdUInt32 index); // Gcad(Modify)

  OdInt32  getIndexAtCell(const OdDbDataCellPtr& cell) const;                       // Gcad(Modify)
  virtual OdResult getIndexAtCell(const OdDbDataCell& cell, OdUInt32& index) const; // Gcad(Add)

  virtual OdUInt32 numCells() const;

  OdDbDataColumn(OdDbDataColumnImpl* m_pImpl);

protected:
  friend class OdDbSystemInternals;
  OdDbDataColumnImpl* m_pImpl;
};

typedef OdSmartPtr<OdDbDataColumn> OdDbDataColumnPtr;

class OdDbDataTableImpl;

/** Description:
    Library: TD_Db 
    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDataTable : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDataTable);
  
  OdDbDataTable(void);
// Gcad(ToDo) : implement operator=
  virtual OdDbDataTable& operator = (const OdDbDataTable& table);
  OdResult audit(OdDbAuditInfo* pAuditInfo);

  virtual OdUInt32 numColumns() const;
  virtual OdUInt32 numRows() const;

  virtual OdResult setNumRowsPhysicalSize(OdUInt32 n); // Gcad(Modify)
  virtual OdResult setNumRowsGrowSize(OdUInt32 n);     // Gcad(Modify)

  virtual OdUInt32 numRowsPhysicalSize() const;
  virtual OdUInt32 numRowsGrowSize() const;

  virtual OdResult setNumColsPhysicalSize(OdUInt32 n); // Gcad(Modify)
  virtual OdResult setNumColsGrowSize(OdUInt32 n);     // Gcad(Modify)

  virtual OdUInt32 numColsPhysicalSize() const;
  virtual OdUInt32 numColsGrowSize() const;
  
  virtual const OdChar* tableName() const;		        // Gcad(Modify) 
  virtual OdResult setTableName(const OdChar* pName);	// Gcad(Modify)

  OdDbDataColumnPtr getColumnAt(OdUInt32 index) const; // Gcad(Modify) 
  OdString columnNameAt(OdUInt32 index) const;		   // Gcad(Modify)

  virtual OdResult getColumnAt(	// Gcad(Add)
	  OdUInt32 index,
	  const OdDbDataColumn*& pCol) const;

  virtual OdResult getColumnNameAt( // Gcad(Add)
	  OdUInt32 index,
	  OdChar*& pName) const;
  
  OdDbDataCell::CellType columnTypeAt(OdUInt32 index) const; // Gcad(Modify)
  OdInt32 columnIndexAtName (const OdString& name) const;    // Gcad(Modify)

  virtual OdResult getColumnTypeAt( // Gcad(Add)
	  OdUInt32 index,
	  OdDbDataCell::CellType& type) const;

  virtual OdResult getColumnIndexAtName( // Gcad(Add)
	  const OdChar* name,
	  OdUInt32& index) const;
	  
  virtual  OdResult appendColumn( // Gcad(Modify)
      OdDbDataCell::CellType type, const OdChar* colName = NULL);
  virtual  OdResult insertColumnAt(OdUInt32 index,  // Gcad(Modify)
      OdDbDataCell::CellType type, const OdChar* colName = NULL);
  virtual  OdResult removeColumnAt(OdUInt32 index); // Gcad(Modify)

  virtual OdResult getRowAt(OdUInt32 index, // Gcad(Modify)
      OdDbDataCellArray& outRow) const;
  virtual OdResult setRowAt(OdUInt32 index, // Gcad(Modify)
      const OdDbDataCellArray& row, bool bValidate = true);

  virtual OdResult appendRow(	// Gcad(Modify)
      const OdDbDataCellArray& row, bool bValidate = true);

  virtual OdResult insertRowAt(OdUInt32 index, // Gcad(Modify)
      const OdDbDataCellArray& row, bool bValidate = true);

  virtual OdResult removeRowAt(OdUInt32 index); // Gcad(Modify)
  
  OdDbDataCellPtr getCellAt(OdUInt32 row, OdUInt32 col) const; // Gcad(Modify)
  void setCellAt(OdUInt32 row, OdUInt32 col, const OdDbDataCellPtr& cell); // Gcad(Modify)

  virtual OdResult getCellAt(	// Gcad(Add)
	  OdUInt32 row, OdUInt32 col,
	  OdDbDataCell& outCell) const;

  virtual OdResult setCellAt(	// Gcad(Add)
	  OdUInt32 row, OdUInt32 col,
	  const OdDbDataCell& cell);

  //********************************************************************
  // Overridden methods from OdDbObject
  //********************************************************************
  //

  virtual OdResult  dwgInFields(
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields( // Gcad(Modify)
    OdDbDwgFiler* pFiler) const;
  virtual OdResult  dxfInFields(
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(	// Gcad(Modify)
    OdDbDxfFiler* pFiler) const;

  // virtual   audit(OdDbAuditInfo* pAuditInfo);
};

typedef OdSmartPtr<OdDbDataTable> OdDbDataTablePtr;

#include "TD_PackPop.h"

#endif
