#include "Bus.h"

bool Bus::PostMessage(Message* a_pMessage)
{
	SetChanged();
	NotifyObservers((void*)a_pMessage, 0);

	return true;
}
