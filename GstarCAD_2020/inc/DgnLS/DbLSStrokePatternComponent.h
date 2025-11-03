/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2014, Open Design Alliance (the "Alliance"). 
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
//   Teigha(R) Copyright (C) 2003-2014 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
///////////////////////////////////////////////////////////////////////////////

#ifndef ODDGNLS_DBLSSTROKEPATTERNCOMPONENT_H
#define ODDGNLS_DBLSSTROKEPATTERNCOMPONENT_H

#include "DbLSComponent.h"
#include "DbLSStroke.h"

#include "TD_PackPush.h"

/** Description:
    Dgn Line Style Stroke Pattern Component.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
class ODDGNLS_EXPORT OdDbLSStrokePatternComponent : public OdDbLSComponent
{
  public:
    enum PhaseMode
    {
      kLSPhaseDistance = 0, // Distance phase mode
      kLSPhaseFraction = 1, // Fraction phase mode (auto phase)
      kLSPhaseCentered = 2  // Centered phase mode (stretch phase mode)
    };
  public:
    ODDB_DECLARE_MEMBERS(OdDbLSStrokePatternComponent);

    OdDbLSStrokePatternComponent();

    /**
      Description:
      Returns phase for fraction phase mode.

      Remarks:
      Null for non-fraction phase modes.
    */
    double autoPhase() const;
    /**
      Description:
      Sets phase for fraction phase mode.

      Arguments:
      fPhase (I) New phase value to set.
    */
    void setAutoPhase(double fPhase);

    /**
      Description:
      Returns true if iteration limit mode is enabled.
    */
    bool hasIterationLimit() const;
    /**
      Description:
      Sets iteration limit mode.

      Arguments:
      bSet (I) New mode to set.
    */
    void setHasIterationLimit(bool bSet);

    /**
      Description:
      Inserts new stroke into this stroke pattern component.

      Arguments:
      fLength (I) Stroke length.
      fStartWidth (I) Stroke start width.
      fEndWidth (I) Stroke end width.
      widthMode (I) Stroke width mode.
      capMode (I) Stroke caps type.
      Remarks:
      Returns pointer to newly added stroke which could be used for additional modifications.
    */
    OdDbLSStroke *insertStroke(double fLength = 1.0, double fStartWidth = 0.0, double fEndWidth = 0.0,
      OdDbLSStroke::WidthMode widthMode = OdDbLSStroke::kLSNoWidth, OdDbLSStroke::CapMode capMode = OdDbLSStroke::kLSCapsClosed);
    /**
      Description:
      Inserts new stroke into this stroke pattern component as copy of existing stroke.

      Arguments:
      pStroke (I) Stroke for clone.
      Remarks:
      Returns pointer to newly added stroke which could be used for additional modifications.
    */
    OdDbLSStroke *insertStroke(const OdDbLSStroke *pStroke);
    /**
      Description:
      Returns stroke pointer from this stroke pattern component.

      Arguments:
      nStroke (I) Stroke index.
    */
    OdDbLSStroke *stroke(OdUInt32 nStroke) const;

    /**
      Description:
      Removes existing stroke from this stroke pattern component.

      Arguments:
      nStroke (I) Stroke index.
    */
    void deleteStroke(OdUInt32 nStroke);

    /**
      Description:
      Returns count of strokes in this stroke pattern component.
    */
    OdUInt32 numberStrokes() const;

    /**
      Description:
      Returns true if single segment mode is enabled.
    */
    bool isSingleSegment() const;
    /**
      Description:
      Enables single segment mode.

      Arguments:
      bSet (I) New mode to set.
    */
    void setIsSingleSegment(bool bSet);

    /**
      Description:
      Returns iteration limit.
    */
    OdInt32 iterationLimit() const;
    /**
      Description:
      Sets iteration limit.

      Arguments:
      nLimit (I) New limit to set.
    */
    void setIterationLimit(OdInt32 nLimit);

    /**
      Description:
      Returns phase for distance phase mode.

      Remarks:
      Null for non-distance phase modes.
    */
    double phase() const;
    /**
      Description:
      Sets phase for distance phase mode.

      Arguments:
      fPhase (I) New phase value to set.
    */
    void setPhase(double fPhase);

    /**
      Description:
      Returns current phase mode.
    */
    PhaseMode phaseMode() const;
    /**
      Description:
      Resets current phase mode.

      Arguments:
      mode (I) New phase mode to set.
    */
    void setPhaseMode(PhaseMode mode);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLSStrokePatternComponent object pointers.
*/
typedef OdSmartPtr<OdDbLSStrokePatternComponent> OdDbLSStrokePatternComponentPtr;

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSSTROKEPATTERNCOMPONENT_H
