#ifndef __ISTREAMINGPROTOCOL_H__
#define __ISTREAMINGPROTOCOL_H__


extern "C" {


//class IStreamingProtocol;
//using namespace::std;


typedef enum _eStramingProtocolProp {
	ESTREAMING_PROTOCOL_PROP_URI,
	ESTREAMING_PROTOCOL_PROP_LAST,
} eStreamingProtocolProp;


class IStreamingProtocol
{
public:
	virtual	void Initialize() = 0;
	virtual	void Destroy() = 0;
	virtual	void Play() = 0;
	virtual	void Pause() = 0;
	virtual	void Stop() = 0;
	virtual	void Seek() = 0;

	virtual	void SetProperty(eStreamingProtocolProp a_eProp, void* a_pdata) = 0;
};


#define	StreamingProtocol_Initialize(Instance)	((IStreamingProtocol*)Instance)->Initialize()
#define	StreamingProtocol_Destroy(Instance)		((IStreamingProtocol*)Instance)->Destroy()
#define	StreamingProtocol_Play(Instance)		((IStreamingProtocol*)Instance)->Play()
#define	StreamingProtocol_Pause(Instance)		((IStreamingProtocol*)Instance)->Pause()
#define	StreamingProtocol_Stop(Instance)		((IStreamingProtocol*)Instance)->Stop()
#define	StreamingProtocol_Seek(Instance)		((IStreamingProtocol*)Instance)->Seek()
#define	StreamingProtocol_SetPeoperty(Instance, Prop, Value)	((IStreamingProtocol*)Instance)->SetProperty((eStreamingProtocolProp)Prop, (void*)Value)



/*
class StreamData
{
	type Audio or Video
	int index
	char * buffer;
	int size;
}








class HLSProtocolCore : public IProtocolCore, public ProtocolObservable
{

public:
	virtual void Initialize(){};
	virtual void Destroy(){};
	virtual void Play(){};
	virtual void Pause(){};
	virtual void Stop(){};
	virtual void Seek(){};
}
*/
/*

typedef enum _eStramingProtocol {
	ESTREAMING_PROTOCOL_SSPK,
	ESTREAMING_PROTOCOL_HLS,
	ESTREAMING_PROTOCOL_DASH,
	ESTREAMING_PROTOCOL_LAST,
} eStreamingProtocol;
*/





} // extern "C" {
#endif //__ISTREAMINGPROTOCOL_H__
