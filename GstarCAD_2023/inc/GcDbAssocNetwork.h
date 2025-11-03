/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once
#include "GcString.h"
#include "GcDbAssocAction.h"
#pragma pack (push, 8)

class  GcDbAssocNetwork : public GcDbAssocAction
{
public:
  GCRX_DECLARE_MEMBERS_EXPIMP(GcDbAssocNetwork, DBCONSTRAINTS_PORT);

  DBCONSTRAINTS_PORT explicit GcDbAssocNetwork(GcDbAssocCreateImpObject createImpObject = kGcDbAssocCreateImpObject);

  DBCONSTRAINTS_PORT const GcDbObjectIdArray& getActions() const;
  DBCONSTRAINTS_PORT const GcDbObjectIdArray& getActionsToEvaluate() const;
  DBCONSTRAINTS_PORT Gcad::ErrorStatus addAction(const GcDbObjectId& actionId, bool alsoSetAsDatabaseOwner);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus removeAction(const GcDbObjectId& actionId, bool alsoEraseIt);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus addActions(const GcDbObjectIdArray& actionIds, bool alsoSetAsDatabaseOwner);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus removeAllActions(bool alsoEraseThem);
  DBCONSTRAINTS_PORT Gcad::ErrorStatus ownedActionStatusChanged(GcDbAssocAction* pOwnedAction,
    GcDbAssocStatus  previousStatus);
  DBCONSTRAINTS_PORT static GcDbObjectId getInstanceFromDatabase(GcDbDatabase*   pDatabase,
    bool            createIfDoesNotExist,
    const GcString& dictionaryKey = GCRX_T(""));
  DBCONSTRAINTS_PORT static GcDbObjectId getInstanceFromObject(const GcDbObjectId& owningObjectId,
    bool                createIfDoesNotExist,
    bool                addToTopLevelNetwork = true,
    const GcString&     dictionaryKey = GCRX_T(""));
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus removeInstanceFromObject(const GcDbObjectId& owningObjectId,
    bool                alsoEraseIt,
    const GcString&     dictionaryKey = GCRX_T(""));
  DBCONSTRAINTS_PORT static Gcad::ErrorStatus removeInstanceFromDatabase(GcDbDatabase*   pDatabase,
    bool            alsoEraseIt,
    const GcString& dictionaryKey = GCRX_T(""));

};

class GcDbAssocNetworkIterator
{
public:
  DBCONSTRAINTS_PORT explicit GcDbAssocNetworkIterator(const GcDbAssocNetwork* pNetwork)
    : mpNetwork(pNetwork), mIndex(-1)
  {
#ifdef ASSERT
    ASSERT(mpNetwork != NULL);
#endif
  }

  DBCONSTRAINTS_PORT GcDbObjectId current() const
  {
    if (mpNetwork != NULL && 0 <= mIndex && mIndex < mpNetwork->getActions().length())
    {
      return mpNetwork->getActions()[mIndex];
    }
    else
    {
#ifdef ASSERT
      ASSERT(false);
#endif
      return GcDbObjectId::kNull;
    }
  }

  DBCONSTRAINTS_PORT bool moveNext()
  {
    return mpNetwork != NULL ? ++mIndex < mpNetwork->getActions().length() : false;
  }

  DBCONSTRAINTS_PORT void reset() { mIndex = -1; }

private:
  const GcDbAssocNetwork* const mpNetwork;
  int                           mIndex;
};

#pragma pack (pop)