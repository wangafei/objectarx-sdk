#pragma once
#ifndef   ZCDWGEXTRACTOR_H
#define   ZCDWGEXTRACTOR_H
#include "zAcString.h"
#include "zrxvalue.h"
#include "zdbid.h"
#include "zpimplapi.h"

#if defined (ZCDWGEXTRACTOR_API)
#define   ZCDWGEXTRACTOR_PORT ZSOFT_EXPORT
#else
#define ZCDWGEXTRACTOR_PORT
#endif

namespace ZcDwgExtractor
{
	class ExtractorImp;

	class BeginExtractionEventArgs
	{
		friend class ExtractorImp;
		BeginExtractionEventArgs();
	public:

		ZCDWGEXTRACTOR_PORT Zcad::ErrorStatus queueForExtraction(const ZcDbObjectId& idObject, const ZcDbObjectId& idLayout);
	};

	class EndExtractionEventArgs
	{
		friend class ExtractorImp;
		EndExtractionEventArgs();
	public:

		ZCDWGEXTRACTOR_PORT Zcad::ErrorStatus addProperty(const ZcDbObjectId& idEntity, const ZcString& propertyCategory, const ZcString& propertyName, const ZcRxValue& propertyValue, const ZcString& units = L"", bool hidden = false);
	};

	class ZSOFT_NO_VTABLE ExtractorReactor
	{
	public:

		virtual void beginExtraction(BeginExtractionEventArgs& args) = 0;

		virtual void endExtraction(EndExtractionEventArgs& args) = 0;
	};

	class Extractor : public Pimpl::ApiPart<void, ExtractorImp>
	{
	protected:
		using base_type = Pimpl::ApiPart<void, ExtractorImp>;
	public:
		Extractor(ExtractorImp* pImp);

		ZCDWGEXTRACTOR_PORT void addReactor(ExtractorReactor* reactor);

		ZCDWGEXTRACTOR_PORT void removeReactor(ExtractorReactor* reactor);

		ZCDWGEXTRACTOR_PORT static Extractor& theOne();
	};

}
#endif