#ifndef __CPROTOCOLCORE_H__
#define __CPROTOCOLCORE_H__


#include <string>

#include "IProtocolCore.h"
#include "ProtocolObservable.h"

using namespace std;

class CProtocolCore : public IProtocolCore, public ProtocolObservable
{
protected:
	string m_strURL;
	Segment m_Segment;


public:
	//IProtocolCore
	virtual	bool Initialize();
	virtual	bool Destroy();
	virtual	bool Play();
	virtual	bool Pause();
	virtual	bool Stop();
	virtual	bool Seek(Segment* a_pSegment);
	virtual	void SetProperty(eProtocolCoreProp a_eProp, void* a_pdata);


	//ProtocolObservable
	virtual void AddProtocolObserver(ProtocolObserver* a_pObserver);
	virtual void RemoveProtocolOberver(ProtocolObserver* a_pObserver);

protected:
	//CProtocolCore. Subclass should implement below virtual functions.
	virtual bool OnInitialize() = 0;
	virtual bool OnDestroy() = 0;
	virtual	bool OnPlay() = 0;
	virtual	bool OnPause() = 0;
	virtual	bool OnStop() = 0;
	virtual	bool OnSeek() = 0;

	bool FeedStream(char* a_pData, unsigned int a_nLen);

};


#endif //__CPROTOCOLCORE_H__

