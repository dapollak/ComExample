#include <Windows.h>
#include "..\ComExampleServer\ExampleObject.h"

#include <string>

#include <string>
#include <memory>

using std::wstring;
using std::string;
using std::unique_ptr;

int main() {
	CoInitializeEx(NULL, COINIT_MULTITHREADED);

	IClassFactory *factory;
	IExample *ptr;
	HRESULT ret = CoGetClassObject(CLSID_ExampleObjectFactory, CLSCTX_INPROC_SERVER, 0, IID_IClassFactory, reinterpret_cast<void**>(&factory));
	factory->CreateInstance(NULL, IID_IExample, reinterpret_cast<void**>(&ptr));

	HRESULT r = ptr->exampleMethod(5);
	CoUninitialize();
	return 0;
}