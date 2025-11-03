/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#ifndef   _GCED_HATCH_H
#define   _GCED_HATCH_H

enum GcHatchNotifier {
  kNobody = 0x00,
  kImpHatch = 0x01,
  kBoundary = 0x02,
  kHatchAndBoundary = (kImpHatch | kBoundary),
  kAddScale = 0x04
};

enum GcHatchEdReact
{
  kStartHatchWatcher = 1,
  kSwapHatchId,
  kUpRootHatchWatcher,
  kDestroyHatchWatcher,
  kDisableNextStart,
  kRecomputeBoundary
};

#endif
