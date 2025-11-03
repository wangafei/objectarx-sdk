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



#ifndef OD_DBDATALINK_H
#define OD_DBDATALINK_H

#include "DbObject.h"
#include "OdValue.h"
#include "StringArray.h"

#include "TD_PackPush.h"

#include "OdDb.h"

/** Description:
    This class links a table to data in another file.

    Library:
    TD_Db
    
    {group:OdDb_Classes} 

*/
class TOOLKIT_EXPORT OdDbDataLink : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDataLink);

  OdDbDataLink(void);
  virtual ~OdDbDataLink(void);

  OdString name (void) const;
  OdResult setName(const OdChar* pszName);
  OdString description (void) const;
  OdResult setDescription(const OdChar* pszDescription);
  OdString getToolTip (void) const;
  OdResult setToolTip(const OdChar* pszToolTip);
  OdString  dataAdapterId (void) const;
  OdResult setDataAdapterId(const OdChar* pszAdapterId);
  OdString  connectionString (void) const;
  OdResult setConnectionString(const OdChar* pszConnectionString);
  OdDb::DataLinkOption option (void) const;
  OdResult setOption (OdDb::DataLinkOption nOption);
  OdInt32 updateOption (void) const;
  OdResult setUpdateOption(OdInt32 nOption);
  OdResult update (OdDb::UpdateDirection nDir, OdDb::UpdateOption nOption);
  OdResult getUpdateStatus(OdDb::UpdateDirection* pDir, 
    OdTimeStamp* pTime, 
    OdString* pErrMessage) const;
  OdResult getUpdateStatus(OdDb::UpdateDirection* pDir, SYSTEMTIME* pTime, OdString* pErrMessage) const;
  OdResult setUpdateStatus(const OdChar* pszErrMessage);
  bool isValid (void) const;
  OdInt32 getTargets (OdDbObjectIdArray& targetIds) const;
  OdResult getSourceFiles(OdDb::DataLinkGetSourceContext nContext, 
    OdStringArray& files) const;
  OdResult repathSourceFiles(OdString& sBasePath, OdDb::PathOption nOption);
  OdResult repathSourceFiles(LPCTSTR pszBasePath, OdDb::PathOption nOption);
  OdValue getCustomData(const OdString& sKey) const;
  OdResult getCustomData(const OdChar* pszKey, OdValue* pData) const;
  OdResult setCustomData(const OdChar* pszKey,const OdValue* pData);
  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);
  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;
  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);
  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;
};

typedef OdArray<OdDbDataLink*> OdDbDataLinkArray;

typedef OdSmartPtr<OdDbDataLink> OdDbDataLinkPtr;

//*************************************************************************
// OdDbDataLinkManager
//*************************************************************************
class OdDbDataLinkManagerImpl;
class TOOLKIT_EXPORT OdDbDataLinkManager : public OdRxObject
{
public:
  ODRX_DECLARE_MEMBERS(OdDbDataLinkManager);

  virtual ~OdDbDataLinkManager(void);

  OdResult createDataLink(const OdChar* pszAdapterId,
    const OdChar* pszName,
    const OdChar* pszDescription,
    const OdChar* pszConnectionString,
    OdDbObjectId& idDataLink);
  OdResult getDataLink(const OdChar* pszName,
    OdDbObjectId& idDataLink) const;
  OdResult getDataLink(const OdChar* pszName, OdDbDataLink*& pDataLink, OdDb::OpenMode mode) const;
  int dataLinkCount(void) const;
  int getDataLink(OdDbObjectIdArray& dataLinks) const;
  OdResult addDataLink(OdDbDataLink* pDataLink);
  OdResult addDataLink(OdDbDataLink* pDataLink, OdDbObjectId& idDataLink);
  OdResult removeDataLink(const OdChar* pszKey,
    OdDbObjectId& idDataLink);
  OdResult removeDataLink(const OdDbObjectId& idDataLink);
  OdResult update(const OdDbObjectIdArray& dataIds, OdDb::UpdateDirection nDir, OdDb::UpdateOption nOption);
  OdResult update(OdDb::UpdateDirection nDir, OdDb::UpdateOption nOption);

protected:
  OdDbDataLinkManager(void);
  OdDbDataLinkManager(OdDbDataLinkManagerImpl* pValImpl);

protected:
  //void* mpImpObj;
  //friend OdTableSystemInternals;

  friend OdDbDataLinkManagerImpl;
  OdDbDataLinkManagerImpl* m_pImpl;
};

#include "TD_PackPop.h"

#endif // OD_DBDATALINK_H
