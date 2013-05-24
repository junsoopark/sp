#include "ProtocolCoreHLS.h"


#include <stdlib.h>
#include <iostream>
#include <memory.h>


#include <pthread.h>
//#include "hls.h"

#include <Buffer.h>

using namespace std;



bool quit;
pthread_t thread;
int thr_id;
int a = 1;
int status = 0;

typedef void (*data_cb)(char* data, int size, void* handle);
data_cb g_cb;
void* g_userdata;

void* func(void* data)
{

	int id;
	int i = 0;
	id = *((int*)data);

	int size = 100;

	while(1)
	{
		cout << "HLSmodule" <<"::"<< __FUNCTION__ << " size: " << size << endl;
		if (g_cb)
			g_cb(0, size, g_userdata);

		sleep(1);

		if (quit == true)
			break;
	}



}

void HLS_RegisterCB(data_cb cb, void* userdata)
{
	g_cb = cb;
	g_userdata = userdata;
}


void HLSFeeder::hls_data_cb(char* data, int size, void* handle)
{
	void* m_pData;
	unsigned int m_nSize;
	unsigned long long m_nTimestamp;
	HLSFeeder* pThis = (HLSFeeder*)handle;
	
	Buffer buffer;
	buffer.m_pData = data;
	buffer.m_nSize = size;
	buffer.m_nTimestamp = 10;

	cout << "HLSFeeder" <<"::"<< __FUNCTION__ << " size: " << size << endl;
	pThis->Feed(&buffer);
}

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

	HLS_RegisterCB(HLSFeeder::hls_data_cb, feeder);
	Feeder* feeder = new HLSFeeder;
	AddFeeder("video", feeder);

	//API_HLS_Init(MEDIA_CH_A, (char*)strURL.data(), info);
	quit = false;
	thr_id = pthread_create(&thread, 0, func, (void*)&a);
	if (thr_id < 0)
		cout << "thread create fail" << endl;
	return true;
}

bool CProtocolCoreHLS::OnPause(){
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;

	//API_HLS_Pause(MEDIA_CH_A);
	quit = true;
	pthread_join(thread, (void**)&status);
	cout << "return thread" << status << endl;


	return true;
}

bool CProtocolCoreHLS::OnStop(){
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;

	//API_HLS_Stop(MEDIA_CH_A);
	quit = true;
	pthread_join(thread, (void**)&status);
	cout << "return thread" << status << endl;

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

