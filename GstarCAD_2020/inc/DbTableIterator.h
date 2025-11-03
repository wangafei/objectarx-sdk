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

#ifndef OD_DBTABLEITERATOR_H
#define OD_DBTABLEITERATOR_H

class OdCell;
class OdCellRange;
class OdDbTable;
class OdDbLinkedTableData;

//*************************************************************************
// OdDbTableIterator
//*************************************************************************

class OdDbTableIterator
{
public:
  OdDbTableIterator(const OdDbTable* pTable);
  OdDbTableIterator(const OdDbTable* pTable, const OdCellRange* pRange, OdDb::TableIteratorOption nOption);
  OdDbTableIterator(const OdDbLinkedTableData* pTable);
  OdDbTableIterator(const OdDbLinkedTableData* pTable, const OdCellRange* pRange, OdDb::TableIteratorOption nOption);
  OdDbTableIterator(const OdCellRange& range);
  OdDbTableIterator(const OdCellRange& range, OdDb::TableIteratorOption nOption);
  ~OdDbTableIterator();

  void start (void);
  void step(void);
  bool done(void);
  bool seek(const OdCell& cell);
  const OdCell& getCell(void) const;
  int getRow(void) const;
  int getColumn(void) const;

protected:
  OdDbTableIterator(void);

protected:
  void* mpImpObj;
};

#endif // OD_DBTABLEITERATOR_H