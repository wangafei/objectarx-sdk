#pragma once
#ifndef   _ZACED_HATCH_H
#define   _ZACED_HATCH_H

enum ZcHatchNotifier {
    kNobody           = 0x00,
    kImpHatch         = 0x01,
    kBoundary         = 0x02,
    kHatchAndBoundary = (kImpHatch | kBoundary),
    kAddScale         = 0x04
};

enum ZcHatchEdReact
{
    kStartHatchWatcher = 1,
    kSwapHatchId,
    kUpRootHatchWatcher,
    kDestroyHatchWatcher,
    kDisableNextStart,
    kRecomputeBoundary
};

#endif
