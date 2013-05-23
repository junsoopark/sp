#include "ProtocolCoreHLS.h"


#include <stdlib.h>
#include <iostream>
#include <memory.h>


//#include "hls.h"

using namespace std;

CProtocolCoreHLS::CProtocolCoreHLS()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}
CProtocolCoreHLS::~CProtocolCoreHLS()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreHLS::OnInitialize(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
//API_HLS_Initialize();
	return true;
}

bool CProtocolCoreHLS::OnFinalize(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
	return true;
}

bool CProtocolCoreHLS::OnPlay(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
//cout << strURL << endl;

//LMF_CONTENT_INFO_T info;
//memset(&info, 0x00, sizeof(LMF_CONTENT_INFO_T));

//API_HLS_Init(MEDIA_CH_A, (char*)strURL.data(), info);
	return true;
}

bool CProtocolCoreHLS::OnPause(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
//API_HLS_Pause(MEDIA_CH_A);
	return true;
}

bool CProtocolCoreHLS::OnStop(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
//API_HLS_Stop(MEDIA_CH_A);
	return true;
}

bool CProtocolCoreHLS::OnSeek(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
	return true;
}


bool GetInstance(void** a_ppInstance)
{
	*a_ppInstance = new CProtocolCoreHLS;
	return true;
}

