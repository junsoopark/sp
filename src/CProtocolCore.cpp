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
/*
	m_pStopState = new StateStop;
	m_pPausedState = new StatePaused;
	m_pPlayingState = new StatePlaying;

	m_pCurrState = m_pStopState;
*/

	return OnInitialize();
}
bool CProtocolCore::Finalize()
{
//	DestroyState();

	
	return OnInitialize();
}

bool CProtocolCore::Play()
{
//	m_pCurrState->Play(a_pSegment);
	//1. check ready
	
	return OnPlay();
}
bool CProtocolCore::Pause()
{
	return OnPause();
}
bool CProtocolCore::Stop()
{
	//1.stop feeding.
	//StopFeeding();

	//2.OnStop
	return OnStop();
}

bool CProtocolCore::Seek(Segment* a_pSegment)
{
	bool res = false;
	
	//1. check values
	if (!a_pSegment)
		return false;

	//2. set values
	m_Segment.m_nMSposition = a_pSegment->m_nMSposition;
	m_Segment.m_nRate = a_pSegment->m_nRate;

/*	
	if (!IsSeekable())
		return FALSE;

	if (FLAG_FLUSH)
	{
		m_oBus.PostMessage(EMESSAGE_TYPE_INFO_FLUSH);
		res = OnFlush();
	}

	if (!res)
		return FALSE;
*/
	return OnSeek();
}

void CProtocolCore::SetProperty(eProtocolCoreProp a_eProp, void* a_pdata)
{
	if (a_eProp == EPROTOCOL_CORE_PROP_URI)
		m_oConnInfo.m_strURL = (char*)a_pdata;
	else
		;
}
/*
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

*/


