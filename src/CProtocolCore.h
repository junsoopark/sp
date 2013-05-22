#ifndef __CPROTOCOLCORE_H__
#define __CPROTOCOLCORE_H__

#include "IProtocolCore.h"
#include "Observable.h"

#include <string>
#include <map>

using namespace std;


typedef enum _eState {
	ESTATE_STOP,
	ESTATE_PAUSED,
	ESTATE_PLAYING,
	ESTATE_LAST,
} eState;

class State
{
	IProtocolCore* m_pProtocolCore;

	State(IProtocolCore* a_pProtocolCore)
	{m_pProtocolCore = a_pProtocolCore;}
	bool Play(Segment* a_pSegment) = 0;
	bool Stop() = 0;
	bool Pause() = 0;
	bool Seek(Segment* a_pSegment) = 0;
	eState GetCurState() = 0;
}

class StateStop : public State
{
	bool Play(){return m_pProtocolCore->Play();}
	bool Stop(){return TRUE;}
	bool Pause(){return TRUE;}
	bool Seek(Segment* a_pSegment){return m_pProtocolCore->Seek(a_pSegment);}
	eState GetCurState(){return ESTATE_STOP;}
}

class StatePaused : public State
{
	bool Play(){return m_pProtocolCore->Resume();}
	bool Stop(){return a_pProtocolCore->Stop();}
	bool Pause(){return TRUE;}
	bool Seek(Segment* a_pSegment){return m_pProtocolCore->Seek(a_pSegment);}
	eState GetCurState(){return ESTATE_PAUSED;}
}

class StatePlaying : public State
{
	bool Play(){return TRUE;}
	bool Stop(){return a_pProtocolCore->Stop();}
	bool Pause(){return a_pProtocolCore->Pause();}
	bool Seek(Segment* a_pSegment){return m_pProtocolCore->Seek(a_pSegment);}
	eState GetCurState(){return ESTATE_PLAYING;}
}




/*
class StreamDataTransfer //: public Runable
{
	StreamData* m_pStreamData;

	StreamDataTransfer(StreamData*

	//void Run(Loop, );

	bool InsertData() = 0;
	bool TransferData(){
		m_pStreamData->FeedData();
	}
	
	static void Loop(void* a_pThis, void* a_pParam)
	{
		Transfer* pThis = (Transfer*)a_pThis;
		pThis->Create();
		pThis->Send();
	}
};

bool StreamDataTransfer
{
	StreamData* m_pStreamData;
	
	bool Create(){
		m_pStreamData
		


}

*/

class CProtocolCore : public IProtocolCore
{
protected:
	//
	ConnInfo m_oConnInfo;

	Bus m_oBus;
	BitrateConfiguration m_oBitrateConfiguration;

	
	State *m_pCurrState;
	State *m_pStopState;
	State *m_pPausedState;
	State *m_pPlayingState;
	
	map<string, Feeder*> m_pFeeders;

	Segment m_Segment;
	//string m_strLanguage;


public:
	//IProtocolCore
	virtual	bool Initialize();
	virtual	bool Finalize();
	virtual	bool Play();
	virtual	bool Pause();
	virtual	bool Stop();
	virtual	bool Seek(Segment* a_pSegment);
	virtual	void SetProperty(eProtocolCoreProp a_eProp, void* a_pdata);


	void AddMessageListener(Observer* a_pObserver);
	void DestroyState();

protected:
	//CProtocolCore. Subclass should implement below virtual functions.
	virtual bool OnInitialize() = 0;
	virtual bool OnDestroy() = 0;
	virtual	bool OnPlay() = 0;
	virtual	bool OnPause() = 0;
	virtual	bool OnStop() = 0;
	virtual	bool OnSeek() = 0;


	bool AddFeeder(string a_strKey, Feeder* a_pFeeder);
};

#endif //__CPROTOCOLCORE_H__

