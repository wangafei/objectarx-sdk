/////////////////////////////////////////////////////////////////////////////////////////
//
// Please refer to "COPYRIGHT.md" for the relevant copyright statement of this software.
//
/////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

#include "gsoft.h"
#include "gcdocman.h"

#include "GcApWindow.h"

class GcApDocWindowImp;

class GcApDocWindowReactor
{
public:
  GCCORE_PORT virtual void documentWindowLoaded();
  GCCORE_PORT virtual void documentWindowUpdated();
};

class GcApDocWindow : public GcApWindow
{
public:
  GCCORE_PORT GcRxObject* document();
  GCCORE_PORT const GCHAR* title() const;
  GCCORE_PORT void setTitle(const GCHAR* title);
  GCCORE_PORT bool canClose() const;
  GCCORE_PORT void setCanClose(bool bCanClose);

public:
  GCCORE_PORT void close();
  GCCORE_PORT void activate();
  GCCORE_PORT void enable(bool bEnable);
  GCCORE_PORT void addReactor(GcApDocWindowReactor* reactor);
  GCCORE_PORT void removeReactor(GcApDocWindowReactor* reactor);

protected:
  GCCORE_PORT virtual void setDocument(GcRxObject* document);

protected:
  GCCORE_PORT virtual void onCreate(HWND hWnd);
  GCCORE_PORT virtual void onLoad();
  GCCORE_PORT virtual void onActivate();
  GCCORE_PORT virtual void onDestroy();
  GCCORE_PORT virtual void onUpdate();

public:
  GCCORE_PORT GcApDocWindow();
  GCCORE_PORT virtual ~GcApDocWindow();

public:
  GCCORE_PORT virtual HWND windowHandle() GSOFT_OVERRIDE;

private:
  GcApDocWindow(const GcApDocWindow&);
  GcApDocWindow& operator=(const GcApDocWindow&);
  friend class GcApDocWindowImp;
};

class GcApDwgDocWindow : public GcApDocWindow
{
public:
  GCCORE_PORT GcApDocument* document();

private:
  GcApDwgDocWindow();
  friend class GcApDocWindowImp;
};

class GcApDocWindowManagerImp;
class GcApDocWindowIteratorImp;

class GcApDocWindowIterator
{
public:
  GCCORE_PORT bool done() const;
  GCCORE_PORT void step();
  GCCORE_PORT GcApDocWindow* current();

private:
  GcApDocWindowIterator();

public:
  GCCORE_PORT ~GcApDocWindowIterator();

private:
  GcApDocWindowIteratorImp* m_pImp;
  friend class GcApDocWindowManagerImp;
};

class GcApDocWindowManagerReactor
{
public:
  GCCORE_PORT virtual void documentWindowCreated(GcApDocWindow* docWindow);
  GCCORE_PORT virtual void documentWindowActivated(GcApDocWindow* docWindow);
  GCCORE_PORT virtual void documentWindowDestroyed(GcApDocWindow* docWindow);
  GCCORE_PORT virtual void documentWindowMoved(GcApDocWindow* docWindow, int newIndex, int oldIndex);
  GCCORE_PORT virtual void documentWindowReplaced(GcApDocWindow* newDocWindow, GcApDocWindow* oldDocWindow);
};

class GcApDocWindowManagerImp;

class GcApDocWindowManager
{
public:
  GCCORE_PORT GcApDocWindow* activeDocumentWindow();
  GCCORE_PORT int documentWindowCount() const;
  GCCORE_PORT bool addDocumentWindow(GcApDocWindow* docWindow);
  GCCORE_PORT bool moveDocumentWindow(GcApDocWindow* docWindow, int newIndex);
  GCCORE_PORT GcApDocWindowIterator* newIterator() const;
  GCCORE_PORT void addReactor(GcApDocWindowManagerReactor* pReactor);
  GCCORE_PORT void removeReactor(GcApDocWindowManagerReactor* pReactor);

private:
  GcApDocWindowManager();
  ~GcApDocWindowManager();
  GcApDocWindowManagerImp* m_pImp;
  friend class GcApDocWindowManagerImp;
};

GCCORE_PORT GcApDocWindowManager* gcDocWindowManagerPtr();
#define gcDocWindowManager gcDocWindowManagerPtr()