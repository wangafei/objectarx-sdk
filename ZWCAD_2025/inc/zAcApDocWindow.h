#pragma once

#include "zadesk.h"
#include "zacdocman.h"
#include "zAcApWindow.h"

class ZcApDocWindowImp;

class ZCAD_PORT ZcApDocWindowReactor
{
public:
	virtual void documentWindowLoaded();
	virtual void documentWindowUpdated();
};

class ZCAD_PORT ZcApDocWindow : public ZcApWindow
{
public:
	ZcRxObject* document();
	const ZTCHAR* title() const;
	void setTitle(const ZTCHAR* title);
	bool canClose() const;
	void setCanClose(bool bCanClose);
    bool isFloating() const;
    bool isPinned() const;

public:
	void close();
	void activate();
	void enable(bool bEnable);
	void addReactor(ZcApDocWindowReactor* reactor);
	void removeReactor(ZcApDocWindowReactor* reactor);

protected:
    virtual void setDocument(ZcRxObject* document);

protected:
    virtual void onCreate(HWND hWnd);
    virtual void onLoad();
    virtual void onActivate();
    virtual void onDestroy();
    virtual void onUpdate();

public:
	ZcApDocWindow();
	virtual ~ZcApDocWindow();

public:
    virtual WindowHandle windowHandle() const ZSOFT_OVERRIDE;

private:
	ZcApDocWindow(const ZcApDocWindow&);
	ZcApDocWindow& operator=(const ZcApDocWindow&);

    friend class ZcApDocWindowImp;
};

class ZCAD_PORT ZcApDwgDocWindow : public ZcApDocWindow
{
public:
    ZcApDocument* document();

private:
	ZcApDwgDocWindow();

    friend class ZcApDocWindowImp;
};

class ZcApDocWindowManagerImp;
class ZcApDocWindowIteratorImp;
class ZCAD_PORT ZcApDocWindowIterator
{
public:
    bool done() const;
    void step();
    ZcApDocWindow* current();

private:
	ZcApDocWindowIterator();

public:
    ~ZcApDocWindowIterator();

private:
    ZcApDocWindowIteratorImp* m_pImp;

    friend class ZcApDocWindowManagerImp;
};

class ZCAD_PORT ZcApDocWindowManagerReactor
{
public:
    virtual void documentWindowCreated(ZcApDocWindow* docWindow);
	virtual void documentWindowActivated(ZcApDocWindow* docWindow);
	virtual void documentWindowDestroyed(ZcApDocWindow* docWindow);
	virtual void documentWindowMoved(ZcApDocWindow* docWindow, int newIndex, int oldIndex);
	virtual void documentWindowReplaced(ZcApDocWindow* newDocWindow, ZcApDocWindow* oldDocWindow);
    virtual void documentWindowFloated(ZcApDocWindow* docWindow);
    virtual void documentWindowDocked(ZcApDocWindow* docWindow);
    virtual void documentWindowToBeDocked(ZcApDocWindow* docWindow);

};

class ZcApDocWindowManagerImp;

class ZCAD_PORT ZcApDocWindowManager
{
public:
    ZcApDocWindow* activeDocumentWindow();
    int documentWindowCount() const;
    bool addDocumentWindow(ZcApDocWindow* docWindow);
    bool moveDocumentWindow(ZcApDocWindow* docWindow, int newIndex);
    ZcApDocWindowIterator* newIterator() const;
    void addReactor(ZcApDocWindowManagerReactor* pReactor);
    void removeReactor(ZcApDocWindowManagerReactor* pReactor);

private:
	ZcApDocWindowManager();
	~ZcApDocWindowManager();

    ZcApDocWindowManagerImp* m_pImp;

    friend class ZcApDocWindowManagerImp;
};

ZCAD_PORT ZcApDocWindowManager* zcDocWindowManagerPtr();
#define zcDocWindowManager zcDocWindowManagerPtr()
