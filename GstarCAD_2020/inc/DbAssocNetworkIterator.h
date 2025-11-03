#pragma once
#include "DbConstraintsExports.h"
#include "DbAssocAction.h"
#include "DbAssocNetwork.h"

class DBCONSTRAINTS_EXPORT OdDbAssocNetworkIterator
{
public:

  explicit OdDbAssocNetworkIterator(const OdDbAssocNetwork* pNetwork);

  OdDbObjectId current() const;

  bool moveNext();

  void reset();

private:
  const OdDbAssocNetwork* const mpNetwork;
  int                           mIndex;
}; // class OdDbAssocNetworkIterator