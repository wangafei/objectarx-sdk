/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#ifndef GTILDEFS_H
#include "AtilDefs.h"
#endif
#ifndef SIZE_H
#include "Size.h"
#endif
#ifndef OFFSET_H
#include "Offset.h"
#endif
#ifndef IMAGEFILTER_H
#include "ImageFilter.h"
#endif
#ifndef DATABUFFER_H
#include "DataBuffer.h"
#endif
#ifndef SPANPROVIDERINTERFACE_H
#include "SpanProviderInterface.h"
#endif
#ifndef GTILFILTERSVERSION_H
#include "AtilFiltersVersion.h"
#endif

#ifndef SPANFILTERS_H
#define SPANFILTERS_H

namespace GtilFilters
{
  class GTIL_EXPORT SpanFilter : public Gtil::ImageFilter
  {
  public:
    enum Operation
    {
      kClip,
      kCrop
    };

  public:
    SpanFilter(Gtil::RowProviderInterface* pInput);
    virtual ~SpanFilter();

    virtual void getNextRow(Gtil::DataBuffer& oneRow);

    virtual int rowsRemaining();

    virtual bool hasSpanInfo() const;

    virtual bool getNextSpan(int& nStart, int& nCount);

    virtual void restartSpans();

    virtual int numSpans();

    virtual Gtil::Size size() const;

    void appendSpanProvider(const SpanProviderInterface& provider,
                            Gtil::Offset offsetFromPipeOrigin,
                            Operation op);

    GtilFiltersVersion version;

  private:
    bool isActive(int nIndex);

    struct SpanProvider
    {
      SpanProviderInterface* pProvider;
      SpanProviderInterface::Mode mode;
      SpanFilter::Operation op;
      Gtil::Offset offset;
      bool bActive;
    };
    struct SpanProvider* maProviderList;

    int mnProviders;
    int mnArrayElements;

    struct Span
    {
      int nStart;
      int nEnd;
      struct Span* next;
    };
    int mnSpans;
    int mnOnSpan;
    int collateProviderSpans(int nProvider);
    int collateProviderSpans(int nProvider, struct Span*& aSpans);
    void mergeSpan(SpanProviderInterface::Mode mode, int nSpans, struct Span* aSpans);
    void clearToEnd(int nEnd);

    struct Span* newSpan();
    void deleteSpanList();
    void appendToList(struct Span* pAppend);
    void insertSpanIntoList(struct Span* pInsert, struct Span* pAfter);
    void removeSpanFromList(struct Span* pRemove);

    struct Span* mpSpanList;
    struct Span* mpTail;

    int mnColumns;
    int mnRows;
    int mnOnRow;
    bool mbShowInactiveRows;
    bool mbActiveProviderOnRow;
  };
}

#endif
