/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gcdocman.h"
#include <map>

template <class T> class GcApDataManager : public GcApDocManagerReactor {

public:
  GcApDataManager() {
    gcDocManager->addReactor(this);
  }
  ~GcApDataManager() {
    if (gcDocManager != NULL)
      gcDocManager->removeReactor(this);
  }
  virtual void documentToBeDestroyed(GcApDocument *pDoc) {
    m_dataMap.erase(pDoc);
  }

  T &docData(GcApDocument *pDoc) {
    if (m_dataMap.find(pDoc) == m_dataMap.end())
      return (m_dataMap[pDoc]);
    return ((*(m_dataMap.find(pDoc))).second);
  }
  T &docData() {
    return (docData(gcDocManager->curDocument()));
  }

private:
  std::map<GcApDocument *, T> m_dataMap;
};