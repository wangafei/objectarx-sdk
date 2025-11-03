/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

class GCDB_PORT GcDbSectionablePE : public GcRxObject
{
public:
  GCRX_DECLARE_MEMBERS(GcDbSectionablePE);

  virtual bool supportSection(const GcDbObject& pObject) = 0;
};