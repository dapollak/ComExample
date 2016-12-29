#include "ExampleObject.h"

size_t ExampleObject::s_numOfObjects = 0;

ExampleObject::ExampleObject() : m_refCount(1) { InterlockedIncrement(&s_numOfObjects); }

ExampleObject::~ExampleObject() { }

ULONG STDMETHODCALLTYPE ExampleObject::AddRef() {
	InterlockedIncrement(&m_refCount);
	return m_refCount;
}

ULONG STDMETHODCALLTYPE ExampleObject::Release() {
	InterlockedDecrement(&m_refCount);
	if (m_refCount == 0) {
		delete this;
		InterlockedDecrement(&s_numOfObjects);
		return 0;
	}

	return m_refCount;
}

HRESULT STDMETHODCALLTYPE ExampleObject::QueryInterface(const IID& riid, void** ppvObject) {
	if (ppvObject == NULL) {
		return E_POINTER;
	}

	if (riid == IID_IExample) {
		*ppvObject = static_cast<IExample*>(this);
		return S_OK;
	}

	return E_NOINTERFACE;
}

HRESULT STDMETHODCALLTYPE ExampleObject::exampleMethod(int n) {
	return S_OK;
}
