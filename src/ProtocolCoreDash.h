#ifndef __PROTOCOLCOREDASH_H__
#define __PROTOCOLCOREDASH_H__

#include "CProtocolCore.h"


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
};

#ifdef __cplusplus
extern "C" {
#endif

bool GetInstance(void** a_ppInstance);


#ifdef __cplusplus
}
#endif

#endif //__PROTOCOLCOREDASH_H__

