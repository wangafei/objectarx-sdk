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

#ifndef _OdError_h_Included_
#define _OdError_h_Included_

namespace Oda
{

#define OD_ERROR_DEF(code, string)  code,
enum OdResult
{
#include "ErrorDefs.h"
  eDummyLastError
};
#undef OD_ERROR_DEF

typedef OdResult ErrorStatus;

#define OD_MESSAGE_DEF(code, string)  code,
enum OdMessage
{
  sidDummyFirstMessage = eDummyLastError -1,
#include "MessageDefs.h"
  sidDummyLastMessage
};
#undef OD_MESSAGE_DEF

// PointHistory
enum PointHistory
{
  eTablet       = 0x0001,
  eNotDigitizer = 0x0002,
  eLastPt       = 0x0004,
  eGripped      = 0x0008,
  eCartSnapped  = 0x0010,
  eOrtho        = 0x0020,
  eCyclingPt    = 0x0040,
  eOsnapped     = 0x0080,
  ePolarAngle   = 0x0100,
  eAligned      = 0x0400,

  eAppFiltered  = 0x0800,

  eForcedPick   = 0x1000,
  ePickMask     = 0xE000,
  eDidNotPick   = 0x0000,

  eUsedPickBox  = 0x2000,
  eUsedOsnapBox = 0x4000,
  ePickAborted  = 0x8000,
  eXPending     = 0x10000,
  eYPending     = 0x20000,
  eZPending     = 0x40000,
  eCoordPending = 0x70000, 
  eFromKeyboard = 0x80000,
  eNotInteractive = 0x100000, 
  eDirectDistance = 0x200000,
};

// PromptStatus
enum PromptStatus
{
  eNone     =  5000,
  eModeless =  5027,
  eNormal   =  5100,
  eError    = -5001,
  eCancel   = -5002,
  eRejected = -5003,
  eFailed   = -5004,
  eKeyword  = -5005,
  eDirect   = -5999
};

}; //namespace Oda

using namespace Oda;

class OdErrorContext;

#include "TD_PackPush.h"
#include "OdString.h"

/** Description:
This class implement OdError node objects in an OdErrorNode stack..

Remarks:
Each Error object points to the previous Error object in the stack.

Library: TD_Root
{group:Error_Classes} 
*/
class FIRSTDLL_EXPORT OdError
{
  OdErrorContext* m_pContext;
public:
  void setContext(OdErrorContext* pErrorContext);
  const OdErrorContext* context() const;
  OdErrorContext* context();

  /** Arguments:
  code (I) Error *code*.
  */
  explicit OdError(OdResult code);
  OdError(const OdError& source);

  /** Arguments:
  pErrorContext (I) Pointer to the ErrorContext.
  */
  explicit OdError(OdErrorContext* pErrorContext);

  /** Arguments:
  errorMessage (I) Error message.
  */
  explicit OdError(const OdString& errorMessage);

  /** Arguments:
  previousError (I) Previous Error object.
  */
  OdError(const OdString& errorMessage, const OdError& previousError);
  ~OdError();

  OdError& operator = (const OdError& source);

  /** Description:
  Returns the OdResult *code* of this Error object.
  */
  OdResult code() const;

  /** Description:
  Returns the *description* of this Error object.
  */
  OdString description() const;

  /** Description:
  Sets the Error object previous to this one in this Error stack.
  Arguments:
  previousError (I) Previous Error object.
  */
  void attachPreviousError(const OdError& previousError);
};

typedef OdResult OdWarning;

#include "TD_PackPop.h"

#endif
