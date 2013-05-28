#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <stdio.h>

#include <glib.h>


#include "sp.h"

using namespace std;



class StreamReceiver;

StreamReceiver* g_sr;


class StreamReceiver : public Observer
{
public:
	void Update(Observable* a_pObservable, long a_pParam1, long a_pParem2)
	{
		Buffer* buffer = (Buffer*)a_pParam1;
		cout << "StreamReceiver::" << __FUNCTION__ << " size : " << buffer->m_nSize << " !!Call LMF API here!!" << endl;
	}

};


class MessageReceiver : public Observer
{
public:
	MessageReceiver()
{
cout << "Message rec create" << endl;
}
	void Update(Observable* a_pObservable, long a_pParam1, long a_pParam2)
	{
		Message::EMESSAGE_TYPE type = (Message::EMESSAGE_TYPE)(a_pParam1);
		if (type == Message::EMESSAGE_TYPE_INFO_ADDED_FEEDER)
{
		Feeder* feeder = (Feeder*)a_pParam2;

		g_sr = new StreamReceiver;
		feeder->AddObserver(g_sr );
		cout << "MessageReceiver::" <<  __FUNCTION__ << " msg = EMESSAGE_TYPE_INFO_ADDED_FEEDER, name = " <<  feeder->GetName()<< endl;
}
	}
};

typedef struct _CustomData {
	GMainLoop *loop;
	IProtocolCore *protocol;
	MessageReceiver receiver;
	bool playing;
} CustomData;




static gboolean handle_keyboard(GIOChannel *source, GIOCondition cond, CustomData *data)
{
	gchar *str = NULL;

	if (g_io_channel_read_line(source, &str, NULL, NULL, NULL) != G_IO_STATUS_NORMAL)
	{
		cout << "[" << __FUNCTION__ << "] str =" << str << endl;
		return TRUE;
	}


	switch (g_ascii_tolower(str[0])){
	case 'p':
		cout << "called. p" << endl;
		data->playing = !data->playing;

		if (data->playing)
			data->protocol->Play();
		else
			data->protocol->Pause();


		break;
	case 's':
		cout << "called. s" << endl;
		data->playing = FALSE;

		data->protocol->Stop();
		break;
	case 'q':
		data->protocol->Stop();
		g_main_loop_quit(data->loop);
		break;
	}

	return TRUE;
}





int main()
{


	CustomData data;
	GIOChannel *io_stdin = NULL;

	data.playing = false;

	if (!g_thread_supported())
	{
		g_thread_init(NULL);
	}

	CreateInstance(eCLSID_PROTOCOLCORE_DASH, (void**)&(data.protocol));
	data.protocol->Initialize();
	data.protocol->AddMessageListener(&data.receiver);

//	StreamingProtocol_SetPeoperty(data.protocol, ESTREAMING_PROTOCOL_PROP_URI, "http://c.brightcove.com/services/mobile/streaming/index/master.m3u8?videoId=1646841329001");

	io_stdin = g_io_channel_unix_new(fileno(stdin));
	g_io_add_watch(io_stdin, G_IO_IN, (GIOFunc)handle_keyboard, &data);


	data.loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(data.loop);




	g_main_loop_unref(data.loop);

	return 0;
}

