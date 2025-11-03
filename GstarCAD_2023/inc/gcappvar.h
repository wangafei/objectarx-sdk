/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCAPPVAR_H
#define GCAPPVAR_H

#include "gcdb.h"
#include "gcadstrc.h"   
#pragma pack (push, 8)

enum {
  kGroupsOn = 0x01,
  kHatchAssocOn = 0x02
};

class GcDbAppSystemVariables {
public:
  inline GcDbAppSystemVariables();
  inline ~GcDbAppSystemVariables() {};

  Gcad::ErrorStatus setAttdia(bool value, bool bUndo = false);
  inline bool attdia() const;

  Gcad::ErrorStatus setAttreq(bool, bool bUndo = false);
  inline bool attreq() const;

  Gcad::ErrorStatus setBlipmode(bool, bool bUndo = false);
  inline bool blipmode() const;

  Gcad::ErrorStatus setCoords(Gsoft::Int16 value, bool bUndo = false);
  inline Gsoft::Int16 coords() const;

  Gcad::ErrorStatus setStatusbar(Gsoft::Int16 value, bool bUndo = false);
  inline Gsoft::Int16 statusbar() const;

  Gcad::ErrorStatus setMenubar(bool value, bool bUndo = false);
  inline bool menubar() const;

  Gcad::ErrorStatus setAppStatusBarUseIcons(bool value, bool bUndo = false);
  inline bool appstatusbaruseicons() const;

  Gcad::ErrorStatus setDelUsedObj(Gsoft::Int16, bool bUndo = false);
  inline Gsoft::Int16 delUsedObj() const;

  Gcad::ErrorStatus setDragmode(Gsoft::Int16, bool bUndo = false);
  inline Gsoft::Int16 dragmode() const;

  Gcad::ErrorStatus setOsmode(Gsoft::Int16 value, bool bUndo = false);
  inline Gsoft::Int16 osmode() const;

  Gcad::ErrorStatus setPickstyle(Gsoft::Int16 value, bool bUndo = false);
  inline Gsoft::Int16 pickstyle() const;

  Gcad::ErrorStatus setLwdefault(GcDb::LineWeight value, bool bUndo = false);
  inline GcDb::LineWeight lwdefault() const;

  Gcad::ErrorStatus setHpassoc(bool value, bool bUndo = false);
  inline bool hpassoc() const;

private:
  bool  m_attdia;
  bool  m_attreq;
  bool  m_blipmode;
  short m_delobj;
  short m_coords;
  short m_statusbar;
  bool  m_menubar;
  bool  m_appstatusbaruseicons;
  short m_dragmode;
  short m_osmode;
  short m_pkstyle;
  GcDb::LineWeight  m_lwdefault;
  bool  m_hpassoc;
};

inline
GcDbAppSystemVariables::GcDbAppSystemVariables()
  : m_attdia(true),
  m_attreq(true),
  m_blipmode(false),
  m_delobj(3),
  m_coords(0),
  m_statusbar(1),
  m_menubar(false),
  m_appstatusbaruseicons(true),
  m_dragmode(2),
  m_osmode(0),
  m_pkstyle(kGroupsOn),
  m_lwdefault(GcDb::kLnWt025),
  m_hpassoc(1)
{
}

inline bool GcDbAppSystemVariables::attdia() const
{
  return m_attdia;
}

inline bool GcDbAppSystemVariables::attreq() const
{
  return m_attreq;
}

inline bool GcDbAppSystemVariables::blipmode() const
{
  return m_blipmode;
}

inline Gsoft::Int16 GcDbAppSystemVariables::coords() const
{
  return m_coords;
}

inline Gsoft::Int16 GcDbAppSystemVariables::statusbar() const
{
  return m_statusbar;
}

inline bool GcDbAppSystemVariables::menubar() const
{
  return m_menubar;
}

inline bool GcDbAppSystemVariables::appstatusbaruseicons() const
{
  return m_appstatusbaruseicons;
}

inline Gsoft::Int16 GcDbAppSystemVariables::delUsedObj() const
{
  return m_delobj;
}

inline Gsoft::Int16 GcDbAppSystemVariables::dragmode() const
{
  return m_dragmode;
}

inline Gsoft::Int16 GcDbAppSystemVariables::osmode() const
{
  return m_osmode;
}

inline Gsoft::Int16 GcDbAppSystemVariables::pickstyle() const
{
  return m_pkstyle;
}

inline GcDb::LineWeight GcDbAppSystemVariables::lwdefault() const
{
  return m_lwdefault;
}

inline bool GcDbAppSystemVariables::hpassoc() const
{
  return m_hpassoc;
}

#pragma pack (pop)
#endif 