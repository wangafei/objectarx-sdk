#pragma once
#ifndef   _ZACED_XREF_H
#define   _ZACED_XREF_H

enum xrefSubcommandActivities
{
    kStart = 0,
    kStartItem = 2,
    kEndItem = 3,
    kEnd = 4,
    kWillAbort = 5,
    kAborted = 6,
    kStartXBindBlock = 7,
    kStartXBindSymbol = 8
};

#endif
