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

#ifndef OdDbCompoundObjectId_INCLUDED
#define OdDbCompoundObjectId_INCLUDED

#include "RxObject.h"
#include "DbObjectId.h"
#include "IdArrays.h"

class OdDbDwgFiler;
class OdDbDxfFiler;

class OdGeMatrix3d;
class OdDbIdMapping;
class OdDbCompoundObjectIdImpl;

#include "TD_PackPush.h"

/** Description:

    {group:OdDb_Classes}
*/
class TOOLKIT_EXPORT OdDbCompoundObjectId : public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdDbCompoundObjectId);

    OdDbCompoundObjectId();

    OdDbCompoundObjectId(const OdDbObjectId& id, OdDbDatabase* pHostDatabase = NULL);

    OdDbCompoundObjectId(const OdDbCompoundObjectId&);

    OdDbCompoundObjectId(const OdDbObjectId& id, const OdDbObjectIdArray& path, OdDbDatabase* pHostDatabase = NULL);

    virtual ~OdDbCompoundObjectId();

    OdDbCompoundObjectId& operator =(const OdDbObjectId&);
    OdDbCompoundObjectId& operator =(const OdDbCompoundObjectId&);

    bool operator ==(const OdDbCompoundObjectId&) const;
    bool operator !=(const OdDbCompoundObjectId& other) const;

    OdDbObjectId topId() const;

    OdDbObjectId leafId() const;

    OdResult getFullPath(OdDbObjectIdArray& fullPath) const;

    OdResult getPath(OdDbObjectIdArray& path) const;

    void setEmpty();

    OdResult set(const OdDbObjectId&, OdDbDatabase* pHostDatabase = NULL);

    OdResult set(const OdDbCompoundObjectId&, OdDbDatabase* pHostDatabase = NULL);

    OdResult set(const OdDbObjectId& id, const OdDbObjectIdArray& path, OdDbDatabase* pHostDatabase = NULL);

    OdResult setFullPath(const OdDbObjectIdArray& fullPath, OdDbDatabase* pHostDatabase = NULL);

    bool isEmpty() const;

    bool isValid(int validityCheckingLevel = 1) const;

    bool isExternal() const;

    bool isSimpleObjectId() const;

    enum Status
    {
      kValid = 0,  // Good to go, can be Null
      kWasLoadedNowUnloaded = 1,  // Loaded during dwgOpen, then xref was unloaded
      kCouldNotResolveNonTerminal = 2,  // Couldn't be resolved - xref not found, unloaded when last saved, etc. non-terminal
      kCouldNotResolveTerminal = 3,  // Couldn't be resolved, bad sceario - xref dwg replaced, not referenced, etc.
	  kCouldNotResolveTooEarly = 4,  // Couldn't be resolved yet - too early - xref not finished resolving
      kIncompatibleIdType = 1000,
    };

    Status status() const;

    OdResult getTransform(OdGeMatrix3d& trans) const;

    bool remap(const OdDbIdMapping& idMap);

    OdResult dwgOutFields(OdDbDwgFiler* pFiler, OdDbDatabase* pHostDatabase) const;

    OdResult dwgInFields(OdDbDwgFiler* pFiler, int ownerVersion);

    OdResult dxfOutFields(OdDbDxfFiler* pFiler, OdDbDatabase* pHostDatabase) const;

    OdResult dxfInFields(OdDbDxfFiler* pFiler, OdDbDatabase* pHostDatabase, int ownerVersion);

    static const OdDbCompoundObjectId& nullId();

protected:

    OdDbCompoundObjectId(OdDbCompoundObjectIdImpl*);

    OdDbCompoundObjectIdImpl* m_pImpl;
};

inline bool OdDbCompoundObjectId::operator !=(const OdDbCompoundObjectId& other) const { return !(*this == other); }

typedef OdSmartPtr<OdDbCompoundObjectId> OdDbCompoundObjectIdPtr;

#include "TD_PackPop.h"

#endif
