#include "ExampleObjectFactory.h"
#include "ExampleObject.h"

#include <string>
#include <memory>

using std::wstring;
using std::string;
using std::unique_ptr;

using RegKeyGuard = unique_ptr<std::remove_pointer_t<HKEY>, decltype(&RegCloseKey)>;

wstring clsidToWstring(const CLSID& clsid) {
	WCHAR *stringPtrTemp;
	StringFromCLSID(clsid, &stringPtrTemp);
	wstring result(stringPtrTemp);
	CoTaskMemFree(stringPtrTemp);
	return result;
}

RegKeyGuard createRegKey(HKEY rootKey, const wstring& subKey) {
	HKEY keyRaw;
	LSTATUS ret = RegCreateKeyExW(rootKey, subKey.c_str(), 0, NULL, 0, KEY_ALL_ACCESS, NULL, &keyRaw, NULL);
	RegKeyGuard res(keyRaw, RegCloseKey);
	return std::move(res);
}

HRESULT __stdcall DllRegisterServer(void) {
	wstring exampleObjectFactoryGuid = clsidToWstring(CLSID_ExampleObjectFactory);

	RegKeyGuard clsidKey = createRegKey(HKEY_CLASSES_ROOT, L"CLSID\\" + exampleObjectFactoryGuid);
	RegKeyGuard inProcKey = createRegKey(clsidKey.get(), L"InprocServer32");

	wstring friendlyName = L"Example Object Factory";
	RegSetValueExW(clsidKey.get(), NULL, 0, REG_EXPAND_SZ, reinterpret_cast<const byte*>(friendlyName.c_str()), friendlyName.length()*sizeof(wchar_t));

	wstring dllPath = L"C:\\Users\\Daniel\\Desktop\\CheckCode\\ComExample\\Debug\\ComExampleServer.dll";
	RegSetValueExW(inProcKey.get(), NULL, 0, REG_EXPAND_SZ, reinterpret_cast<const byte*>(dllPath.c_str()), dllPath.length()*sizeof(wchar_t));

	wstring threadingModel = L"both";
	RegSetValueExW(inProcKey.get(), L"ThreadingModel", 0, REG_SZ, reinterpret_cast<const byte*>(threadingModel.c_str()), threadingModel.length()*sizeof(wchar_t));

	return S_OK;
}

HRESULT __stdcall DllUnregisterServer(void) {
	wstring exampleObjectFactoryGuid = clsidToWstring(CLSID_ExampleObjectFactory);
	RegKeyGuard clsidKey = createRegKey(HKEY_CLASSES_ROOT, L"CLSID");
	RegDeleteTreeW(clsidKey.get(), exampleObjectFactoryGuid.c_str());

	return S_OK;
}

_Check_return_
STDAPI  DllGetClassObject(_In_ REFCLSID rclsid, _In_ REFIID riid, _Outptr_ LPVOID FAR* ppv) {
	if (rclsid == CLSID_ExampleObjectFactory && riid == IID_IClassFactory) {
		IClassFactory* res = new ExampleObjectFactory;
		*ppv = res;
		res->AddRef();
		return S_OK;
	}

	if (rclsid == CLSID_ExampleObject && riid == IID_IExample) {
		*ppv = new ExampleObject;
		return S_OK;
	}

	return CLASS_E_CLASSNOTAVAILABLE;
}

__control_entrypoint(DllExport)
STDAPI  DllCanUnloadNow(void) {
	if (numOfObjects == 0) {
		return S_OK;
	}

	return S_FALSE;
}