
#pragma once
#include "zAcString.h"
#include "zAcDbAssocAction.h"
#pragma pack (push, 8)

class ZCDBCORE2D_PORT ZcDbAssocNetwork : public ZcDbAssocAction
{
public:
    ZCRX_DECLARE_MEMBERS(ZcDbAssocNetwork);

    explicit ZcDbAssocNetwork(ZcDbAssocCreateImpObject createImpObject = kZcDbAssocCreateImpObject);

    const ZcDbObjectIdArray& getActions() const;

    const ZcDbObjectIdArray& getActionsToEvaluate() const;

    Zcad::ErrorStatus addAction(const ZcDbObjectId& actionId, bool alsoSetAsDatabaseOwner);

    Zcad::ErrorStatus removeAction(const ZcDbObjectId& actionId, bool alsoEraseIt);

    Zcad::ErrorStatus addActions(const ZcDbObjectIdArray& actionIds, bool alsoSetAsDatabaseOwner);

    Zcad::ErrorStatus removeAllActions(bool alsoEraseThem);

    Zcad::ErrorStatus ownedActionStatusChanged(ZcDbAssocAction* pOwnedAction,
                                               ZcDbAssocStatus  previousStatus);

    static ZcDbObjectId getInstanceFromDatabase(ZcDbDatabase*   pDatabase,
                                                bool            createIfDoesNotExist,
                                                const ZcString& dictionaryKey = ZCRX_T(""));

    static ZcDbObjectId getInstanceFromObject(const ZcDbObjectId& owningObjectId,
                                              bool                createIfDoesNotExist,
                                              bool                addToTopLevelNetwork = true,
                                              const ZcString&     dictionaryKey        = ZCRX_T(""));

    static Zcad::ErrorStatus removeInstanceFromObject(const ZcDbObjectId& owningObjectId,
                                                      bool                alsoEraseIt,
                                                      const ZcString&     dictionaryKey = ZCRX_T(""));

    static Zcad::ErrorStatus removeInstanceFromDatabase(ZcDbDatabase*   pDatabase,
                                                        bool            alsoEraseIt,
                                                        const ZcString& dictionaryKey = ZCRX_T(""));

};

class ZCDBCORE2D_PORT ZcDbAssocNetworkIterator
{
public:

    explicit ZcDbAssocNetworkIterator(const ZcDbAssocNetwork* pNetwork)
        : mpNetwork(pNetwork), mIndex(-1)
    {
#ifdef ASSERT
        ASSERT(mpNetwork != NULL);
#endif
    }

    ZcDbObjectId current() const
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
            return ZcDbObjectId::kNull;
        }
    }

    bool moveNext()
    {
        return mpNetwork != NULL ? ++mIndex < mpNetwork->getActions().length() : false;
    }

    void reset() { mIndex = -1; }

private:
    const ZcDbAssocNetwork* const mpNetwork;
    int                           mIndex;
};

#pragma pack (pop)

