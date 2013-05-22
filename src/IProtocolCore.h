#ifndef __IPROTOCOLCORE_H__
#define __IPROTOCOLCORE_H__


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
	string strURL;
} ConnInfo;

class IProtocolCore
{
public:
	virtual	void Initialize() = 0;
	virtual	void Finalize() = 0;
	virtual	void Play() = 0;
	virtual	void Pause() = 0;
	virtual	void Stop() = 0;
	virtual	void Seek(Segment* a_pSegment) = 0;
	virtual	void SetProperty(eProtocolCoreProp a_eProp, void* a_pdata) = 0;
};


#endif //__IPROTOCOLCORE_H__