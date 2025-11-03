#pragma  once
#include "AdCharFmt.h"
#include "../grx/GcCFileWrappers.h"

#define acByteSwap gcByteSwap
#define acWriteWCharToCFile gcWriteWCharToCFile
#define acReadCIFFromCFile gcReadCIFFromCFile
#define acReadAnsiCharFromCFile gcReadAnsiCharFromCFile
#define acReadUtf8CharFromCFile gcReadUtf8CharFromCFile
#define acReadUtf16CharFromCFile gcReadUtf16CharFromCFile
#define acCheckCFileCharFormat gcCheckCFileCharFormat

#define AcOutputBufMgr GcOutputBufMgr
#define AcCFile GcCFile
#define AcCStdioFile GcCStdioFile