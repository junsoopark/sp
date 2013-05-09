#ifndef __PROTOCOLOBSERVER_H__
#define __PROTOCOLOBSERVER_H__


class IProtocolCore;
class ProtocolObservable;

class ProtocolObserver{
private:
	IProtocolCore* m_pProtocolCore;

public:
	void UpdateStream(ProtocolObservable* a_pobservable, char* a_pData, unsigned int a_nlen);//StreamData* data);
	void UpdateEvent(ProtocolObservable* a_pobservable);//, Event);
};


#endif //__PROTOCOLOBSERVER_H__
