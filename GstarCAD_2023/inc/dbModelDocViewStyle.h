/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef __GCDBMODELDOCVIEWSTYLE_H__
#define __GCDBMODELDOCVIEWSTYLE_H__

#pragma once
#include "gcdbport.h"
#include "dbmain.h"
#include "dbmtext.h"
#include "GcString.h"

class GcDbImpModelDocViewStyle;

class  GcDbModelDocViewStyle : public GcDbObject
{
protected:
  GCDB_PORT GcDbModelDocViewStyle();

public:
  GCDB_DECLARE_MEMBERS_EXPIMP(GcDbModelDocViewStyle, GCDB_PORT);

  enum AttachmentPoint {
    kAboveView = 0,
    kBelowView = 1,
  };

  enum TextAlignment {
    kTextAlignmentLeft = 0,
    kTextAlignmentCenter = 1,
    kTextAlignmentRight = 2,
  };

  GCDB_PORT ~GcDbModelDocViewStyle() = 0;

  GCDB_PORT virtual Gcad::ErrorStatus getName(GCHAR*& pszName) const final;
  GCDB_PORT virtual Gcad::ErrorStatus getName(GcString& strName) const;
  GCDB_PORT virtual Gcad::ErrorStatus setName(const GCHAR * pszName);

  GCDB_PORT virtual const GCHAR* description(void) const;
  GCDB_PORT virtual void getDescription(GcString& strDescription) const;
  GCDB_PORT virtual Gcad::ErrorStatus setDescription(const GCHAR * pszDescription);
  GCDB_PORT void setDatabaseDefaults(GcDbDatabase* pDb);

  GCDB_PORT Gcad::ErrorStatus postViewStyleToDb(GcDbDatabase* pDb, const GCHAR* styleName, GcDbObjectId &viewStyleId);
  GCDB_PORT bool              isModifiedForRecompute() const;
  GCDB_PORT GcString          defaultViewName(int index) const;
  GCDB_PORT bool              isViewNameValid(const GCHAR* pName) const;
  GCDB_PORT static GcGePoint3d calculateViewLabelPosition(GcGeVector2d &offsetVector,
    GcDbMText::AttachmentPoint &textAlignment,
    GcDbModelDocViewStyle::AttachmentPoint attachment,
    double offset,
    const GcGePoint3d &minPt,
    const GcGePoint3d &maxPt);
  GCDB_PORT static GcGeVector2d setViewLabelPosition(GcDbMText *pMText,
    GcDbModelDocViewStyle::AttachmentPoint attachment,
    double offset,
    const GcGePoint3d &minPt,
    const GcGePoint3d &maxPt);
  GCDB_PORT static GcGeVector2d updateViewLabelPosition(GcDbMText *pMText,
    GcDbModelDocViewStyle::AttachmentPoint &attachment,
    const GcGePoint3d &minPt,
    const GcGePoint3d &maxPt);

protected:
  GCDB_PORT Gcad::ErrorStatus subDeepClone(GcDbObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;
  GCDB_PORT Gcad::ErrorStatus subWblockClone(GcRxObject* pOwner, GcDbObject*& pClonedObject,
    GcDbIdMapping& idMap, Gsoft::Boolean isPrimary = true) const override;

private:
  friend class GcDbImpModelDocViewStyle;
};

inline Gcad::ErrorStatus GcDbModelDocViewStyle::getName(GCHAR*& pName) const
{
  return ::gcutGetGcStringConvertToGChar(this, &GcDbModelDocViewStyle::getName, pName);
}
#endif 