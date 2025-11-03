/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GD_DBMLINESTYLE_H
#define GD_DBMLINESTYLE_H

#include "dbmain.h"
#include "GdGChar.h"

#pragma pack (push, 8)

#define MSTYLE_NAME_LENGTH 32
#define MSTYLE_DESCRIPTION_LENGTH 256
#define LTYPE_LENGTH 32
#define MLINE_MAX_ELEMENTS 16

#define MIN_ANGLE (10.0 * PI / 180.0)

#define MAX_ANGLE (170.0 * PI / 180.0)

#define MSTYLE_DXF_FILL_ON           (0x1)
#define MSTYLE_DXF_SHOW_MITERS       (0x2)
#define MSTYLE_DXF_START_SQUARE_CAP  (0x10)
#define MSTYLE_DXF_START_INNER_ARCS  (0x20)
#define MSTYLE_DXF_START_ROUND_CAP   (0x40)
#define MSTYLE_DXF_END_SQUARE_CAP    (0x100)
#define MSTYLE_DXF_END_INNER_ARCS    (0x200)
#define MSTYLE_DXF_END_ROUND_CAP     (0x400)
#define MSTYLE_DXF_JUST_TOP          (0x1000)
#define MSTYLE_DXF_JUST_ZERO         (0x2000)
#define MSTYLE_DXF_JUST_BOT          (0x4000)

class GCDB_PORT GcDbMlineStyle : public  GcDbObject
{
public:
  GCDB_DECLARE_MEMBERS(GcDbMlineStyle);
  GcDbMlineStyle();
  ~GcDbMlineStyle();

  void              initMlineStyle();
  void              set(const GcDbMlineStyle & src, bool checkIfReferenced = true);

  Gcad::ErrorStatus setDescription(const GCHAR * description);
  const GCHAR*      description() const;

  Gcad::ErrorStatus setName(const GCHAR * name);
  const GCHAR*      name() const;

  void              setShowMiters(bool showThem);
  bool              showMiters() const;

  void              setStartSquareCap(bool showIt);
  bool              startSquareCap() const;

  void              setStartRoundCap(bool showIt);
  bool              startRoundCap() const;

  void              setStartInnerArcs(bool showThem);
  bool              startInnerArcs() const;

  void              setEndSquareCap(bool showIt);
  bool              endSquareCap() const;

  void              setEndRoundCap(bool showIt);
  bool              endRoundCap() const;

  void              setEndInnerArcs(bool showThem);
  bool              endInnerArcs() const;

  Gcad::ErrorStatus setFillColor(const GcCmColor& color);
  const GcCmColor&  fillColor() const;

  void              setFilled(bool onOff);
  bool              filled() const;

  Gcad::ErrorStatus setStartAngle(double ang);
  double            startAngle() const;

  Gcad::ErrorStatus setEndAngle(double ang);
  double            endAngle() const;

  Gcad::ErrorStatus addElement(int& index, double offset,
    const GcCmColor &color,
    GcDbObjectId linetypeId,
    bool checkIfReferenced = true);
  Gcad::ErrorStatus removeElementAt(int elem);

  int numElements() const;

  Gcad::ErrorStatus setElement(int & elem, double offset,
    const GcCmColor &color,
    GcDbObjectId linetypeId);
  Gcad::ErrorStatus getElementAt(int elem, double& offset,
    GcCmColor & color,
    GcDbObjectId & linetypeId) const;

  Gcad::ErrorStatus subErase(Gsoft::Boolean pErasing = true) override;
  Gcad::ErrorStatus dwgInFields(GcDbDwgFiler* filer) override;
  Gcad::ErrorStatus dwgOutFields(GcDbDwgFiler* filer) const override;
  Gcad::ErrorStatus dxfInFields(GcDbDxfFiler* filer) override;
  Gcad::ErrorStatus dxfOutFields(GcDbDxfFiler* filer) const override;

  Gcad::ErrorStatus copyFrom(const GcRxObject* other) override;
};

#pragma pack (pop)

#endif