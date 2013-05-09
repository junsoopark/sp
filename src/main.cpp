#include <stdlib.h>
#include <dlfcn.h>
#include <iostream>
#include <stdio.h>

#include <glib.h>


#include "Factory.h"
#include "IStreamingProtocol.h"

using namespace std;


typedef struct _CustomData {
	GMainLoop *loop;
	IStreamingProtocol *protocol;
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
			StreamingProtocol_Play(data->protocol);
		else
			StreamingProtocol_Pause(data->protocol);


		break;
	case 's':
		cout << "called. s" << endl;
		data->playing = FALSE;

		StreamingProtocol_Stop(data->protocol);
		break;
	case 'q':
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

	CreateInstance(eCLSID_STREAMINGPROTOCOL, (void**)&(data.protocol));
	StreamingProtocol_Initialize(data.protocol);
	StreamingProtocol_SetPeoperty(data.protocol, ESTREAMING_PROTOCOL_PROP_URI, "http://c.brightcove.com/services/mobile/streaming/index/master.m3u8?videoId=1646841329001");

	io_stdin = g_io_channel_unix_new(fileno(stdin));
	g_io_add_watch(io_stdin, G_IO_IN, (GIOFunc)handle_keyboard, &data);


	data.loop = g_main_loop_new(NULL, FALSE);
	g_main_loop_run(data.loop);




	g_main_loop_unref(data.loop);

	return 0;
}

