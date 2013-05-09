#include "ProtocolCoreHLS.h"


#include <stdlib.h>
#include <iostream>
#include <dlfcn.h>
#include <memory.h>


#include "hls.h"

using namespace std;

CProtocolCoreHLS::CProtocolCoreHLS()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}
CProtocolCoreHLS::~CProtocolCoreHLS()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

void CProtocolCoreHLS::OnInitialize(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
API_HLS_Initialize();
}

void CProtocolCoreHLS::OnDestroy(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CProtocolCoreHLS::OnPlay(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
cout << strURL << endl;

LMF_CONTENT_INFO_T info;
memset(&info, 0x00, sizeof(LMF_CONTENT_INFO_T));

API_HLS_Init(MEDIA_CH_A, (char*)strURL.data(), info);

}

void CProtocolCoreHLS::OnPause(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
API_HLS_Pause(MEDIA_CH_A);
}

void CProtocolCoreHLS::OnStop(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
API_HLS_Stop(MEDIA_CH_A);
}

void CProtocolCoreHLS::OnSeek(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}


bool GetInstance(void** a_ppInstance)
{
	*a_ppInstance = new CProtocolCoreHLS;
	return true;
}

