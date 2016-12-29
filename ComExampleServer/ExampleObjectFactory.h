#pragma once

#include "Definitions_h.h"

class ExampleObjectFactory : public IClassFactory {
public:
	ExampleObjectFactory();
	virtual ~ExampleObjectFactory();

	// IUnknown
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject) override;
	ULONG STDMETHODCALLTYPE AddRef() override;
	ULONG STDMETHODCALLTYPE Release() override;

	// IClassFactory
	HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown *pUnkOuter, REFIID riid, void **ppvObject) override;
	HRESULT STDMETHODCALLTYPE LockServer(BOOL fLock) override;

private:
	size_t m_refCount;
};