#ifndef __PROTOCOLCOREHLS_H__
#define __PROTOCOLCOREHLS_H__

#include "CProtocolCore.h"

class CProtocolCoreHLS : public CProtocolCore
{
public:
	CProtocolCoreHLS();
	~CProtocolCoreHLS();

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

