#pragma once

#include "Definitions_h.h"

extern "C" CLSID CLSID_ExampleObject;
extern "C" CLSID CLSID_ExampleObjectFactory;

class ExampleObject : public IExample {
public:
	ExampleObject();
	virtual ~ExampleObject();

	// IUnknown
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObject) override;
	ULONG STDMETHODCALLTYPE AddRef() override;
	ULONG STDMETHODCALLTYPE Release() override;

	// IExample
	HRESULT STDMETHODCALLTYPE exampleMethod(int n) override;

private:
	size_t m_refCount;

	static size_t s_numOfObjects;
};
