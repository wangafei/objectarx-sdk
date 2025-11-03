#pragma once

#define AcFileSelectFlags  GcFileSelectFlags
#define GcFileSelectFlags  OdFileSelectFlags

enum OdFileSelectFlags
{

  kDLFNoType = 0x0,

  kDLFPut = 0x1,

  kDLFDwg = 0x2,

  kDLFPathOnly = 0x4,

  kDLFNoWarn = 0x8,

  kDLFNoExistOk = 0x10,

  kDLFAnyExt = 0x20,

  kDLFRqBox = 0x40,

  kDLFSaveas = 0x80,

  kDLFNoLib = 0x0100,

  kDLFNoXfer = 0x0200,

  kDLFNoURLs = 0x0400,

  kDLFDwgDef = 0x0800,

  kDLFOpenDef = 0x1000,

  kDLFDvc = 0x2000,

  kDLFDwt = 0x4000,

  kDLFOpts = 0x8000,

  kDLFNoPopup = 0x10000,

  kDLFFrcWarn = 0x20000,

  kDLFMulti = 0x40000,

  kDLFCLI = 0x80000,

  kDLFRecover = 0x100000,

  kDLFForceDir = 0x200000,

  kDLFNoFTP = 0x400000,

  kDLFNoAnav = 0x800000,

  kDLFFolders = 0x1000000,

  kDLFNoExtensions = 0x2000000,

  kDLFNoTemplate = 0x4000000,

  kDLFExport = 0x8000000
};
