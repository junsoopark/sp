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
	m_pStopState = new StateStop;
	m_pPausedState = new StatePaused;
	m_pPlayingState = new StatePlaying;

	m_pCurrState = m_pStopState;


	return OnInitialize();
}
bool CProtocolCore::Destroy()
{
	DestroyState();

	
	return OnInitialize();
}

bool CProtocolCore::Play(Segment* a_pSegment)
{
	m_pCurrState->Play(a_pSegment);
	//1. check ready
	
	OnPlay();
}
bool CProtocolCore::Pause()
{
	OnPause();
}
bool CProtocolCore::Stop()
{
	//1.stop feeding.
	//StopFeeding();

	//2.OnStop
	OnStop();
}

bool CProtocolCore::Seek(Segment* a_pSegment)
{
	bool res = FALSE;
	
	//1. check values
	if (!a_pSegment)
		return FALSE;

	//2. set values
	m_Segment.start = a_pSegment->start;
	m_Segment.stop = a_pSegment->stop;
	m_Segment.rate = a_pSegment->rate;

	
	if (!IsSeekable())
		return FALSE;

	if (FLAG_FLUSH)
	{
		m_oBus.PostMessage(EMESSAGE_TYPE_INFO_FLUSH);
		res = OnFlush();
	}

	if (!res)
		return FALSE;

	return OnSeek();
}

void CProtocolCore::SetProperty(eProtocolCoreProp a_eProp, void* a_pdata)
{
	if (a_eProp == EPROTOCOL_CORE_PROP_URI)
		m_strURL = (char*)a_pdata;
	else
		;
}

bool CProtocolCore::PostMessage(Message* a_pMessage)
{
	return m_oBus.PostMessage(a_pMessage);
}

void CProtocolCore::AddMessageListener(Observer* a_pObserver)
{
	m_oBus.AddObserver(a_pObserver);
}

void CProtocolCore::DestroyState()
{
	delete m_pStopState;
	delete m_pPausedState;
	delete m_pPlayingState;

	m_pCurrState = NULL;
}

void CProtocolCore::AddFeeder(string a_strKey, Feeder* a_pFeeder)
{
	m_pFeeders.insert(pair<string, Feeder*>(a_strKey, a_pFeeder));
	m_oBus.PostMessage(Message::EMESSAGE_TYPE_INFO_ADDED_FEEDER, (void*)a_pFeeder);
}




