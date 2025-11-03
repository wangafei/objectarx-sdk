#ifndef __GCAD__MEMORY_POOL__INCLUDE__
#define __GCAD__MEMORY_POOL__INCLUDE__

#pragma once

#include "OdAlloc.h"
#define mp_malloc odrxAlloc
#define mp_free   odrxFree

const int OBJECTS_THRESHOLD	 = 0x10000; // 64k

/* CMemoryPool的遗留问题
   无法处理内存重复释放，如果重复释放的话，内存池链表会被破坏
*/
class CMemoryPool
{
public:
	explicit CMemoryPool(size_t sizeBlock, size_t sizeMax = OBJECTS_THRESHOLD)
	{
		assert(sizeBlock >= sizeof(void*));
		_top_node = 0;
		_object_size  = sizeBlock;
		_object_count = 0;
		_max_count    = sizeMax;
	}
	~CMemoryPool()
	{
		Clear ();
	}

	void* Alloc()
	{
		if (!_top_node)
		{
			return ::mp_malloc(_object_size);
		}
		else
		{
			void* p = _top_node;
			_top_node = *(void**)_top_node;
			--_object_count;
			return p;
		}
	}

	void  Free(void* p)
	{
		if (p)
		{
			if ((_max_count <= 0) || (_object_count < _max_count)) // 可不限制?
			{
				*(void**)p = _top_node;
				_top_node = p;
				++_object_count;
				return;
			}
			::mp_free(p);
		}
	}

	void  Clear()
	{
		while (_top_node)
		{
			void *pNext = *(void**)_top_node; 
			::mp_free(_top_node);
			_top_node = pNext;
			--_object_count;
		}
		assert(_object_count == 0);
	}

private:
	void*   _top_node;
	size_t  _object_size;
	size_t  _object_count;
	size_t  _max_count;
};

class CMemoryPoolMT : protected CMemoryPool
{
private:
	CRITICAL_SECTION _section;
	class lock
	{
	public:
		lock(CRITICAL_SECTION* pSection) : _pSection(pSection) { EnterCriticalSection(pSection); }
		~lock()                                                { LeaveCriticalSection(_pSection); }
	private:
		CRITICAL_SECTION* _pSection;
	};

public:
	explicit CMemoryPoolMT(size_t sizeBlock, size_t sizeMax = OBJECTS_THRESHOLD)
		: CMemoryPool(sizeBlock, sizeMax)
	{
		InitializeCriticalSection(&_section);
	}
	~CMemoryPoolMT()
	{
		Clear();
		DeleteCriticalSection(&_section);
	}

	void* Alloc()
	{
		lock lockhere(&_section);
		return CMemoryPool::Alloc();
	}

	void  Free(void* p)
	{
		lock lockhere(&_section);
		CMemoryPool::Free(p);
	}

	void  Clear()
	{
		lock lockhere(&_section);
		CMemoryPool::Clear();
	}
};

template <typename type_t>
class memory_pool : public CMemoryPool
{
public:
	memory_pool(size_t nBlockSize, size_t nMaxSize) : CMemoryPool(nBlockSize, nMaxSize) {}
	~memory_pool() {}

	type_t* gd_malloc()        { return (type_t*)Alloc(); }
	void    gd_free(type_t* p) { Free(p); }
};

template <typename type_t>
class memory_pool_mt : public CMemoryPoolMT
{
public:
	memory_pool_mt(size_t nBlockSize, size_t nMaxSize) : CMemoryPoolMT(nBlockSize, nMaxSize) {}
	~memory_pool_mt() {}

	type_t* gd_malloc()        { return (type_t*)Alloc(); }
	void    gd_free(type_t* p) { Free(p); }
};


#endif //__GCAD__MEMORY_POOL__INCLUDE__

