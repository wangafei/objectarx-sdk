#ifndef _GNavArray_h
#define _GNavArray_h

#if _MSC_VER >= 1000
#pragma once
#endif

#include <afxtempl.h>

template <class T>
class CNavArray : public CTypedPtrArray<CObArray, T*> {
public:
                CNavArray ();
virtual         ~CNavArray ();

protected:
virtual T       *NewData ();
public:
        T       *AddData ();
        int     GetCount ();
        T       *GetData (int index);
        BOOL    IsIndexValid (int index);
        void    RemoveData (int index);
        void    RemoveAllData ();
};

template <class T>
CNavArray<T>::CNavArray () :
    CTypedPtrArray<CObArray, T*>()
{
}

template <class T>
CNavArray<T>::~CNavArray ()
{
    RemoveAllData();
}

template <class T>
T    *CNavArray<T>::AddData ()
{
    T    *d = NewData();

    ASSERT(d != NULL);
    if (d != NULL)
        Add(d);
    return d;
}

template <class T>
int  CNavArray<T>::GetCount ()
{
    return (int)(GetUpperBound() + 1);
}

template <class T>
T    *CNavArray<T>::GetData (int index)
{
    T    *d = NULL;

    if (IsIndexValid(index))
        d = GetAt(index);
    return d;
}

template <class T>
BOOL CNavArray<T>::IsIndexValid (int index)
{
    return ((index >= 0) && (index <= GetUpperBound()));
}

template <class T>
T    *CNavArray<T>::NewData ()
{
    return new T;
}

template <class T>
void CNavArray<T>::RemoveData (int index)
{
    T    *d;

    if (IsIndexValid(index)) {
        d = GetAt(index);
        RemoveAt(index);
        delete d;
    }
}

template <class T>
void CNavArray<T>::RemoveAllData ()
{
    int  i, n = GetCount();
    T    *d;

    for (i = 0; i < n; i++) {
        d = GetAt(i);
        delete d;
    }
    RemoveAll();
    FreeExtra();
}

#endif