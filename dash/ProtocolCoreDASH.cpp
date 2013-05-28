#include "ProtocolCoreDASH.h"


#include <stdlib.h>
#include <iostream>
#include <memory.h>


#include <pthread.h>
//#include "hls.h"

#include <Buffer.h>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////
bool quit;
pthread_t thread;
pthread_t thread2;
int thr_id;
int thr_id2;
int a = 1;
int status = 0;

typedef void (*data_cb)(char* data, int size, void* handle);
data_cb g_cb;
void* g_userdata;
data_cb g_cb2;
void* g_userdata2;

void* func(void* data)
{

	int id;
	int i = 0;
	id = *((int*)data);

	int size = 100;

	while(1)
	{
		cout << "DASHmodule" <<"::"<< __FUNCTION__ << " size: " << size << endl;
		if (g_cb)
			g_cb(0, size, g_userdata);

		sleep(1);

		if (quit == true)
			break;
	}



}
void* func2(void* data)
{

	int id;
	int i = 0;
	id = *((int*)data);

	int size = 50;

	while(1)
	{
		cout << "DASHmodule" <<"::"<< __FUNCTION__ << " size: " << size << endl;
		if (g_cb2)
			g_cb(0, size, g_userdata2);

		sleep(1);

		if (quit == true)
			break;
	}
}

void DASH_RegisterCB(data_cb cb, void* userdata)
{
	g_cb = cb;
	g_userdata = userdata;
}
void DASH_RegisterCB2(data_cb cb, void* userdata)
{
	g_cb2 = cb;
	g_userdata2 = userdata;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////


void DASHFeeder::dash_data_cb(char* data, int size, void* handle)
{
	void* m_pData;
	unsigned int m_nSize;
	unsigned long long m_nTimestamp;
	DASHFeeder* pThis = (DASHFeeder*)handle;
	
	Buffer buffer;
	buffer.m_pData = data;
	buffer.m_nSize = size;
	buffer.m_nTimestamp = 10;

	cout << "DASHFeeder" <<"::"<< __FUNCTION__ << " size: " << size << endl;
	pThis->Feed(&buffer);
}

CProtocolCoreDASH::CProtocolCoreDASH()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}
CProtocolCoreDASH::~CProtocolCoreDASH()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

bool CProtocolCoreDASH::OnInitialize(){

	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;

	return true;
}

bool CProtocolCoreDASH::OnFinalize(){
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
	return true;
}

bool CProtocolCoreDASH::OnPlay(){
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
	//cout << strURL << endl;

	//LMF_CONTENT_INFO_T info;
	//memset(&info, 0x00, sizeof(LMF_CONTENT_INFO_T));

	Feeder* feeder = new DASHFeeder("video");
	AddFeeder("video", feeder);
	Feeder* feeder2 = new DASHFeeder("audio");
	AddFeeder("audio", feeder2);

	DASH_RegisterCB(DASHFeeder::dash_data_cb, feeder);
	DASH_RegisterCB2(DASHFeeder::dash_data_cb, feeder2);
	quit = false;
	thr_id = pthread_create(&thread, 0, func, (void*)&a);
	if (thr_id < 0)
		cout << "thread create fail" << endl;
	thr_id2 = pthread_create(&thread2, 0, func2, (void*)&a);
	if (thr_id2 < 0)
		cout << "thread create fail" << endl;
	return true;
}

bool CProtocolCoreDASH::OnPause(){
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;

	quit = true;
	pthread_join(thread, (void**)&status);
	pthread_join(thread2, (void**)&status);
	cout << "return thread" << status << endl;


	return true;
}

bool CProtocolCoreDASH::OnStop(){
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;

	quit = true;
	pthread_join(thread, (void**)&status);
	pthread_join(thread2, (void**)&status);
	cout << "return thread" << status << endl;

	return true;
}

bool CProtocolCoreDASH::OnSeek(){
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
	return true;
}


bool GetInstance(void** a_ppInstance)
{
	*a_ppInstance = new CProtocolCoreDASH;
	return true;
}

