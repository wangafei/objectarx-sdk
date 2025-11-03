/////////////////////////////////////////////////////////////////////////////// 
// Copyright (C) 2003-2011, Open Design Alliance (the "Alliance"). 
// All rights reserved. 
// 
// This software and its documentation and related materials are owned by 
// the Alliance. The software may only be incorporated into application 
// programs owned by members of the Alliance, subject to a signed 
// Membership Agreement and Supplemental Software License Agreement with the
// Alliance. The structure and organization of this software are the valuable  
// trade secrets of the Alliance and its suppliers. The software is also 
// protected by copyright law and international treaty provisions. Application  
// programs incorporating this software must include the following statement 
// with their copyright notices:
//   
//   This application incorporates Teigha(R) software pursuant to a license 
//   agreement with Open Design Alliance.
//   Teigha(R) for .dwg files Copyright (C) 2003-2011 by Open Design Alliance. 
//   All rights reserved.
//
// By use of this software, its documentation or related materials, you 
// acknowledge and accept the above terms.
//
//
// *DWG is the native and proprietary file format for AutoCAD(R) and a trademark  
// of Autodesk, Inc.  Open Design Alliance is not associated with Autodesk.
///////////////////////////////////////////////////////////////////////////////


#ifndef _ODGITRAITSCACHE_INCLUDED_
#define _ODGITRAITSCACHE_INCLUDED_

#include "GiCommonDraw.h"

#include "../OdArray.h"

class OdDbStub;

#include "../TD_PackPush.h"

/** Description:
    
    Library:
    TD_Gi
   
    {group:OdGi_Classes}
*/
template <class traitsContainer, class traitsTaker, OdUInt32 byMask = 0>
class OdGiTraitsCache : public traitsTaker
{
  public:
    enum CacheType
    {
      kCacheNone   = 0,
      kCacheByMask = 1,
      kCacheAll    = 2
    };
  protected:
    struct CacheEntry
    {
      OdDbStub       *m_objId;
      traitsContainer m_data;
      OdUInt32        m_flags;
    };
  protected:
    CacheType           m_cacheType;
    OdArray<CacheEntry> m_cacheData;
    OdUInt32            m_traitsAttrib;
  public:
    OdGiTraitsCache()
      : traitsTaker()
      , m_cacheType(kCacheNone)
      , m_traitsAttrib(0)
    {
    }
    explicit OdGiTraitsCache(CacheType cacheType)
      : traitsTaker()
      , m_cacheType(cacheType)
      , m_traitsAttrib()
    {
    }
    ~OdGiTraitsCache()
    {
    }

    void setCacheType(CacheType cacheType)
    {
      m_cacheType = cacheType;
    }
    CacheType cacheType() const
    {
      return m_cacheType;
    }

    void setAttributes(OdDbStub* objId, OdGiContext &giCtx, bool forceCaching = false)
    {
      if (m_cacheType != kCacheNone && m_cacheData.size() > 0)
      {
        // Note: iterator won't compile in this context on all platforms.
#ifdef _MSC_VER
        for (OdArray<CacheEntry>::size_type i = 0; i < m_cacheData.size(); i++)
#else
        for (size_t i = 0; i < m_cacheData.size(); i++)
#endif
        {
          CacheEntry& ce = m_cacheData[i];
          if (ce.m_objId == objId)
          {
            setData(ce.m_data);
            m_traitsAttrib = ce.m_flags;
            return;
          }
        }
      }
      OdGiDrawablePtr drawable = giCtx.openDrawable(objId);
      if (!drawable.isNull())
      {
        m_traitsAttrib = drawable->setAttributes(this);
        if (m_cacheType != kCacheNone)
        {
          if (m_cacheType == kCacheAll || forceCaching || ((m_traitsAttrib & byMask) != 0))
          {
            CacheEntry entry;
            entry.m_objId = objId;
            entry.m_data = this->getData();
            entry.m_flags = m_traitsAttrib;
            m_cacheData.append(entry);
          }
        }
      }
    }

    void setFlags(OdUInt32 uAttrib)
    {
      m_traitsAttrib = uAttrib;
    }
    OdUInt32 getFlags() const
    {
      return m_traitsAttrib;
    }

    void clear()
    {
      m_cacheData.setPhysicalLength(0);
    }
};

// traitsContainer - must have operator =.
// traitsTaker - must have setData(traitsContainer), getData() methods.

#include "../TD_PackPop.h"

#endif // #ifndef _ODGITRAITSCACHE_INCLUDED_
