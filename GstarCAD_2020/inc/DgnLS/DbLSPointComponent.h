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

#ifndef ODDGNLS_DBLSPOINTCOMPONENT_H
#define ODDGNLS_DBLSPOINTCOMPONENT_H

#include "DbLSComponent.h"
#include "DbLSSymbolReference.h"

#include "TD_PackPush.h"

/** Description:
    Dgn Line Style Point Component.
    Library:
    TD_Db
    {group:OdDbLS_Classes} 
*/
class ODDGNLS_EXPORT OdDbLSPointComponent : public OdDbLSComponent
{
  public:
    ODDB_DECLARE_MEMBERS(OdDbLSPointComponent);

    OdDbLSPointComponent();

    /**
      Description:
      Inserts new symbol for stroke into this point component.

      Arguments:
      symCompId (I) Identifier of symbol to set.
      fXOffset (I) Symbol offset in X direction.
      fYOffset (I) Symbol offset in Y direction.
      fAngle (I) Symbol rotation angle in radians.
      nStroke (I) Index of stroke for symbol insert.
      Remarks:
      Returns pointer to newly added symbol reference which could be used for additional modifications.
    */
    OdDbLSSymbolReference *insertSymbolForStroke(const OdDbObjectId &symCompId, double fXOffset = 0.0, double fYOffset = 0.0, double fAngle = 0.0,
                                                 OdInt32 nStroke = 0);
    /**
      Description:
      Inserts new symbol for stroke into this point component.

      Arguments:
      symCompId (I) Identifier of symbol to set.
      nStroke (I) Index of stroke for symbol insert.
      Remarks:
      Returns pointer to newly added symbol reference which could be used for additional modifications.
    */
    OdDbLSSymbolReference *insertSymbolForStroke(const OdDbObjectId &symCompId, OdInt32 nStroke);
    /**
      Description:
      Inserts new symbol for stroke into this point component as copy of existing symbol.

      Arguments:
      pSymbol (I) Symbol reference for clone.
      nStroke (I) Index of stroke for symbol insert.
      Remarks:
      Returns pointer to newly added symbol reference which could be used for additional modifications.
    */
    OdDbLSSymbolReference *insertSymbolForStroke(const OdDbLSSymbolReference *pSymbol, OdInt32 nStroke);

    /**
      Description:
      Inserts new symbol for vertex into this point component.

      Arguments:
      symCompId (I) Identifier of symbol to set.
      fXOffset (I) Symbol offset in X direction.
      fYOffset (I) Symbol offset in Y direction.
      fAngle (I) Symbol rotation angle in radians.
      at (I) Type of vertex for this symbol.
      Remarks:
      Returns pointer to newly added symbol reference which could be used for additional modifications.
    */
    OdDbLSSymbolReference *insertSymbolForVertex(const OdDbObjectId &symCompId, double fXOffset = 0.0, double fYOffset = 0.0, double fAngle = 0.0,
                                                 OdDbLSSymbolReference::VertexMask at = OdDbLSSymbolReference::kLSAtOrigin);
    /**
      Description:
      Inserts new symbol for vertex into this point component.

      Arguments:
      symCompId (I) Identifier of symbol to set.
      at (I) Type of vertex for this symbol.
      Remarks:
      Returns pointer to newly added symbol reference which could be used for additional modifications.
    */
    OdDbLSSymbolReference *insertSymbolForVertex(const OdDbObjectId &symCompId, OdDbLSSymbolReference::VertexMask at);
    /**
      Description:
      Inserts new symbol for vertex into this point component as copy of existing symbol.

      Arguments:
      pSymbol (I) Symbol reference for clone.
      nStroke (I) Index of stroke for symbol insert.
      Remarks:
      Returns pointer to newly added symbol reference which could be used for additional modifications.
    */
    OdDbLSSymbolReference *insertSymbolForVertex(const OdDbLSSymbolReference *pSymbol, OdDbLSSymbolReference::VertexMask at);

    /**
      Description:
      Removes existing symbol for stroke from this point component.

      Arguments:
      nStroke (I) Index of stroke for remove symbol.
    */
    void deleteSymbolForStroke(OdInt32 nStroke);
    /**
      Description:
      Removes existing symbol for vertex from this point component.

      Arguments:
      at (I) Type of vertex for remove symbol.
    */
    void deleteSymbolForVertex(OdDbLSSymbolReference::VertexMask at);

    /**
      Description:
      Returns count of symbols in this point component symbols list.

      Remarks:
      Returns count of both symbol lists for stroke and for vertex.
    */
    OdUInt32 numberSymbols() const;

    /**
      Description:
      Returns stroke component identifier associated with this point component.
    */
    OdDbObjectId strokeComponent() const;
    /**
      Description:
      Sets stroke component identifier associated with this point component.

      Arguments:
      strokeCompId (I) Identifier of stroke component.
    */
    void setStrokeComponent(const OdDbObjectId &strokeCompId);

    /**
      Description:
      Returns symbol by index in point component symbols list.

      Arguments:
      nSym (I) Index of symbol.
    */
    OdDbLSSymbolReference *symbol(OdUInt32 nSym);
    /**
      Description:
      Returns symbol by stroke index.

      Arguments:
      nStroke (I) Stroke index.
    */
    OdDbLSSymbolReference *symbolForStroke(OdInt32 nStroke);
    /**
      Description:
      Returns symbol by vertex type.

      Arguments:
      at (I) Type of vertex.
    */
    OdDbLSSymbolReference *symbolForVertex(OdDbLSSymbolReference::VertexMask at);
};

/** Description:
    This template class is a specialization of the OdSmartPtr class for OdDbLSPointComponent object pointers.
*/
typedef OdSmartPtr<OdDbLSPointComponent> OdDbLSPointComponentPtr;

#include "TD_PackPop.h"

#endif // ODDGNLS_DBLSPOINTCOMPONENT_H
