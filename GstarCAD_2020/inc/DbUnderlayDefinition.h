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


#ifndef __OD_DB_UNDERLAY_DEFINITION__
#define __OD_DB_UNDERLAY_DEFINITION__

#include "TD_PackPush.h"

#include "DbObject.h"
#include "DbUnderlayHost.h"

class IGcReadStream;

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbUnderlayDefinition : public OdDbObject
{
public:
  ODDB_DECLARE_MEMBERS(OdDbUnderlayDefinition);

  OdDbUnderlayDefinition();
  virtual ~OdDbUnderlayDefinition();
  OdResult setSourceFileName(const OdChar* name);
  const OdChar* getSourceFileName() const;

  IGcReadStream* getReadStream() const;

  OdString getActiveFileName() const;
  OdResult getActiveFileName(const OdChar*& file) const;
  OdResult getActiveFileName(OdString& file) const;

  OdResult setItemName(const OdChar* item);
  const OdChar* getItemName() const;

  OdResult setUnderlayItem(const OdChar* sourceFileName, const OdChar* activeFileName, OdDbUnderlayItem* pItem);
  OdDbUnderlayItemPtr getUnderlayItem(ODSYSDEF) const;
  OdDbUnderlayItem* getUnderlayItem() const;

  OdResult load(const wchar_t* password);
  void unload();
  bool isLoaded() const;
  static OdString dictionaryKey(const OdRxClass* underlayDefinitionType);

  virtual OdResult dwgInFields(
    OdDbDwgFiler* pFiler);

  virtual OdResult dwgOutFields(
    OdDbDwgFiler* pFiler) const;

  virtual OdResult dxfInFields(
    OdDbDxfFiler* pFiler);

  virtual OdResult dxfOutFields(
    OdDbDxfFiler* pFiler) const;

  virtual OdDbObjectId postDefinitionToDb(OdDbDatabase* pDb, const OdString& defName);

  virtual OdResult subClose();
};

typedef OdSmartPtr<OdDbUnderlayDefinition> OdDbUnderlayDefinitionPtr;


// These inheritants are for registering OdDbUnderlayHostPE protocol extension

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDwfDefinition : public OdDbUnderlayDefinition
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDwfDefinition);
  
  OdDbDwfDefinition();
  virtual ~OdDbDwfDefinition();
  OdBool isDWFx(void) const;
};

typedef OdSmartPtr<OdDbDwfDefinition> OdDbDwfDefinitionPtr;


/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbDgnDefinition : public OdDbUnderlayDefinition
{
public:
  ODDB_DECLARE_MEMBERS(OdDbDgnDefinition);

  OdDbDgnDefinition();

  // Specific DGNUnderlay functions
  virtual ~OdDbDgnDefinition();
  bool useMasterUnits() const;
  void setUseMasterUnits(bool useMaster);

  int xrefDepth() const;
  void setXrefDepth(int depth);

  bool showRasterRef() const;
  void setShowRasterRef(bool bShow);
};

typedef OdSmartPtr<OdDbDgnDefinition> OdDbDgnDefinitionPtr;

/** Description:

{group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbPdfDefinition : public OdDbUnderlayDefinition
{
public:
  ODDB_DECLARE_MEMBERS(OdDbPdfDefinition);

  OdDbPdfDefinition();

  virtual ~OdDbPdfDefinition();
};

typedef OdSmartPtr<OdDbPdfDefinition> OdDbPdfDefinitionPtr;

#include "TD_PackPop.h"

#endif // __OD_DB_UNDERLAY_DEFINITION__
