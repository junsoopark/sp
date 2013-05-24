#include "Bus.h"

bool Bus::PostMessage(Message::EMESSAGE_TYPE a_eMessage, long param)
{
	SetChanged();
	NotifyObservers((long)a_eMessage, param);

	return true;
}
