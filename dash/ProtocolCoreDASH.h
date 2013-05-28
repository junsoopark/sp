#ifndef __PROTOCOLCOREDASH_H__
#define __PROTOCOLCOREDASH_H__

#include "CProtocolCore.h"
#include "Feeder.h"

class DASHFeeder : public Feeder
{
public:
	DASHFeeder(char* a_pName) : Feeder(a_pName){}
	static void dash_data_cb(char* data, int size, void* handle);
};

class CProtocolCoreDASH : public CProtocolCore
{
public:
	CProtocolCoreDASH();
	virtual ~CProtocolCoreDASH();

	virtual	bool OnInitialize();
	virtual	bool OnFinalize();
	virtual	bool OnPlay();
	virtual	bool OnPause();
	virtual	bool OnStop();
	virtual	bool OnSeek();
};

#ifdef __cplusplus
extern "C" {
#endif

bool GetInstance(void** a_ppInstance);


#ifdef __cplusplus
}
#endif

#endif //__PROTOCOLCOREDASH_H__

