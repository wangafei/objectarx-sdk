///////////////////////////////////////////////////////////////////////////////
// Copyright ?2006, Open Design Alliance Inc. ("Open Design") 
// 
// This software is owned by Open Design, and may only be incorporated into 
// application programs owned by members of Open Design subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with 
// Open Design. The structure and organization of this Software are the valuable 
// trade secrets of Open Design and its suppliers. The Software is also protected 
// by copyright law and international treaty provisions. Application 
// programs incorporating this software must include the following statement 
// with their copyright notices:
//
//      DWGdirect ?2006 by Open Design Alliance Inc. All rights reserved. 
//
// By use of this software, you acknowledge and accept the terms of this 
// agreement.
///////////////////////////////////////////////////////////////////////////////

#ifndef _OD_DB_APP_SYSTEM_VARIABLES_
#define _OD_DB_APP_SYSTEM_VARIABLES_

//////////////////////////////////////////////////////////////////////////

#include "OdPlatformSettings.h"

//////////////////////////////////////////////////////////////////////////

#include "TD_PackPush.h"

enum
{
  kGroupsOn     = 0x01,
  kHatchAssocOn = 0x02
};

class TOOLKIT_EXPORT OdDbAppSystemVariables
{
public:
  OdDbAppSystemVariables() {}; 
  ~OdDbAppSystemVariables() {};

  // ATTDIA
  OdResult setAttdia(bool value, bool bUndo = false);
  bool attdia() const;

  // ATTREQ
  OdResult setAttreq(bool value, bool bUndo = false);
  bool attreq() const;

  // BLIPMODE
  OdResult setBlipmode(bool value, bool bUndo = false);
  bool blipmode() const;

  // COORDS
  OdResult setCoords(OdInt16 value, bool bUndo = false);
  OdInt16 coords() const;

  // STATUSBAR
  OdResult setStatusbar(OdInt16 value, bool bUndo = false);
  inline OdInt16 statusbar() const;
  
  // MENUBAR
  OdResult setMenubar(bool value, bool bUndo = false);
  inline bool menubar() const;
  
  // APPSTATUSBARUSEICONS
  OdResult setAppStatusBarUseIcons(bool value, bool bUndo = false);
  inline bool appstatusbaruseicons() const;
  
  // DELOBJ
  OdResult setDelUsedObj(OdInt16 value, bool bUndo = false);
  OdInt16 delUsedObj() const;

  // DRAGMODE
  OdResult setDragmode(OdInt16 value, bool bUndo = false);
  OdInt16 dragmode() const;

  // OSMODE
  OdResult setOsmode(OdInt16 value, bool bUndo = false);
  OdInt16 osmode() const;

  // PICKSTYLE
  OdResult setPickstyle(OdInt16 value, bool bUndo = false);
  OdInt16 pickstyle() const;

  // LWDEFAULT 
  OdResult setLwdefault(OdDb::LineWeight value, bool bUndo = false);
  OdDb::LineWeight lwdefault() const;

  // HPASSOC
  OdResult setHpassoc(bool value, bool bUndo = false);
  bool hpassoc() const;
};

#include "TD_PackPop.h"

#endif //_ODDB_APP_SYSTEM_VARIABLES_
