// ModelerTools.h : auxilary functionality of geometry modeler

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#ifndef _OD_MODELERTOOLS_INCLUDED_
#define _OD_MODELERTOOLS_INCLUDED_

//#include "BricsysChanges.h"
#include "ModelerGeometry.h"

#include "TD_PackPush.h"

TOOLKIT_EXPORT OdRxClassPtr odrxGetModelerToolsService();

class TOOLKIT_EXPORT OdModelerTools: public OdRxObject
{
protected:
    OdModelerTools() {}
public:  
    ODRX_DECLARE_MEMBERS(OdModelerTools);

    virtual OdResult deleteModelerBulletins() = 0;

    /** Description:
    Should be called from the main stream to start ACIS thread-safety mode.
    Prepares separate history streams for each thread, turns the thread-safety mode on.
    Returns false if no modeler geometry exist.
    */
    virtual void beginThreadSafetyMode(unsigned nThreads, const unsigned* aThreads) = 0;
    /** Description:
    Should be called from the main stream to end ACIS thread-safety mode.
    Merges separate history streams into the main history, turns the thread-safety mode off.
    */
    virtual void endThreadSafetyMode(unsigned nThreads, const unsigned* aThreads) = 0;
    /** Description:
    Should be called from a thread function to start modeler in this particular thread.
    Substitutes default history stream by unique one for the given thread.
    */
    virtual bool startThread() = 0;
    /** Description:
    Should be called from a thread function to stop modeler in this particular thread.
    Restopes default history stream for the given thread.
    */
    virtual bool stopThread() = 0;
    /** Description:
    Checks topology and geometry correctness of given entity.
    Results are returned as text in parameter 'report'.
    */
    virtual OdResult check3dSolid(const OdDb3dSolidPtr&, OdString& report) = 0;
};

/** Description:
This template class is a specialization of the OdSmartPtr class for OdModelerTools object pointers.
*/
typedef OdSmartPtr<OdModelerTools> OdModelerToolsPtr;

#include "TD_PackPop.h"

#endif //_OD_MODELERTOOLS_INCLUDED_

