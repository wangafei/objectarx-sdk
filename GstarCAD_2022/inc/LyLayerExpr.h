#pragma once
#include "LyLayerFilter.h"

class OdLyRelExpr
{
public:
  virtual const OdChar * getVariable() const = 0;
  virtual const OdChar * getConstant() const = 0;
};

class OdLyAndExpr
{
public:
  virtual ~OdLyAndExpr() { }
  virtual const OdArray<OdLyRelExpr*>& getRelExprs() const = 0;
};

class OdLyBoolExpr
{
public:
  virtual ~OdLyBoolExpr() { }
  virtual const OdArray<OdLyAndExpr*>& getAndExprs() const = 0;
};

