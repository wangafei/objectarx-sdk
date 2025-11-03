/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GCDB_DBHELIX_H
#define GCDB_DBHELIX_H

#include "gegbl.h"
#include "dbmain.h"
#include "dbspline.h"

#pragma pack (push, 8)

class GCDB_PORT GcDbHelix : public GcDbSpline
{
public:
  enum ConstrainType {
    kTurnHeight = 0,
    kTurns = 1,
    kHeight = 2
  };

public:
  GEOMENT_DECLARE_MEMBERS(GcDbHelix);
  GcDbHelix();
  ~GcDbHelix();

  Gcad::ErrorStatus createHelix();
  virtual GcGePoint3d axisPoint() const;

  virtual Gcad::ErrorStatus setAxisPoint(const GcGePoint3d &axisPoint, const bool bMoveStartPoint = true);
  virtual GcGePoint3d startPoint() const;
  virtual Gcad::ErrorStatus setStartPoint(const GcGePoint3d &startPoint);
  virtual GcGeVector3d axisVector() const;
  virtual Gcad::ErrorStatus setAxisVector(const GcGeVector3d &axisVector);
  virtual double height() const;
  virtual Gcad::ErrorStatus setHeight(double dHeight);
  virtual double baseRadius() const;
  virtual Gcad::ErrorStatus setBaseRadius(double dRadius);
  virtual double topRadius() const;
  virtual Gcad::ErrorStatus setTopRadius(double dRadius);
  virtual double turns() const;
  virtual Gcad::ErrorStatus setTurns(double dTurns);
  virtual double turnHeight() const;
  virtual Gcad::ErrorStatus setTurnHeight(double dTurnHeight);
  virtual Gsoft::Boolean twist() const;
  virtual Gcad::ErrorStatus setTwist(Gsoft::Boolean bTwist);
  virtual ConstrainType constrain() const;
  virtual Gcad::ErrorStatus setConstrain(ConstrainType constrain);
  virtual double turnSlope() const;
  virtual double totalLength() const;
  Gcad::ErrorStatus reverseCurve() override;

protected:
  Gcad::ErrorStatus subGetClassID(CLSID* pClsid) const override;
};

#pragma pack (pop)

#endif