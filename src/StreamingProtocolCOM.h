#ifndef __STREAMINGPROTOCOLCOM_H__
#define __STREAMINGPROTOCOLCOM_H__

#include "IStreamingProtocol.h"
#include "ProtocolObserver.h"
#include "Factory.h"

#include <string>

using namespace std;

//class IStreamingProtocol;
//class ProtocolObserver;
class IProtocolCore;

class CStreamingProtocolCOM : public IStreamingProtocol, public ProtocolObserver
{
private:
	IProtocolCore* m_pProtocolCore;

		
public:
	CStreamingProtocolCOM();
	~CStreamingProtocolCOM();
	
	virtual	void Initialize();
	virtual	void Destroy();
	virtual	void Play();
	virtual	void Pause();
	virtual	void Stop();
	virtual	void Seek();

	virtual	void SetProperty(eStreamingProtocolProp a_eProp, void* a_pdata);
};


#ifdef __cplusplus
extern "C" {
#endif

bool GetInstance(void** a_ppInstance);


#ifdef __cplusplus
}
#endif

#endif //__STREAMINGPROTOCOLCOM_H__

