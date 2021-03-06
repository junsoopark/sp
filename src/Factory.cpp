#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <stdio.h>

#include "Factory.h"

using namespace std;


//"sspk", "경로를 파일로 제弱�??"
bool CreateInstance(eCLSID a_eClsid, void** a_ppInstance)
{
	void * handle = NULL;
	bool (*CreateInstance)(void**);

	if (a_eClsid <= eCLSID_FIRST || a_eClsid >= eCLSID_LAST)
		return false;

	if (!a_ppInstance)
		return false;


	cout << "Loading lib... Clsid = " << a_eClsid << endl;


	if (eCLSID_PROTOCOLCORE_HLS == a_eClsid)
		handle = dlopen("libpcHLS.so", RTLD_LAZY);
	if (eCLSID_PROTOCOLCORE_DASH == a_eClsid)
		handle = dlopen("libpcDASH.so", RTLD_LAZY);
	else
		cout << "Error. Unknown Clsid." << endl;

	if (!handle)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	cout << "Complete loading lib. handle = " << handle << endl;
	CreateInstance = (bool(*)(void**))dlsym(handle, "GetInstance");

	if (!CreateInstance)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	cout << "Complete loading func. CreateInstance = " << CreateInstance << endl;
	CreateInstance(a_ppInstance);

	if (!(*a_ppInstance))
		return false;

	cout << "Complete creation instance." << endl;

	return true;
}


bool DestroyInstance(void** a_ppInstance)
{
	if (!a_ppInstance || !*a_ppInstance)
		return false;
}


