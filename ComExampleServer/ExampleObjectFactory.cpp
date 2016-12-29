#include "ExampleObjectFactory.h"
#include "ExampleObject.h"

ExampleObjectFactory::ExampleObjectFactory(): m_refCount(1) { }

ExampleObjectFactory::~ExampleObjectFactory() { }

HRESULT STDMETHODCALLTYPE ExampleObjectFactory::CreateInstance(IUnknown* pUnkOuter, const IID& riid, void** ppvObject) {
	if (pUnkOuter != NULL) {
		return CLASS_E_NOAGGREGATION;
	}

	if (riid == IID_IExample) {
		*ppvObject = new ExampleObject;
		return S_OK;
	}

	return E_NOINTERFACE;
}

HRESULT STDMETHODCALLTYPE ExampleObjectFactory::LockServer(BOOL fLock) {
	return S_OK;
}

ULONG STDMETHODCALLTYPE ExampleObjectFactory::AddRef() {
	InterlockedIncrement(&m_refCount);
	return m_refCount;
}

ULONG STDMETHODCALLTYPE ExampleObjectFactory::Release() {
	InterlockedDecrement(&m_refCount);
	if (m_refCount == 0) {
		delete this;
		return 0;
	}

	return m_refCount;
}

HRESULT STDMETHODCALLTYPE ExampleObjectFactory::QueryInterface(const IID& riid, void** ppvObject) {
	if (ppvObject == NULL) {
		return E_POINTER;
	}

	if (riid == IID_IClassFactory) {
		*ppvObject = static_cast<IClassFactory*>(this);
		return S_OK;
	}

	return E_NOINTERFACE;
}



