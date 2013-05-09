#include "ProtocolCoreDASH.h"


#include <stdlib.h>
#include <iostream>
//#include <dlfcn.h>
//#include <memory.h>


//#include "dash.h"

using namespace std;

CProtocolCoreDASH::CProtocolCoreDASH()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}
CProtocolCoreDASH::~CProtocolCoreDASH()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnInitialize()
{
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnDestroy()
{
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnPlay()
{
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnPause()
{
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnStop()
{
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnSeek()
{
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;

}


bool GetInstance(void** a_ppInstance)
{
	*a_ppInstance = new CProtocolCoreDASH;
	return true;
}

