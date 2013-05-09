#ifndef __PROTOCOLCOREHLS_H__
#define __PROTOCOLCOREHLS_H__

#include "CProtocolCore.h"

class CProtocolCoreHLS : public CProtocolCore
{
public:
	CProtocolCoreHLS();
	~CProtocolCoreHLS();

	virtual	void Initialize();
	virtual	void Destroy();
	virtual	void Play();
	virtual	void Pause();
	virtual	void Stop();
	virtual	void Seek();
};

#ifdef __cplusplus
extern "C" {
#endif

bool GetInstance(void** a_ppInstance);


#ifdef __cplusplus
}
#endif

#endif //__PROTOCOLCOREHLS_H__

