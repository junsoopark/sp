#include "Bus.h"

bool Bus::PostMessage(Message* a_pMessage)
{
	SetChagned();
	NotifyObservers((void*)a_pMessage,NULL);

	return TRUE;
}
