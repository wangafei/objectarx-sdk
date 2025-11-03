#pragma once

#include "gcadstd.h"
#include "gcdocman.h"
#include <map>

//-----------------------------------------------------------------------------
template <class T> class GcApDataManager : public GcApDocManagerReactor {

public:
	GcApDataManager () {
		gcDocManager->addReactor (this) ;
	}
	~GcApDataManager () {
		if ( gcDocManager != NULL )
			gcDocManager->removeReactor (this) ;
	}
	virtual void documentToBeDestroyed (GcApDocument *pDoc) {
		m_dataMap.erase (pDoc) ;
	}

	T &docData (GcApDocument *pDoc) {
		std::map<GcApDocument *, T>::iterator i =m_dataMap.find (pDoc) ;
		if ( i == m_dataMap.end () )
			return (m_dataMap [pDoc]) ;
		return ((*i).second) ;
	}
	T &docData () {
		return (docData (gcDocManager->curDocument ())) ;
	}

private:
	std::map<GcApDocument *, T> m_dataMap ;
} ;
