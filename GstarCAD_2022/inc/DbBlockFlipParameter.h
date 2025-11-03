#ifndef _DbBlockFlipParameter_h_Included_
#define _DbBlockFlipParameter_h_Included_

#include "DbBlock2PtParameter.h"

class OdDbBlockFlipGrip;
typedef OdSmartPtr<OdDbBlockFlipGrip> OdDbBlockFlipGripPtr;
class DYNBLOCKS_EXPORT OdDbBlockFlipParameter : public OdDbBlock2PtParameter
{
public:
  ODDB_EVAL_DECLARE_MEMBERS(OdDbBlockFlipParameter);
  OdDbBlockFlipParameter();
  enum FlipState{ NotFlipped, Flipped };
  //OdGePoint3d definitionLabelPoint() const;
  //OdString flipLabel() const;
  //OdString flipLabelDescription()const;
  //OdString baseStateLabel() const;
  //OdString flippedStateLabel()const;
  FlipState flipState() const;
  //OdDbBlockFlipGripPtr  getAssociatedFlipGrip( OdDb::OpenMode );
  //void setBaseStateLabel(const OdString &);
  //void setDefinitionLabelPoint(const OdGePoint3d &);
  //void setFlipLabel(const OdString &);
  //void setFlipLabelDescription(const OdString &);
  //void setFlippedStateLabel(const OdString &);
  void setFlipState(FlipState);
  void setUpdatedFlipState(const FlipState &state);
  FlipState updatedFlipState() const;

  virtual OdString getLabel() const;
  virtual void setLabel(const OdString &str);

  virtual OdString getLabelDesc() const;
  virtual void setLabelDesc(const OdString &str);

  virtual OdString getNotFlippedState() const;
  virtual void setNotFlippedState(const OdString &str);

  virtual OdString getFlippedState() const;
  virtual void setFlippedState(const OdString &str);

  virtual OdGePoint3d getLabelPosition() const;
  virtual void setLabelPosition(const OdGePoint3d &pnt);

  virtual OdString getDataConnection() const;
  virtual void setDataConnection(const OdString &str);

  virtual OdDbEvalNodeId getDataId() const;
  virtual void setDataId(const OdDbEvalNodeId &id);
};

typedef OdSmartPtr<OdDbBlockFlipParameter>OdDbBlockFlipParameterPtr;

#endif // _DbBlockFlipParameter_h_Included_
