#ifndef _GcuiListBox_h
#define _GcuiListBox_h
#pragma pack (push, 8)

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGcUiListBox window

/*
class GCUI_PORT CGcUiListBox : public CGdUiListBox {
//    DECLARE_DYNAMIC(CGcUiListBox);

public:
                CGcUiListBox ();
virtual         ~CGcUiListBox ();

// ClassWizard-controlled
public:
    //{{AFX_VIRTUAL(CGcUiListBox)
    //}}AFX_VIRTUAL
protected:
    //{{AFX_MSG(CGcUiListBox)
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};
*/
//typedef CGdUiListBox    CGcUiListBox;
//The first release (2/2002) of the VC7 compiler has
//a bug that causes the above typedef not to work
//properly in certain situations.
//Here's some minimal code that demonstrates the problem.
//If/when they fix the problem we can go back using
//the typedef.
/*
class A 
{
protected:
    static void f() {}
};

typedef A B;

class C : public B
{
    static void* p;
};
void * C::p = &B::f;  //error C2248: 'A::f' : cannot access protected member declared in class 'A'

void main()
{
}
*/
#define CGcUiListBox CGdUiListBox
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#pragma pack (pop)
#endif

/////////////////////////////////////////////////////////////////////////////
