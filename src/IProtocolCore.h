#ifndef __IPROTOCOLCORE_H__
#define __IPROTOCOLCORE_H__


#include <string>

class Observer;

using namespace std;

typedef enum _eProtocolCoreProp {
	EPROTOCOL_CORE_PROP_URI,
	EPROTOCOL_CORE_PROP_LAST,
} eProtocolCoreProp;

class Segment
{
public:
	long long m_nMSposition;
	//long long stop;
	float m_nRate;
};

typedef struct _ConnInfo {
	string m_strURL;
} ConnInfo;

class IProtocolCore
{
public:
	virtual	bool Initialize() = 0;
	virtual	bool Finalize() = 0;
	virtual	bool Play() = 0;
	virtual	bool Pause() = 0;
	virtual	bool Stop() = 0;
	virtual	bool Seek(Segment* a_pSegment) = 0;
	virtual	void SetProperty(eProtocolCoreProp a_eProp, void* a_pdata) = 0;
	virtual void AddMessageListener(Observer* a_pObserver) = 0;
};


#endif //__IPROTOCOLCORE_H__
