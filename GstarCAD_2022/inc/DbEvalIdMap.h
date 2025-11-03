#pragma once

#include "TD_PackPush.h"

#include "DbEvalGraph.h"

class OdDbEvalIdMap
{
public:
  virtual OdDbEvalNodeId find(const OdDbEvalNodeId& key) = 0;
  virtual void kill() = 0;
};

#include "TD_PackPop.h"