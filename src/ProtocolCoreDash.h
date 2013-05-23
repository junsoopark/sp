#ifndef __PROTOCOLCOREDASH_H__
#define __PROTOCOLCOREDASH_H__

#include "CProtocolCore.h"


class DASHFeeder : public Feeder
{
	static bool DASH_StreamCallback(void* userdata, const char* data, gsize length)//, char* a_pStream)
	{
		DASHFeeder* pThis = (DASHFeeder*)userdata;

		Buffer buffer;
		buffer.m_pData = NULL;
		buffer.m_nSize = 100;
		buffer.m_nTimestamp = 1;

		pThis->Feed(&buffer);
	}
}

class CProtocolCoreDASH : public CProtocolCore
{
public:
	CProtocolCoreDASH();
	~CProtocolCoreDASH();

	virtual	bool OnInitialize();
	virtual	bool OnDestroy();
	virtual	bool OnPlay();
	virtual	bool OnPause();
	virtual	bool OnStop();
	virtual	bool OnSeek();


/////////////////////////////////////////////////////

	void Streamcallback(int type, )

	void AddNewStream()//int codec, somestruct* a_pInfo)
	{
		Feeder* feeder = new DASHFeeder;
		string key;
		//make a key.
		
		AddFeeder(key, feeder);
		RegisterStremCallback(DASHFeeder::DASH_StreamHandler, (void*)feeder);
	}
};

#ifdef __cplusplus
extern "C" {
#endif

bool GetInstance(void** a_ppInstance);


#ifdef __cplusplus
}
#endif

#endif //__PROTOCOLCOREDASH_H__

