#ifndef __PROTOCOLCOREHLS_H__
#define __PROTOCOLCOREHLS_H__

#include "CProtocolCore.h"
#include "Feeder.h"

class HLSFeeder : public Feeder
{
public:
	HLSFeeder(char* a_pName) : Feeder(a_pName){}
	static void hls_data_cb(char* data, int size, void* handle);
};

class CProtocolCoreHLS : public CProtocolCore
{
public:
	CProtocolCoreHLS();
	virtual ~CProtocolCoreHLS();

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

#endif //__PROTOCOLCOREHLS_H__

