#include "StreamingProtocolCOM.h"


#include <stdlib.h>
#include <iostream>
#include <dlfcn.h>


//#include "IStreamingProtocol.h"
//#include "ProtocolObserver.h"
#include "IProtocolCore.h"

using namespace std;

CStreamingProtocolCOM::CStreamingProtocolCOM()
{
	m_pProtocolCore = NULL;


	void *protocolcore;
	CreateInstance(eCLSID_PROTOCOLCORE_HLS, (void**)&protocolcore);
	m_pProtocolCore = (IProtocolCore*)protocolcore;
	
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}
CStreamingProtocolCOM::~CStreamingProtocolCOM()
{
	cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;
}

void CStreamingProtocolCOM::Initialize(){
m_pProtocolCore->Initialize();
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CStreamingProtocolCOM::Destroy(){
m_pProtocolCore->Destroy();
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CStreamingProtocolCOM::Play(){
m_pProtocolCore->Play();
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CStreamingProtocolCOM::Pause(){
m_pProtocolCore->Pause();
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CStreamingProtocolCOM::Stop(){
m_pProtocolCore->Stop();
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CStreamingProtocolCOM::Seek(){
m_pProtocolCore->Seek();
cout << "[" << __FILE__ << "][" << __LINE__ << "][" << __FUNCTION__ << "]" << endl;}

void CStreamingProtocolCOM::SetProperty(eStreamingProtocolProp a_eProp, void* a_pdata){
	if (ESTREAMING_PROTOCOL_PROP_URI == a_eProp)
		m_pProtocolCore->SetProperty(EPROTOCOL_CORE_PROP_URI, a_pdata);}


bool GetInstance(void** a_ppInstance)
{
	*a_ppInstance = new CStreamingProtocolCOM;
	return true;
}


