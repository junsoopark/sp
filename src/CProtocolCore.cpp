#include "CProtocolCore.h"


#include <stdlib.h>
#include <iostream>
 

CProtocolCore::CProtocolCore()
{
}
CProtocolCore::~CProtocolCore()
{
}

bool CProtocolCore::Initialize()
{
	OnInitialize();
}
bool CProtocolCore::Destroy()
{
	OnInitialize();
}

bool CProtocolCore::Play()
{
	OnPlay();
}
bool CProtocolCore::Pause()
{
	OnPause();
}
bool CProtocolCore::Stop()
{
	OnStop();
}


NULL
READY
PAUSE
PREROLL
PLAY
STOP

class State
{
	m_eCurState;
	IProtocolCore* m_pStreamingProtocol;


	void Play(){
	void Stop();
	void Pause();
	void Seek();
}

class StatePreroll : public State
{
	void Play()
	{
		return TRUE;
	}

	void Stop()
		{
			if (!m_pStreamingProtocol->Stop())
				return FALSE;
			
			m_pStreamingProtocol->SetState(m_pStreamingProtocol->GetStateStop())
		}
}
class StatePlay : public State
{


	void Play()
	{
		return TRUE;
	}

	void Stop()
		{
			if (!m_pStreamingProtocol->Stop())
				return FALSE;
			
			m_pStreamingProtocol->SetState(m_pStreamingProtocol->GetStateStop())
		}
}



	

bool CProtocolCore::Seek(Segment* a_pSegment)
{
	if (!a_pSegment)
		return FALSE;

	m_Segment.start = a_pSegment->start;
	m_Segment.stop = a_pSegment->stop;
	m_Segment.rate = a_pSegment->rate;


	return m_State.Seek(this);
	
	if (!IsSeekable())
		return RESOURCE_ERROR_NOT_SEEKABLE;

	if (FLAG_FLUSH)
	{
		SendMessage(MSG_FLUSH);
		//PostMessage();
		res = OnFlush();
	}

	if (!res)
		return RESOURCE_ERROR_FLUSH;
	
	return OnSeek();
}

void CProtocolCore::SetProperty(eProtocolCoreProp a_eProp, void* a_pdata)
{
	if (a_eProp == EPROTOCOL_CORE_PROP_URI)
		m_strURL = (char*)a_pdata;
	else
		;
}

void CProtocolCore::AddProtocolObserver(ProtocolObserver* a_pObserver)
{
	m_oObservers.insert(a_pObserver);
}

void CProtocolCore::RemoveProtocolOberver(ProtocolObserver* a_pObserver)
{
	m_oObservers.remove(a_pObserver);
}

bool CProtocolCore::FeedStream(char* a_pData, unsigned int a_nLen)
{
	for (list<ProtocolObserver*>::iterator it = m_oObservers.begin(); it != m_oObservers.end(); ++it)
		it.UpdateStream(this, a_pData, a_nLen);
}


