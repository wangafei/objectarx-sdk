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


#ifndef OD_DBHATCH_PATTERN_MANAGER
#define OD_DBHATCH_PATTERN_MANAGER

#include "OdString.h"
#include "Ge/GePoint2d.h"
#include "DbHatch.h"
#include "Ge/GeDoubleArray.h"
#include "StringArray.h"

#include "TD_PackPush.h"


/** Description:
    This class manages hatch patterns within a Teigha application.
    Library: TD_Db
    {group:Other_Classes}
*/
class ODRX_ABSTRACT TOOLKIT_EXPORT OdHatchPatternManager : public OdRxObject
{
protected:
  OdHatchPatternManager() {}
public:
  ODRX_DECLARE_MEMBERS(OdHatchPatternManager);

  /** Description:
    Sets the Host Application Services object for this hatchPatternManager object.
    Arguments:
    pServices (I) Pointer to the HostAppServices object.
  */
  virtual void setApplicationService(OdDbHostAppServices *pServices) = 0;

  /** Description:
    Retrieves the specified hatch pattern from this hatchPatternManager object.
    Arguments:
    hatchPatternName (I) Hatch pattern name.
    hatchPatternType (I) Hatch pattern type.
    measurementValue (I) Measurement value.  
    hatchPattern (O) Hatch pattern.
    
    Remarks:
    hatchPatternType must be one of the following:
    
    @table
    Name                        Value    Description
    OdDbHatch::kUserDefined     0        User-defined hatch.
    OdDbHatch::kPreDefined      1        Defined in acad.pat and acadiso.pat. 
    OdDbHatch::kCustomDefined   2        In its own PAT file.
    
    measurementValue must be one of the following:

    @table
    Name             Value
    OdDb::kEnglish   0
    OdDb::kMetric    1
  */
  virtual OdResult retrievePattern(OdDbHatch::HatchPatternType hatchPatternType, const OdString& hatchPatternName, 
    OdDb::MeasurementValue measurementValue, OdHatchPattern& hatchPattern) = 0;

  /** Description:
    Appends the specified hatch pattern to this hatchPatternManager object.

    Arguments:
    hatchPatternName (I) Hatch pattern name.
    hatchPatternType (I) Hatch pattern type.
    measurementValue (I) Measurement value.  
    hatchPattern (I) Hatch pattern.
    
    Remarks:
    hatchPatternType must be one of the following:
    
    @table
    Name                        Value    Description
    OdDbHatch::kUserDefined     0        User-defined hatch.
    OdDbHatch::kPreDefined      1        Defined in acad.pat and acadiso.pat. 
    OdDbHatch::kCustomDefined   2        In its own PAT file.
    
    measurementValue must be one of the following:

    @table
    Name             Value
    OdDb::kEnglish   0
    OdDb::kMetric    1
  */
  virtual void appendPattern(OdDbHatch::HatchPatternType hatchPatternType, const OdString& hatchPatternName, 
                             const OdHatchPattern& hatchPattern, OdDb::MeasurementValue measurementValue = OdDb::kEnglish) = 0;

  /** Description:
    Retrieves names of loaded patterns.

    Arguments:
    hatchPatternType (I) Hatch pattern type.
    measurementValue (I) Measurement value.  
    patternNames (O) Receive loaded pattern names.
    
    Remarks:
    hatchPatternType must be one of the following:
    
    @table
    Name                        Value    Description
    OdDbHatch::kUserDefined     0        User-defined hatch.
    OdDbHatch::kPreDefined      1        Defined in acad.pat and acadiso.pat. 
    OdDbHatch::kCustomDefined   2        In its own PAT file.
    
    measurementValue must be one of the following:

    @table
    Name             Value
    OdDb::kEnglish   0
    OdDb::kMetric    1
  */
  virtual OdResult retrievePatternList(OdDbHatch::HatchPatternType hatchPatternType, OdDb::MeasurementValue measurementValue,
                                       OdStringArray& patternNames) = 0;
};
/** Description:
  This template class is a specialization of the OdSmartPtr class for OdHatchPatternManager object pointers.
*/
typedef OdSmartPtr<OdHatchPatternManager> OdHatchPatternManagerPtr;

#include "TD_PackPop.h"

#endif
